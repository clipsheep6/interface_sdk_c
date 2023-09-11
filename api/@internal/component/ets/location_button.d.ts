/*
 * Copyright (c) 2023 Huawei Device Co., Ltd.
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
 * Enumerates the icon styles.
 *
 * @enum { number }
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @since 10
 */
declare enum LocationIconStyle {
  /**
   * Icon filled with the specified color.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 10
   */
  FULL_FILLED = 0,

  /**
   * Icon rendered as lines.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 10
   */
  LINES = 1
}

/**
 * Enumerates the text that can be displayed on the location button.
 *
 * @enum { number }
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @since 10
 */
declare enum LocationDescription {
  /**
   * Current Location
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 10
   */
  CURRENT_LOCATION = 0,

  /**
   * Add Location
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 10
   */
  ADD_LOCATION = 1,

  /**
   * Select Location
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 10
   */
  SELECT_LOCATION = 2,

  /**
   * Share Location
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 10
   */
  SHARE_LOCATION = 3,

  /**
   * Send Location
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 10
   */
  SEND_LOCATION = 4,

  /**
   * Locating
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 10
   */
  LOCATING = 5,

  /**
   * Location
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 10
   */
  LOCATION = 6,

  /**
   * Send Current Location
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 10
   */
  SEND_CURRENT_LOCATION = 7,

  /**
   * Relocation
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 10
   */
  RELOCATION = 8,

  /**
   * Punch In
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 10
   */
  PUNCH_IN = 9,

  /**
   * Current Position
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 10
   */
  CURRENT_POSITION = 10
}

/**
 * Declares the interface for setting the location button options.
 *
 * @interface LocationButtonOptions
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @since 10
 */
declare interface LocationButtonOptions {
  /**
   * Style of the icon to be drawn.
   *
   * @type { ?LocationIconStyle }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 10
   */
  icon?: LocationIconStyle;

  /**
   * Text to be displayed on the button.
   *
   * @type { ?LocationDescription }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 10
   */
  text?: LocationDescription;

  /**
   * Type of the button.
   *
   * @type { ?ButtonType }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 10
   */
  buttonType?: ButtonType;
}

/**
 * Enumerates the click event results of the location button.
 *
 * @enum { number }
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @since 10
 */
declare enum LocationButtonOnClickResult {
  /**
   * Success.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 10
   */
  SUCCESS = 0,

  /**
   * Failure because the application is not temporarily authorized for accessing location data.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 10
   */
  TEMPORARY_AUTHORIZATION_FAILED = 1
}

/**
 * Defines the interface for setting a location button.
 *
 * @interface LocationButtonInterface
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @since 10
 */
interface LocationButtonInterface {
  /**
   * Creates a location button.
   *
   * @returns { LocationButtonAttribute } TReturns the attribute of the location button.
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 10
   */
  (): LocationButtonAttribute;

  /**
   * Creates a location button with the specified composition.
   * If an attribute is not set, the corresponding element will not be drawn.
   *
   * @param { LocationButtonOptions } options - Indicates the options of the location button.
   * @returns { LocationButtonAttribute } Returns the attribute of the location button.
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 10
   */
  (options: LocationButtonOptions): LocationButtonAttribute;
}

/**
 * Defines the attributes of the location button.
 *
 * @extends SecurityComponentMethod<LocationButtonAttribute>
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @since 10
 */
declare class LocationButtonAttribute extends SecurityComponentMethod<LocationButtonAttribute> {
  /**
   * Called when the location button is clicked.
   *
   * @param { function } event
   * @returns { LocationButtonAttribute } Returns the attribute of the location button.
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 10
   */
  onClick(event: (event: ClickEvent, result: LocationButtonOnClickResult) => void): LocationButtonAttribute;
}

/**
 * Defines a button that interacts with the security component service to
 * request the authorization for accessing location data.
 *
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @since 10
 */
declare const LocationButton: LocationButtonInterface;

/**
 * Defines a location button instance for secure access.
 *
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @since 10
 */
declare const LocationButtonInstance: LocationButtonAttribute;
