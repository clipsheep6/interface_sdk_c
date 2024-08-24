/*
 * Copyright (c) 2022 Huawei Device Co., Ltd.
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
 * @kit BackgroundTasksKit
 */

import { AsyncCallback, Callback } from './@ohos.base';
import { WantAgent } from './@ohos.wantAgent';
import Context from './application/BaseContext';
import type notificationManager from './@ohos.notificationManager';

/**
 * Manages background tasks.
 *
 * @namespace backgroundTaskManager
 * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.Core
 * @since 9
 */
/**
 * Manages background tasks.
 *
 * @namespace backgroundTaskManager
 * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.Core
 * @atomicservice
 * @since 12
 */
declare namespace backgroundTaskManager {
  /**
   * The info of delay suspend.
   *
   * @interface DelaySuspendInfo
   * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask
   * @since 9
   */
  interface DelaySuspendInfo {
    /**
     * The unique identifier of the delay request.
     *
     * @type { number }
     * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask
     * @since 9
     */
    requestId: number;
    /**
     * The actual delay duration (ms).
     *
     * @type { number }
     * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask
     * @since 9
     */
    actualDelayTime: number;
  }

  /**
   * The info of continuous task notification.
   *
   * @interface ContinuousTaskNotification
   * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask
   * @atomicservice
   * @since 12
   */
  interface ContinuousTaskNotification {
    /**
     * The notification slot type.
     *
     * @type { notificationManager.SlotType }
     * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask
     * @atomicservice
     * @since 12
     */
    slotType: notificationManager.SlotType;
    /**
     * The notification content type.
     *
     * @type { notificationManager.ContentType }
     * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask
     * @atomicservice
     * @since 12
     */
    contentType: notificationManager.ContentType;
    /**
     * The notification id.
     *
     * @type { number }
     * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask
     * @atomicservice
     * @since 12
     */
    notificationId: number;
  }

  /**
   * Cancels delayed transition to the suspended state.
   *
   * @param { number } requestId - The identifier of the delay request.
   * @throws { BusinessError } 401 - Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;
   * <br> 2. Incorrect parameters types; 3. Parameter verification failed.
   * @throws { BusinessError } 9800001 - Memory operation failed.
   * @throws { BusinessError } 9800002 - Parcel operation failed.
   * @throws { BusinessError } 9800003 - Internal transaction failed.
   * @throws { BusinessError } 9800004 - System service operation failed.
   * @throws { BusinessError } 9900001 - Caller information verification failed for a transient task.
   * @throws { BusinessError } 9900002 - Transient task verification failed.
   * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask
   * @since 9
   */
  function cancelSuspendDelay(requestId: number): void;

  /**
   * Obtains the remaining time before an application enters the suspended state.
   *
   * @param { number } requestId - The identifier of the delay request.
   * @param { AsyncCallback<number> } callback - The callback of the remaining delay time.
   * @throws { BusinessError } 401 - Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;
   * <br> 2. Incorrect parameters types; 3. Parameter verification failed.
   * @throws { BusinessError } 9800001 - Memory operation failed.
   * @throws { BusinessError } 9800002 - Parcel operation failed.
   * @throws { BusinessError } 9800003 - Internal transaction failed.
   * @throws { BusinessError } 9800004 - System service operation failed.
   * @throws { BusinessError } 9900001 - Caller information verification failed for a transient task.
   * @throws { BusinessError } 9900002 - Transient task verification failed.
   * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask
   * @since 9
   */
  function getRemainingDelayTime(requestId: number, callback: AsyncCallback<number>): void;

  /**
   * Obtains the remaining time before an application enters the suspended state.
   *
   * @param { number } requestId - The identifier of the delay request.
   * @returns { Promise<number> } The promise returns the remaining delay time.
   * @throws { BusinessError } 401 - Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;
   * <br> 2. Incorrect parameters types; 3. Parameter verification failed.
   * @throws { BusinessError } 9800001 - Memory operation failed.
   * @throws { BusinessError } 9800002 - Parcel operation failed.
   * @throws { BusinessError } 9800003 - Internal transaction failed.
   * @throws { BusinessError } 9800004 - System service operation failed.
   * @throws { BusinessError } 9900001 - Caller information verification failed for a transient task.
   * @throws { BusinessError } 9900002 - Transient task verification failed.
   * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask
   * @since 9
   */
  function getRemainingDelayTime(requestId: number): Promise<number>;

  /**
   * Requests delayed transition to the suspended state.
   *
   * @param { string } reason - Indicates the reason for delayed transition to the suspended state.
   * @param { Callback<void> } callback - The callback delay time expired.
   * @returns { DelaySuspendInfo } Info of delay request.
   * @throws { BusinessError } 401 - Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;
   * <br> 2. Incorrect parameters types.
   * @throws { BusinessError } 9800001 - Memory operation failed.
   * @throws { BusinessError } 9800002 - Parcel operation failed.
   * @throws { BusinessError } 9800003 - Internal transaction failed.
   * @throws { BusinessError } 9800004 - System service operation failed.
   * @throws { BusinessError } 9900001 - Caller information verification failed for a transient task.
   * @throws { BusinessError } 9900002 - Transient task verification failed.
   * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask
   * @since 9
   */
  function requestSuspendDelay(reason: string, callback: Callback<void>): DelaySuspendInfo;

  /**
   * Service ability uses this method to request start running in background.
   * <p> System will publish a notification related to the this service. </p>
   *
   * @permission ohos.permission.KEEP_BACKGROUND_RUNNING
   * @param { Context } context - App running context.
   * @param { BackgroundMode } bgMode - Indicates which background mode to request.
   * @param { WantAgent } wantAgent - Indicates which ability to start when user click the notification bar.
   * @param { AsyncCallback<void> } callback - The callback of the function.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 202 - Not System App.
   * @throws { BusinessError } 401 - Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;
   * <br> 2. Incorrect parameters types; 3. Parameter verification failed.
   * @throws { BusinessError } 9800001 - Memory operation failed.
   * @throws { BusinessError } 9800002 - Parcel operation failed.
   * @throws { BusinessError } 9800003 - Internal transaction failed.
   * @throws { BusinessError } 9800004 - System service operation failed.
   * @throws { BusinessError } 9800005 - Continuous task verification failed.
   * @throws { BusinessError } 9800006 - Notification verification failed for a continuous task.
   * @throws { BusinessError } 9800007 - Continuous task storage failed.
   * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask
   * @since 9
   */
  /**
   * Service ability uses this method to request start running in background.
   * <p> System will publish a notification related to the this service. </p>
   *
   * @permission ohos.permission.KEEP_BACKGROUND_RUNNING
   * @param { Context } context - App running context.
   * @param { BackgroundMode } bgMode - Indicates which background mode to request.
   * @param { WantAgent } wantAgent - Indicates which ability to start when user click the notification bar.
   * @param { AsyncCallback<void> } callback - The callback of the function.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 202 - Not System App.
   * @throws { BusinessError } 401 - Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;
   * <br> 2. Incorrect parameters types; 3. Parameter verification failed.
   * @throws { BusinessError } 9800001 - Memory operation failed.
   * @throws { BusinessError } 9800002 - Parcel operation failed.
   * @throws { BusinessError } 9800003 - Internal transaction failed.
   * @throws { BusinessError } 9800004 - System service operation failed.
   * @throws { BusinessError } 9800005 - Continuous task verification failed.
   * @throws { BusinessError } 9800006 - Notification verification failed for a continuous task.
   * @throws { BusinessError } 9800007 - Continuous task storage failed.
   * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask
   * @atomicservice
   * @since 12
   */
  function startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent, callback: AsyncCallback<void>): void;

  /**
   * Service ability uses this method to request start running in background.
   * <p> System will publish a notification related to the this service. </p>
   *
   * @permission ohos.permission.KEEP_BACKGROUND_RUNNING
   * @param { Context } context - App running context.
   * @param { BackgroundMode } bgMode - Indicates which background mode to request.
   * @param { WantAgent } wantAgent - Indicates which ability to start when user click the notification bar.
   * @returns { Promise<void> } The promise returned by the function.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 202 - Not System App.
   * @throws { BusinessError } 401 - Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;
   * <br> 2. Incorrect parameters types; 3. Parameter verification failed.
   * @throws { BusinessError } 9800001 - Memory operation failed.
   * @throws { BusinessError } 9800002 - Parcel operation failed.
   * @throws { BusinessError } 9800003 - Internal transaction failed.
   * @throws { BusinessError } 9800004 - System service operation failed.
   * @throws { BusinessError } 9800005 - Continuous task verification failed.
   * @throws { BusinessError } 9800006 - Notification verification failed for a continuous task.
   * @throws { BusinessError } 9800007 - Continuous task storage failed.
   * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask
   * @since 9
   */
  /**
   * Service ability uses this method to request start running in background.
   * <p> System will publish a notification related to the this service. </p>
   *
   * @permission ohos.permission.KEEP_BACKGROUND_RUNNING
   * @param { Context } context - App running context.
   * @param { BackgroundMode } bgMode - Indicates which background mode to request.
   * @param { WantAgent } wantAgent - Indicates which ability to start when user click the notification bar.
   * @returns { Promise<void> } The promise returned by the function.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 202 - Not System App.
   * @throws { BusinessError } 401 - Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;
   * <br> 2. Incorrect parameters types; 3. Parameter verification failed.
   * @throws { BusinessError } 9800001 - Memory operation failed.
   * @throws { BusinessError } 9800002 - Parcel operation failed.
   * @throws { BusinessError } 9800003 - Internal transaction failed.
   * @throws { BusinessError } 9800004 - System service operation failed.
   * @throws { BusinessError } 9800005 - Continuous task verification failed.
   * @throws { BusinessError } 9800006 - Notification verification failed for a continuous task.
   * @throws { BusinessError } 9800007 - Continuous task storage failed.
   * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask
   * @atomicservice
   * @since 12
   */
  function startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent): Promise<void>;

  /**
   * UIAbility uses this method to request start running in background.
   * <p> System will publish a notification related to the UIAbility. </p>
   *
   * @permission ohos.permission.KEEP_BACKGROUND_RUNNING
   * @param { Context } context - App running context.
   * @param { string[] } bgModes - Indicates which background mode to request.
   * @param { WantAgent } wantAgent - Indicates which ability to start when user click the notification bar.
   * @returns { Promise<ContinuousTaskNotification> } The The continuous task notification.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 401 - Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;
   * <br> 2. Incorrect parameters types; 3. Parameter verification failed.
   * @throws { BusinessError } 9800001 - Memory operation failed.
   * @throws { BusinessError } 9800002 - Parcel operation failed.
   * @throws { BusinessError } 9800003 - Internal transaction failed.
   * @throws { BusinessError } 9800004 - System service operation failed.
   * @throws { BusinessError } 9800005 - Continuous task verification failed.
   * @throws { BusinessError } 9800006 - Notification verification failed for a continuous task.
   * @throws { BusinessError } 9800007 - Continuous task storage failed.
   * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask
   * @atomicservice
   * @since 12
   */
  function startBackgroundRunning(context: Context, bgModes: string[], wantAgent: WantAgent): Promise<ContinuousTaskNotification>;

  /**
   * UIAbility uses this method to update background mode.
   *
   * @permission ohos.permission.KEEP_BACKGROUND_RUNNING
   * @param { Context } context - App running context.
   * @param { string[] } bgModes - Indicates which background mode to request.
   * @returns { Promise<ContinuousTaskNotification> } The continuous task notification.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 401 - Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;
   * <br> 2. Incorrect parameters types; 3. Parameter verification failed.
   * @throws { BusinessError } 9800001 - Memory operation failed.
   * @throws { BusinessError } 9800002 - Parcel operation failed.
   * @throws { BusinessError } 9800003 - Internal transaction failed.
   * @throws { BusinessError } 9800004 - System service operation failed.
   * @throws { BusinessError } 9800005 - Continuous task verification failed.
   * @throws { BusinessError } 9800006 - Notification verification failed for a continuous task.
   * @throws { BusinessError } 9800007 - Continuous task storage failed.
   * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask
   * @atomicservice
   * @since 12
   */
  function updateBackgroundRunning(context: Context, bgModes: string[]): Promise<ContinuousTaskNotification>;

  /**
   * Service ability uses this method to request stop running in background.
   *
   * @param { Context } context - App running context.
   * @param { AsyncCallback<void> } callback - The callback of the function.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 401 - Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.
   * @throws { BusinessError } 9800001 - Memory operation failed.
   * @throws { BusinessError } 9800002 - Parcel operation failed.
   * @throws { BusinessError } 9800003 - Internal transaction failed.
   * @throws { BusinessError } 9800004 - System service operation failed.
   * @throws { BusinessError } 9800005 - Continuous task verification failed.
   * @throws { BusinessError } 9800006 - Notification verification failed for a continuous task.
   * @throws { BusinessError } 9800007 - Continuous task storage failed.
   * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask
   * @since 9
   */
  /**
   * Service ability uses this method to request stop running in background.
   *
   * @param { Context } context - App running context.
   * @param { AsyncCallback<void> } callback - The callback of the function.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 401 - Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.
   * @throws { BusinessError } 9800001 - Memory operation failed.
   * @throws { BusinessError } 9800002 - Parcel operation failed.
   * @throws { BusinessError } 9800003 - Internal transaction failed.
   * @throws { BusinessError } 9800004 - System service operation failed.
   * @throws { BusinessError } 9800005 - Continuous task verification failed.
   * @throws { BusinessError } 9800006 - Notification verification failed for a continuous task.
   * @throws { BusinessError } 9800007 - Continuous task storage failed.
   * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask
   * @atomicservice
   * @since 12
   */
  function stopBackgroundRunning(context: Context, callback: AsyncCallback<void>): void;

  /**
   * Service ability uses this method to request stop running in background.
   *
   * @param { Context } context - App running context.
   * @returns { Promise<void> } The promise returned by the function.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 401 - Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.
   * @throws { BusinessError } 9800001 - Memory operation failed.
   * @throws { BusinessError } 9800002 - Parcel operation failed.
   * @throws { BusinessError } 9800003 - Internal transaction failed.
   * @throws { BusinessError } 9800004 - System service operation failed.
   * @throws { BusinessError } 9800005 - Continuous task verification failed.
   * @throws { BusinessError } 9800006 - Notification verification failed for a continuous task.
   * @throws { BusinessError } 9800007 - Continuous task storage failed.
   * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask
   * @since 9
   */
  /**
   * Service ability uses this method to request stop running in background.
   *
   * @param { Context } context - App running context.
   * @returns { Promise<void> } The promise returned by the function.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 401 - Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.
   * @throws { BusinessError } 9800001 - Memory operation failed.
   * @throws { BusinessError } 9800002 - Parcel operation failed.
   * @throws { BusinessError } 9800003 - Internal transaction failed.
   * @throws { BusinessError } 9800004 - System service operation failed.
   * @throws { BusinessError } 9800005 - Continuous task verification failed.
   * @throws { BusinessError } 9800006 - Notification verification failed for a continuous task.
   * @throws { BusinessError } 9800007 - Continuous task storage failed.
   * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask
   * @atomicservice
   * @since 12
   */
  function stopBackgroundRunning(context: Context): Promise<void>;

  /**
   * Apply or unapply efficiency resources.
   *
   * @param { EfficiencyResourcesRequest } request - The request of apply or unapply efficiency resources.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 202 - Not System App.
   * @throws { BusinessError } 401 - Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;
   * <br> 2. Incorrect parameters types; 3. Parameter verification failed.
   * @throws { BusinessError } 9800001 - Memory operation failed.
   * @throws { BusinessError } 9800002 - Parcel operation failed.
   * @throws { BusinessError } 9800003 - Internal transaction failed.
   * @throws { BusinessError } 9800004 - System service operation failed.
   * @throws { BusinessError } 18700001 - Caller information verification failed for an energy resource request.
   * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply
   * @systemapi Hide this for inner system use.
   * @since 9
   */
  function applyEfficiencyResources(request: EfficiencyResourcesRequest): void;

  /**
   * Reset all efficiency resources apply.
   *
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 202 - Not System App.
   * @throws { BusinessError } 401 - Parameter error. Possible causes: 1. Parameter verification failed.
   * @throws { BusinessError } 9800001 - Memory operation failed.
   * @throws { BusinessError } 9800002 - Parcel operation failed.
   * @throws { BusinessError } 9800003 - Internal transaction failed.
   * @throws { BusinessError } 9800004 - System service operation failed.
   * @throws { BusinessError } 18700001 - Caller information verification failed for an energy resource request.
   * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply
   * @systemapi Hide this for inner system use.
   * @since 9
   */
  function resetAllEfficiencyResources(): void;

  /**
   * Supported background mode.
   *
   * @enum { number }
   * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask
   * @since 9
   */
  /**
   * Supported background mode.
   *
   * @enum { number }
   * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask
   * @atomicservice
   * @since 12
   */
  export enum BackgroundMode {
    /**
     * data transfer mode
     *
     * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask
     * @since 9
     */
    DATA_TRANSFER = 1,

    /**
     * audio playback mode
     *
     * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask
     * @since 9
     */
    /**
     * audio playback mode
     *
     * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask
     * @atomicservice
     * @since 12
     */
    AUDIO_PLAYBACK = 2,

    /**
     * audio recording mode
     *
     * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask
     * @since 9
     */
    AUDIO_RECORDING = 3,

    /**
     * location mode
     *
     * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask
     * @since 9
     */
    LOCATION = 4,

    /**
     * bluetooth interaction mode
     *
     * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask
     * @since 9
     */
    BLUETOOTH_INTERACTION = 5,

    /**
     * multi-device connection mode
     *
     * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask
     * @since 9
     */
    /**
     * multi-device connection mode
     *
     * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask
     * @atomicservice
     * @since 12
     */
    MULTI_DEVICE_CONNECTION = 6,

    /**
     * wifi interaction mode
     *
     * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask
     * @systemapi Hide this for inner system use.
     * @since 9
     */
    WIFI_INTERACTION = 7,

    /**
     * Voice over Internet Phone mode
     *
     * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask
     * @since 9
     */
    VOIP = 8,

    /**
     * background continuous calculate mode, for example 3D render.
     * only supported in particular device
     *
     * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask
     * @since 9
     */
    TASK_KEEPING = 9,
  }

  /**
   * The type of resource.
   *
   * @enum { number }
   * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply
   * @systemapi Hide this for inner system use.
   * @since 9
   */
  export enum ResourceType {
    /**
     * The cpu resource for not being suspended.
     *
     * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply
     * @systemapi Hide this for inner system use.
     * @since 9
     */
    CPU = 1,

    /**
     * The resource for not being proxyed common_event.
     *
     * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply
     * @systemapi Hide this for inner system use.
     * @since 9
     */
    COMMON_EVENT = 1 << 1,

    /**
     * The resource for not being proxyed timer.
     *
     * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply
     * @systemapi Hide this for inner system use.
     * @since 9
     */
    TIMER = 1 << 2,

    /**
     * The resource for not being proxyed workscheduler.
     *
     * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply
     * @systemapi Hide this for inner system use.
     * @since 9
     */
    WORK_SCHEDULER = 1 << 3,

    /**
     * The resource for not being proxyed bluetooth.
     *
     * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply
     * @systemapi Hide this for inner system use.
     * @since 9
     */
    BLUETOOTH = 1 << 4,

    /**
     * The resource for not being proxyed gps.
     *
     * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply
     * @systemapi Hide this for inner system use.
     * @since 9
     */
    GPS = 1 << 5,

    /**
     * The resource for not being proxyed audio.
     *
     * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply
     * @systemapi Hide this for inner system use.
     * @since 9
     */
    AUDIO = 1 << 6,

    /**
     * The resource for not being proxyed running lock.
     *
     * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply
     * @systemapi Hide this for inner system use.
     * @since 10
     */
    RUNNING_LOCK = 1 << 7,

    /**
     * The resource for not being proxyed sensor.
     *
     * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply
     * @systemapi Hide this for inner system use.
     * @since 10
     */
    SENSOR = 1 << 8
  }

  /**
   * The request of efficiency resources.
   *
   * @interface EfficiencyResourcesRequest
   * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply
   * @systemapi Hide this for inner system use.
   * @since 9
   */
  export interface EfficiencyResourcesRequest {
    /**
     * The set of resource types that app wants to apply.
     *
     * @type { number }
     * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply
     * @systemapi Hide this for inner system use.
     * @since 9
     */
    resourceTypes: number;

    /**
     * True if the app begin to use, else false.
     *
     * @type { boolean }
     * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply
     * @systemapi Hide this for inner system use.
     * @since 9
     */
    isApply: boolean;

    /**
     * The duration that the resource can be used most.
     *
     * @type { number }
     * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply
     * @systemapi Hide this for inner system use.
     * @since 9
     */
    timeOut: number;

    /**
     * True if the apply action is persist, else false. Default value is false.
     *
     * @type { ?boolean }
     * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply
     * @systemapi Hide this for inner system use.
     * @since 9
     */
    isPersist?: boolean;

    /**
     * True if apply action is for process, false is for package. Default value is false.
     *
     * @type { ?boolean }
     * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply
     * @systemapi Hide this for inner system use.
     * @since 9
     */
    isProcess?: boolean;

    /**
     * The apply reason.
     *
     * @type { string }
     * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply
     * @systemapi Hide this for inner system use.
     * @since 9
     */
    reason: string;
  }
}

export default backgroundTaskManager;
