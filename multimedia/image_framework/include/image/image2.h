/*
 * Copyright (C) 2024 Huawei Device Co., Ltd.
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
 * @addtogroup image
 * @{
 *
 * @brief Provides APIs for access to the image interface.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */

/**
 * @file image2.h
 *
 * @brief Declares functions that access the image rectangle, size, format, and component data.
 * Need link <b>libimage_native.z.so</b>
 *
 * @since 12
 * @version 5.0
 */

#ifndef INTERFACES_KITS_NATIVE_INCLUDE_IMAGE2_H
#define INTERFACES_KITS_NATIVE_INCLUDE_IMAGE2_H

#include "image_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defines an <b>OH_Image2</b> object at the native layer.
 *
 * @since 12
 * @version 5.0
 */
struct OH_Image2;

/**
 * @brief Defines the data type name of a native image.
 *
 * @since 12
 * @version 5.0
 */
typedef struct OH_Image2 OH_Image2;

/**
 * @brief Defines the image component object at the native layer.
 *
 * @since 12
 * @version 5.0
 */
struct OH_Image2_Component;

/**
 * @brief Defines the data type name of a native image component.
 *
 * @since 12
 * @version 5.0
 */
typedef struct OH_Image2_Component OH_Image2_Component;

/**
 * @brief Creates an empty <b>OH_Image2_Component</b> object at the application layer.
 *
 * @param component Indicates the pointer to the <b>OH_Image2_Component</b> object obtained.
 * @return Returns {@link OH_Image_ErrorCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_MALLOC_ABNORMAL - if malloc failed.
 * @since 12
 * @version 5.0
 */
OH_Image_ErrorCode OH_Image2_CreateComponent(OH_Image2_Component** component);

/**
 * @brief Set byteBuffer of an {@link OH_Image2_Component} object at the native layer.
 *
 * @param component Indicates the pointer to an {@link OH_Image2_Component} object at the native layer.
 * @param buffer Indicates the value of the {@link OH_Image2_Component} object seted.
 * @return Returns {@link OH_Image_ErrorCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * @see OH_Image2_Component
 * @since 12
 * @version 5.0
 */
OH_Image_ErrorCode OH_Image2_SetByteBuffer(OH_Image2_Component* component, uint8_t* buffer);

/**
 * @brief Get byteBuffer from an {@link OH_Image2_Component} object at the native layer.
 *
 * @param component Indicates the pointer to an {@link OH_Image2_Component} object at the native layer.
 * @param buffer Indicates the pointer to the {@link OH_Image2_Component} object obtained.
 * @return Returns {@link OH_Image_ErrorCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * @see OH_Image2_Component
 * @since 12
 * @version 5.0
 */
OH_Image_ErrorCode OH_Image2_GetByteBuffer(const OH_Image2_Component* component, uint8_t** buffer);

/**
 * @brief Set size from an {@link OH_Image2_Component} object at the native layer.
 *
 * @param component Indicates the pointer to an {@link OH_Image2_Component} object at the native layer.
 * @param size Indicates the value of the {@link OH_Image2_Component} object seted.
 * @return Returns {@link OH_Image_ErrorCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * @see OH_Image2_Component
 * @since 12
 * @version 5.0
 */
OH_Image_ErrorCode OH_Image2_SetSize(OH_Image2_Component* component, size_t size);

/**
 * @brief Get size from an {@link OH_Image2_Component} object at the native layer.
 *
 * @param component Indicates the pointer to an {@link OH_Image2_Component} object at the native layer.
 * @param size Indicates the pointer to the {@link OH_Image2_Component} object obtained.
 * @return Returns {@link OH_Image_ErrorCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * @see OH_Image2_Component
 * @since 12
 * @version 5.0
 */
OH_Image_ErrorCode OH_Image2_GetSize(const OH_Image2_Component* component, size_t* size);

/**
 * @brief Set type from an {@link OH_Image2_Component} object at the native layer.
 *
 * @param component Indicates the pointer to an {@link OH_Image2_Component} object at the native layer.
 * @param type Indicates the value of the {@link OH_Image2_Component} object seted.
 * @return Returns {@link OH_Image_ErrorCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * @see OH_Image2_Component
 * @since 12
 * @version 5.0
 */
OH_Image_ErrorCode OH_Image2_SetComponentType(OH_Image2_Component* component, int32_t type);

/**
 * @brief Get type from an {@link OH_Image2_Component} object at the native layer.
 *
 * @param component Indicates the pointer to an {@link OH_Image2_Component} object at the native layer.
 * @param type Indicates the pointer to the {@link OH_Image2_Component} object obtained.
 * @return Returns {@link OH_Image_ErrorCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * @see OH_Image2_Component
 * @since 12
 * @version 5.0
 */
OH_Image_ErrorCode OH_Image2_GetComponentType(const OH_Image2_Component* component, int32_t* type);

/**
 * @brief Set row stride from an {@link OH_Image2_Component} object at the native layer.
 *
 * @param component Indicates the pointer to an {@link OH_Image2_Component} object at the native layer.
 * @param rowStride Indicates the value of the {@link OH_Image2_Component} object seted.
 * @return Returns {@link OH_Image_ErrorCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * @see OH_Image2_Component
 * @since 12
 * @version 5.0
 */
OH_Image_ErrorCode OH_Image2_SetRowStride(OH_Image2_Component* component, int32_t rowStride);

/**
 * @brief Get row stride from an {@link OH_Image2_Component} object at the native layer.
 *
 * @param component Indicates the pointer to an {@link OH_Image2_Component} object at the native layer.
 * @param rowStride Indicates the pointer to the {@link OH_Image2_Component} object obtained.
 * @return Returns {@link OH_Image_ErrorCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * @see OH_Image2_Component
 * @since 12
 * @version 5.0
 */
OH_Image_ErrorCode OH_Image2_GetRowStride(const OH_Image2_Component* component, int32_t* rowStride);

/**
 * @brief Set pixel stride from an {@link OH_Image2_Component} object at the native layer.
 *
 * @param component Indicates the pointer to an {@link OH_Image2_Component} object at the native layer.
 * @param pixelStride Indicates the value of the {@link OH_Image2_Component} object seted.
 * @return Returns {@link OH_Image_ErrorCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * @see OH_Image2_Component
 * @since 12
 * @version 5.0
 */
OH_Image_ErrorCode OH_Image2_SetPixelStride(OH_Image2_Component* component, int32_t pixelStride);

/**
 * @brief Get pixel stride from an {@link OH_Image2_Component} object at the native layer.
 *
 * @param component Indicates the pointer to an {@link OH_Image2_Component} object at the native layer.
 * @param pixelStride Indicates the pointer to the {@link OH_Image2_Component} object obtained.
 * @return Returns {@link OH_Image_ErrorCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * @see OH_Image2_Component
 * @since 12
 * @version 5.0
 */
OH_Image_ErrorCode OH_Image2_GetPixelStride(const OH_Image2_Component* component, int32_t* pixelStride);

/**
 * @brief Releases an {@link OH_Image2_Component} object at the native layer.
 * It is used to release the object {@link OH_Image2_Component} at the native layer.
 *
 * @param component Indicates the pointer to an {@link OH_Image2_Component} object at the native layer.
 * @return Returns {@link OH_Image_ErrorCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * @see OH_Image2_Component
 * @since 12
 * @version 5.0
 */
OH_Image_ErrorCode OH_Image2_ReleaseComponent(OH_Image2_Component* component);

/**
 * @brief Obtains {@link OH_Image_Region} of an {@link OH_Image2} at the native layer.
 *
 * @param image Indicates the pointer to an {@link OH_Image2} object at the native layer.
 * @param rect Indicates the pointer to the {@link OH_Image_Region} object obtained.
 * @return Returns {@link OH_Image_ErrorCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_BAD_PARAMETER - if bad parameter.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_MEDIA_DEAD_OBJECT - if media object dead.
 * @see OH_Image2, OH_Image_Region
 * @since 12
 * @version 5.0
 */
OH_Image_ErrorCode OH_Image2_ClipRect(const OH_Image2* image, struct OH_Image_Region* rect);

/**
 * @brief Obtains {@link OH_Image_Size} of an {@link OH_Image2} object at the native layer.
 *
 * @param image Indicates the pointer to an {@link OH_Image2} object at the native layer.
 * @param size Indicates the pointer to the {@link OH_Image_Size} object obtained.
 * @return Returns {@link OH_Image_ErrorCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_BAD_PARAMETER - if bad parameter.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_MEDIA_DEAD_OBJECT - if media object dead.
 * @see OH_Image2, OH_Image_Size
 * @since 12
 * @version 5.0
 */
OH_Image_ErrorCode OH_Image2_Size(const OH_Image2* image, struct OH_Image_Size* size);

/**
 * @brief Obtains the image format of an {@link OH_Image2} object at the native layer.
 *
 * @param image Indicates the pointer to an {@link OH_Image2} object at the native layer.
 * @param format Indicates the pointer to the image format obtained.
 * @return Returns {@link OH_Image_ErrorCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_BAD_PARAMETER - if bad parameter.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_MEDIA_DEAD_OBJECT - if media object dead.
 * @see OH_Image2
 * @since 12
 * @version 5.0
 */
OH_Image_ErrorCode OH_Image2_Format(const OH_Image2* image, int32_t* format);

/**
 * @brief Obtains {@link OhosImageComponent} of an {@link OH_Image2} object at the native layer.
 *
 * @param image Indicates the pointer to an {@link OH_Image2} object at the native layer.
 * @param componentType Indicates the type of the required component.
 * @param component Indicates the pointer to the {@link OH_Image2_Component} object obtained.
 * @return Returns {@link OH_Image_ErrorCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_BAD_PARAMETER - if bad parameter.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_GET_PARAMETER_FAILED - if Failed to obtain parameters.
 * @see OH_Image2, OhosImageComponent
 * @since 12
 * @version 5.0
 */
OH_Image_ErrorCode OH_Image2_GetComponent(const OH_Image2* image,
    int32_t componentType, OH_Image2_Component** component);

/**
 * @brief Releases an {@link OH_Image2} object at the native layer.
 * It is used to release the object {@link OH_Image2} at the native layer.
 *
 * @param image Indicates the pointer to an {@link OH_Image2} object at the native layer.
 * @return Returns {@link OH_Image_ErrorCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * @see OH_Image2
 * @since 12
 * @version 5.0
 */
OH_Image_ErrorCode OH_Image2_Release(OH_Image2* image);

#ifdef __cplusplus
};
#endif
/** @} */
#endif // INTERFACES_KITS_NATIVE_INCLUDE_IMAGE2_H
