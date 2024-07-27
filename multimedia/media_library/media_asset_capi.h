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
 * @addtogroup OH_MediaAsset
 * @{
 *
 * @brief Provides APIs for encapsulating file asset attributes.
 *
 * @since 12
 */

#ifndef MEDIA_ASSET_CAPI_H
#define MEDIA_ASSET_CAPI_H

#include "media_asset_base_capi.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Get the Uri of the media asset
 *
 * @param mediaAsset Pointer to an OH_MediaAsset instance.
 * @param uri The uri of the requested media asset
 * @param size Size of the requested media asset URI
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@LINK #MEDIA_LIBRARY_PARAMETER_ERROR} if mandatory parameters are left unspecified or incorrect parameter 
 *         types or parameter verification failed.
 *         {@LINK #MEDIA_LIBRARY_INVALID_ARGUMENT} if argument is invalid.
 *         {@LINK #MEDIA_lIBRARY_INVALID_PHOTO_KEY} if member is not a valid PhotoKey
 * @since 12
*/
MediaLibrary_ErrorCode OH_MediaAsset_GetUri(OH_MediaAsset* mediaAsset, const char** uri);

/**
 * @brief Get the media file type of the media asset
 *
 * @param mediaAsset Pointer to an OH_MediaAsset instance.
 * @param mediaType The media file type of the requested media asset
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@LINK #MEDIA_LIBRARY_PARAMETER_ERROR} if mandatory parameters are left unspecified or incorrect parameter 
 *         types or parameter verification failed.
 *         {@LINK #MEDIA_LIBRARY_INVALID_ARGUMENT} if argument is invalid.
 *         {@LINK #MEDIA_lIBRARY_INVALID_PHOTO_KEY} if member is not a valid PhotoKey
 * @since 12
*/
MediaLibrary_ErrorCode OH_MediaAsset_GetMediaType(OH_MediaAsset* mediaAsset, MediaLibrary_MediaType* mediaType);

/**
 * @brief Get the media asset type of the media asset
 *
 * @param mediaAsset Pointer to an OH_MediaAsset instance.
 * @param mediaSubType The media asset type of the requested media asset
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@LINK #MEDIA_LIBRARY_PARAMETER_ERROR} if mandatory parameters are left unspecified or incorrect parameter 
 *         types or parameter verification failed.
 *         {@LINK #MEDIA_LIBRARY_INVALID_ARGUMENT} if argument is invalid.
 *         {@LINK #MEDIA_lIBRARY_INVALID_PHOTO_KEY} if member is not a valid PhotoKey
 * @since 12
*/
MediaLibrary_ErrorCode OH_MediaAsset_GetMediaSubType(OH_MediaAsset* mediaAsset, 
                                                        MediaLibrary_MediaSubType* mediaSubType);

/**
 * @brief Get the display name of the media asset
 *
 * @param mediaAsset Pointer to an OH_MediaAsset instance.
 * @param displayName The display name of the requested media asset
 * @param size The size of display name of the requested media asset
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@LINK #MEDIA_LIBRARY_PARAMETER_ERROR} if mandatory parameters are left unspecified or incorrect parameter 
 *         types or parameter verification failed.
 *         {@LINK #MEDIA_LIBRARY_INVALID_ARGUMENT} if argument is invalid.
 *         {@LINK #MEDIA_lIBRARY_INVALID_PHOTO_KEY} if member is not a valid PhotoKey
 * @since 12
*/
MediaLibrary_ErrorCode OH_MediaAsset_GetDisplayName(OH_MediaAsset* mediaAsset, const char** displayName);

/**
 * @brief Get the file size of the media asset
 *
 * @param mediaAsset Pointer to an OH_MediaAsset instance.
 * @param size The file size(in bytes) of the requested media asset.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@LINK #MEDIA_LIBRARY_PARAMETER_ERROR} if mandatory parameters are left unspecified or incorrect parameter 
 *         types or parameter verification failed.
 *         {@LINK #MEDIA_LIBRARY_INVALID_ARGUMENT} if argument is invalid.
 *         {@LINK #MEDIA_lIBRARY_INVALID_PHOTO_KEY} if member is not a valid PhotoKey
 * @since 12
*/
MediaLibrary_ErrorCode OH_MediaAsset_GetSize(OH_MediaAsset* mediaAsset, uint32_t* size);

/**
 * @brief Get the date of the media asset when the file was added 
 *
 * @param mediaAsset Pointer to an OH_MediaAsset instance.
 * @param dataAdded Date when the file was added. 
 *        The value is the number of seconds elapsed since the Epoch time (00:00:00 UTC on January 1, 1970).
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@LINK #MEDIA_LIBRARY_PARAMETER_ERROR} if mandatory parameters are left unspecified or incorrect parameter 
 *         types or parameter verification failed.
 *         {@LINK #MEDIA_LIBRARY_INVALID_ARGUMENT} if argument is invalid.
 *         {@LINK #MEDIA_lIBRARY_INVALID_PHOTO_KEY} if member is not a valid PhotoKey
 * @since 12
*/
MediaLibrary_ErrorCode OH_MediaAsset_GetDateAdded(OH_MediaAsset* mediaAsset, uint32_t* dataAdded);

/**
 * @brief Get the date of the media asset when the file content was last modified. 
 * 
 * @param mediaAsset Pointer to an OH_MediaAsset instance.
 * @param dataModified Date when the file content (not the file name) was last modified. 
 *        The value is the number of seconds elapsed since the Epoch time.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@LINK #MEDIA_LIBRARY_PARAMETER_ERROR} if mandatory parameters are left unspecified or incorrect parameter 
 *         types or parameter verification failed.
 *         {@LINK #MEDIA_LIBRARY_INVALID_ARGUMENT} if argument is invalid.
 *         {@LINK #MEDIA_lIBRARY_INVALID_PHOTO_KEY} if member is not a valid PhotoKey
 * @since 12
*/
MediaLibrary_ErrorCode OH_MediaAsset_GetDateModified(OH_MediaAsset* mediaAsset, uint32_t* dataModified);

/**
 * @brief Get the date of the media asset when the file (photo) was taken.
 * 
 * @param mediaAsset Pointer to an OH_MediaAsset instance.
 * @param dataTaken Date when the file (photo) was taken. 
 *        The value is the number of seconds elapsed since the Epoch time.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@LINK #MEDIA_LIBRARY_PARAMETER_ERROR} if mandatory parameters are left unspecified or incorrect parameter 
 *         types or parameter verification failed.
 *         {@LINK #MEDIA_LIBRARY_INVALID_ARGUMENT} if argument is invalid.
 *         {@LINK #MEDIA_lIBRARY_INVALID_PHOTO_KEY} if member is not a valid PhotoKey
 * @since 12
*/
MediaLibrary_ErrorCode OH_MediaAsset_GetDataTaken(OH_MediaAsset* mediaAsset, uint32_t* dataTaken); 

/**
 * @brief Get the date of the media asset when the file was added.
 *
 * @param mediaAsset Pointer to an OH_MediaAsset instance.
 * @param dateAddedMs Date when the file was added. The value is the number of milliseconds elapsed since the Epoch 
 *        time (00:00:00 UTC on January 1, 1970).NOTE: The photos queried cannot be sorted based on this field.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@LINK #MEDIA_LIBRARY_PARAMETER_ERROR} if mandatory parameters are left unspecified or incorrect parameter 
 *         types or parameter verification failed.
 *         {@LINK #MEDIA_LIBRARY_INVALID_ARGUMENT} if argument is invalid.
 *         {@LINK #MEDIA_lIBRARY_INVALID_PHOTO_KEY} if member is not a valid PhotoKey
 * @since 12
*/
MediaLibrary_ErrorCode OH_MediaAsset_GetDateAddedMs(OH_MediaAsset* mediaAsset, uint32_t* dateAddedMs);

/**
 * @brief Get the date of the media asset when the file content was last modified. 
 * 
 * @param mediaAsset Pointer to an OH_MediaAsset instance.
 * @param dateModifiedMs Date when the album file content (not the album name) was last modified. The value is the 
 * number of milliseconds elapsed since the Epoch time.NOTE: The photos queried cannot be sorted based on this field.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@LINK #MEDIA_LIBRARY_PARAMETER_ERROR} if mandatory parameters are left unspecified or incorrect parameter 
 *         types or parameter verification failed.
 *         {@LINK #MEDIA_LIBRARY_INVALID_ARGUMENT} if argument is invalid.
 *         {@LINK #MEDIA_lIBRARY_INVALID_PHOTO_KEY} if member is not a valid PhotoKey
 * @since 12
*/
MediaLibrary_ErrorCode OH_MediaAsset_GetDateModifiedMs(OH_MediaAsset* mediaAsset, uint32_t* dateModifiedMs);

/**
 * @brief Get the duration(in ms) of the media asset.
 *
 * @param mediaAsset Pointer to an OH_MediaAsset instance.
 * @param duration The duration(in ms) of the requested media asset.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@LINK #MEDIA_LIBRARY_PARAMETER_ERROR} if mandatory parameters are left unspecified or incorrect parameter 
 *         types or parameter verification failed.
 *         {@LINK #MEDIA_LIBRARY_INVALID_ARGUMENT} if argument is invalid.
 *         {@LINK #MEDIA_lIBRARY_INVALID_PHOTO_KEY} if member is not a valid PhotoKey
 * @since 12
*/
MediaLibrary_ErrorCode OH_MediaAsset_GetDuration(OH_MediaAsset* mediaAsset, uint32_t* duration);

/**
 * @brief Get the image width(in pixels) of the media asset.
 *
 * @param mediaAsset Pointer to an OH_MediaAsset instance.
 * @param width The image width(in pixels) of the requested media asset.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@LINK #MEDIA_LIBRARY_PARAMETER_ERROR} if mandatory parameters are left unspecified or incorrect parameter 
 *         types or parameter verification failed.
 *         {@LINK #MEDIA_LIBRARY_INVALID_ARGUMENT} if argument is invalid.
 *         {@LINK #MEDIA_lIBRARY_INVALID_PHOTO_KEY} if member is not a valid PhotoKey
 * @since 12
*/
MediaLibrary_ErrorCode OH_MediaAsset_GetWidth(OH_MediaAsset* mediaAsset, uint32_t* width);

/**
 * @brief Get the image height(in pixels) of the media asset.
 *
 * @param mediaAsset Pointer to an OH_MediaAsset instance.
 * @param width The image height(in pixels) of the requested media asset.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@LINK #MEDIA_LIBRARY_PARAMETER_ERROR} if mandatory parameters are left unspecified or incorrect parameter 
 *         types or parameter verification failed.
 *         {@LINK #MEDIA_LIBRARY_INVALID_ARGUMENT} if argument is invalid.
 *         {@LINK #MEDIA_lIBRARY_INVALID_PHOTO_KEY} if member is not a valid PhotoKey
 * @since 12
*/
MediaLibrary_ErrorCode OH_MediaAsset_GetHeight(OH_MediaAsset* mediaAsset, uint32_t* height);

/**
 * @brief Get the Orientation of the image file.
 *
 * @param mediaAsset Pointer to an OH_MediaAsset instance.
 * @param orientation The Orientation of the requested media asset.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@LINK #MEDIA_LIBRARY_PARAMETER_ERROR} if mandatory parameters are left unspecified or incorrect parameter 
 *         types or parameter verification failed.
 *         {@LINK #MEDIA_LIBRARY_INVALID_ARGUMENT} if argument is invalid.
 *         {@LINK #MEDIA_lIBRARY_INVALID_PHOTO_KEY} if member is not a valid PhotoKey
 * @since 12
*/
MediaLibrary_ErrorCode OH_MediaAsset_GetOrientation(OH_MediaAsset* mediaAsset, uint32_t* orientation);

/**
 * @brief Whether the file is added to favorites.
 *
 * @param mediaAsset Pointer to an OH_MediaAsset instance.
 * @param favorite The favorite of the requested media asset.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@LINK #MEDIA_LIBRARY_PARAMETER_ERROR} if mandatory parameters are left unspecified or incorrect parameter 
 *         types or parameter verification failed.
 *         {@LINK #MEDIA_LIBRARY_INVALID_ARGUMENT} if argument is invalid.
 *         {@LINK #MEDIA_lIBRARY_INVALID_PHOTO_KEY} if member is not a valid PhotoKey
 * @since 12
*/
MediaLibrary_ErrorCode OH_MediaAsset_isFavorite(OH_MediaAsset* mediaAsset, uint32_t* favorite);

/**
 * @brief Get the title in the media file.
 *
 * @param mediaAsset Pointer to an OH_MediaAsset instance.
 * @param title The title of the requested media asset.
 * @param size The size of the title of the requested media asset.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@LINK #MEDIA_LIBRARY_PARAMETER_ERROR} if mandatory parameters are left unspecified or incorrect parameter 
 *         types or parameter verification failed.
 *         {@LINK #MEDIA_LIBRARY_INVALID_ARGUMENT} if argument is invalid.
 *         {@LINK #MEDIA_lIBRARY_INVALID_PHOTO_KEY} if member is not a valid PhotoKey
 * @since 12
*/
MediaLibrary_ErrorCode OH_MediaAsset_GetTitle(OH_MediaAsset* mediaAsset, const char** title);

/**
 * @brief Release the media asset
 *
 * @param mediaAsset Pointer to an OH_MediaAsset instance.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@LINK #MEDIA_LIBRARY_INVALID_ARGUMENT} if argument is invalid.
 * @since 12
*/
MediaLibrary_ErrorCode OH_MediaAsset_Release(OH_MediaAsset* mediaAsset);

#ifdef __cplusplus
}
#endif

#endif