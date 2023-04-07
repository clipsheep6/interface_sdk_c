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
 * Defines the struct of TimePickerResult.
 * @since 8
 */
declare interface TimePickerResult {
  /**
   * Application hour
   * @since 8
   */
  hour?: number;

  /**
   * Application minute
   * @since 8
   */
  minute?: number;
}

/**
 * Defines the options of TimePicker.
 * @since 8
 */
declare interface TimePickerOptions {
  /**
   * Specifies the time selector check time.
   */
  selected?: Date;
}

/**
 * Defines the TimePicker Component.
 * @since 8
 */
interface TimePickerInterface {
  /**
   * Defines the TimePicker constructor.
   * @since 8
   */
  (options?: TimePickerOptions): TimePickerAttribute;
}

/**
 * Defines the TimePicker attribute functions.
 * @since 8
 */
declare class TimePickerAttribute extends CommonMethod<TimePickerAttribute> {
  /**
   * Time Selector: indicates whether to display the 24-hour clock.
   * @since 8
   */
  useMilitaryTime(value: boolean): TimePickerAttribute;

  /**
   * Sets the text style of disappearing items
   * @param { PickerTextStyle } value - indicates the text style of disappearing items.
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 10
   */
  disappearTextStyle(value: PickerTextStyle): TimePickerAttribute;

  /**
   * Sets the text style of normal items
   * @param { PickerTextStyle } value - indicates the text style of normal items.
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 10
   */
  textStyle(value: PickerTextStyle): TimePickerAttribute;
  
  /**
   * Sets the text style of selected items
   * @param { PickerTextStyle } value - indicates the text style of selected items.
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 10
   */
  selectedTextStyle(value: PickerTextStyle): TimePickerAttribute;
 
  /**
   * This event is triggered when a TimePicker time is selected.
   * @since 8
   */
  onChange(callback: (value: TimePickerResult) => void): TimePickerAttribute;
}

/**
 * Defines the TimePickerDialogOptions for Data Picker Dialog.
 * @since 8
 */
declare interface TimePickerDialogOptions extends TimePickerOptions {
  /**
   * Time Selector: indicates whether to display the 24-hour clock.
   * @since 8
   */
  useMilitaryTime?: boolean;
  /**
   * Text style of disappearing items
   * @type { PickerTextStyle }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 10
   */
  disappearTextStyle?: PickerTextStyle;
  /**
   * Text style of normal items
   * @type { PickerTextStyle }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 10
   */
  textStyle?: PickerTextStyle;
  /**
   * Text style of selected items
   * @type { PickerTextStyle }
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @since 10
   */
  selectedTextStyle?: PickerTextStyle;
  /**
   * Called when the OK button in the dialog is clicked.
   * @since 8
   */
  onAccept?: (value: TimePickerResult) => void;
  /**
   * Called when the Cancel button in the dialog is clicked.
   * @since 8
   */
  onCancel?: () => void;
  /**
   * This event is triggered when a TimePicker Time or time is selected in dialog.
   * @since 8
   */
  onChange?: (value: TimePickerResult) => void;
}

/**
 * Defines TimePickerDialog which uses show method to show TimePicker dialog.
 * @since 8
 */
declare class TimePickerDialog {
  /**
   * Invoking method display.
   * @since 8
   */
  static show(options?: TimePickerDialogOptions);
}

/**
 * Defines TimePicker Component.
 * @since 8
 */
declare const TimePicker: TimePickerInterface;

/**
 * Defines TimePicker Component instance.
 * @since 8
 */
declare const TimePickerInstance: TimePickerAttribute;
