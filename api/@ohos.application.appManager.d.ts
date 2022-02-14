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

import { AsyncCallback } from './basic';
import ApplicationStateObserver from './application/ApplicationStateObserver';
import AppStateData from './application/AppStateData';
import { ProcessRunningInfo } from './application/ProcessRunningInfo';

/**
 * This module provides the function of app manager service.
 *
 * @since 8
 * @SysCap SystemCapability.Ability.AbilityRuntime.Core
 * @import import appManager from '@ohos.application.appManager'
 * @permission N/A
 */
declare namespace appManager {
    /**
     * Register application state observer.
     *
     * @default -
     * @since 8
     * @SysCap SystemCapability.Ability.AbilityRuntime.Core
     * @param observer The application state observer.
     * @return Returns the number code of the observer.
     */
    function registerApplicationStateObserver(observer: ApplicationStateObserver): number;

    /**
     * Unregister application state observer.
     *
     * @since 8
     * @SysCap SystemCapability.Ability.AbilityRuntime.Core
     * @param observerId Indicates the number code of the observer.
     * @return -
     */
    function unregisterApplicationStateObserver(observerId: number,  callback: AsyncCallback<void>): void;
    function unregisterApplicationStateObserver(observerId: number): Promise<void>;

    /**
     * getForegroundApplications.
     *
     * @since 8
     * @SysCap SystemCapability.Ability.AbilityRuntime.Core
     * @return Returns the list of AppStateData.
     */
     function getForegroundApplications(callback: AsyncCallback<Array<AppStateData>>): void;
     function getForegroundApplications(): Promise<Array<AppStateData>>;

    /**
     * Kill process with account.
     *
     * @since 8
     * @SysCap SystemCapability.Ability.AbilityRuntime.Core
     * @param bundleName The process bundle name.
     * @param accountId The account id.
     * @systemapi hide this for inner system use
     * @return -
     */
    function killProcessWithAccount(bundleName: string, accountId: number): Promise<void>;
    function killProcessWithAccount(bundleName: string, accountId: number, callback: AsyncCallback<void>): void;

     /**
     * Is user running in stability test.
     *
     * @since 8
     * @SysCap SystemCapability.Ability.AbilityRuntime.Core
     * @return Returns true if user is running stability test.
     */
      function isRunningInStabilityTest(callback: AsyncCallback<boolean>): void;
      function isRunningInStabilityTest(): Promise<boolean>;

    /**
    * Get information about running processes
    *
    * @since 8
    * @SysCap SystemCapability.Ability.AbilityRuntime.Core
    * @systemapi Hide this for inner system use.
    * @return -
    */
    function getProcessRunningInfos(): Promise<Array<ProcessRunningInfo>>;
    function getProcessRunningInfos(callback: AsyncCallback<Array<ProcessRunningInfo>>): void;

    /**
     * Kill processes by bundle name
     * @since 8
     * @SysCap SystemCapability.Appexecfwk
     * @devices phone, tablet, tv, wearable, car
     * @param bundleName bundle name.
     * @permission ohos.permission.DELETE_MISSIONS
     * @systemapi hide this for inner system use
     */
     function killProcessesByBundleName(bundleName: string): Promise<void>;
     function killProcessesByBundleName(bundleName: string, callback: AsyncCallback<void>);

    /**
     * Clear up application data by bundle name
     * @since 8
     * @SysCap SystemCapability.Appexecfwk
     * @devices phone, tablet, tv, wearable, car
     * @param bundleName bundle name.
     * @permission ohos.permission.DELETE_MISSIONS
     * @systemapi hide this for inner system use
     */
     function clearUpApplicationData(bundleName: string): Promise<void>;
     function clearUpApplicationData(bundleName: string, callback: AsyncCallback<void>);
}

export default appManager;
