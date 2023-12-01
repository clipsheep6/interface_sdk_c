/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
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

import type { AsyncCallback, Callback } from './@ohos.base';

/**
 * Interface of display manager.
 *
 * @namespace display
 * @syscap SystemCapability.WindowManager.WindowManager.Core
 * @since 7
 */
/**
 * Interface of display manager.
 *
 * @namespace display
 * @syscap SystemCapability.WindowManager.WindowManager.Core
 * @crossplatform
 * @since 10
 */
declare namespace display {
  /**
   * Obtain the default display.
   *
   * @param { AsyncCallback<Display> } callback the result of display
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @since 7
   * @deprecated since 9
   * @useinstead ohos.display#getDefaultDisplaySync
   */
  function getDefaultDisplay(callback: AsyncCallback<Display>): void;

  /**
   * Obtain the default display.
   *
   * @returns { Promise<Display> } the result of display
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @since 7
   * @deprecated since 9
   * @useinstead ohos.display#getDefaultDisplaySync
   */
  function getDefaultDisplay(): Promise<Display>;

  /**
   * Obtain the default display.
   *
   * @returns { Display } the result of display
   * @throws { BusinessError } 1400001 - Invalid display or screen.
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @since 9
   */
  /**
   * Obtain the default display.
   *
   * @returns { Display } the result of display
   * @throws { BusinessError } 1400001 - Invalid display or screen.
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @crossplatform
   * @since 10
   */
  /**
   * Obtain the default display.
   *
   * @returns { Display } the result of display
   * @throws { BusinessError } 1400001 - Invalid display or screen.
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @crossplatform
   * @atomicservice
   * @since 11
   */
  function getDefaultDisplaySync(): Display;

  /**
   * Obtain all displays.
   *
   * @param { AsyncCallback<Array<Display>> } callback the result of all displays
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @since 7
   * @deprecated since 9
   * @useinstead ohos.display#getAllDisplays
   */
  function getAllDisplay(callback: AsyncCallback<Array<Display>>): void;

  /**
   * Obtain all displays.
   *
   * @returns { Promise<Array<Display>> } the result of all displays
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @since 7
   * @deprecated since 9
   * @useinstead ohos.display#getAllDisplays
   */
  function getAllDisplay(): Promise<Array<Display>>;

  /**
   * Obtain all displays.
   *
   * @param { AsyncCallback<Array<Display>> } callback the result of all displays
   * @throws { BusinessError } 1400001 - Invalid display or screen.
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @since 9
   */
  function getAllDisplays(callback: AsyncCallback<Array<Display>>): void;

  /**
   * Obtain all displays.
   *
   * @returns { Promise<Array<Display>> } the result of all displays
   * @throws { BusinessError } 1400001 - Invalid display or screen.
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @since 9
   */
  function getAllDisplays(): Promise<Array<Display>>;

  /**
   * Check whether there is a privacy window on the current display.
   *
   * @param { number } displayId Display id to query
   * @returns { boolean } true means there is a privacy window on the current display
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 1400003 - This display manager service works abnormally.
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @systemapi Hide this for inner system use.
   * @since 9
   */
  function hasPrivateWindow(displayId: number): boolean;

  /**
   * Register the callback for display changes.
   *
   * @param { 'add' | 'remove' | 'change' } type the event of display change
   * @param { Callback<number> } callback the display id of changed
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @since 7
   */
  function on(type: 'add' | 'remove' | 'change', callback: Callback<number>): void;

  /**
   * Unregister the callback for display changes.
   *
   * @param { 'add' | 'remove' | 'change' } type the event of display change event
   * @param { Callback<number> } callback the display id of changed
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @since 7
   */
  function off(type: 'add' | 'remove' | 'change', callback?: Callback<number>): void;

  /**
   * Register the callback for private mode changes.
   *
   * @param { 'privateModeChange' } type the event of private mode changes
   * @param { Callback<boolean> } callback Callback used to return the result whether display is on private mode or not
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @systemapi Hide this for inner system use.
   * @since 10
   */
  function on(type: 'privateModeChange', callback: Callback<boolean>): void;

  /**
   * Unregister the callback for private mode changes.
   *
   * @param { 'privateModeChange' } type the event of private mode changes
   * @param { Callback<boolean> } callback Callback used to return the result whether display is on private mode or not
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @systemapi Hide this for inner system use.
   * @since 10
   */
  function off(type: 'privateModeChange', callback?: Callback<boolean>): void;

  /**
   * Check whether the device is foldable.
   *
   * @returns { boolean } true means the device is foldable.
   * @throws { BusinessError } 801 - Capability not supported on this device.
   * @throws { BusinessError } 1400003 - This display manager service works abnormally.
   * @syscap SystemCapability.Window.SessionManager
   * @since 10
   */
  function isFoldable(): boolean;

  /**
   * Get the current fold status of the foldable device.
   *
   * @returns { FoldStatus } fold status of device.
   * @throws { BusinessError } 801 - Capability not supported on this device.
   * @throws { BusinessError } 1400003 - This display manager service works abnormally.
   * @syscap SystemCapability.Window.SessionManager
   * @since 10
   */
  function getFoldStatus(): FoldStatus;

  /**
   * Register the callback for fold status changes.
   *
   * @param { 'foldStatusChange' } type the event of fold status changes
   * @param { Callback<FoldStatus> } callback Callback used to return the current fold status of device
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported on this device.
   * @throws { BusinessError } 1400003 - This display manager service works abnormally.
   * @syscap SystemCapability.Window.SessionManager
   * @since 10
   */
  function on(type: 'foldStatusChange', callback: Callback<FoldStatus>): void;

  /**
   * Unregister the callback for fold status changes.
   *
   * @param { 'foldStatusChange' } type the event of fold status changes
   * @param { Callback<FoldStatus> } callback Callback used to return the current fold status of device
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported on this device.
   * @throws { BusinessError } 1400003 - This display manager service works abnormally.
   * @syscap SystemCapability.Window.SessionManager
   * @since 10
   */
  function off(type: 'foldStatusChange', callback?: Callback<FoldStatus>): void;

  /**
   * Get the display mode of the foldable device.
   *
   * @returns { FoldDisplayMode } display mode of the foldable device.
   * @throws { BusinessError } 801 - Capability not supported on this device.
   * @throws { BusinessError } 1400003 - This display manager service works abnormally.
   * @syscap SystemCapability.Window.SessionManager
   * @since 10
   */
  function getFoldDisplayMode(): FoldDisplayMode;

  /**
   * Change the display mode of the foldable device.
   *
   * @param { FoldDisplayMode } mode target display mode to change.
   * @throws { BusinessError } 202 - Permission verification failed, non-system application uses system API.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported on this device.
   * @throws { BusinessError } 1400003 - This display manager service works abnormally.
   * @syscap SystemCapability.Window.SessionManager
   * @systemapi Hide this for inner system use.
   * @since 10
   */
  function setFoldDisplayMode(mode: FoldDisplayMode): void;

  /**
   * Register the callback for fold display mode changes.
   *
   * @param { 'foldDisplayModeChange' } type the event of fold display mode changes
   * @param { Callback<FoldDisplayMode> } callback Callback used to return the current fold display mode
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported on this device.
   * @throws { BusinessError } 1400003 - This display manager service works abnormally.
   * @syscap SystemCapability.Window.SessionManager
   * @since 10
   */
  function on(type: 'foldDisplayModeChange', callback: Callback<FoldDisplayMode>): void;

  /**
   * Unregister the callback for fold display mode changes.
   *
   * @param { 'foldDisplayModeChange' } type the event of fold display mode changes
   * @param { Callback<FoldDisplayMode> } callback Callback used to return the current fold display mode
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported on this device.
   * @throws { BusinessError } 1400003 - This display manager service works abnormally.
   * @syscap SystemCapability.Window.SessionManager
   * @since 10
   */
  function off(type: 'foldDisplayModeChange', callback?: Callback<FoldDisplayMode>): void;

  /**
   * Get the fold crease region in the current display mode.
   *
   * @returns { FoldCreaseRegion } fold crease region in the current display mode.
   * @throws { BusinessError } 801 - Capability not supported on this device.
   * @throws { BusinessError } 1400003 - This display manager service works abnormally.
   * @syscap SystemCapability.Window.SessionManager
   * @since 10
   */
  function getCurrentFoldCreaseRegion(): FoldCreaseRegion;

  /**
   * Enumerates the fold status.
   *
   * @enum { number }
   * @syscap SystemCapability.Window.SessionManager
   * @since 10
   */
  enum FoldStatus {
    /**
     * Fold Status Unknown.
     *
     * @syscap SystemCapability.Window.SessionManager
     * @since 10
     */
    FOLD_STATUS_UNKNOWN = 0,
    /**
     * Fold Status Expanded.
     *
     * @syscap SystemCapability.Window.SessionManager
     * @since 10
     */
    FOLD_STATUS_EXPANDED,
    /**
     * Fold Status Folded.
     *
     * @syscap SystemCapability.Window.SessionManager
     * @since 10
     */
    FOLD_STATUS_FOLDED,
    /**
     * Fold Status Half Folded.
     *
     * @syscap SystemCapability.Window.SessionManager
     * @since 10
     */
    FOLD_STATUS_HALF_FOLDED
  }

  /**
   * Enumerates the fold display mode.
   *
   * @enum { number }
   * @syscap SystemCapability.Window.SessionManager
   * @since 10
   */
  enum FoldDisplayMode {
    /**
     * Unknown Display.
     *
     * @syscap SystemCapability.Window.SessionManager
     * @since 10
     */
    FOLD_DISPLAY_MODE_UNKNOWN = 0,
    /**
     * Full Display.
     *
     * @syscap SystemCapability.Window.SessionManager
     * @since 10
     */
    FOLD_DISPLAY_MODE_FULL,
    /**
     * Main Display.
     *
     * @syscap SystemCapability.Window.SessionManager
     * @since 10
     */
    FOLD_DISPLAY_MODE_MAIN,
    /**
     * Sub Display.
     *
     * @syscap SystemCapability.Window.SessionManager
     * @since 10
     */
    FOLD_DISPLAY_MODE_SUB,
    /**
     * Coordination Display.
     *
     * @syscap SystemCapability.Window.SessionManager
     * @since 10
     */
    FOLD_DISPLAY_MODE_COORDINATION
  }

  /**
   * Enumerates the display states.
   *
   * @enum { number }
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @since 7
   */
  enum DisplayState {
    /**
     * Unknown.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    STATE_UNKNOWN = 0,
    /**
     * Screen off.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    STATE_OFF,
    /**
     * Screen on.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    STATE_ON,
    /**
     * Doze, but it will update for some important system messages.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    STATE_DOZE,
    /**
     * Doze and not update.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    STATE_DOZE_SUSPEND,
    /**
     * VR node.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    STATE_VR,
    /**
     * Screen on and not update.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    STATE_ON_SUSPEND
  }

  /**
   * Enumerates the display orientation.
   *
   * @enum { number }
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @crossplatform
   * @since 10
   */
  enum Orientation {
    /**
     * Indicate that the display content is in portrait mode.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @crossplatform
     * @since 10
     */
    PORTRAIT = 0,

    /**
     * Indicate that the display content is in landscape mode.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @crossplatform
     * @since 10
     */
    LANDSCAPE = 1,

    /**
     * Indicate that the display content is in the opposite direction of the portrait mode.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @crossplatform
     * @since 10
     */
    PORTRAIT_INVERTED = 2,

    /**
     * Indicate that the display content is in the opposite direction of the landscape mode.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @crossplatform
     * @since 10
     */
    LANDSCAPE_INVERTED = 3
  }

  /**
   * Enumerates the display color space
   *
   * @enum { number }
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @since 11
   */
  enum ColorSpace {
    /**
     * UNKNOWN color space.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 11
     */
    UNKNOWN = 0,
    /**
     * ADOBE_RGB color space.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 11
     */
    ADOBE_RGB = 1,
    /**
     * BT2020_HLG color space.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 11
     */
    BT2020_HLG = 2,
    /**
     * BT2020_PQ color space.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 11
     */
    BT2020_PQ= 3,
    /**
     * BT601_EBU color space.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 11
     */
    BT601_EBU = 4,
    /**
     * BT601_SMPTE_C color space.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 11
     */
    BT601_SMPTE_C = 5,
    /**
     * BT709 color space.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 11
     */
    BT709 = 6,
    /**
     * P3_HLG color space.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 11
     */
    P3_HLG = 7,
    /**
     * P3_PQ color space.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 11
     */
    P3_PQ = 8,
    /**
     * DISPLAY_P3 color space.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 11
     */
    DISPLAY_P3 = 9,
    /**
     * SRGB color space.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 11
     */
    SRGB = 10,
    /**
     * LINEAR_SRGB color space.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 11
     */
    LINEAR_SRGB = 11,
    /**
     * LINEAR_P3 color space.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 11
     */
    LINEAR_P3 = 12,
    /**
     * LINEAR_BT2020 color space.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 11
     */
    LINEAR_BT2020 = 13
  }

  /**
   * Enumerates the display HDR Format
   *
   * @enum { number }
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @since 11
   */
  enum HDRFormat {
    /**
     * Not support HDR.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 11
     */
    NONE = 0,
    /**
     * HLG format supported by video.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 11
     */
    VIDEO_HLG = 1,
    /**
     * HDR10 format supported by video.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 11
     */
    VIDEO_HDR10 = 2,
    /**
     * HDR Vivid format supported by video.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 11
     */
    VIDEO_HDR_VIVID = 3,
    /**
     * HDR Vivid format supported by image, stored in dual JPEG format.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 11
     */
    IMAGE_HDR_VIVID_DUAL = 4,
    /**
     * HDR Vivid format supported by image, stored in single HEIF format.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 11
     */
    IMAGE_HDR_VIVID_SINGLE = 5,
    /**
     * ISO HDR format supported by image, stored in dual JPEG format.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 11
     */
    IMAGE_HDR_ISO_DUAL = 6,
    /**
     * ISO HDR format supported by image, stored in single HEIF format.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 11
     */
    IMAGE_HDR_ISO_SINGLE = 7
  }

  /**
   * Fold Crease Region
   *
   * @interface FoldCreaseRegion
   * @syscap SystemCapability.Window.SessionManager
   * @since 10
   */
  interface FoldCreaseRegion {
    /**
     * The display ID is used to identify the screen where the crease is located.
     *
     * @readonly
     * @syscap SystemCapability.Window.SessionManager
     * @since 10
     */
    readonly displayId: number;

    /**
     * Crease Region.
     *
     * @readonly
     * @syscap SystemCapability.Window.SessionManager
     * @since 10
     */
    readonly creaseRects: Array<Rect>;
  }

  /**
   * Rectangle
   *
   * @interface Rect
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @since 9
   */
  interface Rect {
    /**
     * The X-axis coordinate of the upper left vertex of the rectangle, in pixels.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 9
     */
    left: number;

    /**
     * The Y-axis coordinate of the upper left vertex of the rectangle, in pixels.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 9
     */
    top: number;

    /**
     * Width of the rectangle, in pixels.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 9
     */
    width: number;

    /**
     * Height of the rectangle, in pixels.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 9
     */
    height: number;
  }

  /**
   * Curved area rects of the waterfall display.
   *
   * @interface WaterfallDisplayAreaRects
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @since 9
   */
  interface WaterfallDisplayAreaRects {
    /**
     * Indicates the size of left side curved area of the waterfall screen.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 9
     */
    readonly left: Rect;

    /**
     * Indicates the size of right side curved area of the waterfall screen.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 9
     */
    readonly right: Rect;

    /**
     * Indicates the size of top side curved area of the waterfall screen.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 9
     */
    readonly top: Rect;

    /**
     * Indicates the size of bottom side curved area of the waterfall screen.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 9
     */
    readonly bottom: Rect;
  }

  /**
   * Cutout information of the display.
   *
   * @interface CutoutInfo
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @since 9
   */
  interface CutoutInfo {
    /**
     * Bounding rectangles of the cutout areas of the display.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 9
     */
    readonly boundingRects: Array<Rect>;

    /**
     * Rectangles of curved parts on each side of a waterfall display.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 9
     */
    readonly waterfallDisplayAreaRects: WaterfallDisplayAreaRects;
  }

  /**
   * Define properties of the display. They cannot be updated automatically.
   *
   * @interface Display
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @since 7
   */
  /**
   * Define properties of the display. They cannot be updated automatically.
   *
   * @interface Display
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @crossplatform
   * @since 10
   */
  /**
   * Define properties of the display. They cannot be updated automatically.
   *
   * @interface Display
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @crossplatform
   * @atomicservice
   * @since 11
   */
  interface Display {
    /**
     * Display ID.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    /**
     * Display ID.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @crossplatform
     * @since 10
     */
    id: number;

    /**
     * Display name.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    name: string;

    /**
     * The display is alive.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    alive: boolean;

    /**
     * The state of display.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    state: DisplayState;

    /**
     * Refresh rate, in Hz.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    refreshRate: number;

    /**
     * Rotation degrees of the display.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    /**
     * Rotation degrees of the display.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @atomicservice
     * @since 11
     */
    rotation: number;

    /**
     * Display width, in pixels.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    /**
     * Display width, in pixels.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @crossplatform
     * @since 10
     */
    /**
     * Display width, in pixels.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @crossplatform
     * @atomicservice
     * @since 11
     */
    width: number;

    /**
     * Display height, in pixels.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    /**
     * Display height, in pixels.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @crossplatform
     * @since 10
     */
    /**
     * Display height, in pixels.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @crossplatform
     * @atomicservice
     * @since 11
     */
    height: number;

    /**
     * Display resolution.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    /**
     * Display resolution.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @crossplatform
     * @since 11
     */
    densityDPI: number;

    /**
     * Display orientation.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @crossplatform
     * @since 10
     */
    orientation: Orientation;

    /**
     * Display density, in pixels. The value for a low-resolution display is 1.0.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    /**
     * Display density, in pixels. The value for a low-resolution display is 1.0.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @crossplatform
     * @since 11
     */
    densityPixels: number;

    /**
     * Text scale density of the display.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    /**
     * Text scale density of the display.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @crossplatform
     * @since 11
     */
    scaledDensity: number;

    /**
     * DPI on the x-axis.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    xDPI: number;

    /**
     * DPI on the y-axis.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    yDPI: number;

    /**
     * All supported color space.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 11
     */
    colorSpace: Array<ColorSpace>;

    /**
     * All supported HDR formats.
     *
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 11
     */
    HDRFormats: Array<HDRFormat>;

    /**
     * Obtain the cutout info of the display.
     *
     * @param { AsyncCallback<CutoutInfo> } callback
     * @throws { BusinessError } 1400001 - Invalid display or screen.
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 9
     */
    getCutoutInfo(callback: AsyncCallback<CutoutInfo>): void;

    /**
     * Obtain the cutout info of the display.
     *
     * @returns { Promise<CutoutInfo> }
     * @throws { BusinessError } 1400001 - Invalid display or screen.
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 9
     */
    getCutoutInfo(): Promise<CutoutInfo>;

    /**
     * Check if current display has immersive window.
     *
     * @param { AsyncCallback<boolean> } callback
     * @throws { BusinessError } 801 - Capability not supported on this device.
     * @throws { BusinessError } 1400001 - Invalid display or screen.
     * @throws { BusinessError } 1400003 - This display manager service works abnormally.
     * @syscap SystemCapability.Window.SessionManager
     * @systemapi Hide this for inner system use.
     * @since 11
     */
    hasImmersiveWindow(callback: AsyncCallback<boolean>): void;

    /**
     * Check if current display has immersive window.
     *
     * @returns { Promise<boolean> }
     * @throws { BusinessError } 801 - Capability not supported on this device.
     * @throws { BusinessError } 1400001 - Invalid display or screen.
     * @throws { BusinessError } 1400003 - This display manager service works abnormally.
     * @syscap SystemCapability.Window.SessionManager
     * @systemapi Hide this for inner system use.
     * @since 11
     */
    hasImmersiveWindow(): Promise<boolean>;
  }
}

export default display;
