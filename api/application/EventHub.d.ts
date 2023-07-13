/*
 * Copyright (c) 2021-2023 Huawei Device Co., Ltd.
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

import { BusinessError } from '../@ohos.base';

/**
 * The event center of a context, support the subscription and publication of events.
 *
 * @syscap SystemCapability.Ability.AbilityRuntime.Core
 * @StageModelOnly
 * @since 9
 */
export default class EventHub {
  /**
   * Subscribe to an event.
   *
   * @param { string } event - Indicates the event.
   * @param { Function } callback - Indicates the callback.
   * @throws { BusinessError } 401 - If the input parameter is not valid parameter.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @StageModelOnly
   * @since 9
   */
  on(event: string, callback: Function): void;

  /**
   * Unsubscribe from an event.
   *
   * @param { string } event - Indicates the event.
   * @param { Function } [callback] - Indicates the callback.
   * @throws { BusinessError } 401 - If the input parameter is not valid parameter.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @StageModelOnly
   * @since 9
   */
  off(event: string, callback?: Function): void;

  /**
   * Trigger the event callbacks.
   *
   * @param { string } event - Indicates the event.
   * @param { Object[] } args - Indicates the callback arguments.
   * @throws { BusinessError } 401 - If the input parameter is not valid parameter.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @StageModelOnly
   * @since 9
   */
  emit(event: string, ...args: Object[]): void;
}
