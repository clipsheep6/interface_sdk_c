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
 * @brief Provide the definition of the C interface for the native print module.
 *
 * @syscap SystemCapability.Print.PrintFramework
 *
 * @since 12
 * @version 1.0
 */

/**
 * @file native_print_capi.h
 *
 * @brief Declare the native print functions.
 *
 * @library libohprint.so
 * @syscap SystemCapability.Print.PrintFramework
 * @since 12
 * @version 1.0
 */

#ifndef NATIVE_PRINT_CAPI_H
#define NATIVE_PRINT_CAPI_H

#include "native_print_base.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initialize.
 * @since 12
 */
int32_t OH_Print_Init();
// 反初始化
/**
 * @brief Release resources before exiting.
 * @since 12
 */
int32_t OH_Print_Release();

// 开始发现打印机
/**
 * @brief Start discovering printers.
 * @since 12
 */
int32_t OH_Print_StartPrinterDiscovery(Print_PrinterChangeCallback callback);

// 停止发现打印机
/**
 * @brief Stop discovering printers.
 * @since 12
 */
int32_t OH_Print_StopPrinterDiscovery();

/**
 * @brief Connect to a printer.
 * @since 12
 */
int32_t OH_Print_ConnectPrinter(const char *printerId);

// 开始打印任务
/**
 * @brief Start print job.
 * @since 12
 */
int32_t OH_Print_StartPrintJob(const Print_PrintJob *printJob);

// 注册打印机状态事件
/**
 * @brief Register printer change events.
 * @since 12
 */
int32_t OH_Print_RegisterPrinterChangeListener(Print_PrinterChangeCallback callback);

/**
 * @brief Unregister printer change event.
 * @since 12
 */
void OH_Print_UnregisterPrinterChangeListener();

// 获取打印机列表
/**
 * @brief Query the printer list.
 * @since 12
 */
int32_t OH_Print_QueryPrinterList(Print_StringList *printerIdList);

/**
 * @brief Free printer list memory.
 * @since 12
 */
void OH_Print_ReleasePrinterList(Print_StringList *printerIdList);

/**
 * @brief Query printer infomation.
 * @since 12
 */
int32_t OH_Print_QueryPrinterInfo(const char *printerId, Print_PrinterInfo **printerInfo);

/**
 * @brief Free printer infomation memory.
 * @since 12
 */
void OH_Print_ReleasePrinterInfo(Print_PrinterInfo *printerInfo);

/**
 * @brief Open the printer manager page.
 * @since 12
 */
int32_t OH_Print_LaunchPrinterManager();

/**
 * @brief Query printer properties.
 * @since 12
 */
int32_t OH_Print_QueryPrinterProperties(const char *printerId, const Print_StringList propertyKeyList,
                                        Print_PropertyList *propertyList);

/**
 * @brief Free printer properties memory.
 * @since 12
 */
void OH_Print_ReleasePrinterProperties(Print_PropertyList *propertyList);

/**
 * @brief Set printer properties.
 * @since 12
 */
int32_t OH_Print_UpdatePrinterProperties(const char *printerId, const Print_PropertyList *propertyList);

/**
 * @brief Restore printer properties to default settings.
 * @since 12
 */
int32_t OH_Print_RestorePrinterProperties(const char *printerId, const Print_StringList *propertyKeyList);

#ifdef __cplusplus
}
#endif

#endif // NATIVE_PRINT_CAPI_H
/** @} */
