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

#ifndef HIVIEWDFX_HICOLLIE_H
#define HIVIEWDFX_HICOLLIE_H

/**
 * @addtogroup HiCollie
 * @{
 *
 * @brief Provides xcollie functions.
 *
 * For example, you can use these functions to set, trigger or cancel xcollie mechanism
 *
 * @since 12
 */

/**
 * @file xcollie.h
 * @brief Defines the xcollie functions of the HiCollie module.
 * @library libohhicollie.so
 * @syscap SystemCapability.HiviewDFX.HiCollie
 * @since 12
 */

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * @brief Defines flag enum
 * @since 12
 */
typedef enum XCollie_Flag {
    /** do all callback function */
    XCOLLIE_FLAG_DEFAULT = (~0),
    /** do nothing but the caller defined function */
    XCOLLIE_FLAG_NOOP = (0),
    /** generate log file */
    XCOLLIE_FLAG_LOG = (1 << 0),
    /** die when timeout */
    XCOLLIE_FLAG_RECOVERY = (1 << 1)
} XCollie_Flag;

typedef void (*OH_XCollieCallback)(void*);

/**
 * @brief Set timer.
 * @syscap SystemCapability.HiviewDFX.HiCollie
 * @param name Timer name.
 * @param timeout Timeout, unit second
 * @param func Callback
 * @param arg The Callback's param
 * @param flag Timer timeout operation. the value can be:
 *        OH_XCOLLIE_FLAG_DEFAULT : do all back function
 *        OH_XCOLLIE_FLAG_NOOP : do nothing but the caller defined function
 *        OH_XCOLLIE_FLAG_LOG : generate log file
 *        OH_XCOLLIE_FLAG_RECOVERY : die when timeout
 * @return The timer id
 * @since 12
 */
int OH_XCollie_SetTimer(const char *name, unsigned int timeout,
    OH_XCollieCallback func, void *arg, unsigned int flag);

/**
 * @brief Cancel timer
 * @syscap SystemCapability.HiviewDFX.HiCollie
 * @param id Timer id
 * @since 12
 */
void OH_XCollie_CancelTimer(int id);

/**
 * @brief Set timer and count
 * @syscap SystemCapability.HiviewDFX.HiCollie
 * @param name Timer and count name
 * @param timeLimit Event occured set time param limit
 * @param countLimit Event occured set min count limit
 */
int OH_XCollie_SetTimerCount(const char *name, unsigned int timeLimit, int countLimit);

/**
 * @brief Trigger timer count
 * @syscap SystemCapability.HiviewDFX.HiCollie
 * @param name Trigger name
 * @param bTrigger Trigger or clear previous tigger count
 * @param message Need report pid current message
 * @since 12
 */
void OH_XCollie_TriggerTimerCount(const char *name, bool bTrigger, const char *message);

#ifdef __cplusplus
}
#endif
/** @} */

#endif // HIVIEWDFX_HICOLLIE_H