/*
 * Copyright (C) 2021 Huawei Device Co., Ltd.
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

import { Callback } from './@ohos.base';

/**
 * The event of key input management module is configured to subscribe and unsubscribe system keys.
 *
 * @namespace inputConsumer
 * @syscap SystemCapability.MultimodalInput.Input.InputConsumer
 * @systemapi hide for inner use
 * @since 8
 */
declare namespace inputConsumer {
  /**
   * Defines event of key that user want to subscribe or unsubscribe.
   *
   * @interface KeyOptions
   * @syscap SystemCapability.MultimodalInput.Input.InputConsumer
   * @systemapi hide for inner use
   * @since 8
   */
  interface KeyOptions {
    /**
     * The pre-keys that want to subscribe or unsubscribe.
     *
     * @type { Array<number> }
     * @syscap SystemCapability.MultimodalInput.Input.InputConsumer
     * @systemapi hide for inner use
     * @since 8
     */
    preKeys: Array<number>;

    /**
     * The post position key that want to subscribe or unsubscribe.
     *
     * @type { number }
     * @syscap SystemCapability.MultimodalInput.Input.InputConsumer
     * @systemapi hide for inner use
     * @since 8
     */
    finalKey: number;

    /**
     * The final key press down or up.
     *
     * @type { boolean }
     * @syscap SystemCapability.MultimodalInput.Input.InputConsumer
     * @systemapi hide for inner use
     * @since 8
     */
    isFinalKeyDown: boolean;

    /**
     * Duration of final key press.
     *
     * @type { number }
     * @syscap SystemCapability.MultimodalInput.Input.InputConsumer
     * @systemapi hide for inner use
     * @since 8
     */
    finalKeyDownDuration: number;
  }

  /**
   * Shield mode.
   *
   * @enum { number }
   * @syscap SystemCapability.MultimodalInput.Input.InputConsumer
   * @systemapi hide for inner use
   * @since 11
   */
  enum ShieldMode {
    /**
     * Factory mode shield all key events
     *
     * @syscap SystemCapability.MultimodalInput.Input.InputConsumer
     * @systemapi hide for inner use
     * @since 11
     */
    FACTORY_MODE,

    /**
     * OOBE mode shield key event except power key event
     *
     * @syscap SystemCapability.MultimodalInput.Input.InputConsumer
     * @systemapi hide for inner use
     * @since 11
     */
    OOBE_MODE
  }

  /**
   * Subscribe system keys.
   *
   * @param { 'key' } type - type of the inputevent about input which is to be subscribed.
   * @param { KeyOptions } keyOptions - the key events about input which is to be subscribed.
   * @param { Callback<KeyOptions> } callback - callback function, receive reported data.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.InputConsumer
   * @systemapi hide for inner use
   * @since 8
   */
  function on(type: 'key', keyOptions: KeyOptions, callback: Callback<KeyOptions>): void;

  /**
   * Subscribe system keys.
   *
   * @param { 'key' } type - type of the inputevent about input which is to be subscribed.
   * @param { KeyOptions } keyOptions - the key events about input which is to be subscribed.
   * @param { Callback<KeyOptions> } callback - callback function, receive reported data.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.InputConsumer
   * @systemapi hide for inner use
   * @since 8
   */
  function off(type: 'key', keyOptions: KeyOptions, callback?: Callback<KeyOptions>): void;

  /**
   * Sets whether shield key event interception, only support shield key event.
   *
   * @param { ShieldMode } shieldMode - Accroding the shield mode select shield key event range.
   * @param { boolean } isShield - Indicates whether key event handler chain is shield. The value <b>true</b> indicates that
   * the key event build chain is shield, all key events derictly dispatch to window,
   * if the value <b>false</b> indicates not shield key event interception, handle by the chain.
   * @throws { BusinessError } 202 - SystemAPI permission error.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.InputConsumer
   * @systemapi hide for inner use.
   * @since 11
   */
  function setShieldEventInterceptionStatus(shieldMode: ShieldMode, isShield: boolean): void;

  /**
   * Gets shield event interception status corresponding to shield mode 
   *
   * @param { ShieldMode } shieldMode - Accroding the shield mode select shield key event range.
   * @returns { boolean } Returns true if shield event interception, returns false otherwise.
   * @throws { BusinessError } 202 - SystemAPI permission error.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.MultimodalInput.Input.InputConsumer
   * @systemapi hide for inner use.
   * @since 11
   */
  function getShieldEventInterceptionStatus(shieldMode: ShieldMode): boolean;
}

export default inputConsumer;