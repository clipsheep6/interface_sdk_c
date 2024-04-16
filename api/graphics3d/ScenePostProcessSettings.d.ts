/*
 * Copyright (c) 2024-2024 Huawei Device Co., Ltd.
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
 * @file
 * @kit ArkGraphics3D
 */

/**
 * The enum of tone mapping type.
 *
 * @enum { number }
 * @syscap SystemCapability.ArkUi.Graphics3D
 * @since 12
 */
export enum TonemapType {
  /**
   * The tone mapping type is ACES.
   *
   * @syscap SystemCapability.ArkUi.Graphics3D
   * @since 12
   */
   ACES = 0,

  /**
   * The tone mapping type is ACES_2020.
   *
   * @syscap SystemCapability.ArkUi.Graphics3D
   * @since 12
   */
   ACES_2020 = 1,

  /**
   * The tone mapping type is FILMIC.
   *
   * @syscap SystemCapability.ArkUi.Graphics3D
   * @since 12
   */
   FILMIC = 2,
}

/**
 * Define tone mapping parameters.
 *
 * @typedef TonemapSettings
 * @syscap SystemCapability.ArkUi.Graphics3D
 * @since 12
 */
export type TonemapSettings = {
  /**
   * Type of the tone mapping.
   *
   * @type { TonemapType }
   * @syscap SystemCapability.ArkUi.Graphics3D
   * @since 12
   */
  type?: TonemapType;

  /**
   * Exposure of the tone mapping.
   *
   * @type { ?number }
   * @syscap SystemCapability.ArkUi.Graphics3D
   * @since 12
   */
  exposure?: number;
}

/**
 * Define post processing settings.
 *
 * @typedef PostProcessingSettings 
 * @syscap SystemCapability.ArkUi.Graphics3D
 * @since 12
 */
export type PostProcessSettings = {
  /**
   * Tone mapping settings of the post processing settings.
   *
   * @type { ?TonemapSettings }
   * @syscap SystemCapability.ArkUi.Graphics3D
   * @since 12
   */
  tonemap?: TonemapSettings;
}
