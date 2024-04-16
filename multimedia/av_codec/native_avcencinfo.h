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

#ifndef NATIVE_AVCENCINFO_H
#define NATIVE_AVCENCINFO_H

#include <stdint.h>
#include "native_averrors.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OH_AVBuffer OH_AVBuffer;
typedef struct OH_AVCencInfo OH_AVCencInfo;
/**
 * @brief Key id size.
 * @since 12
 * @version 1.0
 */
#define DRM_KEY_ID_SIZE 16
/**
 * @brief Iv size.
 * @since 12
 * @version 1.0
 */
#define DRM_KEY_IV_SIZE 16
/**
 * @brief Max subsample num.
 * @since 12
 * @version 1.0
 */
#define DRM_KEY_MAX_SUB_SAMPLE_NUM 64

/**
 * @brief Drm cenc algorithm type.
 * @since 12
 * @version 1.0
 */
typedef enum DrmCencAlgorithm {
    /**
     * Uncrypted.
     */
    DRM_ALG_CENC_UNENCRYPTED = 0x0,
    /**
     * Aes ctr.
     */
    DRM_ALG_CENC_AES_CTR = 0x1,
    /**
     * Aes wv.
     */
    DRM_ALG_CENC_AES_WV = 0x2,
    /**
     * Aes cbc.
     */
    DRM_ALG_CENC_AES_CBC = 0x3,
    /**
     * Sm4 cbc.
     */
    DRM_ALG_CENC_SM4_CBC = 0x4,
    /**
     * Sm4 ctr.
     */
    DRM_ALG_CENC_SM4_CTR = 0x5
} DrmCencAlgorithm;

/**
 * @brief Mode of cend info like set or not.
 * @since 12
 * @version 1.0
 */
typedef enum DrmCencInfoMode {
    /* key/iv/subsample set. */
    DRM_CENC_INFO_KEY_IV_SUBSAMPLES_SET = 0x0,
    /* key/iv/subsample not set. */
    DRM_CENC_INFO_KEY_IV_SUBSAMPLES_NOT_SET = 0x1
} DrmCencInfoMode;

/**
 * @brief Subsample info of media.
 * @since 12
 * @version 1.0
 */
typedef struct DrmSubSample {
    /* Clear header len. */
    uint32_t clearHeaderLen;
    /* Payload Len. */
    uint32_t payLoadLen;
} DrmSubSample;

/**
 * @brief Creates an OH_AVCencInfo instance for setting cencinfo.
 * Free the resources of the instance by calling OH_AVCencInfo_Destory.
 * @syscap SystemCapability.Multimedia.Media.Spliter
 * @return Returns a pointer to an OH_AVCencInfo instance
 * @since 12
 * @version 1.0
 */
OH_AVCencInfo *OH_AVCencInfo_Create();

/**
 * @brief Destroy the OH_AVCencInfo instance and free the internal resources.
 * The same instance can only be destroyed once. The destroyed instance
 * should not be used before it is created again. It is recommended setting
 * the instance pointer to NULL right after the instance is destroyed successfully.
 * @syscap SystemCapability.Multimedia.Media.Spliter
 * @param cencInfo Pointer to an OH_AVCencInfo instance.
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * @since 12
 * @version 1.0
*/
OH_AVErrCode OH_AVCencInfo_Destroy(OH_AVCencInfo *cencInfo);

/**
 * @brief Method to set algo of cencinfo.
 * @syscap SystemCapability.Multimedia.Media.Spliter
 * @param cencInfo Pointer to an OH_AVCencInfo instance.
 * @param algo Cenc algo.
 * @return Returns {@link AV_ERR_OK} if the algo is set; returns an error code defined
 * in {@link native_averrors.h} otherwise.
 * @since 12
 * @version 1.0
 */
OH_AVErrCode OH_AVCencInfo_SetAlgo(OH_AVCencInfo *cencInfo, enum DrmCencAlgorithm algo);

/**
 * @brief Method to set key id and iv of cencinfo.
 * @syscap SystemCapability.Multimedia.Media.Spliter
 * @param cencInfo Pointer to an OH_AVCencInfo instance.
 * @param keyId Key id.
 * @param keyIdLen Key id len.
 * @param iv Iv.
 * @param ivLen Iv len.
 * @return Returns {@link AV_ERR_OK} if the key id and iv is set; returns an error code defined
 * in {@link native_averrors.h} otherwise.
 * @since 12
 * @version 1.0
 */
OH_AVErrCode OH_AVCencInfo_SetKeyIdAndIv(OH_AVCencInfo *cencInfo, uint8_t *keyId,
    uint32_t keyIdLen, uint8_t *iv, uint32_t ivLen);

/**
 * @brief Method to set subsample info of cencinfo.
 * @syscap SystemCapability.Multimedia.Media.Spliter
 * @param cencInfo Pointer to an OH_AVCencInfo instance.
 * @param encryptBlocks Number of encrypted blocks.
 * @param skipBlocks Number of skip(clear) blocks.
 * @param firstEncryptOffset Offset of first encrypted payload.
 * @param subsampleNum Subsample num.
 * @param subSamples Subsample info
 * @return Returns {@link AV_ERR_OK} if the subsample info is set; returns an error code defined
 * in {@link native_averrors.h} otherwise.
 * @since 12
 * @version 1.0
 */
OH_AVErrCode OH_AVCencInfo_SetSubsampleInfo(OH_AVCencInfo *cencInfo, uint32_t encryptBlocks,
    uint32_t skipBlocks, uint32_t firstEncryptOffset, uint32_t subsampleNum, DrmSubSample *subSamples);

/**
 * @brief Method to set mode of cencinfo.
 * @syscap SystemCapability.Multimedia.Media.Spliter
 * @param cencInfo Pointer to an OH_AVCencInfo instance.
 * @param mode Cenc mode, indicate whether key/iv/subsample set or not.
 * @return Returns {@link AV_ERR_OK} if the mode is set; returns an error code defined
 * in {@link native_averrors.h} otherwise.
 * @since 12
 * @version 1.0
 */
OH_AVErrCode OH_AVCencInfo_SetMode(OH_AVCencInfo *cencInfo, enum DrmCencInfoMode mode);

/**
 * @brief Method to attach cencinfo to AVBuffer.
 * @syscap SystemCapability.Multimedia.Media.Spliter
 * @param cencInfo Pointer to an OH_AVCencInfo instance.
 * @param buffer AVBuffer to attach cencinfo.
 * @return Returns {@link AV_ERR_OK} if the cencinfo is set; returns an error code defined
 * in {@link native_averrors.h} otherwise.
 * @since 12
 * @version 1.0
 */
OH_AVErrCode OH_AVCencInfo_SetAVBuffer(OH_AVCencInfo *cencInfo, OH_AVBuffer *buffer);

#ifdef __cplusplus
}
#endif

#endif // NATIVE_AVCENCINFO_H
