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
 * @brief Provides APIs for obtaining image data from the native layer.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */

/**
 * @file imageReceiver2.h
 *
 * @brief Declares the APIs for obtaining image data from the native layer.
 * Need link <b>libimage_native.z.so</b> and <b>libimage2.z.so</b>
 * @since 12
 * @version 5.0
 */

#ifndef INTERFACES_KITS_NATIVE_INCLUDE_IMAGE_RECEIVER2_H
#define INTERFACES_KITS_NATIVE_INCLUDE_IMAGE_RECEIVER2_H

#include "image2.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defines an <b>OH_ImageReceiver2</b> object at the native layer.
 *
 * @since 12
 * @version 5.0
 */
struct OH_ImageReceiver2;

/**
 * @brief Defines the data type name of a native image receiver.
 *
 * @since 12
 * @version 5.0
 */
typedef struct OH_ImageReceiver2 OH_ImageReceiver2;

/**
 * @brief Defines an image receiver info object at the native layer.
 *
 * @since 12
 * @version 5.0
 */
struct OH_ImageReceiver2_Info;

/**
 * @brief Defines the data type name of a native image receiver info.
 *
 * @since 12
 * @version 5.0
 */
typedef struct OH_ImageReceiver2_Info OH_ImageReceiver2_Info;

/**
 * @brief Defines the callbacks for images at the native layer.
 *
 * @since 12
 * @version 5.0
 */
typedef void (*OH_Image_Receiver_On_Callback)(void);

/**
 * @brief Creates an <b>OH_ImageReceiver2_Info</b> object at the application layer.
 *
 * @param width Default width of the image received by the consumer, in pixels.
 * @param height Default height of the image received by the consumer, in pixels.
 * @param format Image format {@link OHOS_IMAGE_FORMAT_JPEG} created by using the receiver.
 * @param capicity Maximum number of images that can be cached.
 * @param info Indicates the pointer to the <b>OH_ImageReceiver2_Info</b> object obtained.
 * @return Returns {@link OH_Image_ErrorCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_MALLOC_ABNORMAL - if malloc failed.
 * @since 12
 * @version 5.0
 */
OH_Image_ErrorCode OH_ImageReceiver2_CreateInfo(
    int32_t width, int32_t height, int32_t format, int32_t capicity,
    OH_ImageReceiver2_Info** info);

/**
 * @brief Set width of an {@link OH_ImageReceiver2_Info} object at the native layer.
 *
 * @param info Indicates the pointer to an {@link OH_ImageReceiver2_Info} object at the native layer.
 * @param width Indicates the value of the {@link OH_ImageReceiver2_Info} object seted.
 * @return Returns {@link OH_Image_ErrorCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * @see OH_ImageReceiver2_Info
 * @since 12
 * @version 5.0
 */
OH_Image_ErrorCode OH_ImageReceiver2_SetInfoWidth(OH_ImageReceiver2_Info* info,
    int32_t width);

/**
 * @brief Get width from an {@link OH_ImageReceiver2_Info} object at the native layer.
 *
 * @param info Indicates the pointer to an {@link OH_ImageReceiver2_Info} object at the native layer.
 * @param width Indicates the pointer to the {@link OH_ImageReceiver2_Info} object obtained.
 * @return Returns {@link OH_Image_ErrorCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * @see OH_ImageReceiver2_Info
 * @since 12
 * @version 5.0
 */
OH_Image_ErrorCode OH_ImageReceiver2_GetInfoWidth(const OH_ImageReceiver2_Info* info,
    int32_t* width);

/**
 * @brief Set height of an {@link OH_ImageReceiver2_Info} object at the native layer.
 *
 * @param info Indicates the pointer to an {@link OH_ImageReceiver2_Info} object at the native layer.
 * @param height Indicates the value of the {@link OH_ImageReceiver2_Info} object seted.
 * @return Returns {@link OH_Image_ErrorCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * @see OH_ImageReceiver2_Info
 * @since 12
 * @version 5.0
 */
OH_Image_ErrorCode OH_ImageReceiver2_SetInfoHeight(OH_ImageReceiver2_Info* info,
    int32_t height);

/**
 * @brief Get height from an {@link OH_ImageReceiver2_Info} object at the native layer.
 *
 * @param info Indicates the pointer to an {@link OH_ImageReceiver2_Info} object at the native layer.
 * @param height Indicates the pointer to the {@link OH_ImageReceiver2_Info} object obtained.
 * @return Returns {@link OH_Image_ErrorCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * @see OH_ImageReceiver2_Info
 * @since 12
 * @version 5.0
 */
OH_Image_ErrorCode OH_ImageReceiver2_GetInfoHeight(const OH_ImageReceiver2_Info* info,
    int32_t* height);

/**
 * @brief Set format of an {@link OH_ImageReceiver2_Info} object at the native layer.
 *
 * @param info Indicates the pointer to an {@link OH_ImageReceiver2_Info} object at the native layer.
 * @param format Indicates the value of the {@link OH_ImageReceiver2_Info} object seted.
 * @return Returns {@link OH_Image_ErrorCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * @see OH_ImageReceiver2_Info
 * @since 12
 * @version 5.0
 */
OH_Image_ErrorCode OH_ImageReceiver2_SetInfoFormat(OH_ImageReceiver2_Info* info,
    int32_t format);

/**
 * @brief Get format from an {@link OH_ImageReceiver2_Info} object at the native layer.
 *
 * @param info Indicates the pointer to an {@link OH_ImageReceiver2_Info} object at the native layer.
 * @param format Indicates the pointer to the {@link OH_ImageReceiver2_Info} object obtained.
 * @return Returns {@link OH_Image_ErrorCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * @see OH_ImageReceiver2_Info
 * @since 12
 * @version 5.0
 */
OH_Image_ErrorCode OH_ImageReceiver2_GetInfoFormat(const OH_ImageReceiver2_Info* info,
    int32_t* format);

/**
 * @brief Set capicity of an {@link OH_ImageReceiver2_Info} object at the native layer.
 *
 * @param info Indicates the pointer to an {@link OH_ImageReceiver2_Info} object at the native layer.
 * @param capicity Indicates the value of the {@link OH_ImageReceiver2_Info} object seted.
 * @return Returns {@link OH_Image_ErrorCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * @see OH_ImageReceiver2_Info
 * @since 12
 * @version 5.0
 */
OH_Image_ErrorCode OH_ImageReceiver2_SetInfoCapicity(OH_ImageReceiver2_Info* info,
    int32_t capicity);

/**
 * @brief Get capicity from an {@link OH_ImageReceiver2_Info} object at the native layer.
 *
 * @param info Indicates the pointer to an {@link OH_ImageReceiver2_Info} object at the native layer.
 * @param capicity Indicates the pointer to the {@link OH_ImageReceiver2_Info} object obtained.
 * @return Returns {@link OH_Image_ErrorCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * @see OH_ImageReceiver2_Info
 * @since 12
 * @version 5.0
 */
OH_Image_ErrorCode OH_ImageReceiver2_GetInfoCapicity(const OH_ImageReceiver2_Info* info,
    int32_t* capicity);

/**
 * @brief Releases an {@link OH_ImageReceiver2_Info} object at the native layer.
 * Note: This API is not used to release a JavaScript native API <b>Image</b> object.
 * It is used to release the object {@link OH_ImageReceiver2_Info} at the native layer.
 *
 * @param info Indicates the pointer to an {@link OH_ImageReceiver2_Info} object at the native layer.
 * @return Returns {@link OH_Image_ErrorCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * @see OH_ImageReceiver2_Info
 * @since 12
 * @version 5.0
 */
OH_Image_ErrorCode OH_ImageReceiver2_ReleaseInfo(OH_ImageReceiver2_Info* info);

/**
 * @brief Creates an <b>OH_ImageReceiver2</b> object at the application layer.
 *
 * @param info Indicates the options for setting the <b>OH_ImageReceiver2</b> object.
 * @param res Indicates the pointer to the <b>OH_ImageReceiver2</b> object obtained.
 * @return Returns {@link OH_Image_ErrorCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_MALLOC_ABNORMAL - if malloc failed.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_GET_DATA_ABNORMAL - if get data failed.
 * @since 12
 * @version 5.0
 */
OH_Image_ErrorCode OH_ImageReceiver2_Create(struct OH_ImageReceiver2_Info* info,
    OH_ImageReceiver2** res);

/**
 * @brief Obtains the receiver ID through an {@link OH_ImageReceiver2} object.
 *
 * @param receiver Indicates the pointer to an {@link OH_ImageReceiver2} object at the native layer.
 * @param id Indicates the pointer to the buffer that stores the ID string obtained.
 * @param len Indicates the size of the buffer.
 * @return Returns {@link OH_Image_ErrorCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_BAD_PARAMETER - if bad parameter.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_GET_DATA_ABNORMAL - if get data failed.
 * @see OH_ImageReceiver2
 * @since 12
 * @version 5.0
 */
OH_Image_ErrorCode OH_ImageReceiver2_GetReceivingSurfaceId(const OH_ImageReceiver2* receiver,
    char* id, size_t len);

/**
 * @brief Obtains the latest image through an {@link OH_ImageReceiver2} object.
 *
 * @param receiver Indicates the pointer to an {@link OH_ImageReceiver2} object at the native layer.
 * @param image Indicates the pointer to an <b>OH_Image2</b> object at the application layer.
 * @return Returns {@link OH_Image_ErrorCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_BAD_PARAMETER - if bad parameter.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_GET_DATA_ABNORMAL - if get data failed.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_MALLOC_ABNORMAL - if malloc failed.
 * @see OH_ImageReceiver2, OH_Image2
 * @since 12
 * @version 5.0
 */
OH_Image_ErrorCode OH_ImageReceiver2_ReadLatestImage(const OH_ImageReceiver2* receiver,
    OH_Image2** image);

/**
 * @brief Obtains the next image through an {@link OH_ImageReceiver2} object.
 *
 * @param receiver Indicates the pointer to an {@link OH_ImageReceiver2} object at the native layer.
 * @param image Indicates the pointer to an <b>OH_Image2</b> object at the application layer.
 * @return Returns {@link OH_Image_ErrorCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_BAD_PARAMETER - if bad parameter.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_GET_DATA_ABNORMAL - if get data failed.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_MALLOC_ABNORMAL - if malloc failed.
 * @see OH_ImageReceiver2, OH_Image2
 * @since 12
 * @version 5.0
 */
OH_Image_ErrorCode OH_ImageReceiver2_ReadNextImage(const OH_ImageReceiver2* receiver,
    OH_Image2** image);

/**
 * @brief Registers an {@link OH_Image_Receiver_On_Callback} callback event.
 *
 * This callback event is triggered whenever a new image is received.
 *
 * @param receiver Indicates the pointer to an {@link OH_ImageReceiver2} object at the native layer.
 * @param callback Indicates the {@link OH_Image_Receiver_On_Callback} callback event to register.
 * @return Returns {@link OH_Image_ErrorCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * @see OH_ImageReceiver2, OH_Image_Receiver_On_Callback
 * @since 12
 * @version 5.0
 */
OH_Image_ErrorCode OH_ImageReceiver2_On(const OH_ImageReceiver2* receiver,
    OH_Image_Receiver_On_Callback callback);

/**
 * @brief Unregisters the {@link OH_Image_Receiver_On_Callback} callback event.
 *
 * This callback event is triggered whenever the image is shutdown.
 *
 * @param receiver Indicates the pointer to an {@link OH_ImageReceiver2} object at the native layer.
 * @return Returns {@link OH_Image_ErrorCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_BAD_PARAMETER - if bad parameter.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * @see OH_ImageReceiver2, OH_ImageReceiver2_On
 * @since 12
 * @version 5.0
 */
OH_Image_ErrorCode OH_ImageReceiver2_Off(const OH_ImageReceiver2* receiver);

/**
 * @brief Obtains the info {@link OH_ImageReceiver2_Info} of the image receiver
 *        through an {@link OH_ImageReceiver2} object.
 *
 * @param receiver Indicates the pointer to an {@link OH_ImageReceiver2} object at the native layer.
 * @param infoNative Indicates the pointer to the {@link OH_ImageReceiver2_Info} object obtained.
 * @return Returns {@link OH_Image_ErrorCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_BAD_PARAMETER - if bad parameter.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_MALLOC_ABNORMAL - if malloc failed.
 * @see OH_ImageReceiver2, OH_ImageReceiver2_Info
 * @since 12
 * @version 5.0
 */
OH_Image_ErrorCode OH_ImageReceiver2_GetInfo(const OH_ImageReceiver2* receiver,
    OH_ImageReceiver2_Info** infoNative);

/**
 * @brief Obtains the size of the image receiver through an {@link OH_ImageReceiver2} object.
 *
 * @param receiver Indicates the pointer to an {@link OH_ImageReceiver2} object at the native layer.
 * @param size Indicates the pointer to the {@link OH_Image_Size} object obtained.
 * @return Returns {@link OH_Image_ErrorCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_BAD_PARAMETER - if bad parameter.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * @see OH_ImageReceiver2, OH_Image_Size
 * @since 12
 * @version 5.0
 */
OH_Image_ErrorCode OH_ImageReceiver2_GetSize(const OH_ImageReceiver2* receiver,
    struct OH_Image_Size* size);

/**
 * @brief Obtains the capacity of the image receiver through an {@link OH_ImageReceiver2} object.
 *
 * @param receiver Indicates the pointer to an {@link OH_ImageReceiver2} object at the native layer.
 * @param capacity Indicates the pointer to the capacity obtained.
 * @return Returns {@link OH_Image_ErrorCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_BAD_PARAMETER - if bad parameter.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * @see OH_ImageReceiver2
 * @since 12
 * @version 5.0
 */
OH_Image_ErrorCode OH_ImageReceiver2_GetCapacity(const OH_ImageReceiver2* receiver,
    int32_t* capacity);

/**
 * @brief Obtains the format of the image receiver through an {@link OH_ImageReceiver2} object.
 *
 * @param receiver Indicates the pointer to an {@link OH_ImageReceiver2} object at the native layer.
 * @param format Indicates the pointer to the format obtained.
 * @return Returns {@link OH_Image_ErrorCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_BAD_PARAMETER - if bad parameter.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * @see OH_ImageReceiver2
 * @since 12
 * @version 5.0
 */
OH_Image_ErrorCode OH_ImageReceiver2_GetFormat(const OH_ImageReceiver2* receiver,
    int32_t* format);

/**
 * @brief Releases an {@link OH_ImageReceiver2} object at the native layer.
 *
 * This API is not used to release an <b>ImageReceiver2</b> object at the application layer.
 *
 * @param receiver Indicates the pointer to an {@link OH_ImageReceiver2} object at the native layer.
 * @return Returns {@link OH_Image_ErrorCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link OH_Image_ErrorCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * @see OH_ImageReceiver2
 * @since 12
 * @version 5.0
 */
OH_Image_ErrorCode OH_ImageReceiver2_Release(OH_ImageReceiver2* receiver);

#ifdef __cplusplus
};
#endif
/** @} */

#endif // INTERFACES_KITS_NATIVE_INCLUDE_IMAGE_RECEIVER2_H
