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

#ifndef _JSVM_API_H_
#define _JSVM_API_H_

// This file needs to be compatible with C compilers.
#include <stdbool.h>  // NOLINT(modernize-deprecated-headers)
#include <stddef.h>   // NOLINT(modernize-deprecated-headers)

// Use INT_MAX, this should only be consumed by the pre-processor anyway.
#define JSVM_VERSION_EXPERIMENTAL 2147483647
#ifndef JSVM_VERSION
#ifdef JSVM_EXPERIMENTAL
#define JSVM_VERSION JSVM_VERSION_EXPERIMENTAL
#else
// The baseline version for JSVM-API.
// The JSVM_VERSION controls which version will be used by default when
// compilling a native addon. If the addon developer specifically wants to use
// functions available in a new version of JSVM-API that is not yet ported in all
// LTS versions, they can set JSVM_VERSION knowing that they have specifically
// depended on that version.
#define JSVM_VERSION 8
#endif
#endif

#include "jsvm_types.h"

// If you need __declspec(dllimport), either include <node_api.h> instead, or
// define JSVM_EXTERN as __declspec(dllimport) on the compiler's command line.
#ifndef JSVM_EXTERN
#ifdef _WIN32
#define JSVM_EXTERN __declspec(dllexport)
#elif defined(__wasm__)
#define JSVM_EXTERN                                                            \
  __attribute__((visibility("default")))                                       \
  __attribute__((__import_module__("jsvm")))
#else
#define JSVM_EXTERN __attribute__((visibility("default")))
#endif
#endif

#define JSVM_AUTO_LENGTH SIZE_MAX

#ifdef __cplusplus
#define EXTERN_C_START extern "C" {
#define EXTERN_C_END }
#else
#define EXTERN_C_START
#define EXTERN_C_END
#endif

EXTERN_C_START

JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_Init(const JSVM_InitOptions* options);

JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_CreateVM(JSVM_CreateVMOptions* options, JSVM_VM* result);

JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_DestroyVM(JSVM_VM vm);

JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_OpenVMScope(JSVM_VM vm, JSVM_VM_Scope* result);

JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_CloseVMScope(JSVM_VM vm, JSVM_VM_Scope scope);

JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_CreateEnv(JSVM_VM vm,
   size_t propertyCount,
   const JSVM_PropertyDescriptor* properties,
   JSVM_Env* result);

JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_DestroyEnv(JSVM_Env env);

JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_OpenEnvScope(JSVM_Env env, JSVM_EnvScope* result);

JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_CloseEnvScope(JSVM_Env env, JSVM_EnvScope scope);

JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_CompileScript(JSVM_Env env,
                    JSVM_Value script,
                    const uint8_t* cached_data,
                    size_t cached_data_length,
                    bool eager_compile,
                    JSVM_Script* result);

JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_CreateCodeCache(JSVM_Env env,
                       JSVM_Script script,
                       uint8_t** data,
                       size_t* length);

JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_RunScript(JSVM_Env env, JSVM_Script script, JSVM_Value* result);

JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_JsonParse(JSVM_Env env, JSVM_Value json_string, JSVM_Value* result);

JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_JsonStringify(JSVM_Env env, JSVM_Value json_object, JSVM_Value* result);

JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_CreateSnapshot(JSVM_VM vm,
        size_t context_count,
        const JSVM_Env* contexts,
        const char** blob_data,
        size_t* blob_size);

JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_GetLastErrorInfo(JSVM_Env env, const JSVM_ExtendedErrorInfo** result);

// Getters for defined singletons
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_GetUndefined(JSVM_Env env,
                                                      JSVM_Value* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_GetNull(JSVM_Env env,
                                                 JSVM_Value* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_GetGlobal(JSVM_Env env,
                                                   JSVM_Value* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_GetBoolean(JSVM_Env env,
                                                    bool value,
                                                    JSVM_Value* result);

// Methods to create Primitive types/Objects
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_CreateObject(JSVM_Env env,
                                                      JSVM_Value* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_CreateArray(JSVM_Env env,
                                                     JSVM_Value* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_CreateArrayWithLength(JSVM_Env env, size_t length, JSVM_Value* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_CreateDouble(JSVM_Env env,
                                                      double value,
                                                      JSVM_Value* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_CreateInt32(JSVM_Env env,
                                                     int32_t value,
                                                     JSVM_Value* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_CreateUint32(JSVM_Env env,
                                                      uint32_t value,
                                                      JSVM_Value* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_CreateInt64(JSVM_Env env,
                                                     int64_t value,
                                                     JSVM_Value* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_CreateStringLatin1(
    JSVM_Env env, const char* str, size_t length, JSVM_Value* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_CreateStringUtf8(JSVM_Env env,
                                                           const char* str,
                                                           size_t length,
                                                           JSVM_Value* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_CreateStringUtf16(JSVM_Env env,
                                                            const char16_t* str,
                                                            size_t length,
                                                            JSVM_Value* result);
#ifdef JSVM_EXPERIMENTAL
#define NODE_API_EXPERIMENTAL_HAS_EXTERNAL_STRINGS
JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_CreateExternalStringLatin1(JSVM_Env env,
                                       char* str,
                                       size_t length,
                                       JSVM_Finalize finalizeCallback,
                                       void* finalizeHint,
                                       JSVM_Value* result,
                                       bool* copied);
JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_CreateExternalStringUtf16(JSVM_Env env,
                                      char16_t* str,
                                      size_t length,
                                      JSVM_Finalize finalizeCallback,
                                      void* finalizeHint,
                                      JSVM_Value* result,
                                      bool* copied);
#endif  // JSVM_EXPERIMENTAL
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_CreateSymbol(JSVM_Env env,
                                                      JSVM_Value description,
                                                      JSVM_Value* result);
#if JSVM_VERSION >= 9
JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_SymbolFor(JSVM_Env env,
                    const char* utf8description,
                    size_t length,
                    JSVM_Value* result);
#endif  // JSVM_VERSION >= 9
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_CreateFunction(JSVM_Env env,
                                                        const char* utf8name,
                                                        size_t length,
                                                        JSVM_Callback cb,
                                                        void* data,
                                                        JSVM_Value* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_CreateError(JSVM_Env env,
                                                     JSVM_Value code,
                                                     JSVM_Value msg,
                                                     JSVM_Value* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_CreateTypeError(JSVM_Env env,
                                                          JSVM_Value code,
                                                          JSVM_Value msg,
                                                          JSVM_Value* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_CreateRangeError(JSVM_Env env,
                                                           JSVM_Value code,
                                                           JSVM_Value msg,
                                                           JSVM_Value* result);
#if JSVM_VERSION >= 9
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_CreateSyntaxError(
    JSVM_Env env, JSVM_Value code, JSVM_Value msg, JSVM_Value* result);
#endif  // JSVM_VERSION >= 9

// Methods to get the native JSVM_Value from Primitive type
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_Typeof(JSVM_Env env,
                                               JSVM_Value value,
                                               JSVM_ValueType* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_GetValueDouble(JSVM_Env env,
                                                         JSVM_Value value,
                                                         double* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_GetValueInt32(JSVM_Env env,
                                                        JSVM_Value value,
                                                        int32_t* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_GetValueUint32(JSVM_Env env,
                                                         JSVM_Value value,
                                                         uint32_t* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_GetValueInt64(JSVM_Env env,
                                                        JSVM_Value value,
                                                        int64_t* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_GetValueBool(JSVM_Env env,
                                                       JSVM_Value value,
                                                       bool* result);

// Copies LATIN-1 encoded bytes from a string into a buffer.
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_GetValueStringLatin1(
    JSVM_Env env, JSVM_Value value, char* buf, size_t bufsize, size_t* result);

// Copies UTF-8 encoded bytes from a string into a buffer.
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_GetValueStringUtf8(
    JSVM_Env env, JSVM_Value value, char* buf, size_t bufsize, size_t* result);

// Copies UTF-16 encoded bytes from a string into a buffer.
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_GetValueStringUtf16(JSVM_Env env,
                                                               JSVM_Value value,
                                                               char16_t* buf,
                                                               size_t bufsize,
                                                               size_t* result);

// Methods to coerce values
// These APIs may execute user scripts
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_CoerceToBool(JSVM_Env env,
                                                       JSVM_Value value,
                                                       JSVM_Value* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_CoerceToNumber(JSVM_Env env,
                                                         JSVM_Value value,
                                                         JSVM_Value* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_CoerceToObject(JSVM_Env env,
                                                         JSVM_Value value,
                                                         JSVM_Value* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_CoerceToString(JSVM_Env env,
                                                         JSVM_Value value,
                                                         JSVM_Value* result);

// Methods to work with Objects
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_GetPrototype(JSVM_Env env,
                                                      JSVM_Value object,
                                                      JSVM_Value* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_GetPropertyNames(JSVM_Env env,
                                                           JSVM_Value object,
                                                           JSVM_Value* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_SetProperty(JSVM_Env env,
                                                     JSVM_Value object,
                                                     JSVM_Value key,
                                                     JSVM_Value value);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_HasProperty(JSVM_Env env,
                                                     JSVM_Value object,
                                                     JSVM_Value key,
                                                     bool* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_GetProperty(JSVM_Env env,
                                                     JSVM_Value object,
                                                     JSVM_Value key,
                                                     JSVM_Value* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_DeleteProperty(JSVM_Env env,
                                                        JSVM_Value object,
                                                        JSVM_Value key,
                                                        bool* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_HasOwnProperty(JSVM_Env env,
                                                         JSVM_Value object,
                                                         JSVM_Value key,
                                                         bool* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_SetNamedProperty(JSVM_Env env,
                                                           JSVM_Value object,
                                                           const char* utf8name,
                                                           JSVM_Value value);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_HasNamedProperty(JSVM_Env env,
                                                           JSVM_Value object,
                                                           const char* utf8name,
                                                           bool* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_GetNamedProperty(JSVM_Env env,
                                                           JSVM_Value object,
                                                           const char* utf8name,
                                                           JSVM_Value* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_SetElement(JSVM_Env env,
                                                    JSVM_Value object,
                                                    uint32_t index,
                                                    JSVM_Value value);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_HasElement(JSVM_Env env,
                                                    JSVM_Value object,
                                                    uint32_t index,
                                                    bool* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_GetElement(JSVM_Env env,
                                                    JSVM_Value object,
                                                    uint32_t index,
                                                    JSVM_Value* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_DeleteElement(JSVM_Env env,
                                                       JSVM_Value object,
                                                       uint32_t index,
                                                       bool* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_DefineProperties(JSVM_Env env,
                       JSVM_Value object,
                       size_t propertyCount,
                       const JSVM_PropertyDescriptor* properties);

// Methods to work with Arrays
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_IsArray(JSVM_Env env,
                                                 JSVM_Value value,
                                                 bool* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_GetArrayLength(JSVM_Env env,
                                                         JSVM_Value value,
                                                         uint32_t* result);

// Methods to compare values
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_StrictEquals(JSVM_Env env,
                                                      JSVM_Value lhs,
                                                      JSVM_Value rhs,
                                                      bool* result);

// Methods to work with Functions
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_CallFunction(JSVM_Env env,
                                                      JSVM_Value recv,
                                                      JSVM_Value func,
                                                      size_t argc,
                                                      const JSVM_Value* argv,
                                                      JSVM_Value* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_NewInstance(JSVM_Env env,
                                                     JSVM_Value constructor,
                                                     size_t argc,
                                                     const JSVM_Value* argv,
                                                     JSVM_Value* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_Instanceof(JSVM_Env env,
                                                   JSVM_Value object,
                                                   JSVM_Value constructor,
                                                   bool* result);

// Methods to work with JSVM_Callbacks

// Gets all callback info in a single call. (Ugly, but faster.)
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_GetCbInfo(
    JSVM_Env env,               // [in] JSVM environment handle
    JSVM_CallbackInfo cbinfo,  // [in] Opaque callback-info handle
    size_t* argc,      // [in-out] Specifies the size of the provided argv array
                       // and receives the actual count of args.
    JSVM_Value* argv,  // [out] Array of values
    JSVM_Value* this_arg,  // [out] Receives the JS 'this' arg for the call
    void** data);          // [out] Receives the data pointer for the callback.

JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_GetNewTarget(
    JSVM_Env env, JSVM_CallbackInfo cbinfo, JSVM_Value* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_DefineClass(JSVM_Env env,
                  const char* utf8name,
                  size_t length,
                  JSVM_Callback constructor,
                  void* data,
                  size_t propertyCount,
                  const JSVM_PropertyDescriptor* properties,
                  JSVM_Value* result);

// Methods to work with external data objects
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_Wrap(JSVM_Env env,
                                             JSVM_Value jsObject,
                                             void* nativeObject,
                                             JSVM_Finalize finalizeCb,
                                             void* finalizeHint,
                                             JSVM_Ref* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_Unwrap(JSVM_Env env,
                                               JSVM_Value jsObject,
                                               void** result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_RemoveWrap(JSVM_Env env,
                                                    JSVM_Value jsObject,
                                                    void** result);
JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_CreateExternal(JSVM_Env env,
                     void* data,
                     JSVM_Finalize finalizeCb,
                     void* finalizeHint,
                     JSVM_Value* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_GetValueExternal(JSVM_Env env,
                                                           JSVM_Value value,
                                                           void** result);

// Methods to control object lifespan

// Set initialRefcount to 0 for a weak reference, >0 for a strong reference.
JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_CreateReference(JSVM_Env env,
                      JSVM_Value value,
                      uint32_t initialRefcount,
                      JSVM_Ref* result);

// Deletes a reference. The referenced value is released, and may
// be GC'd unless there are other references to it.
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_DeleteReference(JSVM_Env env,
                                                         JSVM_Ref ref);

// Increments the reference count, optionally returning the resulting count.
// After this call the  reference will be a strong reference because its
// refcount is >0, and the referenced object is effectively "pinned".
// Calling this when the refcount is 0 and the object is unavailable
// results in an error.
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_ReferenceRef(JSVM_Env env,
                                                      JSVM_Ref ref,
                                                      uint32_t* result);

// Decrements the reference count, optionally returning the resulting count.
// If the result is 0 the reference is now weak and the object may be GC'd
// at any time if there are no other references. Calling this when the
// refcount is already 0 results in an error.
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_ReferenceUnref(JSVM_Env env,
                                                        JSVM_Ref ref,
                                                        uint32_t* result);

// Attempts to get a referenced value. If the reference is weak,
// the value might no longer be available, in that case the call
// is still successful but the result is NULL.
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_GetReferenceValue(JSVM_Env env,
                                                            JSVM_Ref ref,
                                                            JSVM_Value* result);

JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_OpenHandleScope(JSVM_Env env, JSVM_HandleScope* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_CloseHandleScope(JSVM_Env env, JSVM_HandleScope scope);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_OpenEscapableHandleScope(
    JSVM_Env env, JSVM_EscapableHandleScope* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_CloseEscapableHandleScope(
    JSVM_Env env, JSVM_EscapableHandleScope scope);

JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_EscapeHandle(JSVM_Env env,
                   JSVM_EscapableHandleScope scope,
                   JSVM_Value escapee,
                   JSVM_Value* result);

// Methods to support error handling
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_Throw(JSVM_Env env, JSVM_Value error);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_ThrowError(JSVM_Env env,
                                                    const char* code,
                                                    const char* msg);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_ThrowTypeError(JSVM_Env env,
                                                         const char* code,
                                                         const char* msg);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_ThrowRangeError(JSVM_Env env,
                                                          const char* code,
                                                          const char* msg);
#if JSVM_VERSION >= 9
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_ThrowSyntaxError(JSVM_Env env,
                                                               const char* code,
                                                               const char* msg);
#endif  // JSVM_VERSION >= 9
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_IsError(JSVM_Env env,
                                                 JSVM_Value value,
                                                 bool* result);

// Methods to support catching exceptions
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_IsExceptionPending(JSVM_Env env,
                                                             bool* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_GetAndClearLastException(JSVM_Env env, JSVM_Value* result);

// Methods to work with array buffers and typed arrays
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_IsArraybuffer(JSVM_Env env,
                                                       JSVM_Value value,
                                                       bool* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_CreateArraybuffer(JSVM_Env env,
                                                           size_t byteLength,
                                                           void** data,
                                                           JSVM_Value* result);
#ifndef NODE_API_NO_EXTERNAL_BUFFERS_ALLOWED
JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_CreateExternalArraybuffer(JSVM_Env env,
                                 void* externalData,
                                 size_t byteLength,
                                 JSVM_Finalize finalizeCb,
                                 void* finalizeHint,
                                 JSVM_Value* result);
#endif  // NODE_API_NO_EXTERNAL_BUFFERS_ALLOWED
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_GetArraybufferInfo(
    JSVM_Env env, JSVM_Value arraybuffer, void** data, size_t* byte_length);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_IsTypedarray(JSVM_Env env,
                                                      JSVM_Value value,
                                                      bool* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_CreateTypedarray(JSVM_Env env,
                       JSVM_TypedarrayType type,
                       size_t length,
                       JSVM_Value arraybuffer,
                       size_t byteOffset,
                       JSVM_Value* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_GetTypedarrayInfo(JSVM_Env env,
                         JSVM_Value typedarray,
                         JSVM_TypedarrayType* type,
                         size_t* length,
                         void** data,
                         JSVM_Value* arraybuffer,
                         size_t* byteOffset);

JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_CreateDataview(JSVM_Env env,
                                                        size_t length,
                                                        JSVM_Value arraybuffer,
                                                        size_t byteOffset,
                                                        JSVM_Value* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_IsDataview(JSVM_Env env,
                                                    JSVM_Value value,
                                                    bool* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_GetDataviewInfo(JSVM_Env env,
                       JSVM_Value dataview,
                       size_t* byteLength,
                       void** data,
                       JSVM_Value* arraybuffer,
                       size_t* byteOffset);

// version management
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_GetVersion(JSVM_Env env,
                                                    uint32_t* result);

// Promises
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_CreatePromise(JSVM_Env env,
                                                       JSVM_Deferred* deferred,
                                                       JSVM_Value* promise);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_ResolveDeferred(JSVM_Env env,
                                                         JSVM_Deferred deferred,
                                                         JSVM_Value resolution);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_RejectDeferred(JSVM_Env env,
                                                        JSVM_Deferred deferred,
                                                        JSVM_Value rejection);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_IsPromise(JSVM_Env env,
                                                   JSVM_Value value,
                                                   bool* is_promise);

/*
// Running a script
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_RunScript(JSVM_Env env,
                                                   JSVM_Value script,
                                                   JSVM_Value* result);
*/

// Memory management
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_AdjustExternalMemory(
    JSVM_Env env, int64_t change_in_bytes, int64_t* adjustedValue);

#if JSVM_VERSION >= 5

// Dates
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_CreateDate(JSVM_Env env,
                                                    double time,
                                                    JSVM_Value* result);

JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_IsDate(JSVM_Env env,
                                                JSVM_Value value,
                                                bool* is_date);

JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_GetDateValue(JSVM_Env env,
                                                       JSVM_Value value,
                                                       double* result);

// Add finalizer for pointer
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_AddFinalizer(JSVM_Env env,
                                                      JSVM_Value jsObject,
                                                      void* finalize_data,
                                                      JSVM_Finalize finalizeCb,
                                                      void* finalizeHint,
                                                      JSVM_Ref* result);

#endif  // JSVM_VERSION >= 5

#ifdef JSVM_EXPERIMENTAL
#define NODE_API_EXPERIMENTAL_HAS_POST_FINALIZER

JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_PostFinalizer(JSVM_Env env,
                        JSVM_Finalize finalizeCb,
                        void* finalize_data,
                        void* finalizeHint);

#endif  // JSVM_EXPERIMENTAL

#if JSVM_VERSION >= 6

// BigInt
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_CreateBigintInt64(JSVM_Env env,
                                                            int64_t value,
                                                            JSVM_Value* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_CreateBigintUint64(JSVM_Env env, uint64_t value, JSVM_Value* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_CreateBigintWords(JSVM_Env env,
                         int signBit,
                         size_t wordCount,
                         const uint64_t* words,
                         JSVM_Value* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_GetValueBigintInt64(JSVM_Env env,
                                                               JSVM_Value value,
                                                               int64_t* result,
                                                               bool* lossless);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_GetValueBigintUint64(
    JSVM_Env env, JSVM_Value value, uint64_t* result, bool* lossless);
JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_GetValueBigintWords(JSVM_Env env,
                            JSVM_Value value,
                            int* signBit,
                            size_t* wordCount,
                            uint64_t* words);

// Object
JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_GetAllPropertyNames(JSVM_Env env,
                            JSVM_Value object,
                            JSVM_KeyCollectionMode keyMode,
                            JSVM_KeyFilter keyFilter,
                            JSVM_KeyConversion keyConversion,
                            JSVM_Value* result);

// Instance data
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_SetInstanceData(
    JSVM_Env env, void* data, JSVM_Finalize finalizeCb, void* finalizeHint);

JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_GetInstanceData(JSVM_Env env,
                                                          void** data);
#endif  // JSVM_VERSION >= 6

#if JSVM_VERSION >= 7
// ArrayBuffer detaching
JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_DetachArraybuffer(JSVM_Env env, JSVM_Value arraybuffer);

JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_IsDetachedArraybuffer(JSVM_Env env, JSVM_Value value, bool* result);
#endif  // JSVM_VERSION >= 7

#if JSVM_VERSION >= 8
// Type tagging
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_TypeTagObject(
    JSVM_Env env, JSVM_Value value, const JSVM_TypeTag* typeTag);

JSVM_EXTERN JSVM_Status JSVM_CDECL
OH_JSVM_CheckObjectTypeTag(JSVM_Env env,
                           JSVM_Value value,
                           const JSVM_TypeTag* typeTag,
                           bool* result);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_ObjectFreeze(JSVM_Env env,
                                                      JSVM_Value object);
JSVM_EXTERN JSVM_Status JSVM_CDECL OH_JSVM_ObjectSeal(JSVM_Env env,
                                                    JSVM_Value object);
#endif  // JSVM_VERSION >= 8

EXTERN_C_END

#endif  // _JSVM_API_H_
