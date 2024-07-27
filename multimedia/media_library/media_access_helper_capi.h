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
 * @addtogroup OH_MediaAccessHelper
 * @{
 *
 * @brief Provides APIs for album management, including creating an album and accessing and 
 *     modifying media data in an album.
 *
 * @since 12
 */

#ifndef MULTIMEDIA_MEDIA_LIBRARY_NATIVE_MEDIA_ACCESS_HELPER_H
#define MULTIMEDIA_MEDIA_LIBRARY_NATIVE_MEDIA_ACCESS_HELPER_H

#include "media_asset_base_capi.h"

/**
 * @brief Apply the change request of asset or album.
 *
 * @param changeRequest The change request to be applied
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@LINK #MEDIA_LIBRARY_PARAMETER_ERROR} if mandatory parameters are left unspecified or incorrect parameter 
 *         types or parameter verification failed.
 *         {@LINK #MEDIA_LIBRARY_PERMISSION_DENIED} if permission is denied.
 *         {@LINK #MEDIA_LIBRARY_SYSTEM_INNER_FAIL} if system inner fail.
 * @since 12    
*/
MediaLibrary_ErrorCode OH_MediaAccessHelper_ApplyChanges(OH_MediaAssetChangeRequest* changeRequest);


#endif // MULTIMEDIA_MEDIA_LIBRARY_NATIVE_MEDIA_ACCESS_HELPER_H