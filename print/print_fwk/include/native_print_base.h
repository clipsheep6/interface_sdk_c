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
    /** Support for color printing. */
    bool supportedColorMode;
    /** Array of supported duplex printing modes. */
    uint32_t *supportedDuplexModes;
    /** Number of supported duplex printing mode. */
    uint32_t supportedDuplexModesCount;
    /** Array of supported print paper sizes. */
    Print_PageSize *supportedPageSizes;
    /** Number of supported print paper sizes. */
    uint32_t supportedPageSizesCount;
    /** Array of supported print media types. */
    uint32_t *supportedMediaTypes;
    /** Number of supported print media types. */
    uint32_t supportedMediaTypesCount;
    /** Array of supported print qulities. */
    uint32_t *supportedQualities;
    /** Number of supported print qulities. */
    uint32_t supportedQualitiesCount;
    /** Supported document handling in json format. */
    char *supportedDocumentHandling;
    /** Supported media source in json format. */
    char *supportedMediaSource;
    /** Supported copies. */
    uint32_t supportedCopies;
    /** Default printer resolution. */
    char *supportedResolution;
    /** Array of supported orientation. */
    uint32_t *supportedOrientation;
    /** Number of supported orientation. */
    uint32_t supportedOrientationCount;
    /** advanced capability in json format. */
    char *advanceCapability;
} Print_PrinterCapability;

/**
 * @brief Indicates current properties
 * @since 12
 */
typedef struct {
    /** Default color mode. */
    uint32_t defaultColorMode;
    /** Default sides. */
    uint32_t defaultSides;
    /** Default media type. */
    char *defaultMediaType;
    /** Default media source. */
    char *defaultMediaSource;
    /** Default print quality */
    uint32_t defaultPrintQuality;
    /** Default copies. */
    uint32_t defaultCopies;
    /** Default printer resolution. */
    char *defaultPrinterResolution;
    /** Default orientation. */
    uint32_t defaultOrientation;
    /** Other default values in json format. */
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
    /** Auto paper source mode. */
    PAPER_SOURCE_MODE_AUTO = 6,
    /** Cassette paper source mode. */
    PAPER_SOURCE_MODE_CASSETTE = 11,
    /** Envelope paper source mode. */
    PAPER_SOURCE_MODE_ENVELOPE = 4,
    /** Manual envelope paper source mode. */
    PAPER_SOURCE_MODE_ENVELOPE_MANUAL = 5,
    /** Form source mode. */
    PAPER_SOURCE_MODE_FORM_SOURCE = 12,
    /** Large capacity paper source mode. */
    PAPER_SOURCE_MODE_LARGE_CAPACITY = 10,
    /** Large format paper source mode. */
    PAPER_SOURCE_MODE_LARGE_FORMAT = 9,
    /** Lower paper source mode. */
    PAPER_SOURCE_MODE_LOWER = 1,
    /** Last paper source mode. */
    PAPER_SOURCE_MODE_LAST_PAPER_SOURCE = 13,
    /** Middle paper source mode. */
    PAPER_SOURCE_MODE_MIDDLE = 2,
    /** Manual paper source mode. */
    PAPER_SOURCE_MODE_MANUAL = 3,
    /** Only one paper source mode. */
    PAPER_SOURCE_MODE_ONLY_ONE = 0,
    /** Tractor paper source mode. */
    PAPER_SOURCE_MODE_TRACTOR = 7,
    /** Smarll format paper source mode. */
    PAPER_SOURCE_MODE_SMALL_FORMAT = 8,
    /** Custom paper source mode. */
    PAPER_SOURCE_MODE_CUSTOM_SOURCE = 14,
} PrintJob_PaperSource;

/**
 * @brief Indicates DuplexMode
 * @since 12
 */
typedef enum {
    /** One sided duplex mode. */
    DUPLEX_MODE_ONE_SIDED = 0,
    /** Long edge two sided duplex mode. */
    DUPLEX_MODE_TWO_SIDED_LONG_EDGE = 1,
    /** Short edge two sided duplex mode. */
    DUPLEX_MODE_TWO_SIDED_SHORT_EDGE = 2,
} PrintJob_DuplexMode;

/**
 * @brief Indicates ColorMode
 * @since 12
 */
typedef enum {
    /** Monochrome mode. */
    COLOR_MODE_MONOCHROME = 0,
    /** Color mode. */
    COLOR_MODE_COLOR = 1,
    /** Auto mode. */
    COLOR_MODE_AUTO = 2,
} PrintJob_ColorMode;

/**
 * @brief Indicates OrientationMode
 * @since 12
 */
typedef enum {
    /** Portrait mode. */
    ORIENTATION_MODE_PORTRAIT = 0,
    /** Landscape mode. */
    ORIENTATION_MODE_LANDSCAPE = 1,
} PrintJob_OrientationMode;

/**
 * @brief Indicates PageSize
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
} PrintJob_PageSize;

/**
 * @brief Indicates PageRange
 * @since 12
 */
typedef struct {
    /** Start page. */
    uint32_t startPage;
    /** End page. */
    uint32_t endPage;
    /** Array of pages. */
    uint32_t *pages;
    /** Number of pages. */
    uint32_t pagesCount;
} PrintJob_PageRange;

/**
 * @brief Indicates PrintMargin
 * @since 12
 */
typedef struct {
    /** top margin. */
    uint32_t topMargin;
    /** bottom margin. */
    uint32_t bottomMargin;
    /** left margin. */
    uint32_t leftMargin;
    /** right margin. */
    uint32_t rightMargin;
} PrintJob_PrintMargin;

/**
 * @brief Indicates PrintJob OptionObject.
 * @since 12
 */
typedef struct {
    /** Job name. */
    char *jobName;
    /** Media type. */
    char *mediaType;
    /** Document category. */
    uint32_t documentCategory;
    /** Print quality. */
    char *printQuality;
    /** Printer name. */
    char *printerName;
    /** Printer Uri. */
    char *printerUri;
    /** Document format. */
    char *documentFormat;
    /** Advanced options in json format. */
    char *advanceOptions;
} PrintJob_OptionObject;

/**
 * @brief Indicates PrintJob Structure.
 * @since 12
 */
typedef struct {
    /** Array of file descriptors to print. */
    uint32_t *fdList;
    /** Number of file descriptors to print. */
    uint32_t fdListCount;
    /** Printer id. */
    char *printerId;
    /** Print resolution in dpi. */
    uint32_t dpi;
    /** Number of copies printed. */
    uint32_t copyNumber;
    /** Paper source. */
    PrintJob_PaperSource paperSource;
    /** Paper size. */
    PrintJob_PageSize pageSize;
    /** Color mode. */
    PrintJob_ColorMode colorMode;
    /** Duplex source. */
    PrintJob_DuplexMode duplexMode;
    /** Page range. */
    PrintJob_PageRange pageRange;
    /** Print margin. */
    PrintJob_PrintMargin printMargin;
    /** Orientation mode. */
    PrintJob_OrientationMode orientationMode;
    /** Print option. */
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
