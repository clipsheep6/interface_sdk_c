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

import type { AsyncCallback } from './basic';

/**
 * Declares interfaces related to mouse pointer attributes.
 *
 * @namespace pointer
 * @syscap SystemCapability.MultimodalInput.Input.Pointer
 * @since 9
 */
declare namespace pointer {
  /**
   * Pointer style.
   *
   * @enum { number }
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @since 9
   */
  enum PointerStyle {
    /**
     * Default
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 9
     */
    DEFAULT,

    /**
     * East arrow
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 9
     */
    EAST,

    /**
     * West arrow
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 9
     */
    WEST,

    /**
     * South arrow
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 9
     */
    SOUTH,

    /**
     * North arrow
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 9
     */
    NORTH,

    /**
     * East-west arrow
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 9
     */
    WEST_EAST,

    /**
     * North-south arrow
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 9
     */
    NORTH_SOUTH,

    /**
     * North-east arrow
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 9
     */
    NORTH_EAST,

    /**
     * North-west arrow
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 9
     */
    NORTH_WEST,

    /**
     * South-east arrow
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 9
     */
    SOUTH_EAST,

    /**
     * South-west arrow
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 9
     */
    SOUTH_WEST,

    /**
     * Northeast and southwest adjustment
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 9
     */
    NORTH_EAST_SOUTH_WEST,

    /**
     * Northwest and southeast adjustment
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 9
     */
    NORTH_WEST_SOUTH_EAST,

    /**
     * Cross (accurate selection)
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 9
     */
    CROSS,

    /**
     * Copy
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 9
     */
    CURSOR_COPY,

    /**
     * Forbid
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 9
     */
    CURSOR_FORBID,

    /**
     * Sucker
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 9
     */
    COLOR_SUCKER,

    /**
     * Grabbing hand
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 9
     */
    HAND_GRABBING,

    /**
     * Opening hand
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 9
     */
    HAND_OPEN,

    /**
     * Hand-shaped pointer
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 9
     */
    HAND_POINTING,

    /**
     * Help
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 9
     */
    HELP,

    /**
     * Move
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 9
     */
    MOVE,

    /**
     * Left and right resizing
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 9
     */
    RESIZE_LEFT_RIGHT,

    /**
     * Up and down resizing
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 9
     */
    RESIZE_UP_DOWN,

    /**
     * Screenshot crosshair
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 9
     */
    SCREENSHOT_CHOOSE,

    /**
     * Screenshot
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 9
     */
    SCREENSHOT_CURSOR,

    /**
     * Text selection
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 9
     */
    TEXT_CURSOR,

    /**
     * Zoom in
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 9
     */
    ZOOM_IN,

    /**
     * Zoom out
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 9
     */
    ZOOM_OUT,

    /**
     * Scrolling east
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 9
     */
    MIDDLE_BTN_EAST,

    /**
     * Scrolling west
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 9
     */
    MIDDLE_BTN_WEST,

    /**
     * Scrolling south
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 9
     */
    MIDDLE_BTN_SOUTH,

    /**
     * Scrolling north
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 9
     */
    MIDDLE_BTN_NORTH,

    /**
     * Scrolling north and south
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 9
     */
    MIDDLE_BTN_NORTH_SOUTH,

    /**
     * Scrolling northeast
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 9
     */
    MIDDLE_BTN_NORTH_EAST,

    /**
     * Scrolling northwest
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 9
     */
    MIDDLE_BTN_NORTH_WEST,

    /**
     * Scrolling southeast
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 9
     */
    MIDDLE_BTN_SOUTH_EAST,

    /**
     * Scrolling southwest
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 9
     */
    MIDDLE_BTN_SOUTH_WEST,

    /**
     * Moving as a cone in four directions
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 9
     */
    MIDDLE_BTN_NORTH_SOUTH_WEST_EAST
  }

  /**
   * Mouse button.
   *
   * @enum { number }
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @since 10
   */
  enum PrimaryButton {
    /**
     * Left mouse button
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 10
     */
    LEFT = 0,
    /**
     * Right mouse button
     *
     * @syscap SystemCapability.MultimodalInput.Input.Pointer
     * @since 10
     */
    RIGHT = 1
  }

  /**
   * Sets the pointer moving speed.
   *
   * @param { number } speed - Pointer moving speed, which is any number.
   * @param { AsyncCallback<void> } callback - Callback used to return the result.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use
   * @since 9
   */
  function setPointerSpeed(speed: number, callback: AsyncCallback<void>): void;

  /**
   * Sets the pointer moving speed.
   *
   * @param { number } speed - Pointer moving speed, which is any number.
   * @returns { Promise<void> } Returns the result through a promise.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use
   * @since 9
   */
  function setPointerSpeed(speed: number): Promise<void>;

  /**
   * Queries the pointer moving speed.
   *
   * @param { AsyncCallback<number> } callback - Callback used to return the result.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use
   * @since 9
   */
  function getPointerSpeed(callback: AsyncCallback<number>): void;

  /**
   * Queries the pointer moving speed.
   *
   * @returns { Promise<number> } Returns the result through a promise.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use
   * @since 9
   */
  function getPointerSpeed(): Promise<number>;

  /**
   * Sets the pointer style.
   *
   * @param { number } windowId - Window ID.
   * @param { PointerStyle } pointerStyle - Pointer style.
   * @param { AsyncCallback<void> } callback - Callback used to return the result.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @since 9
   */
  function setPointerStyle(windowId: number, pointerStyle: PointerStyle, callback: AsyncCallback<void>): void;

  /**
   * Sets the pointer style.
   *
   * @param { number } windowId - Window ID.
   * @param { PointerStyle } pointerStyle - Pointer style.
   * @returns { Promise<void> } Returns the result through a promise.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @since 9
   */
  function setPointerStyle(windowId: number, pointerStyle: PointerStyle): Promise<void>;

  /**
   * Queries the pointer style.
   *
   * @param { number } windowId - Window ID.
   * @param { AsyncCallback<PointerStyle> } callback - Callback used to return the result.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @since 9
   */
  function getPointerStyle(windowId: number, callback: AsyncCallback<PointerStyle>): void;

  /**
   * Queries the pointer style.
   *
   * @param { number } windowId - Window ID.
   * @returns { Promise<PointerStyle> } Returns the result through a promise.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @since 9
   */
  function getPointerStyle(windowId: number): Promise<PointerStyle>;

  /**
   * Sets whether the pointer icon is visible.
   *
   * @param { boolean } visible Whether the pointer icon is visible. The value true indicates that the pointer
   * icon is visible, and the value false indicates the opposite.
   * @param { AsyncCallback<void> } callback - Callback for the input device event.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @since 9
   */
  function setPointerVisible(visible: boolean, callback: AsyncCallback<void>): void;

  /**
   * Sets whether the pointer icon is visible.
   *
   * @param { boolean } visible Whether the pointer icon is visible. The value true indicates that the pointer
   * icon is visible, and the value false indicates the opposite.
   * @returns { Promise<void> } Returns the result through a promise.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @since 9
   */
  function setPointerVisible(visible: boolean): Promise<void>;

  /**
   * Checks whether the pointer icon is visible.
   *
   * @param { AsyncCallback<boolean> } callback - Returns <b>true</b> if the pointer icon is visible,
   * returns <b>false</b> otherwise.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @since 9
   */
  function isPointerVisible(callback: AsyncCallback<boolean>): void;

  /**
   * Checks whether the pointer icon is visible.
   *
   * @returns { Promise<boolean> } Returns <b>true</b> if the pointer icon is visible; returns <b>false</b> otherwise.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @since 9
   */
  function isPointerVisible(): Promise<boolean>;

  /**
   * Sets mouse primary button.
   *
   * @param { PrimaryButton } primary - Indicates mouse primary button. The value LEFT indicates that mouse primary
   * button is left button, and the value RIGHT indicates that mouse primary button is right button.
   * @param { AsyncCallback<void> } callback - Callback used to return the result.
   * @throws { BusinessError } 202 - SystemAPI permission error.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use.
   * @since 10
   */
  function setMousePrimaryButton(primary: PrimaryButton, callback: AsyncCallback<void>): void;

  /**
   * Sets mouse primary button.
   *
   * @param { PrimaryButton } primary - Indicates mouse primary button. The value LEFT indicates that mouse primary
   * button is left button, and the value RIGHT indicates that mouse primary button is right button.
   * @returns { Promise<void> } Returns the result through a promise.
   * @throws { BusinessError } 202 - SystemAPI permission error.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use.
   * @since 10
   */
  function setMousePrimaryButton(primary: PrimaryButton): Promise<void>;

  /**
   * Gets mouse primary button.
   *
   * @param { AsyncCallback<PrimaryButton> } callback - Callback used to return the result.
   * @throws { BusinessError } 202 - SystemAPI permission error.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use.
   * @since 10
   */
  function getMousePrimaryButton(callback: AsyncCallback<PrimaryButton>): void;

  /**
   * Gets mouse primary button.
   *
   * @returns { Promise<PrimaryButton> } Returns the result through a promise.
   * @throws { BusinessError } 202 - SystemAPI permission error.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use.
   * @since 10
   */
  function getMousePrimaryButton(): Promise<PrimaryButton>;

  /**
   * Sets whether the mouse hover scroll is enabled in inactive window.
   *
   * @param { boolean } state - Indicates whether the mouse hover scroll is enabled in inactive window. The value true
   * indicates that the mouse hover scroll is enabled, and the value false indicates the opposite.
   * @param { AsyncCallback<void> } callback - Callback used to return the result.
   * @throws { BusinessError } 202 - SystemAPI permission error.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use.
   * @since 10
   */
  function setHoverScrollState(state: boolean, callback: AsyncCallback<void>): void;

  /**
   * Sets whether mouse hover scroll is enabled in inactive window.
   *
   * @param { boolean } state - Indicates whether the mouse hover scroll is enabled in inactive window. The value true
   * indicates that the mouse hover scroll is enabled, and the value false indicates the opposite.
   * @returns { Promise<void> } Returns the result through a promise.
   * @throws { BusinessError } 202 - SystemAPI permission error.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use.
   * @since 10
   */
  function setHoverScrollState(state: boolean): Promise<void>;

  /**
   * Gets a status whether the mouse hover scroll is enabled in inactive window.
   *
   * @param { AsyncCallback<boolean> } callback - Callback used to return the result.
   * @throws { BusinessError } 202 - SystemAPI permission error.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use.
   * @since 10
   */
  function getHoverScrollState(callback: AsyncCallback<boolean>): void;

  /**
   * Gets a status whether mouse hover scroll is enabled in inactive window.
   *
   * @returns { Promise<boolean> } Returns the result through a promise.
   * @throws { BusinessError } 202 - SystemAPI permission error.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use.
   * @since 10
   */
  function getHoverScrollState(): Promise<boolean>;

  /**
   * Set the number of mouse scrolling rows.
   *
   * @param { number } rows - Indicates the number of mouse scrolling rows.
   * @param { AsyncCallback<void> } callback - Callback used to return the result.
   * @throws { BusinessError } 202 - SystemAPI permission error.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use.
   * @since 10
   */
  function setMouseScrollRows(rows: number, callback: AsyncCallback<void>): void;

  /**
   * Set the number of mouse scrolling rows.
   *
   * @param { number } rows - Indicates the number of mouse scrolling rows.
   * @returns { Promise<void> } Returns the result through a promise.
   * @throws { BusinessError } 202 - SystemAPI permission error.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use.
   * @since 10
   */
  function setMouseScrollRows(rows: number): Promise<void>;

  /**
   * Get the number of mouse scrolling rows.
   *
   * @param { AsyncCallback<number> } callback - Callback used to return the result.
   * @throws { BusinessError } 202 - SystemAPI permission error.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use.
   * @since 10
   */
  function getMouseScrollRows(callback: AsyncCallback<number>): void;

  /**
   * Get the number of mouse scrolling rows.
   *
   * @returns { Promise<number> } Returns the result through a promise.
   * @throws { BusinessError } 202 - SystemAPI permission error.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use.
   * @since 10
   */
  function getMouseScrollRows(): Promise<number>;

  /**
   * Set touchpad scroll switch.
   *
   * @param { boolean } state - Indicates whether the touchpad scroll switch is enabled
   * @param { AsyncCallback<void> } callback - Callback used to return the result.
   * @throws { BusinessError } 202 - SystemAPI permission error.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use.
   * @since 10
   */
  function setTpScrollSwitch(state: boolean, callback: AsyncCallback<void>): void;

  /**
   * Set touchpad scroll switch.
   *
   * @param { boolean } state - Indicates whether the touchpad scroll switch is enabled
   * @returns { Promise<void> } Returns the result through a promise.
   * @throws { BusinessError } 202 - SystemAPI permission error.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use.
   * @since 10
   */
  function setTpScrollSwitch(state: boolean): Promise<void>;

  /**
   * Get touchpad scroll switch state.
   *
   * @param { AsyncCallback<boolean> } callback - Callback used to return the result.
   * @throws { BusinessError } 202 - SystemAPI permission error.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use.
   * @since 10
   */
  function getTpScrollSwitch(callback: AsyncCallback<boolean>): void;

  /**
   * Get touchpad scroll switch state.
   *
   * @returns { Promise<boolean> } Returns the result through a promise.
   * @throws { BusinessError } 202 - SystemAPI permission error.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use.
   * @since 10
   */
  function getTpScrollSwitch(): Promise<boolean>;

  /**
   * Set touchpad scroll direct switch.
   *
   * @param { boolean } state - Indicates whether the touchpad scroll direct switch is forward or reverse
   * @param { AsyncCallback<void> } callback - Callback used to return the result.
   * @throws { BusinessError } 202 - SystemAPI permission error.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use.
   * @since 10
   */
  function setTpScrollDirectSwitch(state: boolean, callback: AsyncCallback<void>): void;

  /**
   * Set touchpad scroll direct switch.
   *
   * @param { boolean } state - Indicates whether the touchpad scroll direct switch is forward or reverse
   * @returns { Promise<void> } Returns the result through a promise.
   * @throws { BusinessError } 202 - SystemAPI permission error.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use.
   * @since 10
   */
  function setTpScrollDirectSwitch(state: boolean): Promise<void>;

  /**
   * Get touchpad scroll direct switch state.
   *
   * @param { AsyncCallback<boolean> } callback - Callback used to return the result.
   * @throws { BusinessError } 202 - SystemAPI permission error.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use.
   * @since 10
   */
  function getTpScrollDirectSwitch(callback: AsyncCallback<boolean>): void;

  /**
   * Get touchpad scroll direct switch state.
   *
   * @returns { Promise<boolean> } Returns the result through a promise.
   * @throws { BusinessError } 202 - SystemAPI permission error.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use.
   * @since 10
   */
  function getTpScrollDirectSwitch(): Promise<boolean>;

  /**
   * Set touchpad tap switch.
   *
   * @param { boolean } state - Indicates whether the touchpad tap switch is enabled
   * @param { AsyncCallback<void> } callback - Callback used to return the result.
   * @throws { BusinessError } 202 - SystemAPI permission error.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use.
   * @since 10
   */
  function setTpTapSwitch(state: boolean, callback: AsyncCallback<void>): void;

  /**
   * Set touchpad tap switch.
   *
   * @param { boolean } state - Indicates whether the touchpad tap switch is enabled
   * @returns { Promise<void> } Returns the result through a promise.
   * @throws { BusinessError } 202 - SystemAPI permission error.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use.
   * @since 10
   */
  function setTpTapSwitch(state: boolean): Promise<void>;

  /**
   * Get touchpad tap switch state.
   *
   * @param { AsyncCallback<boolean> } callback - Callback used to return the result.
   * @throws { BusinessError } 202 - SystemAPI permission error.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use.
   * @since 10
   */
  function getTpTapSwitch(callback: AsyncCallback<boolean>): void;

  /**
   * Get touchpad tap switch state.
   *
   * @returns { Promise<boolean> } Returns the result through a promise.
   * @throws { BusinessError } 202 - SystemAPI permission error.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use.
   * @since 10
   */
  function getTpTapSwitch(): Promise<boolean>;

  /**
   * Set touchpad pointer speed.
   *
   * @param { number } speed - Indicates the number of touchpad pointer speed.
   * @param { AsyncCallback<void> } callback - Callback used to return the result.
   * @throws { BusinessError } 202 - SystemAPI permission error.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use.
   * @since 10
   */
  function setTpPointerSpeed(speed: number, callback: AsyncCallback<void>): void;

  /**
   * Set touchpad pointer speed.
   *
   * @param { number } speed - Indicates the number of touchpad pointer speed.
   * @returns { Promise<void> } Returns the result through a promise.
   * @throws { BusinessError } 202 - SystemAPI permission error.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use.
   * @since 10
   */
  function setTpPointerSpeed(speed: number): Promise<void>;

  /**
   * Get touchpad pointer speed.
   *
   * @param { AsyncCallback<number> } callback - Callback used to return the result.
   * @throws { BusinessError } 202 - SystemAPI permission error.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use.
   * @since 10
   */
  function getTpPointerSpeed(callback: AsyncCallback<number>): void;

  /**
   * Get touchpad pointer speed.
   *
   * @returns { Promise<void> } Returns the result through a promise.
   * @throws { BusinessError } 202 - SystemAPI permission error.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.Pointer
   * @systemapi hide for inner use.
   * @since 10
   */
  function getTpPointerSpeed(): Promise<number>;
}

export default pointer;