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

import type { AsyncCallback } from './@ohos.base';
import type { Callback } from './@ohos.base';

/**
 * Providers interfaces to create a {@link deviceManager} instances.
 *
 * @namespace distributedDeviceManager
 * @syscap SystemCapability.DistributedHardware.DeviceManager
 * @since 10
 */

declare namespace distributedDeviceManager {

  /**
   * Basic description information of a distributed device.
   * @interface DeviceBasicInfo
   * @syscap SystemCapability.DistributedHardware.DeviceManager
   * @since 10
   */
  interface DeviceBasicInfo {
    /**
     * Device unique identifier, The actual value is the udid-hash confused with the appid based on sha256.
     * @syscap SystemCapability.DistributedHardware.DeviceManager
     * @since 10
     */
    deviceId: string;

    /**
     * Device name.
     * @syscap SystemCapability.DistributedHardware.DeviceManager
     * @since 10
     */
    deviceName: string;

    /**
     * Device type. Currently, only support the following device types:
     *    12 - Indicates a smart pc.
     *    14 - Indicates a smart phone.
     *    17 - Indicates a smart pad.
     * @syscap SystemCapability.DistributedHardware.DeviceManager
     * @since 10
     */
    deviceType: number;

    /**
     * Device network id.
     * @syscap SystemCapability.DistributedHardware.DeviceManager
     * @since 10
     */
    networkId?: string;
  }

  /**
   * The state of the nearby devices.
   * @enum { DeviceStateChange }
   * @syscap SystemCapability.DistributedHardware.DeviceManager
   * @since 10
   */
  enum DeviceStateChange {
    /**
     * This state indicates the device is online but the state is unknown,The distributed function cannot used until
     * state changes to AVAILABLE.
     * @syscap SystemCapability.DistributedHardware.DeviceManager
     * @since 10
     */
    UNKNOWN = 0,

    /**
     * This state indicates the device has been synchronized to the database, Now the distributed function can be used.
     * @syscap SystemCapability.DistributedHardware.DeviceManager
     * @since 10
     */
    AVAILABLE = 1,

    /**
     * This state indicates the device is offline.
     * @syscap SystemCapability.DistributedHardware.DeviceManager
     * @since 10
     */
    UNAVAILABLE = 2,
  }

  /**
   * Creates an {@code DeviceManager} instance.
   *
   * To manage devices, you must first call this method to obtain a {@code DeviceManager} instance and then
   * use this instance to call other device management methods.
   *
   * @param { string } bundleName - Indicates the bundle name of the application.
   * @returns { DeviceManager } - Return the DeviceManager object.
   * @throws { BusinessError } 401 - Input parameter error.
   * @syscap SystemCapability.DistributedHardware.DeviceManager
   * @since 10
   */
  function createDeviceManager(bundleName: string): DeviceManager;

  /**
   * Releases the {@code DeviceManager} instance that is no longer used.
   *
   * @permission ohos.permission.DISTRIBUTED_DATASYNC
   * @param { DeviceManager } deviceManager - Indicates the {@code DeviceManager} instance.
   * @throws { BusinessError } 201 - User permission verify failed.
   * @throws { BusinessError } 401 - Input parameter error.
   * @throws { BusinessError } 11600101 - Failed to execute the function.
   * @syscap SystemCapability.DistributedHardware.DeviceManager
   * @since 10
   */
  function releaseDeviceManager(deviceManager: DeviceManager): void;

  /**
   * Provides methods for managing devices.
   *
   * @interface DeviceManager
   * @syscap SystemCapability.DistributedHardware.DeviceManager
   * @since 10
   */
  interface DeviceManager {

    /**
     * Get a list of available devices. This interface query all authorized and connectable devices.
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @returns { Array<DeviceBasicInfo> } - Returns a list of available devices.
     * @throws { BusinessError } 201 - User permission verify failed.
     * @throws { BusinessError } 401 - Input parameter error.
     * @throws { BusinessError } 11600101 - Failed to execute the function.
     * @syscap SystemCapability.DistributedHardware.DeviceManager
     * @since 10
     */
    getAvailableDeviceListSync(): Array<DeviceBasicInfo>;

    /**
     * Get a list of available devices. This interface query all authorized and connectable devices.
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @param { AsyncCallback<Array<DeviceBasicInfo>> } callback - Indicates the callback to be
     * invoked upon getAvailableDeviceList.
     * @returns Returns a list of available devices.
     * @throws { BusinessError } 201 - User permission verify failed.
     * @throws { BusinessError } 11600101 - Failed to execute the function.
     * @syscap SystemCapability.DistributedHardware.DeviceManager
     * @since 10
     */
    getAvailableDeviceList(callback: AsyncCallback<Array<DeviceBasicInfo>>): void;

    /**
     * Get a list of available devices. This interface query all authorized and connectable devices.
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @returns { Promise<Array<DeviceBasicInfo>> } - Returns a list of available devices.
     * @throws { BusinessError } 201 - User permission verify failed.
     * @throws { BusinessError } 11600101 - Failed to execute the function.
     * @syscap SystemCapability.DistributedHardware.DeviceManager
     * @since 10
     */
    getAvailableDeviceList(): Promise<Array<DeviceBasicInfo>>;

    /**
     * Get the network id of the local device.
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @returns { string } - Returns local device network id.
     * @throws { BusinessError } 201 - User permission verify failed.
     * @throws { BusinessError } 11600101 - Failed to execute the function.
     * @syscap SystemCapability.DistributedHardware.DeviceManager
     * @since 10
     */
    getLocalDeviceNetworkId(): string;

    /**
     * Get the device name of the local device.
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @returns { string } - Returns local device name.
     * @throws { BusinessError } 201 - User permission verify failed.
     * @throws { BusinessError } 11600101 - Failed to execute the function.
     * @syscap SystemCapability.DistributedHardware.DeviceManager
     * @since 10
     */
    getLocalDeviceName(): string;

    /**
     * Get the device type of the local device.
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @returns { number } - Returns local device type.
     * @throws { BusinessError } 201 - User permission verify failed.
     * @throws { BusinessError } 11600101 - Failed to execute the function.
     * @syscap SystemCapability.DistributedHardware.DeviceManager
     * @since 10
     */
    getLocalDeviceType(): number;

    /**
     * Get the device id of the local device.
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @returns { string } - Returns local device type.
     * @throws { BusinessError } 201 - User permission verify failed.
     * @throws { BusinessError } 11600101 - Failed to execute the function.
     * @syscap SystemCapability.DistributedHardware.DeviceManager
     * @since 10
     */
    getLocalDeviceId(): string;

    /**
     * Get the device name by network id.
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @param { string } networkId - Device network id.
     * @returns { string } - Returns device name.
     * @throws { BusinessError } 201 - User permission verify failed.
     * @throws { BusinessError } 401 - Input parameter error.
     * @throws { BusinessError } 11600101 - Failed to execute the function.
     * @syscap SystemCapability.DistributedHardware.DeviceManager
     * @since 10
     */
    getDeviceName(networkId: string): string;

    /**
     * Get the device type by network id.
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @param { string } networkId - Device network id.
     * @returns { number } - Returns device type.
     * @throws { BusinessError } 201 - User permission verify failed.
     * @throws { BusinessError } 401 - Input parameter error.
     * @throws { BusinessError } 11600101 - Failed to execute the function.
     * @syscap SystemCapability.DistributedHardware.DeviceManager
     * @since 10
     */
    getDeviceType(networkId: string): number;

    /**
     * Start to discover nearby devices.
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @param { { [key: string]: Object } } discoverParameter - Identifies the type of target discovered.
     * The type of discoverParameter is map. Currently, only one json-format string is supported:
     *         "device" : 1 - Indicates discover the nearby devices.
     * @param { { [key: string]: Object } } filterOptions - FilterOptions to filter discovery device.
     * The type of filterOptions is map. The map are as follows:
     *         "credible" : 0/1     - Discover devices only are credible, The value is 0 indicates device isn't credible;
     *                                The value is 1 indicates device is credible.
     *         "range" : 1          - Discover devices only within the range, The value less than 1 m.
     *         "isTrusted" : 0/1    - Discover devices only are trusted, The value is 0 indicates device isn't trust;
     *                                The value is 1 indicates device is trust.
     *         "authForm" : -1-2    - Discover devices only are specified authenticate type, The value can be -1 to 2.
     *                                The authenticate type are as follows: 
     *                                  -1 - Indicates invalid trusted device type.
     *                                   0 - Indicates peer to peer trusted device type without account.
     *                                   1 - Indicates identical account trusted device type.
     *                                   2 - Indicates across account trusted device type.
     * @throws { BusinessError } 401 - Input parameter error.
     * @throws { BusinessError } 201 - Permission verify failed.
     * @throws { BusinessError } 11600104 - Discovery repeats.
     * @throws { BusinessError } 11600101 - Failed to execute the function.
     * @syscap SystemCapability.DistributedHardware.DeviceManager
     * @since 10
     */
    startDiscovering(discoverParameter: { [key: string]: Object }, filterOptions?: { [key: string]: Object }): void;

    /**
     * Stop discovering nearby devices.
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @throws { BusinessError } 401 - Input parameter error.
     * @throws { BusinessError } 201 - Permission verify failed.
     * @throws { BusinessError } 11600104 - Stop discovery repeats.
     * @throws { BusinessError } 11600101 - Failed to execute the function.
     * @syscap SystemCapability.DistributedHardware.DeviceManager
     * @since 10
     */
    stopDiscovering(): void;

    /**
     * Bind the specified target.
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @param { string } deviceId - id of device to bind.
     * @param { { [key: string]: Object } } bindParam - parameters of device to bind, The parameter type is map,such as:
     *      "bindType" : 1-4,         - This value is type of bind, the values are as follows:
     *                                  1 - The bind type is pin code .
     *                                  2 - The bind type is QR code.
     *                                  3 - The bind type is nfc.
     *                                  4 - The bind type is no_interaction.

     *      "targetPkgName" : "xxxx", - The package name of binding target.
     *      "appName" : "xxxx",       - The app name that try to bind the target.
     *      "appOperation" : "xxxx"   - The reason why the app want to bind the target package.
     *      "customDescription" : "xxxx" - The detail description of the operation.
     * @param { AsyncCallback<{deviceId: string}> } callback - indicates the callback to be invoked upon bindDevice.
     * @throws { BusinessError } 401 - Input parameter error.
     * @throws { BusinessError } 201 - Permission verify failed.
     * @throws { BusinessError } 11600101 - Failed to execute the function.
     * @throws { BusinessError } 11600103 - Bind invalid.
     * @syscap SystemCapability.DistributedHardware.DeviceManager
     * @since 10
     */
    bindTarget(deviceId: string, bindParam: { [key: string]: Object }, callback: AsyncCallback<{deviceId: string}>): void;

    /**
     * Unbind the specified target.
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @param { string } deviceId - id of device to unbind
     * @throws { BusinessError } 401 - Input parameter error.
     * @throws { BusinessError } 201 - Permission verify failed.
     * @throws { BusinessError } 11600101 - Failed to execute the function.
     * @syscap SystemCapability.DistributedHardware.DeviceManager
     * @since 10
     */
    unbindTarget(deviceId: string): void;

    /**
     * The reply of ui operation from pin-code window, this interface can only be used by pin-code-hap of devicemanager.
     *
     * @permission ohos.permission.ACCESS_SERVICE_DM
     * @param { number } action - The reply action of user operation.
     * @param { string } actionResult - Indicates the user operation result.
     * @throws { BusinessError } 201 - Permission verify failed.
     * @throws { BusinessError } 202 - The caller is not a system application.
     * @throws { BusinessError } 401 - Input parameter error.
     * @syscap SystemCapability.DistributedHardware.DeviceManager
     * @systemapi this method can be used only by system applications.
     * @since 10
     */
    replyUiAction(action: number, actionResult: string): void;

    /**
     * Register a device state callback so that the application can be notified upon device state changes based on
     * the application bundle name.
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @param { 'deviceStateChange' } type - Device state change.
     * @param { Callback<{ action: DeviceStateChange, device: DeviceBasicInfo }> } callback
     * Indicates the device state callback to register.
     * @throws { BusinessError } 201 - Permission verify failed.
     * @throws { BusinessError } 401 - Input parameter error.
     * @syscap SystemCapability.DistributedHardware.DeviceManager
     * @since 10
     */
    on(type: 'deviceStateChange', callback: Callback<{ action: DeviceStateChange, device: DeviceBasicInfo }>): void;

    /**
     * UnRegister device state callback based on the application bundle name.
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @param { 'deviceStateChange' } type - Device state change.
     * @param { Callback<{ action: DeviceStateChange, device: DeviceBasicInfo }> } callback
     * Indicates the device state callback to unregister.
     * @throws { BusinessError } 201 - Permission verify failed.
     * @throws { BusinessError } 401 - Input parameter error.
     * @syscap SystemCapability.DistributedHardware.DeviceManager
     * @since 10
     */
    off(type: 'deviceStateChange', callback?: Callback<{ action: DeviceStateChange, device: DeviceBasicInfo }>): void;

    /**
     * Register a device discovery result callback so that the application can be notified when discovery success.
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @param { 'discoverSuccess' } type - Successfully discovered device.
     * @param { Callback<{ subscribeId: number, device: DeviceBasicInfo }> } callback
     * Indicates the device discovery callback to register.
     * @throws { BusinessError } 201 - Permission verify failed.
     * @throws { BusinessError } 401 - Input parameter error.
     * @syscap SystemCapability.DistributedHardware.DeviceManager
     * @since 10
     */
    on(type: 'discoverSuccess', callback: Callback<{ device: DeviceBasicInfo }>): void;

    /**
     * UnRegister the device discovery result callback.
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @param { 'discoverSuccess' } type - Successfully discovered device.
     * @param { Callback<{ subscribeId: number, device: DeviceBasicInfo }> } callback
     * Indicates the device discovery callback to unregister.
     * @throws { BusinessError } 201 - Permission verify failed.
     * @throws { BusinessError } 401 - Input parameter error.
     * @syscap SystemCapability.DistributedHardware.DeviceManager
     * @since 10
     */
    off(type: 'discoverSuccess', callback?: Callback<{ device: DeviceBasicInfo }>): void;

    /**
     * Register a device name change callback so that the application can be notified when discovery success.
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @param { 'deviceNameChange' } type - Changed device name.
     * @param { Callback<{ deviceName: string }> } callback - Indicates the device name change callback to register.
     * @throws { BusinessError } 201 - Permission verify failed.
     * @throws { BusinessError } 401 - Input parameter error.
     * @syscap SystemCapability.DistributedHardware.DeviceManager
     * @since 10
     */
    on(type: 'deviceNameChange', callback: Callback<{ deviceName: string }>): void;

    /**
     * UnRegister the device name change result callback.
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @param { 'deviceNameChange' } type - Changed device name.
     * @param { Callback<{ deviceName: string }> } callback - Indicates the device name change callback to unregister.
     * @throws { BusinessError } 201 - Permission verify failed.
     * @throws { BusinessError } 401 - Input parameter error.
     * @syscap SystemCapability.DistributedHardware.DeviceManager
     * @since 10
     */
    off(type: 'deviceNameChange', callback?: Callback<{ deviceName: string }>): void;

    /**
     * Register a device discovery result callback so that the application can be notified when discover failed.
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @param { 'discoverFail' } type - Discovery Device Failure.
     * @param { Callback<{ subscribeId: number, reason: number }> } callback
     * Indicates the device found result callback to register.
     * @throws { BusinessError } 201 - Permission verify failed.
     * @throws { BusinessError } 401 - Input parameter error.
     * @syscap SystemCapability.DistributedHardware.DeviceManager
     * @since 10
     */
    on(type: 'discoverFail', callback: Callback<{ reason: number }>): void;

    /**
     * UnRegister the device discovery result callback.
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @param { 'discoverFail' } type - Discovery Device Failure.
     * @param { Callback<{ subscribeId: number, reason: number }> } callback
     * Indicates the device found result callback to unregister.
     * @throws { BusinessError } 201 - Permission verify failed.
     * @throws { BusinessError } 401 - Input parameter error.
     * @syscap SystemCapability.DistributedHardware.DeviceManager
     * @since 10
     */
    off(type: 'discoverFail', callback?: Callback<{ reason: number }>): void;

    /**
     * Register a serviceError callback so that the application can be notified when devicemanager service died
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @param { 'serviceDie' } type - Service death.
     * @param { Callback<{}> } callback - Indicates the service error callback to register.
     * @throws { BusinessError } 201 - Permission verify failed.
     * @throws { BusinessError } 401 - Input parameter error.
     * @syscap SystemCapability.DistributedHardware.DeviceManager
     * @since 10
     */
    on(type: 'serviceDie', callback?: Callback<{}>): void;

    /**
     * UnRegister the service error callback.
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @param { 'serviceDie' } type - Service death.
     * @param { Callback<{}> } callback - Indicates the service error callback to unregister.
     * @throws { BusinessError } 201 - Permission verify failed.
     * @throws { BusinessError } 401 - Input parameter error.
     * @syscap SystemCapability.DistributedHardware.DeviceManager
     * @since 10
     */
    off(type: 'serviceDie', callback?: Callback<{}>): void;

    /**
     * Register a callback from deviceManager service so that the devicemanager ui can be notified when uiStateChanges.
     *
     * @permission ohos.permission.ACCESS_SERVICE_DM
     * @param { 'replyResult' } type - Ui reply result to register.
     * @param { Callback<{ param: string }> } callback - Indicates the devicemanager ui state to register.
     * @throws { BusinessError } 401 - Input parameter error.
     * @throws { BusinessError } 202 - The caller is not a system application.
     * @syscap SystemCapability.DistributedHardware.DeviceManager
     * @systemapi this method can be used only by system applications.
     * @since 10
     */
    on(type: 'replyResult', callback: Callback<{ param: string }>): void;

    /**
      * Unregister uiStateChange, this interface can only be used by devicemanager ui.
      *
      * @permission ohos.permission.ACCESS_SERVICE_DM
      * @param { 'replyResult' } type - Ui reply result to unregister.
      * @param { Callback<{ param: string }> } callback - Indicates the devicemanager ui state to unregister.
      * @throws { BusinessError } 401 - Input parameter error.
      * @throws { BusinessError } 202 - The caller is not a system application. 
      * @syscap SystemCapability.DistributedHardware.DeviceManager
      * @systemapi this method can be used only by system applications.
      * @since 10
      */
    off(type: 'replyResult', callback?: Callback<{ param: string }>): void;
  }
}

export default distributedDeviceManager;