/*
 * Copyright (c) 2022-2023 Huawei Device Co., Ltd.
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

/**
 * @file
 * @kit AbilityKit
 */

/**
 * Parameters corresponding to mission.
 *
 * @typedef MissionParameter
 * @permission ohos.permission.MANAGE_MISSIONS
 * @syscap SystemCapability.Ability.AbilityRuntime.Mission
 * @systemapi
 * @since 9
 */
export interface MissionParameter {
  /**
   * Indicates the deviceId to start sync.
   *
   * @permission ohos.permission.MANAGE_MISSIONS
   * @type { string }
   * @syscap SystemCapability.Ability.AbilityRuntime.Mission
   * @systemapi
   * @since 9
   */
  deviceId: string;

  /**
   * If needed to fix the versions conflict.
   *
   * @permission ohos.permission.MANAGE_MISSIONS
   * @type { boolean }
   * @syscap SystemCapability.Ability.AbilityRuntime.Mission
   * @systemapi
   * @since 9
   */
  fixConflict: boolean;

  /**
   * Tag used to be specified.
   *
   * @permission ohos.permission.MANAGE_MISSIONS
   * @type { number }
   * @syscap SystemCapability.Ability.AbilityRuntime.Mission
   * @systemapi
   * @since 9
   */
  tag: number;
}