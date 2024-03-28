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
 * @brief Provide the definition of the C interface for the print module.
 *
 * @syscap SystemCapability.Print.PrintFramework
 *
 * @since 12
 * @version 1.0
 */

/**
 * @file print_base.h
 *
 * @brief Declare the print data types.
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
 *
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
 *
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
 *
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
 *
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
 * @brief Indicates string list.
 *
 * @since 12
 */
typedef struct {
    /** Number of strings. */
    uint32_t count;
    /** String pointer array */
    char **list;
} Print_StringList;

/**
 * @brief Indicates printer property.
 *
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
 *
 * @since 12
 */
typedef struct {
    /** Number of properties. */
    uint32_t count;
    /** Property pointer array. */
    Print_Property *list;
} Print_PropertyList;

/**
 * @brief Indicates print resolution in dpi unit.
 *
 * @since 12
 */
typedef struct {
    uint32_t horizontalDpi;
    uint32_t verticalDpi;
} Print_Resolution;

/**
 * @brief Indicates printing margin
 *
 * @since 12
 */
typedef struct {
    /** Left margin. */
    uint32_t leftMargin;
    /** Top margin. */
    uint32_t topMargin;
    /** Right margin. */
    uint32_t rightMargin;
    /** Bottom margin. */
    uint32_t bottomMargin;
} Print_Margin;

/**
 * @brief Indicates paper size info.
 *
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
} Print_PageSize;

/**
 * @brief Indicates DuplexMode
 *
 * @since 12
 */
typedef enum {
    /** One sided duplex mode. */
    DUPLEX_MODE_ONE_SIDED = 0,
    /** Long edge two sided duplex mode. */
    DUPLEX_MODE_TWO_SIDED_LONG_EDGE = 1,
    /** Short edge two sided duplex mode. */
    DUPLEX_MODE_TWO_SIDED_SHORT_EDGE = 2,
} Print_DuplexMode;

/**
 * @brief Indicates ColorMode
 *
 * @since 12
 */
typedef enum {
    /** Monochrome mode. */
    COLOR_MODE_MONOCHROME = 0,
    /** Color mode. */
    COLOR_MODE_COLOR = 1,
    /** Auto mode. */
    COLOR_MODE_AUTO = 2,
} Print_ColorMode;

/**
 * @brief Indicates OrientationMode
 *
 * @since 12
 */
typedef enum {
    /** Portrait mode. */
    ORIENTATION_MODE_PORTRAIT = 0,
    /** Landscape mode. */
    ORIENTATION_MODE_LANDSCAPE = 1,
    /** Reverse landscape mode. */
    ORIENTATION_MODE_REVERSE_LANDSCAPE = 2,
    /** Reverse portrait mode. */
    ORIENTATION_MODE_REVERSE_PORTRAIT = 3,
    /** Not specified. */
    ORIENTATION_MODE_NONE = 4,
} Print_OrientationMode;

/**
 * @brief Indicates printing qulity
 *
 * @since 12
 */
typedef enum {
    /** Draft quality mode */
    PRINT_QUALITY_DRAFT = 3,
    /** Normal quality mode */
    PRINT_QUALITY_NORMAL = 4,
    /** High quality mode */
    PRINT_QUALITY_HIGH = 5
} Print_Quality;

/**
 * @brief Indicates the MIME media type of the document.
 *
 * @since 12
 */
typedef enum {
    /** MIME: application/octet-stream. */
    DOCUMENT_FORMAT_AUTO,
    /** MIME: image/jpeg. */
    DOCUMENT_FORMAT_JPEG,
    /** MIME: application/pdf. */
    DOCUMENT_FORMAT_PDF,
    /** MIME: application/postscript. */
    DOCUMENT_FORMAT_POSTSCRIPT,
    /** MIME: text/plain. */
    DOCUMENT_FORMAT_TEXT,
} Print_DocumentFormat;

/**
 * @brief Indicates printer capabilities.
 *
 * @since 12
 */
typedef struct {
    /** Array of supported color mode. */
    Print_ColorMode *supportedColorModes;
    /** Number of supported color mode. */
    uint32_t supportedColorModesCount;
    /** Array of supported duplex printing modes. */
    Print_DuplexMode *supportedDuplexModes;
    /** Number of supported duplex printing mode. */
    uint32_t supportedDuplexModesCount;
    /** Array of supported print paper sizes. */
    Print_PageSize *supportedPageSizes;
    /** Number of supported print paper sizes. */
    uint32_t supportedPageSizesCount;
    /** Supported print media types in json string array format. */
    char *supportedMediaTypes;
    /** Array of supported print qulities. */
    Print_Quality *supportedQualities;
    /** Number of supported print qulities. */
    uint32_t supportedQualitiesCount;
    /** Supported paper sources in json string array format. */
    char *supportedPaperSources;
    /** Supported copies. */
    uint32_t supportedCopies;
    /** Array of supported printer resolutions. */
    Print_Resolution *supportedResolutions;
    /** Number of supported printer resolutions. */
    uint32_t supportedResolutionsCount;
    /** Array of supported orientation. */
    Print_OrientationMode *supportedOrientations;
    /** Number of supported orientation. */
    uint32_t supportedOrientationsCount;
    /** Advanced capability in json format. */
    char *advancedCapability;
} Print_PrinterCapability;

/**
 * @brief Indicates current properties
 *
 * @since 12
 */
typedef struct {
    /** Default color mode. */
    Print_ColorMode defaultColorMode;
    /** Default duplex mode. */
    Print_DuplexMode defaultDuplexMode;
    /** Default media type. */
    char *defaultMediaType;
    /** Default page size id. */
    char *defaultPageSizeId;
    /** Default margin. */
    Print_Margin defaultMargin;
    /** Default paper source. */
    char *defaultPaperSource;
    /** Default print quality */
    Print_Quality defaultPrintQuality;
    /** Default copies. */
    uint32_t defaultCopies;
    /** Default printer resolution. */
    Print_Resolution defaultResolution;
    /** Default orientation. */
    Print_OrientationMode defaultOrientation;
    /** Other default values in json format. */
    char *otherDefaultValues;
} Print_DefaultValue;

/**
 * @brief Indicates printer information.
 *
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
    /** Printer make and model information. */
    char *makeAndModel;
    /** Printer Uri. */
    char *printerUri;
    /** Detail information in json format. */
    char *detailInfo;
} Print_PrinterInfo;

/**
 * @brief Indicates PrintJob Structure.
 *
 * @since 12
 */
typedef struct {
    /** Job name. */
    char *jobName;
    /** Array of file descriptors to print. */
    uint32_t *fdList;
    /** Number of file descriptors to print. */
    uint32_t fdListCount;
    /** Printer id. */
    char *printerId;
    /** Number of copies printed. */
    uint32_t copyNumber;
    /** Paper source. */
    char *paperSource;
    /** Media type. */
    char *mediaType;
    /** Paper size id. */
    char *pageSizeId;
    /** Color mode. */
    Print_ColorMode colorMode;
    /** Duplex source. */
    Print_DuplexMode duplexMode;
    /** Print resolution in dpi. */
    Print_Resolution resolution;
    /** Print margin. */
    Print_Margin printMargin;
    /** Borderless. */
    bool borderless;
    /** Orientation mode. */
    Print_OrientationMode orientationMode;
    /** Print quality. */
    Print_Quality printQuality;
    /** Document format. */
    Print_DocumentFormat documentFormat;
    /** Advanced options in json format. */
    char *advancedOptions;
} Print_PrintJob;

/**
 * @brief Printer disconvery callback.
 *
 * @since 12
 */
typedef void (*Print_PrinterDiscoveryCallback)(Print_DiscoveryEvent event, const Print_PrinterInfo *printerInfo);

/**
 * @brief Printer change callback.
 *
 * @since 12
 */
typedef void (*Print_PrinterChangeCallback)(Print_PrinterEvent event, const Print_PrinterInfo *printerInfo);

#ifdef __cplusplus
}
#endif

#endif // NATIVE_PRINT_BASE_H
/** @} */
