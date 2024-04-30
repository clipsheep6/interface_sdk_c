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
 * @file image_processing_type.h
 *
 * @brief Type definitions for image processing.
 *
 * @library libvideo_processing_engine.so
 * @syscap SystemCapability.Multimedia.VideoProcessingEngine
 * @since 12
 */

#ifndef VIDEO_PROCESSING_ENGINE_C_API_IMAGE_PROCESSING_TYPES_H
#define VIDEO_PROCESSING_ENGINE_C_API_IMAGE_PROCESSING_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Define the object for image processing.
 *
 * Define a null pointer of OH_ImageProcessing and call {@link OH_ImageProcessing_Create} to create an image processing
 * instance. The pointer should be null before creating instance.
 * User can create multiple image processing instances for different processing types.
 *
 * @since 12
 */
struct OH_ImageProcessing;

/**
 * @brief Define the object for image processing.
 *
 * Define a null pointer of OH_ImageProcessing and call {@link OH_ImageProcessing_Create} to create an image processing
 * instance. The pointer should be null before creating instance.
 * User can create multiple image processing instances for different processing types.
 *
 * @since 12
 */
typedef struct OH_ImageProcessing OH_ImageProcessing;

/**
 * @brief Used to create an image processing instance for color space conversion.
 *
 * Color space conversion includes the conversion between dual-layer HDR images and single-layer HDR images,
 * as well as the color space conversion of SDR images, and the conversion of SDR images to HDR images. Some
 * capabilities are supported by vendor. Use {@link OH_ImageProcessing_IsColorSpaceConversionSupported} to query if
 * the conversion is supported between single-layer images. Use {@link OH_ImageProcessing_IsCompositionSupported} to
 * query if the composition is supported from dual-layer HDR image to single-layer HDR image. Use
 * {@link OH_ImageProcessing_IsDecompositionSupported} to query if the decomposition is supported from single-layer
 * image to dual-layer HDR image.
 *
 * @see OH_ImageProcessing_Create
 * @since 12
 */
const int IMAGE_PROCESSING_TYPE_COLORSPACE_CONVERSION = 0x1;

/**
 * @brief Used to create an image processing instance for metadata generation.
 *
 * Generate HDR Vivid metadata for single-layer image. The capability is supported by vendor. If the capability is not
 * supported, {@link OH_ImageProcessing_Create} returns {@link IMAGE_PROCESSING_ERROR_UNSUPPORTED_PROCESSING}.
 *
 * @see OH_ImageProcessing_Create
 * @since 12
 */
const int IMAGE_PROCESSING_TYPE_METADATA_GENERATION = 0x2;

/**
 * @brief The color space information is used for color space conversion capability query.
 *
 * @see OH_ImageProcessing_IsColorSpaceConversionSupported
 * @see OH_ImageProcessing_IsCompositionSupported
 * @see OH_ImageProcessing_IsDecompositionSupported
 * @since 12
 */
typedef struct ImageProcessing_ColorSpaceInformation {
    /** define metadata type */
    int metadataType;
    /** define color space, {@link enum OH_NativeBuffer_ColorSpace} */
    int colorSpace;
    /** define pixel format, {@link enum OH_NativeBuffer_Format} */
    int pixelFormat;
} ImageProcessing_ColorSpaceInformation;

/**
 * @brief Image processing error code.
 *
 * @since 12
 */
typedef enum ImageProcessing_ErrorCode {
    /** Operation is successful */
    IMAGE_PROCESSING_SUCCESS,
    /** Some unknown error occurred */
    IMAGE_PROCESSING_ERROR_UNKNOWN,
    /** Initialize global environment for image processing failed */
    IMAGE_PROCESSING_ERROR_INITIALIZE_FAILED,
    /** Create image processing instance failed */
    IMAGE_PROCESSING_ERROR_CREATE_FAILED,
    /** Process image failed */
    IMAGE_PROCESSING_ERROR_PROCESS_FAILED,
    /** Processing is not supported */
    IMAGE_PROCESSING_ERROR_UNSUPPORTED_PROCESSING,
    /** Operation is not permitted */
    IMAGE_PROCESSING_ERROR_OPERATION_NOT_PERMITTED,
    /** Out of memory */
    IMAGE_PROCESSING_ERROR_NO_MEMORY,
    /** Image processing instance is invalid */
    IMAGE_PROCESSING_ERROR_INVALID_INSTANCE,
    /** Parameter is invalid */
    IMAGE_PROCESSING_ERROR_INVALID_PARAMETER,
    /** Value is invalid. */
    IMAGE_PROCESSING_ERROR_INVALID_VALUE
} ImageProcessing_ErrorCode;

#ifdef __cplusplus
}
#endif

#endif // VIDEO_PROCESSING_ENGINE_C_API_IMAGE_PROCESSING_TYPES_H
/** @} */