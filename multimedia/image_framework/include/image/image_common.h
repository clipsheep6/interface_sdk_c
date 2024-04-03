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

/**
 * @addtogroup image
 * @{
 *
 * @brief Provides APIs for access to the image interface.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 */

/**
 * @file image_common.h
 *
 * @brief Declares the common enums and structs used by the image interface.
 *
 * @since 12
 */

#ifndef INTERFACES_KITS_NATIVE_INCLUDE_IMAGE_IMAGE_COMMON_H_
#define INTERFACES_KITS_NATIVE_INCLUDE_IMAGE_IMAGE_COMMON_H_
#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif
#define IMAGE_ERROR_BASE 62980096

/**
 * @brief Defines the image size.
 *
 * @since 12
 */
struct Image_Size {
    /** Image width, in pixels. */
    int32_t width;
    /** Image height, in pixels. */
    int32_t height;
};

/**
 * @brief Declaration the image size.
 *
 * @since 12
 */
typedef struct Image_Size Image_Size;

/**
 * @brief Defines the region of the image source to decode.
 *
 * @since 12
 */
struct Image_Region {
    /** X coordinate of the start point, in pixels. */
    uint32_t x;
    /** Y coordinate of the start point, in pixels. */
    uint32_t y;
    /** Width of the region, in pixels. */
    uint32_t width;
    /** Height of the region, in pixels. */
    uint32_t height;
};

/**
 * @brief Declaration the image region.
 *
 * @since 12
 */
typedef struct Image_Region Image_Region;

/**
 * @brief Defines the region of the image source to decode.
 *
 * @since 12
 */
struct Image_String {
    /** data for string type */
    char *format = nullptr;
    /** data lenth for string type */
    size_t size = 0;
};

/**
 * @brief Defines the property string (in key-value format) of the image source.
 *
 * @since 12
 */
typedef Image_String Image_String;

/**
 * @brief Defines the image packing options.
 *
 * @since 12
 */
typedef Image_String Image_MimeType;

/**
 * @brief Enumerates the return values that may be used by the interface.
 *
 * @since 12
 */
typedef enum {
    IMAGE_ERROR_SUCCESS = 0,                                      // Operation success
    IMAGE_ERROR_BAD_PARAMETER = -1,                               // Invalid parameter
    IMAGE_ERROR_IMAGE_ERROR_BASE = IMAGE_ERROR_BASE,            // Operation failed
    IMAGE_ERROR_ERR_IPC = IMAGE_ERROR_BASE + 1,                  // ipc error
    IMAGE_ERROR_ERR_SHAMEM_NOT_EXIST = IMAGE_ERROR_BASE + 2,     // sharememory error
    IMAGE_ERROR_ERR_SHAMEM_DATA_ABNORMAL = IMAGE_ERROR_BASE + 3, // sharememory data abnormal
    IMAGE_ERROR_DECODE_ABNORMAL = IMAGE_ERROR_BASE + 4,          // image decode error
    IMAGE_ERROR_DATA_ABNORMAL = IMAGE_ERROR_BASE + 5,            // image input data error
    IMAGE_ERROR_MALLOC_ABNORMAL = IMAGE_ERROR_BASE + 6,          // image malloc error
    IMAGE_ERROR_DATA_UNSUPPORT = IMAGE_ERROR_BASE + 7,           // image type unsupported
    IMAGE_ERROR_INIT_ABNORMAL = IMAGE_ERROR_BASE + 8,            // image init error
    IMAGE_ERROR_GET_DATA_ABNORMAL = IMAGE_ERROR_BASE + 9,        // image get data error
    IMAGE_ERROR_TOO_LARGE = IMAGE_ERROR_BASE + 10,               // image data too large
    IMAGE_ERROR_TRANSFORM = IMAGE_ERROR_BASE + 11,               // image transform error
    IMAGE_ERROR_COLOR_CONVERT = IMAGE_ERROR_BASE + 12,           // image color convert error
    IMAGE_ERROR_CROP = IMAGE_ERROR_BASE + 13,                    // crop error
    IMAGE_ERROR_SOURCE_DATA = IMAGE_ERROR_BASE + 14,             // image source data error
    IMAGE_ERROR_SOURCE_DATA_INCOMPLETE = IMAGE_ERROR_BASE + 15,  // image source data incomplete
    IMAGE_ERROR_MISMATCHED_FORMAT = IMAGE_ERROR_BASE + 16,       // image mismatched format
    IMAGE_ERROR_UNKNOWN_FORMAT = IMAGE_ERROR_BASE + 17,          // image unknown format
    IMAGE_ERROR_SOURCE_UNRESOLVED = IMAGE_ERROR_BASE + 18,       // image source unresolved
    IMAGE_ERROR_INVALID_PARAMETER = IMAGE_ERROR_BASE + 19,       // image invalid parameter
    IMAGE_ERROR_DECODE_FAILED = IMAGE_ERROR_BASE + 20,           // decode fail
    IMAGE_ERROR_PLUGIN_REGISTER_FAILED = IMAGE_ERROR_BASE + 21,  // register plugin fail
    IMAGE_ERROR_PLUGIN_CREATE_FAILED = IMAGE_ERROR_BASE + 22,    // create plugin fail
    IMAGE_ERROR_ENCODE_FAILED = IMAGE_ERROR_BASE + 23,           // image encode fail
    IMAGE_ERROR_ADD_PIXEL_MAP_FAILED = IMAGE_ERROR_BASE + 24,    // image add pixel map fail
    IMAGE_ERROR_HW_DECODE_UNSUPPORT = IMAGE_ERROR_BASE + 25,     // image hardware decode unsupported
    IMAGE_ERROR_DECODE_HEAD_ABNORMAL = IMAGE_ERROR_BASE + 26,    // image decode head error
    IMAGE_ERROR_DECODE_EXIF_UNSUPPORT = IMAGE_ERROR_BASE + 27,   // image decode exif unsupport
    IMAGE_ERROR_PROPERTY_NOT_EXIST = IMAGE_ERROR_BASE + 28,      // image property not exist

    IMAGE_ERROR_MEDIA_DATA_UNSUPPORT = IMAGE_ERROR_BASE + 30,               // media type unsupported
    IMAGE_ERROR_MEDIA_TOO_LARGE = IMAGE_ERROR_BASE + 31,                    // media data too large
    IMAGE_ERROR_MEDIA_MALLOC_FAILED = IMAGE_ERROR_BASE + 32,                // media malloc memory failed
    IMAGE_ERROR_MEDIA_END_OF_STREAM = IMAGE_ERROR_BASE + 33,                // media end of stream error
    IMAGE_ERROR_MEDIA_IO_ABNORMAL = IMAGE_ERROR_BASE + 34,                  // media io error
    IMAGE_ERROR_MEDIA_MALFORMED = IMAGE_ERROR_BASE + 35,                    // media malformed error
    IMAGE_ERROR_MEDIA_BUFFER_TOO_SMALL = IMAGE_ERROR_BASE + 36,             // media buffer too small error
    IMAGE_ERROR_MEDIA_OUT_OF_RANGE = IMAGE_ERROR_BASE + 37,                 // media out of range error
    IMAGE_ERROR_MEDIA_STATUS_ABNORMAL = IMAGE_ERROR_BASE + 38,              // media status abnormal error
    IMAGE_ERROR_MEDIA_VALUE_INVALID = IMAGE_ERROR_BASE + 39,                // media value invalid
    IMAGE_ERROR_MEDIA_NULL_POINTER = IMAGE_ERROR_BASE + 40,                 // media error operation
    IMAGE_ERROR_MEDIA_INVALID_OPERATION = IMAGE_ERROR_BASE + 41,            // media invalid operation
    IMAGE_ERROR_MEDIA_ERR_PLAYER_NOT_INIT = IMAGE_ERROR_BASE + 42,          // media init error
    IMAGE_ERROR_MEDIA_EARLY_PREPARE = IMAGE_ERROR_BASE + 43,                // media early prepare
    IMAGE_ERROR_MEDIA_SEEK_ERR = IMAGE_ERROR_BASE + 44,                     // media rewind error
    IMAGE_ERROR_MEDIA_PERMISSION_DENIED = IMAGE_ERROR_BASE + 45,            // media permission denied
    IMAGE_ERROR_MEDIA_DEAD_OBJECT = IMAGE_ERROR_BASE + 46,                  // media dead object
    IMAGE_ERROR_MEDIA_TIMED_OUT = IMAGE_ERROR_BASE + 47,                    // media time out
    IMAGE_ERROR_MEDIA_TRACK_NOT_ALL_SUPPORTED = IMAGE_ERROR_BASE + 48,      // media track subset support
    IMAGE_ERROR_MEDIA_ADAPTER_INIT_FAILED = IMAGE_ERROR_BASE + 49,          // media recorder adapter init failed
    IMAGE_ERROR_MEDIA_WRITE_PARCEL_FAIL = IMAGE_ERROR_BASE + 50,            // write parcel failed
    IMAGE_ERROR_MEDIA_READ_PARCEL_FAIL = IMAGE_ERROR_BASE + 51,             // read parcel failed
    IMAGE_ERROR_MEDIA_NO_AVAIL_BUFFER = IMAGE_ERROR_BASE + 52,              // read parcel failed
    IMAGE_ERROR_MEDIA_INVALID_PARAM = IMAGE_ERROR_BASE + 53,                // media function found invalid param
    IMAGE_ERROR_MEDIA_CODEC_ADAPTER_NOT_EXIST = IMAGE_ERROR_BASE + 54,      // media zcodec adapter not init
    IMAGE_ERROR_MEDIA_CREATE_CODEC_ADAPTER_FAILED = IMAGE_ERROR_BASE + 55,  // media create zcodec adapter failed
    IMAGE_ERROR_MEDIA_CODEC_ADAPTER_NOT_INIT = IMAGE_ERROR_BASE + 56,       // media adapter inner not init
    IMAGE_ERROR_MEDIA_ZCODEC_CREATE_FAILED = IMAGE_ERROR_BASE + 57,         // media adapter inner not init
    IMAGE_ERROR_MEDIA_ZCODEC_NOT_EXIST = IMAGE_ERROR_BASE + 58,             // media zcodec not exist
    IMAGE_ERROR_MEDIA_JNI_CLASS_NOT_EXIST = IMAGE_ERROR_BASE + 59,          // media jni class not found
    IMAGE_ERROR_MEDIA_JNI_METHOD_NOT_EXIST = IMAGE_ERROR_BASE + 60,         // media jni method not found
    IMAGE_ERROR_MEDIA_JNI_NEW_OBJ_FAILED = IMAGE_ERROR_BASE + 61,           // media jni obj new failed
    IMAGE_ERROR_MEDIA_JNI_COMMON_ERROR = IMAGE_ERROR_BASE + 62,             // media jni normal error
    IMAGE_ERROR_MEDIA_DISTRIBUTE_NOT_SUPPORT = IMAGE_ERROR_BASE + 63,       // media distribute not support
    IMAGE_ERROR_MEDIA_SOURCE_NOT_SET = IMAGE_ERROR_BASE + 64,               // media source not set
    IMAGE_ERROR_MEDIA_RTSP_ADAPTER_NOT_INIT = IMAGE_ERROR_BASE + 65,        // media rtsp adapter not init
    IMAGE_ERROR_MEDIA_RTSP_ADAPTER_NOT_EXIST = IMAGE_ERROR_BASE + 66,       // media rtsp adapter not exist
    IMAGE_ERROR_MEDIA_RTSP_SURFACE_UNSUPPORT = IMAGE_ERROR_BASE + 67,       // media rtsp surface not support
    IMAGE_ERROR_MEDIA_RTSP_CAPTURE_NOT_INIT = IMAGE_ERROR_BASE + 68,        // media rtsp capture init error
    IMAGE_ERROR_MEDIA_RTSP_SOURCE_URL_INVALID = IMAGE_ERROR_BASE + 69,      // media rtsp source url invalid
    IMAGE_ERROR_MEDIA_RTSP_VIDEO_TRACK_NOT_FOUND = IMAGE_ERROR_BASE + 70,   // media rtsp can't find video track
    IMAGE_ERROR_MEDIA_RTSP_CAMERA_NUM_REACH_MAX = IMAGE_ERROR_BASE + 71,    // rtsp camera num reach to max num
    IMAGE_ERROR_MEDIA_SET_VOLUME = IMAGE_ERROR_BASE + 72,                   // media set volume error
    IMAGE_ERROR_MEDIA_NUMBER_OVERFLOW = IMAGE_ERROR_BASE + 73,              // media number operation overflow
    IMAGE_ERROR_MEDIA_DIS_PLAYER_UNSUPPORTED = IMAGE_ERROR_BASE + 74,       // media distribute player unsupporteded
    IMAGE_ERROR_MEDIA_DENCODE_ICC_FAILED = IMAGE_ERROR_BASE + 75,           // image dencode ICC fail
    IMAGE_ERROR_MEDIA_ENCODE_ICC_FAILED = IMAGE_ERROR_BASE + 76,            // image encode ICC fail

    IMAGE_ERROR_MEDIA_READ_PIXELMAP_FAILED = IMAGE_ERROR_BASE + 150,        // read pixelmap failed
    IMAGE_ERROR_MEDIA_WRITE_PIXELMAP_FAILED = IMAGE_ERROR_BASE + 151,       // write pixelmap failed
    IMAGE_ERROR_MEDIA_PIXELMAP_NOT_ALLOW_MODIFY = IMAGE_ERROR_BASE + 152,   // pixelmap not allow modify
    IMAGE_ERROR_MEDIA_CONFIG_FAILED = IMAGE_ERROR_BASE + 153,               // config error
    IMAGE_ERROR_JNI_ENV_ABNORMAL = IMAGE_ERROR_BASE + 154,                  // Abnormal JNI environment
    IMAGE_ERROR_SURFACE_GRALLOC_BUFFER_FAILED = IMAGE_ERROR_BASE + 155,     // surface gralloc buffer failed
    IMAGE_ERROR_CREATE_SURFACE_FAILED = IMAGE_ERROR_BASE + 156,             // create surface failed
    IMAGE_ERROR_SURFACE_GET_PARAMETER_FAILED = IMAGE_ERROR_BASE + 157,      // Failed to obtain parameters for surface
    IMAGE_ERROR_GET_SURFACE_FAILED = IMAGE_ERROR_BASE + 158,                // get sufrace failed
    IMAGE_ERROR_SURFACE_ACQUIRE_BUFFER_FAILED = IMAGE_ERROR_BASE + 159,     // Acquire Buffer failed
    IMAGE_ERROR_SURFACE_REQUEST_BUFFER_FAILED = IMAGE_ERROR_BASE + 160,     // request Buffer failed
    IMAGE_ERROR_REGISTER_LISTENER_FAILED = IMAGE_ERROR_BASE + 161,          // Failed to register listener
    IMAGE_ERROR_REGISTER_BUFFER_FAILED = IMAGE_ERROR_BASE + 162,            // Failed to register buffer
    IMAGE_ERROR_FREAD_FAILED = IMAGE_ERROR_BASE + 163,                      // read file failed
    IMAGE_ERROR_PEEK_FAILED = IMAGE_ERROR_BASE + 164,                       // peek file failed
    IMAGE_ERROR_SEEK_FAILED = IMAGE_ERROR_BASE + 165,                       // seek file failed
    IMAGE_ERROR_STREAM_SIZE_ERROR = IMAGE_ERROR_BASE + 166,                 // stream bad
    IMAGE_ERROR_FILE_FD_ERROR = IMAGE_ERROR_BASE + 167,                     // file fd is bad
    IMAGE_ERROR_FILE_DAMAGED = IMAGE_ERROR_BASE + 168,                      // file damaged
    IMAGE_ERROR_CREATE_DECODER_FAILED = IMAGE_ERROR_BASE + 169,             // create decoder failed
    IMAGE_ERROR_CREATE_ENCODER_FAILED = IMAGE_ERROR_BASE + 170,             // create encoder failed
    IMAGE_ERROR_CHECK_FORMAT_ERROR = IMAGE_ERROR_BASE + 171,                // check format failed
    IMAGE_ERROR_THIRDPART_SKIA_ERROR = IMAGE_ERROR_BASE + 172,              // skia error
    IMAGE_ERROR_HW_DECODE_FAILED = IMAGE_ERROR_BASE + 173,                  // hard decode failed
    IMAGE_ERROR_ALLOCATER_TYPE_ERROR = IMAGE_ERROR_BASE + 174,              // hard decode failed
    IMAGE_ERROR_ALPHA_TYPE_ERROR = IMAGE_ERROR_BASE + 175,                  // hard decode failed
    IMAGE_ERROR_INDEX_INVALID = IMAGE_ERROR_BASE + 176,                     // invalid index

    IMAGE_ERROR_MEDIA_UNKNOWN = IMAGE_ERROR_BASE + 200,                     // media unknown error
} Image_ErrorCode;

/**
 * @brief Defines the mbp mime type.
 *
 * @since 12
 */
static const char* MIME_TYPE_BMP = "image/bmp";

/**
 * @brief Defines the jpeg mime type.
 *
 * @since 12
 */
static const char* MIME_TYPE_JPEG = "image/jpeg";

/**
 * @brief Defines the heic mime type.
 *
 * @since 12
 */
static const char* MIME_TYPE_HEIC = "image/heic";

/**
 * @brief Defines the png mime type.
 *
 * @since 12
 */
static const char* MIME_TYPE_PNG = "image/png";

/**
 * @brief Defines the webp mime type.
 *
 * @since 12
 */
static const char* MIME_TYPE_WEBP = "image/webp";

/**
 * @brief Defines the gif mime type.
 *
 * @since 12
 */
static const char* MIME_TYPE_GIF = "image/gif";

/**
 * @brief Defines the x-icon mime type.
 *
 * @since 12
 */
static const char* MIME_TYPE_ICON = "image/x-icon";

#ifdef __cplusplus
};
#endif
/** @} */

#endif // INTERFACES_KITS_NATIVE_INCLUDE_IMAGE_IMAGE_COMMON_H_