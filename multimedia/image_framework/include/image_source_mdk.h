/*
 * Copyright (C) 2023 Huawei Device Co., Ltd.
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
 * @addtogroup image
 * @{
 *
 * @brief Provides native APIs for image sources.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */

/**
 * @file image_source_mdk.h
 *
 * @brief Declares APIs for decoding an image source into a pixel map.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */

#ifndef INTERFACES_KITS_NATIVE_INCLUDE_IMAGE_SOURCE_MDK_H_
#define INTERFACES_KITS_NATIVE_INCLUDE_IMAGE_SOURCE_MDK_H_
#include <cstdint>
#include "napi/native_api.h"
#include "image_mdk_common.h"
#include "rawfile/raw_file.h"
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defines a native image source object for the image source APIs.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
struct ImageSourceNative_;

/**
 * @brief Defines a native image source object for the image source APIs.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
typedef struct ImageSourceNative_ ImageSourceNative;

/**
 * @brief Defines a pointer to bits per sample, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char* OHOS_IMAGE_PROPERTY_BITS_PER_SAMPLE = "BitsPerSample";

/**
 * @brief Defines a pointer to the orientation, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char* OHOS_IMAGE_PROPERTY_ORIENTATION = "Orientation";

/**
 * @brief Defines a pointer to the image length, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char* OHOS_IMAGE_PROPERTY_IMAGE_LENGTH = "ImageLength";

/**
 * @brief Defines a pointer to the image width, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char* OHOS_IMAGE_PROPERTY_IMAGE_WIDTH = "ImageWidth";

/**
 * @brief Defines a pointer to the GPS latitude, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char* OHOS_IMAGE_PROPERTY_GPS_LATITUDE = "GPSLatitude";

/**
 * @brief Defines a pointer to the GPS longitude, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char* OHOS_IMAGE_PROPERTY_GPS_LONGITUDE = "GPSLongitude";

/**
 * @brief Defines a pointer to the GPS latitude reference information, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char* OHOS_IMAGE_PROPERTY_GPS_LATITUDE_REF = "GPSLatitudeRef";

/**
 * @brief Defines a pointer to the GPS longitude reference information, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char* OHOS_IMAGE_PROPERTY_GPS_LONGITUDE_REF = "GPSLongitudeRef";

/**
 * @brief Defines a pointer to the created date and time, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char* OHOS_IMAGE_PROPERTY_DATE_TIME_ORIGINAL = "DateTimeOriginal";

/**
 * @brief Defines a pointer to the exposure time, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char* OHOS_IMAGE_PROPERTY_EXPOSURE_TIME = "ExposureTime";

/**
 * @brief Defines a pointer to the scene type, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char* OHOS_IMAGE_PROPERTY_SCENE_TYPE = "SceneType";

/**
 * @brief Defines a pointer to the ISO speed ratings, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char* OHOS_IMAGE_PROPERTY_ISO_SPEED_RATINGS = "ISOSpeedRatings";

/**
 * @brief Defines a pointer to the f-number of the image, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char* OHOS_IMAGE_PROPERTY_F_NUMBER = "FNumber";

/**
 * @brief Defines a pointer to the compressed bits per pixel, one of the image properties.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
const char* OHOS_IMAGE_PROPERTY_COMPRESSED_BITS_PER_PIXEL = "CompressedBitsPerPixel";

/**
 * @brief The compression scheme used for the image data. When a primary image is JPEG compressed, this designation is not necessary and is omitted. When thumbnails use JPEG compression, this tag value is set to 6.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_COMPRESSION = "Compression";

/**
 * @brief The pixel composition. In JPEG compressed data a JPEG marker is used instead of this tag.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_PHOTOMETRIC_INTERPRETATION = "PhotometricInterpretation";

/**
 * @brief For each strip, the byte offset of that strip. It is recommended that this be selected so the number of strip bytes does not exceed 64 Kbytes. With JPEG compressed data this designation is not needed and is omitted. See also <RowsPerStrip> and <StripByteCounts>.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_STRIP_OFFSETS = "StripOffsets";

/**
 * @brief The number of components per pixel. Since this standard applies to RGB and YCbCr images, the value set for this tag is 3. In JPEG compressed data a JPEG marker is used instead of this tag.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_SAMPLES_PER_PIXEL = "SamplesPerPixel";

/**
 * @brief The number of rows per strip. This is the number of rows in the image of one strip when an image is divided into strips. With JPEG compressed data this designation is not needed and is omitted. See also <StripOffsets> and <StripByteCounts>.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_ROWS_PER_STRIP = "RowsPerStrip";

/**
 * @brief The total number of bytes in each strip. With JPEG compressed data this designation is not needed and is omitted.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_STRIP_BYTE_COUNTS = "StripByteCounts";

/**
 * @brief The number of pixels per <ResolutionUnit> in the <ImageWidth> direction. When the image resolution is unknown, 72 [dpi] is designated.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_X_RESOLUTION = "XResolution";

/**
 * @brief The number of pixels per <ResolutionUnit> in the <ImageLength> direction. The same value as <XResolution> is designated.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_Y_RESOLUTION = "YResolution";

/**
 * @brief Indicates whether pixel components are recorded in a chunky or planar format. In JPEG compressed files a JPEG marker is used instead of this tag. If this field does not exist, the TIFF default of 1 (chunky) is assumed.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_PLANAR_CONFIGURATION = "PlanarConfiguration";

/**
 * @brief The unit for measuring <XResolution> and <YResolution>. The same unit is used for both <XResolution> and <YResolution>. If the image resolution is unknown, 2 (inches) is designated.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_RESOLUTION_UNIT = "ResolutionUnit";

/**
 * @brief A transfer function for the image, described in tabular style. Normally this tag is not necessary, since color space is specified in the color space information tag (<ColorSpace>).
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_TRANSFER_FUNCTION = "TransferFunction";

/**
 * @brief This tag records the name and version of the software or firmware of the camera or image input device used to generate the image. The detailed format is not specified, but it is recommended that the example shown below be followed. When the field is left blank, it is treated as unknown.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_SOFTWARE = "Software";

/**
 * @brief This tag records the name of the camera owner, photographer or image creator. The detailed format is not specified, but it is recommended that the information be written as in the example below for ease of Interoperability. When the field is left blank, it is treated as unknown. Ex.) "Camera owner, John Smith; Photographer, Michael Brown; Image creator, Ken James"
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_ARTIST = "Artist";

/**
 * @brief The chromaticity of the white point of the image. Normally this tag is not necessary, since color space is specified in the colorspace information tag (<ColorSpace>).
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_WHITE_POINT = "WhitePoint";

/**
 * @brief The chromaticity of the three primary colors of the image. Normally this tag is not necessary, since colorspace is specified in the colorspace information tag (<ColorSpace>).
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_PRIMARY_CHROMATICITIES = "PrimaryChromaticities";

/**
 * @brief The matrix coefficients for transformation from RGB to YCbCr image data. No default is given in TIFF; but here the value given in Appendix E, "Color Space Guidelines", is used as the default. The color space is declared in a color space information tag, with the default being the value that gives the optimal image characteristics Interoperability this condition.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_YCBCR_COEFFICIENTS = "YCbCrCoefficients";

/**
 * @brief The sampling ratio of chrominance components in relation to the luminance component. In JPEG compressed data a JPEG marker is used instead of this tag.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_YCBCR_SUB_SAMPLING = "YCbCrSubSampling";

/**
 * @brief The position of chrominance components in relation to the luminance component. This field is designated only for JPEG compressed data or uncompressed YCbCr data. The TIFF default is 1 (centered); but when Y:Cb:Cr = 4:2:2 it is recommended in this standard that 2 (co-sited) be used to record data, in order to improve the image quality when viewed on TV systems. When this field does not exist, the reader shall assume the TIFF default. In the case of Y:Cb:Cr = 4:2:0, the TIFF default (centered) is recommended. If the reader does not have the capability of supporting both kinds of <YCbCrPositioning>, it shall follow the TIFF default regardless of the value in this field. It is preferable that readers be able to support both centered and co-sited positioning.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_YCBCR_POSITIONING = "YCbCrPositioning";

/**
 * @brief The reference black point value and reference white point value. No defaults are given in TIFF, but the values below are given as defaults here. The color space is declared in a color space information tag, with the default being the value that gives the optimal image characteristics Interoperability these conditions.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_REFERENCE_BLACK_WHITE = "ReferenceBlackWhite";

/**
 * @brief Copyright information. In this standard the tag is used to indicate both the photographer and editor copyrights. It is the copyright notice of the person or organization claiming rights to the image. The Interoperability copyright statement including date and rights should be written in this field; e.g., "Copyright, John Smith, 19xx. All rights reserved.". In this standard the field records both the photographer and editor copyrights, with each recorded in a separate part of the statement. When there is a clear distinction between the photographer and editor copyrights, these are to be written in the order of photographer followed by editor copyright, separated by NULL (in this case since the statement also ends with a NULL, there are two NULL codes). When only the photographer copyright is given, it is terminated by one NULL code. When only the editor copyright is given, the photographer copyright part consists of one space followed by a terminating NULL code, then the editor copyright is given. When the field is left blank, it is treated as unknown.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_COPYRIGHT = "Copyright";

/**
 * @brief The offset to the start byte (SOI) of JPEG compressed thumbnail data. This is not used for primary image JPEG data.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_JPEG_INTERCHANGE_FORMAT = "JPEGInterchangeFormat";

/**
 * @brief The number of bytes of JPEG compressed thumbnail data. This is not used for primary image JPEG data. JPEG thumbnails are not divided but are recorded as a continuous JPEG bitstream from SOI to EOI. Appn and COM markers should not be recorded. Compressed thumbnails must be recorded in no more than 64 Kbytes, including all other data to be recorded in APP1.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_JPEG_INTERCHANGE_FORMAT_LENGTH = "JPEGInterchangeFormatLength";

/**
 * @brief The class of the program used by the camera to set exposure when the picture is taken.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_EXPOSURE_PROGRAM = "ExposureProgram";

/**
 * @brief Indicates the spectral sensitivity of each channel of the camera used.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_SPECTRAL_SENSITIVITY = "SpectralSensitivity";

/**
 * @brief Indicates the Opto-Electric Conversion Function (OECF) specified in ISO 14524.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_OECF = "OECF";

/**
 * @brief The version of this standard supported. Nonexistence of this field is taken to mean nonconformance to the standard.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_EXIF_VERSION = "ExifVersion";

/**
 * @brief The date and time when the image was stored as digital data.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_DATE_TIME_DIGITIZED = "DateTimeDigitized";

/**
 * @brief Information specific to compressed data. The channels of each component are arranged in order from the 1st component to the 4th. For uncompressed data the data arrangement is given in the <PhotometricInterpretation> tag. However, since <PhotometricInterpretation> can only express the order of Y, Cb and Cr, this tag is provided for cases when compressed data uses components other than Y, Cb, and Cr and to enable support of other sequences.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_COMPONENTS_CONFIGURATION = "ComponentsConfiguration";

/**
 * @brief Shutter speed.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_SHUTTER_SPEED_VALUE = "ShutterSpeedValue";

/**
 * @brief The value of brightness.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_BRIGHTNESS_VALUE = "BrightnessValue";

/**
 * @brief The smallest F number of the lens.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_MAX_APERTURE_VALUE = "MaxApertureValue";

/**
 * @brief The distance to the subject, given in meters.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_SUBJECT_DISTANCE = "SubjectDistance";

/**
 * @brief This tag indicates the location and area of the main subject in the overall scene.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_SUBJECT_AREA = "SubjectArea";

/**
 * @brief A tag for manufacturers of Exif writers to record any desired information. The contents are up to the manufacturer.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_MAKER_NOTE = "MakerNote";

/**
 * @brief A tag used to record fractions of seconds for the <DateTime> tag.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_SUB_SEC_TIME = "SubSecTime";

/**
 * @brief A tag used to record fractions of seconds for the <DateTimeOriginal> tag.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_SUB_SEC_TIME_ORIGINAL = "SubSecTimeOriginal";

/**
 * @brief A tag used to record fractions of seconds for the <DateTimeDigitized> tag.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_SUB_SEC_TIME_DIGITIZED = "SubSecTimeDigitized";

/**
 * @brief The FlashPix format version supported by a FPXR file.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_FLASHPIX_VERSION = "FlashpixVersion";

/**
 * @brief The color space information tag is always recorded as the color space specifier. Normally sRGB is used to define the color space based on the PC monitor conditions and environment. If a color space other than sRGB is used, Uncalibrated is set. Image data recorded as Uncalibrated can be treated as sRGB when it is converted to FlashPix.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_COLOR_SPACE = "ColorSpace";

/**
 * @brief This tag is used to record the name of an audio file related to the image data. The only relational information recorded here is the Exif audio file name and extension (an ASCII string consisting of 8 characters + '.' + 3 characters). The path is not recorded.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_RELATED_SOUND_FILE = "RelatedSoundFile";

/**
 * @brief Amount of flash energy (BCPS).
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_FLASH_ENERGY = "FlashEnergy";

/**
 * @brief SFR of the camera.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_SPATIAL_FREQUENCY_RESPONSE = "SpatialFrequencyResponse";

/**
 * @brief Number of pixels per FocalPlaneResolutionUnit (37392) in ImageWidth direction for main image.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_FOCAL_PLANE_X_RESOLUTION = "FocalPlaneXResolution";

/**
 * @brief Number of pixels per FocalPlaneResolutionUnit (37392) in ImageLength direction for main image.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_FOCAL_PLANE_Y_RESOLUTION = "FocalPlaneYResolution";

/**
 * @brief Unit of measurement for FocalPlaneXResolution(37390) and FocalPlaneYResolution(37391).
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_FOCAL_PLANE_RESOLUTION_UNIT = "FocalPlaneResolutionUnit";

/**
 * @brief Indicates the location and area of the main subject in the overall scene.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_SUBJECT_LOCATION = "SubjectLocation";

/**
 * @brief Encodes the camera exposure index setting when image was captured.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_EXPOSURE_INDEX = "ExposureIndex";

/**
 * @brief Type of image sensor.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_SENSING_METHOD = "SensingMethod";

/**
 * @brief Indicates the image source. If a DSC recorded the image, this tag value of this tag always be set to 3, indicating that the image was recorded on a DSC.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_FILE_SOURCE = "FileSource";

/**
 * @brief Indicates the color filter array (CFA) geometric pattern of the image sensor when a one-chip color area sensor is used. It does not apply to all sensing methods.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_CFA_PATTERN = "CFAPattern";

/**
 * @brief This tag indicates the use of special processing on image data, such as rendering geared to output. When special processing is performed, the reader is expected to disable or minimize any further processing.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_CUSTOM_RENDERED = "CustomRendered";

/**
 * @brief This tag indicates the exposure mode set when the image was shot. In auto-bracketing mode, the camera shoots a series of frames of the same scene at different exposure settings.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_EXPOSURE_MODE = "ExposureMode";

/**
 * @brief This tag indicates the digital zoom ratio when the image was shot. If the numerator of the recorded value is 0, this indicates that digital zoom was not used.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_DIGITAL_ZOOM_RATIO = "DigitalZoomRatio";

/**
 * @brief This tag indicates the type of scene that was shot. It can also be used to record the mode in which the image was shot. Note that this differs from the <SceneType> tag.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_SCENE_CAPTURE_TYPE = "SceneCaptureType";

/**
 * @brief This tag indicates the degree of overall image gain adjustment.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_GAIN_CONTROL = "GainControl";

/**
 * @brief This tag indicates the direction of contrast processing applied by the camera when the image was shot.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_CONTRAST = "Contrast";

/**
 * @brief This tag indicates the direction of saturation processing applied by the camera when the image was shot.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_SATURATION = "Saturation";

/**
 * @brief This tag indicates the direction of sharpness processing applied by the camera when the image was shot.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_SHARPNESS = "Sharpness";

/**
 * @brief This tag indicates information on the picture-taking conditions of a particular camera model. The tag is used only to indicate the picture-taking conditions in the reader.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_DEVICE_SETTING_DESCRIPTION = "DeviceSettingDescription";

/**
 * @brief This tag indicates the distance to the subject.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_SUBJECT_DISTANCE_RANGE = "SubjectDistanceRange";

/**
 * @brief This tag indicates an identifier assigned uniquely to each image. It is recorded as an ASCII string equivalent to hexadecimal notation and 128-bit fixed length.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_IMAGE_UNIQUE_ID = "ImageUniqueID";

/**
 * @brief Indicates the version of <GPSInfoIFD>. The version is given as 2.0.0.0. This tag is mandatory when <GPSInfo> tag is present. (Note: The <GPSVersionID> tag is given in bytes, unlike the <ExifVersion> tag. When the version is 2.0.0.0, the tag value is 02000000.H).
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_GPS_VERSION_ID = "GPSVersionID";

/**
 * @brief Indicates the altitude used as the reference altitude. If the reference is sea level and the altitude is above sea level, 0 is given. If the altitude is below sea level, a value of 1 is given and the altitude is indicated as an absolute value in the GSPAltitude tag. The reference unit is meters. Note that this tag is BYTE type, unlike other reference tags.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_GPS_ALTITUDE_REF = "GPSAltitudeRef";

/**
 * @brief Indicates the altitude based on the reference in GPSAltitudeRef. Altitude is expressed as one RATIONAL value. The reference unit is meters.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_GPS_ALTITUDE = "GPSAltitude";

/**
 * @brief Indicates the GPS satellites used for measurements. This tag can be used to describe the number of satellites, their ID number, angle of elevation, azimuth, SNR and other information in ASCII notation. The format is not specified. If the GPS receiver is incapable of taking measurements, value of the tag is set to NULL.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_GPS_SATELLITES = "GPSSatellites";

/**
 * @brief Indicates the status of the GPS receiver when the image is recorded. "A" means measurement is in progress, and "V" means the measurement is Interoperability.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_GPS_STATUS = "GPSStatus";

/**
 * @brief Indicates the GPS measurement mode. "2" means two-dimensional measurement and "3" means three-dimensional measurement is in progress.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_GPS_MEASURE_MODE = "GPSMeasureMode";

/**
 * @brief Indicates the GPS DOP (data degree of precision). An HDOP value is written during two-dimensional measurement, and PDOP during three-dimensional measurement.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_GPS_DOP = "GPSDOP";

/**
 * @brief Indicates the unit used to express the GPS receiver speed of movement. "K" "M" and "N" represents kilometers per hour, miles per hour, and knots.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_GPS_SPEED_REF = "GPSSpeedRef";

/**
 * @brief Indicates the speed of GPS receiver movement.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_GPS_SPEED = "GPSSpeed";

/**
 * @brief Indicates the reference for giving the direction of GPS receiver movement. "T" denotes true direction and "M" is magnetic direction.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_GPS_TRACK_REF = "GPSTrackRef";

/**
 * @brief Indicates the direction of GPS receiver movement. The range of values is from 0.00 to 359.99.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_GPS_TRACK = "GPSTrack";

/**
 * @brief Indicates the reference for giving the direction of the image when it is captured. "T" denotes true direction and "M" is magnetic direction.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_GPS_IMG_DIRECTION_REF = "GPSImgDirectionRef";

/**
 * @brief Indicates the direction of the image when it was captured. The range of values is from 0.00 to 359.99.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_GPS_IMG_DIRECTION = "GPSImgDirection";

/**
 * @brief Indicates the geodetic survey data used by the GPS receiver. If the survey data is restricted to Japan, the value of this tag is "TOKYO" or "WGS-84".
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_GPS_MAP_DATUM = "GPSMapDatum";

/**
 * @brief Indicates whether the latitude of the destination point is north or south latitude. The ASCII value "N" indicates north latitude, and "S" is south latitude.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_GPS_DEST_LATITUDE_REF = "GPSDestLatitudeRef";

/**
 * @brief Indicates the latitude of the destination point. The latitude is expressed as three RATIONAL values giving the degrees, minutes, and seconds, respectively. If latitude is expressed as degrees, minutes and seconds, a typical format would be dd/1,mm/1,ss/1. When degrees and minutes are used and, for example, fractions of minutes are given up to two decimal places, the format would be dd/1,mmmm/100,0/1.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_GPS_DEST_LATITUDE = "GPSDestLatitude";

/**
 * @brief Indicates whether the longitude of the destination point is east or west longitude. ASCII "E" indicates east longitude, and "W" is west longitude.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_GPS_DEST_LONGITUDE_REF = "GPSDestLongitudeRef";

/**
 * @brief Indicates the longitude of the destination point. The longitude is expressed as three RATIONAL values giving the degrees, minutes, and seconds, respectively. If longitude is expressed as degrees, minutes and seconds, a typical format would be ddd/1,mm/1,ss/1. When degrees and minutes are used and, for example, fractions of minutes are given up to two decimal places, the format would be ddd/1,mmmm/100,0/1.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_GPS_DEST_LONGITUDE = "GPSDestLongitude";

/**
 * @brief Indicates the reference used for giving the bearing to the destination point. "T" denotes true direction and "M" is magnetic direction. It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_GPS_DEST_BEARING_REF = "GPSDestBearingRef";

/**
 * @brief Indicates the bearing to the destination point. The range of values is from 0.00 to 359.99. It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_GPS_DEST_BEARING = "GPSDestBearing";

/**
 * @brief Indicates the unit used to express the distance to the destination point. "K", "M" and "N" represent kilometers, miles and knots. It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_GPS_DEST_DISTANCE_REF = "GPSDestDistanceRef";

/**
 * @brief Indicates the distance to the destination point. It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_GPS_DEST_DISTANCE = "GPSDestDistance";

/**
 * @brief A character string recording the name of the method used for location finding. The string encoding is defined using the same scheme as UserComment. It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_GPS_PROCESSING_METHOD = "GPSProcessingMethod";

/**
 * @brief A character string recording the name of the GPS area.The string encoding is defined using the same scheme as UserComment. It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_GPS_AREA_INFORMATION = "GPSAreaInformation";

/**
 * @brief Indicates whether differential correction is applied to the GPS receiver. It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_GPS_DIFFERENTIAL = "GPSDifferential";

/**
 * @brief This tag records the serial number of the body of the camera that was used in photography as an ASCII string. It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_BODY_SERIAL_NUMBER = "BodySerialNumber";

/**
 * @brief This tag records the owner of a camera used in photography as an ASCII string. It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_CAMERA_OWNER_NAME = "CameraOwnerName";

/**
 * @brief Indicates whether the recorded image is a composite image or not. It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_COMPOSITE_IMAGE = "CompositeImage";

/**
 * @brief Specific to compressed data; states the compressed bits per pixel. It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_COMPRESSED_BITS_PER_PIXEL = "CompressedBitsPerPixel";

/**
 * @brief This tag encodes the DNG four-tier version number. For files compliant with version 1.1.0.0 of the DNG specification, this tag should contain the bytes: 1, 1, 0, 0. It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_DNG_VERSION = "DNGVersion";

/**
 * @brief Raw images often store extra pixels around the edges of the final image. These extra pixels help prevent interpolation artifacts near the edges of the final image. DefaultCropSize specifies the size of the final image area, in raw image coordinates (i.e., before the DefaultScale has been applied). It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_DEFAULT_CROP_SIZE = "DefaultCropSize";

/**
 * @brief Indicates the value of coefficient gamma. The formula of transfer function used for image reproduction is expressed as follows: (reproduced value) = (input value)^gamma. Both reproduced value and input value indicate normalized value, whose minimum value is 0 and maximum value is 1. It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_GAMMA = "Gamma";

/**
 * @brief This tag indicates the ISO speed latitude yyy value of a camera or input device that is defined in ISO 12232. However, this tag shall not be recorded without ISOSpeed and ISOSpeedLatitudezzz. It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_ISO_SPEED_LATITUDEYYY = "ISOSpeedLatitudeyyy";

/**
 * @brief This tag indicates the ISO speed latitude zzz value of a camera or input device that is defined in ISO 12232. However, this tag shall not be recorded without ISOSpeed and ISOSpeedLatitudeyyy.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_ISOSPEEDLATITUDEZZZ = "ISOSpeedLatitudezzz";

/**
 * @brief This tag records the lens manufactor as an ASCII string.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_LENS_MAKE = "LensMake";

/**
 * @brief This tag records the lens's model name and model number as an ASCII string.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_LENS_MODEL = "LensModel";

/**
 * @brief This tag records the serial number of the interchangeable lens that was used in photography as an ASCII string.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_LENS_SERIAL_NUMBER = "LensSerialNumber";

/**
 * @brief This tag notes minimum focal length, maximum focal length, minimum F number in the minimum focal length, and minimum F number in the maximum focal length, which are specification information for the lens that was used in photography. When the minimum F number is unknown, the notation is 0/0
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_LENS_SPECIFICATION = "LensSpecification";

/**
 * @brief A general indication of the kind of data contained in this subfile.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_NEW_SUBFILE_TYPE = "NewSubfileType";

/**
 * @brief Time difference from Universal Time Coordinated including daylight saving time of DateTime tag.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_OFFSET_TIME = "OffsetTime";

/**
 * @brief Time difference from Universal Time Coordinated including daylight saving time of DateTimeDigitized tag.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_OFFSET_TIME_DIGITIZED = "OffsetTimeDigitized";

/**
 * @brief Time difference from Universal Time Coordinated including daylight saving time of DateTimeOriginal tag.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_OFFSET_TIME_ORIGINAL = "OffsetTimeOriginal";

/**
 * @brief For a composite image, records the parameters relating exposure time of the exposures for generating the said composite image, such as respective exposure times of captured source images (tentatively recorded images).
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_SOURCE_EXPOSURE_TIMES_OF_COMPOSITE_IMAGE = "SourceExposureTimesOfCompositeImage";

/**
 * @brief Indicates the number of the source images (tentatively recorded images) captured for a composite Image.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_SOURCE_IMAGE_NUMBER_OF_COMPOSITE_IMAGE = "SourceImageNumberOfCompositeImage";

/**
 * @brief A general indication of the kind of data contained in this subfile. This field is deprecated. The NewSubfileType field should be used instead.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_SUBFILE_TYPE = "SubfileType";

/**
 * @brief This tag indicates horizontal positioning errors in meters.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_GPS_H_POSITIONING_ERROR = "GPSHPositioningError";

/**
 * @brief Burst Number
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_BURST_NUMBER = "HwMnoteBurstNumber";

/**
 * @brief Face Conf
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_FACE_CONF = "HwMnoteFaceConf";

/**
 * @brief Face Leye Center
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_FACE_LEYE_CENTER = "HwMnoteFaceLeyeCenter";

/**
 * @brief Face Mouth Center
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 12
 * @version 5.0
 */
const char* OHOS_IMAGE_PROPERTY_FACE_MOUTH_CENTER = "HwMnoteFaceMouthCenter";

/**
 * @brief Defines the region of the image source to decode.
 * It is used in {@link OhosImageDecodingOps}, {@link OH_ImageSource_CreatePixelMap}, and
 * {@link OH_ImageSource_CreatePixelMapList}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
struct OhosImageRegion {
    /** X coordinate of the start point, in pixels. */
    int32_t x;
    /** Y coordinate of the start point, in pixels. */
    int32_t y;
    /** Width of the region, in pixels. */
    int32_t width;
    /** Height of the region, in pixels. */
    int32_t height;
};

/**
 * @brief Defines image source options infomation
 * {@link OH_ImageSource_Create} and {@link OH_ImageSource_CreateIncremental}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
struct OhosImageSourceOps {
    /** Pixel density of the image source. */
    int32_t density;
    /** Image source pixel format, used to describe YUV buffer usually. */
    int32_t pixelFormat;
    /** Image source pixel size of width and height. */
    struct OhosImageSize size;
};

/**
 * @brief Defines the options for decoding the image source.
 * It is used in {@link OH_ImageSource_CreatePixelMap} and {@link OH_ImageSource_CreatePixelMapList}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
struct OhosImageDecodingOps {
    /** Defines output pixel map editable. */
    int8_t editable;
    /** Defines output pixel format. */
    int32_t pixelFormat;
    /** Defines decoding target pixel density. */
    int32_t fitDensity;
    /** Defines decoding index of image source. */
    uint32_t index;
    /** Defines decoding sample size option. */
    uint32_t sampleSize;
    /** Defines decoding rotate option. */
    uint32_t rotate;
    /** Defines decoding target pixel size of width and height. */
    struct OhosImageSize size;
    /** Defines image source pixel region for decoding. */
    struct OhosImageRegion region;
};

/**
 * @brief Defines the image source information, which is obtained by calling {@link OH_ImageSource_GetImageInfo}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
struct OhosImageSourceInfo {
    /** Pixel format of the image source. It is set in {@link OH_ImageSource_Create}. */
    int32_t pixelFormat;
    /** Color space of the image source. */
    int32_t colorSpace;
    /** Alpha type of the image source. */
    int32_t alphaType;
    /** Image density of the image source. It is set in {@link OH_ImageSource_Create}. */
    int32_t density;
    /** Pixel width and height of the image source. */
    struct OhosImageSize size;
};

/**
 * @brief Defines the input resource of the image source. It is obtained by calling {@link OH_ImageSource_Create}.
 * Only one type of resource is accepted at a time.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 * @deprecated since 11
 */
struct OhosImageSource {
    /** Pointer to the image source URI. Only a file URI or Base64 URI is accepted. */
    char* uri = nullptr;
    /** Length of the image source URI. */
    size_t uriSize = 0;
    /** Descriptor of the image source. */
    int32_t fd = -1;
    /** Pointer to the image source buffer. Only a formatted packet buffer or Base64 buffer is accepted. */
    uint8_t* buffer = nullptr;
    /** Size of the image source buffer. */
    size_t bufferSize = 0;
};

/**
 * @brief Defines the delay time list of the image source. It is obtained by calling
 * {@link OH_ImageSource_GetDelayTime}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
struct OhosImageSourceDelayTimeList {
    /** Pointer to the head of the image source delay time list. */
    int32_t* delayTimeList;
    /** Size of the image source delay time list. */
    size_t size = 0;
};

/**
 * @brief Defines image source supported format string.
 * {@link OhosImageSourceSupportedFormatList} and {@link OH_ImageSource_GetSupportedFormats}
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
struct OhosImageSourceSupportedFormat {
    /** Image source supported format string head.*/
    char* format = nullptr;
    /** Image source supported format string size.*/
    size_t size = 0;
};

/**
 * @brief Defines the format string list supported by the image source.
 * It is obtained by calling {@link OH_ImageSource_GetSupportedFormats}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
struct OhosImageSourceSupportedFormatList {
    /** Image source supported format string list head.*/
    struct OhosImageSourceSupportedFormat** supportedFormatList = nullptr;
    /** Image source supported format string list size.*/
    size_t size = 0;
};

/**
 * @brief Defines the property string (in key-value format) of the image source.
 * It is used in {@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
struct OhosImageSourceProperty {
    /** Image source property key and value string head.*/
    char* value = nullptr;
    /** Image source property key and value string size.*/
    size_t size = 0;
};

/**
 * @brief Defines the update data of the image source. It is obtained by calling {@link OH_ImageSource_UpdateData}.
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
struct OhosImageSourceUpdateData {
    /** Image source update data buffer.*/
    uint8_t* buffer = nullptr;
    /** Image source update data buffer size.*/
    size_t bufferSize = 0;
    /** Image source offset of update data buffer.*/
    uint32_t offset = 0;
    /** Image source update data length in update data buffer.*/
    uint32_t updateLength = 0;
    /** Image source update data is completed in this session.*/
    int8_t isCompleted = 0;
};

/**
 * @brief Creates an <b>ImageSource</b> object at the JavaScript native layer based on the specified
 * {@link OhosImageSource} and {@link OhosImageSourceOps} structs.
 *
 * @param env Indicates a pointer to the Java Native Interface (JNI) environment.
 * @param src Indicates a pointer to the input resource of the image source. For details, see {@link OhosImageSource}.
 * @param ops Indicates a pointer to the options for creating the image source.
 * For details, see {@link OhosImageSourceOps}.
 * @param res Indicates a pointer to the <b>ImageSource</b> object created at the JavaScript native layer.
 * @return Returns {@link IRNdkErrCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_BAD_PARAMETER - if bad parameter.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_JNI_ENV_ABNORMAL - if Abnormal JNI environment.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_SOURCE_DATA_INCOMPLETE - if image source data incomplete.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_SOURCE_DATA - if image source data error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_GET_DATA_ABNORMAL - if image get data error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_TOO_LARGE - if image data too large.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DECODE_FAILED - if decode fail.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DECODE_HEAD_ABNORMAL - if image decode head error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DECODE_EXIF_UNSUPPORT - if image decode exif unsupport.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_PROPERTY_NOT_EXIST - if image property not exist.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_FILE_DAMAGED - if file damaged.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_FILE_FD_ERROR - if file fd is bad.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_STREAM_SIZE_ERROR - if stream bad.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_SEEK_FAILED - if seek file failed.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_PEEK_FAILED - if peek file failed.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_FREAD_FAILED - if read file failed.
 * @see {@link OhosImageSource}, {@link OhosImageSourceOps}
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 * @deprecated since 11
 * @useinstead image#OH_ImageSource_CreateFromUri
 * @useinstead image#OH_ImageSource_CreateFromFd
 * @useinstead image#OH_ImageSource_CreateFromData
 */
int32_t OH_ImageSource_Create(napi_env env, struct OhosImageSource* src,
    struct OhosImageSourceOps* ops, napi_value *res);

/**
 * @brief Creates an <b>ImageSource</b> object at the JavaScript native layer based on the specified
 * image source URI and {@link OhosImageSourceOps} structs.
 *
 * @param env Indicates a pointer to the Java Native Interface (JNI) environment.
 * @param uri Indicates a pointer to the image source URI. Only a file URI or Base64 URI is accepted.
 * @param size Indicates the length of the image source URI.
 * @param ops Indicates a pointer to the options for creating the image source.
 * For details, see {@link OhosImageSourceOps}.
 * @param res Indicates a pointer to the <b>ImageSource</b> object created at the JavaScript native layer.
 * @return Returns {@link IRNdkErrCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_BAD_PARAMETER - if bad parameter.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_JNI_ENV_ABNORMAL - if Abnormal JNI environment.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * @see {@link OhosImageSourceOps}
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 11
 * @version 4.1
 */
int32_t OH_ImageSource_CreateFromUri(napi_env env, char* uri, size_t size,
    struct OhosImageSourceOps* ops, napi_value *res);

/**
 * @brief Creates an <b>ImageSource</b> object at the JavaScript native layer based on the specified
 * image source file descriptor and {@link OhosImageSourceOps} structs.
 *
 * @param env Indicates a pointer to the Java Native Interface (JNI) environment.
 * @param fd Indicates the image source file descriptor.
 * @param ops Indicates a pointer to the options for creating the image source.
 * For details, see {@link OhosImageSourceOps}.
 * @param res Indicates a pointer to the <b>ImageSource</b> object created at the JavaScript native layer.
 * @return Returns {@link IRNdkErrCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_BAD_PARAMETER - if bad parameter.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_JNI_ENV_ABNORMAL - if Abnormal JNI environment.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * @see {@link OhosImageSourceOps}
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 11
 * @version 4.1
 */
int32_t OH_ImageSource_CreateFromFd(napi_env env, int32_t fd,
    struct OhosImageSourceOps* ops, napi_value *res);

/**
 * @brief Creates an <b>ImageSource</b> object at the JavaScript native layer based on the specified
 * image source data and {@link OhosImageSourceOps} structs.
 *
 * @param env Indicates a pointer to the Java Native Interface (JNI) environment.
 * @param data Indicates a pointer to the image source data. Only a formatted packet data or Base64 data is accepted.
 * @param dataSize Indicates the size of the image source data.
 * @param ops Indicates a pointer to the options for creating the image source.
 * For details, see {@link OhosImageSourceOps}.
 * @param res Indicates a pointer to the <b>ImageSource</b> object created at the JavaScript native layer.
 * @return Returns {@link IRNdkErrCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_BAD_PARAMETER - if bad parameter.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_JNI_ENV_ABNORMAL - if Abnormal JNI environment.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * @see {@link OhosImageSourceOps}
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 11
 * @version 4.1
 */
int32_t OH_ImageSource_CreateFromData(napi_env env, uint8_t* data, size_t dataSize,
    struct OhosImageSourceOps* ops, napi_value *res);

/**
 * @brief Creates an <b>ImageSource</b> object at the JavaScript native layer based on the specified
 * raw file's file descriptor and {@link OhosImageSourceOps} structs.
 *
 * @param env Indicates a pointer to the Java Native Interface (JNI) environment.
 * @param rawFile Indicates the raw file's file descriptor.
 * @param ops Indicates a pointer to the options for creating the image source.
 * For details, see {@link OhosImageSourceOps}.
 * @param res Indicates a pointer to the <b>ImageSource</b> object created at the JavaScript native layer.
 * @return Returns {@link IRNdkErrCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_BAD_PARAMETER - if bad parameter.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_JNI_ENV_ABNORMAL - if Abnormal JNI environment.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * @see {@link OhosImageSourceOps}
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 11
 * @version 4.1
 */
int32_t OH_ImageSource_CreateFromRawFile(napi_env env, RawFileDescriptor rawFile,
    struct OhosImageSourceOps* ops, napi_value *res);

/**
 * @brief Creates an incremental <b>ImageSource</b> object at the JavaScript native layer based on the specified
 * {@link OhosImageSource} and {@link OhosImageSourceOps} structs.
 * The image source data will be updated through {@link OH_ImageSource_UpdateData}.
 *
 * @param env Indicates a pointer to the JNI environment.
 * @param src Indicates a pointer to the input resource of the image source. Only the buffer type is accepted.
 * For details, see {@link OhosImageSource}.
 * @param ops Indicates a pointer to the options for creating the image source.
 * For details, see {@link OhosImageSourceOps}.
 * @param res Indicates a pointer to the <b>ImageSource</b> object created at the JavaScript native layer.
 * @return Returns {@link IRNdkErrCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_BAD_PARAMETER - if bad parameter.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_JNI_ENV_ABNORMAL - if Abnormal JNI environment.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_SOURCE_DATA_INCOMPLETE - if image source data incomplete.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_SOURCE_DATA - if image source data error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_GET_DATA_ABNORMAL - if image get data error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_TOO_LARGE - if image data too large.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DECODE_FAILED - if decode fail.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DECODE_HEAD_ABNORMAL - if image decode head error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DECODE_EXIF_UNSUPPORT - if image decode exif unsupport.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_PROPERTY_NOT_EXIST - if image property not exist.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_FILE_DAMAGED - if file damaged.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_FILE_FD_ERROR - if file fd is bad.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_STREAM_SIZE_ERROR - if stream bad.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_SEEK_FAILED - if seek file failed.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_PEEK_FAILED - if peek file failed.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_FREAD_FAILED - if read file failed.
 * @see {@link OhosImageSource}, {@link OhosImageSourceOps}, {@link OH_ImageSource_UpdateData}
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 * @deprecated since 11
 * @useinstead image#OH_ImageSource_CreateIncrementalFromData
 */
int32_t OH_ImageSource_CreateIncremental(napi_env env, struct OhosImageSource* source,
    struct OhosImageSourceOps* ops, napi_value *res);

/**
 * @brief Creates an incremental <b>ImageSource</b> object at the JavaScript native layer based on the specified
 * image source data and {@link OhosImageSourceOps} structs.
 * The image source data will be updated through {@link OH_ImageSource_UpdateData}.
 *
 * @param env Indicates a pointer to the JNI environment.
 * @param data Indicates a pointer to the image source data. Only a formatted packet data or Base64 data is accepted.
 * @param dataSize Indicates the size of the image source data.
 * @param ops Indicates a pointer to the options for creating the image source.
 * For details, see {@link OhosImageSourceOps}.
 * @param res Indicates a pointer to the <b>ImageSource</b> object created at the JavaScript native layer.
 * @return Returns {@link IRNdkErrCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_BAD_PARAMETER - if bad parameter.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_JNI_ENV_ABNORMAL - if Abnormal JNI environment.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * @see {@link OhosImageSourceOps}, {@link OH_ImageSource_UpdateData}
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 11
 * @version 4.1
 */
int32_t OH_ImageSource_CreateIncrementalFromData(napi_env env, uint8_t* data, size_t dataSize,
    struct OhosImageSourceOps* ops, napi_value *res);

/**
 * @brief Obtains all supported decoding formats.
 *
 * @param res Indicates a pointer to the <b>OhosImageSourceSupportedFormatList</b> struct.
 * When the input <b>supportedFormatList</b> is a null pointer and <b>size</b> is 0, the size of the supported formats
 * is returned through <b>size</b> in <b>res</b>.
 * To obtain all formats, a space larger than <b>size</b> is required.
 * In addition, sufficient space must be reserved for each format supported.
 * @return Returns {@link IRNdkErrCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_BAD_PARAMETER - if bad parameter.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_JNI_ENV_ABNORMAL - if Abnormal JNI environment.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DECODE_FAILED - if decode fail.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_CHECK_FORMAT_ERROR - if decode fail.
 * @see {@link OhosImageSourceSupportedFormatList}, {@link OhosImageSourceSupportedFormat}
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
int32_t OH_ImageSource_GetSupportedFormats(struct OhosImageSourceSupportedFormatList* res);

/**
 * @brief Converts an {@link ImageSource} object at the JavaScript native layer to an <b>ImageSourceNative</b> object
 * at the C++ native layer.
 *
 * @param env Indicates a pointer to the JNI environment.
 * @param source Indicates a pointer to the <b>ImageSource</b> object at the JavaScript native layer.
 * @return Returns a pointer to the {@link ImageSourceNative} object if the operation is successful;
 * returns a null pointer otherwise.
 * @see {@link ImageSourceNative}, {@link OH_ImageSource_Release}
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
ImageSourceNative* OH_ImageSource_InitNative(napi_env env, napi_value source);

/**
 * @brief Decodes an <b>ImageSource</b> object to obtain a <b>PixelMap</b> object at the JavaScript native layer
 * based on the specified {@link OhosImageDecodingOps} struct.
 *
 * @param native Indicates a pointer to the {@link ImageSourceNative} object at the C++ native layer.
 * @param ops Indicates a pointer to the options for decoding the image source.
 * For details, see {@link OhosImageDecodingOps}.
 * @param res Indicates a pointer to the <b>PixelMap</b> object obtained at the JavaScript native layer.
 * @return Returns {@link IRNdkErrCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_BAD_PARAMETER - if bad parameter.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_JNI_ENV_ABNORMAL - if Abnormal JNI environment.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_GET_DATA_ABNORMAL - if image get data error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DECODE_FAILED - if decode fail.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DECODE_HEAD_ABNORMAL - if image decode head error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_CREATE_DECODER_FAILED - if create decoder failed.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_CREATE_ENCODER_FAILED - if create encoder failed.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_CHECK_FORMAT_ERROR - if check format failed.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_THIRDPART_SKIA_ERROR - if skia error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DATA_ABNORMAL - if image input data error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST - if sharememory error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL - if sharememory data abnormal.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DECODE_ABNORMAL - if image decode error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_MALLOC_ABNORMAL - if image malloc error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DATA_UNSUPPORT - if image init error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_INIT_ABNORMAL - if image input data error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_CROP - if crop error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_UNKNOWN_FORMAT - if image unknown format.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_PLUGIN_REGISTER_FAILED - if register plugin fail.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_PLUGIN_CREATE_FAILED - if create plugin fail.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_ENCODE_FAILED - if image add pixel map fail.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_HW_DECODE_UNSUPPORT - if image hardware decode unsupported.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_HW_DECODE_FAILED - if hard decode failed.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_ERR_IPC - if ipc error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_INDEX_INVALID - if invalid index.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_ALPHA_TYPE_ERROR - if hard decode failed.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_ALLOCATER_TYPE_ERROR - if hard decode failed.
 * @see {@link ImageSourceNative}, {@link OhosImageDecodingOps}
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
int32_t OH_ImageSource_CreatePixelMap(const ImageSourceNative* native,
    struct OhosImageDecodingOps* ops, napi_value *res);

/**
 * @brief Decodes an <b>ImageSource</b> to obtain all the <b>PixelMap</b> objects at the JavaScript native layer
 * based on the specified {@link OhosImageDecodingOps} struct.
 *
 * @param native Indicates a pointer to the {@link ImageSourceNative} object at the C++ native layer.
 * @param ops Indicates a pointer to the options for decoding the image source.
 * For details, see {@link OhosImageDecodingOps}.
 * @param res Indicates a pointer to the <b>PixelMap</b> objects obtained at the JavaScript native layer.
 * @return Returns {@link IRNdkErrCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_BAD_PARAMETER - if bad parameter.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_JNI_ENV_ABNORMAL - if Abnormal JNI environment.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_GET_DATA_ABNORMAL - if image get data error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DECODE_FAILED - if decode fail.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DECODE_HEAD_ABNORMAL - if image decode head error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_CREATE_DECODER_FAILED - if create decoder failed.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_CREATE_ENCODER_FAILED - if create encoder failed.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_CHECK_FORMAT_ERROR - if check format failed.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_THIRDPART_SKIA_ERROR - if skia error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DATA_ABNORMAL - if image input data error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST - if sharememory error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL - if sharememory data abnormal.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DECODE_ABNORMAL - if image decode error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_MALLOC_ABNORMAL - if image malloc error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DATA_UNSUPPORT - if image init error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_INIT_ABNORMAL - if image input data error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_CROP - if crop error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_UNKNOWN_FORMAT - if image unknown format.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_PLUGIN_REGISTER_FAILED - if register plugin fail.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_PLUGIN_CREATE_FAILED - if create plugin fail.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_ENCODE_FAILED - if image add pixel map fail.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_HW_DECODE_UNSUPPORT - if image hardware decode unsupported.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_HW_DECODE_FAILED - if hard decode failed.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_ERR_IPC - if ipc error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_INDEX_INVALID - if invalid index.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_ALPHA_TYPE_ERROR - if hard decode failed.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_ALLOCATER_TYPE_ERROR - if hard decode failed.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DECODE_EXIF_UNSUPPORT - if image decode exif unsupport.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_PROPERTY_NOT_EXIST - if image property not exist.
 * @see {@link ImageSourceNative}, {@link OhosImageDecodingOps}
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
int32_t OH_ImageSource_CreatePixelMapList(const ImageSourceNative* native,
    struct OhosImageDecodingOps* ops, napi_value *res);

/**
 * @brief Obtains the delay time list from some <b>ImageSource</b> objects (such as GIF image sources).
 *
 * @param native Indicates a pointer to the {@link ImageSourceNative} object at the C++ native layer.
 * @param res Indicates a pointer to the delay time list obtained.
 * For details, see {@link OhosImageSourceDelayTimeList}. When the input <b>delayTimeList</b> is a null pointer and
 * <b>size</b> is <b>0</b>, the size of the delay time list is returned through <b>size</b> in <b>res</b>.
 * To obtain the complete delay time list, a space greater than <b>size</b> is required.
 * @return Returns {@link IRNdkErrCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_BAD_PARAMETER - if bad parameter.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_JNI_ENV_ABNORMAL - if Abnormal JNI environment.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_GET_DATA_ABNORMAL - if image get data error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DECODE_FAILED - if decode fail.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DECODE_HEAD_ABNORMAL - if image decode head error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_CREATE_DECODER_FAILED - if create decoder failed.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_THIRDPART_SKIA_ERROR - if skia error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DATA_ABNORMAL - if image input data error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DECODE_ABNORMAL - if image decode error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DATA_UNSUPPORT - if image init error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_UNKNOWN_FORMAT - if image unknown format.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_PLUGIN_REGISTER_FAILED - if register plugin fail.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_PLUGIN_CREATE_FAILED - if create plugin fail.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_INDEX_INVALID - if invalid index.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DECODE_EXIF_UNSUPPORT - if image decode exif unsupport.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_PROPERTY_NOT_EXIST - if image property not exist.
 * @see {@link ImageSourceNative}, {@link OhosImageSourceDelayTimeList}
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
int32_t OH_ImageSource_GetDelayTime(const ImageSourceNative* native,
    struct OhosImageSourceDelayTimeList* res);

/**
 * @brief Obtains the number of frames from an <b>ImageSource</b> object.
 *
 * @param native Indicates a pointer to the {@link ImageSourceNative} object at the C++ native layer.
 * @param res Indicates a pointer to the number of frames obtained.
 * @return Returns {@link IRNdkErrCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_BAD_PARAMETER - if bad parameter.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_JNI_ENV_ABNORMAL - if Abnormal JNI environment.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_GET_DATA_ABNORMAL - if image get data error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DECODE_FAILED - if decode fail.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DECODE_HEAD_ABNORMAL - if image decode head error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_CREATE_DECODER_FAILED - if create decoder failed.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_THIRDPART_SKIA_ERROR - if skia error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DATA_ABNORMAL - if image input data error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DECODE_ABNORMAL - if image decode error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DATA_UNSUPPORT - if image init error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_UNKNOWN_FORMAT - if image unknown format.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_PLUGIN_REGISTER_FAILED - if register plugin fail.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_PLUGIN_CREATE_FAILED - if create plugin fail.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_INDEX_INVALID - if invalid index.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DECODE_EXIF_UNSUPPORT - if image decode exif unsupport.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_PROPERTY_NOT_EXIST - if image property not exist.
 * @see {@link ImageSourceNative}
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
int32_t OH_ImageSource_GetFrameCount(const ImageSourceNative* native, uint32_t *res);

/**
 * @brief Obtains image source information from an <b>ImageSource</b> object by index.
 *
 * @param native Indicates a pointer to the {@link ImageSourceNative} object at the C++ native layer.
 * @param index Indicates the index of the frame.
 * @param info Indicates a pointer to the image source information obtained.
 * For details, see {@link OhosImageSourceInfo}.
 * @return Returns {@link IRNdkErrCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_BAD_PARAMETER - if bad parameter.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_JNI_ENV_ABNORMAL - if Abnormal JNI environment.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_GET_DATA_ABNORMAL - if image get data error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DECODE_FAILED - if decode fail.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DECODE_HEAD_ABNORMAL - if image decode head error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_CREATE_DECODER_FAILED - if create decoder failed.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_THIRDPART_SKIA_ERROR - if skia error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DATA_ABNORMAL - if image input data error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DECODE_ABNORMAL - if image decode error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DATA_UNSUPPORT - if image init error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_UNKNOWN_FORMAT - if image unknown format.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_PLUGIN_REGISTER_FAILED - if register plugin fail.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_PLUGIN_CREATE_FAILED - if create plugin fail.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_INDEX_INVALID - if invalid index.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DECODE_EXIF_UNSUPPORT - if image decode exif unsupport.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_PROPERTY_NOT_EXIST - if image property not exist.
 * @see {@link ImageSourceNative}, {@link OhosImageSourceInfo}
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
int32_t OH_ImageSource_GetImageInfo(const ImageSourceNative* native, int32_t index,
    struct OhosImageSourceInfo* info);

/**
 * @brief Obtains the value of an image property from an <b>ImageSource</b> object.
 *
 * @param native Indicates a pointer to the {@link ImageSourceNative} object at the C++ native layer.
 * @param key Indicates a pointer to the property. For details, see {@link OhosImageSourceProperty}.
 * @param value Indicates a pointer to the property value obtained.
 * If the input <b>value</b> is a null pointer and <b>size</b> is <b>0</b>, the size of the property value is returned
 * through <b>size</b> in <b>value</b>.
 * To obtain the complete property value, a space greater than <b>size</b> is required.
 * @return Returns {@link IRNdkErrCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_BAD_PARAMETER - if bad parameter.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_JNI_ENV_ABNORMAL - if Abnormal JNI environment.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_GET_DATA_ABNORMAL - if image get data error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DECODE_FAILED - if decode fail.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DECODE_HEAD_ABNORMAL - if image decode head error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_CREATE_DECODER_FAILED - if create decoder failed.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_THIRDPART_SKIA_ERROR - if skia error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DATA_ABNORMAL - if image input data error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DECODE_ABNORMAL - if image decode error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DATA_UNSUPPORT - if image init error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_UNKNOWN_FORMAT - if image unknown format.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_PLUGIN_REGISTER_FAILED - if register plugin fail.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_PLUGIN_CREATE_FAILED - if create plugin fail.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_INDEX_INVALID - if invalid index.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DECODE_EXIF_UNSUPPORT - if image decode exif unsupport.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_PROPERTY_NOT_EXIST - if image property not exist.
 * @see {@link ImageSourceNative}, {@link OhosImageSourceProperty}
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
int32_t OH_ImageSource_GetImageProperty(const ImageSourceNative* native,
    struct OhosImageSourceProperty* key, struct OhosImageSourceProperty* value);

/**
 * @brief Modifies the value of an image property of an <b>ImageSource</b> object.
 *
 * @param native Indicates a pointer to the {@link ImageSourceNative} object at the C++ native layer.
 * @param key Indicates a pointer to the property. For details, see {@link OhosImageSourceProperty}.
 * @param value Indicates a pointer to the new value of the property.
 * @return Returns {@link IRNdkErrCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_BAD_PARAMETER - if bad parameter.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_JNI_ENV_ABNORMAL - if Abnormal JNI environment.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_GET_DATA_ABNORMAL - if image get data error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DECODE_FAILED - if decode fail.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DECODE_HEAD_ABNORMAL - if image decode head error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_CREATE_DECODER_FAILED - if create decoder failed.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_THIRDPART_SKIA_ERROR - if skia error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DATA_ABNORMAL - if image input data error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DECODE_ABNORMAL - if image decode error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DATA_UNSUPPORT - if image init error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_UNKNOWN_FORMAT - if image unknown format.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_PLUGIN_REGISTER_FAILED - if register plugin fail.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_PLUGIN_CREATE_FAILED - if create plugin fail.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_INDEX_INVALID - if invalid index.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DECODE_EXIF_UNSUPPORT - if image decode exif unsupport.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_PROPERTY_NOT_EXIST - if image property not exist.
 * @see {@link ImageSourceNative}, {@link OhosImageSourceProperty}
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
int32_t OH_ImageSource_ModifyImageProperty(const ImageSourceNative* native,
    struct OhosImageSourceProperty* key, struct OhosImageSourceProperty* value);

/**
 * @brief Updates the data of an <b>ImageSource</b> object.
 *
 * @param native Indicates a pointer to the {@link ImageSourceNative} object at the C++ native layer.
 * @param data Indicates a pointer to the update data. For details, see {@link OhosImageSourceUpdateData}.
 * @return Returns {@link IRNdkErrCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_BAD_PARAMETER - if bad parameter.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_JNI_ENV_ABNORMAL - if Abnormal JNI environment.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_GET_DATA_ABNORMAL - if image get data error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DECODE_FAILED - if decode fail.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DECODE_HEAD_ABNORMAL - if image decode head error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_CREATE_DECODER_FAILED - if create decoder failed.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_CREATE_ENCODER_FAILED - if create encoder failed.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_CHECK_FORMAT_ERROR - if check format failed.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_THIRDPART_SKIA_ERROR - if skia error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DATA_ABNORMAL - if image input data error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST - if sharememory error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL - if sharememory data abnormal.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DECODE_ABNORMAL - if image decode error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_MALLOC_ABNORMAL - if image malloc error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DATA_UNSUPPORT - if image init error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_INIT_ABNORMAL - if image input data error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_CROP - if crop error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_UNKNOWN_FORMAT - if image unknown format.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_PLUGIN_REGISTER_FAILED - if register plugin fail.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_PLUGIN_CREATE_FAILED - if create plugin fail.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_ENCODE_FAILED - image add pixel map fail.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_HW_DECODE_UNSUPPORT - if image hardware decode unsupported.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_HW_DECODE_FAILED - if hard decode failed.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_ERR_IPC - if ipc error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_INDEX_INVALID - if invalid index.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_ALPHA_TYPE_ERROR - if hard decode failed.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_ALLOCATER_TYPE_ERROR - if hard decode failed.
 * @see {@link ImageSourceNative}, {@link OhosImageSourceUpdateData}
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
int32_t OH_ImageSource_UpdateData(const ImageSourceNative* native, struct OhosImageSourceUpdateData* data);


/**
 * @brief Releases an <b>ImageSourceNative</b> object.
 *
 * @param native Indicates a pointer to the {@link ImageSourceNative} object at the C++ native layer.
 * @return Returns {@link IRNdkErrCode} IMAGE_RESULT_SUCCESS - if the operation is successful.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_BAD_PARAMETER - if bad parameter.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_JNI_ENV_ABNORMAL - if Abnormal JNI environment.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_INVALID_PARAMETER - if invalid parameter.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_GET_DATA_ABNORMAL - if image get data error.
 * returns {@link IRNdkErrCode} IMAGE_RESULT_DATA_ABNORMAL - if image input data error.
 * @see {@link ImageSourceNative}, {@link OH_ImageSource_Create}, {@link OH_ImageSource_CreateIncremental}
 *
 * @Syscap SystemCapability.Multimedia.Image
 * @since 10
 * @version 4.0
 */
int32_t OH_ImageSource_Release(ImageSourceNative* native);
#ifdef __cplusplus
};
#endif
#endif // INTERFACES_KITS_NATIVE_INCLUDE_IMAGE_SOURCE_MDK_H_
