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
 * Defines range of text type component.
 *
 * @interface TextRange
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @since 12
 */
declare interface TextRange {
  /**
   * Start offset.
   *
   * @type { ?number }
   * @default 0
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 12
   */
  start?: number;

  /**
   * End offset.
   *
   * @type { ?number }
   * @default text length
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 12
   */
  end?: number;
}

/**
 * Defines the inserted text value info.
 *
 * @interface InsertValue
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @since 12
 */
declare interface InsertValue {
  /**
   * The location info where the value will be inserted.
   *
   * @type { number }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 12
   */
  insertOffset: number;

  /**
   * The inserted value.
   *
   * @type { string }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 12
   */
  insertValue: string;
}

/**
 * Defines delete text direction.
 *
 * @enum { number }
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @since 12
 */
declare enum TextDeleteDirection {
  /**
   * Delete backward.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 12
   */
  BACKWARD = 0,

  /**
   * Delete forward.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 12
   */
  FORWARD = 1,
}

/**
 * Provides an interface for deleting value from text.
 *
 * @interface DeleteValue
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @since 12
 */
declare interface DeleteValue {
  /**
   * The location info where the value will be deleted.
   *
   * @type { number }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 12
   */
  deleteOffset: number;

  /**
   * The deleted direction.
   *
   * @type { TextDeleteDirection }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 12
   */
  direction: TextDeleteDirection;

  /**
   * The deleted value.
   *
   * @type { string }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 12
   */
  deleteValue: string;
}

/**
 * Callback after content changed.
 * 
 * @typedef { function } OnDidChangeCallback
 * @param { TextRange } rangeBefore - Range of content that had been replaced.
 * @param { TextRange } rangeAfter - Range of content that newly added.
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @since 12
 */
declare type OnDidChangeCallback = (rangeBefore: TextRange, rangeAfter: TextRange) => void;

/**
 * Define the text selection controller.
 *
 * @interface TextBaseController
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @since 12
 */
declare interface TextBaseController {
  /**
   * Set selection to select a range of content.
   *
   * @param { number } selectionStart - The start position of the selected text.
   * @param { number } selectionEnd - The end position of the selected text.
   * @param { SelectionOptions } [options] - Indicates the options of selection.
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 12
   */
  setSelection(selectionStart: number, selectionEnd: number, options?: SelectionOptions): void;

  /**
   * Close the select menu when menu is on.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 12
   */
  closeSelectionMenu(): void;

  /**
   * Get LayoutManager.
   *
   * @returns { LayoutManager } - Return the LayoutManager.
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @atomicservice
   * @since 12
   */
  getLayoutManager(): LayoutManager;
}

/**
 * Define the text extended editing controller.
 *
 * @interface TextEditControllerEx
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @since 12
 */
declare interface TextEditControllerEx extends TextBaseController{
  /**
   * Judge whether is in editing state
   * 
   * @returns { boolean } - true means that the component is in editing state, false means is non in editing status
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 12
   */
  isEditing(): boolean;

  /**
   * Stop editing state.
   *
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 12
   */
  stopEditing(): void;

  /**
   * Set caret offset.
   *
   * @param { number } offset - caret offset.
   * @returns { boolean } - Return true if the caret offset was successfully set, false otherwise.
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 12
   */
  setCaretOffset(offset: number): boolean;

  /**
   * Get caret offset from controller.
   *
   * @returns { number }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 12
   */
  getCaretOffset(): number;
}

/**
 * Define the StyledString controller.
 *
 * @interface StyledStringController
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @since 12
 */
declare interface StyledStringController {
  /**
   * Set the StyledString of the component.
   *
   * @param { StyledString } styledString - StyledString.
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 12
   */
  setStyledString(styledString: StyledString): void;

  /**
   * Get the StyledString of the component.
   *
   * @returns { MutableStyledString }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 12
   */
  getStyledString(): MutableStyledString;
}

/**
 * Define the StyledString changed listener.
 *
 * @interface StyledStringChangedListener
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @since 12
 */
declare interface StyledStringChangedListener {
  /**
   * Called before text changed.
   *
   * @type { ?Callback<StyledStringChangeValue, boolean> }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 12
   */
  onWillChange?: Callback<StyledStringChangeValue, boolean>;

  /**
   * Called after text changed.
   *
   * @type { ?OnDidChangeCallback }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 12
   */
  onDidChange?: OnDidChangeCallback;
}

/**
 * Define the StyledString changed value.
 *
 * @interface StyledStringChangeValue
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @since 12
 */
interface StyledStringChangeValue {
  /**
   * Range of the content to be replaced.
   *
   * @type { TextRange }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 12
   */
  range: TextRange;

  /**
   * StyledString to replace.
   *
   * @type { StyledString }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 12
   */
  replacementString: StyledString;

  /**
   * Preview StyledString
   *
   * @type { ?StyledString }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @atomicservice
   * @since 12
   */
  previewText?: StyledString;
}

/**
 * Define the LayoutManager for querying layout information.
 *
 * @interface LayoutManager
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @atomicservice
 * @since 12
 */
declare interface LayoutManager {
  /**
   * Get the line count.
   * 
   * @returns { number } The line count value returned to the caller.
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @atomicservice
   * @since 12
   */
  getLineCount(): number;

  /**
   * Get the glyph position at coordinate.
   * 
   * @param { number } x - the positionX of typography.
   * @param { number } y - the positionY of typography.
   * @returns { PositionWithAffinity } TextBlob object.
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @atomicservice
   * @since 12
   */
  getGlyphPositionAtCoordinate(x: number, y: number): PositionWithAffinity;

  /**
   * Get LineMetrics.
   * 
   * @param { number } lineNumber - the number of line.
   * @returns { LineMetrics } The line Metrics.
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @atomicservice
   * @since 12
   */
  getLineMetrics(lineNumber: number): LineMetrics;
}

/**
 * Position and affinity.
 * 
 * @typedef PositionWithAffinity
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @atomicservice
 * @since 12
 */
interface PositionWithAffinity {
  /**
   * Position of text.
   * 
   * @type { number }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @atomicservice
   * @since 12
   */
  position: number;

  /**
   * Affinity of text.
   * 
   * @type { Affinity }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @atomicservice
   * @since 12
   */
  affinity: Affinity;
}

/**
 * Define the Affinity type.
 * 
 * @typedef { import('../api/@ohos.graphics.text').default.Affinity } Affinity
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @atomicservice
 * @since 12
 */
declare type Affinity = import('../api/@ohos.graphics.text').default.Affinity;

/**
 * Define the LineMetrics type.
 * 
 * @typedef { import('../api/@ohos.graphics.text').default.LineMetrics } LineMetrics
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @atomicservice
 * @since 12
 */
declare type LineMetrics = import('../api/@ohos.graphics.text').default.LineMetrics; 

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

/**
 * ExpandedMenuItemOptions
 *
 * @interface ExpandedMenuItemOptions
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @atomicservice
 * @since 12
 */
declare interface ExpandedMenuItemOptions {
  /**
   * Customize what the menu displays.
   *
   * @type { ResourceStr }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @atomicservice
   * @since 12
   */
  content: ResourceStr;
  /**
   * Customize the icon before the menu displays content.
   *
   * @type { ?ResourceStr }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @atomicservice
   * @since 12
   */
  startIcon?: ResourceStr;
  /**
   * Get the selected text information.
   *
   * @type { Callback<TextRange> }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @atomicservice
   * @since 12
   */
  action: Callback<TextRange>;
}