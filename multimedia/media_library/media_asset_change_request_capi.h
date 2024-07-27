#ifndef MEDIA_ASSET_CHANGE_REQUEST_H
#define MEDIA_ASSET_CHANGE_REQUEST_H
#include "media_asset_base_capi.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Create a MediaAssetChangeRequest instance.
 *
 * @param mediaAsset Pointer to an OH_MediaAsset instance.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@LINK #MEDIA_LIBRARY_PARAMETER_ERROR} if mandatory parameters are left unspecified or incorrect parameter 
 *         types or parameter verification failed.
 *         {@LINK #MEDIA_LIBRARY_SYSTEM_INNER_FAIL} if system inner fail.
 * @since 12
*/
OH_MediaAssetChangeRequest* OH_MediaAssetChangeRequest_Create(OH_MediaAsset* mediaAsset);

/**
 * @brief Add resource of the asset using file uri.
 * 
 * @param changeRequest Pointer to an OH_MediaAssetChangeRequest instance.
 * @param resourceType Type of the resource to add.
 * @param fileUri Data source of the resource to be added, 
 *        which is specified by a URI in the application sandbox directory.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@LINK #MEDIA_LIBRARY_PARAMETER_ERROR} if mandatory parameters are left unspecified or incorrect parameter 
 *         types or parameter verification failed.
 *         {@LINK #MEDIA_LIBRARY_NO_SUCH_FILE} if file does not exist 
 *         {@LINK #MEDIA_LIBRARY_SYSTEM_INNER_FAIL} if system inner fail.
 *         {@LINK #MEDIA_LIBRARY_OPERATION_NOT_SUPPORT} if operation is not supported.
 * @since 12
*/
MediaLibrary_ErrorCode  OH_MediaAssetChangeRequest_AddResourceWithUri(OH_MediaAssetChangeRequest* changeRequest,
    MediaLibrary_ResourceType resourceType, char* fileUri);

/**
 * @brief Add resource of the asset using ArrayBuffer.
 * 
 * @param changeRequest Pointer to an OH_MediaAssetChangeRequest instance.
 * @param resourceType Type of the resource to add.
 * @param buffer Data of the resource to add.
 * @param length The data length of the resource to add.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@LINK #MEDIA_LIBRARY_PARAMETER_ERROR} if mandatory parameters are left unspecified or incorrect parameter 
 *         types or parameter verification failed.
 *         {@LINK #MEDIA_LIBRARY_SYSTEM_INNER_FAIL} if system inner fail.
 *         {@LINK #MEDIA_LIBRARY_OPERATION_NOT_SUPPORT} if operation is not supported.
 * @since 12
*/
MediaLibrary_ErrorCode OH_MediaAssetChangeRequest_AddResourceWithBuffer(OH_MediaAssetChangeRequest* changeRequest,
    MediaLibrary_ResourceType resourceType, uint8_t* buffer, uint32_t length);

/**
 * @brief Get write cache handler.
 * 
 * @param changeRequest Pointer to an OH_MediaAssetChangeRequest instance.
 * @param Fd Write handle of a temporary file.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@LINK #MEDIA_LIBRARY_PARAMETER_ERROR} if mandatory parameters are left unspecified or incorrect parameter 
 *         types or parameter verification failed.
 *         {@LINK #MEDIA_LIBRARY_SYSTEM_INNER_FAIL} if system inner fail.
 *         {@LINK #MEDIA_LIBRARY_PERMISSION_DENIED} if permission is denied.
 *         {@LINK #MEDIA_LIBRARY_OPERATION_NOT_SUPPORT} if operation is not supported.
 * @since 12
*/
MediaLibrary_ErrorCode OH_Media_AssetChangeRequest_GetWriteCacheHandler(OH_MediaAssetChangeRequest* changeRequest,
    int32_t* Fd);

/**
 * @brief Save the photo asset captured by camera.
 * 
 * @param changeRequest Pointer to an OH_MediaAssetChangeRequest instance.
 * @param imageFileType The mage file type of photo asset.
 * @return {@LINK #MEDIA_LIBRARY_SYSTEM_INNER_FAIL} if system inner fail.
 *         {@LINK #MEDIA_LIBRARY_OPERATION_NOT_SUPPORT} if operation is not supported.
 * @since 12
*/
MediaLibrary_ErrorCode OH_Media_AssetChangeRequest_SaveCameraPhoto(OH_MediaAssetChangeRequest* changeRequest,
    MediaLibrary_ImageFileType imageFileType);

/**
 * @brief Discard the photo asset captured by camera.
 * 
 * @param changeRequest Pointer to an OH_MediaAssetChangeRequest instance.
 * @return {@LINK #MEDIA_LIBRARY_SYSTEM_INNER_FAIL} if system inner fail.
 *         {@LINK #MEDIA_LIBRARY_OPERATION_NOT_SUPPORT} if operation is not supported.
 * @since 12
*/
MediaLibrary_ErrorCode OH_MediaAssetChangeRequest_DiscardCameraPhoto(OH_MediaAssetChangeRequest* changeRequest);

/**
 * @brief Release the OH_MediaAssetChangeRequest object.
 *
 * @param changeRequest Pointer to an OH_MediaAssetManager instance.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@LINK #MEDIA_LIBRARY_INVALID_ARGUMENT} if argument is invalid.
 * @since 12
*/
MediaLibrary_ErrorCode OH_MediaAssetChangeRequest_Release(OH_MediaAssetChangeRequest* changeRequest);
#ifdef __cplusplus
}
#endif
#endif
