
/*
 * Copyright (c) 2022 Huawei Device Co., Ltd.
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
 * A test case for default tag's order
 * @namespace dataShare
 * @syscap SystemCapability.DistributedDataManager.DataShare.Consumer
 * @since 9
 */
declare namespace dataShare {
  /**
   * @interface DataShareHelperOptions
   * @syscap SystemCapability.DistributedDataManager.DataShare.Consumer
   * @since 10
   */
  interface DataShareHelperOptions {
    /**
     * @syscap SystemCapability.DistributedDataManager.DataShare.Consumer
     * @since 10 
     * @default false
     */
    isProxy?: boolean;
  }
}
