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

#ifndef UDS_H
#define UDS_H

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
 * @file uds.h
 *
 * @brief Provides uniform data related functions and struct.
 *
 * @since 12
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Describes the unified data struct of plaintext.
 *
 * @since 12
 */
typedef struct OH_Uds_PlainText OH_Uds_PlainText;

/**
 * @brief Describes the unified data struct of hyperlink.
 *
 * @since 12
 */
typedef struct OH_Uds_Hyperlink OH_Uds_Hyperlink;

/**
 * @brief Describes the unified data struct of html.
 *
 * @since 12
 */
typedef struct OH_Uds_Html OH_Uds_Html;

/**
 * @brief Describes the unified data struct of open harmony application item.
 *
 * @since 12
 */
typedef struct OH_Uds_OpenHarmonyAppItem OH_Uds_OpenHarmonyAppItem;

/**
 * @brief creation a pointer to the instance of the {@link OH_Uds_PlainText}.
 *
 * @return If the operation is successful, a pointer to the instance of
 *      the {@link OH_Uds_PlainText} structure is returned.
 *      If the operation is failed, nullptr is returned.
 * @see OH_Uds_PlainText
 * @since 12
 */
OH_Uds_PlainText* OH_Uds_CreatePlainText();

/**
 * @brief destroy a pointer that points to the {@link OH_Uds_PlainText} instance.
 *
 * @param plainText Represents a pointer to an {@link OH_Uds_PlainText} instance.
 * @see OH_Uds_PlainText
 * @since 12
 */
void OH_Uds_DestroyPlainText(OH_Uds_PlainText* plainText);

/**
 * @brief get type id from the {@link OH_Uds_PlainText}.
 *
 * @param plainText Represents a pointer to an {@link OH_Uds_PlainText} instance.
 * @return returns a pointer of the value string when input args normally, otherwise return nullptr.
 * @see OH_Uds_PlainText 
 * @since 12
 */
const char* OH_Uds_GetPlainTextType(OH_Uds_PlainText* plainText);

/**
 * @brief get content from the {@link OH_Uds_PlainText}.
 *
 * @param plainText Represents a pointer to an {@link OH_Uds_PlainText} instance.
 * @return returns a pointer of the value string when input args normally, otherwise return nullptr.
 * @see OH_Uds_PlainText 
 * @since 12
 */
const char* OH_Uds_GetPlainTextContent(OH_Uds_PlainText* plainText);

/**
 * @brief get abstract from the {@link OH_Uds_PlainText}.
 *
 * @param plainText Represents a pointer to an {@link OH_Uds_PlainText} instance.
 * @return returns a pointer of the value string when input args normally, otherwise return nullptr.
 * @see OH_Uds_PlainText 
 * @since 12
 */
const char* OH_Uds_GetPlainTextAbstract(OH_Uds_PlainText* plainText);

/**
 * @brief set content to the {@link OH_Uds_PlainText}.
 *
 * @param plainText Represents a pointer to an {@link OH_Uds_PlainText} instance.
 * @param content Represents a new content string.
 * @see OH_Uds_PlainText 
 * @since 12
 */
void OH_Uds_SetPlainTextContent(OH_Uds_PlainText* plainText, const char* content);

/**
 * @brief set abstract to the {@link OH_Uds_PlainText}.
 *
 * @param abstract Represents a pointer to an {@link OH_Uds_PlainText} instance.
 * @see OH_Uds_PlainText 
 * @since 12
 */
void OH_Uds_SetPlainTextAbstract(OH_Uds_PlainText* plainText, const char* abstract);

/**
 * @brief creation a pointer to the instance of the {@link OH_Uds_Hyperlink}.
 *
 * @return If the operation is successful, a pointer to the instance of
 *      the {@link OH_Uds_Hyperlink} structure is returned.
 *      If the operation is failed, nullptr is returned.
 * @see OH_Uds_Hyperlink
 * @since 12
 */
OH_Uds_Hyperlink* OH_Uds_CreateHyperlink();

/**
 * @brief destroy a pointer that points to the {@link OH_Uds_Hyperlink} instance.
 *
 * @param hyperlink Represents a pointer to an {@link OH_Uds_Hyperlink} instance.
 * @see OH_Uds_Hyperlink
 * @since 12
 */
void OH_Uds_DestroyHyperlink(OH_Uds_Hyperlink* hyperlink);

/**
 * @brief get type from the {@link OH_Uds_Hyperlink}.
 *
 * @param hyperlink Represents a pointer to an {@link OH_Uds_Hyperlink} instance.
 * @return returns a pointer of the value string when input args normally, otherwise return nullptr.
 * @see OH_Uds_Hyperlink 
 * @since 12
 */
const char* OH_Uds_GetHyperlinkType(OH_Uds_Hyperlink* hyperlink);

/**
 * @brief get url from the {@link OH_Uds_Hyperlink}.
 *
 * @param hyperlink Represents a pointer to an {@link OH_Uds_Hyperlink} instance.
 * @return returns a pointer of the value string when input args normally, otherwise return nullptr.
 * @see OH_Uds_Hyperlink 
 * @since 12
 */
const char* OH_Uds_GetHyperlinkUrl(OH_Uds_Hyperlink* hyperlink);

/**
 * @brief get description from the {@link OH_Uds_Hyperlink}.
 *
 * @param hyperlink Represents a pointer to an {@link OH_Uds_Hyperlink} instance.
 * @return returns a pointer of the value string when input args normally, otherwise return nullptr.
 * @see OH_Uds_Hyperlink 
 * @since 12
 */
const char* OH_Uds_GetHyperlinkDescription(OH_Uds_Hyperlink* hyperlink);

/**
 * @brief set url to the {@link OH_Uds_Hyperlink}.
 *
 * @param hyperlink Represents a pointer to an {@link OH_Uds_Hyperlink} instance.
 * @param url Represents a new string value.
 * @see OH_Uds_Hyperlink 
 * @since 12
 */
void OH_Uds_SetHyperlinkUrl(OH_Uds_Hyperlink* hyperlink, const char* url);

/**
 * @brief set description to the {@link OH_Uds_Hyperlink}.
 *
 * @param hyperlink Represents a pointer to an {@link OH_Uds_Hyperlink} instance.
 * @param description Represents a new string value.
 * @see OH_Uds_Hyperlink 
 * @since 12
 */
void OH_Uds_SetHyperlinkDescription(OH_Uds_Hyperlink* hyperlink, const char* description);

/**
 * @brief creation a pointer to the instance of the {@link OH_Uds_Html}.
 *
 * @return If the operation is successful, a pointer to the instance of
 *      the {@link OH_Uds_Html} structure is returned.
 *      If the operation is failed, nullptr is returned.
 * @see OH_Uds_Html
 * @since 12
 */
OH_Uds_Html* OH_Uds_CreateHtml();

/**
 * @brief destroy a pointer that points to the {@link OH_Uds_Html} instance.
 *
 * @param html Represents a pointer to an {@link OH_Uds_Html} instance.
 * @see OH_Uds_Html
 * @since 12
 */
void OH_Uds_DestroyHtml(OH_Uds_Html* html);

/**
 * @brief get html from the {@link OH_Uds_Html}.
 *
 * @param html Represents a pointer to an {@link OH_Uds_Html} instance.
 * @return returns a pointer of the value string when input args normally, otherwise return nullptr.
 * @see OH_Uds_Html 
 * @since 12
 */
const char* OH_Uds_GetHtmlType(OH_Uds_Html* html);

/**
 * @brief get content from the {@link OH_Uds_Html}.
 *
 * @param html Represents a pointer to an {@link OH_Uds_Html} instance.
 * @return returns a pointer of the value string when input args normally, otherwise return nullptr.
 * @see OH_Uds_Html 
 * @since 12
 */
const char* OH_Uds_GetHtmlContent(OH_Uds_Html* html);

/**
 * @brief get plain content from the {@link OH_Uds_Html}.
 *
 * @param html Represents a pointer to an {@link OH_Uds_Html} instance.
 * @return returns a pointer of the value string when input args normally, otherwise return nullptr.
 * @see OH_Uds_Html 
 * @since 12
 */
const char* OH_Uds_GetHtmlPlainContent(OH_Uds_Html* html);

/**
 * @brief set content to the {@link OH_Uds_Html}.
 *
 * @param html Represents a pointer to an {@link OH_Uds_Html} instance.
 * @param content Represents a new string value.
 * @see OH_Uds_Html 
 * @since 12
 */
void OH_Uds_SetHtmlContent(OH_Uds_Html* html, const char* content);

/**
 * @brief set plain content to the {@link OH_Uds_Html}.
 *
 * @param html Represents a pointer to an {@link OH_Uds_Html} instance.
 * @param plainContent Represents a new string value.
 * @see OH_Uds_Html 
 * @since 12
 */
void OH_Uds_SetHtmlPlainContent(OH_Uds_Html* html, const char* plainContent);

/**
 * @brief creation a pointer to the instance of the {@link OH_Uds_OpenHarmonyAppItem}.
 *
 * @return If the operation is successful, a pointer to the instance of
 *      the {@link OH_Uds_OpenHarmonyAppItem} structure is returned.
 *      If the operation is failed, nullptr is returned.
 * @see OH_Uds_OpenHarmonyAppItem
 * @since 12
 */
OH_Uds_OpenHarmonyAppItem* OH_Uds_CreateOpenHarmonyAppItem();

/**
 * @brief destroy a pointer that points to the {@link OH_Uds_OpenHarmonyAppItem} instance.
 *
 * @param appItem Represents a pointer to an {@link OH_Uds_OpenHarmonyAppItem} instance.
 * @see OH_Uds_OpenHarmonyAppItem
 * @since 12
 */
void OH_Uds_DestroyOpenHarmonyAppItem(OH_Uds_OpenHarmonyAppItem* appItem);

/**
 * @brief get type from the {@link OH_Uds_OpenHarmonyAppItem}.
 *
 * @param html Represents a pointer to an {@link OH_Uds_OpenHarmonyAppItem} instance.
 * @return returns a pointer of the value string when input args normally, otherwise return nullptr.
 * @see OH_Uds_OpenHarmonyAppItem 
 * @since 12
 */
const char* OH_Uds_GetAppItemUdtType(OH_Uds_OpenHarmonyAppItem* appItem);

/**
 * @brief get app id from the {@link OH_Uds_OpenHarmonyAppItem}.
 *
 * @param html Represents a pointer to an {@link OH_Uds_OpenHarmonyAppItem} instance.
 * @return returns a pointer of the value string when input args normally, otherwise return nullptr.
 * @see OH_Uds_OpenHarmonyAppItem 
 * @since 12
 */
const char* OH_Uds_GetAppItemId(OH_Uds_OpenHarmonyAppItem* appItem);

/**
 * @brief get app name from the {@link OH_Uds_OpenHarmonyAppItem}.
 *
 * @param html Represents a pointer to an {@link OH_Uds_OpenHarmonyAppItem} instance.
 * @return returns a pointer of the value string when input args normally, otherwise return nullptr.
 * @see OH_Uds_OpenHarmonyAppItem 
 * @since 12
 */
const char* OH_Uds_GetAppItemName(OH_Uds_OpenHarmonyAppItem* appItem);

/**
 * @brief get app icon id from the {@link OH_Uds_OpenHarmonyAppItem}.
 *
 * @param html Represents a pointer to an {@link OH_Uds_OpenHarmonyAppItem} instance.
 * @return returns a pointer of the value string when input args normally, otherwise return nullptr.
 * @see OH_Uds_OpenHarmonyAppItem 
 * @since 12
 */
const char* OH_Uds_GetAppItemIconId(OH_Uds_OpenHarmonyAppItem* appItem);

/**
 * @brief get app label id from the {@link OH_Uds_OpenHarmonyAppItem}.
 *
 * @param html Represents a pointer to an {@link OH_Uds_OpenHarmonyAppItem} instance.
 * @return returns a pointer of the value string when input args normally, otherwise return nullptr.
 * @see OH_Uds_OpenHarmonyAppItem 
 * @since 12
 */
const char* OH_Uds_GetAppItemLabelId(OH_Uds_OpenHarmonyAppItem* appItem);

/**
 * @brief get bundle name from the {@link OH_Uds_OpenHarmonyAppItem}.
 *
 * @param html Represents a pointer to an {@link OH_Uds_OpenHarmonyAppItem} instance.
 * @return returns a pointer of the value string when input args normally, otherwise return nullptr.
 * @see OH_Uds_OpenHarmonyAppItem 
 * @since 12
 */
const char* OH_Uds_GetAppItemBundleName(OH_Uds_OpenHarmonyAppItem* appItem);

/**
 * @brief get ability name from the {@link OH_Uds_OpenHarmonyAppItem}.
 *
 * @param html Represents a pointer to an {@link OH_Uds_OpenHarmonyAppItem} instance.
 * @return returns a pointer of the value string when input args normally, otherwise return nullptr.
 * @see OH_Uds_OpenHarmonyAppItem 
 * @since 12
 */
const char* OH_Uds_GetAppItemAbilityName(OH_Uds_OpenHarmonyAppItem* appItem);

/**
 * @brief set application id to the {@link OH_Uds_OpenHarmonyAppItem}.
 *
 * @param html Represents a pointer to an {@link OH_Uds_OpenHarmonyAppItem} instance.
 * @param appId Represents a new string value.
 * @see OH_Uds_OpenHarmonyAppItem 
 * @since 12
 */
void OH_Uds_SetAppItemId(OH_Uds_OpenHarmonyAppItem* appItem, const char* appId);

/**
 * @brief set application name to the {@link OH_Uds_OpenHarmonyAppItem}.
 *
 * @param html Represents a pointer to an {@link OH_Uds_OpenHarmonyAppItem} instance.
 * @param appName Represents a new string value.
 * @see OH_Uds_OpenHarmonyAppItem 
 * @since 12
 */
void OH_Uds_SetAppItemName(OH_Uds_OpenHarmonyAppItem* appItem, const char* appName);

/**
 * @brief set application icon id to the {@link OH_Uds_OpenHarmonyAppItem}.
 *
 * @param html Represents a pointer to an {@link OH_Uds_OpenHarmonyAppItem} instance.
 * @param appIconId Represents a new string value.
 * @see OH_Uds_OpenHarmonyAppItem 
 * @since 12
 */
void OH_Uds_SetAppItemIconId(OH_Uds_OpenHarmonyAppItem* appItem, const char* appIconId);

/**
 * @brief set application label id to the {@link OH_Uds_OpenHarmonyAppItem}.
 *
 * @param html Represents a pointer to an {@link OH_Uds_OpenHarmonyAppItem} instance.
 * @param appLabelId Represents a new string value.
 * @see OH_Uds_OpenHarmonyAppItem 
 * @since 12
 */
void OH_Uds_SetAppItemLabelId(OH_Uds_OpenHarmonyAppItem* appItem, const char* appLabelId);

/**
 * @brief set bundle name to the {@link OH_Uds_OpenHarmonyAppItem}.
 *
 * @param html Represents a pointer to an {@link OH_Uds_OpenHarmonyAppItem} instance.
 * @param bundleName Represents a new string value.
 * @see OH_Uds_OpenHarmonyAppItem 
 * @since 12
 */
void OH_Uds_SetAppItemBundleName(OH_Uds_OpenHarmonyAppItem* appItem, const char* bundleName);

/**
 * @brief set ability name to the {@link OH_Uds_OpenHarmonyAppItem}.
 *
 * @param html Represents a pointer to an {@link OH_Uds_OpenHarmonyAppItem} instance.
 * @param abilityName Represents a new string value.
 * @see OH_Uds_OpenHarmonyAppItem 
 * @since 12
 */
void OH_Uds_SetAppItemAbilityName(OH_Uds_OpenHarmonyAppItem* appItem, const char* abilityName);

#ifdef __cplusplus
};
#endif

#endif