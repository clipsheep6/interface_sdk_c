/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
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

#ifndef HIVIEWDFX_HIAPPEVENT_EVENT_H
#define HIVIEWDFX_HIAPPEVENT_EVENT_H

/**
 * @addtogroup HiAppEvent
 * @{
 *
 * @brief Provides application event logging functions.
 *
 * Provides the event logging function for applications to log the fault, statistical, security, and user behavior
 * events reported during running. Based on event information, you will be able to analyze the running status of
 * applications.
 *
 * @syscap SystemCapability.HiviewDFX.HiAppEvent
 *
 * @since 8
 * @version 1.0
 */

/**
 * @file hiappevent_event.h
 *
 * @brief Defines the event names of all predefined events.
 *
 * In addition to custom events associated with specific apps, you can also use predefined events for logging.
 *
 * Sample code:
 * <pre>
 *     ParamList list = OH_HiAppEvent_CreateParamList();
 *     OH_HiAppEvent_AddInt32Param(list, PARAM_USER_ID, 123);
 *     int res = OH_HiAppEvent_Write("user_domain", EVENT_USER_LOGIN, BEHAVIOR, list);
 *     OH_HiAppEvent_DestroyParamList(list);
 * </pre>
 *
 * @since 8
 * @version 1.0
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief user login event.
 *
 * @since 8
 * @version 1.0
 */
#define EVENT_USER_LOGIN "hiappevent.user_login"

/**
 * @brief user logout event.
 *
 * @since 8
 * @version 1.0
 */
#define EVENT_USER_LOGOUT "hiappevent.user_logout"

/**
 * @brief distributed service event.
 *
 * @since 8
 * @version 1.0
 */
#define EVENT_DISTRIBUTED_SERVICE_START "hiappevent.distributed_service_start"

/**
 * @brief app crash event.
 *
 * @since 12
 * @version 1.0
 */
#define EVENT_APP_CRASH "hiappevent.app_crash"

/**
 * @brief app freeze event.
 *
 * @since 12
 * @version 1.0
 */
#define EVENT_APP_FREEZE "hiappevent.app_freeze"

/**
 * @brief app launch event.
 *
 * @since 12
 * @version 1.0
 */
#define EVENT_APP_LAUNCH "hiappevent.app_launch"

/**
 * @brief app scroll jank event.
 *
 * @since 12
 * @version 1.0
 */
#define EVENT_SCROLL_JANK "hiappevent.scroll_jank"

/**
 * @brief app cpu usage high event.
 *
 * @since 12
 * @version 1.0
 */
#define EVENT_CPU_USAGE_HIGH "hiappevent.cpu_usage_high"

/**
 * @brief app battery usage event.
 *
 * @since 12
 * @version 1.0
 */
#define EVENT_BATTERY_USAGE "hiappevent.battery_usage"

/**
 * @brief app resource overlimit event.
 *
 * @since 12
 * @version 1.0
 */
#define EVENT_RESOURCE_OVERLIMIT "hiappevent.resource_overlimit"

/**
 * @brief OS domain.
 *
 * @since 12
 * @version 1.0
 */
#define DOMAIN_OS "hiappevent.os"

#ifdef __cplusplus
}
#endif
/** @} */
#endif // HIVIEWDFX_HIAPPEVENT_EVENT_H