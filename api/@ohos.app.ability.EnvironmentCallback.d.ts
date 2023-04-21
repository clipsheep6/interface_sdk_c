/*
 * Copyright (c) 2022 Huawei Device Co., Ltd.
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

import AbilityConstant from "./@ohos.app.ability.AbilityConstant";
import { Configuration } from './@ohos.app.ability.Configuration';

/**
 * The environment callback.
 * @syscap SystemCapability.Ability.AbilityRuntime.Core
 * @since 9
 */
export default class EnvironmentCallback {
  /**
   * Called when the system configuration is updated.
   * @param { Configuration } config - Indicates the updated configuration.
   * @syscap SystemCapability.Ability.AbilityRuntime.AbilityCore
   * @StageModelOnly
   * @since 9
   */
  onConfigurationUpdated(config: Configuration): void;

  /**
   * Called when the system has determined to trim the memory, for example, when the ability is running in the
   * background and there is no enough memory for running as many background processes as possible.
   *
   * @param level: Indicates the memory trim level, which shows the current memory usage status.
   * @syscap SystemCapability.Ability.AbilityRuntime.AbilityCore
   * @StageModelOnly
   * @since 9
   */
  onMemoryLevel(level: AbilityConstant.MemoryLevel): void;
}
