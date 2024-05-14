/*
 * Copyright (c) 2024 Huawei Device Co., Ltd.
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

#ifndef INCLUDE_NATIVE_ERROR_CODE_H
#define INCLUDE_NATIVE_ERROR_CODE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief interface error code.
 * @since 12
 */
typedef enum OHNativeErrorCode {
    /** succeed */
    NATIVE_ERROR_OK = 0,
    /** input invalid parameter */
    NATIVE_ERROR_INVALID_ARGUMENTS = 40001000,
    /** unauthorized operation */
    NATIVE_ERROR_NO_PERMISSION = 40301000,
    /** no idle buffer is available */
    NATIVE_ERROR_NO_BUFFER = 40601000,
    /** the consumer side doesn't exist */
    NATIVE_ERROR_NO_CONSUMER = 41202000,
    /** uninitialized */
    NATIVE_ERROR_NOT_INIT = 41203000,
    /** the consumer is connected */
    NATIVE_ERROR_CONSUMER_IS_CONNECTED = 41206000,
    /** the buffer status did not meet expectations */
    NATIVE_ERROR_BUFFER_STATE_INVALID = 41207000,
    /** buffer is already in the cache queue */
    NATIVE_ERROR_BUFFER_IS_INCACHE = 41208000,
    /** the buffer queue is full */
    NATIVE_ERROR_BUFFER_QUEUE_FULL = 41209000,
    /** buffer is not in the cache queue */
    NATIVE_ERROR_BUFFER_NOT_INCACHE = 41210000,
    /** the current device or platform does not support it */
    NATIVE_ERROR_UNSUPPORT = 50102000,
    /** unknown error, please check log */
    NATIVE_ERROR_UNKNOW = 50002000,
    /** the egl environment is abnormal */
    NATIVE_ERROR_EGL_STATE_UNKNOW = 60001000,
    /** egl interface invocation failed */
    NATIVE_ERROR_EGL_API_FAILED = 60002000,
} OHNativeErrorCode;

#ifdef __cplusplus
}
#endif

#endif // INCLUDE_NATIVE_ERROR_CODE_H