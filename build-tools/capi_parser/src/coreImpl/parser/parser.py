#!/usr/bin/env python
# coding=utf-8
##############################################
# Copyright (c) 2021-2022 Huawei Device Co., Ltd.
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
##############################################

import json
import os
import glob
import re
import shutil
from utils.constants import StringConstant, RegularExpressions
from typedef.parser.parser import ParserGetResultTable, OneFileApiMessage, NodeKind
from coreImpl.parser import parse_include, generating_tables  # 引入解析文件 # 引入得到结果表格文件


def find_gn_file(directory):  # 找指定目录下所有GN文件
    gn_files = []
    for root, _, files in os.walk(directory):  # dirpath, dirnames, filenames(对应信息)
        for file in files:
            if file.endswith(".gn"):
                gn_files.append(os.path.join(root, file))
    return gn_files


def find_h_file(matches, f, sources):
    for mat in matches:
        # 匹配sources = \[[^\]]*\](匹配方括号内的内容，其中包括一个或多个非右括号字符),\s*：匹配0个或多个空白字符
        f.seek(mat.span()[0])
        content = f.read()
        pattern = RegularExpressions.SOURCES.value
        sources_match = re.search(pattern, content)
        if sources_match:
            sources_value = sources_match.group(0)  # 获取完整匹配的字符串
            sources_value = re.sub(r'\s', '', sources_value)  # 去除源字符串的空白字符(换行符)和空格
            pattern = RegularExpressions.INCLUDE_H.value  # 匹配引号中的内容，找对应的.h
            source = re.findall(pattern, sources_value)
            sources.extend(source)


def find_function_file(file, function_name):  # 在GN文件中查找指定函数并在有函数名，获取对应sources的值
    with open(file, 'r') as f:
        content = f.read()  # 获取文件内容
        pattern = ''.join([r'\b', re.escape(function_name), r'\b'])    # '\b'确保函数名的完全匹配
        matches = re.finditer(pattern, content)  # finditer会返回位置信息
        f.seek(0)  # 回到文件开始位置
        sources = []  # 装全部匹配的sources的.h(可能不止一个-headers函数)
        if matches:  # 是否匹配成功
            find_h_file(matches, f, sources)
        f.close()
        return matches, sources


def find_dest_dir(matches, content, f):
    sources_dir = []
    if matches:
        end = 0
        for _ in matches:
            pattern = RegularExpressions.DEST_DIR.value
            source_match = re.search(pattern, content)
            if source_match:
                con = source_match.group(1)
                sources_dir.append(con)
                end += source_match.end()  # 每次找完一个sources的.h路径，记录光标结束位置
                f.seek(end)  # 移动光标在该结束位置
                content = f.read()
    return sources_dir


def get_dest_dir(file, function_name):  # 获取dest_dir
    with open(file, 'r') as f:
        content = f.read()  # 获取文件内容
        pattern = ''.join([r'\b', re.escape(function_name), r'\b'])  # '\b'确保函数名的完全匹配
        matches = re.findall(pattern, content)
        f.seek(0)
        sources_dir = find_dest_dir(matches, content, f)
        f.close()
        return sources_dir


def find_json_file(gn_file_match):  # 找gn文件同级目录下的.json文件
    match_json_file = []
    directory = os.path.dirname(gn_file_match)
    for file in glob.glob(os.path.join(directory, "*.json")):  # 统计.json文件
        match_json_file.append(file)
    return match_json_file


def dire_func(gn_file, func_name):  # 统计数据的
    matches_file_total = []  # 统计有ohos_ndk_headers函数的gn文件
    json_file_total = []  # 统计跟含有函数的gn文件同级的json文件
    source_include = []  # 统计sources里面的.h
    matches, source = find_function_file(gn_file, func_name)  # 找到包含函数的gn文件
    if matches:  # 保证两个都不为空，source可能为空
        source_include = source  # 获取头文件列表
        matches_file_total.append(gn_file)  # 调用匹配函数的函数(说明有对应的函数、source)
        json_file_total.extend(find_json_file(gn_file))  # 同级目录下的.json文件

    return matches_file_total, json_file_total, source_include


def change_json_file(dict_data, name):  # 生成json文件
    file_name = name + '_new' + '.json'  # json文件名
    with open(file_name, 'w', encoding='UTF-8') as f:  # encoding='UTF-8'能显示中文
        # ensure_ascii=False确保能显示中文，indent=4(格式控制)使生成的json样式跟字典一样
        json.dump(dict_data, f, ensure_ascii=False, indent=4)
    f.close()
    return file_name


def change_abs(include_files, dire_path):  # 获取.h绝对路径
    abs_path = []
    for j_item in include_files:  # 拼接路径，生成绝对路径
        # os.path.normpath(path):规范或者是格式化路径，它会把所有路径分割符按照操作系统进行替换
        # 把规范路径和gn文件对应的目录路径拼接
        if os.path.isabs(j_item):  # 是否是绝对路径，是就拼接路径盘，不是就拼接gn目录路径
            head = os.path.splitdrive(dire_path)  # 获取windows盘路径
            include_file = os.path.normpath(j_item)
            change_path = head[1].split('interface_sdk_c')
            replace_path = os.path.normpath(os.path.join(change_path[0], 'interface_sdk_c'))
            if 'third_party/node/src' in j_item:
                include_file = include_file.replace('\\\\',
                                                    '{}{}'.format(replace_path, '\\'))
            else:
                # 去掉绝对路径的双\\,替换为interface_sdk_c
                include_file = include_file.replace('\\\\interface\\sdk_c',
                                                    replace_path)
            if head:
                include_file = os.path.join(head[0], include_file)  # 拼接盘和路径
            abs_path.append(include_file)
        else:
            relative_path = os.path.abspath(os.path.join(dire_path, os.path.normpath(j_item)))  # ../ .解决
            abs_path.append(relative_path)
    return abs_path


def get_result_table(json_files, abs_path, link_path, gn_path):  # 进行处理，生成表格
    compare_result_list = []
    head_name = ""
    generate_data_only = []
    original_data_only = []
    parser_file_data = []
    if json_files:
        file_name = os.path.split(json_files[0])  # 取第一个json名，但我是用列表装的
        file_name = os.path.splitext(file_name[1])  # 取下标1对应的元素(元组)
        parser_file_data = parse_include.get_include_file(abs_path, link_path, gn_path)  # 获取解析返回的数据
        parser_json_name = change_json_file(parser_file_data, file_name[0])  # 生成json文件
        # 解析完后，传两个json文件，对比两个json文件，最后生成数据表格
        (compare_result_list, head_name, generate_data_only,
         original_data_only) = generating_tables.get_json_file(parser_json_name, json_files)

    obj_data = ParserGetResultTable(compare_result_list, head_name,
                                    generate_data_only, original_data_only, parser_file_data)

    return obj_data


def create_dir(sources_dir, gn_file, function_name, link_include_file):
    if sources_dir:
        for item in sources_dir:
            directory = item
            new_dire = os.path.join('sysroot', directory)
            new_dire = os.path.normpath(new_dire)
            if not os.path.exists(new_dire):
                os.makedirs(new_dire)
            if new_dire in link_include_file:
                pass
            else:
                link_include_file.append(new_dire)  # 添加链接的头文件
            match_files, json_files, include_files = dire_func(gn_file, function_name)
            dire_path = os.path.dirname(gn_file)  # 获取gn文件路径
            if match_files:
                dir_copy(include_files, dire_path, new_dire)
            else:
                print("在create_dir函数中，原因：gn文件条件不满足")
    else:
        print("gn文件没有ohos_sdk_headers")


def dir_copy(include_files, dire_path, new_dire):
    abs_path = change_abs(include_files, dire_path)  # 接收.h绝对路径
    for j_item in abs_path:
        shutil.copy(j_item, new_dire)


def link_include(directory_path, function_names, link_include_file):
    gn_file_total = find_gn_file(directory_path)  # 查找gn文件
    for item in gn_file_total:  # 处理每个gn文件
        sources_dir = get_dest_dir(item, function_names)
        if sources_dir:
            create_dir(sources_dir, item, function_names, link_include_file)


def main_entrance(directory_path, function_names, link_path):  # 主入口
    gn_file_total = find_gn_file(directory_path)  # 查找gn文件
    compare_result_list_total = []
    generate_data_only_total = []
    original_data_only_total = []
    data_total = []             # 总的解析数据
    for item in gn_file_total:  # 处理每个gn文件
        match_files, json_files, include_files = dire_func(item, function_names)
        dire_path = os.path.dirname(item)  # 获取gn文件路径
        if include_files:  # 符合条件的gn文件
            abs_path = change_abs(include_files, dire_path)  # 接收.h绝对路径
            # 接收对比结果信息
            data_result = get_result_table(json_files, abs_path, link_path, directory_path)
            data_total.append(data_result.parser_data)
            if len(data_result.compare_result_list) != 0:
                compare_result_list_total.extend(data_result.compare_result_list)
                generate_data_only_total.extend(data_result.generate_data_only)
                original_data_only_total.extend(data_result.original_data_only)
            elif data_result.head_name == "":
                print("gn文件下无json文件")
            else:
                generate_data_only_total.extend(data_result.generate_data_only)
                original_data_only_total.extend(data_result.original_data_only)
                print("没有匹配项")
        else:
            print("gn文件无header函数")
    generating_tables.generate_excel(compare_result_list_total, StringConstant.RESULT_HEAD_NAME.value,
                                     generate_data_only_total, original_data_only_total)

    obj_data_total = ParserGetResultTable(compare_result_list_total, '', generate_data_only_total,
                                          original_data_only_total, data_total)
    return obj_data_total


def copy_std_lib(link_include_file, root_path=''):
    if root_path:
        include_lib = os.path.abspath(os.path.join(root_path, StringConstant.INCLUDE_LIB.value))
    else:
        include_lib = StringConstant.INCLUDE_LIB.value
    std_include = StringConstant.STD_INCLUDE.value
    if not os.path.exists(std_include):
        try:
            shutil.copytree(include_lib, std_include)
        except OSError:
            pass
    if std_include not in link_include_file:
        link_include_file.append(std_include)


def find_include(link_include_path):
    for dir_path, _, _ in os.walk(StringConstant.CREATE_LIB_PATH.value):
        if dir_path not in link_include_path:
            link_include_path.append(dir_path)


def copy_self_include(link_include_path, self_include_file, flag=-1):
    for dir_path, _, file_name_list in os.walk(self_include_file):
        for file in file_name_list:
            if (file.endswith('.h') and ('sysroot' not in dir_path)
                    and (dir_path not in link_include_path)):
                link_include_path.append(dir_path)


def delete_typedef_child(child):
    if child['kind'] == 'TYPEDEF_DECL':
        if 'children' in child and len(child['children']) \
                and (child['children'][0]['kind'] == 'STRUCT_DECL'
                     or child['children'][0]['kind'] == 'ENUM_DECL'
                     or child['children'][0]['kind'] == 'UNION_DECL'):
            child['children'] = []


def parser(directory_path):  # 目录路径
    function_name = StringConstant.FUNK_NAME.value  # 匹配的函数名

    link_include_path = []  # 装链接头文件路径
    copy_std_lib(link_include_path)  # ndk头文件移到sysroot中
    find_include(link_include_path)
    link_include(directory_path, function_name, link_include_path)

    data_total = main_entrance(directory_path, function_name, link_include_path)  # 调用入口函数
    return data_total


def parser_include_ast(dire_file_path, include_path, flag=-1):        # 对于单独的.h解析接口
    correct_include_path = []

    link_include_path = []
    if -1 == flag:
        copy_std_lib(link_include_path, dire_file_path)
    else:
        copy_std_lib(link_include_path)
    find_include(link_include_path)
    link_include(dire_file_path, StringConstant.FUNK_NAME.value, link_include_path)
    if len(link_include_path) <= 1:
        copy_self_include(link_include_path, dire_file_path, flag)
    for item in include_path:
        split_path = os.path.splitext(item)
        if split_path[1] == '.h':   # 判断.h结尾
            correct_include_path.append(item)

    data = parse_include.get_include_file(correct_include_path, link_include_path, dire_file_path)

    for item in data:
        if 'children' in item:
            for child in item['children']:
                delete_typedef_child(child)

    return data


def get_dir_file_path(dir_path):
    file_path_list = []
    link_include_path = []  # 装链接头文件路径
    for dir_path, dir_names, filenames in os.walk(dir_path):
        for dir_name in dir_names:
            link_include_path.append(os.path.join(dir_path, dir_name))
        for file in filenames:
            if 'build-tools' not in dir_path and 'sysroot' not in dir_path and file.endswith('.h'):
                file_path_list.append(os.path.join(dir_path, file))

    return file_path_list, link_include_path


def get_file_api_num(file_data, kind_list):
    api_number = 0
    if 'children' in file_data:
        for child in file_data['children']:
            if 'kind' in child and child['kind'] in kind_list:
                api_number += 1
    return api_number


def get_file_api_dict(data_total):
    api_obj_total_list = []
    kind_list = [
        NodeKind.MACRO_DEFINITION.value,
        NodeKind.STRUCT_DECL.value,
        NodeKind.UNION_DECL.value,
        NodeKind.ENUM_DECL.value,
        NodeKind.FUNCTION_DECL.value,
        NodeKind.VAR_DECL.value
    ]
    for one_file_data in data_total:
        file_api_num = get_file_api_num(one_file_data, kind_list)
        if 'name' in one_file_data and 'kit_name' in one_file_data and 'sub_system' in one_file_data:
            api_message_obj = OneFileApiMessage(one_file_data['name'], one_file_data['kit_name'],
                                                one_file_data['sub_system'], file_api_num)
            api_message_obj.set_file_path(api_message_obj.get_file_path().replace('\\', '/'))
            current_file = os.path.dirname(__file__)
            kit_json_file_path = os.path.abspath(os.path.join(current_file,
                                                              r"kit_sub_system/c_file_kit_sub_system.json"))
            complete_kit_or_system(api_message_obj, kit_json_file_path)
            api_obj_total_list.append(api_message_obj)
    api_dict_total_list = obj_change_to_dict(api_obj_total_list)

    return api_dict_total_list


def obj_change_to_dict(obj_data: list):
    dict_list = []
    for element in obj_data:
        element_dict = {
            'filePath': element.file_path,
            'kitName': element.kit_name,
            'subSystem': element.sub_system,
            'apiNumber': element.api_number
        }
        dict_list.append(element_dict)

    return dict_list


def generate_file_api_json(dict_data, output_path=''):
    if not output_path:
        output_path = StringConstant.FILE_LEVEL_API_DATA.value
    with open(output_path, 'w', encoding='utf-8') as fs:
        json.dump(dict_data, fs, indent=4, ensure_ascii=False)
        fs.close()


def complete_kit_or_system(api_message: OneFileApiMessage, json_path):
    if (not api_message.get_kit_name()) or (not api_message.get_sub_system()):
        kit_name, sub_system_name = parse_include.get_kit_system_data(json_path,
                                                                      api_message.get_file_path())
        if not api_message.get_kit_name():
            api_message.set_kit_name(kit_name)
        if not api_message.get_sub_system():
            api_message.set_sub_system(sub_system_name)


def parser_direct(path):  # 目录路径
    file_path_list = []
    link_include_path = []  # 装链接头文件路径
    copy_std_lib(link_include_path)
    dir_path = ''
    if os.path.isdir(path):
        link_include_path.append(path)
        file_path_total, link_include_total = get_dir_file_path(path)
        file_path_list.extend(file_path_total)
        link_include_path.extend(link_include_total)
        dir_path = path
    else:
        if path.endswith('.h'):
            file_path_list.append(path)
            dir_path = os.path.dirname(path)
            link_include_path.append(dir_path)
    data_total = parse_include.get_include_file(file_path_list, link_include_path, dir_path)
    generating_tables.get_api_data(data_total, StringConstant.PARSER_DIRECT_EXCEL_NAME.value)

    return data_total


def parser_file_level(output_path):
    current_file = os.path.dirname(__file__)
    parser_path = os.path.abspath(os.path.join(current_file, r'../../../../..'))
    file_path_list = []
    link_include_path = []  # 装链接头文件路径
    data_total = []
    if not os.path.isdir(parser_path):
        return data_total
    file_path_total, link_include_total = get_dir_file_path(parser_path)
    file_path_list.extend(file_path_total)
    link_include_path.extend(link_include_total)
    data_total = parse_include.get_include_file(file_path_list, link_include_path, parser_path)
    file_api_dict = get_file_api_dict(data_total)
    generate_file_api_json(file_api_dict, output_path)

    return data_total
