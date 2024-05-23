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
 * @kit DriverDevelopmentKit
 */

import type { AsyncCallback } from './@ohos.base';
import type rpc from './@ohos.rpc';

/**
 * This module provides the capability of manage external device.
 *
 * @namespace deviceManager
 * @syscap SystemCapability.Driver.ExternalDevice
 * @since 10
 */
declare namespace deviceManager {
  /**
   * Query the external device list.
   *
   * @permission ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER
   * @param { number } busType - The bus type of device to be queried.
   * @returns { Array<Readonly<Device>> } External device list.
   * @throws { BusinessError } 401 - The parameter check failed.
   * @throws { BusinessError } 22900001 - ExternalDeviceManager service exception.
   * @syscap SystemCapability.Driver.ExternalDevice
   * @since 10
   */
  function queryDevices(busType?: number): Array<Readonly<Device>>;

  /**
   * Bind the device based on the device information returned by queryDevices().
   *
   * @permission ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER
   * @param { number } deviceId - Device id on the device list returned by queryDevices().
   * @param { AsyncCallback<number> } onDisconnect - Callback is invoked when device is disconnected after bind
   * success.
   * @param { AsyncCallback<{deviceId: number, remote: rpc.IRemoteObject}> } callback - Indicates the bind result
   * including device ID and remote object.
   * @throws { BusinessError } 401 - Parameter error. Possible casues: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.
   * 3.Parameter verification failed.
   * @throws { BusinessError } 22900001 - ExternalDeviceManager service exception.
   * @syscap SystemCapability.Driver.ExternalDevice
   * @since 10
   */
  function bindDevice(deviceId: number, onDisconnect: AsyncCallback<number>,
    callback: AsyncCallback<{deviceId: number, remote: rpc.IRemoteObject}>): void;

  /**
   * Bind the device based on the device information returned by queryDevices().
   *
   * @permission ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER
   * @param { number } deviceId - Device id on the device list returned by queryDevices().
   * @param { AsyncCallback<number> } onDisconnect - Callback is invoked when device is disconnected after bind
   * success.
   * @param { AsyncCallback<RemoteDeviceDriver> } callback - Indicates the bind result including device ID and
   * remote object.
   * @throws { BusinessError } 401 - Parameter error. Possible casues: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.
   * 3.Parameter verification failed.
   * @throws { BusinessError } 22900001 - ExternalDeviceManager service exception.
   * @syscap SystemCapability.Driver.ExternalDevice
   * @since 11
   */
  function bindDeviceDriver(deviceId: number, onDisconnect: AsyncCallback<number>,
    callback: AsyncCallback<RemoteDeviceDriver>): void;

  /**
   * Bind the device based on the device information returned by queryDevices().
   *
   * @permission ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER
   * @param { number } deviceId - Device id on the device list returned by queryDevices().
   * @param { AsyncCallback<number> } onDisconnect - Callback is invoked when device is disconnected after bind
   * success.
   * @returns { Promise<{deviceId: number, remote: rpc.IRemoteObject}> } Indicates the bind result including device
   * ID and remote object.
   * @throws { BusinessError } 401 - Parameter error. Possible casues: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.
   * 3.Parameter verification failed.
   * @throws { BusinessError } 22900001 - ExternalDeviceManager service exception.
   * @syscap SystemCapability.Driver.ExternalDevice
   * @since 10
   */
  function bindDevice(deviceId: number, onDisconnect: AsyncCallback<number>): Promise<{deviceId: number,
    remote: rpc.IRemoteObject}>;

  /**
   * Bind the device based on the device information returned by queryDevices().
   *
   * @permission ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER
   * @param { number } deviceId - Device id on the device list returned by queryDevices().
   * @param { AsyncCallback<number> } onDisconnect - Callback is invoked when device is disconnected after bind
   * success.
   * @returns { Promise<RemoteDeviceDriver> } Indicates the bind result including device ID and remote object.
   * @throws { BusinessError } 401 - Parameter error. Possible casues: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.
   * 3.Parameter verification failed.
   * @throws { BusinessError } 22900001 - ExternalDeviceManager service exception.
   * @syscap SystemCapability.Driver.ExternalDevice
   * @since 11
   */
  function bindDeviceDriver(deviceId: number, onDisconnect: AsyncCallback<number>): Promise<RemoteDeviceDriver>;

  /**
   * Unbind the device based on the device information returned by queryDevices().
   *
   * @permission ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER
   * @param { number } deviceId - Device id on the device list returned by queryDevices().
   * @param { AsyncCallback<number> } callback - Indicates the unbind result invoked when unbind is finished.
   * @throws { BusinessError } 401 - Parameter error. Possible casues: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.
   * @throws { BusinessError } 22900001 - ExternalDeviceManager service exception.
   * @syscap SystemCapability.Driver.ExternalDevice
   * @since 10
   */
  function unbindDevice(deviceId: number, callback: AsyncCallback<number>): void;

  /**
   * Unbind the device based on the device information returned by queryDevices().
   *
   * @permission ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER
   * @param { number } deviceId - Device id on the device list returned by queryDevices().
   * @returns { Promise<number> } - Indicates the unbind result invoked when unbind is finished.
  * @throws { BusinessError } 401 - Parameter error. Possible casues: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.
   * 3.Parameter verification failed.
   * @throws { BusinessError } 22900001 - ExternalDeviceManager service exception.
   * @syscap SystemCapability.Driver.ExternalDevice
   * @since 10
   */
  function unbindDevice(deviceId: number): Promise<number>;

  /**
   * Queries external device information.
   *
   * @permission ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER
   * @param { number } deviceId - ID of device to query.
   * @returns { Array<Readonly<DeviceInfo>> } Device information obtained.
   * @throws { BusinessError } 201 - The permission check failed.
   * @throws { BusinessError } 202 - Permission denied. A non-system application cannot call a system API.
   * @throws { BusinessError } 401 - Parameter error. Possible casues: 1.Incorrect parameter types.
   * @throws { BusinessError } 26300001 - ExternalDeviceManager service exception.
   * @syscap SystemCapability.Driver.ExternalDevice
   * @systemapi
   * @since 12
   */
  function queryDeviceInfo(deviceId?: number): Array<Readonly<DeviceInfo>>;

  /**
   * Queries driver information.
   *
   * @permission ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER
   * @param { string } driverUid - Unique identifier of driver query.
   * @returns { Array<Readonly<DriverInfo>> } Driver information obtained.
   * @throws { BusinessError } 201 - The permission check failed.
   * @throws { BusinessError } 202 - Permission denied. A non-system application cannot call a system API.
   * @throws { BusinessError } 401 - Parameter error. Possible casues: 1.Incorrect parameter types.
   * @throws { BusinessError } 26300001 - ExternalDeviceManager service exception.
   * @syscap SystemCapability.Driver.ExternalDevice
   * @systemapi
   * @since 12
   */
  function queryDriverInfo(driverUid?: string): Array<Readonly<DriverInfo>>;

  /**
   * Enumerates the bus types.
   *
   * @enum { number }
   * @syscap SystemCapability.Driver.ExternalDevice
   * @since 10
   */
  export enum BusType {
    /**
     * USB device type
     *
     * @syscap SystemCapability.Driver.ExternalDevice
     * @since 10
     */
    USB = 1,
  }

  /**
   * Represents a device.
   *
   * @typedef Device
   * @syscap SystemCapability.Driver.ExternalDevice
   * @since 10
   */
  interface Device {
    /**
     * Bus type of the device.
     *
     * @syscap SystemCapability.Driver.ExternalDevice
     * @since 10
     */
    busType: BusType;

    /**
     * Device ID.
     *
     * @syscap SystemCapability.Driver.ExternalDevice
     * @since 10
     */
    deviceId: number;

    /**
     * Description of the device.
     *
     * @syscap SystemCapability.Driver.ExternalDevice
     * @since 10
     */
    description: string;
  }

  /**
   * Represents a USB device.
   *
   * @typedef USBDevice
   * @syscap SystemCapability.Driver.ExternalDevice
   * @since 10
   */
  interface USBDevice extends Device {
    /**
     * Vendor ID.
     *
     * @syscap SystemCapability.Driver.ExternalDevice
     * @since 10
     */
    vendorId: number;

    /**
     * Product ID.
     *
     * @syscap SystemCapability.Driver.ExternalDevice
     * @since 10
     */
    productId: number;
  }
  
  /**
   * Driver of the remote device bound with <b>deviceId</b>.
   *
   * @typedef RemoteDeviceDriver
   * @syscap SystemCapability.Driver.ExternalDevice
   * @since 11
   */
  interface RemoteDeviceDriver {
    /**
     * Device ID.
     *
     * @syscap SystemCapability.Driver.ExternalDevice
     * @since 11
     */
    deviceId: number;

    /**
     * Remote driver object.
     *
     * @syscap SystemCapability.Driver.ExternalDevice
     * @since 11
     */
    remote: rpc.IRemoteObject;
  }

  /**
   * Represents information about a device interface descriptor.
   *
   * @typedef USBInterfaceDesc
   * @syscap SystemCapability.Driver.ExternalDevice
   * @systemapi
   * @since 12
   */
  interface USBInterfaceDesc {
    /**
     * Interface number.
     *
     * @syscap SystemCapability.Driver.ExternalDevice
     * @systemapi
     * @since 12
     */
    bInterfaceNumber: number;

    /**
     * Interface class code.
     *
     * @syscap SystemCapability.Driver.ExternalDevice
     * @systemapi
     * @since 12
     */
    bClass: number;

    /**
     * Interface subclass code.
     *
     * @syscap SystemCapability.Driver.ExternalDevice
     * @systemapi
     * @since 12
     */
    bSubClass: number;

    /**
     * Interface protocol.
     *
     * @syscap SystemCapability.Driver.ExternalDevice
     * @systemapi
     * @since 12
     */
    bProtocol: number;
  }


  /**
   * Represents the device information.
   *
   * @typedef DeviceInfo
   * @syscap SystemCapability.Driver.ExternalDevice
   * @systemapi
   * @since 12
   */
  interface DeviceInfo {
    /**
     * Device ID.
     *
     * @syscap SystemCapability.Driver.ExternalDevice
     * @systemapi
     * @since 12
     */
    deviceId: number;

    /**
     * Whether the device has a matched driver.
     *
     * @syscap SystemCapability.Driver.ExternalDevice
     * @systemapi
     * @since 12
     */
    isDriverMatched: boolean;

    /**
     * Unique identifier of the driver.
     *
     * @syscap SystemCapability.Driver.ExternalDevice
     * @systemapi
     * @since 12
     */
    driverUid?: string;
  }

  /**
   * Represents the USB device information.
   *
   * @typedef USBDeviceInfo
   * @syscap SystemCapability.Driver.ExternalDevice
   * @systemapi
   * @since 12
   */
  interface USBDeviceInfo extends DeviceInfo {
    /**
     * Vendor ID.
     *
     * @syscap SystemCapability.Driver.ExternalDevice
     * @systemapi
     * @since 12
     */
    vendorId: number;

    /**
     * Product ID.
     *
     * @syscap SystemCapability.Driver.ExternalDevice
     * @systemapi
     * @since 12
     */
    productId: number;

    /**
     * List of USB interface descriptors.
     *
     * @syscap SystemCapability.Driver.ExternalDevice
     * @systemapi
     * @since 12
     */
    interfaceDescList: Array<Readonly<USBInterfaceDesc>>;
  }

  /**
   * Represents the driver information.
   *
   * @typedef DriverInfo
   * @syscap SystemCapability.Driver.ExternalDevice
   * @systemapi
   * @since 12
   */
  interface DriverInfo {
    /**
     * Bus type of the device.
     *
     * @syscap SystemCapability.Driver.ExternalDevice
     * @systemapi
     * @since 12
     */
    busType: BusType;

    /**
     * Unique identifier of the driver.
     *
     * @syscap SystemCapability.Driver.ExternalDevice
     * @systemapi
     * @since 12
     */
    driverUid: string;

    /**
     * Driver name.
     *
     * @syscap SystemCapability.Driver.ExternalDevice
     * @systemapi
     * @since 12
     */
    driverName: string;

    /**
     * Driver version.
     *
     * @syscap SystemCapability.Driver.ExternalDevice
     * @systemapi
     * @since 12
     */
    driverVersion: string;

    /**
     * Driver size.
     *
     * @syscap SystemCapability.Driver.ExternalDevice
     * @systemapi
     * @since 12
     */
    driverSize: string;

    /**
     * Driver description.
     *
     * @syscap SystemCapability.Driver.ExternalDevice
     * @systemapi
     * @since 12
     */
    description: string;
  }

  /**
   * Represents the USB driver information.
   *
   * @typedef USBDriverInfo
   * @syscap SystemCapability.Driver.ExternalDevice
   * @systemapi
   * @since 12
   */
  interface USBDriverInfo extends DriverInfo {
    /**
     * IDs of supported products.
     *
     * @syscap SystemCapability.Driver.ExternalDevice
     * @systemapi
     * @since 12
     */
    productIdList: Array<number>;

    /**
     * IDs of supported vendors.
     *
     * @syscap SystemCapability.Driver.ExternalDevice
     * @systemapi
     * @since 12
     */
    vendorIdList: Array<number>;
  }
}

export default deviceManager;
