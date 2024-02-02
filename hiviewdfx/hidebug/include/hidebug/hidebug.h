/*
 * Copyright (c) 2024-2024 Huawei Device Co., Ltd.
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

#ifndef HIVIEWDFX_HIDEBUG_H
#define HIVIEWDFX_HIDEBUG_H
/**
 * @addtogroup HiDebug
 * @{
 *
 * @brief Provides debug functions.
 *
 * For example, you can use these functions to obtain cpu uage, memory, heap, capture trace.
 *
 * @since 12
 */

/**
 * @file hideug.h
 *
 * @brief Defines the debug functions of the HiDebug module.
 *
 * @syscap SystemCapability.HiviewDFX.HiProfiler.HiDebug
 * @since 12
 */

#include <stdint.h>
#include "hidebug_type.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * @brief Obtains the cpu usage of system.
 *
 * @return Returns the cpu usage of system
 * @since 12
 */
double OH_HiDebug_GetSysCpuUsage();

/**
 * @brief Obtains the cpu usage percent of a process.
 *
 * @return Returns the cpu usage percent of a process
 * @since 12
 */
double OH_HiDebug_GetAppCpuUsage();

/**
 * @brief Obtains cpu usage of application's all thread.
 *
 * @return Returns all thread cpu usage. See {@link HiDebug_ThreadCpuUsagePtr}
 * @since 12
 */
HiDebug_ThreadCpuUsagePtr OH_HiDebug_GetAppThreadCpuUsage();

/**
 * @brief Free cpu usage buffer of application's all thread.
 *
 * @param threadCpuUsage Indicates applicatoin's all thread. See {@link HiDebug_ThreadCpuUsagePtr}
 * @since 12
 */
void OH_HiDebug_FreeThreadCpuUsage(HiDebug_ThreadCpuUsagePtr *threadCpuUsage);

/**
 * @brief Obtains the system memory size.
 *
 * @param sysMemInfo Indicates the pointer to {@link HiDebug_SysMemInfo}.
 * @since 12
 */
void OH_HiDebug_GetSysMemInfo(HiDebug_SysMemInfo *sysMemInfo);

/**
 * @brief Obtains the memory info of application process.
 *
 * @param nativeMemInfo Indicates the pointer to {@link HiDebug_NativeMemInfo}.
 * @since 12
 */
void OH_HiDebug_GetAppNativeMemory(HiDebug_NativeMemInfo *nativeMemInfo);

/**
 * @brief Obtains the memory limit of application process.
 *
 * @param memoryLimit Indicates the pointer to {@link OH_HiDebug_MemoryLimit}
 * @since 12
 */
void OH_HiDebug_GetAppMemoryLimit(OH_HiDebug_MemoryLimit *memoryLimit);

/**
 * @brief Start capture application trace.
 *
 * @param fileName Output trace file name
 * @param flag Trace flag
 * @param tags Tag of trace
 * @param limitSize Max size of trace file, in bytes, the max is 500MB.
 * @return Returns {@code HIDEBUG_SUCCESS} if successful. See {@link HiDebug_ErrorCode}
 * @since 12
 */
HiDebug_ErrorCode OH_HiDebug_StartCaptureAppTrace(const char* fileName, HiDebug_TraceFlag flag, uint64_t tags, uint32_t limitSize);

/**
 * @brief Stop capture application trace.
 *
 * @return Returns {@code HIDEBUG_SUCCESS} if successful. See {@link HiDebug_ErrorCode}
 * @since 12
 */
HiDebug_ErrorCode OH_HiDebug_StopCaptureAppTrace();

#ifdef __cplusplus
}
#endif // __cplusplus
/** @} */

#endif // HIVIEWDFX_HIDEBUG_H