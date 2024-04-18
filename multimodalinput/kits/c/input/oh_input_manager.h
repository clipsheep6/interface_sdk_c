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
 * @brief Enumerates key event types.
 *
 * @since 12
 */
typedef enum {
    /** Cancellation of a key action. */
    KEY_ACTION_CANCEL = 0,
    /** Pressing of a key. */
    KEY_ACTION_DOWN = 1,
    /** Release of a key. */
    KEY_ACTION_UP = 2,
} Input_KeyEventAction;

/**
 * @brief Enumerated values of mouse event action.
 *
 * @since 12
 */
typedef enum {
    /** Cancel. */
    MOUSE_ACTION_CANCEL = 0,
    /** Moving of the mouse pointer. */
    MOUSE_ACTION_MOVE = 1,
    /** Pressing down of the mouse. */
    MOUSE_ACTION_BUTTON_DOWN = 2,
    /** Lifting of the mouse button. */
    MOUSE_ACTION_BUTTON_UP = 3,
    /** Beginning of the mouse axis event */
    MOUSE_ACTION_AXIS_BEGIN = 4,
    /** Updating of the mouse axis event */
    MOUSE_ACTION_AXIS_UPDATE = 5,
    /** End of the mouse axis event */
    MOUSE_ACTION_AXIS_END = 6,
} Input_MouseEventAction;

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
 * @brief Enumerated values of mouse event button.
 *
 * @since 12
 */
typedef enum {
    /** Invalid button */
    MOUSE_BUTTON_NONE = -1,
    /** Left button on the mouse. */
    MOUSE_BUTTON_LEFT = 0,
    /** Middle button on the mouse. */
    MOUSE_BUTTON_MIDDLE = 1,
    /** Right button on the mouse. */
    MOUSE_BUTTON_RIGHT = 2,
    /** Forward button on the mouse. */
    MOUSE_BUTTON_FORWARD = 3,
    /** Back button on the mouse. */
    MOUSE_BUTTON_BACK = 4,
} Input_MouseEventButton;

/**
 * @brief Enumerated values of touch event action.
 *
 * @since 12
 */
typedef enum {
    /** Touch cancelled. */
    TOUCH_ACTION_CANCEL = 0,
    /** Touch pressed. */
    TOUCH_ACTION_DOWN = 1,
    /** Touch moved. */
    TOUCH_ACTION_MOVE = 2,
    /** Touch lifted. */
    TOUCH_ACTION_UP = 3,
} Input_TouchEventAction;

/**
 * @brief Defines key information, which identifies a key pressing behavior. For example, the Ctrl key information contains the key value and key type.
 *
 * @since 12
 */
struct Input_KeyState;

/**
 * @brief The key event to be injected.
 *
 * @since 12
 */
struct Input_KeyEvent;

/**
 * @brief The mouse event to be injected.
 *
 * @since 12
 */
struct Input_MouseEvent;

/**
 * @brief The touch event to be injected.
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
void OH_Input_DestroyKeyState(struct Input_KeyState** keyState);

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
int32_t OH_Input_GetKeyCode(const struct Input_KeyState* keyState);

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
int32_t OH_Input_GetKeyPressed(const struct Input_KeyState* keyState);

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
int32_t OH_Input_GetKeySwitch(const struct Input_KeyState* keyState);

/**
 * @brief Inject system keys.
 *
 * @param keyEvent - the key event to be injected.
 * @return 0 - Success.
 *         201 - Missing permissions.
 *         401 - Parameter error.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_InjectKeyEvent(const struct Input_KeyEvent* keyEvent);

/**
 * @brief Creates a key event object.
 *
 * @return Returns an {@link Input_KeyEvent} pointer object if the operation is successful.
 * returns a null pointer otherwise.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
struct Input_KeyEvent* OH_Input_CreateKeyEvent();

/**
 * @brief Destroys a key event object.
 *
 * @param keyEvent Key event object.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_DestroyKeyEvent(struct Input_KeyEvent** keyEvent);

/**
 * @brief Sets the key event type.
 *
 * @param keyEvent Key event object.
 * @param action Key event type.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetKeyEventAction(struct Input_KeyEvent* keyEvent, int32_t action);

/**
 * @brief Obtains the key event type.
 *
 * @param keyEvent Key event object.
 * @return Key event type.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_GetKeyEventAction(const struct Input_KeyEvent* keyEvent);

/**
 * @brief Sets the key value for a key event.
 *
 * @param keyEvent Key event object.
 * @param keyCode keyCode Key code.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetKeyEventKeyCode(struct Input_KeyEvent* keyEvent, int32_t keyCode);

/**
 * @brief Obtains the key value of a key event.
 *
 * @param keyEvent Key event object.
 * @return Key code.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_GetKeyEventKeyCode(const struct Input_KeyEvent* keyEvent);

/**
 * @brief Sets the time when a key event occurs.
 *
 * @param keyEvent Key event object.
 * @param actionTime Time when the key event occurs.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetKeyEventActionTime(struct Input_KeyEvent* keyEvent, int64_t actionTime);

/**
 * @brief Obtains the time when a key event occurs.
 *
 * @param keyEvent Key event object.
 * @return Returns the time when the key event occurs.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int64_t OH_Input_GetKeyEventActionTime(const struct Input_KeyEvent* keyEvent);

/**
 * @brief Inject mouse event.
 *
 * @param mouseEvent - the mouse event to be injected.
 * @return 0 - Success.
 *         201 - Missing permissions.
 *         401 - Parameter error.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_InjectMouseEvent(const struct Input_MouseEvent* mouseEvent);

/**
 * @brief Creates a mouse event object.
 *
 * @return Returns an {@link Input_MouseEvent} pointer object if the operation is successful.
 * returns a null pointer otherwise.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
struct Input_MouseEvent* OH_Input_CreateMouseEvent();

/**
 * @brief Destroys a mouse event object.
 *
 * @param mouseEvent Mouse event object.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_DestroyMouseEvent(struct Input_MouseEvent** mouseEvent);

/**
 * @brief Sets the action for a mouse event.
 *
 * @param mouseEvent Mouse event object.
 * @param action Mouse action.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetMouseEventAction(struct Input_MouseEvent* mouseEvent, int32_t action);

/**
 * @brief Obtains the action of a mouse event.
 *
 * @param mouseEvent Mouse event object.
 * @return Mouse action.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_GetMouseEventAction(const struct Input_MouseEvent* mouseEvent);

/**
 * @brief Sets the X coordinate for a mouse event.
 *
 * @param mouseEvent Mouse event object.
 * @param displayX  X coordinate on the display.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetMouseEventDisplayX(struct Input_MouseEvent* mouseEvent, int32_t displayX);

/**
 * @brief Obtains the X coordinate of a mouse event.
 *
 * @param mouseEvent Mouse event object.
 * @return X coordinate on the display.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_GetMouseEventDisplayX(const struct Input_MouseEvent* mouseEvent);

/**
 * @brief Sets the Y coordinate for a mouse event.
 *
 * @param mouseEvent Mouse event object.
 * @param displayY Y coordinate on the display.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetMouseEventDisplayY(struct Input_MouseEvent* mouseEvent, int32_t displayY);

/**
 * @brief Obtains the Y coordinate of a mouse event.
 *
 * @param mouseEvent Mouse event object.
 * @return Y coordinate on the display.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_GetMouseEventDisplayY(const struct Input_MouseEvent* mouseEvent);

/**
 * @brief Sets the button for a mouse event.
 *
 * @param mouseEvent Mouse event object.
 * @param button Mouse button.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetMouseEventButton(struct Input_MouseEvent* mouseEvent, int32_t button);

/**
 * @brief Obtains the button of a mouse event.
 *
 * @param mouseEvent Mouse event object.
 * @return Mouse button.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_GetMouseEventButton(const struct Input_MouseEvent* mouseEvent);

/**
 * @brief Sets the axis type for mouse event.
 *
 * @param mouseEvent Mouse event object.
 * @param axisType Axis type, for example, X axis or Y axis.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetMouseEventAxisType(struct Input_MouseEvent* mouseEvent, int32_t axisType);

/**
 * @brief Obtains the axis type of a mouse event.
 *
 * @param mouseEvent Mouse event object.
 * @return Axis type.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_GetMouseEventAxisType(const struct Input_MouseEvent* mouseEvent);

/**
 * @brief Sets the axis value for a mouse axis event.
 *
 * @param mouseEvent Mouse event object.
 * @param axisType Axis value. A positive value means scrolling forward, and a negative number means scrolling backward.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetMouseEventAxisValue(struct Input_MouseEvent* mouseEvent, float axisValue);

/**
 * @brief Obtains the axis value of a mouse event.
 *
 * @param mouseEvent Mouse event object.
 * @return Axis value.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
float OH_Input_GetMouseEventAxisValue(const struct Input_MouseEvent* mouseEvent);

/**
 * @brief Sets the time when a mouse event occurs.
 *
 * @param mouseEvent Mouse event object.
 * @param actionTime Time when the mouse event occurs.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetMouseEventActionTime(struct Input_MouseEvent* mouseEvent, int64_t actionTime);

/**
 * @brief Obtains the time when a mouse event occurs.
 *
 * @param keyEvent Mouse event object.
 * @return Returns the time when the mouse event occurs.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int64_t OH_Input_GetMouseEventActionTime(const struct Input_MouseEvent* mouseEvent);

/**
 * @brief Inject touch event.
 *
 * @param touchEvent - the touch event to be injected.
 * @return 0 - Success.
 *         201 - Missing permissions.
 *         401 - Parameter error.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_InjectTouchEvent(const struct Input_TouchEvent* touchEvent);

/**
 * @brief Creates a touch event object.
 *
 * @return Returns an {@link Input_TouchEvent} pointer object if the operation is successful.
 * returns a null pointer otherwise.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
struct Input_TouchEvent* OH_Input_CreateTouchEvent();

/**
 * @brief Destroys a touch event object.
 *
 * @param touchEvent Touch event object.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_DestroyTouchEvent(struct Input_TouchEvent** touchEvent);

/**
 * @brief Sets the action for a touch event.
 *
 * @param touchEvent Touch event object.
 * @param action Touch action.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetTouchEventAction(struct Input_TouchEvent* touchEvent, int32_t action);

/**
 * @brief Obtains the action of a touch event.
 *
 * @param touchEvent Touch event object.
 * @return Touch action.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_GetTouchEventAction(const struct Input_TouchEvent* touchEvent);

/**
 * @brief Sets the finger ID for the touch event.
 *
 * @param touchEvent Touch event object.
 * @param id Finger ID.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetTouchEventFingerId(struct Input_TouchEvent* touchEvent, int32_t id);

/**
 * @brief Obtains the finger ID of a touch event.
 *
 * @param touchEvent Touch event object.
 * @return Finger ID.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_GetTouchEventFingerId(const struct Input_TouchEvent* touchEvent);

/**
 * @brief Sets the X coordinate for a touch event.
 *
 * @param touchEvent Touch event object.
 * @param displayX X coordinate.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetTouchEventDisplayX(struct Input_TouchEvent* touchEvent, int32_t displayX);

/**
 * @brief Obtains the X coordinate of a touch event.
 *
 * @param touchEvent Touch event object.
 * @return X coordinate.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_GetTouchEventDisplayX(const struct Input_TouchEvent* touchEvent);

/**
 * @brief Sets the Y coordinate for a touch event.
 *
 * @param touchEvent Touch event object.
 * @param displayY Y coordinate.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetTouchEventDisplayY(struct Input_TouchEvent* touchEvent, int32_t displayY);

/**
 * @brief Obtains the Y coordinate of a touch event.
 *
 * @param touchEvent Touch event object.
 * @return Y coordinate.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_GetTouchEventDisplayY(const struct Input_TouchEvent* touchEvent);

/**
 * @brief Sets the time when a touch event occurs.
 *
 * @param keyEvent Touch event object.
 * @param actionTime Time when the touch event occurs.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetTouchEventActionTime(struct Input_TouchEvent* touchEvent, int64_t actionTime);

/**
 * @brief Obtains the time when a touch event occurs.
 *
 * @param keyEvent touch event object.
 * @return Returns the time when the touch event occurs.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int64_t OH_Input_GetTouchEventActionTime(const struct Input_TouchEvent* touchEvent);

/**
 * @brief Cancels event injection and revokes authorization.
 *
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_CancelInjection();

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
