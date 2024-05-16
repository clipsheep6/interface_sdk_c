/*
 * Copyright (c) 2022-2023 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @addtogroup rawfile
 * @{
 *
 * @brief Provides native functions for the resource manager to operate raw file directories and their raw files.
 *
 * You can use the resource manager to traverse, open, seek, read, and close raw files.
 *
 * @since 8
 * @version 1.0
 */

/**
 * @file raw_file_manager.h
 *
 * @brief Declares native functions for the resource manager.
 *
 * You can use the resource manager to open raw files for subsequent operations, such as seeking and reading.
 *
 * @since 8
 * @version 1.0
 */
#ifndef GLOBAL_RAW_FILE_MANAGER_H
#define GLOBAL_RAW_FILE_MANAGER_H

#include "napi/native_api.h"
#include "raw_dir.h"
#include "raw_file.h"

#ifdef __cplusplus
extern "C" {
#endif

struct NativeResourceManager;

/**
 * @brief Presents the resource manager.
 *
 * This class encapsulates the native implementation of the JavaScript resource manager. The pointer to a
 * <b>ResourceManager</b> object can be obtained by calling {@link OH_ResourceManager_InitNativeResourceManager}.
 *
 * @since 8
 * @version 1.0
 */
typedef struct NativeResourceManager NativeResourceManager;

enum ResourceManager_ErrorCode{
    SUCCESS == 0;
    ERROR_CODE_INVALID_INPUT_PARAMETER = 401,
    ERROR_CODE_RES_ID_NOT_FOUND        = 9001001,
    ERROR_CODE_RES_NOT_FOUND_BY_ID     = 9001002,
    ERROR_CODE_RES_NAME_NOT_FOUND      = 9001003,
    ERROR_CODE_RES_NOT_FOUND_BY_NAME   = 9001004,
    ERROR_CODE_RES_PATH_INVALID        = 9001005,
    ERROR_CODE_RES_REF_TOO_MUCH        = 9001006,
    ERROR_CODE_RES_ID_FORMAT_ERROR     = 9001007,
    ERROR_CODE_RES_NAME_FORMAT_ERROR   = 9001008,
    ERROR_CODE_SYSTEM_RES_MANAGER_GET_FAILED = 9001009,
    ERROR_CODE_OVERLAY_RES_PATH_INVALID = 9001010,
};

/**
 * @brief Obtains the native resource manager based on the JavaScipt resource manager.
 *
 * You need to obtain the resource manager to process raw files as required.
 *
 * @param env Indicates the pointer to the JavaScipt Native Interface (napi) environment.
 * @param jsResMgr Indicates the JavaScipt resource manager.
 * @return Returns the pointer to {@link NativeResourceManager}.
 * @since 8
 * @version 1.0
 */
NativeResourceManager *OH_ResourceManager_InitNativeResourceManager(napi_env env, napi_value jsResMgr);

/**
 * @brief Releases the native resource manager.
 *
 *
 *
 * @param resMgr Indicates the pointer to {@link RawDir}.
 * @since 8
 * @version 1.0
 */
void OH_ResourceManager_ReleaseNativeResourceManager(NativeResourceManager *resMgr);

#ifdef __cplusplus
};
#endif

/** @} */
#endif // GLOBAL_NATIVE_RESOURCE_MANAGER_H
