#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright (c) 2023 Huawei Device Co., Ltd.
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

import json
import os.path
from pathlib import Path
from typedef.check.check import FileDocInfo, check_command_message, CheckErrorMessage
from coreImpl.check.check_doc import process_comment, process_file_doc_info
from coreImpl.check.check_name import check_file_name, check_api_name
from coreImpl.parser.parser import parser_include_ast


def process_api_json(api_info, file_doc_info, api_result_info_list, parent_kind, command_list):
    for command in command_list:
        # 对非文件名校验
        if 'NAME' in command and CheckErrorMessage.API_NAME_UNIVERSAL_14.name != command:
            api_result_info_list.extend(check_api_name(api_info, parent_kind))
            break
    if 'comment' in api_info.keys():
        comment = api_info['comment']
        api_result_info_list.extend(
           process_comment(comment, file_doc_info, api_info))
    kind = api_info['kind']
    child_node_list = get_api_info_child(api_info)
    for child_node in child_node_list:
        process_api_json(child_node, file_doc_info, api_result_info_list, kind, command_list)


def get_api_info_child(api_info):
    if 'children' in api_info.keys():
        return api_info['children']
    if 'members' in api_info.keys():
        return api_info['members']
    if 'parm' in api_info.keys():
        return api_info['parm']
    return []


def process_file_json(file_info, api_result_info_list, command_list):
    # 校验文件名
    if CheckErrorMessage.API_NAME_UNIVERSAL_14.name in command_list:
        api_result_info_list.extend(check_file_name(file_info))
    apis = file_info['children']
    kind = file_info['kind']
    file_doc_info = FileDocInfo()
    # 校验Doc信息
    api_result_info_list.extend(process_comment(file_info["comment"], file_doc_info, file_info))
    for api in apis:
        process_api_json(api, file_doc_info, api_result_info_list, kind, command_list)
    api_result_info_list.extend(process_file_doc_info(file_doc_info, file_info))


def process_all_json(python_obj, command_list):
    api_result_info_list = []
    for file_info in python_obj:
        process_file_json(file_info, api_result_info_list, command_list)
    return api_result_info_list


def write_in_txt(check_result, output_path):
    result_json = result_to_json(check_result)
    with open(output_path, 'w', encoding='utf-8') as fs:
        fs.write(result_json)
        fs.close()


def result_to_json(check_result):
    return json.dumps(check_result, default=lambda obj: obj.__dict__, indent=4)


def curr_entry(files_path, command: str, output):
    file_list = get_files(files_path)
    if command == 'all':
        command_list = check_command_message
    else:
        command_list = command.split(',')
    check_result_list = []
    if len(file_list) > 0:
        check_result_list = get_check_result_list(file_list, command_list)
    result_list = []
    if command != 'all':
        for result in check_result_list:
            if result.defectType in command_list:
                result_list.append(result)
    else:
        result_list = check_result_list
    write_in_txt(result_list, output)


def get_check_result_list(file_list, command_list):
    check_result_list = []
    for file in file_list:
        python_obj = parser_include_ast(os.path.dirname(file), [file])
        check_result_list.extend(process_all_json(python_obj, command_list))
    return check_result_list


def get_files(files_path: str):
    return files_path.split(',')


def get_file_type(file_path):
    return Path(file_path).suffix
