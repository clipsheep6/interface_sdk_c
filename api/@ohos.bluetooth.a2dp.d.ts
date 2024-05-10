/*
 * Copyright (C) 2023 Huawei Device Co., Ltd.
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
 * @kit ConnectivityKit
 */

import type { AsyncCallback } from './@ohos.base';
import type baseProfile from './@ohos.bluetooth.baseProfile';

/**
 * Provides methods to accessing bluetooth audio related capabilities.
 *
 * @namespace a2dp
 * @syscap SystemCapability.Communication.Bluetooth.Core
 * @since 10
 */
declare namespace a2dp {
  /**
   * Base interface of profile.
   *
   * @syscap SystemCapability.Communication.Bluetooth.Core
   * @since 10
   */
  type BaseProfile = baseProfile.BaseProfile;

  /**
   * create the instance of a2dp profile.
   *
   * @returns { A2dpSourceProfile } Returns the instance of profile.
   * @throws { BusinessError } 401 - Invalid parameter.
   * @throws { BusinessError } 801 - Capability not supported.
   * @syscap SystemCapability.Communication.Bluetooth.Core
   * @since 10
   */
  function createA2dpSrcProfile(): A2dpSourceProfile;

  /**
   * Manager a2dp source profile.
   *
   * @typedef A2dpSourceProfile
   * @syscap SystemCapability.Communication.Bluetooth.Core
   * @since 10
   */
  interface A2dpSourceProfile extends BaseProfile {
    /**
     * Initiate an A2DP connection to a remote device.
     *
     * @permission ohos.permission.ACCESS_BLUETOOTH
     * @param { string } deviceId - Indicates device ID. For example, "11:22:33:AA:BB:FF".
     * @throws { BusinessError } 201 - Permission denied.
     * @throws { BusinessError } 202 - Non-system applications are not allowed to use system APIs.
     * @throws { BusinessError } 401 - Invalid parameter.
     * @throws { BusinessError } 801 - Capability not supported.
     * @throws { BusinessError } 2900001 - Service stopped.
     * @throws { BusinessError } 2900003 - Bluetooth switch is off.
     * @throws { BusinessError } 2900004 - Profile is not supported.
     * @throws { BusinessError } 2900099 - Operation failed.
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @systemapi
     * @since 10
     */
    connect(deviceId: string): void;

    /**
     * Disconnect the A2DP connection with the remote device.
     *
     * @permission ohos.permission.ACCESS_BLUETOOTH
     * @param { string } deviceId - Indicates device ID. For example, "11:22:33:AA:BB:FF".
     * @throws { BusinessError } 201 - Permission denied.
     * @throws { BusinessError } 202 - Non-system applications are not allowed to use system APIs.
     * @throws { BusinessError } 401 - Invalid parameter.
     * @throws { BusinessError } 801 - Capability not supported.
     * @throws { BusinessError } 2900001 - Service stopped.
     * @throws { BusinessError } 2900003 - Bluetooth switch is off.
     * @throws { BusinessError } 2900004 - Profile is not supported.
     * @throws { BusinessError } 2900099 - Operation failed.
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @systemapi
     * @since 10
     */
    disconnect(deviceId: string): void;

    /**
     * Obtains the playing state of device.
     *
     * @permission ohos.permission.ACCESS_BLUETOOTH
     * @param { string } deviceId - Indicates device ID. For example, "11:22:33:AA:BB:FF".
     * @returns { PlayingState } Returns the playing state.
     * @throws { BusinessError } 201 - Permission denied.
     * @throws { BusinessError } 401 - Invalid parameter.
     * @throws { BusinessError } 801 - Capability not supported.
     * @throws { BusinessError } 2900001 - Service stopped.
     * @throws { BusinessError } 2900003 - Bluetooth switch is off.
     * @throws { BusinessError } 2900004 - Profile is not supported.
     * @throws { BusinessError } 2900099 - Operation failed.
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @since 10
     */
    getPlayingState(deviceId: string): PlayingState;

    /**
     * Checks whether the device supports absolute volume.
     *
     * @permission ohos.permission.ACCESS_BLUETOOTH
     * @param { string } deviceId - Indicates device ID. For example, "11:22:33:AA:BB:FF".
     * @returns { Promise<boolean> } Returns the promise object.
     * @throws { BusinessError } 201 - Permission denied.
     * @throws { BusinessError } 202 - Non-system applications are not allowed to use system APIs.
     * @throws { BusinessError } 401 - Invalid parameter.
     * @throws { BusinessError } 801 - Capability not supported.
     * @throws { BusinessError } 2900001 - Service stopped.
     * @throws { BusinessError } 2900003 - Bluetooth switch is off.
     * @throws { BusinessError } 2900099 - Operation failed.
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @systemapi
     * @since 11
     */
    isAbsoluteVolumeSupported(deviceId: string): Promise<boolean>;

    /**
     * Checks whether the device supports absolute volume.
     *
     * @permission ohos.permission.ACCESS_BLUETOOTH
     * @param { string } deviceId - Indicates device ID. For example, "11:22:33:AA:BB:FF".
     * @param { AsyncCallback<boolean> } callback - Callback used to listen for the pairing request event.
     * @throws { BusinessError } 201 - Permission denied.
     * @throws { BusinessError } 202 - Non-system applications are not allowed to use system APIs.
     * @throws { BusinessError } 401 - Invalid parameter.
     * @throws { BusinessError } 801 - Capability not supported.
     * @throws { BusinessError } 2900001 - Service stopped.
     * @throws { BusinessError } 2900003 - Bluetooth switch is off.
     * @throws { BusinessError } 2900099 - Operation failed.
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @systemapi
     * @since 11
     */
    isAbsoluteVolumeSupported(deviceId: string, callback: AsyncCallback<boolean>): void;

    /**
     * Checks whether the absolute volume is enabled.
     *
     * @permission ohos.permission.ACCESS_BLUETOOTH
     * @param { string } deviceId - Indicates device ID. For example, "11:22:33:AA:BB:FF".
     * @returns { Promise<boolean> } Returns the promise object.
     * @throws { BusinessError } 201 - Permission denied.
     * @throws { BusinessError } 202 - Non-system applications are not allowed to use system APIs.
     * @throws { BusinessError } 401 - Invalid parameter.
     * @throws { BusinessError } 801 - Capability not supported.
     * @throws { BusinessError } 2900001 - Service stopped.
     * @throws { BusinessError } 2900003 - Bluetooth switch is off.
     * @throws { BusinessError } 2900099 - Operation failed.
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @systemapi
     * @since 11
     */
    isAbsoluteVolumeEnabled(deviceId: string): Promise<boolean>;

    /**
     * Checks whether the absolute volume is enabled.
     *
     * @permission ohos.permission.ACCESS_BLUETOOTH
     * @param { string } deviceId - Indicates device ID. For example, "11:22:33:AA:BB:FF".
     * @param { AsyncCallback<boolean> } callback - the callback result.
     * @throws { BusinessError } 201 - Permission denied.
     * @throws { BusinessError } 202 - Non-system applications are not allowed to use system APIs.
     * @throws { BusinessError } 401 - Invalid parameter.
     * @throws { BusinessError } 801 - Capability not supported.
     * @throws { BusinessError } 2900001 - Service stopped.
     * @throws { BusinessError } 2900003 - Bluetooth switch is off.
     * @throws { BusinessError } 2900099 - Operation failed.
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @systemapi
     * @since 11
     */
    isAbsoluteVolumeEnabled(deviceId: string, callback: AsyncCallback<boolean>): void;

    /**
     * Turn on the absolute volume switch.
     *
     * @permission ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH
     * @param { string } deviceId - Indicates device ID. For example, "11:22:33:AA:BB:FF".
     * @returns { Promise<void> } Returns the promise object.
     * @throws { BusinessError } 201 - Permission denied.
     * @throws { BusinessError } 202 - Non-system applications are not allowed to use system APIs.
     * @throws { BusinessError } 401 - Invalid parameter.
     * @throws { BusinessError } 801 - Capability not supported.
     * @throws { BusinessError } 2900001 - Service stopped.
     * @throws { BusinessError } 2900003 - Bluetooth switch is off.
     * @throws { BusinessError } 2900099 - Operation failed.
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @systemapi
     * @since 11
     */
    enableAbsoluteVolume(deviceId: string): Promise<void>;

    /**
     * Turn on the absolute volume switch..
     *
     * @permission ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH
     * @param { string } deviceId - Indicates device ID. For example, "11:22:33:AA:BB:FF".
     * @param { AsyncCallback<void> } callback - the callback result.
     * @throws { BusinessError } 201 - Permission denied.
     * @throws { BusinessError } 202 - Non-system applications are not allowed to use system APIs.
     * @throws { BusinessError } 401 - Invalid parameter.
     * @throws { BusinessError } 801 - Capability not supported.
     * @throws { BusinessError } 2900001 - Service stopped.
     * @throws { BusinessError } 2900003 - Bluetooth switch is off.
     * @throws { BusinessError } 2900099 - Operation failed.
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @systemapi
     * @since 11
     */
    enableAbsoluteVolume(deviceId: string, callback: AsyncCallback<void>): void;

    /**
     * Turn off the absolute volume switch.
     *
     * @permission ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH
     * @param { string } deviceId - Indicates device ID. For example, "11:22:33:AA:BB:FF".
     * @returns { Promise<void> } Returns the promise object.
     * @throws { BusinessError } 201 - Permission denied.
     * @throws { BusinessError } 202 - Non-system applications are not allowed to use system APIs.
     * @throws { BusinessError } 401 - Invalid parameter.
     * @throws { BusinessError } 801 - Capability not supported.
     * @throws { BusinessError } 2900001 - Service stopped.
     * @throws { BusinessError } 2900003 - Bluetooth switch is off.
     * @throws { BusinessError } 2900099 - Operation failed.
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @systemapi
     * @since 11
     */
    disableAbsoluteVolume(deviceId: string): Promise<void>;

    /**
     * Turn off the absolute volume switch..
     *
     * @permission ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH
     * @param { string } deviceId - Indicates device ID. For example, "11:22:33:AA:BB:FF".
     * @param { AsyncCallback<void> } callback - the callback result.
     * @throws { BusinessError } 201 - Permission denied.
     * @throws { BusinessError } 202 - Non-system applications are not allowed to use system APIs.
     * @throws { BusinessError } 401 - Invalid parameter.
     * @throws { BusinessError } 801 - Capability not supported.
     * @throws { BusinessError } 2900001 - Service stopped.
     * @throws { BusinessError } 2900003 - Bluetooth switch is off.
     * @throws { BusinessError } 2900099 - Operation failed.
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @systemapi
     * @since 11
     */
    disableAbsoluteVolume(deviceId: string, callback: AsyncCallback<void>): void;

    /**
     * Get codec information.
     *
     * @permission ohos.permission.ACCESS_BLUETOOTH
     * @param { string } deviceId - Indicates device ID. For example, "11:22:33:AA:BB:FF".
     * @returns { CodecInfo } Returns the CodecInfo.
     * @throws { BusinessError } 201 - Permission denied.
     * @throws { BusinessError } 202 - Non-system applications are not allowed to use system APIs.
     * @throws { BusinessError } 401 - Invalid parameter.
     * @throws { BusinessError } 801 - Capability not supported.
     * @throws { BusinessError } 2900001 - Service stopped.
     * @throws { BusinessError } 2900003 - Bluetooth switch is off.
     * @throws { BusinessError } 2900099 - Operation failed.
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @systemapi
     * @since 11
     */
    getCurrentCodecInfo(deviceId: string): CodecInfo;
    
    /**
     * Set codec information.
     *
     * @permission ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH
     * @param { string } deviceId - Indicates device ID. For example, "11:22:33:AA:BB:FF".
     * @param { CodecInfo } codecInfo - Indicates the CodecInfo.
     * @throws { BusinessError } 201 - Permission denied.
     * @throws { BusinessError } 202 - Non-system applications are not allowed to use system APIs.
     * @throws { BusinessError } 401 - Invalid parameter.
     * @throws { BusinessError } 801 - Capability not supported.
     * @throws { BusinessError } 2900001 - Service stopped.
     * @throws { BusinessError } 2900003 - Bluetooth switch is off.
     * @throws { BusinessError } 2900099 - Operation failed.
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @systemapi
     * @since 11
     */
    setCurrentCodecInfo(deviceId: string, codecInfo: CodecInfo): void;

    /**
     * Restriction devices to play music within {@code duration} milliseconds of connection.
     *
     * @permission ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH
     * @param { string } deviceId - Indicates device ID. For example, "11:22:33:AA:BB:FF".
     * @param { number } duration - Restricted duration <milliseconds>. Valid range is from 3000ms to 20000ms.
     * @returns { Promise<void> } Returns the promise object.
     * @throws { BusinessError } 201 - Permission denied.
     * @throws { BusinessError } 202 - Non-system applications are not allowed to use system APIs.
     * @throws { BusinessError } 401 - Invalid parameter.
     * @throws { BusinessError } 801 - Capability not supported.
     * @throws { BusinessError } 2900001 - Service stopped.
     * @throws { BusinessError } 2900003 - Bluetooth switch is off.
     * @throws { BusinessError } 2900099 - Operation failed.
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @systemapi
     * @since 12
     */
    disableAutoPlay(deviceId: string, duration: number): Promise<void>;

    /**
     * Allow devices to automatically play music when connected.
     *
     * @permission ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH
     * @param { string } deviceId - Indicates device ID. For example, "11:22:33:AA:BB:FF".
     * @returns { Promise<void> } Returns the promise object.
     * @throws { BusinessError } 201 - Permission denied.
     * @throws { BusinessError } 202 - Non-system applications are not allowed to use system APIs.
     * @throws { BusinessError } 401 - Invalid parameter.
     * @throws { BusinessError } 801 - Capability not supported.
     * @throws { BusinessError } 2900001 - Service stopped.
     * @throws { BusinessError } 2900003 - Bluetooth switch is off.
     * @throws { BusinessError } 2900099 - Operation failed.
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @systemapi
     * @since 12
     */
    enableAutoPlay(deviceId: string): Promise<void>;

    /**
     * Obtains the duration for which automatic playback is disabled.
     *
     * @permission ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH
     * @param { string } deviceId - Indicates device ID. For example, "11:22:33:AA:BB:FF".
     * @returns { Promise<number> } Returns the duration <milliseconds>; 
     *                              If returns { @code -1 } means allow devices automatic play music when connected.
     * @throws { BusinessError } 201 - Permission denied.
     * @throws { BusinessError } 202 - Non-system applications are not allowed to use system APIs.
     * @throws { BusinessError } 401 - Invalid parameter.
     * @throws { BusinessError } 801 - Capability not supported.
     * @throws { BusinessError } 2900001 - Service stopped.
     * @throws { BusinessError } 2900003 - Bluetooth switch is off.
     * @throws { BusinessError } 2900099 - Operation failed.
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @systemapi
     * @since 12
     */
    getAutoPlayDisabledDuration(deviceId: string): Promise<number>;
  }

  /**
   * Describes the codec information.
   *
   * @typedef CodecInfo
   * @syscap SystemCapability.Communication.Bluetooth.Core
   * @since 11
   */
  interface CodecInfo {
    /**
     * codec type
     *
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @since 11
     */
    codecType: CodecType;
    /**
     * codec bits per sample.
     *
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @since 11
     */
    codecBitsPerSample: CodecBitsPerSample;
    /**
     * codec channel mode.
     *
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @since 11
     */
    codecChannelMode: CodecChannelMode;
    /**
     * codec sample rate.
     *
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @since 11
     */
    codecSampleRate: CodecSampleRate;
  }

  /**
   * The enum of a2dp playing state.
   *
   * @enum { number }
   * @syscap SystemCapability.Communication.Bluetooth.Core
   * @since 10
   */
  enum PlayingState {
    /**
     * Not playing.
     *
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @since 10
     */
    STATE_NOT_PLAYING,
    /**
     * Playing.
     *
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @since 10
     */
    STATE_PLAYING
  }

  /**
   * Describes the codec type.
   *
   * @enum { number }
   * @syscap SystemCapability.Communication.Bluetooth.Core
   * @since 11
   */
  enum CodecType {
    /**
     * invalid codec type.
     *
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @since 11
     */
    CODEC_TYPE_INVALID = -1,
    /**
     * SBC - Sub-band coding.
     *
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @since 11
     */
    CODEC_TYPE_SBC = 0,
    /**
     * AAC -Advanced Audio Coding.
     *
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @since 11
     */
    CODEC_TYPE_AAC = 1,
    /**
     * L2HC.
     *
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @since 11
     */
    CODEC_TYPE_L2HC = 2
  }

  /**
   * Describes the codec channel mode.
   *
   * @enum { number }
   * @syscap SystemCapability.Communication.Bluetooth.Core
   * @since 11
   */
  enum CodecChannelMode {
    /**
     * Codec channel mode none.
     *
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @since 11
     */
    CODEC_CHANNEL_MODE_NONE = 0,
    /**
     * Codec channel mode MONO.
     *
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @since 11
     */
    CODEC_CHANNEL_MODE_MONO = 1,
    /**
     * Codec channel mode STEREO.
     *
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @since 11
     */
    CODEC_CHANNEL_MODE_STEREO = 2
  }

  /**
   * Describes the codec bits per sample.
   *
   * @enum { number }
   * @syscap SystemCapability.Communication.Bluetooth.Core
   * @since 11
   */
  enum CodecBitsPerSample {
    /**
     * Codec bits per sample none.
     *
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @since 11
     */
    CODEC_BITS_PER_SAMPLE_NONE = 0,
    /**
     * Codec 16 bits per sample.
     *
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @since 11
     */
    CODEC_BITS_PER_SAMPLE_16 = 1,
    /**
     * Codec 24 bits per sample.
     *
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @since 11
     */
    CODEC_BITS_PER_SAMPLE_24 = 2,
    /**
     * Codec 32 bits per sample.
     *
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @since 11
     */
    CODEC_BITS_PER_SAMPLE_32 = 3
  }

  /**
   * Describes the codec sample rate.
   *
   * @enum { number }
   * @syscap SystemCapability.Communication.Bluetooth.Core
   * @since 11
   */
  enum CodecSampleRate {
    /**
     * Codec sample rate none.
     *
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @since 11
     */
    CODEC_SAMPLE_RATE_NONE = 0,
    /**
     * Codec sample rate 44.1k.
     *
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @since 11
     */
    CODEC_SAMPLE_RATE_44100 = 1,
    /**
     * Codec sample rate 48k.
     *
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @since 11
     */
    CODEC_SAMPLE_RATE_48000 = 2,
    /**
     * Codec sample rate 88.2k.
     *
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @since 11
     */
    CODEC_SAMPLE_RATE_88200 = 3,
    /**
     * Codec sample rate 96k.
     *
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @since 11
     */
    CODEC_SAMPLE_RATE_96000 = 4,
    /**
     * Codec sample rate 176.4k.
     *
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @since 11
     */
    CODEC_SAMPLE_RATE_176400 = 5,
    /**
     * Codec sample rate 192k.
     *
     * @syscap SystemCapability.Communication.Bluetooth.Core
     * @since 11
     */
    CODEC_SAMPLE_RATE_192000 = 6
  }
}

export default a2dp;