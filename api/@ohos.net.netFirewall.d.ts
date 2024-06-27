/*
 * Copyright (C) 2024 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @file
 * @kit NetworkKit
 */

/**
 * Provides interfaces to manage net firewall.
 * 
 * @namespace netFirewall
 * @syscap SystemCapability.Communication.NetManager.NetFirewall
 * @since 12
 */
declare namespace netFirewall {
  /**
   * Set firewall policy by userId.
   * <p>Enables or disables the firewall function, and specifies the default actions for inbound connections and
   * outbound connections.</p>
   *
   * @permission ohos.permission.MANAGE_NET_STRATEGY
   * @param { NetFirewallPolicy } policy - The firewall policy to be set.
   * @param { number } userId - Indicates the user ID. It cannot be the ID of a user that does not exist.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 202 - Non-system applications use system APIs.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 2100001 - Invalid parameter value.
   * @throws { BusinessError } 2100002 - Operation failed. Cannot connect to service.
   * @throws { BusinessError } 2100003 - System internal error.
   * @throws { BusinessError } 29400000 - The specified user does not exit.
   * @syscap SystemCapability.Communication.NetManager.NetFirewall
   * @systemapi Hide this for inner system use.
   * @since 12
   */
  function setNetFirewallPolicy(userId: number, policy: NetFirewallPolicy): Promise<void>;

  /**
   * Query firewall policy by userId.
   * 
   * @permission ohos.permission.MANAGE_NET_STRATEGY
   * @param { number } userId - Indicates the user ID. It cannot be the ID of a user that does not exist.
   * @return { NetFirewallPolicy } Current user firewall policy.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 202 - Non-system applications use system APIs.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 2100001 - Invalid parameter value.
   * @throws { BusinessError } 2100002 - Operation failed. Cannot connect to service.
   * @throws { BusinessError } 2100003 - System internal error.
   * @throws { BusinessError } 29400000 - The specified user does not exit.
   * @syscap SystemCapability.Communication.NetManager.NetFirewall
   * @systemapi Hide this for inner system use.
   * @since 12
   */
  function getNetFirewallPolicy(userId: number): Promise<NetFirewallPolicy>;

  /**
   * Add a firewall rule.
   *
   * @permission ohos.permission.MANAGE_NET_STRATEGY
   * @param { NetFirewallRule } rule - Firewall rule.
   * @return { number } ruleId - Indicates the rule ID, generated by the system.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 202 - Non-system applications use system APIs.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 2100001 - Invalid parameter value.
   * @throws { BusinessError } 2100002 - Operation failed. Cannot connect to service.
   * @throws { BusinessError } 2100003 - System internal error.
   * @throws { BusinessError } 29400000 - The specified user does not exit.
   * @throws { BusinessError } 29400001 - The number of firewall rules exceeds the maximum.
   * @throws { BusinessError } 29400002 - The number of IP address rules in the firewall rule exceeds the maximum.
   * @throws { BusinessError } 29400003 - The number of port rules in the firewall rule exceeds the maximum.
   * @throws { BusinessError } 29400004 - The number of domain rules in the firewall rule exceeds the maximum.
   * @throws { BusinessError } 29400005 - The number of domain rules exceeds the maximum.
   * @throws { BusinessError } 29400006 - The specified rule does not exist.
   * @throws { BusinessError } 29400007 - The dns rule is duplication.
   * @syscap SystemCapability.Communication.NetManager.NetFirewall
   * @systemapi Hide this for inner system use.
   * @since 12
   */
  function addNetFirewallRule(rule: NetFirewallRule): Promise<number>;

  /**
   * Update a firewall rule.
   *
   * @permission ohos.permission.MANAGE_NET_STRATEGY
   * @param { NetFirewallRule } rule - Firewall rule.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 202 - Non-system applications use system APIs.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 2100001 - Invalid parameter value.
   * @throws { BusinessError } 2100002 - Operation failed. Cannot connect to service.
   * @throws { BusinessError } 2100003 - System internal error.
   * @throws { BusinessError } 29400000 - The specified user does not exit.
   * @throws { BusinessError } 29400001 - The number of firewall rules exceeds the maximum.
   * @throws { BusinessError } 29400002 - The number of IP address rules in the firewall rule exceeds the maximum.
   * @throws { BusinessError } 29400003 - The number of port rules in the firewall rule exceeds the maximum.
   * @throws { BusinessError } 29400004 - The number of domain rules in the firewall rule exceeds the maximum.
   * @throws { BusinessError } 29400005 - The number of domain rules exceeds the maximum.
   * @throws { BusinessError } 29400006 - The specified rule does not exist.
   * @throws { BusinessError } 29400007 - The dns rule is duplication.
   * @syscap SystemCapability.Communication.NetManager.NetFirewall
   * @systemapi Hide this for inner system use.
   * @since 12
   */
  function updateNetFirewallRule(rule: NetFirewallRule): Promise<void>;

  /**
   * Delete a firewall rule by userId and ruleId.
   *
   * @permission ohos.permission.MANAGE_NET_STRATEGY
   * @param { number } userId - Indicates the user ID. It cannot be the ID of a user that does not exist.
   * @param { number } ruleId - Rule ID.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 202 - Non-system applications use system APIs.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 2100001 - Invalid parameter value.
   * @throws { BusinessError } 2100002 - Operation failed. Cannot connect to service.
   * @throws { BusinessError } 2100003 - System internal error.
   * @throws { BusinessError } 29400000 - The specified user does not exit.
   * @throws { BusinessError } 29400006 - The specified rule does not exist.
   * @syscap SystemCapability.Communication.NetManager.NetFirewall
   * @systemapi Hide this for inner system use.
   * @since 12
   */
  function removeNetFirewallRule(userId: number, ruleId: number): Promise<void>;

  /**
   * Get firewall rules by userId, and it is necessary to specify the pagination query parameters.
   *
   * @permission ohos.permission.MANAGE_NET_STRATEGY
   * @param { number } userId - Indicates the user ID. It cannot be the ID of a user that does not exist.
   * @param { RequestParam } requestParam - Paging query input parameters.
   * @return { FirewallRulePage } Paginated firewall rule list.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 202 - Non-system applications use system APIs.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 2100001 - Invalid parameter value.
   * @throws { BusinessError } 2100002 - Operation failed. Cannot connect to service.
   * @throws { BusinessError } 2100003 - System internal error.
   * @throws { BusinessError } 29400000 - The specified user does not exit.
   * @syscap SystemCapability.Communication.NetManager.NetFirewall
   * @systemapi Hide this for inner system use.
   * @since 12
   */
  function getNetFirewallRules(userId: number, requestParam: RequestParam): Promise<FirewallRulePage>;

  /**
   * Get information about the specified rule ID.
   *
   * @permission ohos.permission.MANAGE_NET_STRATEGY
   * @param { number } userId - Indicates the user ID. It cannot be the ID of a user that does not exist.
   * @param { number } ruleId - Rule ID.
   * @return { NetFirewallRule } Firewall Rule.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 202 - Non-system applications use system APIs.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 2100001 - Invalid parameter value.
   * @throws { BusinessError } 2100002 - Operation failed. Cannot connect to service.
   * @throws { BusinessError } 2100003 - System internal error.
   * @throws { BusinessError } 29400000 - The specified user does not exit.
   * @throws { BusinessError } 29400006 - The specified rule does not exist.
   * @syscap SystemCapability.Communication.NetManager.NetFirewall
   * @systemapi Hide this for inner system use.
   * @since 12
   */
  function getNetFirewallRule(userId: number, ruleId: number): Promise<NetFirewallRule>;

  /**
   * Get interception records by userId, and it is necessary to specify the pagination query parameters.
   *
   * @permission ohos.permission.MANAGE_NET_STRATEGY
   * @param { number } userId - Indicates the user ID. It cannot be the ID of a user that does not exist.
   * @param { RequestParam } requestParam - Paging query input parameters.
   * @return { InterceptRecordPage } Block Record List.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 202 - Non-system applications use system APIs.
   * @throws { BusinessError } 401 - Parameter error.
   * @throws { BusinessError } 2100001 - Invalid parameter value.
   * @throws { BusinessError } 2100002 - Operation failed. Cannot connect to service.
   * @throws { BusinessError } 2100003 - System internal error.
   * @throws { BusinessError } 29400000 - The specified user does not exit.
   * @syscap SystemCapability.Communication.NetManager.NetFirewall
   * @systemapi Hide this for inner system use.
   * @since 12
   */
  function getInterceptRecords(userId: number, requestParam: RequestParam): Promise<InterceptRecordPage>;

  /**
   * Firewall rule direction enumeration.
   *
   * @enum {number}
   * @syscap SystemCapability.Communication.NetManager.NetFirewall
   * @systemapi Hide this for inner system use.
   * @since 12
   */
  enum NetFirewallRuleDirection {
    /**
     * Inbound.
     *
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    RULE_IN = 1,
    /**
     * Outbound.
     *
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    RULE_OUT = 2
  }

  /**
   * Firewall rule behavior enumeration.
   *
   * @enum {number}
   * @syscap SystemCapability.Communication.NetManager.NetFirewall
   * @systemapi Hide this for inner system use.
   * @since 12
   */
  enum FirewallRuleAction {
    /**
     * allow access.
     *
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    RULE_ALLOW = 0,
    /**
     * deny access.
     *
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    RULE_DENY = 1
  }

  /**
   * Indicates the firewall rule type.
   *
   * @enum {number}
   * @syscap SystemCapability.Communication.NetManager.NetFirewall
   * @systemapi Hide this for inner system use.
   * @since 12
   */
  enum NetFirewallRuleType {
    /**
     * IP.
     *
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    RULE_IP = 1,
    /**
     * Domain.
     *
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    RULE_DOMAIN = 2,
    /**
     * DNS.
     *
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    RULE_DNS = 3
  }

  /**
   * Pagination query sorting field.
   *
   * @enum {number}
   * @syscap SystemCapability.Communication.NetManager.NetFirewall
   * @systemapi Hide this for inner system use.
   * @since 12
   */
  enum NetFirewallOrderField {
    /**
     * Sort rule names, only support getAllNetFirewallRules interface calls.
     *
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    ORDER_BY_RULE_NAME = 1,
    /**
     * Sort the recorded time, only support getAllNetFirewallRules interface calls.
     *
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    ORDER_BY_RECORD_TIME = 100,
  }

  /**
   * Pagination query sorting type.
   *
   * @enum {number}
   * @syscap SystemCapability.Communication.NetManager.NetFirewall
   * @systemapi Hide this for inner system use.
   * @since 12
   */
  enum NetFirewallOrderType {
    /**
     * Ascending order.
     *
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    ORDER_ASC = 1,
    /**
     * Descending order.
     *
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    ORDER_DESC = 100,
  }

  /**
   * Firewall policy.
   *
   * @interface NetFirewallPolicy
   * @syscap SystemCapability.Communication.NetManager.NetFirewall
   * @systemapi Hide this for inner system use.
   * @since 12
   */
  interface NetFirewallPolicy {
    /**
     * Whether the firewall is enabled.
     *
     * @type {boolean}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    isOpen: boolean;

    /**
     * Inbound connections are allowed by default or the organization.
     *
     * @type {FirewallRuleAction}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    inAction: FirewallRuleAction;

    /**
     * Outbound connections are allowed by default or the organization.
     *
     * @type {FirewallRuleAction}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    outAction: FirewallRuleAction;
  }

  /**
   * Firewall IP parameters.
   *
   * @interface NetFirewallIpParam
   * @syscap SystemCapability.Communication.NetManager.NetFirewall
   * @systemapi Hide this for inner system use.
   * @since 12
   */
  interface NetFirewallIpParam {
    /**
     * IPv4=1, IPv6=2, default IPv4.
     *
     * @type {?number}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    family?: number;
    /**
     * 1: IP address or subnet, when using a single IP, the mask is 32,2: IP segment.
     *
     * @type {number}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    type: number;
    /**
     * IP address: Valid when type equals 1, otherwise it will be ignored.
     *
     * @type {?string}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    address?: string;
    /**
     * IPv4: subnet mask, IPv6: prefix, Valid when type equals 1, otherwise it will be ignored.
     *
     * @type {?number}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    mask?: number;
    /**
     * Starting IP: Valid when type equals 2, otherwise it will be ignored.
     *
     * @type {?string}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    startIp?: string;
    /**
     * End IP: Valid when type equals 2, otherwise it will be ignored.
     *
     * @type {?string}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    endIp?: string;
  }

  /**
   * Firewall port parameters.
   *
   * @interface NetFirewallPortParam
   * @syscap SystemCapability.Communication.NetManager.NetFirewall
   * @systemapi Hide this for inner system use.
   * @since 12
   */
  interface NetFirewallPortParam {
    /**
     * Starting port, when there is only one port, the starting port is the same as the ending port.
     *
     * @type {number}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    startPort: number;
    /**
     * End port, when there is only one port, the start port is the same as the end port.
     *
     * @type {number}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    endPort: number;
  }

  /**
   * Firewall domain name parameters.
   *
   * @interface NetFirewallDomainParam
   * @syscap SystemCapability.Communication.NetManager.NetFirewall
   * @systemapi Hide this for inner system use.
   * @since 12
   */
  interface NetFirewallDomainParam {
    /**
     * Is there a universal configuration rule.
     *
     * @type {boolean}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    isWildcard: boolean;
    /**
     * domain:When isWildcard is false, the complete domain that needs to be determined;
     * When isWildcard is true, fuzzy domain only support domains like *.huawei.com; *.com.
     *
     * @type {string}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    domain: string;
  }

  /**
   * Firewall DNS parameters.
   *
   * @interface NetFirewallDnsParam
   * @syscap SystemCapability.Communication.NetManager.NetFirewall
   * @systemapi Hide this for inner system use.
   * @since 12
   */
  interface NetFirewallDnsParam {
    /**
     * Primary DNS.
     *
     * @type {string}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    primaryDns: string;
    /**
     * Backup DNS.
     *
     * @type {?string}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    standbyDns?: string;
  }

  /**
   * Firewall rules.
   *
   * @interface NetFirewallRule
   * @syscap SystemCapability.Communication.NetManager.NetFirewall
   * @systemapi Hide this for inner system use.
   * @since 12
   */
  interface NetFirewallRule {
    /**
     * Rule id: When a rule is added to the system, the system generates a rule ID.
     *
     * @type {?number}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    id?: number;
    /**
     * Rule name.
     *
     * @type {string}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    name: string;
    /**
     * Rule description.
     *
     * @type {?string}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    description?: string;
    /**
     * Rule direction, inbound or outbound.
     *
     * @type {NetFirewallRuleDirection}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    direction: NetFirewallRuleDirection;
    /**
     * Rule action.
     *
     * @type {FirewallRuleAction}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    action: FirewallRuleAction;
    /**
     * Rule type.
     *
     * @type {NetFirewallRuleType}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    type: NetFirewallRuleType;
    /**
     * Whether the rule is enabled
     *
     * @type {boolean}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    isEnabled: boolean;
    /**
     * Application or Service UID.
     *
     * @type {?number}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    appUid?: number;
    /**
     * Local IP address: Valid when ruleType = RULE_IP, otherwise it will be ignored.
     *
     * @type {?Array<NetFirewallIpParam>}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    localIps?: Array<NetFirewallIpParam>;
    /**
     * Remote IP address: Valid when ruleType = RULE_IP, otherwise it will be ignored.
     *
     * @type {?Array<NetFirewallIpParam>}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    remoteIps?: Array<NetFirewallIpParam>;
    /**
     * Protocol, ICMPv4: 1, TCP: 6, UDP: 17, ICMPv6:58. Valid when ruleType = RULE_IP, otherwise it will be ignored.
     *
     * @type {?number}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    protocol?: number;
    /**
     * Local Port: Valid when ruleType = RULE_IP, otherwise it will be ignored.
     *
     * @type {?Array<NetFirewallPortParam>}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    localPorts?: Array<NetFirewallPortParam>;
    /**
     * Remote Port: Valid when ruleType = RULE_IP, otherwise it will be ignored.
     *
     * @type {?Array<NetFirewallPortParam>}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    remotePorts?: Array<NetFirewallPortParam>;
    /**
     * Domain Name List: Valid when ruleType = RULE_DOMAIN, otherwise it will be ignored.
     *
     * @type {?Array<NetFirewallDomainParam>}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    domains?: Array<NetFirewallDomainParam>;
    /**
     * DNS: Valid when ruleType = RULE_DNS, otherwise it will be ignored.
     *
     * @type {?NetFirewallDnsParam}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    dns?: NetFirewallDnsParam;
    /**
     * User id.
     *
     * @type {number}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    userId: number;
  }

  /**
   * Interception Record.
   *
   * @interface InterceptRecord
   * @syscap SystemCapability.Communication.NetManager.NetFirewall
   * @systemapi Hide this for inner system use.
   * @since 12
   */
  interface InterceptRecord {
    /**
     * Time stamp.
     *
     * @type {number}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    time: number;
    /**
     * Local IP.
     *
     * @type {?string}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    localIp?: string;
    /**
     * Remote IP.
     *
     * @type {?string}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    remoteIp?: string;
    /**
     * Local Port.
     *
     * @type {?number}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    localPort?: number;
    /**
     * Remote Port.
     *
     * @type {?number}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    remotePort?: number;
    /**
     * Transport Layer Protocol.
     *
     * @type {?number}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    protocol?: number;
    /**
     * Application or Service ID.
     *
     * @type {?number}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    appUid?: number;
    /**
     * Blocked domain name information.
     *
     * @type {?string}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    domain?: string;
  }

  /**
   * Pagination query input parameters.
   *
   * @interface RequestParam
   * @syscap SystemCapability.Communication.NetManager.NetFirewall
   * @systemapi Hide this for inner system use.
   * @since 12
   */
  interface RequestParam {
    /**
     * Page No.: Indicates the page number to be queried.The start value is 1.
     *
     * @type {number}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    page: number;
    /**
     * Page size: Indicates the number of data records to be queried at a time. The maximum value is 50.
     *
     * @type {number}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    pageSize: number;
    /**
     * Sort field.
     *
     * @type {NetFirewallOrderField}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    orderField: NetFirewallOrderField;
    /**
     * Sort Type: Ascending or descending.
     *
     * @type {NetFirewallOrderType}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    orderType: NetFirewallOrderType;
  }

  /**
   * Rule page information.
   *
   * @interface FirewallRulePage
   * @syscap SystemCapability.Communication.NetManager.NetFirewall
   * @systemapi Hide this for inner system use.
   * @since 12
   */
  interface FirewallRulePage {
    /**
     * Current page No.: Indicates the page number of this query.
     *
     * @type {number}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    page: number;
    /**
     * Page size: Maximum number of records on a page for this query.
     *
     * @type {number}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    pageSize: number;
    /**
     * Total pages: Total number of pages.
     *
     * @type {number}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    totalPage: number;
    /**
     * Page data: All records displayed on this page.
     *
     * @type {Array<NetFirewallRule> }
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    data: Array<NetFirewallRule>;
  }

  /**
   * Interception record page information.
   *
   * @interface InterceptRecordPage
   * @syscap SystemCapability.Communication.NetManager.NetFirewall
   * @systemapi Hide this for inner system use.
   * @since 12
   */
  interface InterceptRecordPage {
    /**
     * Current page No.: Indicates the page number of this query.
     *
     * @type {number}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    page: number;
    /**
     * Page size: Maximum number of records on a page for this query.
     *
     * @type {number}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    pageSize: number;
    /**
     * Total pages: Total number of pages.
     *
     * @type {number}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    totalPage: number;
    /**
     * Page data: All records displayed on this page.
     *
     * @type {Array<InterceptRecord>}
     * @syscap SystemCapability.Communication.NetManager.NetFirewall
     * @systemapi Hide this for inner system use.
     * @since 12
     */
    data: Array<InterceptRecord>;
  }
}

export default netFirewall;