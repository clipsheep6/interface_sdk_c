/*
 * Copyright (c) 2022-2023 Huawei Device Co., Ltd.
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

import { AsyncCallback } from './@ohos.base';
import * as _ApplicationStateObserver from './application/ApplicationStateObserver';
import * as _AbilityStateData from './application/AbilityStateData';
import * as _AppStateData from './application/AppStateData';
import { ProcessInformation as _ProcessInformation } from './application/ProcessInformation';
import { LowMemoryObserver as _LowMemoryObserver } from './application/LowMemoryObserver';

/**
 * This module provides the function of app manager service.
 *
 * @namespace appManager
 * @syscap SystemCapability.Ability.AbilityRuntime.Core
 * @since 9
 */
declare namespace appManager {
  /**
   * Enum for the application state
   *
   * @enum { number }
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @systemapi
   * @since 9
   */
  export enum ApplicationState {
    /**
     * The state in which the application is being created.
     *
     * @syscap SystemCapability.Ability.AbilityRuntime.Core
     * @systemapi
     * @since 9
     */
    STATE_CREATE,

    /**
     * The state that the application is in when it switches to the foreground.
     *
     * @syscap SystemCapability.Ability.AbilityRuntime.Core
     * @systemapi
     * @since 9
     */
    STATE_FOREGROUND,

    /**
     * The state in which the application is in focus.
     *
     * @syscap SystemCapability.Ability.AbilityRuntime.Core
     * @systemapi
     * @since 9
     */
    STATE_ACTIVE,

    /**
     * The state in which the application is invisible in the background.
     *
     * @syscap SystemCapability.Ability.AbilityRuntime.Core
     * @systemapi
     * @since 9
     */
    STATE_BACKGROUND,

    /**
     * The state that the application is in when it is destroyed.
     *
     * @syscap SystemCapability.Ability.AbilityRuntime.Core
     * @systemapi
     * @since 9
     */
    STATE_DESTROY
  }

  /**
   * Enum for the process state
   *
   * @enum { number }
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @systemapi
   * @since 9
   */
  export enum ProcessState {
    /**
     * The state that the process is in when it is being created.
     *
     * @syscap SystemCapability.Ability.AbilityRuntime.Core
     * @systemapi
     * @since 9
     */
    STATE_CREATE,

    /**
     * The state in which the process is in when it switches to the foreground.
     *
     * @syscap SystemCapability.Ability.AbilityRuntime.Core
     * @systemapi
     * @since 9
     */
    STATE_FOREGROUND,

    /**
     * The state in which the process is in focus.
     *
     * @syscap SystemCapability.Ability.AbilityRuntime.Core
     * @systemapi
     * @since 9
     */
    STATE_ACTIVE,

    /**
     * The state in which a process is invisible in the background.
     *
     * @syscap SystemCapability.Ability.AbilityRuntime.Core
     * @systemapi
     * @since 9
     */
    STATE_BACKGROUND,

    /**
     * The state that the process is in when it is destroyed.
     *
     * @syscap SystemCapability.Ability.AbilityRuntime.Core
     * @systemapi
     * @since 9
     */
    STATE_DESTROY
  }

  /**
   * Register application state observer.
   *
   * @permission ohos.permission.RUNNING_STATE_OBSERVER
   * @param { 'applicationState' } type - applicationState.
   * @param { ApplicationStateObserver } observer - The application state observer.
   * @returns { number } Returns the number code of the observer.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 202 - Not system application.
   * @throws { BusinessError } 401 - If the input parameter is not valid parameter.
   * @throws { BusinessError } 16000050 - Internal error.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @systemapi
   * @since 9
   */
  function on(type: 'applicationState', observer: ApplicationStateObserver): number;

  /**
   * Register application state observer.
   *
   * @permission ohos.permission.RUNNING_STATE_OBSERVER
   * @param { 'applicationState' } type - applicationState.
   * @param { ApplicationStateObserver } observer - The application state observer.
   * @param { Array<string> } bundleNameList - The list of bundleName. The max length is 128.
   * @returns { number } Returns the number code of the observer.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 202 - Not system application.
   * @throws { BusinessError } 401 - If the input parameter is not valid parameter.
   * @throws { BusinessError } 16000050 - Internal error.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @systemapi
   * @since 9
   */
  function on(type: 'applicationState', observer: ApplicationStateObserver, bundleNameList: Array<string>): number;

  /**
   * Unregister application state observer.
   *
   * @permission ohos.permission.RUNNING_STATE_OBSERVER
   * @param { 'applicationState' } type - applicationState.
   * @param { number } observerId - Indicates the number code of the observer.
   * @param { AsyncCallback<void> } callback - The callback of off.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 202 - Not system application.
   * @throws { BusinessError } 401 - If the input parameter is not valid parameter.
   * @throws { BusinessError } 16000050 - Internal error.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @systemapi
   * @since 9
   */
  function off(type: 'applicationState', observerId: number, callback: AsyncCallback<void>): void;

  /**
   * Unregister application state observer.
   *
   * @permission ohos.permission.RUNNING_STATE_OBSERVER
   * @param { 'applicationState' } type - applicationState.
   * @param { number } observerId - Indicates the number code of the observer.
   * @returns { Promise<void> } The promise returned by the function.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 202 - Not system application.
   * @throws { BusinessError } 401 - If the input parameter is not valid parameter.
   * @throws { BusinessError } 16000050 - Internal error.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @systemapi
   * @since 9
   */
  function off(type: 'applicationState', observerId: number): Promise<void>;

  /**
   * getForegroundApplications.
   *
   * @permission ohos.permission.GET_RUNNING_INFO
   * @param { AsyncCallback<Array<AppStateData>> } callback - The callback is used to return the list of AppStateData.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 202 - Not system application.
   * @throws { BusinessError } 401 - If the input parameter is not valid parameter.
   * @throws { BusinessError } 16000050 - Internal error.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @systemapi
   * @since 9
   */
  function getForegroundApplications(callback: AsyncCallback<Array<AppStateData>>): void;

  /**
   * getForegroundApplications.
   *
   * @permission ohos.permission.GET_RUNNING_INFO
   * @returns { Promise<Array<AppStateData>> } Returns the list of AppStateData.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 202 - Not system application.
   * @throws { BusinessError } 16000050 - Internal error.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @systemapi
   * @since 9
   */
  function getForegroundApplications(): Promise<Array<AppStateData>>;

  /**
   * Kill process with account.
   *
   * @permission ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS and ohos.permission.CLEAN_BACKGROUND_PROCESSES
   * @param { string } bundleName - The process bundle name.
   * @param { number } accountId - The account id.
   * @returns { Promise<void> } The promise returned by the function.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 202 - Not system application.
   * @throws { BusinessError } 401 - If the input parameter is not valid parameter.
   * @throws { BusinessError } 16000050 - Internal error.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @systemapi
   * @since 9
   */
  function killProcessWithAccount(bundleName: string, accountId: number): Promise<void>;

  /**
   * Kill process with account.
   *
   * @permission ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS and ohos.permission.CLEAN_BACKGROUND_PROCESSES
   * @param { string } bundleName - The process bundle name.
   * @param { number } accountId - The account id.
   * @param { AsyncCallback<void> } callback - The callback of killProcessWithAccount.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 202 - Not system application.
   * @throws { BusinessError } 401 - If the input parameter is not valid parameter.
   * @throws { BusinessError } 16000050 - Internal error.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @systemapi
   * @since 9
   */
  function killProcessWithAccount(bundleName: string, accountId: number, callback: AsyncCallback<void>): void;

  /**
   * Is user running in stability test.
   *
   * @param { AsyncCallback<boolean> } callback - The callback is used to return true if user is running stability test.
   * @throws { BusinessError } 401 - If the input parameter is not valid parameter.
   * @throws { BusinessError } 16000050 - Internal error.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @since 9
   */
  function isRunningInStabilityTest(callback: AsyncCallback<boolean>): void;

  /**
   * Is user running in stability test.
   *
   * @returns { Promise<boolean> } Returns true if user is running stability test.
   * @throws { BusinessError } 16000050 - Internal error.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @since 9
   */
  function isRunningInStabilityTest(): Promise<boolean>;

  /**
   * Kill processes by bundle name
   *
   * @permission ohos.permission.CLEAN_BACKGROUND_PROCESSES
   * @param { string } bundleName - bundle name.
   * @returns { Promise<void> } The promise returned by the function.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 202 - Not system application.
   * @throws { BusinessError } 401 - If the input parameter is not valid parameter.
   * @throws { BusinessError } 16000050 - Internal error.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @systemapi
   * @since 9
   */
  function killProcessesByBundleName(bundleName: string): Promise<void>;

  /**
   * Kill processes by bundle name
   *
   * @permission ohos.permission.CLEAN_BACKGROUND_PROCESSES
   * @param { string } bundleName - bundle name.
   * @param { AsyncCallback<void> } callback - The callback of killProcessesByBundleName.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 202 - Not system application.
   * @throws { BusinessError } 401 - If the input parameter is not valid parameter.
   * @throws { BusinessError } 16000050 - Internal error.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @systemapi
   * @since 9
   */
  function killProcessesByBundleName(bundleName: string, callback: AsyncCallback<void>);

  /**
   * Clear up application data by bundle name
   *
   * @permission ohos.permission.CLEAN_APPLICATION_DATA
   * @param { string } bundleName - bundle name.
   * @returns { Promise<void> } The promise returned by the function.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 202 - Not system application.
   * @throws { BusinessError } 401 - If the input parameter is not valid parameter.
   * @throws { BusinessError } 16000050 - Internal error.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @systemapi
   * @since 9
   */
  function clearUpApplicationData(bundleName: string): Promise<void>;

  /**
   * Clear up application data by bundle name
   *
   * @permission ohos.permission.CLEAN_APPLICATION_DATA
   * @param { string } bundleName - bundle name.
   * @param { AsyncCallback<void> } callback - The callback of clearUpApplicationData.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 202 - Not system application.
   * @throws { BusinessError } 401 - If the input parameter is not valid parameter.
   * @throws { BusinessError } 16000050 - Internal error.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @systemapi
   * @since 9
   */
  function clearUpApplicationData(bundleName: string, callback: AsyncCallback<void>);

  /**
   * Is it a ram-constrained device
   *
   * @returns { Promise<boolean> } Returns true if the device is ram-constrained.
   * @throws { BusinessError } 16000050 - Internal error.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @since 9
   */
  function isRamConstrainedDevice(): Promise<boolean>;

  /**
   * Is it a ram-constrained device
   *
   * @param { AsyncCallback<boolean> } callback - The callback is used to return true if the device is ram-constrained.
   * @throws { BusinessError } 401 - If the input parameter is not valid parameter.
   * @throws { BusinessError } 16000050 - Internal error.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @since 9
   */
  function isRamConstrainedDevice(callback: AsyncCallback<boolean>): void;

  /**
   * Get the memory size of the application
   *
   * @returns { Promise<number> } Returns the application memory size.
   * @throws { BusinessError } 16000050 - Internal error.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @since 9
   */
  function getAppMemorySize(): Promise<number>;

  /**
   * Get the memory size of the application
   *
   * @param { AsyncCallback<number> } callback - The callback is used to return the application memory size.
   * @throws { BusinessError } 401 - If the input parameter is not valid parameter.
   * @throws { BusinessError } 16000050 - Internal error.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @since 9
   */
  function getAppMemorySize(callback: AsyncCallback<number>): void;

  /**
   * If you apply for permission, you can obtain information about all running processes.
   * If you do not apply, you can only obtain information about the current process.
   *
   * @permission ohos.permission.GET_RUNNING_INFO
   * @returns { Promise<Array<ProcessInformation>> } Returns the array of {@link ProcessInformation}.
   * @throws { BusinessError } 16000050 - Internal error.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @since 9
   */
  function getRunningProcessInformation(): Promise<Array<ProcessInformation>>;

  /**
   * If you apply for permission, you can obtain information about all running processes.
   * If you do not apply, you can only obtain information about the current process.
   *
   * @permission ohos.permission.GET_RUNNING_INFO
   * @param { AsyncCallback<Array<ProcessInformation>> } callback - The callback is used to return the array of {@link ProcessInformation}.
   * @throws { BusinessError } 401 - If the input parameter is not valid parameter.
   * @throws { BusinessError } 16000050 - Internal error.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @since 9
   */
  function getRunningProcessInformation(callback: AsyncCallback<Array<ProcessInformation>>): void;

  /**
   * Check whether the shared bundle is running.
   *
   * @permission ohos.permission.GET_RUNNING_INFO
   * @param { string } bundleName - Indicates the bundle name of the shared bundle.
   * @param { number } versionCode - Indicates the version code of the shared bundle.
   * @returns { Promise<boolean> } Returns the shared bundle running result. The result is true if running, false otherwise.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 202 - Not system application.
   * @throws { BusinessError } 401 - If the input parameter is not valid parameter.
   * @throws { BusinessError } 16000050 - Internal error.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @systemapi
   * @since 10
   */
  function isSharedBundleRunning(bundleName: string, versionCode: number): Promise<boolean>;

  /**
   * Check whether the shared bundle is running.
   *
   * @permission ohos.permission.GET_RUNNING_INFO
   * @param { string } bundleName - Indicates the bundle name of the shared bundle.
   * @param { number } versionCode - Indicates the version code of the shared bundle.
   * @param { AsyncCallback<boolean> } callback - The callback of checking the shared bundle running result.
   *                                              The result is true if running, false otherwise.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 202 - Not system application.
   * @throws { BusinessError } 401 - If the input parameter is not valid parameter.
   * @throws { BusinessError } 16000050 - Internal error.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @systemapi
   * @since 10
   */
  function isSharedBundleRunning(bundleName: string, versionCode: number, callback: AsyncCallback<boolean>): void;

<<<<<<< HEAD
  /**
   * Register system low memory state observer.
   * @param { 'lowMemory' } type - lowMemory.
   * @param { LowMemoryObserver } observer - Indicates the LowMemoryObserver to be registered.
   * @returns { number } Returns the index number of the LowMemoryObserver.
   * @throws { BusinessError } 202 - Not system application.
   * @throws { BusinessError } 401 - If the input parameter is not valid parameter.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @systemapi
   * @since 10
   */
  function on(type: 'lowMemory', observer: LowMemoryObserver): number;

  /**
   * Unregister system low memory state observer.
   * @param { 'lowMemory' } type - lowMemory.
   * @param { number } observerId - Indicates the observer id to be unregistered.
   * @param { AsyncCallback<void> } callback - the callback of off.
   * @throws { BusinessError } 202 - Not system application.
   * @throws { BusinessError } 401 - If the input parameter is not valid parameter.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @systemapi
   * @since 10
   */
  function off(type: 'lowMemory', observerId: number, callback: AsyncCallback<void>): void;

  /**
   * Unregister system low memory state observer.
   * @param { 'lowMemory' } type - lowMemory.
   * @param { number } observerId - Indicates the observer id to be unregistered.
   * @returns { Promise<void> } The promise returned by the function.
   * @throws { BusinessError } 202 - Not system application.
   * @throws { BusinessError } 401 - If the input parameter is not valid parameter.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @systemapi
   * @since 10
   */
  function off(type: 'lowMemory', observerId: number): Promise<void>;

  /**
   * Obtains memory usage of one process by its pid.
   *
   * @param { number } pid - Indicates the pid of the process.
   * @returns { Promise<number> } Returns the memory usage of the process in KB.
   * @throws { BusinessError } 202 - Permission denied, non-system app called system api.
   * @throws { BusinessError } 401 - The parameter check failed.
   * @throws { BusinessError } 16000050 - Internal error.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @systemapi
   * @since 10
   */
  function getProcessMemoryByPid(pid: number): Promise<number>;

  /**
   * Obtains memory usage of one process by its pid.
   *
   * @param { number } pid - Indicates the pid of the process.
   * @param { AsyncCallback<number> } - Indicates the callback of getting process memory by pid result.
   * @throws { BusinessError } 202 - Permission denied, non-system app called system api.
   * @throws { BusinessError } 401 - The parameter check failed.
   * @throws { BusinessError } 16000050 - Internal error.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @systemapi
   * @since 10
   */
  function getProcessMemoryByPid(pid: number, callback: AsyncCallback<number>): void;

  /**
   * Obtains the pid list of running processes that belong to a specific bundle of current user.
   *
   * @param { string } bundleName - Indicates the bundle name of the application to which the processes belong to.
   * @param { AsyncCallback<Array<number>> } - Indicates the callback of getting pids by bundleName result.
   * @throws { BusinessError } 202 - Permission denied, non-system app called system api.
   * @throws { BusinessError } 401 - The parameter check failed.
   * @throws { BusinessError } 16000050 - Internal error.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @systemapi
   * @since 10
   */
  function getPidsByBundleName(bundleName: string, callback: AsyncCallback<Array<number>>): void;

  /**
   * Obtains the pid list of running processes that belong to a specific bundle and specific user ID.
   *
   * @param { string } bundleName - Indicates the bundle name of the application to which the processes belong to.
   * @param { number } userId - Indicates the user ID of the application to which the processes belong to.
   * @param { AsyncCallback<Array<number>> } - Indicates the callback of getting pids by bundleName result.
   * @throws { BusinessError } 202 - Permission denied, non-system app called system api.
   * @throws { BusinessError } 401 - The parameter check failed.
   * @throws { BusinessError } 16000050 - Internal error.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @systemapi
   * @since 10
   */
  function getPidsByBundleName(bundleName: string, userId: number, callback: AsyncCallback<Array<number>>): void;

  /**
   * Obtains the pid list of running processes that belong to a specific bundle of current user.
   *
   * @param { string } bundleName - Indicates the bundle name of the application to which the processes belong to.
   * @returns { Promise<Array<number>> } - Returns a list of pid numbers.
   * @throws { BusinessError } 202 - Permission denied, non-system app called system api.
   * @throws { BusinessError } 401 - The parameter check failed.
   * @throws { BusinessError } 16000050 - Internal error.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @systemapi
   * @since 10
   */
  function getPidsByBundleName(bundleName: string): Promise<Array<number>>;

  /**
   * Obtains the pid list of running processes that belong to a specific bundle and specific user ID.
   * 
   * @param { string } bundleName - Indicates the bundle name of the application to which the processes belong to.
   * @param { number } userId - Indicates the user ID of the application to which the processes belong to.
   * @returns { Promise<Array<number>> } - Returns a list of pid numbers.
   * @throws { BusinessError } 202 - Permission denied, non-system app called system api.
   * @throws { BusinessError } 401 - The parameter check failed.
   * @throws { BusinessError } 16000050 - Internal error.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @systemapi
   * @since 10
   */
  function getPidsByBundleName(bundleName: string, userId: number): Promise<Array<number>>;

=======
>>>>>>> master
  /**
   * The ability or extension state data.
   *
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @systemapi
   * @since 9
   */
  export type AbilityStateData = _AbilityStateData.default;

  /**
   * The application state data.
   *
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @systemapi
   * @since 9
   */
  export type AppStateData = _AppStateData.default;

  /**
   * The application state observer.
   *
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @systemapi
   * @since 9
   */
  export type ApplicationStateObserver = _ApplicationStateObserver.default;

  /**
   * The class of a process information.
   *
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @since 9
   */
  export type ProcessInformation = _ProcessInformation

  /**
   * The system low memory state observer.
   * @syscap SystemCapability.Ability.AbilityRuntime.Core
   * @systemapi
   * @since 10
   */
  export type LowMemoryObserver = _LowMemoryObserver;
}

export default appManager;
