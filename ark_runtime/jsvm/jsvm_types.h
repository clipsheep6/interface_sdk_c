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

#ifndef _JSVM_API_TYPE_H_
#define _JSVM_API_TYPE_H_

// This file needs to be compatible with C compilers.
// This is a public include file, and these includes have essentially
// became part of it's API.
#include <stddef.h>  // NOLINT(modernize-deprecated-headers)
#include <stdint.h>  // NOLINT(modernize-deprecated-headers)

#if !defined __cplusplus || (defined(_MSC_VER) && _MSC_VER < 1900)
typedef uint16_t char16_t;
#endif

#ifndef JSVM_CDECL
#ifdef _WIN32
#define JSVM_CDECL __cdecl
#else
#define JSVM_CDECL
#endif
#endif

// JSVM API types are all opaque pointers for ABI stability
// typedef undefined structs instead of void* for compile time type safety
typedef struct JSVM_VM__* JSVM_VM;
typedef struct JSVM_VM_Scope__* JSVM_VM_Scope;
typedef struct JSVM_EnvScope__* JSVM_EnvScope;
typedef struct JSVM_Script__* JSVM_Script;
typedef struct JSVM_Env__* JSVM_Env;
typedef struct JSVM_Value__* JSVM_Value;
typedef struct JSVM_Ref__* JSVM_Ref;
typedef struct JSVM_HandleScope__* JSVM_HandleScope;
typedef struct JSVM_EscapableHandleScope__* JSVM_EscapableHandleScope;
typedef struct JSVM_CallbackInfo__* JSVM_CallbackInfo;
typedef struct JSVM_Deferred__* JSVM_Deferred;

typedef enum {
  JSVM_DEFAULT = 0,
  JSVM_WRITABLE = 1 << 0,
  JSVM_ENUMERABLE = 1 << 1,
  JSVM_CONFIGURABLE = 1 << 2,

  // Used with OH_JSVM_DefineClass to distinguish static properties
  // from instance properties. Ignored by OH_JSVM_DefineProperties.
  JSVM_STATIC = 1 << 10,

#if JSVM_VERSION >= 8
  // Default for class methods.
  JSVM_DEFAULT_METHOD = JSVM_WRITABLE | JSVM_CONFIGURABLE,

  // Default for object properties, like in JS obj[prop].
  JSVM_DEFAULT_JSPROPERTY = JSVM_WRITABLE | JSVM_ENUMERABLE | JSVM_CONFIGURABLE,
#endif  // JSVM_VERSION >= 8
} JSVM_PropertyAttributes;

typedef enum {
  // ES6 types (corresponds to typeof)
  JSVM_UNDEFINED,
  JSVM_NULL,
  JSVM_BOOLEAN,
  JSVM_NUMBER,
  JSVM_STRING,
  JSVM_SYMBOL,
  JSVM_OBJECT,
  JSVM_FUNCTION,
  JSVM_EXTERNAL,
  JSVM_BIGINT,
} JSVM_ValueType;

typedef enum {
  JSVM_INT8_ARRAY,
  JSVM_UINT8_ARRAY,
  JSVM_UINT8_CLAMPED_ARRAY,
  JSVM_INT16_ARRAY,
  JSVM_UINT16_ARRAY,
  JSVM_INT32_ARRAY,
  JSVM_UINT32_ARRAY,
  JSVM_FLOAT32_ARRAY,
  JSVM_FLOAT64_ARRAY,
  JSVM_BIGINT64_ARRAY,
  JSVM_BIGUINT64_ARRAY,
} JSVM_TypedarrayType;

typedef enum {
  JSVM_OK,
  JSVM_INVALID_ARG,
  JSVM_OBJECT_EXPECTED,
  JSVM_STRING_EXPECTED,
  JSVM_NAME_EXPECTED,
  JSVM_FUNCTION_EXPECTED,
  JSVM_NUMBER_EXPECTED,
  JSVM_BOOLEAN_EXPECTED,
  JSVM_ARRAY_EXPECTED,
  JSVM_GENERIC_FAILURE,
  JSVM_PENDING_EXCEPTION,
  JSVM_CANCELLED,
  JSVM_ESCAPE_CALLED_TWICE,
  JSVM_HANDLE_SCOPE_MISMATCH,
  JSVM_CALLBACK_SCOPE_MISMATCH,
  JSVM_QUEUE_FULL,
  JSVM_CLOSING,
  JSVM_BIGINT_EXPECTED,
  JSVM_DATE_EXPECTED,
  JSVM_ARRAYBUFFER_EXPECTED,
  JSVM_DETACHABLE_ARRAYBUFFER_EXPECTED,
  JSVM_WOULD_DEADLOCK,  // unused
  JSVM_NO_EXTERNAL_BUFFERS_ALLOWED,
  JSVM_CANNOT_RUN_JS,
} JSVM_Status;
// Note: when adding a new enum value to `JSVM_Status`, please also update
//   * `const int last_status` in the definition of `OH_JSVM_GetLastErrorInfo()'
//     in file js_native_api_v8.cc.
//   * `const char* error_messages[]` in file js_native_api_v8.cc with a brief
//     message explaining the error.
//   * the definition of `JSVM_Status` in doc/api/n-api.md to reflect the newly
//     added value(s).

typedef JSVM_Value(JSVM_CDECL* JSVM_Callback)(JSVM_Env env,
                                              JSVM_CallbackInfo info);
typedef void(JSVM_CDECL* JSVM_Finalize)(JSVM_Env env,
                                        void* finalize_data,
                                        void* finalize_hint);

typedef struct {
 // Flags for the VM. IF remove_flags is true, recognized flags will be removed
 // from (argc, argv). Note that these flags are specific to VM (currently V8).
 // They are mainly used for development. Do not include them in production as
 // they might not take effect if the VM is different from the development
 // environment.
 int* argc;
 char** argv;
 bool removeFlags;
} JSVM_InitOptions;

typedef struct {
    size_t maxOldGenerationSize;
    size_t maxYoungGenerationSize;
    size_t initialOldGenerationSize;
    size_t initialYoungGenerationSize;
    // Optional startup snapshot data.
    const char* snapshotBlobData;
    // Optional size of the startup snapshot data.
    size_t snapshotBlobSize;
    // Optional nullptr-terminated array of raw addresses in the embedder that the
    // VM can match against during serialization and use for deserialization. This
    // array and its content must stay valid for the entire lifetime of the VM
    // instance.
    const intptr_t* externalReferences;
} JSVM_CreateVMOptions;

typedef struct {
  // One of utf8name or name should be NULL.
  const char* utf8name;
  JSVM_Value name;

  JSVM_Callback method;
  JSVM_Callback getter;
  JSVM_Callback setter;
  JSVM_Value value;

  JSVM_PropertyAttributes attributes;
  void* data;
} JSVM_PropertyDescriptor;

typedef struct{
  const char* errorMessage;
  void* engineReserved;
  uint32_t engineErrorCode;
  JSVM_Status errorCode;
} JSVM_ExtendedErrorInfo; 

#if JSVM_VERSION >= 6
typedef enum {
  JSVM_KEY_INCLUDE_PROTOTYPES,
  JSVM_KEY_OWN_ONLY
} JSVM_KeyCollectionMode;

typedef enum {
  JSVM_KEY_ALL_PROPERTIES = 0,
  JSVM_KEY_WRITABLE = 1,
  JSVM_KEY_ENUMERABLE = 1 << 1,
  JSVM_KEY_CONFIGURABLE = 1 << 2,
  JSVM_KEY_SKIP_STRINGS = 1 << 3,
  JSVM_KEY_SKIP_SYMBOLS = 1 << 4
} JSVM_KeyFilter;

typedef enum {
  JSVM_KEY_KEEP_NUMBERS,
  JSVM_KEY_NUMBERS_TO_STRINGS
} JSVM_KeyConversion;
#endif  // JSVM_VERSION >= 6

#if JSVM_VERSION >= 8
typedef struct {
  uint64_t lower;
  uint64_t upper;
} JSVM_TypeTag;
#endif  // JSVM_VERSION >= 8

#endif  // _JSVM_API_TYPE_H_
