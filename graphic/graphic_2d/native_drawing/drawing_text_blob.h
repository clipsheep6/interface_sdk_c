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

#ifndef C_INCLUDE_DRAWING_TEXT_BLOB_H
#define C_INCLUDE_DRAWING_TEXT_BLOB_H

/**
 * @addtogroup Drawing
 * @{
 *
 * @brief Provides functions such as 2D graphics rendering, text drawing, and image display.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 *
 * @since 11
 * @version 1.0
 */

/**
 * @file drawing_text_blob.h
 *
 * @brief Declares functions related to the <b>textBlob</b> object in the drawing module.
 *
 * @since 11
 * @version 1.0
 */

#include "drawing_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Creates an <b>OH_Drawing_TextBlobBuilder</b> object.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @return Returns the pointer to the <b>OH_Drawing_TextBlobBuilder</b> object created.
 * @since 11
 * @version 1.0
 */
OH_Drawing_TextBlobBuilder* OH_Drawing_TextBlobBuilderCreate(void);

/**
 * @brief Defines a run, supplies storage for glyphs and positions.
 *
 * @since 11
 * @version 1.0
 */
typedef struct {
    /** storage for glyph indexes in run */
    uint16_t* glyphs;
    /** storage for glyph positions in run */
    float* pos;
    /** storage for text UTF-8 code units in run */
    char* utf8text;
    /** storage for glyph clusters (index of UTF-8 code unit) */
    uint32_t* clusters;
} OH_Drawing_RunBuffer;

/**
 * @brief Alloc run with storage for glyphs and positions. The returned pointer does not need to be managed
 * by the caller and is forbidden to be used after OH_Drawing_TextBlobBuilderMake is called.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param OH_Drawing_TextBlobBuilder Indicates the pointer to an <b>OH_Drawing_TextBlobBuilder</b> object.
 * @param OH_Drawing_Font Indicates the pointer to an <b>OH_Drawing_Font</b> object.
 * @param count Indicates the number of glyphs.
 * @param OH_Drawing_Rect Indicates the optional run bounding box.
 * @since 11
 * @version 1.0
 */
const OH_Drawing_RunBuffer* OH_Drawing_TextBlobBuilderAllocRunPos(OH_Drawing_TextBlobBuilder*, const OH_Drawing_Font*,
    int32_t count, const OH_Drawing_Rect*);

/**
 * @brief Make an <b>OH_Drawing_TextBlob</b> from <b>OH_Drawing_TextBlobBuilder</b>.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param OH_Drawing_TextBlobBuilder Indicates the pointer to an <b>OH_Drawing_TextBlobBuilder</b> object.
 * @return Returns the pointer to the <b>OH_Drawing_TextBlob</b> object.
 * @since 11
 * @version 1.0
 */
OH_Drawing_TextBlob* OH_Drawing_TextBlobBuilderMake(OH_Drawing_TextBlobBuilder*);

/**
 * @brief Destroys an <b>OH_Drawing_TextBlob</b> object and reclaims the memory occupied by the object.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param OH_Drawing_TextBlob Indicates the pointer to an <b>OH_Drawing_TextBlob</b> object.
 * @since 11
 * @version 1.0
 */
void OH_Drawing_TextBlobDestroy(OH_Drawing_TextBlob*);

/**
 * @brief Destroys an <b>OH_Drawing_TextBlobBuilder</b> object and reclaims the memory occupied by the object.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param OH_Drawing_TextBlobBuilder Indicates the pointer to an <b>OH_Drawing_TextBlobBuilder</b> object.
 * @since 11
 * @version 1.0
 */
void OH_Drawing_TextBlobBuilderDestroy(OH_Drawing_TextBlobBuilder*);

#ifdef __cplusplus
}
#endif
/** @} */
#endif
