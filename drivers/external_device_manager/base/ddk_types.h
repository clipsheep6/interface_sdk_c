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
#ifndef DDK_TYPES_H
#define DDK_TYPES_H

/**
 * @addtogroup Ddk
 * @{
 *
 * @brief Provides Base DDK types and declares the macros, enums, and\n
 * data structs used by the Base DDK APIs.
 *
 * @since 12
 */

/**
 * @file usb_ddk_types.h
 *
 * @brief Provides the enums, structs, and macros used in USB Base APIs.
 *
 * @syscap SystemCapability.Driver.DDK.Extension
 * @since 12
 */

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * @brief Defines the shared memory created by using <b>OH_DDK_CreateAShMem</b>.\n
 * A buffer for the shared memory provides better performance.
 *
 * @since 12
 */
typedef struct DDK_ASharedMem {
    /** File descriptor of the shared memory. */
    int32_t aShMemFd;
    /** Buffer address. */
    uint8_t * const address;
    /** Buffer size. */
    const size_t size;
    /** Offset of the used buffer. The default value is 0, which indicates that there is no offset\n
     * and the buffer starts from the specified address.
     */
    uint32_t offset;
    /** Length of the used buffer. By default, the value is equal to the size, which indicates that\n
     * the entire buffer is used.
     */
    uint32_t bufferLength;
    /** Length of the transferred data. */
    uint32_t transferredLength;
} DDK_ASharedMem;

/**
 * @brief Enumerates the permissions on the mapped memory.
 *
 * @since 12
 */
typedef enum {
    /** The mapped memory is inaccessible. */
    PROT_NONE = 0,
    /** The mapped memory is readable. */
    PROT_READ = 1,
    /** The mapped memory is writable. */
    PROT_WRITE = 2,
    /** The mapped memory is executable. */
    PROT_EXEC = 4

} DDK_ASharedMemMapType;

/**
 * @brief Enumerates the error codes used in the Base DDK.
 *
 * @since 12
 */
typedef enum {
    /** Operation success */
    DDK_SUCCESS = 0,
    /** Operation failed */
    DDK_FAILURE = -1,
    /** Invalid parameter */
    DDK_INVALID_PARAMETER = -2,
    /** Invalid operation */
    DDK_INVALID_OPERATION = -3,
    /** Null pointer exception */
    DDK_NULL_PTR = -4
} DDK_RetCode;
#ifdef __cplusplus
}
/** @} */
#endif /* __cplusplus */
#endif // DDK_TYPES_H
