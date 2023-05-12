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

import { AsyncCallback, Callback } from './@ohos.base';
import Context from './application/BaseContext';
import dataSharePredicates from './@ohos.data.dataSharePredicates';

/**
 * Provides methods for rdbStore create and delete.
 *
 * @namespace relationalStore
 * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
 * @since 9
 */
/**
 * Provides methods for rdbStore create and delete.
 *
 * @namespace relationalStore
 * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
 * @crossplatform
 * @since 10
 */
declare namespace relationalStore {
  /**
   * Records information of the asset.
   *
   * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
   * @since 10
   */
  interface Asset {
    /**
     * The name of asset.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 10
     */
    name: string;

    /**
     * The uri of asset.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 10
     */
    uri: string;

    /**
     * The create time of asset.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 10
     */
    createTime: string;

    /**
     * The modify time of asset.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 10
     */
    modifyTime: string;

    /**
     * The size of asset.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 10
     */
    size: string;
  }

  /**
   * Indicates possible value types
   *
   * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
   * @since 9
   */
  /**
   * Indicates possible value types
   *
   * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
   * @crossplatform
   * @since 10
   */
  type ValueType = null | number | string | boolean | Uint8Array | Asset | Asset[];

  /**
   * Values in buckets are stored in key-value pairs
   *
   * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
   * @since 9
   */
  /**
   * Values in buckets are stored in key-value pairs
   *
   * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
   * @crossplatform
   * @since 10
   */
  type ValuesBucket = { [key: string]: ValueType; }

  /**
   * Manages relational database configurations.
   *
   * @interface StoreConfig
   * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
   * @since 9
   */
  /**
   * Manages relational database configurations.
   *
   * @interface StoreConfig
   * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
   * @crossplatform
   * @since 10
   */
  interface StoreConfig {
    /**
     * The database name.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * The database name.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    name: string;

    /**
     * Specifies the security level of the database.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    securityLevel: SecurityLevel;

    /**
     * Specifies whether the database is encrypted.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    encrypt?: boolean;
  }

  /**
   * The cloud sync progress
   *
   * @enum { number }
   * @syscap SystemCapability.DistributedDataManager.CloudSync.Client
   * @since 10
   */
  enum Progress {
    /**
     * SYNC_BEGIN: means the sync process begin.
     *
     * @syscap SystemCapability.DistributedDataManager.CloudSync.Client
     * @since 10
     */
    SYNC_BEGIN,

    /**
     * SYNC_BEGIN: means the sync process is in progress
     *
     * @syscap SystemCapability.DistributedDataManager.CloudSync.Client
     * @since 10
     */
    SYNC_IN_PROGRESS,

    /**
     * SYNC_BEGIN: means the sync process is finished
     *
     * @syscap SystemCapability.DistributedDataManager.CloudSync.Client
     * @since 10
     */
    SYNC_FINISH
  }

  /**
   * Describes the statistic of the cloud sync process.
   *
   * @interface Statistic
   * @syscap SystemCapability.DistributedDataManager.CloudSync.Client
   * @since 10
   */
  interface Statistic {
    /**
     * Describes the total number of data to sync.
     *
     * @syscap SystemCapability.DistributedDataManager.CloudSync.Client
     * @since 10
     */
    total: number;

    /**
     * Describes the number of successfully synced data.
     *
     * @syscap SystemCapability.DistributedDataManager.CloudSync.Client
     * @since 10
     */
    success: number;

    /**
     * Describes the number of data failed to sync.
     *
     * @syscap SystemCapability.DistributedDataManager.CloudSync.Client
     * @since 10
     */
    failed: number;

    /**
     * Describes the number of data remained to sync.
     *
     * @syscap SystemCapability.DistributedDataManager.CloudSync.Client
     * @since 10
     */
    remained: number;
  }

  /**
   * Describes the {@code Statistic} details of the table.
   *
   * @interface TableDetails
   * @syscap SystemCapability.DistributedDataManager.CloudSync.Client
   * @since 10
   */
  interface TableDetails {
    /**
     * Describes the {@code Statistic} details of the upload process.
     *
     * @enum { number }
     * @syscap SystemCapability.DistributedDataManager.CloudSync.Client
     * @since 10
     */
    upload: Statistic;

    /**
     * Describes the {@code Statistic} details of the download process.
     *
     * @enum { number }
     * @syscap SystemCapability.DistributedDataManager.CloudSync.Client
     * @since 10
     */
    download: Statistic;
  }

  /**
   * Describes detail of the cloud sync {@code Process}.
   *
   * @interface ProgressDetails
   * @syscap SystemCapability.DistributedDataManager.CloudSync.Client
   * @since 10
   */
  interface ProgressDetails {
    /**
     * Describes the status of data sync progress.
     *
     * @syscap SystemCapability.DistributedDataManager.CloudSync.Client
     * @since 10
     */
    schedule: Progress;

    /**
     * Describes the code of data sync progress.
     *
     * @syscap SystemCapability.DistributedDataManager.CloudSync.Client
     * @since 10
     */
    code: number;

    /**
     * The statistic details of the tables.
     *
     * @syscap SystemCapability.DistributedDataManager.CloudSync.Client
     * @since 10
     */
    details: {
      [table: string]: TableDetails;
    };
  }

  /**
   * Describes the {@code RdbStore} type.
   *
   * @enum { number }
   * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
   * @since 9
   */
  enum SecurityLevel {
    /**
     * S1: means the db is low level security
     * There are some low impact, when the data is leaked.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    S1 = 1,

    /**
     * S2: means the db is middle level security
     * There are some major impact, when the data is leaked.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    S2 = 2,

    /**
     * S3: means the db is high level security
     * There are some severity impact, when the data is leaked.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    S3 = 3,

    /**
     * S4: means the db is critical level security
     * There are some critical impact, when the data is leaked.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    S4 = 4
  }

  /**
   * Indicates the database synchronization mode.
   *
   * @enum { number }
   * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
   * @since 9
   */
  /**
   * Indicates the database synchronization mode.
   *
   * @enum { number }
   * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
   * @crossplatform
   * @since 10
   */
  enum SyncMode {
    /**
     * Indicates the data is pushed to remote device from local device.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Indicates the data is pushed to remote device from local device.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    SYNC_MODE_PUSH = 0,

    /**
     * Indicates the data is pulled from remote device to local device.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Indicates the data is pulled from remote device to local device.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    SYNC_MODE_PULL = 1,

    /**
     * Indicates the data is pulled from remote device to local device.
     *
     * @syscap SystemCapability.DistributedDataManager.CloudSync.Client
     * @since 10
     */
    SYNC_MODE_TIME_FIRST,

    /**
     * Indicates force push the native data to the cloud.
     *
     * @syscap SystemCapability.DistributedDataManager.CloudSync.Client
     * @since 10
     */
    SYNC_MODE_NATIVE_FIRST,

    /**
     * Indicates the data is pulled from cloud to local device.
     *
     * @syscap SystemCapability.DistributedDataManager.CloudSync.Client
     * @since 10
     */
    SYNC_MODE_CLOUD_FIRST
  }

  /**
   * Describes the subscription type.
   *
   * @permission ohos.permission.DISTRIBUTED_DATASYNC
   * @enum { number }
   * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
   * @since 9
   */
  enum SubscribeType {
    /**
     * Subscription to remote data changes
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    SUBSCRIBE_TYPE_REMOTE = 0,

    /**
     * Subscription to cloud data changes
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @syscap SystemCapability.DistributedDataManager.CloudSync.Client
     * @since 10
     */
    SUBSCRIBE_TYPE_CLOUD,

    /**
     * Subscription to cloud data changes details
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @syscap SystemCapability.DistributedDataManager.CloudSync.Client
     * @since 10
     */
    SUBSCRIBE_TYPE_CLOUD_DETAILS
  }

  /**
   * Indicates the notify info
   *
   * @syscap SystemCapability.DistributedDataManager.CloudSync.Client
   * @since 10
   */
  interface ChangeInfo {
    /**
     * Indicates the changed table
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 10
     */
    table: string;

    /**
     * Indicates if there is a string primary key, the inserted will keep data's primary keys
     * otherwise it will keep the data's rowid.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 10
     */
    inserted: Array<string> | Array<number>;

    /**
     * Indicates if there is a string primary key, the updated will keep data's primary keys
     * otherwise it will keep the data's rowid.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 10
     */
    updated: Array<string> | Array<number>;

    /**
     * Indicates if there is a string primary key, the deleted will keep data's primary keys
     * otherwise it will keep the data's rowid.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 10
     */
    deleted: Array<string> | Array<number>;
  }

  /**
   * Describes the distribution type of the tables.
   *
   * @permission ohos.permission.DISTRIBUTED_DATASYNC
   * @enum { number }
   * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
   * @since 10
   */
  enum DistributedType {
    /**
     * Indicates the table is distributed among the devices
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 10
     */
    DISTRIBUTED_DEVICE = 0,

    /**
     * Indicates the table is distributed between the cloud and the devices.
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @syscap SystemCapability.DistributedDataManager.CloudSync.Client
     * @since 10
     */
    DISTRIBUTED_CLOUD
  }

  /**
   * Describes the conflict resolutions to insert data into the table.
   *
   * @enum { number }
   * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
   * @crossplatform
   * @since 10
   */
  enum ConflictResolution {
    /**
     * Implements no action when conflict occurs.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    ON_CONFLICT_NONE = 0,

    /**
     * Implements rollback operation when conflict occurs.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    ON_CONFLICT_ROLLBACK = 1,

    /**
     * Implements abort operation when conflict occurs.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    ON_CONFLICT_ABORT = 2,

    /**
     * Implements fail operation when conflict occurs.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    ON_CONFLICT_FAIL = 3,

    /**
     * Implements ignore operation when conflict occurs.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    ON_CONFLICT_IGNORE = 4,

    /**
     * Implements replace operation operator when conflict occurs.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    ON_CONFLICT_REPLACE = 5
  }

  /**
   * Manages relational database configurations.
   *
   * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
   * @since 9
   */
  /**
   * Manages relational database configurations.
   *
   * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
   * @crossplatform
   * @since 10
   */
  class RdbPredicates {
    /**
     * A parameterized constructor used to create a RdbPredicates instance.
     *
     * @param { string } name - indicates the table name of the database.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * A parameterized constructor used to create a RdbPredicates instance.
     *
     * @param { string } name - indicates the table name of the database.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    constructor(name: string);

    /**
     * Specifies remote devices which connect to local device when syncing distributed database.
     * When query database, this function should not be called.
     *
     * @param { Array<string> } devices - indicates specified remote devices.
     * @returns { RdbPredicates } - the {@link RdbPredicates} self.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    inDevices(devices: Array<string>): RdbPredicates;

    /**
     * Specifies all remote devices which connect to local device when syncing distributed database.
     * When query database, this function should not be called.
     *
     * @returns { RdbPredicates } - the {@link RdbPredicates} self.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    inAllDevices(): RdbPredicates;

    /**
     * Configure the RdbPredicates to match the field whose data type is ValueType and value is equal
     * to a specified value.
     * This method is similar to = of the SQL statement.
     *
     * @param { string } field - indicates the column name in the database table.
     * @param { ValueType } value - indicates the value to match with the {@link RdbPredicates}.
     * @returns { RdbPredicates } - the {@link RdbPredicates} self.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Configure the RdbPredicates to match the field whose data type is ValueType and value is equal
     * to a specified value.
     * This method is similar to = of the SQL statement.
     *
     * @param { string } field - indicates the column name in the database table.
     * @param { ValueType } value - indicates the value to match with the {@link RdbPredicates}.
     * @returns { RdbPredicates } - the {@link RdbPredicates} self.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    equalTo(field: string, value: ValueType): RdbPredicates;

    /**
     * Configure the RdbPredicates to match the field whose data type is ValueType and value is not equal to
     * a specified value.
     * This method is similar to != of the SQL statement.
     *
     * @param { string } field - indicates the column name in the database table.
     * @param { ValueType } value - indicates the value to match with the {@link RdbPredicates}.
     * @returns { RdbPredicates } - the {@link RdbPredicates} self.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Configure the RdbPredicates to match the field whose data type is ValueType and value is not equal to
     * a specified value.
     * This method is similar to != of the SQL statement.
     *
     * @param { string } field - indicates the column name in the database table.
     * @param { ValueType } value - indicates the value to match with the {@link RdbPredicates}.
     * @returns { RdbPredicates } - the {@link RdbPredicates} self.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    notEqualTo(field: string, value: ValueType): RdbPredicates;

    /**
     * Adds a left parenthesis to the RdbPredicates.
     * This method is similar to ( of the SQL statement and needs to be used together with endWrap().
     *
     * @returns { RdbPredicates } - the {@link RdbPredicates} with the left parenthesis.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Adds a left parenthesis to the RdbPredicates.
     * This method is similar to ( of the SQL statement and needs to be used together with endWrap().
     *
     * @returns { RdbPredicates } - the {@link RdbPredicates} with the left parenthesis.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    beginWrap(): RdbPredicates;

    /**
     * Adds a right parenthesis to the RdbPredicates.
     * This method is similar to ) of the SQL statement and needs to be used together with beginWrap().
     *
     * @returns { RdbPredicates } - the {@link RdbPredicates} with the right parenthesis.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Adds a right parenthesis to the RdbPredicates.
     * This method is similar to ) of the SQL statement and needs to be used together with beginWrap().
     *
     * @returns { RdbPredicates } - the {@link RdbPredicates} with the right parenthesis.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    endWrap(): RdbPredicates;

    /**
     * Adds an or condition to the RdbPredicates.
     * This method is similar to or of the SQL statement.
     *
     * @returns { RdbPredicates } - the {@link RdbPredicates} with the or condition.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Adds an or condition to the RdbPredicates.
     * This method is similar to or of the SQL statement.
     *
     * @returns { RdbPredicates } - the {@link RdbPredicates} with the or condition.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    or(): RdbPredicates;

    /**
     * Adds an and condition to the RdbPredicates.
     * This method is similar to and of the SQL statement.
     *
     * @returns { RdbPredicates } - the {@link RdbPredicates} with the and condition.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Adds an and condition to the RdbPredicates.
     * This method is similar to and of the SQL statement.
     *
     * @returns { RdbPredicates } - the {@link RdbPredicates} with the and condition.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    and(): RdbPredicates;

    /**
     * Configure the RdbPredicates to match the field whose data type is string and value
     * contains a specified value.
     * This method is similar to contains of the SQL statement.
     *
     * @param { string } field - indicates the column name in the database table.
     * @param { string } value - indicates the value to match with the {@link RdbPredicates}.
     * @returns { RdbPredicates } - the {@link RdbPredicates} self.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Configure the RdbPredicates to match the field whose data type is string and value
     * contains a specified value.
     * This method is similar to contains of the SQL statement.
     *
     * @param { string } field - indicates the column name in the database table.
     * @param { string } value - indicates the value to match with the {@link RdbPredicates}.
     * @returns { RdbPredicates } - the {@link RdbPredicates} self.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    contains(field: string, value: string): RdbPredicates;

    /**
     * Configure the RdbPredicates to match the field whose data type is string and value starts
     * with a specified string.
     * This method is similar to value% of the SQL statement.
     *
     * @param { string } field - indicates the column name in the database table.
     * @param { string } value - indicates the value to match with the {@link RdbPredicates}.
     * @returns { RdbPredicates } - the {@link RdbPredicates} self.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Configure the RdbPredicates to match the field whose data type is string and value starts
     * with a specified string.
     * This method is similar to value% of the SQL statement.
     *
     * @param { string } field - indicates the column name in the database table.
     * @param { string } value - indicates the value to match with the {@link RdbPredicates}.
     * @returns { RdbPredicates } - the {@link RdbPredicates} self.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    beginsWith(field: string, value: string): RdbPredicates;

    /**
     * Configure the RdbPredicates to match the field whose data type is string and value
     * ends with a specified string.
     * This method is similar to %value of the SQL statement.
     *
     * @param { string } field - indicates the column name in the database table.
     * @param { string } value - indicates the value to match with the {@link RdbPredicates}.
     * @returns { RdbPredicates } - the {@link RdbPredicates} self.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Configure the RdbPredicates to match the field whose data type is string and value
     * ends with a specified string.
     * This method is similar to %value of the SQL statement.
     *
     * @param { string } field - indicates the column name in the database table.
     * @param { string } value - indicates the value to match with the {@link RdbPredicates}.
     * @returns { RdbPredicates } - the {@link RdbPredicates} self.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    endsWith(field: string, value: string): RdbPredicates;

    /**
     * Configure the RdbPredicates to match the fields whose value is null.
     * This method is similar to is null of the SQL statement.
     *
     * @param { string } field - indicates the column name in the database table.
     * @returns { RdbPredicates } - the {@link RdbPredicates} self.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Configure the RdbPredicates to match the fields whose value is null.
     * This method is similar to is null of the SQL statement.
     *
     * @param { string } field - indicates the column name in the database table.
     * @returns { RdbPredicates } - the {@link RdbPredicates} self.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    isNull(field: string): RdbPredicates;

    /**
     * Configure the RdbPredicates to match the specified fields whose value is not null.
     * This method is similar to is not null of the SQL statement.
     *
     * @param { string } field - indicates the column name in the database table.
     * @returns { RdbPredicates } - the {@link RdbPredicates} self.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Configure the RdbPredicates to match the specified fields whose value is not null.
     * This method is similar to is not null of the SQL statement.
     *
     * @param { string } field - indicates the column name in the database table.
     * @returns { RdbPredicates } - the {@link RdbPredicates} self.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    isNotNull(field: string): RdbPredicates;

    /**
     * Configure the RdbPredicates to match the fields whose data type is string and value is
     * similar to a specified string.
     * This method is similar to like of the SQL statement.
     *
     * @param { string } field - indicates the column name in the database table.
     * @param { string } value - indicates the value to match with the {@link RdbPredicates}.
     * @returns { RdbPredicates } - the {@link RdbPredicates} that match the specified field.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Configure the RdbPredicates to match the fields whose data type is string and value is
     * similar to a specified string.
     * This method is similar to like of the SQL statement.
     *
     * @param { string } field - indicates the column name in the database table.
     * @param { string } value - indicates the value to match with the {@link RdbPredicates}.
     * @returns { RdbPredicates } - the {@link RdbPredicates} that match the specified field.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    like(field: string, value: string): RdbPredicates;

    /**
     * Configure RdbPredicates to match the specified field whose data type is string and the value contains
     * a wildcard.
     * Different from like, the input parameters of this method are case-sensitive.
     *
     * @param { string } field - indicates the column name in the database table.
     * @param { string } value - indicates the value to match with the {@link RdbPredicates}.
     * @returns { RdbPredicates } - the SQL statement with the specified {@link RdbPredicates}.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Configure RdbPredicates to match the specified field whose data type is string and the value contains
     * a wildcard.
     * Different from like, the input parameters of this method are case-sensitive.
     *
     * @param { string } field - indicates the column name in the database table.
     * @param { string } value - indicates the value to match with the {@link RdbPredicates}.
     * @returns { RdbPredicates } - the SQL statement with the specified {@link RdbPredicates}.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    glob(field: string, value: string): RdbPredicates;

    /**
     * Configure RdbPredicates to match the specified field whose value is within a given range.
     *
     * @param { string } field - indicates the column name.
     * @param { ValueType } low - indicates the minimum value.
     * @param { ValueType } high - indicates the maximum value.
     * @returns { RdbPredicates } - the SQL statement with the specified {@link RdbPredicates}.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Configure RdbPredicates to match the specified field whose value is within a given range.
     *
     * @param { string } field - indicates the column name.
     * @param { ValueType } low - indicates the minimum value.
     * @param { ValueType } high - indicates the maximum value.
     * @returns { RdbPredicates } - the SQL statement with the specified {@link RdbPredicates}.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    between(field: string, low: ValueType, high: ValueType): RdbPredicates;

    /**
     * Configure RdbPredicates to match the specified field whose value is out of a given range.
     *
     * @param { string } field - indicates the column name in the database table.
     * @param { ValueType } low - indicates the minimum value.
     * @param { ValueType } high - indicates the maximum value.
     * @returns { RdbPredicates } - the SQL statement with the specified {@link RdbPredicates}.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Configure RdbPredicates to match the specified field whose value is out of a given range.
     *
     * @param { string } field - indicates the column name in the database table.
     * @param { ValueType } low - indicates the minimum value.
     * @param { ValueType } high - indicates the maximum value.
     * @returns { RdbPredicates } - the SQL statement with the specified {@link RdbPredicates}.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    notBetween(field: string, low: ValueType, high: ValueType): RdbPredicates;

    /**
     * Restricts the value of the field to be greater than the specified value.
     *
     * @param { string } field - indicates the column name in the database table.
     * @param { ValueType } value - indicates the value to match with the {@link RdbPredicates}.
     * @returns { RdbPredicates } - the SQL query statement with the specified {@link RdbPredicates}.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Restricts the value of the field to be greater than the specified value.
     *
     * @param { string } field - indicates the column name in the database table.
     * @param { ValueType } value - indicates the value to match with the {@link RdbPredicates}.
     * @returns { RdbPredicates } - the SQL query statement with the specified {@link RdbPredicates}.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    greaterThan(field: string, value: ValueType): RdbPredicates;

    /**
     * Restricts the value of the field to be smaller than the specified value.
     *
     * @param { string } field - indicates the column name in the database table.
     * @param { ValueType } value - indicates the value to match with the {@link RdbPredicates}.
     * @returns { RdbPredicates } - the SQL query statement with the specified {@link RdbPredicates}.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Restricts the value of the field to be smaller than the specified value.
     *
     * @param { string } field - indicates the column name in the database table.
     * @param { ValueType } value - indicates the value to match with the {@link RdbPredicates}.
     * @returns { RdbPredicates } - the SQL query statement with the specified {@link RdbPredicates}.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    lessThan(field: string, value: ValueType): RdbPredicates;

    /**
     * Restricts the value of the field to be greater than or equal to the specified value.
     *
     * @param { string } field - indicates the column name in the database table.
     * @param { ValueType } value - indicates the value to match with the {@link RdbPredicates}.
     * @returns { RdbPredicates } - the SQL query statement with the specified {@link RdbPredicates}.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Restricts the value of the field to be greater than or equal to the specified value.
     *
     * @param { string } field - indicates the column name in the database table.
     * @param { ValueType } value - indicates the value to match with the {@link RdbPredicates}.
     * @returns { RdbPredicates } - the SQL query statement with the specified {@link RdbPredicates}.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    greaterThanOrEqualTo(field: string, value: ValueType): RdbPredicates;

    /**
     * Restricts the value of the field to be smaller than or equal to the specified value.
     *
     * @param { string } field - indicates the column name in the database table.
     * @param { ValueType } value - indicates the value to match with the {@link RdbPredicates}.
     * @returns { RdbPredicates } - the SQL query statement with the specified {@link RdbPredicates}.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Restricts the value of the field to be smaller than or equal to the specified value.
     *
     * @param { string } field - indicates the column name in the database table.
     * @param { ValueType } value - indicates the value to match with the {@link RdbPredicates}.
     * @returns { RdbPredicates } - the SQL query statement with the specified {@link RdbPredicates}.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    lessThanOrEqualTo(field: string, value: ValueType): RdbPredicates;

    /**
     * Restricts the ascending order of the return list. When there are several orders,
     * the one close to the head has the highest priority.
     *
     * @param { string } field - indicates the column name for sorting the return list.
     * @returns { RdbPredicates } - the SQL query statement with the specified {@link RdbPredicates}.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Restricts the ascending order of the return list. When there are several orders,
     * the one close to the head has the highest priority.
     *
     * @param { string } field - indicates the column name for sorting the return list.
     * @returns { RdbPredicates } - the SQL query statement with the specified {@link RdbPredicates}.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    orderByAsc(field: string): RdbPredicates;

    /**
     * Restricts the descending order of the return list. When there are several orders,
     * the one close to the head has the highest priority.
     *
     * @param { string } field - indicates the column name for sorting the return list.
     * @returns { RdbPredicates } - the SQL query statement with the specified {@link RdbPredicates}.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Restricts the descending order of the return list. When there are several orders,
     * the one close to the head has the highest priority.
     *
     * @param { string } field - indicates the column name for sorting the return list.
     * @returns { RdbPredicates } - the SQL query statement with the specified {@link RdbPredicates}.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    orderByDesc(field: string): RdbPredicates;

    /**
     * Restricts each row of the query result to be unique.
     *
     * @returns { RdbPredicates } - the SQL query statement with the specified {@link RdbPredicates}.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Restricts each row of the query result to be unique.
     *
     * @returns { RdbPredicates } - the SQL query statement with the specified {@link RdbPredicates}.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    distinct(): RdbPredicates;

    /**
     * Restricts the max number of return records.
     *
     * @param { number } value - indicates the max length of the return list.
     * @returns { RdbPredicates } - the SQL query statement with the specified {@link RdbPredicates}.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Restricts the max number of return records.
     *
     * @param { number } value - indicates the max length of the return list.
     * @returns { RdbPredicates } - the SQL query statement with the specified {@link RdbPredicates}.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    limitAs(value: number): RdbPredicates;

    /**
     * Configure RdbPredicates to specify the start position of the returned result.
     * Use this method together with limit(number).
     *
     * @param { number } rowOffset - indicates the start position of the returned result. The value is a positive integer.
     * @returns { RdbPredicates } - the SQL query statement with the specified {@link RdbPredicates}.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Configure RdbPredicates to specify the start position of the returned result.
     * Use this method together with limit(number).
     *
     * @param { number } rowOffset - indicates the start position of the returned result. The value is a positive integer.
     * @returns { RdbPredicates } - the SQL query statement with the specified {@link RdbPredicates}.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    offsetAs(rowOffset: number): RdbPredicates;

    /**
     * Configure RdbPredicates to group query results by specified columns.
     *
     * @param { Array<string> } fields - indicates the specified columns by which query results are grouped.
     * @returns { RdbPredicates } - the SQL query statement with the specified {@link RdbPredicates}.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Configure RdbPredicates to group query results by specified columns.
     *
     * @param { Array<string> } fields - indicates the specified columns by which query results are grouped.
     * @returns { RdbPredicates } - the SQL query statement with the specified {@link RdbPredicates}.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    groupBy(fields: Array<string>): RdbPredicates;

    /**
     * Configure RdbPredicates to specify the index column.
     * Before using this method, you need to create an index column.
     *
     * @param { string } field - indicates the name of the index column.
     * @returns { RdbPredicates } - the SQL statement with the specified {@link RdbPredicates}.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Configure RdbPredicates to specify the index column.
     * Before using this method, you need to create an index column.
     *
     * @param { string } field - indicates the name of the index column.
     * @returns { RdbPredicates } - the SQL statement with the specified {@link RdbPredicates}.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    indexedBy(field: string): RdbPredicates;

    /**
     * Configure RdbPredicates to match the specified field whose data type is ValueType array and values
     * are within a given range.
     *
     * @param { string } field - indicates the column name in the database table.
     * @param { Array<ValueType> } value - indicates the values to match with {@link RdbPredicates}.
     * @returns { RdbPredicates } - the SQL statement with the specified {@link RdbPredicates}.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Configure RdbPredicates to match the specified field whose data type is ValueType array and values
     * are within a given range.
     *
     * @param { string } field - indicates the column name in the database table.
     * @param { Array<ValueType> } value - indicates the values to match with {@link RdbPredicates}.
     * @returns { RdbPredicates } - the SQL statement with the specified {@link RdbPredicates}.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    in(field: string, value: Array<ValueType>): RdbPredicates;

    /**
     * Configure RdbPredicates to match the specified field whose data type is ValueType array and values
     * are out of a given range.
     *
     * @param { string } field - indicates the column name in the database table.
     * @param { Array<ValueType> } value - indicates the values to match with {@link RdbPredicates}.
     * @returns { RdbPredicates } - the SQL statement with the specified {@link RdbPredicates}.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Configure RdbPredicates to match the specified field whose data type is ValueType array and values
     * are out of a given range.
     *
     * @param { string } field - indicates the column name in the database table.
     * @param { Array<ValueType> } value - indicates the values to match with {@link RdbPredicates}.
     * @returns { RdbPredicates } - the SQL statement with the specified {@link RdbPredicates}.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    notIn(field: string, value: Array<ValueType>): RdbPredicates;
  }

  /**
   * Provides methods for accessing a database result set generated by querying the database.
   *
   * @interface ResultSet
   * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
   * @since 9
   */
  /**
   * Provides methods for accessing a database result set generated by querying the database.
   *
   * @interface ResultSet
   * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
   * @crossplatform
   * @since 10
   */
  interface ResultSet {
    /**
     * Obtains the names of all columns in a result set.
     * The column names are returned as a string array, in which the strings are in the same order
     * as the columns in the result set.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Obtains the names of all columns in a result set.
     * The column names are returned as a string array, in which the strings are in the same order
     * as the columns in the result set.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    columnNames: Array<string>;

    /**
     * Obtains the number of columns in the result set.
     * The returned number is equal to the length of the string array returned by the
     * columnNames method.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Obtains the number of columns in the result set.
     * The returned number is equal to the length of the string array returned by the
     * columnNames method.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    columnCount: number;

    /**
     * Obtains the number of rows in the result set.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Obtains the number of rows in the result set.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    rowCount: number;

    /**
     * Obtains the current index of the result set.
     * The result set index starts from 0.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Obtains the current index of the result set.
     * The result set index starts from 0.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    rowIndex: number;

    /**
     * Checks whether the cursor is positioned at the first row.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Checks whether the cursor is positioned at the first row.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    isAtFirstRow: boolean;

    /**
     * Checks whether the cursor is positioned at the last row.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Checks whether the cursor is positioned at the last row.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    isAtLastRow: boolean;

    /**
     * Checks whether the cursor is positioned after the last row.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Checks whether the cursor is positioned after the last row.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    isEnded: boolean;

    /**
     * Checks whether the cursor is positioned before the first row.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Checks whether the cursor is positioned before the first row.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    isStarted: boolean;

    /**
     * Checks whether the current result set is closed.
     * If the result set is closed by calling the close method, true will be returned.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Checks whether the current result set is closed.
     * If the result set is closed by calling the close method, true will be returned.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    isClosed: boolean;

    /**
     * Obtains the column index based on the specified column name.
     * The column name is passed as an input parameter.
     *
     * @param { string } columnName - indicates the name of the specified column in the result set.
     * @returns { number } the index of the specified column.
     * @throws { BusinessError } 14800013 - the column value is null or the column type is incompatible.
     * @throws { BusinessError } 401 - the parameter check failed.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Obtains the column index based on the specified column name.
     * The column name is passed as an input parameter.
     *
     * @param { string } columnName - indicates the name of the specified column in the result set.
     * @returns { number } the index of the specified column.
     * @throws { BusinessError } 14800013 - the column value is null or the column type is incompatible.
     * @throws { BusinessError } 401 - the parameter check failed.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    getColumnIndex(columnName: string): number;

    /**
     * Obtains the column name based on the specified column index.
     * The column index is passed as an input parameter.
     *
     * @param { number } columnIndex - indicates the index of the specified column in the result set.
     * @returns { string } the name of the specified column.
     * @throws { BusinessError } 14800013 - the column value is null or the column type is incompatible.
     * @throws { BusinessError } 401 - parameter error.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Obtains the column name based on the specified column index.
     * The column index is passed as an input parameter.
     *
     * @param { number } columnIndex - indicates the index of the specified column in the result set.
     * @returns { string } the name of the specified column.
     * @throws { BusinessError } 14800013 - the column value is null or the column type is incompatible.
     * @throws { BusinessError } 401 - parameter error.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    getColumnName(columnIndex: number): string;

    /**
     * Go to the specified row of the result set forwards or backwards by an offset relative to its current position.
     * A positive offset indicates moving backwards, and a negative offset indicates moving forwards.
     *
     * @param { number } offset - indicates the offset relative to the current position.
     * @returns { boolean } true if the result set is moved successfully and does not go beyond the range;
     *                   returns false otherwise.
     * @throws { BusinessError } 14800012 - the result set is empty or the specified location is invalid.
     * @throws { BusinessError } 401 - parameter error.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Go to the specified row of the result set forwards or backwards by an offset relative to its current position.
     * A positive offset indicates moving backwards, and a negative offset indicates moving forwards.
     *
     * @param { number } offset - indicates the offset relative to the current position.
     * @returns { boolean } true if the result set is moved successfully and does not go beyond the range;
     *                   returns false otherwise.
     * @throws { BusinessError } 14800012 - the result set is empty or the specified location is invalid.
     * @throws { BusinessError } 401 - parameter error.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    goTo(offset: number): boolean;

    /**
     * Go to the specified row of the result set.
     *
     * @param { number } position - indicates the index of the specified row, which starts from 0.
     * @returns { boolean } true if the result set is moved successfully; returns false otherwise.
     * @throws { BusinessError } 14800012 - the result set is empty or the specified location is invalid.
     * @throws { BusinessError } 401 - parameter error.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Go to the specified row of the result set.
     *
     * @param { number } position - indicates the index of the specified row, which starts from 0.
     * @returns { boolean } true if the result set is moved successfully; returns false otherwise.
     * @throws { BusinessError } 14800012 - the result set is empty or the specified location is invalid.
     * @throws { BusinessError } 401 - parameter error.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    goToRow(position: number): boolean;

    /**
     * Go to the first row of the result set.
     *
     * @returns { boolean } true if the result set is moved successfully;
     *                    returns false otherwise, for example, if the result set is empty.
     * @throws { BusinessError } 14800012 - the result set is empty or the specified location is invalid.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Go to the first row of the result set.
     *
     * @returns { boolean } true if the result set is moved successfully;
     *                    returns false otherwise, for example, if the result set is empty.
     * @throws { BusinessError } 14800012 - the result set is empty or the specified location is invalid.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    goToFirstRow(): boolean;

    /**
     * Go to the last row of the result set.
     *
     * @returns { boolean } true if the result set is moved successfully;
     *                    returns false otherwise, for example, if the result set is empty.
     * @throws { BusinessError } 14800012 - the result set is empty or the specified location is invalid.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Go to the last row of the result set.
     *
     * @returns { boolean } true if the result set is moved successfully;
     *                    returns false otherwise, for example, if the result set is empty.
     * @throws { BusinessError } 14800012 - the result set is empty or the specified location is invalid.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    goToLastRow(): boolean;

    /**
     * Go to the next row of the result set.
     *
     * @returns { boolean } true if the result set is moved successfully;
     *                    returns false otherwise, for example, if the result set is already in the last row.
     * @throws { BusinessError } 14800012 - the result set is empty or the specified location is invalid.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Go to the next row of the result set.
     *
     * @returns { boolean } true if the result set is moved successfully;
     *                    returns false otherwise, for example, if the result set is already in the last row.
     * @throws { BusinessError } 14800012 - the result set is empty or the specified location is invalid.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    goToNextRow(): boolean;

    /**
     * Go to the previous row of the result set.
     *
     * @returns { boolean } true if the result set is moved successfully;
     *                    returns false otherwise, for example, if the result set is already in the first row.
     * @throws { BusinessError } 14800012 - the result set is empty or the specified location is invalid.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Go to the previous row of the result set.
     *
     * @returns { boolean } true if the result set is moved successfully;
     *                    returns false otherwise, for example, if the result set is already in the first row.
     * @throws { BusinessError } 14800012 - the result set is empty or the specified location is invalid.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    goToPreviousRow(): boolean;

    /**
     * Obtains the value of the specified column in the current row as a byte array.
     * The implementation class determines whether to throw an exception if the value of the specified column
     * in the current row is null or the specified column is not of the Blob type.
     *
     * @param { number } columnIndex - indicates the specified column index, which starts from 0.
     * @returns { Uint8Array } the value of the specified column as a byte array.
     * @throws { BusinessError } 14800013 - the column value is null or the column type is incompatible.
     * @throws { BusinessError } 401 - the parameter check failed.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Obtains the value of the specified column in the current row as a byte array.
     * The implementation class determines whether to throw an exception if the value of the specified column
     * in the current row is null or the specified column is not of the Blob type.
     *
     * @param { number } columnIndex - indicates the specified column index, which starts from 0.
     * @returns { Uint8Array } the value of the specified column as a byte array.
     * @throws { BusinessError } 14800013 - the column value is null or the column type is incompatible.
     * @throws { BusinessError } 401 - the parameter check failed.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    getBlob(columnIndex: number): Uint8Array;

    /**
     * Obtains the value of the specified column in the current row as string.
     * The implementation class determines whether to throw an exception if the value of the specified column
     * in the current row is null or the specified column is not of the string type.
     *
     * @param { number } columnIndex - indicates the specified column index, which starts from 0.
     * @returns { string } the value of the specified column as a string.
     * @throws { BusinessError } 14800013 - the column value is null or the column type is incompatible.
     * @throws { BusinessError } 401 - the parameter check failed.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Obtains the value of the specified column in the current row as string.
     * The implementation class determines whether to throw an exception if the value of the specified column
     * in the current row is null or the specified column is not of the string type.
     *
     * @param { number } columnIndex - indicates the specified column index, which starts from 0.
     * @returns { string } the value of the specified column as a string.
     * @throws { BusinessError } 14800013 - the column value is null or the column type is incompatible.
     * @throws { BusinessError } 401 - the parameter check failed.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    getString(columnIndex: number): string;

    /**
     * Obtains the value of the specified column in the current row as long.
     * The implementation class determines whether to throw an exception if the value of the specified column
     * in the current row is null, the specified column is not of the integer type.
     *
     * @param { number } columnIndex - indicates the specified column index, which starts from 0.
     * @returns { number } the value of the specified column as a long.
     * @throws { BusinessError } 14800013 - the column value is null or the column type is incompatible.
     * @throws { BusinessError } 401 - the parameter check failed.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Obtains the value of the specified column in the current row as long.
     * The implementation class determines whether to throw an exception if the value of the specified column
     * in the current row is null, the specified column is not of the integer type.
     *
     * @param { number } columnIndex - indicates the specified column index, which starts from 0.
     * @returns { number } the value of the specified column as a long.
     * @throws { BusinessError } 14800013 - the column value is null or the column type is incompatible.
     * @throws { BusinessError } 401 - the parameter check failed.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    getLong(columnIndex: number): number;

    /**
     * Obtains the value of the specified column in the current row as double.
     * The implementation class determines whether to throw an exception if the value of the specified column
     * in the current row is null, the specified column is not of the double type.
     *
     * @param { number } columnIndex - indicates the specified column index, which starts from 0.
     * @returns { number } the value of the specified column as a double.
     * @throws { BusinessError } 14800013 - the column value is null or the column type is incompatible.
     * @throws { BusinessError } 401 - the parameter check failed.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Obtains the value of the specified column in the current row as double.
     * The implementation class determines whether to throw an exception if the value of the specified column
     * in the current row is null, the specified column is not of the double type.
     *
     * @param { number } columnIndex - indicates the specified column index, which starts from 0.
     * @returns { number } the value of the specified column as a double.
     * @throws { BusinessError } 14800013 - the column value is null or the column type is incompatible.
     * @throws { BusinessError } 401 - the parameter check failed.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    getDouble(columnIndex: number): number;

    /**
     * Checks whether the value of the specified column in the current row is null.
     *
     * @param { number } columnIndex - indicates the specified column index, which starts from 0.
     * @returns { boolean } true if the value of the specified column in the current row is null;
     *                    returns false otherwise.
     * @throws { BusinessError } 14800013 - the column value is null or the column type is incompatible.
     * @throws { BusinessError } 401 - parameter error.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Checks whether the value of the specified column in the current row is null.
     *
     * @param { number } columnIndex - indicates the specified column index, which starts from 0.
     * @returns { boolean } true if the value of the specified column in the current row is null;
     *                    returns false otherwise.
     * @throws { BusinessError } 14800013 - the column value is null or the column type is incompatible.
     * @throws { BusinessError } 401 - parameter error.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    isColumnNull(columnIndex: number): boolean;

    /**
     * Closes the result set.
     * Calling this method on the result set will release all of its resources and makes it ineffective.
     *
     * @throws { BusinessError } 14800012 - the result set is empty or the specified location is invalid.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Closes the result set.
     * Calling this method on the result set will release all of its resources and makes it ineffective.
     *
     * @throws { BusinessError } 14800012 - the result set is empty or the specified location is invalid.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    close(): void;
  }

  /**
   * Provides methods for managing the relational database (RDB).
   * This class provides methods for creating, querying, updating, and deleting RDBs.
   *
   * @interface RdbStore
   * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
   * @since 9
   */
  /**
   * Provides methods for managing the relational database (RDB).
   * This class provides methods for creating, querying, updating, and deleting RDBs.
   *
   * @interface RdbStore
   * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
   * @crossplatform
   * @since 10
   */
  interface RdbStore {
    /**
     * Obtains the RdbStore version. The version number must be an integer greater than 0.
     *
     * @throws { BusinessError } 401 - parameter error.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 10
     */
    /**
     * Obtains the RdbStore version. The version number must be an integer greater than 0.
     *
     * @throws { BusinessError } 401 - parameter error.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    version: number;

    /**
     * Inserts a row of data into the target table.
     *
     * @param { string } table - indicates the target table.
     * @param { ValuesBucket } values - indicates the row of data {@link ValuesBucket} to be inserted into the table.
     * @param { AsyncCallback<number> } callback - the row ID if the operation is successful. returns -1 otherwise.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Inserts a row of data into the target table.
     *
     * @param { string } table - indicates the target table.
     * @param { ValuesBucket } values - indicates the row of data {@link ValuesBucket} to be inserted into the table.
     * @param { AsyncCallback<number> } callback - the row ID if the operation is successful. returns -1 otherwise.
     * @throws { BusinessError } 14800047 - if the WAL file size exceeds the default limit.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    insert(table: string, values: ValuesBucket, callback: AsyncCallback<number>): void;

    /**
     * Inserts a row of data into the target table.
     *
     * @param { string } table - indicates the target table.
     * @param { ValuesBucket } values - indicates the row of data {@link ValuesBucket} to be inserted into the table.
     * @param { ConflictResolution } conflict - indicates the {@link ConflictResolution} to insert data into the table.
     * @param { AsyncCallback<number> } callback - the row ID if the operation is successful. returns -1 otherwise.
     * @throws { BusinessError } 14800047 - if the WAL file size exceeds the default limit.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    insert(table: string, values: ValuesBucket, conflict: ConflictResolution, callback: AsyncCallback<number>): void;

    /**
     * Inserts a row of data into the target table.
     *
     * @param { string } table - indicates the target table.
     * @param { ValuesBucket } values - indicates the row of data {@link ValuesBucket} to be inserted into the table.
     * @returns { Promise<number> } the row ID if the operation is successful. return -1 otherwise.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Inserts a row of data into the target table.
     *
     * @param { string } table - indicates the target table.
     * @param { ValuesBucket } values - indicates the row of data {@link ValuesBucket} to be inserted into the table.
     * @returns { Promise<number> } the row ID if the operation is successful. return -1 otherwise.
     * @throws { BusinessError } 14800047 - if the WAL file size exceeds the default limit.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    insert(table: string, values: ValuesBucket): Promise<number>;

    /**
     * Inserts a row of data into the target table.
     *
     * @param { string } table - indicates the target table.
     * @param { ValuesBucket } values - indicates the row of data {@link ValuesBucket} to be inserted into the table.
     * @param { ConflictResolution } conflict - indicates the {@link ConflictResolution} to insert data into the table.
     * @returns { Promise<number> } the row ID if the operation is successful. return -1 otherwise.
     * @throws { BusinessError } 14800047 - if the WAL file size exceeds the default limit.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    insert(table: string, values: ValuesBucket, conflict: ConflictResolution): Promise<number>;

    /**
     * Inserts a batch of data into the target table.
     *
     * @param { string } table - indicates the target table.
     * @param { Array<ValuesBucket> } values - indicates the rows of data {@link ValuesBucket} to be inserted into the table.
     * @param { AsyncCallback<number> } callback - the number of values that were inserted if the operation is successful. returns -1 otherwise.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Inserts a batch of data into the target table.
     *
     * @param { string } table - indicates the target table.
     * @param { Array<ValuesBucket> } values - indicates the rows of data {@link ValuesBucket} to be inserted into the table.
     * @param { AsyncCallback<number> } callback - the number of values that were inserted if the operation is successful. returns -1 otherwise.
     * @throws { BusinessError } 14800047 - if the WAL file size exceeds the default limit.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    batchInsert(table: string, values: Array<ValuesBucket>, callback: AsyncCallback<number>): void;

    /**
     * Inserts a batch of data into the target table.
     *
     * @param { string } table - indicates the target table.
     * @param { Array<ValuesBucket> } values - indicates the rows of data {@link ValuesBucket} to be inserted into the table.
     * @returns { Promise<number> } the number of values that were inserted if the operation is successful. returns -1 otherwise.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Inserts a batch of data into the target table.
     *
     * @param { string } table - indicates the target table.
     * @param { Array<ValuesBucket> } values - indicates the rows of data {@link ValuesBucket} to be inserted into the table.
     * @returns { Promise<number> } the number of values that were inserted if the operation is successful. returns -1 otherwise.
     * @throws { BusinessError } 14800047 - if the WAL file size exceeds the default limit.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    batchInsert(table: string, values: Array<ValuesBucket>): Promise<number>;

    /**
     * Updates data in the database based on a specified instance object of RdbPredicates.
     *
     * @param { ValuesBucket } values - indicates the row of data to be updated in the database.The key-value pairs are associated with column names of the database table.
     * @param { RdbPredicates } predicates - indicates the specified update condition by the instance object of  {@link RdbPredicates}.
     * @param { AsyncCallback<number> } callback - the number of affected rows.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Updates data in the database based on a specified instance object of RdbPredicates.
     *
     * @param { ValuesBucket } values - indicates the row of data to be updated in the database.The key-value pairs are associated with column names of the database table.
     * @param { RdbPredicates } predicates - indicates the specified update condition by the instance object of  {@link RdbPredicates}.
     * @param { AsyncCallback<number> } callback - the number of affected rows.
     * @throws { BusinessError } 14800047 - if the WAL file size exceeds the default limit.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    update(values: ValuesBucket, predicates: RdbPredicates, callback: AsyncCallback<number>): void;

    /**
     * Updates data in the database based on a specified instance object of RdbPredicates.
     *
     * @param { ValuesBucket } values - indicates the row of data to be updated in the database.The key-value pairs are associated with column names of the database table.
     * @param { RdbPredicates } predicates - indicates the specified update condition by the instance object of  {@link RdbPredicates}.
     * @param { ConflictResolution } conflict - indicates the {@link ConflictResolution} to insert data into the table.
     * @param { AsyncCallback<number> } callback - the number of affected rows.
     * @throws { BusinessError } 14800047 - if the WAL file size exceeds the default limit.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    update(values: ValuesBucket, predicates: RdbPredicates, conflict: ConflictResolution, callback: AsyncCallback<number>): void;

    /**
     * Updates data in the database based on a specified instance object of RdbPredicates.
     *
     * @param { ValuesBucket } values - indicates the row of data to be updated in the database.The key-value pairs are associated with column names of the database table.
     * @param { RdbPredicates } predicates - indicates the specified update condition by the instance object of  {@link RdbPredicates}.
     * @returns { Promise<number> } the number of affected rows.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Updates data in the database based on a specified instance object of RdbPredicates.
     *
     * @param { ValuesBucket } values - indicates the row of data to be updated in the database.The key-value pairs are associated with column names of the database table.
     * @param { RdbPredicates } predicates - indicates the specified update condition by the instance object of  {@link RdbPredicates}.
     * @returns { Promise<number> } the number of affected rows.
     * @throws { BusinessError } 14800047 - if the WAL file size exceeds the default limit.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    update(values: ValuesBucket, predicates: RdbPredicates): Promise<number>;

    /**
     * Updates data in the database based on a specified instance object of RdbPredicates.
     *
     * @param { ValuesBucket } values - indicates the row of data to be updated in the database.The key-value pairs are associated with column names of the database table.
     * @param { RdbPredicates } predicates - indicates the specified update condition by the instance object of  {@link RdbPredicates}.
     * @param { ConflictResolution } conflict - indicates the {@link ConflictResolution} to insert data into the table.
     * @returns { Promise<number> } the number of affected rows.
     * @throws { BusinessError } 14800047 - if the WAL file size exceeds the default limit.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    update(values: ValuesBucket, predicates: RdbPredicates, conflict: ConflictResolution): Promise<number>;

    /**
     * Updates data in the database based on a specified instance object of RdbPredicates.
     *
     * @param { string } table - indicates the target table.
     * @param { ValuesBucket } values - indicates the row of data to be updated in the database.The key-value pairs are associated with column names of the database table.
     * @param { dataSharePredicates.DataSharePredicates } predicates - indicates the specified update condition by the instance object of {@link dataSharePredicates.DataSharePredicates}.
     * @param { AsyncCallback<number> } callback - the number of affected rows.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @throws { BusinessError } 202 - if permission verification failed, application which is not a system application uses system API.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @systemapi
     * @StageModelOnly
     * @since 9
     */
    /**
     * Updates data in the database based on a specified instance object of RdbPredicates.
     *
     * @param { string } table - indicates the target table.
     * @param { ValuesBucket } values - indicates the row of data to be updated in the database.The key-value pairs are associated with column names of the database table.
     * @param { dataSharePredicates.DataSharePredicates } predicates - indicates the specified update condition by the instance object of {@link dataSharePredicates.DataSharePredicates}.
     * @param { AsyncCallback<number> } callback - the number of affected rows.
     * @throws { BusinessError } 14800047 - if the WAL file size exceeds the default limit.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @throws { BusinessError } 202 - if permission verification failed, application which is not a system application uses system API.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @systemapi
     * @StageModelOnly
     * @since 10
     */
    update(table: string, values: ValuesBucket, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback<number>): void;

    /**
     * Updates data in the database based on a specified instance object of RdbPredicates.
     *
     * @param { string } table - indicates the target table.
     * @param { ValuesBucket } values - indicates the row of data to be updated in the database.The key-value pairs are associated with column names of the database table.
     * @param { dataSharePredicates.DataSharePredicates } predicates - indicates the specified update condition by the instance object of {@link dataSharePredicates.DataSharePredicates}.
     * @returns { Promise<number> } the number of affected rows.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @throws { BusinessError } 202 - if permission verification failed, application which is not a system application uses system API.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @systemapi
     * @StageModelOnly
     * @since 9
     */
    /**
     * Updates data in the database based on a specified instance object of RdbPredicates.
     *
     * @param { string } table - indicates the target table.
     * @param { ValuesBucket } values - indicates the row of data to be updated in the database.The key-value pairs are associated with column names of the database table.
     * @param { dataSharePredicates.DataSharePredicates } predicates - indicates the specified update condition by the instance object of {@link dataSharePredicates.DataSharePredicates}.
     * @returns { Promise<number> } the number of affected rows.
     * @throws { BusinessError } 14800047 - if the WAL file size exceeds the default limit.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @throws { BusinessError } 202 - if permission verification failed, application which is not a system application uses system API.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @systemapi
     * @StageModelOnly
     * @since 10
     */
    update(table: string, values: ValuesBucket, predicates: dataSharePredicates.DataSharePredicates): Promise<number>;

    /**
     * Deletes data from the database based on a specified instance object of RdbPredicates.
     *
     * @param { RdbPredicates } predicates - the specified delete condition by the instance object of {@link RdbPredicates}.
     * @param { AsyncCallback<number> } callback - the number of affected rows.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Deletes data from the database based on a specified instance object of RdbPredicates.
     *
     * @param { RdbPredicates } predicates - the specified delete condition by the instance object of {@link RdbPredicates}.
     * @param { AsyncCallback<number> } callback - the number of affected rows.
     * @throws { BusinessError } 14800047 - if the WAL file size exceeds the default limit.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    delete(predicates: RdbPredicates, callback: AsyncCallback<number>): void;

    /**
     * Deletes data from the database based on a specified instance object of RdbPredicates.
     *
     * @param { RdbPredicates } predicates - the specified delete condition by the instance object of {@link RdbPredicates}.
     * @returns { Promise<number> } the number of affected rows.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Deletes data from the database based on a specified instance object of RdbPredicates.
     *
     * @param { RdbPredicates } predicates - the specified delete condition by the instance object of {@link RdbPredicates}.
     * @returns { Promise<number> } return the number of affected rows.
     * @throws { BusinessError } 14800047 - if the WAL file size exceeds the default limit.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    delete(predicates: RdbPredicates): Promise<number>;

    /**
     * Deletes data from the database based on a specified instance object of RdbPredicates.
     *
     * @param { string } table - indicates the target table.
     * @param { dataSharePredicates.DataSharePredicates } predicates - the specified delete condition by the instance object of {@link dataSharePredicates.DataSharePredicates}.
     * @param { AsyncCallback<number> } callback - the number of affected rows.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @throws { BusinessError } 202 - if permission verification failed, application which is not a system application uses system API.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @systemapi
     * @StageModelOnly
     * @since 9
     */
    /**
     * Deletes data from the database based on a specified instance object of RdbPredicates.
     *
     * @param { string } table - indicates the target table.
     * @param { dataSharePredicates.DataSharePredicates } predicates - the specified delete condition by the instance object of {@link dataSharePredicates.DataSharePredicates}.
     * @param { AsyncCallback<number> } callback - the number of affected rows.
     * @throws { BusinessError } 14800047 - if the WAL file size exceeds the default limit.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @throws { BusinessError } 202 - if permission verification failed, application which is not a system application uses system API.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @systemapi
     * @StageModelOnly
     * @since 10
     */
    delete(table: string, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback<number>): void;

    /**
     * Deletes data from the database based on a specified instance object of RdbPredicates.
     *
     * @param { string } table - indicates the target table.
     * @param { dataSharePredicates.DataSharePredicates } predicates - the specified delete condition by the instance object of {@link dataSharePredicates.DataSharePredicates}.
     * @returns { Promise<number> } the number of affected rows.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @throws { BusinessError } 202 - if permission verification failed, application which is not a system application uses system API.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @systemapi
     * @StageModelOnly
     * @since 9
     */
    /**
     * Deletes data from the database based on a specified instance object of RdbPredicates.
     *
     * @param { string } table - indicates the target table.
     * @param { dataSharePredicates.DataSharePredicates } predicates - the specified delete condition by the instance object of {@link dataSharePredicates.DataSharePredicates}.
     * @returns { Promise<number> } the number of affected rows.
     * @throws { BusinessError } 14800047 - if the WAL file size exceeds the default limit.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @throws { BusinessError } 202 - if permission verification failed, application which is not a system application uses system API.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @systemapi
     * @StageModelOnly
     * @since 10
     */
    delete(table: string, predicates: dataSharePredicates.DataSharePredicates): Promise<number>;

    /**
     * Queries data in the database based on specified conditions.
     *
     * @param { RdbPredicates } predicates - the specified query condition by the instance object of {@link RdbPredicates}.
     * @param { AsyncCallback<ResultSet> } callback - the {@link ResultSet} object if the operation is successful.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    query(predicates: RdbPredicates, callback: AsyncCallback<ResultSet>): void;

    /**
     * Queries data in the database based on specified conditions.
     *
     * @param { RdbPredicates } predicates - the specified query condition by the instance object of {@link RdbPredicates}.
     * @param { Array<string> } columns - the columns to query. If the value is empty array, the query applies to all columns.
     * @param { AsyncCallback<ResultSet> } callback - the {@link ResultSet} object if the operation is successful.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Queries data in the database based on specified conditions.
     *
     * @param { RdbPredicates } predicates - the specified query condition by the instance object of {@link RdbPredicates}.
     * @param { Array<string> } columns - the columns to query. If the value is empty array, the query applies to all columns.
     * @param { AsyncCallback<ResultSet> } callback - the {@link ResultSet} object if the operation is successful.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    query(predicates: RdbPredicates, columns: Array<string>, callback: AsyncCallback<ResultSet>): void;

    /**
     * Queries data in the database based on specified conditions.
     *
     * @param { RdbPredicates } predicates - the specified query condition by the instance object of {@link RdbPredicates}.
     * @param { Array<string> } columns - the columns to query. If the value is null, the query applies to all columns.
     * @returns { Promise<ResultSet> } the {@link ResultSet} object if the operation is successful.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Queries data in the database based on specified conditions.
     *
     * @param { RdbPredicates } predicates - the specified query condition by the instance object of {@link RdbPredicates}.
     * @param { Array<string> } columns - the columns to query. If the value is null, the query applies to all columns.
     * @returns { Promise<ResultSet> } the {@link ResultSet} object if the operation is successful.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    query(predicates: RdbPredicates, columns?: Array<string>): Promise<ResultSet>;

    /**
     * Queries data in the database based on specified conditions.
     *
     * @param { string } table - indicates the target table.
     * @param { dataSharePredicates.DataSharePredicates } predicates - the specified query condition by the instance object of {@link dataSharePredicates.DataSharePredicates}.
     * @param { AsyncCallback<ResultSet> } callback - the {@link ResultSet} object if the operation is successful.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @throws { BusinessError } 202 - if permission verification failed, application which is not a system application uses system API.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @systemapi
     * @StageModelOnly
     * @since 10
     */
    query(table: string, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback<ResultSet>): void;

    /**
     * Queries data in the database based on specified conditions.
     *
     * @param { string } table - indicates the target table.
     * @param { dataSharePredicates.DataSharePredicates } predicates - the specified query condition by the instance object of {@link dataSharePredicates.DataSharePredicates}.
     * @param { Array<string> } columns - the columns to query. If the value is empty array, the query applies to all columns.
     * @param { AsyncCallback<ResultSet> } callback - the {@link ResultSet} object if the operation is successful.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @throws { BusinessError } 202 - if permission verification failed, application which is not a system application uses system API.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @systemapi
     * @StageModelOnly
     * @since 9
     */
    query(table: string, predicates: dataSharePredicates.DataSharePredicates, columns: Array<string>, callback: AsyncCallback<ResultSet>): void;

    /**
     * Queries data in the database based on specified conditions.
     *
     * @param { string } table - indicates the target table.
     * @param { dataSharePredicates.DataSharePredicates } predicates - the specified query condition by the instance object of {@link dataSharePredicates.DataSharePredicates}.
     * @param { Array<string> } columns - the columns to query. If the value is null, the query applies to all columns.
     * @returns { Promise<ResultSet> } the {@link ResultSet} object if the operation is successful.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @throws { BusinessError } 202 - if permission verification failed, application which is not a system application uses system API.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @systemapi
     * @StageModelOnly
     * @since 9
     */
    query(table: string, predicates: dataSharePredicates.DataSharePredicates, columns?: Array<string>): Promise<ResultSet>;

    /**
     * Queries data in the database based on SQL statement.
     *
     * @param { string } sql - indicates the SQL statement to execute.
     * @param { AsyncCallback<ResultSet> } callback - the {@link ResultSet} object if the operation is successful.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    querySql(sql: string, callback: AsyncCallback<ResultSet>): void;

    /**
     * Queries data in the database based on SQL statement.
     *
     * @param { string } sql - indicates the SQL statement to execute.
     * @param { Array<ValueType> } bindArgs - indicates the {@link ValueType} values of the parameters in the SQL statement. The values are strings.
     * @param { AsyncCallback<ResultSet> } callback - the {@link ResultSet} object if the operation is successful.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Queries data in the database based on SQL statement.
     *
     * @param { string } sql - indicates the SQL statement to execute.
     * @param { Array<ValueType> } bindArgs - indicates the {@link ValueType} values of the parameters in the SQL statement. The values are strings.
     * @param { AsyncCallback<ResultSet> } callback - the {@link ResultSet} object if the operation is successful.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    querySql(sql: string, bindArgs: Array<ValueType>, callback: AsyncCallback<ResultSet>): void;

    /**
     * Queries data in the database based on SQL statement.
     *
     * @param { string } sql - indicates the SQL statement to execute.
     * @param { Array<ValueType> } bindArgs - indicates the {@link ValueType} values of the parameters in the SQL statement. The values are strings.
     * @returns { Promise<ResultSet> } the {@link ResultSet} object if the operation is successful.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Queries data in the database based on SQL statement.
     *
     * @param { string } sql - indicates the SQL statement to execute.
     * @param { Array<ValueType> } bindArgs - indicates the {@link ValueType} values of the parameters in the SQL statement. The values are strings.
     * @returns { Promise<ResultSet> } the {@link ResultSet} object if the operation is successful.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    querySql(sql: string, bindArgs?: Array<ValueType>): Promise<ResultSet>;

    /**
     * Executes a SQL statement that contains specified parameters but returns no value.
     *
     * @param { string } sql - indicates the SQL statement to execute.
     * @param { AsyncCallback<void> } callback - the callback of executeSql.
     * @throws { BusinessError } 14800047 - if the WAL file size exceeds the default limit.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    executeSql(sql: string, callback: AsyncCallback<void>): void;

    /**
     * Executes a SQL statement that contains specified parameters but returns no value.
     *
     * @param { string } sql - indicates the SQL statement to execute.
     * @param { Array<ValueType> } bindArgs - indicates the {@link ValueType} values of the parameters in the SQL statement. The values are strings.
     * @param { AsyncCallback<void> } callback - the callback of executeSql.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Executes a SQL statement that contains specified parameters but returns no value.
     *
     * @param { string } sql - indicates the SQL statement to execute.
     * @param { Array<ValueType> } bindArgs - indicates the {@link ValueType} values of the parameters in the SQL statement. The values are strings.
     * @param { AsyncCallback<void> } callback - the callback of executeSql.
     * @throws { BusinessError } 14800047 - if the WAL file size exceeds the default limit.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    executeSql(sql: string, bindArgs: Array<ValueType>, callback: AsyncCallback<void>): void;

    /**
     * Executes a SQL statement that contains specified parameters but returns no value.
     *
     * @param { string } sql - indicates the SQL statement to execute.
     * @param { Array<ValueType> } bindArgs - indicates the {@link ValueType} values of the parameters in the SQL statement. The values are strings.
     * @returns { Promise<void> } the promise returned by the function.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Executes a SQL statement that contains specified parameters but returns no value.
     *
     * @param { string } sql - indicates the SQL statement to execute.
     * @param { Array<ValueType> } bindArgs - indicates the {@link ValueType} values of the parameters in the SQL statement. The values are strings.
     * @returns { Promise<void> } the promise returned by the function.
     * @throws { BusinessError } 14800047 - if the WAL file size exceeds the default limit.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    executeSql(sql: string, bindArgs?: Array<ValueType>): Promise<void>;

    /**
     * BeginTransaction before execute your sql.
     *
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * BeginTransaction before execute your sql.
     *
     * @throws { BusinessError } 14800047 - if the WAL file size exceeds the default limit.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    beginTransaction(): void;

    /**
     * Commit the the sql you have executed.
     *
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Commit the the sql you have executed.
     *
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    commit(): void;

    /**
     * Roll back the sql you have already executed.
     *
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Roll back the sql you have already executed.
     *
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    rollBack(): void;

    /**
     * Backs up a database in a specified name.
     *
     * @param { string } destName - indicates the name that saves the database backup.
     * @param { AsyncCallback<void> } callback - the callback of backup.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Backs up a database in a specified name.
     *
     * @param { string } destName - indicates the name that saves the database backup.
     * @param { AsyncCallback<void> } callback - the callback of backup.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    backup(destName: string, callback: AsyncCallback<void>): void;

    /**
     * Backs up a database in a specified name.
     *
     * @param { string } destName - indicates the name that saves the database backup.
     * @returns { Promise<void> } the promise returned by the function.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Backs up a database in a specified name.
     *
     * @param { string } destName - indicates the name that saves the database backup.
     * @returns { Promise<void> } the promise returned by the function.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    backup(destName: string): Promise<void>;

    /**
     * Restores a database from a specified database file.
     *
     * @param { string } srcName - indicates the name that saves the database file.
     * @param { AsyncCallback<void> } callback - the callback of restore.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Restores a database from a specified database file.
     *
     * @param { string } srcName - indicates the name that saves the database file.
     * @param { AsyncCallback<void> } callback - the callback of restore.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    restore(srcName: string, callback: AsyncCallback<void>): void;

    /**
     * Restores a database from a specified database file.
     *
     * @param { string } srcName - indicates the name that saves the database file.
     * @returns { Promise<void> } the promise returned by the function.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    /**
     * Restores a database from a specified database file.
     *
     * @param { string } srcName - indicates the name that saves the database file.
     * @returns { Promise<void> } the promise returned by the function.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @crossplatform
     * @since 10
     */
    restore(srcName: string): Promise<void>;

    /**
     * Set table to be distributed table.
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @param { Array<string> } tables - indicates the tables name you want to set.
     * @param { AsyncCallback<void> } callback - the callback of setDistributedTables.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @throws { BusinessError } 801 - Capability not supported.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    setDistributedTables(tables: Array<string>, callback: AsyncCallback<void>): void;

    /**
     * Set table to be distributed table.
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @param { Array<string> } tables - indicates the tables name you want to set.
     * @returns { Promise<void> } the promise returned by the function.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @throws { BusinessError } 801 - Capability not supported.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    setDistributedTables(tables: Array<string>): Promise<void>;

    /**
     * Set table to be a distributed table.
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @param { Array<string> } tables - indicates the tables name you want to set.
     * @param { number } mode - indicates the distribution type of the tables. {@link DistributedType}.
     * @returns { Promise<void> } the promise returned by the function.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @throws { BusinessError } 202 - if permission verification failed, application does not have permission ohos.permission.DISTRIBUTED_DATASYNC.
     * @throws { BusinessError } 801 - Capability not supported.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 10
     */
    setDistributedTables(tables: Array<string>, type?: number): Promise<void>;

    /**
     * Obtain distributed table name of specified remote device according to local table name.
     * When query remote device database, distributed table name is needed.
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @param { string } device - indicates the remote device.
     * @param { string } table - {string}: the distributed table name.
     * @param { AsyncCallback<string> } callback
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @throws { BusinessError } 801 - Capability not supported.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    obtainDistributedTableName(device: string, table: string, callback: AsyncCallback<string>): void;

    /**
     * Obtain distributed table name of specified remote device according to local table name.
     * When query remote device database, distributed table name is needed.
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @param { string } device - indicates the remote device.
     * @param { string } table
     * @returns { Promise<string> } {string}: the distributed table name.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @throws { BusinessError } 801 - Capability not supported.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    obtainDistributedTableName(device: string, table: string): Promise<string>;

    /**
     * Sync data between devices.
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @param { SyncMode } mode - indicates the database synchronization mode.
     * @param { RdbPredicates } predicates - the specified sync condition by the instance object of {@link RdbPredicates}.
     * @param { AsyncCallback<Array<[string, number]>> } callback - {Array<[string, number]>}: devices sync status array, {string}: device id, {number}: device sync status.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @throws { BusinessError } 801 - Capability not supported.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    sync(mode: SyncMode, predicates: RdbPredicates, callback: AsyncCallback<Array<[string, number]>>): void;

    /**
     * Sync data between devices.
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @param { SyncMode } mode - indicates the database synchronization mode.
     * @param { RdbPredicates } predicates - the specified sync condition by the instance object of {@link RdbPredicates}.
     * @returns { Promise<Array<[string, number]>> } {Array<[string, number]>}: devices sync status array, {string}: device id, {number}: device sync status.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @throws { BusinessError } 801 - Capability not supported.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    sync(mode: SyncMode, predicates: RdbPredicates): Promise<Array<[string, number]>>;

    /**
     * Sync data to cloud.
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @param { number } mode - indicates the database synchronization mode.
     * @param { Callback<ProgressDetails> } progress - the specified sync condition by the instance object of {@link ProgressDetails}.
     * @param { AsyncCallback<void> } callback - {Array<[string, number]>}: devices sync status array, {string}: device id, {number}: device sync status.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @throws { BusinessError } 202 - if permission verification failed, application does not have permission ohos.permission.DISTRIBUTED_DATASYNC.
     * @throws { BusinessError } 801 - Capability not supported.
     * @syscap SystemCapability.DistributedDataManager.CloudSync.Client
     * @since 10
     */
    cloudSync(mode: SyncMode, progress: Callback<ProgressDetails>, callback: AsyncCallback<void>): void;

    /**
     * Sync data to cloud.
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @param { number } mode - indicates the database synchronization mode.
     * @param { Callback<ProgressDetails> } progress - the specified sync condition by the instance object of {@link ProgressDetails}.
     * @returns { Promise<void> } : devices sync status array, {string}: device id, {number}: device sync status.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @throws { BusinessError } 202 - if permission verification failed, application does not have permission ohos.permission.DISTRIBUTED_DATASYNC.
     * @throws { BusinessError } 801 - Capability not supported.
     * @syscap SystemCapability.DistributedDataManager.CloudSync.Client
     * @since 10
     */
    cloudSync(mode: SyncMode, progress: Callback<ProgressDetails>): Promise<void>;

    /**
     * Sync data to cloud.
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @param { number } mode - indicates the database synchronization mode.
     * @param { string[] } tables - indicates the name of tables to sync.
     * @param { Callback<ProgressDetails> } progress - the specified sync condition by the instance object of {@link ProgressDetails}.
     * @param { AsyncCallback<void> } callback - {Array<[string, number]>}: devices sync status array, {string}: device id, {number}: device sync status.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @throws { BusinessError } 202 - if permission verification failed, application does not have permission ohos.permission.DISTRIBUTED_DATASYNC.
     * @throws { BusinessError } 801 - Capability not supported.
     * @syscap SystemCapability.DistributedDataManager.CloudSync.Client
     * @since 10
     */
    cloudSync(mode: SyncMode, tables: string[], progress: Callback<ProgressDetails>, callback: AsyncCallback<void>): void;

    /**
     * Sync data to cloud.
     *
     * @permission ohos.permission.DISTRIBUTED_DATASYNC
     * @param { number } mode - indicates the database synchronization mode.
     * @param { string[] } tables - indicates the name of tables to sync.
     * @param { Callback<ProgressDetails> } progress - the specified sync condition by the instance object of {@link ProgressDetails}.
     * @returns { Promise<void> } : devices sync status array, {string}: device id, {number}: device sync status.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @throws { BusinessError } 202 - if permission verification failed, application does not have permission ohos.permission.DISTRIBUTED_DATASYNC.
     * @throws { BusinessError } 801 - Capability not supported.
     * @syscap SystemCapability.DistributedDataManager.CloudSync.Client
     * @since 10
     */
    cloudSync(mode: SyncMode, tables: string[], progress: Callback<ProgressDetails>): Promise<void>;

    /**
     * Queries remote data in the database based on specified conditions before Synchronizing Data.
     *
     * @param { string } device - indicates specified remote device.
     * @param { string } table - indicates the target table.
     * @param { RdbPredicates } predicates - the specified remote remote query condition by the instance object of {@link RdbPredicates}.
     * @param { Array<string> } columns - the columns to remote query. If the value is empty array, the remote query applies to all columns.
     * @param { AsyncCallback<ResultSet> } callback - the {@link ResultSet} object if the operation is successful.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @throws { BusinessError } 801 - Capability not supported.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    remoteQuery(device: string, table: string, predicates: RdbPredicates, columns: Array<string>, callback: AsyncCallback<ResultSet>): void;

    /**
     * Queries remote data in the database based on specified conditions before Synchronizing Data.
     *
     * @param { string } device - indicates specified remote device.
     * @param { string } table - indicates the target table.
     * @param { RdbPredicates } predicates - the specified remote remote query condition by the instance object of {@link RdbPredicates}.
     * @param { Array<string> } columns - the columns to remote query. If the value is empty array, the remote query applies to all columns.
     * @returns { Promise<ResultSet> } the {@link ResultSet} object if the operation is successful.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @throws { BusinessError } 801 - Capability not supported.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    remoteQuery(device: string, table: string, predicates: RdbPredicates, columns: Array<string>): Promise<ResultSet>;

    /**
     * Registers an observer for the database. When data in the distributed database changes,
     * the callback will be invoked.
     *
     * @param { 'dataChange' } event - indicates the event must be string 'dataChange'.
     * @param { SubscribeType } type - indicates the subscription type, which is defined in {@link SubscribeType}.If its value is SUBSCRIBE_TYPE_REMOTE, ohos.permission.DISTRIBUTED_DATASYNC is required.
     * @param { Callback<Array<string>> } observer - {Array<string>}: the observer of data change events in the distributed database.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @throws { BusinessError } 801 - Capability not supported.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    on(event: 'dataChange', type: SubscribeType, observer: Callback<Array<string>>): void;

    /**
     * Registers an observer for the database. When data in the distributed database changes,
     * the callback will be invoked.
     *
     * @param { 'dataChange' } event - indicates the event must be string 'dataChange'.
     * @param { SubscribeType } type - indicates the subscription type, which is defined in {@link SubscribeType}.If its value is SUBSCRIBE_TYPE_REMOTE, ohos.permission.DISTRIBUTED_DATASYNC is required.
     * @param { Callback<Array<string>> | Callback<Array<ChangeInfo>> } observer - {Array<string>}: the observer of data change events in the distributed database. {Array<ChangeInfo>}: the change info of data change events in the distributed database.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @throws { BusinessError } 202 - if permission verification failed, application does not have permission ohos.permission.DISTRIBUTED_DATASYNC.
     * @throws { BusinessError } 801 - Capability not supported.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 10
     */
    on(event: 'dataChange', type: SubscribeType, observer: Callback<Array<string>> | Callback<Array<ChangeInfo>>): void;

    /**
     * Remove specified observer of specified type from the database.
     *
     * @param { 'dataChange' } event - indicates the event must be string 'dataChange'.
     * @param { SubscribeType } type - indicates the subscription type, which is defined in {@link SubscribeType}.If its value is SUBSCRIBE_TYPE_REMOTE, ohos.permission.DISTRIBUTED_DATASYNC is required.
     * @param { Callback<Array<string>> } observer - {Array<string>}: the data change observer already registered.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @throws { BusinessError } 801 - Capability not supported.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 9
     */
    off(event: 'dataChange', type: SubscribeType, observer: Callback<Array<string>>): void;

    /**
     * Remove specified observer of specified type from the database.
     *
     * @param { 'dataChange' } event - indicates the event must be string 'dataChange'.
     * @param { SubscribeType } type - indicates the subscription type, which is defined in {@link SubscribeType}.
     * If its value is SUBSCRIBE_TYPE_REMOTE, ohos.permission.DISTRIBUTED_DATASYNC is required.
     * @param { Callback<Array<string>> | Callback<Array<ChangeInfo>> } observer - {Array<string>}: the data change observer already registered. {Array<ChangeInfo>}: the change info already registered.
     * @throws { BusinessError } 401 - if the parameter type is incorrect.
     * @throws { BusinessError } 202 - if permission verification failed, application does not have permission ohos.permission.DISTRIBUTED_DATASYNC.
     * @throws { BusinessError } 801 - Capability not supported.
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 10
     */
    off(event: 'dataChange', type: SubscribeType, observer: Callback<Array<string>> | Callback<Array<ChangeInfo>>): void;
  }

  /**
   * Obtains a RDB store.
   * You can set parameters of the RDB store as required. In general, this method is recommended
   * to obtain a rdb store.
   *
   * @param { Context } context - indicates the context of application or capability.
   * @param { StoreConfig } config - indicates the {@link StoreConfig} configuration of the database related to this RDB store.
   * @param { AsyncCallback<RdbStore> } callback - the RDB store {@link RdbStore}.
   * @throws { BusinessError } 401 - if the parameter type is incorrect.
   * @throws { BusinessError } 14800010 - if failed open database by invalid database name.
   * @throws { BusinessError } 14800011 - if failed open database by database corrupted.
   * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
   * @since 9
   */
  /**
   * Obtains a RDB store.
   * You can set parameters of the RDB store as required. In general, this method is recommended
   * to obtain a rdb store.
   *
   * @param { Context } context - indicates the context of application or capability.
   * @param { StoreConfig } config - indicates the {@link StoreConfig} configuration of the database related to this RDB store.
   * @param { AsyncCallback<RdbStore> } callback - the RDB store {@link RdbStore}.
   * @throws { BusinessError } 401 - if the parameter type is incorrect.
   * @throws { BusinessError } 14800010 - if failed open database by invalid database name.
   * @throws { BusinessError } 14800011 - if failed open database by database corrupted.
   * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
   * @crossplatform
   * @since 10
   */
  function getRdbStore(context: Context, config: StoreConfig, callback: AsyncCallback<RdbStore>): void;

  /**
   * Obtains a RDB store.
   * You can set parameters of the RDB store as required. In general, this method is recommended
   * to obtain a rdb store.
   *
   * @param { Context } context - indicates the context of application or capability.
   * @param { StoreConfig } config - indicates the {@link StoreConfig} configuration of the database related to this RDB store.
   * @returns { Promise<RdbStore> } the RDB store {@link RdbStore}.
   * @throws { BusinessError } 401 - if the parameter type is incorrect.
   * @throws { BusinessError } 14800010 - if failed open database by invalid database name.
   * @throws { BusinessError } 14800011 - if failed open database by database corrupted.
   * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
   * @since 9
   */
  /**
   * Obtains a RDB store.
   * You can set parameters of the RDB store as required. In general, this method is recommended
   * to obtain a rdb store.
   *
   * @param { Context } context - indicates the context of application or capability.
   * @param { StoreConfig } config - indicates the {@link StoreConfig} configuration of the database related to this RDB store.
   * @returns { Promise<RdbStore> } the RDB store {@link RdbStore}.
   * @throws { BusinessError } 401 - if the parameter type is incorrect.
   * @throws { BusinessError } 14800010 - if failed open database by invalid database name.
   * @throws { BusinessError } 14800011 - if failed open database by database corrupted.
   * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
   * @crossplatform
   * @since 10
   */
  function getRdbStore(context: Context, config: StoreConfig): Promise<RdbStore>;

  /**
   * Deletes the database with a specified name.
   *
   * @param { Context } context - indicates the context of application or capability.
   * @param { string } name - indicates the database name.
   * @param { AsyncCallback<void> } callback - the callback of deleteRdbStore.
   * @throws { BusinessError } 401 - if the parameter type is incorrect.
   * @throws { BusinessError } 14800010 - if failed delete database by invalid database name.
   * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
   * @since 9
   */
  /**
   * Deletes the database with a specified name.
   *
   * @param { Context } context - indicates the context of application or capability.
   * @param { string } name - indicates the database name.
   * @param { AsyncCallback<void> } callback - the callback of deleteRdbStore.
   * @throws { BusinessError } 401 - if the parameter type is incorrect.
   * @throws { BusinessError } 14800010 - if failed delete database by invalid database name.
   * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
   * @crossplatform
   * @since 10
   */
  function deleteRdbStore(context: Context, name: string, callback: AsyncCallback<void>): void;

  /**
   * Deletes the database with a specified name.
   *
   * @param { Context } context - indicates the context of application or capability.
   * @param { string } name - indicates the database name.
   * @returns { Promise<void> } the promise returned by the function.
   * @throws { BusinessError } 401 - if the parameter type is incorrect.
   * @throws { BusinessError } 14800010 - if failed delete database by invalid database name.
   * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
   * @since 9
   */
  /**
   * Deletes the database with a specified name.
   *
   * @param { Context } context - indicates the context of application or capability.
   * @param { string } name - indicates the database name.
   * @returns { Promise<void> } the promise returned by the function.
   * @throws { BusinessError } 401 - if the parameter type is incorrect.
   * @throws { BusinessError } 14800010 - if failed delete database by invalid database name.
   * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
   * @crossplatform
   * @since 10
   */
  function deleteRdbStore(context: Context, name: string): Promise<void>;

}

export default relationalStore;
