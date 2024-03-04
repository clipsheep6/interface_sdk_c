/*
 * Copyright (C) 2024 Huawei Device Co., Ltd.
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
 * @version 5.0
 */

/**
 * @file image_common.h
 *
 * @brief Declares the common enums and structs used by the image interface.
 *
 * @since 12
 * @version 5.0
 */

#ifndef INTERFACES_KITS_NATIVE_INCLUDE_IMAGE_IMAGE_COMMON_H
#define INTERFACES_KITS_NATIVE_INCLUDE_IMAGE_IMAGE_COMMON_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define IMAGE_RESULT_BASE 62980096

/**
 * @brief Enumerates the return values that may be used by the interface.
 *
 * @since 12
 * @version 5.0
 */
typedef enum {
    IMAGE_RESULT_SUCCESS = 0,                                      // Operation success
    IMAGE_RESULT_BAD_PARAMETER = -1,                               // Invalid parameter
    IMAGE_RESULT_MALLOC_ABNORMAL = IMAGE_RESULT_BASE + 6,          // image malloc error
    IMAGE_RESULT_INVALID_PARAMETER = IMAGE_RESULT_BASE + 19,       // image invalid parameter
    IMAGE_RESULT_MEDIA_DEAD_OBJECT = IMAGE_RESULT_BASE + 46,       // media dead object
    IMAGE_RESULT_GET_PARAMETER_FAILED = IMAGE_RESULT_BASE + 157,   // Failed to obtain parameters
    IMAGE_RESULT_GET_DATA_ABNORMAL = IMAGE_RESULT_BASE + 9,        // image get data error
    IMAGE_RESULT_MEDIA_UNKNOWN = IMAGE_RESULT_BASE + 200,          // media unknown error
} OH_Image_ErrorCode;

/**
 * @brief Defines the image size.
 *
 * @since 12
 * @version 5.0
 */
struct OH_Image_Size {
    /** Image width, in pixels. */
    int32_t width = 0;
    /** Image height, in pixels. */
    int32_t height = 0;
};

/**
 * @brief Defines the image region.
 *
 * @since 12
 * @version 5.0
 */
struct OH_Image_Region {
    /** X coordinate of the rectangle. */
    int32_t x = 0;
    /** Y coordinate of the rectangle. */
    int32_t y = 0;
    /** Width of the rectangle, in pixels. */
    int32_t width = 0;
    /** Height of the rectangle, in pixels. */
    int32_t height = 0;
};

/**
 * @brief Defines the image string.
 *
 * @since 12
 * @version 5.0
 */
struct OH_Image_String {
    /**  */
    char* format = nullptr;
    /**  */
    size_t size = 0;
};

/**
 * @brief Enumerates the image formats.
 *
 * @since 12
 * @version 5.0
 */
enum {
    /** YCbCr422 semi-planar format. */
    OHOS_IMAGE_FORMAT_YCBCR_422_SP = 1000,
    /** JPEG encoding format. */
    OHOS_IMAGE_FORMAT_JPEG = 2000
};

/**
 * @brief Enumerates the image components.
 *
 * @since 12
 * @version 5.0
 */
enum {
    /** Luminance component. */
    OHOS_IMAGE_COMPONENT_FORMAT_YUV_Y = 1,
    /** Chrominance component - blue projection. */
    OHOS_IMAGE_COMPONENT_FORMAT_YUV_U = 2,
    /** Chrominance component - red projection. */
    OHOS_IMAGE_COMPONENT_FORMAT_YUV_V = 3,
    /** JPEG format. */
    OHOS_IMAGE_COMPONENT_FORMAT_JPEG = 4,
};

typedef OH_Image_String OH_Image_Property, OH_Image_MimeType;

#ifdef __cplusplus
};
#endif
/** @} */

#endif // INTERFACES_KITS_NATIVE_INCLUDE_IMAGE_IMAGE_COMMON_H