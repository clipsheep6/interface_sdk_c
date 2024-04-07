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

#ifndef HIVIEWDFX_HITRACE_H
#define HIVIEWDFX_HITRACE_H
/**
 * @addtogroup Hitrace
 * @{
 *
 * @brief hiTraceMeter provides APIs for system performance trace.
 *
 * You can call the APIs provided by hiTraceMeter in your own service logic to effectively
 * track service processes and check the system performance.
 *
 * @syscap SystemCapability.HiviewDFX.HiTrace
 *
 * @since 10
 */

/**
 * @file trace.h
 *
 * @brief Defines APIs of the HiTraceMeter module for performance trace.
 *
 * Sample code: \n
 * Synchronous timeslice trace event: \n
 *     OH_HiTrace_StartTrace("hitraceTest");\n
 *     OH_HiTrace_FinishTrace();\n
 * Output: \n
 *     <...>-1668    (-------) [003] ....   135.059377: tracing_mark_write: B|1668|H:hitraceTest \n
 *     <...>-1668    (-------) [003] ....   135.059415: tracing_mark_write: E|1668| \n
 * Asynchronous timeslice trace event:\n
 *     OH_HiTrace_StartAsyncTrace("hitraceTest", 123); \n
 *     OH_HiTrace_FinishAsyncTrace("hitraceTest", 123); \n
 * Output: \n
 *     <...>-2477    (-------) [001] ....   396.427165: tracing_mark_write: S|2477|H:hitraceTest 123 \n
 *     <...>-2477    (-------) [001] ....   396.427196: tracing_mark_write: F|2477|H:hitraceTest 123 \n
 * Integer value trace event:\n
 *     OH_HiTrace_CountTrace("hitraceTest", 500); \n
 * Output: \n
 *     <...>-2638    (-------) [002] ....   458.904382: tracing_mark_write: C|2638|H:hitraceTest 500 \n
 *
 * @syscap SystemCapability.HiviewDFX.HiTrace
 * @since 10
 */
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum HiTraceId_Valid {
    HITRACE_ID_INVALID = 0,
    HITRACE_ID_VALID = 1,
} HiTraceId_Valid;

typedef enum HiTrace_Version {
    HITRACE_VER_1 = 0,
} HiTrace_Version;

typedef enum HiTrace_Flag {
    HITRACE_FLAG_DEFAULT = 0,
    HITRACE_FLAG_INCLUDE_ASYNC = 1 << 0,
    HITRACE_FLAG_DONOT_CREATE_SPAN = 1 << 1,
    HITRACE_FLAG_TP_INFO = 1 << 2,
    HITRACE_FLAG_NO_BE_INFO = 1 << 3,
    HITRACE_FLAG_DONOT_ENABLE_LOG = 1 << 4,
    HITRACE_FLAG_FAULT_TRIGGER = 1 << 5,
    HITRACE_FLAG_D2D_TP_INFO = 1 << 6,
} HiTrace_Flag;

typedef enum HiTrace_Tracepoint_Type {
    HITRACE_TP_CS = 0,
    HITRACE_TP_CR = 1,
    HITRACE_TP_SS = 2,
    HITRACE_TP_SR = 3,
    HITRACE_TP_GENERAL = 4,
} HiTrace_Tracepoint_Type;

typedef enum HiTrace_Communication_Mode {
    HITRACE_CM_DEFAULT = 0,
    HITRACE_CM_THREAD = 1,
    HITRACE_CM_PROCESS = 2,
    HITRACE_CM_DEVICE = 3,
} HiTrace_Communication_Mode;

typedef struct HiTraceId {
#if __BYTE_ORDER == __LITTLE_ENDIAN
    uint64_t valid : 1;
    uint64_t ver : 3;
    uint64_t chainId : 60;
    uint64_t flags : 12;
    uint64_t spanId : 26;
    uint64_t parentSpanId : 26;
#elif __BYTE_ORDER == __BIG_ENDIAN
    uint64_t chainId : 60;
    uint64_t ver : 3;
    uint64_t valid : 1;
    uint64_t parentSpanId : 26;
    uint64_t spanId : 26;
    uint64_t flags : 12;
#else
#error "ERROR: No BIG_LITTLE_ENDIAN defines."
#endif
} HiTraceId;

HiTraceId OH_HiTrace_BeginChain(const char* name, int flags);
void OH_HiTrace_EndChain();
HiTraceId OH_HiTrace_GetId();
void OH_HiTrace_SetId(const HiTraceId* id);
void OH_HiTrace_ClearId(void);
HiTraceId OH_HiTrace_CreateSpan(void);
void OH_HiTrace_Tracepoint(HiTrace_Communication_Mode mode, HiTrace_Tracepoint_Type type,
                           const HiTraceId* id, const char* fmt, ...);
void OH_HiTrace_InitId(HiTraceId* id);
void OH_HiTrace_IdFromBytes(HiTraceId *id, const uint8_t* pIdArray, int len);
bool OH_HiTrace_IsIdValid(const HiTraceId* id);
bool OH_HiTrace_IsFlagEnabled(const HiTraceId* id, HiTrace_Flag flag);
void OH_HiTrace_EnableFlag(const HiTraceId* id, HiTrace_Flag flag);
int OH_HiTrace_GetFlags(const HiTraceId* id);
void OH_HiTrace_SetFlags(HiTraceId* id, int flags);
uint64_t OH_HiTrace_GetChainId(const HiTraceId* id);
void OH_HiTrace_SetChainId(HiTraceId* id, uint64_t chainId);
uint64_t OH_HiTrace_GetSpanId(const HiTraceId* id);
void OH_HiTrace_SetSpanId(HiTraceId* id, uint64_t spanId);
uint64_t OH_HiTrace_GetParentSpanId(const HiTraceId* id);
void OH_HiTrace_SetParentSpanId(HiTraceId* id, uint64_t parentSpanId);
int OH_HiTrace_IdToBytes(const HiTraceId* id, uint8_t* pIdArray, int len);

/**
 * @brief Marks the start of a synchronous trace task.
 *
 * The <b>OH_HiTrace_StartTrace</b> and <b>OH_HiTrace_FinishTrace</b> APIs must be used in pairs.
 * The two APIs can be used in nested mode. The stack data structure is used for matching during trace data parsing.
 *
 * @param name Name of a trace task.
 *
 * @syscap SystemCapability.HiviewDFX.HiTrace
 * @since 10
 */
void OH_HiTrace_StartTrace(const char *name);

/**
 * @brief Marks the end of a synchronous trace task.
 *
 * This API must be used with <b>OH_HiTrace_StartTrace</b> in pairs. During trace data parsing, the system matches
 * it with the <b>OH_HiTrace_StartTrace</b> API recently invoked in the service process.
 *
 * @syscap SystemCapability.HiviewDFX.HiTrace
 * @since 10
 */
void OH_HiTrace_FinishTrace(void);

/**
 * @brief Marks the start of an asynchronous trace task.
 *
 * This API is called to implement performance trace in asynchronous manner. The start and end of an asynchronous
 * trace task do not occur in sequence. Therefore, a unique <b>taskId</b> is required to ensure proper data parsing.
 * It is passed as an input parameter for the asynchronous API.
 * This API is used with <b>OH_HiTrace_FinishAsyncTrace</b> in pairs. The two APIs that have the same name and
 * task ID together form an asynchronous timeslice trace task.
 * If multiple trace tasks with the same name need to be performed at the same time or a trace task needs to be
 * performed multiple times concurrently, different task IDs must be specified in <b>OH_HiTrace_StartTrace</b>.
 * If the trace tasks with the same name are not performed at the same time, the same taskId can be used.
 *
 * @param name Name of the asynchronous trace task.
 * @param taskId ID of the asynchronous trace task. The start and end of an asynchronous trace task do not occur in
 * sequence. Therefore, the start and end of an asynchronous trace need to be matched based on the task name and the
 * unique task ID together.
 *
 * @syscap SystemCapability.HiviewDFX.HiTrace
 * @since 10
 */
void OH_HiTrace_StartAsyncTrace(const char *name, int32_t taskId);

/**
 * @brief Marks the end of an asynchronous trace task.
 *
 * This API is called in the callback function after an asynchronous trace is complete.
 * It is used with <b>OH_HiTrace_StartAsyncTrace</b> in pairs. Its name and task ID must be the same as those of
 * <b>OH_HiTrace_StartAsyncTrace</b>.
 *
 * @param name Name of the asynchronous trace task.
 * @param taskId ID of the asynchronous trace task. The start and end of an asynchronous trace task do not occur in
 * sequence. Therefore, the start and end of an asynchronous trace need to be matched based on the task name and the
 * unique task ID together.
 *
 * @syscap SystemCapability.HiviewDFX.HiTrace
 * @since 10
 */
void OH_HiTrace_FinishAsyncTrace(const char *name, int32_t taskId);

/**
 * @brief Traces the value change of an integer variable based on its name.
 *
 * This API can be executed for multiple times to trace the value change of a given integer variable at different
 * time points.
 *
 * @param name Name of the integer variable. It does not need to be the same as the real variable name.
 * @param count Integer value. Generally, an integer variable can be passed.
 *
 * @syscap SystemCapability.HiviewDFX.HiTrace
 * @since 10
 */
void OH_HiTrace_CountTrace(const char *name, int64_t count);

#ifdef __cplusplus
}
#endif
#endif // HIVIEWDFX_HITRACE_H
