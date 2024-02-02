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

#ifndef CAPI_INPUT_EVENT_H
#define CAPI_INPUT_EVENT_H

/**
 * @addtogroup OHInput
 * @{
 *
 * @brief Provides the C interface in the multi-modal input domain.
 *
 * @since 11
 * @version 1.0
 */

/**
 * @file capi_input_event.h
 *
 * @brief Provides C interfaces for multi-modal event injection.
 *
 * @syscap SystemCapability.MultimodalInput.Input.InputSimulator
 * @library libohinput.so
 * @since 11
 * @version 1.0
 */

#include <stdint.h>
#include "capi_key_event.h"
#include "capi_mouse_event.h"
#include "capi_touch_event.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Inject system keys.
 *
 * @param keyEvent - the key event to be injected.
 * @return 0 - Success.
 *         201 - Missing permissions.
 *         202 - SystemAPI permission error.
 *         401 - Parameter error.
 * @permission systemapi hide for inner use
 * @syscap SystemCapability.MultimodalInput.Input.InputSimulator
 * @since 11
 * @version 1.0
 */
int32_t OH_InputEventClient_InjectEvent(struct OH_KeyEvent* keyEvent);

/**
 * @brief Inject mouse event.
 *
 * @param mouseEvent - the mouse event to be injected.
 * @return 0 - Success.
 *         201 - Missing permissions.
 *         202 - SystemAPI permission error.
 *         401 - Parameter error.
 * @permission systemapi hide for inner use
 * @syscap SystemCapability.MultimodalInput.Input.InputSimulator
 * @since 11
 * @version 1.0
 */
int32_t OH_InputEventClient_InjectMouseEvent(struct OH_MouseEvent* mouseEvent);

/**
 * @brief Inject touch event.
 *
 * @param touchEvent - the touch event to be injected.
 * @return 0 - Success.
 *         201 - Missing permissions.
 *         202 - SystemAPI permission error.
 *         401 - Parameter error.
 * @permission systemapi hide for inner use
 * @syscap SystemCapability.MultimodalInput.Input.InputSimulator
 * @since 11
 * @version 1.0
 */
int32_t OH_InputEventClient_InjectTouchEvent(struct OH_TouchEvent* touchEvent);

#ifdef __cplusplus
}
#endif
#endif // CAPI_INPUT_EVENT_H
