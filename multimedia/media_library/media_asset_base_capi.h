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
 * @addtogroup MediaAssetManager
 * @{
 *
 * @brief Provides APIs of request capability for Media Source.
 *
 * The OH_MediaAssetManager structure and MediaLibrary_RequestId type are used to request media library resources.
 * The request can be cancelled using the request ID.
 *
 * @since 12
 */

/**
 * @file media_asset_manager.h
 *
 * @brief Defines the structure and enumeration for Media Asset Manager.
 *
 * OH_MediaAssetManager structure: This structure provides the ability to request resources from a media library. \n
 * MediaLibrary_RequestId type: This type is returned when requesting a media library resource.
 * The request ID is used to cancel the request. \n
 * MediaLibrary_DeliveryMode enumeration: This enumeration defines the delivery mode of the requested resources. \n
 * OH_MediaLibrary_OnDataPrepared function pointer: This function is called when the requested source is prepared. \n
 * MediaLibrary_RequestOptions structure: This structure provides options for requesting media library resources. \n
 *
 * @kit MediaLibraryKit
 * @Syscap SystemCapability.FileManagement.PhotoAccessHelper.Core
 * @library libmedia_asset_manager.so
 * @since 12
 */

#ifndef MULTIMEDIA_MEDIA_LIBRARY_NATIVE_MEDIA_ASSET_BASE_H
#define MULTIMEDIA_MEDIA_LIBRARY_NATIVE_MEDIA_ASSET_BASE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Define UUID max length
 *
 * This constant defines the maximum length of a UUID string.
 *
 * @since 12
 */
static const int32_t UUID_STR_MAX_LENGTH = 37;

/**
 * @brief Define Media Asset Manager
 *
 * This structure provides the ability to request media library resources.
 * Null pointer is returned if the creation fails.
 *
 * @since 12
 */
typedef struct OH_MediaAssetManager OH_MediaAssetManager;

/**
 * @brief Define Media Asset Change Request 
 *
 * This structure provides the ability to handle a media asset change request.
 * Null pointer is returned if the creation fails.
 *
 * @since 12
 */
typedef struct OH_MediaAssetChangeRequest OH_MediaAssetChangeRequest;

/**
 * @brief Define Moving Photo
 *
 * Request the image and video content of the moving photo and write to destination uri.
 * Null pointer is returned if the creation fails.
 *
 * @since 12
 */
typedef struct OH_MovingPhoto OH_MovingPhoto;

/**
 * @brief Define Media Access Helper
 *
 * The photoAccessHelper module provides APIs for album management, 
 * including creating an album and accessing and modifying media data in an album.
 * Null pointer is returned if the creation fails.
 *
 * @since 12
 */
typedef struct OH_MediaAccessHelper OH_MediaAccessHelper;

/**
 * @brief Define Media Asset
 *
 * This structure provides the ability to encapsulate file asset attributes.
 * 
 * @since 12
 */
typedef struct OH_MediaAsset OH_MediaAsset;

/**
 * @brief Enum for mediaLibrary error code.
 *
 * @since 12
 */
typedef enum MediaLibrary_ErrorCode {
    /**
     * Media library result is ok.
     */
    MEDIA_LIBRARY_OK = 0,

    /**
     * Permission is denied.
     */
    MEDIA_LIBRARY_PERMISSION_DENIED = 201,

    /**
     * Mandatory parameters are left unspecified or incorrect parameter types or parameter verification failed.
     */
    MEDIA_LIBRARY_PARAMETER_ERROR = 401,

    /**
     * File does not exist.
     */
    MEDIA_LIBRARY_NO_SUCH_FILE = 13900002,

    /**
     * File operation has no permission.
     */
    MEDIA_LIBRARY_NO_PERMISSION = 13900012,

    /**
     * Argument is invalid.
     */
    MEDIA_LIBRARY_INVALID_ARGUMENT = 13900020,

    /**
     * Unkown error.
     */
    MEDIA_LIBRARY_UNKNOWN_ERROR = 13900042,

    /**
     * Invalid display name.
     */
    MEDIA_LIBRARY_INVALID_DISPLAY_NAME = 14000001,

    /**
     * Invalid asset uri.
     */
    MEDIA_LIBRARY_INVALID_ASSET_URI = 14000002,

    /**
     * System inner fail.
     */
    MEDIA_LIBRARY_SYSTEM_INNER_FAIL = 14000011,

    /**
     * Member is not a valid PhotoKey.
     */
    MEDIA_LIBRARY_INVALID_PHOTO_KEY = 14000014,

    /**
     * Operation is not supported.
     */
    MEDIA_LIBRARY_OPERATION_NOT_SUPPORT = 14000016
} MediaLibrary_ErrorCode;

/**
 * @brief Define MediaLibrary_RequestId
 *
 * This type is returned when requesting a media library resource.
 * The request id is used to cancel the request.
 * The value is all zero like "00000000-0000-0000-0000-000000000000" if the request fails.
 *
 * @since 12
 */
typedef struct MediaLibrary_RequestId {
    /*request id*/
    char requestId[UUID_STR_MAX_LENGTH];
} MediaLibrary_RequestId;

/**
 * @brief Delivery Mode
 *
 * This enumeration defines the delivery mode of the requested resources.
 * The delivery mode can be set to fast mode, high quality mode, or balanced mode.
 *
 * @since 12
 */
typedef enum MediaLibrary_DeliveryMode {
    /*delivery fast mode*/
    MEDIA_LIBRARY_FAST_MODE = 0,
    /*delivery high quality mode*/
    MEDIA_LIBRARY_HIGH_QUALITY_MODE = 1,
    /*delivery balanced mode*/
    MEDIA_LIBRARY_BALANCED_MODE = 2
} MediaLibrary_DeliveryMode;

typedef enum MediaLibrary_MediaType {
    /*image asset*/
    MEDIA_LIBRARY_IMAGE = 1,
    /*video asset*/
    MEDIA_lIBRARY_VIDEO = 2
}MediaLibrary_MediaType;

typedef enum MediaLibrary_MediaSubType {
    /*default Photo Type*/
    MEDIA_LIBRARY_DEFAULT = 0,
    /*moving Photo Type*/
    MEDIA_LIBRARY_MOVING_PHOTO = 3, 
    /*burst Photo Type*/
    MEDIA_LIBRARY_BURST = 4,
}MediaLibrary_MediaSubType;

typedef enum MediaLibrary_ResourceType {
    /*image resource*/
    MEDIA_LIBRARY_IMAGE_RESOURCE = 1,
    /*video resource*/
    MEDIA_LIBRARY_VIDEO_RESOURCE = 2
}MediaLibrary_ResourceType;

typedef enum MediaLibrary_ImageFileType {
    /*JPEG type*/
    MEDIA_LIBRARY_IMAGE_JPEG = 1
}MediaLibrary_ImageFileType;

/**
 * @brief Called when a requested source is prepared.
 *
 * This function is called when the requested source is prepared.
 *
 * @param result Results of the processing of the requested resources.
 * @param requestId Request ID.
 * @since 12
 */
typedef void (*OH_MediaLibrary_OnDataPrepared)(int32_t result, MediaLibrary_RequestId requestId);

typedef enum MediaLibrary_MediaQuality {
    /*fast quality*/
    MEDIA_LIBRARY_FAST_QUALITY = 1,
    /*high quality*/
    MEDIA_LIBRARY_HIGH_QUALITY = 2
}MediaLibrary_MediaQuality;

typedef enum MediaLibrary_MediaContentType {
    /*compressed media content type*/
    MEDIA_LIBRARY_COMPRESSED = 1,
    /*picture object media content type*/
    MEDIA_LIBRARY_PICTURE_OBJECT = 2 //YUV
}MediaLibrary_MediaContentType;

/**
 * @brief Request Options
 *
 * This structure provides options for requesting media library resources.
 *
 * @since 12
 */
typedef struct MediaLibrary_RequestOptions {
    /*delivery mode*/
    MediaLibrary_DeliveryMode deliveryMode;
} MediaLibrary_RequestOptions;

/**
 * @brief Called when a requested source is prepared.
 *
 * This function is called when the requested source is prepared.
 *
 * @param result Results of the processing of the requested resources.
 * @param requestId Request ID.
 * @param mediaQuality media quality.
 * @param type media content type.
 * @since 12
 */
typedef void (*OH_MediaLibrary_OnDataPreparedWithDetails)(MediaLibrary_ErrorCode result,
    MediaLibrary_RequestId requestId, MediaLibrary_MediaQuality mediaQuality, MediaLibrary_MediaContentType type);

#ifdef __cplusplus
}
#endif
#endif // MULTIMEDIA_MEDIA_LIBRARY_NATIVE_MEDIA_ASSET_BASE_H