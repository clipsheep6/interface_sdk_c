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
 * @kit MDMKit
 */

import type Want from './@ohos.app.ability.Want';

/**
 * This module provides the capability to manage the location of the enterprise devices.
 *
 * @namespace locationManager
 * @syscap SystemCapability.Customization.EnterpriseDeviceManager
 * @systemapi
 * @stagemodelonly
 * @since 11
 */
declare namespace locationManager {
  /**
   * The location policy.
   *
   * @enum { number }
   * @syscap SystemCapability.Customization.EnterpriseDeviceManager
   * @systemapi
   * @stagemodelonly
   * @since 11
   */
  export enum LocationPolicy {
    /**
     * Default location service.
     *
     * @syscap SystemCapability.Customization.EnterpriseDeviceManager
     * @systemapi
     * @stagemodelonly
     * @since 11
     */
    DEFAULT_LOCATION_SERVICE = 0,

    /**
     * Disallows open location service.
     *
     * @syscap SystemCapability.Customization.EnterpriseDeviceManager
     * @systemapi
     * @stagemodelonly
     * @since 11
     */
    DISALLOW_LOCATION_SERVICE = 1,

    /**
     * Force open the location service.
     *
     * @syscap SystemCapability.Customization.EnterpriseDeviceManager
     * @systemapi
     * @stagemodelonly
     * @since 11
     */
    FORCE_OPEN_LOCATION_SERVICE = 2,
  }

  /**
   * Sets the policy of location service.
   * This function can be called by a super administrator.
   *
   * @permission ohos.permission.ENTERPRISE_MANAGE_LOCATION
   * @param { Want } admin - admin indicates the administrator ability information.
   * @param { LocationPolicy } policy - the policy of location service.
   * @throws { BusinessError } 9200001 - the application is not an administrator of the device.
   * @throws { BusinessError } 9200002 - the administrator application does not have permission to manage the device.
   * @throws { BusinessError } 201 - the application does not have permission to call this function.
   * @throws { BusinessError } 202 - not system application.
   * @throws { BusinessError } 401 - invalid input parameter.
   * @syscap SystemCapability.Customization.EnterpriseDeviceManager
   * @systemapi
   * @stagemodelonly
   * @since 11
   */
  function setLocationPolicy(admin: Want, policy: LocationPolicy): void;

  /**
   * Gets device location service policy.
   * This function can be called by a super administrator.
   *
   * @permission ohos.permission.ENTERPRISE_MANAGE_LOCATION
   * @param { Want } admin - admin indicates the administrator ability information.
   * @returns { LocationPolicy } the policy of location service.
   * @throws { BusinessError } 9200001 - the application is not an administrator of the device.
   * @throws { BusinessError } 9200002 - the administrator application does not have permission to manage the device.
   * @throws { BusinessError } 201 - the application does not have permission to call this function.
   * @throws { BusinessError } 202 - not system application.
   * @throws { BusinessError } 401 - invalid input parameter.
   * @syscap SystemCapability.Customization.EnterpriseDeviceManager
   * @systemapi
   * @stagemodelonly
   * @since 11
   */
  function getLocationPolicy(admin: Want): LocationPolicy;
}

export default locationManager;
