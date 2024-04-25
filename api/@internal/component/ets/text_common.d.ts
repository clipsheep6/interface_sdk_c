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
 * @file
 * @kit ArkUI
 */

/**
 * Defines the text data detector type.
 *
 * @enum { number }
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @since 11
 */
/**
 * Defines the text data detector type.
 *
 * @enum { number }
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @atomicservice
 * @since 12
 */
declare enum TextDataDetectorType {
  /**
   * Detector type phone number.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 11
   */  
  /**
   * Detector type phone number.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @atomicservice
   * @since 12
   */   
  PHONE_NUMBER = 0,

  /**
   * Detector type URL.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 11
   */ 
  /**
   * Detector type URL.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @atomicservice
   * @since 12
   */
  URL = 1,

  /**
   * Detector type email.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 11
   */ 
  /**
   * Detector type email.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @atomicservice
   * @since 12
   */ 
  EMAIL = 2,

  /**
   * Detector type address.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 11
   */
  /**
   * Detector type address.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @atomicservice
   * @since 12
   */
  ADDRESS = 3,
}
  
/**
 * Text data detector config.
 *
 * @interface TextDataDetectorConfig
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @since 11
 */
/**
 * Text data detector config.
 *
 * @interface TextDataDetectorConfig
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @atomicservice
 * @since 12
 */
declare interface TextDataDetectorConfig {
  /**
   * Text data detector types.
   *
   * @type { TextDataDetectorType[] }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 11
   */
  /**
   * Text data detector types.
   *
   * @type { TextDataDetectorType[] }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @atomicservice
   * @since 12
   */
  types: TextDataDetectorType[]

  /**
   * Text data detect result callback.
   *
   * @type { ?function }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 11
   */
  /**
   * Text data detect result callback.
   *
   * @type { ?function }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @atomicservice
   * @since 12
   */
  onDetectResultUpdate?: (result: string) => void
}

/**
 * Defines the cursor style
 *
 * @interface CaretStyle
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @since 10
 */
/**
 * Defines the cursor style
 *
 * @interface CaretStyle
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @atomicservice
 * @since 11
 */
interface CaretStyle {
  /**
   * Set the cursor width
   *
   * @type { ?Length }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  /**
   * Set the cursor width
   *
   * @type { ?Length }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @atomicservice
   * @since 11
   */
  width?: Length,

  /**
   * Set the cursor color
   *
   * @type { ?ResourceColor }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  /**
   * Set the cursor color
   *
   * @type { ?ResourceColor }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @atomicservice
   * @since 11
   */
  color?: ResourceColor,
}