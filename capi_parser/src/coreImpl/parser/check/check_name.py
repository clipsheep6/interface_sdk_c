import enum
import os.path
import re
from typedef.check.check import ApiResultInfo, ErrorMessage, ErrorType, LogType


def check_large_hump(api_info):
    return processing_check_data('LARGE_HUMP', api_info)


def check_function_name(api_info):
    return processing_check_data('CHECK_FUNCTION_NAME', api_info)


def check_small_hump(api_info):
    return processing_check_data('SMALL_HUMP', api_info)


def check_all_uppercase_hump(api_info):
    return processing_check_data('ALL_UPPERCASE_HUMP', api_info)


def check_global_variable(api_info):
    return processing_check_data('GLOBAL_VARIABLE', api_info)


def check_file_name(file_path):
    api_result_info_list = []
    file_name = os.path.basename(file_path)
    result = re.match(CheckName['FILE_NAME'].value, file_name)
    if result is None:
        error_info = ErrorMessage.TRANSLATION_UNIT.value
        api_result_info = ApiResultInfo(ErrorType.NAMING_ERRORS.value, error_info, '')
        api_result_info.set_type(LogType.LOG_FILE.value)
        api_result_info.set_level(2)
        api_result_info_list.append(api_result_info)
    return api_result_info_list


def processing_check_data(function_type, api_info):
    api_result_info_list = []
    name = api_info['name']
    result = re.match(CheckName[function_type].value, name)
    if result is None:
        api_result_info = ApiResultInfo(ErrorType.NAMING_ERRORS.value,
                                        ErrorMessage[api_info['kind']].value, name)
        api_result_info.set_location_line(api_info['location']['location_line'])
        api_result_info.set_location_column(api_info['location']['location_column'])
        api_result_info.set_location(api_info['location']['location_path'])
        api_result_info.set_type(LogType.LOG_API.value)
        api_result_info.set_level(2)
        api_result_info.set_file_name(api_info['location']['location_path'])
        api_result_info_list.append(api_result_info)
    return api_result_info_list


class CheckName(enum.Enum):
    LARGE_HUMP = r'^([A-Z][a-z0-9]*)*$'
    SMALL_HUMP = r'^([a-z][A-Z0-9]*)*$'
    ALL_UPPERCASE_HUMP = r'^[A-Z]+[0-9]*([\_][A-Z0-9]+)*$'
    GLOBAL_VARIABLE = r'^g_([a-z][A-Z0-9]*)*$'
    FILE_NAME = r'^[a-z]+[a-z0-9]+([\_][a-z0-9]+)*\.h$'
    CHECK_FUNCTION_NAME = r'^([OH|OS]+([\_]([A-Z]+[a-z0-9]*)+)*)|(([A-Z][a-z0-9]*)*)$'


process_tag_function = {
    'FUNCTION_DECL': check_function_name,
    'STRUCT_DECL': check_large_hump,
    'ENUM_DECL': check_large_hump,
    'UNION_DECL': check_large_hump,
    'VAR_DECL': check_small_hump,
    'PARM_DECL': check_small_hump,
    'FIELD_DECL': check_small_hump,
    'MACRO_DEFINITION': check_all_uppercase_hump,
    'ENUM_CONSTANT_DECL': check_all_uppercase_hump,
}


def check_ndk_name(api_info) -> list[ApiResultInfo]:
    api_result_info_list = []
    kind = api_info['kind']
    if kind not in process_tag_function.keys():
        return api_result_info_list
    name_process = process_tag_function[kind]
    return name_process(api_info)
