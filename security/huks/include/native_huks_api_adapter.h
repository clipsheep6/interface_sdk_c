/*
 * Copyright (c) 2022 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @file
 * @kit Universal Keystore Kit
 */
 
#ifndef NATIVE_HUKS_API_ADAPTER_H
#define NATIVE_HUKS_API_ADAPTER_H

#include "native_huks_type.h"

#ifdef __cplusplus
extern "C" {
#endif

int32_t HuksAttestAdapter(const struct OH_Huks_Blob *keyAlias, const struct OH_Huks_ParamSet *paramSet,
    struct OH_Huks_CertChain *certChain);

#ifdef __cplusplus
}
#endif

#endif /* NATIVE_HUKS_API_ADAPTER_H */
