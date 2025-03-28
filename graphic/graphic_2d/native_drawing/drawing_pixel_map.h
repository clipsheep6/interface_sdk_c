/*
 * Copyright (c) 2024 Huawei Device Co., Ltd.
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
 * @addtogroup Drawing
 * @{
 *
 * @brief Provides functions such as 2D graphics rendering, text drawing, and image display.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 *
 * @since 8
 * @version 1.0
 */

/**
 * @file drawing_pixel_map.h
 *
 * @brief Declares functions related to the <b>pixelmap</b> object in the drawing module.
 *
 * @kit ArkGraphics2D
 * @library libnative_drawing.so
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @since 12
 * @version 1.0
 */

#ifndef C_INCLUDE_DRAWING_PIXEL_MAP_H
#define C_INCLUDE_DRAWING_PIXEL_MAP_H

#include "drawing_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Introduces the native pixel map information defined by image framework.
 * @since 12
 * @version 1.0
 */
typedef struct NativePixelMap_ NativePixelMap_;

/**
 * @brief Introduces the native pixel map information defined by image framework.
 * @since 12
 * @version 1.0
 */
typedef struct OH_PixelmapNative OH_PixelmapNative;

/**
 * @brief Gets an <b>OH_Drawing_PixelMap</b> object.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param nativePixelMap Indicates a pointer to an native pixelmap supported by image framework.
 * @return Returns the pointer to the <b>OH_Drawing_PixelMap</b> object.
 * @since 12
 * @version 1.0
 */
OH_Drawing_PixelMap* OH_Drawing_PixelMapGetFromNativePixelMap(NativePixelMap_* nativePixelMap);

/**
 * @brief Gets an <b>OH_Drawing_PixelMap</b> object.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param pixelmapNative Indicates a pointer to the <b>OH_PixelmapNative</b> object supported by image framework.
 * @return Returns the pointer to the <b>OH_Drawing_PixelMap</b> object.
 *         If nullptr is returned, the get operation fails.
 *         The possible cause of the failure is that a nullptr is passed.
 * @since 12
 * @version 1.0
 */
OH_Drawing_PixelMap* OH_Drawing_PixelMapGetFromOhPixelMapNative(OH_PixelmapNative* pixelmapNative);

/**
 * @brief Dissolves the relationship between <b>OH_Drawing_PixelMap</b> object and <b>NativePixelMap_</b> or
          <b>OH_PixelmapNative</b> which is build by 'GetFrom' function.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param pixelMap Indicates a pointer to the <b>OH_Drawing_PixelMap</b>.
 * @since 12
 * @version 1.0
 */
void OH_Drawing_PixelMapDissolve(OH_Drawing_PixelMap* pixelMap);

#ifdef __cplusplus
}
#endif
/** @} */
#endif
