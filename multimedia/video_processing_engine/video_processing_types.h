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
 * @addtogroup VideoProcessing
 * @{
 *
 * @brief Provide video processing including color space conversion and metadata generation.
 *
 * @since 12
 */

/**
 * @file video_processing_types.h
 *
 * @brief Type definitions for video processing.
 *
 * @library libvideo_processing_engine.so
 * @syscap SystemCapability.Multimedia.VideoProcessingEngine
 * @since 12
 */

#ifndef VIDEO_PROCESSING_ENGINE_C_API_VIDEO_PROCESSING_TYPES_H
#define VIDEO_PROCESSING_ENGINE_C_API_VIDEO_PROCESSING_TYPES_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Define the video processing object.
 *
 * Define a null pointer of OH_VideoProcessing and call {@link OH_VideoProcessing_Create} to create a video processing
 * instance. The pointer should be null before creating instance.
 * User can create multiple video processing instances for different processing types.
 *
 * @since 12
 */
struct OH_VideoProcessing;

/**
 * @brief Define the video processing object.
 *
 * Define a null pointer of OH_VideoProcessing and call {@link OH_VideoProcessing_Create} to create a video processing
 * instance. The pointer should be null before creating instance.
 * User can create multiple video processing instances for different processing types.
 *
 * @since 12
 */
typedef struct OH_VideoProcessing OH_VideoProcessing;

/**
 * @brief Used to create a video processing instance for color space conversion.
 *
 * Some capabilities are supported by vendor. Use {@link OH_VideoProcessing_IsColorSpaceConversionSupported} to query if
 * the conversion is supported.
 *
 * @see OH_VideoProcessing_Create
 * @since 12
 */
const int VIDEO_PROCESSING_TYPE_COLORSPACE_CONVERSION = 0x10000;

/**
 * @brief Used to create a video processing instance for metadata generation.
 *
 * Generate HDR vivid metadata for video. The capability is supported by vendor. If the capability is not supported,
 * {@link OH_VideoProcessing_Create} returns {@link VIDEO_PROCESSING_ERROR_UNSUPPORTED_PROCESSING}.
 *
 * @see OH_VideoProcessing_Create
 * @since 12
 */
const int VIDEO_PROCESSING_TYPE_METADATA_GENERATION = 0x20000;

/**
 * @brief Video color space information structure of querying if video color space conversion is supported.
 *
 * @see OH_VideoProcessing_IsColorSpaceConversionSupported
 * @since 12
 */
typedef struct VideoProcessing_ColorSpaceInformation {
    /** The metadata type of the video */
    int metadataType;
    /** The color space type of the video, see {@link enum OH_NativeBuffer_ColorSpace} */
    int colorSpace;
    /** The pixel format of the video, see {@link enum OH_NativeBuffer_Format} */
    int pixelFormat;
} VideoProcessing_ColorSpaceInformation;

/**
 * @brief Video processing error code.
 *
 * @since 12
 */
typedef enum VideoProcessing_ErrorCode {
    /** Operation is successful */
    VIDEO_PROCESSING_SUCCESS,
    /** Some unknown error occurred */
    VIDEO_PROCESSING_ERROR_UNKNOWN,
    /** Initializing global environment for video processing failed */
    VIDEO_PROCESSING_ERROR_INITIALIZE_FAILED,
    /** Create video processing instance failed */
    VIDEO_PROCESSING_ERROR_CREATE_FAILED,
    /** Process video failed */
    VIDEO_PROCESSING_ERROR_PROCESS_FAILED,
    /** The processing is not supported */
    VIDEO_PROCESSING_ERROR_UNSUPPORTED_PROCESSING,
    /** Operation is not permitted */
    VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED,
    /** Out of memory */
    VIDEO_PROCESSING_ERROR_NO_MEMORY,
    /** Video processing instance is invalid */
    VIDEO_PROCESSING_ERROR_INVALID_INSTANCE,
    /** Parameter is invalid. */
    VIDEO_PROCESSING_ERROR_INVALID_PARAMETER,
    /** Value is invalid */
    VIDEO_PROCESSING_ERROR_INVALID_VALUE
} VideoProcessing_ErrorCode;

/**
 * @brief Video processing states.
 *
 * The state is reported to user by callback function {@link OH_VideoProcessing_OnState}.
 *
 * @since 12
 */
typedef enum VideoProcessing_State {
    /** Video processing is running */
    VIDEO_PROCESSING_STATE_RUNNING,
    /** Video processing is stopped */
    VIDEO_PROCESSING_STATE_STOPPED
} VideoProcessing_State;

/**
 * @brief Video processing asynchronous callback object type.
 *
 * Define a null pointer of VideoProcessing_Callback and call {@link OH_VideoProcessingCallback_Create} to create a
 * callback object. The pointer should be null before creating the callback object.
 * Register the callback to a video processing instance by calling {@link OH_VideoProcessing_RegisterCallback}.
 *
 * @since 12
 */
struct VideoProcessing_Callback;

/**
 * @brief Video processing asynchronous callback object type.
 *
 * Define a null pointer of VideoProcessing_Callback and call {@link OH_VideoProcessingCallback_Create} to create a
 * callback object. The pointer should be null before creating the callback object.
 * Register the callback to a video processing instance by calling {@link OH_VideoProcessing_RegisterCallback}.
 *
 * @since 12
 */
typedef struct VideoProcessing_Callback VideoProcessing_Callback;

/**
 * @brief The callback function pointer definition for reporting error during video processing.
 *
 * Errors: \n
 * {@link VIDEO_PROCESSING_ERROR_UNSUPPORTED_PROCESSING}, the processing is not supported. For example, the
 * color space conversion according to the source and destination videos' properties is not supported. \n
 * {@link VIDEO_PROCESSING_ERROR_INVALID_VALUE}, some property of the video is invalid. For example, the color space of
 * the video is invalid. \n
 * {@link VIDEO_PROCESSING_ERROR_NO_MEMORY}, out of memory. \n
 * {@link VIDEO_PROCESSING_ERROR_PROCESS_FAILED}, some processing error occurs. \n
 * For more errors, see {@link VideoProcessing_ErrorCode}.
 *
 * @param instance The video processing instance.
 * @param error Error code reporting to user.
 * @param userData User's custom data.
 * @since 12
 */
typedef void (*OH_VideoProcessingCallback_OnError)(OH_VideoProcessing* instance, VideoProcessing_ErrorCode error,
    void* userData);

/**
 * @brief The callback function pointer definition for reporting video processing state.
 *
 * The state will be {@link VIDEO_PROCESSING_STATE_RUNNING} after {@link OH_VideoProcessing_Start} is called
 * successfully.
 * The state will be {@link VIDEO_PROCESSING_STATE_STOPPED} after all the buffers cached before
 * {@link OH_VideoProcessing_Stop} is called are processed.
 *
 * @param instance The video processing instance.
 * @param state see {@link VideoProcessing_State}.
 * @param userData User's custom data.
 * @since 12
 */
typedef void (*OH_VideoProcessingCallback_OnState)(OH_VideoProcessing* instance, VideoProcessing_State state,
    void* userData);

/**
 * @brief The callback function pointer definition for reporting a new output buffer is filled with processed data.
 *
 * Every new output buffer's index will report to user once the buffer is filled with processed data. Then call
 * {@link OH_VideoProcessing_RenderOutputBuffer} with the buffer's index to send the output buffer out.
 * If this function is not registered, the output buffer is sent out as soon as the buffer is filled with processed
 * data without reporting.
 *
 * @param instance The video processing instance.
 * @param index The index of the new output buffer.
 * @param userData The user's custom data.
 * @since 12
 */
typedef void (*OH_VideoProcessingCallback_OnNewOutputBuffer)(OH_VideoProcessing* instance, uint32_t index,
    void* userData);

#ifdef __cplusplus
}
#endif

#endif // VIDEO_PROCESSING_ENGINE_C_API_VIDEO_PROCESSING_TYPES_H
/** @} */