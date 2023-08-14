/*
 * Copyright (c) 2023 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License"),
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

import type { AbilityResult } from './ability/abilityResult';
import type { AsyncCallback } from './@ohos.base';
import type { LocalStorage } from 'StateManagement';

/**
 * class of ui extension content session.
 *
 * @syscap SystemCapability.Ability.AbilityRuntime.Core
 * @StageModelOnly
 * @since 10
 */
export default class UIExtensionContentSession {
  /**
   * Send data from an ui extension to an ui extension component.
   *
   * @param { object } data - Indicates the data send to ui extension component.
   * @throws { BusinessError } 401 - The parameter check failed.
   * @throws { BusinessError } 16000050 - Internal error.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @systemapi
   * @StageModelOnly
   * @since 10
   */
  sendData(data: { [key: string]: Object }): void;

  /**
   * Sets the callback for the ui extension to receive data from an ui extension component.
   *
   * @param { function } callback - Indicates the receive data callback to set.
   * @throws { BusinessError } 401 - If the input parameter is not valid parameter.
   * @throws { BusinessError } 16000050 - Internal error.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @systemapi
   * @StageModelOnly
   * @since 10
   */
  setReceiveDataCallback(callback: (data: { [key: string]: Object }) => void): void;

  /**
   * Loads an UI extension content.
   *
   * @param { string } path - Path of the page to which the content will be loaded
   * @param { LocalStorage } [storage] - The data object shared within the content instance loaded by the page
   * @throws { BusinessError } 401 - If the input parameter is not valid parameter.
   * @throws { BusinessError } 16000050 - Internal error.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @StageModelOnly
   * @since 10
   */
  loadContent(path: string, storage?: LocalStorage): void;

  /**
   * Destroys the UI extension.
   *
   * @param { AsyncCallback<void> } callback - The callback of terminateSelf.
   * @throws { BusinessError } 401 - If the input parameter is not valid parameter.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @StageModelOnly
   * @since 10
   */
  terminateSelf(callback: AsyncCallback<void>): void;

  /**
   * Destroys the UI extension.
   *
   * @returns { Promise<void> } The promise returned by the function.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @StageModelOnly
   * @since 10
   */
  terminateSelf(): Promise<void>;

  /**
   * Destroys the UI extension while returning the specified result code and data to the caller.
   *
   * @param { AbilityResult } parameter - Indicates the result to return.
   * @param { AsyncCallback<void> } callback - The callback of terminateSelfWithResult.
   * @throws { BusinessError } 401 - If the input parameter is not valid parameter.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @StageModelOnly
   * @since 10
   */
  terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback<void>): void;

  /**
   * Destroys the UI extension while returning the specified result code and data to the caller.
   *
   * @param { AbilityResult } parameter - Indicates the result to return.
   * @returns { Promise<void> } The promise returned by the function.
   * @throws { BusinessError } 401 - If the input parameter is not valid parameter.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @StageModelOnly
   * @since 10
   */
  terminateSelfWithResult(parameter: AbilityResult): Promise<void>;

  /**
   * Sets the background color of the UI extension.
   *
   * @param { string } color - the specified color.
   * @throws { BusinessError } 401 - If the input parameter is not valid parameter.
   * @throws { BusinessError } 16000050 - Internal error.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @systemapi
   * @StageModelOnly
   * @since 10
   */
  setWindowBackgroundColor(color: string): void;

  /**
   * Sets whether this window is in privacy mode.
   *
   * @permission ohos.permission.PRIVACY_WINDOW
   * @param { boolean } isPrivacyMode - Whether the window is in privacy mode. The value true means that
   *                                    the window is in privacy mode, and false means the opposite.
   * @returns { Promise<void> } Promise that returns no value.
   * @throws { BusinessError } 201 - The application does not have permission to call the interface.
   * @throws { BusinessError } 401 - If the input parameter is not valid parameter.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @StageModelOnly
   * @since 10
   */
  setWindowPrivacyMode(isPrivacyMode: boolean): Promise<void>;

  /**
   * Sets whether this window is in privacy mode.
   *
   * @permission ohos.permission.PRIVACY_WINDOW
   * @param { boolean } isPrivacyMode - Whether the window is in privacy mode. The value true means that
   *                                    the window is in privacy mode, and false means the opposite.
   * @param { AsyncCallback<void> } callback - Callback used to return the result.
   * @throws { BusinessError } 201 - The application does not have permission to call the interface.
   * @throws { BusinessError } 401 - If the input parameter is not valid parameter.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @StageModelOnly
   * @since 10
   */
  setWindowPrivacyMode(isPrivacyMode: boolean, callback: AsyncCallback<void>): void;
}
