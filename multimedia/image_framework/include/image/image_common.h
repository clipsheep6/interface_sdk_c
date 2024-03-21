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
 * @Syscap SystemCapability.Multimedia.Image
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
    IMAGE_RESULT_MEDIA_RTSP_SURFACE_UNSUPPORT = IMAGE_RESULT_BASE + 67,      // media rtsp surface not support
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
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char *OHOS_IMAGE_PROPERTY_BITS_PER_SAMPLE = "BitsPerSample";

/**
 * @brief Defines a pointer to the orientation, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char *OHOS_IMAGE_PROPERTY_ORIENTATION = "Orientation";

/**
 * @brief Defines a pointer to the image length, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char *OHOS_IMAGE_PROPERTY_IMAGE_LENGTH = "ImageLength";

/**
 * @brief Defines a pointer to the image width, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char *OHOS_IMAGE_PROPERTY_IMAGE_WIDTH = "ImageWidth";

/**
 * @brief Defines a pointer to the GPS latitude, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_LATITUDE = "GPSLatitude";

/**
 * @brief Defines a pointer to the GPS longitude, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_LONGITUDE = "GPSLongitude";

/**
 * @brief Defines a pointer to the GPS latitude reference information, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_LATITUDE_REF = "GPSLatitudeRef";

/**
 * @brief Defines a pointer to the GPS longitude reference information, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_LONGITUDE_REF = "GPSLongitudeRef";

/**
 * @brief Defines a pointer to the created date and time, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char *OHOS_IMAGE_PROPERTY_DATE_TIME_ORIGINAL = "DateTimeOriginal";

/**
 * @brief Defines a pointer to the exposure time, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char *OHOS_IMAGE_PROPERTY_EXPOSURE_TIME = "ExposureTime";

/**
 * @brief Defines a pointer to the scene type, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char *OHOS_IMAGE_PROPERTY_SCENE_TYPE = "SceneType";

/**
 * @brief Defines a pointer to the ISO speed ratings, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char *OHOS_IMAGE_PROPERTY_ISO_SPEED_RATINGS = "ISOSpeedRatings";

/**
 * @brief Defines a pointer to the f-number of the image, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char *OHOS_IMAGE_PROPERTY_F_NUMBER = "FNumber";

/**
 * @brief Defines a pointer to the compressed bits per pixel, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char *OHOS_IMAGE_PROPERTY_COMPRESSED_BITS_PER_PIXEL = "CompressedBitsPerPixel";

/**
 * @brief Compression scheme for image data. If primary image is JPEG compressed, this is omitted.
 * If thumbnails use JPEG compression, this tag value is set to 6.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_COMPRESSION = "Compression";

/**
 * @brief The pixel composition. In JPEG compressed data a JPEG marker is used instead.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_PHOTOMETRIC_INTERPRETATION = "PhotometricInterpretation";

/**
 * @brief Byte offset of each strip. Recommended to select so strip bytes do not exceed 64 Kbytes.
 * With JPEG compressed data this is not needed and is omitted. See also <RowsPerStrip> and <StripByteCounts>.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_STRIP_OFFSETS = "StripOffsets";

/**
 * @brief Number of components per pixel. This standard applies to RGB and YCbCr images, so the value is 3.
 * In JPEG compressed data a JPEG marker is used instead.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_SAMPLES_PER_PIXEL = "SamplesPerPixel";

/**
 * @brief Number of rows per strip. This is the number of rows in one strip when an image is divided into strips.
 * With JPEG compressed data this is not needed and is omitted. See also <StripOffsets> and <StripByteCounts>.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_ROWS_PER_STRIP = "RowsPerStrip";

/**
 * @brief Total bytes in each strip. Not needed and omitted for JPEG compressed data.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_STRIP_BYTE_COUNTS = "StripByteCounts";

/**
 * @brief Pixels per <ResolutionUnit> in <ImageWidth> direction. If unknown, 72 [dpi] is used.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_X_RESOLUTION = "XResolution";

/**
 * @brief Pixels per <ResolutionUnit> in <ImageLength> direction. Same value as <XResolution> is used.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_Y_RESOLUTION = "YResolution";

/**
 * @brief Indicates pixel components format. In JPEG files a JPEG marker is used instead. If absent, 1 (chunky)
 * is assumed.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_PLANAR_CONFIGURATION = "PlanarConfiguration";

/**
 * @brief Unit for <XResolution> and <YResolution>. Same unit for both. If unknown, 2 (inches) is used.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_RESOLUTION_UNIT = "ResolutionUnit";

/**
 * @brief Image transfer function, described in tabular style. Not necessary if color space is specified in
 * <ColorSpace>. Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_TRANSFER_FUNCTION = "TransferFunction";

/**
 * @brief Records software or firmware name and version used to generate the image. If blank, treated as unknown.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_SOFTWARE = "Software";

/**
 * @brief Records name of camera owner, photographer or image creator. If blank, treated as unknown.
 * Ex.) "Camera owner, John Smith; Photographer, Michael Brown; Image creator, Ken James"
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_ARTIST = "Artist";

/**
 * @brief Chromaticity of the image's white point. Not necessary if color space is specified in <ColorSpace>.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_WHITE_POINT = "WhitePoint";

/**
 * @brief Chromaticity of the image's three primary colors. Not necessary if color space is specified in <ColorSpace>.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_PRIMARY_CHROMATICITIES = "PrimaryChromaticities";

/**
 * @brief Matrix coefficients for RGB to YCbCr transformation. No TIFF default; value from Appendix E is used.
 * Color space is declared in a color space information tag.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_YCBCR_COEFFICIENTS = "YCbCrCoefficients";

/**
 * @brief Sampling ratio of chrominance to luminance. In JPEG data a JPEG marker is used instead.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_YCBCR_SUB_SAMPLING = "YCbCrSubSampling";

/**
 * @brief Position of chrominance to luminance. Only for JPEG or uncompressed YCbCr data. TIFF default is 1 (centered).
 * For Y:Cb:Cr = 4:2:2, 2 (co-sited) is recommended. If absent, TIFF default is assumed.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_YCBCR_POSITIONING = "YCbCrPositioning";

/**
 * @brief Reference black and white point values. No TIFF defaults; values here are defaults.
 * Color space is declared in a color space information tag.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_REFERENCE_BLACK_WHITE = "ReferenceBlackWhite";

/**
 * @brief Copyright information for photographer and editor. If blank, treated as unknown.
 * Format: "Copyright, John Smith, 19xx. All rights reserved.".
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_COPYRIGHT = "Copyright";

/**
 * @brief Offset to start byte of JPEG thumbnail data. Not used for primary image JPEG data.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_JPEG_INTERCHANGE_FORMAT = "JPEGInterchangeFormat";

/**
 * @brief Number of bytes of JPEG thumbnail data. Not used for primary image JPEG data.
 * JPEG thumbnails are continuous bitstream from SOI to EOI. Must be recorded in no more than 64 Kbytes.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_JPEG_INTERCHANGE_FORMAT_LENGTH = "JPEGInterchangeFormatLength";

/**
 * @brief Class of the program used by the camera to set exposure.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_EXPOSURE_PROGRAM = "ExposureProgram";

/**
 * @brief Spectral sensitivity of each channel of the camera used.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_SPECTRAL_SENSITIVITY = "SpectralSensitivity";

/**
 * @brief Opto-Electric Conversion Function (OECF) specified in ISO 14524.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_OECF = "OECF";

/**
 * @brief Supported version of this standard. Nonexistence means nonconformance to the standard.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_EXIF_VERSION = "ExifVersion";

/**
 * @brief Date and time when the image was stored as digital data.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_DATE_TIME_DIGITIZED = "DateTimeDigitized";

/**
 * @brief Info specific to compressed data. For uncompressed data, see <PhotometricInterpretation> tag.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_COMPONENTS_CONFIGURATION = "ComponentsConfiguration";

/**
 * @brief Shutter speed.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_SHUTTER_SPEED_VALUE = "ShutterSpeedValue";

/**
 * @brief The value of brightness.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_BRIGHTNESS_VALUE = "BrightnessValue";

/**
 * @brief The smallest F number of the lens.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_MAX_APERTURE_VALUE = "MaxApertureValue";

/**
 * @brief The distance to the subject, given in meters.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_SUBJECT_DISTANCE = "SubjectDistance";

/**
 * @brief This tag indicates the location and area of the main subject in the overall scene.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_SUBJECT_AREA = "SubjectArea";

/**
 * @brief A tag for manufacturers of Exif writers to record any desired information. The contents are up to
 * the manufacturer.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_MAKER_NOTE = "MakerNote";

/**
 * @brief A tag used to record fractions of seconds for the <DateTime> tag.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_SUBSEC_TIME = "SubsecTime";

/**
 * @brief A tag used to record fractions of seconds for the <DateTimeOriginal> tag.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_SUBSEC_TIME_ORIGINAL = "SubsecTimeOriginal";

/**
 * @brief A tag used to record fractions of seconds for the <DateTimeDigitized> tag.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_SUBSEC_TIME_DIGITIZED = "SubsecTimeDigitized";

/**
 * @brief The FlashPix format version supported by a FPXR file.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_FLASHPIX_VERSION = "FlashpixVersion";

/**
 * @brief The color space information tag is always recorded as the color space specifier.
 * Normally sRGB is used based on the PC monitor conditions and environment. If a color space
 * other than sRGB is used, Uncalibrated is set. Image data recorded as Uncalibrated can be
 * treated as sRGB when it is converted to FlashPix.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_COLOR_SPACE = "ColorSpace";

/**
 * @brief This tag is used to record the name of an audio file related to the image data.
 * The only relational information recorded here is the Exif audio file name and extension
 * (an ASCII string consisting of 8 characters + '.' + 3 characters). The path is not recorded.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_RELATED_SOUND_FILE = "RelatedSoundFile";

/**
 * @brief Amount of flash energy (BCPS).
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_FLASH_ENERGY = "FlashEnergy";

/**
 * @brief SFR of the camera.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_SPATIAL_FREQUENCY_RESPONSE = "SpatialFrequencyResponse";

/**
 * @brief Number of pixels per FocalPlaneResolutionUnit (37392) in ImageWidth direction for main image.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_FOCAL_PLANE_X_RESOLUTION = "FocalPlaneXResolution";

/**
 * @brief Number of pixels per FocalPlaneResolutionUnit (37392) in ImageLength direction for main image.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_FOCAL_PLANE_Y_RESOLUTION = "FocalPlaneYResolution";

/**
 * @brief Unit of measurement for FocalPlaneXResolution(37390) and FocalPlaneYResolution(37391).
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_FOCAL_PLANE_RESOLUTION_UNIT = "FocalPlaneResolutionUnit";

/**
 * @brief Indicates the location and area of the main subject in the overall scene.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_SUBJECT_LOCATION = "SubjectLocation";

/**
 * @brief Encodes the camera exposure index setting when image was captured.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_EXPOSURE_INDEX = "ExposureIndex";

/**
 * @brief Type of image sensor.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_SENSING_METHOD = "SensingMethod";

/**
 * @brief Indicates the image source. If a DSC recorded the image, this tag value always be set to 3.
 * This indicates that the image was recorded on a DSC.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_FILE_SOURCE = "FileSource";

/**
 * @brief Indicates the color filter array (CFA) geometric pattern of the image sensor.
 * This is applicable when a one-chip color area sensor is used. It does not apply to all sensing methods.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_CFA_PATTERN = "CFAPattern";

/**
 * @brief Indicates the use of special processing on image data, such as rendering geared to output.
 * When special processing is performed, the reader is expected to disable or minimize any further processing.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_CUSTOM_RENDERED = "CustomRendered";

/**
 * @brief Indicates the exposure mode set when the image was shot. In auto-bracketing mode,
 * the camera shoots a series of frames of the same scene at different exposure settings.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_EXPOSURE_MODE = "ExposureMode";

/**
 * @brief Indicates the digital zoom ratio when the image was shot. If the numerator of the recorded
 * value is 0, this indicates that digital zoom was not used.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_DIGITAL_ZOOM_RATIO = "DigitalZoomRatio";

/**
 * @brief Indicates the type of scene that was shot. It can also be used to record the mode in which
 * the image was shot. Note that this differs from the <SceneType> tag.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_SCENE_CAPTURE_TYPE = "SceneCaptureType";

/**
 * @brief This tag indicates the degree of overall image gain adjustment.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GAIN_CONTROL = "GainControl";

/**
 * @brief This tag indicates the direction of contrast processing applied by the camera when the image was shot.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_CONTRAST = "Contrast";

/**
 * @brief This tag indicates the direction of saturation processing applied by the camera when the image was shot.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_SATURATION = "Saturation";

/**
 * @brief This tag indicates the direction of sharpness processing applied by the camera when the image was shot.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_SHARPNESS = "Sharpness";

/**
 * @brief Indicates picture-taking conditions of a camera model. Used only to indicate conditions in the reader.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_DEVICE_SETTING_DESCRIPTION = "DeviceSettingDescription";

/**
 * @brief Indicates the distance to the subject.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_SUBJECT_DISTANCE_RANGE = "SubjectDistanceRange";

/**
 * @brief Indicates an identifier assigned uniquely to each image.
 * Recorded as an ASCII string equivalent to hexadecimal notation and 128-bit fixed length.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_IMAGE_UNIQUE_ID = "ImageUniqueID";

/**
 * @brief Indicates the version of <GPSInfoIFD>. Given as 2.0.0.0.
 * This tag is mandatory when <GPSInfo> tag is present.
 * (Note: The <GPSVersionID> tag is given in bytes, unlike the <ExifVersion> tag.
 * When the version is 2.0.0.0, the tag value is 02000000.H).
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_VERSION_ID = "GPSVersionID";

/**
 * @brief Indicates the reference altitude. If the reference is sea level and the altitude is above sea level,
 * 0 is given.
 * If the altitude is below sea level, a value of 1 is given and the altitude is indicated as an absolute value
 * in the GSPAltitude tag.
 * The reference unit is meters. Note that this tag is BYTE type, unlike other reference tags.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_ALTITUDE_REF = "GPSAltitudeRef";

/**
 * @brief Indicates the altitude based on the reference in GPSAltitudeRef.
 * Altitude is expressed as one RATIONAL value. The reference unit is meters.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_ALTITUDE = "GPSAltitude";

/**
 * @brief Indicates the GPS satellites used for measurements.
 * This tag can be used to describe the number of satellites, their ID number, angle of elevation, azimuth, SNR and
 * other information in ASCII notation.
 * The format is not specified. If the GPS receiver is incapable of taking measurements, value of the tag is set to
 * NULL.
 * Used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_SATELLITES = "GPSSatellites";

/**
 * @brief Indicates the status of the GPS receiver when the image is recorded.
 * "A" means measurement is in progress, and "V" means the measurement is Interoperability.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_STATUS = "GPSStatus";

/**
 * @brief Indicates the GPS measurement mode.
 * "2" means two-dimensional measurement and "3" means three-dimensional measurement is in progress.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_MEASURE_MODE = "GPSMeasureMode";

/**
 * @brief Indicates the GPS DOP (data degree of precision). An HDOP value is written during two-dimensional
 * measurement, and PDOP during three-dimensional measurement.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_DOP = "GPSDOP";

/**
 * @brief Indicates the unit used to express the GPS receiver speed of movement. "K" "M" and "N"
 * represents kilometers per hour, miles per hour, and knots.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_SPEED_REF = "GPSSpeedRef";

/**
 * @brief Indicates the speed of GPS receiver movement.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_SPEED = "GPSSpeed";

/**
 * @brief Indicates the reference for giving the direction of GPS receiver movement. "T" denotes true
 * direction and "M" is magnetic direction.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_TRACK_REF = "GPSTrackRef";

/**
 * @brief Indicates the direction of GPS receiver movement. The range of values is from 0.00 to 359.99.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_TRACK = "GPSTrack";

/**
 * @brief Indicates the reference for giving the direction of the image when it is captured. "T" denotes
 * true direction and "M" is magnetic direction.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_IMG_DIRECTION_REF = "GPSImgDirectionRef";

/**
 * @brief Indicates the direction of the image when it was captured. The range of values is from 0.00 to 359.99.
 * It is used in {@link OH_ImageSource_GetImageProperty} and
 * {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_IMG_DIRECTION = "GPSImgDirection";

/**
 * @brief Indicates the geodetic survey data used by the GPS receiver. If the survey data is restricted to
 * Japan, the value of this tag is "TOKYO" or "WGS-84".
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_MAP_DATUM = "GPSMapDatum";

/**
 * @brief Indicates whether the latitude of the destination point is north or south latitude. The ASCII
 * value "N" indicates north latitude, and "S" is south latitude.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_DEST_LATITUDE_REF = "GPSDestLatitudeRef";

/**
 * @brief Indicates the latitude of the destination point. The latitude is expressed as three RATIONAL
 * values giving the degrees, minutes, and seconds, respectively. If latitude is expressed as degrees,
 * minutes and seconds, a typical format would be dd/1,mm/1,ss/1. When degrees and minutes are used and,
 * for example, fractions of minutes are given up to two decimal places, the format would be dd/1,mmmm/100,0/1.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_DEST_LATITUDE = "GPSDestLatitude";

/**
 * @brief Indicates whether the longitude of the destination point is east or west longitude. ASCII "E"
 * indicates east longitude, and "W" is west longitude.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_DEST_LONGITUDE_REF = "GPSDestLongitudeRef";

/**
 * @brief A character string recording the name of the method used for location finding. The string encoding
 * is defined using the same scheme as UserComment.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_PROCESSING_METHOD = "GPSProcessingMethod";

/**
 * @brief A character string recording the name of the GPS area.The string encoding is defined using the
 * same scheme as UserComment.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_AREA_INFORMATION = "GPSAreaInformation";

/**
 * @brief Indicates whether differential correction is applied to the GPS receiver.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_DIFFERENTIAL = "GPSDifferential";

/**
 * @brief This tag records the serial number of the body of the camera that was used in photography as an ASCII string.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_BODY_SERIAL_NUMBER = "BodySerialNumber";

/**
 * @brief This tag records the owner of a camera used in photography as an ASCII string.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_CAMERA_OWNER_NAME = "CameraOwnerName";

/**
 * @brief Indicates whether the recorded image is a composite image or not.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_COMPOSITE_IMAGE = "CompositeImage";

/**
 * @brief This tag encodes the DNG four-tier version number. For files compliant with version 1.1.0.0 of
 * the DNG specification, this tag should contain the bytes: 1, 1, 0, 0.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_DNG_VERSION = "DNGVersion";

/**
 * @brief Indicates the longitude of the destination point. The longitude is expressed as three RATIONAL
 * values giving the degrees, minutes, and seconds, respectively. If longitude is expressed as degrees,
 * minutes and seconds, a typical format would be ddd/1,mm/1,ss/1. When degrees and minutes are used and,
 * for example, fractions of minutes are given up to two decimal places, the format would be ddd/1,mmmm/100,0/1.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_DEST_LONGITUDE = "GPSDestLongitude";

/**
 * @brief Indicates the reference used for giving the bearing to the destination point. "T" denotes true
 * direction and "M" is magnetic direction.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_DEST_BEARING_REF = "GPSDestBearingRef";

/**
 * @brief Indicates the bearing to the destination point. The range of values is from 0.00 to 359.99.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_DEST_BEARING = "GPSDestBearing";

/**
 * @brief Indicates the unit used to express the distance to the destination point. "K", "M" and "N"
 * represent kilometers, miles and knots.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_DEST_DISTANCE_REF = "GPSDestDistanceRef";

/**
 * @brief Indicates the distance to the destination point.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_DEST_DISTANCE = "GPSDestDistance";

/**
 * @brief Raw images often store extra pixels around the edges of the final image. These extra pixels
 * help prevent interpolation artifacts near the edges of the final image. DefaultCropSize specifies
 * the size of the final image area, in raw image coordinates (i.e., before the DefaultScale has been
 * applied).
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_DEFAULT_CROP_SIZE = "DefaultCropSize";

/**
 * @brief Indicates the value of coefficient gamma. The formula of transfer function used for image
 * reproduction is expressed as follows: (reproduced value) = (input value)^gamma. Both reproduced value
 * and input value indicate normalized value, whose minimum value is 0 and maximum value is 1.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GAMMA = "Gamma";

/**
 * @brief This tag indicates the ISO speed latitude yyy value of a camera or input device that is
 * defined in ISO 12232. However, this tag shall not be recorded without ISOSpeed and
 * ISOSpeedLatitudezzz.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_ISO_SPEED_LATITUDEYYY = "ISOSpeedLatitudeyyy";

/**
 * @brief This tag indicates the ISO speed latitude zzz value of a camera or input device that is
 * defined in ISO 12232. However, this tag shall not be recorded without ISOSpeed and
 * ISOSpeedLatitudeyyy.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_ISO_SPEED_LATITUDEZZZ = "ISOSpeedLatitudezzz";

/**
 * @brief This tag records the lens manufactor as an ASCII string.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_LENS_MAKE = "LensMake";

/**
 * @brief This tag records the lens's model name and model number as an ASCII string.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_LENS_MODEL = "LensModel";

/**
 * @brief This tag records the serial number of the interchangeable lens that was used in photography as
 * an ASCII string.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_LENS_SERIAL_NUMBER = "LensSerialNumber";

/**
 * @brief This tag notes minimum focal length, maximum focal length, minimum F number in the minimum focal length,
 * and minimum F number in the maximum focal length, which are specification information for the lens that was
 * used in photography. When the minimum F number is unknown, the notation is 0/0
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_LENS_SPECIFICATION = "LensSpecification";

/**
 * @brief A general indication of the kind of data contained in this subfile.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_NEW_SUBFILE_TYPE = "NewSubfileType";

/**
 * @brief Time difference from Universal Time Coordinated including daylight saving time of DateTime tag.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_OFFSET_TIME = "OffsetTime";

/**
 * @brief Time difference from Universal Time Coordinated including daylight saving time of DateTimeDigitized tag.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_OFFSET_TIME_DIGITIZED = "OffsetTimeDigitized";

/**
 * @brief Time difference from Universal Time Coordinated including daylight saving time of DateTimeOriginal tag.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_OFFSET_TIME_ORIGINAL = "OffsetTimeOriginal";

/**
 * @brief For a composite image, records the parameters relating exposure time of the exposures for generating
 * the said composite image, such as respective exposure times of captured source images (tentatively recorded images).
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_SOURCE_EXPOSURE_TIMES_OF_COMPOSITE_IMAGE = "SourceExposureTimesOfCompositeImage";

/**
 * @brief Indicates the number of the source images (tentatively recorded images) captured for a composite Image.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_SOURCE_IMAGE_NUMBER_OF_COMPOSITE_IMAGE = "SourceImageNumberOfCompositeImage";

/**
 * @brief A general indication of the kind of data contained in this subfile. This field is deprecated.
 * The NewSubfileType field should be used instead.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_SUBFILE_TYPE = "SubfileType";

/**
 * @brief This tag indicates horizontal positioning errors in meters.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_GPS_H_POSITIONING_ERROR = "GPSHPositioningError";

/**
 * @brief Burst Number
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_BURST_NUMBER = "HwMnoteBurstNumber";

/**
 * @brief Face Conf
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_FACE_CONF = "HwMnoteFaceConf";

/**
 * @brief Face Leye Center
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_FACE_LEYE_CENTER = "HwMnoteFaceLeyeCenter";

/**
 * @brief Face Mouth Center
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char *OHOS_IMAGE_PROPERTY_FACE_MOUTH_CENTER = "HwMnoteFaceMouthCenter";

#ifdef __cplusplus
};
#endif
/* * @} */


#endif // INTERFACES_KITS_NATIVE_INCLUDE_IMAGE_IMAGE_COMMON_H_