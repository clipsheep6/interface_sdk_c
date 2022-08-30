/*
* Copyright (c) 2021 Huawei Device Co., Ltd.
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

import { AsyncCallback } from '../basic';
import ResultSet from '../data/rdb/resultSet';
import { DataAbilityOperation } from './dataAbilityOperation';
import { DataAbilityResult } from './dataAbilityResult';
import dataAbility from '../@ohos.data.dataAbility';
import rdb from '../@ohos.data.rdb';

/**
 * DataAbilityHelper
 * @syscap SystemCapability.Ability.AbilityRuntime.FAModel
 *
 * @since 7
 * @FAModelOnly
 */
export interface DataAbilityHelper {
    /**
     * Opens a file in a specified remote path.
     *
     * @since 7
     * @syscap SystemCapability.Ability.AbilityRuntime.FAModel
     * @param uri Indicates the path of the file to open.
     * @param mode Indicates the file open mode, which can be "r" for read-only access, "w" for write-only access
     *             (erasing whatever data is currently in the file), "wt" for write access that truncates any existing
     *             file, "wa" for write-only access to append to any existing data, "rw" for read and write access on
     *             any existing data, or "rwt" for read and write access that truncates any existing file.
     * @param callback Indicates the callback when openfile success
     * @return Returns the file descriptor.
     * @FAModelOnly
     */
    openFile(uri: string, mode: string, callback: AsyncCallback<number>): void;
    openFile(uri: string, mode: string): Promise<number>;

    /**
     * Registers an observer to observe data specified by the given uri.
     *
     * @since 7
     * @syscap SystemCapability.Ability.AbilityRuntime.FAModel
     * @param type dataChange.
     * @param uri Indicates the path of the data to operate.
     * @param callback Indicates the callback when dataChange.
     * @return -
     * @FAModelOnly
     */
    on(type: 'dataChange', uri: string, callback: AsyncCallback<void>): void;

    /**
     * Deregisters all observers used for monitoring data specified by the given uri.
     *
     * @since 7
     * @syscap SystemCapability.Ability.AbilityRuntime.FAModel
     * @param type dataChange.
     * @param uri Indicates the path of the data to operate.
     * @param callback Indicates the registered callback.
     * @return -
     * @FAModelOnly
     */
    off(type: 'dataChange', uri: string, callback?: AsyncCallback<void>): void;

    /**
     * Obtains the MIME type of the date specified by the given URI.
     *
     * @since 7
     * @syscap SystemCapability.Ability.AbilityRuntime.FAModel
     * @param uri Indicates the path of the data to operate.
     * @return Returns the MIME type that matches the data specified by uri.
     * @FAModelOnly
     */
    getType(uri: string, callback: AsyncCallback<string>): void;
    getType(uri: string): Promise<string>;

    /**
     * Obtains the MIME types of files supported.
     *
     * @since 7
     * @syscap SystemCapability.Ability.AbilityRuntime.FAModel
     * @param uri Indicates the path of the files to obtain.
     * @param mimeTypeFilter Indicates the MIME types of the files to obtain.
     * @return Returns the matched MIME types Array.
     * @FAModelOnly
     */
    getFileTypes(uri: string, mimeTypeFilter: string, callback: AsyncCallback<Array<string>>): void;
    getFileTypes(uri: string, mimeTypeFilter: string): Promise<Array<string>>;

    /**
     * Converts the given uri that refers to the Data ability into a normalized uri.
     *
     * @since 7
     * @syscap SystemCapability.Ability.AbilityRuntime.FAModel
     * @param uri Indicates the uri object to normalize.
     * @return Returns the normalized uri object if the Data ability supports URI normalization or null.
     * @FAModelOnly
     */
    normalizeUri(uri: string, callback: AsyncCallback<string>): void;
    normalizeUri(uri: string): Promise<string>;

    /**
     * Converts the given normalized uri generated by normalizeUri(uri) into a denormalized one.
     *
     * @since 7
     * @syscap SystemCapability.Ability.AbilityRuntime.FAModel
     * @param uri Indicates the uri object to normalize.
     * @return Returns the denormalized uri object if the denormalization is successful.
     * @FAModelOnly
     */
    denormalizeUri(uri: string, callback: AsyncCallback<string>): void;
    denormalizeUri(uri: string): Promise<string>;

    /**
     * Notifies the registered observers of a change to the data resource specified by uri.
     *
     * @since 7
     * @syscap SystemCapability.Ability.AbilityRuntime.FAModel
     * @param uri Indicates the path of the data to operate.
     * @return -
     * @FAModelOnly
     */
    notifyChange(uri: string, callback: AsyncCallback<void>): void;
    notifyChange(uri: string): Promise<void>;

    /**
     * Inserts a single data record into the database.
     *
     * @since 7
     * @syscap SystemCapability.Ability.AbilityRuntime.FAModel
     * @param uri Indicates the path of the data to insert.
     * @param valuesBucket Indicates the data record to insert. If this parameter is null, a blank row will be inserted.
     * @return Returns the index of the inserted data record.
     * @FAModelOnly
     */
    insert(uri: string, valuesBucket: rdb.ValuesBucket, callback: AsyncCallback<number>): void;
    insert(uri: string, valuesBucket: rdb.ValuesBucket): Promise<number>;

    /**
     * Inserts multiple data records into the database.
     *
     * @since 7
     * @syscap SystemCapability.Ability.AbilityRuntime.FAModel
     * @param uri Indicates the path of the data to batchInsert.
     * @param valuesBuckets Indicates the data records to insert.
     * @return Returns the number of data records inserted.
     * @FAModelOnly
     */
    batchInsert(uri: string, valuesBuckets: Array<rdb.ValuesBucket>, callback: AsyncCallback<number>): void;
    batchInsert(uri: string, valuesBuckets: Array<rdb.ValuesBucket>): Promise<number>;

    /**
     * Deletes one or more data records from the database.
     *
     * @since 7
     * @syscap SystemCapability.Ability.AbilityRuntime.FAModel
     * @param uri Indicates the path of the data to delete.
     * @param predicates Indicates filter criteria. You should define the processing logic when this parameter is null.
     * @return Returns the number of data records deleted.
     * @FAModelOnly
     */
    delete(uri: string, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback<number>): void;
    delete(uri: string, predicates?: dataAbility.DataAbilityPredicates): Promise<number>;
    delete(uri: string, callback: AsyncCallback<number>): void;

    /**
     * Updates data records in the database.
     *
     * @since 7
     * @syscap SystemCapability.Ability.AbilityRuntime.FAModel
     * @param uri Indicates the path of data to update.
     * @param valuesBucket Indicates the data to update.
     * @param predicates Indicates filter criteria. You should define the processing logic when this parameter is null.
     * @return Returns the number of data records updated.
     * @FAModelOnly
     */
    update(uri: string, valuesBucket: rdb.ValuesBucket, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback<number>): void;
    update(uri: string, valuesBucket: rdb.ValuesBucket, predicates?: dataAbility.DataAbilityPredicates): Promise<number>;
    update(uri: string, valuesBucket: rdb.ValuesBucket, callback: AsyncCallback<number>): void;

    /**
     * Queries data in the database.
     *
     * @since 7
     * @syscap SystemCapability.Ability.AbilityRuntime.FAModel
     * @param uri Indicates the path of data to query.
     * @param columns Indicates the columns to query. If this parameter is null, all columns are queried.
     * @param predicates Indicates filter criteria. You should define the processing logic when this parameter is null.
     * @return Returns the query result {@link ResultSet}.
     * @FAModelOnly
     */
    query(uri: string, columns: Array<string>, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback<ResultSet>): void;
    query(uri: string, callback: AsyncCallback<ResultSet>): void;
    query(uri: string, columns: Array<string>, callback: AsyncCallback<ResultSet>): void;
    query(uri: string, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback<ResultSet>): void;
    query(uri: string, columns?: Array<string>, predicates?: dataAbility.DataAbilityPredicates): Promise<ResultSet>;

    /**
     * Calls the extended API of the DataAbility. This method uses a promise to return the result.
     *
     * @since 7
     * @syscap SystemCapability.Ability.AbilityRuntime.FAModel
     * @param uri URI of the Data ability. Example: "dataability:///com.example.xxx.xxxx"
     * @param method Indicates the method to call.
     * @param arg Indicates the parameter of the String type.
     * @param extras Indicates the parameter of the PacMap type. 
     * If a custom Sequenceable object is put in the PacMap object and will be transferred across processes,
     * you must call BasePacMap.setClassLoader(ClassLoader) to set a class loader for the custom object.
     * If the PacMap object is to be transferred to a non-OHOS process,
     * values of primitive types are supported, but not custom Sequenceable objects.
     * @return Returns the query result {@link PacMap}.
     * @FAModelOnly
     */
    call(uri: string, method: string, arg: string, extras: PacMap, callback: AsyncCallback<PacMap>): void;
    call(uri: string, method: string, arg: string, extras: PacMap): Promise<PacMap>;

    /**
     * Queries data in the database.
     *
     * @since 7
     * @syscap SystemCapability.Ability.AbilityRuntime.FAModel
     * @param uri Indicates the path of data to query.
     * @param operations Indicates the data operation list, which can contain multiple operations on the database.
     * @return Returns the result of each operation, in array {@link DataAbilityResult}.
     */
     executeBatch(uri: string, operations: Array<DataAbilityOperation>, callback: AsyncCallback<Array<DataAbilityResult>>): void;
     executeBatch(uri: string, operations: Array<DataAbilityOperation>): Promise<Array<DataAbilityResult>>;
}

/**
 * Defines a PacMap object for storing a series of values.
 * @since 7
 * @syscap SystemCapability.Ability.AbilityRuntime.FAModel
 * @FAModelOnly
 */
 export interface PacMap {
  
    /**
     * Indicates the parameter of the PacMap type.
     * If a custom Sequenceable object is put in the PacMap object and will be transferred across processes,
     * you must call BasePacMap.setClassLoader(ClassLoader) to set a class loader for the custom object.
     * If the PacMap object is to be transferred to a non-OHOS process,
     * values of primitive types are supported, but not custom Sequenceable objects.
     * @since 7
     * @syscap SystemCapability.Ability.AbilityRuntime.FAModel
     * @FAModelOnly
     */
     [key: string]: number | string | boolean | Array<string | number | boolean> | null;
}
