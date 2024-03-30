/*
 * Copyright (c) 2024 Huawei Device Co., Ltd.
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

import StartupConfig from './@ohos.app.appstartup.StartupConfig';

/**
 * @file
 * @kit AbilityKit
 */

/**
 * The configuration entry for running startup tasks.
 *
 * @syscap SystemCapability.Ability.AppStartup
 * @stagemodelonly
 * @since 12
 */
export default class StartupConfigEntry {
  /**
   * Called when startup initialization to configure startup mode.
   *
   * @returns { StartupConfig } The developer returns a startup configuration.
   * @syscap SystemCapability.Ability.AppStartup
   * @stagemodelonly
   * @since 12
   */
  onConfig?(): StartupConfig;
}
