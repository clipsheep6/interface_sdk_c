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

import { AsyncCallback } from './@ohos.base';
import { Callback } from './@ohos.base';

/**
 * Implements screen hopping operation management.
 *
 * @namespace cooperate
 * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
 * @systemapi Hide this for inner system use.
 * @since 10
 */
declare namespace cooperate {
  /**
   * Enumerates screen hopping message notifications.
   *
   * @enum { number }
   * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
   * @systemapi Hide this for inner system use.
   * @since 10
   * @deprecated since 11
   * @useinstead cooperate#CooperateMessage
   */
  enum CooperateMsg {
    /**
     * Preparing for screen hopping.
     *
     * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
     * @systemapi Hide this for inner system use.
     * @since 10
     * @deprecated since 11
     * @useinstead cooperate#CooperateMessage
     */
    COOPERATE_PREPARE = 0,

    /**
     * Canceling the preparation for screen hopping.
     *
     * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
     * @systemapi Hide this for inner system use.
     * @since 10
     * @deprecated since 11
     * @useinstead cooperate#CooperateMessage
     */
    COOPERATE_UNPREPARE = 1,

    /**
     * Starting screen hopping.
     *
     * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
     * @systemapi Hide this for inner system use.
     * @since 10
     * @deprecated since 11
     * @useinstead cooperate#CooperateMessage
     */
    COOPERATE_ACTIVATE = 2,

    /**
     * Success in starting screen hopping.
     *
     * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
     * @systemapi Hide this for inner system use.
     * @since 10
     * @deprecated since 11
     * @useinstead cooperate#CooperateMessage
     */
    COOPERATE_ACTIVATE_SUCCESS = 3,

    /**
     * Failure to start screen hopping.
     *
     * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
     * @systemapi Hide this for inner system use.
     * @since 10
     * @deprecated since 11
     * @useinstead cooperate#CooperateMessage
     */
    COOPERATE_ACTIVATE_FAIL = 4,

    /**
     * Success in stopping screen hopping.
     *
     * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
     * @systemapi Hide this for inner system use.
     * @since 10
     * @deprecated since 11
     * @useinstead cooperate#CooperateMessage
     */
    COOPERATE_DEACTIVATE_SUCCESS = 5,

    /**
     * Failure to stop screen hopping.
     *
     * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
     * @systemapi Hide this for inner system use.
     * @since 10
     * @deprecated since 11
     * @useinstead cooperate#CooperateMessage
     */
    COOPERATE_DEACTIVATE_FAIL = 6,

    /**
     * Inter-device session disconnected.
     *
     * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
     * @systemapi Hide this for inner system use.
     * @since 10
     * @deprecated since 11
     * @useinstead cooperate#CooperateMessage
     */
    COOPERATE_SESSION_DISCONNECTED = 7,
  }

  /**
   * Enumerates screen hopping message notifications.
   *
   * @enum { number }
   * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
   * @systemapi Hide this for inner system use.
   * @since 11
   */
  enum CooperateMessage {
    /**
     * Preparing for screen hopping.
     *
     * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
     * @systemapi Hide this for inner system use.
     * @since 11
     */
    COOPERATE_PREPARE = 0,

    /**
     * Canceling the preparation for screen hopping.
     *
     * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
     * @systemapi Hide this for inner system use.
     * @since 11
     */
    COOPERATE_UNPREPARE = 1,

    /**
     * Starting screen hopping.
     *
     * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
     * @systemapi Hide this for inner system use.
     * @since 11
     */
    COOPERATE_ACTIVATE = 2,

    /**
     * Success in starting screen hopping.
     *
     * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
     * @systemapi Hide this for inner system use.
     * @since 11
     */
    COOPERATE_ACTIVATE_SUCCESS = 3,

    /**
     * Failure to start screen hopping.
     *
     * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
     * @systemapi Hide this for inner system use.
     * @since 11
     */
    COOPERATE_ACTIVATE_FAILURE = 4,

    /**
     * Success in stopping screen hopping.
     *
     * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
     * @systemapi Hide this for inner system use.
     * @since 11
     */
    COOPERATE_DEACTIVATE_SUCCESS = 5,

    /**
     * Failure to stop screen hopping.
     *
     * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
     * @systemapi Hide this for inner system use.
     * @since 11
     */
    COOPERATE_DEACTIVATE_FAILURE = 6,

    /**
     * Inter-device session disconnected.
     *
     * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
     * @systemapi Hide this for inner system use.
     * @since 11
     */
    COOPERATE_SESSION_DISCONNECT = 7,
  }

  /**
   * Prepares for screen hopping.
   *
   * @param { AsyncCallback<void> } callback Asynchronous callback used to return the operation result.
   * @throws {BusinessError} 401 - Parameter error.
   * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
   * @systemapi Hide this for inner system use.
   * @since 10
   * @deprecated since 11
   * @useinstead cooperate#prepareCooperate
   */
  function prepare(callback: AsyncCallback<void>): void;

  /**
   * Prepares for screen hopping.
   *
   * @returns { Promise<void> } the promise returned by the function.
   * @throws {BusinessError} 401 - Parameter error.
   * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
   * @systemapi Hide this for inner system use.
   * @since 10
   * @deprecated since 11
   * @useinstead cooperate#prepareCooperate
   */
  function prepare(): Promise<void>;

  /**
   * Prepares for screen hopping.
   *
   * @permission ohos.permission.COOPERATE_MANAGER
   * @param { AsyncCallback<void> } callback - Asynchronous callback used to return the operation result.
   * @throws {BusinessError} 201 - Permission denied.
   * @throws {BusinessError} 202 - Not system application.
   * @throws {BusinessError} 401 - Parameter error.
   * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
   * @systemapi Hide this for inner system use.
   * @since 11
   */
  function prepareCooperate(callback: AsyncCallback<void>): void;

  /**
   * Prepares for screen hopping.
   *
   * @permission ohos.permission.COOPERATE_MANAGER
   * @returns { Promise<void> } the promise returned by the function.
   * @throws {BusinessError} 201 - Permission denied.
   * @throws {BusinessError} 202 - Not system application.
   * @throws {BusinessError} 401 - Parameter error.
   * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
   * @systemapi Hide this for inner system use.
   * @since 11
   */
  function prepareCooperate(): Promise<void>;

  /**
   * Cancels the preparation for screen hopping.
   *
   * @param { AsyncCallback<void> } callback Asynchronous callback used to return the operation result.
   * @throws {BusinessError} 401 - Parameter error.
   * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
   * @systemapi Hide this for inner system use.
   * @since 10
   * @deprecated since 11
   * @useinstead cooperate#unprepareCooperate
   */
  function unprepare(callback: AsyncCallback<void>): void;

  /**
   * Cancels the preparation for screen hopping.
   *
   * @returns { Promise<void> } the promise returned by the function.
   * @throws {BusinessError} 401 - Parameter error.
   * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
   * @systemapi Hide this for inner system use.
   * @since 10
   * @deprecated since 11
   * @useinstead cooperate#unprepareCooperate
   */
  function unprepare(): Promise<void>;

  /**
   * Cancels the preparation for screen hopping.
   *
   * @permission ohos.permission.COOPERATE_MANAGER
   * @param { AsyncCallback<void> } callback - Asynchronous callback used to return the operation result.
   * @throws {BusinessError} 201 - Permission denied.
   * @throws {BusinessError} 202 - Not system application.
   * @throws {BusinessError} 401 - Parameter error.
   * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
   * @systemapi Hide this for inner system use.
   * @since 11
   */
  function unprepareCooperate(callback: AsyncCallback<void>): void;

  /**
   * Cancels the preparation for screen hopping.
   *
   * @permission ohos.permission.COOPERATE_MANAGER
   * @returns { Promise<void> } the promise returned by the function.
   * @throws {BusinessError} 201 - Permission denied.
   * @throws {BusinessError} 202 - Not system application.
   * @throws {BusinessError} 401 - Parameter error.
   * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
   * @systemapi Hide this for inner system use.
   * @since 11
   */
  function unprepareCooperate(): Promise<void>;

  /**
   * Starts screen hopping.
   *
   * @param { string } targetNetworkId Descriptor of the target device for screen hopping.
   * @param { number } inputDeviceId Identifier of the input device for screen hopping.
   * @param { AsyncCallback<void> } callback Asynchronous callback used to return the operation result.
   * @throws {BusinessError} 401 - Parameter error.
   * @throws {BusinessError} 20900001 - Operation failed.
   * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
   * @systemapi Hide this for inner system use.
   * @since 10
   * @deprecated since 11
   * @useinstead cooperate#activateCooperate
   */
  function activate(targetNetworkId: string, inputDeviceId: number, callback: AsyncCallback<void>): void;

  /**
   * Starts screen hopping.
   *
   * @param { string } targetNetworkId Descriptor of the target device for screen hopping.
   * @param { number }inputDeviceId Identifier of the input device for screen hopping.
   * @returns { Promise<void> } the promise returned by the function.
   * @throws {BusinessError} 401 - Parameter error.
   * @throws {BusinessError} 20900001 - Operation failed.
   * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
   * @systemapi Hide this for inner system use.
   * @since 10
   * @deprecated since 11
   * @useinstead cooperate#activateCooperate
   */
  function activate(targetNetworkId: string, inputDeviceId: number): Promise<void>;

  /**
   * Starts screen hopping.
   *
   * @permission ohos.permission.COOPERATE_MANAGER
   * @param { string } targetNetworkId - Descriptor of the target device for screen hopping.
   * @param { number } inputDeviceId - Identifier of the input device for screen hopping.
   * @param { AsyncCallback<void> } callback - Asynchronous callback used to return the operation result.
   * @throws {BusinessError} 201 - Permission denied.
   * @throws {BusinessError} 202 - Not system application.
   * @throws {BusinessError} 401 - Parameter error.
   * @throws {BusinessError} 20900001 - Operation failed.
   * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
   * @systemapi Hide this for inner system use.
   * @since 11
   */
  function activateCooperate(targetNetworkId: string, inputDeviceId: number, callback: AsyncCallback<void>): void;

  /**
   * Starts screen hopping.
   *
   * @permission ohos.permission.COOPERATE_MANAGER
   * @param { string } targetNetworkId - Descriptor of the target device for screen hopping.
   * @param { number }inputDeviceId - Identifier of the input device for screen hopping.
   * @returns { Promise<void> } the promise returned by the function.
   * @throws {BusinessError} 201 - Permission denied.
   * @throws {BusinessError} 202 - Not system application.
   * @throws {BusinessError} 401 - Parameter error.
   * @throws {BusinessError} 20900001 - Operation failed.
   * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
   * @systemapi Hide this for inner system use.
   * @since 11
   */
  function activateCooperate(targetNetworkId: string, inputDeviceId: number): Promise<void>;

  /**
   * Stops screen hopping.
   *
   * @param { boolean } isUnchained Whether the cross-device link is unchained.
   * @param { AsyncCallback<void> } callback Asynchronous callback used to return the operation result.
   * @throws {BusinessError} 401 - Parameter error.
   * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
   * @systemapi Hide this for inner system use.
   * @since 10
   * @deprecated since 11
   * @useinstead cooperate#deactivateCooperate
   */
  function deactivate(isUnchained: boolean, callback: AsyncCallback<void>): void;

  /**
   * Stops screen hopping.
   *
   * @param { boolean } isUnchained Whether the cross-device link is unchained.
   * @returns { Promise<void> } the promise returned by the function.
   * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
   * @systemapi Hide this for inner system use.
   * @since 10
   * @deprecated since 11
   * @useinstead cooperate#deactivateCooperate
   */
  function deactivate(isUnchained: boolean): Promise<void>;

  /**
   * Stops screen hopping.
   *
   * @permission ohos.permission.COOPERATE_MANAGER
   * @param { boolean } isUnchained - Whether the cross-device link is unchained.
   * @param { AsyncCallback<void> } callback - Asynchronous callback used to return the operation result.
   * @throws {BusinessError} 201 - Permission denied.
   * @throws {BusinessError} 202 - Not system application.
   * @throws {BusinessError} 401 - Parameter error.
   * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
   * @systemapi Hide this for inner system use.
   * @since 11
   */
  function deactivateCooperate(isUnchained: boolean, callback: AsyncCallback<void>): void;

  /**
   * Stops screen hopping.
   *
   * @permission ohos.permission.COOPERATE_MANAGER
   * @param { boolean } isUnchained - Whether the cross-device link is unchained.
   * @returns { Promise<void> } the promise returned by the function.
   * @throws {BusinessError} 201 - Permission denied.
   * @throws {BusinessError} 202 - Not system application.
   * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
   * @systemapi Hide this for inner system use.
   * @since 11
   */
  function deactivateCooperate(isUnchained: boolean): Promise<void>;

  /**
   * Obtains the screen hopping status.
   *
   * @param { string } networkId Descriptor of the target device for screen hopping.
   * @param { AsyncCallback<boolean> } callback Asynchronous callback used to return the screen hopping status.
   * @throws {BusinessError} 401 - Parameter error.
   * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
   * @systemapi Hide this for inner system use.
   * @since 10
   * @deprecated since 11
   * @useinstead cooperate#getCooperateSwitchState
   */
  function getCrossingSwitchState(networkId: string, callback: AsyncCallback<boolean>): void;

  /**
   * Obtains the status of the screen hopping switch.
   *
   * @param { string } networkId Descriptor of the target device for screen hopping.
   * @returns { Promise<boolean> } Returns {@code true} the screen hopping status;
   *                               returns {@code false} otherwise.
   * @throws {BusinessError} 401 - Parameter error.
   * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
   * @systemapi Hide this for inner system use.
   * @since 10
   * @deprecated since 11
   * @useinstead cooperate#getCooperateSwitchState
   */
  function getCrossingSwitchState(networkId: string): Promise<boolean>;


  /**
   * Obtains the screen hopping status.
   *
   * @permission ohos.permission.COOPERATE_MANAGER
   * @param { string } networkId - Descriptor of the target device for screen hopping.
   * @param { AsyncCallback<boolean> } callback - Asynchronous callback used to return the screen hopping status.
   * @throws {BusinessError} 201 - Permission denied.
   * @throws {BusinessError} 202 - Not system application.
   * @throws {BusinessError} 401 - Parameter error.
   * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
   * @systemapi Hide this for inner system use.
   * @since 11
   */
  function getCooperateSwitchState(networkId: string, callback: AsyncCallback<boolean>): void;

  /**
   * Obtains the status of the screen hopping switch.
   *
   * @permission ohos.permission.COOPERATE_MANAGER
   * @param { string } networkId - Descriptor of the target device for screen hopping.
   * @returns { Promise<boolean> } Returns {@code true} the screen hopping status;
   *                               returns {@code false} otherwise.
   * @throws {BusinessError} 201 - Permission denied.
   * @throws {BusinessError} 202 - Not system application.
   * @throws {BusinessError} 401 - Parameter error.
   * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
   * @systemapi Hide this for inner system use.
   * @since 11
   */
  function getCooperateSwitchState(networkId: string): Promise<boolean>;

  /**
   * Enables listening for screen hopping status change events.
   *
   * @param { 'cooperate' } type Change type.
   * @param { Callback<{ networkId: string, msg: CooperateMsg }> } callback Asynchronous callback used to
   * return the screen hopping status change event.
   * @throws {BusinessError} 401 - Parameter error.
   * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
   * @systemapi Hide this for inner system use.
   * @since 10
   * @deprecated since 11
   * @useinstead cooperate#on
   */
  function on(type: 'cooperate', callback: Callback<{ networkId: string, msg: CooperateMsg }>): void;

  /**
   * Disables listening for screen hopping status change events.
   *
   * @param { 'cooperate' } type Change type.
   * @param { Callback<void> } callback Callback for which listening
   * is disabled. If this parameter is not specified, listening will be disabled for all registered callbacks.
   * @throws {BusinessError} 401 - Parameter error.
   * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
   * @systemapi Hide this for inner system use.
   * @since 10
   * @deprecated since 11
   * @useinstead cooperate#on
   */
  function off(type: 'cooperate', callback?: Callback<void>): void;

  /**
   * Enables listening for screen hopping status change events.
   *
   * @permission ohos.permission.COOPERATE_MANAGER
   * @param { 'cooperateMessage' } type - Change type.
   * @param { Callback<{ networkId: string, msg: CooperateMessage }> } callback - Asynchronous callback used to
   * return the screen hopping status change event.
   * @throws {BusinessError} 201 - Permission denied.
   * @throws {BusinessError} 202 - Not system application.
   * @throws {BusinessError} 401 - Parameter error.
   * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
   * @systemapi Hide this for inner system use.
   * @since 11
   */
  function on(type: 'cooperateMessage', callback: Callback<{ networkId: string, msg: CooperateMessage }>): void;

  /**
   * Disables listening for screen hopping status change events.
   *
   * @permission ohos.permission.COOPERATE_MANAGER
   * @param { 'cooperateMessage' } type - Change type.
   * @param { Callback<{ networkId: string, msg: CooperateMessage }> } callback - Callback for which listening
   * is disabled. If this parameter is not specified, listening will be disabled for all registered callbacks.
   * @throws {BusinessError} 201 - Permission denied.
   * @throws {BusinessError} 202 - Not system application.
   * @throws {BusinessError} 401 - Parameter error.
   * @syscap SystemCapability.Msdp.DeviceStatus.Cooperate
   * @systemapi Hide this for inner system use.
   * @since 11
   */
  function off(type: 'cooperateMessage', callback?: Callback<{ networkId: string, msg: CooperateMessage }>): void;
}

export default cooperate;
