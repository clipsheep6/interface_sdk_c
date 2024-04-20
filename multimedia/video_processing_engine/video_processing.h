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
 * @file video_processing.h
 *
 * @brief Declare video processing functions.
 * 
 * @library libvideo_processing_engine.so
 * @syscap SystemCapability.Multimedia.VideoProcessingEngine
 * @since 12
 */

#ifndef VIDEO_PROCESSING_ENGINE_C_API_VIDEO_PROCESSING_H
#define VIDEO_PROCESSING_ENGINE_C_API_VIDEO_PROCESSING_H

#include <stdint.h>
#include "native_window/external_window.h"
#include "video_processing_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Query if the video color space conversion is supported.
 * 
 * @param sourceVideoInformation Source video color space information.
 * @param destinationVideoInformation Destination video color space information.
 * @return Return <b>true</b> if the video color space conversion is supported. \n
 * Return <b>false</b> if the video color space conversion is not supported.
 * @since 12
 */
bool OH_VPE_IsVideoColorSpaceConversionSupported(const VPE_VideoColorSpaceInformation* sourceVideoInformation,
                                                    const VPE_VideoColorSpaceInformation* destinationVideoInformation);

/**
 * @brief Initialize global environment for video processing.
 * 
 * This function is optional. \n
 * Typically, this function is called once when the host process is started to initialize the global environment for 
 * video processing, which can decrease the time of {@link OH_VPE_CreateVideoProcessing}. Then 
 * {@link OH_VPE_DeinitializeVideoProcessingEnvironment} must be called to deinitialize the global environment.
 * 
 * @see OH_VPE_DeinitializeVideoProcessingEnvironment
 * @return {@link VPE_VIDEO_PROCESSING_ERRORCODES_OK} if succeeded. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODES_INITIALIZE_FAILED} if failed.
 * @since 12
 */
VPE_VideoProcessingErrorCode OH_VPE_InitializeVideoProcessingEnvironment();

/**
 * @brief Deinitialize global environment for video processing.
 * 
 * This function is required if {@link OH_VPE_InitializedVideoProcessingEnvironment} is called. Typically, this 
 * function is called once when the host process is to exit to deinitialize the global environment, which is 
 * initialized by calling {@link OH_VPE_InitializeVideoProcessingEnvironment}. \n
 * If there is some video processing instance existing, this function should not be called. \n
 * If the {@link OH_VPE_InitializedVideoProcessingEnvironment} is not called, this function should not be called.
 * 
 * @see OH_VPE_InitializeVideoProcessingEnvironment
 * @return {@link VPE_VIDEO_PROCESSING_ERRORCODES_OK} if succeeded. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODES_OPERATION_NOT_PERMIT} if 
 * {@link OH_VPE_InitializeVideoProcessingEnvironment} is not called. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODES_OPERATION_NOT_PERMIT} if video processing instance exists. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODES_UNKNOWN} if some internal error occurs.
 * @since 12
 */
VPE_VideoProcessingErrorCode OH_VPE_DeinitializeVideoProcessingEnvironment();

/**
 * @brief Create a video processing instance.
 * 
 * Use a null variable of {@link OH_VPE_VideoProcessing}* for creating video processing instance. \n
 * The processing type of each instance can not be changed after is created. \n
 * 
 * @param instance Output parameter. The *instance points to a new video processing object. The *instance must be NULL 
 * before passed in.
 * @param type The processing type, see {@link VPE_VIDEO_PROCESSING_TYPE_COLORSPACE_CONVERSION}, 
 * {@link VPE_VIDEO_PROCESSING_TYPE_METADATA_GENERATION}.
 * @return {@link VPE_VIDEO_PROCESSING_ERRORCODE_OK} if succeeded. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_CREATE_FAILED} if failed. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_INVALID_INSTANCE} if instance is NULL. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_INVALID_INSTANCE} if <b>*</b>instance is <b>not</b> NULL. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_INVALID_PARAMETER} if type is invalid.
 * @since 12
 */
VPE_VideoProcessingErrorCode OH_VPE_CreateVideoProcessing(OH_VPE_VideoProcessing** instance, int type);

/**
 * @brief Destroy the video processing instance.
 * 
 * Stop the instance before destroying it. see {@link OH_VPE_StopVideoProcessing}. \n
 * The instance pointer should set to NULL by user after the instance is destroyed.
 * 
 * @param instance The video processing instance to be destroyed.
 * @return {@link VPE_VIDEO_PROCESSING_ERRORCODE_OK} if succeeded. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_INVALID_INSTANCE} if instance is NULL. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_INVALID_INSTANCE} if instance is not a video processing instance. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_OPERATION_NOT_PERMIT} if the instance is still running. \n
 * @since 12
 */
VPE_VideoProcessingErrorCode OH_VPE_DestroyVideoProcessing(OH_VPE_VideoProcessing* instance);

/**
 * @brief Register callback object.
 * 
 * Register the callback object before starting video processing. \n
 * The callback object can be destroyed after it is registered.
 * 
 * @param instance An existing video processing instance.
 * @param callback Callback object to be registered. see {@link VPE_VideoProcessingCallback}.
 * @param userData User's custom data.
 * @see OH_VPE_CreateVideoProcessingCallback
 * @see OH_VPE_DestroyVideoProcessingCallback
 * @see OH_VPE_BindVideoProcessingCallbackOnError
 * @see OH_VPE_BindVideoProcessingCallbackOnState
 * @see OH_VPE_BindVideoProcessingCallbackOnNewOutputBuffer
 * @return {@link VPE_VIDEO_PROCESSING_ERRORCODE_OK} if succeeded. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_INVALID_INSTANCE} if instance is NULL. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_INVALID_INSTANCE} if instance is not a video processing instance. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_INVALID_PARAMETER} if callback is NULL. \n
 * @since 12
 */
VPE_VideoProcessingErrorCode OH_VPE_RegisterVideoProcessingCallback(OH_VPE_VideoProcessing* instance,
                                                                    const VPE_VideoProcessingCallback* callback,
                                                                    void* userData);

/**
 * @brief Set the output surface for video processing.
 * 
 * Set the output surface before starting video processing.
 * 
 * @param instance An existing video processing instance.
 * @param window The output surface.
 * @return {@link VPE_VIDEO_PROCESSING_ERRORCODE_OK} if succeeded. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_INVALID_INSTANCE} if instance is NULL. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_INVALID_INSTANCE} if instance is not a video processing instance. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_INVALID_PARAMETER} if window is NULL.
 * @since 12
 */
VPE_VideoProcessingErrorCode OH_VPE_SetVideoProcessingSurface(OH_VPE_VideoProcessing* instance,
                                                                const OHNativeWindow* window);

/**
 * @brief Create an input surface.
 * 
 * Create the input surface before starting video processing. \n
 * Call {@link OH_NativeWindow_DestroyNativeWindow} to destroy the input surface.
 * 
 * @param instance An existing video processing instance.
 * @param window The input surface. Usually, it is the output surface of a video decoder.
 * @return {@link VPE_VIDEO_PROCESSING_ERRORCODE_OK} if succeeded. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_INVALID_INSTANCE} if instance is NULL. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_INVALID_INSTANCE} if instance is not a video processing instance. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_INVALID_PARAMETER} if window is NULL. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_INVALID_PARAMETER} if <b>*</b>window is <b>not</b> NULL. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_OPERATION_NOT_PERMIT} if creating surface failed.
 * @since 12
 */
VPE_VideoProcessingErrorCode OH_VPE_GetVideoProcessingSurface(OH_VPE_VideoProcessing* instance,
                                                                OHNativeWindow** window);

/**
 * @brief Start video processing.
 * 
 * After calling this function, the {@link VPE_VIDEO_PROCESSING_STATE_RUNNING} is reported by callback function 
 * {@link OH_VPE_OnVideoProcessingState}.
 * 
 * @param instance An existing video processing instance.
 * @return {@link VPE_VIDEO_PROCESSING_ERRORCODE_OK} if succeeded. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_INVALID_INSTANCE} if instance is NULL. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_INVALID_INSTANCE} if instance is not a video processing instance. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_OPERATION_NOT_PERMIT} if callback is not registered. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_OPERATION_NOT_PERMIT} if output surface is not set. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_OPERATION_NOT_PERMIT} if input surface is not created. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_OPERATION_NOT_PERMIT} if instance is running.
 * @since 12
 */
VPE_VideoProcessingErrorCode OH_VPE_StartVideoProcessing(OH_VPE_VideoProcessing* instance);

/**
 * @brief Stop video processing.
 * 
 * After all the cached buffers before this function is called are processed, the 
 * {@link VPE_VIDEO_PROCESSING_STATE_STOPPED} is reported by callback function {@link OH_VPE_OnVideoProcessingState}.
 * 
 * 
 * @param instance An existing video processing instance.
 * @return {@link VPE_VIDEO_PROCESSING_ERRORCODE_OK} if succeeded. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_INVALID_INSTANCE} if instance is NULL. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_INVALID_INSTANCE} if instance is not a video processing instance. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_OPERATION_NOT_PERMIT} if this function is called. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_OPERATION_NOT_PERMIT} if instance is stopped.
 * @since 12
 */
VPE_VideoProcessingErrorCode OH_VPE_StopVideoProcessing(OH_VPE_VideoProcessing* instance);

/**
 * @brief Send the output buffer out.
 * 
 * If the callback function {@link OH_VPE_OnVideoProcessingNewOutputBuffer} is not set, this function should not be 
 * called.
 * 
 * @param instance An existing video processing instance.
 * @param index The output buffer's index from callback function {@link VPE_OnVideoProcessingNewOutputBuffer}.
 * @return {@link VPE_VIDEO_PROCESSING_ERRORCODE_OK} if succeeded. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_INVALID_INSTANCE} if instance is NULL. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_INVALID_INSTANCE} if instance is not a video processing instance. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_INVALID_PARAMETER} if index is invalid. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_OPERATION_NOT_PERMIT} if callback 
 * {@link OH_VPE_OnVideoProcessingNewOutputBuffer} is not set. \n
 * {@link VPE_VIDEO_PROCESSING_ERRORCODE_OPERATION_NOT_PERMIT} if instance is stopped.
 * @since 12
 */
VPE_VideoProcessingErrorCode OH_VPE_RenderVideoProcessingOutputBuffer(OH_VPE_VideoProcessing* instance, uint32_t index);

#ifdef __cplusplus
}
#endif

#endif // VIDEO_PROCESSING_ENGINE_C_API_VIDEO_PROCESSING_H
/** @} */