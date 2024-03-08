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
#ifndef DDK_API_H
#define DDK_API_H

/**
 * @addtogroup Ddk
 * @{
 *
 * @brief Provides Base DDK APIs, including creating the shared memory, mapping the shared memory,\n
 * unmapping the shared memory, and destroying the shared memory.
 *
 * @since 12
 */

/**
 * @file ddk_api.h
 *
 * @brief Declares the Base DDK APIs.
 *
 * @syscap SystemCapability.Driver.DDK.Extension
 * @since 12
 */

#include <stdint.h>
#include "ddk_types.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * @brief Creates shared memory. To prevent resource leakage, destroy the shared memory that is not required by\n
 * calling <b>OH_DDK_DestroyAShMem</b>.
 *
 * @param name Pointer to the shared memory to create.
 * @param size Size of the buffer corresponding to the shared memory.
 * @param aSharedMem Pointer to the shared memory created.
 * @return Returns <b>DDK_SUCCESS</b> if the operation is successful; returns a negative value otherwise.
 * @since 12
 */
DDK_RetCode OH_DDK_CreateAShMem(const uint8_t *name, size_t size, DDK_ASharedMem **aSharedMem);

/**
 * @brief Maps the created shared memory to the user space. Unmap the shared memory that is not required by using\n
 * <b>OH_DDK_UnMapAShMem</b>.
 *
 * @param aShMemFd File descriptor of the shared memory to map.
 * @param aShMemMapType Protection permission value of the shared memory.
 * @return Returns <b>DDK_SUCCESS</b> if the operation is successful; returns a negative value otherwise.
 * @since 12
 */
DDK_RetCode OH_DDK_MapAShMem(const int32_t aShMemFd, const uint8_t aShMemMapType);

/**
 * @brief Unmaps shared memory.
 *
 * @param aShMemFd File descriptor of the shared memory to unmap.
 * @return Returns <b>DDK_SUCCESS</b> if the operation is successful; returns a negative value otherwise.
 * @since 12
 */
DDK_RetCode OH_DDK_UnMapAShMem(const int32_t aShMemFd);

/**
 * @brief Destroys shared memory.
 *
 * @param aShMemFd File descriptor of the shared memory to destroy.
 * @return Returns <b>DDK_SUCCESS</b> if the operation is successful; returns a negative value otherwise.
 * @since 12
 */
DDK_RetCode OH_DDK_DestroyAShMem(const int32_t aShMemFd);
/** @} */
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif // DDK_API_H
