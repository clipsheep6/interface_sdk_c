/*
 * Copyright (c) 2022-2023 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License"),
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
 * the constant for action and entity in the want
 *
 * @namespace wantConstant
 * @syscap SystemCapability.Ability.AbilityBase
 * @since 9
 */
declare namespace wantConstant {
  /**
   * The constant for params of the want
   *
   * @enum { string }
   * @syscap SystemCapability.Ability.AbilityBase
   * @since 9
   */
  export enum Params {
    /**
     * Indicates the param of sandbox flag.
     *
     * @syscap SystemCapability.Ability.AbilityBase
     * @systemapi
     * @since 9
     */
    DLP_PARAMS_SANDBOX = 'ohos.dlp.params.sandbox',

    /**
     * Indicates the param of dlp bundle name.
     *
     * @syscap SystemCapability.Ability.AbilityBase
     * @systemapi
     * @since 9
     */
    DLP_PARAMS_BUNDLE_NAME = 'ohos.dlp.params.bundleName',

    /**
     * Indicates the param of dlp module name.
     *
     * @syscap SystemCapability.Ability.AbilityBase
     * @systemapi
     * @since 9
     */
    DLP_PARAMS_MODULE_NAME = 'ohos.dlp.params.moduleName',

    /**
     * Indicates the param of dlp ability name.
     *
     * @syscap SystemCapability.Ability.AbilityBase
     * @systemapi
     * @since 9
     */
    DLP_PARAMS_ABILITY_NAME = 'ohos.dlp.params.abilityName',

    /**
     * Indicates the param of dlp bundle index.
     *
     * @syscap SystemCapability.Ability.AbilityBase
     * @systemapi
     * @since 9
     */
    DLP_PARAMS_INDEX = 'ohos.dlp.params.index',

    /**
     * Indicates the ability in this want can back to the current top ability even though they are not in the same
     * mission stack.
     *
     * @syscap SystemCapability.Ability.AbilityBase
     * @since 9
     */
    ABILITY_BACK_TO_OTHER_MISSION_STACK = 'ability.params.backToOtherMissionStack',

    /**
     * Indicates the param of ability failure restart recovery identification
     *
     * @syscap SystemCapability.Ability.AbilityBase
     * @since 10
     */
    ABILITY_RECOVERY_RESTART = 'ohos.ability.params.abilityRecoveryRestart',

    /**
     * Indicates the param of extra content title
     *
     * @syscap SystemCapability.Ability.AbilityBase
     * @since 10
     */
    CONTENT_TITLE_KEY = 'ohos.extra.param.key.contentTitle',

    /**
     * Indicates the param of extra shared abstract
     *
     * @syscap SystemCapability.Ability.AbilityBase
     * @since 10
     */
    SHARE_ABSTRACT_KEY = 'ohos.extra.param.key.shareAbstract',

    /**
     * Indicates the param of extra shareURL
     *
     * @syscap SystemCapability.Ability.AbilityBase
     * @since 10
     */
    SHARE_URL_KEY = 'ohos.extra.param.key.shareUrl',

    /**
     * Indicates the param of extra support continue page stack.
     * The default value of the param is true,
     * and the system will automatically flow the page stack information by default.
     *
     * @syscap SystemCapability.Ability.AbilityBase
     * @since 10
     */
    SUPPORT_CONTINUE_PAGE_STACK_KEY = 'ohos.extra.param.key.supportContinuePageStack',

    /**
     * Indicates the param of extra stop source ability on continue.
     * The default value of the param is true,
     * and the system will exit the source application by default.
     *
     * @syscap SystemCapability.Ability.AbilityBase
     * @since 10
     */
    SUPPORT_CONTINUE_SOURCE_EXIT_KEY = 'ohos.extra.param.key.supportContinueSourceExit'
  }

  /**
   * Used to indicate how Want is handled.
   *
   * @enum { number }
   * @syscap SystemCapability.Ability.AbilityBase
   * @since 9
   */
  export enum Flags {
    /**
     * Indicates the grant to perform read operations on the URI.
     *
     * @syscap SystemCapability.Ability.AbilityBase
     * @since 9
     */
    FLAG_AUTH_READ_URI_PERMISSION = 0x00000001,

    /**
     * Indicates the grant to perform write operations on the URI.
     *
     * @syscap SystemCapability.Ability.AbilityBase
     * @since 9
     */
    FLAG_AUTH_WRITE_URI_PERMISSION = 0x00000002,

    /**
     * Indicates the grant for possible persisting on the URI.
     * The flag only valid in PC scenarios.
     * When sharing user file URI,
     * if the application has PERMISSION_PROXY_AUTHORIZATION_URI permission or persistable permission to the URI,
     * it can share persistable URI permission by using this flag.
     * To grant persistable read permissions to URI,
     * you can set flag = FLAG_AUTH_READ_URI_PERMISSION | FLAG_AUTH_PERSISTABLE_URI_PERMISSION.
     * To grant persistable write permissions to URI,
     * you can set flag = FLAG_AUTH_WRITE_URI_PERMISSION | FLAG_AUTH_PERSISTABLE_URI_PERMISSION.
     *
     * @syscap SystemCapability.Ability.AbilityBase
     * @systemapi
     * @since 10
     */
    FLAG_AUTH_PERSISTABLE_URI_PERMISSION = 0x00000040,

    /**
     * Install the specified ability if it's not installed.
     *
     * @syscap SystemCapability.Ability.AbilityBase
     * @since 9
     */
    FLAG_INSTALL_ON_DEMAND = 0x00000800
  }
}

export default wantConstant;
