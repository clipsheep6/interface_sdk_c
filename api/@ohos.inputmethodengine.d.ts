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

import {AsyncCallback} from './basic';
import InputMethodSubtype from './@ohos.inputMethodSubtype';

/**
 * Input method engine
 *
 * @since 8
 * @syscap SystemCapability.MiscServices.InputMethodFramework
 */
declare namespace inputMethodEngine {
    /**
     * @since 8
     * @syscap SystemCapability.MiscServices.InputMethodFramework
     */
    const ENTER_KEY_TYPE_UNSPECIFIED: number;

    /**
     * @since 8
     * @syscap SystemCapability.MiscServices.InputMethodFramework
     */
    const ENTER_KEY_TYPE_GO: number;

    /**
     * @since 8
     * @syscap SystemCapability.MiscServices.InputMethodFramework
     */
    const ENTER_KEY_TYPE_SEARCH: number;

    /**
     * @since 8
     * @syscap SystemCapability.MiscServices.InputMethodFramework
     */
    const ENTER_KEY_TYPE_SEND: number;

    /**
     * @since 8
     * @syscap SystemCapability.MiscServices.InputMethodFramework
     */
    const ENTER_KEY_TYPE_NEXT: number;

    /**
     * @since 8
     * @syscap SystemCapability.MiscServices.InputMethodFramework
     */
    const ENTER_KEY_TYPE_DONE: number;

    /**
     * @since 8
     * @syscap SystemCapability.MiscServices.InputMethodFramework
     */
    const ENTER_KEY_TYPE_PREVIOUS: number;

    /**
     * @since 8
     * @syscap SystemCapability.MiscServices.InputMethodFramework
     */
    const PATTERN_NULL: number;

    /**
     * @since 8
     * @syscap SystemCapability.MiscServices.InputMethodFramework
     */
    const PATTERN_TEXT: number;

    /**
     * @since 8
     * @syscap SystemCapability.MiscServices.InputMethodFramework
     */
    const PATTERN_NUMBER: number;

    /**
     * @since 8
     * @syscap SystemCapability.MiscServices.InputMethodFramework
     */
    const PATTERN_PHONE: number;

    /**
     * @since 8
     * @syscap SystemCapability.MiscServices.InputMethodFramework
     */
    const PATTERN_DATETIME: number;

    /**
     * @since 8
     * @syscap SystemCapability.MiscServices.InputMethodFramework
     */
    const PATTERN_EMAIL: number;

    /**
     * @since 8
     * @syscap SystemCapability.MiscServices.InputMethodFramework
     */
    const PATTERN_URI: number;

    /**
     * @since 8
     * @syscap SystemCapability.MiscServices.InputMethodFramework
     */
    const PATTERN_PASSWORD: number;

    /**
     * @since 8
     * @syscap SystemCapability.MiscServices.InputMethodFramework
     */
    const FLAG_SELECTING: number;

    /**
     * @since 8
     * @syscap SystemCapability.MiscServices.InputMethodFramework
     */
    const FLAG_SINGLE_LINE: number;

    /**
     * @since 8
     * @syscap SystemCapability.MiscServices.InputMethodFramework
     */
    const DISPLAY_MODE_PART: number;

    /**
     * @since 8
     * @syscap SystemCapability.MiscServices.InputMethodFramework
     */
    const DISPLAY_MODE_FULL: number;

    /**
     * @since 8
     * @syscap SystemCapability.MiscServices.InputMethodFramework
     */
    const OPTION_ASCII: number;

    /**
     * @since 8
     * @syscap SystemCapability.MiscServices.InputMethodFramework
     */
    const OPTION_NONE: number;

    /**
     * @since 8
     * @syscap SystemCapability.MiscServices.InputMethodFramework
     */
    const OPTION_AUTO_CAP_CHARACTERS: number;

    /**
     * @since 8
     * @syscap SystemCapability.MiscServices.InputMethodFramework
     */
    const OPTION_AUTO_CAP_SENTENCES: number;

    /**
     * @since 8
     * @syscap SystemCapability.MiscServices.InputMethodFramework
     */
    const OPTION_AUTO_WORDS: number;

    /**
     * @since 8
     * @syscap SystemCapability.MiscServices.InputMethodFramework
     */
    const OPTION_MULTI_LINE: number;

    /**
     * @since 8
     * @syscap SystemCapability.MiscServices.InputMethodFramework
     */
    const OPTION_NO_FULLSCREEN: number;

    /**
     * The move direction of cursor: UP
     * @since 9
     * @syscap SystemCapability.MiscServices.InputMethodFramework
     */
    const CURSOR_UP: number;

    /**
     * The move direction of cursor: DOWN
     * @since 9
     * @syscap SystemCapability.MiscServices.InputMethodFramework
     */
    const CURSOR_DOWN: number;

    /**
     * The move direction of cursor: LEFT
     * @since 9
     * @syscap SystemCapability.MiscServices.InputMethodFramework
     */
    const CURSOR_LEFT: number;

    /**
     * The move direction of cursor: RIGHT
     * @since 9
     * @syscap SystemCapability.MiscServices.InputMethodFramework
     */
    const CURSOR_RIGHT: number;

    /**
     * The window styles for input method ability.
     * @since 9
     * @syscap SystemCapability.MiscServices.InputMethodFramework
     */
    const WINDOW_TYPE_INPUT_METHOD_FLOAT: number;

    /**
     * @since 9
     * @return InputMethodAbility object of the current input method
     * @throws {BusinessError} 401 - permissions check fails.
     * @throws {BusinessError} 201 - parameter error.
     * @throws {BusinessError} 801 - call unsupported api.
     * @throws {BusinessError} 12800002 - input method engine error.
     * @syscap SystemCapability.MiscServices.InputMethodFramework
     */
    function getInputMethodAbility(): InputMethodAbility;

    /**
     * @since 8
     * @deprecated since 9
     * @useinstead ohos.inputmethodengine.getInputMethodAbility
     */
    function getInputMethodEngine(): InputMethodEngine;

    /**
     * @since 9
     * @return KeyboardDelegate object of the current input method
     * @throws {BusinessError} 401 - permissions check fails.
     * @throws {BusinessError} 201 - parameter error.
     * @throws {BusinessError} 12800002 - input method engine error.
     * @syscap SystemCapability.MiscServices.InputMethodFramework
     */
    function getKeyboardDelegate(): KeyboardDelegate;

    /**
     * @since 8
     * @deprecated since 9
     * @useinstead ohos.inputmethodengine.getKeyboardDelegate
     */
    function createKeyboardDelegate(): KeyboardDelegate;

    /**
     * @since 8
     */
    interface KeyboardController {
        /**
         * @since 9
         * @throws {BusinessError} 401 - permissions check fails.
         * @throws {BusinessError} 201 - parameter error.
         * @throws {BusinessError} 12800002 - input method engine error.
         * @throws {BusinessError} 12800008 - input method manager service error.
         * @syscap SystemCapability.MiscServices.InputMethodFramework
         */
        hide(callback: AsyncCallback<void>): void;

        /**
         * @since 9
         * @throws {BusinessError} if exception occurs
         * @throws {BusinessError} 401 - permissions check fails.
         * @throws {BusinessError} 201 - parameter error.
         * @throws {BusinessError} 12800002 - input method engine error.
         * @throws {BusinessError} 12800008 - input method manager service error.
         * @syscap SystemCapability.MiscServices.InputMethodFramework
         */
        hide(): Promise<void>;

        /**
         * @since 8
         * @deprecated since 9
         * @useinstead ohos.inputmethodengine.KeyboardController.hide
         */
        hideKeyboard(callback: AsyncCallback<void>): void;

        /**
         * @since 8
         * @deprecated since 9
         * @useinstead ohos.inputmethodengine.KeyboardController.hide
         */
        hideKeyboard(): Promise<void>;
    }

    /**
     * @since 8
     */
    interface InputMethodEngine {
        /**
         * Subscribe 'inputStart'
         * @since 8
         * @param type inputStart
         * @param callback give keyboard controller and text input client
         * @return :-
         */
        on(type: 'inputStart', callback: (kbController: KeyboardController, textInputClient: TextInputClient) => void): void;

        /**
         * Unsubscribe 'inputStart'
         * @since 8
         * @param type inputStart
         * @param callback optional, give keyboard controller and text input client
         * @return :-
         */
        off(type: 'inputStart', callback?: (kbController: KeyboardController, textInputClient: TextInputClient) => void): void;

        /**
         * Subscribe 'keyboardShow'|'keyboardHide'
         * @since 8
         * @param type keyboardShow|keyboardHide
         * @return :-
         */
        on(type: 'keyboardShow'|'keyboardHide', callback: () => void): void;

        /**
         * Unsubscribe 'keyboardShow'|'keyboardHide'
         * @since 8
         * @param type keyboardShow|keyboardHide
         * @return :-
         */
        off(type: 'keyboardShow'|'keyboardHide', callback?: () => void): void;
    }

    /**
     * @since 9
     * @syscap SystemCapability.MiscServices.InputMethodFramework
     */
     interface InputMethodAbility {
        /**
         * Subscribe 'inputStart'
         * @since 9
         * @param type inputStart
         * @param callback give keyboard controller and text input client
         * @return :-
         */
        on(type: 'inputStart', callback: (kbController: KeyboardController, inputClient: InputClient) => void): void;

        /**
         * Unsubscribe 'inputStart'
         * @since 9
         * @param type inputStart
         * @param callback optional, give keyboard controller and text input client
         * @return :-
         */
        off(type: 'inputStart', callback?: (kbController: KeyboardController, inputClient: InputClient) => void): void;

        /**
         * Subscribe 'inputStop'.
         * @since 9
         * @syscap SystemCapability.MiscServices.InputMethodFramework
         * @param type inputStop
         * @return :-
         */
        on(type: 'inputStop', callback: () => void): void;

        /**
         * Unsubscribe 'inputStop'.
         * @since 9
         * @syscap SystemCapability.MiscServices.InputMethodFramework
         * @param type inputStop
         * @return :-
         */
        off(type: 'inputStop', callback: () => void): void;

        /**
         * Subscribe 'setCallingWindow'.
         * @since 9
         * @syscap SystemCapability.MiscServices.InputMethodFramework
         * @param type setCallingWindow
         * @return :-
         */
        on(type: 'setCallingWindow', callback: (wid:number) => void): void;

        /**
         * Unsubscribe 'setCallingWindow'.
         * @since 9
         * @syscap SystemCapability.MiscServices.InputMethodFramework
         * @param type setCallingWindow
         * @return :-
         */
        off(type: 'setCallingWindow', callback: (wid:number) => void): void;

        /**
         * Subscribe 'keyboardShow'|'keyboardHide'
         * @since 9
         * @param type keyboardShow|keyboardHide
         * @return :-
         */
        on(type: 'keyboardShow'|'keyboardHide', callback: () => void): void;

        /**
         * Unsubscribe 'keyboardShow'|'keyboardHide'
         * @since 9
         * @param type keyboardShow|keyboardHide
         * @return :-
         */
        off(type: 'keyboardShow'|'keyboardHide', callback?: () => void): void;

        /**
         * Subscribe 'setSubtype'
         * @since 9
         * @return :-
         * @syscap SystemCapability.MiscServices.InputMethodFramework
         */
        on(type: 'setSubtype', callback: (inputMethodSubtype: InputMethodSubtype) => void): void;

        /**
         * Unsubscribe 'setSubtype'
         * @since 9
         * @return :-
         * @syscap SystemCapability.MiscServices.InputMethodFramework
         */
        off(ype: 'setSubtype', callback?: (inputMethodSubtype: InputMethodSubtype) => void): void;
    }

    /**
     * @since 8
     * @deprecated since 9
     * @useinstead ohos.inputmethodengine.InputClient
     */
    interface TextInputClient {
        /**
         * @since 8
         * @deprecated since 9
         * @useinstead ohos.inputmethodengine.InputClient.sendKeyFunction
         */
        sendKeyFunction(action: number, callback: AsyncCallback<boolean>): void;

        /**
         * @since 8
         * @deprecated since 9
         * @useinstead ohos.inputmethodengine.InputClient.sendKeyFunction
         */
        sendKeyFunction(action: number): Promise<boolean>;

        /**
         * @since 8
         * @deprecated since 9
         * @useinstead ohos.inputmethodengine.InputClient.deleteForward
         */
        deleteForward(length: number, callback: AsyncCallback<boolean>): void;

        /**
         * @since 8
         * @deprecated since 9
         * @useinstead ohos.inputmethodengine.InputClient.deleteForward
         */
        deleteForward(length: number): Promise<boolean>;

        /**
         * @since 8
         * @deprecated since 9
         * @useinstead ohos.inputmethodengine.InputClient.deleteBackward
         */
        deleteBackward(length: number, callback: AsyncCallback<boolean>): void;

        /**
         * @since 8
         * @deprecated since 9
         * @useinstead ohos.inputmethodengine.InputClient.deleteBackward
         */
        deleteBackward(length: number): Promise<boolean>;

        /**
         * @since 8
         * @deprecated since 9
         * @useinstead ohos.inputmethodengine.InputClient.insertText
         */
        insertText(text: string, callback: AsyncCallback<boolean>): void;

        /**
         * @since 8
         * @deprecated since 9
         * @useinstead ohos.inputmethodengine.InputClient.insertText
         */
        insertText(text: string): Promise<boolean>;

        /**
         * @since 8
         * @deprecated since 9
         * @useinstead ohos.inputmethodengine.InputClient.getForward
         */
        getForward(length: number, callback: AsyncCallback<string>): void;

        /**
         * @since 8
         * @deprecated since 9
         * @useinstead ohos.inputmethodengine.InputClient.getForward
         */
        getForward(length: number): Promise<string>;

        /**
         * @since 8
         * @deprecated since 9
         * @useinstead ohos.inputmethodengine.InputClient.getBackward
         */
        getBackward(length: number, callback: AsyncCallback<string>): void;

        /**
         * @since 8
         * @deprecated since 9
         * @useinstead ohos.inputmethodengine.InputClient.getBackward
         */
        getBackward(length: number): Promise<string>;

        /**
         * @since 8
         * @deprecated since 9
         * @useinstead ohos.inputmethodengine.InputClient.getEditorAttribute
         */
        getEditorAttribute(callback: AsyncCallback<EditorAttribute>): void;

        /**
         * @since 8
         * @deprecated since 9
         * @useinstead ohos.inputmethodengine.InputClient.getEditorAttribute
         */
        getEditorAttribute(): Promise<EditorAttribute>;
    }

    /**
     * @since 9
     * @syscap SystemCapability.MiscServices.InputMethodFramework
     */
     interface InputClient {
        /**
         * @since 9
         * @throws {BusinessError} 401 - permissions check fails.
         * @throws {BusinessError} 201 - parameter error.
         * @throws {BusinessError} 12800003 - input method client error.
         * @syscap SystemCapability.MiscServices.InputMethodFramework
         */
        sendKeyFunction(action: number, callback: AsyncCallback<boolean>): void;

        /**
         * @since 9
         * @throws {BusinessError} 401 - permissions check fails.
         * @throws {BusinessError} 201 - parameter error.
         * @throws {BusinessError} 12800003 - input method client error.
         * @syscap SystemCapability.MiscServices.InputMethodFramework
         */
        sendKeyFunction(action: number): Promise<boolean>;

        /**
         * @since 9
         * @throws {BusinessError} 401 - permissions check fails.
         * @throws {BusinessError} 201 - parameter error.
         * @throws {BusinessError} 12800003 - input method client error.
         * @syscap SystemCapability.MiscServices.InputMethodFramework
         */
        deleteForward(length: number, callback: AsyncCallback<boolean>): void;

        /**
         * @since 9
         * @throws {BusinessError} 401 - permissions check fails.
         * @throws {BusinessError} 201 - parameter error.
         * @throws {BusinessError} 12800003 - input method client error.
         * @syscap SystemCapability.MiscServices.InputMethodFramework
         */
        deleteForward(length: number): Promise<boolean>;

        /**
         * @since 9
         * @throws {BusinessError} 401 - permissions check fails.
         * @throws {BusinessError} 201 - parameter error.
         * @throws {BusinessError} 12800003 - input method client error.
         * @syscap SystemCapability.MiscServices.InputMethodFramework
         */
        deleteBackward(length: number, callback: AsyncCallback<boolean>): void;

        /**
         * @since 9
         * @throws {BusinessError} 401 - permissions check fails.
         * @throws {BusinessError} 201 - parameter error.
         * @throws {BusinessError} 12800003 - input method client error.
         * @syscap SystemCapability.MiscServices.InputMethodFramework
         */
        deleteBackward(length: number): Promise<boolean>;

        /**
         * @since 9
         * @throws {BusinessError} 401 - permissions check fails.
         * @throws {BusinessError} 201 - parameter error.
         * @throws {BusinessError} 12800003 - input method client error.
         * @syscap SystemCapability.MiscServices.InputMethodFramework
         */
        insertText(text: string, callback: AsyncCallback<boolean>): void;

        /**
         * @since 9
         * @throws {BusinessError} 401 - permissions check fails.
         * @throws {BusinessError} 201 - parameter error.
         * @throws {BusinessError} 12800003 - input method client error.
         * @syscap SystemCapability.MiscServices.InputMethodFramework
         */
        insertText(text: string): Promise<boolean>;

        /**
         * @since 9
         * @throws {BusinessError} 401 - permissions check fails.
         * @throws {BusinessError} 201 - parameter error.
         * @throws {BusinessError} 12800003 - input method client error.
         * @syscap SystemCapability.MiscServices.InputMethodFramework
         */
        getForward(length: number, callback: AsyncCallback<string>): void;

        /**
         * @since 9
         * @throws {BusinessError} 401 - permissions check fails.
         * @throws {BusinessError} 201 - parameter error.
         * @throws {BusinessError} 12800003 - input method client error.
         * @syscap SystemCapability.MiscServices.InputMethodFramework
         */
        getForward(length: number): Promise<string>;

        /**
         * @since 9
         * @throws {BusinessError} 401 - permissions check fails.
         * @throws {BusinessError} 201 - parameter error.
         * @throws {BusinessError} 12800003 - input method client error.
         * @syscap SystemCapability.MiscServices.InputMethodFramework
         */
        getBackward(length: number, callback: AsyncCallback<string>): void;

        /**
         * @since 9
         * @throws {BusinessError} 401 - permissions check fails.
         * @throws {BusinessError} 201 - parameter error.
         * @throws {BusinessError} 12800003 - input method client error.
         * @syscap SystemCapability.MiscServices.InputMethodFramework
         */
        getBackward(length: number): Promise<string>;

        /**
         * @since 9
         * @throws {BusinessError} 401 - permissions check fails.
         * @throws {BusinessError} 201 - parameter error.
         * @throws {BusinessError} 12800003 - input method client error.
         * @syscap SystemCapability.MiscServices.InputMethodFramework
         */
        getEditorAttribute(callback: AsyncCallback<EditorAttribute>): void;

        /**
         * @since 9
         * @throws {BusinessError} 401 - permissions check fails.
         * @throws {BusinessError} 201 - parameter error.
         * @throws {BusinessError} 12800003 - input method client error.
         * @syscap SystemCapability.MiscServices.InputMethodFramework
         */
        getEditorAttribute(): Promise<EditorAttribute>;

        /**
         * Move cursor from input method.
         *
         * @since 9
         * @syscap SystemCapability.MiscServices.InputMethodFramework
         * @param direction Indicates the distance of cursor to be moved.
         * @return -
         * @throws {BusinessError} 401 - permissions check fails.
         * @throws {BusinessError} 201 - parameter error.
         * @throws {BusinessError} 12800003 - input method client error.
         * @StageModelOnly
         */
        moveCursor(direction: number, callback: AsyncCallback<void>): void;

        /**
         * Move curosr from input method.
         *
         * @since 9
         * @syscap SystemCapability.MiscServices.InputMethodFramework
         * @param direction Indicates the distance of cursor to be moved.
         * @return -
         * @throws {BusinessError} 401 - permissions check fails.
         * @throws {BusinessError} 201 - parameter error.
         * @throws {BusinessError} 12800003 - input method client error.
         * @StageModelOnly
         */
        moveCursor(direction: number): Promise<void>;
    }

    /**
     * @since 8
     */
    interface KeyboardDelegate {
        /**
         * Subscribe key up or down event
         *
         * @since 8
         */
        on(type: 'keyDown'|'keyUp', callback: (event: KeyEvent) => boolean): void;

        /**
         * Unsubscribe key up or down event
         *
         * @since 8
         */
        off(type: 'keyDown'|'keyUp', callback?: (event: KeyEvent) => boolean): void;

        /**
         * Subscribe cursor context change
         *
         * @since 8
         */
        on(type: 'cursorContextChange', callback: (x: number, y: number, height: number) => void): void;

        /**
         * Unsubscribe cursor context change
         *
         * @since 8
         */
        off(type: 'cursorContextChange', callback?: (x: number, y: number, height: number) => void): void;

        /**
         * Subscribe selection change
         *
         * @since 8
         */
        on(type: 'selectionChange', callback: (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void): void;

        /**
         * Unsubscribe selection change
         *
         * @since 8
         */
        off(type: 'selectionChange', callback?: (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void): void;

        /**
         * Subscribe text change
         *
         * @since 8
         */
        on(type: 'textChange', callback: (text: string) => void): void;

        /**
         * Unsubscribe text change
         *
         * @since 8
         */
        off(type: 'textChange', callback?: (text: string) => void): void;
    }

    /**
     * @since 8
     */
    interface EditorAttribute {
        /**
         * Editor's pattern
         *
         * @since 8
         * @syscap SystemCapability.MiscServices.InputMethodFramework
         */
        readonly inputPattern: number;

        /**
         * Editor's key type
         *
         * @since 8
         * @syscap SystemCapability.MiscServices.InputMethodFramework
         */
        readonly enterKeyType: number;
    }

    /**
     * @since 8
     */
    interface KeyEvent {
        /**
         * Key code
         *
         * @since 8
         */
        readonly keyCode: number;

        /**
         * Key action
         *
         * @since 8
         */
        readonly keyAction: number;
    }
}

export default inputMethodEngine;