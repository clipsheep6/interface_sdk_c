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
 * class of wallpaper extension.
 *
 * @syscap SystemCapability.MiscServices.Wallpaper
 * @systemapi Hide this for inner system use.
 * @StageModelOnly
 * @since 9
 */
declare class WallpaperExtension {
  /**
   * Called once to initialize the extension.
   *
   * @param { object } want - Indicates connection information about the wallpaper extension ability.
   * @syscap SystemCapability.MiscServices.Wallpaper
   * @systemapi Hide this for inner system use.
   * @StageModelOnly
   * @since 9
   */
  onCreated(want: object): void;

  /**
   * The onWallpaperChanged callback is triggered when the user modifies the wallpaper settings.
   *
   * @param { number } wallpaperType - Indicates the wallpaper type.
   * @syscap SystemCapability.MiscServices.Wallpaper
   * @systemapi Hide this for inner system use.
   * @StageModelOnly
   * @since 9
   */
  onWallpaperChanged(wallpaperType: number): void;

  /**
   * Called once to destroy the exten.
   *
   * @syscap SystemCapability.MiscServices.Wallpaper
   * @systemapi Hide this for inner system use.
   * @StageModelOnly
   * @since 9
   */
  onDestroy(): void;
}

export default WallpaperExtension;
