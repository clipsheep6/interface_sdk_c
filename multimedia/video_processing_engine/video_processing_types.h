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
 * @addtogroup VideoProcessingEngine
 * @{
 *
 * @brief 
 *
 * 
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
 * @brief Define the video processing instance type.
 * 
 * Use a null OH_VPE_VideoProcessing* variable and call {@link OH_VPE_CreateVideoProcessing} to create a video \n
 * processing object.
 * The variable should be NULL before creating object.
 * 
 * @since 12
 */
struct OH_VPE_VideoProcessing;
typedef struct OH_VPE_VideoProcessing_ OH_VPE_VideoProcessing;

/**
 * @brief Video colorspace information structure.
 * 
 * @see OH_VPE_IsVideoColorSpaceConversionSupported
 * @since 12
 */
typedef struct VPE_VideoColorSpaceInformation {
    /** The metadata type of the video */
    int metadataType;
    /** The color space type of the video, the value is defined in {@link enum OH_NativeBuffer_ColorSpace} */
    int colorSpace;
    /** The pixel format of the video, the value is defined in {@link enum OH_NativeBuffer_Format} */
    int pixelFormat;
} VPE_VideoColorSpaceInformation;

/**
 * @brief Video processing error codes.
 * 
 * @since 12
 */
typedef enum VPE_VideoProcessingErrorCode {
    /** Operation succeeded */
    VPE_VIDEO_PROCESSING_ERRORCODE_OK,
    /** Some unknown error occurred */
    VPE_VIDEO_PROCESSING_ERRORCODE_UNKNOWN,
    /** Initializing global environment for video processing failed */
    VPE_VIDEO_PROCESSING_ERRORCODE_INITIALIZE_FAILED,
    /** Creating video processing instance failed */
    VPE_VIDEO_PROCESSING_ERRORCODE_CREATE_FAILED,
    /** Processing video failed */
    VPE_VIDEO_PROCESSING_ERRORCODE_PROCESS_FAILED,
    /** Out of memory */
    VPE_VIDEO_PROCESSING_ERRORCODE_NO_MEMORY,
    /** The processing is not supported */
    VPE_VIDEO_PROCESSING_ERRORCODE_UNSUPPORTED_PROCESSING,
    /** The operation is not permitted */
    VPE_VIDEO_PROCESSING_ERRORCODE_OPERATION_NOT_PERMIT,
    /** The processing instance is invalid */
    VPE_VIDEO_PROCESSING_ERRORCODE_INVALID_INSTANCE,
    /** The parameter is invalid */
    VPE_VIDEO_PROCESSING_ERRORCODE_INVALID_PARAMETER,
    /** The value is invalid */
    VPE_VIDEO_PROCESSING_ERRORCODE_INVALID_VALUE
} VPE_VideoProcessingErrorCode;

/**
 * @brief Used to create a video processing instance for color space conversion.
 * 
 * @see OH_VPE_CreateVideoProcessing
 * @since 12
 */
const int VPE_VIDEO_PROCESSING_TYPE_COLORSPACE_CONVERSION = 0x10000;

/**
 * @brief Used to create a video processing instance for metadata generation.
 * 
 * @see OH_VPE_CreateVideoProcessing
 * @since 12
 */
const int VPE_VIDEO_PROCESSING_TYPE_METADATA_GENERATION = 0x20000;

/**
 * @brief Video processing states.
 * 
 * When the video processing instance is created, the state is {@link VPE_VIDEO_PROCESSING_STATE_RUNNING}. \n
 * The state is reported to user by callback function {@link OH_VPE_OnVideoProcessingState}.
 * 
 * @since 12
 */
typedef enum VPE_VideoProcessingState {
    /** Video processing is running */
    VPE_VIDEO_PROCESSING_STATE_RUNNING,
    /** Video processing is stopped */
    VPE_VIDEO_PROCESSING_STATE_STOPPED
} VPE_VideoProcessingState;

/**
 * @brief Video processing asynchronous callback object type.
 * 
 * Use a null variable of VPE_VideoProcessingCallback* and call {@link OH_VPE_CreateVideoProcessingCallback} to create a 
 * callback object. Then call {@link OH_VPE_RegisterVideoProcessingCallback} to register it. \n
 * The variable should be NULL before creating the callback object.
 * 
 * @since 12
 */
struct VPE_VideoProcessingCallback;
typedef struct VPE_VideoProcessingCallback VPE_VideoProcessingCallback;

/**
 * @brief The callback function pointer definition for reporting error during video processing.
 * 
 * This callback function is required. \n
 * Errors: \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_UNSUPPORTED_PROCESSING}, the processing is not supported. For example, the
 * color space conversion according to the source and destination videos' properties is not supported. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_INVALID_VALUE}, some property of the video is invalid. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_NO_MEMORY}, out of memory. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_PROCESS_FAILED}, some internal error occurred.
 * 
 * @param instance The video processing instance.
 * @param error see {@link VPE_VideoProcessingErrorCode}.
 * @param userData User's custom data.
 * @since 12
 */
typedef void (*OH_VPE_OnVideoProcessingError)(OH_VPE_VideoProcessing* instance, VPE_VideoProcessingErrorCode error,
                                                void* userData);

/**
 * @brief The callback function pointer definition for reporting video processing state.
 * 
 * This callback is required. \n
 * The state will be {@link VPE_VIDEO_PROCESSING_STATE_RUNNING} after {@link OH_VPE_VideoProcessing_Start} is called 
 * successfully. \n
 * The state will be {@link VPE_VIDEO_PROCESSING_STATE_STOPPED} after all the buffers cached before 
 * {@link OH_VPE_VideoProcessing_Stop} is called are processed.
 * 
 * @param instance The video processing instance.
 * @param state see {@link VPE_VideoProcessingState}.
 * @param userData User's custom data.
 * @since 12
 */
typedef void (*OH_VPE_OnVideoProcessingState)(OH_VPE_VideoProcessing* instance, VPE_VideoProcessingState state,
                                                void* userData);

/**
 * @brief The callback function pointer definition for reporting a new output buffer is filled with processed data.
 * 
 * This callback function is optional. \n
 * If user wants to control the time to send the output buffer out, this callback function is required. Every new 
 * output buffer's index will report to user once the buffer is filled with processed data. Then call 
 * {@link OH_VPE_RenderVideoProcessingOutputBuffer} with the buffer's index to send the output buffer out. \n
 * If this function is not registered, the output buffer is sent out as soon as the buffer is filled with processed 
 * data without reporting. In this case, {@link OH_VPE_RenderVideoProcessingOutputBuffer} is not called.
 * 
 * @param instance The video processing instance.
 * @param index The index of the new output buffer.
 * @param userData The user's custom data.
 * @since 12
 */
typedef void (*OH_VPE_OnVideoProcessingNewOutputBuffer)(OH_VPE_VideoProcessing* instance, uint32_t index,
                                                        void* userData);

/**
 * @brief Create a video processing callback object.
 * 
 * Declare a {@link VPE_VideoProcessingCallback}* variable for creating callback object. \n
 * The *callback should be NULL before creating the callback object.
 * 
 * @param callback Output parameter. The *callback points to a new callback object.
 * @return {@link VPE_VIDEO_PROCESSING_ERRORCODE_OK} if callback object is created. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_INVALID_PARAMETER} if callback is NULL. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_INVALID_PARAMETER} if <b>*</b>callback is <b>not</b> NULL. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_NO_MEMORY} if callback object cannot be created.
 * @since 12
 */
VPE_VideoProcessingErrorCode OH_VPE_CreateVideoProcessingCallback(VPE_VideoProcessingCallback** callback);

/**
 * @brief Destroy the callback object.
 * 
 * The callback object can be destroyed after it is registered to video processing instance. \n
 * The callback pointer should be set to NULL by user after calling this function.
 * 
 * @param callback The callback object to destroy.
 * @return {@link VPE_VIDEO_PROCESSING_ERRORCODE_OK} if callback is successfully destroyed. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_INVALID_PARAMETER} if callback is NULL.
 * @since 12
 */
VPE_VideoProcessingErrorCode OH_VPE_DestroyVideoProcessingCallback(VPE_VideoProcessingCallback* callback);

/**
 * @brief Bind the {@link OH_VPE_OnVideoProcessingError} callback function to callback object.
 * 
 * @param callback An existing callback object.
 * @param onError The callback function.
 * @return {@link VPE_VIDEO_PROCESSING_ERRORCODE_OK} if the callback is set. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_INVALID_PARAMETER} if the callback is NULL. \n
 * @since 12
 */
VPE_VideoProcessingErrorCode OH_VPE_BindVideoProcessingCallbackOnError(
    VPE_VideoProcessingCallback* callback,
    OH_VPE_OnVideoProcessingError onError);

/**
 * @brief Bind the {@link OH_VPE_OnVideoProcessingState} callback function to callback object.
 * 
 * @param callback An existing callback object.
 * @param onState The callback function.
 * @return {@link VPE_VIDEO_PROCESSING_ERRORCODE_OK} if the callback is set. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_INVALID_PARAMETER} if the callback is NULL. \n
 * @since 12
 */
VPE_VideoProcessingErrorCode OH_VPE_BindVideoProcessingCallbackOnState(
    VPE_VideoProcessingCallback* callback,
    OH_VPE_OnVideoProcessingState onState);

/**
 * @brief Bind the {@link OH_VPE_OnVideoProcessingNewOutputBuffer} callback function to callback object.
 * 
 * @param callback An existing callback object.
 * @param onNewOutputBuffer The callback function.
 * @return {@link VPE_VIDEO_PROCESSING_ERRORCODE_OK} if the callback is set. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_INVALID_PARAMETER} if the callback is NULL. \n
 * @since 12
 */
VPE_VideoProcessingErrorCode OH_VPE_BindVideoProcessingCallbackOnNewOutputBuffer(
    VPE_VideoProcessingCallback* callback,
    OH_VPE_OnVideoProcessingNewOutputBuffer onNewOutputBuffer);

#ifdef __cplusplus
}
#endif

#endif // VIDEO_PROCESSING_ENGINE_C_API_VIDEO_PROCESSING_TYPES_H
/** @} */