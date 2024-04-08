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
 * @brief Provides APIs for obtaining image data.
 *
 * @since 12
 */

/**
 * @file image_receiver.h
 *
 * @brief Declares the APIs for obtaining image data.
 * 
 * @library libohimagereceiver.so
 * @syscap SystemCapability.Multimedia.Image.ImageReceiver
 * @since 12
 */

#ifndef INTERFACES_KITS_NATIVE_INCLUDE_IMAGE_RECEIVER_H
#define INTERFACES_KITS_NATIVE_INCLUDE_IMAGE_RECEIVER_H

#include "image_native.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defines an <b>OH_ImageReceiver</b> object.
 *
 * @since 12
 */
struct OH_ImageReceiver;

/**
 * @brief Defines the data type name of a native image receiver.
 *
 * @since 12
 */
typedef struct OH_ImageReceiver OH_ImageReceiver;

/**
 * @brief Defines an image receiver options object.
 *
 * @since 12
 */
struct OH_ImageReceiverOptions;

/**
 * @brief Defines the data type name of a native image receiver info.
 *
 * @since 12
 */
typedef struct OH_ImageReceiverOptions OH_ImageReceiverOptions;

/**
 * @brief Defines the callbacks for images.
 *
 * @since 12
 */
typedef void (*OH_Image_Receiver_On_Callback)(OH_ImageReceiver *receiver);

/**
 * @brief Creates an <b>OH_ImageReceiverOptions</b> object at the application layer.
 *
 * @param options Indicates the pointer to the <b>OH_ImageReceiverOptions</b> object obtained.
 * @return Returns {@link Image_ErrorCode} IMAGE_SUCCESS - if the operation is successful.
 * returns {@link Image_ErrorCode} IMAGE_BAD_PARAMETER - if bad parameter.
 * returns {@link Image_ErrorCode} IMAGE_ALLOC_FAILED - if alloc failed.
 * @since 12
 */
Image_ErrorCode OH_ImageReceiverOptions_Create(OH_ImageReceiverOptions **options);

/**
 * @brief Get size of an {@link OH_ImageReceiverOptions} object.
 *
 * @param options Indicates the pointer to an {@link OH_ImageReceiverOptions} object.
 * @param size Indicates the value of the {@Link Image_Size} object will be obtained.
 * @return Returns {@link Image_ErrorCode} IMAGE_SUCCESS - if the operation is successful.
 * returns {@link Image_ErrorCode} IMAGE_BAD_PARAMETER - if bad parameter.
 * @since 12
 */
Image_ErrorCode OH_ImageReceiverOptions_GetSize(OH_ImageReceiverOptions* options, Image_Size* size);

/**
 * @brief Set size of an {@link OH_ImageReceiverOptions} object.
 *
 * @param options Indicates the pointer to an {@link OH_ImageReceiverOptions} object.
 * @param size Indicates the value of the {@link Image_Size} object will be seted.
 * @return Returns {@link Image_ErrorCode} IMAGE_SUCCESS - if the operation is successful.
 * returns {@link Image_ErrorCode} IMAGE_BAD_PARAMETER - if bad parameter.
 * @since 12
 */
Image_ErrorCode OH_ImageReceiverOptions_SetSize(OH_ImageReceiverOptions* options, Image_Size size);

/**
 * @brief Get capacity from an {@link OH_ImageReceiverOptions} object.
 *
 * @param options Indicates the pointer to an {@link OH_ImageReceiverOptions} object.
 * @param capacity Indicates the pointer to capacity will be obtained.
 * @return Returns {@link Image_ErrorCode} IMAGE_SUCCESS - if the operation is successful.
 * returns {@link Image_ErrorCode} IMAGE_BAD_PARAMETER - if bad parameter.
 * @since 12
 */
Image_ErrorCode OH_ImageReceiverOptions_GetCapacity(OH_ImageReceiverOptions* options, int32_t* capacity);

/**
 * @brief Set capacity of an {@link OH_ImageReceiverOptions} object.
 *
 * @param options Indicates the pointer to an {@link OH_ImageReceiverOptions} object.
 * @param capacity Indicates the value of capacity will be seted.
 * @return Returns {@link Image_ErrorCode} IMAGE_SUCCESS - if the operation is successful.
 * returns {@link Image_ErrorCode} IMAGE_BAD_PARAMETER - if bad parameter.
 * @since 12
 */
Image_ErrorCode OH_ImageReceiverOptions_SetCapacity(OH_ImageReceiverOptions* options, int32_t capacity);

/**
 * @brief Releases an {@link OH_ImageReceiverOptions} object.
 * It is used to release the object {@link OH_ImageReceiverOptions}.
 *
 * @param options Indicates the pointer to an {@link OH_ImageReceiverOptions} object.
 * @return Returns {@link Image_ErrorCode} IMAGE_SUCCESS - if the operation is successful.
 * returns {@link Image_ErrorCode} IMAGE_BAD_PARAMETER - if bad parameter.
 * @see OH_ImageReceiverOptions
 * @since 12
 */
Image_ErrorCode OH_ImageReceiverOptions_Release(OH_ImageReceiverOptions* options);

/**
 * @brief Creates an <b>OH_ImageReceiver</b> object at the application layer.
 *
 * @param options Indicates the options for setting the <b>OH_ImageReceiver</b> object.
 * @param receiver Indicates the pointer to the <b>OH_ImageReceiver</b> object obtained.
 * @return Returns {@link Image_ErrorCode} IMAGE_SUCCESS - if the operation is successful.
 * returns {@link Image_ErrorCode} IMAGE_BAD_PARAMETER - if bad parameter.
 * returns {@link Image_ErrorCode} IMAGE_ALLOC_FAILED - if alloc failed.
 * @since 12
 */
Image_ErrorCode OH_ImageReceiverNative_Create(OH_ImageReceiverOptions* options, OH_ImageReceiver** receiver);

/**
 * @brief Obtains the receiver ID through an {@link OH_ImageReceiver} object.
 *
 * @param receiver Indicates the pointer to an {@link OH_ImageReceiver} object.
 * @param surfaceId Indicates the pointer to the surface ID will be obtained.
 * @return Returns {@link Image_ErrorCode} IMAGE_SUCCESS - if the operation is successful.
 * returns {@link Image_ErrorCode} IMAGE_BAD_PARAMETER - if bad parameter.
 * returns {@link Image_ErrorCode} IMAGE_UNKNOWN_ERROR - inner unknown error.
 * @see OH_ImageReceiver
 * @since 12
 */
Image_ErrorCode OH_ImageReceiverNative_GetReceivingSurfaceId(OH_ImageReceiver* receiver, uint64_t* surfaceId);

/**
 * @brief Obtains the latest image through an {@link OH_ImageReceiver} object.
 *
 * @param receiver Indicates the pointer to an {@link OH_ImageReceiver} object.
 * @param image Indicates the pointer to an <b>OH_Image</b> object at the application layer.
 * @return Returns {@link Image_ErrorCode} IMAGE_SUCCESS - if the operation is successful.
 * returns {@link Image_ErrorCode} IMAGE_BAD_PARAMETER - if bad parameter.
 * returns {@link Image_ErrorCode} IMAGE_UNKNOWN_ERROR - inner unknown error.
 * returns {@link Image_ErrorCode} IMAGE_ALLOC_FAILED - if alloc failed.
 * @see OH_ImageReceiver, OH_Image
 * @since 12
 */
Image_ErrorCode OH_ImageReceiverNative_ReadLatestImage(OH_ImageReceiver* receiver, OH_Image** image);

/**
 * @brief Obtains the next image through an {@link OH_ImageReceiver} object.
 *
 * @param receiver Indicates the pointer to an {@link OH_ImageReceiver} object.
 * @param image Indicates the pointer to an <b>OH_Image</b> object at the application layer.
 * @return Returns {@link Image_ErrorCode} IMAGE_SUCCESS - if the operation is successful.
 * returns {@link Image_ErrorCode} IMAGE_BAD_PARAMETER - if bad parameter.
 * returns {@link Image_ErrorCode} IMAGE_UNKNOWN_ERROR - inner unknown error.
 * returns {@link Image_ErrorCode} IMAGE_ALLOC_FAILED - if alloc failed.
 * @see OH_ImageReceiver, OH_Image
 * @since 12
 */
Image_ErrorCode OH_ImageReceiverNative_ReadNextImage(OH_ImageReceiver* receiver, OH_Image** image);

/**
 * @brief Registers an {@link OH_Image_Receiver_On_Callback} callback event.
 *
 * This callback event is triggered whenever a new image is received.
 *
 * @param receiver Indicates the pointer to an {@link OH_ImageReceiver} object.
 * @param callback Indicates the {@link OH_Image_Receiver_On_Callback} callback event to register.
 * @return Returns {@link Image_ErrorCode} IMAGE_SUCCESS - if the operation is successful.
 * returns {@link Image_ErrorCode} IMAGE_BAD_PARAMETER - if bad parameter.
 * @see OH_ImageReceiver, OH_Image_Receiver_On_Callback
 * @since 12
 */
Image_ErrorCode OH_ImageReceiverNative_On(OH_ImageReceiver* receiver, OH_Image_Receiver_On_Callback callback);

/**
 * @brief Unregisters the {@link OH_Image_Receiver_On_Callback} callback event.
 *
 * Turn off the callback witch triggered by {@link OH_ImageReceiverNative_On}.
 *
 * @param receiver Indicates the pointer to an {@link OH_ImageReceiver} object.
 * @return Returns {@link Image_ErrorCode} IMAGE_SUCCESS - if the operation is successful.
 * returns {@link Image_ErrorCode} IMAGE_BAD_PARAMETER - if bad parameter.
 * @see OH_ImageReceiver, OH_ImageReceiverNative_On
 * @since 12
 */
Image_ErrorCode OH_ImageReceiverNative_Off(OH_ImageReceiver* receiver);

/**
 * @brief Obtains the size of the image receiver through an {@link OH_ImageReceiver} object.
 *
 * @param receiver Indicates the pointer to an {@link OH_ImageReceiver} object.
 * @param size Indicates the pointer to the {@link Image_Size} object will be obtained.
 * @return Returns {@link Image_ErrorCode} IMAGE_SUCCESS - if the operation is successful.
 * returns {@link Image_ErrorCode} IMAGE_BAD_PARAMETER - if bad parameter.
 * @see OH_ImageReceiver, Image_Size
 * @since 12
 */
Image_ErrorCode OH_ImageReceiverNative_GetSize(OH_ImageReceiver* receiver, Image_Size* size);

/**
 * @brief Obtains the capacity of the image receiver through an {@link OH_ImageReceiver} object.
 *
 * @param receiver Indicates the pointer to an {@link OH_ImageReceiver} object.
 * @param capacity Indicates the pointer to the capacity will be obtained.
 * @return Returns {@link Image_ErrorCode} IMAGE_SUCCESS - if the operation is successful.
 * returns {@link Image_ErrorCode} IMAGE_BAD_PARAMETER - if bad parameter.
 * @see OH_ImageReceiver
 * @since 12
 */
Image_ErrorCode OH_ImageReceiverNative_GetCapacity(OH_ImageReceiver* receiver, int32_t* capacity);

/**
 * @brief Obtains the format of the image receiver through an {@link OH_ImageReceiver} object.
 *
 * @param receiver Indicates the pointer to an {@link OH_ImageReceiver} object.
 * @param format Indicates the pointer to the format will be obtained.
 * @return Returns {@link Image_ErrorCode} IMAGE_SUCCESS - if the operation is successful.
 * returns {@link Image_ErrorCode} IMAGE_BAD_PARAMETER - if bad parameter.
 * @see OH_ImageReceiver
 * @since 12
 */
Image_ErrorCode OH_ImageReceiverNative_GetFormat(OH_ImageReceiver* receiver, int32_t* format);

/**
 * @brief Releases an {@link OH_ImageReceiver} object.
 *
 * This API is not used to release an <b>ImageReceiver2</b> object at the application layer.
 *
 * @param receiver Indicates the pointer to an {@link OH_ImageReceiver} object.
 * @return Returns {@link Image_ErrorCode} IMAGE_SUCCESS - if the operation is successful.
 * returns {@link Image_ErrorCode} IMAGE_BAD_PARAMETER - if bad parameter.
 * @see OH_ImageReceiver
 * @since 12
 */
Image_ErrorCode OH_ImageReceiverNative_Release(OH_ImageReceiver* receiver);

#ifdef __cplusplus
};
#endif
/** @} */

#endif // INTERFACES_KITS_NATIVE_INCLUDE_IMAGE_RECEIVER_H
