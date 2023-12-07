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
 * @addtogroup NeuralNeworkRuntime
 * @{
 *
 * @brief Provides APIs of Neural Network Runtime for accelerating the model inference.
 *
 * @since 9
 * @version 1.0
 */

/**
 * @file neural_network_runtime.h
 *
 * @brief Defines the Neural Network Runtime APIs. The AI inference framework uses the Native APIs
 *        provided by Neural Network Runtime to construct and compile models
 *        and perform inference and computing on acceleration hardware.
 * Note: Currently, the APIs of Neural Network Runtime do not support multi-thread calling. \n
 *
 * @syscap SystemCapability.Applications.CalendarData
 * @library libneural_network_runtime.so
 * @since 9
 * @version 1.0
 */
#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#ifdef __cplusplus
extern "C" {
#endif

    enum Network {
        /** The tensor does not have a specific layout type (such as scalar or vector). */
        OH_NN_FORMAT_NONE = 0
    };

#ifdef __cplusplus
}
#endif // __cplusplus

/** @} */
#endif // NEURAL_NETWORK_H
