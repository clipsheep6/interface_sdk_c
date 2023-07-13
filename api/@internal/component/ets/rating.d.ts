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
 * Provides the interface for scoring bars.
 *
 * @interface RatingInterface
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @since 7
 */
/**
 * Provides the interface for scoring bars.
 *
 * @interface RatingInterface
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @since 9
 * @form
 */
/**
 * Provides the interface for scoring bars.
 *
 * @interface RatingInterface
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @since 10
 * @form
 */
interface RatingInterface {
  /**
   * Called when a score bar is created.
   *
   * @param { { rating: number; indicator?: boolean } } options
   * @returns { RatingAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 7
   */
  /**
   * Called when a score bar is created.
   *
   * @param { { rating: number; indicator?: boolean } } options
   * @returns { RatingAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 9
   * @form
   */
  /**
   * Called when a score bar is created.
   *
   * @param { { rating: number; indicator?: boolean } } options
   * @returns { RatingAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   * @form
   */
  (options?: { rating: number; indicator?: boolean }): RatingAttribute;
}

/**
 * Defines the rating attribute functions.
 *
 * @extends CommonMethod
 * @since 7
 */
/**
 * Defines the rating attribute functions.
 *
 * @extends CommonMethod
 * @since 9
 * @form
 */
/**
 * Defines the rating attribute functions.
 *
 * @extends CommonMethod
 * @crossplatform
 * @since 10
 * @form
 */
declare class RatingAttribute extends CommonMethod<RatingAttribute> {
  /**
   * Called when the total number of stars is set.
   *
   * @param { number } value
   * @returns { RatingAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 7
   */
  /**
   * Called when the total number of stars is set.
   *
   * @param { number } value
   * @returns { RatingAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 9
   * @form
   */
  /**
   * Called when the total number of stars is set.
   *
   * @param { number } value
   * @returns { RatingAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   * @form
   */
  stars(value: number): RatingAttribute;

  /**
   * Called when the step size of the operation rating.
   *
   * @param { number } value
   * @returns { RatingAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 7
   */
  /**
   * Called when the step size of the operation rating.
   *
   * @param { number } value
   * @returns { RatingAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 9
   * @form
   */
  /**
   * Called when the step size of the operation rating.
   *
   * @param { number } value
   * @returns { RatingAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   * @form
   */
  stepSize(value: number): RatingAttribute;

  /**
   * Called when a picture is set.
   *
   * @param { { backgroundUri: string; foregroundUri: string; secondaryUri?: string } } value
   * @returns { RatingAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 7
   */
  /**
   * Called when a picture is set.
   *
   * @param { { backgroundUri: string; foregroundUri: string; secondaryUri?: string } } value
   * @returns { RatingAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 9
   * @form
   */
  /**
   * Called when a picture is set.
   *
   * @param { { backgroundUri: string; foregroundUri: string; secondaryUri?: string } } value
   * @returns { RatingAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   * @form
   */
  starStyle(value: { backgroundUri: string; foregroundUri: string; secondaryUri?: string }): RatingAttribute;

  /**
   * Called when the star rating of the operation scoring bar changes.
   *
   * @param { (value: number) => void } callback
   * @returns { RatingAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 7
   */
  /**
   * Called when the star rating of the operation scoring bar changes.
   *
   * @param { (value: number) => void } callback
   * @returns { RatingAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 9
   * @form
   */
  /**
   * Called when the star rating of the operation scoring bar changes.
   *
   * @param { (value: number) => void } callback
   * @returns { RatingAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   * @form
   */
  onChange(callback: (value: number) => void): RatingAttribute;
}

/**
 * Defines Rating Component.
 *
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @since 7
 */
/**
 * Defines Rating Component.
 *
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @since 9
 * @form
 */
/**
 * Defines Rating Component.
 *
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @since 10
 * @form
 */
declare const Rating: RatingInterface;

/**
 * Defines Rating Component instance.
 *
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @since 7
 */
/**
 * Defines Rating Component instance.
 *
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @since 9
 * @form
 */
/**
 * Defines Rating Component instance.
 *
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @since 10
 * @form
 */
declare const RatingInstance: RatingAttribute;
