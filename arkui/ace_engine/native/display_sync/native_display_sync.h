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


#ifndef NATIVE_DISPLAY_SYNC_H
#define NATIVE_DISPLAY_SYNC_H

/**
 * @addtogroup OH_DisplaySync
 * @{
 *
 * @brief Provides the native displaySync capability.
 *
 * @since 12
 * @version 1.0
 */

/**
 * @file native_display_sync.h
 *
 * @brief Defines the functions for obtaining and using a native displaySync.
 * @library libace_ndk.z.so
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @since 12
 * @version 1.0
 */
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defines the native displySync struct.
 *
 * @since 12
 * @version 1.0
 */
typedef struct OH_DisplaySync OH_DisplaySync;

/**
 * @brief Defines the expected frame rate range struct.
 *
 * @since 12
 * @version 1.0
 */
typedef struct {
    /** The minimum frame rate of dynamical callback rate range. */
    int32_t min;
    /** The maximum frame rate of dynamical callback rate range. */
    int32_t max;
    /** The expected frame rate of dynamical callback rate range. */
    int32_t expected;
} DisplaySync_ExpectedRateRange;

/**
 * @brief Creates a <b>OH_DisplaySync</b> instance.\n
 *
 * @return Returns the pointer to the <b>OH_DisplaySync</b> instance.
 * @since 12
 * @version 1.0
 */
OH_DisplaySync* OH_DisplaySync_Create();

/**
 * @brief Add <b>OH_DisplaySync</b> instance to pipeline.\n
 *
 * @param displaySync Indicates the pointer to a native displaySync.
 * @since 12
 * @version 1.0
 */
void OH_DisplaySync_Start(OH_DisplaySync* displaySync);

/**
 * @brief Stop <b>OH_DisplaySync</b> instance from pipeline.\n
 *
 * @param displaySync Indicates the pointer to a native displaySync.
 * @since 12
 * @version 1.0
 */
void OH_DisplaySync_Stop(OH_DisplaySync* displaySync);

/**
 * @brief Registers a callback for this <b>OH_DisplaySync</b> instance.
 *
 * @param displaySync Indicates the pointer to a native displaySync.
 * @param userData Indicates the pointer to user data.
 * @param callback Indicates the pointer to a onFrame callback.
 * @param timestamp Indicates the current timestamp.
 * @param targetTimestamp Indicates the target timestamp.
 * @since 12
 * @version 1.0
 */
void OH_DisplaySync_RegisterCallback(OH_DisplaySync* displaySync, void* userData,
    void (*Callback)(uint64_t timestamp, uint64_t targetTimestamp, void* userData));

/**
 * @brief Unregisters a callback for this <b>OH_DisplaySync</b> instance.
 *
 * @param displaySync Indicates the pointer to a native displaySync.
 * @since 12
 * @version 1.0
 */
void OH_DisplaySync_UnregisterCallback(OH_DisplaySync* displaySync);

/**
 * @brief Set the Expected FrameRateRange.
 *
 * @param displaySync Indicates the pointer to a native displaySync.
 * @param range Indicates the pointer to a expected rate range.
 * @since 12
 * @version 1.0
 */
void OH_DisplaySync_SetExpectedFrameRateRange(
    OH_DisplaySync* displaySync, DisplaySync_ExpectedRateRange* range);

/**
 * @brief Destroy a <b>OH_DisplaySync</b> instance.\n
 *
 * @param displaySync Indicates the pointer to a native displaySync.
 * @since 12
 * @version 1.0
 */
void OH_DisplaySync_Destroy(OH_DisplaySync* displaySync);

#ifdef __cplusplus
}
#endif

#endif
/** @} */