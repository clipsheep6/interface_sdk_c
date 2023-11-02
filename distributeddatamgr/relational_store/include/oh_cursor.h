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

#ifndef OH_CURSOR_H
#define OH_CURSOR_H

/**
 * @addtogroup RDB
 * @{
 *
 * @brief The relational database (RDB) store manages data based on relational models.
 * With the underlying SQLite database, the RDB store provides a complete mechanism for managing local databases.
 * To satisfy different needs in complicated scenarios, the RDB store offers a series of APIs for performing operations
 * such as adding, deleting, modifying, and querying data, and supports direct execution of SQL statements.
 *
 * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
 * @since 10
 */

/**
 * @file oh_cursor.h
 *
 * @brief Provides functions and enumerations related to the resultSet.
 *
 * @since 10
 */

#include <cstdint>
#include <stddef.h>
#include <stdbool.h>
#include "data_asset.h"
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Indicates the column type.
 *
 * @since 10
 */
typedef enum OH_ColumnType {
    /**
     * Indicates the column type is NULL.
     */
    TYPE_NULL = 0,
    /**
     * Indicates the column type is INT64.
     */
    TYPE_INT64,
    /**
     * Indicates the column type is REAL.
     */
    TYPE_REAL,
    /**
     * Indicates the column type is TEXT.
     */
    TYPE_TEXT,
    /**
     * Indicates the column type is BLOB.
     */
    TYPE_BLOB,
    /**
     * Indicates the column type is {@link Data_Asset}.
     *
     * @since 11
     */
    TYPE_ASSET,
    /**
     * Indicates the column type is array of {@link Data_Asset}.
     *
     * @since 11
     */
    TYPE_ASSETS
} OH_ColumnType;

/**
 * @brief Define the OH_Cursor structure type.
 *
 * Provides methods for accessing a database result set generated by query the database.
 *
 * @since 10
 */
typedef struct OH_Cursor {
    /**
     * The id used to uniquely identify the OH_Cursor struct.
     */
    int64_t id;
    /**
     * @brief Function pointer. Obtains the total number of columns.
     *
     * @param cursor Represents a pointer to an {@link OH_Cursor} instance.
     * @param count This parameter is the output parameter, and the number of columns is written to this variable.
     * @return Returns the status code of the execution.
     * @see OH_Cursor.
     * @since 10
     */
    int (*getColumnCount)(OH_Cursor *cursor, int *count);

    /**
     * @brief Function pointer. Obtains data type of the given column's value.
     *
     * @param cursor Represents a pointer to an {@link OH_Cursor} instance.
     * @param columnIndex Indicates the zero-based index of the target column.
     * @param columnType This parameter is the output parameter, and the column value type is written to this variable.
     * @return Returns the status code of the execution.
     * @see OH_Cursor, OH_ColumnType.
     * @since 10
     */
    int (*getColumnType)(OH_Cursor *cursor, int32_t columnIndex, OH_ColumnType *columnType);

    /**
     * @brief Function pointer. Obtains the zero-based index for the given column name.
     *
     * @param cursor Represents a pointer to an {@link OH_Cursor} instance.
     * @param name Indicates the name of the column.
     * @param columnIndex This parameter is the output parameter,
     * and the column index for the given column is written to this variable.
     * @return Returns the status code of the execution.
     * @see OH_Cursor.
     * @since 10
     */
    int (*getColumnIndex)(OH_Cursor *cursor, const char *name, int *columnIndex);

    /**
     * @brief Function pointer. Obtains the column name at the given column index.
     *
     * @param cursor Represents a pointer to an {@link OH_Cursor} instance.
     * @param columnIndex Indicates the zero-based column index.
     * @param name This parameter is the output parameter,
     * and the column name for the given index is written to this variable.
     * @param length Indicates the length of the name.
     * @return Returns the status code of the execution.
     * @see OH_Cursor.
     * @since 10
     */
    int (*getColumnName)(OH_Cursor *cursor, int32_t columnIndex, char *name, int length);

    /**
     * @brief Function pointer. Obtains the numbers of rows in the result set.
     *
     * @param cursor Represents a pointer to an {@link OH_Cursor} instance.
     * @param count This parameter is the output parameter,
     * and the numbers of rows in the result set is written to this variable.
     * @return Returns the status code of the execution.
     * @see OH_Cursor.
     * @since 10
     */
    int (*getRowCount)(OH_Cursor *cursor, int *count);

    /**
     * @brief Function pointer. Move the cursor to the next row.
     *
     * @param cursor Represents a pointer to an {@link OH_Cursor} instance.
     * @return Returns the status code of the execution.
     * @see OH_Cursor.
     * @since 10
     */
    int (*goToNextRow)(OH_Cursor *cursor);

    /**
     * @brief Function pointer. Obtains the size of blob or text.
     *
     * @param cursor Represents a pointer to an {@link OH_Cursor} instance.
     * @param columnIndex Indicates the zero-based column index.
     * @param size This parameter is the output parameter,
     * and the value size of the requested column is written to this variable.
     * @return Returns the status code of the execution.
     * @see OH_Cursor.
     * @since 10
     */
    int (*getSize)(OH_Cursor *cursor, int32_t columnIndex, size_t *size);

    /**
     * @brief Function pointer. Obtains the value of the requested column as a string.
     *
     * @param cursor Represents a pointer to an {@link OH_Cursor} instance.
     * @param columnIndex Indicates the zero-based column index.
     * @param value This parameter is the output parameter,
     * and the value of the requested column as a char * is written to this variable.
     * @param length Indicates the length of the value, it can be obtained through the OH_Cursor_GetSize function.
     * @return Returns the status code of the execution.
     * @see OH_Cursor.
     * @since 10
     */
    int (*getText)(OH_Cursor *cursor, int32_t columnIndex, char *value, int length);

    /**
     * @brief Function pointer. Obtains the value of the requested column as a int64_t.
     *
     * @param cursor Represents a pointer to an {@link OH_Cursor} instance.
     * @param columnIndex Indicates the zero-based column index.
     * @param value This parameter is the output parameter,
     * and the value of the requested column as a int64_t is written to this variable.
     * @return Returns the status code of the execution.
     * @see OH_Cursor.
     * @since 10
     */
    int (*getInt64)(OH_Cursor *cursor, int32_t columnIndex, int64_t *value);

    /**
     * @brief Function pointer. Obtains the value of the requested column as a double.
     *
     * @param cursor Represents a pointer to an {@link OH_Cursor} instance.
     * @param columnIndex Indicates the zero-based column index.
     * @param value This parameter is the output parameter,
     * and the value of the requested column as a double is written to this variable.
     * @return Returns the status code of the execution.
     * @see OH_Cursor.
     * @since 10
     */
    int (*getReal)(OH_Cursor *cursor, int32_t columnIndex, double *value);

    /**
     * @brief Function pointer. Obtains the value of the requested column as a byte array.
     *
     * @param cursor Represents a pointer to an {@link OH_Cursor} instance.
     * @param columnIndex Indicates the zero-based column index.
     * @param value This parameter is the output parameter,
     * and the value of the requested column as a byte array is written to this variable.
     * @param length Indicates the length of the value, it can be obtained through the OH_Cursor_GetSize function.
     * @return Returns the status code of the execution.
     * @see OH_Cursor.
     * @since 10
     */
    int (*getBlob)(OH_Cursor *cursor, int32_t columnIndex, unsigned char *value, int length);

    /**
     * @brief Function pointer. Obtains Whether the value of the requested column is null.
     *
     * @param cursor Represents a pointer to an {@link OH_Cursor} instance.
     * @param columnIndex Indicates the zero-based column index.
     * @param isNull This parameter is the output parameter,
     * and the value whether the column value is null is written to this variable.
     * @return Returns the status code of the execution.
     * @see OH_Cursor.
     * @since 10
     */
    int (*isNull)(OH_Cursor *cursor, int32_t columnIndex, bool *isNull);

    /**
     * @brief Function pointer. Destroy the result set, releasing all of its resources and making it completely invalid.
     *
     * @param cursor Represents a pointer to an {@link OH_Cursor} instance.
     * @return Returns the status code of the execution.
     * @see OH_Cursor.
     * @since 10
     */
    int (*destroy)(OH_Cursor *cursor);

    /**
     * @brief Function pointer. Obtains the value of the requested column as an {@link Data_Asset} instance.
     *
     * @param cursor Represents a pointer to an {@link OH_Cursor} instance.
     * @param columnIndex Indicates the zero-based column index.
     * @param value This parameter is the output parameter,
     * and the value of the requested column as an {@link Data_Asset} instance is written to this variable.
     * @return Returns the status code of the execution.
     * @see OH_Cursor.
     * @since 11
     */
    int (*getAsset)(OH_Cursor *cursor, int32_t columnIndex, Data_Asset *value);

    /**
     * @brief Function pointer. Obtains the value of the requested column as an {@link Data_Asset} instance.
     *
     * @param cursor Represents a pointer to an {@link OH_Cursor} instance.
     * @param columnIndex Indicates the zero-based column index.
     * @param value This parameter is the output parameter,
     * and the value of the requested column as an {@link Data_Asset} instance is written to this variable.
     * @param length Indicates the length of the value.
     * @return Returns the status code of the execution.
     * @see OH_Cursor.
     * @since 11
     */
    int (*getAssets)(OH_Cursor *cursor, int32_t columnIndex, Data_Asset **value, uint32_t *length);

    /**
     * @brief Function pointer. Obtains the count of the {@Data_Asset} in the given column.
     *
     * @param cursor Represents a pointer to an {@link OH_Cursor} instance.
     * @param columnIndex Indicates the zero-based column index.
     * @param count Indicates the count of the assets int the column.
     * @return Returns the status code of the execution.
     * @see OH_Cursor.
     * @since 11
     */
    int (*getAssetsCount)(OH_Cursor *cursor, int32_t columnIndex, uint32_t *count);

} OH_Cursor;

#ifdef __cplusplus
};
#endif

#endif // OH_CURSOR_H
