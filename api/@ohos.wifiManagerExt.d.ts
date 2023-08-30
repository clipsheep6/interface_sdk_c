/*
 * Copyright (C) 2022 Huawei Device Co., Ltd.
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

import { AsyncCallback, Callback } from './@ohos.base';
/**
 * Provides extended methods to operate or manage Wi-Fi.
 *
 * <p>The APIs involved in this file are non-general APIs.
 * These extended APIs are only used by some product types, such as routers. 
 * Common products should not use these APIs.</p>
 *
 * @namespace wifiManagerExt
 * @since 9
 */
declare namespace wifiManagerExt {
  /**
   * Enable Wi-Fi hotspot function.
   * This method is asynchronous. After the Wi-Fi hotspot is enabled, Wi-Fi may be disabled.
   * @permission ohos.permission.SET_WIFI_INFO
   * @throws {BusinessError} 201 - Permission denied.
   * @throws {BusinessError} 801 - Capability not supported.
   * @throws {BusinessError} 2701000 - Operation failed.
   * @syscap SystemCapability.Communication.WiFi.AP.Extension
   * @since 9
   */
  function enableHotspot(): void;

  /**
   * Disable Wi-Fi hotspot function.
   * If Wi-Fi is enabled after the Wi-Fi hotspot is disabled, Wi-Fi may be re-enabled.
   * @permission ohos.permission.SET_WIFI_INFO
   * @throws {BusinessError} 201 - Permission denied.
   * @throws {BusinessError} 801 - Capability not supported.
   * @throws {BusinessError} 2701000 - Operation failed.
   * @syscap SystemCapability.Communication.WiFi.AP.Extension
   * @since 9
   */
  function disableHotspot(): void;

  /**
   * Obtains the supported power Mode.
   * @permission ohos.permission.GET_WIFI_INFO
   * @throws {BusinessError} 201 - Permission denied.
   * @throws {BusinessError} 801 - Capability not supported.
   * @throws {BusinessError} 2701000 - Operation failed.
   * @syscap SystemCapability.Communication.WiFi.AP.Extension
   * @since 9
   */
  function getSupportedPowerMode(): Promise<Array<PowerMode>>;

    /**
   * Obtains the supported power Mode.
   * @permission ohos.permission.GET_WIFI_INFO
   * @throws {BusinessError} 201 - Permission denied.
   * @throws {BusinessError} 801 - Capability not supported.
   * @throws {BusinessError} 2701000 - Operation failed.
   * @syscap SystemCapability.Communication.WiFi.AP.Extension
   * @since 9
   */
  function getSupportedPowerMode(callback: AsyncCallback<Array<PowerMode>>): void;

  /**
   * Obtains the current Wi-Fi power mode.
   * @permission ohos.permission.GET_WIFI_INFO
   * @throws {BusinessError} 201 - Permission denied.
   * @throws {BusinessError} 801 - Capability not supported.
   * @throws {BusinessError} 2701000 - Operation failed.
   * @syscap SystemCapability.Communication.WiFi.AP.Extension
   * @since 9
   */
  function getPowerMode(): Promise<PowerMode>;

  /**
   * Obtains the current Wi-Fi power mode.
   * @permission ohos.permission.GET_WIFI_INFO
   * @throws {BusinessError} 201 - Permission denied.
   * @throws {BusinessError} 801 - Capability not supported.
   * @throws {BusinessError} 2701000 - Operation failed.
   * @syscap SystemCapability.Communication.WiFi.AP.Extension
   * @since 9
   */
  function getPowerMode(callback: AsyncCallback<PowerMode>): void;

  /**
   * Set the current Wi-Fi power mode.
   * @permission ohos.permission.SET_WIFI_INFO
   * @throws {BusinessError} 201 - Permission denied.
   * @throws {BusinessError} 801 - Capability not supported.
   * @throws {BusinessError} 2701000 - Operation failed.
   * @syscap SystemCapability.Communication.WiFi.AP.Extension
   * @since 9
   */
  function setPowerMode(mode: PowerMode): void;

  /**
   * The power Mode enumeration.
   *
   * @enum { number } PowerMode
   * @since 9
   * @syscap SystemCapability.Communication.WiFi.AP.Extension
   */
  export enum PowerMode {
    /** Sleeping Mode. */
    SLEEPING = 0,

    /** General Mode. */
    GENERAL = 1,

    /** Through wall Mode. */
    THROUGH_WALL = 2,
  }
}

export default wifiManagerExt;
