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

import { AsyncCallback } from './basic';
import { ElementName }  from './bundle/elementName';
import { RemoteAbilityInfo as _RemoteAbilityInfo } from './bundle/remoteAbilityInfo';

/**
 * distributedBundle.
 * @name distributedBundle
 * @since 8
 * @syscap SystemCapability.BundleManager.DistributedBundleFramework
 * @permission NA
 * @systemapi Hide this for inner system use
 * @deprecated since 9
 * @useinstead ohos.bundle.distributeBundle
 */
 declare namespace distributedBundle {
  /**
   * Obtains information about the ability info of the remote device.
   *
   * @since 8
   * @syscap SystemCapability.BundleManager.DistributedBundleFramework
   * @param elementName Indicates the elementName.
   * @return Returns the ability info of the remote device.
   * @permission ohos.permission.GET_BUNDLE_INFO_PRIVILEGED
   * @systemapi
   * @deprecated since 9
   * @useinstead ohos.bundle.distributeBundle#getRemoteAbilityInfo
   */
   function getRemoteAbilityInfo(elementName: ElementName, callback: AsyncCallback<RemoteAbilityInfo>): void;
   function getRemoteAbilityInfo(elementName: ElementName): Promise<RemoteAbilityInfo>;

  /**
   * Obtains information about the ability infos of the remote device.
   *
   * @since 8
   * @syscap SystemCapability.BundleManager.DistributedBundleFramework
   * @param elementNames Indicates the elementNames, Maximum array length ten.
   * @return Returns the ability infos of the remote device.
   * @permission ohos.permission.GET_BUNDLE_INFO_PRIVILEGED
   * @systemapi
   * @deprecated since 9
   * @useinstead ohos.bundle.distributeBundle#getRemoteAbilityInfo
   */
   function getRemoteAbilityInfos(elementNames: Array<ElementName>, callback: AsyncCallback<Array<RemoteAbilityInfo>>): void;
   function getRemoteAbilityInfos(elementNames: Array<ElementName>): Promise<Array<RemoteAbilityInfo>>;

  /**
   * Obtains information about the ability info of the remote device.
   *
   * @since 9
   * @syscap SystemCapability.BundleManager.DistributedBundleFramework
   * @param elementName Indicates the elementName.
   * @param locale Indicates the locale info
   * @return Returns the ability info of the remote device.
   * @permission ohos.permission.GET_BUNDLE_INFO_PRIVILEGED
   * @systemapi
   */
   function getRemoteAbilityInfo(elementName: ElementName, locale: string, callback: AsyncCallback<RemoteAbilityInfo>): void;
   function getRemoteAbilityInfo(elementName: ElementName, locale: string): Promise<RemoteAbilityInfo>;

  /**
   * Obtains information about the ability infos of the remote device.
   *
   * @since 9
   * @syscap SystemCapability.BundleManager.DistributedBundleFramework
   * @param elementNames Indicates the elementNames, Maximum array length ten.
   * @param locale Indicates the locale info
   * @return Returns the ability infos of the remote device.
   * @permission ohos.permission.GET_BUNDLE_INFO_PRIVILEGED
   * @systemapi
   */
   function getRemoteAbilityInfos(elementNames: Array<ElementName>, locale: string, callback: AsyncCallback<Array<RemoteAbilityInfo>>): void;
   function getRemoteAbilityInfos(elementNames: Array<ElementName>, locale: string): Promise<Array<RemoteAbilityInfo>>;

  /**
   * Contains basic remote ability information.
   * 
   * @since 9
   * @syscap SystemCapability.BundleManager.DistributedBundleFramework
   * @systemapi hide this for inner system use
   */
  export type RemoteAbilityInfo = _RemoteAbilityInfo;
}
export default distributedBundle;