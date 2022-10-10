/*
 * Copyright (C) 2021-2022 Huawei Device Co., Ltd.
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

import {AsyncCallback, Callback, ErrorCallback} from "./basic";
import connection from "./@ohos.net.connection";
import cryptoFramework from "./@ohos.security.cryptoFramework";

/**
 * Provides TCP and UDP Socket APIs.
 *
 * @since 7
 * @syscap SystemCapability.Communication.NetStack
 */
declare namespace socket {
  export import NetAddress = connection.NetAddress;
  export type X509CertRawData = cryptoFramework.EncodingBlob;

  /**
   * Creates a UDPSocket object.
   */
  function constructUDPSocketInstance(): UDPSocket;

  /**
   * Creates a TCPSocket object.
   */
  function constructTCPSocketInstance(): TCPSocket;

  /**
   * Creates a TLSSocket object.
   *
   * @since 9
   */
  function constructTLSSocketInstance(): TLSSocket;

  export interface UDPSendOptions {
    /**
     * Data to send.
     */
    data: string | ArrayBuffer;

    /**
     * Destination address.
     */
    address: NetAddress;
  }

  export interface ExtraOptionsBase {
    /**
     * Size of the receive buffer, in MBS.
     */
    receiveBufferSize?: number;

    /**
     * Size of the send buffer, in MBS.
     */
    sendBufferSize?: number;

    /**
     * Whether to reuse addresses. The default value is false.
     */
    reuseAddress?: boolean;

    /**
     * Timeout duration of the UDPSocket connection, in milliseconds.
     */
    socketTimeout?: number;
  }

  export interface UDPExtraOptions extends ExtraOptionsBase {
    /**
     * Whether to send broadcast messages. The default value is false.
     */
    broadcast?: boolean;
  }

  export interface SocketStateBase {
    /**
     * Whether the connection is in the bound state.
     */
    isBound: boolean;

    /**
     * Whether the connection is in the closed state.
     */
    isClose: boolean;

    /**
     * Whether the connection is in the connected state.
     */
    isConnected: boolean;
  }

  export interface SocketRemoteInfo {
    /**
     * Bound IP address.
     */
    address: string;

    /**
     * Network protocol type. The options are as follows: IPv4, IPv6.
     */
    family: 'IPv4' | 'IPv6';

    /**
     * Port number. The value ranges from 0 to 65535.
     */
    port: number;

    /**
     * Length of the server response message, in bytes.
     */
    size: number;
  }

  export interface UDPSocket {
    /**
     * Binds the IP address and port number. The port number can be specified or randomly allocated by the system.
     *
     * @param address Destination address. {@link NetAddress}
     * @permission ohos.permission.INTERNET
     */
    bind(address: NetAddress, callback: AsyncCallback<void>): void;
    bind(address: NetAddress): Promise<void>;

    /**
     * Sends data over a UDPSocket connection.
     *
     * @param options Optional parameters {@link UDPSendOptions}.
     * @permission ohos.permission.INTERNET
     */
    send(options: UDPSendOptions, callback: AsyncCallback<void>): void;
    send(options: UDPSendOptions): Promise<void>;

    /**
     * Closes a UDPSocket connection.
     * @permission ohos.permission.INTERNET
     */
    close(callback: AsyncCallback<void>): void;
    close(): Promise<void>;

    /**
     * Obtains the status of the UDPSocket connection.
     *
     * @param callback Callback used to return the result. {@link SocketStateBase}.
     * @permission ohos.permission.INTERNET
     */
    getState(callback: AsyncCallback<SocketStateBase>): void;
    getState(): Promise<SocketStateBase>;

    /**
     * Sets other attributes of the UDPSocket connection.
     *
     * @param options Optional parameters {@link UDPExtraOptions}.
     * @permission ohos.permission.INTERNET
     */
    setExtraOptions(options: UDPExtraOptions, callback: AsyncCallback<void>): void;
    setExtraOptions(options: UDPExtraOptions): Promise<void>;

    /**
     * Listens for message receiving events of the UDPSocket connection.
     */
    on(type: 'message', callback: Callback<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}>): void;

    /**
     * Cancels listening for message receiving events of the UDPSocket connection.
     */
    off(type: 'message', callback?: Callback<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}>): void;

    /**
     * Listens for data packet message events or close events of the UDPSocket connection.
     */
    on(type: 'listening' | 'close', callback: Callback<void>): void;

    /**
     * Cancels listening for data packet message events or close events of the UDPSocket connection.
     */
    off(type: 'listening' | 'close', callback?: Callback<void>): void;

    /**
     * Listens for error events of the UDPSocket connection.
     */
    on(type: 'error', callback: ErrorCallback): void;

    /**
     * Cancels listening for error events of the UDPSocket connection.
     */
    off(type: 'error', callback?: ErrorCallback): void;
  }

  export interface TCPConnectOptions {
    /**
     * Bound IP address and port number.
     */
    address: NetAddress;

    /**
     * Timeout duration of the TCPSocket connection, in milliseconds.
     */
    timeout?: number;
  }

  export interface TCPSendOptions {
    /**
     * Data to send.
     */
    data: string | ArrayBuffer;

    /**
     * Character encoding format.
     */
    encoding?: string;
  }

  export interface TCPExtraOptions extends ExtraOptionsBase {
    /**
     * Whether to keep the connection alive. The default value is false.
     */
    keepAlive?: boolean;

    /**
     * Whether to enable OOBInline. The default value is false.
     */
    OOBInline?: boolean;

    /**
     * Whether to enable no-delay on the TCPSocket connection. The default value is false.
     */
    TCPNoDelay?: boolean;

    /**
     * Socket linger.
     */
    socketLinger?: {on: boolean, linger: number};
  }

  export interface TCPSocket {
    /**
     * Binds the IP address and port number. The port number can be specified or randomly allocated by the system.
     *
     * @param address Destination address. {@link NetAddress}
     * @permission ohos.permission.INTERNET
     */
    bind(address: NetAddress, callback: AsyncCallback<void>): void;
    bind(address: NetAddress): Promise<void>;

    /**
     * Sets up a connection to the specified IP address and port number.
     *
     * @param options Optional parameters {@link TCPConnectOptions}.
     * @permission ohos.permission.INTERNET
     */
    connect(options: TCPConnectOptions, callback: AsyncCallback<void>): void;
    connect(options: TCPConnectOptions): Promise<void>;

    /**
     * Sends data over a TCPSocket connection.
     *
     * @param options Optional parameters {@link TCPSendOptions}.
     * @permission ohos.permission.INTERNET
     */
    send(options: TCPSendOptions, callback: AsyncCallback<void>): void;
    send(options: TCPSendOptions): Promise<void>;

    /**
     * Closes a TCPSocket connection.
     * @permission ohos.permission.INTERNET
     */
    close(callback: AsyncCallback<void>): void;
    close(): Promise<void>;

    /**
     * Obtains the peer address of a TCPSocket connection.
     *
     * @param callback Callback used to return the result. {@link NetAddress}
     * @permission ohos.permission.INTERNET
     */
    getRemoteAddress(callback: AsyncCallback<NetAddress>): void;
    getRemoteAddress(): Promise<NetAddress>;

    /**
     * Obtains the status of the TCPSocket connection.
     *
     * @param callback Callback used to return the result. {@link SocketStateBase}
     * @permission ohos.permission.INTERNET
     */
    getState(callback: AsyncCallback<SocketStateBase>): void;
    getState(): Promise<SocketStateBase>;

    /**
     * Sets other attributes of the TCPSocket connection.
     *
     * @param options Optional parameters {@link TCPExtraOptions}.
     * @permission ohos.permission.INTERNET
     */
    setExtraOptions(options: TCPExtraOptions, callback: AsyncCallback<void>): void;
    setExtraOptions(options: TCPExtraOptions): Promise<void>;

    /**
     * Listens for message receiving events of the TCPSocket connection.
     */
    on(type: 'message', callback: Callback<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}>): void;

    /**
     * Cancels listening for message receiving events of the TCPSocket connection.
     */
    off(type: 'message', callback?: Callback<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}>): void;

    /**
     * Listens for connection or close events of the TCPSocket connection.
     */
    on(type: 'connect' | 'close', callback: Callback<void>): void;

    /**
     * Cancels listening for connection or close events of the TCPSocket connection.
     */
    off(type: 'connect' | 'close', callback?: Callback<void>): void;

    /**
     * Listens for error events of the TCPSocket connection.
     */
    on(type: 'error', callback: ErrorCallback): void;

    /**
     * Cancels listening for error events of the TCPSocket connection.
     */
    off(type: 'error', callback?: ErrorCallback): void;
  }

  /**
   * @since 9
   */
  export interface TLSSocket extends TCPSocket {

    /**
     * Returns an object representing a local certificate.
     */
    getCertificate(callback: AsyncCallback<X509CertRawData>): void;
    getCertificate(): Promise<X509CertRawData>;

    /**
     * Returns an object representing the peer certificate. If the peer does not provide a certificate,
     * an empty object will be returned. If the socket is destroyed, null is returned.
     * If needChain is true, it contains the complete certificate chain. Otherwise,
     * it only contains the peer's certificate.
     */
    getRemoteCertificate(callback: AsyncCallback<X509CertRawData>): void;
    getRemoteCertificate(): Promise<X509CertRawData>;

    /**
     * Returns a string containing the negotiated SSL/TLS protocol version of the current connection.
     * For connected sockets that have not completed the handshake process, the value 'unknown' will be returned.
     * Server sockets or disconnected client sockets will return a value of null.
     */
    getProtocol(callback: AsyncCallback<string>): void;
    getProtocol(): Promise<string>;

    /**
     * Returns an object containing the negotiated cipher suite information.
     * For example:{"name": "AES128-SHA256", "standardName": "TLS_RSA_WITH_AES_128_CBC_SHA256", "version": "TLSv1.2"}
     */
    getCipherSuite(callback: AsyncCallback<Array<string>>): void;
    getCipherSuite(): Promise<Array<string>>;

    /**
     * The list of signature algorithms shared between the server and the client, in descending order of priority.
     * @see https://www.openssl.org/docs/man1.1.1/man3/SSL_get_shared_sigalgs.html
     */
    getSignatureAlgorithms(callback: AsyncCallback<Array<string>>): void;
    getSignatureAlgorithms(): Promise<Array<string>>;

    /**
     * @permission ohos.permission.INTERNET
     */
    connect(options: TLSConnectOptions, callback: AsyncCallback<void>): void;
    connect(options: TLSConnectOptions): Promise<void>;

    /**
     * Sends data over a TLSSocket connection.
     *
     * @param data Optional parameters {@link string}.
     * @permission ohos.permission.INTERNET
     */
    send(data: string, callback: AsyncCallback<void>): void;
    send(data: string): Promise<void>;
  }

  /**
   * @since 9
   */
  export interface TLSSecureOptions {
    ca: string | Array<string>;
    cert: string;
    key: string;
    passwd?: string;
    protocols?: Protocol | Array<Protocol>;

    /**
     * default is false, use local cipher.
     */
    useRemoteCipherPrefer?: boolean;

    /**
     * Supported signature algorithms. This list can contain summary algorithms（SHA256、MD5、etc）、
     * Public key algorithm（RSA-PSS、ECDSA、etc）、Combination of the two（For example 'RSA+SHA384'）
     * or TLS v1.3 Scheme name（For example  rsa_pss_pss_sha512）
     */
    signatureAlgorithms?: string;

    /**
     * Crypto suite specification
     */
    cipherSuite?: string;
  }

  /**
   * @since 9
   */
  export interface TLSConnectOptions {
    address: NetAddress;
    secureOptions: TLSSecureOptions;
    checkServerIdentity?: (hostname: string, cert: X509CertRawData) => Error | undefined;

    /**
     * Application layer protocol negotiation extension, supporting HTTP, HTTP/2
     */
    ALPNProtocols?: Array<string>;
  }

  /**
   * @since 9
   */
  export enum Protocol {
    TLSv12 = "TLSv1.2",
    TLSv13 = "TLSv1.3",
  }
}

export default socket;
