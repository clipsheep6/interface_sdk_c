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

import { AsyncCallback } from './@ohos.base';
import { ApplicationInfo } from './bundle/applicationInfo';
import { AbilityInfo } from './bundle/abilityInfo';
import { PermissionDef } from './bundle/PermissionDef';
import Want from './@ohos.app.ability.Want';
import image from './@ohos.multimedia.image';
import { BundleInfo } from './bundle/bundleInfo';
import { BundleInstaller } from './bundle/bundleInstaller';

/**
 * bundle.
 *
 * @namespace bundle
 * @syscap SystemCapability.BundleManager.BundleFramework
 * @since 7
 * @deprecated since 9
 * @useinstead ohos.bundle.bundleManager
 */
declare namespace bundle {
  /**
   * BundleFlag
   *
   * @enum { number }
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 7
   * @deprecated since 9
   * @useinstead ohos.bundle.bundleManager.BundleFlag
   */
  /**
   * BundleFlag
   *
   * @enum { number }
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @atomicservice
   * @since 11
   * @deprecated since 9
   * @useinstead ohos.bundle.bundleManager.BundleFlag
   */
  enum BundleFlag {
    /**
     * GET_BUNDLE_DEFAULT
     *
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.bundle.bundleManager.BundleFlag
     */
    /**
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @atomicservice
     * @since 11
     * @deprecated since 9
     * @useinstead ohos.bundle.bundleManager.BundleFlag
     */
    GET_BUNDLE_DEFAULT = 0x00000000,
    /**
     * GET_BUNDLE_WITH_ABILITIES
     *
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.bundle.bundleManager.BundleFlag
     */
    /**
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @atomicservice
     * @since 11
     * @deprecated since 9
     * @useinstead ohos.bundle.bundleManager.BundleFlag
     */
    GET_BUNDLE_WITH_ABILITIES = 0x00000001,
    /**
     * GET_ABILITY_INFO_WITH_PERMISSION
     *
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.bundle.bundleManager.BundleFlag
     */
    /**
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @atomicservice
     * @since 11
     * @deprecated since 9
     * @useinstead ohos.bundle.bundleManager.BundleFlag
     */
    GET_ABILITY_INFO_WITH_PERMISSION = 0x00000002,
    /**
     * GET_ABILITY_INFO_WITH_APPLICATION
     *
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.bundle.bundleManager.BundleFlag
     */
    /**
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @atomicservice
     * @since 11
     * @deprecated since 9
     * @useinstead ohos.bundle.bundleManager.BundleFlag
     */
    GET_ABILITY_INFO_WITH_APPLICATION = 0x00000004,
    /**
     * GET_APPLICATION_INFO_WITH_PERMISSION
     *
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.bundle.bundleManager.BundleFlag
     */
    /**
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @atomicservice
     * @since 11
     * @deprecated since 9
     * @useinstead ohos.bundle.bundleManager.BundleFlag
     */
    GET_APPLICATION_INFO_WITH_PERMISSION = 0x00000008,
    /**
     * GET_BUNDLE_WITH_REQUESTED_PERMISSION
     *
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.bundle.bundleManager.BundleFlag
     */
    /**
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @atomicservice
     * @since 11
     * @deprecated since 9
     * @useinstead ohos.bundle.bundleManager.BundleFlag
     */
    GET_BUNDLE_WITH_REQUESTED_PERMISSION = 0x00000010,
    /**
     * GET_ALL_APPLICATION_INFO
     *
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.bundle.bundleManager.BundleFlag
     */
    /**
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @atomicservice
     * @since 11
     * @deprecated since 9
     * @useinstead ohos.bundle.bundleManager.BundleFlag
     */
    GET_ALL_APPLICATION_INFO = 0xFFFF0000,
    /**
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @since 8
     * @deprecated since 9
     */
    GET_ABILITY_INFO_WITH_METADATA = 0x00000020,
    /**
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @since 8
     * @deprecated since 9
     */
    GET_APPLICATION_INFO_WITH_METADATA = 0x00000040,
    /**
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @since 8
     * @deprecated since 9
     */
    GET_ABILITY_INFO_SYSTEMAPP_ONLY = 0x00000080,
    /**
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @since 8
     * @deprecated since 9
     */
    GET_ABILITY_INFO_WITH_DISABLE = 0x00000100,
    /**
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @since 8
     * @deprecated since 9
     */
    GET_APPLICATION_INFO_WITH_DISABLE = 0x00000200
  }

  /**
   * ColorMode
   *
   * @enum { number }
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 7
   * @deprecated since 9
   */
  /**
   * ColorMode
   *
   * @enum { number }
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @atomicservice
   * @since 11
   * @deprecated since 9
   */
  export enum ColorMode {
    /**
     * AUTO_MODE
     *
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @since 7
     * @deprecated since 9
     */
    /**
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @atomicservice
     * @since 11
     * @deprecated since 9
     */
    AUTO_MODE = -1,
    /**
     * DARK_MODE
     *
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @since 7
     * @deprecated since 9
     */
    /**
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @atomicservice
     * @since 11
     * @deprecated since 9
     */
    DARK_MODE = 0,
    /**
     * LIGHT_MODE
     *
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @since 7
     * @deprecated since 9
     */
    /**
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @atomicservice
     * @since 11
     * @deprecated since 9
     */
    LIGHT_MODE = 1
  }

  /**
   * GrantStatus
   *
   * @enum { number }
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 7
   * @deprecated since 9
   * @useinstead ohos.bundle.bundleManager.PermissionGrantState
   */
  /**
   * GrantStatus
   *
   * @enum { number }
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @atomicservice
   * @since 11
   * @deprecated since 9
   * @useinstead ohos.bundle.bundleManager.PermissionGrantState
   */
  export enum GrantStatus {
    /**
     * PERMISSION_DENIED
     *
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.bundle.bundleManager.PermissionGrantState
     */
    /**
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @atomicservice
     * @since 11
     * @deprecated since 9
     * @useinstead ohos.bundle.bundleManager.PermissionGrantState
     */
    PERMISSION_DENIED = -1,
    /**
     * PERMISSION_GRANTED
     *
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @since 7
     * @deprecated since 9
     * @useinstead ohos.bundle.bundleManager.PermissionGrantState
     */
    /**
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @atomicservice
     * @since 11
     * @deprecated since 9
     * @useinstead ohos.bundle.bundleManager.PermissionGrantState
     */
    PERMISSION_GRANTED = 0
  }

  /**
   * AbilityType
   *
   * @enum { number }
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 7
   * @deprecated since 9
   * @useinstead ohos.bundle.bundleManager.AbilityType
   */
  /**
   * AbilityType
   *
   * @enum { number }
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @atomicservice
   * @since 11
   * @deprecated since 9
   * @useinstead ohos.bundle.bundleManager.AbilityType
   */
  export enum AbilityType {
    /**
     * Indicates an unknown ability type
     *
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @since 7
     * @deprecated since 9
     */
    /**
     * Indicates an unknown ability type
     *
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @atomicservice
     * @since 11
     * @deprecated since 9
     */
    UNKNOWN,

    /**
     * Indicates that the ability has a UI
     *
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @since 7
     * @deprecated since 9
     */
    /**
     * Indicates that the ability has a UI
     *
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @atomicservice
     * @since 11
     * @deprecated since 9
     */
    PAGE,

    /**
     * Indicates that the ability does not have a UI
     *
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @since 7
     * @deprecated since 9
     */
    /**
     * Indicates that the ability does not have a UI
     *
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @atomicservice
     * @since 11
     * @deprecated since 9
     */
    SERVICE,

    /**
     * Indicates that the ability is used to provide data access services
     *
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @since 7
     * @deprecated since 9
     */
    /**
     * Indicates that the ability is used to provide data access services
     *
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @atomicservice
     * @since 11
     * @deprecated since 9
     */
    DATA
  }

  /**
   * AbilitySubType
   *
   * @enum { number }
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 7
   * @deprecated since 9
   */
  /**
   * AbilitySubType
   *
   * @enum { number }
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @atomicservice
   * @since 11
   * @deprecated since 9
   */
  export enum AbilitySubType {
    /**
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @since 7
     * @deprecated since 9
     */
    /**
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @atomicservice
     * @since 11
     * @deprecated since 9
     */
    UNSPECIFIED = 0,
    /**
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @since 7
     * @deprecated since 9
     */
    /**
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @atomicservice
     * @since 11
     * @deprecated since 9
     */
    CA = 1
  }

  /**
   * DisplayOrientation
   *
   * @enum { number }
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 7
   * @deprecated since 9
   * @useinstead ohos.bundle.bundleManager.DisplayOrientation
   */
  /**
   * DisplayOrientation
   *
   * @enum { number }
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @atomicservice
   * @since 11
   * @deprecated since 9
   * @useinstead ohos.bundle.bundleManager.DisplayOrientation
   */
  export enum DisplayOrientation {
    /**
     * Indicates that the system automatically determines the display orientation
     *
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @since 7
     * @deprecated since 9
     */
    /**
     * Indicates that the system automatically determines the display orientation
     *
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @atomicservice
     * @since 11
     * @deprecated since 9
     */
    UNSPECIFIED,

    /**
     * Indicates the landscape orientation
     *
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @since 7
     * @deprecated since 9
     */
    /**
     * Indicates the landscape orientation
     *
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @atomicservice
     * @since 11
     * @deprecated since 9
     */
    LANDSCAPE,

    /**
     * Indicates the portrait orientation
     *
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @since 7
     * @deprecated since 9
     */
    /**
     * Indicates the portrait orientation
     *
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @atomicservice
     * @since 11
     * @deprecated since 9
     */
    PORTRAIT,

    /**
     * Indicates the page ability orientation is the same as that of the nearest ability in the stack
     *
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @since 7
     * @deprecated since 9
     */
    /**
     * Indicates the page ability orientation is the same as that of the nearest ability in the stack
     *
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @atomicservice
     * @since 11
     * @deprecated since 9
     */
    FOLLOW_RECENT
  }

  /**
   * LaunchMode
   *
   * @enum { number }
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 7
   * @deprecated since 9
   * @useinstead ohos.bundle.bundleManager.LaunchType
   */
  /**
   * LaunchMode
   *
   * @enum { number }
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @atomicservice
   * @since 11
   * @deprecated since 9
   * @useinstead ohos.bundle.bundleManager.LaunchType
   */
  export enum LaunchMode {
    /**
     * Indicates that the ability has only one instance
     *
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @since 7
     * @deprecated since 9
     */
    /**
     * Indicates that the ability has only one instance
     *
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @atomicservice
     * @since 11
     * @deprecated since 9
     */
    SINGLETON = 0,

    /**
     * Indicates that the ability can have multiple instances
     *
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @since 7
     * @deprecated since 9
     */
    /**
     * Indicates that the ability can have multiple instances
     *
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @atomicservice
     * @since 11
     * @deprecated since 9
     */
    STANDARD = 1
  }

  /**
   * BundleOptions
   *
   * @typedef BundleOptions
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 7
   * @deprecated since 9
   */
  export interface BundleOptions {
    /**
     * Indicates the user id
     *
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @since 7
     * @deprecated since 9
     */
    userId?: number;
  }

  /**
   * InstallErrorCode
   *
   * @enum { number }
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 7
   * @deprecated since 9
   */
  export enum InstallErrorCode {
    SUCCESS = 0,
    STATUS_INSTALL_FAILURE = 1,
    STATUS_INSTALL_FAILURE_ABORTED = 2,
    STATUS_INSTALL_FAILURE_INVALID = 3,
    STATUS_INSTALL_FAILURE_CONFLICT = 4,
    STATUS_INSTALL_FAILURE_STORAGE = 5,
    STATUS_INSTALL_FAILURE_INCOMPATIBLE = 6,
    STATUS_UNINSTALL_FAILURE = 7,
    STATUS_UNINSTALL_FAILURE_BLOCKED = 8,
    STATUS_UNINSTALL_FAILURE_ABORTED = 9,
    STATUS_UNINSTALL_FAILURE_CONFLICT = 10,
    STATUS_INSTALL_FAILURE_DOWNLOAD_TIMEOUT = 0x0B,
    STATUS_INSTALL_FAILURE_DOWNLOAD_FAILED = 0x0C,
    /**
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @since 8
     * @deprecated since 9
     */
    STATUS_RECOVER_FAILURE_INVALID = 0x0D,
    /**
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @since 7
     * @deprecated since 9
     */
    STATUS_ABILITY_NOT_FOUND = 0x40,
    /**
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @since 7
     * @deprecated since 9
     */
    STATUS_BMS_SERVICE_ERROR = 0x41,
    /**
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @since 8
     * @deprecated since 9
     */
    STATUS_FAILED_NO_SPACE_LEFT = 0x42,
    /**
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @since 8
     * @deprecated since 9
     */
    STATUS_GRANT_REQUEST_PERMISSIONS_FAILED = 0x43,
    /**
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @since 8
     * @deprecated since 9
     */
    STATUS_INSTALL_PERMISSION_DENIED = 0x44,
    /**
     * @syscap SystemCapability.BundleManager.BundleFramework
     * @since 8
     * @deprecated since 9
     */
    STATUS_UNINSTALL_PERMISSION_DENIED = 0x45
  }

  /**
   * Obtains bundleInfo based on bundleName, bundleFlags and options.
   *
   * @permission ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO
   * @param { string } bundleName - Indicates the application bundle name to be queried.
   * @param { number } bundleFlags - Indicates the application bundle flags to be queried.
   * @param { BundleOptions } options Indicates the bundle options object.
   * @param { AsyncCallback<BundleInfo> } callback
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 7
   * @deprecated since 9
   */
  function getBundleInfo(bundleName: string,
    bundleFlags: number, options: BundleOptions, callback: AsyncCallback<BundleInfo>): void;

  /**
   * Obtains bundleInfo based on bundleName, bundleFlags and options.
   *
   * @permission ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO
   * @param { string } bundleName - Indicates the application bundle name to be queried.
   * @param { number } bundleFlags - Indicates the application bundle flags to be queried.
   * @param { AsyncCallback<BundleInfo> } callback
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 7
   * @deprecated since 9
   */
  function getBundleInfo(bundleName: string, bundleFlags: number, callback: AsyncCallback<BundleInfo>): void;

  /**
   * Obtains bundleInfo based on bundleName, bundleFlags and options.
   *
   * @permission ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO
   * @param { string } bundleName - Indicates the application bundle name to be queried.
   * @param { number } bundleFlags - Indicates the application bundle flags to be queried.
   * @param { BundleOptions } options Indicates the bundle options object.
   * @returns { Promise<BundleInfo> } Returns the BundleInfo object.
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 7
   * @deprecated since 9
   */
  function getBundleInfo(bundleName: string, bundleFlags: number, options?: BundleOptions): Promise<BundleInfo>;

  /**
   * Obtains the interface used to install bundles.
   *
   * @permission ohos.permission.INSTALL_BUNDLE
   * @param { AsyncCallback<BundleInstaller> } callback
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @systemapi Hide this for inner system use
   * @since 7
   * @deprecated since 9
   * @useinstead ohos.bundle.installer#getBundleInstaller
   */
  function getBundleInstaller(callback: AsyncCallback<BundleInstaller>): void;

  /**
   * Obtains the interface used to install bundles.
   *
   * @permission ohos.permission.INSTALL_BUNDLE
   * @returns { Promise<BundleInstaller> } Returns the IBundleInstaller interface.
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @systemapi Hide this for inner system use
   * @since 7
   * @deprecated since 9
   * @useinstead ohos.bundle.installer#getBundleInstaller
   */
  function getBundleInstaller(): Promise<BundleInstaller>;

  /**
   * Obtains information about the current ability.
   *
   * @permission ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO
   * @param { string } bundleName - Indicates the application bundle name to be queried.
   * @param { string } abilityName - Indicates the ability name.
   * @param { AsyncCallback<AbilityInfo> } callback
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 7
   * @deprecated since 9
   */
  function getAbilityInfo(bundleName: string, abilityName: string, callback: AsyncCallback<AbilityInfo>): void;

  /**
   * Obtains information about the current ability.
   *
   * @permission ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO
   * @param { string } bundleName - Indicates the application bundle name to be queried.
   * @param { string } abilityName - Indicates the ability name.
   * @returns { Promise<AbilityInfo> } Returns the AbilityInfo object for the current ability.
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 7
   * @deprecated since 9
   */
  function getAbilityInfo(bundleName: string, abilityName: string): Promise<AbilityInfo>;

  /**
   * Obtains based on a given bundle name.
   *
   * @permission ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO
   * @param { string } bundleName - Indicates the application bundle name to be queried.
   * @param { number } bundleFlags - Indicates the flag used to specify information contained
   *                                 in the ApplicationInfo object that will be returned.
   * @param { number } userId - Indicates the user ID or do not pass user ID.
   * @param { AsyncCallback<ApplicationInfo> } callback
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 7
   * @deprecated since 9
   */
  function getApplicationInfo(bundleName: string,
    bundleFlags: number, userId: number, callback: AsyncCallback<ApplicationInfo>): void;

  /**
   * Obtains based on a given bundle name.
   *
   * @permission ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO
   * @param { string } bundleName - Indicates the application bundle name to be queried.
   * @param { number } bundleFlags - Indicates the flag used to specify information contained
   *                                 in the ApplicationInfo object that will be returned.
   * @param { AsyncCallback<ApplicationInfo> } callback
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 7
   * @deprecated since 9
   */
  function getApplicationInfo(bundleName: string, bundleFlags: number, callback: AsyncCallback<ApplicationInfo>): void;

  /**
   * Obtains based on a given bundle name.
   *
   * @permission ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO
   * @param { string } bundleName - Indicates the application bundle name to be queried.
   * @param { number } bundleFlags - Indicates the flag used to specify information contained
   *                                 in the ApplicationInfo object that will be returned.
   * @param { number } userId - Indicates the user ID or do not pass user ID.
   * @returns { Promise<ApplicationInfo> } Returns the ApplicationInfo object.
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 7
   * @deprecated since 9
   */
  function getApplicationInfo(bundleName: string, bundleFlags: number, userId?: number): Promise<ApplicationInfo>;

  /**
   * Query the AbilityInfo by the given Want.
   *
   * @permission ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO
   * @param { Want } want - Indicates the Want containing the application bundle name
   *                        to be queried.
   * @param { number } bundleFlags - Indicates the flag used to specify information contained in the AbilityInfo objects that
   *                                 will be returned.
   * @param { number } userId - Indicates the user ID.
   * @param { AsyncCallback<Array<AbilityInfo>> } callback
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 7
   * @deprecated since 9
   */
  function queryAbilityByWant(want: Want,
    bundleFlags: number, userId: number, callback: AsyncCallback<Array<AbilityInfo>>): void;

  /**
   * Query the AbilityInfo by the given Want.
   *
   * @permission ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO
   * @param { Want } want - Indicates the Want containing the application bundle name
   *                        to be queried.
   * @param { number } bundleFlags - Indicates the flag used to specify information contained in the AbilityInfo objects that
   *                                 will be returned.
   * @param { AsyncCallback<Array<AbilityInfo>> } callback
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 7
   * @deprecated since 9
   */
  function queryAbilityByWant(want: Want, bundleFlags: number, callback: AsyncCallback<Array<AbilityInfo>>): void;

  /**
   * Query the AbilityInfo by the given Want.
   *
   * @permission ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO
   * @param { Want } want - Indicates the Want containing the application bundle name
   *                        to be queried.
   * @param { number } bundleFlags - Indicates the flag used to specify information contained in the AbilityInfo objects that
   *                                 will be returned.
   * @param { number } userId - Indicates the user ID.
   * @returns { Promise<Array<AbilityInfo>> } Returns a list of AbilityInfo objects.
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 7
   * @deprecated since 9
   */
  function queryAbilityByWant(want: Want, bundleFlags: number, userId?: number): Promise<Array<AbilityInfo>>;

  /**
   * Obtains BundleInfo of all bundles available in the system.
   *
   * @permission ohos.permission.GET_BUNDLE_INFO_PRIVILEGED
   * @param { BundleFlag } bundleFlag - Indicates the flag used to specify information contained
   *                                    in the BundleInfo that will be returned.
   * @param { number } userId - Indicates the user ID.
   * @param { AsyncCallback<Array<BundleInfo>> } callback
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 7
   * @deprecated since 9
   */
  function getAllBundleInfo(bundleFlag: BundleFlag, userId: number, callback: AsyncCallback<Array<BundleInfo>>): void;

  /**
   * Obtains BundleInfo of all bundles available in the system.
   *
   * @permission ohos.permission.GET_BUNDLE_INFO_PRIVILEGED
   * @param { BundleFlag } bundleFlag - Indicates the flag used to specify information contained
   *                                    in the BundleInfo that will be returned.
   * @param { AsyncCallback<Array<BundleInfo>> } callback
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 7
   * @deprecated since 9
   */
  function getAllBundleInfo(bundleFlag: BundleFlag, callback: AsyncCallback<Array<BundleInfo>>): void;

  /**
   * Obtains BundleInfo of all bundles available in the system.
   *
   * @permission ohos.permission.GET_BUNDLE_INFO_PRIVILEGED
   * @param { BundleFlag } bundleFlag - Indicates the flag used to specify information contained
   *                                    in the BundleInfo that will be returned.
   * @param { number } userId - Indicates the user ID.
   * @returns { Promise<Array<BundleInfo>> } Returns a list of BundleInfo objects.
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 7
   * @deprecated since 9
   */
  function getAllBundleInfo(bundleFlag: BundleFlag, userId?: number): Promise<Array<BundleInfo>>;

  /**
   * Obtains information about all installed applications of a specified user.
   *
   * @permission ohos.permission.GET_BUNDLE_INFO_PRIVILEGED
   * @param { number } bundleFlags - Indicates the flag used to specify information contained
   *                                 in the ApplicationInfo objects that will be returned.
   * @param { number } userId - Indicates the user ID.
   * @param { AsyncCallback<Array<ApplicationInfo>> } callback
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 7
   * @deprecated since 9
   */
  function getAllApplicationInfo(bundleFlags: number,
    userId: number, callback: AsyncCallback<Array<ApplicationInfo>>): void;

  /**
   * Obtains information about all installed applications of a specified user.
   *
   * @permission ohos.permission.GET_BUNDLE_INFO_PRIVILEGED
   * @param { number } bundleFlags - Indicates the flag used to specify information contained
   *                                 in the ApplicationInfo objects that will be returned.
   * @param { AsyncCallback<Array<ApplicationInfo>> } callback
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 7
   * @deprecated since 9
   */
  function getAllApplicationInfo(bundleFlags: number, callback: AsyncCallback<Array<ApplicationInfo>>): void;

  /**
   * Obtains information about all installed applications of a specified user.
   *
   * @permission ohos.permission.GET_BUNDLE_INFO_PRIVILEGED
   * @param { number } bundleFlags - Indicates the flag used to specify information contained
   *                                 in the ApplicationInfo objects that will be returned.
   * @param { number } userId - Indicates the user ID or do not pass user ID.
   * @returns { Promise<Array<ApplicationInfo>> } Returns a list of ApplicationInfo objects.
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 7
   * @deprecated since 9
   */
  function getAllApplicationInfo(bundleFlags: number, userId?: number): Promise<Array<ApplicationInfo>>;

  /**
   * Obtains bundle name by the given uid.
   *
   * @param { number } uid - Indicates the UID of an application.
   * @param { AsyncCallback<string> } callback
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 8
   * @deprecated since 9
   */
  function getNameForUid(uid: number, callback: AsyncCallback<string>): void;

  /**
   * Obtains bundle name by the given uid.
   *
   * @param { number } uid - Indicates the UID of an application.
   * @returns { Promise<string> } Returns the bundle name.
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 8
   * @deprecated since 9
   */
  function getNameForUid(uid: number): Promise<string>;

  /**
   * Obtains information about an application bundle contained in an ohos Ability Package (HAP).
   *
   * @param { string } hapFilePath - Indicates the path storing the HAP. The path should be the relative path
   *                                 to the data directory of the current application.
   * @param { number } bundleFlags - Indicates the flag used to specify information contained in the
   *                                 BundleInfo object to be returned.
   * @param { AsyncCallback<BundleInfo> } callback
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 7
   * @deprecated since 9
   */
  function getBundleArchiveInfo(hapFilePath: string, bundleFlags: number, callback: AsyncCallback<BundleInfo>): void;

  /**
   * Obtains information about an application bundle contained in an ohos Ability Package (HAP).
   *
   * @param { string } hapFilePath - Indicates the path storing the HAP. The path should be the relative path
   *                                 to the data directory of the current application.
   * @param { number } bundleFlags - Indicates the flag used to specify information contained in the
   *                                 BundleInfo object to be returned.
   * @returns { Promise<BundleInfo> } - Returns the BundleInfo object.
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 7
   * @deprecated since 9
   */
  function getBundleArchiveInfo(hapFilePath: string, bundleFlags: number): Promise<BundleInfo>;

  /**
   * Obtains the Want for starting the main ability of an application based on the
   * given bundle name. The main ability of an application is the ability that has the
   * #ACTION_HOME and #ENTITY_HOME Want
   * filters set in the application's <b>config.json</b> file.
   *
   * @permission ohos.permission.GET_BUNDLE_INFO_PRIVILEGED
   * @param { string } bundleName - Indicates the bundle name of the application.
   * @param { AsyncCallback<Want> } callback
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 7
   * @deprecated since 9
   */
  function getLaunchWantForBundle(bundleName: string, callback: AsyncCallback<Want>): void;

  /**
   * Obtains the Want for starting the main ability of an application based on the
   * given bundle name. The main ability of an application is the ability that has the
   * #ACTION_HOME and #ENTITY_HOME Want
   * filters set in the application's <b>config.json</b> file.
   *
   * @permission ohos.permission.GET_BUNDLE_INFO_PRIVILEGED
   * @param { string } bundleName - Indicates the bundle name of the application.
   * @returns { Promise<Want> } Returns the Want for starting the application's main ability if any.
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 7
   * @deprecated since 9
   */
  function getLaunchWantForBundle(bundleName: string): Promise<Want>;

  /**
   * Clears cache data of a specified application.
   *
   * @permission ohos.permission.REMOVE_CACHE_FILES
   * @param { string } bundleName - Indicates the bundle name of the application whose cache data is to be cleared.
   * @param { AsyncCallback<void> } callback Indicates the callback to be invoked for returning the operation result.
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @systemapi Hide this for inner system use
   * @since 8
   * @deprecated since 9
   * @useinstead ohos.bundle.bundleManager#cleanBundleCacheFiles
   */
  function cleanBundleCacheFiles(bundleName: string, callback: AsyncCallback<void>): void;

  /**
   * Clears cache data of a specified application.
   *
   * @permission ohos.permission.REMOVE_CACHE_FILES
   * @param { string } bundleName - Indicates the bundle name of the application whose cache data is to be cleared.
   * @returns { Promise<void> }
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @systemapi Hide this for inner system use
   * @since 8
   * @deprecated since 9
   * @useinstead ohos.bundle.bundleManager#cleanBundleCacheFiles
   */
  function cleanBundleCacheFiles(bundleName: string): Promise<void>;

  /**
   * Sets whether to enable a specified application.
   *
   * @permission ohos.permission.CHANGE_ABILITY_ENABLED_STATE
   * @param { string } bundleName - Indicates the bundle name of the application.
   * @param { boolean } isEnable - Specifies whether to enable the application. The value true means to enable it,
   *                               and the value false means to disable it.
   * @param { AsyncCallback<void> } callback
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @systemapi Hide this for inner system use
   * @since 8
   * @deprecated since 9
   * @useinstead ohos.bundle.bundleManager#setApplicationEnabled
   */
  function setApplicationEnabled(bundleName: string, isEnable: boolean, callback: AsyncCallback<void>): void;

  /**
   * Sets whether to enable a specified application.
   *
   * @permission ohos.permission.CHANGE_ABILITY_ENABLED_STATE
   * @param { string } bundleName - Indicates the bundle name of the application.
   * @param { boolean } isEnable - Specifies whether to enable the application. The value true means to enable it,
   *                               and the value false means to disable it.
   * @returns { Promise<void> }
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @systemapi Hide this for inner system use
   * @since 8
   * @deprecated since 9
   * @useinstead ohos.bundle.bundleManager#setApplicationEnabled
   */
  function setApplicationEnabled(bundleName: string, isEnable: boolean): Promise<void>;

  /**
   * Sets whether to enable a specified ability.
   *
   * @permission ohos.permission.CHANGE_ABILITY_ENABLED_STATE
   * @param { AbilityInfo } info - Indicates information about the ability to set.
   * @param { boolean } isEnable - Specifies whether to enable the application. The value true means to enable it,
   *                               and the value false means to disable it.
   * @param { AsyncCallback<void> } callback
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @systemapi Hide this for inner system use
   * @since 8
   * @deprecated since 9
   * @useinstead ohos.bundle.bundleManager#setAbilityEnabled
   */
  function setAbilityEnabled(info: AbilityInfo, isEnable: boolean, callback: AsyncCallback<void>): void;

  /**
   * Sets whether to enable a specified ability.
   *
   * @permission ohos.permission.CHANGE_ABILITY_ENABLED_STATE
   * @param { AbilityInfo } info - Indicates information about the ability to set.
   * @param { boolean } isEnable - Specifies whether to enable the application. The value true means to enable it,
   *                               and the value false means to disable it.
   * @returns { Promise<void> }
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @systemapi Hide this for inner system use
   * @since 8
   * @deprecated since 9
   * @useinstead ohos.bundle.bundleManager#setAbilityEnabled
   */
  function setAbilityEnabled(info: AbilityInfo, isEnable: boolean): Promise<void>;

  /**
   * Get the permission details by permissionName.
   *
   * @permission ohos.permission.GET_BUNDLE_INFO_PRIVILEGED
   * @param { string } permissionName - Indicates permission name.
   * @param { AsyncCallback<PermissionDef> } callback
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @systemapi
   * @since 8
   * @deprecated since 9
   * @useinstead ohos.bundle.bundleManager#getPermissionDef
   */
  function getPermissionDef(permissionName: string, callback: AsyncCallback<PermissionDef>): void;

  /**
   * Get the permission details by permissionName.
   *
   * @permission ohos.permission.GET_BUNDLE_INFO_PRIVILEGED
   * @param { string } permissionName - Indicates permission name.
   * @returns { Promise<PermissionDef> } Returns permissionDef object.
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @systemapi
   * @since 8
   * @deprecated since 9
   * @useinstead ohos.bundle.bundleManager#getPermissionDef
   */
  function getPermissionDef(permissionName: string): Promise<PermissionDef>;

  /**
   * Obtains the label of a specified ability.
   *
   * @permission ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO
   * @param { string } bundleName - Indicates the bundle name of the application to which the ability belongs.
   * @param { string } abilityName - Indicates the ability name.
   * @param { AsyncCallback<string> } callback
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 8
   * @deprecated since 9
   */
  function getAbilityLabel(bundleName: string, abilityName: string, callback: AsyncCallback<string>): void;

  /**
   * Obtains the label of a specified ability.
   *
   * @permission ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO
   * @param { string } bundleName - Indicates the bundle name of the application to which the ability belongs.
   * @param { string } abilityName - Indicates the ability name.
   * @returns { Promise<string> } Returns the label representing the label of the specified ability.
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 8
   * @deprecated since 9
   */
  function getAbilityLabel(bundleName: string, abilityName: string): Promise<string>;

  /**
   * Obtains the icon of a specified ability.
   *
   * @permission ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO
   * @param { string } bundleName - Indicates the bundle name of the application to which the ability belongs.
   * @param { string } abilityName - Indicates the ability name.
   * @param { AsyncCallback<image.PixelMap> } callback
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 8
   * @deprecated since 9
   * @useinstead ohos.resourceManager#getMediaContent
   */
  function getAbilityIcon(bundleName: string, abilityName: string, callback: AsyncCallback<image.PixelMap>): void;

  /**
   * Obtains the icon of a specified ability.
   *
   * @permission ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO
   * @param { string } bundleName - Indicates the bundle name of the application to which the ability belongs.
   * @param { string } abilityName - Indicates the ability name.
   * @returns { Promise<image.PixelMap> } Returns the PixelMap object representing the icon of the specified ability.
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 8
   * @deprecated since 9
   * @useinstead ohos.resourceManager#getMediaContent
   */
  function getAbilityIcon(bundleName: string, abilityName: string): Promise<image.PixelMap>;

  /**
   * Checks whether a specified ability is enabled.
   *
   * @param { AbilityInfo } info - Indicates information about the ability to check.
   * @param { AsyncCallback<boolean> } callback
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 8
   * @deprecated since 9
   */
  function isAbilityEnabled(info: AbilityInfo, callback: AsyncCallback<boolean>): void;

  /**
   * Checks whether a specified ability is enabled.
   *
   * @param { AbilityInfo } info - Indicates information about the ability to check.
   * @returns { Promise<boolean> } Returns true if the ability is enabled; returns false otherwise.
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 8
   * @deprecated since 9
   */
  function isAbilityEnabled(info: AbilityInfo): Promise<boolean>;

  /**
   * Checks whether a specified application is enabled.
   *
   * @param { string } bundleName - Indicates the bundle name of the application.
   * @param { AsyncCallback<boolean> } callback
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 8
   * @deprecated since 9
   */
  function isApplicationEnabled(bundleName: string, callback: AsyncCallback<boolean>): void;

  /**
   * Checks whether a specified application is enabled.
   *
   * @param { string } bundleName - Indicates the bundle name of the application.
   * @returns { Promise<boolean> } Returns true if the application is enabled; returns false otherwise.
   * @syscap SystemCapability.BundleManager.BundleFramework
   * @since 8
   * @deprecated since 9
   */
  function isApplicationEnabled(bundleName: string): Promise<boolean>;
}

export default bundle;
