/*
 * Copyright (C) 2023 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
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
 * @syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 2.0
 */

/**
 * @file image_common.h
 *
 * @brief Declares the common enums and structs used by the image interface.
 *
 * @since 10
 * @version 2.0
 */

#ifndef INTERFACES_KITS_NATIVE_INCLUDE_IMAGE_IMAGE_COMMON_H_
#define INTERFACES_KITS_NATIVE_INCLUDE_IMAGE_IMAGE_COMMON_H_
#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif
#define IMAGE_RESULT_BASE 62980096

/**
 * @brief Defines the image size.
 *
 * @since 10
 * @version 2.0
 */
struct Image_Size {
    /* * Image width, in pixels. */
    int32_t width;
    /* * Image height, in pixels. */
    int32_t height;
};

/**
 * @brief Declaration the image size.
 *
 * @since 10
 * @version 2.0
 */
typedef struct Image_Size Image_Size;

/**
 * @brief Defines the region of the image source to decode.
 *
 * @since 10
 * @version 2.0
 */
struct Image_Region {
    /* * X coordinate of the start point, in pixels. */
    uint32_t x;
    /* * Y coordinate of the start point, in pixels. */
    uint32_t y;
    /* * Width of the region, in pixels. */
    uint32_t width;
    /* * Height of the region, in pixels. */
    uint32_t height;
};

/**
 * @brief Declaration the image region.
 *
 * @since 10
 * @version 2.0
 */
typedef struct Image_Region Image_Region;

/**
 * @brief Defines the region of the image source to decode.
 *
 * @since 10
 * @version 2.0
 */
struct Image_String {
    /* * data for string type */
    char *format = nullptr;
    /* * data lenth for string type */
    size_t size = 0;
};

/**
 * @brief Defines the property string (in key-value format) of the image source.
 *
 * @since 10
 * @version 2.0
 */
typedef Image_String Image_String;

/**
 * @brief Defines the image packing options.
 *
 * @since 10
 * @version 2.0
 */
typedef Image_String Image_MimeType;

/**
 * @brief Enumerates the return values that may be used by the interface.
 *
 * @since 10
 * @version 2.0
 */
typedef enum {
    IMAGE_RESULT_SUCCESS = 0,                                      // Operation success
    IMAGE_RESULT_BAD_PARAMETER = -1,                               // Invalid parameter
    IMAGE_RESULT_IMAGE_RESULT_BASE = IMAGE_RESULT_BASE,            // Operation failed
    IMAGE_RESULT_ERR_IPC = IMAGE_RESULT_BASE + 1,                  // ipc error
    IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST = IMAGE_RESULT_BASE + 2,     // sharememory error
    IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL = IMAGE_RESULT_BASE + 3, // sharememory data abnormal
    IMAGE_RESULT_DECODE_ABNORMAL = IMAGE_RESULT_BASE + 4,          // image decode error
    IMAGE_RESULT_DATA_ABNORMAL = IMAGE_RESULT_BASE + 5,            // image input data error
    IMAGE_RESULT_MALLOC_ABNORMAL = IMAGE_RESULT_BASE + 6,          // image malloc error
    IMAGE_RESULT_DATA_UNSUPPORT = IMAGE_RESULT_BASE + 7,           // image type unsupported
    IMAGE_RESULT_INIT_ABNORMAL = IMAGE_RESULT_BASE + 8,            // image init error
    IMAGE_RESULT_GET_DATA_ABNORMAL = IMAGE_RESULT_BASE + 9,        // image get data error
    IMAGE_RESULT_TOO_LARGE = IMAGE_RESULT_BASE + 10,               // image data too large
    IMAGE_RESULT_TRANSFORM = IMAGE_RESULT_BASE + 11,               // image transform error
    IMAGE_RESULT_COLOR_CONVERT = IMAGE_RESULT_BASE + 12,           // image color convert error
    IMAGE_RESULT_CROP = IMAGE_RESULT_BASE + 13,                    // crop error
    IMAGE_RESULT_SOURCE_DATA = IMAGE_RESULT_BASE + 14,             // image source data error
    IMAGE_RESULT_SOURCE_DATA_INCOMPLETE = IMAGE_RESULT_BASE + 15,  // image source data incomplete
    IMAGE_RESULT_MISMATCHED_FORMAT = IMAGE_RESULT_BASE + 16,       // image mismatched format
    IMAGE_RESULT_UNKNOWN_FORMAT = IMAGE_RESULT_BASE + 17,          // image unknown format
    IMAGE_RESULT_SOURCE_UNRESOLVED = IMAGE_RESULT_BASE + 18,       // image source unresolved
    IMAGE_RESULT_INVALID_PARAMETER = IMAGE_RESULT_BASE + 19,       // image invalid parameter
    IMAGE_RESULT_DECODE_FAILED = IMAGE_RESULT_BASE + 20,           // decode fail
    IMAGE_RESULT_PLUGIN_REGISTER_FAILED = IMAGE_RESULT_BASE + 21,  // register plugin fail
    IMAGE_RESULT_PLUGIN_CREATE_FAILED = IMAGE_RESULT_BASE + 22,    // create plugin fail
    IMAGE_RESULT_ENCODE_FAILED = IMAGE_RESULT_BASE + 23,           // image encode fail
    IMAGE_RESULT_ADD_PIXEL_MAP_FAILED = IMAGE_RESULT_BASE + 24,    // image add pixel map fail
    IMAGE_RESULT_HW_DECODE_UNSUPPORT = IMAGE_RESULT_BASE + 25,     // image hardware decode unsupported
    IMAGE_RESULT_DECODE_HEAD_ABNORMAL = IMAGE_RESULT_BASE + 26,    // image decode head error
    IMAGE_RESULT_DECODE_EXIF_UNSUPPORT = IMAGE_RESULT_BASE + 27,   // image decode exif unsupport
    IMAGE_RESULT_PROPERTY_NOT_EXIST = IMAGE_RESULT_BASE + 28,      // image property not exist

    IMAGE_RESULT_MEDIA_DATA_UNSUPPORT = IMAGE_RESULT_BASE + 30,              // media type unsupported
    IMAGE_RESULT_MEDIA_TOO_LARGE = IMAGE_RESULT_BASE + 31,                   // media data too large
    IMAGE_RESULT_MEDIA_MALLOC_FAILED = IMAGE_RESULT_BASE + 32,               // media malloc memory failed
    IMAGE_RESULT_MEDIA_END_OF_STREAM = IMAGE_RESULT_BASE + 33,               // media end of stream error
    IMAGE_RESULT_MEDIA_IO_ABNORMAL = IMAGE_RESULT_BASE + 34,                 // media io error
    IMAGE_RESULT_MEDIA_MALFORMED = IMAGE_RESULT_BASE + 35,                   // media malformed error
    IMAGE_RESULT_MEDIA_BUFFER_TOO_SMALL = IMAGE_RESULT_BASE + 36,            // media buffer too small error
    IMAGE_RESULT_MEDIA_OUT_OF_RANGE = IMAGE_RESULT_BASE + 37,                // media out of range error
    IMAGE_RESULT_MEDIA_STATUS_ABNORMAL = IMAGE_RESULT_BASE + 38,             // media status abnormal error
    IMAGE_RESULT_MEDIA_VALUE_INVALID = IMAGE_RESULT_BASE + 39,               // media value invalid
    IMAGE_RESULT_MEDIA_NULL_POINTER = IMAGE_RESULT_BASE + 40,                // media error operation
    IMAGE_RESULT_MEDIA_INVALID_OPERATION = IMAGE_RESULT_BASE + 41,           // media invalid operation
    IMAGE_RESULT_MEDIA_ERR_PLAYER_NOT_INIT = IMAGE_RESULT_BASE + 42,         // media init error
    IMAGE_RESULT_MEDIA_EARLY_PREPARE = IMAGE_RESULT_BASE + 43,               // media early prepare
    IMAGE_RESULT_MEDIA_SEEK_ERR = IMAGE_RESULT_BASE + 44,                    // media rewind error
    IMAGE_RESULT_MEDIA_PERMISSION_DENIED = IMAGE_RESULT_BASE + 45,           // media permission denied
    IMAGE_RESULT_MEDIA_DEAD_OBJECT = IMAGE_RESULT_BASE + 46,                 // media dead object
    IMAGE_RESULT_MEDIA_TIMED_OUT = IMAGE_RESULT_BASE + 47,                   // media time out
    IMAGE_RESULT_MEDIA_TRACK_NOT_ALL_SUPPORTED = IMAGE_RESULT_BASE + 48,     // media track subset support
    IMAGE_RESULT_MEDIA_ADAPTER_INIT_FAILED = IMAGE_RESULT_BASE + 49,         // media recorder adapter init failed
    IMAGE_RESULT_MEDIA_WRITE_PARCEL_FAIL = IMAGE_RESULT_BASE + 50,           // write parcel failed
    IMAGE_RESULT_MEDIA_READ_PARCEL_FAIL = IMAGE_RESULT_BASE + 51,            // read parcel failed
    IMAGE_RESULT_MEDIA_NO_AVAIL_BUFFER = IMAGE_RESULT_BASE + 52,             // read parcel failed
    IMAGE_RESULT_MEDIA_INVALID_PARAM = IMAGE_RESULT_BASE + 53,               // media function found invalid param
    IMAGE_RESULT_MEDIA_CODEC_ADAPTER_NOT_EXIST = IMAGE_RESULT_BASE + 54,     // media zcodec adapter not init
    IMAGE_RESULT_MEDIA_CREATE_CODEC_ADAPTER_FAILED = IMAGE_RESULT_BASE + 55, // media create zcodec adapter failed
    IMAGE_RESULT_MEDIA_CODEC_ADAPTER_NOT_INIT = IMAGE_RESULT_BASE + 56,      // media adapter inner not init
    IMAGE_RESULT_MEDIA_ZCODEC_CREATE_FAILED = IMAGE_RESULT_BASE + 57,        // media adapter inner not init
    IMAGE_RESULT_MEDIA_ZCODEC_NOT_EXIST = IMAGE_RESULT_BASE + 58,            // media zcodec not exist
    IMAGE_RESULT_MEDIA_JNI_CLASS_NOT_EXIST = IMAGE_RESULT_BASE + 59,         // media jni class not found
    IMAGE_RESULT_MEDIA_JNI_METHOD_NOT_EXIST = IMAGE_RESULT_BASE + 60,        // media jni method not found
    IMAGE_RESULT_MEDIA_JNI_NEW_OBJ_FAILED = IMAGE_RESULT_BASE + 61,          // media jni obj new failed
    IMAGE_RESULT_MEDIA_JNI_COMMON_ERROR = IMAGE_RESULT_BASE + 62,            // media jni normal error
    IMAGE_RESULT_MEDIA_DISTRIBUTE_NOT_SUPPORT = IMAGE_RESULT_BASE + 63,      // media distribute not support
    IMAGE_RESULT_MEDIA_SOURCE_NOT_SET = IMAGE_RESULT_BASE + 64,              // media source not set
    IMAGE_RESULT_MEDIA_RTSP_ADAPTER_NOT_INIT = IMAGE_RESULT_BASE + 65,       // media rtsp adapter not init
    IMAGE_RESULT_MEDIA_RTSP_ADAPTER_NOT_EXIST = IMAGE_RESULT_BASE + 66,      // media rtsp adapter not exist
    IMAGE_RESULT_MEDIA_RTSP_SURFACE_UNSUPPORTED = IMAGE_RESULT_BASE + 67,    // media rtsp surface unsupported
    IMAGE_RESULT_MEDIA_RTSP_CAPTURE_NOT_INIT = IMAGE_RESULT_BASE + 68,       // media rtsp capture init error
    IMAGE_RESULT_MEDIA_RTSP_SOURCE_URL_INVALID = IMAGE_RESULT_BASE + 69,     // media rtsp source url invalid
    IMAGE_RESULT_MEDIA_RTSP_VIDEO_TRACK_NOT_FOUND = IMAGE_RESULT_BASE + 70,  // media rtsp can't find video track
    IMAGE_RESULT_MEDIA_RTSP_CAMERA_NUM_REACH_MAX = IMAGE_RESULT_BASE + 71,   // rtsp camera num reach to max num
    IMAGE_RESULT_MEDIA_SET_VOLUME = IMAGE_RESULT_BASE + 72,                  // media set volume error
    IMAGE_RESULT_MEDIA_NUMBER_OVERFLOW = IMAGE_RESULT_BASE + 73,             // media number operation overflow
    IMAGE_RESULT_MEDIA_DIS_PLAYER_UNSUPPORTED = IMAGE_RESULT_BASE + 74,      // media distribute player unsupporteded
    IMAGE_RESULT_MEDIA_DENCODE_ICC_FAILED = IMAGE_RESULT_BASE + 75,          // image dencode ICC fail
    IMAGE_RESULT_MEDIA_ENCODE_ICC_FAILED = IMAGE_RESULT_BASE + 76,           // image encode ICC fail

    IMAGE_RESULT_MEDIA_READ_PIXELMAP_FAILED = IMAGE_RESULT_BASE + 150,      // read pixelmap failed
    IMAGE_RESULT_MEDIA_WRITE_PIXELMAP_FAILED = IMAGE_RESULT_BASE + 151,     // write pixelmap failed
    IMAGE_RESULT_MEDIA_PIXELMAP_NOT_ALLOW_MODIFY = IMAGE_RESULT_BASE + 152, // pixelmap not allow modify
    IMAGE_RESULT_MEDIA_CONFIG_FAILED = IMAGE_RESULT_BASE + 153,             // config error
    IMAGE_RESULT_JNI_ENV_ABNORMAL = IMAGE_RESULT_BASE + 154,                // Abnormal JNI environment
    IMAGE_RESULT_SURFACE_GRALLOC_BUFFER_FAILED = IMAGE_RESULT_BASE + 155,   // surface gralloc buffer failed
    IMAGE_RESULT_CREATE_SURFACE_FAILED = IMAGE_RESULT_BASE + 156,           // create surface failed
    IMAGE_RESULT_SURFACE_GET_PARAMETER_FAILED = IMAGE_RESULT_BASE + 157,    // Failed to obtain parameters for surface
    IMAGE_RESULT_GET_SURFACE_FAILED = IMAGE_RESULT_BASE + 158,              // get sufrace failed
    IMAGE_RESULT_SURFACE_ACQUIRE_BUFFER_FAILED = IMAGE_RESULT_BASE + 159,   // Acquire Buffer failed
    IMAGE_RESULT_SURFACE_REQUEST_BUFFER_FAILED = IMAGE_RESULT_BASE + 160,   // request Buffer failed
    IMAGE_RESULT_REGISTER_LISTENER_FAILED = IMAGE_RESULT_BASE + 161,        // Failed to register listener
    IMAGE_RESULT_REGISTER_BUFFER_FAILED = IMAGE_RESULT_BASE + 162,          // Failed to register buffer
    IMAGE_RESULT_FREAD_FAILED = IMAGE_RESULT_BASE + 163,                    // read file failed
    IMAGE_RESULT_PEEK_FAILED = IMAGE_RESULT_BASE + 164,                     // peek file failed
    IMAGE_RESULT_SEEK_FAILED = IMAGE_RESULT_BASE + 165,                     // seek file failed
    IMAGE_RESULT_STREAM_SIZE_ERROR = IMAGE_RESULT_BASE + 166,               // stream bad
    IMAGE_RESULT_FILE_FD_ERROR = IMAGE_RESULT_BASE + 167,                   // file fd is bad
    IMAGE_RESULT_FILE_DAMAGED = IMAGE_RESULT_BASE + 168,                    // file damaged
    IMAGE_RESULT_CREATE_DECODER_FAILED = IMAGE_RESULT_BASE + 169,           // create decoder failed
    IMAGE_RESULT_CREATE_ENCODER_FAILED = IMAGE_RESULT_BASE + 170,           // create encoder failed
    IMAGE_RESULT_CHECK_FORMAT_ERROR = IMAGE_RESULT_BASE + 171,              // check format failed
    IMAGE_RESULT_THIRDPART_SKIA_ERROR = IMAGE_RESULT_BASE + 172,            // skia error
    IMAGE_RESULT_HW_DECODE_FAILED = IMAGE_RESULT_BASE + 173,                // hard decode failed
    IMAGE_RESULT_ALLOCATER_TYPE_ERROR = IMAGE_RESULT_BASE + 174,            // hard decode failed
    IMAGE_RESULT_ALPHA_TYPE_ERROR = IMAGE_RESULT_BASE + 175,                // hard decode failed
    IMAGE_RESULT_INDEX_INVALID = IMAGE_RESULT_BASE + 176,                   // invalid index

    IMAGE_RESULT_MEDIA_UNKNOWN = IMAGE_RESULT_BASE + 200, // media unknown error
} Image_ErrorCode;

/**
 * @brief Defines the mbp mime type.
 *
 * @since 10
 * @version 2.0
 */
static const char *MIME_TYPE_BMP = "image/bmp";

/**
 * @brief Defines the jpeg mime type.
 *
 * @since 10
 * @version 2.0
 */
static const char *MIME_TYPE_JPEG = "image/jpeg";

/**
 * @brief Defines the heic mime type.
 *
 * @since 10
 * @version 2.0
 */
static const char *MIME_TYPE_HEIC = "image/heic";

/**
 * @brief Defines the png mime type.
 *
 * @since 10
 * @version 2.0
 */
static const char *MIME_TYPE_PNG = "image/png";

/**
 * @brief Defines the webp mime type.
 *
 * @since 10
 * @version 2.0
 */
static const char *MIME_TYPE_WEBP = "image/webp";

/**
 * @brief Defines the gif mime type.
 *
 * @since 10
 * @version 2.0
 */
static const char *MIME_TYPE_GIF = "image/gif";

/**
 * @brief Defines the x-icon mime type.
 *
 * @since 10
 * @version 2.0
 */
static const char *MIME_TYPE_ICON = "image/x-icon";

/**
 * @brief Defines a pointer to bits per sample, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char *OHOS_IMAGE_PROPERTY_BITS_PER_SAMPLE = "BitsPerSample";

/**
 * @brief Defines a pointer to the orientation, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char *OHOS_IMAGE_PROPERTY_ORIENTATION = "Orientation";

/**
 * @brief Defines a pointer to the image length, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char *OHOS_IMAGE_PROPERTY_IMAGE_LENGTH = "ImageLength";

/**
 * @brief Defines a pointer to the image width, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char *OHOS_IMAGE_PROPERTY_IMAGE_WIDTH = "ImageWidth";

/**
 * @brief Defines a pointer to the GPS latitude, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_LATITUDE = "GPSLatitude";

/**
 * @brief Defines a pointer to the GPS longitude, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_LONGITUDE = "GPSLongitude";

/**
 * @brief Defines a pointer to the GPS latitude reference information, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_LATITUDE_REF = "GPSLatitudeRef";

/**
 * @brief Defines a pointer to the GPS longitude reference information, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_LONGITUDE_REF = "GPSLongitudeRef";

/**
 * @brief Defines a pointer to the created date and time, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char *OHOS_IMAGE_PROPERTY_DATE_TIME_ORIGINAL = "DateTimeOriginal";

/**
 * @brief Defines a pointer to the exposure time, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char *OHOS_IMAGE_PROPERTY_EXPOSURE_TIME = "ExposureTime";

/**
 * @brief Defines a pointer to the scene type, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char *OHOS_IMAGE_PROPERTY_SCENE_TYPE = "SceneType";

/**
 * @brief Defines a pointer to the ISO speed ratings, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char *OHOS_IMAGE_PROPERTY_ISO_SPEED_RATINGS = "ISOSpeedRatings";

/**
 * @brief Defines a pointer to the f-number of the image, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char *OHOS_IMAGE_PROPERTY_F_NUMBER = "FNumber";

/**
 * @brief Defines a pointer to the compressed bits per pixel, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char *OHOS_IMAGE_PROPERTY_COMPRESSED_BITS_PER_PIXEL = "CompressedBitsPerPixel";

/**
 * @brief The scheme used for image compression.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_COMPRESSION = "Compression";

/**
 * @brief Pixel composition, such as RGB or YCbCr.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_PHOTOMETRIC_INTERPRETATION = "PhotometricInterpretation";

/**
 * @brief For each strip, the byte offset of that strip.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_STRIP_OFFSETS = "StripOffsets";

/**
 * @brief The number of components per pixel.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_SAMPLES_PER_PIXEL = "SamplesPerPixel";

/**
 * @brief The number of rows per strip of image data.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_ROWS_PER_STRIP = "RowsPerStrip";

/**
 * @brief The total number of bytes in each strip of image data.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_STRIP_BYTE_COUNTS = "StripByteCounts";

/**
 * @brief The image resolution in the width direction.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_X_RESOLUTION = "XResolution";

/**
 * @brief The image resolution in the height direction.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_Y_RESOLUTION = "YResolution";

/**
 * @brief Indicates whether pixel components are recorded in a chunky or planar format.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_PLANAR_CONFIGURATION = "PlanarConfiguration";

/**
 * @brief The unit used to measure XResolution and YResolution.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_RESOLUTION_UNIT = "ResolutionUnit";

/**
 * @brief The transfer function for the image, typically used for color correction.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_TRANSFER_FUNCTION = "TransferFunction";

/**
 * @brief The name and version of the software used to generate the image.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_SOFTWARE = "Software";

/**
 * @brief The name of the person who created the image.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_ARTIST = "Artist";

/**
 * @brief The chromaticity of the white point of the image.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_WHITE_POINT = "WhitePoint";

/**
 * @brief The chromaticity of the primary colors of the image.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_PRIMARY_CHROMATICITIES = "PrimaryChromaticities";

/**
 * @brief The matrix coefficients for transformation from RGB to YCbCr image data.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_YCBCR_COEFFICIENTS = "YCbCrCoefficients";

/**
 * @brief The sampling ratio of chrominance components to the luminance component.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_YCBCR_SUB_SAMPLING = "YCbCrSubSampling";

/**
 * @brief The position of chrominance components in relation to the luminance component.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_YCBCR_POSITIONING = "YCbCrPositioning";

/**
 * @brief The reference black point value and reference white point value.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_REFERENCE_BLACK_WHITE = "ReferenceBlackWhite";

/**
 * @brief Copyright information for the image.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_COPYRIGHT = "Copyright";

/**
 * @brief The offset to the start byte (SOI) of JPEG compressed thumbnail data.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_JPEG_INTERCHANGE_FORMAT = "JPEGInterchangeFormat";

/**
 * @brief The number of bytes of JPEG compressed thumbnail data.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_JPEG_INTERCHANGE_FORMAT_LENGTH = "JPEGInterchangeFormatLength";

/**
 * @brief The class of the program used by the camera to set exposure when the picture is taken.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_EXPOSURE_PROGRAM = "ExposureProgram";

/**
 * @brief Indicates the spectral sensitivity of each channel of the camera used.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_SPECTRAL_SENSITIVITY = "SpectralSensitivity";

/**
 * @brief Indicates the Opto-Electric Conversion Function (OECF) specified in ISO 14524.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_OECF = "OECF";

/**
 * @brief The version of the Exif standard supported.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_EXIF_VERSION = "ExifVersion";

/**
 * @brief The date and time when the image was stored as digital data.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_DATE_TIME_DIGITIZED = "DateTimeDigitized";

/**
 * @brief Information specific to compressed data.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_COMPONENTS_CONFIGURATION = "ComponentsConfiguration";

/**
 * @brief The shutter speed, expressed as an APEX (Additive System of Photographic Exposure) value.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_SHUTTER_SPEED_VALUE = "ShutterSpeedValue";

/**
 * @brief The brightness value of the image, in APEX units.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_BRIGHTNESS_VALUE = "BrightnessValue";

/**
 * @brief The smallest F number of lens.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_MAX_APERTURE_VALUE = "MaxApertureValue";

/**
 * @brief The distance to the subject, measured in meters.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_SUBJECT_DISTANCE = "SubjectDistance";

/**
 * @brief This tag indicate the location and area of the main subject in the overall scene.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_SUBJECT_AREA = "SubjectArea";

/**
 * @brief A tag for manufacturers of Exif/DCF writers to record any desired infomation.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_MAKER_NOTE = "MakerNote";

/**
 * @brief A tag for record fractions of seconds for the DateTime tag.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_SUBSEC_TIME = "SubsecTime";

/**
 * @brief A tag used to record fractions of seconds for the DateTimeOriginal tag.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_SUBSEC_TIME_ORIGINAL = "SubsecTimeOriginal";

/**
 * @brief A tag used to record fractions of seconds for the DateTimeDigitized tag.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_SUBSEC_TIME_DIGITIZED = "SubsecTimeDigitized";

/**
 * @brief This tag denotes the Flashpix format version supported by an FPXR file, enhancing device compatibility.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_FLASHPIX_VERSION = "FlashpixVersion";

/**
 * @brief The color space information tag, often recorded as the color space specifier.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_COLOR_SPACE = "ColorSpace";

/**
 * @brief The name of an audio file related to the image data.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_RELATED_SOUND_FILE = "RelatedSoundFile";

/**
 * @brief Strobe energy at image capture, in BCPS.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_FLASH_ENERGY = "FlashEnergy";

/**
 * @brief Camera or input device spatial frequency table.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_SPATIAL_FREQUENCY_RESPONSE = "SpatialFrequencyResponse";

/**
 * @brief Pixels per FocalPlaneResolutionUnit in the image width.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_FOCAL_PLANE_X_RESOLUTION = "FocalPlaneXResolution";

/**
 * @brief Pixels per FocalPlaneResolutionUnit in the image height.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_FOCAL_PLANE_Y_RESOLUTION = "FocalPlaneYResolution";

/**
 * @brief Unit for measuring FocalPlaneXResolution and FocalPlaneYResolution.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_FOCAL_PLANE_RESOLUTION_UNIT = "FocalPlaneResolutionUnit";

/**
 * @brief Location of the main subject, relative to the left edge.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_SUBJECT_LOCATION = "SubjectLocation";

/**
 * @brief Selected exposure index at capture.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_EXPOSURE_INDEX = "ExposureIndex";

/**
 * @brief Image sensor type on the camera.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_SENSING_METHOD = "SensingMethod";

/**
 * @brief Indicates the image source.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_FILE_SOURCE = "FileSource";

/**
 * @brief Color filter array (CFA) geometric pattern of the image sensor.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_CFA_PATTERN = "CFAPattern";

/**
 * @brief Indicates special processing on image data.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_CUSTOM_RENDERED = "CustomRendered";

/**
 * @brief Exposure mode set when the image was shot.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_EXPOSURE_MODE = "ExposureMode";

/**
 * @brief Digital zoom ratio at the time of capture.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_DIGITAL_ZOOM_RATIO = "DigitalZoomRatio";

/**
 * @brief Type of scene captured.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_SCENE_CAPTURE_TYPE = "SceneCaptureType";

/**
 * @brief Degree of overall image gain adjustment.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GAIN_CONTROL = "GainControl";

/**
 * @brief Direction of contrast processing applied by the camera.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_CONTRAST = "Contrast";

/**
 * @brief Direction of saturation processing applied by the camera.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_SATURATION = "Saturation";

/**
 * @brief The direction of sharpness processing applied by the camera.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_SHARPNESS = "Sharpness";

/**
 * @brief Information on picture-taking conditions for a specific camera model.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_DEVICE_SETTING_DESCRIPTION = "DeviceSettingDescription";

/**
 * @brief Indicates the distance range to the subject.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_SUBJECT_DISTANCE_RANGE = "SubjectDistanceRange";

/**
 * @brief An identifier uniquely assigned to each image.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_IMAGE_UNIQUE_ID = "ImageUniqueID";

/**
 * @brief The version of the GPSInfoIFD.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_VERSION_ID = "GPSVersionID";

/**
 * @brief Reference altitude used for GPS altitude.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_ALTITUDE_REF = "GPSAltitudeRef";

/**
 * @brief The altitude based on the reference in GPSAltitudeRef.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_ALTITUDE = "GPSAltitude";

/**
 * @brief The GPS satellites used for measurements.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_SATELLITES = "GPSSatellites";

/**
 * @brief The status of the GPS receiver when the image is recorded.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_STATUS = "GPSStatus";

/**
 * @brief The GPS measurement mode.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_MEASURE_MODE = "GPSMeasureMode";

/**
 * @brief The GPS DOP (data degree of precision).
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_DOP = "GPSDOP";

/**
 * @brief The unit used to express the GPS receiver speed of movement.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_SPEED_REF = "GPSSpeedRef";

/**
 * @brief The speed of GPS receiver movement.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_SPEED = "GPSSpeed";

/**
 * @brief The reference for giving the direction of GPS receiver movement.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_TRACK_REF = "GPSTrackRef";

/**
 * @brief The direction of GPS receiver movement.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_TRACK = "GPSTrack";

/**
 * @brief The reference for the image's direction.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_IMG_DIRECTION_REF = "GPSImgDirectionRef";

/**
 * @brief The direction of the image when captured.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_IMG_DIRECTION = "GPSImgDirection";

/**
 * @brief Geodetic survey data used by the GPS receiver.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_MAP_DATUM = "GPSMapDatum";

/**
 * @brief Indicates the latitude reference of the destination point.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_DEST_LATITUDE_REF = "GPSDestLatitudeRef";

/**
 * @brief The latitude of the destination point.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_DEST_LATITUDE = "GPSDestLatitude";

/**
 * @brief Indicates the longitude reference of the destination point.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_DEST_LONGITUDE_REF = "GPSDestLongitudeRef";

/**
 * @brief A character string recording the name of the method used for location finding.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_PROCESSING_METHOD = "GPSProcessingMethod";

/**
 * @brief A character string recording the name of the GPS area.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_AREA_INFORMATION = "GPSAreaInformation";

/**
 * @brief This field denotes if differential correction was applied to GPS data, crucial for precise location accuracy.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_DIFFERENTIAL = "GPSDifferential";

/**
 * @brief The serial number of the camera body.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_BODY_SERIAL_NUMBER = "BodySerialNumber";

/**
 * @brief The name of the camera owner.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_CAMERA_OWNER_NAME = "CameraOwnerName";

/**
 * @brief The name of the camera owner.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_COMPOSITE_IMAGE = "CompositeImage";

/**
 * @brief The DNGVersion tag encodes the four-tier version number for DNG specification compliance.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_DNG_VERSION = "DNGVersion";

/**
 * @brief The longitude of the destination point.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_DEST_LONGITUDE = "GPSDestLongitude";

/**
 * @brief The reference for the bearing to the destination point.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_DEST_BEARING_REF = "GPSDestBearingRef";

/**
 * @brief The bearing to the destination point.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_DEST_BEARING = "GPSDestBearing";

/**
 * @brief The measurement unit for the distance to the target point.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_DEST_DISTANCE_REF = "GPSDestDistanceRef";

/**
 * @brief The distance to the destination point.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_DEST_DISTANCE = "GPSDestDistance";

/**
 * @brief DefaultCropSize specifies the final image size in raw coordinates, accounting for extra edge pixels.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_DEFAULT_CROP_SIZE = "DefaultCropSize";

/**
 * @brief The Gamma tag represents the gamma coefficient used for color correction in image processing.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GAMMA = "Gamma";

/**
 * @brief The ISO speed latitude yyy value of the camera.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_ISO_SPEED_LATITUDEYYY = "ISOSpeedLatitudeyyy";

/**
 * @brief The ISO speed latitude zzz value of the camera.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_ISO_SPEED_LATITUDEZZZ = "ISOSpeedLatitudezzz";

/**
 * @brief The manufacturer of the lens.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_LENS_MAKE = "LensMake";

/**
 * @brief The model name of the lens.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_LENS_MODEL = "LensModel";

/**
 * @brief The serial number of the lens.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_LENS_SERIAL_NUMBER = "LensSerialNumber";

/**
 * @brief Specifications of the lens used.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_LENS_SPECIFICATION = "LensSpecification";

/**
 * @brief This tag provides a broad description of the data type in this subfile.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_NEW_SUBFILE_TYPE = "NewSubfileType";

/**
 * @brief This tag records the UTC offset for the DateTime tag, ensuring accurate timestamps regardless of location.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_OFFSET_TIME = "OffsetTime";

/**
 * @brief This tag logs the UTC offset when the image was digitized, aiding in accurate timestamp adjustment.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_OFFSET_TIME_DIGITIZED = "OffsetTimeDigitized";

/**
 * @brief This tag records the UTC offset when the original image was created, crucial for time-sensitive applications.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_OFFSET_TIME_ORIGINAL = "OffsetTimeOriginal";

/**
 * @brief Exposure times of source images for a composite image.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_SOURCE_EXPOSURE_TIMES_OF_COMPOSITE_IMAGE = "SourceExposureTimesOfCompositeImage";

/**
 * @brief The number of source images used for a composite image.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_SOURCE_IMAGE_NUMBER_OF_COMPOSITE_IMAGE = "SourceImageNumberOfCompositeImage";

/**
 * @brief This deprecated field signifies the type of data in this subfile. Use the NewSubfileType field instead.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_SUBFILE_TYPE = "SubfileType";

/**
 * @brief This tag denotes the horizontal positioning inaccuracies measured in meters.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_H_POSITIONING_ERROR = "GPSHPositioningError";

/**
 * @brief Burst Number
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_BURST_NUMBER = "HwMnoteBurstNumber";

/**
 * @brief Face Conf
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_FACE_CONF = "HwMnoteFaceConf";

/**
 * @brief Face Leye Center
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_FACE_LEYE_CENTER = "HwMnoteFaceLeyeCenter";

/**
 * @brief Face Mouth Center
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_FACE_MOUTH_CENTER = "HwMnoteFaceMouthCenter";

#ifdef __cplusplus
};
#endif
/* * @} */


#endif // INTERFACES_KITS_NATIVE_INCLUDE_IMAGE_IMAGE_COMMON_H_