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
 * @kit LocationKit
 */

import { AsyncCallback, Callback } from './@ohos.base';
import { WantAgent } from './@ohos.wantAgent';
import { NotificationRequest } from './notification/notificationRequest';

/**
 * Provides interfaces for acquiring location information, managing location switches,
 * geocoding, reverse geocoding, country code, fencing and other functions.
 *
 * @namespace geoLocationManager
 * @since 9
 */
/**
 * Provides interfaces for acquiring location information, managing location switches,
 * geocoding, reverse geocoding, country code, fencing and other functions.
 *
 * @namespace geoLocationManager
 * @atomicservice
 * @since 11
 */
declare namespace geoLocationManager {
  /**
   * Subscribe location changed.
   *
   * @permission ohos.permission.APPROXIMATELY_LOCATION
   * @param { 'locationChange' } type - Indicates the location service event to be subscribed to.
   * @param { LocationRequest } request - Indicates the location request parameters.
   * @param { Callback<Location> } callback - Indicates the callback for reporting the location result.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301100 - The location switch is off.
   * @throws { BusinessError } 3301200 - Failed to obtain the geographical location.
   * @syscap SystemCapability.Location.Location.Core
   * @since 9
   */
  /**
   * Subscribe location changed.
   *
   * @permission ohos.permission.APPROXIMATELY_LOCATION
   * @param { 'locationChange' } type - Indicates the location service event to be subscribed to.
   * @param { LocationRequest } request - Indicates the location request parameters.
   * @param { Callback<Location> } callback - Indicates the callback for reporting the location result.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301100 - The location switch is off.
   * @throws { BusinessError } 3301200 - Failed to obtain the geographical location.
   * @syscap SystemCapability.Location.Location.Core
   * @atomicservice
   * @since 11
   */
  /**
   * Subscribe location changed.
   *
   * @permission ohos.permission.APPROXIMATELY_LOCATION
   * @param { 'locationChange' } type - Indicates the location service event to be subscribed to.
   * @param { LocationRequest | ContinuousLocationRequest } request - Indicates the location request parameters.
   * @param { Callback<Location> } callback - Indicates the callback for reporting the location result.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301100 - The location switch is off.
   * @throws { BusinessError } 3301200 - Failed to obtain the geographical location.
   * @syscap SystemCapability.Location.Location.Core
   * @atomicservice
   * @since 12
   */
  function on(type: 'locationChange', request: LocationRequest | ContinuousLocationRequest,
  callback: Callback<Location>): void;

  /**
   * Unsubscribe location changed.
   *
   * @permission ohos.permission.APPROXIMATELY_LOCATION
   * @param { 'locationChange' } type - Indicates the location service event to be subscribed to.
   * @param { Callback<Location> } [callback] - Indicates the callback for reporting the location result.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301100 - The location switch is off.
   * @throws { BusinessError } 3301200 - Failed to obtain the geographical location.
   * @syscap SystemCapability.Location.Location.Core
   * @since 9
   */
  /**
   * Unsubscribe location changed.
   *
   * @permission ohos.permission.APPROXIMATELY_LOCATION
   * @param { 'locationChange' } type - Indicates the location service event to be subscribed to.
   * @param { Callback<Location> } [callback] - Indicates the callback for reporting the location result.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301100 - The location switch is off.
   * @throws { BusinessError } 3301200 - Failed to obtain the geographical location.
   * @syscap SystemCapability.Location.Location.Core
   * @atomicservice
   * @since 11
   */
  function off(type: 'locationChange', callback?: Callback<Location>): void;

  /**
   * Subscribe continuous location error changed.
   *
   * @permission ohos.permission.APPROXIMATELY_LOCATION
   * @param { 'locationError' } type - Indicates the location service event to be subscribed to.
   * @param { Callback<LocationError> } callback - Indicates the callback for reporting the continuous location error.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @syscap SystemCapability.Location.Location.Core
   * @atomicservice
   * @since 12
   */
  function on(type: 'locationError', callback: Callback<LocationError>): void;

  /**
   * Unsubscribe continuous location error changed.
   *
   * @permission ohos.permission.APPROXIMATELY_LOCATION
   * @param { 'locationError' } type - Indicates the location service event to be subscribed to.
   * @param { Callback<LocationError> } [callback] - Indicates the callback for reporting the continuous location error.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @syscap SystemCapability.Location.Location.Core
   * @atomicservice
   * @since 12
   */
  function off(type: 'locationError', callback?: Callback<LocationError>): void;

  /**
   * Subscribe location switch changed.
   *
   * @param { 'locationEnabledChange' } type - Indicates the location service event to be subscribed to.
   * @param { Callback<boolean> } callback - Indicates the callback for reporting the location switch status.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @syscap SystemCapability.Location.Location.Core
   * @since 9
   */
  function on(type: 'locationEnabledChange', callback: Callback<boolean>): void;

  /**
   * Unsubscribe location switch changed.
   *
   * @param { 'locationEnabledChange' } type - Indicates the location service event to be subscribed to.
   * @param { Callback<boolean> } [callback] - Indicates the callback for reporting the location switch status.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @syscap SystemCapability.Location.Location.Core
   * @since 9
   */
  function off(type: 'locationEnabledChange', callback?: Callback<boolean>): void;

  /**
   * Subscribe to cache GNSS locations update messages.
   *
   * @permission ohos.permission.APPROXIMATELY_LOCATION
   * @param { 'cachedGnssLocationsChange' } type - Indicates the location service event to be subscribed to.
   * @param { CachedGnssLocationsRequest } request - Indicates the cached GNSS locations request parameters.
   * @param { Callback<Array<Location>> } callback - Indicates the callback for reporting the cached GNSS locations.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301100 - The location switch is off.
   * @throws { BusinessError } 3301200 - Failed to obtain the geographical location.
   * @syscap SystemCapability.Location.Location.Gnss
   * @since 9
   */
  function on(type: 'cachedGnssLocationsChange', request: CachedGnssLocationsRequest, callback: Callback<Array<Location>>): void;

  /**
   * Unsubscribe to cache GNSS locations update messages.
   *
   * @permission ohos.permission.APPROXIMATELY_LOCATION
   * @param { 'cachedGnssLocationsChange' } type - Indicates the location service event to be subscribed to.
   * @param { Callback<Array<Location>> } [callback] - Indicates the callback for reporting the cached gnss locations.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301100 - The location switch is off.
   * @throws { BusinessError } 3301200 - Failed to obtain the geographical location.
   * @syscap SystemCapability.Location.Location.Gnss
   * @since 9
   */
  function off(type: 'cachedGnssLocationsChange', callback?: Callback<Array<Location>>): void;

  /**
   * Subscribe satellite status changed.
   *
   * @permission ohos.permission.APPROXIMATELY_LOCATION
   * @param { 'satelliteStatusChange' } type - Indicates the location service event to be subscribed to.
   * @param { Callback<SatelliteStatusInfo> } callback - Indicates the callback for reporting the satellite status.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301100 - The location switch is off.
   * @syscap SystemCapability.Location.Location.Gnss
   * @since 9
   */
  function on(type: 'satelliteStatusChange', callback: Callback<SatelliteStatusInfo>): void;

  /**
   * Unsubscribe satellite status changed.
   *
   * @permission ohos.permission.APPROXIMATELY_LOCATION
   * @param { 'satelliteStatusChange' } type - Indicates the location service event to be subscribed to.
   * @param { Callback<SatelliteStatusInfo> } [callback] - Indicates the callback for reporting the satellite status.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301100 - The location switch is off.
   * @syscap SystemCapability.Location.Location.Gnss
   * @since 9
   */
  function off(type: 'satelliteStatusChange', callback?: Callback<SatelliteStatusInfo>): void;

  /**
   * Subscribe nmea message changed.
   *
   * @permission ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION
   * @param { 'nmeaMessage' } type - Indicates the location service event to be subscribed to.
   * @param { Callback<string> } callback - Indicates the callback for reporting the nmea message.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301100 - The location switch is off.
   * @syscap SystemCapability.Location.Location.Gnss
   * @since 9
   */
  function on(type: 'nmeaMessage', callback: Callback<string>): void;

  /**
   * Unsubscribe nmea message changed.
   *
   * @permission ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION
   * @param { 'nmeaMessage' } type - Indicates the location service event to be subscribed to.
   * @param { Callback<string> } [callback] - Indicates the callback for reporting the nmea message.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301100 - The location switch is off.
   * @syscap SystemCapability.Location.Location.Gnss
   * @since 9
   */
  function off(type: 'nmeaMessage', callback?: Callback<string>): void;

  /**
   * Add a geofence and subscribe geofence status changed.
   *
   * @permission ohos.permission.APPROXIMATELY_LOCATION
   * @param { 'gnssFenceStatusChange' } type - Indicates the location service event to be subscribed to.
   * @param { GeofenceRequest } request - Indicates the Geofence configuration parameters.
   * @param { WantAgent } want - Indicates which ability to start when the geofence event is triggered.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301100 - The location switch is off.
   * @throws { BusinessError } 3301600 - Failed to operate the geofence.
   * @syscap SystemCapability.Location.Location.Geofence
   * @since 9
   */
  function on(type: 'gnssFenceStatusChange', request: GeofenceRequest, want: WantAgent): void;

  /**
   * Remove a geofence and unsubscribe geofence status changed.
   *
   * @permission ohos.permission.APPROXIMATELY_LOCATION
   * @param { 'gnssFenceStatusChange' } type - Indicates the location service event to be subscribed to.
   * @param { GeofenceRequest } request - Indicates the Geofence configuration parameters.
   * @param { WantAgent } want - Indicates which ability to start when the geofence event is triggered.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301100 - The location switch is off.
   * @throws { BusinessError } 3301600 - Failed to operate the geofence.
   * @syscap SystemCapability.Location.Location.Geofence
   * @since 9
   */
  function off(type: 'gnssFenceStatusChange', request: GeofenceRequest, want: WantAgent): void;

  /**
   * Registering the callback function for listening to country code changes.
   *
   * @param { 'countryCodeChange' } type - Indicates the location service event to be subscribed to.
   * @param { Callback<CountryCode> } callback - Indicates the callback for reporting country code changes.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301500 - Failed to query the area information.
   * @syscap SystemCapability.Location.Location.Core
   * @since 9
   */
  function on(type: 'countryCodeChange', callback: Callback<CountryCode>): void;

  /**
   * Unregistering the callback function for listening to country code changes.
   *
   * @param { 'countryCodeChange' } type - Indicates the location service event to be subscribed to.
   * @param { Callback<CountryCode> } [callback] - Indicates the callback for reporting country code changes.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301500 - Failed to query the area information.
   * @syscap SystemCapability.Location.Location.Core
   * @since 9
   */
  function off(type: 'countryCodeChange', callback?: Callback<CountryCode>): void;

  /**
   * Subscribe to changes in WiFi/BT scanning information,
   * and use the WiFi/BT scanning information for localization.
   *
   * @permission ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION
   * @param { 'locatingRequiredDataChange' } type - Indicates the location service event to be subscribed to.
   * @param { LocatingRequiredDataConfig } config - Indicates the locating required data configuration parameters.
   * @param { Callback<Array<LocatingRequiredData>> } [callback] - Indicates the callback for reporting WiFi/BT scan info.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 401 - Invalid parameter.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301800 - Failed to start WiFi or Bluetooth scanning.
   * @syscap SystemCapability.Location.Location.Core
   * @systemapi
   * @since 10
   */
  function on(type: 'locatingRequiredDataChange', config: LocatingRequiredDataConfig, callback: Callback<Array<LocatingRequiredData>>): void;

  /**
   * Stop WiFi/BT scanning and unsubscribe from WiFi/BT scanning information changes.
   *
   * @permission ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION
   * @param { 'locatingRequiredDataChange' } type - Indicates the location service event to be subscribed to.
   * @param { Callback<Array<LocatingRequiredData>> } [callback] - Indicates the callback for reporting WiFi/BT scan info.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 401 - Invalid parameter.
   * @throws { BusinessError } 801 - Capability not supported.
   * @syscap SystemCapability.Location.Location.Core
   * @systemapi
   * @since 10
   */
  function off(type: 'locatingRequiredDataChange', callback?: Callback<Array<LocatingRequiredData>>): void;

  /**
   * Subscribe location icon status changed.
   *
   * @param { 'locationIconStatusChange' } type - Indicates the location service event to be subscribed to.
   * @param { Callback<LocationIconStatus> } callback - Indicates the callback for reporting the location icon status.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @syscap SystemCapability.Location.Location.Core
   * @systemapi
   * @since 12
   */
  function on(type: 'locationIconStatusChange', callback: Callback<LocationIconStatus>): void;

  /**
   * Unsubscribe location icon status changed.
   *
   * @param { 'locationIconStatusChange' } type - Indicates the location service event to be subscribed to.
   * @param { Callback<LocationIconStatus> } [callback] - Indicates the callback for reporting the location icon status.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @syscap SystemCapability.Location.Location.Core
   * @systemapi
   * @since 12
   */
  function off(type: 'locationIconStatusChange', callback?: Callback<LocationIconStatus>): void;

  /**
   * Obtain current location.
   *
   * @permission ohos.permission.APPROXIMATELY_LOCATION
   * @param { CurrentLocationRequest } request - Indicates the location request parameters.
   * @param { AsyncCallback<Location> } callback - Indicates the callback for reporting the location result.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301100 - The location switch is off.
   * @throws { BusinessError } 3301200 - Failed to obtain the geographical location.
   * @syscap SystemCapability.Location.Location.Core
   * @since 9
   */
  /**
   * Obtain current location.
   *
   * @permission ohos.permission.APPROXIMATELY_LOCATION
   * @param { CurrentLocationRequest } request - Indicates the location request parameters.
   * @param { AsyncCallback<Location> } callback - Indicates the callback for reporting the location result.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301100 - The location switch is off.
   * @throws { BusinessError } 3301200 - Failed to obtain the geographical location.
   * @syscap SystemCapability.Location.Location.Core
   * @atomicservice
   * @since 11
   */
  /**
   * Obtain current location.
   *
   * @permission ohos.permission.APPROXIMATELY_LOCATION
   * @param { CurrentLocationRequest | SingleLocationRequest } request - Indicates the location request parameters.
   * @param { AsyncCallback<Location> } callback - Indicates the callback for reporting the location result.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301100 - The location switch is off.
   * @throws { BusinessError } 3301200 - Failed to obtain the geographical location.
   * @syscap SystemCapability.Location.Location.Core
   * @atomicservice
   * @since 12
   */
  function getCurrentLocation(request: CurrentLocationRequest | SingleLocationRequest,
  callback: AsyncCallback<Location>): void;

  /**
   * Obtain current location.
   *
   * @permission ohos.permission.APPROXIMATELY_LOCATION
   * @param { AsyncCallback<Location> } callback - Indicates the callback for reporting the location result.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301100 - The location switch is off.
   * @throws { BusinessError } 3301200 - Failed to obtain the geographical location.
   * @syscap SystemCapability.Location.Location.Core
   * @since 9
   */
  /**
   * Obtain current location.
   *
   * @permission ohos.permission.APPROXIMATELY_LOCATION
   * @param { AsyncCallback<Location> } callback - Indicates the callback for reporting the location result.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301100 - The location switch is off.
   * @throws { BusinessError } 3301200 - Failed to obtain the geographical location.
   * @syscap SystemCapability.Location.Location.Core
   * @atomicservice
   * @since 11
   */
  function getCurrentLocation(callback: AsyncCallback<Location>): void;

  /**
   * Obtain current location.
   *
   * @permission ohos.permission.APPROXIMATELY_LOCATION
   * @param { CurrentLocationRequest } [request] - Indicates the location request parameters.
   * @returns { Promise<Location> } The promise returned by the function.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301100 - The location switch is off.
   * @throws { BusinessError } 3301200 - Failed to obtain the geographical location.
   * @syscap SystemCapability.Location.Location.Core
   * @since 9
   */
  /**
   * Obtain current location.
   *
   * @permission ohos.permission.APPROXIMATELY_LOCATION
   * @param { CurrentLocationRequest } [request] - Indicates the location request parameters.
   * @returns { Promise<Location> } The promise returned by the function.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301100 - The location switch is off.
   * @throws { BusinessError } 3301200 - Failed to obtain the geographical location.
   * @syscap SystemCapability.Location.Location.Core
   * @atomicservice
   * @since 11
   */
  /**
   * Obtain current location.
   *
   * @permission ohos.permission.APPROXIMATELY_LOCATION
   * @param { CurrentLocationRequest | SingleLocationRequest } [request] - Indicates the location request parameters.
   * @returns { Promise<Location> } The promise returned by the function.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301100 - The location switch is off.
   * @throws { BusinessError } 3301200 - Failed to obtain the geographical location.
   * @syscap SystemCapability.Location.Location.Core
   * @atomicservice
   * @since 12
   */
  function getCurrentLocation(request?: CurrentLocationRequest | SingleLocationRequest):
  Promise<Location>;

  /**
   * Obtain last known location.
   *
   * @permission ohos.permission.APPROXIMATELY_LOCATION
   * @returns { Location } The last known location information.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301100 - The location switch is off.
   * @throws { BusinessError } 3301200 - Failed to obtain the geographical location.
   * @syscap SystemCapability.Location.Location.Core
   * @since 9
   */
  /**
   * Obtain last known location.
   *
   * @permission ohos.permission.APPROXIMATELY_LOCATION
   * @returns { Location } The last known location information.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301100 - The location switch is off.
   * @throws { BusinessError } 3301200 - Failed to obtain the geographical location.
   * @syscap SystemCapability.Location.Location.Core
   * @atomicservice
   * @since 11
   */
  function getLastLocation(): Location;

  /**
   * Obtain current location switch status.
   *
   * @returns { boolean } Returns {@code true} if the location switch on, returns {@code false} otherwise.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @syscap SystemCapability.Location.Location.Core
   * @since 9
   */
  /**
   * Obtain current location switch status.
   *
   * @returns { boolean } Returns {@code true} if the location switch on, returns {@code false} otherwise.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @syscap SystemCapability.Location.Location.Core
   * @atomicservice
   * @since 11
   */
  function isLocationEnabled(): boolean;

  /**
   * Enable location switch.
   *
   * @permission ohos.permission.MANAGE_SECURE_SETTINGS
   * @param { AsyncCallback<void> } callback - Indicates the callback for reporting the error message.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 202 - System API is not allowed called by third HAP.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @syscap SystemCapability.Location.Location.Core
   * @systemapi
   * @since 9
   */
  function enableLocation(callback: AsyncCallback<void>): void;

  /**
   * Enable location switch.
   *
   * @permission ohos.permission.MANAGE_SECURE_SETTINGS
   * @returns { Promise<void> } The promise returned by the function.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 202 - System API is not allowed called by third HAP.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @syscap SystemCapability.Location.Location.Core
   * @systemapi
   * @since 9
   */
  function enableLocation(): Promise<void>;

  /**
   * Disable location switch.
   *
   * @permission ohos.permission.MANAGE_SECURE_SETTINGS
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 202 - System API is not allowed called by third HAP.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @syscap SystemCapability.Location.Location.Core
   * @systemapi
   * @since 9
   */
  function disableLocation(): void;

  /**
   * Obtain address info from location.
   *
   * @param { ReverseGeoCodeRequest } request - Indicates the reverse geocode query parameters.
   * @param { AsyncCallback<Array<GeoAddress>> } callback - Indicates the callback for reporting the address info.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301300 - Reverse geocoding query failed.
   * @syscap SystemCapability.Location.Location.Geocoder
   * @since 9
   */
  function getAddressesFromLocation(request: ReverseGeoCodeRequest, callback: AsyncCallback<Array<GeoAddress>>): void;

  /**
   * Obtain address info from location.
   *
   * @param { ReverseGeoCodeRequest } request - Indicates the reverse geocode query parameters.
   * @returns { Promise<Array<GeoAddress>> } The promise returned by the function.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301300 - Reverse geocoding query failed.
   * @syscap SystemCapability.Location.Location.Geocoder
   * @since 9
   */
  function getAddressesFromLocation(request: ReverseGeoCodeRequest): Promise<Array<GeoAddress>>;

  /**
   * Obtain latitude and longitude info from location address.
   *
   * @param { GeoCodeRequest } request - Indicates the geocode query parameters.
   * @param { AsyncCallback<Array<GeoAddress>> } callback - Indicates the callback for reporting the latitude and longitude result.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301400 - Geocoding query failed.
   * @syscap SystemCapability.Location.Location.Geocoder
   * @since 9
   */
  function getAddressesFromLocationName(request: GeoCodeRequest, callback: AsyncCallback<Array<GeoAddress>>): void;

  /**
   * Obtain latitude and longitude info from location address.
   *
   * @param { GeoCodeRequest } request - Indicates the geocode query parameters.
   * @returns { Promise<Array<GeoAddress>> } The promise returned by the function.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301400 - Geocoding query failed.
   * @syscap SystemCapability.Location.Location.Geocoder
   * @since 9
   */
  function getAddressesFromLocationName(request: GeoCodeRequest): Promise<Array<GeoAddress>>;

  /**
   * Obtain geocoding service status.
   *
   * @returns { boolean } Returns {@code true} if geocoding service is available, returns {@code false} otherwise.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @syscap SystemCapability.Location.Location.Geocoder
   * @since 9
   */
  function isGeocoderAvailable(): boolean;

  /**
   * Obtain the number of cached GNSS locations reported at a time.
   *
   * @permission ohos.permission.APPROXIMATELY_LOCATION
   * @param { AsyncCallback<number> } callback - Indicates the callback for reporting the cached GNSS locations size.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301100 - The location switch is off.
   * @syscap SystemCapability.Location.Location.Gnss
   * @since 9
   */
  function getCachedGnssLocationsSize(callback: AsyncCallback<number>): void;

  /**
   * Obtain the number of cached GNSS locations.
   *
   * @permission ohos.permission.APPROXIMATELY_LOCATION
   * @returns { Promise<number> } The promise returned by the function.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301100 - The location switch is off.
   * @syscap SystemCapability.Location.Location.Gnss
   * @since 9
   */
  function getCachedGnssLocationsSize(): Promise<number>;

  /**
   * All prepared GNSS locations are returned to the application through the callback function,
   * and the bottom-layer buffer is cleared.
   *
   * @permission ohos.permission.APPROXIMATELY_LOCATION
   * @param { AsyncCallback<void> } callback - Indicates the callback for reporting the error message.
   * If the function fails to execute, the error message will be carried in the first parameter err of AsyncCallback,
   * If the function executes successfully, execute the callback function only, no data will be returned.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301100 - The location switch is off.
   * @throws { BusinessError } 3301200 - Failed to obtain the geographical location.
   * @syscap SystemCapability.Location.Location.Gnss
   * @since 9
   */
  function flushCachedGnssLocations(callback: AsyncCallback<void>): void;

  /**
   * All prepared GNSS locations are returned to the application,
   * and the bottom-layer buffer is cleared.
   *
   * @permission ohos.permission.APPROXIMATELY_LOCATION
   * @returns { Promise<void> } The promise returned by the function.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301100 - The location switch is off.
   * @throws { BusinessError } 3301200 - Failed to obtain the geographical location.
   * @syscap SystemCapability.Location.Location.Gnss
   * @since 9
   */
  function flushCachedGnssLocations(): Promise<void>;

  /**
   * Send extended commands to location subsystem.
   *
   * @param { LocationCommand } command - Indicates the extended command message body.
   * @param { AsyncCallback<void> } callback - Indicates the callback for reporting the error message.
   * If the function fails to execute, the error message will be carried in the first parameter err of AsyncCallback,
   * If the function executes successfully, execute the callback function only, no data will be returned.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @syscap SystemCapability.Location.Location.Core
   * @since 9
   */
  function sendCommand(command: LocationCommand, callback: AsyncCallback<void>): void;

  /**
   * Send extended commands to location subsystem.
   *
   * @param { LocationCommand } command - Indicates the extended command message body.
   * @returns { Promise<void> } The promise returned by the function.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @syscap SystemCapability.Location.Location.Core
   * @since 9
   */
  function sendCommand(command: LocationCommand): Promise<void>;

  /**
   * Obtain the current country code.
   *
   * @param { AsyncCallback<CountryCode> } callback - Indicates the callback for reporting the country code.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301500 - Failed to query the area information.
   * @syscap SystemCapability.Location.Location.Core
   * @since 9
   */
  function getCountryCode(callback: AsyncCallback<CountryCode>): void;

  /**
   * Obtain the current country code.
   *
   * @returns { Promise<CountryCode> } The promise returned by the function.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301500 - Failed to query the area information.
   * @syscap SystemCapability.Location.Location.Core
   * @since 9
   */
  function getCountryCode(): Promise<CountryCode>;

  /**
   * Enable the geographical location simulation function.
   *
   * @throws { BusinessError } 202 - System API is not allowed called by third HAP.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301100 - The location switch is off.
   * @syscap SystemCapability.Location.Location.Core
   * @systemapi
   * @since 9
   */
  function enableLocationMock(): void;

  /**
   * Disable the geographical location simulation function.
   *
   * @throws { BusinessError } 202 - System API is not allowed called by third HAP.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301100 - The location switch is off.
   * @syscap SystemCapability.Location.Location.Core
   * @systemapi
   * @since 9
   */
  function disableLocationMock(): void;

  /**
   * Set the configuration parameters for location simulation.
   *
   * @param { LocationMockConfig } config - Indicates the configuration parameters for location simulation.
   * Contains the array of locations and reporting intervals that need to be simulated.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301100 - The location switch is off.
   * @syscap SystemCapability.Location.Location.Core
   * @systemapi
   * @since 9
   */
  function setMockedLocations(config: LocationMockConfig): void;

  /**
   * Enable the reverse geocoding simulation function.
   *
   * @throws { BusinessError } 202 - System API is not allowed called by third HAP.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @syscap SystemCapability.Location.Location.Core
   * @systemapi
   * @since 9
   */
  function enableReverseGeocodingMock(): void;

  /**
   * Disable the reverse geocoding simulation function.
   *
   * @throws { BusinessError } 202 - System API is not allowed called by third HAP.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @syscap SystemCapability.Location.Location.Core
   * @systemapi
   * @since 9
   */
  function disableReverseGeocodingMock(): void;

  /**
   * Set the configuration parameters for simulating reverse geocoding.
   *
   * @param { Array<ReverseGeocodingMockInfo> } mockInfos - Indicates the set of locations and place names to be simulated.
   * @throws { BusinessError } 202 - System API is not allowed called by third HAP.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @syscap SystemCapability.Location.Location.Core
   * @systemapi
   * @since 9
   */
  function setReverseGeocodingMockInfo(mockInfos: Array<ReverseGeocodingMockInfo>): void;

  /**
   * Querying location privacy protocol confirmation status.
   *
   * @param { LocationPrivacyType } type - Indicates location privacy protocol type.
   * @returns { boolean } Returns {@code true} if the location privacy protocol has been confirmed, returns {@code false} otherwise.
   * @throws { BusinessError } 202 - System API is not allowed called by third HAP.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @syscap SystemCapability.Location.Location.Core
   * @systemapi
   * @since 9
   */
  function isLocationPrivacyConfirmed(type: LocationPrivacyType): boolean;

  /**
   * Set location privacy protocol confirmation status.
   *
   * @permission ohos.permission.MANAGE_SECURE_SETTINGS
   * @param { LocationPrivacyType } type - Indicates location privacy protocol type.
   * @param { boolean } isConfirmed - Indicates whether the location privacy protocol has been confirmed.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 202 - System API is not allowed called by third HAP.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @syscap SystemCapability.Location.Location.Core
   * @systemapi
   * @since 9
   */
  function setLocationPrivacyConfirmStatus(type: LocationPrivacyType, isConfirmed: boolean): void;

  /**
   * Get WiFi/BT scanning information, and use the WiFi/BT scanning information for localization.
   *
   * @permission ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION
   * @param { LocatingRequiredDataConfig } config - Indicates the request parameters for obtaining the data required for locating.
   * @returns { Promise<Array<LocatingRequiredData>> } The promise returned by the function, for reporting WiFi/BT scan info.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 401 - Invalid parameter.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301800 - Failed to start WiFi or Bluetooth scanning.
   * @syscap SystemCapability.Location.Location.Core
   * @systemapi
   * @since 10
   */
  function getLocatingRequiredData(config: LocatingRequiredDataConfig): Promise<Array<LocatingRequiredData>>;

  /**
   * Add a geofence.
   *
   * @permission ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION
   * @param { GnssGeofenceRequest } fenceRequest - Indicates the Geofence configuration parameters.
   * @returns { Promise<number> } The promise returned by the function, for reporting the ID of geofence.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301100 - The location switch is off.
   * @throws { BusinessError } 3301601 - The number of geofences exceeds the maximum.
   * @syscap SystemCapability.Location.Location.Geofence
   * @since 12
   */
  function addGnssGeofence(fenceRequest: GnssGeofenceRequest): Promise<number>;

  /**
   * Remove a geofence.
   *
   * @permission ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION
   * @param { number } geofenceId - Indicates the ID of geofence.
   * @returns { Promise<void> } The promise returned by the function.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @throws { BusinessError } 3301602 - Failed to delete a geofence due to an incorrect ID.
   * @syscap SystemCapability.Location.Location.Geofence
   * @since 12
   */
  function removeGnssGeofence(geofenceId: number): Promise<void>;

  /**
   * Obtains the coordinate system types supported by geofence.
   *
   * @returns { Array<CoordinateSystemType> } Return the coordinate system types supported by geofence.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @syscap SystemCapability.Location.Location.Geofence
   * @since 12
   */
  function getGeofenceSupportedCoordTypes(): Array<CoordinateSystemType>;

  /**
   * Get location icon status.
   *
   * @returns { LocationIconStatus } The location icon status.
   * @throws { BusinessError } 801 - Capability not supported.
   * @throws { BusinessError } 3301000 - Location service is unavailable.
   * @syscap SystemCapability.Location.Location.Core
   * @systemapi
   * @since 12
   */
  function getLocationIconStatus(): LocationIconStatus;

  /**
   * Configuration parameters for simulating reverse geocoding.
   *
   * @typedef ReverseGeocodingMockInfo
   * @syscap SystemCapability.Location.Location.Core
   * @systemapi
   * @since 9
   */
  export interface ReverseGeocodingMockInfo {
    /**
     * Location for which reverse geocoding query is required.
     *
     * @type { ReverseGeoCodeRequest }
     * @syscap SystemCapability.Location.Location.Core
     * @systemapi
     * @since 9
     */
    location: ReverseGeoCodeRequest;

    /**
     * Actual address information corresponding to the location.
     *
     * @type { GeoAddress }
     * @syscap SystemCapability.Location.Location.Core
     * @systemapi
     * @since 9
     */
    geoAddress: GeoAddress;
  }

  /**
   * Parameters for configuring the location simulation function.
   *
   * @typedef LocationMockConfig
   * @syscap SystemCapability.Location.Location.Core
   * @systemapi
   * @since 9
   */
  export interface LocationMockConfig {
    /**
     * Interval for reporting simulated locations.
     *
     * @type { number }
     * @syscap SystemCapability.Location.Location.Core
     * @systemapi
     * @since 9
     */
    timeInterval: number;

    /**
     * Mock location array.
     *
     * @type { Array<Location> }
     * @syscap SystemCapability.Location.Location.Core
     * @systemapi
     * @since 9
     */
    locations: Array<Location>;
  }

  /**
   * Satellite status information.
   *
   * @typedef SatelliteStatusInfo
   * @syscap SystemCapability.Location.Location.Gnss
   * @since 9
   */
  export interface SatelliteStatusInfo {
    /**
     * Number of satellites.
     *
     * @type { number }
     * @syscap SystemCapability.Location.Location.Gnss
     * @since 9
     */
    satellitesNumber: number;

    /**
     * Satellite ID array.
     *
     * @type { Array<number> }
     * @syscap SystemCapability.Location.Location.Gnss
     * @since 9
     */
    satelliteIds: Array<number>;

    /**
     * Carrier to noise density array.
     *
     * @type { Array<number> }
     * @syscap SystemCapability.Location.Location.Gnss
     * @since 9
     */
    carrierToNoiseDensitys: Array<number>;

    /**
     * Satellite altitude array.
     *
     * @type { Array<number> }
     * @syscap SystemCapability.Location.Location.Gnss
     * @since 9
     */
    altitudes: Array<number>;

    /**
     * Satellite azimuth array.
     *
     * @type { Array<number> }
     * @syscap SystemCapability.Location.Location.Gnss
     * @since 9
     */
    azimuths: Array<number>;

    /**
     * Satellite carrier frequency array.
     *
     * @type { Array<number> }
     * @syscap SystemCapability.Location.Location.Gnss
     * @since 9
     */
    carrierFrequencies: Array<number>;

    /**
     * Satellite constellation type array.
     *
     * @type { Array<SatelliteConstellationCategory> }
     * @syscap SystemCapability.Location.Location.Gnss
     * @since 12
     */
    satelliteConstellation: Array<SatelliteConstellationCategory>;

    /**
     * Satellite additional information array.
     *
     * @type { Array<number> }
     * @syscap SystemCapability.Location.Location.Gnss
     * @since 12
     */
    satelliteAdditionalInfo: Array<number>;
  }

  /**
   * Parameters for requesting to report cache location information.
   *
   * @typedef CachedGnssLocationsRequest
   * @syscap SystemCapability.Location.Location.Gnss
   * @since 9
   */
  export interface CachedGnssLocationsRequest {
    /**
     * GNSS cache location report period.
     *
     * @type { number }
     * @syscap SystemCapability.Location.Location.Gnss
     * @since 9
     */
    reportingPeriodSec: number;

    /**
     * Indicates whether to wake up the listener when the GNSS cache location queue is full.
     *
     * @type { boolean }
     * @syscap SystemCapability.Location.Location.Gnss
     * @since 9
     */
    wakeUpCacheQueueFull: boolean;
  }

  /**
   * Configuring parameters in GNSS geofence requests.
   *
   * @typedef GnssGeofenceRequest
   * @syscap SystemCapability.Location.Location.Geofence
   * @since 12
   */
  export interface GnssGeofenceRequest {
    /**
     * Circular fence information.
     *
     * @type { Geofence }
     * @syscap SystemCapability.Location.Location.Geofence
     * @since 12
     */
    geofence: Geofence;

    /**
     * Indicates geofence transition status monitored.
     *
     * @type { Array<GeofenceTransitionEvent> }
     * @syscap SystemCapability.Location.Location.Geofence
     * @since 12
     */
    monitorTransitionEvents: Array<GeofenceTransitionEvent>;

    /**
     * Indicates the geofence notifications to publish.
     *
     * @type { ?Array<NotificationRequest> }
     * @syscap SystemCapability.Location.Location.Geofence
     * @since 12
     */
    notifications?: Array<NotificationRequest>;

    /**
     * Indicates the callback for reporting the geofence transition status.
     *
     * @type { AsyncCallback<GeofenceTransition> }
     * @syscap SystemCapability.Location.Location.Geofence
     * @since 12
     */
    geofenceTransitionCallback: AsyncCallback<GeofenceTransition>;
  }

  /**
   * Configuring parameters in geofence requests.
   *
   * @typedef GeofenceRequest
   * @syscap SystemCapability.Location.Location.Geofence
   * @since 9
   */
  export interface GeofenceRequest {
    /**
     * Indicate the user scenario.
     *
     * @type { LocationRequestScenario }
     * @syscap SystemCapability.Location.Location.Geofence
     * @since 9
     */
    scenario: LocationRequestScenario;

    /**
     * Circular fence information.
     *
     * @type { Geofence }
     * @syscap SystemCapability.Location.Location.Geofence
     * @since 9
     */
    geofence: Geofence;
  }

  /**
   * Circular fence information.
   *
   * @typedef Geofence
   * @syscap SystemCapability.Location.Location.Geofence
   * @since 9
   */
  export interface Geofence {
    /**
     * Latitude of the center point of the circular fence.
     *
     * @type { number }
     * @syscap SystemCapability.Location.Location.Geofence
     * @since 9
     */
    latitude: number;

    /**
     * Longitude of the center point of the circular fence.
     *
     * @type { number }
     * @syscap SystemCapability.Location.Location.Geofence
     * @since 9
     */
    longitude: number;

    /**
     * Coordinate system type.
     *
     * @type { ?CoordinateSystemType }
     * @syscap SystemCapability.Location.Location.Geofence
     * @since 12
     */
    coordinateSystemType?: CoordinateSystemType;

    /**
     * Radius of the circular fence.
     *
     * @type { number }
     * @syscap SystemCapability.Location.Location.Geofence
     * @since 9
     */
    radius: number;

    /**
     * Expiration of the circular fence.
     *
     * @type { number }
     * @syscap SystemCapability.Location.Location.Geofence
     * @since 9
     */
    expiration: number;
  }

  /**
   * Configuring parameters in reverse geocode requests.
   *
   * @typedef ReverseGeoCodeRequest
   * @syscap SystemCapability.Location.Location.Geocoder
   * @since 9
   */
  export interface ReverseGeoCodeRequest {
    /**
     * Indicates the language area information.
     *
     * @type { ?string }
     * @syscap SystemCapability.Location.Location.Geocoder
     * @since 9
     */
    locale?: string;

    /**
     * Indicates the country information.
     *
     * @type { ?string }
     * @syscap SystemCapability.Location.Location.Geocoder
     * @since 12
     */
    country?: string;

    /**
     * Latitude for reverse geocoding query.
     *
     * @type { number }
     * @syscap SystemCapability.Location.Location.Geocoder
     * @since 9
     */
    latitude: number;

    /**
     * Longitude for reverse geocoding query.
     *
     * @type { number }
     * @syscap SystemCapability.Location.Location.Geocoder
     * @since 9
     */
    longitude: number;

    /**
     * Indicates the maximum number of addresses returned by reverse geocoding query.
     *
     * @type { ?number }
     * @syscap SystemCapability.Location.Location.Geocoder
     * @since 9
     */
    maxItems?: number;
  }

  /**
   * Configuring parameters in geocode requests.
   *
   * @typedef GeoCodeRequest
   * @syscap SystemCapability.Location.Location.Geocoder
   * @since 9
   */
  export interface GeoCodeRequest {
    /**
     * Indicates the language area information.
     *
     * @type { ?string }
     * @syscap SystemCapability.Location.Location.Geocoder
     * @since 9
     */
    locale?: string;

    /**
     * Indicates the country information.
     *
     * @type { ?string }
     * @syscap SystemCapability.Location.Location.Geocoder
     * @since 12
     */
    country?: string;

    /**
     * Address information.
     *
     * @type { string }
     * @syscap SystemCapability.Location.Location.Geocoder
     * @since 9
     */
    description: string;

    /**
     * Indicates the maximum number of geocode query results.
     *
     * @type { ?number }
     * @syscap SystemCapability.Location.Location.Geocoder
     * @since 9
     */
    maxItems?: number;

    /**
     * Indicates the minimum latitude for geocoding query results.
     *
     * @type { ?number }
     * @syscap SystemCapability.Location.Location.Geocoder
     * @since 9
     */
    minLatitude?: number;

    /**
     * Indicates the minimum longitude for geocoding query results.
     *
     * @type { ?number }
     * @syscap SystemCapability.Location.Location.Geocoder
     * @since 9
     */
    minLongitude?: number;

    /**
     * Indicates the maximum latitude for geocoding query results.
     *
     * @type { ?number }
     * @syscap SystemCapability.Location.Location.Geocoder
     * @since 9
     */
    maxLatitude?: number;

    /**
     * Indicates the maximum longitude for geocoding query results.
     *
     * @type { ?number }
     * @syscap SystemCapability.Location.Location.Geocoder
     * @since 9
     */
    maxLongitude?: number;
  }

  /**
   * Data struct describes geographic locations.
   *
   * @typedef GeoAddress
   * @syscap SystemCapability.Location.Location.Geocoder
   * @since 9
   */
  export interface GeoAddress {
    /**
     * Indicates latitude information.
     * A positive value indicates north latitude,
     * and a negative value indicates south latitude.
     *
     * @type { ?number }
     * @syscap SystemCapability.Location.Location.Geocoder
     * @since 9
     */
    latitude?: number;

    /**
     * Indicates longitude information.
     * A positive value indicates east longitude ,
     * and a negative value indicates west longitude.
     *
     * @type { ?number }
     * @syscap SystemCapability.Location.Location.Geocoder
     * @since 9
     */
    longitude?: number;

    /**
     * Indicates language used for the location description.
     * zh indicates Chinese, and en indicates English.
     *
     * @type { ?string }
     * @syscap SystemCapability.Location.Location.Geocoder
     * @since 9
     */
    locale?: string;

    /**
     * Indicates detailed address information.
     *
     * @type { ?string }
     * @syscap SystemCapability.Location.Location.Geocoder
     * @since 9
     */
    placeName?: string;

    /**
     * Indicates country code.
     *
     * @type { ?string }
     * @syscap SystemCapability.Location.Location.Geocoder
     * @since 9
     */
    countryCode?: string;

    /**
     * Indicates country name.
     *
     * @type { ?string }
     * @syscap SystemCapability.Location.Location.Geocoder
     * @since 9
     */
    countryName?: string;

    /**
     * Indicates administrative region name.
     *
     * @type { ?string }
     * @syscap SystemCapability.Location.Location.Geocoder
     * @since 9
     */
    administrativeArea?: string;

    /**
     * Indicates sub-administrative region name.
     *
     * @type { ?string }
     * @syscap SystemCapability.Location.Location.Geocoder
     * @since 9
     */
    subAdministrativeArea?: string;

    /**
     * Indicates locality information.
     *
     * @type { ?string }
     * @syscap SystemCapability.Location.Location.Geocoder
     * @since 9
     */
    locality?: string;

    /**
     * Indicates sub-locality information.
     *
     * @type { ?string }
     * @syscap SystemCapability.Location.Location.Geocoder
     * @since 9
     */
    subLocality?: string;

    /**
     * Indicates road name.
     *
     * @type { ?string }
     * @syscap SystemCapability.Location.Location.Geocoder
     * @since 9
     */
    roadName?: string;

    /**
     * Indicates auxiliary road information.
     *
     * @type { ?string }
     * @syscap SystemCapability.Location.Location.Geocoder
     * @since 9
     */
    subRoadName?: string;

    /**
     * Indicates house information.
     *
     * @type { ?string }
     * @syscap SystemCapability.Location.Location.Geocoder
     * @since 9
     */
    premises?: string;

    /**
     * Indicates postal code.
     *
     * @type { ?string }
     * @syscap SystemCapability.Location.Location.Geocoder
     * @since 9
     */
    postalCode?: string;

    /**
     * Indicates phone number.
     *
     * @type { ?string }
     * @syscap SystemCapability.Location.Location.Geocoder
     * @since 9
     */
    phoneNumber?: string;

    /**
     * Indicates website URL.
     *
     * @type { ?string }
     * @syscap SystemCapability.Location.Location.Geocoder
     * @since 9
     */
    addressUrl?: string;

    /**
     * Indicates additional information.
     *
     * @type { ?Array<string> }
     * @syscap SystemCapability.Location.Location.Geocoder
     * @since 9
     */
    descriptions?: Array<string>;

    /**
     * Indicates the amount of additional descriptive information.
     *
     * @type { ?number }
     * @syscap SystemCapability.Location.Location.Geocoder
     * @since 9
     */
    descriptionsSize?: number;

    /**
     * Indicates whether it is an mock GeoAddress
     *
     * @type { ?Boolean }
     * @syscap SystemCapability.Location.Location.Geocoder
     * @systemapi
     * @since 9
     */
    isFromMock?: Boolean;
  }

  /**
   * Configuring parameters in location requests.
   *
   * @typedef LocationRequest
   * @syscap SystemCapability.Location.Location.Core
   * @since 9
   */
  /**
   * Configuring parameters in location requests.
   *
   * @typedef LocationRequest
   * @syscap SystemCapability.Location.Location.Core
   * @atomicservice
   * @since 11
   */
  export interface LocationRequest {
    /**
     * Priority of the location request.
     *
     * @type { ?LocationRequestPriority }
     * @syscap SystemCapability.Location.Location.Core
     * @since 9
     */
    /**
     * Priority of the location request.
     *
     * @type { ?LocationRequestPriority }
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 11
     */
    priority?: LocationRequestPriority;

    /**
     * User scenario of the location request.
     *
     * @type { ?LocationRequestScenario }
     * @syscap SystemCapability.Location.Location.Core
     * @since 9
     */
    /**
     * User scenario of the location request.
     *
     * @type { ?LocationRequestScenario }
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 11
     */
    scenario?: LocationRequestScenario;

    /**
     * Location report interval.
     *
     * @type { ?number }
     * @syscap SystemCapability.Location.Location.Core
     * @since 9
     */
    /**
     * Location report interval.
     *
     * @type { ?number }
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 11
     */
    timeInterval?: number;

    /**
     * Location report distance interval.
     *
     * @type { ?number }
     * @syscap SystemCapability.Location.Location.Core
     * @since 9
     */
    /**
     * Location report distance interval.
     *
     * @type { ?number }
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 11
     */
    distanceInterval?: number;

    /**
     * Accuracy requirements for reporting locations.
     *
     * @type { ?number }
     * @syscap SystemCapability.Location.Location.Core
     * @since 9
     */
    /**
     * Accuracy requirements for reporting locations.
     *
     * @type { ?number }
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 11
     */
    maxAccuracy?: number;
  }

  /**
   * Configuring parameters in current location requests.
   *
   * @typedef CurrentLocationRequest
   * @syscap SystemCapability.Location.Location.Core
   * @since 9
   */
  /**
   * Configuring parameters in current location requests.
   *
   * @typedef CurrentLocationRequest
   * @syscap SystemCapability.Location.Location.Core
   * @atomicservice
   * @since 11
   */
  export interface CurrentLocationRequest {
    /**
     * Priority of the location request.
     *
     * @type { ?LocationRequestPriority }
     * @syscap SystemCapability.Location.Location.Core
     * @since 9
     */
    /**
     * Priority of the location request.
     *
     * @type { ?LocationRequestPriority }
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 11
     */
    priority?: LocationRequestPriority;

    /**
     * User scenario of the location request.
     *
     * @type { ?LocationRequestScenario }
     * @syscap SystemCapability.Location.Location.Core
     * @since 9
     */
    /**
     * User scenario of the location request.
     *
     * @type { ?LocationRequestScenario }
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 11
     */
    scenario?: LocationRequestScenario;

    /**
     * Accuracy requirements for reporting locations.
     *
     * @type { ?number }
     * @syscap SystemCapability.Location.Location.Core
     * @since 9
     */
    /**
     * Accuracy requirements for reporting locations.
     *
     * @type { ?number }
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 11
     */
    maxAccuracy?: number;

    /**
     * Timeout interval of a single location request.
     *
     * @type { ?number }
     * @syscap SystemCapability.Location.Location.Core
     * @since 9
     */
    /**
     * Timeout interval of a single location request.
     *
     * @type { ?number }
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 11
     */
    timeoutMs?: number;
  }

  /**
   * Geofence transition status.
   *
   * @typedef GeofenceTransition
   * @syscap SystemCapability.Location.Location.Geofence
   * @since 12
   */
  export interface GeofenceTransition {
    /**
     * ID of the geofence.
     *
     * @type { number }
     * @syscap SystemCapability.Location.Location.Geofence
     * @since 12
     */
    geofenceId: number;

    /**
     * Indicates the geofence transition status.
     *
     * @type { GeofenceTransitionEvent }
     * @syscap SystemCapability.Location.Location.Geofence
     * @since 12
     */
    transitionEvent: GeofenceTransitionEvent;
  }

  /**
   * Configuring parameters in continuous location requests.
   *
   * @typedef ContinuousLocationRequest
   * @syscap SystemCapability.Location.Location.Core
   * @atomicservice
   * @since 12
   */
  export interface ContinuousLocationRequest {
    /**
     * Location report interval, in seconds.
     *
     * @type { number }
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 12
     */
    interval: number;

    /**
     * Location scenario. You can select a user activity scenario or power consumption scenario.
     *
     * @type { UserActivityScenario | PowerConsumptionScenario }
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 12
     */
    locationScenario: UserActivityScenario | PowerConsumptionScenario;
  }

  /**
   * Configuring parameters in single location requests.
   *
   * @typedef SingleLocationRequest
   * @syscap SystemCapability.Location.Location.Core
   * @atomicservice
   * @since 12
   */
  export interface SingleLocationRequest {
    /**
     * Priority of the location request.
     *
     * @type { LocatingPriority }
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 12
     */
    locatingPriority: LocatingPriority;

    /**
     * Timeout of a single location request, in milliseconds.
     *
     * @type { number }
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 12
     */
    locatingTimeoutMs: number;
  }

  /**
   * Provides information about geographic locations.
   *
   * @typedef Location
   * @syscap SystemCapability.Location.Location.Core
   * @since 9
   */
  /**
   * Provides information about geographic locations.
   *
   * @typedef Location
   * @syscap SystemCapability.Location.Location.Core
   * @atomicservice
   * @since 11
   */
  export interface Location {
    /**
     * Indicates latitude information.
     * A positive value indicates north latitude,
     * and a negative value indicates south latitude.
     *
     * @type { number }
     * @syscap SystemCapability.Location.Location.Core
     * @since 9
     */
    /**
     * Indicates latitude information.
     * A positive value indicates north latitude,
     * and a negative value indicates south latitude.
     *
     * @type { number }
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 11
     */
    latitude: number;

    /**
     * Indicates Longitude information.
     * A positive value indicates east longitude ,
     * and a negative value indicates west longitude.
     *
     * @type { number }
     * @syscap SystemCapability.Location.Location.Core
     * @since 9
     */
    /**
     * Indicates Longitude information.
     * A positive value indicates east longitude ,
     * and a negative value indicates west longitude.
     *
     * @type { number }
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 11
     */
    longitude: number;

    /**
     * Indicates location altitude, in meters.
     *
     * @type { number }
     * @syscap SystemCapability.Location.Location.Core
     * @since 9
     */
    /**
     * Indicates location altitude, in meters.
     *
     * @type { number }
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 11
     */
    altitude: number;

    /**
     * Indicates location accuracy, in meters.
     *
     * @type { number }
     * @syscap SystemCapability.Location.Location.Core
     * @since 9
     */
    /**
     * Indicates location accuracy, in meters.
     *
     * @type { number }
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 11
     */
    accuracy: number;

    /**
     * Indicates speed, in m/s.
     *
     * @type { number }
     * @syscap SystemCapability.Location.Location.Core
     * @since 9
     */
    /**
     * Indicates speed, in m/s.
     *
     * @type { number }
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 11
     */
    speed: number;

    /**
     * Indicates location timestamp in the UTC format.
     *
     * @type { number }
     * @syscap SystemCapability.Location.Location.Core
     * @since 9
     */
    /**
     * Indicates location timestamp in the UTC format.
     *
     * @type { number }
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 11
     */
    timeStamp: number;

    /**
     * Indicates direction information.
     *
     * @type { number }
     * @syscap SystemCapability.Location.Location.Core
     * @since 9
     */
    /**
     * Indicates direction information.
     *
     * @type { number }
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 11
     */
    direction: number;

    /**
     * Indicates location timestamp since boot.
     *
     * @type { number }
     * @syscap SystemCapability.Location.Location.Core
     * @since 9
     */
    /**
     * Indicates location timestamp since boot.
     *
     * @type { number }
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 11
     */
    timeSinceBoot: number;

    /**
     * Indicates additional information.
     *
     * @type { ?Array<string> }
     * @syscap SystemCapability.Location.Location.Core
     * @since 9
     */
    /**
     * Indicates additional information.
     *
     * @type { ?Array<string> }
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 11
     */
    additions?: Array<string>;

    /**
     * Indicates additional information map.
     *
     * @type { ?Map<string, string> }
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 12
     */
    additionsMap?: Map<string, string>;

    /**
     * Indicates the amount of additional descriptive information.
     *
     * @type { ?number }
     * @syscap SystemCapability.Location.Location.Core
     * @since 9
     */
    /**
     * Indicates the amount of additional descriptive information.
     *
     * @type { ?number }
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 11
     */
    additionSize?: number;

    /**
     * Indicates whether it is an mock location.
     *
     * @type { ?Boolean }
     * @syscap SystemCapability.Location.Location.Core
     * @systemapi
     * @since 9
     */
    isFromMock?: Boolean;

    /**
     * Indicates vertical position accuracy in meters.
     *
     * @type { number }
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 12
     */
    altitudeAccuracy: number;

    /**
     * Indicates speed accuracy in meter per seconds.
     *
     * @type { number }
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 12
     */
    speedAccuracy: number;

    /**
     * Indicates direction accuracy in degrees.
     *
     * @type { number }
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 12
     */
    directionAccuracy: number;

    /**
     * Time uncertainty Of timeSinceBoot in nanosecond.
     *
     * @type { number }
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 12
     */
    uncertaintyOfTimeSinceBoot: number;

    /**
     * Indicates the source of the location.
     *
     * @type { LocationSourceType }
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 12
     */
    sourceType: LocationSourceType;
  }

  /**
   * Describes the request parameters for obtaining the data required for locating.
   * @typedef LocatingRequiredDataConfig
   * @syscap SystemCapability.Location.Location.Core
   * @systemapi
   * @since 10
   */
  export interface LocatingRequiredDataConfig {
    /**
     * Indicates the type of locating required data.
     *
     * @type {LocatingRequiredDataType}
     * @syscap SystemCapability.Location.Location.Core
     * @systemapi
     * @since 10
     */
    type: LocatingRequiredDataType;

    /**
     * Indicates whether to start scanning.
     *
     * @type {boolean}
     * @syscap SystemCapability.Location.Location.Core
     * @systemapi
     * @since 10
     */
    needStartScan: boolean;

    /**
     * Indicates the interval between scans. The unit is millisecond.
     * This parameter needs to be set only when scanning information is continuously monitored.
     *
     * @type {?number}
     * @syscap SystemCapability.Location.Location.Core
     * @systemapi
     * @since 10
     */
    scanInterval?: number;

    /**
     * Indicates the timeout period of a single scan. The unit is millisecond. The default value is 10000.
     * This parameter needs to be set only when getLocatingRequiredData is used.
     *
     * @type {?number}
     * @syscap SystemCapability.Location.Location.Core
     * @systemapi
     * @since 10
     */
    scanTimeout?: number;
  }

  /**
   * Describes the structure of the data required for locating.
   * @typedef LocatingRequiredData
   * @syscap SystemCapability.Location.Location.Core
   * @systemapi
   * @since 10
   */
  export interface LocatingRequiredData {
    /**
     * WiFi scan info.
     *
     * @type {?WifiScanInfo}
     * @syscap SystemCapability.Location.Location.Core
     * @systemapi
     * @since 10
     */
    wifiData?: WifiScanInfo;

    /**
     * Bluetooth scan info.
     *
     * @type {?BluetoothScanInfo}
     * @syscap SystemCapability.Location.Location.Core
     * @systemapi
     * @since 10
     */
    bluetoothData?: BluetoothScanInfo;
  }

  /**
   * Describes the scanned WiFi information.
   * @typedef WifiScanInfo
   * @syscap SystemCapability.Location.Location.Core
   * @systemapi
   * @since 10
   */
  export interface WifiScanInfo {
    /**
     * WiFi SSID: the maximum length is 32.
     *
     * @type {string}
     * @syscap SystemCapability.Location.Location.Core
     * @systemapi
     * @since 10
     */
    ssid: string;

    /**
     * WiFi bssid(MAC): the length is 6.
     *
     * @type {string}
     * @syscap SystemCapability.Location.Location.Core
     * @systemapi
     * @since 10
     */
    bssid: string;

    /**
     * Received signal strength indicator (RSSI).
     *
     * @type {number}
     * @syscap SystemCapability.Location.Location.Core
     * @systemapi
     * @since 10
     */
    rssi: number;

    /**
     * Frequency
     *
     * @type {number}
     * @syscap SystemCapability.Location.Location.Core
     * @systemapi
     * @since 10
     */
    frequency: number;

    /**
     * Time stamp.
     *
     * @type {number}
     * @syscap SystemCapability.Location.Location.Core
     * @systemapi
     * @since 10
     */
    timestamp: number;
  }

  /**
   * Describes the contents of the Bluetooth scan results.
   *
   * @typedef BluetoothScanInfo
   * @syscap SystemCapability.Location.Location.Core
   * @systemapi
   * @since 10
   */
  export interface BluetoothScanInfo {
    /**
     * The local name of the device.
     *
     * @type {string}
     * @syscap SystemCapability.Location.Location.Core
     * @systemapi
     * @since 10
     */
    deviceName: string;

    /**
     * Mac address of the scanned device.
     *
     * @type {string}
     * @syscap SystemCapability.Location.Location.Core
     * @systemapi
     * @since 10
     */
    macAddress: string;

    /**
     * RSSI of the remote device.
     *
     * @type {number}
     * @syscap SystemCapability.Location.Location.Core
     * @systemapi
     * @since 10
     */
    rssi: number;

    /**
     * Time stamp.
     *
     * @type {number}
     * @syscap SystemCapability.Location.Location.Core
     * @systemapi
     * @since 10
     */
    timestamp: number;
  }

  /**
   * Enum for the source of the location.
   *
   * @enum { number }
   * @syscap SystemCapability.Location.Location.Core
   * @atomicservice
   * @since 12
   */
  export enum LocationSourceType {
    /**
     * The location is obtained from the GNSS.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 12
     */
    GNSS = 1,

    /**
     * The location comes from the network positioning technology.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 12
     */
    NETWORK = 2,

    /**
     * The location comes from the indoor positioning technology.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 12
     */
    INDOOR = 3,

    /**
     * The location comes from the GNSS RTK technology.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 12
     */
    RTK = 4
  }

  /**
   * Enum for coordinate system type.
   *
   * @enum { number }
   * @syscap SystemCapability.Location.Location.Geofence
   * @since 12
   */
  export enum CoordinateSystemType {
    /**
     * WGS84 coordinates system.
     *
     * @syscap SystemCapability.Location.Location.Geofence
     * @since 12
     */
    WGS84 = 1,

    /**
     * GCJ-02 coordinates system.
     *
     * @syscap SystemCapability.Location.Location.Geofence
     * @since 12
     */
    GCJ02 = 2
  }

  /**
   * Enum for location icon status.
   *
   * @enum { number }
   * @syscap SystemCapability.Location.Location.Core
   * @systemapi
   * @since 12
   */
  export enum LocationIconStatus {
    /**
     * The locating service is not started.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @systemapi
     * @since 12
     */
    LOCATING_NOT_STARTED = 0,

    /**
     * The normal locating service is started.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @systemapi
     * @since 12
     */
    LOCATING_STARTED = 1,

    /**
     * The HD locating service(RTK) is started.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @systemapi
     * @since 12
     */
    HD_LOCATING_STARTED = 2
  }

  /**
   * Enum for location error code.
   *
   * @enum { number }
   * @syscap SystemCapability.Location.Location.Core
   * @atomicservice
   * @since 12
   */
  export enum LocationError {
    /**
     * Default cause for location failure.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 12
     */
    LOCATING_FAILED_DEFAULT = -1,

    /**
     * Locating failed because the location permission fails to be verified.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 12
     */
    LOCATING_FAILED_LOCATION_PERMISSION_DENIED = -2,

    /**
     * Locating failed because the app is in the background and the background location permission verification failed.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 12
     */
    LOCATING_FAILED_BACKGROUND_PERMISSION_DENIED = -3,

    /**
     * Locating failed because the location switch is turned off.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 12
     */
    LOCATING_FAILED_LOCATION_SWITCH_OFF = -4,

    /**
     * Locating failed because internet access failure.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 12
     */
    LOCATING_FAILED_INTERNET_ACCESS_FAILURE = -5
  }

  /**
   * Enum for geofence transition status.
   *
   * @enum { number }
   * @syscap SystemCapability.Location.Location.Geofence
   * @since 12
   */
  export enum GeofenceTransitionEvent {
    /**
     * The device is within the geofence.
     *
     * @syscap SystemCapability.Location.Location.Geofence
     * @since 12
     */
    GEOFENCE_TRANSITION_EVENT_ENTER = 1,

    /**
     * The device is out of the geofence.
     *
     * @syscap SystemCapability.Location.Location.Geofence
     * @since 12
     */
    GEOFENCE_TRANSITION_EVENT_EXIT = 2,

    /**
     * The device is in the geographical fence for a period of time.
     *
     * @syscap SystemCapability.Location.Location.Geofence
     * @since 12
     */
    GEOFENCE_TRANSITION_EVENT_DWELL = 4
  }

  /**
   * Enum for satellite constellation category.
   *
   * @enum { number }
   * @syscap SystemCapability.Location.Location.Gnss
   * @since 12
   */
  export enum SatelliteConstellationCategory {
    /**
     * Invalid value.
     *
     * @syscap SystemCapability.Location.Location.Gnss
     * @since 12
     */
    CONSTELLATION_CATEGORY_UNKNOWN = 0,

    /**
     * GPS.
     *
     * @syscap SystemCapability.Location.Location.Gnss
     * @since 12
     */
    CONSTELLATION_CATEGORY_GPS = 1,

    /**
     * SBAS.
     *
     * @syscap SystemCapability.Location.Location.Gnss
     * @since 12
     */
    CONSTELLATION_CATEGORY_SBAS = 2,

    /**
     * GLONASS.
     *
     * @syscap SystemCapability.Location.Location.Gnss
     * @since 12
     */
    CONSTELLATION_CATEGORY_GLONASS = 3,

    /**
     * QZSS.
     *
     * @syscap SystemCapability.Location.Location.Gnss
     * @since 12
     */
    CONSTELLATION_CATEGORY_QZSS = 4,

    /**
     * BEIDOU.
     *
     * @syscap SystemCapability.Location.Location.Gnss
     * @since 12
     */
    CONSTELLATION_CATEGORY_BEIDOU = 5,

    /**
     * GALILEO.
     *
     * @syscap SystemCapability.Location.Location.Gnss
     * @since 12
     */
    CONSTELLATION_CATEGORY_GALILEO = 6,

    /**
     * IRNSS.
     *
     * @syscap SystemCapability.Location.Location.Gnss
     * @since 12
     */
    CONSTELLATION_CATEGORY_IRNSS = 7
  }

  /**
   * Enum for satellite additional information.
   *
   * @enum { number }
   * @syscap SystemCapability.Location.Location.Gnss
   * @since 12
   */
  export enum SatelliteAdditionalInfo {
    /**
     * Default value.
     *
     * @syscap SystemCapability.Location.Location.Gnss
     * @since 12
     */
    SATELLITES_ADDITIONAL_INFO_NULL = 0,

    /**
     * Ephemeris data exist.
     *
     * @syscap SystemCapability.Location.Location.Gnss
     * @since 12
     */
    SATELLITES_ADDITIONAL_INFO_EPHEMERIS_DATA_EXIST = 1,

    /**
     * Almanac data exist.
     *
     * @syscap SystemCapability.Location.Location.Gnss
     * @since 12
     */
    SATELLITES_ADDITIONAL_INFO_ALMANAC_DATA_EXIST = 2,

    /**
     * This satellite is being used in location fix.
     *
     * @syscap SystemCapability.Location.Location.Gnss
     * @since 12
     */
    SATELLITES_ADDITIONAL_INFO_USED_IN_FIX = 4,

    /**
     * Carrier frequency exist.
     *
     * @syscap SystemCapability.Location.Location.Gnss
     * @since 12
     */
    SATELLITES_ADDITIONAL_INFO_CARRIER_FREQUENCY_EXIST = 8
  }

  /**
   * Enum for user activity scenario.
   *
   * @enum { number }
   * @syscap SystemCapability.Location.Location.Core
   * @atomicservice
   * @since 12
   */
  export enum UserActivityScenario {
    /**
     * Navigation scenario. High positioning precision and real-time performance are required.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 12
     */
    NAVIGATION = 0x401,

    /**
     * Sport scenario. High positioning precision is required.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 12
     */
    SPORT = 0x402,

    /**
     * Transport scenario. High positioning precision and real-time performance are required.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 12
     */
    TRANSPORT = 0x403,

    /**
     * Daily life scenarios. Low requirements on positioning precision.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 12
     */
    DAILY_LIFE_SERVICE = 0x404
  }

  /**
   * Enum for locating priority.
   *
   * @enum { number }
   * @syscap SystemCapability.Location.Location.Core
   * @atomicservice
   * @since 12
   */
  export enum LocatingPriority {
    /**
     * Preferentially ensure the highest locating accuracy.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 12
     */
    PRIORITY_ACCURACY = 0x501,

    /**
     * Preferentially ensure the fastest locating speed.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 12
     */
    PRIORITY_LOCATING_SPEED = 0x502
  }

  /**
   * Enum for location priority.
   *
   * @enum { number }
   * @syscap SystemCapability.Location.Location.Core
   * @since 9
   */
  /**
   * Enum for location priority.
   *
   * @enum { number }
   * @syscap SystemCapability.Location.Location.Core
   * @atomicservice
   * @since 11
   */
  export enum LocationRequestPriority {
    /**
     * Default priority.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @since 9
     */
    /**
     * Default priority.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 11
     */
    UNSET = 0x200,

    /**
     * Preferentially ensure the locating accuracy.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @since 9
     */
    /**
     * Preferentially ensure the locating accuracy.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 11
     */
    ACCURACY,

    /**
     * Preferentially ensure low power consumption for locating.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @since 9
     */
    /**
     * Preferentially ensure low power consumption for locating.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 11
     */
    LOW_POWER,

    /**
     * Preferentially ensure that the first location is time-consuming.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @since 9
     */
    /**
     * Preferentially ensure that the first location is time-consuming.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 11
     */
    FIRST_FIX
  }

  /**
   * Enum for location scenario.
   *
   * @enum { number }
   * @syscap SystemCapability.Location.Location.Core
   * @since 9
   */
  /**
   * Enum for location scenario.
   *
   * @enum { number }
   * @syscap SystemCapability.Location.Location.Core
   * @atomicservice
   * @since 11
   */
  export enum LocationRequestScenario {
    /**
     * Default scenario.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @since 9
     */
    /**
     * Default scenario.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 11
     */
    UNSET = 0x300,

    /**
     * Navigation scenario. High positioning precision and real-time performance are required.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @since 9
     */
    /**
     * Navigation scenario. High positioning precision and real-time performance are required.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 11
     */
    NAVIGATION,

    /**
     * Trajectory tracking scenario. High positioning precision is required.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @since 9
     */
    /**
     * Trajectory tracking scenario. High positioning precision is required.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 11
     */
    TRAJECTORY_TRACKING,

    /**
     * Car hailing scenario. High positioning precision and real-time performance are required.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @since 9
     */
    /**
     * Car hailing scenario. High positioning precision and real-time performance are required.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 11
     */
    CAR_HAILING,

    /**
     * Daily life scenarios. Low requirements on positioning precision and real-time performance.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @since 9
     */
    /**
     * Daily life scenarios. Low requirements on positioning precision and real-time performance.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 11
     */
    DAILY_LIFE_SERVICE,

    /**
     * Power saving scenarios.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @since 9
     */
    /**
     * Power saving scenarios.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 11
     */
    NO_POWER
  }

  /**
   * Enum for power consumption scenario.
   *
   * @enum { number }
   * @syscap SystemCapability.Location.Location.Core
   * @atomicservice
   * @since 12
   */
  export enum PowerConsumptionScenario {
    /**
     * High power consumption mode.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 12
     */
    HIGH_POWER_CONSUMPTION = 0x601,

    /**
     * Low power consumption mode.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 12
     */
    LOW_POWER_CONSUMPTION = 0x602,

    /**
     * Power saving scenarios.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @atomicservice
     * @since 12
     */
    NO_POWER_CONSUMPTION = 0x603
  }

  /**
   * Enum for location privacy type.
   *
   * @enum { number }
   * @syscap SystemCapability.Location.Location.Core
   * @systemapi
   * @since 9
   */
  export enum LocationPrivacyType {
    /**
     * Other scenarios.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @systemapi
     * @since 9
     */
    OTHERS = 0,

    /**
     * Privacy agreement for the startup wizard scenario.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @systemapi
     * @since 9
     */
    STARTUP,

    /**
     * Privacy agreement pop-up when network location is enabled.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @systemapi
     * @since 9
     */
    CORE_LOCATION
  }

  /**
   * Location subsystem command structure.
   *
   * @typedef LocationCommand
   * @syscap SystemCapability.Location.Location.Core
   * @since 9
   */
  export interface LocationCommand {
    /**
     * Information about the scenario where the command is sent.
     *
     * @type { LocationRequestScenario }
     * @syscap SystemCapability.Location.Location.Core
     * @since 9
     */
    scenario: LocationRequestScenario;

    /**
     * Sent command content.
     *
     * @type { string }
     * @syscap SystemCapability.Location.Location.Core
     * @since 9
     */
    command: string;
  }

  /**
   * Country code structure.
   *
   * @typedef CountryCode
   * @syscap SystemCapability.Location.Location.Core
   * @since 9
   */
  export interface CountryCode {
    /**
     * Country code character string.
     *
     * @type { string }
     * @syscap SystemCapability.Location.Location.Core
     * @since 9
     */
    country: string;

    /**
     * Country code source.
     *
     * @type { CountryCodeType }
     * @syscap SystemCapability.Location.Location.Core
     * @since 9
     */
    type: CountryCodeType;
  }

  /**
   * Enum for country code type.
   *
   * @enum { number }
   * @syscap SystemCapability.Location.Location.Core
   * @since 9
   */
  export enum CountryCodeType {
    /**
     * Country code obtained from the locale setting.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @since 9
     */
    COUNTRY_CODE_FROM_LOCALE = 1,

    /**
     * Country code obtained from the SIM information.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @since 9
     */
    COUNTRY_CODE_FROM_SIM,

    /**
     * Query the country code information from the reverse geocoding result.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @since 9
     */
    COUNTRY_CODE_FROM_LOCATION,

    /**
     * Obtain the country code from the cell registration information.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @since 9
     */
    COUNTRY_CODE_FROM_NETWORK
  }

  /**
   * Enum for locating required data type.
   *
   * @enum { number }
   * @syscap SystemCapability.Location.Location.Core
   * @systemapi
   * @since 10
   */
  export enum LocatingRequiredDataType {
    /**
     * Obtains WiFi scanning information for locating.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @systemapi
     * @since 10
     */
    WIFI = 1,

    /**
     * Obtains BT scanning information for locating.
     *
     * @syscap SystemCapability.Location.Location.Core
     * @systemapi
     * @since 10
     */
    BLUETOOTH
  }
}

export default geoLocationManager;