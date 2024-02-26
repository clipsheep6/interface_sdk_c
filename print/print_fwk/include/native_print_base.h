/*
 * Copyright (C) 2024 Huawei Device Co., Ltd.
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
 * @addtogroup OH_Print
 * @{
 *
 * @brief Provide the definition of the C interface for the native print module.
 *
 * @syscap SystemCapability.Print.PrintFramework
 *
 * @since 12
 * @version 1.0
 */

/**
 * @file native_print_base.h
 *
 * @brief Declare the native print data types.
 *
 * @library libohprint.so
 * @syscap SystemCapability.Print.PrintFramework
 * @since 12
 * @version 1.0
 */

#ifndef NATIVE_PRINT_BASE_H
#define NATIVE_PRINT_BASE_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defines error codes.
 * @since 12
 * @version 1.0
 */
typedef enum {
    /** The operation is successful. */
    PRINT_ERROR_NONE = 0,
    /** Permission verification failed. */
    PRINT_ERROR_NO_PERMISSION = 201,
    /** Invalid parameter. */
    PRINT_ERROR_INVALID_PARAMETER = 401,
    /** General internal error. */
    PRINT_ERROR_GENERIC_FAILURE = 24300001,
    /** RPC communication error. */
    PRINT_ERROR_RPC_FAILURE = 24300002,
    /** Server error. */
    PRINT_ERROR_SERVER_FAILURE = 24300003,
    /** Invalid extension. */
    PRINT_ERROR_INVALID_EXTENSION = 24300004,
    /** Invalid printer. */
    PRINT_ERROR_INVALID_PRINTER = 24300005,
    /** Invalid print job. */
    PRINT_ERROR_INVALID_PRINT_JOB = 24300006,
    /** Failed to read or write files. */
    PRINT_ERROR_FILE_IO = 24300007,
    /** Unknown error. */
    PRINT_ERROR_UNKNOWN = 24300255,
} Print_ErrorCode;

/**
 * @brief Indicates printer states.
 * @since 12
 */
typedef enum {
    /** Printer idle. */
    PRINTER_IDLE,
    /** Printer busy. */
    PRINTER_BUSY,
    /** Printer not available. */
    PRINTER_UNAVAILABLE,
} Print_PrinterState;

/**
 * @brief Indicate printer discovery events.
 * @since 12
 */
typedef enum {
    /** Printer discovered. */
    PRINTER_DISCOVERED = 0,
    /** Printer lost. */
    PRINTER_LOST = 1,
    /** Printer connecting. */
    PRINTER_CONNECTING = 2,
    /** Printer connected. */
    PRINTER_CONNECTED = 3,
} Print_DiscoveryEvent;

/**
 * @brief Indicate printer change events.
 * @since 12
 */
typedef enum {
    /** Printer added. */
    PRINTER_ADDED = 0,
    /** Printer deleted. */
    PRINTER_DELETED = 1,
    /** Printer state changed. */
    PRINTER_STATE_CHANGED = 2,
    /** Printer info changed. */
    PRINTER_INFO_CHANGED = 3,
} Print_PrinterEvent;

/**
 * @brief Indicates paper size info.
 * @since 12
 */
typedef struct {
    /** Paper id. */
    char *id;
    /** Paper name. */
    char *name;
    /** Paper width. */
    uint32_t width;
    /** Paper height. */
    uint32_t height;
    /** Paper left margin. */
    uint32_t leftMargin;
    /** Paper top margin. */
    uint32_t topMargin;
    /** Paper right margin. */
    uint32_t rightMargin;
    /** Paper bottom margin. */
    uint32_t bottomMargin;
} Print_PageSize;

/**
 * @brief Indicates string list.
 * @since 12
 */
typedef struct {
    /** Number of strings. */
    uint32_t count;
    /** String pointer array */
    char **list;
} Print_StringList;

/**
 * @brief Indicates printer capabilities.
 * @since 12
 */
typedef struct {
    bool supportedColorMode;
    uint32_t *supportedDuplexModes;
    uint32_t supportedDuplexModesCount;
    Print_PageSize *supportedPageSizes;
    uint32_t supportedPageSizesCount;
    uint32_t *supportedMediaTypes;
    uint32_t supportedMediaTypesCount;
    uint32_t *supportedQualities;
    uint32_t supportedQualitiesCount;
    char *supportedDocumentHandling;
    char *supportedMediaSource;
    uint32_t supportedCopies;
    char *supportedResolution;
    uint32_t *supportedOrientation;
    uint32_t supportedOrientationCount;
    char *advanceCapability;
} Print_PrinterCapability;

/**
 * @brief Indicates current properties
 * @since 12
 */
typedef struct {
    uint32_t defaultColorMode;
    uint32_t defaultSides;
    char *defaultMediaType;
    char *defaultMediaSource;
    uint32_t defaultPrintQuality;
    uint32_t defaultCopies;
    char *defaultPrinterResolution;
    uint32_t defaultOrientation;
    char *otherDefaultValues;
} Print_DefaultValue;

/**
 * @brief Indicates printer infomation.
 * @since 12
 */
typedef struct {
    /** Printer state. */
    Print_PrinterState printerState;
    /** Printer capabilities. */
    Print_PrinterCapability capability;
    /** Printer current properties. */
    Print_DefaultValue defaultValue;
    /** Default printer. */
    bool isDefaultPrinter;
    /** Printer id. */
    char *printerId;
    /** Printer name. */
    char *printerName;
    /** Printer description. */
    char *description;
    /** Printer location. */
    char *location;
    /** Printer make and model infomation. */
    char *makeAndModel;
    /** Printer Uri. */
    char *printerUri;
    /** Detail infomation in json format. */
    char *detailInfo;
} Print_PrinterInfo;

/**
 * @brief Indicates printer property.
 * @since 12
 */
typedef struct {
    /** Property keyword */
    char *key;
    /** Property value. */
    char *value;
} Print_Property;

/**
 * @brief List of printer properties.
 * @since 12
 */
typedef struct {
    /** Number of properties. */
    uint32_t count;
    /** Property pointer array. */
    Print_Property *list;
} Print_PropertyList;

/**
 * @brief Indicates PaperSource Mode.
 * @since 12
 */
typedef enum {
    OH_PAPERSOURCE_MODE_AUTO = 6,
    OH_PAPERSOURCE_MODE_CASSETTE = 11,
    OH_PAPERSOURCE_MODE_ENVELOPE = 4,
    OH_PAPERSOURCE_MODE_ENVELOPE_MANUAL = 5,
    OH_PAPERSOURCE_MODE_FORM_SOURCE = 12,
    OH_PAPERSOURCE_MODE_LARGE_CAPACITY = 10,
    OH_PAPERSOURCE_MODE_LARGE_FORMAT = 9,
    OH_PAPERSOURCE_MODE_LOWER = 1,
    OH_PAPERSOURCE_MODE_LAST_PAPER_SOURCE = 13,
    OH_PAPERSOURCE_MODE_MIDDLE = 2,
    OH_PAPERSOURCE_MODE_MANUAL = 3,
    OH_PAPERSOURCE_MODE_ONLY_ONE = 0,
    OH_PAPERSOURCE_MODE_TRACTOR = 7,
    OH_PAPERSOURCE_MODE_SMALL_FORMAT = 8,
    OH_PAPERSOURCE_MODE_CUSTOM_SOURCE = 14,
} PrintJob_PaperSource;

/**
 * @brief Indicates DuplexMode
 * @since 12
 */
typedef enum {
    OH_DUPLEX_MODE_ONE_SIDED = 0,
    OH_DUPLEX_MODE_TWO_SIDED_LONG_EDGE = 1,
    OH_DUPLEX_MODE_TWO_SIDED_SHORT_EDGE = 2,
} PrintJob_DuplexMode;

/**
 * @brief Indicates ColorMode
 * @since 12
 */
typedef enum {
    OH_COLOR_MODE_MONOCHROME = 0,
    OH_COLOR_MODE_COLOR = 1,
    OH_COLOR_MODE_AUTO = 2,
} PrintJob_ColorMode;

/**
 * @brief Indicates OrientationMode
 * @since 12
 */
typedef enum {
    OH_ORIENTATION_MODE_PORTRAIT = 0,
    OH_ORIENTATION_MODE_LANDSCAPE = 1,
} PrintJob_OrientationMode;

/**
 * @brief Indicates PageSize
 * @since 12
 */
typedef struct {
    char *id;
    char *name;
    uint32_t width;
    uint32_t height;
} PrintJob_PageSize;

/**
 * @brief Indicates PageRange
 * @since 12
 */
typedef struct {
    uint32_t startPage;
    uint32_t endPage;
    uint32_t *pages;
    uint32_t pagesCount;
} PrintJob_PageRange;

/**
 * @brief Indicates PrintMargin
 * @since 12
 */
typedef struct {
    uint32_t topMargin;
    uint32_t bottomMargin;
    uint32_t leftMargin;
    uint32_t rightMargin;
} PrintJob_PrintMargin;

/**
 * @brief Indicates PrintJob OptionObject.
 * @since 12
 */
typedef struct {
    char *jobName;
    char *mediaType;
    uint32_t documentCategory;
    char *printQuality;
    char *printerName;
    char *printerUri;
    char *documentFormat;
    char *advanceOptions;
} PrintJob_OptionObject;

/**
 * @brief Indicates PrintJob Structure.
 * @since 12
 */
typedef struct {
    uint32_t *fdList;
    uint32_t fdListCount;
    char *printerId;
    uint32_t dpi;
    uint32_t copyNumber;
    PrintJob_PaperSource paperSource;
    PrintJob_PageSize pageSize;
    PrintJob_ColorMode colorMode;
    PrintJob_DuplexMode duplexMode;
    PrintJob_PageRange pageRange;
    PrintJob_PrintMargin printMargin;
    PrintJob_OrientationMode orientationMode;
    PrintJob_OptionObject printOption;
} Print_PrintJob;

/**
 * @brief Printer change callback.
 * @since 12
 */
typedef void (*Print_PrinterChangeCallback)(uint32_t event, const Print_PrinterInfo *printerInfo);

#ifdef __cplusplus
}
#endif

#endif // NATIVE_PRINT_BASE_H
/** @} */
