/*
 * Copyright (C) 2023 Huawei Device Co., Ltd.
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

#ifndef NATIVE_AVCODEC_VIDEODECODER_H
#define NATIVE_AVCODEC_VIDEODECODER_H

#include <stdint.h>
#include <stdio.h>
#include "native_averrors.h"
#include "native_avformat.h"
#include "native_avmemory.h"
#include "native_avcodec_base.h"
#include "native_drm_common.h"
#include "native_mediakeysession.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Creates a video decoder instance from the mime type, which is recommended in most cases.
 * @syscap SystemCapability.Multimedia.Media.VideoDecoder
 * @param mime mime type description string, refer to {@link AVCODEC_MIME_TYPE}
 * @return Returns a Pointer to an OH_AVCodec instance
 * @since 9
 * @version 1.0
 */
OH_AVCodec *OH_VideoDecoder_CreateByMime(const char *mime);

/**
 * @brief Create a video decoder instance through the video decoder name.
 * The premise of using this interface is to know the exact name of the decoder.
 * @syscap SystemCapability.Multimedia.Media.VideoDecoder
 * @param name video codec name
 * @return Returns a Pointer to an OH_AVCodec instance
 * @since 9
 * @version 1.0
 */
OH_AVCodec *OH_VideoDecoder_CreateByName(const char *name);

/**
 * @brief Clear the internal resources of the decoder and destroy the decoder instance
 * @syscap SystemCapability.Multimedia.Media.VideoDecoder
 * @param codec Pointer to an OH_AVCodec instance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * @since 9
 * @version 1.0
 */
OH_AVErrCode OH_VideoDecoder_Destroy(OH_AVCodec *codec);

/**
 * @brief Set the asynchronous callback function so that your application can respond to the events
 * generated by the video decoder. This interface must be called before Prepare is called.
 * @syscap SystemCapability.Multimedia.Media.VideoDecoder
 * @param codec Pointer to an OH_AVCodec instance
 * @param callback A collection of all callback functions, see {@link OH_AVCodecAsyncCallback}
 * @param userData User specific data
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * @since 9
 * @version 1.0
 */
OH_AVErrCode OH_VideoDecoder_SetCallback(OH_AVCodec *codec, OH_AVCodecAsyncCallback callback, void *userData);

/**
 * @brief Specify the output Surface to provide video decoding output,
 * this interface must be called before Prepare is called
 * @syscap SystemCapability.Multimedia.Media.VideoDecoder
 * @param codec Pointer to an OH_AVCodec instance
 * @param window A pointer to a OHNativeWindow instance, see {@link OHNativeWindow}
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * @since 9
 * @version 1.0
 */
OH_AVErrCode OH_VideoDecoder_SetSurface(OH_AVCodec *codec, OHNativeWindow *window);

/**
 * @brief To configure the video decoder, typically, you need to configure the description information of the decoded
 * video track, which can be extracted from the container. This interface must be called before Prepare is called.
 * @syscap SystemCapability.Multimedia.Media.VideoDecoder
 * @param codec Pointer to an OH_AVCodec instance
 * @param format A pointer to an OH_AVFormat to give the description of the video track to be decoded
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * @since 9
 * @version 1.0
 */
OH_AVErrCode OH_VideoDecoder_Configure(OH_AVCodec *codec, OH_AVFormat *format);

/**
 * @brief To prepare the internal resources of the decoder, the Configure interface must be called before
 * calling this interface.
 * @syscap SystemCapability.Multimedia.Media.VideoDecoder
 * @param codec Pointer to an OH_AVCodec instance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * @since 9
 * @version 1.0
 */
OH_AVErrCode OH_VideoDecoder_Prepare(OH_AVCodec *codec);

/**
 * @brief Start the decoder, this interface must be called after the Prepare is successful.
 * After being successfully started, the decoder will start reporting NeedInputData events.
 * @syscap SystemCapability.Multimedia.Media.VideoDecoder
 * @param codec Pointer to an OH_AVCodec instance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * @since 9
 * @version 1.0
 */
OH_AVErrCode OH_VideoDecoder_Start(OH_AVCodec *codec);

/**
 * @brief Stop the decoder. After stopping, you can re-enter the Started state through Start,
 * but it should be noted that if Codec-Specific-Data has been input to the decoder before, it needs to be input again.
 * @syscap SystemCapability.Multimedia.Media.VideoDecoder
 * @param codec Pointer to an OH_AVCodec instance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * @since 9
 * @version 1.0
 */
OH_AVErrCode OH_VideoDecoder_Stop(OH_AVCodec *codec);

/**
 * @brief Clear the input and output data buffered in the decoder. After this interface is called, all the Buffer
 * indexes previously reported through the asynchronous callback will be invalidated, make sure not to access
 * the Buffers corresponding to these indexes.
 * @syscap SystemCapability.Multimedia.Media.VideoDecoder
 * @param codec Pointer to an OH_AVCodec instance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * @since 9
 * @version 1.0
 */
OH_AVErrCode OH_VideoDecoder_Flush(OH_AVCodec *codec);

/**
 * @brief Reset the decoder. To continue decoding, you need to call the Configure interface again
 * to configure the decoder instance.
 * @syscap SystemCapability.Multimedia.Media.VideoDecoder
 * @param codec Pointer to an OH_AVCodec instance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * @since 9
 * @version 1.0
 */
OH_AVErrCode OH_VideoDecoder_Reset(OH_AVCodec *codec);

/**
 * @brief Get the description information of the output data of the decoder, refer to {@link OH_AVFormat}
 * It should be noted that the life cycle of the OH_AVFormat instance pointed to by the return value * needs
 * to be manually released by the caller.
 * @syscap SystemCapability.Multimedia.Media.VideoDecoder
 * @param codec Pointer to an OH_AVCodec instance
 * @return Returns a pointer to an OH_AVFormat instance
 * @since 9
 * @version 1.0
 */
OH_AVFormat *OH_VideoDecoder_GetOutputDescription(OH_AVCodec *codec);

/**
 * @brief Set dynamic parameters to the decoder. Note: This interface can only be called after the decoder is started.
 * At the same time, incorrect parameter settings may cause decoding failure.
 * @syscap SystemCapability.Multimedia.Media.VideoDecoder
 * @param codec Pointer to an OH_AVCodec instance
 * @param format pointer to an OH_AVFormat instance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * @since 9
 * @version 1.0
 */
OH_AVErrCode OH_VideoDecoder_SetParameter(OH_AVCodec *codec, OH_AVFormat *format);

/**
 * @brief Submit the input buffer filled with data to the video decoder. The {@link OH_AVCodecOnNeedInputData} callback
 * will report the available input buffer and the corresponding index value. Once the buffer with the specified index
 * is submitted to the video decoder, the buffer cannot be accessed again until the {@link OH_AVCodecOnNeedInputData}
 * callback is received again reporting that the buffer with the same index is available. In addition, for some
 * decoders, it is required to input Codec-Specific-Data to the decoder at the beginning to initialize the decoding
 * process of the decoder, such as PPS/SPS data in H264 format.
 * @syscap SystemCapability.Multimedia.Media.VideoDecoder
 * @param codec Pointer to an OH_AVCodec instance
 * @param index Enter the index value corresponding to the Buffer
 * @param attr Information describing the data contained in the Buffer
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * @since 9
 * @version 1.0
 */
OH_AVErrCode OH_VideoDecoder_PushInputData(OH_AVCodec *codec, uint32_t index, OH_AVCodecBufferAttr attr);

/**
 * @brief Return the processed output Buffer to the decoder, and notify the decoder to finish rendering the
 * decoded data contained in the Buffer on the output Surface. If the output surface is not configured before,
 * calling this interface only returns the output buffer corresponding to the specified index to the decoder.
 * @syscap SystemCapability.Multimedia.Media.VideoDecoder
 * @param codec Pointer to an OH_AVCodec instance
 * @param index The index value corresponding to the output Buffer
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * @since 9
 * @version 1.0
 */
OH_AVErrCode OH_VideoDecoder_RenderOutputData(OH_AVCodec *codec, uint32_t index);

/**
 * @brief Return the processed output Buffer to the decoder.
 * @syscap SystemCapability.Multimedia.Media.VideoDecoder
 * @param codec Pointer to an OH_AVCodec instance
 * @param index The index value corresponding to the output Buffer
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * @since 9
 * @version 1.0
 */
OH_AVErrCode OH_VideoDecoder_FreeOutputData(OH_AVCodec *codec, uint32_t index);

/**
 * @brief Check whether the current codec instance is valid. It can be used fault recovery or app
 * switchback from the background.
 * @syscap SystemCapability.Multimedia.Media.VideoDecoder
 * @param codec Pointer to an OH_AVCodec instance
 * @param isValid Output parameter. A pointer to a boolean instance, it is true if the codec instance is valid,
 * false if the codec instance is invalid
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * @since 10
 */
OH_AVErrCode OH_VideoDecoder_IsValid(OH_AVCodec *codec, bool *isValid);

/**
 * @brief Set decryption info.
 *
 * @syscap SystemCapability.Multimedia.Media.VideoDecoder
 * @param codec Pointer to an OH_AVCodec instance
 * @param mediaKeySession A media key session instance with decryption function.
 * @param secureVideoPath Require secure decoder or not.
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * @since 11
 * @version 1.0
*/
OH_AVErrCode OH_VideoDecoder_SetDecryptionConfig(OH_AVCodec *codec, MediaKeySession *mediaKeySession,
    bool secureVideoPath);

#ifdef __cplusplus
}
#endif

#endif // NATIVE_AVCODEC_VIDEODECODER_H