/*
 * Copyright (c) 2023 Huawei Device Co., Ltd.
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
 * Used to do observer layout and draw event for component.
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @crossplatform
 * @since 10
 */
declare namespace inspector {

  /**
   * The ComponentObserver is used to listen for layout and draw events.
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  interface ComponentObserver {

    /**
     * Registers a callback with the corresponding query condition by using the handle.
     * This callback is triggered when the component layout complete.
     * @param { string } type - type of the listened event.
     * @param { ()=>void } callback - callback of the listened event.
     * @syscap SystemCapability.ArkUI.ArkUI.Full
     * @crossplatform
     * @since 10
     */
    on(type: 'layout', callback: () => void): void;

    /**
     * Deregisters a callback with the corresponding query condition by using the handle.
     * This callback is not triggered when the component layout complete.
     * @param { string } type - type of the listened event.
     * @param { ()=>void } callback - callback of the listened event.
     * @syscap SystemCapability.ArkUI.ArkUI.Full
     * @crossplatform
     * @since 10
     */
    off(type: 'layout', callback?: () => void): void;

    /**
     * Registers a callback with the corresponding query condition by using the handle.
     * This callback is triggered when the component draw complete.
     * @param { string } type - type of the listened event.
     * @param { ()=>void } callback - callback of the listened event.
     * @syscap SystemCapability.ArkUI.ArkUI.Full
     * @crossplatform
     * @since 10
     */
    on(type: 'draw', callback: () => void): void;

    /**
     * Deregisters a callback with the corresponding query condition by using the handle.
     * This callback is not triggered when the component draw complete.
     * @param { string } type - type of the listened event.
     * @param { ()=>void } callback - callback of the listened event.
     * @syscap SystemCapability.ArkUI.ArkUI.Full
     * @crossplatform
     * @since 10
     */
    off(type: 'draw', callback?: () => void): void;
  }

  /**
   * Sets the component after layout or draw criteria and returns the corresponding listening handle
   * @param { string } id - component id.
   * @returns { ComponentObserver } create listener for observer component event.
   * @syscap SystemCapability.ArkUI.ArkUI.Full
   * @crossplatform
   * @since 10
   */
  function createComponentObserver(id: string): ComponentObserver;
}

export default inspector;
