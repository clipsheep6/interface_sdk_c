/*
 * Copyright (c) 2022 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

import { AsyncCallback, Callback } from './@ohos.base';
import type Context from './application/BaseContext';

/**
 * Provides interfaces to sync distributed object.
 *
 * @namespace distributedDataObject
 * @syscap SystemCapability.DistributedDataManager.DataObject.DistributedObject
 * @since 8
 */
declare namespace distributedDataObject {
  /**
   * Create distributed object.
   *
   * @param { object } source - Source Init data of distributed object.
   * @returns { DistributedObject } - Return the distributed object.
   * @syscap SystemCapability.DistributedDataManager.DataObject.DistributedObject
   * @since 8
   * @deprecated since 9
   * @useinstead ohos.distributedDataObject.create
   */
  function createDistributedObject(source: object): DistributedObject;

  /**
   * Create distributed object.
   *
   * @param { Context } context - Indicates the application context.
   * @param { object } source - Source Init data of distributed object.
   * @returns { DataObject } - Return the distributed object.
   * @throws { BusinessError } 401 - Parameter error.
   * @syscap SystemCapability.DistributedDataManager.DataObject.DistributedObject
   * @since 9
   */
  function create(context: Context, source: object): DataObject;

  /**
   * Generate a random sessionId.
   *
   * @returns { string } - Return generated sessionId.
   * @syscap SystemCapability.DistributedDataManager.DataObject.DistributedObject
   * @since 8
   */
  function genSessionId(): string;

  /**
   * The response of save.
   * Contains the parameter information of the save object.
   *
   * @interface SaveSuccessResponse
   * @syscap SystemCapability.DistributedDataManager.DataObject.DistributedObject
   * @since 9
   */
  interface SaveSuccessResponse {
    /**
     * sessionId of saved object
     *
     * @syscap SystemCapability.DistributedDataManager.DataObject.DistributedObject
     * @since 9
     */
    sessionId: string;

    /**
     * version of saved object, can compare with DistributedObject.__version
     *
     * @syscap SystemCapability.DistributedDataManager.DataObject.DistributedObject
     * @since 9
     */
    version: number;

    /**
     * deviceid that data saved
     * data is "local", means save in local device
     * otherwise, means the networkId of device
     *
     * @syscap SystemCapability.DistributedDataManager.DataObject.DistributedObject
     * @since 9
     */
    deviceId: string;
  }

  /**
   * The response of revokeSave.
   * Contains the sessionId of the changed object.
   *
   * @interface RevokeSaveSuccessResponse
   * @syscap SystemCapability.DistributedDataManager.DataObject.DistributedObject
   * @since 9
   */
  interface RevokeSaveSuccessResponse {
    /**
     * The sessionId of the changed object.
     *
     * @syscap SystemCapability.DistributedDataManager.DataObject.DistributedObject
     * @since 9
     */
    sessionId: string;
  }

  /**
   * Object create by {@link createDistributedObject}.
   *
   * @interface DistributedObject
   * @syscap SystemCapability.DistributedDataManager.DataObject.DistributedObject
   * @since 8
   * @deprecated since 9
   * @useinstead ohos.distributedDataObject.DataObject
   */
  interface DistributedObject {
    /**
     * Change object session
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @param { string } sessionId - sessionId The sessionId to be joined, if empty, leave all session.
     * @returns { boolean } - Return a result of function.
     * @syscap SystemCapability.DistributedDataManager.DataObject.DistributedObject
     * @since 8
     * @deprecated since 9
     * @useinstead ohos.distributedDataObject.DataObject.setSessionId
     */
    setSessionId(sessionId?: string): boolean;

    /**
     * On watch of change
     *
     * @param { 'change' } type - Event type, fixed as 'change', indicates data change.
     * @param { Function } callback
     *          Indicates the observer of object data changed.
     *          {string} sessionId - The sessionId of the changed object.
     *          {Array<string>} fields - Changed data.
     * @syscap SystemCapability.DistributedDataManager.DataObject.DistributedObject
     * @since 8
     * @deprecated since 9
     * @useinstead ohos.distributedDataObject.DataObject.on
     */
    on(type: 'change', callback: (sessionId: string, fields: Array<string>) => void): void;

    /**
     * Off watch of change
     *
     * @param { 'change' } type - Event type, fixed as 'change', indicates data change.
     * @param { Function } callback
     *          Indicates the observer of object data changed.
     *          {string} sessionId - The sessionId of the changed object.
     *          {Array<string>} fields - Changed data.
     *          callback If not null, off the callback, if undefined, off all callbacks.
     * @syscap SystemCapability.DistributedDataManager.DataObject.DistributedObject
     * @since 8
     * @deprecated since 9
     * @useinstead ohos.distributedDataObject.DataObject.off
     */
    off(type: 'change', callback?: (sessionId: string, fields: Array<string>) => void): void;

    /**
     * On watch of status
     *
     * @param { 'status' } type - Event type, fixed as 'status', indicates the online and offline of the object.
     * @param { Function } callback
     *          Indicates the observer of object status changed.
     *          {string} sessionId - The sessionId of the changed object.
     *          {string} networkId - NetworkId of the changed device.
     *          {string} status
     *                   'online' The object became online on the device and data can be synced to the device.
     *                   'offline' The object became offline on the device and the object can not sync any data.
     * @syscap SystemCapability.DistributedDataManager.DataObject.DistributedObject
     * @since 8
     * @deprecated since 9
     * @useinstead ohos.distributedDataObject.DataObject.on
     */
    on(
      type: 'status',
      callback: (sessionId: string, networkId: string, status: 'online' | 'offline' ) => void
    ): void;

    /**
     * Off watch of status
     *
     * @param { 'status' } type - Event type, fixed as 'status', indicates the online and offline of the object.
     * @param { Function } callback
     *          Indicates the observer of object status changed.
     *          {string} sessionId - The sessionId of the changed object.
     *          {string} networkId - NetworkId of the changed device.
     *          {string} status
     *                   'online' The object became online on the device and data can be synced to the device.
     *                   'offline' The object became offline on the device and the object can not sync any data.
     *          callback If not null, off the callback, if undefined, off all callbacks.
     * @syscap SystemCapability.DistributedDataManager.DataObject.DistributedObject
     * @since 8
     * @deprecated since 9
     * @useinstead ohos.distributedDataObject.DataObject.off
     */
    off(
      type: 'status',
      callback?: (sessionId: string, networkId: string, status: 'online' | 'offline' ) => void
    ): void;
  }

  /**
   * Object create by {@link create}.
   *
   * @interface DataObject
   * @syscap SystemCapability.DistributedDataManager.DataObject.DistributedObject
   * @since 9
   */
  interface DataObject {
    /*
     * Change object session.
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @param {string} sessionId - sessionId The sessionId to be joined, if empty, leave all session.
     * @param {AsyncCallback<void>} callback - The callback of setSessionId.
     * @throws {BusinessError} 201 - Permission verification failed.
     * @throws {BusinessError} 401 - Parameter error.
     * @throws {BusinessError} 15400001 - Create table failed.
     * @syscap SystemCapability.DistributedDataManager.DataObject.DistributedObject
     * @since 9
     */
    setSessionId(sessionId: string, callback: AsyncCallback<void>): void;

    /*
     * Change object session.
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @param {string} sessionId - sessionId The sessionId to be joined, if empty, leave all session.
     * @param {AsyncCallback<void>} callback - The callback of setSessionId.
     * @throws {BusinessError} 201 - Permission verification failed.
     * @throws {BusinessError} 401 - Parameter error.
     * @throws {BusinessError} 15400001 - Create table failed.
     * @syscap SystemCapability.DistributedDataManager.DataObject.DistributedObject
     * @since 9
     */
    setSessionId(callback: AsyncCallback<void>): void;

    /*
     * Change object session.
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @param {string} sessionId - sessionId The sessionId to be joined, if empty, leave all session.
     * @returns {Promise<void>} - The promise returned by the function.
     * @throws {BusinessError} 201 - Permission verification failed.
     * @throws {BusinessError} 401 - Parameter error.
     * @throws {BusinessError} 15400001 - Create table failed.
     * @syscap SystemCapability.DistributedDataManager.DataObject.DistributedObject
     * @since 9
     */
    setSessionId(sessionId?: string): Promise<void>;

    /**
     * On watch of change.
     *
     * @param { 'change' } type - event type, fixed as 'change', indicates data change.
     * @param { Function } callback
     *
     *          indicates the observer of object data changed.
     *          {string} sessionId - the sessionId of the changed object.
     *          {Array<string>} fields - changed data.
     *          sessionId The sessionId of the changed object.
     * @throws { BusinessError } 401 - Parameter error.
     * @syscap SystemCapability.DistributedDataManager.DataObject.DistributedObject
     * @since 9
     */
    on(type: 'change', callback: (sessionId: string, fields: Array<string>) => void ): void;

    /**
     * Off watch of change.
     *
     * @param { 'change' } type - Event type, fixed as 'change', indicates data change.
     * @param { Function } callback
     *          indicates the observer of object data changed.
     *          {string} sessionId - The sessionId of the changed object.
     *          {Array<string>} fields - Changed data.
     *          callback If not null, off the callback, if undefined, off all callbacks.
     * @throws { BusinessError } 401 - Parameter error.
     * @syscap SystemCapability.DistributedDataManager.DataObject.DistributedObject
     * @since 9
     */
    off(type: 'change', callback?: (sessionId: string, fields: Array<string>) => void ): void;

    /**
     * On watch of status.
     *
     * @param { 'status' } type - Event type, fixed as 'status', indicates the online and offline of the object.
     * @param { Function } callback
     *          indicates the observer of object status changed.
     *          {string} sessionId - The sessionId of the changed object.
     *          {string} networkId - NetworkId of the changed device.
     *          {string} status
     *                   'online' The object became online on the device and data can be synced to the device.
     *                   'offline' The object became offline on the device and the object can not sync any data.
     *                   'restored' The object restored success.
     * @throws { BusinessError } 401 - Parameter error.
     * @syscap SystemCapability.DistributedDataManager.DataObject.DistributedObject
     * @since 9
     */
    on(
      type: 'status',
      callback: (sessionId: string, networkId: string, status: 'online' | 'offline' ) => void
    ): void;

    /**
     * Off watch of status.
     *
     * @param { 'status' } type - Event type, fixed as 'status', indicates the online and offline of the object.
     * @param { Function } callback
     *          Indicates the observer of object status changed.
     *          {string} sessionId - The sessionId of the changed object.
     *          {string} networkId - NetworkId of the changed device.
     *          {string} status
     *                   'online' The object became online on the device and data can be synced to the device.
     *                   'offline' The object became offline on the device and the object can not sync any data.
     *          callback If not null, off the callback, if undefined, off all callbacks.
     * @throws { BusinessError } 401 - Parameter error.
     * @syscap SystemCapability.DistributedDataManager.DataObject.DistributedObject
     * @since 9
     */
    off(
      type: 'status',
      callback?: (sessionId: string, networkId: string, status: 'online' | 'offline' ) => void
    ): void;

    /**
     * Save object, after save object data successfully, the object data will not release when app existed,
     * and resume data on saved device after app existed.
     * the saved data secure level is S0, it is not safe, can only save public data, if there is privacy data,
     * you should encrypt it
     * The saved data will be released when
     * 1. saved after 24h.
     * 2. app uninstalled.
     * 3. after resume data success, system will auto delete the saved data.
     *
     * @param { string } deviceId - Indicates the device that will resume the object data.
     * @param { AsyncCallback<SaveSuccessResponse> } callback
     *        {SaveSuccessResponse}: The response of save.
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 801 - Capability not supported.
     * @syscap SystemCapability.DistributedDataManager.DataObject.DistributedObject
     * @since 9
     */
    save(deviceId: string, callback: AsyncCallback<SaveSuccessResponse>): void;

    /**
     * Save object, after save object data successfully, the object data will not release when app existed,
     * and resume data on saved device after app existed.
     * the saved data secure level is S0, it is not safe, can only save public data, if there is privacy data,
     * you should encrypt it.
     * The saved data will be released when
     * 1. saved after 24h.
     * 2. app uninstalled.
     * 3. after resume data success, system will auto delete the saved data.
     *
     * @param { string } deviceId - Indicates the device that will resume the object data.
     * @returns { Promise<SaveSuccessResponse> } {SaveSuccessResponse}: The response of save.
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 801 - Capability not supported.
     * @syscap SystemCapability.DistributedDataManager.DataObject.DistributedObject
     * @since 9
     */
    save(deviceId: string): Promise<SaveSuccessResponse>;

    /**
     * Revoke save object, delete saved object immediately, if object is saved in local device,
     * it will delete saved data on all trusted device.
     * if object is saved in other device, it will delete data in local device.
     *
     * @param { AsyncCallback<RevokeSaveSuccessResponse> } callback
     *        {RevokeSaveSuccessResponse}: The response of revokeSave.
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 801 - Capability not supported.
     * @syscap SystemCapability.DistributedDataManager.DataObject.DistributedObject
     * @since 9
     */
    revokeSave(callback: AsyncCallback<RevokeSaveSuccessResponse>): void;

    /**
     * Revoke save object, delete saved object immediately, if object is saved in local device,
     * it will delete saved data on all trusted device.
     * if object is saved in other device, it will delete data in local device.
     *
     * @returns { Promise<RevokeSaveSuccessResponse> } {RevokeSaveSuccessResponse}: The response of revokeSave.
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 801 - Capability not supported.
     * @syscap SystemCapability.DistributedDataManager.DataObject.DistributedObject
     * @since 9
     */
    revokeSave(): Promise<RevokeSaveSuccessResponse>;
  }
}

export default distributedDataObject;
