/*
 * Copyright (c) 2024-2025 Huawei Device Co., Ltd.
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

#ifndef GLOBAL_NATIVE_RESOURCE_MANAGER_H
#define GLOBAL_NATIVE_RESOURCE_MANAGER_H

#include "native_common.h"

#ifdef __cplusplus
extern "C" {
#endif

ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64(const NativeResourceManager *mgr, uint32_t resId, char **resultValue, uint64_t *resultLen, uint32_t density = 0);

ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64ByName(const NativeResourceManager *mgr, const char *resName, char **resultValue, uint64_t *resultLen, uint32_t density = 0);

ResourceManager_ErrorCode OH_ResourceManager_GetMedia(const NativeResourceManager *mgr, uint32_t resId, unit8_t **resultValue, uint64_t *resultLen, uint32_t density = 0);

ResourceManager_ErrorCode OH_ResourceManager_GetMediaByname(const NativeResourceManager *mgr, const char *resName, unit8_t **resultValue, uint64_t *resultLen, uint32_t density = 0);

ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptor(const NativeResourceManager *mgr, uint32_t resId, ArkUI_DrawableDescriptor **drawableDescriptor, uint32_t density = 0, uint32_t type = 0);

ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptorByName(const NativeResourceManager *mgr, char *resName, ArkUI_DrawableDescriptor **drawableDescriptor, uint32_t density = 0, uint32_t type = 0);

ResourceManager_ErrorCode OH_ResourceManager_GetSymbol(const NativeResourceManager *mgr, uint32_t resId,  uint32_t *resultValue);

ResourceManager_ErrorCode OH_ResourceManager_GetSymbolByName(const NativeResourceManager *mgr, const char *resName, uint32_t *resultValue);

ResourceManager_ErrorCode OH_ResourceManager_GetLocales(char **resultValue, uint32_t *resultLen, bool includeSystem = false);

ResourceManager_ErrorCode OH_ResourceManager_GetDeviceCapability(const NativeResourceManager *mgr, DeviceCapability *deviceCapability);

ResourceManager_ErrorCode OH_ResourceManager_GetConfiguration(const NativeResourceManager *mgr, Configuration *configuration);

ResourceManager_ErrorCode OH_ResourceManager_GetString(const NativeResourceManager *mgr, uint32_t resId, char **resultValue, ...);

ResourceManager_ErrorCode OH_ResourceManager_GetStringByName(const NativeResourceManager *mgr, const char *resName, char **resultValue, ...);

ResourceManager_ErrorCode OH_ResourceManager_GetStringArray(const NativeResourceManager *mgr, uint32_t resId, char ***resultValue, uint32_t *resultLen);

ResourceManager_ErrorCode OH_ResourceManager_GetStringArrayByName(const NativeResourceManager *mgr, const char *resName, char ***resultValue, uint32_t *resultLen);

ResourceManager_ErrorCode OH_ResourceManager_ReleaseStringArray(char ***resValue, uint32_t *len);

ResourceManager_ErrorCode OH_ResourceManager_GetPluralString(const NativeResourceManager *mgr, uint32_t resId, uint32_t num, char **resultValue);

ResourceManager_ErrorCode OH_ResourceManager_GetPluralStringByName(const NativeResourceManager *mgr, const char *resName, uint32_t num, char **resultValue);

ResourceManager_ErrorCode OH_ResourceManager_GetColor(const NativeResourceManager *mgr, uint32_t resId,  uint32_t *resultValue);

ResourceManager_ErrorCode OH_ResourceManager_GetColorByName(const NativeResourceManager *mgr, const char *resName, uint32_t *resultValue);

ResourceManager_ErrorCode OH_ResourceManager_GetInt(const NativeResourceManager *mgr, uint32_t resId,  int *resultValue);

ResourceManager_ErrorCode OH_ResourceManager_GetIntByName(const NativeResourceManager *mgr, const char *resName, int *resultValue);

ResourceManager_ErrorCode OH_ResourceManager_GetFloat(const NativeResourceManager *mgr, uint32_t resId,  float *resultValue);

ResourceManager_ErrorCode OH_ResourceManager_GetFloatByName(const NativeResourceManager *mgr, const char *resName, float *resultValue);

ResourceManager_ErrorCode OH_ResourceManager_GetBool(const NativeResourceManager *mgr, uint32_t resId,  bool *resultValue);

ResourceManager_ErrorCode OH_ResourceManager_GetBoolByName(const NativeResourceManager *mgr, const char *resName, bool *resultValue);

ResourceManager_ErrorCode OH_ResourceManager_AddResource(const NativeResourceManager *mgr, char *path);

ResourceManager_ErrorCode OH_ResourceManager_RemoveResource(const NativeResourceManager *mgr, char *path);
#ifdef __cplusplus
};
#endif

/** @} */
#endif // GLOBAL_NATIVE_RESOURCE_MANAGER_H