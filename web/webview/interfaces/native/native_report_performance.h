/*
 * Copyright (c) 2023 Huawei Device Co., Ltd.
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
 * @addtogroup Web
 * @{
 *
 * @brief Provides APIs to report corewebvatils and gpu stats.
 * @since 11
 */
/**
 * @file native_report_performance.h
 *
 * @library libohwebperformance.so
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
#ifndef NATIVE_REPORT_PERFORMANCE_H
#define NATIVE_REPORT_PERFORMANCE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * @brief core web vatils.
 *
 * @param LCP performance parameter of largeset contentful paint.
 * @param FID performance parameter of first input delay .
 * @param CLS performance parameter of cumulative layout shift.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
typedef struct {
    double LCP;
    double FID;
    double CLS;
} CoreWebVatils;

/*
 * @brief frame rate and gpu stats.
 *
 * @param gpuOn parameter gpu switch.
 * @param frameRate Frame rate.
 * @param gpuUseMemory gpu used memory.
 * @param gpuTotalMemory gpu total memory.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
typedef struct {
    int gpuOn;
    uint64_t frameRate;
    uint64_t gpuUseMemory;
    uint64_t gpuTotalMemory;
} FrameRenderStats;  

/**
* @brief Defines the callback for core web vatils.
*
* @since 11
*/
typedef void (*NativeArkWeb_OnCoreWebVatilsCallback)(CoreWebVatils*);

/**
* @brief Defines the callback for frame render stats.
*
* @since 11
*/
typedef void (*NativeArkWeb_OnFrameRenderStatsCallback)(FrameRenderStats*);

/*
 * @brief Report performance of CoreWebVatils.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeReportCoreWebVatilsPerformance(NativeArkWeb_OnCoreWebVatilsCallback callback);

/*
 * @brief Report frame rate and gpu stats.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeReportFrameRenderStatsPerformance(NativeArkWeb_OnFrameRenderStatsCallback callback);

#ifdef __cplusplus
};
#endif
#endif // NATIVE_REPORT_PERFORMANCE_H