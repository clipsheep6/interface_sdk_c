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
import { AsyncCallback, Callback } from './basic' ;
import { Context } from  './application/BaseContext';
import { LocalStorage } from './@internal/component/ets/stateManagement';
import image from './@ohos.multimedia.image';
import rpc from './@ohos.rpc';

/**
 * Window manager.
 * @syscap SystemCapability.WindowManager.WindowManager.Core
 */
declare namespace window {
  /**
   * The type of a window.
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @since 7
   */
  enum WindowType {
    /**
     * App.
     * @FAModelOnly
     */
    TYPE_APP,
    /**
     * System alert.
     */
    TYPE_SYSTEM_ALERT,
    /**
     * input method.
     * @systemapi Hide this for inner system use.
     * @since 9
     * @StageModelOnly
     */
    TYPE_INPUT_METHOD,
    /**
     * status bar.
     * @systemapi Hide this for inner system use.
     * @since 9
     * @StageModelOnly
     */
    TYPE_STATUS_BAR,
    /**
     * panel.
     * @systemapi Hide this for inner system use.
     * @since 9
     * @StageModelOnly
     */
    TYPE_PANEL,
    /**
     * keyguard.
     * @systemapi Hide this for inner system use.
     * @since 9
     * @StageModelOnly
     */
    TYPE_KEYGUARD,
    /**
     * volume.
     * @systemapi Hide this for inner system use.
     * @since 9
     * @StageModelOnly
     */
    TYPE_VOLUME_OVERLAY,
    /**
     * navigation bar.
     * @systemapi Hide this for inner system use.
     * @since 9
     * @StageModelOnly
     */
    TYPE_NAVIGATION_BAR,
    /**
     * float.
     * @permission ohos.permission.SYSTEM_FLOAT_WINDOW
     * @since 9
     * @StageModelOnly
     */
    TYPE_FLOAT,
    /**
     * wallpaper.
     * @systemapi Hide this for inner system use.
     * @since 9
     * @StageModelOnly
     */
    TYPE_WALLPAPER,
    /**
     * desktop.
     * @systemapi Hide this for inner system use.
     * @since 9
     * @StageModelOnly
     */
    TYPE_DESKTOP,
    /**
     * recent.
     * @systemapi Hide this for inner system use.
     * @since 9
     * @StageModelOnly
     */
    TYPE_LAUNCHER_RECENT,
    /**
     * dock.
     * @systemapi Hide this for inner system use.
     * @since 9
     * @StageModelOnly
     */
    TYPE_LAUNCHER_DOCK,
    /**
     * voice interaction.
     * @systemapi Hide this for inner system use.
     * @since 9
     * @StageModelOnly
     */
    TYPE_VOICE_INTERACTION,
    /**
     * pointer.
     * @systemapi Hide this for inner system use.
     * @since 9
     * @StageModelOnly
     */
    TYPE_POINTER,
    /**
     * float camera.
     * @permission ohos.permission.SYSTEM_FLOAT_WINDOW
     * @since 9
     * @StageModelOnly
     */
     TYPE_FLOAT_CAMERA,
     /**
     * dialog.
     * @systemapi Hide this for inner system use.
     * @since 9
     * @StageModelOnly
     */
    TYPE_DIALOG,
    /**
     * screenshot.
     * @systemapi Hide this for inner system use.
     * @since 9
     * @StageModelOnly
     */
    TYPE_SCREENSHOT
  }

  /**
   * Describes the type of avoid area
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @since 7
   */
  enum AvoidAreaType {
    /**
     * Default area of the system
     */
    TYPE_SYSTEM,

    /**
     * Notch
     */
    TYPE_CUTOUT,

    /**
     * area for system gesture
     * @since 9
     */
    TYPE_SYSTEM_GESTURE,

    /**
     * area for keyboard
     * @since 9
     */
     TYPE_KEYBOARD
  }
  /**
   * Describes the window mode of an application
   * @systemapi Hide this for inner system use.
   * @since 7
   */
  enum WindowMode {
    UNDEFINED = 1,
    FULLSCREEN,
    PRIMARY,
    SECONDARY,
    FLOATING
  }

   /**
   * Describes the mode of window layout
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @systemapi Hide this for inner system use.
   * @since 9
   */
  enum WindowLayoutMode {
    /**
     * CASCADE
     * @systemapi Hide this for inner system use.
     * @since 9
     */
    WINDOW_LAYOUT_MODE_CASCADE,
    /**
     * TILE
     * @systemapi Hide this for inner system use.
     * @since 9
     */
    WINDOW_LAYOUT_MODE_TILE
  }

  /**
   * Properties of status bar and navigation bar, it couldn't update automatically
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @since 6
   */
  interface SystemBarProperties {
    /**
     * the color of the status bar.
     * @since 6
     */
    statusBarColor?: string;

    /**
     * the light icon of the status bar.
     * @since 7
     */
    isStatusBarLightIcon?: boolean;

    /**
     * the content color of the status bar
     * @since 8
     */
    statusBarContentColor?: string;

    /**
     * the color of the navigation bar.
     * @since 6
     */
    navigationBarColor?: string;

    /**
     * the light icon of the navigation bar.
     * @since 7
     */
    isNavigationBarLightIcon?: boolean;

    /**
     * the content color of the navigation bar
     * @since 8
     */
    navigationBarContentColor?: string;
  }

  /**
   * system bar tint of region
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @systemapi Hide this for inner system use.
   * @since 8
   */
  interface SystemBarRegionTint {
    /**
     * system bar type
     */
    type: WindowType;

    /**
     * the visibility of system bar
     */
    isEnable?: boolean;

    /**
     * the region of system bar
     */
    region?: Rect;

    /**
     * the background color of the system bar.
     */
    backgroundColor?: string;

    /**
     * the content color of the system bar.
     */
    contentColor?: string
  }

  /**
   * system bar tint state for systemui
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @systemapi Hide this for inner system use.
   * @since 8
   */
  interface SystemBarTintState {
    /**
     * id of display
     */
    displayId: number;
    /**
     * region tint of systembar
     */
    regionTint: Array<SystemBarRegionTint>;
  }

  /**
   * Rectangle
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @since 7
   */
  interface Rect {
    left: number;

    top: number;

    width: number;

    height: number;
  }

  /**
   * avoid area
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @since 7
   */
  interface AvoidArea {
    /**
     * Whether avoidArea is visible on screen
     * @since 9
     */
    visible: boolean;

    /**
     * Rectangle on the left of the screen
     */
    leftRect: Rect;

    /**
     * Rectangle on the top of the screen
     */
    topRect: Rect;

    /**
     * Rectangle on the right of the screen
     */
    rightRect: Rect;

    /**
     * Rectangle on the bottom of the screen
     */
    bottomRect: Rect;
  }

  /**
   * window size
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @since 7
   */
  interface Size {
    /**
     * the width of the window.
     */
    width: number;

    /**
     * the height of the window.
     */
    height: number;
  }

  /**
   * Properties of window, it couldn't update automatically
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @since 6
   */
  interface WindowProperties {
    /**
     * the position and size of the window
     * @since 7
     */
    windowRect: Rect;

    /**
     * window type
     * @since 7
     */
    type: WindowType;

    /**
     * Whether the window is displayed in full screen mode. The default value is false.
     * @since 6
     */
    isFullScreen: boolean

    /**
     * Whether the window layout is in full screen mode(whether the window is immersive). The default value is false.
     * @since 7
     */
    isLayoutFullScreen: boolean

    /**
     * Whether the window can gain focus. The default value is true
     * @since 7
     */
    focusable: boolean

    /**
     * Whether the window is touchable. The default value is false
     * @since 7
     */
    touchable: boolean

    /**
     * Brightness value of window.
     * @since 6
     */
    brightness: number

    /**
     * The dimbehind value of window.
     * @since 7
     * @deprecated since 9
     */
    dimBehindValue: number

    /**
     * Whether keep screen on.
     * @since 6
     */
    isKeepScreenOn: boolean

    /**
     * Whether make window in privacy mode or not.
     * @since 7
     */
    isPrivacyMode: boolean

    /**
     * Whether is round corner or not.
     * @since 7
     * @deprecated since 9
     */
    isRoundCorner: boolean

    /**
     * Whether is transparent or not.
     * @since 7
     */
    isTransparent: boolean
  }

  /**
   * Type of allowing the specified of color space.
   * @since 8
   */
  enum ColorSpace {
    /**
     * Default color space.
     */
    DEFAULT,
    /**
     * Wide gamut color space. The specific wide color gamut depends on thr screen.
     */
    WIDE_GAMUT,
  }
  /**
   * Describes the scale Transition Options of window
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @since 9
   * @systemapi
   */
   interface ScaleOptions {
    /**
     * The scale param of x direction. Default is 1.f
     */
    x?: number;
    /**
     * The scale param of y direction. Default is 1.f
     */
    y?: number;
    /**
     * The scale param of pivot point of x. Default is 0.5f, Interval is 0.f - 1.f
     */
    pivotX?: number;
    /**
     * The scale param of pivot point of y. Default is 0.5f, Interval is 0.f - 1.f
     */
    pivotY?: number;
  }

  /**
   * Describes the rotate Transition Options of window
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @since 9
   * @systemapi
   */
  interface RotateOptions {
    /**
     * The rotate degree of x direction. Default value is 0.f
     */
    x?: number;
    /**
     * The rotate degree of y direction. Default value is 0.f
     */
    y?: number;
    /**
     * The rotate degree of z direction. Default value is 0.f
     */
    z?: number;
    /**
     * The param of pivot point of x. Default is 0.5f, Interval is 0.f - 1.f
     */
    pivotX?: number;
    /**
     * The param of pivot point of y. Default is 0.5f, Interval is 0.f - 1.f
     */
    pivotY?: number;
  }

  /**
   * Describes the translate Transition Options of window
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @since 9
   * @systemapi
   */
  interface TranslateOptions {
    /**
    * The translate pixel param of x direction. Default is 0.f
    */
    x?: number;
    /**
     * The translate pixel param of y direction. Default is 0.f
     */
    y?: number;
    /**
     * The translate pixel param of z direction. Default is 0.f
     */
    z?: number;
  }

  /**
   * Transition Context
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @systempi
   * @since 9
   */
   interface TransitionContext {
    /**
     * The target window with animation
     */
    toWindow: Window
    /**
     * Set complete state of animation transition
     * @param isCompleted is Completed if true, or not if false.
     */
    completeTransition(isCompleted: boolean): void;
  }

  /**
   * Transition Controller
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @systempi
   * @since 9
   */
  interface TransitionController {
    /**
     * Animation configuration when showing window
     * @param context transition Context.
     */
    animationForShown(context: TransitionContext): void;
    /**
     * Animation configuration when hiding window
     * @param context transition context.
     */
    animationForHidden(context: TransitionContext): void;
  }

  /**
   * Create a sub window with a specific id and type, only support 7.
   * @param id Indicates window id.
   * @param type Indicates window type.
   * @since 7
   * @FAModelOnly
   */
  function create(id: string, type: WindowType, callback: AsyncCallback<Window>): void;

  /**
   * Create a sub window with a specific id and type, only support 7.
   * @param id Indicates window id.
   * @param type Indicates window type.
   * @since 7
   * @FAModelOnly
   */
  function create(id: string, type: WindowType): Promise<Window>;

  /**
   * Create a system or float window with a specific id and type.
   * @param ctx Indicates the context on which the window depends
   * @param id Indicates window id.
   * @param type Indicates window type.
   * @since 8
   */
  function create(ctx: Context, id: string, type: WindowType): Promise<Window>;

  /**
   * Create a system or float window with a specific id and type.
   * @param ctx Indicates the context on which the window depends
   * @param id Indicates window id.
   * @param type Indicates window type.
   * @since 8
   */
  function create(ctx: Context, id: string, type: WindowType, callback: AsyncCallback<Window>): void;

  /**
   * Find the window by id.
   * @param id Indicates window id.
   * @since 7
   */
  function find(id: string, callback: AsyncCallback<Window>): void;

  /**
   * Find the window by id.
   * @param id Indicates window id.
   * @since 7
   */
  function find(id: string): Promise<Window>;

  /**
   * Get the final show window.
   * @param id Indicates window id.
   * @since 6
   * @FAModelOnly
   */
  function getTopWindow(callback: AsyncCallback<Window>): void;

  /**
   * Get the final show window.
   * @since 6
   * @FAModelOnly
   */
  function getTopWindow(): Promise<Window>;

  /**
   * Get the final show window.
   * @param ctx Indicates the context on which the window depends
   * @since 8
   */
  function getTopWindow(ctx: Context): Promise<Window>;

  /**
   * Get the final show window.
   * @param ctx Indicates the context on which the window depends
   * @since 8
   */
  function getTopWindow(ctx: Context, callback: AsyncCallback<Window>): void;

  /**
   * minimize all app windows.
   * @systemapi Hide this for inner system use.
   * @since 9
   */
  function minimizeAll(id: number, callback: AsyncCallback<void>): void;

  /**
   * minimize all app windows.
   * @systemapi Hide this for inner system use.
   * @since 9
   */
  function minimizeAll(id: number): Promise<void>;

  /**
   * Toggle shown state for all app windows. Minimize or restore all app windows.
   * @systemapi Hide this for inner system use.
   * @since 9
   */
  function toggleShownStateForAllAppWindows(callback: AsyncCallback<void>): void;

  /**
   * Toggle shown state for all app windows. Minimize or restore all app windows.
   * @systemapi Hide this for inner system use.
   * @since 9
   */
  function toggleShownStateForAllAppWindows(): Promise<void>;

  /**
   * Set the layout mode of a window.
   * @param mode the layout mode of a window.
   * @systemapi Hide this for inner system use.
   * @since 9
   */
  function setWindowLayoutMode(mode: WindowLayoutMode, callback: AsyncCallback<void>): void;

  /**
   * Set the layout mode of a window.
   * @param mode the layout mode of a window.
   * @systemapi Hide this for inner system use.
   * @since 9
   */
  function setWindowLayoutMode(mode: WindowLayoutMode): Promise<void>;

  /**
   * register the callback of systemBarTintChange
   * @param type: 'systemBarTintChange'
   * @systemapi Hide this for inner system use.
   * @since 8
   */
  function on(type: 'systemBarTintChange', callback: Callback<SystemBarTintState>): void;

  /**
  * unregister the callback of systemBarTintChange
  * @param type: 'systemBarTintChange'
  * @systemapi Hide this for inner system use.
  * @since 8
  */
  function off(type: 'systemBarTintChange', callback?: Callback<SystemBarTintState>): void;

  /**
   * display orientation
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @since 9
   */
  enum Orientation {
    UNSPECIFIED = 0,
    PORTRAIT = 1,
    LANDSCAPE = 2,
    PORTRAIT_INVERTED = 3,
    LANDSCAPE_INVERTED = 4,
    AUTO_ROTATION = 5,
    AUTO_ROTATION_PORTRAIT = 6,
    AUTO_ROTATION_LANDSCAPE = 7,
    AUTO_ROTATION_RESTRICTED = 8,
    AUTO_ROTATION_PORTRAIT_RESTRICTED = 9,
    AUTO_ROTATION_LANDSCAPE_RESTRICTED = 10,
    LOCKED = 11,
  }

  /**
   * Type of blur style
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @systemapi Hide this for inner system use.
   * @since 9
   */
  enum BlurStyle {
    /**
     * Close blur.
     */
    OFF,
    /**
     * Blur style thin.
     */
    THIN,
     /**
     * Blur style regular.
     */
    REGULAR,
    /**
     * Blur style thick.
     */
    THICK,
  }

  interface Window {
    /**
     * hide window.
     * @systemapi Hide this for inner system use.
     * @since 7
     */
    hide (callback: AsyncCallback<void>): void;

    /**
      * hide window.
      * @systemapi Hide this for inner system use.
      * @since 7
      */
    hide(): Promise<void>;

    /**
      * hide window with animation.
      * @since 9
      * @systemapi
      */
    hideWithAnimation(callback: AsyncCallback<void>): void;

    /**
      * hide window with animation.
      * @since 9
      * @systemapi
      */
    hideWithAnimation(): Promise<void>;

    /**
      * show window.
      * @since 7
      */
    show(callback: AsyncCallback<void>): void;

    /**
      * show window.
      * @since 7
      */
    show(): Promise<void>;

    /**
      * show window with animation.
      * @since 9
      * @systemapi
      */
    showWithAnimation(callback: AsyncCallback<void>): void;

    /**
      * show window with animation.
      * @since 9
      * @systemapi
      */
    showWithAnimation(): Promise<void>;

    /**
     * Destroy the window.
     * @since 7
     */
    destroy(callback: AsyncCallback<void>): void;

    /**
      * Destroy the window.
      * @since 7
      */
    destroy(): Promise<void>;

    /**
     * Set the position of a window.
     * @param x Indicate the X-coordinate of the window.
     * @param y Indicate the Y-coordinate of the window.
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    moveTo(x: number, y: number): Promise<void>;

    /**
     * Set the position of a window.
     * @param x Indicate the X-coordinate of the window.
     * @param y Indicate the Y-coordinate of the window.
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    moveTo(x: number, y: number, callback: AsyncCallback<void>): void;

    /**
     * Set the size of a window .
     * @param width Indicates the width of the window.
     * @param height Indicates the height of the window.
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    resetSize(width: number, height: number): Promise<void>;

    /**
     * Set the size of a window .
     * @param width Indicates the width of the window.
     * @param height Indicates the height of the window.
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    resetSize(width: number, height: number, callback: AsyncCallback<void>): void;

    /**
     * Set the type of a window.
     * @param type Indicate the type of a window.
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @systemapi Hide this for inner system use.
     * @since 7
     * @deprecated since 9
     */
    setWindowType(type: WindowType): Promise<void>;

    /**
     * Set the type of a window.
     * @param type Indicate the type of a window.
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @systemapi Hide this for inner system use.
     * @since 7
     * @deprecated since 9
     */
    setWindowType(type: WindowType, callback: AsyncCallback<void>): void;

    /**
     * get the properties of current window
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 6
     */
    getProperties(callback: AsyncCallback<WindowProperties>): void;

     /**
      * get the properties of current window
      * @syscap SystemCapability.WindowManager.WindowManager.Core
      * @since 6
      */
    getProperties(): Promise<WindowProperties>;

    /**
     * get the avoid area
     * @param type Type of the area
     * @since 7
     */
    getAvoidArea(type: AvoidAreaType, callback: AsyncCallback<AvoidArea>): void;

    /**
     * get the avoid area
     * @param type Type of the area
     * @since 7
     */
    getAvoidArea(type: AvoidAreaType): Promise<AvoidArea>;

    /**
     * set the flag of the window is shown full screen
     * @param isFullScreen the flag of the window is shown full screen
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 6
     */
    setFullScreen(isFullScreen: boolean, callback: AsyncCallback<void>): void;

    /**
     * set the flag of the window is shown full screen
     * @param isFullScreen the flag of the window is shown full screen
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 6
     */
    setFullScreen(isFullScreen: boolean): Promise<void>;

    /**
     * set the property of the window can layout in full screen
     * @param isLayoutFullScreen the window can layout in full screen
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    setLayoutFullScreen(isLayoutFullScreen: boolean, callback: AsyncCallback<void>): void;

    /**
     * set the property of the window can layout in full screen
     * @param isLayoutFullScreen the window can layout in full screen
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    setLayoutFullScreen(isLayoutFullScreen: boolean): Promise<void>;

    /**
     * set the system bar to have visible.
     * @param names the set of system bar
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    setSystemBarEnable(names: Array<'status'|'navigation'>, callback: AsyncCallback<void>): void;

    /**
     * set the system bar to have visible.
     * @param names the set of system bar
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    setSystemBarEnable(names: Array<'status'|'navigation'>): Promise<void>;

    /**
     * set the background color of statusbar
     * @param color the background color of statusbar
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 6
     */
    setSystemBarProperties(systemBarProperties: SystemBarProperties, callback: AsyncCallback<void>): void;

    /**
     * set the background color of statusbar
     * @param color the background color of statusbar
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 6
     */
    setSystemBarProperties(systemBarProperties: SystemBarProperties): Promise<void>;

    /**
     * Set the preferred orientation config of the window
     * @param orientation the orientation config of the window
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 9
     */
    setPreferredOrientation(orientation: Orientation): Promise<void>;

    /**
     * Set the preferred orientation config of the window
     * @param orientation the orientation config of the window
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 9
     */
    setPreferredOrientation(orientation: Orientation, callback: AsyncCallback<void>): void;

    /**
     * Loads content
     * @param path  path Path of the page to which the content will be loaded
     * @param storage storage The data object shared within the content instance loaded by the window
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 9
     * @StageModelOnly
     */
    loadContent(path: string, storage: LocalStorage, callback: AsyncCallback<void>): void;

    /**
     * Loads content
     * @param path path of the page to which the content will be loaded
     * @param storage storage The data object shared within the content instance loaded by the window
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 9
     * @StageModelOnly
     */
    loadContent(path: string, storage: LocalStorage): Promise<void>;

    /**
     * Loads content
     * @param path path of the page to which the content will be loaded
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    loadContent(path: string, callback: AsyncCallback<void>): void;

    /**
     * Loads content
     * @param path path of the page to which the content will be loaded
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    loadContent(path: string): Promise<void>;

    /**
     * Checks whether the window is displayed
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    isShowing(callback: AsyncCallback<boolean>): void;

    /**
     * Checks whether the window is displayed
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    isShowing(): Promise<boolean>;

    /**
     * register the callback of windowSizeChange
     * @param type: 'windowSizeChange'
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    on(type: 'windowSizeChange', callback: Callback<Size>): void;

    /**
     * unregister the callback of windowSizeChange
     * @param type: 'windowSizeChange'
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    off(type: 'windowSizeChange', callback?: Callback<Size>): void;

    /**
     * register the callback of systemAvoidAreaChange
     * @param type: 'systemAvoidAreaChange'
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     * @deprecated since 9, please use on_avoidAreaChange instead.
     */
    on(type: 'systemAvoidAreaChange', callback: Callback<AvoidArea>): void;

    /**
     * unregister the callback of systemAvoidAreaChange
     * @param type: 'systemAvoidAreaChange'
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     * @deprecated since 9, please use off_avoidAreaChange instead.
     */
    off(type: 'systemAvoidAreaChange', callback?: Callback<AvoidArea>): void;

    /**
     * register the callback of avoidAreaChange
     * @param type: 'avoidAreaChange'
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 9
     */
    on(type: 'avoidAreaChange', callback: Callback<{ type: AvoidAreaType, area: AvoidArea }>): void;

    /**
     * unregister the callback of avoidAreaChange
     * @param type: 'avoidAreaChange'
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 9
     */
    off(type: 'avoidAreaChange', callback?: Callback<{ type: AvoidAreaType, area: AvoidArea }>): void;

    /**
     * register the callback of keyboardHeightChange
     * @param type: 'keyboardHeightChange'
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    on(type: 'keyboardHeightChange', callback: Callback<number>): void;

    /**
     * unregister the callback of keyboardHeightChange
     * @param type: 'keyboardHeightChange'
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    off(type: 'keyboardHeightChange', callback?: Callback<number>): void;

    /**
     * touch outside callback on.
     * @systemapi Hide this for inner system use.
     * @since 9
     */
    on(type: 'touchOutside', callback: Callback<void>): void;

    /**
     * touch outside callback off.
     * @systemapi Hide this for inner system use.
     * @since 9
     */
    off(type: 'touchOutside', callback?: Callback<void>): void;

    /**
     * register the callback of screenshot, only the focused window called back
     * @param type: 'screenshot'
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 9
     */
    on(type: 'screenshot', callback: Callback<void>): void;

     /**
      * unregister the callback of screenshot
      * @param type: 'screenshot'
      * @syscap SystemCapability.WindowManager.WindowManager.Core
      * @since 9
      */
    off(type: 'screenshot', callback?: Callback<void>): void;

    /**
     * register the callback of dialogTargetTouch
     * @param type: 'dialogTargetTouch'
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 9
     */
    on(type: 'dialogTargetTouch', callback: Callback<void>): void;

     /**
      * unregister the callback of dialogTargetTouch
      * @param type: 'dialogTargetTouch'
      * @syscap SystemCapability.WindowManager.WindowManager.Core
      * @since 9
      */
    off(type: 'dialogTargetTouch', callback?: Callback<void>): void;

    /**
     * bind dialog to the target window.
     * @param token token of the target window.
     * @param deathCallback the callback of dialogDeath.
     * @systemapi Hide this for inner system use.
     * @since 9
     */
    bindDialogTarget(token: rpc.RemoteObject, deathCallback: Callback<void>): Promise<void>;

     /**
      * bind dialog to the target window.
      * @param token token of the target window.
      * @param deathCallback the callback of dialogDeath.
      * @systemapi Hide this for inner system use.
      * @since 9
      */
    bindDialogTarget(token: rpc.RemoteObject, deathCallback: Callback<void>, callback: AsyncCallback<void>);

    /**
     * Whether the window supports thr wide gamut setting.
     * @since 8
     */
    isSupportWideGamut(): Promise<boolean>;

    /**
     * Whether the window supports thr wide gamut setting.
     * @since 8
     */
    isSupportWideGamut(callback: AsyncCallback<boolean>): void;

    /**
     * Sets the specified color space.
     * @param colorSpace the specified color space.
     * @since 8
     */
    setColorSpace(colorSpace:ColorSpace): Promise<void>;

    /**
     * Sets the specified color space.
     * @param colorSpace the specified color space.
     * @since 8
     */
    setColorSpace(colorSpace:ColorSpace, callback: AsyncCallback<void>): void;

    /**
     * Obtains thr set color space.
     * @since 8
     */
    getColorSpace(): Promise<ColorSpace>;

    /**
     * Obtains thr set color space.
     * @since 8
     */
    getColorSpace(callback: AsyncCallback<ColorSpace>): void;

    /**
     * Sets the background color of window.
     * @param color the specified color.
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 6
     */
    setBackgroundColor(color: string): Promise<void>;

    /**
     * Sets the background color of window.
     * @param color the specified color.
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 6
     */
    setBackgroundColor(color: string, callback: AsyncCallback<void>): void;

    /**
     * Sets the brightness of window.
     * @param brightness the specified brightness value.
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 6
     */
    setBrightness(brightness: number): Promise<void>;

    /**
     * Sets the brightness of window.
     * @param brightness the specified brightness value.
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 6
     */
    setBrightness(brightness: number, callback: AsyncCallback<void>): void;

    /**
    * Sets the dimBehind of window.
    * @param dimBehindValue the specified dimBehind.
    * @syscap SystemCapability.WindowManager.WindowManager.Core
    * @since 7
    * @deprecated since 9
    */
    setDimBehind(dimBehindValue: number, callback: AsyncCallback<void>): void;

    /**
     * Sets the dimBehind of window.
     * @param dimBehind the specified dimBehind.
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     * @deprecated since 9
     */
    setDimBehind(dimBehindValue: number): Promise<void>;

    /**
     * Sets whether focusable or not.
     * @param isFocusable can be focus if true, or can not be focus if false.
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    setFocusable(isFocusable: boolean): Promise<void>;

    /**
     * Sets whether focusable or not.
     * @param isFocusable can be focus if true, or can not be focus if false.
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    setFocusable(isFocusable: boolean, callback: AsyncCallback<void>): void;

    /**
     * Sets whether keep screen on or not.
     * @param isKeepScreenOn keep screen on if true, or not if false.
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 6
     */
    setKeepScreenOn(isKeepScreenOn: boolean): Promise<void>;

    /**
     * Sets whether keep screen on or not.
     * @param isKeepScreenOn keep screen on if true, or not if false.
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 6
     */
    setKeepScreenOn(isKeepScreenOn: boolean, callback: AsyncCallback<void>): void;

    /**
     * Sets whether to wake up the screen when this ability is restored.
     * @param wakeUp Specifies whether to wake up the screen. True means to wake it up, false means not.
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @systemapi Hide this for inner system use.
     * @since 9
     */
    setWakeUpScreen(wakeUp: boolean): void;

    /**
    * Sets whether outside can be touch or not.
    * @param touchable outside can be touch if true, or not if false.
    * @syscap SystemCapability.WindowManager.WindowManager.Core
    * @since 7
    * @deprecated since 9
    */
    setOutsideTouchable(touchable: boolean): Promise<void>;

    /**
     * Sets whether outside can be touch or not.
     * @param touchable outside can be touch if true, or not if false.
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     * @deprecated since 9
     */
    setOutsideTouchable(touchable: boolean, callback: AsyncCallback<void>): void;

    /**
     * Sets whether is private mode or not.
     * @param isPrivacyMode in private mode if true, or not if false.
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    setPrivacyMode(isPrivacyMode: boolean): Promise<void>;

    /**
     * Sets whether is private mode or not.
     * @param isPrivacyMode in private mode if true, or not if false.
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    setPrivacyMode(isPrivacyMode: boolean, callback: AsyncCallback<void>): void;

    /**
     * Ignore this window during screenshot.
     * @param isSkip skip if true, or not if false.
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @systemapi Hide this for inner system use.
     * @since 9
     */
    setSnapshotSkip(isSkip: boolean): void;

    /**
     * Sets whether is touchable or not.
     * @param isTouchable is touchable if true, or not if false.
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    setTouchable(isTouchable: boolean): Promise<void>;

    /**
     * Sets whether is touchable or not.
     * @param isTouchable is touchable if true, or not if false.
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 7
     */
    setTouchable(isTouchable: boolean, callback: AsyncCallback<void>): void;

    /**
     * set the flag of the window is forbidden to move in split screen mode
     * @param isForbidSplitMove the flag of the window is forbidden to move in split screen mode
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @systemapi
     * @since 9
     */
    setForbidSplitMove(isForbidSplitMove: boolean, callback: AsyncCallback<void>): void;

    /**
     * set the flag of the window is forbidden to move in split screen mode
     * @param isForbidSplitMove the flag of the window is forbidden to move in split screen mode
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @systemapi
     * @since 9
     */
    setForbidSplitMove(isForbidSplitMove: boolean): Promise<void>;

    /**
     * Obtains snapshot of window
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 9
     */
    snapshot(callback: AsyncCallback<image.PixelMap>): void;

     /**
      * Obtains snapshot of window
      * @syscap SystemCapability.WindowManager.WindowManager.Core
      * @since 9
      */
    snapshot(): Promise<image.PixelMap>;

    /* * Sets opacity  of window
     * @param opacity  Interval is 0.f-1.f.
     * @systemapi
     * @since 9
     */
    opacity(opacity: number): void;

    /**
     * Sets scale options of window.
     * @param scaleOptions scale param of window.
     * @systemapi
     * @since 9
     */
    scale(scaleOptions: ScaleOptions): void;

    /**
     * Sets rotate options of window.
     * @param rotateOptions rotate param of window.
     * @systemapi
     * @since 9
     */
    rotate(rotateOptions: RotateOptions): void;

    /**
     * Sets translate options of window.
     * @param translateOptions translate param of window.
     * @systemapi
     * @since 9
     */
    translate(translateOptions: TranslateOptions): void;

    /**
     * Get Transition Controller.
     * @systemapi
     * @since 9
     */
    getTransitionController(): TransitionController;

    /**
     * Sets the window blur radius.
     * @param radius the blur radius.
     * @systemapi Hide this for inner system use.
     * @since 9
     */
    setBlur(radius: number): void;

    /**
     * Sets the window backdrop blur radius.
     * @param radius the blur radius.
     * @systemapi Hide this for inner system use.
     * @since 9
     */
    setBackdropBlur(radius: number): void;

    /**
     * Sets the window backdrop blur style.
     * @param blurStyle the specified blur style.
     * @systemapi Hide this for inner system use.
     * @since 9
     */
    setBackdropBlurStyle(blurStyle: BlurStyle): void;

    /**
     * Sets shadow.
     * @param radius the radius of the shadow.
     * @param color the color of the shadow.
     * @param offsetX the offset of the shadow on the x-axis.
     * @param offsetY the offset of the shadow on the y-axis.
     * @systemapi Hide this for inner system use.
     * @since 9
     */
    setShadow(radius: number, color?: string, offsetX?: number, offsetY?: number): void;

    /**
     * Sets corner radius.
     * @param cornerRadius the corner radius.
     * @systemapi Hide this for inner system use.
     * @since 9
     */
    setCornerRadius(cornerRadius: number): void;
  }
  /**
   * window stage callback event type
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @since 9
   * @StageModelOnly
   */
  enum WindowStageEventType {
    FOREGROUND = 1,
    ACTIVE,
    INACTIVE,
    BACKGROUND,
  }
  /**
   * WindowStage
   * @syscap SystemCapability.WindowManager.WindowManager.Core
   * @since 9
   */
  interface WindowStage {
    /**
     * Get main window of the stage.
     * @since 9
     * @StageModelOnly
     */
    getMainWindow(): Promise<Window>;
    /**
     * Get main window of the stage.
     * @since 9
     * @StageModelOnly
     */
    getMainWindow(callback: AsyncCallback<Window>): void;
    /**
     * Create sub window of the stage.
     * @param name window name of sub window
     * @since 9
     * @StageModelOnly
     */
    createSubWindow(name: string): Promise<Window>;
    /**
     * Create sub window of the stage.
     * @param name window name of sub window
     * @since 9
     * @StageModelOnly
     */
    createSubWindow(name: string, callback: AsyncCallback<Window>): void;
    /**
     * Get sub window of the stage.
     * @since 9
     * @StageModelOnly
     */
    getSubWindow(): Promise<Array<Window>>;
    /**
     * Get sub window of the stage.
     * @since 9
     * @StageModelOnly
     */
    getSubWindow(callback: AsyncCallback<Array<Window>>): void;
    /**
     * Loads content
     * @param path  path Path of the page to which the content will be loaded
     * @param storage storage The data object shared within the content instance loaded by the window
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 9
     * @StageModelOnly
     */
    loadContent(path: string, storage: LocalStorage, callback: AsyncCallback<void>): void;
    /**
     * Loads content
     * @param path path of the page to which the content will be loaded
     * @param storage storage The data object shared within the content instance loaded by the window
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 9
     * @StageModelOnly
     */
    loadContent(path: string, storage?: LocalStorage): Promise<void>;
    /**
     * Loads content
     * @param path path of the page to which the content will be loaded
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @since 9
     * @StageModelOnly
     */
    loadContent(path: string, callback: AsyncCallback<void>): void;
    /**
     * window stage event callback on.
     * @since 9
     * @StageModelOnly
     */
    on(eventType: 'windowStageEvent', callback: Callback<WindowStageEventType>): void;
    /**
     * window stage event callback off.
     * @since 9
     * @StageModelOnly
     */
    off(eventType: 'windowStageEvent', callback?: Callback<WindowStageEventType>): void;

    /**
     * disable window decoration. It must be called before loadContent.
     * @systemapi
     * @since 9
     * @StageModelOnly
     */
     disableWindowDecor(): void;

    /**
     * Sets whether can show on lock screen or not
     * @param showOnLockScreen can show on lock screen if true, or not if false
     * @syscap SystemCapability.WindowManager.WindowManager.Core
     * @systemapi Hide this for inner system use.
     * @since 9
     * @StageModelOnly
     */
     setShowOnLockScreen(showOnLockScreen: boolean): void;
  }
}

export default window;
