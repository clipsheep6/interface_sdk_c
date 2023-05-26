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
 * Content scroll direction.
 * @since 8
 */
/**
 * Content scroll direction.
 * @crossplatform
 * @since 10
 */
declare enum ScrollBarDirection {
  /**
   * Vertical scrolling is supported.
   * @since 8
   */
  /**
   * Vertical scrolling is supported.
   * @crossplatform
   * @since 10
   */
  Vertical,

  /**
   * Horizontal scrolling is supported.
   * @since 8
   */
  /**
   * Horizontal scrolling is supported.
   * @crossplatform
   * @since 10
   */
  Horizontal,
}

/**
 * Defines the options of ScrollBar.
 * @since 8
 */
/**
 * Defines the options of ScrollBar.
 * @crossplatform
 * @since 10
 */
declare interface ScrollBarOptions {
  /**
   * Sets the scroller of scroll bar.
   * @since 8
   */
  /**
   * Sets the scroller of scroll bar.
   * @crossplatform
   * @since 10
   */
  scroller: Scroller;

  /**
   * Sets the direction of scroll bar.
   * @since 8
   */
  /**
   * Sets the direction of scroll bar.
   * @crossplatform
   * @since 10
   */
  direction?: ScrollBarDirection;

  /**
   * Sets the state of scroll bar.
   * @since 8
   */
  /**
   * Sets the state of scroll bar.
   * @crossplatform
   * @since 10
   */
  state?: BarState;
}

/**
 * Provides interfaces for scroll bar.
 * @since 8
 */
/**
 * Provides interfaces for scroll bar.
 * @crossplatform
 * @since 10
 */
interface ScrollBarInterface {
  /**
   * Called when a ScrollBar container is set.
   * @since 8
   */
  /**
   * Called when a ScrollBar container is set.
   * @crossplatform
   * @since 10
   */
  (value: ScrollBarOptions): ScrollBarAttribute;
}

/**
 * Defines the scrollbar attribute functions.
 * @since 8
 */
/**
 * Defines the scrollbar attribute functions.
 * @crossplatform
 * @since 10
 */
declare class ScrollBarAttribute extends CommonMethod<ScrollBarAttribute> {}

/**
 * Defines ScrollBar Component.
 * @since 8
 */
/**
 * Defines ScrollBar Component.
 * @crossplatform
 * @since 10
 */
declare const ScrollBar: ScrollBarInterface;

/**
 * Defines ScrollBar Component instance.
 * @since 8
 */
/**
 * Defines ScrollBar Component instance.
 * @crossplatform
 * @since 10
 */
declare const ScrollBarInstance: ScrollBarAttribute;
