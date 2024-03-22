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

#ifndef OH_INPUT_MANAGER_H
#define OH_INPUT_MANAGER_H

/**
 * @addtogroup input
 * @{
 *
 * @brief Provides C APIs of the multimodal input module.
 *
 * @since 12
 */

/**
 * @file oh_input_manager.h
 *
 * @brief Provides capabilities such as event injection and key status query.
 *
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @library liboh_input.so
 * @since 12
 */

#include <stdint.h>

#include "oh_key_code.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Enumerated values of key event action.
 *
 * @since 12
 */
enum Input_KeyStateAction {
    /** Default */
    KEY_DEFAULT = -1,
    /** Key pressed */
    KEY_PRESSED = 0,
    /** Key released */
    KEY_RELEASED = 1,
    /** Key switch enabled */
    KEY_SWITCH_ON = 2,
    /** Key switch disabled */
    KEY_SWITCH_OFF = 3
};

/**
 * @brief Mouse actions.
 *
 * @since 12
 */
enum InputEvent_MouseAction {
    /** Cancelling of the mouse action */
    MOUSE_ACTION_CANCEL = 0,
    /** Moving of the mouse */
    MOUSE_ACTION_MOVE = 1,
    /** Pressing of the mouse button */
    MOUSE_ACTION_BUTTON_DOWN = 2,
    /** Releasing of the mouse button */
    MOUSE_ACTION_BUTTON_UP = 3,
    /** Beginning of the mouse axis event */
    MOUSE_ACTION_AXIS_BEGIN = 4,
    /** Updating of the mouse axis event */
    MOUSE_ACTION_AXIS_UPDATE = 5,
    /** End of the mouse axis event */
    MOUSE_ACTION_AXIS_END = 6,
    /** Finger pressing on the touchpad */
    MOUSE_ACTION_ACTION_DOWN = 7,
    /** Finger lifting from the touchpad */
    MOUSE_ACTION_ACTION_UP = 8,
};

/**
 * @brief Mouse axis types.
 *
 * @since 12
 */
enum InputEvent_MouseAxis {
    /** Vertical scroll axis */
    MOUSE_AXIS_SCROLL_VERTICAL = 0,
    /** Horizontal scroll axis */
    MOUSE_AXIS_SCROLL_HORIZONTAL = 1,
};

/**
 * @brief Mouse tool types.
 *
 * @since 12
 */
enum InputEvent_MouseToolType {
    /** Mouse */
    MOUSE_TOOL_TYPE_MOUSE = 0,
    /** Joystick */
    MOUSE_TOOL_TYPE_JOYSTICK = 1,
};

/**
 * @brief Touch actions, including pressing, moving, and lifting.
 *
 * @since 12
 */
enum InputEvent_TouchAction {
    /** Cancelling of the touch operation */
    TOUCH_ACTION_CANCEL = 0,
    /** Pressing */
    TOUCH_ACTION_DOWN = 1,
    /** Moving */
    TOUCH_ACTION_MOVE = 2,
    /** Lifting */
    TOUCH_ACTION_UP = 3,
};

/**
 * @brief Touchscreen source types.
 *
 * @since 12
 */
enum InputEvent_TouchSourceType {
    /** Touchscreen */
    TOUCH_SOURCE_TYPE_TOUCH_SCREEN = 0,
    /** Stylus */
    TOUCH_SOURCE_TYPE_PEN = 1,
    /** Touchpad */
    TOUCH_SOURCE_TYPE_TOUCH_PAD = 2,
};

/**
 * @brief Touchscreen tool types.
 *
 * @since 12
 */
enum InputEvent_TouchToolType {
    /** Finger */
    TOUCH_TOOLTYPE_FINGER = 0,
    /** Stylus */
    TOUCH_TOOLTYPE_PEN = 1,
    /** Rubber */
    TOUCH_TOOLTYPE_RUBBER = 2,
    /** Brush */
    TOUCH_TOOLTYPE_BRUSH = 3,
    /** Pencil */
    TOUCH_TOOLTYPE_PENCIL = 4,
    /** Air brush */
    TOUCH_TOOLTYPE_AIRBRUSH = 5,
    /** Mouse */
    TOUCH_TOOLTYPE_MOUSE = 6,
    /** Lens */
    TOUCH_TOOLTYPE_LENS = 7,
};

/**
 * @brief Sets the tool type.
 *
 * @since 12
 */
enum InputEvent_KeyAction {
    /** Key releasing */
    KEY_ACTION_UNPRESSED = 0,
    /** Key pressing */
    KEY_ACTION_PRESSED = 1,
};

/**
 * @brief Defines key information, which identifies a key pressing behavior. For example, the Ctrl key information contains the key code and key type.
 *
 * @since 12
 */
struct Input_KeyState;

/**
 * @brief Key events.
 *
 * @since 12
 */
struct Input_KeyEvent;

/**
 * @brief Mouse events.
 *
 * @since 12
 */
struct Input_MouseEvent;

/**
 * @brief Touch events.
 *
 * @since 12
 */
struct Input_TouchEvent;

/**
 * @brief Enumerates the error codes.
 *
 * @since 12
 */
typedef enum {
    /** Success */
    INPUT_SUCCESS = 0,
    /** Permission verification failed */
    INPUT_PERMISSION_DENIED = 201,
    /** Non-system application */
    INPUT_NOT_SYSTEM_APPLICATION = 202,
    /** Parameter check failed */
    INPUT_PARAMETER_ERROR = 401
} Input_Result;

/**
 * @brief Queries the key state.
 *
 * @param keyState Key state.
 * @HTTP4O4 Returns {@Link Input_Result#INPUT_SUCCESS} if the operation is successful;
 * returns an error code defined in {@Link Input_Result} otherwise.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
Input_Result OH_Input_GetKeyState(struct Input_KeyState* keyState);

/**
 * @brief Creates a key status enumeration object.
 *
 * @return Returns an {@link Input_KeyState} pointer object if the operation is successful.
 * returns a null pointer otherwise.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
struct Input_KeyState* OH_Input_CreateKeyState();

/**
 * @brief Destroys a key status enumeration object.
 * 
 * @param keyState Key status enumeration object.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_DestroyKeyState(struct Input_KeyState* keyState);

/**
 * @brief Sets the key code of a key status enumeration object.
 * 
 * @param keyState Key status enumeration object.
 * @param keyCode Key code of the key status enumeration object.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetKeyCode(struct Input_KeyState* keyState, int32_t keyCode);

/**
 * @brief Obtains the key code of a key status enumeration object.
 * 
 * @param keyState Key status enumeration object.
 * @return Key code of the key status enumeration object.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_GetKeyCode(struct Input_KeyState* keyState);

/**
 * @brief Sets the key action.
 * 
 * @param keyEvent Key event.
 * @param keyAction Key action.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetKeyAction(struct Input_KeyEvent* keyEvent, int32_t keyAction);

/**
 * @brief Obtains the key action.
 * 
 * @param keyEvent Key event.
 * @return Action of the key enumeration object.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_GetKeyAction(struct Input_KeyEvent* keyEvent);

/**
 * @brief Sets whether to enable repeated input of keys.
 * 
 * @param keyEvent Key event.
 * @param repeat Whether to enable repeated input of keys.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetKeyRepeat(struct Input_KeyEvent* keyEvent, bool repeat);

/**
 * @brief Obtains whether repeated input of keys is enabled.
 * 
 * @param keyEvent Key event.
 * @return Result indicating whether repeated input of keys is enabled.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
bool OH_Input_GetKeyRepeat(struct Input_KeyEvent* keyEvent);

/**
 * @brief Sets whether the key specific to a key status enumeration object is pressed.
 * 
 * @param keyState Key status enumeration object.
 * @param keyAction Whether the key is pressed.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetKeyPressed(struct Input_KeyState* keyState, int32_t keyAction);

/**
 * @brief Checks whether the key specific to a key status enumeration object is pressed.
 * 
 * @param keyState Key status enumeration object.
 * @return Key pressing status of the key status enumeration object.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_GetKeyPressed(struct Input_KeyState* keyState);

/**
 * @brief Sets the key switch of the key status enumeration object.
 * 
 * @param keyState Key status enumeration object.
 * @param keySwitch Key switch of the key status enumeration object.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetKeySwitch(struct Input_KeyState* keyState, int32_t keySwitch);

/**
 * @brief Obtains the key switch of the key status enumeration object.
 * 
 * @param keyState Key status enumeration object.
 * @return Key switch of the key status enumeration object.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_GetKeySwitch(struct Input_KeyState* keyState);

/**
 * @brief Injects a key event.
 * 
 * @param keyEvent Key event.
 * @return 0 - success
 *         201 - permission denied
 *         401 - parameter error
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_InjectKeyEvent(struct Input_KeyEvent* keyEvent);

/**
 * @brief Creates a key event object.
 * 
 * @param keyCode Key code.
 * @param action Key action.
 * @return an Input_KeyEvent pointer object if the operation is successful.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
Input_KeyEvent *OH_Input_CreateKeyEvent(int32_t keyCode, int32_t action);

/**
 * @brief Destroys a key event object.
 * 
 * @param keyEvent Key event.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_DestroyKeyEvent(struct Input_KeyEvent** keyEvent);

/**
 * @brief Injects a mouse event.
 * 
 * @param mouseEvent Mouse event.
 * @return 0 - success
 *         201 - permission denied
 *         401 - parameter error
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_InjectMouseEvent(struct Input_MouseEvent* mouseEvent);

/**
 * @brief Creates a mouse event object.
 * 
 * @param displayX X coordinate relative to the screen.
 * @param displayY Y coordinate relative to the screen.
 * @param action Action of the mouse event.
 * @param sourceType Resource type of the mouse event.
 * @return an Input_TouchEvent pointer object if the operation is successful.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
Input_MouseEvent *OH_Input_CreateMouseEvent(int32_t displayX, int32_t displayY, int32_t action, int32_t sourceType);

/**
 * @brief Destroys a mouse event object.
 * 
 * @param mouseEvent Mouse event.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_DestroyMouseEvent(struct Input_MouseEvent** mouseEvent);

/**
 * @brief Injects a touch event.
 * 
 * @param touchEvent Touch event.
 * @return 0 - success
 *         201 - permission denied
 *         401 - parameter error
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_InjectTouchEvent(struct Input_TouchEvent* touchEvent);

/**
 * @brief Creates a touch event object.
 * 
 * @param displayX X coordinate relative to the screen.
 * @param displayY Y coordinate relative to the screen.
 * @param action Touch action of the touch event.
 * @param sourceType Resource type of the touch event.
 * @param toolType Tool type of the touch event.
 * @return an Input_TouchEvent pointer object if the operation is successful.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
Input_TouchEvent *OH_Input_CreateTouchEvent(int32_t displayX, int32_t displayY, int32_t action, int32_t sourceType, int32_t toolType);

/**
 * @brief Destroys a touch event object.
 * 
 * @param touchEvent Touch event.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_DestroyTouchEvent(struct Input_TouchEvent** touchEvent);

/**
 * @brief Sets the X coordinate relative to the screen.
 * 
 * @param mouseEvent Mouse event.
 * @param displayX X coordinate.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetMouseDisplayX(struct Input_MouseEvent* mouseEvent, int32_t displayX);

/**
 * @brief Obtains the X coordinate relative to the screen.
 * 
 * @param mouseEvent Mouse event.
 * @return X coordinate relative to the screen.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_GetMouseDisplayX(struct Input_MouseEvent* mouseEvent);

/**
 * @brief Sets the Y coordinate relative to the screen.
 * 
 * @param mouseEvent Mouse event.
 * @param displayY Y coordinate.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetMouseDisplayY(struct Input_MouseEvent* mouseEvent, int32_t displayY);

/**
 * @brief Obtains the Y coordinate relative to the screen.
 * 
 * @param mouseEvent Mouse event.
 * @return Y coordinate relative to the screen.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_GetMouseDisplayY(struct Input_MouseEvent* mouseEvent);

/**
 * @brief Sets the action, which can be pressing, moving, and lifting.
 * 
 * @param mouseEvent Mouse event.
 * @param mouseAction Mouse action.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetMouseAction(struct Input_MouseEvent* mouseEvent, int32_t mouseAction);

/**
 * @brief Obtains actions, such as pressing, moving, and lifting.
 * 
 * @param mouseEvent Mouse event.
 * @return Mouse action.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_GetMouseAction(struct Input_MouseEvent* mouseEvent);

/**
 * @brief Sets the resource type.
 * 
 * @param mouseEvent Mouse event.
 * @param sourceType Resource type.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetMouseSourceType(struct Input_MouseEvent* mouseEvent, int32_t sourceType);

/**
 * @brief Obtains the resource type.
 * 
 * @param mouseEvent Mouse event.
 * @return Resource type of the mouse event.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_GetMouseSourceType(struct Input_MouseEvent* mouseEvent);

/**
 * @brief Sets the mouse button.
 * 
 * @param mouseEvent Mouse event.
 * @param buttonId Mouse button.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetButtonId(struct Input_MouseEvent* mouseEvent, int32_t buttonId);

/**
 * @brief Obtains the mouse button.
 * 
 * @param mouseEvent Mouse event.
 * @return ID of the mouse button.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_GetButtonId(struct Input_MouseEvent* mouseEvent);

/**
 * @brief Sets the offset of the scroll wheel.
 * 
 * @param mouseEvent Mouse event.
 * @param scrollValue Offset of the scroll wheel.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetScrollValue(struct Input_MouseEvent* mouseEvent, int32_t scrollValue);

/**
 * @brief Obtains the offset of the scroll wheel.
 * 
 * @param mouseEvent Mouse event.
 * @return Offset of the scroll wheel.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_GetScrollValue(struct Input_MouseEvent* mouseEvent);

/**
 * @brief Sets the X coordinate.
 * 
 * @param touchEvent Touch event.
 * @param displayX X coordinate relative to the screen.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetTouchDisplayX(struct Input_TouchEvent* touchEvent, int32_t displayX);

/**
 * @brief Obtains the X coordinate.
 * 
 * @param touchEvent Touch event.
 * @return X coordinate relative to the screen.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_GetTouchDisplayX(struct Input_TouchEvent* touchEvent);

/**
 * @brief Sets the Y coordinate.
 * 
 * @param touchEvent Touch event.
 * @param displayY Y coordinate relative to the screen.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetTouchDisplayY(struct Input_TouchEvent* touchEvent, int32_t displayY);

/**
 * @brief Obtains the Y coordinate.
 * 
 * @param touchEvent Touch event.
 * @return Y coordinate relative to the screen.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_GetTouchDisplayY(struct Input_TouchEvent* touchEvent);

/**
 * @brief Sets the touch action.
 * 
 * @param touchEvent Touch event.
 * @param mouseAction Touch action.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetTouchAction(struct Input_TouchEvent* touchEvent, int32_t mouseAction);

/**
 * @brief Obtains the touch action.
 * 
 * @param touchEvent Touch event.
 * @return Touch action.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_GetTouchAction(struct Input_TouchEvent* touchEvent);

/**
 * @brief Sets the resource type.
 * 
 * @param touchEvent Touch event.
 * @param sourceType Resource type.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetTouchSourceType(struct Input_TouchEvent* touchEvent, int32_t sourceType);

/**
 * @brief Obtains the resource type.
 * 
 * @param touchEvent Touch event.
 * @return Resource type.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_GetTouchSourceType(struct Input_TouchEvent* touchEvent);

/**
 * @brief Sets the tool type.
 * 
 * @param touchEvent Touch event.
 * @param toolType Tool type.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetTouchToolType(struct Input_TouchEvent* touchEvent, int32_t toolType);

/**
 * @brief Obtains the tool type.
 * 
 * @param touchEvent Touch event.
 * @return Tool type.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_GetTouchToolType(struct Input_TouchEvent* touchEvent);

#ifdef __cplusplus
}
#endif
/** @} */

#endif /* OH_INPUT_MANAGER_H */
