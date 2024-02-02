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

#ifndef HIVIEWDFX_HIDEBUG_TYPE_H
#define HIVIEWDFX_HIDEBUG_TYPE_H
/**
 * @addtogroup HiDebug
 * @{
 *
 * @brief Provides debug code define.
 *
 * For example, you can use these code for check result or parameter of HiDebug function.
 *
 * @since 12
 */

/**
 * @file hideug_type.h
 *
 * @brief Defines the code of the HiDebug module.
 *
 * @syscap SystemCapability.HiviewDFX.HiProfiler.HiDebug
 * @since 12
 */

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * @brief Defines error code
 *
 * @since 12
 */
typedef enum HiDebug_ErrorCode {
    /**
     * Success
     */
    HIDEBUG_SUCCESS = 0,
    /**
     * Invalid argument
     */
    HIDEBUG_INVALID_ARGUMENT = 401,
    /**
     * Have already capture trace
     */
    HIDEBUG_ALREADY_CAPTURE_TRACE = 11400102,
    /**
     * Without write permission on the file
     */
    HIDEBUG_WITHOUT_PERMISSION = 11400103,
    /**
     * The status of the trace is abnormal
     */
    HIDEBUG_TRACE_ABNORMAL = 11400104
} HiDebug_ErrorCode;

/**
 * @brief Defines application cpu usage of all threads structure type.
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
 * @brief Defines pointer of HiDebug_ThreadCpuUsage.
 *
 * @since 12
 */
typedef HiDebug_ThreadCpuUsage* HiDebug_ThreadCpuUsagePtr;

/**
 * @brief Defines system memory information structure type.
 *
 * @since 12
 */
typedef struct HiDebug_SysMemInfo {
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
} HiDebug_SysMemInfo;

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
 * @brief Enum for trace flag.
 *
 * @since 12
 */
typedef enum HiDebug_TraceFlag {
    /**
     * Only capture main thread trace
     */
    HIDEBUG_TRACE_FLAG_MAIN_THREAD = 1,
    /**
     * Capture all thread trace
     */
    HIDEBUG_TRACE_FLAG_ALL_THREADS = 2
} HiDebug_TraceFlag;

/**
 * @brief Ffrt tasks.
 * @since 12
 */
const uint64_t HIDEBUG_TRACE_TAG_FFRT = (1ULL << 13);
/**
 * @brief Commonlibrary subsystem tag.
 * @since 12
 */
const uint64_t HIDEBUG_TRACE_TAG_COMMONLIBRARY = (1ULL << 16);
/**
 * @brief HDF subsystem tag.
 * @since 12
 */
const uint64_t HIDEBUG_TRACE_TAG_HDF = (1ULL << 18);
/**
 * @brief Net tag.
 * @since 12
 */
const uint64_t HIDEBUG_TRACE_TAG_NET = (1ULL << 23);
/**
 * @brief NWeb tag.
 * @since 12
 */
const uint64_t HIDEBUG_TRACE_TAG_NWEB = (1ULL << 24);
/**
 * @brief Distributed audio tag.
 * @since 12
 */
const uint64_t HIDEBUG_TRACE_TAG_DISTRIBUTED_AUDIO = (1ULL << 27);
/**
 * @brief Filemanagement tag.
 * @since 12
 */
const uint64_t HIDEBUG_TRACE_TAG_FILEMANAGEMENT = (1ULL << 29);
/**
 * @brief OHOS generic tag.
 * @since 12
 */
const uint64_t HIDEBUG_TRACE_TAG_OHOS = (1ULL << 30);
/**
 * @brief Ability Manager tag.
 * @since 12
 */
const uint64_t HIDEBUG_TRACE_TAG_ABILITY_MANAGER = (1ULL << 31);
/**
 * @brief Camera module tag.
 * @since 12
 */
const uint64_t HIDEBUG_TRACE_TAG_ZCAMERA = (1ULL << 32);
/**
 * @brief Media module tag.
 * @since 12
 */
const uint64_t HIDEBUG_TRACE_TAG_ZMEDIA = (1ULL << 33);
/**
 * @brief Image module tag.
 * @since 12
 */
const uint64_t HIDEBUG_TRACE_TAG_ZIMAGE = (1ULL << 34);
/**
 * @brief Audio module tag.
 * @since 12
 */
const uint64_t HIDEBUG_TRACE_TAG_ZAUDIO = (1ULL << 35);
/**
 * @brief Distributeddata manager module tag.
 * @since 12
 */
const uint64_t HIDEBUG_TRACE_TAG_DISTRIBUTEDDATA = (1ULL << 36);
/**
 * @brief Graphic module tag.
 * @since 12
 */
const uint64_t HIDEBUG_TRACE_TAG_GRAPHIC_AGP = (1ULL << 38);
/**
 * @brief ACE development framework tag.
 * @since 12
 */
const uint64_t HIDEBUG_TRACE_TAG_ACE = (1ULL << 39);
/**
 * @brief Notification module tag.
 * @since 12
 */
const uint64_t HIDEBUG_TRACE_TAG_NOTIFICATION = (1ULL << 40);
/**
 * @brief Notification module tag.
 * @since 12
 */
const uint64_t HIDEBUG_TRACE_TAG_MISC = (1ULL << 41);
/**
 * @brief Multi modal module tag.
 * @since 12
 */
const uint64_t HIDEBUG_TRACE_TAG_MULTIMODALINPUT = (1ULL << 42);
/**
 * @brief RPC and IPC tag.
 * @since 12
 */
const uint64_t HIDEBUG_TRACE_TAG_RPC = (1ULL << 46);
/**
 * @brief ARK tag.
 * @since 12
 */
const uint64_t HIDEBUG_TRACE_TAG_ARK = (1ULL << 47);
/**
 * @brief Window manager tag.
 * @since 12
 */
const uint64_t HIDEBUG_TRACE_TAG_WINDOW_MANAGER = (1ULL << 48);
/**
 * @brief Distributed screen tag.
 * @since 12
 */
const uint64_t HIDEBUG_TRACE_TAG_DISTRIBUTED_SCREEN = (1ULL << 50);
/**
 * @brief Distributed camera tag.
 * @since 12
 */
const uint64_t HIDEBUG_TRACE_TAG_DISTRIBUTED_CAMERA = (1ULL << 51);
/**
 * @brief Distributed hardware fwk tag.
 * @since 12
 */
const uint64_t HIDEBUG_TRACE_TAG_DISTRIBUTED_HARDWARE_FWK = (1ULL << 52);
/**
 * @brief Global resource manager tag.
 * @since 12
 */
const uint64_t HIDEBUG_TRACE_TAG_GLOBAL_RESMGR = (1ULL << 53);
/**
 * @brief Distributed hardware devicemanager tag.
 * @since 12
 */
const uint64_t HIDEBUG_TRACE_TAG_DEVICE_MANAGER = (1ULL << 54);
/**
 * @brief SA tag.
 * @since 12
 */
const uint64_t HIDEBUG_TRACE_TAG_SAMGR = (1ULL << 55);
/**
 * @brief Power manager tag.
 * @since 12
 */
const uint64_t HIDEBUG_TRACE_TAG_POWER = (1ULL << 56);
/**
 * @brief Distributed schedule tag.
 * @since 12
 */
const uint64_t HIDEBUG_TRACE_TAG_DISTRIBUTED_SCHEDULE = (1ULL << 57);
/**
 * @brief Distributed input tag.
 * @since 12
 */
const uint64_t HIDEBUG_TRACE_TAG_DISTRIBUTED_INPUT = (1ULL << 59);
/**
 * @brief bluetooth tag.
 * @since 12
 */
const uint64_t HIDEBUG_TRACE_TAG_BLUETOOTH = (1ULL << 60);

#ifdef __cplusplus
}
#endif // __cplusplus
/** @} */

#endif // HIVIEWDFX_HIDEBUG_TYPE_H