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
 * Provides an interface for generating QR codes.
 * @since 7
 */
/**
 * Provides an interface for generating QR codes.
 * @form
 * @since 9
 */
/**
 * Provides an interface for generating QR codes.
 * @form
 * @crossplatform
 * @since 10
 */
interface QRCodeInterface {
  /**
   * Called when a QR code is set.
   * @since 7
   */
  /**
   * Called when a QR code is set.
   * @form
   * @since 9
   */
  /**
   * Called when a QR code is set.
   * @form
   * @crossplatform
   * @since 10
   */
  (value: string): QRCodeAttribute;
}

/**
 * Defines the qrcode attribute functions.
 * @since 7
 */
/**
 * Defines the qrcode attribute functions.
 * @form
 * @since 9
 */
/**
 * Defines the qrcode attribute functions.
 * @form
 * @crossplatform
 * @since 10
 */
declare class QRCodeAttribute extends CommonMethod<QRCodeAttribute> {
  /**
   * Called when the QR code color is set.
   * @since 7
   */
  /**
   * Called when the QR code color is set.
   * @form
   * @since 9
   */
  /**
   * Called when the QR code color is set.
   * @form
   * @crossplatform
   * @since 10
   */
  color(value: ResourceColor): QRCodeAttribute;

  /**
   * Called when setting the QR code background color.
   * @since 7
   */
  /**
   * Called when setting the QR code background color.
   * @form
   * @since 9
   */
  /**
   * Called when setting the QR code background color.
   * @form
   * @crossplatform
   * @since 10
   */
  backgroundColor(value: ResourceColor): QRCodeAttribute;

  /**
   * Set the opacity of the QR code content color.
   * @param { number | Resource } value - indicates the opacity of the QR code content color. The value is between 0 and 1, with a default value of 1.
   * @returns { QRCodeAttribute } the attribute of the QR code
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 11
   */
  contentOpacity(value: number | Resource): QRCodeAttribute;
}

/**
 * Defines QRCode Component.
 * @since 7
 */
/**
 * Defines QRCode Component.
 * @form
 * @since 9
 */
/**
 * Defines QRCode Component.
 * @form
 * @crossplatform
 * @since 10
 */
declare const QRCode: QRCodeInterface;

/**
 * Defines QRCode Component instance.
 * @since 7
 */
/**
 * Defines QRCode Component instance.
 * @form
 * @since 9
 */
/**
 * Defines QRCode Component instance.
 * @form
 * @crossplatform
 * @since 10
 */
declare const QRCodeInstance: QRCodeAttribute;
