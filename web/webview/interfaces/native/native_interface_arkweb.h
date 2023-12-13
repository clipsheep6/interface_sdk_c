/*
 * Copyright (c) 2023 Huawei Device Co., Ltd.
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
 * @addtogroup Web
 * @{
 *
 * @brief Provides APIs to use javascript proxy and run javascirpt code.
 * @since 11
 */
/**
 * @file native_interface_arkweb.h
 *
 * @brief Declares the APIs to use javascript proxy and run javascirpt code.
 * @library libweb_ndk.z.so
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */

#ifndef _NATIVE_INTERFACE_ARKWEB_H_
#define _NATIVE_INTERFACE_ARKWEB_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * @brief Configuration information for custom schemes. 
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
enum OH_ArkWeb_CustomSchemeOption {
   OH_ARKWEB_SCHEME_OPTION_NONE = 0,

   /*
    * @brief If OH_ARKWEB_SCHEME_OPTION_STANDARD is set the scheme will be handled
    * as a standard scheme. The standard schemes needs to comply with the URL normalization
    * and parsing rules defined in Section 3.1 of RFC 1738, which can be found in the
    * http://www.ietf.org/rfc/rfc1738.txt.
    *
    * @syscap SystemCapability.Web.Webview.Core
    * @since 11
    */
   OH_ARKWEB_SCHEME_OPTION_STANDARD = 1 << 0,

   /*
    * @brief If OH_ARKWEB_SCHEME_OPTION_LOCAL is set, the same security rules as those
    * applied to the "file" URL will be used to handle the scheme.
    *
    * @syscap SystemCapability.Web.Webview.Core
    * @since 11
    */
   OH_ARKWEB_SCHEME_OPTION_LOCAL = 1 << 1,

   /*
    * @brief If OH_ARKWEB_SCHEME_OPTION_DISPLAY_ISOLATED is set, then the scheme can only
    * be displayed from other content hosted using the same scheme.
    *
    * @syscap SystemCapability.Web.Webview.Core
    * @since 11
    */
   OH_ARKWEB_SCHEME_OPTION_DISPLAY_ISOLATED = 1 << 2,

   /*
    * @brief If OH_ARKWEB_SCHEME_OPTION_SECURE is set, the same security rules as those
    * applied to the "https" URL will be used to handle the scheme.
    *
    * @syscap SystemCapability.Web.Webview.Core
    * @since 11
    */
   OH_ARKWEB_SCHEME_OPTION_SECURE = 1 << 3,

   /*
    * @brief If OH_ARKWEB_SCHEME_OPTION_CORS_ENABLED is set, then the scheme can be sent CORS
    * requests. In most case this value should be set when OH_ARKWEB_SCHEME_OPTION_STANDARD
    * is set.
    *
    * @syscap SystemCapability.Web.Webview.Core
    * @since 11
    */
   OH_ARKWEB_SCHEME_OPTION_CORS_ENABLED = 1 << 4,

   /*
    * @brief If OH_ARKWEB_SCHEME_OPTION_CSP_BYPASSING is set, then this scheme can bypass
    * Content Security Policy (CSP) checks. In most cases, this value should not be set
    * when OH_ARKWEB_SCHEME_OPTION_STANDARD is set.
    *
    * @syscap SystemCapability.Web.Webview.Core
    * @since 11
    */
   OH_ARKWEB_SCHEME_OPTION_CSP_BYPASSING = 1 << 5,

   /*
    * @brief If OH_ARKWEB_SCHEME_OPTION_FETCH_ENABLED is set, then this scheme can perform
    * FETCH API requests.
    *
    * @syscap SystemCapability.Web.Webview.Core
    * @since 11
    */
   OH_ARKWEB_SCHEME_OPTION_FETCH_ENABLED = 1 << 6,
};

/*
 * @brief  This class is used to intercept requests for a specified scheme. 
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
typedef struct OH_ArkWeb_SchemeHandler_ OH_ArkWeb_SchemeHandler;

/*
 * @brief Used to intercept url requests. Response headers and body can be
 * sent through OH_ArkWeb_ResourceHandler. 
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
typedef struct OH_ArkWeb_ResourceHandler OH_ArkWeb_ResourceHandler;

/*
 * @brief The response of the intercepted request. 
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
typedef struct OH_ArkWeb_Response_ OH_ArkWeb_Response;

/*
 * @brief The info of the request. You can obtain the requested URL,
 * method, post data, and other information through OH_ArkWeb_ResourceRequest.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
typedef struct OH_ArkWeb_ResourceRequest_ OH_ArkWeb_ResourceRequest;

/*
 * @brief The request headers of the request.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
typedef struct OH_ArkWeb_RequestHeaderList_ OH_ArkWeb_RequestHeaderList;

/*
 * @brief A single request header. 
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
typedef struct OH_ArkWeb_RequestHeader_ OH_ArkWeb_RequestHeader;

/*
 * @brief Callback for handling the request. This will called on the IO thread. 
 *        should not use resourceHandler in the function.
 * @param webTag The name of the web component.
 * @param resourceRequest Obtain request's information through this.
 * @param resourceHandler The OH_ArkWeb_ResourceHandler for the request. It
 *                        should not be used if intercept is set to false.
 * @param intercept If true will intercept the request, if false otherwise.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
typedef void (*OnRequestStart)(const char* webTag, OH_ArkWeb_ResourceRequest* resourceRequest, OH_ArkWeb_ResourceHandler* resourceHandler, bool* intercept);

/*
 * @brief  Callback when the request is completed. This will called on the IO thread.
 * @param webTag The name of the web component.
 * @param resourceHandler The OH_ArkWeb_ResourceHandler for the request.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
typedef void (*OnRequestStop)(const char* webTag, OH_ArkWeb_ResourceRequest* resourceRequest, OH_ArkWeb_ResourceHandler* resourceHandler);

/*
 * @brief A list of request header. 
 * @param requestHeaderList The created OH_ArkWeb_RequestHeaderList.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_RequestHeaderList_Create(OH_ArkWeb_RequestHeaderList** requestHeaderList);

/*
 * @brief Destroy the RequestHeaderList. 
 * @param requestHeaderList The OH_ArkWeb_RequestHeaderList to be destroyed.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_RequestHeaderList_Destroy(OH_ArkWeb_RequestHeaderList* requestHeaderList);

/*
 * @brief Get the request headers size. 
 * @param requestHeaderList The list of request header.
 * @param size The size of request headers.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_RequestHeaderList_GetSize(const OH_ArkWeb_RequestHeaderList* requestHeaderList, int* size);

/*
 * @brief Get the specified request header. 
 * @param requestHeaderList The list of request header.
 * @param index The index of request header.
 * @param requestHeader The request header at index.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_RequestHeaderList_GetHeader(const OH_ArkWeb_RequestHeaderList* requestHeaderList, int index, OH_ArkWeb_RequestHeader* requestHeader);

/*
 * @brief Create a request header. 
 * @param requestHeader Return the created OH_ArkWeb_RequestHeader.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_RequestHeader_Create(OH_ArkWeb_RequestHeader** requestHeader);

/*
 * @brief Destroy the request header. 
 * @param requestHeader The request header to be destroyed.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_RequestHeader_Destroy(OH_ArkWeb_RequestHeader* requestHeader);

/*
 * @brief Get the name of request header. 
 * @param requestHeader The request header.
 * @param name The name of request header. This function will allocate memory for the name string and caller
 *             must release the string by OH_NativeArkWeb_ReleaseString.
 *             
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_RequestHeader_GetName(const OH_ArkWeb_RequestHeader* requestHeader, char** name);

/*
 * @brief Get the value of request header. 
 * @param requestHeader The request header.
 * @param value The value of request header. This function will allocate memory for the value string and caller
 *               must release the string by OH_NativeArkWeb_ReleaseString.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_RequestHeader_GetValue(const OH_ArkWeb_RequestHeader* requestHeader, char** value);

/*
 * @brief Get the method of request. 
 * @param resourceRequest The resource request.
 * @param method The request's http method. This function will allocate memory for the method string and caller
 *               must release the string by OH_NativeArkWeb_ReleaseString.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_ResourceRequest_GetMethod(const OH_ArkWeb_ResourceRequest* resourceRequest, char** method);

/*
 * @brief Get the url of request. 
 * @param resourceRequest The resource request.
 * @param url The request's url. This function will allocate memory for the url string and caller
 *            must release the string by OH_NativeArkWeb_ReleaseString.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_ResourceRequest_GetUrl(const OH_ArkWeb_ResourceRequest* resourceRequest, char** url);

/*
 * @brief Get the post data of request. 
 * @param resourceRequest The resource request.
 * @param postData The request's post data. This function will allocate memory for the post data and caller
 *                 must release the string by OH_NativeArkWeb_ReleaseByteArray.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_ResourceRequest_GetPostData(const OH_ArkWeb_ResourceRequest* resourceRequest, uint8_t** postData, int64_t* postDataSize);

/*
 * @brief Get the referrer of request. 
 * @param resourceRequest The resource request.
 * @param referrer The request's referrer. This function will allocate memory for the post data string and caller
 *                 must release the string by OH_NativeArkWeb_ReleaseString.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_ResourceRequest_GetReferrer(const OH_ArkWeb_ResourceRequest* resourceRequest, char** referrer);

/*
 * @brief Get the OH_ArkWeb_RequestHeaderList of the request.
 * @param resourceRequest The resource request.
 * @param requestHeaderList The RequestHeaderList of request.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_ResourceRequest_GetRequestHeaders(const OH_ArkWeb_ResourceRequest* resourceRequest, OH_ArkWeb_RequestHeaderList** requestHeaderList);

/*
 * @brief Get if this is a redirect request.
 * @param resourceRequest The resource request.
 * @param isRedirect True if this is a redirect, false otherwise.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_ResourceRequest_IsRedirect(const OH_ArkWeb_ResourceRequest* resourceRequest, bool* isRedirect);

/*
 * @brief Get if this is a request from main frame.
 * @param resourceRequest The resource request.
 * @param isMainFrame True if this is from main frame, false otherwise.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_ResourceRequest_IsMainFrame(const OH_ArkWeb_ResourceRequest* resourceRequest, bool* isMainFrame);

/*
 * @brief Get if this is a request is triggered by user gesutre.
 * @param resourceRequest The resource request.
 * @param hasGesture True if this is triggered by user gesture, false otherwise.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_ResourceRequest_HasGesture(const OH_ArkWeb_ResourceRequest* resourceRequest, bool* hasGesture);

/*
 * @brief Register custom scheme to the ArkWeb. Should not be called for
 *        built-in HTTP, HTTPS, FILE, FTP, ABOUT and DATA schemes.
 *        This function should be called on main thread.
 * @param scheme The scheme to regist.
 * @param option The configuration of the scheme.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_RegisterCustomSchemes(const char* scheme, int32_t option);

/*
 * @brief  Set a SchemeHandler for a specific scheme to intercept requests of that scheme type.
 * @param scheme  Scheme that need to be intercepted.
 * @param schemeHandler The SchemeHandler for the scheme.
 * @return Return true if set SchemeHandler for specific scheme successful, return false otherwise.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
bool OH_NativeArkWeb_SetSchemeHandler(const char* scheme, OH_ArkWeb_SchemeHandler* schemeHandler);

/*
 * @brief Clear all registered SchemeHandlers .
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_ClearAllSchemeHandlers();

/*
 * @brief Create a SchemeHandler.
 * @param schemeHandler Return the created SchemeHandler. Use OH_NativeArkWeb_DestroySchemeHandler destroy
 *                      it when donn't need it.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_CreateSchemeHandler(OH_ArkWeb_SchemeHandler** schemeHandler);

/*
 * @brief Destroy a SchemeHandler.
 * @param The OH_ArkWeb_SchemeHandler to be destroy.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_DestroySchemeHandler(OH_ArkWeb_SchemeHandler* schemeHandler);

/*
 * @brief Set the OnRequestStart callback for SchemeHandler.
 * @param schemeHandler The SchemeHandler for the scheme.
 * @param onRequestStart The OnRequestStart callback.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_SchemeHandler_SetOnRequestStart(OH_ArkWeb_SchemeHandler* schemeHandler, OnRequestStart onRequestStart);

/*
 * @brief Set the OnRequestStop callback for SchemeHandler.
 * @param schemeHandler The SchemeHandler for the scheme.
 * @param onRequestStop The OnRequestStop callback.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_SchemeHandler_SetOnRequestStop(OH_ArkWeb_SchemeHandler* schemeHandler, OnRequestStop onRequestStop);

/*
 * @brief Create a Response for a request.
 * @param Return the created Response. Use OH_NativeArkWeb_DestroyResponse to destroy when donn't need it.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_CreateResponse(OH_ArkWeb_Response** response);

/*
 * @brief Destroy the Reponse.
 * @param response The Response needs destroy.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_DestroyResponse(OH_ArkWeb_Response* response);

/*
 * @brief Set a error code to OH_ArkWeb_Response.
 * @param response The response to set.
 * @param errorCode The error code for the failed request.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_Response_SetError(OH_ArkWeb_Response* response, int32_t errorCode);

/*
 * @brief Get the response's error code.
 * @param response The response.
 * @param errorCode Return the response's error code.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_Response_GetError(const OH_ArkWeb_Response* response, int32_t* errorCode);

/*
 * @brief Set a status code to ArkWebResponse.
 * @param response The response to set.
 * @param status The status for the request.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_Response_SetStatus(OH_ArkWeb_Response* response, int32_t status);

/*
 * @brief Get the response's status code.
 * @param response The response.
 * @param status Return the response's status code.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_Response_GetStatus(const OH_ArkWeb_Response* response, int32_t* status);

/*
 * @brief Set a status text to ArkWebResponse.
 * @param response The response to set.
 * @param statusText The status text for the request.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_Response_SetStatusText(OH_ArkWeb_Response* response, const char* statusText);

/*
 * @brief Get the response's status text.
 * @param response The response.
 * @param statusText Return the response's statusText. This function will allocate memory for the statusText string and caller
 *             must release the string by OH_NativeArkWeb_ReleaseString.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_Response_GetStatusText(const OH_ArkWeb_Response* response, char** statusText);

/*
 * @brief Set mime type to ArkWebResponse.
 * @param response The response to set.
 * @param mimeType The mime type for the request.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_Response_SetMimeType(OH_ArkWeb_Response* response, const char* mimeType);

/*
 * @brief Get the response's mime type.
 * @param response The response.
 * @param mimeType Return the response's mime type. This function will allocate memory for the mime type string and caller
 *             must release the string by OH_NativeArkWeb_ReleaseString.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_Response_GetMimeType(const OH_ArkWeb_Response* response, char** mimeType);

/*
 * @brief Set charset to OH_ArkWeb_Response.
 * @param response The response to set.
 * @param charset The charset for the request.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_Response_SetCharset(OH_ArkWeb_Response* response, const char* charset);

/*
 * @brief Get the response's charset.
 * @param response The response.
 * @param charset Return the response's charset. This function will allocate memory for the charset string and caller
 *                must release the string by OH_NativeArkWeb_ReleaseString.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_Response_GetCharset(const OH_ArkWeb_Response* response, char** charset);

/*
 * @brief Set a header to OH_ArkWeb_Response.
 * @param response The response.
 * @param name The name of the header.
 * @param value The value of the header.
 * @bool overwirte If true will overwrite the exsits header, if false otherwise. 
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_Response_SetHeaderByName(OH_ArkWeb_Response* response, const char* name, const char* value, bool overwrite);

/*
 * @brief Get the header from the response.
 * @param response The Response.
 * @param name The name of the header.
 * @param value Return the header's value. This function will allocate memory for the value string and caller
 *              must release the string by OH_NativeArkWeb_ReleaseString.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_Response_GetHeaderByName(const OH_ArkWeb_Response* response, const char* name, char** value);

/*
 * @brief Pass response headers to intercepted requests .
 * @param resourceHandler The OH_ArkWeb_ResourceHandler for the request.
 * @param response The OH_ArkWeb_Response for the intercepting requests. 
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_ResourceHandler_DidReceiveResponse(const OH_ArkWeb_ResourceHandler* resourceHandler, const OH_ArkWeb_Response* response);

/*
 * @brief Pass response body data to intercepted requests.
 * @param resourceHandler The OH_ArkWeb_ResourceHandler for the request.
 * @param buffer Buffer data to send.
 * @param bufLen The size of buffer. 
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_ResourceHandler_DidReceiveData(const char* OH_ArkWeb_ResourceHandler* resourceHandler, const char* buffer, int bufLen);

/*
 * @brief Notify the ArkWeb that this request should be finished and there is no more data available.
 * @param resourceHandler The OH_ArkWeb_ResourceHandler for the request.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_ResourceHandler_DidFinish(const OH_ArkWeb_ResourceHandler* resourceHandler);

/*
 * @brief Notify the ArkWeb that this request should be failed.
 * @param resourceHandler The OH_ArkWeb_ResourceHandler for the request.
 * @param errorCode The error code for this request.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_ResourceHandler_DidFailWithError(const OH_ArkWeb_ResourceHandler* resourceHandler, int errorCode);

/*
 * @brief Release the string acquired by native function.
 * @param string The string to be released.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_ReleaseString(char* string);

/*
 * @brief Release the byte array acquired by native function.
 * @param byteArray The byte array to be released.
 *
 * @syscap SystemCapability.Web.Webview.Core
 * @since 11
 */
void OH_NativeArkWeb_ReleaseByteArray(uint8_t* byteArray);

#ifdef __cplusplus
};
#endif
#endif // _NATIVE_INTERFACE_ARKWEB_H_
