/*
 * Copyright (c) 2021-2023 Huawei Device Co., Ltd.
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

import { ErrorCallback, AsyncCallback, Callback } from './@ohos.base';

/**
 * @namespace audio
 * @since 7
 */
declare namespace audio {
  /**
   * Enumerates audio errors.
   * @enum {number}
   * @syscap SystemCapability.Multimedia.Audio.Core
   * @since 9
   */
  enum AudioErrors {
    /**
     * Invalid parameter.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 9
     */
    ERROR_INVALID_PARAM = 6800101,
    /**
     * Allocate memory failed.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 9
     */
    ERROR_NO_MEMORY = 6800102,
    /**
     * Operation not permit at current state.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 9
     */
    ERROR_ILLEGAL_STATE = 6800103,
    /**
     * Unsupported option.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 9
     */
    ERROR_UNSUPPORTED = 6800104,
    /**
     * Time out.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 9
     */
    ERROR_TIMEOUT = 6800105,
    /**
     * Audio specific errors.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 9
     */
    ERROR_STREAM_LIMIT = 6800201,
    /**
     * Default error.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 9
     */
    ERROR_SYSTEM = 6800301
  }

  /**
   * Define local device network id for audio
   * @constant
   * @syscap SystemCapability.Multimedia.Audio.Device
   * @systemapi
   * @since 9
   */
  const LOCAL_NETWORK_ID: string;

  /**
   * Define default volume group id for audio
   * @constant
   * @syscap SystemCapability.Multimedia.Audio.Volume
   * @since 9
   */
  const DEFAULT_VOLUME_GROUP_ID: number;

  /**
   * Define default interrupt group id for audio
   * @constant
   * @syscap SystemCapability.Multimedia.Audio.Interrupt
   * @since 9
   */
  const DEFAULT_INTERRUPT_GROUP_ID: number;

  /**
   * Obtains an {@link AudioManager} instance.
   * @returns { AudioManager } this {@link AudioManager} object.
   * @syscap SystemCapability.Multimedia.Audio.Core
   * @since 7
   */
  function getAudioManager(): AudioManager;

  /**
   * Obtains an {@link AudioCapturer} instance. This method uses an asynchronous callback to return the capturer instance.
   * @param { AudioCapturerOptions } options - Capturer configurations.
   * @param { AsyncCallback<AudioCapturer> } callback - Callback used to return the audio capturer instance.
   * @syscap SystemCapability.Multimedia.Audio.Capturer
   * @since 8
   */
  function createAudioCapturer(options: AudioCapturerOptions, callback: AsyncCallback<AudioCapturer>): void;

  /**
   * Obtains an {@link AudioCapturer} instance. This method uses a promise to return the capturer instance.
   * @param { AudioCapturerOptions } options - Capturer configurations.
   * @returns { Promise<AudioCapturer> } Promise used to return the audio capturer instance.
   * @syscap SystemCapability.Multimedia.Audio.Capturer
   * @since 8
   */
  function createAudioCapturer(options: AudioCapturerOptions): Promise<AudioCapturer>;

  /**
   * Obtains an {@link AudioRenderer} instance. This method uses an asynchronous callback to return the renderer instance.
   * @param { AudioRendererOptions } options - Renderer configurations.
   * @param { AsyncCallback<AudioRenderer> } callback - Callback used to return the audio renderer instance.
   * @syscap SystemCapability.Multimedia.Audio.Renderer
   * @since 8
   */
  function createAudioRenderer(options: AudioRendererOptions, callback: AsyncCallback<AudioRenderer>): void;

  /**
   * Obtains an {@link AudioRenderer} instance. This method uses a promise to return the renderer instance.
   * @param { AudioRendererOptions } options - Renderer configurations.
   * @returns { Promise<AudioRenderer> } Promise used to return the audio renderer instance.
   * @syscap SystemCapability.Multimedia.Audio.Renderer
   * @since 8
   */
  function createAudioRenderer(options: AudioRendererOptions): Promise<AudioRenderer>;

  /**
   * Obtains a {@link TonePlayer} instance. This method uses an asynchronous callback to return the renderer instance.
   * @param { AudioRendererInfo } options - Tone playing attribute.
   * @param { AsyncCallback<TonePlayer> } callback - Callback used to return the tonePlayer instance.
   * @syscap SystemCapability.Multimedia.Audio.Tone
   * @systemapi
   * @since 9
   */
  function createTonePlayer(options: AudioRendererInfo, callback: AsyncCallback<TonePlayer>): void;

  /**
   * Obtains a {@link TonePlayer} instance. This method uses a promise to return the renderer instance.
   * @param { AudioRendererInfo } options - Tone playing attribute.
   * @returns { Promise<TonePlayer> } Promise used to return the tonePlayer instance.
   * @syscap SystemCapability.Multimedia.Audio.Tone
   * @systemapi
   * @since 9
   */
  function createTonePlayer(options: AudioRendererInfo): Promise<TonePlayer>;

  /**
   * Enumerates the audio states.
   * @enum { number }
   * @syscap SystemCapability.Multimedia.Audio.Core
   * @since 8
   */
  enum AudioState {
    /**
     * Invalid state.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    STATE_INVALID = -1,
    /**
     * Create new instance state.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    STATE_NEW = 0,
    /**
     * Prepared state.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    STATE_PREPARED = 1,
    /**
     * Running state.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    STATE_RUNNING = 2,
    /**
     * Stopped state.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    STATE_STOPPED = 3,
    /**
     * Released state.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    STATE_RELEASED = 4,
    /**
     * Paused state.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    STATE_PAUSED = 5
  }

  /**
   * Enumerates audio stream types.
   * @enum { number }
   * @syscap SystemCapability.Multimedia.Audio.Volume
   * @since 7
   */
  enum AudioVolumeType {
    /**
     * Audio streams for voice calls.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 8
     */
    VOICE_CALL = 0,
    /**
     * Audio streams for ringtones.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 7
     */
    RINGTONE = 2,
    /**
     * Audio streams for media purpose.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 7
     */
    MEDIA = 3,
    /**
     * Audio stream for voice assistant.
     * Audio volume for alarm purpose.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 10
     */
    ALARM = 4,
    /**
     * Audio volume for accessibility purpose.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 10
     */
    ACCESSIBILITY = 5,
    /**
     * Audio stream for voice assistant.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 8
     */
    VOICE_ASSISTANT = 9,
    /**
     * Audio volume for ultrasonic.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @systemapi
     * @since 10
     */
    ULTRASONIC = 10,
    /**
     * Audio stream for all common.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @systemapi
     * @since 9
     */
    ALL = 100,
  }

  /**
   * Enumerates audio device flags.
   * @enum { number }
   * @syscap SystemCapability.Multimedia.Audio.Device
   * @since 7
   */
  enum DeviceFlag {
    /**
     * None devices.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @systemapi
     * @since 9
     */
    NONE_DEVICES_FLAG = 0,
    /**
     * Output devices.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 7
     */
    OUTPUT_DEVICES_FLAG = 1,
    /**
     * Input devices.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 7
     */
    INPUT_DEVICES_FLAG = 2,
    /**
     * All devices.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 7
     */
    ALL_DEVICES_FLAG = 3,
    /**
     * Distributed output devices.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @systemapi
     * @since 9
     */
    DISTRIBUTED_OUTPUT_DEVICES_FLAG = 4,
    /**
     * Distributed input devices.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @systemapi
     * @since 9
     */
    DISTRIBUTED_INPUT_DEVICES_FLAG = 8,
    /**
     * All Distributed devices.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @systemapi
     * @since 9
     */
    ALL_DISTRIBUTED_DEVICES_FLAG = 12,
  }

  /**
   * Enumerates device roles.
   * @enum { number }
   * @syscap SystemCapability.Multimedia.Audio.Device
   * @since 7
   */
  enum DeviceRole {
    /**
     * Input role.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 7
     */
    INPUT_DEVICE = 1,
    /**
     * Output role.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 7
     */
    OUTPUT_DEVICE = 2,
  }

  /**
   * Enumerates device types.
   * @enum { number }
   * @syscap SystemCapability.Multimedia.Audio.Device
   * @since 7
   */
  enum DeviceType {
    /**
     * Invalid device.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 7
     */
    INVALID = 0,
    /**
     * Built-in earpiece.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 7
     */
    EARPIECE = 1,
    /**
     * Built-in speaker.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 7
     */
    SPEAKER = 2,
    /**
     * Wired headset, which is a combination of a pair of earpieces and a microphone.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 7
     */
    WIRED_HEADSET = 3,
    /**
     * A pair of wired headphones.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 7
     */
    WIRED_HEADPHONES = 4,
    /**
     * Bluetooth device using the synchronous connection oriented link (SCO).
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 7
     */
    BLUETOOTH_SCO = 7,
    /**
     * Bluetooth device using advanced audio distribution profile (A2DP).
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 7
     */
    BLUETOOTH_A2DP = 8,
    /**
     * Built-in microphone.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 7
     */
    MIC = 15,
    /**
     * USB audio headset.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 7
     */
    USB_HEADSET = 22,
    /**
     * Default device type.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 9
     */
    DEFAULT = 1000,
  }

  /**
   * Enumerates the active device types.
   * @enum { number }
   * @syscap SystemCapability.Multimedia.Audio.Device
   * @since 7
   * @deprecated since 9
   * @useinstead ohos.multimedia.audio.CommunicationDeviceType
   */
  enum ActiveDeviceType {
    /**
     * Speaker.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.multimedia.audio.CommunicationDeviceType.SPEAKER
     */
    SPEAKER = 2,
    /**
     * Bluetooth device using the SCO link.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 7
     * @deprecated since 9
     */
    BLUETOOTH_SCO = 7,
  }

  /**
   * Enumerates the available device types for communication.
   * @enum { number }
   * @syscap SystemCapability.Multimedia.Audio.Communication
   * @since 9
   */
  enum CommunicationDeviceType {
    /**
     * Speaker.
     * @syscap SystemCapability.Multimedia.Audio.Communication
     * @since 9
     */
    SPEAKER = 2
  }

  /**
   * Enumerates ringer modes.
   * @enum { number }
   * @syscap SystemCapability.Multimedia.Audio.Communication
   * @since 7
   */
  enum AudioRingMode {
    /**
     * Silent mode.
     * @syscap SystemCapability.Multimedia.Audio.Communication
     * @since 7
     */
    RINGER_MODE_SILENT = 0,
    /**
     * Vibration mode.
     * @syscap SystemCapability.Multimedia.Audio.Communication
     * @since 7
     */
    RINGER_MODE_VIBRATE = 1,
    /**
     * Normal mode.
     * @syscap SystemCapability.Multimedia.Audio.Communication
     * @since 7
     */
    RINGER_MODE_NORMAL = 2,
  }

  /**
   * Enumerates the audio sample formats.
   * @enum { number }
   * @syscap SystemCapability.Multimedia.Audio.Core
   * @since 8
   */
  enum AudioSampleFormat {
    /**
     * Invalid format.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    SAMPLE_FORMAT_INVALID = -1,
    /**
     * Unsigned 8 format.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    SAMPLE_FORMAT_U8 = 0,
    /**
     * Signed 16 bit integer, little endian.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    SAMPLE_FORMAT_S16LE = 1,
    /**
     * Signed 24 bit integer, little endian.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    SAMPLE_FORMAT_S24LE = 2,
    /**
     * Signed 32 bit integer, little endian.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    SAMPLE_FORMAT_S32LE = 3,
    /**
     * Signed 32 bit float, little endian.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 9
     */
    SAMPLE_FORMAT_F32LE = 4,
  }

  /**
   * Enumerates the audio channel.
   * @enum { number }
   * @syscap SystemCapability.Multimedia.Audio.Core
   * @since 8
   */
  enum AudioChannel {
    /**
     * Channel 1.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    CHANNEL_1 = 0x1 << 0,
    /**
     * Channel 2.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    CHANNEL_2 = 0x1 << 1
  }

  /**
   * Enumerates the audio sampling rate.
   * @enum { number }
   * @syscap SystemCapability.Multimedia.Audio.Core
   * @since 8
   */
  enum AudioSamplingRate {
    /**
     * 8kHz sample rate.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    SAMPLE_RATE_8000 = 8000,
    /**
     * 11.025kHz sample rate.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    SAMPLE_RATE_11025 = 11025,
    /**
     * 12kHz sample rate.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    SAMPLE_RATE_12000 = 12000,
    /**
     * 16kHz sample rate.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    SAMPLE_RATE_16000 = 16000,
    /**
     * 22.05kHz sample rate.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    SAMPLE_RATE_22050 = 22050,
    /**
     * 24kHz sample rate.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    SAMPLE_RATE_24000 = 24000,
    /**
     * 32kHz sample rate.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    SAMPLE_RATE_32000 = 32000,
    /**
     * 44.1kHz sample rate.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    SAMPLE_RATE_44100 = 44100,
    /**
     * 48kHz sample rate.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    SAMPLE_RATE_48000 = 48000,
    /**
     * 64kHz sample rate.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    SAMPLE_RATE_64000 = 64000,
    /**
     * 96kHz sample rate.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    SAMPLE_RATE_96000 = 96000
  }

  /**
   * Enumerates the audio encoding type.
   * @enum { number }
   * @syscap SystemCapability.Multimedia.Audio.Core
   * @since 8
   */
  enum AudioEncodingType {
    /**
     * Invalid type.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    ENCODING_TYPE_INVALID = -1,
    /**
     * PCM encoding.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    ENCODING_TYPE_RAW = 0
  }

  /**
   * Enumerates the audio content type.
   * @enum { number }
   * @syscap SystemCapability.Multimedia.Audio.Core
   * @since 7
   */
  enum ContentType {
    /**
     * Unknown content.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 7
     */
    CONTENT_TYPE_UNKNOWN = 0,
    /**
     * Speech content.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 7
     */
    CONTENT_TYPE_SPEECH = 1,
    /**
     * Music content.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 7
     */
    CONTENT_TYPE_MUSIC = 2,
    /**
     * Movie content.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 7
     */
    CONTENT_TYPE_MOVIE = 3,
    /**
     * Notification content.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 7
     */
    CONTENT_TYPE_SONIFICATION = 4,
    /**
     * Ringtone content.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    CONTENT_TYPE_RINGTONE = 5,
    /**
     * Ultrasonic content.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @systemapi
     * @since 10
     */
    CONTENT_TYPE_ULTRASONIC = 9
  }

  /**
   * Enumerates the stream usage.
   * @enum { number }
   * @syscap SystemCapability.Multimedia.Audio.Core
   * @since 7
   */
  enum StreamUsage {
    /**
     * Unknown usage.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 7
     */
    STREAM_USAGE_UNKNOWN = 0,
    /**
     * Media usage.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 7
     */
    STREAM_USAGE_MEDIA = 1,
    /**
     * Voice communication usage.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 7
     */
    STREAM_USAGE_VOICE_COMMUNICATION = 2,
    /**
     * Voice assistant broadcast usage.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 9
     */
    STREAM_USAGE_VOICE_ASSISTANT = 3,
    /**
     * Alarm usage.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 10
     */
    STREAM_USAGE_ALARM = 4,
    /**
     * Notification or ringtone usage.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 7
     */
    STREAM_USAGE_NOTIFICATION_RINGTONE = 6,
    /**
     * Accessibility usage, such as screen reader.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 10
     */
    STREAM_USAGE_ACCESSIBILITY = 8,
    /**
     * System usage, such as screen lock or key click.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @systemapi
     * @since 10
     */
    STREAM_USAGE_SYSTEM = 9,
  }

  /**
   * Enumerates the audio interrupt request type.
   * @enum { number }
   * @syscap SystemCapability.Multimedia.Audio.Interrupt
   * @systemapi
   * @since 9
   */
  enum InterruptRequestType {
    /**
     * Default type to request audio interrupt.
     * @syscap SystemCapability.Multimedia.Audio.Interrupt
     * @systemapi
     * @since 9
     */
    INTERRUPT_REQUEST_TYPE_DEFAULT = 0,
  }

  /**
   * Describes audio stream information.
   * @typedef AudioStreamInfo
   * @syscap SystemCapability.Multimedia.Audio.Core
   * @since 8
   */
  interface AudioStreamInfo {
    /**
     * Sampling rate.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    samplingRate: AudioSamplingRate;
    /**
     * Audio channels.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    channels: AudioChannel;
    /**
     * Audio sample format.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    sampleFormat: AudioSampleFormat;
    /**
     * Audio encoding type.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    encodingType: AudioEncodingType;
  }

  /**
   * Describes audio renderer information.
   * @typedef AudioRendererInfo
   * @syscap SystemCapability.Multimedia.Audio.Core
   * @since 8
   */
  interface AudioRendererInfo {
    /**
     * Content type.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    content: ContentType;
    /**
     * Stream usage.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    usage: StreamUsage;
    /**
     * Audio renderer flags.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    rendererFlags: number;
  }

  /** 
   * Describes audio renderer filter.
   * @typedef AudioRendererFilter
   * @syscap SystemCapability.Multimedia.Audio.Core
   * @systemapi
   * @since 9
   */
  interface AudioRendererFilter {
    /**
     * Application uid.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @systemapi
     * @since 9
     */
    uid?: number;
    /**
     * Renderer information.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @systemapi
     * @since 9
     */
    rendererInfo?: AudioRendererInfo;
    /**
     * AudioRenderer id.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @systemapi
     * @since 9
     */
    rendererId?: number;
  }

  /**
   * Describes audio renderer configuration options.
   * @typedef AudioRendererOptions
   * @syscap SystemCapability.Multimedia.Audio.Renderer
   * @since 8
   */
  interface AudioRendererOptions {
    /**
     * Stream information.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 8
     */
    streamInfo: AudioStreamInfo;
    /**
     * Renderer information.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 8
     */
    rendererInfo: AudioRendererInfo;
    /**
     * Privacy configuration.
     * @since 10
     * @syscap SystemCapability.Multimedia.Audio.PlaybackCapture
     */
    privacyType?: AudioPrivacyType;
  }

  /**
   * Enumerates audio stream privacy type for playback capture.
   * @since 10
   * @syscap SystemCapability.Multimedia.Audio.PlaybackCapture
   */
  enum AudioPrivacyType {
    /**
     * Privacy type that stream can be captured by third party applications.
     * @since 10
     * @syscap SystemCapability.Multimedia.Audio.PlaybackCapture
     */
    PRIVACY_TYPE_PUBLIC = 0,

    /**
     * Privacy type that stream can be only captured by system.
     * @since 10
     * @syscap SystemCapability.Multimedia.Audio.PlaybackCapture
     */
    PRIVACY_TYPE_PROTECTED = 1,

    /**
     * Privacy type that stream can not be captured.
     * @since 10
     * @syscap SystemCapability.Multimedia.Audio.PlaybackCapture
     */
    PRIVACY_TYPE_PRIVATE = 2,
  }

  /**
   * Enumerates the interrupt modes.
   * @enum { number }
   * @syscap SystemCapability.Multimedia.Audio.Interrupt
   * @since 9
   */
  enum InterruptMode {
    /**
     * Mode that different stream share one interrupt unit.
     * @syscap SystemCapability.Multimedia.Audio.Interrupt
     * @since 9
     */
    SHARE_MODE = 0,
    /**
     * Mode that each stream has independent interrupt unit.
     * @syscap SystemCapability.Multimedia.Audio.Interrupt
     * @since 9
     */
    INDEPENDENT_MODE = 1
  }

  /**
   * Enumerates the audio renderer rates.
   * @enum { number }
   * @syscap SystemCapability.Multimedia.Audio.Renderer
   * @since 8
   */
  enum AudioRendererRate {
    /**
     * Normal rate.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 8
     */
    RENDER_RATE_NORMAL = 0,
    /**
     * Double rate.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 8
     */
    RENDER_RATE_DOUBLE = 1,
    /**
     * Half rate.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 8
     */
    RENDER_RATE_HALF = 2
  }

  /**
   * Enumerates the interrupt types.
   * @enum { number }
   * @syscap SystemCapability.Multimedia.Audio.Renderer
   * @since 7
   */
  enum InterruptType {
    /**
     * Audio playback interruption started.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 7
     */
    INTERRUPT_TYPE_BEGIN = 1,

    /**
     * Audio playback interruption ended.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 7
     */
    INTERRUPT_TYPE_END = 2
  }

  /**
   * Enumerates the interrupt hints.
   * @enum { number }
   * @syscap SystemCapability.Multimedia.Audio.Renderer
   * @since 7
   */
  enum InterruptHint {
    /**
     * None.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 8
     */
    INTERRUPT_HINT_NONE = 0,
    /**
     * Resume the playback.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 7
     */
    INTERRUPT_HINT_RESUME = 1,

    /**
     * Paused/Pause the playback.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 7
     */
    INTERRUPT_HINT_PAUSE = 2,

    /**
     * Stopped/Stop the playback.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 7
     */
    INTERRUPT_HINT_STOP = 3,

    /**
     * Ducked the playback. (In ducking, the audio volume is reduced, but not silenced.)
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 7
     */
    INTERRUPT_HINT_DUCK = 4,

    /**
     * Unducked the playback.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 8
     */
    INTERRUPT_HINT_UNDUCK = 5,
  }

  /**
   * Enumerates the interrupt force types.
   * @enum { number }
   * @syscap SystemCapability.Multimedia.Audio.Renderer
   * @since 9
   */
  enum InterruptForceType {
    /**
     * Forced action taken by system.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 9
     */
    INTERRUPT_FORCE = 0,
    /**
     * Share type, application can choose to take action or ignore.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 9
     */
    INTERRUPT_SHARE = 1
  }

  /**
   * Describes the interrupt event received by the app when playback is interrupted.
   * @typedef InterruptEvent
   * @syscap SystemCapability.Multimedia.Audio.Renderer
   * @since 9
   */
  interface InterruptEvent {
    /**
     * Indicates whether the interruption has started or finished.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 9
     */
    eventType: InterruptType;

    /**
     * Indicates whether the action is taken by system or to be taken by the app.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 9
     */
    forceType: InterruptForceType;

    /**
     * Indicates the kind of action.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 9
     */
    hintType: InterruptHint;
  }

  /**
   * Enumerates interrupt action types.
   * @enum { number }
   * @syscap SystemCapability.Multimedia.Audio.Renderer
   * @since 7
   * @deprecated since 9
   */
  enum InterruptActionType {

    /**
     * Focus gain event.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 7
     * @deprecated since 9
     */
    TYPE_ACTIVATED = 0,

    /**
     * Audio interruption event.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 7
     * @deprecated since 9
     */
    TYPE_INTERRUPT = 1
  }

  /**
   * Enumerates device change types.
   * @enum { number }
   * @syscap SystemCapability.Multimedia.Audio.Device
   * @since 7
   */
  enum DeviceChangeType {
    /**
     * Device connection.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 7
     */
    CONNECT = 0,

    /**
     * Device disconnection.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 7
     */
    DISCONNECT = 1,
  }

  /**
   * Enumerates audio scenes.
   * @enum { number }
   * @syscap SystemCapability.Multimedia.Audio.Communication
   * @since 8
   */
  enum AudioScene {
    /**
     * Default audio scene
     * @syscap SystemCapability.Multimedia.Audio.Communication
     * @since 8
     */
    AUDIO_SCENE_DEFAULT = 0,
    /**
     * Ringing audio scene
     * @syscap SystemCapability.Multimedia.Audio.Communication
     * @systemapi
     * @since 8
     */
    AUDIO_SCENE_RINGING = 1,
    /**
     * Phone call audio scene
     * @syscap SystemCapability.Multimedia.Audio.Communication
     * @systemapi
     * @since 8
     */
    AUDIO_SCENE_PHONE_CALL = 2,
    /**
     * Voice chat audio scene
     * @syscap SystemCapability.Multimedia.Audio.Communication
     * @since 8
     */
    AUDIO_SCENE_VOICE_CHAT = 3
  }

  /**
   * Enumerates volume adjustment types.
   * @enum { number }
   * @syscap SystemCapability.Multimedia.Audio.Volume
   * @systemapi
   * @since 10
   */
  enum VolumeAdjustType {
    /**
     * Adjust volume up.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @systemapi
     * @since 10
     */
    VOLUME_UP = 0,
    /**
     * Adjust volume down.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @systemapi
     * @since 10
     */
    VOLUME_DOWN = 1,
  }

  /**
   * Implements audio volume and audio device management.
   * @typedef AudioManager
   * @syscap SystemCapability.Multimedia.Audio.Core
   * @since 7
   */
  interface AudioManager {
    /**
     * Sets the volume for a stream. This method uses an asynchronous callback to return the result.
     * @permission ohos.permission.ACCESS_NOTIFICATION_POLICY
     * @param { AudioVolumeType } volumeType - Audio stream type.
     * @param { number } volume - Volume to set. The value range can be obtained by calling getMinVolume and getMaxVolume.
     * @param { AsyncCallback<void> } callback - Callback used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.multimedia.audio.AudioVolumeGroupManager#setVolume
     */
    setVolume(volumeType: AudioVolumeType, volume: number, callback: AsyncCallback<void>): void;
    /**
     * Sets the volume for a stream. This method uses a promise to return the result.
     * @permission ohos.permission.ACCESS_NOTIFICATION_POLICY
     * @param { AudioVolumeType } volumeType - Audio stream type.
     * @param { number } volume - Volume to set. The value range can be obtained by calling getMinVolume and getMaxVolume.
     * @returns { Promise<void> } Promise used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.multimedia.audio.AudioVolumeGroupManager#setVolume
     */
    setVolume(volumeType: AudioVolumeType, volume: number): Promise<void>;
    /**
     * Obtains the volume of a stream. This method uses an asynchronous callback to return the query result.
     * @param { AudioVolumeType } volumeType - Audio stream type.
     * @param { AsyncCallback<number> } callback - Callback used to return the volume.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.multimedia.audio.AudioVolumeGroupManager#getVolume
     */
    getVolume(volumeType: AudioVolumeType, callback: AsyncCallback<number>): void;
    /**
     * Obtains the volume of a stream. This method uses a promise to return the query result.
     * @param { AudioVolumeType } volumeType - Audio stream type.
     * @returns { Promise<number> } Promise used to return the volume.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.multimedia.audio.AudioVolumeGroupManager#getVolume
     */
    getVolume(volumeType: AudioVolumeType): Promise<number>;
    /**
     * Obtains the minimum volume allowed for a stream. This method uses an asynchronous callback to return the query result.
     * @param { AudioVolumeType } volumeType - Audio stream type.
     * @param { AsyncCallback<number> } callback - Callback used to return the minimum volume.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.multimedia.audio.AudioVolumeGroupManager#getMinVolume
     */
    getMinVolume(volumeType: AudioVolumeType, callback: AsyncCallback<number>): void;
    /**
     * Obtains the minimum volume allowed for a stream. This method uses a promise to return the query result.
     * @param { AudioVolumeType } volumeType - Audio stream type.
     * @returns { Promise<number> } Promise used to return the minimum volume.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.multimedia.audio.AudioVolumeGroupManager#getMinVolume
     */
    getMinVolume(volumeType: AudioVolumeType): Promise<number>;
    /**
     * Obtains the maximum volume allowed for a stream. This method uses an asynchronous callback to return the query result.
     * @param { AudioVolumeType } volumeType - Audio stream type.
     * @param { AsyncCallback<number> } callback - Callback used to return the maximum volume.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.multimedia.audio.AudioVolumeGroupManager#getMaxVolume
     */
    getMaxVolume(volumeType: AudioVolumeType, callback: AsyncCallback<number>): void;
    /**
     * Obtains the maximum volume allowed for a stream. This method uses a promise to return the query result.
     * @param { AudioVolumeType } volumeType - Audio stream type.
     * @returns { Promise<number> } Promise used to return the maximum volume.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.multimedia.audio.AudioVolumeGroupManager#getMaxVolume
     */
    getMaxVolume(volumeType: AudioVolumeType): Promise<number>;
    /**
     * Obtains the audio devices with a specific flag. This method uses an asynchronous callback to return the query result.
     * @param { DeviceFlag } deviceFlag - Audio device flag.
     * @param { AsyncCallback<AudioDeviceDescriptors> } callback - Callback used to return the device list.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.multimedia.audio.AudioRoutingManager#getDevices
     */
    getDevices(deviceFlag: DeviceFlag, callback: AsyncCallback<AudioDeviceDescriptors>): void;
    /**
     * Obtains the audio devices with a specific flag. This method uses a promise to return the query result.
     * @param { DeviceFlag } deviceFlag - Audio device flag.
     * @returns { Promise<AudioDeviceDescriptors> } Promise used to return the device list.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.multimedia.audio.AudioRoutingManager#getDevices
     */
    getDevices(deviceFlag: DeviceFlag): Promise<AudioDeviceDescriptors>;
    /**
     * Mutes a stream. This method uses an asynchronous callback to return the result.
     * @param { AudioVolumeType } volumeType - Audio stream type.
     * @param { boolean } mute - Mute status to set. The value true means to mute the stream, and false means the opposite.
     * @param { AsyncCallback<void> } callback - Callback used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.multimedia.audio.AudioVolumeGroupManager#mute
     */
    mute(volumeType: AudioVolumeType, mute: boolean, callback: AsyncCallback<void>): void;
    /**
     * Mutes a stream. This method uses a promise to return the result.
     * @param { AudioVolumeType } volumeType - Audio stream type.
     * @param { boolean } mute -  Mute status to set. The value true means to mute the stream, and false means the opposite.
     * @returns { Promise<void> } Promise used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.multimedia.audio.AudioVolumeGroupManager#mute
     */
    mute(volumeType: AudioVolumeType, mute: boolean): Promise<void>;
    /**
     * Checks whether a stream is muted. This method uses an asynchronous callback to return the query result.
     * @param { AudioVolumeType } volumeType - Audio stream type.
     * @param { AsyncCallback<boolean> } callback - Callback used to return the mute status of the stream.
     *        The value true means that the stream is muted, and false means the opposite.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.multimedia.audio.AudioVolumeGroupManager#isMute
     */
    isMute(volumeType: AudioVolumeType, callback: AsyncCallback<boolean>): void;
    /**
     * Checks whether a stream is muted. This method uses a promise to return the result.
     * @param { AudioVolumeType } volumeType - Audio stream type.
     * @returns { Promise<boolean> } Promise used to return the mute status of the stream. The value true means
     *          that the stream is muted, and false means the opposite.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.multimedia.audio.AudioVolumeGroupManager#isMute
     */
    isMute(volumeType: AudioVolumeType): Promise<boolean>;
    /**
     * Checks whether a stream is active. This method uses an asynchronous callback to return the query result.
     * @param { AudioVolumeType } volumeType - Audio stream type.
     * @param { AsyncCallback<boolean> } callback - Callback used to return the active status of the stream.
     *        The value true means that the stream is active, and false means the opposite.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.multimedia.audio.AudioStreamManager#isActive
     */
    isActive(volumeType: AudioVolumeType, callback: AsyncCallback<boolean>): void;
    /**
     * Checks whether a stream is active. This method uses a promise to return the query result.
     * @param { AudioVolumeType } volumeType - Audio stream type.
     * @returns { Promise<boolean> } Promise used to return the active status of the stream. The value true means
     *          that the stream is active, and false means the opposite.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.multimedia.audio.AudioStreamManager#isActive
     */
    isActive(volumeType: AudioVolumeType): Promise<boolean>;
    /**
     * Mutes or unmutes the microphone. This method uses an asynchronous callback to return the result.
     * @permission ohos.permission.MICROPHONE
     * @param { boolean } mute - Mute status to set. The value true means to mute the microphone, and false means the opposite.
     * @param { AsyncCallback<void> } callback - Callback used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.multimedia.audio.AudioVolumeGroupManager#setMicrophoneMute
     */
    setMicrophoneMute(mute: boolean, callback: AsyncCallback<void>): void;
    /**
     * Mutes or unmutes the microphone. This method uses a promise to return the result.
     * @permission ohos.permission.MICROPHONE
     * @param { boolean } mute - Mute status to set. The value true means to mute the microphone, and false means the opposite.
     * @returns { Promise<void> } Promise used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.multimedia.audio.AudioVolumeGroupManager#setMicrophoneMute
     */
    setMicrophoneMute(mute: boolean): Promise<void>;
    /**
     * Checks whether the microphone is muted. This method uses an asynchronous callback to return the query result.
     * @permission ohos.permission.MICROPHONE
     * @param { AsyncCallback<boolean> } callback - used to return the mute status of the microphone. The value
     *        true means that the microphone is muted, and false means the opposite.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.multimedia.audio.AudioVolumeGroupManager#isMicrophoneMute
     */
    isMicrophoneMute(callback: AsyncCallback<boolean>): void;
    /**
     * Checks whether the microphone is muted. This method uses a promise to return the query result.
     * @permission ohos.permission.MICROPHONE
     * @returns { Promise<boolean> } Promise used to return the mute status of the microphone. The value
     *          true means that the microphone is muted, and false means the opposite.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.multimedia.audio.AudioVolumeGroupManager#isMicrophoneMute
     */
    isMicrophoneMute(): Promise<boolean>;
    /**
     * Sets the ringer mode. This method uses an asynchronous callback to return the result.
     * @permission ohos.permission.ACCESS_NOTIFICATION_POLICY
     * @param { AudioRingMode } mode - Ringer mode.
     * @param { AsyncCallback<void> } callback - Callback used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Communication
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.multimedia.audio.AudioVolumeGroupManager#setRingerMode
     */
    setRingerMode(mode: AudioRingMode, callback: AsyncCallback<void>): void;
    /**
     * Sets the ringer mode. This method uses a promise to return the result.
     * @permission ohos.permission.ACCESS_NOTIFICATION_POLICY
     * @param { AudioRingMode } mode - Ringer mode.
     * @returns { Promise<void> } Promise used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Communication
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.multimedia.audio.AudioVolumeGroupManager#setRingerMode
     */
    setRingerMode(mode: AudioRingMode): Promise<void>;
    /**
     * Obtains the ringer mode. This method uses an asynchronous callback to return the query result.
     * @param { AsyncCallback<AudioRingMode> } callback - Callback used to return the ringer mode.
     * @syscap SystemCapability.Multimedia.Audio.Communication
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.multimedia.audio.AudioVolumeGroupManager#getRingerMode
     */
    getRingerMode(callback: AsyncCallback<AudioRingMode>): void;
    /**
     * Obtains the ringer mode. This method uses a promise to return the query result.
     * @returns { Promise<AudioRingMode> } Promise used to return the ringer mode.
     * @syscap SystemCapability.Multimedia.Audio.Communication
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.multimedia.audio.AudioVolumeGroupManager#getRingerMode
     */
    getRingerMode(): Promise<AudioRingMode>;
    /**
     * Sets an audio parameter. This method uses an asynchronous callback to return the result.
     * @permission ohos.permission.MODIFY_AUDIO_SETTINGS
     * @param { string } key - Key of the audio parameter to set.
     * @param { string } value -  Value of the audio parameter to set.
     * @param { AsyncCallback<void> } callback - Callback used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 7
     */
    setAudioParameter(key: string, value: string, callback: AsyncCallback<void>): void;
    /**
     * Sets an audio parameter. This method uses a promise to return the result.
     * @permission ohos.permission.MODIFY_AUDIO_SETTINGS
     * @param { string } key - Key of the audio parameter to set.
     * @param { string } value - Value of the audio parameter to set.
     * @returns { Promise<void> } Promise used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 7
     */
    setAudioParameter(key: string, value: string): Promise<void>;
    /**
     * Obtains the value of an audio parameter. This method uses an asynchronous callback to return the query result.
     * @param { string } key - Key of the audio parameter whose value is to be obtained.
     * @param { AsyncCallback<string> } callback - Callback used to return the value of the audio parameter.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 7
     */
    getAudioParameter(key: string, callback: AsyncCallback<string>): void;
    /**
     * Obtains the value of an audio parameter. This method uses a promise to return the query result.
     * @param { string } key - Key of the audio parameter whose value is to be obtained.
     * @returns { Promise<string> } Promise used to return the value of the audio parameter.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 7
     */
    getAudioParameter(key: string): Promise<string>;
    /**
     * Sets a device to the active state. This method uses an asynchronous callback to return the result.
     * @param { ActiveDeviceType } deviceType - Audio device type.
     * @param { boolean } active - Active status to set. The value true means to set the device to the active
     *        status, and false means the opposite.
     * @param { AsyncCallback<void> } callback - Callback used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.multimedia.audio.AudioRoutingManager#setCommunicationDevice
     */
    setDeviceActive(deviceType: ActiveDeviceType, active: boolean, callback: AsyncCallback<void>): void;
    /**
     * Sets a device to the active state. This method uses a promise to return the result.
     * @param { ActiveDeviceType } deviceType - Audio device type.
     * @param { boolean } active - Active status to set. The value true means to set the device to the active
     *        status, and false means the opposite.
     * @returns { Promise<void> } Promise used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.multimedia.audio.AudioRoutingManager#setCommunicationDevice
     */
    setDeviceActive(deviceType: ActiveDeviceType, active: boolean): Promise<void>;
    /**
     * Checks whether a device is active. This method uses an asynchronous callback to return the query result.
     * @param { ActiveDeviceType } deviceType - Audio device type.
     * @param { AsyncCallback<boolean> } callback - Callback used to return the active status of the device.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.multimedia.audio.AudioRoutingManager#isCommunicationDeviceActive
     */
    isDeviceActive(deviceType: ActiveDeviceType, callback: AsyncCallback<boolean>): void;
    /**
     * Checks whether a device is active. This method uses a promise to return the query result.
     * @param { ActiveDeviceType } deviceType - Audio device type.
     * @returns { Promise<boolean> } Promise used to return the active status of the device.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.multimedia.audio.AudioRoutingManager#isCommunicationDeviceActive
     */
    isDeviceActive(deviceType: ActiveDeviceType): Promise<boolean>;
    /**
     * Listens for system volume change events. This method uses a callback to get volume change events.
     * @param { 'volumeChange' } type - Type of the event to listen for. Only the volumeChange event is supported.
     * @param { Callback<VolumeEvent> } callback - Callback used to get the system volume change event.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @systemapi
     * @since 8
     * @deprecated since 9
     * @useinstead ohos.multimedia.audio.AudioVolumeManager#event:volumeChange
     */
    on(type: 'volumeChange', callback: Callback<VolumeEvent>): void;
    /**
     * Listens for ringer mode change events. This method uses a callback to get ringer mode changes.
     * @param { 'ringerModeChange' } type - Type of the event to listen for. Only the ringerModeChange event is supported.
     * @param { Callback<AudioRingMode> } callback - Callback used to get the updated ringer mode.
     * @syscap SystemCapability.Multimedia.Audio.Communication
     * @systemapi
     * @since 8
     * @deprecated since 9
     * @useinstead ohos.multimedia.audio.AudioVolumeGroupManager#event:ringerModeChange
     */
    on(type: 'ringerModeChange', callback: Callback<AudioRingMode>): void;
    /**
     * Sets the audio scene mode to change audio strategies. This method uses an asynchronous callback to return the
     * result.
     * @param { AudioScene } scene - Audio scene mode.
     * @param { AsyncCallback<void> } callback - Callback used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Communication
     * @systemapi
     * @since 8
     */
    setAudioScene(scene: AudioScene, callback: AsyncCallback<void>): void;
    /**
     * Sets the audio scene mode to change audio strategies. This method uses a promise to return the result.
     * @param { AudioScene } scene - Audio scene mode.
     * @returns { Promise<void> } Promise used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Communication
     * @systemapi
     * @since 8
     */
    setAudioScene(scene: AudioScene): Promise<void>;
    /**
     * Obtains the audio scene mode. This method uses an asynchronous callback to return the query result.
     * @param { AsyncCallback<AudioScene> } callback - Callback used to return the audio scene mode.
     * @syscap SystemCapability.Multimedia.Audio.Communication
     * @since 8
     */
    getAudioScene(callback: AsyncCallback<AudioScene>): void;
    /**
     * Obtains the audio scene mode. This method uses a promise to return the query result.
     * @returns { Promise<AudioScene> } Promise used to return the audio scene mode.
     * @syscap SystemCapability.Multimedia.Audio.Communication
     * @since 8
     */
    getAudioScene(): Promise<AudioScene>;
    /**
     * Subscribes to device change events. When a device is connected/disconnected, registered clients will receive
     * the callback.
     * @param { 'deviceChange' } type - Type of the event to listen for. Only the deviceChange event is supported.
     * @param { Callback<DeviceChangeAction> } callback - Callback used to obtain the device update details.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.multimedia.audio.AudioRoutingManager#event:deviceChange
     */
    on(type: 'deviceChange', callback: Callback<DeviceChangeAction>): void;

    /**
     * UnSubscribes to device change events.
     * @param { 'deviceChange' } type - Type of the event to listen for. Only the deviceChange event is supported.
     * @param { Callback<DeviceChangeAction> } callback - Callback used to obtain the device update details.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.multimedia.audio.AudioRoutingManager#event:deviceChange
     */
    off(type: 'deviceChange', callback?: Callback<DeviceChangeAction>): void;

    /**
     * Listens for audio interruption events. When the audio of an application is interrupted by another application,
     * the callback is invoked to notify the former application.
     * @param { 'interrupt' } type - Type of the event to listen for. Only the interrupt event is supported.
     * @param { AudioInterrupt } interrupt - Parameters of the audio interruption event type.
     * @param { Callback<InterruptAction> } callback - Callback invoked for the audio interruption event.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 7
     */
    on(type: 'interrupt', interrupt: AudioInterrupt, callback: Callback<InterruptAction>): void;

    /**
     * Cancels the listening of audio interruption events.
     * @param { 'interrupt' } type - Type of the event to listen for. Only the interrupt event is supported.
     * @param { AudioInterrupt } interrupt - Input parameters of the audio interruption event.
     * @param { Callback<InterruptAction> } callback - Callback invoked for the audio interruption event.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 7
     */
    off(type: 'interrupt', interrupt: AudioInterrupt, callback?: Callback<InterruptAction>): void;

    /**
     * Obtains an {@link AudioVolumeManager} instance.
     * @returns { AudioVolumeManager } AudioVolumeManager instance.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 9
     */
    getVolumeManager(): AudioVolumeManager;

    /**
     * Obtains an {@link AudioStreamManager} instance.
     * @returns { AudioStreamManager } AudioStreamManager instance.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 9
     */
    getStreamManager(): AudioStreamManager;

    /**
     * Obtains an {@link AudioRoutingManager} instance.
     * @returns { AudioRoutingManager } AudioRoutingManager instance.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 9
     */
    getRoutingManager(): AudioRoutingManager;
  }

  /**
   * Enumerates audio interrupt request result type.
   * @enum { number }
   * @syscap SystemCapability.Multimedia.Audio.Interrupt
   * @systemapi
   * @since 9
   */
  enum InterruptRequestResultType {
    /**
     * Request audio interrupt success
     * @syscap SystemCapability.Multimedia.Audio.Interrupt
     * @systemapi
     * @since 9
     */
    INTERRUPT_REQUEST_GRANT = 0,
    /**
     * Request audio interrupt fail, may have higher priority type
     * @syscap SystemCapability.Multimedia.Audio.Interrupt
     * @systemapi
     * @since 9
     */
    INTERRUPT_REQUEST_REJECT = 1
  }

  /**
   * Describes audio interrupt operation results.
   * @typedef InterruptResult
   * @syscap SystemCapability.Multimedia.Audio.Interrupt
   * @systemapi
   * @since 9
   */
  interface InterruptResult {
    /**
     * Interrupt request or abandon result.
     * @syscap SystemCapability.Multimedia.Audio.Interrupt
     * @systemapi
     * @since 9
     */
    requestResult: InterruptRequestResultType;
    /**
     * Interrupt node as a unit to receive interrupt change event.
     * @syscap SystemCapability.Multimedia.Audio.Interrupt
     * @systemapi
     * @since 9
     */
    interruptNode: number;
  }

  /**
   * Implements audio router management.
   * @typedef AudioRoutingManager
   * @syscap SystemCapability.Multimedia.Audio.Device
   * @since 9
   */
  interface AudioRoutingManager {
    /**
     * Obtains the audio devices with a specific flag. This method uses an asynchronous callback to return the query result.
     * @param { DeviceFlag } deviceFlag - Audio device flag.
     * @param { AsyncCallback<AudioDeviceDescriptors> } callback - Callback used to return the device list.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 9
     */
    getDevices(deviceFlag: DeviceFlag, callback: AsyncCallback<AudioDeviceDescriptors>): void;
    /**
     * Obtains the audio devices with a specific flag. This method uses a promise to return the query result.
     * @param { DeviceFlag } deviceFlag - Audio device flag.
     * @returns { Promise<AudioDeviceDescriptors> } Promise used to return the device list.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 9
     */
    getDevices(deviceFlag: DeviceFlag): Promise<AudioDeviceDescriptors>;

    /**
     * Subscribes to device change events. When a device is connected/disconnected, registered clients will receive
     * the callback.
     * @param { 'deviceChange' } type - Type of the event to listen for. Only the deviceChange event is supported.
     * @param { DeviceFlag } deviceFlag - Audio device flag.
     * @param { Callback<DeviceChangeAction> } callback - Callback used to obtain the device update details.
     * @throws { BusinessError } 401 - if input parameter type or number mismatch
     * @throws { BusinessError } 6800101 - if input parameter value error
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 9
     */
    on(type: 'deviceChange', deviceFlag: DeviceFlag, callback: Callback<DeviceChangeAction>): void;

    /**
     * UnSubscribes to device change events.
     * @param { 'deviceChange' } type - Type of the event to listen for. Only the deviceChange event is supported.
     * @param { Callback<DeviceChangeAction> } callback - Callback used to obtain the device update details.
     * @throws { BusinessError } 401 - if input parameter type or number mismatch
     * @throws { BusinessError } 6800101 - if input parameter value error
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 9
     */
    off(type: 'deviceChange', callback?: Callback<DeviceChangeAction>): void;

    /**
     * Sets a device to the active state. This method uses an asynchronous callback to return the result.
     * @param { CommunicationDeviceType } deviceType - Audio device type.
     * @param { boolean } active - Active status to set. The value true means to set the device to
     *  the active status, and false means the opposite.
     * @param { AsyncCallback<void> } callback - Callback used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Communication
     * @since 9
     */
    setCommunicationDevice(deviceType: CommunicationDeviceType, active: boolean, callback: AsyncCallback<void>): void;
    /**
     * Sets a device to the active state. This method uses a promise to return the result.
     * @param { CommunicationDeviceType } deviceType - Audio device type.
     * @param { boolean } active - Active status to set. The value true means to set the device to the active status,
     * and false means the opposite.
     * @returns { Promise<void> } Promise used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Communication
     * @since 9
     */
    setCommunicationDevice(deviceType: CommunicationDeviceType, active: boolean): Promise<void>;

    /**
     * Checks whether a device is active. This method uses an asynchronous callback to return the query result.
     * @param { CommunicationDeviceType } deviceType - Audio device type.
     * @param { AsyncCallback<boolean> } callback - Callback used to return the active status of the device.
     * @syscap SystemCapability.Multimedia.Audio.Communication
     * @since 9
     */
    isCommunicationDeviceActive(deviceType: CommunicationDeviceType, callback: AsyncCallback<boolean>): void;
    /**
     * Checks whether a device is active. This method uses a promise to return the query result.
     * @param { CommunicationDeviceType } deviceType - Audio device type.
     * @returns { Promise<boolean> } Promise used to return the active status of the device.
     * @syscap SystemCapability.Multimedia.Audio.Communication
     * @since 9
     */
    isCommunicationDeviceActive(deviceType: CommunicationDeviceType): Promise<boolean>;

    /**
     * Select the output device. This method uses an asynchronous callback to return the result.
     * @param { AudioDeviceDescriptors } outputAudioDevices - Audio device description
     * @param { AsyncCallback<void> } callback - Callback used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @systemapi
     * @since 9
     */
    selectOutputDevice(outputAudioDevices: AudioDeviceDescriptors, callback: AsyncCallback<void>): void;
    /**
     * Select the output device. This method uses a promise to return the result.
     * @param { AudioDeviceDescriptors } outputAudioDevices - Audio device description
     * @returns { Promise<void> } Promise used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @systemapi
     * @since 9
     */
    selectOutputDevice(outputAudioDevices: AudioDeviceDescriptors): Promise<void>;

    /**
     * Select the output device with desired AudioRenderer. This method uses an asynchronous callback to return the result.
     * @param { AudioRendererFilter } filter - Filter for AudioRenderer.
     * @param { AudioDeviceDescriptors } outputAudioDevices - Audio device description.
     * @param { AsyncCallback<void> } callback - Callback used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @systemapi
     * @since 9
     */
    selectOutputDeviceByFilter(filter: AudioRendererFilter, outputAudioDevices: AudioDeviceDescriptors, callback: AsyncCallback<void>): void;
    /**
     * Select the output device with desired AudioRenderer. This method uses a promise to return the result.
     * @param { AudioRendererFilter } filter - Filter for AudioRenderer.
     * @param { AudioDeviceDescriptors } outputAudioDevices - Audio device description
     * @returns { Promise<void> } Promise used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @systemapi
     * @since 9
     */
    selectOutputDeviceByFilter(filter: AudioRendererFilter, outputAudioDevices: AudioDeviceDescriptors): Promise<void>;

    /**
     * Select the input device. This method uses an asynchronous callback to return the result.
     * @param { AudioDeviceDescriptors } inputAudioDevices - Audio device description
     * @param { AsyncCallback<void> } callback - Callback used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @systemapi
     * @since 9
     */
    selectInputDevice(inputAudioDevices: AudioDeviceDescriptors, callback: AsyncCallback<void>): void;
    /**
     * Select the input device. This method uses a promise to return the result.
     * @param { AudioDeviceDescriptors } inputAudioDevices - Audio device description
     * @returns { Promise<void> } Promise used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @systemapi
     * @since 9
     */
    selectInputDevice(inputAudioDevices: AudioDeviceDescriptors): Promise<void>;

    /**
     * Get output device for target audio renderer info.
     * @param { AudioRendererInfo } rendererInfo - Audio renderer information
     * @param { AsyncCallback<AudioDeviceDescriptors> } callback - Callback used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 10
     */
    getPreferOutputDeviceForRendererInfo(rendererInfo: AudioRendererInfo, callback: AsyncCallback<AudioDeviceDescriptors>): void;
    /**
     * Get output device for target audio renderer info.
     * @param { AudioRendererInfo } rendererInfo - Audio renderer information.
     * @returns { Promise<AudioDeviceDescriptors> } Promise used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 10
     */
    getPreferOutputDeviceForRendererInfo(rendererInfo: AudioRendererInfo): Promise<AudioDeviceDescriptors>;

    /**
     * Subscribes to prefer output device change events. When prefer device for target audio renderer info changes,
     * registered clients will receive the callback.
     * @param { 'preferOutputDeviceChangeForRendererInfo' } type - Type of the event to listen for. Only the
     * preferOutputDeviceChangeForRendererInfo event is supported.
     * @param { AudioRendererInfo } rendererInfo - Audio renderer information.
     * @param { Callback<AudioDeviceDescriptors> } callback - Callback used to obtain the changed prefer devices information.
     * @throws { BusinessError } 401 - if input parameter type or number mismatch
     * @throws { BusinessError } 6800101 - if input parameter value error
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 10
     */
    on(type: 'preferOutputDeviceChangeForRendererInfo', rendererInfo: AudioRendererInfo, callback: Callback<AudioDeviceDescriptors>): void;
    /**
     * UnSubscribes to prefer output device change events.
     * @param { 'preferOutputDeviceChangeForRendererInfo' } type - Type of the event to listen for. Only the 
     * preferOutputDeviceChangeForRendererInfo event is supported.
     * @param { Callback<AudioDeviceDescriptors> } callback - Callback used to obtain the changed prefer devices in subscribe.
     * @throws { BusinessError } 401 - if input parameter type or number mismatch
     * @throws { BusinessError } 6800101 - if input parameter value error
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 10
     */
    off(type: 'preferOutputDeviceChangeForRendererInfo', callback?: Callback<AudioDeviceDescriptors>): void;
  }

  /**
   * Implements audio stream management.
   * @typedef AudioStreamManager
   * @syscap SystemCapability.Multimedia.Audio.Core
   * @since 9
   */
  interface AudioStreamManager {
    /**
     * Get information of current existing audio renderers.
     * @param { AsyncCallback<AudioRendererChangeInfoArray> } callback - Callback used to return the information
     * of current existing audio renderers.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 9
     */
    getCurrentAudioRendererInfoArray(callback: AsyncCallback<AudioRendererChangeInfoArray>): void;
    /**
     * Get information of current existing audio renderers.
     * @returns { Promise<AudioRendererChangeInfoArray> } Promise used to return the information of current
     * existing audio renderers.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 9
     */
    getCurrentAudioRendererInfoArray(): Promise<AudioRendererChangeInfoArray>;

    /**
     * Get information of current existing audio capturers.
     * @param { AsyncCallback<AudioCapturerChangeInfoArray> } callback - Callback used to return the information
     * of current existing audio capturers.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 9
     */
    getCurrentAudioCapturerInfoArray(callback: AsyncCallback<AudioCapturerChangeInfoArray>): void;
    /**
     * Get information of current existing audio capturers.
     * @returns { Promise<AudioCapturerChangeInfoArray> } Promise used to return the information of current existing
     * audio capturers.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 9
     */
    getCurrentAudioCapturerInfoArray(): Promise<AudioCapturerChangeInfoArray>;

    /**
     * Gets information of audio effects.
     * @param { ContentType } content - Content type.
     * @param { StreamUsage } usage - Stream usage.
     * @param { AsyncCallback<AudioEffectInfoArray> } callback - Callback used to return the information of audio effects.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 10
     */
    getAudioEffectInfoArray(content: ContentType, usage: StreamUsage, callback: AsyncCallback<AudioEffectInfoArray>): void;
    /**
     * Gets information of audio effects.
     * @param { ContentType } content - Content type.
     * @param { StreamUsage } usage - Stream usage.
     * @returns { Promise<AudioEffectInfoArray> } Promise used to return the information of audio effects.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 10
     */
    getAudioEffectInfoArray(content: ContentType, usage: StreamUsage): Promise<AudioEffectInfoArray>;

    /**
     * Listens for audio renderer change events. When there is any audio renderer change,
     * registered clients will receive the callback.
     * @param { "audioRendererChange" } type - Type of the event to listen for. Only the audioRendererChange event is supported.
     * @param { Callback<AudioRendererChangeInfoArray> } callback - Callback invoked for the audio renderer change event.
     * @throws { BusinessError } 401 - if input parameter type or number mismatch
     * @throws { BusinessError } 6800101 - if input parameter value error
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 9
     */
    on(type: "audioRendererChange", callback: Callback<AudioRendererChangeInfoArray>): void;

    /**
     * UnSubscribes to audio renderer change events.
     * @param { "audioRendererChange" } type - Type of the event to listen for. Only the audioRendererChange event is supported.
     * @throws { BusinessError } 401 - if input parameter type or number mismatch
     * @throws { BusinessError } 6800101 - if input parameter value error
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 9
     */
    off(type: "audioRendererChange"): void;

    /**
     * Listens for audio capturer change events. When there is any audio capturer change,
     * registered clients will receive the callback.
     * @param { "audioCapturerChange" } type - Type of the event to listen for. Only the audioCapturerChange event is supported.
     * @param { Callback<AudioCapturerChangeInfoArray> } callback - Callback invoked for the audio capturer change event.
     * @throws { BusinessError } 401 - if input parameter type or number mismatch
     * @throws { BusinessError } 6800101 - if input parameter value error
     * @syscap SystemCapability.Multimedia.Audio.Capturer
     * @since 9
     */
    on(type: "audioCapturerChange", callback: Callback<AudioCapturerChangeInfoArray>): void;

    /**
     * UnSubscribes to audio capturer change events.
     * @param { "audioCapturerChange" } type - Type of the event to listen for. Only the audioCapturerChange event is supported.
     * @throws { BusinessError } 401 - if input parameter type or number mismatch
     * @throws { BusinessError } 6800101 - if input parameter value error
     * @syscap SystemCapability.Multimedia.Audio.Capturer
     * @since 9
     */
    off(type: "audioCapturerChange"): void;

    /**
     * Checks whether a stream is active. This method uses an asynchronous callback to return the query result.
     * @param { AudioVolumeType } volumeType - Audio stream type.
     * @param { AsyncCallback<boolean> } callback - Callback used to return the active status of the stream.
     *  The value true means that the stream is active, and false means the opposite.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 9
     */
    isActive(volumeType: AudioVolumeType, callback: AsyncCallback<boolean>): void;
    /**
     * Checks whether a stream is active. This method uses a promise to return the query result.
     * @param { AudioVolumeType } volumeType - Audio stream type.
     * @returns { Promise<boolean> } Promise used to return the active status of the stream. The value
     * true means that the stream is active, and false means the opposite.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 9
     */
    isActive(volumeType: AudioVolumeType): Promise<boolean>;
  }

  /**
   * Implements audio volume management.
   * @typedef AudioVolumeManager
   * @syscap SystemCapability.Multimedia.Audio.Volume
   * @since 9
   */
  interface AudioVolumeManager {
    /**
     * Get the volume group list for a networkId. This method uses an asynchronous callback to return the result.
     * @param { string } networkId - Distributed deice net work id
     * @param { AsyncCallback<VolumeGroupInfos> } callback - Callback used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @systemapi
     * @since 9
     */
    getVolumeGroupInfos(networkId: string, callback: AsyncCallback<VolumeGroupInfos>): void;
    /**
     * Get the volume group list for a networkId. This method uses a promise to return the result.
     * @param { string } networkId - Distributed deice net work id
     * @returns { Promise<VolumeGroupInfos> } Promise used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @systemapi
     * @since 9
     */
    getVolumeGroupInfos(networkId: string): Promise<VolumeGroupInfos>;

    /**
     * Obtains an AudioVolumeGroupManager instance. This method uses an asynchronous callback to return the result.
     * @param { number } groupId - volume group id, use LOCAL_VOLUME_GROUP_ID in default
     * @param { AsyncCallback<AudioVolumeGroupManager> } callback - Callback used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 9
     */
    getVolumeGroupManager(groupId: number, callback: AsyncCallback<AudioVolumeGroupManager>): void;
    /**
     * Obtains an AudioVolumeGroupManager instance. This method uses a promise to return the result.
     * @param { number } groupId - volume group id, use LOCAL_VOLUME_GROUP_ID in default
     * @returns { Promise<AudioVolumeGroupManager> } Promise used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 9
     */
    getVolumeGroupManager(groupId: number): Promise<AudioVolumeGroupManager>;

    /**
     * Listens for system volume change events. This method uses a callback to get volume change events.
     * @param { 'volumeChange' } type - Type of the event to listen for. Only the volumeChange event is supported.
     * @param { Callback<VolumeEvent> } callback - Callback used to get the system volume change event.
     * @throws { BusinessError } 401 - if input parameter type or number mismatch
     * @throws { BusinessError } 6800101 - if input parameter value error
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 9
     */
    on(type: 'volumeChange', callback: Callback<VolumeEvent>): void;
  }

  /**
   * Implements audio volume group management.
   * @typedef AudioVolumeGroupManager
   * @syscap SystemCapability.Multimedia.Audio.Volume
   * @since 9
   */
  interface AudioVolumeGroupManager {
    /**
     * Sets the volume for a stream. This method uses an asynchronous callback to return the result.
     * @permission ohos.permission.ACCESS_NOTIFICATION_POLICY
     * @param { AudioVolumeType } volumeType - Audio stream type.
     * @param { number } volume - Volume to set. The value range can be obtained by calling getMinVolume and getMaxVolume.
     * @param { AsyncCallback<void> } callback - Callback used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @systemapi
     * @since 9
     */
    setVolume(volumeType: AudioVolumeType, volume: number, callback: AsyncCallback<void>): void;
    /**
     * Sets the volume for a stream. This method uses a promise to return the result.
     * @permission ohos.permission.ACCESS_NOTIFICATION_POLICY
     * @param { AudioVolumeType } volumeType - Audio stream type.
     * @param { number } volume - Volume to set. The value range can be obtained by calling getMinVolume and getMaxVolume.
     * @returns { Promise<void> } Promise used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @systemapi
     * @since 9
     */
    setVolume(volumeType: AudioVolumeType, volume: number): Promise<void>;

    /**
     * Obtains the volume of a stream. This method uses an asynchronous callback to return the query result.
     * @param { AudioVolumeType } volumeType - Audio stream type.
     * @param { AsyncCallback<number> } callback - Callback used to return the volume.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 9
     */
    getVolume(volumeType: AudioVolumeType, callback: AsyncCallback<number>): void;
    /**
     * Obtains the volume of a stream. This method uses a promise to return the query result.
     * @param { AudioVolumeType } volumeType - Audio stream type.
     * @returns { Promise<number> } Promise used to return the volume.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 9
     */
    getVolume(volumeType: AudioVolumeType): Promise<number>;

    /**
     * Obtains the minimum volume allowed for a stream. This method uses an asynchronous callback to return the query result.
     * @param { AudioVolumeType } volumeType - Audio stream type.
     * @param { AsyncCallback<number> } callback - Callback used to return the minimum volume.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 9
     */
    getMinVolume(volumeType: AudioVolumeType, callback: AsyncCallback<number>): void;
    /**
     * Obtains the minimum volume allowed for a stream. This method uses a promise to return the query result.
     * @param { AudioVolumeType } volumeType - Audio stream type.
     * @returns { Promise<number> } Promise used to return the minimum volume.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 9
     */
    getMinVolume(volumeType: AudioVolumeType): Promise<number>;

    /**
     * Obtains the maximum volume allowed for a stream. This method uses an asynchronous callback to return the query result.
     * @param { AudioVolumeType } volumeType - Audio stream type.
     * @param { AsyncCallback<number> } callback - Callback used to return the maximum volume.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 9
     */
    getMaxVolume(volumeType: AudioVolumeType, callback: AsyncCallback<number>): void;
    /**
     * Obtains the maximum volume allowed for a stream. This method uses a promise to return the query result.
     * @param { AudioVolumeType } volumeType - Audio stream type.
     * @returns { Promise<number> } Promise used to return the maximum volume.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 9
     */
    getMaxVolume(volumeType: AudioVolumeType): Promise<number>;

    /**
     * Mutes a stream. This method uses an asynchronous callback to return the result.
     * @permission ohos.permission.ACCESS_NOTIFICATION_POLICY
     * @param { AudioVolumeType } volumeType - Audio stream type.
     * @param { boolean } mute - Mute status to set. The value true means to mute the stream, and false means the opposite.
     * @param { AsyncCallback<void> } callback - Callback used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @systemapi
     * @since 9
     */
    mute(volumeType: AudioVolumeType, mute: boolean, callback: AsyncCallback<void>): void;
    /**
     * Mutes a stream. This method uses a promise to return the result.
     * @permission ohos.permission.ACCESS_NOTIFICATION_POLICY
     * @param { AudioVolumeType } volumeType - Audio stream type.
     * @param { boolean } mute - Mute status to set. The value true means to mute the stream, and false means the opposite.
     * @returns { Promise<void> } Promise used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @systemapi
     * @since 9
     */
    mute(volumeType: AudioVolumeType, mute: boolean): Promise<void>;

    /**
     * Checks whether a stream is muted. This method uses an asynchronous callback to return the query result.
     * @param { AudioVolumeType } volumeType - Audio stream type.
     * @param { AsyncCallback<boolean> } callback - Callback used to return the mute status of the stream. The
     * value true means that the stream is muted, and false means the opposite.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 9
     */
    isMute(volumeType: AudioVolumeType, callback: AsyncCallback<boolean>): void;
    /**
     * Checks whether a stream is muted. This method uses a promise to return the result.
     * @param { AudioVolumeType } volumeType - Audio stream type.
     * @returns { Promise<boolean> } Promise used to return the mute status of the stream. The value true
     * means that the stream is muted, and false means the opposite.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 9
     */
    isMute(volumeType: AudioVolumeType): Promise<boolean>;

    /**
     * Sets the ringer mode. This method uses an asynchronous callback to return the result.
     * @permission ohos.permission.ACCESS_NOTIFICATION_POLICY
     * @param { AudioRingMode } mode - Ringer mode.
     * @param { AsyncCallback<void> } callback - Callback used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @systemapi
     * @since 9
     */
    setRingerMode(mode: AudioRingMode, callback: AsyncCallback<void>): void;
    /**
     * Sets the ringer mode. This method uses a promise to return the result.
     * @permission ohos.permission.ACCESS_NOTIFICATION_POLICY
     * @param { AudioRingMode } mode - Ringer mode.
     * @returns { Promise<void> } Promise used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @systemapi
     * @since 9
     */
    setRingerMode(mode: AudioRingMode): Promise<void>;

    /**
     * Obtains the ringer mode. This method uses an asynchronous callback to return the query result.
     * @param { AsyncCallback<AudioRingMode> } callback - Callback used to return the ringer mode.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 9
     */
    getRingerMode(callback: AsyncCallback<AudioRingMode>): void;
    /**
     * Obtains the ringer mode. This method uses a promise to return the query result.
     * @returns { Promise<AudioRingMode> } Promise used to return the ringer mode.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 9
     */
    getRingerMode(): Promise<AudioRingMode>;

    /**
     * Listens for ringer mode change events. This method uses a callback to get ringer mode changes.
     * @param { 'ringerModeChange' } type - Type of the event to listen for. Only the ringerModeChange event is supported.
     * @param { Callback<AudioRingMode> } callback - Callback used to get the updated ringer mode.
     * @throws { BusinessError } 401 - if input parameter type or number mismatch
     * @throws { BusinessError } 6800101 - if input parameter value error
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 9
     */
    on(type: 'ringerModeChange', callback: Callback<AudioRingMode>): void;

    /**
     * Mutes or unmutes the microphone. This method uses an asynchronous callback to return the result.
     * @permission ohos.permission.MANAGE_AUDIO_CONFIG
     * @param { boolean } mute - Mute status to set. The value true means to mute the microphone, and false means the opposite.
     * @param { AsyncCallback<void> } callback - Callback used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 9
     */
    setMicrophoneMute(mute: boolean, callback: AsyncCallback<void>): void;
    /**
     * Mutes or unmutes the microphone. This method uses a promise to return the result.
     * @permission ohos.permission.MANAGE_AUDIO_CONFIG
     * @param { boolean } mute - Mute status to set. The value true means to mute the microphone, and false means the opposite.
     * @returns { Promise<void> } Promise used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 9
     */
    setMicrophoneMute(mute: boolean): Promise<void>;

    /**
     * Checks whether the microphone is muted. This method uses an asynchronous callback to return the query result.
     * @param { AsyncCallback<boolean> } callback - used to return the mute status of the microphone. The value
     * true means that the microphone is muted, and false means the opposite.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 9
     */
    isMicrophoneMute(callback: AsyncCallback<boolean>): void;
    /**
     * Checks whether the microphone is muted. This method uses a promise to return the query result.
     * @returns { Promise<boolean> } Promise used to return the mute status of the microphone. The value true
     * means that the microphone is muted, and false means the opposite.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 9
     */
    isMicrophoneMute(): Promise<boolean>;

    /**
     * Listens for system microphone state change events. This method uses a callback to get microphone change events.
     * @param { 'micStateChange' } type - Type of the event to listen for. Only the micStateChange event is supported.
     * @param { Callback<MicStateChangeEvent> } callback - Callback used to get the system microphone state change event.
     * @throws { BusinessError } 401 - if input parameter type or number mismatch
     * @throws { BusinessError } 6800101 - if input parameter value error
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 9
     */
    on(type: 'micStateChange', callback: Callback<MicStateChangeEvent>): void;

    /**
     * Gets if this volume group is volume unadjustable.
     * @returns { boolean } Whether it is volume unadjustable.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 10
     */
    isVolumeUnadjustable(): boolean;

    /**
     * Adjusts system volume by step, volume type is decided by system.
     * This method uses an asynchronous callback to return the result.
     * @permission ohos.permission.ACCESS_NOTIFICATION_POLICY
     * @param { VolumeAdjustType } adjustType - Volume adjustment type.
     * @param { AsyncCallback<void> } callback - Callback used to return the result.
     * @throws { BusinessError } 201 - Permission denied. Return by callback.
     * @throws { BusinessError } 401 - Parameter error. Return by callback.
     * @throws { BusinessError } 6800101 - Invalid parameter error. Return by callback.
     * @throws { BusinessError } 6800301 - System error. Return by callback.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @systemapi
     * @since 10
     */
    adjustVolumeByStep(adjustType: VolumeAdjustType, callback: AsyncCallback<void>): void;
    /**
     * Adjusts system volume by step, volume type is decided by system.
     * This method uses a promise to return the result.
     * @permission ohos.permission.ACCESS_NOTIFICATION_POLICY
     * @param { VolumeAdjustType } adjustType - Volume adjustment type.
     * @returns { Promise<void> } Promise used to return the result.
     * @throws { BusinessError } 201 - Permission denied. Return by promise.
     * @throws { BusinessError } 401 - Parameter error. Return by promise.
     * @throws { BusinessError } 6800101 - Invalid parameter error. Return by promise.
     * @throws { BusinessError } 6800301 - System error. Return by promise.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @systemapi
     * @since 10
     */
    adjustVolumeByStep(adjustType: VolumeAdjustType): Promise<void>;

    /**
     * Adjusts system volume by step for target volume type.
     * This method uses an asynchronous callback to return the result.
     * @permission ohos.permission.ACCESS_NOTIFICATION_POLICY
     * @param { AudioVolumeType } volumeType - Audio volume type.
     * @param { VolumeAdjustType } adjustType - Volume adjustment type.
     * @param { AsyncCallback<void> } callback - Callback used to return the result.
     * @throws { BusinessError } 201 - Permission denied. Return by callback.
     * @throws { BusinessError } 401 - Parameter error. Return by callback.
     * @throws { BusinessError } 6800101 - Invalid parameter error. Return by callback.
     * @throws { BusinessError } 6800301 - System error. Return by callback.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @systemapi
     * @since 10
     */
    adjustSystemVolumeByStep(volumeType: AudioVolumeType, adjustType: VolumeAdjustType, callback: AsyncCallback<void>): void;
    /**
     * Adjusts system volume by step for target volume type.
     * This method uses a promise to return the result.
     * @permission ohos.permission.ACCESS_NOTIFICATION_POLICY
     * @param { AudioVolumeType } volumeType - Audio volume type.
     * @param { VolumeAdjustType } adjustType - Volume adjustment type.
     * @returns { Promise<void> } Promise used to return the result.
     * @throws { BusinessError } 201 - Permission denied. Return by promise.
     * @throws { BusinessError } 401 - Parameter error. Return by promise.
     * @throws { BusinessError } 6800101 - Invalid parameter error. Return by promise.
     * @throws { BusinessError } 6800301 - System error. Return by promise.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @systemapi
     * @since 10
     */
    adjustSystemVolumeByStep(volumeType: AudioVolumeType, adjustType: VolumeAdjustType): Promise<void>;

    /**
     * Gets the volume db value that system calculate by volume type, volume level and device type.
     * This method uses an asynchronous callback to return the result.
     * @param { AudioVolumeType } volumeType - Audio volume type.
     * @param { number } volumeLevel - Volume level to set.
     * @param { DeviceType } device - Output device type.
     * @param { AsyncCallback<number> } callback - Callback used to return the result.
     * @throws { BusinessError } 401 - Parameter error. Return by callback.
     * @throws { BusinessError } 6800101 - Invalid parameter error. Return by callback.
     * @throws { BusinessError } 6800301 - System error. Return by callback.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 10
     */
    getSystemVolumeInDb(volumeType: AudioVolumeType, volumeLevel: number, device: DeviceType, callback: AsyncCallback<number>): void;
    /**
     * Gets the volume db value that system calculate by volume type, volume level and device type.
     * This method uses a promise to return the result.
     * @param { AudioVolumeType } volumeType - Audio volume type.
     * @param { number } volumeLevel - Volume level to set.
     * @param { DeviceType } device - Output device type.
     * @returns { Promise<number> } Promise used to return the result.
     * @throws { BusinessError } 401 - Parameter error. Return by promise.
     * @throws { BusinessError } 6800101 - Invalid parameter error. Return by promise.
     * @throws { BusinessError } 6800301 - System error. Return by promise.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 10
     */
    getSystemVolumeInDb(volumeType: AudioVolumeType, volumeLevel: number, device: DeviceType): Promise<number>;
  }

  /**
   * Describes an audio volume group.
   * @enum { number }
   * @syscap SystemCapability.Multimedia.Audio.Volume
   * @systemapi
   * @since 9
   */
  enum ConnectType {
    /**
     * Connect type for local device.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @systemapi
     * @since 9
     */
    CONNECT_TYPE_LOCAL = 1,

    /**
     * Connect type for distributed device.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @systemapi
     * @since 9
     */
    CONNECT_TYPE_DISTRIBUTED = 2
  }

  /**
   * Describes an audio volume group.
   * @typedef VolumeGroupInfo
   * @syscap SystemCapability.Multimedia.Audio.Volume
   * @systemapi
   * @since 9
   */
  interface VolumeGroupInfo {
    /**
     * Device network id.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @systemapi
     * @since 9
     */
    readonly networkId: string;

    /**
     * Volume group id.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @systemapi
     * @since 9
     */
    readonly groupId: number;

    /**
     * Volume mapping group id.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @systemapi
     * @since 9
     */
    readonly mappingId: number;

    /**
     * Volume group name.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @systemapi
     * @since 9
     */
    readonly groupName: string;

    /**
     * Connect type of device for this group.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @systemapi
     * @since 9
     */
    readonly type: ConnectType;
  }

  /**
   * Array of VolumeGroupInfos, which is read-only.
   * @syscap SystemCapability.Multimedia.Audio.Volume
   * @systemapi
   * @since 9
   */
  type VolumeGroupInfos = Array<Readonly<VolumeGroupInfo>>;

  /**
   * Array of AudioRendererChangeInfo, which is read-only.
   * @syscap SystemCapability.Multimedia.Audio.Renderer
   * @since 9
   */
  type AudioRendererChangeInfoArray = Array<Readonly<AudioRendererChangeInfo>>;

  /**
   * Describes audio renderer change information.
   * @typedef AudioRendererChangeInfo
   * @syscap SystemCapability.Multimedia.Audio.Renderer
   * @since 9
   */
  interface AudioRendererChangeInfo {
    /**
     * Audio stream unique id.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 9
     */
    readonly streamId: number;

    /**
     * Uid for audio renderer client application.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @systemapi
     * @since 9
     */
    readonly clientUid: number;

    /**
     * Audio renderer information.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 9
     */
    readonly rendererInfo: AudioRendererInfo;

    /**
     * Audio state.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @systemapi
     * @since 9
     */
    readonly rendererState: AudioState;

    /**
     * Audio output devices.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 9
     */
    readonly deviceDescriptors: AudioDeviceDescriptors;
  }

  /**
   * Array of AudioCapturerChangeInfo, which is read-only.
   * @syscap SystemCapability.Multimedia.Audio.Capturer
   * @since 9
   */
  type AudioCapturerChangeInfoArray = Array<Readonly<AudioCapturerChangeInfo>>;

  /**
   * Describes audio capturer change information.
   * @typedef AudioCapturerChangeInfo
   * @syscap SystemCapability.Multimedia.Audio.Capturer
   * @since 9
   */
  interface AudioCapturerChangeInfo {
    /**
     * Audio stream unique id.
     * @syscap SystemCapability.Multimedia.Audio.Capturer
     * @since 9
     */
    readonly streamId: number;

    /**
     * Uid for audio capturer client application.
     * @syscap SystemCapability.Multimedia.Audio.Capturer
     * @systemapi
     * @since 9
     */
    readonly clientUid: number;

    /**
     * Audio capturer information.
     * @syscap SystemCapability.Multimedia.Audio.Capturer
     * @since 9
     */
    readonly capturerInfo: AudioCapturerInfo;

    /**
     * Audio state.
     * @syscap SystemCapability.Multimedia.Audio.Capturer
     * @systemapi
     * @since 9
     */
    readonly capturerState: AudioState;

    /**
     * Audio input devices.
     * @syscap SystemCapability.Multimedia.Audio.Capturer
     * @since 9
     */
    readonly deviceDescriptors: AudioDeviceDescriptors;
  }

  /**
   * Describes an audio device.
   * @typedef AudioDeviceDescriptor
   * @syscap SystemCapability.Multimedia.Audio.Device
   * @since 7
   */
  interface AudioDeviceDescriptor {
    /**
     * Audio device role.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 7
     */
    readonly deviceRole: DeviceRole;

    /**
     * Audio device type.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 7
     */
    readonly deviceType: DeviceType;

    /**
     * Audio device id.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 9
     */
    readonly id: number;

    /**
     * Audio device name.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 9
     */
    readonly name: string;

    /**
     * Audio device address.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 9
     */
    readonly address: string;

    /**
     * Supported sampling rates.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 9
     */
    readonly sampleRates: Array<number>;

    /**
     * Supported channel counts.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 9
     */
    readonly channelCounts: Array<number>;

    /**
     * Supported channel masks.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 9
     */
    readonly channelMasks: Array<number>;
    /**
     * Device network id
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @systemapi
     * @since 9
     */
    readonly networkId: string;
    /**
     * Interrupt group id
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @systemapi
     * @since 9
     */
    readonly interruptGroupId: number;
    /**
     * Volume group id
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @systemapi
     * @since 9
     */
    readonly volumeGroupId: number;
    /**
     * Name used to display, considering distributed device situation.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 10
     */
    readonly displayName: string;
  }

  /**
   * Array of AudioDeviceDescriptors, which is read-only.
   * @syscap SystemCapability.Multimedia.Audio.Device
   * @since 7
   */
  type AudioDeviceDescriptors = Array<Readonly<AudioDeviceDescriptor>>;

  /**
   * Describes the volume event received by the app when the volume is changed.
   * @typedef VolumeEvent
   * @syscap SystemCapability.Multimedia.Audio.Volume
   * @since 9
   */
  interface VolumeEvent {
    /**
     * Volume type of the current stream.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 9
     */
    volumeType: AudioVolumeType;
    /**
     * Volume level.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 9
     */
    volume: number;
    /**
     * Whether to show the volume change in UI.
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @since 9
     */
    updateUi: boolean;
    /**
     * volumeGroup id
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @systemapi
     * @since 9
     */
    volumeGroupId: number;
    /**
     * Device network id
     * @syscap SystemCapability.Multimedia.Audio.Volume
     * @systemapi
     * @since 9
     */
    networkId: string;
  }

  /**
   * Describes the callback invoked for audio interruption or focus gain events.When the audio of an application
   * is interrupted by another application, the callback is invoked to notify the former application.
   * @typedef InterruptAction
   * @syscap SystemCapability.Multimedia.Audio.Renderer
   * @since 7
   * @deprecated since 9
   * @useinstead ohos.multimedia.audio.InterruptEvent
   */
  interface InterruptAction {

    /**
     * Event type.
     * The value TYPE_ACTIVATED means the focus gain event, and TYPE_INTERRUPT means the audio interruption event.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 7
     * @deprecated since 9
     */
    actionType: InterruptActionType;

    /**
     * Type of the audio interruption event.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 7
     * @deprecated since 9
     */
    type?: InterruptType;

    /**
     * Hint for the audio interruption event.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 7
     * @deprecated since 9
     */
    hint?: InterruptHint;

    /**
     * Whether the focus is gained or released. The value true means that the focus is gained or released,
     * and false means that the focus fails to be gained or released.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 7
     * @deprecated since 9
     */
    activated?: boolean;
  }

  /**
   * Describes input parameters of audio listening events.
   * @typedef AudioInterrupt
   * @syscap SystemCapability.Multimedia.Audio.Renderer
   * @since 7
   * @deprecated since 9
   */
  interface AudioInterrupt {

    /**
     * Audio stream usage type.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 7
     * @deprecated since 9
     */
    streamUsage: StreamUsage;

    /**
     * Type of the media interrupted.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 7
     * @deprecated since 9
     */
    contentType: ContentType;

    /**
     * Whether audio playback can be paused when it is interrupted.
     * The value true means that audio playback can be paused when it is interrupted, and false means the opposite.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 7
     * @deprecated since 9
     */
    pauseWhenDucked: boolean;
  }

  /**
   * Describes the microphone state change event received by the app when the microphone state is changed.
   * @typedef MicStateChangeEvent
   * @syscap SystemCapability.Multimedia.Audio.Device
   * @since 9
   */
  interface MicStateChangeEvent {
    /**
     * Mic mute state.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 9
     */
    mute: boolean;
  }
  /**
   * Describes the device change type and device information.
   * @typedef DeviceChangeAction
   * @syscap SystemCapability.Multimedia.Audio.Device
   * @since 7
   */
  interface DeviceChangeAction {
    /**
     * Device change type.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 7
     */
    type: DeviceChangeType;

    /**
     * Device information.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 7
     */
    deviceDescriptors: AudioDeviceDescriptors;
  }

  /**
   * Provides audio playback APIs.
   * @typedef AudioRenderer
   * @syscap SystemCapability.Multimedia.Audio.Renderer
   * @since 8
   */
  interface AudioRenderer {
    /**
     * Defines the current render state.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 8
     */
    readonly state: AudioState;

    /**
     * Obtains the renderer information provided while creating a renderer instance. This method uses an asynchronous
     * callback to return the result.
     * @param { AsyncCallback<AudioRendererInfo> } callback - Callback used to return the renderer information.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 8
     */
    getRendererInfo(callback: AsyncCallback<AudioRendererInfo>): void;
    /**
     * Obtains the renderer information provided while creating a renderer instance. This method uses a promise to
     * return the result.
     * @returns { Promise<AudioRendererInfo> } Promise used to return the renderer information.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 8
     */
    getRendererInfo(): Promise<AudioRendererInfo>;

    /**
     * Obtains the renderer stream information. This method uses an asynchronous callback to return the result.
     * @param { AsyncCallback<AudioStreamInfo> } callback - Callback used to return the stream information.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 8
     */
    getStreamInfo(callback: AsyncCallback<AudioStreamInfo>): void;
    /**
     * Obtains the renderer stream information. This method uses a promise to return the result.
     * @returns { Promise<AudioStreamInfo> } Promise used to return the stream information.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 8
     */
    getStreamInfo(): Promise<AudioStreamInfo>;

    /**
     * Obtains the renderer stream id. This method uses an asynchronous callback to return the result.
     * @param { AsyncCallback<number> } callback - Callback used to return the stream id.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 9
     */
    getAudioStreamId(callback: AsyncCallback<number>): void;
    /**
     * Obtains the renderer stream id. This method uses a promise to return the result.
     * @returns { Promise<number> } Promise used to return the stream id.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 9
     */
    getAudioStreamId(): Promise<number>;

    /**
     * Obtains the current audio effect mode. This method uses an asynchronous callback to return the query result.
     * @param { AsyncCallback<AudioEffectMode> } callback - Callback used to return the current audio effect mode.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 10
     */
    getAudioEffectMode(callback: AsyncCallback<AudioEffectMode>): void;
    /**
     * Obtains the current audio effect mode. This method uses a promise to return the query result.
     * @returns { Promise<AudioEffectMode> } Promise used to return the current audio effect mode.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 10
     */
    getAudioEffectMode(): Promise<AudioEffectMode>;

    /**
     * Sets the current audio effect mode. This method uses an asynchronous callback to return the result.
     * @param { AudioEffectMode } mode - Audio effect mode.
     * @param { AsyncCallback<void> } callback - Callback used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 10
     */
    setAudioEffectMode(mode: AudioEffectMode, callback: AsyncCallback<void>): void;
    /**
     * Sets the current audio effect mode. This method uses a promise to return the result.
     * @param { AudioEffectMode } mode - Audio effect mode.
     * @returns { Promise<void> } Promise used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 10
     */
    setAudioEffectMode(mode: AudioEffectMode): Promise<void>;

    /**
     * Starts the renderer. This method uses an asynchronous callback to return the result.
     * @param { AsyncCallback<void> } callback - Callback used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 8
     */
    start(callback: AsyncCallback<void>): void;
    /**
     * Starts the renderer. This method uses a promise to return the result.
     * @returns { Promise<void> } Promise used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 8
     */
    start(): Promise<void>;

    /**
     * Writes the buffer. This method uses an asynchronous callback to return the result.
     * @param { ArrayBuffer } buffer - Buffer to be written.
     * @param { AsyncCallback<number> } callback - Returns the number of bytes written if the operation is successful.
     *        Returns an error code otherwise.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 8
     */
    write(buffer: ArrayBuffer, callback: AsyncCallback<number>): void;
    /**
     * Writes the buffer. This method uses a promise to return the result.
     * @param { ArrayBuffer } buffer - Buffer to be written.
     * @returns { Promise<number> } Returns the number of bytes written if the operation is successful.
     *          Returns an error code otherwise.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 8
     */
    write(buffer: ArrayBuffer): Promise<number>;

    /**
     * Obtains the timestamp in Unix epoch time (starts from January 1, 1970), in nanoseconds. This method uses an
     * asynchronous callback to return the result.
     * @param { AsyncCallback<number> } callback - Callback used to return the timestamp.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 8
     */
    getAudioTime(callback: AsyncCallback<number>): void;
    /**
     * Obtains the timestamp in Unix epoch time (starts from January 1, 1970), in nanoseconds. This method uses a
     * promise to return the result.
     * @returns { Promise<number> } Promise used to return the timestamp.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 8
     */
    getAudioTime(): Promise<number>;

    /**
     * Drains the playback buffer. This method uses an asynchronous callback to return the result.
     * @param { AsyncCallback<void> } callback - Callback used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 8
     */
    drain(callback: AsyncCallback<void>): void;
    /**
     * Drains the playback buffer. This method uses a promise to return the result.
     * @returns { Promise<void> } Promise used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 8
     */
    drain(): Promise<void>;

    /**
     * Pauses rendering. This method uses an asynchronous callback to return the result.
     * @param { AsyncCallback<void> } callback - Callback used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 8
     */
    pause(callback: AsyncCallback<void>): void;
    /**
     * Pauses rendering. This method uses a promise to return the result.
     * @returns { Promise<void> } Promise used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 8
     */
    pause(): Promise<void>;

    /**
     * Stops rendering. This method uses an asynchronous callback to return the result.
     * @param { AsyncCallback<void> } callback - Callback used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 8
     */
    stop(callback: AsyncCallback<void>): void;
    /**
     * Stops rendering. This method uses a promise to return the result.
     * @returns { Promise<void> } Promise used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 8
     */
    stop(): Promise<void>;

    /**
     * Releases the renderer. This method uses an asynchronous callback to return the result.
     * @param { AsyncCallback<void> } callback - Callback used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 8
     */
    release(callback: AsyncCallback<void>): void;
    /**
     * Releases the renderer. This method uses a promise to return the result.
     * @returns { Promise<void> } Promise used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 8
     */
    release(): Promise<void>;

    /**
     * Obtains a reasonable minimum buffer size in bytes for rendering. This method uses an asynchronous callback to
     * return the result.
     * @param { AsyncCallback<number> } callback - Callback used to return the buffer size.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 8
     */
    getBufferSize(callback: AsyncCallback<number>): void;
    /**
     * Obtains a reasonable minimum buffer size in bytes for rendering. This method uses a promise to return the result.
     * @returns { Promise<number> } Promise used to return the buffer size.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 8
     */
    getBufferSize(): Promise<number>;

    /**
     * Sets the render rate. This method uses an asynchronous callback to return the result.
     * @param { AudioRendererRate } rate - Audio render rate.
     * @param { AsyncCallback<void> } callback - Callback used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 8
     */
    setRenderRate(rate: AudioRendererRate, callback: AsyncCallback<void>): void;
    /**
     * Sets the render rate. This method uses a promise to return the result.
     * @param { AudioRendererRate } rate - Audio render rate.
     * @returns { Promise<void> } Promise used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 8
     */
    setRenderRate(rate: AudioRendererRate): Promise<void>;

    /**
     * Obtains the current render rate. This method uses an asynchronous callback to return the result.
     * @param { AsyncCallback<AudioRendererRate> } callback - Callback used to return the audio render rate.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 8
     */
    getRenderRate(callback: AsyncCallback<AudioRendererRate>): void;
    /**
     * Obtains the current render rate. This method uses a promise to return the result.
     * @returns { Promise<AudioRendererRate> } Promise used to return the audio render rate.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 8
     */
    getRenderRate(): Promise<AudioRendererRate>;

    /**
     * Set interrupt mode.
     * @param { InterruptMode } mode - The interrupt mode.
     * @param { AsyncCallback<void> } callback - Callback used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Interrupt
     * @since 9
     */
    setInterruptMode(mode: InterruptMode, callback: AsyncCallback<void>): void;
    /**
     * Set interrupt mode.
     * @param { InterruptMode } mode - The interrupt mode.
     * @returns { Promise<void> } Promise used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Interrupt
     * @since 9
     */
    setInterruptMode(mode: InterruptMode): Promise<void>;

    /**
     * Sets the volume for this stream. This method uses an asynchronous callback to return the result.
     * @param { number } volume - Volume to set. The value type is float, form 0.0 to 1.0.
     * @param { AsyncCallback<void> } callback - Callback used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 9
     */
    setVolume(volume: number, callback: AsyncCallback<void>): void;
    /**
     * Sets the volume for a stream. This method uses a promise to return the result.
     * @param { number } volume - Volume to set. The value type is float, form 0.0 to 1.0.
     * @returns { Promise<void> } Promise used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 9
     */
    setVolume(volume: number): Promise<void>;

    /**
     * Gets the min volume this stream can set. This method uses an asynchronous callback to return the result.
     * @param { AsyncCallback<number> } callback - Callback used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 10
     */
    getMinStreamVolume(callback: AsyncCallback<number>): void;
    /**
     * Gets the min volume this stream can set. This method uses a promise to return the result.
     * @returns { Promise<number> } Promise used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 10
     */
    getMinStreamVolume(): Promise<number>;

    /**
     * Gets the max volume this stream can set. This method uses an asynchronous callback to return the result.
     * @param { AsyncCallback<number> } callback - Callback used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 10
     */
    getMaxStreamVolume(callback: AsyncCallback<number>): void;
    /**
     * Gets the max volume this stream can set. This method uses a promise to return the result.
     * @returns { Promise<number> } Promise used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 10
     */
    getMaxStreamVolume(): Promise<number>;

    /**
     * Gets buffer underflow count. This method uses an asynchronous callback to return the result.
     * @param { AsyncCallback<number> } callback - Callback used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 10
     */
    getUnderflowCount(callback: AsyncCallback<number>): void;
    /**
     * Gets buffer underflow count. This method uses a promise to return the result.
     * @returns { Promise<number> } Promise used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 10
     */
    getUnderflowCount(): Promise<number>;

    /**
     * Gets the output device or devices for this stream.
     * This method uses an asynchronous callback to return the result.
     * @param { AsyncCallback<AudioDeviceDescriptors> } callback - Callback used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 10
     */
    getCurrentOutputDevices(callback: AsyncCallback<AudioDeviceDescriptors>): void;
    /**
     * Gets the output device or devices for this stream.
     * This method uses a promise to return the result.
     * @returns { Promise<AudioDeviceDescriptors> } Promise used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 10
     */
    getCurrentOutputDevices(): Promise<AudioDeviceDescriptors>;

    /**
     * Listens for audio interrupt events. This method uses a callback to get interrupt events. The interrupt event is
     * triggered when audio playback is interrupted.
     * @param { 'audioInterrupt' } type - Type of the event to listen for. Only the audioInterrupt event is supported.
     * @param { Callback<InterruptEvent> } callback - Callback used to listen for interrupt callback.
     * @throws { BusinessError } 401 - if input parameter type or number mismatch
     * @throws { BusinessError } 6800101 - if input parameter value error
     * @syscap SystemCapability.Multimedia.Audio.Interrupt
     * @since 9
     */
    on(type: 'audioInterrupt', callback: Callback<InterruptEvent>): void;

    /**
     * Subscribes to mark reached events. When the number of frames rendered reaches the value of the frame parameter,
     * the callback is invoked.
     * @param { "markReach" } type - Type of the event to listen for. Only the markReach event is supported.
     * @param { number } frame - Number of frames to trigger the event. The value must be greater than 0.
     * @param { Callback<number> } callback - Callback invoked when the event is triggered.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 8
     */
    on(type: "markReach", frame: number, callback: Callback<number>): void;
    /**
     * Unsubscribes from mark reached events.
     * @param { "markReach" } type - Type of the event to listen for. Only the markReach event is supported.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 8
     */
    off(type: "markReach"): void;

    /**
     * Subscribes to period reached events. When the period of frame rendering reaches the value of frame parameter,
     * the callback is invoked.
     * @param { "periodReach" } type - Type of the event to listen for. Only the periodReach event is supported.
     * @param { number } frame - Period during which frame rendering is listened. The value must be greater than 0.
     * @param { Callback<number> } callback - Callback invoked when the event is triggered.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 8
     */
    on(type: "periodReach", frame: number, callback: Callback<number>): void;
    /**
     * Unsubscribes from period reached events.
     * @param { "periodReach" } type - Type of the event to listen for. Only the periodReach event is supported.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 8
     */
    off(type: "periodReach"): void;

    /**
     * Subscribes audio state change event callback.
     * @param { "stateChange" } type - Type of the event to listen for. Only the stateChange event is supported.
     * @param { Callback<AudioState> } callback - Callback invoked when state change.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 8
     */
    on(type: "stateChange", callback: Callback<AudioState>): void;

    /**
     * Subscribes output device change event callback.
     * The event is triggered when output device change for this stream.
     * @param { 'outputDeviceChange' } type - Type of the event to listen for.
     * @param { Callback<AudioDeviceDescriptors> } callback - Callback used to listen device change event.
     * @throws { BusinessError } 401 - if input parameter type or number mismatch.
     * @throws { BusinessError } 6800101 - if input parameter value error.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 10
     */
    on(type: 'outputDeviceChange', callback: Callback<AudioDeviceDescriptors>): void;
    /**
     * Unsubscribes output device change event callback.
     * @param { 'outputDeviceChange' } type - Type of the event to listen for.
     * @param { Callback<AudioDeviceDescriptors> } callback - Callback used in subscribe.
     * @throws { BusinessError } 401 - if input parameter type or number mismatch.
     * @throws { BusinessError } 6800101 - if input parameter value error.
     * @syscap SystemCapability.Multimedia.Audio.Device
     * @since 10
     */
    off(type: 'outputDeviceChange', callback?: Callback<AudioDeviceDescriptors>): void;
  }

  /**
   * Enumerates source types.
   * @enum { number }
   * @syscap SystemCapability.Multimedia.Audio.Core
   * @since 8
   */
  enum SourceType {
    /**
     * Invalid source type.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    SOURCE_TYPE_INVALID = -1,
    /**
     * Mic source type.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    SOURCE_TYPE_MIC = 0,
    /**
     * Voice recognition source type.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 9
     */
    SOURCE_TYPE_VOICE_RECOGNITION = 1,
    /**
     * Playback capture source type.
     * @since 10
     * @syscap SystemCapability.Multimedia.Audio.PlaybackCapture
     * @permission ohos.permission.CAPTURE_INTERNAL_AUDIO
     */
    SOURCE_TYPE_PLAYBACK_CAPTURE = 2,
    /**
     * Voice communication source type.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    SOURCE_TYPE_VOICE_COMMUNICATION = 7
  }

  /**
   * Describes audio capturer information.
   * @typedef AudioCapturerInfo
   * @syscap SystemCapability.Multimedia.Audio.Core
   * @since 8
   */
  interface AudioCapturerInfo {
    /**
     * Audio source type.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    source: SourceType;
    /**
     * Audio capturer flags.
     * @syscap SystemCapability.Multimedia.Audio.Core
     * @since 8
     */
    capturerFlags: number;
  }

  /**
   * Describes audio capturer configuration options.
   * @typedef AudioCapturerOptions
   * @syscap SystemCapability.Multimedia.Audio.Capturer
   * @since 8
   */
  interface AudioCapturerOptions {
    /**
     * Stream information.
     * @syscap SystemCapability.Multimedia.Audio.Capturer
     * @since 8
     */
    streamInfo: AudioStreamInfo;
    /**
     * Capturer information.
     * @syscap SystemCapability.Multimedia.Audio.Capturer
     * @since 8
     */
    capturerInfo: AudioCapturerInfo;
    /**
     * Playback capture config.
     * @since 10
     * @syscap SystemCapability.Multimedia.Audio.PlaybackCapture
     */
    playbackCaptureConfig?: AudioPlaybackCaptureConfig;
  }

  /**
   * Describe playback capture filtering options
   * @since 10
   * @syscap SystemCapability.Multimedia.Audio.PlaybackCapture
   */
  interface CaptureFilterOptions {
    /**
     * Filter by stream usage.
     * @since 10
     * @syscap SystemCapability.Multimedia.Audio.PlaybackCapture
     */
    usage: StreamUsage;
    /**
     * Filter by content type.
     * @since 10
     * @syscap SystemCapability.Multimedia.Audio.PlaybackCapture
     */
    content: ContentType;
  }

  /**
   * Describe playback capture config object.
   * @since 10
   * @syscap SystemCapability.Multimedia.Audio.PlaybackCapture
   */
  interface AudioPlaybackCaptureConfig {
    /**
     * Add matching audio renderer info to decide which streams to be captured.
     * @since 10
     * @syscap SystemCapability.Multimedia.Audio.PlaybackCapture
     * @permission ohos.permission.CAPTURE_VOICE_AUDIO
     */
    filterOptions: Array<CaptureFilterOptions>;

    /**
     * Enable or disable external recording at the same time, default value is false.
     * @since 10
     * @syscap SystemCapability.Multimedia.Audio.PlaybackCapture
     * @permission ohos.permission.MICROPHONE
     */
    enableMicrophone?: boolean;
  }

  /**
   * Provides APIs for audio recording.
   * @typedef AudioCapturer
   * @syscap SystemCapability.Multimedia.Audio.Capturer
   * @since 8
   */
  interface AudioCapturer {
    /**
     * Defines the current capture state.
     * @syscap SystemCapability.Multimedia.Audio.Capturer
     * @since 8
     */
    readonly state: AudioState;

    /**
     * Obtains the capturer information provided while creating a capturer instance. This method uses an asynchronous
     * callback to return the result.
     * @param { AsyncCallback<AudioCapturerInfo> } callback - Callback used to return the capturer information.
     * @syscap SystemCapability.Multimedia.Audio.Capturer
     * @since 8
     */
    getCapturerInfo(callback: AsyncCallback<AudioCapturerInfo>): void;
    /**
     * Obtains the capturer information provided while creating a capturer instance. This method uses a promise to
     * return the result.
     * @returns { Promise<AudioCapturerInfo> } Promise used to return the capturer information.
     * @syscap SystemCapability.Multimedia.Audio.Capturer
     * @since 8
     */
    getCapturerInfo(): Promise<AudioCapturerInfo>;

    /**
     * Obtains the capturer stream information. This method uses an asynchronous callback to return the result.
     * @param { AsyncCallback<AudioStreamInfo> } callback - Callback used to return the stream information.
     * @syscap SystemCapability.Multimedia.Audio.Capturer
     * @since 8
     */
    getStreamInfo(callback: AsyncCallback<AudioStreamInfo>): void;
    /**
     * Obtains the capturer stream information. This method uses a promise to return the result.
     * @returns { Promise<AudioStreamInfo> } Promise used to return the stream information.
     * @syscap SystemCapability.Multimedia.Audio.Capturer
     * @since 8
     */
    getStreamInfo(): Promise<AudioStreamInfo>;

    /**
     * Obtains the capturer stream id. This method uses an asynchronous callback to return the result.
     * @param { AsyncCallback<number> } callback - Callback used to return the stream id.
     * @syscap SystemCapability.Multimedia.Audio.Capturer
     * @since 9
     */
    getAudioStreamId(callback: AsyncCallback<number>): void;
    /**
     * Obtains the capturer stream id. This method uses a promise to return the result.
     * @returns { Promise<number> } Promise used to return the stream id.
     * @syscap SystemCapability.Multimedia.Audio.Capturer
     * @since 9
     */
    getAudioStreamId(): Promise<number>;

    /**
     * Starts capturing. This method uses an asynchronous callback to return the result.
     * @param { AsyncCallback<void> } callback - Callback used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Capturer
     * @since 8
     */
    start(callback: AsyncCallback<void>): void;
    /**
     * Starts capturing. This method uses a promise to return the result.
     * @returns { Promise<void> } Promise used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Capturer
     * @since 8
     */
    start(): Promise<void>;

    /**
     * Reads the buffer from the audio capturer. This method uses an asynchronous callback to return the result.
     * @param { number } size - Number of bytes to read.
     * @param { boolean } isBlockingRead - Whether the read operation should be blocked.
     * @param { AsyncCallback<ArrayBuffer> } callback - Callback used to return the buffer.
     * @syscap SystemCapability.Multimedia.Audio.Capturer
     * @since 8
     */
    read(size: number, isBlockingRead: boolean, callback: AsyncCallback<ArrayBuffer>): void;
    /**
     * Reads the buffer from the audio capturer. This method uses a promise to return the result.
     * @param { number } size - Number of bytes to read.
     * @param { boolean } isBlockingRead - Whether the read operation should be blocked.
     * @returns { Promise<ArrayBuffer> } Returns the buffer data read if the operation is successful.
     *          Returns an error code otherwise.
     * @syscap SystemCapability.Multimedia.Audio.Capturer
     * @since 8
     */
    read(size: number, isBlockingRead: boolean): Promise<ArrayBuffer>;

    /**
     * Obtains the timestamp in Unix epoch time (starts from January 1, 1970), in nanoseconds. This method uses an
     * asynchronous callback to return the result.
     * @param { AsyncCallback<number> } callback - Callback used to return the timestamp.
     * @syscap SystemCapability.Multimedia.Audio.Capturer
     * @since 8
     */
    getAudioTime(callback: AsyncCallback<number>): void;
    /**
     * Obtains the timestamp in Unix epoch time (starts from January 1, 1970), in nanoseconds. This method uses a
     * promise to return the result.
     * @returns { Promise<number> } Promise used to return the timestamp.
     * @syscap SystemCapability.Multimedia.Audio.Capturer
     * @since 8
     */
    getAudioTime(): Promise<number>;

    /**
     * Stops capturing. This method uses an asynchronous callback to return the result.
     * @param { AsyncCallback<void> } callback - Callback used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Capturer
     * @since 8
     */
    stop(callback: AsyncCallback<void>): void;
    /**
     * Stops capturing. This method uses a promise to return the result.
     * @returns { Promise<void> } Promise used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Capturer
     * @since 8
     */
    stop(): Promise<void>;

    /**
     * Releases the capturer. This method uses an asynchronous callback to return the result.
     * @param { AsyncCallback<void> } callback - Callback used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Capturer
     * @since 8
     */
    release(callback: AsyncCallback<void>): void;
    /**
     * Releases the capturer. This method uses a promise to return the result.
     * @returns { Promise<void> } - Promise used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Capturer
     * @since 8
     */
    release(): Promise<void>;

    /**
     * Obtains a reasonable minimum buffer size in bytes for capturing. This method uses an asynchronous callback to
     * return the result.
     * @param { AsyncCallback<number> } callback - Callback used to return the buffer size.
     * @syscap SystemCapability.Multimedia.Audio.Capturer
     * @since 8
     */
    getBufferSize(callback: AsyncCallback<number>): void;
    /**
     * Obtains a reasonable minimum buffer size in bytes for capturing. This method uses a promise to return the result.
     * @returns { Promise<number> } Promise used to return the buffer size.
     * @syscap SystemCapability.Multimedia.Audio.Capturer
     * @since 8
     */
    getBufferSize(): Promise<number>;

    /**
     * Subscribes to mark reached events. When the number of frames captured reaches the value of the frame parameter,
     * the callback is invoked.
     * @param { "markReach" } type - Type of the event to listen for. Only the markReach event is supported.
     * @param { number } frame - Number of frames to trigger the event. The value must be greater than 0.
     * @param { Callback<number> } callback - Callback invoked when the event is triggered.
     * @syscap SystemCapability.Multimedia.Audio.Capturer
     * @since 8
     */
    on(type: "markReach", frame: number, callback: Callback<number>): void;
    /**
     * Unsubscribes from the mark reached events.
     * @param { "markReach" } type - Type of the event to listen for. Only the markReach event is supported.
     * @syscap SystemCapability.Multimedia.Audio.Capturer
     * @since 8
     */
    off(type: "markReach"): void;

    /**
     * Subscribes to period reached events. When the period of frame capturing reaches the value of frame parameter,
     * the callback is invoked.
     * @param { "periodReach" } type - Type of the event to listen for. Only the periodReach event is supported.
     * @param { number } frame - Period during which frame capturing is listened. The value must be greater than 0.
     * @param { Callback<number> } callback - Callback invoked when the event is triggered.
     * @syscap SystemCapability.Multimedia.Audio.Capturer
     * @since 8
     */
    on(type: "periodReach", frame: number, callback: Callback<number>): void;
    /**
     * Unsubscribes from period reached events.
     * @param { "periodReach" } type - Type of the event to listen for. Only the periodReach event is supported.
     * @syscap SystemCapability.Multimedia.Audio.Capturer
     * @since 8
     */
    off(type: "periodReach"): void;

    /**
     * Subscribes audio state change event callback.
     * @param { "stateChange" } type - Type of the event to listen for. Only the stateChange event is supported.
     * @param { Callback<AudioState> } callback - Callback used to listen for the audio state change event.
     * @syscap SystemCapability.Multimedia.Audio.Capturer
     * @since 8
     */
    on(type: "stateChange", callback: Callback<AudioState>): void;

    /**
     * Listens for audio interrupt events. This method uses a callback to get interrupt events. The interrupt event is
     * triggered when audio recording is interrupted.
     * @param { 'audioInterrupt' } type - Type of the event to listen for. Only the audioInterrupt event is supported.
     * @param { Callback<InterruptEvent> } callback - Callback used to listen for interrupt callback.
     * @throws { BusinessError } 401 - if input parameter type or number mismatch
     * @throws { BusinessError } 6800101 - if input parameter value error
     * @syscap SystemCapability.Multimedia.Audio.Interrupt
     * @since 10
     */
    on(type: 'audioInterrupt', callback: Callback<InterruptEvent>): void;

    /**
     * UnSubscribes to audio interrupt events.
     * @param { 'audioInterrupt' } type - Type of the event to listen for. Only the audioInterrupt event is supported.
     * @throws { BusinessError } 401 - if input parameter type or number mismatch
     * @throws { BusinessError } 6800101 - if input parameter value error
     * @syscap SystemCapability.Multimedia.Audio.Interrupt
     * @since 10
     */
    off(type: 'audioInterrupt'): void;
  }

  /**
   * Enumerates tone types for player.
   * @enum { number }
   * @syscap SystemCapability.Multimedia.Audio.Tone
   * @systemapi
   * @since 9
   */
  enum ToneType {
    /**
     * Dial tone for key 0.
     * @syscap SystemCapability.Multimedia.Audio.Tone
     * @systemapi
     * @since 9
     */
    TONE_TYPE_DIAL_0 = 0,
    /**
     * Dial tone for key 1.
     * @syscap SystemCapability.Multimedia.Audio.Tone
     * @systemapi
     * @since 9
     */
    TONE_TYPE_DIAL_1 = 1,
    /**
     * Dial tone for key 2.
     * @syscap SystemCapability.Multimedia.Audio.Tone
     * @systemapi
     * @since 9
     */
    TONE_TYPE_DIAL_2 = 2,
    /**
     * Dial tone for key 3.
     * @syscap SystemCapability.Multimedia.Audio.Tone
     * @systemapi
     * @since 9
     */
    TONE_TYPE_DIAL_3 = 3,
    /**
     * Dial tone for key 4.
     * @syscap SystemCapability.Multimedia.Audio.Tone
     * @systemapi
     * @since 9
     */
    TONE_TYPE_DIAL_4 = 4,
    /**
     * Dial tone for key 5.
     * @syscap SystemCapability.Multimedia.Audio.Tone
     * @systemapi
     * @since 9
     */
    TONE_TYPE_DIAL_5 = 5,
    /**
     * Dial tone for key 6.
     * @syscap SystemCapability.Multimedia.Audio.Tone
     * @systemapi
     * @since 9
     */
    TONE_TYPE_DIAL_6 = 6,
    /**
     * Dial tone for key 7.
     * @syscap SystemCapability.Multimedia.Audio.Tone
     * @systemapi
     * @since 9
     */
    TONE_TYPE_DIAL_7 = 7,
    /**
     * Dial tone for key 8.
     * @syscap SystemCapability.Multimedia.Audio.Tone
     * @systemapi
     * @since 9
     */
    TONE_TYPE_DIAL_8 = 8,
    /**
     * Dial tone for key 9.
     * @syscap SystemCapability.Multimedia.Audio.Tone
     * @systemapi
     * @since 9
     */
    TONE_TYPE_DIAL_9 = 9,
    /**
     * Dial tone for key *.
     * @syscap SystemCapability.Multimedia.Audio.Tone
     * @systemapi
     * @since 9
     */
    TONE_TYPE_DIAL_S = 10,
    /**
     * Dial tone for key #.
     * @syscap SystemCapability.Multimedia.Audio.Tone
     * @systemapi
     * @since 9
     */
    TONE_TYPE_DIAL_P = 11,
    /**
     * Dial tone for key A.
     * @syscap SystemCapability.Multimedia.Audio.Tone
     * @systemapi
     * @since 9
     */
    TONE_TYPE_DIAL_A = 12,
    /**
     * Dial tone for key B.
     * @syscap SystemCapability.Multimedia.Audio.Tone
     * @systemapi
     * @since 9
     */
    TONE_TYPE_DIAL_B = 13,
    /**
     * Dial tone for key C.
     * @syscap SystemCapability.Multimedia.Audio.Tone
     * @systemapi
     * @since 9
     */
    TONE_TYPE_DIAL_C = 14,
    /**
     * Dial tone for key D.
     * @syscap SystemCapability.Multimedia.Audio.Tone
     * @systemapi
     * @since 9
     */
    TONE_TYPE_DIAL_D = 15,
    /**
     * Supervisory tone for dial.
     * @syscap SystemCapability.Multimedia.Audio.Tone
     * @systemapi
     * @since 9
     */
    TONE_TYPE_COMMON_SUPERVISORY_DIAL = 100,
    /**
     * Supervisory tone for busy.
     * @syscap SystemCapability.Multimedia.Audio.Tone
     * @systemapi
     * @since 9
     */
    TONE_TYPE_COMMON_SUPERVISORY_BUSY = 101,
    /**
     * Supervisory tone for dial.
     * @syscap SystemCapability.Multimedia.Audio.Tone
     * @systemapi
     * @since 9
     */
    TONE_TYPE_COMMON_SUPERVISORY_CONGESTION = 102,
    /**
     * Supervisory tone for radio path acknowledgment.
     * @syscap SystemCapability.Multimedia.Audio.Tone
     * @systemapi
     * @since 9
     */
    TONE_TYPE_COMMON_SUPERVISORY_RADIO_ACK = 103,
    /**
     * Supervisory tone for radio path not available.
     * @syscap SystemCapability.Multimedia.Audio.Tone
     * @systemapi
     * @since 9
     */
    TONE_TYPE_COMMON_SUPERVISORY_RADIO_NOT_AVAILABLE = 104,
    /**
     * Supervisory tone for call waiting.
     * @syscap SystemCapability.Multimedia.Audio.Tone
     * @systemapi
     * @since 9
     */
    TONE_TYPE_COMMON_SUPERVISORY_CALL_WAITING = 106,
    /**
     * Supervisory tone for ringtone.
     * @syscap SystemCapability.Multimedia.Audio.Tone
     * @systemapi
     * @since 9
     */
    TONE_TYPE_COMMON_SUPERVISORY_RINGTONE = 107,
    /**
     * Proprietary tone for beep.
     * @syscap SystemCapability.Multimedia.Audio.Tone
     * @systemapi
     * @since 9
     */
    TONE_TYPE_COMMON_PROPRIETARY_BEEP = 200,
    /**
     * Proprietary tone for positive acknowledgment.
     * @syscap SystemCapability.Multimedia.Audio.Tone
     * @systemapi
     * @since 9
     */
    TONE_TYPE_COMMON_PROPRIETARY_ACK = 201,
    /**
     * Proprietary tone for prompt.
     * @syscap SystemCapability.Multimedia.Audio.Tone
     * @systemapi
     * @since 9
     */
    TONE_TYPE_COMMON_PROPRIETARY_PROMPT = 203,
    /**
     * Proprietary tone for double beep.
     * @syscap SystemCapability.Multimedia.Audio.Tone
     * @systemapi
     * @since 9
     */
    TONE_TYPE_COMMON_PROPRIETARY_DOUBLE_BEEP = 204,
  }

  /**
   * Provides APIs for tone playing.
   * @typedef TonePlayer
   * @syscap SystemCapability.Multimedia.Audio.Tone
   * @systemapi
   * @since 9
   */
  interface TonePlayer {
    /**
     * Loads tone. This method uses an asynchronous callback to return the result.
     * @param { ToneType } type - Tone type to play.
     * @param { AsyncCallback<void> } callback - Callback used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Tone
     * @systemapi
     * @since 9
     */
    load(type: ToneType, callback: AsyncCallback<void>): void;
    /**
     * Loads tone. This method uses a promise to return the result.
     * @param { ToneType } type - Tone type to play.
     * @returns { Promise<void> } Promise used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Tone
     * @systemapi
     * @since 9
     */
    load(type: ToneType): Promise<void>;

    /**
     * Starts player. This method uses an asynchronous callback to return the result.
     * @param { AsyncCallback<void> } callback - Callback used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Tone
     * @systemapi
     * @since 9
     */
    start(callback: AsyncCallback<void>): void;
    /**
     * Starts player. This method uses a promise to return the result.
     * @returns { Promise<void> }Promise used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Tone
     * @systemapi
     * @since 9
     */
    start(): Promise<void>;

    /**
     * Stops player. This method uses an asynchronous callback to return the result.
     * @param { AsyncCallback<void> } callback - Callback used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Tone
     * @systemapi
     * @since 9
     */
    stop(callback: AsyncCallback<void>): void;
    /**
     * Stops player. This method uses a promise to return the result.
     * @returns { Promise<void> } Promise used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Tone
     * @systemapi
     * @since 9
     */
    stop(): Promise<void>;

    /**
     * Releases the player. This method uses an asynchronous callback to return the result.
     * @param { AsyncCallback<void> } callback - Callback used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Tone
     * @systemapi
     * @since 9
     */
    release(callback: AsyncCallback<void>): void;
    /**
     * Releases the player. This method uses a promise to return the result.
     * @returns { Promise<void> } Promise used to return the result.
     * @syscap SystemCapability.Multimedia.Audio.Tone
     * @systemapi
     * @since 9
     */
    release(): Promise<void>;
  }

  /**
   * Array of AudioEffectMode, which is read-only.
   * @syscap SystemCapability.Multimedia.Audio.Renderer
   * @since 10
   */
  type AudioEffectInfoArray = Array<Readonly<AudioEffectMode>>;

  /**
   * Describes an audio effect mode group.
   * @enum { number }
   * @syscap SystemCapability.Multimedia.Audio.Renderer
   * @since 10
   */
  enum AudioEffectMode {
    /**
     * Audio Effect Mode effect none.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 10
     */
    EFFECT_NONE = 0,
    /**
     * Audio Effect Mode effect default.
     * @syscap SystemCapability.Multimedia.Audio.Renderer
     * @since 10
     */
    EFFECT_DEFAULT = 1,
  }
}

export default audio;