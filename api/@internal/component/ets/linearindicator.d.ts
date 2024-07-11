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

/**
 * Defines the LinearIndicator Controller.
 *
 * @interface LinearIndicatorController
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @atomicservice
 * @since 12
 */
declare class LinearIndicatorController {
  /**
   * constructor.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @atomicservice
   * @since 12
   */
  constructor();

  /**
   * Sets the progress of indicator.
   *
   * @param { number } index - the index of current indicator,  value range: [0, count - 1].
   * If index value is out of range, do nothing.
   * @param { number } progress - current indicator progress value, value range: [0, 100].
   * If the progress value is out of range, do nothing.
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @atomicservice
   * @since 12
   */
  setProgress(index: number, progress: number): void;

  /**
   * Start indicator auto play.
   *
   * @param { LinearIndicatorStartOptions } [options] - the options of indicator auto play.
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @atomicservice
   * @since 12
   */
  start(options?: LinearIndicatorStartOptions): void;

  /**
   * Pause indicator auto play. 
   * Start auto play will be resumed from this paused position.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @atomicservice
   * @since 12
   */
  pause(): void;

  /**
   * Stop indicator auto play.
   * Start auto play will restart from the very beginning.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @atomicservice
   * @since 12
   */
  stop(): void;
}

/**
 * Provides options of indicator auto play.
 *
 * @interface LinearIndicatorAutoPlayOptions
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @atomicservice
 * @since 12
 */
declare interface LinearIndicatorStartOptions {
  /**
   * The interval between twice auto play. The unit is ms.
   *
   * @type { ?number }
   * @default The default value is 0. if value is less than 0, the value will be 0.
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @atomicservice
   * @since 12
   */
  interval?: number;

  /**
   * The animation curve duration. The unit is ms.
   *
   * @type { ?number }
   * @default The default value is 4000. if value is less than 0, the value will be 1.
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @atomicservice
   * @since 12
   */
  duration?: number;
}

/**
 * Provides linear indicator style.
 *
 * @interface LinearIndicatorStyle
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @atomicservice
 * @since 12
 */
declare interface LinearIndicatorStyle {
  /**
   * The space of two linear indicator.
   *
   * @type { ?LengthMetrics }
   * @default The default value is 4.0vp. if value is less than 0, the value will be 4.0vp.
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @atomicservice
   * @since 12
   */
  space?: LengthMetrics;

  /**
   * Stroke width of the progress indicator.
   *
   * @type { ?LengthMetrics }
   * @default The default value is 2.0vp. if value is less than 0, the value will be 2.0vp.
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @atomicservice
   * @since 12
   */
  strokeWidth?: LengthMetrics;

  /**
   * The stroke radius of linear indicator.
   *
   * @type { ?LengthMetrics }
   * @default 1vp
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @atomicservice
   * @since 12
   */
  strokeRadius?: LengthMetrics;

  /**
   * The track background color of linear indicator.
   *
   * @type { ?ColorMetrics }
   * @default comp_background_tertiary
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @atomicservice
   * @since 12
   */
  trackBackgroundColor?: ColorMetrics;

  /**
   * The track color of linear indicator.
   *
   * @type { ?ColorMetrics }
   * @default comp_background_emphasize
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @atomicservice
   * @since 12
   */
  trackColor?: ColorMetrics;
}

/**
 * Provides an interface for indicator.
 *
 * @interface LinearIndicatorInterface
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @atomicservice
 * @since 12
 */
interface LinearIndicatorInterface {
  /**
   * Constructor parameters
   *
   * @param { number } count - the number of progress in LinearIndicator. minimum value is 2(default is 5).
   * if count is less than 2, the value will be 2.
   * @param { LinearIndicatorController } controller - Controller of LinearIndicator.
   * @returns { LinearIndicatorAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @atomicservice
   * @since 12
   */
   (count?: number, controller?: LinearIndicatorController): LinearIndicatorAttribute;
}

/**
 * Defines the Indicator attribute functions.
 *
 * @extends CommonMethod<LinearIndicatorAttribute>
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @since 12
 */
declare class LinearIndicatorAttribute extends CommonMethod<LinearIndicatorAttribute> {
  /**
   * Sets the indicator style.
   *
   * @param { Optional<LinearIndicatorStyle> } style
   * @returns { LinearIndicatorAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @atomicservice
   * @since 12
   */
  indicatorStyle(style: Optional<LinearIndicatorStyle>): LinearIndicatorAttribute;

  /**
   * Sets whether indicator supports loop, default is true.
   *
   * @param { Optional<boolean> } loop
   * @returns { LinearIndicatorAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @atomicservice
   * @since 12
   */
  indicatorLoop(loop: Optional<boolean>): LinearIndicatorAttribute;

  /**
   * Called when progress value update.
   *
   * @param { Optional<OnLinearIndicatorChangeCallback> } callback - callback of the progress change event.
   * @returns { LinearIndicatorAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @atomicservice
   * @since 12
   */
  onChange(callback: Optional<OnLinearIndicatorChangeCallback>): LinearIndicatorAttribute;
}

/**
 * Defines the callback type used in  the indicator progress change event.
 *
 * @typedef { function } OnLinearIndicatorChangeCallback
 * @param { number } index - index of current indicator.
 * @param { number } progress - current indicator progress value.
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @atomicservice
 * @since 12
 */
declare type OnLinearIndicatorChangeCallback = (index: number, progress: number) => void;

/**
 * Defines Indicator Component.
 *
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @atomicservice
 * @since 12
 */
declare const LinearIndicator: LinearIndicatorInterface;

/**
 * Defines Indicator Component instance.
 *
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @atomicservice
 * @since 12
 */
declare const LinearIndicatorInstance: LinearIndicatorAttribute;