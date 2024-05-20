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

#ifndef QOS_H
#define QOS_H
/**
 * @addtogroup QoS
 * @{
 *
 * @brief QoS provides APIs.
 *
 * @since 12
 */
 
/**
 * @file qos.h
 *
 * @brief Declares the QoS interfaces in C.
 *
 * Quality-of-service (QoS) refers to the priority scheduling attribute of tasks
 * in OpenHarmony. Developers can use QoS to categorize tasks to be executed to
 * indicate the degree of their relevance to user interactions, the system can
 * schedule the time and running order of tasks according to the QoS set by the tasks.
 *
 * @library libqos.so
 * @syscap SystemCapability.Resourceschedule.QoS.Core
 * @since 12
 */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Describes the level of QoS.
 *
 * @since 12
 */
typedef enum QoS_Level {
    /**
     * @brief Means the QoS level is background.
     */
    QOS_BACKGROUND = 0,

    /**
     * @brief Means the QoS level is utility.
     */
    QOS_UTILITY,

    /**
     * @brief Means the QoS level is default.
     */
    QOS_DEFAULT,

    /**
     * @brief Means the QoS level is user-initiated.
     */
    QOS_USER_INITIATED,

    /**
     * @brief Means the QoS level is user-request.
     */
    QOS_DEADLINE_REQUEST,

    /**
     * @brief Means the QoS level is user-interactive.
     */
    QOS_USER_INTERACTIVE,
} QoS_Level;

/**
  *@brief Enum of qos error code.
  *
  *@since@ 12
*/
typedef enum QoS_ErrCode {
    /** @error Operation sucess*/
    QOS_SUCCESS = 0,
    /** @error Operation failde*/
    QOS_FAILURE = -1,
    /** @error Invalid parameter */
    QOS_INVALID_PARAMETR = -2,
    /** @error Operation not allowed*/
    QOS_NOT_ALLOWED = -3,
    /** @error Operation not supported*/
    QOS_NO_SUPPORT = -4
} QoS_ErrCode;

/**
 * @brief Set the QoS level of the current thread.
 *
 * @param level Indicates the level to set. Specific level can be referenced {@link QoS_Level}.
 * @return {@link QOS_SUCCESS} the operation is successful.
 *         {@link QOS_FAILURE} permission check failed or internal error failed.
 *         {@link QOS_INVALID_PARAMETR} level is out of range.
 * @see QoS_Level
 * @since 12
 */
int OH_QoS_SetThreadQoS(QoS_Level level);

/**
 * @brief Cancel the QoS level of the current thread.
 *
 * @return {@link QOS_SUCCESS} the operation is successful.
 *         {@link QOS_FAILURE} permission check failed or internal error failed.
 * @see QoS_Level
 * @since 12
 */
int OH_QoS_ResetThreadQoS();

/**
 * @brief Obtains the QoS level of the current thread.
 *
 * @param level This parameter is the output parameter,
 * and the QoS level of the thread as a {@link QoS_Level} is written to this variable.
 * @return {@link QOS_SUCCESS} the operation is successful.
 *         {@link QOS_FAILURE} permission check failed or internal error failed.
 *         {@link QOS_INVALID_PARAMETR} level is null.
 * @see QoS_Level
 * @since 12
 */
int OH_QoS_GetThreadQoS(QoS_Level *level);
#ifdef __cplusplus
};
#endif
#endif //QOS_H
