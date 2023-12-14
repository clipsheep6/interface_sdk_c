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

import sensor from '../@ohos.sensor';
import vibrator from '../@ohos.vibrator';
import Sensor, {
  type AccelerometerResponse, type BarometerResponse, type CompassResponse, type DeviceOrientationResponse,
  type GetOnBodyStateOptions, type GyroscopeResponse, type HeartRateResponse, type LightResponse,
  type OnBodyStateResponse, type ProximityResponse, type StepCounterResponse, type SubscribeBarometerOptions,
  type SubscribeCompassOptions, type SubscribeDeviceOrientationOptions, type SubscribeGyroscopeOptions,
  type SubscribeHeartRateOptions, type SubscribeLightOptions, type SubscribeOnBodyStateOptions,
  type SubscribeProximityOptions, type SubscribeStepCounterOptions, type subscribeAccelerometerOptions
} from '../@system.sensor';
import Vibrator, { VibrateOptions } from '../@system.vibrator';

export {
  type AccelerometerResponse, type BarometerResponse, type CompassResponse, type DeviceOrientationResponse,
  type GetOnBodyStateOptions, type GyroscopeResponse, type HeartRateResponse, type LightResponse,
  type OnBodyStateResponse, type ProximityResponse, Sensor, type StepCounterResponse, type SubscribeBarometerOptions,
  type SubscribeCompassOptions, type SubscribeDeviceOrientationOptions, type SubscribeGyroscopeOptions,
  type SubscribeHeartRateOptions, type SubscribeLightOptions, type SubscribeOnBodyStateOptions,
  type SubscribeProximityOptions, type SubscribeStepCounterOptions, VibrateOptions, Vibrator, sensor,
  type subscribeAccelerometerOptions, vibrator
};
