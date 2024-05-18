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

#ifndef GLOBAL_NATIVE_RESOURCE_MANAGER_H
#define GLOBAL_NATIVE_RESOURCE_MANAGER_H

#include "native_common.h"

#ifdef __cplusplus
extern "C" {
#endif
/**
 * @brief Obtains the Base64 code of the image resource.
 *
 * Obtains the Base64 code of the image resource corresponding to the specified resource ID in callback mode.
 *
 * @param mgr Indicates the pointer to {@link NativeResourceManager}
 * {@link OH_ResourceManager_InitNativeResourceManager}.
 * @param resId Indicates the resource ID.
 * @param density The optional parameter ScreenDensity A value of 0 means to use the density of current system dpi.
 * @param resultValue the result write to resultValue.
 * @param resultLen the media length write to resultLen.
 * @return { BusinessError } 401 - If the input parameter invalid. Possible causes: Incorrect parameter types.
           { BusinessError } 9001001 - Invalid resource ID.
           { BusinessError } 9001002 - No matching resource is found based on the resource ID.
 * @since 12
 * @version 1.0
 */
ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64(const NativeResourceManager *mgr, uint32_t resId, char **resultValue, uint64_t *resultLen, uint32_t density = 0);

/**
 * @brief Obtains the Base64 code of the image resource.
 *
 * Obtains the Base64 code of the image resource corresponding to the specified resource Name in callback mode.
 *
 * @param mgr Indicates the pointer to {@link NativeResourceManager}
 * {@link OH_ResourceManager_InitNativeResourceManager}.
 * @param resName Indicates the resource name.
 * @param density The optional parameter ScreenDensity A value of 0 means to use the density of current system dpi.
 * @param resultValue the result write to resultValue.
 * @param resultLen the media length write to resultLen.
 * @return { BusinessError } 401 - If the input parameter invalid. Possible causes: Incorrect parameter types
           { BusinessError } 9001003 - Invalid resource name.
           { BusinessError } 9001004 - No matching resource is found based on the resource name.
 * @since 12
 * @version 1.0
 */
ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64ByName(const NativeResourceManager *mgr, const char *resName, char **resultValue, uint64_t *resultLen, uint32_t density = 0);

/**
 * @brief Obtains the content of the image resource.
 *
 * Obtains the content of the specified screen density media file corresponding to a specified resource ID.
 *
 * @param mgr Indicates the pointer to {@link NativeResourceManager}
 * {@link OH_ResourceManager_InitNativeResourceManager}.
 * @param resId Indicates the resource ID.
 * @param density The optional parameter ScreenDensity A value of 0 means to use the density of current system dpi.
 * @param resultValue the result write to resultValue.
 * @param resultLen the media length write to resultLen.
 * @return { BusinessError } 401 - If the input parameter invalid. Possible causes: Incorrect parameter types.
           { BusinessError } 9001001 - Invalid resource ID.
           { BusinessError } 9001002 - No matching resource is found based on the resource ID.
 * @since 12
 * @version 1.0
 */
ResourceManager_ErrorCode OH_ResourceManager_GetMedia(const NativeResourceManager *mgr, uint32_t resId, unit8_t **resultValue, uint64_t *resultLen, uint32_t density = 0);

/**
 * @brief Obtains the content of the image resource.
 *
 * Obtains the content of the specified screen density media file corresponding to a specified resource Name.
 *
 * @param mgr Indicates the pointer to {@link NativeResourceManager}
 * {@link OH_ResourceManager_InitNativeResourceManager}.
 * @param resName Indicates the resource name.
 * @param density The optional parameter ScreenDensity A value of 0 means to use the density of current system dpi.
 * @param resultValue the result write to resultValue.
 * @param resultLen the media length write to resultLen.
 * @return { BusinessError } 401 - If the input parameter invalid. Possible causes: Incorrect parameter types
           { BusinessError } 9001003 - Invalid resource name.
           { BusinessError } 9001004 - No matching resource is found based on the resource name.
 * @since 12
 * @since 12
 * @version 1.0
 */
ResourceManager_ErrorCode OH_ResourceManager_GetMediaByname(const NativeResourceManager *mgr, const char *resName, unit8_t **resultValue, uint64_t *resultLen, uint32_t density = 0);

/**
 * @brief Obtains the DrawableDescriptor of the media file.
 *
 * Obtains the DrawableDescriptor of the media file corresponding to a specified resource ID.
 *
 * @param mgr Indicates the pointer to {@link NativeResourceManager}
 * {@link OH_ResourceManager_InitNativeResourceManager}.
 * @param resId Indicates the resource ID.
 * @param density The optional parameter ScreenDensity A value of 0 means to use the density of current system dpi.
 * @param type The optional parameter means the media type, the default value 0 means the normal media.
 * @param drawableDescriptor the result write to drawableDescriptor.
 * @return { BusinessError } 401 - If the input parameter invalid. Possible causes: Incorrect parameter types.
           { BusinessError } 9001001 - Invalid resource ID.
           { BusinessError } 9001002 - No matching resource is found based on the resource ID.
 * @since 12
 * @version 1.0
 */
ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptor(const NativeResourceManager *mgr, uint32_t resId, ArkUI_DrawableDescriptor **drawableDescriptor, uint32_t density = 0, uint32_t type = 0);

/**
 * @brief Obtains the DrawableDescriptor of the media file.
 *
 * Obtains the DrawableDescriptor of the media file corresponding to a specified resource Name.
 * @param mgr Indicates the pointer to {@link NativeResourceManager}
 * {@link OH_ResourceManager_InitNativeResourceManager}.
 * @param resName Indicates the resource name.
 * @param density The optional parameter ScreenDensity A value of 0 means to use the density of current system dpi.
 * @param type The optional parameter means the media type, the default value 0 means the normal media.
 * @param drawableDescriptor the result write to drawableDescriptor.
 * @return { BusinessError } 401 - If the input parameter invalid. Possible causes: Incorrect parameter types
           { BusinessError } 9001003 - Invalid resource name.
           { BusinessError } 9001004 - No matching resource is found based on the resource name.
 * @since 12
 * @version 1.0
 */
ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptorByName(const NativeResourceManager *mgr, char *resName, ArkUI_DrawableDescriptor **drawableDescriptor, uint32_t density = 0, uint32_t type = 0);

/**
 * @brief Obtains the symbol resource.
 *
 * Obtains the symbol resource corresponding to the specified resource ID.
 *
 * @param mgr Indicates the pointer to {@link NativeResourceManager}
 * {@link OH_ResourceManager_InitNativeResourceManager}.
 * @param resId Indicates the resource ID.
 * @param resultValue the result write to resultValue.
 * @return { BusinessError } 401 - If the input parameter invalid. Possible causes: Incorrect parameter types.
           { BusinessError } 9001001 - Invalid resource ID.
           { BusinessError } 9001002 - No matching resource is found based on the resource ID.
 * @since 12
 * @version 1.0
 */
ResourceManager_ErrorCode OH_ResourceManager_GetSymbol(const NativeResourceManager *mgr, uint32_t resId,  uint32_t *resultValue);

/**
 * @brief Obtains the symbol resource.
 *
 * Obtains the symbol resource corresponding to the specified resource Name.
 *
 * @param mgr Indicates the pointer to {@link NativeResourceManager}
 * {@link OH_ResourceManager_InitNativeResourceManager}.
 * @param resId Indicates the resource ID.
 * @param resultValue the result write to resultValue.
 * @return { BusinessError } 401 - If the input parameter invalid. Possible causes: Incorrect parameter types
           { BusinessError } 9001003 - Invalid resource name.
           { BusinessError } 9001004 - No matching resource is found based on the resource name.
 * @since 12
 * @version 1.0
 */
ResourceManager_ErrorCode OH_ResourceManager_GetSymbolByName(const NativeResourceManager *mgr, const char *resName, uint32_t *resultValue);

/**
 * @brief Obtains locales list.
 * @param resultValue the result write to resultValue.
 * @param resultLen the locales length write to resultLen.
 * @param includeSystem the parameter controls whether to include system resources,
 *     the default value is false, it has no effect when only system resources query the locales list.
 * @return { BusinessError } 401 - If the input parameter invalid. Possible causes: Incorrect parameter types
 * @since 12
 * @version 1.0
 */
ResourceManager_ErrorCode OH_ResourceManager_GetLocales(char **resultValue, uint32_t *resultLen, bool includeSystem = false);

/**
 * @brief Obtains the device capability.
 * @param mgr Indicates the pointer to {@link NativeResourceManager}
 * {@link OH_ResourceManager_InitNativeResourceManager}.
 * @param deviceCapability the result write to deviceCapability.
 * @since 12
 * @version 1.0
 */
ResourceManager_ErrorCode OH_ResourceManager_GetDeviceCapability(const NativeResourceManager *mgr, DeviceCapability *deviceCapability);

/**
 * @brief Obtains the device configuration.
 * @param mgr Indicates the pointer to {@link NativeResourceManager}
 * {@link OH_ResourceManager_InitNativeResourceManager}.
 * @param configuration the result write to configuration.
 * @since 12
 * @version 1.0
 */
ResourceManager_ErrorCode OH_ResourceManager_GetConfiguration(const NativeResourceManager *mgr, Configuration *configuration);

/**
 * @brief Obtains the character string.
 * 
 * Obtains the character string corresponding to a specified resource ID.
 * 
 * @param mgr Indicates the pointer to {@link NativeResourceManager}
{@link OH_ResourceManager_InitNativeResourceManager}.
 * @param resId Indicates the resource ID.
 * @param resultValue the result write to resultValue.
 * @return { BusinessError } 401 - If the input parameter invalid. Possible causes: Incorrect parameter types.
           { BusinessError } 9001001 - Invalid resource ID.
           { BusinessError } 9001002 - No matching resource is found based on the resource ID.
 * @since 12
 * @version 1.0
 */
ResourceManager_ErrorCode OH_ResourceManager_GetString(const NativeResourceManager *mgr, uint32_t resId, char **resultValue, ...);

/**
 * @brief Obtains the character string.
 * 
 * Obtains the character string corresponding to a specified resource Name.
 * 
 * @param mgr Indicates the pointer to {@link NativeResourceManager}
 * {@link OH_ResourceManager_InitNativeResourceManager}.
 * @param resName Indicates the resource Name.
 * @param resultValue the result write to resultValue.
 * @return { BusinessError } 401 - If the input parameter invalid. Possible causes: Incorrect parameter types
           { BusinessError } 9001003 - Invalid resource name.
           { BusinessError } 9001004 - No matching resource is found based on the resource name.
 * @since 12
 * @version 1.0
 */
ResourceManager_ErrorCode OH_ResourceManager_GetStringByName(const NativeResourceManager *mgr, const char *resName, char **resultValue, ...);

/**
 * @brief Obtains the array of character strings.
 * 
 * Obtains the array of character strings corresponding to a specified resource ID.
 * 
 * @param mgr Indicates the pointer to {@link NativeResourceManager}
{@link OH_ResourceManager_InitNativeResourceManager}.
 * @param resId Indicates the resource ID.
 * @param resultValue the result write to resultValue.
 * @param resultLen the StringArray length write to resultLen.
 * @return { BusinessError } 401 - If the input parameter invalid. Possible causes: Incorrect parameter types.
           { BusinessError } 9001001 - Invalid resource ID.
           { BusinessError } 9001002 - No matching resource is found based on the resource ID.
 * @since 12
 * @version 1.0
 */
ResourceManager_ErrorCode OH_ResourceManager_GetStringArray(const NativeResourceManager *mgr, uint32_t resId, char ***resultValue, uint32_t *resultLen);

/**
 * @brief Obtains the array of character strings.
 * 
 * Obtains the array of character strings corresponding to a specified resource Name.
 * 
 * @param mgr Indicates the pointer to {@link NativeResourceManager}
{@link OH_ResourceManager_InitNativeResourceManager}.
 * @param resName Indicates the resource Name.
 * @param resultValue the result write to resultValue.
 * @param resultLen the StringArray length write to resultLen.
 * @return { BusinessError } 401 - If the input parameter invalid. Possible causes: Incorrect parameter types
           { BusinessError } 9001003 - Invalid resource name.
           { BusinessError } 9001004 - No matching resource is found based on the resource name.
 * @since 12
 * @version 1.0
 */
ResourceManager_ErrorCode OH_ResourceManager_GetStringArrayByName(const NativeResourceManager *mgr, const char *resName, char ***resultValue, uint32_t *resultLen);

/**
 * @brief Release the array of character strings.
 * @param resValue the array of character strings corresponding to the specified resource name.
 * @param len the length of array.
 * @return 
 * @since 12
 * @version 1.0
 */
ResourceManager_ErrorCode OH_ResourceManager_ReleaseStringArray(char ***resValue, uint32_t *len);

/**
 * @brief Obtains the singular-plural character string represented.
 * 
 * Obtains the singular-plural character string represented by the ID string corresponding to the
 * specified number.
 * 
 * @param mgr Indicates the pointer to {@link NativeResourceManager}
{@link OH_ResourceManager_InitNativeResourceManager}.
 * @param resId Indicates the resource ID.
 * @param resultValue the result write to resultValue.
 * @param resultLen the PluralString length write to resultLen.
 * @return { BusinessError } 401 - If the input parameter invalid. Possible causes: Incorrect parameter types.
           { BusinessError } 9001001 - Invalid resource ID.
           { BusinessError } 9001002 - No matching resource is found based on the resource ID.
 * @since 12
 * @version 1.0
 */
ResourceManager_ErrorCode OH_ResourceManager_GetPluralString(const NativeResourceManager *mgr, uint32_t resId, uint32_t num, char **resultValue);

/**
 * @brief Obtains the singular-plural character string represented.
 * 
 * Obtains the singular-plural character string represented by the Name string corresponding to the
 * specified number.
 * 
 * @param mgr Indicates the pointer to {@link NativeResourceManager}
{@link OH_ResourceManager_InitNativeResourceManager}.
 * @param resName Indicates the resource Name.
 * @param resultValue the result write to resultValue.
 * @param resultLen the PluralString length write to resultLen.
 * @return { BusinessError } 401 - If the input parameter invalid. Possible causes: Incorrect parameter types
           { BusinessError } 9001003 - Invalid resource name.
           { BusinessError } 9001004 - No matching resource is found based on the resource name.
 * @since 12
 * @version 1.0
 */
ResourceManager_ErrorCode OH_ResourceManager_GetPluralStringByName(const NativeResourceManager *mgr, const char *resName, uint32_t num, char **resultValue);

/**
 * @brief Obtains the color resource.
 * 
 * Obtains the color resource corresponding to the specified resource ID.
 * 
 * @param mgr Indicates the pointer to {@link NativeResourceManager}
{@link OH_ResourceManager_InitNativeResourceManager}.
 * @param resId Indicates the resource ID.
 * @param resultValue the result write to resultValue.
 * @return { BusinessError } 401 - If the input parameter invalid. Possible causes: Incorrect parameter types.
           { BusinessError } 9001001 - Invalid resource ID.
           { BusinessError } 9001002 - No matching resource is found based on the resource ID.
 * @since 12
 * @version 1.0
 */
ResourceManager_ErrorCode OH_ResourceManager_GetColor(const NativeResourceManager *mgr, uint32_t resId,  uint32_t *resultValue);

/**
 * @brief Obtains the color resource.
 * 
 * Obtains the color resource corresponding to the specified resource Name.
 * 
 * @param mgr Indicates the pointer to {@link NativeResourceManager}
{@link OH_ResourceManager_InitNativeResourceManager}.
 * @param resName Indicates the resource Name.
 * @param resultValue the result write to resultValue.
 * @return { BusinessError } 401 - If the input parameter invalid. Possible causes: Incorrect parameter types
           { BusinessError } 9001003 - Invalid resource name.
           { BusinessError } 9001004 - No matching resource is found based on the resource name.
 * @since 12
 * @version 1.0
 */
ResourceManager_ErrorCode OH_ResourceManager_GetColorByName(const NativeResourceManager *mgr, const char *resName, uint32_t *resultValue);

/**
 * @brief Obtains the Int resource.
 * 
 * Obtains the Int resource corresponding to the specified resource ID.
 * 
 * @param mgr Indicates the pointer to {@link NativeResourceManager}
{@link OH_ResourceManager_InitNativeResourceManager}.
 * @param resId Indicates the resource ID.
 * @param resultValue the result write to resultValue.
 * @return { BusinessError } 401 - If the input parameter invalid. Possible causes: Incorrect parameter types.
           { BusinessError } 9001001 - Invalid resource ID.
           { BusinessError } 9001002 - No matching resource is found based on the resource ID.
 * @since 12
 * @version 1.0
 */
ResourceManager_ErrorCode OH_ResourceManager_GetInt(const NativeResourceManager *mgr, uint32_t resId,  int *resultValue);

/**
 * @brief Obtains the Int resource.
 * 
 * Obtains the Int resource corresponding to the specified resource Name.
 * 
 * @param mgr Indicates the pointer to {@link NativeResourceManager}
{@link OH_ResourceManager_InitNativeResourceManager}.
 * @param resName Indicates the resource Name.
 * @param resultValue the result write to resultValue.
 * @return { BusinessError } 401 - If the input parameter invalid. Possible causes: Incorrect parameter types
           { BusinessError } 9001003 - Invalid resource name.
           { BusinessError } 9001004 - No matching resource is found based on the resource name.
 * @since 12
 * @version 1.0
 */
ResourceManager_ErrorCode OH_ResourceManager_GetIntByName(const NativeResourceManager *mgr, const char *resName, int *resultValue);

/**
 * @brief Obtains the Float resource.
 * 
 * Obtains the Int resource corresponding to the specified resource ID.
 * 
 * @param mgr Indicates the pointer to {@link NativeResourceManager}
{@link OH_ResourceManager_InitNativeResourceManager}.
 * @param resId Indicates the resource ID.
 * @param resultValue the result write to resultValue.
 * @return { BusinessError } 401 - If the input parameter invalid. Possible causes: Incorrect parameter types.
           { BusinessError } 9001001 - Invalid resource ID.
           { BusinessError } 9001002 - No matching resource is found based on the resource ID.
 * @since 12
 * @version 1.0
 */
ResourceManager_ErrorCode OH_ResourceManager_GetFloat(const NativeResourceManager *mgr, uint32_t resId,  float *resultValue);

/**
 * @brief Obtains the Float resource.
 * 
 * Obtains the Float resource corresponding to the specified resource Name.
 * 
 * @param mgr Indicates the pointer to {@link NativeResourceManager}
{@link OH_ResourceManager_InitNativeResourceManager}.
 * @param resName Indicates the resource Name.
 * @param resultValue the result write to resultValue.
 * @return { BusinessError } 401 - If the input parameter invalid. Possible causes: Incorrect parameter types
           { BusinessError } 9001003 - Invalid resource name.
           { BusinessError } 9001004 - No matching resource is found based on the resource name.
 * @since 12
 * @version 1.0
 */
ResourceManager_ErrorCode OH_ResourceManager_GetFloatByName(const NativeResourceManager *mgr, const char *resName, float *resultValue);

/**
 * @brief Obtains the boolean result.
 * 
 * Obtains the boolean result with a specified resource ID.
 * 
 * @param mgr Indicates the pointer to {@link NativeResourceManager}
{@link OH_ResourceManager_InitNativeResourceManager}.
 * @param resId Indicates the resource ID.
 * @param resultValue the result write to resultValue.
 * @return { BusinessError } 401 - If the input parameter invalid. Possible causes: Incorrect parameter types.
           { BusinessError } 9001001 - Invalid resource ID.
           { BusinessError } 9001002 - No matching resource is found based on the resource ID.
 * @since 12
 * @version 1.0
 */
ResourceManager_ErrorCode OH_ResourceManager_GetBool(const NativeResourceManager *mgr, uint32_t resId,  bool *resultValue);

/**
 * @brief Obtains the boolean result.
 * 
 * Obtains the boolean result with a specified resource Name.
 * 
 * @param mgr Indicates the pointer to {@link NativeResourceManager}
{@link OH_ResourceManager_InitNativeResourceManager}.
 * @param resName Indicates the resource Name.
 * @param resultValue the result write to resultValue.
 * @return { BusinessError } 401 - If the input parameter invalid. Possible causes: Incorrect parameter types
           { BusinessError } 9001003 - Invalid resource name.
           { BusinessError } 9001004 - No matching resource is found based on the resource name.
 * @since 12
 * @version 1.0
 */
ResourceManager_ErrorCode OH_ResourceManager_GetBoolByName(const NativeResourceManager *mgr, const char *resName, bool *resultValue);

/**
 * @brief Add overlay resources during application runtime.
 * @param mgr Indicates the pointer to {@link NativeResourceManager}
 * {@link OH_ResourceManager_InitNativeResourceManager}.
 * @param path Indicates the application overlay path.
 * @return { BusinessError } 401 - If the input parameter invalid. Possible causes: Incorrect parameter types.
 *         { BusinessError } 9001010 - Invalid overlay path.
 * @since 12
 * @version 1.0
 */
ResourceManager_ErrorCode OH_ResourceManager_AddResource(const NativeResourceManager *mgr, char *path);

/**
 * @brief RemovE overlay resources during application runtime.
 * @param mgr Indicates the pointer to {@link NativeResourceManager}
 * {@link OH_ResourceManager_InitNativeResourceManager}.
 * @param path Indicates the application overlay path.
 * @return { BusinessError } 401 - If the input parameter invalid. Possible causes: Incorrect parameter types.
 *         { BusinessError } 9001010 - Invalid overlay path.
 * @since 12
 * @version 1.0
 */
ResourceManager_ErrorCode OH_ResourceManager_RemoveResource(const NativeResourceManager *mgr, char *path);
#ifdef __cplusplus
};
#endif

/** @} */
#endif // GLOBAL_NATIVE_RESOURCE_MANAGER_H