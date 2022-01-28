/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
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
 * @since 8
 */
declare enum SeekMode {
  /**
   * Sync to keyframes before the time point.
   * @since 8
   */
  PreviousSync,

  /**
   * Sync to keyframes after the time point.
   * @since 8
   */
  NextSync,

  /**
   * Sync to closest keyframes.
   * @since 8
   */
  ClosestSync,

   /**
   * Seek to frames closest the time point.
   * @since 8
   */
  Closest,
}

/**
 * @since 7
 */
declare class VideoController {
  /**
   * constructor.
   * @since 7
   */
  constructor();

  /**
   * Provides events to play.
   * @since 7
   */
  start();

  /**
   * Provides a pause event for playback.
   * @since 7
   */
  pause();

  /**
   * Provide the progress method of video playback.
   * @since 7
   */
  setCurrentTime(value: number);

  /**
   * Provide the progress method of video playback.
   * @since 8
   */
  setCurrentTime(value: number, seekMode: SeekMode);
}

/**
 * @since 7
 */
interface VideoInterface {
  /**
   * Set the value.
   * @since 7
   */
  (value: {
    src?: string | Resource;
    previewUri?: string | PixelMap | Resource;
    controller?: VideoController;
  }): VideoAttribute;
}

/**
 * @since 7
 */
declare class VideoAttribute extends CommonMethod<VideoAttribute> {
  /**
   * Just use for genetate tsbundle
   * @ignore ide should ignore this arrtibute
   */
  create(value: {
    src?: string | Resource;
    previewUri?: string | PixelMap | Resource;
    controller?: VideoController;
  }): VideoAttribute;

  /**
   * Just use for genetate tsbundle
   * @ignore ide should ignore this arrtibute
   */
  debugLine(value: string): VideoAttribute;

  /**
   * Called when judging whether the video is muted.
   * @since 7
   */
  muted(value: boolean): VideoAttribute;

  /**
   * Called when judging whether the video is played automatically.
   * @since 7
   */
  autoPlay(value: boolean): VideoAttribute;

  /**
   * Called when judging whether the control bar is displayed.
   * @since 7
   */
  controls(value: boolean): VideoAttribute;

  /**
   * Called when judging whether the video is played circular.
   * @since 6
   */
  loop(value: boolean): VideoAttribute;

  /**
   * Called when determining the zoom type of the video source.
   * @since 7
   */
  objectFit(value: ImageFit): VideoAttribute;

  /**
   * Called when the video is played.
   * @since 7
   */
  onStart(event: () => void): VideoAttribute;

  /**
   * Called when the video is paused.
   * @since 7
   */
  onPause(event: () => void): VideoAttribute;

  /**
   * Called when the video playback ends.
   * @since 7
   */
  onFinish(event: () => void): VideoAttribute;

  /**
   * Called when the video preparation is complete.
   * @since 7
   */
  onPrepared(callback: (event?: { duration: number }) => void): VideoAttribute;

  /**
   * Called when the time information is reported when the progress bar process is operated.
   * @since 7
   */
  onSeeking(callback: (event?: { time: number }) => void): VideoAttribute;

  /**
   * Called when the playback time information is reported after the operation progress bar is completed.
   * @since 7
   */
  onSeeked(callback: (event?: { time: number }) => void): VideoAttribute;

  /**
   * Called when the playback progress changes.
   * @since 7
   */
  onUpdate(callback: (event?: { time: number }) => void): VideoAttribute;

  /**
   * Called when playback fails.
   * @since 7
   */
  onError(event: () => void): VideoAttribute;
}

declare const Video: VideoInterface;
declare const VideoInstance: VideoAttribute;
