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
 * @addtogroup ImageProcessing
 * @{
 *
 * @brief Provide image processing including color space conversion and metadata generation.
 *
 * @since 12
 */

/**
 * @file image_processing.h
 *
 * @brief Declare image processing functions.
 *
 * Provides SDR content processing for images, including color space conversion and metadata generation.
 *
 * @library libimage_processing.so
 * @syscap SystemCapability.Multimedia.VideoProcessingEngine
 * @since 12
 */

#ifndef VIDEO_PROCESSING_ENGINE_C_API_IMAGE_PROCESSING_H
#define VIDEO_PROCESSING_ENGINE_C_API_IMAGE_PROCESSING_H

#include <stdint.h>

#include "image_processing_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initialize global environment for image processing.
 *
 * This function is optional. \n
 * Typically, this function is called once when the host process is started to initialize the global environment for
 * image processing, which can reduce the time of {@link OH_ImageProcessing_Create}. \n
 * To deinitialize global environment, call {@link OH_ImageProcessing_DeinitializeEnvironment}.
 *
 * @return {@link IMAGE_PROCESSING_SUCCESS} if initialization is successful. \n
 * {@link IMAGE_PROCESSING_ERROR_INITIALIZE_FAILED} if initialization is failed.
 * @since 12
 */
ImageProcessing_ErrorCode OH_ImageProcessing_InitializeEnvironment();

/**
 * @brief Deinitialize global environment for image processing.
 *
 * This function is required if {@link OH_ImageProcessing_InitializeEnvironment} is called. Typically, this
 * function is called when the host process is about to exit to deinitialize the global environment, which is
 * initialized by calling {@link OH_ImageProcessing_InitializeEnvironment}. \n
 * If there is some image processing instance existing, this function should not be called. \n
 * If the {@link OH_ImageProcessing_InitializeEnvironment} is not called, this function should not be called.
 *
 * @return {@link IMAGE_PROCESSING_SUCCESS} if deinitialization is successful. \n
 * {@link IMAGE_PROCESSING_ERROR_OPERATION_NOT_PERMITTED} if some image processing instance is not destroyed or
 * {@link OH_ImageProcessing_InitializeEnvironment} is not called. \n
 * @since 12
 */
ImageProcessing_ErrorCode OH_ImageProcessing_DeinitializeEnvironment();

/**
 * @brief Query whether the image color space conversion is supported.
 *
 * @param sourceImageInfo Input image color space information pointer.
 * @param destinationImageInfo Output image color space information pointer.
 * @return <b>true</b> if the color space conversion is supported. \n
 * <b>false</b> if the the color space conversion is unsupported.
 * @since 12
 */
bool OH_ImageProcessing_IsColorSpaceConversionSupported(
    const ImageProcessing_ColorSpaceInfo* sourceImageInfo,
    const ImageProcessing_ColorSpaceInfo* destinationImageInfo);

/**
 * @brief Query whether the image composition is supported.
 *
 * @param sourceImageInfo Input image color space information pointer.
 * @param sourceGainmapInfo Input gainmap color space information pointer.
 * @param destinationImageInfo Output image color space information pointer.
 * @return <b>true</b> if the image composition is supported. \n
 * <b>false</b> if the image composition is unsupported.
 * @since 12
 */
bool OH_ImageProcessing_IsCompositionSupported(
    const ImageProcessing_ColorSpaceInfo* sourceImageInfo,
    const ImageProcessing_ColorSpaceInfo* sourceGainmapInfo,
    const ImageProcessing_ColorSpaceInfo* destinationImageInfo);

/**
 * @brief Query whether the image decomposition is supported.
 *
 * @param sourceImageInfo Input image color space information pointer.
 * @param destinationImageInfo Output image color space information pointer.
 * @param destinationGainmapInfo Output gainmap information pointer.
 * @return <b>true</b> if the image decomposition is supported. \n
 * <b>false</b> if the image decomposition is unsupported.
 * @since 12
 */
bool OH_ImageProcessing_IsDecompositionSupported(
    const ImageProcessing_ColorSpaceInfo* sourceImageInfo,
    const ImageProcessing_ColorSpaceInfo* destinationImageInfo,
    const ImageProcessing_ColorSpaceInfo* destinationGainmapInfo);

/**
 * @brief Create an image processing instance.
 *
 * @param instance Output parameter. The *instance points to a new image processing object. The *instance must be null
 * before passed in.
 * @param type Use IMAGE_PROCESSING_TYPE_XXX to specify the processing type. The processing type of the instance can not
 * be changed.
 * @return {@link IMAGE_PROCESSING_SUCCESS} if creating an image processing successfully. \n
 * {@link IMAGE_PROCESSING_ERROR_UNSUPPORTED_PROCESSING} if the type is not supported. For example, if metadata
 * generation is not supported by vendor, it returns unsupported processing. \n
 * {@link IMAGE_PROCESSING_ERROR_CREATE_FAILED} if failed to create an image processing. \n
 * {@link IMAGE_PROCESSING_ERROR_INVALID_INSTANCE} if instance is null or <b>*</b>instance is <b>not</b> null. \n
 * {@link IMAGE_PROCESSING_ERROR_INVALID_PARAMETER} if type is invalid. \n
 * @since 12
 */
ImageProcessing_ErrorCode OH_ImageProcessing_Create(OH_ImageProcessing** instance, int32_t type);

/**
 * @brief Destroy the image processing instance.
 *
 * @param instance An image processing instance pointer. It is recommended setting the instance pointer to null after
 * the instance is destroyed.
 * @return {@link IMAGE_PROCESSING_SUCCESS} if the instance is destroyed successfully. \n
 * {@link IMAGE_PROCESSING_ERROR_INVALID_INSTANCE} if instance is null or not an image processing instance.
 * @since 12
 */
ImageProcessing_ErrorCode OH_ImageProcessing_Destroy(OH_ImageProcessing* instance);

/**
 * @brief Process image.
 *
 * The processing type is specified when creating the instance.
 * For color space conversion, it includes the conversion between single-layer images, composition from dual-layer HDR
 * images to single-layer HDR images, and decomposition from single-layer image to dual-layer HDR image.
 *
 * @param instance An image processing instance pointer.
 * @param sourceImage Input image pointer.
 * @param destinationImage Output image pointer.
 * @return {@link IMAGE_PROCESSING_SUCCESS} if processing image is successful. \n
 * {@link IMAGE_PROCESSING_ERROR_INVALID_INSTANCE} if instance is null or not an image processing instance. \n
 * {@link IMAGE_PROCESSING_ERROR_INVALID_PARAMETER} if the image is null. \n
 * {@link IMAGE_PROCESSING_ERROR_INVALID_VALUE} if some property of image is invalid. For example, the color space
 * of the image is unsupported. \n
 * {@link IMAGE_PROCESSING_ERROR_UNSUPPORTED_PROCESSING} if the processing is not supported. \n
 * {@link IMAGE_PROCESSING_ERROR_PROCESS_FAILED} if processing error occurs. \n
 * {@link IMAGE_PROCESSING_ERROR_NO_MEMORY} if memory allocation failed.
 * @since 12
 */
ImageProcessing_ErrorCode OH_ImageProcessing_Process(OH_ImageProcessing* instance, OH_PixelmapNative* sourceImage,
    OH_PixelmapNative* destinationImage);

#ifdef __cplusplus
}
#endif

#endif // VIDEO_PROCESSING_ENGINE_C_API_IMAGE_PROCESSING_H
/** @} */