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
 * @brief Provides the C interface in the multi-modal input domain.
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
    /** Pressing of a key */
    KEY_PRESSED = 0,
    /** Release of a key */
    KEY_RELEASED = 1,
    /** Key switch enabled */
    KEY_SWITCH_ON = 2,
    /** Key switch disabled */
    KEY_SWITCH_OFF = 3
};

/**
 * @brief 鼠标动作。
 *
 * @since 12
 */
enum InputEvent_MouseAction {
    /** 取消鼠标操作 */
    MOUSE_ACTION_CANCEL = 0,
    /** 鼠标移动操作 */
    MOUSE_ACTION_MOVE = 1,
    /** 鼠标按键按下操作 */
    MOUSE_ACTION_BUTTON_DOWN = 2,
    /** 鼠标按键抬起操作 */
    MOUSE_ACTION_BUTTON_UP = 3,
    /** 鼠标轴事件开始动作 */
    MOUSE_ACTION_AXIS_BEGIN = 4,
    /** 鼠标轴事件更新动作 */
    MOUSE_ACTION_AXIS_UPDATE = 5,
    /** 鼠标轴事件结束动作 */
    MOUSE_ACTION_AXIS_END = 6,
    /** 鼠标触摸板按下动作 */
    MOUSE_ACTION_ACTION_DOWN = 7,
    /** 鼠标触摸板抬起动作 */
    MOUSE_ACTION_ACTION_UP = 8,
};

/**
 * @brief 鼠标轴类型。
 *
 * @since 12
 */
enum InputEvent_MouseAxis {
    /** 垂直滚动轴 */
    MOUSE_AXIS_SCROLL_VERTICAL = 0,
    /** 水平滚动轴 */
    MOUSE_AXIS_SCROLL_HORIZONTAL = 1,
};

/**
 * @brief 鼠标工具类型。
 *
 * @since 12
 */
enum InputEvent_MouseToolType {
    /** 鼠标 */
    MOUSE_TOOL_TYPE_MOUSE = 0,
    /** 摇杆 */
    MOUSE_TOOL_TYPE_JOYSTICK = 1,
};

/**
 * @brief 触屏行为，包括按下、移动、抬起等。
 *
 * @since 12
 */
enum InputEvent_TouchAction {
    /** 取消触摸操作 */
    TOUCH_ACTION_CANCEL = 0,
    /** 触摸按下操作 */
    TOUCH_ACTION_DOWN = 1,
    /** 触摸移动操作 */
    TOUCH_ACTION_MOVE = 2,
    /** 触摸抬起操作 */
    TOUCH_ACTION_UP = 3,
};

/**
 * @brief 触屏源类型。
 *
 * @since 12
 */
enum InputEvent_TouchSourceType {
    /** 触屏 */
    TOUCH_SOURCE_TYPE_TOUCH_SCREEN = 0,
    /** 手写笔 */
    TOUCH_SOURCE_TYPE_PEN = 1,
    /** 触摸板 */
    TOUCH_SOURCE_TYPE_TOUCH_PAD = 2,
};

/**
 * @brief 触屏工具类型。
 *
 * @since 12
 */
enum InputEvent_TouchToolType {
    /** 手指 */
    TOUCH_TOOLTYPE_FINGER = 0,
    /** 手写笔 */
    TOUCH_TOOLTYPE_PEN = 1,
    /** 橡皮 */
    TOUCH_TOOLTYPE_RUBBER = 2,
    /** 刷子 */
    TOUCH_TOOLTYPE_BRUSH = 3,
    /** 铅笔 */
    TOUCH_TOOLTYPE_PENCIL = 4,
    /** 喷枪 */
    TOUCH_TOOLTYPE_AIRBRUSH = 5,
    /** 鼠标 */
    TOUCH_TOOLTYPE_MOUSE = 6,
    /** 透镜 */
    TOUCH_TOOLTYPE_LENS = 7,
};

/**
 * @brief 设置工具类型。
 *
 * @since 12
 */
enum InputEvent_KeyAction {
    /** 按键释放操作 */
    KEY_ACTION_UNPRESSED = 0,
    /** 按键按下操作 */
    KEY_ACTION_PRESSED = 1,
};

/**
 * @brief Defines key information, which identifies a key pressing behavior. For example, the Ctrl key information contains the key value and key type.
 *
 * @since 12
 */
struct Input_KeyState;

/**
 * @brief 按键事件。
 *
 * @since 12
 */
struct Input_KeyEvent;

/**
 * @brief 鼠标事件。
 *
 * @since 12
 */
struct Input_MouseEvent;

/**
 * @brief 触摸事件。
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
 * @brief Sets the key value of a key status enumeration object.
 * 
 * @param keyState Key status enumeration object.
 * @param keyCode Key value of the key status enumeration object.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetKeyCode(struct Input_KeyState* keyState, int32_t keyCode);

/**
 * @brief Obtains the key value of a key status enumeration object.
 * 
 * @param keyState Key status enumeration object.
 * @return Key value of the key status enumeration object.
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_GetKeyCode(struct Input_KeyState* keyState);

/**
 * @brief 设置按键动作。
 * 
 * @param keyEvent 按键事件。
 * @param keyAction 按键动作。
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetKeyAction(struct Input_KeyEvent* keyEvent, int32_t keyAction);

/**
 * @brief 获取按键动作。
 * 
 * @param keyEvent 按键事件。
 * @return 返回按键枚举对象的动作。
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_GetKeyAction(struct Input_KeyEvent* keyEvent);

/**
 * @brief 设置是否重复输入。
 * 
 * @param keyEvent 按键事件。
 * @param repeat 按键是否重复输入。
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetKeyRepeat(struct Input_KeyEvent* keyEvent, bool repeat);

/**
 * @brief 获取按键是否重复输入。
 * 
 * @param keyEvent 按键事件。
 * @return 返回按键枚举对象是否重复输入。
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
 * @brief 注入按键事件。
 * 
 * @param keyEvent 按键事件。
 * @return 0 - 成功
 *         201 - 权限拒绝
 *         401 - 参数错误
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_InjectKeyEvent(struct Input_KeyEvent* keyEvent);

/**
 * @brief 创建按键事件对象。
 * 
 * @param keyCode 按键键值。
 * @param action 按键动作。
 * @return 如果成功，返回一个Input_KeyEvent的指针对象
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
Input_KeyEvent *OH_Input_CreateKeyEvent(int32_t keyCode, int32_t action);

/**
 * @brief 销毁按键事件对象。
 * 
 * @param keyEvent 按键事件。
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_DestroyKeyEvent(struct Input_KeyEvent** keyEvent);

/**
 * @brief 注入鼠标事件。
 * 
 * @param mouseEvent 鼠标事件。
 * @return 0 - 成功
 *         201 - 权限拒绝
 *         401 - 参数错误
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_InjectMouseEvent(struct Input_MouseEvent* mouseEvent);

/**
 * @brief 创建鼠标事件对象。
 * 
 * @param displayX 鼠标事件的相对屏幕X坐标。
 * @param displayY 鼠标事件的相对屏幕Y坐标。
 * @param action 鼠标事件的动作。
 * @param sourceType 鼠标事件的资源类型。
 * @return 如果成功，返回一个 Input_TouchEvent 的指针对象
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
Input_MouseEvent *OH_Input_CreateMouseEvent(int32_t displayX, int32_t displayY, int32_t action, int32_t sourceType);

/**
 * @brief 销毁鼠标事件对象。
 * 
 * @param mouseEvent 鼠标事件。
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_DestroyMouseEvent(struct Input_MouseEvent** mouseEvent);

/**
 * @brief 注入触摸事件。
 * 
 * @param touchEvent 触摸事件。
 * @return 0 - 成功
 *         201 - 权限拒绝
 *         401 - 参数错误
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_InjectTouchEvent(struct Input_TouchEvent* touchEvent);

/**
 * @brief 创建触摸事件对象。
 * 
 * @param displayX 触摸事件的相对屏幕X坐标。
 * @param displayY 触摸事件的相对屏幕Y坐标。
 * @param action 触摸事件的触屏动作。
 * @param sourceType 触摸事件的资源类型。
 * @param toolType 触摸事件的工具类型。
 * @return 如果成功，返回一个 Input_TouchEvent 的指针对象
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
Input_TouchEvent *OH_Input_CreateTouchEvent(int32_t displayX, int32_t displayY, int32_t action, int32_t sourceType, int32_t toolType);

/**
 * @brief 销毁触摸事件对象。
 * 
 * @param touchEvent 触摸事件。
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_DestroyTouchEvent(struct Input_TouchEvent** touchEvent);

/**
 * @brief 设置相对屏幕X坐标。
 * 
 * @param mouseEvent 鼠标事件。
 * @param displayX X坐标。
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetMouseDisplayX(struct Input_MouseEvent* mouseEvent, int32_t displayX);

/**
 * @brief 获取相对屏幕X坐标。
 * 
 * @param mouseEvent 鼠标事件。
 * @return 返回鼠标事件的相对屏幕X坐标。
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_GetMouseDisplayX(struct Input_MouseEvent* mouseEvent);

/**
 * @brief 设置相对屏幕Y坐标。
 * 
 * @param mouseEvent 鼠标事件。
 * @param displayY Y坐标。
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetMouseDisplayY(struct Input_MouseEvent* mouseEvent, int32_t displayY);

/**
 * @brief 获取相对屏幕Y坐标。
 * 
 * @param mouseEvent 鼠标事件。
 * @return 返回鼠标事件的相对屏幕Y坐标。
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_GetMouseDisplayY(struct Input_MouseEvent* mouseEvent);

/**
 * @brief 设置动作，按下、移动、抬起。
 * 
 * @param mouseEvent 鼠标事件。
 * @param mouseAction 鼠标动作。
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetMouseAction(struct Input_MouseEvent* mouseEvent, int32_t mouseAction);

/**
 * @brief 获取动作，按下、移动、抬起。
 * 
 * @param mouseEvent 鼠标事件。
 * @return 返回鼠标事件的动作。
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_GetMouseAction(struct Input_MouseEvent* mouseEvent);

/**
 * @brief 设置资源类型。
 * 
 * @param mouseEvent 鼠标事件。
 * @param sourceType 资源类型。
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetMouseSourceType(struct Input_MouseEvent* mouseEvent, int32_t sourceType);

/**
 * @brief 获取资源类型。
 * 
 * @param mouseEvent 鼠标事件。
 * @return 返回鼠标事件的资源类型。
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_GetMouseSourceType(struct Input_MouseEvent* mouseEvent);

/**
 * @brief 设置鼠标按键。
 * 
 * @param mouseEvent 鼠标事件。
 * @param buttonId 鼠标按键。
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetButtonId(struct Input_MouseEvent* mouseEvent, int32_t buttonId);

/**
 * @brief 获取鼠标按键。
 * 
 * @param mouseEvent 鼠标事件。
 * @return 返回鼠标事件的按键ID。
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_GetButtonId(struct Input_MouseEvent* mouseEvent);

/**
 * @brief 设置滚轮滚动偏移值。
 * 
 * @param mouseEvent 鼠标事件。
 * @param scrollValue 鼠标按键。
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetScrollValue(struct Input_MouseEvent* mouseEvent, int32_t scrollValue);

/**
 * @brief 获取滚轮偏移值。
 * 
 * @param mouseEvent 鼠标事件。
 * @return 返回鼠标事件的滚轮偏移值。
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_GetScrollValue(struct Input_MouseEvent* mouseEvent);

/**
 * @brief 设置X坐标。
 * 
 * @param touchEvent 触摸事件。
 * @param displayX 触摸事件相对屏幕的X坐标。
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetTouchDisplayX(struct Input_TouchEvent* touchEvent, int32_t displayX);

/**
 * @brief 获取X坐标。
 * 
 * @param touchEvent 触摸事件。
 * @return 返回触摸事件的相对屏幕X坐标。
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_GetTouchDisplayX(struct Input_TouchEvent* touchEvent);

/**
 * @brief 设置Y坐标。
 * 
 * @param touchEvent 触摸事件。
 * @param displayY 触摸事件相对屏幕的Y坐标。
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetTouchDisplayY(struct Input_TouchEvent* touchEvent, int32_t displayY);

/**
 * @brief 获取Y坐标。
 * 
 * @param touchEvent 触摸事件。
 * @return 返回触摸事件的相对屏幕Y坐标。
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_GetTouchDisplayY(struct Input_TouchEvent* touchEvent);

/**
 * @brief 设置动作。
 * 
 * @param touchEvent 触摸事件。
 * @param mouseAction 触摸动作。
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetTouchAction(struct Input_TouchEvent* touchEvent, int32_t mouseAction);

/**
 * @brief 获取动作。
 * 
 * @param touchEvent 触摸事件。
 * @return 返回触摸事件的动作。
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_GetTouchAction(struct Input_TouchEvent* touchEvent);

/**
 * @brief 设置资源类型。
 * 
 * @param touchEvent 触摸事件。
 * @param sourceType 资源类型。
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetTouchSourceType(struct Input_TouchEvent* touchEvent, int32_t sourceType);

/**
 * @brief 获取资源类型。
 * 
 * @param touchEvent 触摸事件。
 * @return 返回触摸事件资源类型。
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_GetTouchSourceType(struct Input_TouchEvent* touchEvent);

/**
 * @brief 设置工具类型。
 * 
 * @param touchEvent 触摸事件。
 * @param toolType 工具类型。
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
void OH_Input_SetTouchToolType(struct Input_TouchEvent* touchEvent, int32_t toolType);

/**
 * @brief 获取工具类型。
 * 
 * @param touchEvent 触摸事件。
 * @return 返回触摸事件工具类型。
 * @syscap SystemCapability.MultimodalInput.Input.Core
 * @since 12
 */
int32_t OH_Input_GetTouchToolType(struct Input_TouchEvent* touchEvent);

#ifdef __cplusplus
}
#endif
/** @} */

#endif /* OH_INPUT_MANAGER_H */
