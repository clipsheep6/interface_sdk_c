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
/**
 * @addtogroup JSVM
 * @{
 *
 * @brief Provides the standard JavaScript engine capabilities.
 *
 * Provides API to Provide independent, standard, and complete JavaScript engine capabilities for developers,
 * including managing the engine lifecycle, compiling and running JS code, implementing JS/C++ cross language calls,
 * and taking snapshots.
 *
 * @since 11
 */

/**
 * @file jsvm.h
 *
 * @brief Provides the JSVM API define.
 *
 * Provides API to Provide independent, standard, and complete JavaScript engine capabilities for developers,
 * including managing the engine lifecycle, compiling and running JS code, implementing JS/C++ cross language calls,
 * and taking snapshots.
 * @library libjsvm.so
 * @kit ArkTS
 * @syscap SystemCapability.ArkCompiler.JSVM
 * @since 11
 */


#ifndef ARK_RUNTIME_JSVM_JSVM_H
#define ARK_RUNTIME_JSVM_JSVM_H


// This file needs to be compatible with C compilers.
#include <stdbool.h>  // NOLINT(modernize-deprecated-headers)
#include <stddef.h>   // NOLINT(modernize-deprecated-headers)
#include "jsvm_types.h"

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

#ifndef JSVM_EXTERN
#ifdef _WIN32
/**
 * @brief externally visible.
 *
 * @since 11
 */
#define JSVM_EXTERN __declspec(dllexport)
#elif defined(__wasm__)
#define JSVM_EXTERN                                           \
    __attribute__((visibility("default")))                    \
    __attribute__((__import_module__("jsvm")))
#else
#define JSVM_EXTERN __attribute__((visibility("default")))
#endif
#endif

/**
 * @brief auto length.
 *
 * @since 11
 */
#define JSVM_AUTO_LENGTH SIZE_MAX

#ifdef __cplusplus
#define EXTERN_C_START extern "C" {
#define EXTERN_C_END }
#else
#define EXTERN_C_START
#define EXTERN_C_END
#endif

EXTERN_C_START

/**
 * @brief Init a JavaScript vm.
 *
 * @param  options The options for initialize the JavaScript VM.
 * @return Returns JSVM funtions result code.
 *         Returns {@link JSVM_OK } in all cases.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_Init(const JSVM_InitOptions* options);

/**
 * @brief This API create a new VM instance.
 *
 * @param options The options for create the VM instance.
 * @param result The new VM instance.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CreateVM(const JSVM_CreateVMOptions* options,
                                         JSVM_VM* result);

/**
 * @brief This function controls how Microtasks are invoked of the vm. If the method is not
 * called, the default microtask policy of vm is JSVM_MicrotaskPolicy::JSVM_MICROTASK_AUTO.
 *
 * @param vm The VM instance to set mircrotasks policy.
 * @param policy Policy for running microtasks.
 * @return Returns JSVM_OK if the API succeeded.
 * @since 18
 */
JSVM_EXTERN JSVM_Status OH_JSVM_SetMicrotaskPolicy(JSVM_VM vm,
                                                   JSVM_MicrotaskPolicy policy);

/**
 * @brief Destroys VM instance.
 *
 * @param vm The VM instance to be Destroyed.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_DestroyVM(JSVM_VM vm);

/**
 * @brief This API allocates a default JavaScript Proxy. It is the equivalent of
 * doing new Proxy(target, handler) in JavaScript.
 *
 * @param env The environment that the API is invoked under.
 * @param target A JSVM_Value representing the JavaScript Object which you want to proxy.
 * @param handler A JSVM_Value representing the JavaScript Object that defines which
 * operations will be intercepted and how to redefine intercepted operations.
 * @param result A JSVM_Value representing a JavaScript Proxy.
 * @return Returns JSVM functions result code.
 *         {@link JSVM_OK } if the API succeeded. \n
 *         {@link JSVM_INVALID_ARG } if the any of the input arguments is NULL. \n
 *         {@link JSVM_OBJECT_EXPECTED} if target or handler is not Javascript Object. \n
 *         {@link JSVM_PENDING_EXCEPTION} if an exception occurs. \n
 *
 * @since 18
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CreateProxy(JSVM_Env env,
                                            JSVM_Value target,
                                            JSVM_Value handler,
                                            JSVM_Value* result);

/**
 * @brief This API checks if the value passed in is a Proxy.
 *
 * @param env The environment that the API is invoked under.
 * @param value The JavaScript value to check.
 * @param isProxy Whether the given value is Proxy.
 * @return Returns JSVM functions result code.
 *         {@link JSVM_OK } if the API succeeded. \n
 *         {@link JSVM_INVALID_ARG } if the any of the input arguments is NULL. \n
 *
 * @since 18
 */
JSVM_EXTERN JSVM_Status OH_JSVM_IsProxy(JSVM_Env env,
                                        JSVM_Value value,
                                        bool* isProxy);

/**
 * @brief This API gets target from proxy.
 *
 * @param env The environment that the API is invoked under.
 * @param value JSVM_Value representing JavaScript Proxy whose target to return.
 * @param result Target of the given proxy.
 * @return Returns JSVM functions result code.
 *         {@link JSVM_OK } if the API succeeded. \n
 *         {@link JSVM_INVALID_ARG } if the any of the input arguments is NULL. \n
 *         {@link JSVM_INVALID_TYPE} if value is not a Javascript Proxy. \n
 *
 * @since 18
 */
JSVM_EXTERN JSVM_Status OH_JSVM_ProxyGetTarget(JSVM_Env env,
                                               JSVM_Value value,
                                               JSVM_Value* result);

/**
 * @brief This API open a new VM scope for the VM instance.
 *
 * @param vm The VM instance to open scope for.
 * @param result The new VM scope.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_OpenVMScope(JSVM_VM vm,
                                            JSVM_VMScope* result);

/**
 * @brief This function close the VM scope for the VM instance.
 *
 * @param vm The VM instance to close scope for.
 * @param scope The VM scope to be closed.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CloseVMScope(JSVM_VM vm,
                                             JSVM_VMScope scope);

/**
 * @brief This function create a new environment with optional properties for the context of the new environment.
 *
 * @param vm The VM instance that the env will be created in.
 * @param propertyCount The number of elements in the properties array.
 * @param properties The array of property descriptor.
 * @param result The new environment created.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CreateEnv(JSVM_VM vm,
                                          size_t propertyCount,
                                          const JSVM_PropertyDescriptor* properties,
                                          JSVM_Env* result);

/**
 * @brief This function create a new environment from the start snapshot of the vm.
 *
 * @param vm The VM instance that the env will be created in.
 * @param index The index of the environment in the snapshot.
 * @param result The new environment created.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CreateEnvFromSnapshot(JSVM_VM vm,
                                                      size_t index,
                                                      JSVM_Env* result);

/**
 * @brief This function destroys the environment.
 *
 * @param env The environment to be destroyed.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_DestroyEnv(JSVM_Env env);

/**
 * @brief This function open a new environment scope.
 *
 * @param env The environment that the JSVM-API call is invoked under.
 * @param result The new environment scope.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_OpenEnvScope(JSVM_Env env,
                                             JSVM_EnvScope* result);

/**
 * @brief This function closes the environment scope of the environment.
 *
 * @param env The environment that the JSVM-API call is invoked under.
 * @param scope The environment scope to be closed.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CloseEnvScope(JSVM_Env env,
                                              JSVM_EnvScope scope);

/**
 * @brief This function retrieves the VM instance of the given environment.
 *
 * @param env The environment that the JSVM-API call is invoked under.
 * @param result The VM instance of the environment.
 * @return Returns JSVM funtions result code.
 *         Returns {@link JSVM_OK } in all cases.\n
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetVM(JSVM_Env env,
                                      JSVM_VM* result);

/**
 * @brief This function compiles a string of JavaScript code and returns the compiled script.
 *
 * @param env The environment that the JSVM-API call is invoked under.
 * @param script A JavaScript string containing the script yo be compiled.
 * @param cachedData Optional code cache data for the script.
 * @param cacheDataLength The length of cachedData array.
 * @param eagerCompile Whether to compile the script eagerly.
 * @param cacheRejected Whether the code cache rejected by compilation.
 * @param result The compiled script.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CompileScript(JSVM_Env env,
                                              JSVM_Value script,
                                              const uint8_t* cachedData,
                                              size_t cacheDataLength,
                                              bool eagerCompile,
                                              bool* cacheRejected,
                                              JSVM_Script* result);

/**
 * @brief This function compiles a string of JavaScript code with the source code information
 * and returns the compiled script.
 *
 * @param env The environment that the JSVM-API call is invoked under.
 * @param script A JavaScript string containing the script to be compiled.
 * @param cachedData Optional code cache data for the script.
 * @param cacheDataLength The length of cachedData array.
 * @param eagerCompile Whether to compile the script eagerly.
 * @param cacheRejected Whether the code cache rejected by compilation.
 * @param origin The information of source code.
 * @param result The compiled script.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CompileScriptWithOrigin(JSVM_Env env,
                                                        JSVM_Value script,
                                                        const uint8_t* cachedData,
                                                        size_t cacheDataLength,
                                                        bool eagerCompile,
                                                        bool* cacheRejected,
                                                        JSVM_ScriptOrigin* origin,
                                                        JSVM_Script* result);

/**
 * @brief This function creates code cache for the compiled script.
 *
 * @param env The environment that the JSVM-API call is invoked under.
 * @param script A compiled script to create code cache for.
 * @param data The data of the code cache.
 * @param length The length of the code cache data.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CreateCodeCache(JSVM_Env env,
                                                JSVM_Script script,
                                                const uint8_t** data,
                                                size_t* length);

/**
 * @brief This function executes a string of JavaScript code and returns its result with the following caveats:
 * Unlike eval, this function does not allow the script to access the current lexical scope, and therefore also
 * does not allow to access the module scope, meaning that pseudo-globals such as require will not be available.
 * The script can access the global scope. Function and var declarations in the script will be added to the
 * global object. Variable declarations made using let and const will be visible globally, but will not be added
 * to the global object.The value of this is global within the script.
 *
 * @param  env The environment that the API is invoked under.
 * @param  script A JavaScript string containing the script to execute.
 * @param  result The value resulting from having executed the script.
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_RunScript(JSVM_Env env,
                                          JSVM_Script script,
                                          JSVM_Value* result);

/**
 * @brief This API associates data with the currently running JSVM environment. data can later be retrieved
 * using OH_JSVM_GetInstanceData().
 *
 * @param env The environment that the JSVM-API call is invoked under.
 * @param data The data item to make available to bindings of this instance.
 * @param finalizeCb The function to call when the environment is being torn down. The function receives
 * data so that it might free it. JSVM_Finalize provides more details.
 * @param finalizeHint Optional hint to pass to the finalize callback during collection.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_SetInstanceData(JSVM_Env env,
                                                void* data,
                                                JSVM_Finalize finalizeCb,
                                                void* finalizeHint);

/**
 * @brief This API retrieves data that was previously associated with the currently running JSVM environment
 * via OH_JSVM_SetInstanceData(). If no data is set, the call will succeed and data will be set to NULL.
 *
 * @param env The environment that the JSVM-API call is invoked under.
 * @param data The data item that was previously associated with the currently running JSVM environment by
 * a call to OH_JSVM_SetInstanceData().
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetInstanceData(JSVM_Env env,
                                                void** data);

/**
 * @brief This API retrieves a JSVM_ExtendedErrorInfo structure with information about the last error that
 * occurred.
 *
 * @param env The environment that the JSVM-API call is invoked under.
 * @param result The JSVM_ExtendedErrorInfo structure with more information about the error.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetLastErrorInfo(JSVM_Env env,
                                                 const JSVM_ExtendedErrorInfo** result);

/**
 * @brief This API throws the JavaScript value provided.
 *
 * @param env The environment that the API is invoked under.
 * @param error The JavaScript value to be thrown.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_Throw(JSVM_Env env,
                                      JSVM_Value error);

/**
 * @brief This API throws a JavaScript Error with the text provided.
 *
 * @param env The environment that the API is invoked under.
 * @param code Optional error code to be set on the error.
 * @param msg C string representing the text to be associated with the error.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_ThrowError(JSVM_Env env,
                                           const char* code,
                                           const char* msg);

/**
 * @brief This API throws a JavaScript TypeError with the text provided.
 *
 * @param env The environment that the API is invoked under.
 * @param code Optional error code to be set on the error.
 * @param msg C string representing the text to be associated with the error.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_ThrowTypeError(JSVM_Env env,
                                               const char* code,
                                               const char* msg);

/**
 * @brief This API throws a JavaScript RangeError with the text provided.
 *
 * @param env The environment that the API is invoked under.
 * @param code Optional error code to be set on the error.
 * @param msg C string representing the text to be associated with the error.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_ThrowRangeError(JSVM_Env env,
                                                const char* code,
                                                const char* msg);

/**
 * @brief This API throws a JavaScript SyntaxError with the text provided.
 *
 * @param env The environment that the API is invoked under.
 * @param code Optional error code to be set on the error.
 * @param msg C string representing the text to be associated with the error.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_ThrowSyntaxError(JSVM_Env env,
                                                 const char* code,
                                                 const char* msg);

/**
 * @brief This API queries a JSVM_Value to check if it represents an error object.
 *
 * @param env The environment that the API is invoked under.
 * @param value The JSVM_Value to be checked.
 * @param result Boolean value that is set to true if JSVM_Value represents an error,
 * false otherwise.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_IsError(JSVM_Env env,
                                        JSVM_Value value,
                                        bool* result);

/**
 * @brief This API returns a JavaScript Error with the text provided.
 *
 * @param env The environment that the API is invoked under.
 * @param code Optional JSVM_Value with the string for the error code to be associated with the error.
 * @param msg JSVM_Value that references a JavaScript string to be used as the message for the Error.
 * @param result JSVM_Value representing the error created.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CreateError(JSVM_Env env,
                                            JSVM_Value code,
                                            JSVM_Value msg,
                                            JSVM_Value* result);

/**
 * @brief This API returns a JavaScript TypeError with the text provided.
 *
 * @param env The environment that the API is invoked under.
 * @param code Optional JSVM_Value with the string for the error code to be associated with the error.
 * @param msg JSVM_Value that references a JavaScript string to be used as the message for the Error.
 * @param result JSVM_Value representing the error created.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CreateTypeError(JSVM_Env env,
                                                JSVM_Value code,
                                                JSVM_Value msg,
                                                JSVM_Value* result);

/**
 * @brief This API returns a JavaScript RangeError with the text provided.
 *
 * @param env The environment that the API is invoked under.
 * @param code Optional JSVM_Value with the string for the error code to be associated with the error.
 * @param msg JSVM_Value that references a JavaScript string to be used as the message for the Error.
 * @param result JSVM_Value representing the error created.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CreateRangeError(JSVM_Env env,
                                                 JSVM_Value code,
                                                 JSVM_Value msg,
                                                 JSVM_Value* result);

/**
 * @brief This API returns a JavaScript SyntaxError with the text provided.
 *
 * @param env The environment that the API is invoked under.
 * @param code Optional JSVM_Value with the string for the error code to be associated with the error.
 * @param msg JSVM_Value that references a JavaScript string to be used as the message for the Error.
 * @param result JSVM_Value representing the error created.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CreateSyntaxError(JSVM_Env env,
                                                  JSVM_Value code,
                                                  JSVM_Value msg,
                                                  JSVM_Value* result);

/**
 * @brief This API returns a JavaScript exception if one is pending, NULL otherwise.
 *
 * @param env The environment that the API is invoked under.
 * @param result The exception if one is pending, NULL otherwise.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetAndClearLastException(JSVM_Env env,
                                                         JSVM_Value* result);

/**
 * @brief This API returns true if an exception is pending, false otherwise.
 *
 * @param env The environment that the API is invoked under.
 * @param result Boolean value that is set to true if an exception is pending.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_IsExceptionPending(JSVM_Env env,
                                                   bool* result);

/**
 * @brief This API opens a new scope.
 *
 * @param env The environment that the API is invoked under.
 * @param result JSVM_Value representing the new scope.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_OpenHandleScope(JSVM_Env env,
                                                JSVM_HandleScope* result);

/**
 * @brief This API closes the scope passed in. Scopes must be closed in the reverse
 * order from which they were created.
 *
 * @param env The environment that the API is invoked under.
 * @param scope JSVM_Value representing the scope to be closed.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CloseHandleScope(JSVM_Env env,
                                                 JSVM_HandleScope scope);

/**
 * @brief This API opens a new scope from which one object can be promoted to the outer scope.
 *
 * @param env The environment that the API is invoked under.
 * @param result JSVM_Value representing the new scope.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_OpenEscapableHandleScope(JSVM_Env env,
                                                         JSVM_EscapableHandleScope* result);

/**
 * @brief This API closes the scope passed in. Scopes must be closed in the reverse order
 * from which they were created.
 *
 * @param env The environment that the API is invoked under.
 * @param scope JSVM_Value representing the scope to be closed.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CloseEscapableHandleScope(JSVM_Env env,
                                                          JSVM_EscapableHandleScope scope);

/**
 * @brief This API promotes the handle to the JavaScript object so that it is valid for the lifetime
 * of the outer scope. It can only be called once per scope. If it is called more than once an error
 * will be returned.
 *
 * @param env The environment that the API is invoked under.
 * @param scope JSVM_Value representing the current scope.
 * @param escapee JSVM_Value representing the JavaScript Object to be escaped.
 * @param result JSVM_Value representing the handle to the escaped Object in the outer scope.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_EscapeHandle(JSVM_Env env,
                                             JSVM_EscapableHandleScope scope,
                                             JSVM_Value escapee,
                                             JSVM_Value* result);

/**
 * @brief This API creates a new reference with the specified reference count to the value passed in.
 *
 * @param env The environment that the API is invoked under.
 * @param value The JSVM_Value for which a reference is being created.
 * @param initialRefcount Initial reference count for the new reference.
 * @param result JSVM_Ref pointing to the new reference.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CreateReference(JSVM_Env env,
                                                JSVM_Value value,
                                                uint32_t initialRefcount,
                                                JSVM_Ref* result);

/**
 * @brief his API deletes the reference passed in.
 *
 * @param env The environment that the API is invoked under.
 * @param ref JSVM_Ref to be deleted.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_DeleteReference(JSVM_Env env,
                                                JSVM_Ref ref);

/**
 * @brief his API increments the reference count for the reference passed in and
 * returns the resulting reference count.
 *
 * @param env The environment that the API is invoked under.
 * @param ref JSVM_Ref for which the reference count will be incremented.
 * @param result The new reference count.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_ReferenceRef(JSVM_Env env,
                                             JSVM_Ref ref,
                                             uint32_t* result);

/**
 * @brief This API decrements the reference count for the reference passed in and
 * returns the resulting reference count.
 *
 * @param env The environment that the API is invoked under.
 * @param ref JSVM_Ref for which the reference count will be decremented.
 * @param result The new reference count.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_ReferenceUnref(JSVM_Env env,
                                               JSVM_Ref ref,
                                               uint32_t* result);

/**
 * @brief If still valid, this API returns the JSVM_Value representing the
 * JavaScript value associated with the JSVM_Ref. Otherwise, result will be NULL.
 *
 * @param env The environment that the API is invoked under.
 * @param ref The JSVM_Ref for which the corresponding value is being requested.
 * @param result The JSVM_Value referenced by the JSVM_Ref.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetReferenceValue(JSVM_Env env,
                                                  JSVM_Ref ref,
                                                  JSVM_Value* result);

/**
 * @brief This API returns a JSVM-API value corresponding to a JavaScript Array type.
 *
 * @param env The environment that the API is invoked under.
 * @param result A JSVM_Value representing a JavaScript Array.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CreateArray(JSVM_Env env,
                                            JSVM_Value* result);


/**
 * @brief This API returns a JSVM-API value corresponding to a JavaScript Array type. The Array's length property
 * is set to the passed-in length parameter. However, the underlying buffer is not guaranteed to be pre-allocated
 * by the VM when the array is created. That behavior is left to the underlying VM implementation.
 *
 * @param env The environment that the API is invoked under.
 * @param length The initial length of the Array.
 * @param result A JSVM_Value representing a JavaScript Array.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CreateArrayWithLength(JSVM_Env env,
                                                      size_t length,
                                                      JSVM_Value* result);

/**
 * @brief This API returns a JSVM-API value corresponding to a JavaScript ArrayBuffer. ArrayBuffers are used to
 * represent fixed-length binary data buffers. They are normally used as a backing-buffer for TypedArray objects.
 * The ArrayBuffer allocated will have an underlying byte buffer whose size is determined by the length parameter
 * that's passed in. The underlying buffer is optionally returned back to the caller in case the caller wants to
 * directly manipulate the buffer. This buffer can only be written to directly from native code. To write to this
 * buffer from JavaScript, a typed array or DataView object would need to be created.
 *
 * @param env The environment that the API is invoked under.
 * @param byteLength The length in bytes of the array buffer to create.
 * @param data Pointer to the underlying byte buffer of the ArrayBuffer.data can optionally be ignored by passing NULL.
 * @param result A JSVM_Value representing a JavaScript Array.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CreateArraybuffer(JSVM_Env env,
                                                  size_t byteLength,
                                                  void** data,
                                                  JSVM_Value* result);

/**
 * @brief This API allocate the memory of array buffer backing store.
 *
 * @param byteLength size of backing store memory.
 * @param initialized initialization status of the backing store memory.
 * @param data pointer that recieve the backing store memory pointer.
 * @return Returns JSVM funtions result code.
 *         Returns {@link JSVM_OK } if allocation succeed.\n
 *         Returns {@link JSVM_INVALID_ARG } if data is null pointer.\n
 *         Returns {@link JSVM_GENERIC_FAILURE } if allocation failed.\n
 * @since 12
 */
JSVM_Status JSVM_CDECL OH_JSVM_AllocateArrayBufferBackingStoreData(size_t byteLength,
                                                                   JSVM_InitializedFlag initialized,
                                                                   void **data);

/**
 * @brief This API release the memory of an array buffer backing store.
 *
 * @param data pointer to the backing store memory.
 * @return Returns JSVM funtions result code.
 *         Returns {@link JSVM_OK } if run succeed.\n
 *         Returns {@link JSVM_INVALID_ARG } if data is null pointer.\n
 * @since 12
 */
JSVM_Status JSVM_CDECL OH_JSVM_FreeArrayBufferBackingStoreData(void *data);

/**
 * @brief This API create an array buffer using the backing store data.
 *
 * @param env The environment that the API is invoked under.
 * @param data pointer to the backing store memory.
 * @param backingStoreSize size of backing store memory.
 * @param offset start position of the array buffer in the backing store memory.
 * @param arrayBufferSize size of the array buffer.
 * @param result pointer that recieve the array buffer.
 * @return Returns JSVM funtions result code.
 *         Returns {@link JSVM_OK } if creation succeed.\n
 *         Returns {@link JSVM_INVALID_ARG } if any of the following condition reached:\n
 *         1. offset + arrayBufferSize > backingStoreSize\n
 *         2. backingStoreSize or arrayBufferSize equals zero
 *         3. data or result is null pointer
 * @since 12
 */
JSVM_Status JSVM_CDECL OH_JSVM_CreateArrayBufferFromBackingStoreData(JSVM_Env env,
                                                                     void *data,
                                                                     size_t backingStoreSize,
                                                                     size_t offset,
                                                                     size_t arrayBufferSize,
                                                                     JSVM_Value *result);

/**
 * @brief This API does not observe leap seconds; they are ignored, as ECMAScript aligns with POSIX time specification.
 * This API allocates a JavaScript Date object.
 *
 * @param env The environment that the API is invoked under.
 * @param time ECMAScript time value in milliseconds since 01 January, 1970 UTC.
 * @param result A JSVM_Value representing a JavaScript Date.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CreateDate(JSVM_Env env,
                                           double time,
                                           JSVM_Value* result);

/**
 * @brief This API allocates a JavaScript value with external data attached to it. This is used to pass external
 * data through JavaScript code, so it can be retrieved later by native code using OH_JSVM_GetValueExternal.
 * The API adds a JSVM_Finalize callback which will be called when the JavaScript object just created has been garbage
 * collected.The created value is not an object, and therefore does not support additional properties. It is considered
 * a distinct value type calling OH_JSVM_Typeof() with an external value yields JSVM_EXTERNAL.
 *
 * @param env The environment that the API is invoked under.
 * @param data Raw pointer to the external data.
 * @param finalizeCb Optional callback to call when the external value is being collected. JSVM_Finalize provides
 * more details.
 * @param finalizeHint Optional hint to pass to the finalize callback during collection.
 * @param result A JSVM_Value representing an external value.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CreateExternal(JSVM_Env env,
                                               void* data,
                                               JSVM_Finalize finalizeCb,
                                               void* finalizeHint,
                                               JSVM_Value* result);

/**
 * @brief This API allocates a default JavaScript Object. It is the equivalent of doing new Object() in JavaScript.
 *
 * @param env The environment that the API is invoked under.
 * @param result  A JSVM_Value representing a JavaScript Object.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CreateObject(JSVM_Env env,
                                             JSVM_Value* result);

/**
 * @brief This API creates a JavaScript symbol value from a UTF8-encoded C string.
 *
 * @param env The environment that the API is invoked under.
 * @param description Optional JSVM_Value which refers to a JavaScript string to be set as the description
 * for the symbol.
 * @param result A JSVM_Value representing a JavaScript symbol.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CreateSymbol(JSVM_Env env,
                                             JSVM_Value description,
                                             JSVM_Value* result);

/**
 * @brief This API searches in the global registry for an existing symbol with the given description.
 * If the symbol already exists it will be returned, otherwise a new symbol will be created in the registry.
 *
 * @param env The environment that the API is invoked under.
 * @param utf8description UTF-8 C string representing the text to be used as the description for the symbol.
 * @param length The length of the description string in bytes, or JSVM_AUTO_LENGTH if it is null-terminated.
 * @param result A JSVM_Value representing a JavaScript symbol.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_SymbolFor(JSVM_Env env,
                                          const char* utf8description,
                                          size_t length,
                                          JSVM_Value* result);

/**
 * @brief This API creates a JavaScript TypedArray object over an existing ArrayBuffer. TypedArray
 * objects provide an array-like view over an underlying data buffer where each element has the
 * same underlying binary scalar datatype.It's required that (length * size_of_element) + byte_offset should
 * be <= the size in bytes of the array passed in. If not, a RangeError exception is raised.
 *
 * @param env The environment that the API is invoked under.
 * @param type Scalar datatype of the elements within the TypedArray.
 * @param length Number of elements in the TypedArray.
 * @param arraybuffer ArrayBuffer underlying the typed array.
 * @param byteOffset The byte offset within the ArrayBuffer from which to start projecting the TypedArray.
 * @param result A JSVM_Value representing a JavaScript TypedArray
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CreateTypedarray(JSVM_Env env,
                                                 JSVM_TypedarrayType type,
                                                 size_t length,
                                                 JSVM_Value arraybuffer,
                                                 size_t byteOffset,
                                                 JSVM_Value* result);

/**
 * @brief This API creates a JavaScript DataView object over an existing ArrayBuffer. DataView
 * objects provide an array-like view over an underlying data buffer, but one which allows items
 * of different size and type in the ArrayBuffer.It is required that byte_length + byte_offset is
 * less than or equal to the size in bytes of the array passed in. If not, a RangeError exception
 * is raised.
 *
 * @param env The environment that the API is invoked under.
 * @param length Number of elements in the DataView.
 * @param arraybuffer ArrayBuffer underlying the DataView.
 * @param byteOffset The byte offset within the ArrayBuffer from which to start projecting the DataView.
 * @param result A JSVM_Value representing a JavaScript DataView.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CreateDataview(JSVM_Env env,
                                               size_t length,
                                               JSVM_Value arraybuffer,
                                               size_t byteOffset,
                                               JSVM_Value* result);

/**
 * @brief This API is used to convert from the C int32_t type to the JavaScript number type.
 *
 * @param env The environment that the API is invoked under.
 * @param value Integer value to be represented in JavaScript.
 * @param result A JSVM_Value representing a JavaScript number.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CreateInt32(JSVM_Env env,
                                            int32_t value,
                                            JSVM_Value* result);

/**
 * @brief This API is used to convert from the C uint32_t type to the JavaScript number type.
 *
 * @param env The environment that the API is invoked under.
 * @param value Unsigned integer value to be represented in JavaScript.
 * @param result A JSVM_Value representing a JavaScript number.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CreateUint32(JSVM_Env env,
                                             uint32_t value,
                                             JSVM_Value* result);

/**
 * @brief This API is used to convert from the C int64_t type to the JavaScript number type.
 *
 * @param env The environment that the API is invoked under.
 * @param value Integer value to be represented in JavaScript.
 * @param result A JSVM_Value representing a JavaScript number.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CreateInt64(JSVM_Env env,
                                            int64_t value,
                                            JSVM_Value* result);

/**
 * @brief This API is used to convert from the C double type to the JavaScript number type.
 *
 * @param env The environment that the API is invoked under.
 * @param value Double-precision value to be represented in JavaScript.
 * @param result A JSVM_Value representing a JavaScript number.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CreateDouble(JSVM_Env env,
                                             double value,
                                             JSVM_Value* result);

/**
 * @brief This API converts the C int64_t type to the JavaScript BigInt type.
 *
 * @param env The environment that the API is invoked under.
 * @param value Integer value to be represented in JavaScript.
 * @param result A JSVM_Value representing a JavaScript BigInt.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CreateBigintInt64(JSVM_Env env,
                                                  int64_t value,
                                                  JSVM_Value* result);

/**
 * @brief This API converts the C uint64_t type to the JavaScript BigInt type.
 *
 * @param env The environment that the API is invoked under.
 * @param value Unsigned integer value to be represented in JavaScript.
 * @param result A JSVM_Value representing a JavaScript BigInt.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CreateBigintUint64(JSVM_Env env,
                                                   uint64_t value,
                                                   JSVM_Value* result);

/**
 * @brief This API converts an array of unsigned 64-bit words into a single BigInt value.
 * The resulting BigInt is calculated as (–1)sign_bit (words[0] × (264)0 + words[1] × (264)1 + …)
 *
 * @param env The environment that the API is invoked under.
 * @param signBit Determines if the resulting BigInt will be positive or negative.
 * @param wordCount The length of the words array.
 * @param words An array of uint64_t little-endian 64-bit words.
 * @param result A JSVM_Value representing a JavaScript BigInt.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CreateBigintWords(JSVM_Env env,
                                                  int signBit,
                                                  size_t wordCount,
                                                  const uint64_t* words,
                                                  JSVM_Value* result);

/**
 * @brief This API creates a JavaScript string value from an ISO-8859-1-encoded C
 * string. The native string is copied.
 *
 * @param env The environment that the API is invoked under.
 * @param str Character buffer representing an ISO-8859-1-encoded string.
 * @param length The length of the string in bytes, or JSVM_AUTO_LENGTH if it is null-terminated.
 * @param result A JSVM_Value representing a JavaScript string.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CreateStringLatin1(JSVM_Env env,
                                                   const char* str,
                                                   size_t length,
                                                   JSVM_Value* result);

/**
 * @brief This API creates a JavaScript string value from a UTF16-LE-encoded C
 * string. The native string is copied.
 *
 * @param env The environment that the API is invoked under.
 * @param str Character buffer representing a UTF16-LE-encoded string.
 * @param length The length of the string in two-byte code units, or JSVM_AUTO_LENGTH
 * if it is null-terminated.
 * @param result A JSVM_Value representing a JavaScript string.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CreateStringUtf16(JSVM_Env env,
                                                  const char16_t* str,
                                                  size_t length,
                                                  JSVM_Value* result);

/**
 * @brief This API creates a JavaScript string value from a UTF8-encoded C
 * string. The native string is copied.
 *
 * @param env The environment that the API is invoked under.
 * @param str Character buffer representing a UTF8-encoded string.
 * @param length The length of the string in bytes, or JSVM_AUTO_LENGTH if it is null-terminated.
 * @param result A JSVM_Value representing a JavaScript string.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CreateStringUtf8(JSVM_Env env,
                                                 const char* str,
                                                 size_t length,
                                                 JSVM_Value* result);

/**
 * @brief This API returns the length of an array.
 *
 * @param env The environment that the API is invoked under.
 * @param value JSVM_Value representing the JavaScript Array whose length is being queried.
 * @param result uint32 representing length of the array.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetArrayLength(JSVM_Env env,
                                               JSVM_Value value,
                                               uint32_t* result);

/**
 * @brief This API is used to retrieve the underlying data buffer of an ArrayBuffer and its length.
 *
 * @param env The environment that the API is invoked under.
 * @param arraybuffer JSVM_Value representing the ArrayBuffer being queried.
 * @param data The underlying data buffer of the ArrayBuffer. If byte_length is 0, this may be NULL
 * or any other pointer value.
 * @param byteLength Length in bytes of the underlying data buffer.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetArraybufferInfo(JSVM_Env env,
                                                   JSVM_Value arraybuffer,
                                                   void** data,
                                                   size_t* byteLength);

/**
 * @brief This API returns the length of an array.
 *
 * @param env The environment that the API is invoked under.
 * @param object JSVM_Value representing JavaScript Object whose prototype to return. This returns
 * the equivalent of Object.getPrototypeOf (which is not the same as the function's prototype property).
 * @param result JSVM_Value representing prototype of the given object.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetPrototype(JSVM_Env env,
                                             JSVM_Value object,
                                             JSVM_Value* result);

/**
 * @brief This API returns various properties of a typed array.
 *
 * @param env The environment that the API is invoked under.
 * @param typedarray JSVM_Value representing the TypedArray whose properties to query.
 * @param type Scalar datatype of the elements within the TypedArray.
 * @param length The number of elements in the TypedArray.
 * @param data The data buffer underlying the TypedArray adjusted by the byte_offset value so that it
 * points to the first element in the TypedArray. If the length of the array is 0, this may be NULL or
 * any other pointer value.
 * @param arraybuffer The ArrayBuffer underlying the TypedArray.
 * @param byteOffset The byte offset within the underlying native array at which the first element of
 * the arrays is located. The value for the data parameter has already been adjusted so that data points
 * to the first element in the array. Therefore, the first byte of the native array would be at data - byte_offset.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetTypedarrayInfo(JSVM_Env env,
                                                  JSVM_Value typedarray,
                                                  JSVM_TypedarrayType* type,
                                                  size_t* length,
                                                  void** data,
                                                  JSVM_Value* arraybuffer,
                                                  size_t* byteOffset);

/**
 * @brief Any of the out parameters may be NULL if that property is unneeded.
 * This API returns various properties of a DataView.
 *
 * @param env The environment that the API is invoked under.
 * @param dataview JSVM_Value representing the DataView whose properties to query.
 * @param bytelength Number of bytes in the DataView.
 * @param data The data buffer underlying the DataView.
 * If byte_length is 0, this may be NULL or any other pointer value.
 * @param arraybuffer ArrayBuffer underlying the DataView.
 * @param byteOffset The byte offset within the data buffer from which to start projecting the DataView.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetDataviewInfo(JSVM_Env env,
                                                JSVM_Value dataview,
                                                size_t* bytelength,
                                                void** data,
                                                JSVM_Value* arraybuffer,
                                                size_t* byteOffset);

/**
 * @brief Returns JSVM_OK if the function executed successfully. If a non-date JSVM_Value is
 * passed in it returns JSVM_date_expected.This API returns the C double
 * primitive of time value for the given JavaScript Date.
 *
 * @param env The environment that the API is invoked under.
 * @param value JSVM_Value representing a JavaScript Date.
 * @param result Time value as a double represented as milliseconds
 * since midnight at the beginning of 01 January, 1970 UTC.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 *         {@link JSVM_DATE_EXPECTED } If a non-date JSVM_Value is passed in it.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetDateValue(JSVM_Env env,
                                             JSVM_Value value,
                                             double* result);

/**
 * @brief This API returns the C boolean primitive equivalent of the given JavaScript Boolean.
 *
 * @param env The environment that the API is invoked under.
 * @param value JSVM_Value representing JavaScript Boolean.
 * @param result C boolean primitive equivalent of the given JavaScript Boolean.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 *         {@link JSVM_BOOLEAN_EXPECTED }If a non-boolean JSVM_Value is passed in it.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetValueBool(JSVM_Env env,
                                             JSVM_Value value,
                                             bool* result);

/**
 * @brief This API returns the C double primitive equivalent of the given JavaScript number.
 *
 * @param env The environment that the API is invoked under.
 * @param value JSVM_Value representing JavaScript number.
 * @param result C double primitive equivalent of the given JavaScript number.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 *         {@link JSVM_NUMBER_EXPECTED } If a non-number JSVM_Value is passed in.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetValueDouble(JSVM_Env env,
                                               JSVM_Value value,
                                               double* result);

/**
 * @brief This API returns the C int64_t primitive equivalent of the given JavaScript BigInt.
 * If needed it will truncate the value, setting lossless to false.
 *
 * @param env The environment that the API is invoked under.
 * @param value JSVM_Value representing JavaScript BigInt.
 * @param result C int64_t primitive equivalent of the given JavaScript BigInt.
 * @param lossless Indicates whether the BigInt value was converted losslessly.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 *         {@link JSVM_BIGINT_EXPECTED } If a non-BigInt is passed in it.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetValueBigintInt64(JSVM_Env env,
                                                    JSVM_Value value,
                                                    int64_t* result,
                                                    bool* lossless);

/**
 * @brief This API returns the C uint64_t primitive equivalent of the given JavaScript BigInt.
 * If needed it will truncate the value, setting lossless to false.
 *
 * @param env The environment that the API is invoked under.
 * @param value JSVM_Value representing JavaScript BigInt.
 * @param result C uint64_t primitive equivalent of the given JavaScript BigInt.
 * @param lossless Indicates whether the BigInt value was converted losslessly.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 *         {@link JSVM_BIGINT_EXPECTED } If a non-BigInt is passed in it.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetValueBigintUint64(JSVM_Env env,
                                                     JSVM_Value value,
                                                     uint64_t* result,
                                                     bool* lossless);

/**
 * @brief This API converts a single BigInt value into a sign bit, 64-bit little-endian array, and the number
 * of elements in the array. signBit and words may be both set to NULL, in order to get only wordCount.
 *
 * @param env The environment that the API is invoked under.
 * @param value JSVM_Value representing JavaScript BigInt.
 * @param signBit Integer representing if the JavaScript BigInt is positive or negative.
 * @param wordCount Must be initialized to the length of the words array. Upon return, it will be set to
 * the actual number of words that would be needed to store this BigInt.
 * @param words Pointer to a pre-allocated 64-bit word array.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetValueBigintWords(JSVM_Env env,
                                                    JSVM_Value value,
                                                    int* signBit,
                                                    size_t* wordCount,
                                                    uint64_t* words);

/**
 * @brief This API retrieves the external data pointer that was previously passed to OH_JSVM_CreateExternal().
 *
 * @param env The environment that the API is invoked under.
 * @param value JSVM_Value representing JavaScript external value.
 * @param result Pointer to the data wrapped by the JavaScript external value.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 *         {@link JSVM_INVALID_ARG } If a non-external JSVM_Value is passed in it.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetValueExternal(JSVM_Env env,
                                                 JSVM_Value value,
                                                 void** result);

/**
 * @brief This API returns the C int32 primitive equivalent of the given JavaScript number.
 *
 * @param env The environment that the API is invoked under.
 * @param value JSVM_Value representing JavaScript number.
 * @param result C int32 primitive equivalent of the given JavaScript number.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 *         {@link JSVM_NUMBER_EXPECTED } If a non-number JSVM_Value is passed in.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetValueInt32(JSVM_Env env,
                                              JSVM_Value value,
                                              int32_t* result);

/**
 * @brief This API returns the C int64 primitive equivalent of the given JavaScript number.
 *
 * @param env The environment that the API is invoked under.
 * @param value JSVM_Value representing JavaScript number.
 * @param result C int64 primitive equivalent of the given JavaScript number.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 *         {@link JSVM_NUMBER_EXPECTED } If a non-number JSVM_Value is passed in.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetValueInt64(JSVM_Env env,
                                              JSVM_Value value,
                                              int64_t* result);

/**
 * @brief This API returns the ISO-8859-1-encoded string corresponding the value passed in.
 *
 * @param env The environment that the API is invoked under.
 * @param value JSVM_Value representing JavaScript string.
 * @param buf Buffer to write the ISO-8859-1-encoded string into. If NULL is passed in, the
 * length of the string in bytes and excluding the null terminator is returned in result.
 * @param bufsize Size of the destination buffer. When this value is insufficient, the returned string
 * is truncated and null-terminated.
 * @param result Number of bytes copied into the buffer, excluding the null terminator.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 *         {@link JSVM_NUMBER_EXPECTED } If a non-number JSVM_Value is passed in.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetValueStringLatin1(JSVM_Env env,
                                                     JSVM_Value value,
                                                     char* buf,
                                                     size_t bufsize,
                                                     size_t* result);

/**
 * @brief This API returns the UTF8-encoded string corresponding the value passed in.
 *
 * @param env The environment that the API is invoked under.
 * @param value JSVM_Value representing JavaScript string.
 * @param buf Buffer to write the UTF8-encoded string into. If NULL is passed in, the length
 * of the string in bytes and excluding the null terminator is returned in result.
 * @param bufsize Size of the destination buffer. When this value is insufficient, the returned
 * string is truncated and null-terminated.
 * @param result Number of bytes copied into the buffer, excluding the null terminator.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 *         {@link JSVM_NUMBER_EXPECTED } If a non-number JSVM_Value is passed in.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetValueStringUtf8(JSVM_Env env,
                                                   JSVM_Value value,
                                                   char* buf,
                                                   size_t bufsize,
                                                   size_t* result);

/**
 * @brief This API returns the UTF16-encoded string corresponding the value passed in.
 *
 * @param env The environment that the API is invoked under.
 * @param value JSVM_Value representing JavaScript string.
 * @param buf Buffer to write the UTF16-LE-encoded string into. If NULL is passed in,
 * the length of the string in 2-byte code units and excluding the null terminator is returned.
 * @param bufsize Size of the destination buffer. When this value is insufficient,
 * the returned string is truncated and null-terminated.
 * @param result Number of 2-byte code units copied into the buffer, excluding the null terminator.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 *         {@link JSVM_NUMBER_EXPECTED } If a non-number JSVM_Value is passed in.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetValueStringUtf16(JSVM_Env env,
                                                    JSVM_Value value,
                                                    char16_t* buf,
                                                    size_t bufsize,
                                                    size_t* result);

/**
 * @brief This API returns the C primitive equivalent of the given JSVM_Value as a uint32_t.
 *
 * @param env The environment that the API is invoked under.
 * @param value JSVM_Value representing JavaScript number.
 * @param result C primitive equivalent of the given JSVM_Value as a uint32_t.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 *         {@link JSVM_NUMBER_EXPECTED } If a non-number JSVM_Value is passed in it.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetValueUint32(JSVM_Env env,
                                               JSVM_Value value,
                                               uint32_t* result);

/**
 * @brief This API is used to return the JavaScript singleton object that is used to represent the given boolean value.
 *
 * @param env The environment that the API is invoked under.
 * @param value The value of the boolean to retrieve.
 * @param result JSVM_Value representing JavaScript Boolean singleton to retrieve.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetBoolean(JSVM_Env env,
                                           bool value,
                                           JSVM_Value* result);

/**
 * @brief This API returns the global object.
 *
 * @param env The environment that the API is invoked under.
 * @param result JSVM_Value representing JavaScript global object.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetGlobal(JSVM_Env env,
                                          JSVM_Value* result);

/**
 * @brief This API returns the null object.
 *
 * @param env The environment that the API is invoked under.
 * @param result JSVM_Value representing JavaScript null object.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetNull(JSVM_Env env,
                                        JSVM_Value* result);

/**
 * @brief This API returns the Undefined object.
 *
 * @param env The environment that the API is invoked under.
 * @param result JSVM_Value representing JavaScript Undefined value.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetUndefined(JSVM_Env env,
                                             JSVM_Value* result);

/**
 * @brief This API implements the abstract operation ToBoolean()
 *
 * @param env The environment that the API is invoked under.
 * @param value The JavaScript value to coerce.
 * @param result JSVM_Value representing the coerced JavaScript Boolean.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CoerceToBool(JSVM_Env env,
                                             JSVM_Value value,
                                             JSVM_Value* result);

/**
 * @brief This API implements the abstract operation ToNumber() as defined. This
 * function potentially runs JS code if the passed-in value is an object.
 *
 * @param env The environment that the API is invoked under.
 * @param value The JavaScript value to coerce.
 * @param result JSVM_Value representing the coerced JavaScript number.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CoerceToNumber(JSVM_Env env,
                                               JSVM_Value value,
                                               JSVM_Value* result);

/**
 * @brief This API implements the abstract operation ToObject().
 *
 * @param env The environment that the API is invoked under.
 * @param value The JavaScript value to coerce.
 * @param result JSVM_Value representing the coerced JavaScript Object.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CoerceToObject(JSVM_Env env,
                                               JSVM_Value value,
                                               JSVM_Value* result);

/**
 * @brief This API implements the abstract operation ToString().This
 * function potentially runs JS code if the passed-in value is an object.
 *
 * @param env The environment that the API is invoked under.
 * @param value The JavaScript value to coerce.
 * @param result JSVM_Value representing the coerced JavaScript string.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CoerceToString(JSVM_Env env,
                                               JSVM_Value value,
                                               JSVM_Value* result);

/**
 * @brief This API represents behavior similar to invoking the typeof Operator
 * on the object as defined. However, there are some differences:It has support
 * for detecting an External value.It detects null as a separate type, while
 * ECMAScript typeof would detect object.If value has a type that is invalid,
 * an error is returned.
 *
 * @param env The environment that the API is invoked under.
 * @param value The JavaScript value whose type to query.
 * @param result The type of the JavaScript value.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_Typeof(JSVM_Env env,
                                       JSVM_Value value,
                                       JSVM_ValueType* result);

/**
 * @brief This API represents invoking the instanceof Operator on the object.
 *
 * @param env The environment that the API is invoked under.
 * @param object The JavaScript value to check.
 * @param constructor The JavaScript function object of the constructor function
 * to check against.
 * @param result Boolean that is set to true if object instanceof constructor is true.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_Instanceof(JSVM_Env env,
                                           JSVM_Value object,
                                           JSVM_Value constructor,
                                           bool* result);

/**
 * @brief This API represents invoking the IsArray operation on the object
 *
 * @param env The environment that the API is invoked under.
 * @param value The JavaScript value to check.
 * @param result Whether the given object is an array.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_IsArray(JSVM_Env env,
                                        JSVM_Value value,
                                        bool* result);

/**
 * @brief This API checks if the Object passed in is an array buffer.
 *
 * @param env The environment that the API is invoked under.
 * @param value The JavaScript value to check.
 * @param result Whether the given object is an ArrayBuffer.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_IsArraybuffer(JSVM_Env env,
                                              JSVM_Value value,
                                              bool* result);

/**
 * @brief This API checks if the Object passed in is a date.
 *
 * @param env The environment that the API is invoked under.
 * @param value The JavaScript value to check.
 * @param isDate Whether the given JSVM_Value represents a JavaScript Date object.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_IsDate(JSVM_Env env,
                                       JSVM_Value value,
                                       bool* isDate);

/**
 * @brief This API checks if the Object passed in is a typed array.
 *
 * @param env The environment that the API is invoked under.
 * @param value The JavaScript value to check.
 * @param result Whether the given JSVM_Value represents a TypedArray.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_IsTypedarray(JSVM_Env env,
                                             JSVM_Value value,
                                             bool* result);

/**
 * @brief This API checks if the Object passed in is a DataView.
 *
 * @param env The environment that the API is invoked under.
 * @param value The JavaScript value to check.
 * @param result Whether the given JSVM_Value represents a DataView.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_IsDataview(JSVM_Env env,
                                           JSVM_Value value,
                                           bool* result);

/**
 * @brief This API represents the invocation of the Strict Equality algorithm.
 *
 * @param env The environment that the API is invoked under.
 * @param lhs The JavaScript value to check.
 * @param rhs The JavaScript value to check against.
 * @param result Whether the two JSVM_Value objects are equal.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_StrictEquals(JSVM_Env env,
                                             JSVM_Value lhs,
                                             JSVM_Value rhs,
                                             bool* result);

/**
 * @brief This API represents the invocation of the Relaxed Equality algorithm.
 * Returns true as long as the values are equal, regardless of type.
 *
 * @param env The environment that the API is invoked under.
 * @param lhs The JavaScript value to check.
 * @param rhs The JavaScript value to check against.
 * @param result Whether the two JSVM_Value objects are relaxed equal.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_Equals(JSVM_Env env,
                                       JSVM_Value lhs,
                                       JSVM_Value rhs,
                                       bool* result);

/**
 * @brief This API represents the invocation of the ArrayBuffer detach operation.
 *
 * @param env The environment that the API is invoked under.
 * @param arraybuffer The JavaScript ArrayBuffer to be detached.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 *         {@link JSVM_DETACHABLE_ARRAYBUFFER_EXPECTED } If a non-detachable ArrayBuffer is passed in it.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_DetachArraybuffer(JSVM_Env env,
                                                  JSVM_Value arraybuffer);

/**
 * @brief This API represents the invocation of the ArrayBuffer IsDetachedBuffer operation.
 *
 * @param env The environment that the API is invoked under.
 * @param value The JavaScript ArrayBuffer to be checked.
 * @param result Whether the arraybuffer is detached.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_IsDetachedArraybuffer(JSVM_Env env,
                                                      JSVM_Value value,
                                                      bool* result);

/**
 * @brief This API returns the names of the enumerable properties of object as an array of
 * strings. The properties of object whose key is a symbol will not be included.
 *
 * @param env The environment that the API is invoked under.
 * @param object The object from which to retrieve the properties.
 * @param result A JSVM_Value representing an array of JavaScript values that represent
 * the property names of the object. The API can be used to iterate over result using
 * OH_JSVM_GetArrayLength and OH_JSVM_GetElement.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetPropertyNames(JSVM_Env env,
                                                 JSVM_Value object,
                                                 JSVM_Value* result);

/**
 * @brief This API returns an array containing the names of the available properties
 * of this object.
 *
 * @param env The environment that the API is invoked under.
 * @param object The object from which to retrieve the properties.
 * @param keyMode Whether to retrieve prototype properties as well.
 * @param keyFilter Which properties to retrieve (enumerable/readable/writable).
 * @param keyConversion Whether to convert numbered property keys to strings.
 * @param result A JSVM_Value representing an array of JavaScript values
 * that represent the property names of the object. OH_JSVM_GetArrayLength and
 * OH_JSVM_GetElement can be used to iterate over result.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetAllPropertyNames(JSVM_Env env,
                                                    JSVM_Value object,
                                                    JSVM_KeyCollectionMode keyMode,
                                                    JSVM_KeyFilter keyFilter,
                                                    JSVM_KeyConversion keyConversion,
                                                    JSVM_Value* result);

/**
 * @brief This API set a property on the Object passed in.
 *
 * @param env The environment that the API is invoked under.
 * @param object The object on which to set the property.
 * @param key The name of the property to set.
 * @param value The property value.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_SetProperty(JSVM_Env env,
                                            JSVM_Value object,
                                            JSVM_Value key,
                                            JSVM_Value value);

/**
 * @brief This API gets the requested property from the Object passed in.
 *
 * @param env The environment that the API is invoked under.
 * @param object The object from which to retrieve the property.
 * @param key The name of the property to retrieve.
 * @param result The value of the property.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetProperty(JSVM_Env env,
                                            JSVM_Value object,
                                            JSVM_Value key,
                                            JSVM_Value* result);

/**
 * @brief This API checks if the Object passed in has the named property.
 *
 * @param env The environment that the API is invoked under.
 * @param object The object to query.
 * @param key The name of the property whose existence to check.
 * @param result Whether the property exists on the object or not.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_HasProperty(JSVM_Env env,
                                            JSVM_Value object,
                                            JSVM_Value key,
                                            bool* result);

/**
 * @brief This API attempts to delete the key own property from object.
 *
 * @param env The environment that the API is invoked under.
 * @param object The object to query.
 * @param key The name of the property to delete.
 * @param result Whether the property deletion succeeded or not. result
 * can optionally be ignored by passing NULL.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_DeleteProperty(JSVM_Env env,
                                               JSVM_Value object,
                                               JSVM_Value key,
                                               bool* result);

/**
 * @brief This API checks if the Object passed in has the named own property.
 * key must be a string or a symbol, or an error will be thrown. JSVM-API will
 * not perform any conversion between data types.
 *
 * @param env The environment that the API is invoked under.
 * @param object The object to query.
 * @param key The name of the own property whose existence to check.
 * @param result  Whether the own property exists on the object or not.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_HasOwnProperty(JSVM_Env env,
                                               JSVM_Value object,
                                               JSVM_Value key,
                                               bool* result);

/**
 * @brief This method is equivalent to calling OH_JSVM_SetProperty with
 * a JSVM_Value created from the string passed in as utf8name.
 *
 * @param env The environment that the API is invoked under.
 * @param object The object on which to set the property.
 * @param utf8name The name of the property to set.
 * @param value The property value.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_SetNamedProperty(JSVM_Env env,
                                                 JSVM_Value object,
                                                 const char* utf8name,
                                                 JSVM_Value value);

/**
 * @brief This method is equivalent to calling OH_JSVM_SetProperty with
 * a JSVM_Value created from the string passed in as utf8name.
 *
 * @param env The environment that the API is invoked under.
 * @param object The object from which to retrieve the property.
 * @param utf8name The name of the property to get.
 * @param result The value of the property.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetNamedProperty(JSVM_Env env,
                                                 JSVM_Value object,
                                                 const char* utf8name,
                                                 JSVM_Value* result);

/**
 * @brief This method is equivalent to calling OH_JSVM_SetProperty with
 * a JSVM_Value created from the string passed in as utf8name.
 *
 * @param env The environment that the API is invoked under.
 * @param object The object to query.
 * @param utf8name The name of the property whose existence to check.
 * @param result Whether the property exists on the object or not.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_HasNamedProperty(JSVM_Env env,
                                                 JSVM_Value object,
                                                 const char* utf8name,
                                                 bool* result);

/**
 * @brief This API sets an element on the Object passed in.
 *
 * @param env The environment that the API is invoked under.
 * @param object The object from which to set the properties.
 * @param index The index of the property to set.
 * @param value The property value.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_SetElement(JSVM_Env env,
                                           JSVM_Value object,
                                           uint32_t index,
                                           JSVM_Value value);

/**
 * @brief This API gets the element at the requested index.
 *
 * @param env The environment that the API is invoked under.
 * @param object The object from which to retrieve the property.
 * @param index The index of the property to get.
 * @param result The value of the property.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetElement(JSVM_Env env,
                                           JSVM_Value object,
                                           uint32_t index,
                                           JSVM_Value* result);

/**
 * @brief This API returns if the Object passed in has an element
 * at the requested index.
 *
 * @param env The environment that the API is invoked under.
 * @param object The object to query.
 * @param index The index of the property whose existence to check.
 * @param result Whether the property exists on the object or not.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_HasElement(JSVM_Env env,
                                           JSVM_Value object,
                                           uint32_t index,
                                           bool* result);

/**
 * @brief This API attempts to delete the specified index from object.
 *
 * @param env The environment that the API is invoked under.
 * @param object The object to query.
 * @param index The index of the property to delete.
 * @param result Whether the element deletion succeeded or not. result
 * can optionally be ignored by passing NULL.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_DeleteElement(JSVM_Env env,
                                              JSVM_Value object,
                                              uint32_t index,
                                              bool* result);

/**
 * @brief This method allows the efficient definition of multiple properties
 * on a given object.  The properties are defined using property descriptors.
 * Given an array of such property descriptors, this API will set the properties
 * on the object one at a time, as defined by DefineOwnProperty().
 *
 * @param env The environment that the API is invoked under.
 * @param object The object from which to retrieve the properties.
 * @param propertyCount The number of elements in the properties array.
 * @param properties The array of property descriptors.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_DefineProperties(JSVM_Env env,
                                                 JSVM_Value object,
                                                 size_t propertyCount,
                                                 const JSVM_PropertyDescriptor* properties);

/**
 * @brief This method freezes a given object. This prevents new properties
 * from being added to it, existing properties from being removed, prevents
 * changing the enumerability, configurability, or writability of existing
 * properties, and prevents the values of existing properties from being changed.
 * It also prevents the object's prototype from being changed.
 *
 * @param env The environment that the API is invoked under.
 * @param object The object to freeze.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_ObjectFreeze(JSVM_Env env,
                                             JSVM_Value object);

/**
 * @brief This method seals a given object. This prevents new properties
 * from being added to it, as well as marking all existing properties as non-configurable.
 *
 * @param env The environment that the API is invoked under.
 * @param object The object to seal.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_ObjectSeal(JSVM_Env env,
                                           JSVM_Value object);

/**
 * @brief This method allows a JavaScript function object to be called from
 * a native add-on. This is the primary mechanism of calling back from the
 * add-on's native code into JavaScript.
 *
 * @param env The environment that the API is invoked under.
 * @param recv The this value passed to the called function.
 * @param func JSVM_Value representing the JavaScript function to be invoked.
 * @param argc The count of elements in the argv array.
 * @param argv Array of JSVM_values representing JavaScript values passed in as arguments to the function.
 * @param result JSVM_Value representing the JavaScript object returned.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CallFunction(JSVM_Env env,
                                             JSVM_Value recv,
                                             JSVM_Value func,
                                             size_t argc,
                                             const JSVM_Value* argv,
                                             JSVM_Value* result);

 /**
 * @brief This API allows an add-on author to create a function object in native
 * code. This is the primary mechanism to allow calling into the add-on's native
 * code from JavaScript.The newly created function is not automatically visible
 * from script after this call. Instead, a property must be explicitly set on any
 * object that is visible to JavaScript, in order for the function to be accessible
 * from script.
 *
 * @param env The environment that the API is invoked under.
 * @param utf8name Optional name of the function encoded as UTF8. This is visible
 * within JavaScript as the new function object's name property.
 * @param length The length of the utf8name in bytes, or JSVM_AUTO_LENGTH if it
 * is null-terminated.
 * @param cb The native function which should be called when this function
 * object is invoked and data. JSVM_Callback provides more details.
 * @param result JSVM_Value representing the JavaScript function object for the newly
 * created function.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CreateFunction(JSVM_Env env,
                                               const char* utf8name,
                                               size_t length,
                                               JSVM_Callback cb,
                                               JSVM_Value* result);

 /**
 * @brief This method is used within a callback function to retrieve details about
 * the call like the arguments and the this pointer from a given callback info.
 *
 * @param env The environment that the API is invoked under.
 * @param cbinfo The callback info passed into the callback function.
 * @param argc Specifies the length of the provided argv array and receives the
 * actual count of arguments. argc can optionally be ignored by passing NULL.
 * @param argv C array of JSVM_values to which the arguments will be copied. If
 * there are more arguments than the provided count, only the requested number of
 * arguments are copied. If there are fewer arguments provided than claimed, the
 * rest of argv is filled with JSVM_Value values that represent undefined. argv
 * can optionally be ignored by passing NULL.
 * @param thisArg Receives the JavaScript this argument for the call. thisArg
 * can optionally be ignored by passing NULL.
 * @param data Receives the data pointer for the callback. data can optionally
 * be ignored by passing NULL.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetCbInfo(JSVM_Env env,
                                          JSVM_CallbackInfo cbinfo,
                                          size_t* argc,
                                          JSVM_Value* argv,
                                          JSVM_Value* thisArg,
                                          void** data);

/**
 * @brief This API returns the new.target of the constructor call. If the
 * current callback is not a constructor call, the result is NULL.
 *
 * @param env The environment that the API is invoked under.
 * @param cbinfo The callback info passed into the callback function.
 * @param result The new.target of the constructor call.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetNewTarget(JSVM_Env env,
                                             JSVM_CallbackInfo cbinfo,
                                             JSVM_Value* result);

/**
 * @brief his method is used to instantiate a new JavaScript value using
 * a given JSVM_Value that represents the constructor for the object.
 *
 * @param env The environment that the API is invoked under.
 * @param constructor JSVM_Value representing the JavaScript function to be invoked as a constructor.
 * @param argc The count of elements in the argv array.
 * @param argv Array of JavaScript values as JSVM_Value representing the arguments to
 * the constructor. If argc is zero this parameter may be omitted by passing in NULL.
 * @param result JSVM_Value representing the JavaScript object returned, which
 * in this case is the constructed object.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_NewInstance(JSVM_Env env,
                                            JSVM_Value constructor,
                                            size_t argc,
                                            const JSVM_Value* argv,
                                            JSVM_Value* result);

/**
 * @brief When wrapping a C++ class, the C++ constructor callback passed via constructor
 * should be a static method on the class that calls the actual class constructor, then
 * wraps the new C++ instance in a JavaScript object, and returns the wrapper object.
 *
 * @param env The environment that the API is invoked under.
 * @param utf8name Name of the JavaScript constructor function. For clarity, it is
 * recommended to use the C++ class name when wrapping a C++ class.
 * @param length The length of the utf8name in bytes, or JSVM_AUTO_LENGTH if it
 * is null-terminated.
 * @param constructor Struct include callback function that handles constructing instances of the class.
 * When wrapping a C++ class, this method must be a static member with the JSVM_Callback.callback
 * signature. A C++ class constructor cannot be used.
 * Include Optional data to be passed to the constructor callback as the data
 * property of the callback info. JSVM_Callback provides more details.
 * @param propertyCount Number of items in the properties array argument.
 * @param properties Array of property descriptors describing static and instance data
 * properties, accessors, and methods on the class See JSVM_PropertyDescriptor.
 * @param result A JSVM_Value representing the constructor function for the class.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_DefineClass(JSVM_Env env,
                                            const char* utf8name,
                                            size_t length,
                                            JSVM_Callback constructor,
                                            size_t propertyCount,
                                            const JSVM_PropertyDescriptor* properties,
                                            JSVM_Value* result);

/**
 * @brief Wraps a native instance in a JavaScript object.  The native instance can
 * be retrieved later using OH_JSVM_Unwrap().
 *
 * @param env The environment that the API is invoked under.
 * @param jsObject The JavaScript object that will be the wrapper for the native object.
 * @param nativeObject The native instance that will be wrapped in the JavaScript object.
 * @param finalizeCb Optional native callback that can be used to free the native instance
 * when the JavaScript object has been garbage-collected.
 * @param finalizeHint Optional contextual hint that is passed to the finalize callback.
 * properties, accessors, and methods on the class See JSVM_PropertyDescriptor.
 * @param result Optional reference to the wrapped object.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_Wrap(JSVM_Env env,
                                     JSVM_Value jsObject,
                                     void* nativeObject,
                                     JSVM_Finalize finalizeCb,
                                     void* finalizeHint,
                                     JSVM_Ref* result);

/**
 * @brief When JavaScript code invokes a method or property accessor on the class, the corresponding
 * JSVM_Callback is invoked. If the callback is for an instance method or accessor, then the this
 * argument to the callback is the wrapper object; the wrapped C++ instance that is the target of
 * the call can be obtained then by calling OH_JSVM_Unwrap() on the wrapper object.
 *
 * @param env The environment that the API is invoked under.
 * @param jsObject The object associated with the native instance.
 * @param result Pointer to the wrapped native instance.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_Unwrap(JSVM_Env env,
                                       JSVM_Value jsObject,
                                       void** result);

/**
 * @brief Retrieves a native instance that was previously wrapped in the JavaScript object jsObject
 * using OH_JSVM_Wrap() and removes the wrapping. If a finalize callback was associated with the wrapping,
 * it will no longer be called when the JavaScript object becomes garbage-collected.
 *
 * @param env The environment that the API is invoked under.
 * @param jsObject The object associated with the native instance.
 * @param result Pointer to the wrapped native instance.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_RemoveWrap(JSVM_Env env,
                                           JSVM_Value jsObject,
                                           void** result);

/**
 * @brief Associates the value of the typeTag pointer with the JavaScript object or external.
 * OH_JSVM_CheckObjectTypeTag() can then be used to compare the tag that was attached to the
 * object with one owned by the addon to ensure that the object has the right type.
 * If the object already has an associated type tag, this API will return JSVM_INVALID_ARG.
 *
 * @param env The environment that the API is invoked under.
 * @param value The JavaScript object or external to be marked.
 * @param typeTag The tag with which the object is to be marked.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 *         {@link JSVM_INVALID_ARG } If the object already has an associated type tag.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_TypeTagObject(JSVM_Env env,
                                              JSVM_Value value,
                                              const JSVM_TypeTag* typeTag);

/**
 * @brief Compares the pointer given as typeTag with any that can be found on js object.
 * If no tag is found on js object or, if a tag is found but it does not match typeTag,
 * then result is set to false. If a tag is found and it matches typeTag, then result is set to true.
 *
 * @param env The environment that the API is invoked under.
 * @param value The JavaScript object or external whose type tag to examine.
 * @param typeTag The tag with which to compare any tag found on the object.
 * @param result Whether the type tag given matched the type tag on the object. false is also returned
 * if no type tag was found on the object.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CheckObjectTypeTag(JSVM_Env env,
                                                   JSVM_Value value,
                                                   const JSVM_TypeTag* typeTag,
                                                   bool* result);

/**
 * @brief This API can be called multiple times on a single JavaScript object.
 *
 * @param env The environment that the API is invoked under.
 * @param jsObject The JavaScript object to which the native data will be attached.
 * @param finalizeData Optional data to be passed to finalizeCb.
 * @param finalizeCb Native callback that will be used to free the native data when the
 * JavaScript object has been garbage-collected. JSVM_Finalize provides more details.
 * @param finalizeHint Optional contextual hint that is passed to the finalize callback.
 * @param result Optional reference to the JavaScript object.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_AddFinalizer(JSVM_Env env,
                                             JSVM_Value jsObject,
                                             void* finalizeData,
                                             JSVM_Finalize finalizeCb,
                                             void* finalizeHint,
                                             JSVM_Ref* result);

/**
 * @brief This API returns the highest JSVM-API version supported by the JSVM runtime.
 *
 * JSVM-API is planned to be additive such that newer releases of JSVM may support additional
 * API functions. In order to allow an addon to use a newer function when running with versions
 * of JSVM that support it, while providing fallback behavior when running with JSVM
 * versions that don't support it.
 * @param env The environment that the API is invoked under.
 * @param result The highest version of JSVM-API supported.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetVersion(JSVM_Env env,
                                           uint32_t* result);

/**
 * @brief Return information of the VM.
 *
 * @param result The information of the VM.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetVMInfo(JSVM_VMInfo* result);

/**
 * @brief This function gives V8 an indication of the amount of externally
 * allocated memory that is kept alive by JavaScript objects (i.e. a JavaScript
 * object that points to its own memory allocated by a native addon). Registering
 * externally allocated memory will trigger global garbage collections more often
 * than it would otherwise.
 *
 * @param env The environment that the API is invoked under.
 * @param changeInBytes The change in externally allocated memory that is kept
 * alive by JavaScript objects.
 * @param result The adjusted value
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_AdjustExternalMemory(JSVM_Env env,
                                                     int64_t changeInBytes,
                                                     int64_t* result);

/**
 * @brief This function notifies the VM that the system is running low on memory
 * and optionally triggers a garbage collection.
 *
 * @param env The environment that the API is invoked under.
 * @param level The memory pressure level set to the current VM.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_MemoryPressureNotification(JSVM_Env env,
                                                           JSVM_MemoryPressureLevel level);

/**
 * @brief This API creates a deferred object and a JavaScript promise.
 *
 * @param env The environment that the API is invoked under.
 * @param deferred A newly created deferred object which can later be
 * passed to OH_JSVM_ResolveDeferred() or OH_JSVM_RejectDeferred() to resolve
 * resp. reject the associated promise.
 * @param promise The JavaScript promise associated with the deferred object.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CreatePromise(JSVM_Env env,
                                              JSVM_Deferred* deferred,
                                              JSVM_Value* promise);

/**
 * @brief This API resolves a JavaScript promise by way of the deferred object with
 * which it is associated. Thus, it can only be used to resolve JavaScript promises
 * for which the corresponding deferred object is available. This effectively means
 * that the promise must have been created using OH_JSVM_CreatePromise() and the deferred
 * object returned from that call must have been retained in order to be passed to this API.
 *
 * @param env The environment that the API is invoked under.
 * @param deferred The deferred object whose associated promise to resolve.
 * @param resolution The value with which to resolve the promise.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_ResolveDeferred(JSVM_Env env,
                                                JSVM_Deferred deferred,
                                                JSVM_Value resolution);

/**
 * @brief This API rejects a JavaScript promise by way of the deferred object with
 * which it is associated. Thus, it can only be used to reject JavaScript promises
 * for which the corresponding deferred object is available. This effectively means
 * that the promise must have been created using OH_JSVM_CreatePromise() and the deferred
 * object returned from that call must have been retained in order to be passed to this API.
 *
 * @param env The environment that the API is invoked under.
 * @param deferred The deferred object whose associated promise to resolve.
 * @param rejection The value with which to reject the promise.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_RejectDeferred(JSVM_Env env,
                                               JSVM_Deferred deferred,
                                               JSVM_Value rejection);

/**
 * @brief This API return indicating whether promise is a native promise object.
 * @param env The environment that the API is invoked under.
 * @param value The value to examine
 * @param isPromise Flag indicating whether promise is a native promise object
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_IsPromise(JSVM_Env env,
                                          JSVM_Value value,
                                          bool* isPromise);

/**
 * @brief This API register a resolution/rejection handler with a promise.
 * @param env The environment that the API is invoked under.
 * @param promise The promise to be handled.
 * @param onFulfilled The function to be invoked if promise is resolved.
 * @param onRejected The function to be invoked if promise is rejected.
 * @param result Another promise returned from promise then/catch method.
 * @return Returns JSVM functions result code.
 *         {@link JSVM_OK } if the API succeeded. \n
 *         {@link JSVM_INVALID_ARG } if the arguments are invalid. \n
 *         {@link JSVM_INVALID_TYPE } if the arguments are invalid Javascript type. \n
 *         {@link JSVM_PENDING_EXCEPTION} if an exception occurs. \n
 *         {@link JSVM_GENERIC_FAILURE} if the API failed. \n
 *
 * @since 18
 */
JSVM_EXTERN JSVM_Status OH_JSVM_PromiseRegisterHandler(JSVM_Env env,
                                                       JSVM_Value promise,
                                                       JSVM_Value onFulfilled,
                                                       JSVM_Value onRejected,
                                                       JSVM_Value* result);

/**
 * @brief This API parses a JSON string and returns it as value if successful.
 * @param env The environment that the API is invoked under.
 * @param jsonString The string to parse.
 * @param result The parse value if successful.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_JsonParse(JSVM_Env env,
                                          JSVM_Value jsonString,
                                          JSVM_Value* result);

/**
 * @brief This API stringifies the object and returns it as string if successful.
 * @param env The environment that the API is invoked under.
 * @param jsonObject The object to stringify.
 * @param result The string if successfully stringified.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_JsonStringify(JSVM_Env env,
                                              JSVM_Value jsonObject,
                                              JSVM_Value* result);

/**
 * @brief This API create the startup snapshot of the VM.
 * @param vm The environment that the API is invoked under.
 * @param contextCount The object to stringify.
 * @param contexts The array of contexts to add to the snapshot.
 * @param blobData The snapshot data.
 * @param blobSize The size of snapshot data.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 11
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CreateSnapshot(JSVM_VM vm,
                                               size_t contextCount,
                                               const JSVM_Env* contexts,
                                               const char** blobData,
                                               size_t* blobSize);

/**
 * @brief This function returns a set of statistics data of the heap of the VM.
 *
 * @param vm The VM whose heap statistics are returned.
 * @param result The heap statistics data.
 * @return Returns JSVM funtions result code.
 *         Returns {@link JSVM_OK } in all cases.\n
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetHeapStatistics(JSVM_VM vm,
                                                  JSVM_HeapStatistics* result);

/**
 * @brief This function creates and starts a CPU profiler.
 *
 * @param vm The VM to start CPU profiler for.
 * @param result The pointer to the CPU profiler.
 * @return Returns JSVM funtions result code.
 *         Returns {@link JSVM_OK } in all cases.\n
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_StartCpuProfiler(JSVM_VM vm,
                                                 JSVM_CpuProfiler* result);

/**
 * @brief This function stops the CPU profiler and output to the stream.
 *
 * @param vm THe VM to start CPU profiler for.
 * @param profiler The CPU profiler to stop.
 * @param stream The output stream callback for receiving the data.
 * @param streamData Optional data to be passed to the stream callback.
 * @return Returns JSVM funtions result code.
 *         Returns {@link JSVM_OK } in all cases.\n
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_StopCpuProfiler(JSVM_VM vm,
                                                JSVM_CpuProfiler profiler,
                                                JSVM_OutputStream stream,
                                                void* streamData);

/**
 * @brief This funciton takes the current heap snapshot and output to the stream.
 *
 * @param vm The VM whose heap snapshot is taken.
 * @param stream The output stream callback for receiving the data.
 * @param streamData Optional data to be passed to the stream callback.
 * @return Returns JSVM funtions result code.
 *         Returns {@link JSVM_OK } in all cases.\n
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_TakeHeapSnapshot(JSVM_VM vm,
                                                 JSVM_OutputStream stream,
                                                 void* streamData);

/**
 * @brief This functiong activates insepctor on host and port.
 *
 * @param env The environment that the API is invoked under.
 * @param host The host to listen to for inspector connections.
 * @param port The port to listen to for inspector connections.
 * @return Returns JSVM funtions result code.
 *         Returns {@link JSVM_OK } if the function executed successfully.\n
 *         Returns {@link JSVM_PENDING_EXCEPTION } if an exception occurs.\n
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_OpenInspector(JSVM_Env env,
                                              const char* host,
                                              uint16_t port);

/**
 * @brief This function attempts to close all remaining inspector connections.
 *
 * @param env The environment that the API is invoked under.
 * @return Returns JSVM funtions result code.
 *         Returns {@link JSVM_OK } if the function executed successfully.\n
 *         Returns {@link JSVM_PENDING_EXCEPTION } if an exception occurs.\n
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CloseInspector(JSVM_Env env);

/**
 * @brief This function will block until a client (existing or connected later)
 * has sent Runtime.runIfWaitingForDebugger command.
 *
 * @param env The environment that the API is invoked under.
 * @param breakNextLine Whether break on the next line of JavaScript code.
 * @return Returns JSVM funtions result code.
 *         Returns {@link JSVM_OK } if the function executed successfully.\n
 *         Returns {@link JSVM_PENDING_EXCEPTION } if an exception occurs.\n
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_WaitForDebugger(JSVM_Env env,
                                                bool breakNextLine);

/**
 * @brief Define a JavaScript class with given class name, constructor, properties, callback handlers for
 * property operations including get, set, delete, enum etc., and call as function callback.
 *
 * @param env The environment that the API is invoked under.
 * @param utf8name Name of the JavaScript constructor function. For clarity, it is
 * recommended to use the C++ class name when wrapping a C++ class.
 * @param length The length of the utf8name in bytes, or JSVM_AUTO_LENGTH if it
 * is null-terminated.
 * @param constructor Struct include callback function that handles constructing instances of the class.
 * When wrapping a C++ class, this method must be a static member with the JSVM_Callback.callback
 * signature. A C++ class constructor cannot be used.
 * Include Optional data to be passed to the constructor callback as the data
 * property of the callback info. JSVM_Callback provides more details.
 * @param propertyCount Number of items in the properties array argument.
 * @param properties Array of property descriptors describing static and instance data
 * properties, accessors, and methods on the class See JSVM_PropertyDescriptor.
 * @param propertyHandlerCfg The instance object triggers the corresponding callback function.
 * @param callAsFunctionCallback Calling an instance object as a function will trigger this callback.
 * @param result A JSVM_Value representing the constructor function for the class.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_DefineClassWithPropertyHandler(JSVM_Env env,
                                                               const char* utf8name,
                                                               size_t length,
                                                               JSVM_Callback constructor,
                                                               size_t propertyCount,
                                                               const JSVM_PropertyDescriptor* properties,
                                                               JSVM_PropertyHandlerCfg propertyHandlerCfg,
                                                               JSVM_Callback callAsFunctionCallback,
                                                               JSVM_Value* result);

/**
 * @brief Determines whether the current thread holds the lock for the specified environment.
 * Only threads that hold locks can use the environment.
 *
 * @param env The environment that the API is invoked under.
 * @param isLocked Flag indicating whether the current thread holds the lock for the specified environment.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_IsLocked(JSVM_Env env,
                                         bool* isLocked);

/**
 * @brief Acquire the lock for the specified environment. Only threads that hold locks can use the environment.
 *
 * @param env The environment that the API is invoked under.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_AcquireLock(JSVM_Env env);

/**
 * @brief Release the lock for the specified environment. Only threads that hold locks can use the environment.
 *
 * @param env The environment that the API is invoked under.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_ReleaseLock(JSVM_Env env);

/**
 * @brief Starts the running of the task queue inside the VM.
 * This task queue can be executed by an external event loop.
 *
 * @param vm The VM instance on which to start the task queue.
 * @param result Whether the task queue was successfully started.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_PumpMessageLoop(JSVM_VM vm,
                                                bool* result);

/**
 * @brief Check to see if there are any microtasks waiting in the queue, and if there are, execute them.
 *
 * @param vm The VM instance on which to check microtasks.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_PerformMicrotaskCheckpoint(JSVM_VM vm);

/**
 * @brief This API checks if the value passed in is callable.
 *
 * @param env The VM instance on which to check microtasks.
 * @param value The JavaScript value to check.
 * @param isCallable Whether the given value is callable.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } If the function executed successfully.\n
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_IsCallable(JSVM_Env env,
                                           JSVM_Value value,
                                           bool* isCallable);

/**
 * @brief This API checks if the value passed in is undefined.
 * This equals to `value === undefined` in JS.
 *
 * @param env The VM instance on which to check microtasks.
 * @param value The JavaScript value to check.
 * @param isUndefined Whether the given value is Undefined.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } This API will not trigger any exception.\n
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_IsUndefined(JSVM_Env env,
                                            JSVM_Value value,
                                            bool* isUndefined);

/**
 * @brief This API checks if the value passed in is a null object.
 * This equals to `value === null` in JS.
 *
 * @param env The VM instance on which to check microtasks.
 * @param value The JavaScript value to check.
 * @param isNull Whether the given value is Null.
 * @return Only returns JSVM funtions result code.
 *         {@link JSVM_OK } This API will not trigger any exception.\n
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_IsNull(JSVM_Env env,
                                       JSVM_Value value,
                                       bool* isNull);

/**
 * @brief This API checks if the value passed in is either a null or an undefined object.
 * This is equivalent to `value == null` in JS.
 *
 * @param env The VM instance on which to check microtasks.
 * @param value The JavaScript value to check.
 * @param isNullOrUndefined Whether the given value is Null or Undefined.
 * @return Only returns JSVM funtions result code.
 *         {@link JSVM_OK } This API will not trigger any exception.\n
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_IsNullOrUndefined(JSVM_Env env,
                                                  JSVM_Value value,
                                                  bool* isNullOrUndefined);

/**
 * @brief This API checks if the value passed in is a boolean.
 * This equals to `typeof value === 'boolean'` in JS.
 *
 * @param env The VM instance on which to check microtasks.
 * @param value The JavaScript value to check.
 * @param isBoolean Whether the given value is Boolean.
 * @return Only returns JSVM funtions result code.
 *         {@link JSVM_OK } This API will not trigger any exception.\n
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_IsBoolean(JSVM_Env env,
                                          JSVM_Value value,
                                          bool* isBoolean);

/**
 * @brief This API checks if the value passed in is a number.
 * This equals to `typeof value === 'number'` in JS.
 *
 * @param env The VM instance on which to check microtasks.
 * @param value The JavaScript value to check.
 * @param isNumber Whether the given value is Number.
 * @return Only returns JSVM funtions result code.
 *         {@link JSVM_OK } This API will not trigger any exception.\n
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_IsNumber(JSVM_Env env,
                                         JSVM_Value value,
                                         bool* isNumber);

/**
 * @brief This API checks if the value passed in is a string.
 * This equals to `typeof value === 'string'` in JS.
 *
 * @param env The VM instance on which to check microtasks.
 * @param value The JavaScript value to check.
 * @param isString Whether the given value is String.
 * @return Only returns JSVM funtions result code.
 *         {@link JSVM_OK } This API will not trigger any exception.\n
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_IsString(JSVM_Env env,
                                         JSVM_Value value,
                                         bool* isString);

/**
 * @brief This API checks if the value passed in is a symbol.
 * This equals to `typeof value === 'symbol'` in JS.
 *
 * @param env The VM instance on which to check microtasks.
 * @param value The JavaScript value to check.
 * @param isSymbol Whether the given value is Symbol.
 * @return Only returns JSVM funtions result code.
 *         {@link JSVM_OK } This API will not trigger any exception.\n
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_IsSymbol(JSVM_Env env,
                                         JSVM_Value value,
                                         bool* isSymbol);

/**
 * @brief This API checks if the value passed in is a function.
 * This equals to `typeof value === 'function'` in JS.
 *
 * @param env The VM instance on which to check microtasks.
 * @param value The JavaScript value to check.
 * @param isFunction Whether the given value is Function.
 * @return Only returns JSVM funtions result code.
 *         {@link JSVM_OK } This API will not trigger any exception.\n
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_IsFunction(JSVM_Env env,
                                           JSVM_Value value,
                                           bool* isFunction);

/**
 * @brief This API checks if the value passed in is an object.
 *
 * @param env The VM instance on which to check microtasks.
 * @param value The JavaScript value to check.
 * @param isObject Whether the given value is Object.
 * @return Only returns JSVM funtions result code.
 *         {@link JSVM_OK } This API will not trigger any exception.\n
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_IsObject(JSVM_Env env,
                                         JSVM_Value value,
                                         bool* isObject);

/**
 * @brief This API checks if the value passed in is a bigInt.
 * This equals to `typeof value === 'bigint'` in JS.
 *
 * @param env The VM instance on which to check microtasks.
 * @param value The JavaScript value to check.
 * @param isBigInt Whether the given value is BigInt.
 * @return Only returns JSVM funtions result code.
 *         {@link JSVM_OK } This API will not trigger any exception.\n
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_IsBigInt(JSVM_Env env,
                                         JSVM_Value value,
                                         bool* isBigInt);

/**
 * @brief This API returns a JSVM-API value corresponding to a JavaScript Map type.
 *
 * @param env The environment that the API is invoked under.
 * @param result A JSVM_Value representing a JavaScript Map.
 * @return Only returns JSVM function's result code.
 *         {@link JSVM_OK } If the API succeeded.\n
 *         {@link JSVM_INVALID_ARG } If the input parameter is invalid.\n
 * @since 12
 */
JSVM_Status JSVM_CDECL OH_JSVM_CreateMap(JSVM_Env env, JSVM_Value* result);

/**
 * @brief This API checks if the value passed in is a Map.
 *
 * @param env The environment that the API is invoked under.
 * @param value The JavaScript value to check.
 * @param isMap Whether the given value is Map.
 * @return Only returns JSVM function's result code.
 *         {@link JSVM_OK } If the API succeeded.\n
 *         {@link JSVM_INVALID_ARG } If the input parameter is invalid.\n
 * @since 12
 */
JSVM_Status JSVM_CDECL OH_JSVM_IsMap(JSVM_Env env,
                                     JSVM_Value value,
                                     bool* isMap);

/**
 * @brief This API returns a JSVM-API value corresponding to a JavaScript Set type.
 *
 * @param env The environment that the API is invoked under.
 * @param result A JSVM_Value representing a JavaScript Set.
 * @return Returns JSVM function's result code.
 *         {@link JSVM_OK } If the API succeeded.\n
 *         {@link JSVM_INVALID_ARG } If the input parameter is invalid.\n
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CreateSet(JSVM_Env env,
                                          JSVM_Value* result);

/**
 * @brief This API checks if the value passed in is a Set.
 *
 * @param env The environment that the API is invoked under.
 * @param value The JavaScript value to check.
 * @param isSet Whether the given value is Set.
 * @return Returns JSVM function's result code.
 *         {@link JSVM_OK } If the API succeeded.\n
 *         {@link JSVM_INVALID_ARG } If the input parameter is invalid.\n
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_IsSet(JSVM_Env env,
                                      JSVM_Value value,
                                      bool* isSet);

/**
 * @brief This function compiles a string of JavaScript code with the compile options
 * and returns the compiled script.
 *
 * @param env The environment that the JSVM-API call is invoked under.
 * @param script A JavaScript string containing the script to be compiled.
 * @param optionCount length of option array.
 * @param options Compile options to be passed.
 * @param result The compiled script.
 * @return Returns JSVM functions result code
 *         {@link JSVM_OK } if the API succeeded. \n
 *         {@link JSVM_INVALID_ARG } If the input parameter is invalid.\n
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CompileScriptWithOptions(JSVM_Env env,
                                                         JSVM_Value script,
                                                         size_t optionCount,
                                                         JSVM_CompileOptions options[],
                                                         JSVM_Script* result);

/**
 * @brief This API implements the abstract operation ToBigInt().
 *
 * @param env The environment that the API is invoked under.
 * @param value The JavaScript value to coerce.
 * @param result JSVM_Value representing the coerced JavaScript BigInt.
 * @return Returns JSVM function's result code.
 *         {@link JSVM_OK } If the API succeeded.
 *         {@link JSVM_INVALID_ARG } If the input parameter is invalid.\n
 *         {@link JSVM_BIGINT_EXPECTED} If the JavaScript value fails to coerce.\n
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CoerceToBigInt(JSVM_Env env,
                                               JSVM_Value value,
                                               JSVM_Value* result);

/**
 * @brief This API checks if the value passed in is a regExp.
 * This equals to `value instanceof RegExp` in JS.
 *
 * @param env The environment that the API is invoked under.
 * @param value The JavaScript value to check.
 * @param result Whether the given value is RegExp.
 * @return Returns JSVM function's result code.
 *         {@link JSVM_OK } If the API succeeded.\n
 *         {@link JSVM_INVALID_ARG } If the input parameter is invalid.\n
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_IsRegExp(JSVM_Env env,
                                         JSVM_Value value,
                                         bool* result);


/**
 * @brief This API checks if the value passed in is a constructor.
 *
 * @param env The environment that the API is invoked under.
 * @param value The JavaScript value to check.
 * @param isConstructor Whether the given value is Constructor.
 * @return Only returns JSVM function's result code.
 *         {@link JSVM_OK } If the API succeeded.\n
 *         {@link JSVM_INVALID_ARG } If the input parameter is invalid.\n
 * @since 12
 */
JSVM_Status JSVM_CDECL OH_JSVM_IsConstructor(JSVM_Env env,
                                             JSVM_Value value,
                                             bool* isConstructor);

/**
 * @brief This API returns the JavaScript value of the regular expression
 * corresponding to the input.
 * The interface may throw an exception.
 *
 * @param env The environment that the API is invoked under.
 * @param value The JavaScript string to convert to a regular expression.
 * @param flags Regular expression flag bits.
 * @param result A JSVM_Value representing a JavaScript RegExp.
 * @return Only returns JSVM function's result code.
 *         {@link JSVM_OK } If the API succeeded.\n
 *         {@link JSVM_INVALID_ARG } If the input parameter is invalid.\n
 *         {@link JSVM_STRING_EXPECTED } If the value of 'value' is not a string.\n
 *         {@link JSVM_GENERIC_FAILURE } If create RegExp failed.\n
 *         {@link JSVM_PENDING_EXCEPTION } If the API throws an exception during runtime.\n
 * @since 12
 */
JSVM_Status JSVM_CDECL OH_JSVM_CreateRegExp(JSVM_Env env,
                                            JSVM_Value value,
                                            JSVM_RegExpFlags flags,
                                            JSVM_Value* result);

/**
 * @brief This API returns the Object prototype.
 *
 * @param env The environment that the API is invoked under.
 * @param object JSVM_Value representing JavaScript Object whose prototype to return. This returns
 * the equivalent of Object.getPrototypeOf (which is not the same as the function's prototype property).
 * @param result JSVM_Value representing prototype of the given object.
 * @return Returns JSVM function's result code.
 *         {@link JSVM_OK } If the API succeeded.\n
 *         {@link JSVM_INVALID_ARG } If the input parameter is invalid.\n
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_ObjectGetPrototypeOf(JSVM_Env env,
                                                     JSVM_Value object,
                                                     JSVM_Value* result);

/**
 * @brief This API set the prototype on the Object passed in.
 *
 * @param env The environment that the API is invoked under.
 * @param object The object on which to set the prototype.
 * @param prototype The prototype value.
 * @return Returns JSVM function's result code.
 *         {@link JSVM_OK } If the API succeeded.\n
 *         {@link JSVM_INVALID_ARG } If the input parameter is invalid.\n
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_ObjectSetPrototypeOf(JSVM_Env env,
                                                     JSVM_Value object,
                                                     JSVM_Value prototype);

/**
 * @brief Creates a function with a given script as its body.
 *
 * @param env The environment that the API is invoked under.
 * @param funcName A string containing the function's name. Pass NULL to create an anonymous function.
 * @param length The length of the funcName in bytes, or JSVM_AUTO_LENGTH if it
 * is null-terminated.
 * @param argc The count of elements in the argv array.
 * @param argv Array of JSVM_Values representing JavaScript strings passed in as arguments to the function.
 * @param script A JavaScript string containing the script to use as the function's body.
 * @param result JSVM_Value representing the JavaScript function object for the newly
 * created function.
 * @return  Returns JSVM function's result code.
 *          {@link JSVM_OK } If the API succeeded.
 *          {@link JSVM_INVALID_ARG } If the input parameter is invalid.\n
 *          {@link JSVM_GENERIC_FAILURE} If the input script fails to be compiled.\n
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CreateFunctionWithScript(JSVM_Env env,
                                                         const char* funcName,
                                                         size_t length,
                                                         size_t argc,
                                                         const JSVM_Value* argv,
                                                         JSVM_Value script,
                                                         JSVM_Value* result);

/**
 * @brief This function keep persistently save a JSVM_Script and extend its lifecycle
 * beyond the current scope.
 *
 * @param env The environment that the API is invoked under.
 * @param script A JavaScript string containing the script to be retained.
 * @return Returns JSVM functions result code
 *         {@link JSVM_OK } if the API succeeded. \n
 *         {@link JSVM_INVALID_ARG } if the script is empty or already retained. \n
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_RetainScript(JSVM_Env env, JSVM_Script script);

/**
 * @brief This function release the script retained by OH_JSVM_RetainScript
 *
 * @param env The environment that the API is invoked under.
 * @param script A JavaScript string containing the script to be retained.
 * @return Returns JSVM functions result code
 *         {@link JSVM_OK } if the API succeeded. \n
 *         {@link JSVM_INVALID_ARG } if the script is empty or not retained. \n
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_ReleaseScript(JSVM_Env env, JSVM_Script script);

/**
 * @brief This function activates insepctor with pid and alias it.
 *
 * @param env The environment that the API is invoked under.
 * @param pid A process id to identify the inspector connection.
 * @param name An alias for the inspector that under a specific pid.
 * default name is jsvm if a nullptr is passed in.
 * @return Returns JSVM funtions result code.
 *         Returns {@link JSVM_OK } if the function executed successfully.\n
 *         Returns {@link JSVM_PENDING_EXCEPTION } if an exception occurs.\n
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_OpenInspectorWithName(JSVM_Env env,
                                                      int pid,
                                                      const char* name);

/**
 * @brief Compile WebAssembly bytecode into a WebAssembly module.
 * If WebAssembly cache provided, deserialization will be performed.
 *
 * @param env The environment that the API is invoked under.
 * @param wasmBytecode WebAssembly bytecode.
 * @param wasmBytecodeLength WebAssembly bytecode length in byte.
 * @param cacheData Optional WebAssembly cache.
 * @param cacheDataLength Optional WebAssembly cache length in byte.
 * @param cacheRejected Output parameter representing whether the provided cacheData is rejected.
 * @param  wasmModule Output parameter representing compiled WebAssembly module.
 * @return Returns JSVM funtions result code.
 *         Returns {@link JSVM_OK } if the function executed successfully.\n
 *         Returns {@link JSVM_INVALID_ARG } if any of env, wasmBytecode is NULL, or data length is invalid.\n
 *         Returns {@link JSVM_GENERIC_FAILURE } if compile failed.\n
 *         Returns {@link JSVM_PENDING_EXCEPTION } if an exception occurs.\n
 *         Returns {@link JSVM_JIT_MODE_EXPECTED } if run in jitless mode.\n
 *
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CompileWasmModule(JSVM_Env env,
                                                  const uint8_t *wasmBytecode,
                                                  size_t wasmBytecodeLength,
                                                  const uint8_t *cacheData,
                                                  size_t cacheDataLength,
                                                  bool *cacheRejected,
                                                  JSVM_Value *wasmModule);

/**
 * @brief Compile the function with the specified index in the WebAssembly module
 * into the specified optimization level.
 *
 * @param env The environment that the API is invoked under.
 * @param wasmModule The WebAssembly module to which the function to compiled belongs.
 * @param functionIndex The index of the function to be compiled, should never be out of range.
 * @param optLevel Optimization level the function will be compiled with.
 * @return Returns JSVM funtions result code.
 *         Returns {@link JSVM_OK } if the function executed successfully.\n
 *         Returns {@link JSVM_INVALID_ARG } if env is NULL, or wasmModule is NULL or is not a WebAssembly module.\n
 *         Returns {@link JSVM_GENERIC_FAILURE } if functionIndex out of range or compile failed.\n
 *         Returns {@link JSVM_PENDING_EXCEPTION } if an exception occurs.\n
 *         Returns {@link JSVM_JIT_MODE_EXPECTED } if run in jitless mode.\n
 *
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CompileWasmFunction(JSVM_Env env,
                                                    JSVM_Value wasmModule,
                                                    uint32_t functionIndex,
                                                    JSVM_WasmOptLevel optLevel);

/**
 * @brief Check whether the given JSVM_Value is a WebAssembly module.
 *
 * @param env The environment that the API is invoked under.
 * @param value The JavaScript value to check.
 * @param result Whether the given value is a WebAssembly module.
 * @return Returns JSVM funtions result code.
 *         Returns {@link JSVM_OK } if the function executed successfully.\n
 *         Returns {@link JSVM_INVALID_ARG } if any of the input arguments is NULL.\n
 *
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_IsWasmModuleObject(JSVM_Env env,
                                                   JSVM_Value value,
                                                   bool* result);

/**
 * @brief Create cache for compiled WebAssembly module.
 *
 * @param env The environment that the API is invoked under.
 * @param wasmModule The compiled WebAssembly module.
 * @param data Output parameter representing generated WebAssembly module cache.
 * @param length Output parameter representing byte length of generated WebAssembly module cache.
 * @return Returns JSVM funtions result code.
 *         Returns {@link JSVM_OK } if the function executed successfully.\n
 *         Returns {@link JSVM_INVALID_ARG } if any of the input arguments is NULL.\n
 *         Returns {@link JSVM_GENERIC_FAILURE } if create wasm cache failed.\n
 *         Returns {@link JSVM_JIT_MODE_EXPECTED } if run in jitless mode.\n
 *
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CreateWasmCache(JSVM_Env env,
                                                JSVM_Value wasmModule,
                                                const uint8_t** data,
                                                size_t* length);

/**
 * @brief Release cache data with specified cache type.
 *
 * @param env The environment that the API is invoked under.
 * @param cacheData The cache data to be released, double free is undefined behaviors.
 * @param cacheType The type of cache data.
 * @return Returns JSVM funtions result code.
 *         Returns {@link JSVM_OK } if the function executed successfully.\n
 *         Returns {@link JSVM_INVALID_ARG } if any of the pointer arguments is NULL or cacheType is illegal.\n
 *
 * @since 12
 */
JSVM_EXTERN JSVM_Status OH_JSVM_ReleaseCache(JSVM_Env env,
                                             const uint8_t* cacheData,
                                             JSVM_CacheType cacheType);

/**
 * @brief This API creates an external JavaScript string value from an ISO-8859-1-encoded C
 * string. The native string is copied when failed to create external string.
 *
 * @param env The environment that the API is invoked under.
 * @param str Character buffer representing an ISO-8859-1-encoded string.
 * @param length The length of the string in bytes, or JSVM_AUTO_LENGTH if it is null-terminated.
 * @param finalizeCallback Optional callback to call when the external value is being collected.
 * JSVM_Finalize provides more details.
 * @param finalizeHint Optional hint to pass to the finalize callback during collection.
 * @param result A JSVM_Value representing a JavaScript external string.
 * @param copied flag indicate whether the external string is successfully created,
 * true for faild to create external ones and fall back to non-external strings, false for success.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } if the function executed successfully.\n
 *         {@link JSVM_INVALID_ARG } if one of env, str and copied is NULL.\n
 * @since 18
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CreateExternalStringLatin1(JSVM_Env env,
                                                           char* str,
                                                           size_t length,
                                                           JSVM_Finalize finalizeCallback,
                                                           void* finalizeHint,
                                                           JSVM_Value* result,
                                                           bool* copied);

/**
 * @brief This API creates an external JavaScript string value from an UTF16-LE-encoded C
 * string. The native string is copied when failed to create external string.
 *
 * @param env The environment that the API is invoked under.
 * @param str Character buffer representing an UTF16-LE-encoded string.
 * @param length The length of the string in bytes, or JSVM_AUTO_LENGTH if it is null-terminated.
 * @param finalizeCallback Optional callback to call when the external value is being collected.
 * JSVM_Finalize provides more details.
 * @param finalizeHint Optional hint to pass to the finalize callback during collection.
 * @param result A JSVM_Value representing a JavaScript external string.
 * @param copied flag indicate whether the external string is successfully created,
 * true for faild to create external ones and fall back to non-external strings, false for success.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } if the function executed successfully.\n
 *         {@link JSVM_INVALID_ARG } if one of env, str and copied is NULL.\n
 * @since 18
 */

JSVM_EXTERN JSVM_Status OH_JSVM_CreateExternalStringUtf16(JSVM_Env env,
                                                          char16_t* str,
                                                          size_t length,
                                                          JSVM_Finalize finalizeCallback,
                                                          void* finalizeHint,
                                                          JSVM_Value* result,
                                                          bool* copied);

/**
 * @brief This API creates a JavaScript private key.
 *
 * @param env The environment that the API is invoked under.
 * @param description Optional JSVM_Value which refers to a JavaScript string to be set as the description
 * for the private key.
 * @param result A JSVM_Data representing a JavaScript private key.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } if the function executed successfully.\n
 *         {@link JSVM_INVALID_ARG } if env or result is NULL.\n
 *         {@link JSVM_STRING_EXPECTED } if the description is not a string.\n
 * @since 18
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CreatePrivate(JSVM_Env env,
                                              JSVM_Value description,
                                              JSVM_Data* result);

/**
 * @brief This API set a private property on the Object passed in.
 *
 * @param env The environment that the API is invoked under.
 * @param object The object on which to set the private property.
 * @param key The private key of the property.
 * @param value The private property value.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } if the function executed successfully.\n
 *         {@link JSVM_INVALID_ARG } if any of the arguments is NULL or the key is not a private key.\n
 *         {@link JSVM_OBJECT_EXPECTED } object passed in is not a real object.\n
 *         {@link JSVM_GENERIC_FAILURE } if failed to set the private key but no exception is pending.\n
 *         {@link JSVM_PENDING_EXCPTION } if an exception occurs.\n
 * @since 18
 */
JSVM_EXTERN JSVM_Status OH_JSVM_SetPrivate(JSVM_Env env,
                                           JSVM_Value object,
                                           JSVM_Data key,
                                           JSVM_Value value);

/**
 * @brief This API gets the requested private property from the Object passed in.
 *
 * @param env The environment that the API is invoked under.
 * @param object The object from which to retrieve the private property.
 * @param key The private key of the property.
 * @param result The value of the private property.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } if the function executed successfully.\n
 *         {@link JSVM_INVALID_ARG } if any of the arguments is NULL or the key is not a private key.\n
 *         {@link JSVM_OBJECT_EXPECTED } object passed in is not a real object.\n
 *         {@link JSVM_GENERIC_FAILURE } if failed to get the private key but no exception is pending.\n
 *         {@link JSVM_PENDING_EXCPTION } if an exception occurs.\n
 * @since 18
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetPrivate(JSVM_Env env,
                                           JSVM_Value object,
                                           JSVM_Data key,
                                           JSVM_Value *result);

/**
 * @brief This API attempts to delete the property of the private key from object.
 *
 * @param env The environment that the API is invoked under.
 * @param object The object to query.
 * @param key The private key of the property to delete.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } if the function executed successfully.\n
 *         {@link JSVM_INVALID_ARG } if any of the arguments is NULL or the key is not a private key.\n
 *         {@link JSVM_OBJECT_EXPECTED } object passed in is not a real object.\n
 *         {@link JSVM_GENERIC_FAILURE } if failed to delete the private key but no exception is pending.\n
 *         {@link JSVM_PENDING_EXCPTION } if an exception occurs.\n
 * @since 18
 */
JSVM_EXTERN JSVM_Status OH_JSVM_DeletePrivate(JSVM_Env env,
                                              JSVM_Value object,
                                              JSVM_Data key);

/**
 * @brief This API creates a new reference with the specified reference count to the data passed in.
 *
 * @param env The environment that the API is invoked under.
 * @param data The JSVM_Data for which a reference is being created.
 * @param initialRefcount Initial reference count for the new reference.
 * @param result JSVM_Ref pointing to the new reference.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } if the function executed successfully.\n
 *         {@link JSVM_INVALID_ARG } if any parameter is null or the value of initialRefcount is 0.\n
 * @since 18
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CreateDataReference(JSVM_Env env,
                                                    JSVM_Data data,
                                                    uint32_t initialRefcount,
                                                    JSVM_Ref* result);

/**
 * @brief If still valid, this API returns the JSVM_Data representing the
 * JavaScript data associated with the JSVM_Ref. Otherwise, result will be NULL.
 *
 * @param env The environment that the API is invoked under.
 * @param ref The JSVM_Ref for which the corresponding value is being requested.
 * @param result The JSVM_Data referenced by the JSVM_Ref.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } if the function executed successfully.\n
 *         {@link JSVM_INVALID_ARG } if any parameter is null or the ref is not a reference to JSVM_Data.\n
 *
 * @since 18
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetReferenceData(JSVM_Env env,
                                                 JSVM_Ref ref,
                                                 JSVM_Data* result);

/**
 * @brief Check whether the given JSVM_Value is a BigInt Object.
 *
 * @param env The environment that the API is invoked under.
 * @param value The JavaScript value to check.
 * @param result Whether the given value is a BigInt Object.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } if the function executed successfully.\n
 *         {@link JSVM_INVALID_ARG } if any of the pointer arguments is NULL.\n
 *
 * @since 18
 */
JSVM_EXTERN JSVM_Status OH_JSVM_IsBigIntObject(JSVM_Env env,
                                               JSVM_Value value,
                                               bool* result);

/**
 * @brief Check whether the given JSVM_Value is a Boolean Object.
 *
 * @param env The environment that the API is invoked under.
 * @param value The JavaScript value to check.
 * @param result Whether the given value is a Boolean Object.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } if the function executed successfully.\n
 *         {@link JSVM_INVALID_ARG } if any of the pointer arguments is NULL.\n
 *
 * @since 18
 */
JSVM_EXTERN JSVM_Status OH_JSVM_IsBooleanObject(JSVM_Env env,
                                                JSVM_Value value,
                                                bool* result);

/**
 * @brief Check whether the given JSVM_Value is a String Object.
 *
 * @param env The environment that the API is invoked under.
 * @param value The JavaScript value to check.
 * @param result Whether the given value is a String Object.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } if the function executed successfully.\n
 *         {@link JSVM_INVALID_ARG } if any of the pointer arguments is NULL.\n
 *
 * @since 18
 */
JSVM_EXTERN JSVM_Status OH_JSVM_IsStringObject(JSVM_Env env,
                                               JSVM_Value value,
                                               bool* result);

/**
 * @brief Check whether the given JSVM_Value is a Number Object.
 *
 * @param env The environment that the API is invoked under.
 * @param value The JavaScript value to check.
 * @param result Whether the given value is a Number Object.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } if the function executed successfully.\n
 *         {@link JSVM_INVALID_ARG } if any of the pointer arguments is NULL.\n
 *
 * @since 18
 */
JSVM_EXTERN JSVM_Status OH_JSVM_IsNumberObject(JSVM_Env env,
                                               JSVM_Value value,
                                               bool* result);

/**
 * @brief Check whether the given JSVM_Value is a Symbol Object.
 *
 * @param env The environment that the API is invoked under.
 * @param value The JavaScript value to check.
 * @param result Whether the given value is a Symbol Object.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } if the function executed successfully.\n
 *         {@link JSVM_INVALID_ARG } if any of the pointer arguments is NULL.\n
 *
 * @since 18
 */
JSVM_EXTERN JSVM_Status OH_JSVM_IsSymbolObject(JSVM_Env env,
                                               JSVM_Value value,
                                               bool* result);

/**
 * @brief This API returns the Symbol.asyncIterator of Well-Known Symbols.
 *
 * @param env The environment that the API is invoked under.
 * @param result The Symbol.asyncIterator of Well-Known Symbols.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } if the function executed successfully.\n
 *         {@link JSVM_INVALID_ARG } if any of the pointer arguments is NULL.\n
 *
 * @since 18
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetSymbolAsyncIterator(JSVM_Env env, JSVM_Value* result);

/**
 * @brief This API returns the Symbol.hasInstance of Well-Known Symbols.
 *
 * @param env The environment that the API is invoked under.
 * @param result The Symbol.hasInstance of Well-Known Symbols.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } if the function executed successfully.\n
 *         {@link JSVM_INVALID_ARG } if any of the pointer arguments is NULL.\n
 *
 * @since 18
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetSymbolHasInstance(JSVM_Env env, JSVM_Value* result);

/**
 * @brief This API returns the Symbol.isConcatSpreadable of Well-Known Symbols
 *
 * @param env The environment that the API is invoked under.
 * @param result The Symbol.isConcatSpreadable of Well-Known Symbols.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } if the function executed successfully.\n
 *         {@link JSVM_INVALID_ARG } if any of the pointer arguments is NULL.\n
 *
 * @since 18
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetSymbolIsConcatSpreadable(JSVM_Env env, JSVM_Value* result);

/**
 * @brief This API returns the Symbol.match of Well-Known Symbols
 *
 * @param env The environment that the API is invoked under.
 * @param result The Symbol.match of Well-Known Symbols.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } if the function executed successfully.\n
 *         {@link JSVM_INVALID_ARG } if any of the pointer arguments is NULL.\n
 *
 * @since 18
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetSymbolMatch(JSVM_Env env, JSVM_Value* result);

/**
 * @brief This API returns the Symbol.replace of Well-Known Symbols
 *
 * @param env The environment that the API is invoked under.
 * @param result The Symbol.replace of Well-Known Symbols.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } if the function executed successfully.\n
 *         {@link JSVM_INVALID_ARG } if any of the pointer arguments is NULL.\n
 *
 * @since 18
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetSymbolReplace(JSVM_Env env, JSVM_Value* result);

/**
 * @brief This API returns the Symbol.search of Well-Known Symbols
 *
 * @param env The environment that the API is invoked under.
 * @param result The Symbol.search of Well-Known Symbols.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } if the function executed successfully.\n
 *         {@link JSVM_INVALID_ARG } if any of the pointer arguments is NULL.\n
 *
 * @since 18
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetSymbolSearch(JSVM_Env env, JSVM_Value* result);

/**
 * @brief This API returns the Symbol.split of Well-Known Symbols
 *
 * @param env The environment that the API is invoked under.
 * @param result The Symbol.split of Well-Known Symbols.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } if the function executed successfully.\n
 *         {@link JSVM_INVALID_ARG } if any of the pointer arguments is NULL.\n
 *
 * @since 18
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetSymbolSplit(JSVM_Env env, JSVM_Value* result);

/**
 * @brief This API returns the Symbol.toPrimitive of Well-Known Symbols
 *
 * @param env The environment that the API is invoked under.
 * @param result The Symbol.toPrimitive of Well-Known Symbols.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } if the function executed successfully.\n
 *         {@link JSVM_INVALID_ARG } if any of the pointer arguments is NULL.\n
 *
 * @since 18
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetSymbolToPrimitive(JSVM_Env env, JSVM_Value* result);

/**
 * @brief This API returns the Symbol.unscopables of Well-Known Symbols
 *
 * @param env The environment that the API is invoked under.
 * @param result The Symbol.unscopables of Well-Known Symbols.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } if the function executed successfully.\n
 *         {@link JSVM_INVALID_ARG } if any of the pointer arguments is NULL.\n
 *
 * @since 18
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetSymbolUnscopables(JSVM_Env env, JSVM_Value* result);

/**
 * @brief This API returns the Symbol.toStringTag of Well-Known Symbols
 *
 * @param env The environment that the API is invoked under.
 * @param result The Symbol.toStringTag of Well-Known Symbols.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } if the function executed successfully.\n
 *         {@link JSVM_INVALID_ARG } if any of the pointer arguments is NULL.\n
 *
 * @since 18
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetSymbolToStringTag(JSVM_Env env, JSVM_Value* result);

/**
 * @brief This API returns the Symbol.iterator of Well-Known Symbols
 *
 * @param env The environment that the API is invoked under.
 * @param result The Symbol.iterator of Well-Known Symbols.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } if the function executed successfully.\n
 *         {@link JSVM_INVALID_ARG } if any of the pointer arguments is NULL.\n
 *
 * @since 18
 */
JSVM_EXTERN JSVM_Status OH_JSVM_GetSymbolIterator(JSVM_Env env, JSVM_Value* result);

/**
 * @brief Trace start with specified categories for all JSVM VM.(Non-thread-safe)
 *
 * @param count The count of trace categories.
 * @param categories Select internal trace events for tracing by categories.
 * @param tag User-defined tag of trace data.
 * @param eventsCount Number of trace events.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } if the function executed successfully.\n
 *         {@link JSVM_INVALID_ARG } if categories or count is illegal.\n
 *
 * @since 18
 */
JSVM_EXTERN JSVM_Status OH_JSVM_TraceStart(size_t count, const JSVM_TraceCategory* categories,
                                           const char* tag, size_t eventsCount);

/**
 * @brief Trace stop for specified categories for all JSVM VM.(Non-thread-safe)
 *
 * @param stream The output stream callback for receiving the data.
 * @param streamData Data passed to the stream callback.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } if the function executed successfully.\n
 *         {@link JSVM_INVALID_ARG } if stream or streamData is NULL\n
 *
 * @since 18
 */
JSVM_EXTERN JSVM_Status OH_JSVM_TraceStop(JSVM_OutputStream stream, void* streamData);

/**
 * @brief Set Handler For OOM Error. If this function is invoked repeatedly,
 * only the last time takes effect. When handler is null, the previous setting is canceled.
 *
 * @param vm The environment that the API is invoked under.
 * @param handler The handler for OOM Error.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } if the function executed successfully.\n
 *         {@link JSVM_INVALID_ARG } if vm is NULL.\n
 *
 * @since 18
 */
JSVM_EXTERN JSVM_Status OH_JSVM_SetHandlerForOOMError(JSVM_VM vm,
                                                      JSVM_HandlerForOOMError handler);

/**
 * @brief This API is used to enable/disable the given debug option for a certain JSVM_Env.
 *
 * @param env The environment that the API is invoked under.
 * @param debugOption The debug option to be changed.
 * @param isEnabled Whether to enable or disable the debug option.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } if the function executed successfully.\n
 *         {@link JSVM_INVALID_ARG } if env is NULL.\n
 *
 * @since 20
 */
JSVM_EXTERN JSVM_Status OH_JSVM_SetDebugOption(JSVM_Env env, JSVM_DebugOption debugOption, bool isEnabled);

/**
 * @brief Set Handler For Fatal Error. If this function is invoked repeatedly,
 * only the last time takes effect. When handler is null, the previous setting is canceled.
 *
 * @param vm The environment that the API is invoked under.
 * @param handler The handler for Fatal Error.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } if the function executed successfully.\n
 *         {@link JSVM_INVALID_ARG } if vm is NULL.\n
 *
 * @since 18
 */
JSVM_EXTERN JSVM_Status OH_JSVM_SetHandlerForFatalError(JSVM_VM vm,
                                                        JSVM_HandlerForFatalError handler);

/**
 * @brief Set Handler For Promise Reject. If this function is invoked repeatedly,
 * only the last time takes effect. When handler is null, the previous setting is canceled.
 *
 * @param vm The environment that the API is invoked under.
 * @param handler The handler for Promise Reject.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } if the function executed successfully.\n
 *         {@link JSVM_INVALID_ARG } if vm is NULL.\n
 *
 * @since 18
 */
JSVM_EXTERN JSVM_Status OH_JSVM_SetHandlerForPromiseReject(JSVM_VM vm,
                                                           JSVM_HandlerForPromiseReject handler);

/**
 * @brief When wrapping a C++ class, the C++ constructor callback passed via constructor
 * should be a static method on the class that calls the actual class constructor, then
 * wraps the new C++ instance in a JavaScript object according to the different Options
 * passed in, and returns the wrapper object.
 *
 * @param env The environment that the API is invoked under.
 * @param utf8name Name of the JavaScript constructor function. For clarity, it is
 * recommended to use the C++ class name when wrapping a C++ class.
 * @param length The length of the utf8name in bytes, or JSVM_AUTO_LENGTH if it
 * is null-terminated.
 * @param constructor Struct include callback function that handles constructing instances of the class.
 * When wrapping a C++ class, this method must be a static member with the JSVM_Callback.callback
 * signature. A C++ class constructor cannot be used.
 * Include Optional data to be passed to the constructor callback as the data
 * property of the callback info. JSVM_Callback provides more details.
 * @param propertyCount Number of items in the properties array argument.
 * @param properties Array of property descriptors describing static and instance data
 * properties, accessors, and methods on the class See JSVM_PropertyDescriptor.
 * @param parentClass The parent-class of the currently defined class.
 * @param option_count Number of items in an option array argument.
 * @param options DefineClass options to be passed.
 * @param result A JSVM_Value representing the constructor function for the class.
 * @return Returns JSVM functions result code.
 *         {@link JSVM_OK } if the function executed successfully. \n
 *         {@link JSVM_INVALID_ARG } if any of the pointer arguments is NULL. \n
 *         {@link JSVM_GENERIC_FAILURE} if the input utf8name | constructor | properties is invalid. \n
 * @since 18
 */
JSVM_EXTERN JSVM_Status OH_JSVM_DefineClassWithOptions(JSVM_Env env,
                                                       const char* utf8name,
                                                       size_t length,
                                                       JSVM_Callback constructor,
                                                       size_t propertyCount,
                                                       const JSVM_PropertyDescriptor* properties,
                                                       JSVM_Value parentClass,
                                                       size_t option_count,
                                                       JSVM_DefineClassOptions options[],
                                                       JSVM_Value* result);

/**
 * @brief Add VM GC Callback.
 *
 * @param vm The environment that the API is invoked under.
 * @param triggerTime The timing of GC callback trigger.
 * @param handler When Trigger gc, the callback function will be called.
 * @param gcType The type of gc.
 * @param userData The native pointer data.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } if the function executed successfully.\n
 *         {@link JSVM_INVALID_ARG } if the vm or the handler is NULL or the handler has been added before.\n
 *
 * @since 18
 */
JSVM_EXTERN JSVM_Status OH_JSVM_AddHandlerForGC(JSVM_VM vm,
                                                JSVM_CBTriggerTimeForGC triggerTime,
                                                JSVM_HandlerForGC handler,
                                                JSVM_GCType gcType,
                                                void* userData);

/**
 * @brief Remove VM GC Callback.
 *
 * @param vm The environment that the API is invoked under.
 * @param triggerTime The timing of GC callback trigger.
 * @param handler When Trigger gc, the callback function will be called.
 * @param userData The native pointer data.
 * @return Returns JSVM funtions result code.
 *         {@link JSVM_OK } if the function executed successfully.\n
 *         {@link JSVM_INVALID_ARG } if the vm or the handler is NULL, or the handler has been removed,
 * or the handler has never been added.\n
 *
 * @since 18
 */
JSVM_EXTERN JSVM_Status OH_JSVM_RemoveHandlerForGC(JSVM_VM vm,
                                                   JSVM_CBTriggerTimeForGC triggerTime,
                                                   JSVM_HandlerForGC handler,
                                                   void* userData);
EXTERN_C_END
/** @} */
#endif /* ARK_RUNTIME_JSVM_JSVM_H */

