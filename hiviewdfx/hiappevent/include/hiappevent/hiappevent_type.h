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

#ifndef HIVIEWDFX_HIAPPEVENT_TYPE_H
#define HIVIEWDFX_HIAPPEVENT_TYPE_H

/**
 * @addtogroup HiAppEvent
 * @{
 *
 * @brief Defines the structure used by hiappevent APIs.
 *
 * @syscap SystemCapability.HiviewDFX.HiAppEvent
 * @since 12
 * @version 1.0
 */

/**
 * @file hiappevent_type.h
 *
 * @brief Defines the structures used in the hiappevent APIs.
 *
 * @since 12
 * @version 1.0
 */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defines the event config to be reported by processor..
 * @SystemCapability.HiviewDFX.HiAppEvent
 * @since 12
 * @version 1.0
 */
struct OH_HiAppEvent_AppEventReportConfig {
	/* The domain of the event. */
	char* domain;
	/* The name of the event. */
	char* name;
	/* The realtime report event. */
	bool isRealTime;
};

/**
 * @brief Defines the event config to be reported by processor..
 * @SystemCapability.HiviewDFX.HiAppEvent
 * @since 12
 * @version 1.0
 */
struct OH_HiAppEvent_TriggerCondition {
	/* The number of write events that trigger callback. */
	uint32_t row;
	/* The interval for triggering callback. */
	uint32_t size;
	/* The interval for triggering callback. */
	uint32_t timeOut;
};

/**
 * @brief Defines the processor information structure.
 * @SystemCapability.HiviewDFX.HiAppEvent
 * @since 12
 * @version 1.0
 */
struct OH_HiAppEvent_Processor {
	/* The name of the processor. */
	char* name;
	/* The processor enable the developer to debug. */
	bool debugMode;
	/* The server location which used for the processor to receive the data, defined by the processor. */
	char* routeInfo;
	/* The app ID is provided by the processor. */
	char* appId;
	/* The processor report the event when start. */
	bool onStartReport;
	/* The processor report the event when the application onBackground. */
	bool onBackgroundReport;
	/* The processor report the event according to the period. */
	uint32_t periodReport;
	/* The processor report the event according to the batch size. */
	uint32_t batchReport;
	/* The user ID names which the processor can report. */
	char* userIds[];
	/* The user ID name array size. */
	uint32_t userIdArraySize;
	/* The user property names which the processor can report. */
	char* userProperties[];
	/* The user property array size. */
	uint32_t userPropertyArraySize;
	/* The events which the processor can report. */
	struct OH_HiAppEvent_AppEventReportConfig* eventConfigs;
	/* The app event report config array size. */
	uint32_t reportConfigArraySize;	
	/* The processor id. */
	int id;
	/* The extend value. */
	char* extendConfig;
};

/**
 * @brief Definition of event filter object, which is used to filter events monitored by the watcher.
 * @SystemCapability.HiviewDFX.HiAppEvent
 * @since 12
 * @version 1.0
 */
struct OH_HiAppEvent_AppEventFilter {
	/* The name of the processor. */
	char* domain;
	/* The types of the events to be monitored by the watcher. */
	uint32_t eventType;
	/* The names of the events to be monitored by the watcher. */
	char* names[];
	/* The size of the name array. */
	uint32_t nameArraySize;
};

/**
 * @brief Defines the event group.
 * @syscap SystemCapability.HiviewDFX.HiAppEvent
 * @since 12
 * @version 1.0
 */
struct OH_HiAppEvent_AppEventGroup {
	/* The name of the event. */
	char* name;
	/* The event array which is group by the name. */
	char* appEventInfos[];
	/* The event array size. */
	uint32_t appEventInfoArraySize
};

/**
 * @brief Called when watcher receive the event.
 * @syscap SystemCapability.HiviewDFX.HiAppEvent
 * @param domain The domain of the event.
 * @param appEventGroups The event group by the domain.
 * @since 12
 * @version 1.0
 */
typedef void (*OH_HiAppEvent_OnReceive)(const char* domain, const struct OH_HiAppEvent_AppEventGroup* appEventGroups, uint32_t groupSize);

/**
 * @brief Called when watcher receive the event meet the condition.
 * @syscap SystemCapability.HiviewDFX.HiAppEvent
 * @param row The row of events received by watcher.
 * @param size The size of events received by watcher.
 * @since 12
 * @version 1.0
 */
typedef void (*OH_HiAppEvent_OnTrigger)(int32_t row, int32_t size);

/**
 * @brief Defines the watcher information structure.
 * @syscap SystemCapability.HiviewDFX.HiAppEvent
 * @since 12
 * @version 1.0
 */
struct OH_HiAppEvent_Watcher {
	/* The name of the watcher. */
	char* name;
	/* The condition for triggering callback.*/
	struct OH_HiAppEvent_TriggerCondition triggerCondition;
	/* The event filters for monitoring events. */
	struct OH_HiAppEvent_AppEventFilter* appEventFilters;
	/* The event filters array size. */
	uint32_t filterArraySize;
	/* The callback function of watcher.*/
    OH_HiAppEvent_OnTrigger onTrigger;
	/* The callback function, when watcher receive the event.*/	
	OH_HiAppEvent_OnReceive onReceive;
};
#ifdef __cplusplus
}
#endif
/** @} */
#endif // HIVIEWDFX_HIAPPEVENT_TYPE_H