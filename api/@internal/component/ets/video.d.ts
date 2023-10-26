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

/**
 * Seek mode.
 *
 * @enum { number }
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @since 8
 */
/**
 * Seek mode.
 *
 * @enum { number }
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @since 10
 */
declare enum SeekMode {
  /**
   * Sync to keyframes before the time point.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 8
   */
  /**
   * Sync to keyframes before the time point.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  PreviousKeyframe,

  /**
   * Sync to keyframes after the time point.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 8
   */
  /**
   * Sync to keyframes after the time point.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  NextKeyframe,

  /**
   * Sync to closest keyframes.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 8
   */
  /**
   * Sync to closest keyframes.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  ClosestKeyframe,

  /**
   * Seek to frames closest the time point.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 8
   */
  /**
   * Seek to frames closest the time point.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  Accurate,
}

/**
 * playback speed.
 *
 * @enum { number }
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @since 8
 */
/**
 * playback speed.
 *
 * @enum { number }
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @since 10
 */
declare enum PlaybackSpeed {
  /**
   * 0.75x speed playback.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 8
   */
  /**
   * 0.75x speed playback.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  Speed_Forward_0_75_X,

  /**
   * 1.00x speed playback.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 8
   */
  /**
   * 1.00x speed playback.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  Speed_Forward_1_00_X,

  /**
   * 1.25x speed playback.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 8
   */
  /**
   * 1.25x speed playback.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  Speed_Forward_1_25_X,

  /**
   * 1.75x speed playback.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 8
   */
  /**
   * 1.75x speed playback.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  Speed_Forward_1_75_X,

  /**
   * 2.00x speed playback.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 8
   */
  /**
   * 2.00x speed playback.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  Speed_Forward_2_00_X,
}

/**
 * Defines the video options.
 *
 * @interface VideoOptions
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @since 7
 */
/**
 * Defines the video options.
 *
 * @interface VideoOptions
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @since 10
 */
declare interface VideoOptions {
  /**
   * src of video.
   *
   * @type { ?(string | Resource) }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 7
   */
  /**
   * src of video.
   *
   * @type { ?(string | Resource) }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  src?: string | Resource;

  /**
   * playback rate of video.
   *
   * @type { ?(number | string | PlaybackSpeed) }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 7
   */
  /**
   * playback rate of video.
   *
   * @type { ?(number | string | PlaybackSpeed) }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  currentProgressRate?: number | string | PlaybackSpeed;

  /**
   * preview uri of video.
   *
   * @type { ?(string | PixelMap | Resource) }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 7
   */
  /**
   * preview uri of video.
   *
   * @type { ?(string | PixelMap | Resource) }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  previewUri?: string | PixelMap | Resource;

  /**
   * controller of video.
   *
   * @type { ?VideoController }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 7
   */
  /**
   * controller of video.
   *
   * @type { ?VideoController }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  controller?: VideoController;
}

/**
 * Defines the video controller.
 *
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @since 7
 */
/**
 * Defines the video controller.
 *
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @since 10
 */
declare class VideoController {
  /**
   * constructor.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 7
   */
  /**
   * constructor.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  constructor();

  /**
   * Provides events to play.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 7
   */
  /**
   * Provides events to play.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  start();

  /**
   * Provides a pause event for playback.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 7
   */
  /**
   * Provides a pause event for playback.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  pause();

  /**
   * Provides an event to stop playback.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 7
   */
  /**
   * Provides an event to stop playback.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  stop();

  /**
   * Provide the progress method of video playback.
   *
   * @param { number } value
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 7
   */
  /**
   * Provide the progress method of video playback.
   *
   * @param { number } value
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  setCurrentTime(value: number);

  /**
   * Provides a full screen playback method.
   *
   * @param { boolean } value
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 7
   */
  /**
   * Provides a full screen playback method.
   *
   * @param { boolean } value
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  requestFullscreen(value: boolean);

  /**
   * Provides a method to exit full screen playback.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 7
   */
  /**
   * Provides a method to exit full screen playback.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  exitFullscreen();

  /**
   * Provide the progress method of video playback.
   *
   * @param { number } value
   * @param { SeekMode } seekMode
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 8
   */
  /**
   * Provide the progress method of video playback.
   *
   * @param { number } value
   * @param { SeekMode } seekMode
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  setCurrentTime(value: number, seekMode: SeekMode);
}

/**
 * Defines the video interface.
 *
 * @interface VideoInterface
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @since 7
 */
/**
 * Defines the video interface.
 *
 * @interface VideoInterface
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @since 10
 */
interface VideoInterface {
  /**
   * Set the value.
   *
   * @param { VideoOptions } value
   * @returns { VideoAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 7
   */
  /**
   * Set the value.
   *
   * @param { VideoOptions } value
   * @returns { VideoAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  (value: VideoOptions): VideoAttribute;
}

/**
 * Defines the video attribute functions.
 *
 * @extends CommonMethod
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @since 7
 */
/**
 * Defines the video attribute functions.
 *
 * @extends CommonMethod
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @since 10
 */
declare class VideoAttribute extends CommonMethod<VideoAttribute> {
  /**
   * Called when judging whether the video is muted.
   *
   * @param { boolean } value
   * @returns { VideoAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 7
   */
  /**
   * Called when judging whether the video is muted.
   *
   * @param { boolean } value
   * @returns { VideoAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  muted(value: boolean): VideoAttribute;

  /**
   * Called when judging whether the video is played automatically.
   *
   * @param { boolean } value
   * @returns { VideoAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 7
   */
  /**
   * Called when judging whether the video is played automatically.
   *
   * @param { boolean } value
   * @returns { VideoAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  autoPlay(value: boolean): VideoAttribute;

  /**
   * Called when judging whether the control bar is displayed.
   *
   * @param { boolean } value
   * @returns { VideoAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 7
   */
  /**
   * Called when judging whether the control bar is displayed.
   *
   * @param { boolean } value
   * @returns { VideoAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  controls(value: boolean): VideoAttribute;

  /**
   * Called when judging whether the video is played circular.
   *
   * @param { boolean } value
   * @returns { VideoAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 6
   */
  /**
   * Called when judging whether the video is played circular.
   *
   * @param { boolean } value
   * @returns { VideoAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  loop(value: boolean): VideoAttribute;

  /**
   * Called when determining the zoom type of the video source.
   *
   * @param { ImageFit } value
   * @returns { VideoAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 7
   */
  /**
   * Called when determining the zoom type of the video source.
   *
   * @param { ImageFit } value
   * @returns { VideoAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  objectFit(value: ImageFit): VideoAttribute;

  /**
   * Called when the video is played.
   *
   * @param { function } event
   * @returns { VideoAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 7
   */
  /**
   * Called when the video is played.
   *
   * @param { function } event
   * @returns { VideoAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  onStart(event: () => void): VideoAttribute;

  /**
   * Called when the video is paused.
   *
   * @param { function } event
   * @returns { VideoAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 7
   */
  /**
   * Called when the video is paused.
   *
   * @param { function } event
   * @returns { VideoAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  onPause(event: () => void): VideoAttribute;

  /**
   * Called when the video playback ends.
   *
   * @param { function } event
   * @returns { VideoAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 7
   */
  /**
   * Called when the video playback ends.
   *
   * @param { function } event
   * @returns { VideoAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  onFinish(event: () => void): VideoAttribute;

  /**
   * Called when the video enters and exits the full screen.
   *
   * @param { function } callback
   * @returns { VideoAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 7
   */
  /**
   * Called when the video enters and exits the full screen.
   *
   * @param { function } callback
   * @returns { VideoAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  onFullscreenChange(callback: (event: {
    /**
     * Play the flag in full screen.
     *
     * @syscap SystemCapability.ArkUI.ArkUI.Full
     * @crossplatform
     * @since 10
     */
    fullscreen: boolean
  }) => void): VideoAttribute;

  /**
   * Called when the video preparation is complete.
   *
   * @param { function } callback
   * @returns { VideoAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 7
   */
  /**
   * Called when the video preparation is complete.
   *
   * @param { function } callback
   * @returns { VideoAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  onPrepared(callback: (event: {
    /**
     * Playback duration.
     *
     * @syscap SystemCapability.ArkUI.ArkUI.Full
     * @crossplatform
     * @since 10
     */
    duration: number
  }) => void): VideoAttribute;

  /**
   * Called when the time information is reported when the progress bar process is operated.
   *
   * @param { function } callback
   * @returns { VideoAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 7
   */
  /**
   * Called when the time information is reported when the progress bar process is operated.
   *
   * @param { function } callback
   * @returns { VideoAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  onSeeking(callback: (event: {
    /**
     * Play time.
     *
     * @syscap SystemCapability.ArkUI.ArkUI.Full
     * @crossplatform
     * @since 10
     */
    time: number
  }) => void): VideoAttribute;

  /**
   * Called when the playback time information is reported after the operation progress bar is completed.
   *
   * @param { function } callback
   * @returns { VideoAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 7
   */
  /**
   * Called when the playback time information is reported after the operation progress bar is completed.
   *
   * @param { function } callback
   * @returns { VideoAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  onSeeked(callback: (event: {
    /**
     * Play time.
     *
     * @syscap SystemCapability.ArkUI.ArkUI.Full
     * @crossplatform
     * @since 10
     */
    time: number
  }) => void): VideoAttribute;

  /**
   * Called when the playback progress changes.
   *
   * @param { function } callback
   * @returns { VideoAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 7
   */
  /**
   * Called when the playback progress changes.
   *
   * @param { function } callback
   * @returns { VideoAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  onUpdate(callback: (event: {
    /**
     * Play time.
     *
     * @syscap SystemCapability.ArkUI.ArkUI.Full
     * @crossplatform
     * @since 10
     */
    time: number
  }) => void): VideoAttribute;

  /**
   * Called when playback fails.
   *
   * @param { function } event
   * @returns { VideoAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 7
   */
  /**
   * Called when playback fails.
   *
   * @param { function } event
   * @returns { VideoAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  onError(event: () => void): VideoAttribute;
}

/**
 * Defines Video Component.
 *
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @since 7
 */
/**
 * Defines Video Component.
 *
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @since 10
 */
declare const Video: VideoInterface;

/**
 * Defines Video Component instance.
 *
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @since 7
 */
/**
 * Defines Video Component instance.
 *
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @since 10
 */
declare const VideoInstance: VideoAttribute;
