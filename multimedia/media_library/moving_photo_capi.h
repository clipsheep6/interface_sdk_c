#ifndef MOVING_PHOTO_CAPI_H
#define MOVING_PHOTO_CAPI_H 
#include "media_asset_base_capi.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Get uri of the moving photo.
 *
 * @param movingPhoto Pointer to an OH_MovingPhoto instance.
 * @param resourceType Resource type of the moving photo content to request.
 * @param uri URI of the moving photo obtained.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@LINK #MEDIA_LIBRARY_PARAMETER_ERROR} if mandatory parameters are left unspecified or incorrect parameter 
 *         types or parameter verification failed.
 *         {@LINK #MEDIA_LIBRARY_SYSTEM_INNER_FAIL} if system inner fail.
 * @since 12
*/
MediaLibrary_ErrorCode OH_MovingPhoto_GetUri(OH_MovingPhoto* movingPhoto, MediaLibrary_ResourceType resourceType,
    const char** uri);

/**
 * @brief Request the image and video content of the moving photo and write to destination uri.
 *
 * @param movingPhoto Pointer to an OH_MovingPhoto instance.
 * @param imageUri URI to which the image data of the moving photo is to be written.
 * @param videoUri URI to which the video data of the moving photo is to be written.
 * @param callback Called when a requested source is prepared.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@LINK #MEDIA_LIBRARY_PARAMETER_ERROR} if mandatory parameters are left unspecified or incorrect parameter 
 *         types or parameter verification failed.
 *         {@LINK #MEDIA_LIBRARY_PERMISSION_DENIED} if permission is denied.
 *         {@LINK #MEDIA_LIBRARY_SYSTEM_INNER_FAIL} if system inner fail.
 * @since 12
*/
MediaLibrary_ErrorCode OH_MovingPhoto_RequestContentWithUris(OH_MovingPhoto* movingPhoto, char* imageUri, char* videoUri,
    OH_MediaLibrary_OnDataPrepared callback);

/**
 * @brief Request the image and video content of the moving photo and write to destination uri.
 *
 * @param movingPhoto Pointer to an OH_MovingPhoto instance.
 * @param resourceType Resource type of the moving photo content to request.
 * @param uri URI to which the moving photo content is to be written.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@LINK #MEDIA_LIBRARY_PARAMETER_ERROR} if mandatory parameters are left unspecified or incorrect parameter 
 *         types or parameter verification failed.
 *         {@LINK #MEDIA_LIBRARY_PERMISSION_DENIED} if permission is denied.
 *         {@LINK #MEDIA_LIBRARY_SYSTEM_INNER_FAIL} if system inner fail.
 * @since 12
*/
MediaLibrary_ErrorCode OH_MovingPhoto_RequestContentWithUri(OH_MovingPhoto* movingPhoto,
    MediaLibrary_ResourceType resourceType, char* uri);

/**
 * @brief Request content of the moving photo for the given resource type and return the array buffer.
 *
 * @param movingPhoto Pointer to an OH_MovingPhoto instance.
 * @param resourceType Resource type of the moving photo content to request.
 * @param buffer Array buffer of the content.
 * @param size The size of array buffer.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@LINK #MEDIA_LIBRARY_PARAMETER_ERROR} if mandatory parameters are left unspecified or incorrect parameter 
 *         types or parameter verification failed.
 *         {@LINK #MEDIA_LIBRARY_PERMISSION_DENIED} if permission is denied.
 *         {@LINK #MEDIA_LIBRARY_SYSTEM_INNER_FAIL} if system inner fail.
 * @since 12
*/
MediaLibrary_ErrorCode OH_MovingPhoto_RequestContentWithBuffer(OH_MovingPhoto* movingPhoto,
    MediaLibrary_ResourceType resourceType, const uint8_t** buffer, uint32_t* size);

/**
 * @brief Release the moving photo object.
 *
 * @param movingPhoto Pointer to an OH_MovingPhoto instance.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@LINK #MEDIA_LIBRARY_PARAMETER_ERROR} if mandatory parameters are left unspecified or incorrect parameter 
 *         types or parameter verification failed.
 *         {@LINK #MEDIA_LIBRARY_PERMISSION_DENIED} if permission is denied.
 *         {@LINK #MEDIA_LIBRARY_SYSTEM_INNER_FAIL} if system inner fail.
 * @since 12
*/
MediaLibrary_ErrorCode OH_MovingPhoto_Release(OH_MovingPhoto* movingPhoto);
#ifdef __cplusplus
}
#endif

#endif