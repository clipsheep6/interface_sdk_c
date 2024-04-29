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
 * @brief Initialize global environment for video processing.
 *
 * This function is optional. \n
 * Typically, this function is called once when the host process is started to initialize the global environment for
 * video processing, which can reduce the time of {@link OH_VideoProcessing_Create}. \n
 * To deinitialize global environment, call {@link OH_VideoProcessing_DeinitializeEnvironment}.
 *
 * @return {@link VIDEO_PROCESSING_SUCCESS} if initialization is successful. \n
 * {@link VIDEO_PROCESSING_ERROR_INITIALIZE_FAILED} if initialization is failed.
 * @since 12
 */
VideoProcessing_ErrorCode OH_VideoProcessing_InitializeEnvironment();

/**
 * @brief Deinitialize global environment for video processing.
 *
 * This function is required if {@link OH_VideoProcessing_InitializeEnvironment} is called. Typically, this
 * function is called when the host process is about to exit to deinitialize the global environment, which is
 * initialized by calling {@link OH_VideoProcessing_InitializeEnvironment}. \n
 * If there is some video processing instance existing, this function should not be called. \n
 * If the {@link OH_VideoProcessing_InitializeEnvironment} is not called, this function should not be called.
 *
 * @return {@link VIDEO_PROCESSING_SUCCESS} if deinitialization is successful. \n
 * {@link VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED} if some video processing instance is not destroyed or
 * {@link OH_VideoProcessing_InitializeEnvironment} is not called. \n
 * @since 12
 */
VideoProcessing_ErrorCode OH_VideoProcessing_DeinitializeEnvironment();

/**
 * @brief Query if the video color space conversion is supported.
 *
 * @param sourceVideoInformation Source video color space information.
 * @param destinationVideoInformation Destination video color space information.
 * @return <b>true</b> if the video color space conversion is supported. \n
 * <b>false</b> if the video color space conversion is not supported.
 * @since 12
 */
bool OH_VideoProcessing_IsColorSpaceConversionSupported(
    const VideoProcessing_ColorSpaceInformation* sourceVideoInformation,
    const VideoProcessing_ColorSpaceInformation* destinationVideoInformation);

/**
 * @brief Create a video processing instance.
 *
 * @param instance Output parameter. The *instance points to a new video processing object. The *instance must be null
 * before passed in.
 * @param type Use VIDEO_PROCESSING_TYPE_XXX to specify the processing type. The processing type of the instance can not
 * be changed.
 * @return {@link VIDEO_PROCESSING_SUCCESS} if creating a video processing instance successfully. \n
 * {@link VIDEO_PROCESSING_ERROR_CREATE_FAILED} if failed to create a video processing instance. \n
 * {@link VIDEO_PROCESSING_ERROR_INVALID_INSTANCE} if instance is null or <b>*</b>instance is <b>not</b> null. \n
 * {@link VIDEO_PROCESSING_ERROR_INVALID_PARAMETER} if type is invalid.
 * @since 12
 */
VideoProcessing_ErrorCode OH_VideoProcessing_Create(OH_VideoProcessing** instance, int type);

/**
 * @brief Destroy the video processing instance.
 *
 * Stop the instance before destroying it. see {@link OH_VideoProcessing_Stop}. \n
 *
 * @param instance The video processing instance pointer to be destroyed. It is recommended setting the instance pointer
 * to null after the instance is destroyed.
 * @return {@link VIDEO_PROCESSING_SUCCESS} if the instance is destroyed successfully . \n
 * {@link VIDEO_PROCESSING_ERROR_INVALID_INSTANCE} if instance is null or not a video processing instance. \n
 * {@link VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED} if the instance is still running.
 * @since 12
 */
VideoProcessing_ErrorCode OH_VideoProcessing_Destroy(OH_VideoProcessing* instance);

/**
 * @brief Register callback object.
 *
 * Register the callback object before starting video processing.
 *
 * @param instance A video processing instance pointer.
 * @param callback Callback pointer to be registered.
 * @param userData User's custom data pointer.
 * @return {@link VIDEO_PROCESSING_SUCCESS} if callback is registered successfully. \n
 * {@link VIDEO_PROCESSING_ERROR_INVALID_INSTANCE} if instance is null or not a video processing instance. \n
 * {@link VIDEO_PROCESSING_ERROR_INVALID_PARAMETER} if callback is null. \n
 * {@link VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED} if video processing instance is running.
 * @since 12
 */
VideoProcessing_ErrorCode OH_VideoProcessing_RegisterCallback(OH_VideoProcessing* instance,
    const VideoProcessing_Callback* callback, void* userData);

/**
 * @brief Set the output surface for video processing.
 *
 * Set the output surface before starting video processing.
 *
 * @param instance A video processing instance pointer.
 * @param window The output surface pointer.
 * @return {@link VIDEO_PROCESSING_SUCCESS} if setting output surface successfully. \n
 * {@link VIDEO_PROCESSING_ERROR_INVALID_INSTANCE} if instance is null or not a video processing instance. \n
 * {@link VIDEO_PROCESSING_ERROR_INVALID_PARAMETER} if window is null.
 * @since 12
 */
VideoProcessing_ErrorCode OH_VideoProcessing_SetSurface(OH_VideoProcessing* instance, const OHNativeWindow* window);

/**
 * @brief Create an input surface.
 *
 * Create the input surface before starting video processing.
 * Call {@link OH_NativeWindow_DestroyNativeWindow} to destroy the input surface.
 *
 * @param instance A video processing instance pointer.
 * @param window The input surface pointer. For example, it is the output surface of a video decoder.
 * @return {@link VIDEO_PROCESSING_SUCCESS} if operation is successful. \n
 * {@link VIDEO_PROCESSING_ERROR_INVALID_INSTANCE} if instance is null or not a video processing instance. \n
 * {@link VIDEO_PROCESSING_ERROR_INVALID_PARAMETER} if window is null or <b>*</b>window is <b>not</b> null. \n
 * {@link VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED} if creating surface failed, input surface is already created
 * or video processing instance is running.
 * @since 12
 */
VideoProcessing_ErrorCode OH_VideoProcessing_GetSurface(OH_VideoProcessing* instance, OHNativeWindow** window);

/**
 * @brief Start video processing.
 *
 * After successfully calling this function, the {@link VIDEO_PROCESSING_STATE_RUNNING} is reported by callback function
 * {@link OH_VideoProcessingCallback_OnState}.
 *
 * @param instance A video processing instance pointer.
 * @return {@link VIDEO_PROCESSING_SUCCESS} if the operation is successful. \n
 * {@link VIDEO_PROCESSING_ERROR_INVALID_INSTANCE} if instance is null or not a video processing instance. \n
 * {@link VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED} if output surface is not set, input surface is not created or
 * instance is already running.
 * @since 12
 */
VideoProcessing_ErrorCode OH_VideoProcessing_Start(OH_VideoProcessing* instance);

/**
 * @brief Stop video processing.
 *
 * After all the cached buffers before this function is called are processed, the
 * {@link VIDEO_PROCESSING_STATE_STOPPED} is reported by callback function {@link OH_VideoProcessing_OnState}.
 *
 * @param instance A video processing instance pointer.
 * @return {@link VIDEO_PROCESSING_SUCCESS} if the operation is successful. \n
 * {@link VIDEO_PROCESSING_ERROR_INVALID_INSTANCE} if instance is null or not a video processing instance. \n
 * {@link VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED} if instance is already stopped.
 * @since 12
 */
VideoProcessing_ErrorCode OH_VideoProcessing_Stop(OH_VideoProcessing* instance);

/**
 * @brief Send the output buffer out.
 *
 * If the callback function {@link OH_VideoProcessingCallback_OnNewOutputBuffer} is set, the buffer's index is reported
 * to user by the callback function when an output buffer is ready.
 *
 * @param instance A video processing instance pointer.
 * @param index The output buffer's index.
 * @return {@link VIDEO_PROCESSING_SUCCESS} if the operation is successful. \n
 * {@link VIDEO_PROCESSING_ERROR_INVALID_INSTANCE} if instance is null or not a video processing instance. \n
 * {@link VIDEO_PROCESSING_ERROR_INVALID_PARAMETER} if index is invalid. \n
 * {@link VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED} if callback {@link OH_VideoProcessing_OnNewOutputBuffer} is
 * not set or instance is stopped.
 * @since 12
 */
VideoProcessing_ErrorCode OH_VideoProcessing_RenderOutputBuffer(OH_VideoProcessing* instance, uint32_t index);

/**
 * @brief Create a video processing callback object.
 *
 * @param callback Output parameter. The *callback points to a new callback object. The *callback should be null before
 * creating the callback object.
 * @return {@link VIDEO_PROCESSING_SUCCESS} if callback object is created successfully. \n
 * {@link VIDEO_PROCESSING_ERROR_INVALID_PARAMETER} if callback is null or <b>*</b>callback is <b>not</b> null. \n
 * {@link VIDEO_PROCESSING_ERROR_NO_MEMORY} if out of memory.
 * @since 12
 */
VideoProcessing_ErrorCode OH_VideoProcessingCallback_Create(VideoProcessing_Callback** callback);

/**
 * @brief Destroy the callback object.
 *
 * The callback object can be destroyed after it is registered to video processing instance.
 *
 * @param callback The callback object pointer. It is recommended setting the callback pointer to null after the
 * callback object is destroyed.
 * @return {@link VIDEO_PROCESSING_SUCCESS} if callback is successfully destroyed. \n
 * {@link VIDEO_PROCESSING_ERROR_INVALID_PARAMETER} if callback is null.
 * @since 12
 */
VideoProcessing_ErrorCode OH_VideoProcessingCallback_Destroy(VideoProcessing_Callback* callback);

/**
 * @brief Bind the {@link OH_VideoProcessingCallback_OnError} callback function to callback object.
 *
 * @param callback A callback object pointer.
 * @param onError The callback function.
 * @return {@link VIDEO_PROCESSING_SUCCESS} if the function is bound to callback object successfully. \n
 * {@link VIDEO_PROCESSING_ERROR_INVALID_PARAMETER} if the callback is null or onError is null.
 * @since 12
 */
VideoProcessing_ErrorCode OH_VideoProcessingCallback_BindOnError(VideoProcessing_Callback* callback,
    OH_VideoProcessingCallback_OnError onError);

/**
 * @brief Bind the {@link OH_VideoProcessingCallback_OnState} callback function to callback object.
 *
 * @param callback A callback object pointer.
 * @param onState The callback function.
 * @return {@link VIDEO_PROCESSING_SUCCESS} if the function is bound to callback object successfully. \n
 * {@link VIDEO_PROCESSING_ERROR_INVALID_PARAMETER} if the callback is null or onState is null.
 * @since 12
 */
VideoProcessing_ErrorCode OH_VideoProcessingCallback_BindOnState(VideoProcessing_Callback* callback,
    OH_VideoProcessingCallback_OnState onState);

/**
 * @brief Bind the {@link OH_VideoProcessingCallback_OnNewOutputBuffer} callback function to callback object.
 *
 * @param callback A callback object pointer.
 * @param onNewOutputBuffer The callback function.
 * @return {@link VIDEO_PROCESSING_SUCCESS} if the function is bound to callback object successfully. \n
 * {@link VIDEO_PROCESSING_ERROR_INVALID_PARAMETER} if the callback is null.
 * @since 12
 */
VideoProcessing_ErrorCode OH_VideoProcessingCallback_BindOnNewOutputBuffer(VideoProcessing_Callback* callback,
    OH_VideoProcessingCallback_OnNewOutputBuffer onNewOutputBuffer);

#ifdef __cplusplus
}
#endif

#endif // VIDEO_PROCESSING_ENGINE_C_API_VIDEO_PROCESSING_H
/** @} */