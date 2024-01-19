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

#ifndef ACCESSTOKEN_INTERFACES_KITS_C_ACCESSTOKEN_NDK_API_H
#define ACCESSTOKEN_INTERFACES_KITS_C_ACCESSTOKEN_NDK_API_H

#include <stdbool.h>
#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif

struct RequestResult {
    const char* permission;
    bool isDialogShow;
    int authResult;
};

int32_t OH_AccessToken_VerifyAccessToken(unsigned int tokenid, const char* permission);

/**
 * @brief request permission.
 * 
 * @param env Indicates the pointer to the JavaScript Native Interface (napi) environment.
 * @param abilitycontext Indicates the pointer to the JavaScript ability context.
 * @param permissionList Indicates the permission list to be requested.
 * @param permissionSize Indicates the permission list size.
 * @param callback Indicates the permission request event callback.
 * @return Returns the status code of the execution.
 * @since 12
 * @version 1.0
*/
// int32_t OH_AccessToken_RequestPermissionFromUser(
//     NativeContext* abilitycontext, char** permissionList, int permissionSize, void (*callback)(RequestResult* result);

#ifdef __cplusplus
}
#endif

/** @} */
#endif /* ACCESSTOKEN_INTERFACES_KITS_C_ACCESSTOKEN_NDK_API_H */
