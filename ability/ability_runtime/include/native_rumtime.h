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
 * @addtogroup Ability_Runtime
 * @{
 *
 * @brief Provides runtime environment.

 *
 * @since 12
 * @version 1.0
 */

/**
 * @file native_rumtime.h
 *
 * @brief Declare interfaces for creating and destroying runtime environments.
 *
 * @library libruntime_ndk.z.so
 * @syscap SystemCapability.Ability.AbilityRuntime.AbilityCore
 * @since 12
 * @version 1.0
 */
#ifndef ABILITY_ABILITY_RUNTIME_NATIVE_RUNTIME_H
#define ABILITY_ABILITY_RUNTIME_NATIVE_RUNTIME_H

#include <stdint.h>
#include "napi/native_api.h"
#ifdef __cplusplus
extern "C" {
#endif
/**
 * @brief Create runtime environment.
 * 
 * @param env: The environment that the API is invoked under.
 * @return 0 - 成功。
 *         1 - 超出最大运行时环境数量上限。
 *         2 - 一个线程只允许创建一个运行时环境。
 *         4 - 内部错误。
 * @since 12
 * @version 1.0
 */
int32_t OH_NativeAbility_Create_NapiEnv(napi_env *env);


/**
 * @brief Destroy runtime environment.
 *
 * @param env: The environment that the API is invoked under.
 * @return 0 - 成功。
 *         3 - 销毁失败。
 * @since 12
 * @version 1.0
 */
int32_t OH_NativeAbility_Destroy_NapiEnv(napi_env *env);

#ifdef __cplusplus
};
#endif
/** @} */
#endif  // ABILITY_ABILITY_RUNTIME_RUNTIME_H