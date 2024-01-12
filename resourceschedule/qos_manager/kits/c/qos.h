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

#ifndef QOS_H
#define QOS_H
/**
 * @addtogroup QoS
 * @{
 *
 * @brief QoS provides APIs.
 *
 * @since 11
 */
 
/**
 * @file qos.h
 *
 * @brief Declares the QoS interfaces in C.
 * @library libqos.z.so
 * @syscap SystemCapability.Resourceschedule.QoS.Core
 * @since 11
 */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Describes the level of QoS.
 *
 * @since 11
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
     * @brief Means the QoS level is deadline-request.
     */
    QOS_DEADLINE_REQUEST,

    /**
     * @brief Means the QoS level is user-interactive.
     */
    QOS_USER_INTERACTIVE,
} QoS_Level;

/**
 * @brief Set the QoS level of the current thread.
 *
 * @param level Indicates the level to set. Specific level can be referenced {@link QoS_Level}.
 * @return Returns int32_t, return value == 0, success, otherwise value == -1, failed.
 * @see QoS_Level
 * @since 11
 */
int OH_QoS_SetThreadQoS(QoS_Level level);

/**
 * @brief Cancel the QoS level of the current thread.
 *
 * @return Returns int32_t, return value == 0, success, otherwise value == -1, failed.
 * @see QoS_Level
 * @since 11
 */
int OH_QoS_ResetThreadQoS();

/**
 * @brief Obtains the QoS level of the current thread.
 *
 * @param level This parameter is the output parameter,
 * and the QoS level of the thread as a {@link QoS_Level} is written to this variable.
 * @return Returns int32_t, return value == 0, success, otherwise value == -1, failed.
 * @see QoS_Level
 * @since 11
 */
int OH_QoS_GetThreadQoS(QoS_Level *level);
#ifdef __cplusplus
};
#endif
#endif //QOS_H
