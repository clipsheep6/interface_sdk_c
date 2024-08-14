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
 * Define options used to construct a row.
 *
 * @interface RowOptions
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @form
 * @atomicservice
 * @since 13
 */
declare interface RowOptions {
  /**
   * Row spacing.
   *
   * @type { ?(string | number) }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 7
   */
  /**
   * Row spacing.
   *
   * @type { ?(string | number) }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @form
   * @since 9
   */
  /**
   * Row spacing.
   *
   * @type { ?(string | number) }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @form
   * @since 10
   */
  /**
   * Row spacing.
   *
   * @type { ?(string | number) }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @form
   * @atomicservice
   * @since 11
   */
  space?: string | number;
}

/**
 * The components are laid out horizontally
 *
 * @interface RowInterface
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @since 7
 */
/**
 * The components are laid out horizontally
 *
 * @interface RowInterface
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @form
 * @since 9
 */
/**
 * The components are laid out horizontally
 *
 * @interface RowInterface
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @form
 * @since 10
 */
/**
 * The components are laid out horizontally
 *
 * @interface RowInterface
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @form
 * @atomicservice
 * @since 11
 */
interface RowInterface {
  /**
   * Called when the layout is set in the horizontal direction.
   *
   * @param { object } value
   * @returns { RowAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 7
   */
  /**
   * Called when the layout is set in the horizontal direction.
   *
   * @param { object } value
   * @returns { RowAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @form
   * @since 9
   */
  /**
   * Called when the layout is set in the horizontal direction.
   *
   * @param { object } value
   * @returns { RowAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @form
   * @since 10
   */
  /**
   * Called when the layout is set in the horizontal direction.
   *
   * @param { object } value
   * @returns { RowAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @form
   * @atomicservice
   * @since 11
   */
  /**
   * Called when the layout is set in the horizontal direction.
   *
   * @param { ?RowOptions } options - row options
   * @returns { RowAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @form
   * @atomicservice
   * @since 13
   */
  (options?: RowOptions): RowAttribute;
}

/**
 * Defines the row attribute functions.
 *
 * @extends CommonMethod<RowAttribute>
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @since 7
 */
/**
 * Defines the row attribute functions.
 *
 * @extends CommonMethod<RowAttribute>
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @form
 * @since 9
 */
/**
 * Defines the row attribute functions.
 *
 * @extends CommonMethod<RowAttribute>
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @form
 * @since 10
 */
/**
 * Defines the row attribute functions.
 *
 * @extends CommonMethod<RowAttribute>
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @form
 * @atomicservice
 * @since 11
 */
declare class RowAttribute extends CommonMethod<RowAttribute> {
  /**
   * Called when the vertical alignment is set.
   *
   * @param { VerticalAlign } value
   * @returns { RowAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 7
   */
  /**
   * Called when the vertical alignment is set.
   *
   * @param { VerticalAlign } value
   * @returns { RowAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @form
   * @since 9
   */
  /**
   * Called when the vertical alignment is set.
   *
   * @param { VerticalAlign } value
   * @returns { RowAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @form
   * @since 10
   */
  /**
   * Called when the vertical alignment is set.
   *
   * @param { VerticalAlign } value
   * @returns { RowAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @form
   * @atomicservice
   * @since 11
   */
  alignItems(value: VerticalAlign): RowAttribute;

  /**
   * Called when the horizontal alignment is set.
   *
   * @param { FlexAlign } value
   * @returns { RowAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 8
   */
  /**
   * Called when the horizontal alignment is set.
   *
   * @param { FlexAlign } value
   * @returns { RowAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @form
   * @since 9
   */
  /**
   * Called when the horizontal alignment is set.
   *
   * @param { FlexAlign } value
   * @returns { RowAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @form
   * @since 10
   */
  /**
   * Called when the horizontal alignment is set.
   *
   * @param { FlexAlign } value
   * @returns { RowAttribute }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @form
   * @atomicservice
   * @since 11
   */
  justifyContent(value: FlexAlign): RowAttribute;
  /**
   * Defines the PointLight
   *
   * @param { PointLightStyle } value - The point light style.
   * @returns { RowAttribute } The attribute of the row.
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @systemapi
   * @since 11
   */
  pointLight(value: PointLightStyle): RowAttribute;
}

/**
 * Defines Row Component.
 *
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @since 7
 */
/**
 * Defines Row Component.
 *
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @form
 * @since 9
 */
/**
 * Defines Row Component.
 *
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @form
 * @since 10
 */
/**
 * Defines Row Component.
 *
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @form
 * @atomicservice
 * @since 11
 */
declare const Row: RowInterface;

/**
 * Defines Row Component instance.
 *
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @since 7
 */
/**
 * Defines Row Component instance.
 *
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @form
 * @since 9
 */
/**
 * Defines Row Component instance.
 *
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @form
 * @since 10
 */
/**
 * Defines Row Component instance.
 *
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @form
 * @atomicservice
 * @since 11
 */
declare const RowInstance: RowAttribute;
