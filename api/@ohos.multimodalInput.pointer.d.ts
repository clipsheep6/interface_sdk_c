/*
* Copyright (c) 2022-2023 Huawei Device Co., Ltd.
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

import { AsyncCallback } from "./@ohos.base";

/**
 * Declares interfaces related to mouse pointer attributes.
 *
 * @since 9
 * @syscap SystemCapability.MultimodalInput.Input.Pointer
 */
declare namespace pointer {
  /**
   * Pointer style.
   * 
   * @since 9
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   */
  enum PointerStyle {
    /**
     * Default
     */
    DEFAULT,

    /**
     * East arrow
     */
    EAST,

    /**
     * West arrow
     */
    WEST,

    /**
     * South arrow
     */
    SOUTH,

    /**
     * North arrow
     */
    NORTH,

    /**
     * East-west arrow
     */
    WEST_EAST,

    /**
     * North-south arrow
     */
    NORTH_SOUTH,

    /**
     * North-east arrow
     */
    NORTH_EAST,

    /**
     * North-west arrow
     */
    NORTH_WEST,

    /**
     * South-east arrow
     */
    SOUTH_EAST,

    /**
     * South-west arrow
     */
    SOUTH_WEST,

    /**
     * Northeast and southwest adjustment
     */
    NORTH_EAST_SOUTH_WEST,

    /**
     * Northwest and southeast adjustment
     */
    NORTH_WEST_SOUTH_EAST,

    /**
     * Cross (accurate selection)
     */
    CROSS,

    /**
     * Copy
     */
    CURSOR_COPY,

    /**
     * Forbid
     */
    CURSOR_FORBID,

    /**
     * Sucker
     */
    COLOR_SUCKER,

    /**
     * Grabbing hand
     */
    HAND_GRABBING,

    /**
     * Opening hand
     */
    HAND_OPEN,

    /**
     * Hand-shaped pointer
     */
    HAND_POINTING,

    /**
     * Help
     */
    HELP,

    /**
     * Move
     */
    MOVE,

    /**
     * Left and right resizing
     */
    RESIZE_LEFT_RIGHT,

    /**
     * Up and down resizing
     */
    RESIZE_UP_DOWN,

    /**
     * Screenshot crosshair
     */
    SCREENSHOT_CHOOSE,

    /**
     * Screenshot
     */
    SCREENSHOT_CURSOR,

    /**
     * Text selection
     */
    TEXT_CURSOR,

    /**
     * Zoom in
     */
    ZOOM_IN,

    /**
     * Zoom out
     */
    ZOOM_OUT,

    /**
     * Scrolling east
     */
    MIDDLE_BTN_EAST,

    /**
     * Scrolling west
     */
    MIDDLE_BTN_WEST,

    /**
     * Scrolling south
     */
    MIDDLE_BTN_SOUTH,

    /**
     * Scrolling north
     */
    MIDDLE_BTN_NORTH,

    /**
     * Scrolling north and south
     */
    MIDDLE_BTN_NORTH_SOUTH,

    /**
     * Scrolling northeast
     */
    MIDDLE_BTN_NORTH_EAST,

    /**
     * Scrolling northwest
     */
    MIDDLE_BTN_NORTH_WEST,

    /**
     * Scrolling southeast
     */
    MIDDLE_BTN_SOUTH_EAST,

    /**
     * Scrolling southwest
     */
    MIDDLE_BTN_SOUTH_WEST,

    /**
     * Moving as a cone in four directions
     */
    MIDDLE_BTN_NORTH_SOUTH_WEST_EAST,
  }

  /**
   * Mouse button.
   * @enum { number }
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @since 10
   */
  enum PrimaryButton {
    /**
     * Left mouse button
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 10
     */
    LEFT = 0,
    /**
     * Right mouse button
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 10
     */
    RIGHT = 1
  }

  /**
   * Sets the pointer moving speed.
   * 
   * @since 9
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use
   * @param speed Pointer moving speed, which is any number.
   * @param callback Callback used to return the result.
   * @throws {BusinessError} 401 - Parameter error.
   */
  function setPointerSpeed(speed: number, callback: AsyncCallback<void>): void;

  /**
   * Sets the pointer moving speed.
   * 
   * @since 9
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use
   * @param speed Pointer moving speed, which is any number.
   * @returns Returns the result through a promise.
   * @throws {BusinessError} 401 - Parameter error.
   */
  function setPointerSpeed(speed: number): Promise<void>;

  /**
   * Queries the pointer moving speed.
   * 
   * @since 9
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use
   * @param callback Callback used to return the result.
   * @throws {BusinessError} 401 - Parameter error.
   */
  function getPointerSpeed(callback: AsyncCallback<number>): void;

  /**
   * Queries the pointer moving speed.
   * 
   * @since 9
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use
   * @returns Returns the result through a promise.
   */
  function getPointerSpeed(): Promise<number>;

  /**
   * Sets the pointer style.
   * 
   * @since 9
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @param windowId Window ID.
   * @param pointerStyle Pointer style.
   * @param callback Callback used to return the result.
   * @throws {BusinessError} 401 - Parameter error.
   */
  function setPointerStyle(windowId: number, pointerStyle: PointerStyle, callback: AsyncCallback<void>): void;

  /**
   * Sets the pointer style.
   * 
   * @since 9
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @param windowId Window ID.
   * @param pointerStyle Pointer style.
   * @returns Returns the result through a promise.
   * @throws {BusinessError} 401 - Parameter error.
   */
  function setPointerStyle(windowId: number, pointerStyle: PointerStyle): Promise<void>;

  /**
   * Queries the pointer style.
   * 
   * @since 9
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @param windowId Window ID.
   * @param callback Callback used to return the result.
   * @throws {BusinessError} 401 - Parameter error.
   */
  function getPointerStyle(windowId: number, callback: AsyncCallback<PointerStyle>): void;

  /**
   * Queries the pointer style.
   * 
   * @since 9
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @param windowId Window ID.
   * @returns Returns the result through a promise.
   * @throws {BusinessError} 401 - Parameter error.
   */
  function getPointerStyle(windowId: number): Promise<PointerStyle>;

  /**
   * Sets whether the pointer icon is visible.
   *
   * @since 9
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @param visible Whether the pointer icon is visible. The value true indicates that the pointer icon is visible,
   * and the value false indicates the opposite.
   * @returns Callback for the input device event.
   * @throws {BusinessError} 401 - Parameter error.
   */
  function setPointerVisible(visible: boolean, callback: AsyncCallback<void>): void;

  /**
   * Sets whether the pointer icon is visible.
   *
   * @since 9
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @param visible Whether the pointer icon is visible. The value true indicates that the pointer icon is visible,
   * and the value false indicates the opposite.
   * @throws {BusinessError} 401 - Parameter error.
   */
  function setPointerVisible(visible: boolean): Promise<void>;

  /**
   * Checks whether the pointer icon is visible.
   *
   * @since 9
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @returns Returns <b>true</b> if the pointer icon is visible; returns <b>false</b> otherwise.
   * @throws {BusinessError} 401 - Parameter error.
   */
  function isPointerVisible(callback: AsyncCallback<boolean>): void;

  /**
   * Checks whether the pointer icon is visible.
   *
   * @since 9
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @returns Returns <b>true</b> if the pointer icon is visible; returns <b>false</b> otherwise.
   */
  function isPointerVisible(): Promise<boolean>;

  /**
   * Sets mouse primary button.
   * @param { PrimaryButton } primary - Indicates mouse primary button. The value LEFT indicates that mouse primary button is
   * left button, and the value RIGHT indicates that mouse primary button is right button.
   * @param { AsyncCallback<void> } callback - Callback used to return the result.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use.
   * @since 10
   */
  function setMousePrimaryButton(primary: PrimaryButton, callback: AsyncCallback<void>): void;

  /**
   * Sets mouse primary button.
   * @param { PrimaryButton } primary - Indicates mouse primary button. The value LEFT indicates that mouse primary button is
   * left button, and the value RIGHT indicates that mouse primary button is right button.
   * @returns { Promise<void> } Returns the result through a promise.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use.
   * @since 10
   */
  function setMousePrimaryButton(primary: PrimaryButton): Promise<void>;

  /**
   * Gets mouse primary button.
   * @param { AsyncCallback<PrimaryButton> } callback - Callback used to return the result.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use.
   * @since 10
   */
  function getMousePrimaryButton(callback: AsyncCallback<PrimaryButton>): void;

  /**
   * Gets mouse primary button.
   * @returns { Promise<PrimaryButton> } Returns the result through a promise.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use.
   * @since 10
   */
  function getMousePrimaryButton(): Promise<PrimaryButton>;

  /**
   * Sets whether the mouse hover scroll is enabled in inactive window.
   * @param { boolean } state - Indicates whether the mouse hover scroll is enabled in inactive window. The value true
   * indicates that the mouse hover scroll is enabled, and the value false indicates the opposite.
   * @param { AsyncCallback<void> } callback - Callback used to return the result.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use.
   * @since 10
   */
  function setHoverScrollState(state: boolean, callback: AsyncCallback<void>): void;

  /**
   * Sets whether mouse hover scroll is enabled in inactive window.
   * @param { boolean } state - Indicates whether the mouse hover scroll is enabled in inactive window. The value true
   * indicates that the mouse hover scroll is enabled, and the value false indicates the opposite.
   * @returns { Promise<void> } Returns the result through a promise.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use.
   * @since 10
   */
  function setHoverScrollState(state: boolean): Promise<void>;

  /**
   * Gets a status whether the mouse hover scroll is enabled in inactive window.
   * @param { AsyncCallback<boolean> } callback - Callback used to return the result.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use.
   * @since 10
   */
  function getHoverScrollState(callback: AsyncCallback<boolean>): void;

  /**
   * Gets a status whether mouse hover scroll is enabled in inactive window.
   * @returns { Promise<boolean> } Returns the result through a promise.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use.
   * @since 10
   */
  function getHoverScrollState(): Promise<boolean>;
}

export default pointer;