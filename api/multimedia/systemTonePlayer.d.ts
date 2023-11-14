/*
 * Copyright (c) 2023-2023 Huawei Device Co., Ltd.
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

import type { AsyncCallback } from '../@ohos.base';

/**
 * System tone player object.
 * @typedef SystemTonePlayer
 * @syscap SystemCapability.Multimedia.SystemSound.Core
 * @systemapi
 * @since 11
 */
export interface SystemTonePlayer {
  /**
   * Gets the title of system tone.
   * @param { AsyncCallback<string> } callback - Callback used to return the title.
   * @throws { BusinessError } 401 - The parameter check failed.
   * @throws { BusinessError } 5400103 - I/O error.
   * @syscap SystemCapability.Multimedia.SystemSound.Core
   * @systemapi
   * @since 11
   */
  getTitle(callback: AsyncCallback<string>): void;

  /**
   * Gets the title of system tone.
   * @returns { Promise<string> } Promise used to return the title.
   * @throws { BusinessError } 5400103 - I/O error.
   * @syscap SystemCapability.Multimedia.SystemSound.Core
   * @systemapi
   * @since 11
   */
  getTitle(): Promise<string>;

  /**
   * Prepare to play.
   * @param { AsyncCallback<void> } callback - Callback to return result of prepare.
   * @throws { BusinessError } 401 - The parameter check failed.
   * @throws { BusinessError } 5400102 - Operation not allowed.
   * @throws { BusinessError } 5400103 - I/O error.
   * @syscap SystemCapability.Multimedia.SystemSound.Core
   * @systemapi
   * @since 11
   */
  prepare(callback: AsyncCallback<void>): void;

  /**
   * Prepare to play.
   * @returns { Promise<void> } Promise used to return result of prepare.
   * @throws { BusinessError } 5400102 - Operation not allowed.
   * @throws { BusinessError } 5400103 - I/O error.
   * @syscap SystemCapability.Multimedia.SystemSound.Core
   * @systemapi
   * @since 11
   */
  prepare(): Promise<void>;

  /**
   * Start playing the system tone. Using this interface, the audio and haptic will not be muted.
   * @param { AsyncCallback<number> } callback - Callback to return id of this start.
   * @throws { BusinessError } 401 - The parameter check failed.
   * @throws { BusinessError } 5400102 - Operation not allowed.
   * @syscap SystemCapability.Multimedia.SystemSound.Core
   * @systemapi
   * @since 11
   */
  start(callback: AsyncCallback<number>): void;

  /**
   * Start playing the system tone. By default, the audio and haptic will not be muted. Using tone options to mute audio
   * or haptic.
   * @param { ToneOptions } toneOptions - Tone options used for this play.
   * @returns { Promise<number> } Promise used to return the id of this playback.
   * @throws { BusinessError } 401 - The parameter check failed.
   * @throws { BusinessError } 5400102 - Operation not allowed.
   * @syscap SystemCapability.Multimedia.SystemSound.Core
   * @systemapi
   * @since 11
   */
  start(toneOptions?: ToneOptions): Promise<number>;

  /**
   * Start playing the system tone with toneOptions.
   * @param { ToneOptions } toneOptions - Tone options used for this play.
   * @param { AsyncCallback<number> } callback - Callback to return id of this play.
   * @throws { BusinessError } 401 - The parameter check failed.
   * @throws { BusinessError } 5400102 - Operation not allowed.
   * @syscap SystemCapability.Multimedia.SystemSound.Core
   * @systemapi
   * @since 11
   */
  start(toneOptions: ToneOptions, callback: AsyncCallback<number>): void;

  /**
   * Stop with playback id.
   * @param { number } id - The Playback id to stop.
   * @param { AsyncCallback<void> } callback - Callback to return result of this stop.
   * @throws { BusinessError } 401 - The parameters check failed.
   * @throws { BusinessError } 5400102 - Operation not allowed.
   * @syscap SystemCapability.Multimedia.SystemSound.Core
   * @systemapi
   * @since 11
   */
  stop(id: number, callback: AsyncCallback<void>): void;

  /**
   * Stop with playback id.
   * @param { number } id - The Playback id to stop.
   * @returns { Promise<void> } Promise used to return result of this stop.
   * @throws { BusinessError } 401 - The parameters check failed.
   * @throws { BusinessError } 5400102 - Operation not allowed.
   * @syscap SystemCapability.Multimedia.SystemSound.Core
   * @systemapi
   * @since 11
   */
  stop(id: number): Promise<void>;

  /**
   * Release this system tone player.
   * @param { AsyncCallback<void> } callback - Callback used to return result of release.
   * @throws { BusinessError } 401 - The parameters check failed.
   * @throws { BusinessError } 5400102 - Operation not allowed.
   * @throws { BusinessError } 5400103 - I/O error.
   * @syscap SystemCapability.Multimedia.SystemSound.Core
   * @systemapi
   * @since 11
   */
  release(callback: AsyncCallback<void>): void;

  /**
   * Release this system tone player.
   * @returns { Promise<void> } Promise used to return result of release.
   * @throws { BusinessError } 5400102 - Operation not allowed.
   * @throws { BusinessError } 5400103 - I/O error.
   * @syscap SystemCapability.Multimedia.SystemSound.Core
   * @systemapi
   * @since 11
   */
  release(): Promise<void>;
}

/**
 * Tone options used when SystemTonePlayer start playing.
 * @typedef ToneOptions
 * @syscap SystemCapability.Multimedia.SystemSound.Core
 * @systemapi
 * @since 11
 */
export interface ToneOptions {
  /**
   * Mute audio.
   * @syscap SystemCapability.Multimedia.SystemSound.Core
   * @systemapi
   * @since 11
   */
  muteAudio?: boolean;

  /**
   * Mute haptic.
   * @syscap SystemCapability.Multimedia.SystemSound.Core
   * @systemapi
   * @since 11
   */
  muteHaptic?: boolean;
}