/*
 * Copyright (c) 2024 Huawei Device Co., Ltd.
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
 * @addtogroup DlpPermissionApi
 * @{
 *
 * @brief Provides the capability to access the data loss prevention (DLP) files.
 *
 * @since 12
 */

/**
 * @file dlp_permission_api.h
 *
 * @brief Declares the APIs for accessing the data loss prevention (DLP) files.
 *
 * @library libohdlp_permission.so
 * @kit DataProtectionKit
 * @syscap SystemCapability.Security.DataLossPrevention
 * @since 12
 */

#ifndef DLP_PERMISSION_API_H
#define DLP_PERMISSION_API_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Enumerates the error codes.
 *
 * @since 12
 */
typedef enum {
    /** The operation is successful. */
    ERR_OH_SUCCESS = 0,
    /** Invalid parameter value. */
    ERR_OH_INVALID_PARAMETER = 19100001,
    /** No permission to call this API, which is available only for DLP sandbox applications. */
    ERR_OH_API_ONLY_FOR_SANDBOX_ERROR = 19100006,
    /** No permission to call this API, which is available only for non-DLP sandbox applications. */
    ERR_OH_API_NOT_FOR_SANDBOX_ERROR = 19100007,
    /** The system ability works abnormally. */
    ERR_OH_SYSTEM_SERVICE_EXCEPTION = 19100011,
    /** Indicates the memory error. */
    ERR_OH_OUT_OF_MEMORY = 19100012,
    /** DisplayName missing in want. */
    ERR_OH_APPLICATION_NOT_AUTHORIZED = 19100018
} DLP_ErrCode;

/**
 * @brief Enumerates the access permissions for a DLP file.
 *
 * @since 12
 */
typedef enum {
    /** No permission. */
    NO_PERMISSION = 0,
    /** Read-only. */
    READ_ONLY = 1,
    /** Edit. */
    CONTENT_EDIT = 2,
    /** Full control. */
    FULL_CONTROL = 3
} DLP_FileAccess;

/**
 * @brief Represents the permission info of a DLP file.
 *
 * @since 12
 */
typedef struct {
     /**
     * Access permission for the DLP file.
     */
    DLP_FileAccess dlpFileAccess;
    /**
     * Actions allowed for the DLP file.
     */
    uint32_t flags;
} DLP_PermissionInfo;

/**
 * @brief Obtains the permission info of this DLP file.
 *
 * @param info - Indicates output parameter about {@link DLP_PermissionInfo}.
 * @return {@link DLP_ErrCode#ERR_OH_SUCCESS} 0 - If the operation is successful.
 *         {@link DLP_ErrCode#ERR_OH_INVALID_PARAMETER} 19100001 - If the parameter value is invalid.
 *         {@link DLP_ErrCode#ERR_OH_API_ONLY_FOR_SANDBOX_ERROR} 19100006 - If No permission to
 *             call this API, which is available only for DLP sandbox applications.
 *         {@link DLP_ErrCode#ERR_OH_SYSTEM_SERVICE_EXCEPTION} 19100011 - If the system ability
 *             works abnormally.
 * @since 12
 */
DLP_ErrCode OH_DLP_GetDLPPermissionInfo(DLP_PermissionInfo *info);

/**
 * @brief Obtains the original file name from a DLP file name.
 *        This method removes the DLP file name extension from the DLP file name.
 *
 * @param fileName - Indicates the DLP file name.
 * @param originalFileName - Indicates the original file name obtained.
 * @return {@link DLP_ErrCode#ERR_OH_SUCCESS} 0 - If the operation is successful.
 *         {@link DLP_ErrCode#ERR_OH_INVALID_PARAMS} 19100001 - If the parameter value is invalid.
 * @since 12
 */
DLP_ErrCode OH_DLP_GetOriginalFileName(const char *fileName, char *originalFileName);

/**
 * @brief Obtains the original file name from a DLP file name.
 *        This method removes the DLP file name extension from the DLP file name.
 *
 * @param fileName - Indicates the DLP file name.
 * @param suffixFileName - Indicates the suffix file name obtained.
 * @return {@link DLP_ErrCode#ERR_OH_SUCCESS} 0 - If the operation is successful.
 *         {@link DLP_ErrCode#ERR_OH_OUT_OF_MEMORY} 19100012 - If the memory error.
 * @since 12
 */
DLP_ErrCode OH_DLP_GetDLPSuffix(char *suffixFileName);

/**
 * @brief Checks whether current application is in the DLP sandbox. This method uses a promise to return the result.
 *
 * @param isInSandbox - Indicates output parameter;
                        {@code true} if current application is in a DLP sandbox, {@code false} otherwise.
 * @return {@link DLP_ErrCode#ERR_OH_SUCCESS} 0 - If the operation is successful.
 *         {@link DLP_ErrCode#ERR_OH_SYSTEM_SERVICE_EXCEPTION} 19100011 - If the system ability
 *             works abnormally.
 *         {@link DLP_ErrCode#ERR_OH_OUT_OF_MEMORY} 19100012 - If the memory error.
 * @since 12
 */
DLP_ErrCode OH_DLP_IsInSandbox(bool *isInSandbox);

/**
 * @brief Sets sandbox application configuration. This method uses a promise to return the result.
 *
 * @param configInfo - Configuration of the sandbox application.
 * @return {@link DLP_ErrCode#ERR_OH_SUCCESS} 0 - If the operation is successful.
 *         {@link DLP_ErrCode#ERR_OH_INVALID_PARAMETER} 19100001 - If the parameter value is invalid.
 *         {@link DLP_ErrCode#ERR_OH_API_NOT_FOR_SANDBOX_ERROR} 19100007 - If No permission to
 *             call this API, which is available only for non-DLP sandbox applications.
 *         {@link DLP_ErrCode#ERR_OH_SYSTEM_SERVICE_EXCEPTION} 19100011 - If the system ability
 *             works abnormally.
 *         {@link DLP_ErrCode#ERR_OH_APPLICATION_NOT_AUTHORIZED} 19100018 - Not authorized application.
 * @since 12
 */
DLP_ErrCode OH_DLP_SetSandboxAppConfig(const char *configInfo);

/**
 * @brief Obtains sandbox application configuration. This method uses a promise to return the result.
 *
 * @param configInfo - Configuration of the sandbox application.
 * @return {@link DLP_ErrCode#ERR_OH_SUCCESS} 0 - If the operation is successful.
 *         {@link DLP_ErrCode#ERR_OH_SYSTEM_SERVICE_EXCEPTION} 19100011 - If the system ability
 *             works abnormally.
 *         {@link DLP_ErrCode#ERR_OH_OUT_OF_MEMORY} 19100012 - If the memory error.
 *         {@link DLP_ErrCode#ERR_OH_APPLICATION_NOT_AUTHORIZED} 19100018 - Not authorized application.
 * @since 12
 */
DLP_ErrCode OH_DLP_GetSandboxAppConfig(char *configInfo);

/**
 * @brief Cleans sandbox application configuration. This method uses a promise to return the result.
 *
 * @return {@link DLP_ErrCode#ERR_OH_SUCCESS} 0 - If the operation is successful.
 *         {@link DLP_ErrCode#ERR_OH_API_NOT_FOR_SANDBOX_ERROR} 19100007 - If No permission to
 *             call this API, which is available only for non-DLP sandbox applications.
 *         {@link DLP_ErrCode#ERR_OH_SYSTEM_SERVICE_EXCEPTION} 19100011 - If the system ability
 *             works abnormally.
 *         {@link DLP_ErrCode#ERR_OH_APPLICATION_NOT_AUTHORIZED} 19100018 - Not authorized application.
 * @since 12
 */
DLP_ErrCode OH_DLP_CleanSandboxAppConfig();

#ifdef __cplusplus
}
#endif

/** @} */
#endif /* DLP_PERMISSION_API_H */