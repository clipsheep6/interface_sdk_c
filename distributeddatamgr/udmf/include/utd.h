/*
 * Copyright (c) 2024 Huawei Device Co., Ltd.
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

#ifndef UTD_H
#define UTD_H

/**
 * @addtogroup udmf_ndk
 * @{
 *
 * @brief The Unified Data Management Framework(UDMF) aims to define various standards
 * for data across applications, devices, and platforms, providing a unified OpenHarmony
 * data language and standardized data access and reading paths.
 *
 * @syscap SystemCapability.DistributedDataManager.UDMF.Core
 * @since 12
 */

  /**
 * @file utd.h
 *
 * @brief Provides uniform type descriptor related functions and struct.
 *
 * @since 12
 */


#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Describes the unified data type descriptor.
 *
 * @since 12
 */
typedef struct OH_Utd_TypeDescriptor OH_Utd_TypeDescriptor;

/**
 * @brief prouct a pointer to the instance of the {@link OH_Utd_TypeDescriptor}.
 *
 * @param data Represents type of UTD, reference udmf_meta.h.
 * @return If the operation is successful, a pointer to the instance of the {@link OH_Utd_TypeDescriptor} structure is returned.
 *         If the operation is failed, nullptr is returned.
 *         Must be destroyed with {@link OH_Utd_DestroyTypeDescriptor} when not needed.
 * @see OH_Utd_TypeDescriptor.
 * @since 12
 */
OH_Utd_TypeDescriptor* OH_Utd_GetTypeDescriptor(const char* typeId);

/**
 * @brief destroy a pointer that points to the {@link OH_Utd_TypeDescriptor} instance.
 *
 * @param desc Represents a pointer to an {@link OH_Utd_TypeDescriptor} instance.
 * @see OH_Utd_TypeDescriptor.
 * @since 12
 */
void OH_Utd_DestroyTypeDescriptor(OH_Utd_TypeDescriptor* desc);

/**
 * @brief get type id from the {@link OH_Utd_TypeDescriptor}.
 *
 * @param desc Represents a pointer to an {@link OH_Utd_TypeDescriptor} instance.
 * @return returns a pointer of the tag value string when input args normally, otherwise return nullptr.
 * @see OH_Utd_TypeDescriptor.
 * @since 12
 */
const char* OH_Utd_GetTypeId(OH_Utd_TypeDescriptor* desc);

/**
 * @brief get description from the {@link OH_Utd_TypeDescriptor}.
 *
 * @param desc Represents a pointer to an {@link OH_Utd_TypeDescriptor} instance.
 * @return returns a pointer of the tag value string when input args normally, otherwise return nullptr.
 * @see OH_Utd_TypeDescriptor.
 * @since 12
 */
const char* OH_Utd_GetDescription(OH_Utd_TypeDescriptor* desc);

/**
 * @brief get url from the {@link OH_Utd_TypeDescriptor}.
 *
 * @param desc Represents a pointer to an {@link OH_Utd_TypeDescriptor} instance.
 * @return returns a pointer of the tag value string when input args normally, otherwise return nullptr.
 * @see OH_Utd_TypeDescriptor.
 * @since 12
 */
const char* OH_Utd_GetReferenceURL(OH_Utd_TypeDescriptor* desc);

/**
 * @brief get icon file from the {@link OH_Utd_TypeDescriptor}.
 *
 * @param desc Represents a pointer to an {@link OH_Utd_TypeDescriptor} instance.
 * @return returns a pointer of the tag value string when input args normally, otherwise return nullptr.
 * @see OH_Utd_TypeDescriptor.
 * @since 12
 */
const char* OH_Utd_GetIconFile(OH_Utd_TypeDescriptor* desc);

/**
 * @brief get belong to type id of the current {@link OH_Utd_TypeDescriptor}.
 *
 * @param desc Represents a pointer to an {@link OH_Utd_TypeDescriptor} instance.
 * @param count Represents the types count.
 * @return returns string array when input args normally, otherwise return nullptr.
 * @see OH_Utd_TypeDescriptor.
 * @since 12
 */
const char** OH_Utd_GetBelongingToTypes(OH_Utd_TypeDescriptor* desc, int* count);

/**
 * @brief get filename extensions of the current {@link OH_Utd_TypeDescriptor}.
 *
 * @param desc Represents a pointer to an {@link OH_Utd_TypeDescriptor} instance.
 * @param count Represents the types count.
 * @return returns string array when input args normally, otherwise return nullptr.
 * @see OH_Utd_TypeDescriptor.
 * @since 12
 */
const char** OH_Utd_GetFilenameExtensions(OH_Utd_TypeDescriptor* desc, int* count);

/**
 * @brief get mime types of the current {@link OH_Utd_TypeDescriptor}.
 *
 * @param desc Represents a pointer to an {@link OH_Utd_TypeDescriptor} instance.
 * @param count Represents the types count.
 * @return returns string array when input args normally, otherwise return nullptr.
 * @see OH_Utd_TypeDescriptor.
 * @since 12
 */
const char** OH_Utd_GetMimeTypes(OH_Utd_TypeDescriptor* desc, int* count);


/**
 * @brief get type id by file name extension.
 *
 * @param extension Represents file name extension.
 * @param count Represents the types count.
 * @return returns string list of types. Must be destroyed with {@link OH_Utd_DestroyStringList} when not needed.
 * @since 12
 */
const char** OH_Utd_GetUniformDataTypeByFilenameExtension(const char* extension, unsigned int* count);

/**
 * @brief get type id by mime type.
 *
 * @param mimeType Represents mime type
 * @param count Represents the types count.
 * @return returns string list of types. Must be destroyed with {@link OH_Utd_DestroyStringList} when not needed.
 * @since 12
 */
const char** OH_Utd_GetUniformDataTypeByMimeType(const char* mimeType, unsigned int* count);

/**
 * @brief calculate relationships of two types.
 *
 * @param srcTypeId Represents source type id.
 * @param destTypeId Represents target type id.
 * @return 0 - Represents srcTypeId not belongs to destTypeId.
        1 - Represents srcTypeId belongs to destTypeId.
 * @since 12
 */
int OH_Utd_IsBelongsTo(const char* srcTypeId, const char* destTypeId);

/**
 * @brief calculate relationships of two types.
 *
 * @param srcTypeId Represents source type id.
 * @param destTypeId Represents target type id.
 * @return 0 - Represents srcTypeId not lower level to destTypeId.
 *     1 - Represents srcTypeId lower level to destTypeId.
 * @since 12
 */
int OH_Utd_IsLowerLevelType(const char* srcTypeId, const char* destTypeId);

/**
 * @brief calculate relationships of two types.
 *
 * @param srcTypeId Represents source type id.
 * @param destTypeId Represents target type id.
 * @return 0 - Represents srcTypeId not higher level to destTypeId.
        1 - Represents srcTypeId higher level to destTypeId.
 * @since 12
 */
int OH_Utd_IsHigherLevelType(const char* srcTypeId, const char* destTypeId);

/**
 * @brief calculate two {@link OH_Utd_TypeDescriptor}s are equal.
 *
 * @param desc1 Represents a pointer to {@link OH_Utd_TypeDescriptor} instance.
 * @param desc2 Represents a pointer to {@link OH_Utd_TypeDescriptor} instance.
 * @return 0 - Represents desc1 and desc2 are not equal.
 *     1 - Represents desc1 and desc2 are equal.
 * @since 12
 */
int OH_Utd_IsEquals(OH_Utd_TypeDescriptor* desc1, OH_Utd_TypeDescriptor* desc2);

/**
 * @brief destroy string list memory.
 *
 * @param list Represents a point to string list.
 * @param count Represents string count in list.
 * @since 12
 */
void OH_Utd_DestroyStringList(const char** list, unsigned int count);

#ifdef __cplusplus
};
#endif

#endif