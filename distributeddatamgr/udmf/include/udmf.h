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

#ifndef UDMF_H
#define UDMF_H

#include "uds.h"
#include <inttypes.h>

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
 * @file udmf.h
 *
 * @brief Provides unified data management framework related functions and enumerations.
 *
 * @since 12
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief The key minimum memory space size of Unified Data.
 *
 * @since 12
 */
#define UDMF_KEY_BUFFER_LEN (512)

/**
 * @brief Describe the intention type of the udmf.
 *
 * @since 12
 */
typedef enum OH_Udmf_Intention {
    /**
     * @brief The intention is drag.
     */
    UDMF_INTENTION_DRAG,
    /**
     * @brief The intention is pasteboard.
     */
    UDMF_INTENTION_PASTEBOARD,
} OH_Udmf_Intention;

/**
 * @brief Describe intra-device usage range type enumeration.
 *
 * @since 12
 */
typedef enum OH_Udmf_ShareOption
{
    /**
     * @brief Allowed to be used in the same application on this device.
     */
    SHARE_OPTIONS_IN_APP,
    /**
     * @brief Allowed to be used in the cross application on this device.
     */
    SHARE_OPTIONS_CROSS_APP,
} OH_Udmf_ShareOption;

/**
 * @brief Describes the unified data type.
 *
 * @since 12
 */
typedef struct OH_Udmf_UnifiedData OH_Udmf_UnifiedData;

/**
 * @brief Describes the record type in the unified data.
 *
 * @since 12
 */
typedef struct OH_Udmf_UnifiedRecord OH_Udmf_UnifiedRecord;

/**
 * @brief Describes some property parameters of unified data.
 *
 * @since 12
 */
typedef struct OH_Udmf_UnifiedDataProperties OH_Udmf_UnifiedDataProperties;

/**
 * @brief creation a pointer to the instance of the {@link OH_Udmf_UnifiedData}.
 *
 * @return If the operation is successful, a pointer to the instance of the {@link OH_Udmf_UnifiedData}.
 *     structure is returned. If the operation is failed, nullptr is returned.
 * @see OH_Udmf_UnifiedData.
 * @since 12
 */
OH_Udmf_UnifiedData* OH_Udmf_CreateUnifiedData();

/**
 * @brief destroy a pointer that points to the {@link OH_Udmf_UnifiedData} instance.
 *
 * @param data Represents a pointer to an {@link OH_Udmf_UnifiedData} instance.
 * @see OH_Udmf_UnifiedData.
 * @since 12
 */
void OH_Udmf_DestroyUnifiedData(OH_Udmf_UnifiedData* data);

/**
 * @brief add one {OH_Udmf_UnifiedRecord} record to the {@link OH_Udmf_UnifiedData} data.
 *
 * @param unifiedData Represents a pointer to an {@link OH_Udmf_UnifiedData} instance.
 * @param record Represents a pointer to an {@link OH_Udmf_UnifiedRecord} instance.
 * @return returns the status code of the execution. See {@link OH_Udmf_ErrCode}.
 *     {@link UDMF_E_OK} success.
 *     {@link UDMF_E_INVAILD_PARAM} The error code for common invalid args.
 * @see OH_Udmf_UnifiedData OH_Udmf_ErrCode.
 * @since 12
 */
int OH_Udmf_AddRecord(OH_Udmf_UnifiedData* unifiedData, OH_Udmf_UnifiedRecord* record);

/**
 * @brief check whether the type exists in the {@link OH_Udmf_UnifiedData} data.
 *
 * @param unifiedData Represents a pointer to an {@link OH_Udmf_UnifiedData} instance.
 * @param type Represents a string pointer of the type.
 * @return returns the status of finding type.
 *     0 is not existed.
 *     1 is existed.
 * @see OH_Udmf_UnifiedData.
 * @since 12
 */
int OH_Udmf_HasType(OH_Udmf_UnifiedData* unifiedData, const char* type);

/**
 * @brief get all types in the {@link OH_Udmf_UnifiedData} data.
 *
 * @param unifiedData Represents a pointer to an {@link OH_Udmf_UnifiedData} instance.
 * @param count Represents the types count that is a output param.
 * @return returns string array that in {@link OH_Udmf_UnifiedData} when input args normally, otherwise return nullptr.
 * @see OH_Udmf_UnifiedData.
 * @since 12
 */
char** OH_Udmf_GetTypes(OH_Udmf_UnifiedData* unifiedData, int* count);

/**
 * @brief get all records in the {@link OH_Udmf_UnifiedData} data.
 *
 * @param unifiedData Represents a pointer to an {@link OH_Udmf_UnifiedData} instance.
 * @param count Represents the records count that is a output param.
 * @return returns {@link OH_Udmf_UnifiedRecord} pointer array when args normally, otherwise return nullptr.
 * @see OH_Udmf_UnifiedData OH_Udmf_UnifiedRecord.
 * @since 12
 */
OH_Udmf_UnifiedRecord** OH_Udmf_GetRecords(OH_Udmf_UnifiedData* unifiedData, int* count);

/**
 * @brief creation a pointer to the instance of the {@link OH_Udmf_UnifiedRecord}, it's relate with UDS data.
 *
 * @return If the operation is successful, a pointer to the instance of
 *    the {@link OH_Udmf_UnifiedRecord} structure is returned.
 *    If the operation is failed, nullptr is returned.
 * @see OH_Udmf_UnifiedRecord.
 * @since 12
 */
OH_Udmf_UnifiedRecord* OH_Udmf_CreateUnifiedRecord();

/**
 * @brief creation a pointer to the instance of the {@link OH_Udmf_UnifiedRecord}, it's relate with custom data.
 * @param typeId Represents record type, reference udmf_meta.h.
 * @param data Represents custom data.
 * @param count Represents the size of data param.
 * @return If the operation is successful, a pointer to the instance of
 *    the {@link OH_Udmf_UnifiedRecord} structure is returned.
 *    If the operation is failed, nullptr is returned.
 * @see OH_Udmf_UnifiedRecord.
 * @since 12
 */
OH_Udmf_UnifiedRecord* OH_Udmf_CreateGeneralRecord(const char* typeId, unsigned char* data, unsigned int count);

/**
 * @brief destroy a pointer that points to the {@link OH_Udmf_UnifiedRecord} instance.
 *
 * @param record Represents a pointer to an {@link OH_Udmf_UnifiedRecord} instance.
 * @see OH_Udmf_UnifiedRecord.
 * @since 12
 */
void OH_Udmf_DestroyUnifiedRecord(OH_Udmf_UnifiedRecord* record);

/**
 * @brief add one {OH_Uds_PlainText} data to the {@link OH_Udmf_UnifiedRecord} record.
 *
 * @param record Represents a pointer to an {@link OH_Udmf_UnifiedRecord} instance.
 * @param plainText Represents a pointer to an {@link OH_Uds_PlainText} instance.
 * @return returns the status code of the execution. See {@link OH_Udmf_ErrCode}.
 *     {@link UDMF_E_OK} success.
 *     {@link UDMF_E_INVAILD_PARAM} The error code for common invalid args.
 * @see OH_Udmf_UnifiedRecord OH_Uds_PlainText OH_Udmf_ErrCode.
 * @since 12
 */
int OH_Udmf_BuildRecordByPlainText(OH_Udmf_UnifiedRecord* record, OH_Uds_PlainText* plainText);

/**
 * @brief add one {OH_Uds_Hyperlink} data to the {@link OH_Udmf_UnifiedRecord} record.
 *
 * @param record Represents a pointer to an {@link OH_Udmf_UnifiedRecord} instance.
 * @param plainText Represents a pointer to an {@link OH_Uds_Hyperlink} instance.
 * @return returns the status code of the execution. See {@link OH_Udmf_ErrCode}.
 *     {@link UDMF_E_OK} success.
 *     {@link UDMF_E_INVAILD_PARAM} The error code for common invalid args.
 * @see OH_Udmf_UnifiedRecord OH_Uds_Hyperlink OH_Udmf_ErrCode.
 * @since 12
 */
int OH_Udmf_BuildRecordByHyperlink(OH_Udmf_UnifiedRecord* record, OH_Uds_Hyperlink* hyperlink);

/**
 * @brief add one {OH_Uds_Html} data to the {@link OH_Udmf_UnifiedRecord} record.
 *
 * @param record Represents a pointer to an {@link OH_Udmf_UnifiedRecord} instance.
 * @param plainText Represents a pointer to an {@link OH_Uds_Html} instance.
 * @return returns the status code of the execution. See {@link OH_Udmf_ErrCode}.
 *     {@link UDMF_E_OK} success.
 *     {@link UDMF_E_INVAILD_PARAM} The error code for common invalid args.
 * @see OH_Udmf_UnifiedRecord OH_Uds_Html OH_Udmf_ErrCode.
 * @since 12
 */
int OH_Udmf_BuildRecordByHtml(OH_Udmf_UnifiedRecord* record, OH_Uds_Html* html);

/**
 * @brief add one {OH_Uds_OpenHarmonyAppItem} data to the {@link OH_Udmf_UnifiedRecord} record.
 *
 * @param record Represents a pointer to an {@link OH_Udmf_UnifiedRecord} instance.
 * @param plainText Represents a pointer to an {@link OH_Uds_OpenHarmonyAppItem} instance.
 * @return returns the status code of the execution. See {@link OH_Udmf_ErrCode}.
 *     {@link UDMF_E_OK} success.
 *     {@link UDMF_E_INVAILD_PARAM} The error code for common invalid args.
 * @see OH_Udmf_UnifiedRecord OH_Uds_OpenHarmonyAppItem OH_Udmf_ErrCode.
 * @since 12
 */
int OH_Udmf_BuildRecordByOpenHarmonyAppItem(OH_Udmf_UnifiedRecord* record, OH_Uds_OpenHarmonyAppItem* appItem);

/**
 * @brief get one {OH_Uds_PlainText} data from the {@link OH_Udmf_UnifiedRecord} record.
 *
 * @param record Represents a pointer to an {@link OH_Udmf_UnifiedRecord} instance.
 * @param plainText Represents a pointer to an {@link OH_Uds_PlainText} instance.
 * @return returns the status code of the execution. See {@link OH_Udmf_ErrCode}.
 *     {@link UDMF_E_OK} success.
 *     {@link UDMF_E_INVAILD_PARAM} The error code for common invalid args.
 * @see OH_Udmf_UnifiedRecord OH_Uds_PlainText OH_Udmf_ErrCode.
 * @since 12
 */
int OH_Udmf_GetPlainTextFromRecord(OH_Udmf_UnifiedRecord* record, OH_Uds_PlainText* plainText);

/**
 * @brief get one {OH_Uds_Hyperlink} data from the {@link OH_Udmf_UnifiedRecord} record.
 *
 * @param record Represents a pointer to an {@link OH_Udmf_UnifiedRecord} instance.
 * @param plainText Represents a pointer to an {@link OH_Uds_Hyperlink} instance.
 * @return returns the status code of the execution. See {@link OH_Udmf_ErrCode}.
 *     {@link UDMF_E_OK} success.
 *     {@link UDMF_E_INVAILD_PARAM} The error code for common invalid args.
 * @see OH_Udmf_UnifiedRecord OH_Uds_Hyperlink OH_Udmf_ErrCode.
 * @since 12
 */
int OH_Udmf_GetHyperlinkFromRecord(OH_Udmf_UnifiedRecord* record, OH_Uds_Hyperlink* hyperlink);

/**
 * @brief get one {OH_Uds_Html} data from the {@link OH_Udmf_UnifiedRecord} record.
 *
 * @param record Represents a pointer to an {@link OH_Udmf_UnifiedRecord} instance.
 * @param plainText Represents a pointer to an {@link OH_Uds_Html} instance.
 * @return returns the status code of the execution. See {@link OH_Udmf_ErrCode}.
 *     {@link UDMF_E_OK} success.
 *     {@link UDMF_E_INVAILD_PARAM} The error code for common invalid args.
 * @see OH_Udmf_UnifiedRecord OH_Uds_Html OH_Udmf_ErrCode.
 * @since 12
 */
int OH_Udmf_GetHtmlFromRecord(OH_Udmf_UnifiedRecord* record, OH_Uds_Html* html);

/**
 * @brief get one {OH_Uds_OpenHarmonyAppItem} data from the {@link OH_Udmf_UnifiedRecord} record.
 *
 * @param record Represents a pointer to an {@link OH_Udmf_UnifiedRecord} instance.
 * @param plainText Represents a pointer to an {@link OH_Uds_OpenHarmonyAppItem} instance.
 * @return returns the status code of the execution. See {@link OH_Udmf_ErrCode}.
 *     {@link UDMF_E_OK} success.
 *     {@link UDMF_E_INVAILD_PARAM} The error code for common invalid args.
 * @see OH_Udmf_UnifiedRecord OH_Uds_OpenHarmonyAppItem OH_Udmf_ErrCode.
 * @since 12
 */
int OH_Udmf_GetOpenHarmonyAppItemFromRecord(OH_Udmf_UnifiedRecord* record, OH_Uds_OpenHarmonyAppItem* appItem);

/**
 * @brief creation a pointer to the instance of the {@link OH_Udmf_UnifiedDataProperties}
 *     from a {@link OH_Udmf_UnifiedData} data.
 *
 * @param data Represents a pointer to an {@link OH_Udmf_UnifiedData} instance.
 * @return If the operation is successful, a pointer to the instance of the {@link OH_Udmf_UnifiedDataProperties}
 *     structure is returned. If the operation is failed, nullptr is returned.
 * @see OH_Udmf_UnifiedData OH_Udmf_UnifiedDataProperties.
 * @since 12
 */
OH_Udmf_UnifiedDataProperties* OH_Udmf_CreatePropertiesFromUnifiedData(OH_Udmf_UnifiedData* data);

/**
 * @brief destroy a pointer that points to the {@link OH_Udmf_UnifiedDataProperties} instance.
 *
 * @param data Represents a pointer to an {@link OH_Udmf_UnifiedDataProperties} instance.
 * @see OH_Udmf_UnifiedDataProperties.
 * @since 12
 */
void OH_Udmf_DetroyUnifiedDataProperties(OH_Udmf_UnifiedDataProperties* properties);

/**
 * @brief get tag value from the {@link OH_Udmf_UnifiedDataProperties}.
 *
 * @param properties Represents a pointer to an {@link OH_Udmf_UnifiedDataProperties} instance.
 * @return returns a pointer of the tag value string when input args normally, otherwise return nullptr.
 * @see OH_Udmf_UnifiedDataProperties.
 * @since 12
 */
const char* OH_Udmf_GetPropertiesTag(OH_Udmf_UnifiedDataProperties* properties);

/**
 * @brief get timestamp value from the {@link OH_Udmf_UnifiedDataProperties}.
 *
 * @param properties Represents a pointer to an {@link OH_Udmf_UnifiedDataProperties} instance.
 * @return returns timestamp value.
 * @see OH_Udmf_UnifiedDataProperties.
 * @since 12
 */
int64_t OH_Udmf_GetPropertiesTimestamp(OH_Udmf_UnifiedDataProperties* properties);

/**
 * @brief get share option value from the {@link OH_Udmf_UnifiedDataProperties}.
 *
 * @param properties Represents a pointer to an {@link OH_Udmf_UnifiedDataProperties} instance.
 * @return returns {@link OH_Udmf_ShareOption}} value.
 * @see OH_Udmf_UnifiedDataProperties OH_Udmf_ShareOption.
 * @since 12
 */
OH_Udmf_ShareOption OH_Udmf_GetPropertiesShareOption(OH_Udmf_UnifiedDataProperties* properties);

/**
 * @brief get integer value by key from the {@link OH_Udmf_UnifiedDataProperties}.
 *
 * @param properties Represents a pointer to an {@link OH_Udmf_UnifiedDataProperties} instance.
 * @param key Represents key-value pair's key
 * @param defaultValue Represents when get value failure.
 * @return returns value associated with the key in successfully, otherwise return defaultValue.
 * @see OH_Udmf_UnifiedDataProperties.
 * @since 12
 */
int OH_Udmf_GetPropertiesExtrasIntParam(OH_Udmf_UnifiedDataProperties* properties,
    const char* key, const int defaultValue);

/**
 * @brief get tag value from the {@link OH_Udmf_UnifiedDataProperties}.
 *
 * @param properties Represents a pointer to an {@link OH_Udmf_UnifiedDataProperties} instance.
 * @param key Represents key-value pair's key.
 * @return returns a pointer of the key value string when input args normally, otherwise return nullptr.
 * @see OH_Udmf_UnifiedDataProperties.
 * @since 12
 */
const char* OH_Udmf_GetPropertiesExtrasStringParam(OH_Udmf_UnifiedDataProperties* properties, const char* key);

/**
 * @brief set tag value to {@link OH_Udmf_UnifiedDataProperties} .
 *
 * @param properties Represents a pointer to an {@link OH_Udmf_UnifiedDataProperties} instance.
 * @param tag Represents new tag param.
 * @return returns the status code of the execution. See {@link OH_Udmf_ErrCode}.
 *     {@link UDMF_E_OK} success.
 *     {@link UDMF_E_INVAILD_PARAM} The error code for common invalid args.
 * @see OH_Udmf_UnifiedDataProperties OH_Udmf_ErrCode.
 * @since 12
 */
int OH_Udmf_SetPropertiesTag(OH_Udmf_UnifiedDataProperties* properties, const char* tag);

/**
 * @brief set OH_Udmf_ShareOption value to {@link OH_Udmf_UnifiedDataProperties}.
 *
 * @param properties Represents a pointer to an {@link OH_Udmf_UnifiedDataProperties} instance.
 * @param option Represents new {@link OH_Udmf_ShareOption} param.
 * @return returns the status code of the execution. See {@link OH_Udmf_ErrCode}.
 *     {@link UDMF_E_OK} success.
 *     {@link UDMF_E_INVAILD_PARAM} The error code for common invalid args.
 * @see OH_Udmf_UnifiedDataProperties OH_Udmf_ShareOption OH_Udmf_ErrCode.
 * @since 12
 */
int OH_Udmf_SetPropertiesShareOption(OH_Udmf_UnifiedDataProperties* properties, OH_Udmf_ShareOption option);

/**
 * @brief set extras param to {@link OH_Udmf_UnifiedDataProperties}.
 *
 * @param properties Represents a pointer to an {@link OH_Udmf_UnifiedRecord} instance.
 * @param key Represents extras param's key value.
 * @param param Represents value of k-v pairs.
 * @return returns the status code of the execution. See {@link OH_Udmf_ErrCode}.
 *     {@link UDMF_E_OK} success.
 *     {@link UDMF_E_INVAILD_PARAM} The error code for common invalid args.
 * @see OH_Udmf_UnifiedDataProperties OH_Udmf_ErrCode.
 * @since 12
 */
int OH_Udmf_SetPropertiesExtrasIntParam(OH_Udmf_UnifiedDataProperties* properties, const char* key, int param);

/**
 * @brief set extras param to {@link OH_Udmf_UnifiedDataProperties}.
 *
 * @param properties Represents a pointer to an {@link OH_Udmf_UnifiedRecord} instance.
 * @param key Represents extras param's key value.
 * @param param Represents value of k-v pairs.
 * @return returns the status code of the execution. See {@link OH_Udmf_ErrCode}.
 *     {@link UDMF_E_OK} success.
 *     {@link UDMF_E_INVAILD_PARAM} The error code for common invalid args.
 * @see OH_Udmf_UnifiedDataProperties OH_Udmf_ErrCode.
 * @since 12
 */
int OH_Udmf_SetPropertiesExtrasStringParam(OH_Udmf_UnifiedDataProperties* properties,
    const char* key, const char* param);

/**
 * @brief get {@link OH_Udmf_UnifiedData} data from udmf database.
 *
 * @param key Represents database store's key value.
 * @param intention Represents data type {@link OH_Udmf_Intention}
 * @param data Represents output params of {@link OH_Udmf_UnifiedData};
 * @return returns the status code of the execution. See {@link OH_Udmf_ErrCode}.
 *     {@link UDMF_E_OK} success.
 *     {@link UDMF_E_INVAILD_PARAM} The error code for common invalid args.
 * @see OH_Udmf_UnifiedDataProperties OH_Udmf_Intention OH_Udmf_ErrCode.
 * @since 12
 */
int OH_Udmf_GetUnifiedData(const char* key, OH_Udmf_Intention intention, OH_Udmf_UnifiedData* data);

/**
 * @brief get {@link OH_Udmf_UnifiedData} data from udmf database.
 *
 * @param intention Represents data type {@link OH_Udmf_Intention}.
 * @param data Represents output params of {@link OH_Udmf_UnifiedData}.
 * @param key Represents return value after set data to database successfully,
 *     it's memory size not less than {@link UDMF_KEY_BUFFER_LEN}.
 * @param keyLen Represents size of key param.
 * @return returns the status code of the execution. See {@link OH_Udmf_ErrCode}.
 *     {@link UDMF_E_OK} success.
 *     {@link UDMF_E_INVAILD_PARAM} The error code for common invalid args.
 * @see OH_Udmf_UnifiedDataProperties OH_Udmf_Intention OH_Udmf_ErrCode.
 * @since 12
 */
int OH_Udmf_SetUnifiedData(OH_Udmf_Intention intention, OH_Udmf_UnifiedData* unifiedData,
    char* key, unsigned int keyLen);

#ifdef __cplusplus
};
#endif

#endif