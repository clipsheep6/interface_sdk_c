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
 * @addtogroup OH_Print
 * @{
 *
 * @brief Provides the definition of the C interface for the print module.
 *
 * @syscap SystemCapability.Print.PrintFramework
 *
 * @since 12
 * @version 1.0
 */

/**
 * @file print_capi.h
 *
 * @brief Declares the APIs to discover and connect printers, get printer lists and printer information,
 *        and use a printer to print files, etc.
 *
 * @library libohprint.so
 * @syscap SystemCapability.Print.PrintFramework
 * @since 12
 * @version 1.0
 */

#ifndef NATIVE_PRINT_CAPI_H
#define NATIVE_PRINT_CAPI_H

#include "print_base.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief This API checks and pulls up the print service, initializes the print client,
 *        and establishes a connection to the print service.
 *
 * @permission {@code ohos.permission.PRINT}
 * @return Returns {@link Print_ErrorCode#PRINT_ERROR_NONE} if the execution is successful,
 *         otherwise returns a specific error code, refer to {@link Print_ErrorCode}.
 * @syscap SystemCapability.Print.PrintFramework
 * @since 12
 */
int32_t OH_Print_Init();

/**
 * @brief This API closes the connection from the print service, dissolves the previous callback,
 *        and releases the print client resources.
 *
 * @return Returns {@link Print_ErrorCode#PRINT_ERROR_NONE} if the execution is successful,
 *         otherwise returns a specific error code, refer to {@link Print_ErrorCode}.
 * @syscap SystemCapability.Print.PrintFramework
 * @since 12
 */
int32_t OH_Print_Release();

/**
 * @brief This API starts discovering printers.
 *
 * @permission {@code ohos.permission.PRINT}
 * @param callback The {@link Print_PrinterChangeCallback} of printer discovery event.
 * @return Returns {@link Print_ErrorCode#PRINT_ERROR_NONE} if the execution is successful,
 *         otherwise returns a specific error code, refer to {@link Print_ErrorCode}.
 * @syscap SystemCapability.Print.PrintFramework
 * @since 12
 */
int32_t OH_Print_StartPrinterDiscovery(Print_PrinterChangeCallback callback);

/**
 * @brief This API stops discovering printers.
 *
 * @permission {@code ohos.permission.PRINT}
 * @return Returns {@link Print_ErrorCode#PRINT_ERROR_NONE} if the execution is successful,
 *         otherwise returns a specific error code, refer to {@link Print_ErrorCode}.
 * @syscap SystemCapability.Print.PrintFramework
 * @since 12
 */
int32_t OH_Print_StopPrinterDiscovery();

/**
 * @brief This API connects to the printer using the printer id.
 *
 * @permission {@code ohos.permission.PRINT}
 * @param printerId The id of the printer to be connected.
 * @return Returns {@link Print_ErrorCode#PRINT_ERROR_NONE} if the execution is successful,
 *         otherwise returns a specific error code, refer to {@link Print_ErrorCode}.
 * @syscap SystemCapability.Print.PrintFramework
 * @since 12
 */
int32_t OH_Print_ConnectPrinter(const char *printerId);

/**
 * @brief This API starts initiating a print job.
 *
 * @permission {@code ohos.permission.PRINT}
 * @param printJob A pointer to a {@link Print_PrintJob} instance that specifies the information for the print job.
 * @return Returns {@link Print_ErrorCode#PRINT_ERROR_NONE} if the execution is successful,
 *         otherwise returns a specific error code, refer to {@link Print_ErrorCode}.
 * @syscap SystemCapability.Print.PrintFramework
 * @since 12
 */
int32_t OH_Print_StartPrintJob(const Print_PrintJob *printJob);

/**
 * @brief This API registers the callback for printer changes.
 *
 * @permission {@code ohos.permission.PRINT}
 * @param callback The {@link Print_PrinterChangeCallback} to be registered.
 * @return Returns {@link Print_ErrorCode#PRINT_ERROR_NONE} if the execution is successful,
 *         otherwise returns a specific error code, refer to {@link Print_ErrorCode}.
 * @syscap SystemCapability.Print.PrintFramework
 * @since 12
 */
int32_t OH_Print_RegisterPrinterChangeListener(Print_PrinterChangeCallback callback);

/**
 * @brief This API unregisters the callback for printer changes.
 *
 * @permission {@code ohos.permission.PRINT}
 * @syscap SystemCapability.Print.PrintFramework
 * @since 12
 */
void OH_Print_UnregisterPrinterChangeListener();

/**
 * @brief This API queries for a list of added printers.
 *
 * @permission {@code ohos.permission.PRINT}
 * @param printerIdList A pointer to a {@link Print_StringList} instance to store the queried printer id list.
 * @return Returns {@link Print_ErrorCode#PRINT_ERROR_NONE} if the execution is successful,
 *         otherwise returns a specific error code, refer to {@link Print_ErrorCode}.
 * @syscap SystemCapability.Print.PrintFramework
 * @since 12
 */
int32_t OH_Print_QueryPrinterList(Print_StringList *printerIdList);

/**
 * @brief This API frees up the printer list memory for the query.
 *
 * @param printerIdList The queried printer id list to be released.
 * @syscap SystemCapability.Print.PrintFramework
 * @since 12
 */
void OH_Print_ReleasePrinterList(Print_StringList *printerIdList);

/**
 * @brief This API queries printer information based on the printer id.
 *
 * @permission {@code ohos.permission.PRINT}
 * @param printerId The id of the printer to be queried.
 * @param printerInfo A pointer to a {@link Print_PrinterInfo} pointer to store the printer infomation.
 * @return Returns {@link Print_ErrorCode#PRINT_ERROR_NONE} if the execution is successful,
 *         otherwise returns a specific error code, refer to {@link Print_ErrorCode}.
 * @syscap SystemCapability.Print.PrintFramework
 * @since 12
 */
int32_t OH_Print_QueryPrinterInfo(const char *printerId, Print_PrinterInfo **printerInfo);

/**
 * @brief This API frees up the printer infomation memory for the query.
 *
 * @param printerInfo The pointer of the queried printer infomation to be released.
 * @syscap SystemCapability.Print.PrintFramework
 * @since 12
 */
void OH_Print_ReleasePrinterInfo(Print_PrinterInfo *printerInfo);

/**
 * @brief This API launches the system's printer management window.
 *
 * @return Returns {@link Print_ErrorCode#PRINT_ERROR_NONE} if the execution is successful,
 *         otherwise returns a specific error code, refer to {@link Print_ErrorCode}.
 * @syscap SystemCapability.Print.PrintFramework
 * @since 12
 */
int32_t OH_Print_LaunchPrinterManager();

/**
 * @brief This API queries the corresponding printer property values based on the list of property keywords.
 *
 * @permission {@code ohos.permission.PRINT}
 * @param printerId The id of the printer to be queried.
 * @param propertyKeyList The list of property keywords to be queried
 * @param propertyList The list of printer property values queried.
 * @return Returns {@link Print_ErrorCode#PRINT_ERROR_NONE} if the execution is successful,
 *         otherwise returns a specific error code, refer to {@link Print_ErrorCode}.
 * @syscap SystemCapability.Print.PrintFramework
 * @since 12
 */
int32_t OH_Print_QueryPrinterProperties(const char *printerId, const Print_StringList *propertyKeyList,
                                        Print_PropertyList *propertyList);

/**
 * @brief This API frees up the property list memory for the query.
 *
 * @param propertyList The pointer of the queried printer property values to be released.
 * @syscap SystemCapability.Print.PrintFramework
 * @since 12
 */
void OH_Print_ReleasePrinterProperties(Print_PropertyList *propertyList);

/**
 * @brief This API sets printer properties based on a list of property key-value pairs.
 *
 * @permission {@code ohos.permission.PRINT}
 * @param printerId The id of the printer to be set.
 * @param propertyList The list of printer property values to be set.
 * @return Returns {@link Print_ErrorCode#PRINT_ERROR_NONE} if the execution is successful,
 *         otherwise returns a specific error code, refer to {@link Print_ErrorCode}.
 * @syscap SystemCapability.Print.PrintFramework
 * @since 12
 */
int32_t OH_Print_UpdatePrinterProperties(const char *printerId, const Print_PropertyList *propertyList);

/**
 * @brief This API restores printer properties to default settings based on the list of property keywords.
 *
 * @permission {@code ohos.permission.PRINT}
 * @param printerId The id of the printer to be restored.
 * @param propertyKeyList The list of property keywords to be restored.
 * @return Returns {@link Print_ErrorCode#PRINT_ERROR_NONE} if the execution is successful,
 *         otherwise returns a specific error code, refer to {@link Print_ErrorCode}.
 * @syscap SystemCapability.Print.PrintFramework
 * @since 12
 */
int32_t OH_Print_RestorePrinterProperties(const char *printerId, const Print_StringList *propertyKeyList);

#ifdef __cplusplus
}
#endif

#endif // NATIVE_PRINT_CAPI_H
/** @} */
