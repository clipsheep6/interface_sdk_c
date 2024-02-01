/*
 * Copyright (c) 2021-2022 Huawei Device Co., Ltd.
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

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * @brief Defines system memory information structure type.
 *
 * @since 12
 */
typedef struct HiDebug_SysMeminfo {
    /**
     * Total system memory size, in kibibytes
     */
    uint32_t memTotal;
    /**
     * System free memory size, in kibibytes
     */
    uint32_t memFree;
    /**
     * System available memory size, in kibibytes
     */
    uint32_t memAvailable;
} HiDebug_SysMeminfo;

/**
 * @brief Obtains the system memory size.
 *
 * @param systemMemInfo Indicates the pointer to {@link HiDebug_SysMemInfo}.
 * @since 12
 */
void OH_HiDebug_GetSysMemInfo(HiDebug_SysMeminfo *systemMemInfo);

/**
 * @brief Defines application process native memory information structure type.
 *
 * @since 12
 */
typedef struct HiDebug_NativeMemInfo {
    /**
     * Process proportional set size memory, in kibibytes
     */
    uint32_t pss;
    /**
     * Virtual set size memory, in kibibytes
     */
    uint32_t vss;
    /**
     * Resident set size, in kibibytes
     */
    uint32_t rss;
    /**
     * The size of the shared dirty memory, in kibibytes
     */
    uint32_t sharedDirty;
    /**
     * The size of the private dirty memory, in kibibytes
     */
    uint32_t privateDirty;
    /**
     * The size of the shared clean memory, in kibibytes
     */
    uint32_t sharedClean;
    /**
     * The size of the private clean memory, in kibibytes
     */
    uint32_t privateClean;
} HiDebug_NativeMemInfo;

/**
 * @brief Obtains the memory info of application process.
 *
 * @param nativeMemInfo Indicates the pointer to {@link HiDebug_NativeMemInfo}.
 * @since 12
 */
void OH_HiDebug_GetAppNativeMemory(HiDebug_NativeMemInfo *nativeMemInfo);

/**
 * @brief Obtains the cpu usage of system.
 *
 * @return The cpu usage of system
 * @since 12
 */
double OH_HiDebug_GetSysCpuUsage();

/**
 * @brief Defines application CPU usage of all threads structure type.
 *
 * @since 12
 */
typedef struct HiDebug_ThreadCpuUsage {
    /**
     * Thread id
     */
    uint32_t threadId;
    /**
     * Cpu usage of thread
     */
    double cpuUsage;
    /**
     * Next thread cpu usage
     */
    struct HiDebug_ThreadCpuUsage *next;
} HiDebug_ThreadCpuUsage;

/**
 * @brief Defines pointer of HiDebug_ThreadCpuUsage
 *
 * @since 12
 */
typedef HiDebug_ThreadCpuUsage* HiDebug_ThreadCpuUsagePtr;

/**
 * @brief Obtains cpu usage of application's all thread
 *
 * @return Returns all thread cpu usage. See {@link HiDebug_ThreadCpuUsagePtr}
 * @since 12
 * @version 1.0
 */
HiDebug_ThreadCpuUsagePtr OH_HiDebug_GetAppThreadCpuUsage();

/**
 * @brief Free cpu usage buffer of applicatoin's all thread
 *
 * @param threadCpuUsage Applicatoin's all thread. . See {@link HiDebug_ThreadCpuUsagePtr}
 */
void OH_HiDebug_FreeThreadCpuUsage(HiDebug_ThreadCpuUsagePtr *threadCpuUsage);

/**
 * @brief Defines application process memory limit structure type.
 *
 * @since 12
 */
typedef struct OH_HiDebug_MemoryLimit {
    /**
     * The limit of the application process's resident set, in kibibytes
     */
    uint32_t rssLimit;
    /**
     * The limit of the application process's virtual memory, in kibibytes
     */
    uint32_t vssLimit;
} OH_HiDebug_MemoryLimit;

/**
 * @brief Obtains the memory limit of application process.
 *
 * @param memoryLimit Indicates the pointer to {@link OH_HiDebug_MemoryLimit}
 * @since 12
 */
void OH_HiDebug_GetAppMemoryLimit(OH_HiDebug_MemoryLimit *memoryLimit);

/**
 * @brief Obtains the cpu usage percent of a process.
 *
 * @return Returns the cpu usage percent of a process
 * @since 12
 */
double OH_HiDebug_GetAppCpuUsage();

/**
 * @brief Enum for trace flag
 *
 * @since 12
 */
typedef enum HiDebug_TraceFlag {
    /**
     * Only capture main thread trace
     */
    MAIN_THREAD = 1,
    /**
     * Capture all thread trace
     */
    ALL_THREADS = 2
} HiDebug_TraceFlag;

/**
 * @brief Start capture application trace.
 *
 * @param fileName Output trace file name
 * @param flag Trace flag
 * @param tags Tag of trace
 * @param limitSize Max size of trace file, in bytes, the max is 500MB.
 * @return Returns {@code 0} if successful. See {@link HiDebug_ErrorCode}
 * @since 12
 */
int OH_HiDebug_StartCaptureAppTrace(const char* fileName, uint64_t flag, uint64_t tags, uint32_t limitSize);

/**
 * @brief Stop capture application trace.
 *
 * @return Returns {@code 0} if successful. See {@link HiDebug_ErrorCode}
 * @since 12
 */
int OH_HiDebug_StopCaptureAppTrace();
#ifdef __cplusplus
}
#endif // __cplusplus
/** @} */

#endif // HIVIEWDFX_HIDEBUG_H