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
 * @brief Provides get resourcemanager interface.

 *
 * @since 13
 * @version 1.0
 */

/**
 * @file native_context.h
 *
 * @brief Declare interfaces for creating and destroying native resourceManager.
 *
 * @library libnative_context.z.so
 * @syscap SystemCapability.Ability.AbilityRuntime.AbilityCore
 * @since 13
 * @version 1.0
 */
#ifndef ABILITY_ABILITY_RUNTIME_CONTEXT_NATIVE_CONTEXT_H
#define ABILITY_ABILITY_RUNTIME_CONTEXT_NATIVE_CONTEXT_H

#include <stdint.h>
#include "raw_file_manager.h"
#ifdef __cplusplus
extern "C" {
#endif

struct NativeResourceManager;
/**
 * @brief Bind native rresourceManager with system.
 * 
 * @return Returns the pointer to {@link NativeResourceManager}. If failed returns nullptr.       
 * @since 12
 * @version 1.0
 */
NativeResourceManager *OH_ApplicationContext_BindNativeResourceManager();

/**
 * @brief Release native rresourceManager with system.
 *    
 * @since 12
 * @version 1.0
 */
void OH_ApplicationContext_ReleaseNativeResourceManager(NativeResourceManager *resMgr);

/**
 * @brief Create native rresourceManager with modulename.
 *
 * @param moduleName Indicates the moduleName.
 * @return Returns the pointer to {@link NativeResourceManager}. If failed returns nullptr.       
 * @since 12
 * @version 1.0
 */
NativeResourceManager *OH_ApplicationContext_CreateNativeResourceManager(char *moduleName);

/**
 * @brief Delete native rresourceManager.
 *
 * @param resMgr Indicates the pointer to {@link RawDir}.
 * @return Returns the pointer to {@link NativeResourceManager}. If failed returns nullptr.       
 * @since 12
 * @version 1.0
 */
void OH_ApplicationContext_DeleteNativeResourceManager(NativeResourceManager *resMgr);

#ifdef __cplusplus
};
#endif
/** @} */
#endif  // ABILITY_ABILITY_RUNTIME_RUNTIME_H