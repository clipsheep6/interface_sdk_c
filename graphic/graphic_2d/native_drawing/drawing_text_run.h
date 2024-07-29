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

#ifndef C_INCLUDE_DRAWING_TEXT_RUN_H
#define C_INCLUDE_DRAWING_TEXT_RUN_H

/**
 * @addtogroup Drawing
 * @{
 *
 * @brief Provides the text run capability.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 *
 * @since 14
 * @version 1.0
 */

/**
 * @file drawing_text_run.h
 *
 * @brief Declares functions related to <b>run</b> in the drawing module.
 *
 * @since 14
 * @version 1.0
 */

#include "drawing_text_declaration.h"
#include "drawing_types.h"

#ifdef __cplusplus
extern "C" {
#endif
/**
 * @brief Gets the run glyph indices ,the offset of the index relative to the entire paragraph.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param OH_Drawing_Run Indicates the pointer to an <b>OH_Drawing_Run</b> object.
 * @param start The run of start index.
 * @param length The run of length, if start and length are set to 0, then get all of the current run.
 * @return Run of glyph indices array.
 * @since 14
 * @version 1.0
 */
OH_Drawing_Array* OH_Drawing_GetRunStringIndices(OH_Drawing_Run* run, int64_t start, int64_t length);

/**
 * @brief Gets the run glyph indices by index.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param OH_Drawing_Array the run glyph indices array.
 * @param index The run of glyph index.
 * @return Run of glyph indices element.
 * @since 14
 * @version 1.0
 */
uint64_t OH_Drawing_GetRunStringIndicesElement(OH_Drawing_Array* stringIndices, size_t index);

/**
 * @brief Releases the memory run glyph indices array.
 * 
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param stringIndices glyph indices the pointer.
 * @since 14
 * @version 1.0
 */
void OH_Drawing_DestroyRunStringIndices(OH_Drawing_Array* stringIndices);

/**
 * @brief Gets the range run glyph location and length.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param OH_Drawing_Run Indicates the pointer to an <b>OH_Drawing_Run</b> object.
 * @param location The run of glyph location.
 * @param length The run of glyph length.
 * @since 14
 * @version 1.0
 */
void OH_Drawing_GetRunStringRange(OH_Drawing_Run* run, uint64_t* location, uint64_t* length);

/**
 * @brief Gets the run typographic bound.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param OH_Drawing_Run Indicates the pointer to an <b>OH_Drawing_Run</b> object.
 * @param ascent The run of ascent.
 * @param descent The run of descent.
 * @param leading The run of leading.
 * @return run typographic width.
 * @since 14
 * @version 1.0
 */
float OH_Drawing_GetRunTypographicBounds(OH_Drawing_Run* run, float* ascent, float* descent, float* leading);

/**
 * @brief Paints text on the canvas.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param OH_Drawing_Canvas Indicates the pointer to an <b>OH_Drawing_Canvas</b> object.
 * @param OH_Drawing_Run Indicates the pointer to an <b>OH_Drawing_Run</b> object.
 * @param x Indicates the x coordinate.
 * @param y Indicates the y coordinate.
 * @since 14
 * @version 1.0
 */
void OH_Drawing_RunPaint(OH_Drawing_Canvas* canvas, OH_Drawing_Run* run, double x, double y);

/**
 * @brief Gets the run image bound.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param OH_Drawing_Run Indicates the pointer to an <b>OH_Drawing_Run</b> object.
 * @return OH_Drawing_Rect The run image bounds.
 * @since 14
 * @version 1.0
 */
OH_Drawing_Rect* OH_Drawing_GetRunImageBounds(OH_Drawing_Run* run);

 /**
 * @brief Releases the memory run image bounds pointer.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param OH_Drawing_Rect Run image bounds pointer.
 * @since 14
 * @version 1.0
 */
void OH_Drawing_DestroyRunImageBounds(OH_Drawing_Rect* rect);

/**
 * @brief Gets the range glyph identifier for each character.
 * 
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param OH_Drawing_Run Indicates the pointer to an <b>OH_Drawing_Run</b> object.
 * @param start The run of start index.
 * @param length The run of length, if start and length are set to 0, then get all of the current run.
 * @return Run of glyph array.
 * @since 14
 * @version 1.0
 */
OH_Drawing_Array* OH_Drawing_GetRunGlyphs(OH_Drawing_Run* run, int64_t start, int64_t length);

/**
 * @brief Gets the glyph identifier by index.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param glyphs The run of glyph array.
 * @param index The run of glyph index.
 * @return Run of glyph element.
 * @since 14
 * @version 1.0
 */
uint16_t OH_Drawing_GetRunGlyphsElement(OH_Drawing_Array* glyphs, size_t index);

/**
 * @brief Releases the memory run glyph array.
 * 
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param glyphs The run of glyph array.
 * @since 14
 * @version 1.0
 */
void OH_Drawing_DestroyRunGlyphs(OH_Drawing_Array* glyphs);

/**
 * @brief Gets the range glyph position array.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param OH_Drawing_Run Indicates the pointer to an <b>OH_Drawing_Run</b> object.
 * @param start The run of start index.
 * @param length The run of length, if start and length are set to 0, then get all of the current run.
 * @return Run of position array.
 * @since 14
 * @version 1.0
 */
OH_Drawing_Array* OH_Drawing_GetRunPositions(OH_Drawing_Run* run, int64_t start, int64_t length);

/**
 * @brief Gets the glyph position by index.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param OH_Drawing_Array The run of position array.
 * @param index The run of glyph index.
 * @return Run of glyph position pointer.
 * @since 14
 * @version 1.0
 */
OH_Drawing_Point* OH_Drawing_GetRunPositionsElement(OH_Drawing_Array* positions, size_t index);

/**
 * @brief Releases the memory run of position array.
 * 
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param positions The run of position array.
 * @since 14
 * @version 1.0
 */
void OH_Drawing_DestroyRunPositions(OH_Drawing_Array* positions);

/**
 * @brief Gets the number of glyph.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param OH_Drawing_Run Indicates the pointer to an <b>OH_Drawing_Run</b> object.
 * @return The number of glyph.
 * @since 14
 * @version 1.0
 */
uint32_t OH_Drawing_GetRunGlyphCount(OH_Drawing_Run* run);
#ifdef __cplusplus
}
#endif
/** @} */
#endif // C_INCLUDE_DRAWING_TEXT_RUN_H
