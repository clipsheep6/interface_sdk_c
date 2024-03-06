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

#ifndef C_INCLUDE_DRAWING_TYPEFACE_H
#define C_INCLUDE_DRAWING_TYPEFACE_H

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
 * @file drawing_typeface.h
 *
 * @brief Declares functions related to the <b>typeface</b> object in the drawing module.
 *
 * @since 11
 * @version 1.0
 */

#include "drawing_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Creates a default <b>OH_Drawing_Typeface</b> object.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @return Returns the pointer to the <b>OH_Drawing_Typeface</b> object created.
 * @since 11
 * @version 1.0
 */
OH_Drawing_Typeface* OH_Drawing_TypefaceCreateDefault(void);

/**
 * @brief Creates a <b>OH_Drawing_Typeface</b> object by file.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param path  file path.
 * @param index  file index.
 * @return Returns the pointer to the <b>OH_Drawing_Typeface</b> object created.
 * @since 12
 * @version 1.0
 */
OH_Drawing_Typeface* OH_Drawing_TypefaceCreateFromFile(const char* path, int index);

/**
 * @brief Creates a <b>OH_Drawing_Typeface</b> object by given a stream. If the stream is not a valid
 * font file, returns nullptr. Ownership of the stream is transferred, so the caller must not reference
 * it or free it again.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param OH_Drawing_MemoryStream Indicates the pointer to an <b>OH_Drawing_MemoryStream</b> object.
 * @param index  memory stream index.
 * @return Returns the pointer to the <b>OH_Drawing_Typeface</b> object created.
 * @since 12
 * @version 1.0
 */
OH_Drawing_Typeface* OH_Drawing_TypefaceCreateFromStream(OH_Drawing_MemoryStream*, int32_t index);

/**
 * @brief Destroys an <b>OH_Drawing_Typeface</b> object and reclaims the memory occupied by the object.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param OH_Drawing_Typeface Indicates the pointer to an <b>OH_Drawing_Typeface</b> object.
 * @since 11
 * @version 1.0
 */
void OH_Drawing_TypefaceDestroy(OH_Drawing_Typeface*);

/**
 * @brief Creates an <b>OH_Drawing_FontMgr</b> object, user should manage the pointer's lifecycle,
 * release pointer by {@link OH_Drawing_FontMgrDestroy}.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @return Returns the pointer to the <b>OH_Drawing_FontMgr</b> object created.
 * @since 12
 * @version 1.0
 */
OH_Drawing_FontMgr* OH_Drawing_FontMgrCreate(void);

/**
 * @brief Destroys an <b>OH_Drawing_FontMgr</b> object and reclaims the memory occupied by the object.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param OH_Drawing_FontMgr Indicates the pointer to an <b>OH_Drawing_FontMgr</b> object.
 * @since 12
 * @version 1.0
 */
void OH_Drawing_FontMgrDestroy(OH_Drawing_FontMgr*);

/**
 * @brief Get the pointer to an <b>OH_Drawing_FontStyleSet</b> object for the given font style set family name,
 * user should manage the pointer's lifecycle, release pointer by {@link OH_Drawing_FontStyleSetDestroy}.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param OH_Drawing_FontMgr Indicates the pointer to an <b>OH_Drawing_FontMgr</b> object.
 * @param familyName The family name of a font style set to be matched.
 * @return Returns the pointer to the <b>OH_Drawing_FontStyleSet</b> matched,
 *         Return the default font style set if family name is null, Return null if family name is not found.
 * @since 12
 * @version 1.0
 */
OH_Drawing_FontStyleSet* OH_Drawing_FontMgrMatchFamily(const OH_Drawing_FontMgr*, const char* familyName);

/**
 * @brief Get the pointer to an <b>OH_Drawing_Typeface</b> object based on the given font style and family name,
 * user should manage the pointer's lifecycle, release the pointer by {@link OH_Drawing_TypefaceDestroy}.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param OH_Drawing_FontMgr Indicates the pointer to an <b>OH_Drawing_FontMgr</b> object.
 * @param familyName The family name of a font style set to be matched.
 * @param fontStyle Indicates the pointer to an <b>OH_Drawing_TextFontStyle</b> object.
 * @return Returns the pointer to the <b>OH_Drawing_Typeface</b> object which is closest matching to 'style',
 *         Return the typeface in the default font style set if family name is null,
 *         Return null if family name is not found.
 * @since 12
 * @version 1.0
 */
OH_Drawing_Typeface* OH_Drawing_FontMgrMatchFamilyStyle(const OH_Drawing_FontMgr*, const char* familyName,
                                                        const OH_Drawing_TextFontStyle* fontStyle);

/**
 * @brief Get the pointer to an <b>OH_Drawing_Typeface</b> object for the given character,
 * user should manage the pointer's lifecycle, release the pointer by {@link OH_Drawing_TypefaceDestroy}.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param OH_Drawing_FontMgr Indicates the pointer to an <b>OH_Drawing_FontMgr</b> object.
 * @param familyName The family name of a font style set to be matched.
 * @param fontStyle Indicates the pointer to an <b>OH_Drawing_FontStyle</b> object to be matched.
 * @param bcp47 An array of languages which indicate the language of 'character'.
 * @param bcp47Count The array size of bcp47.
 * @param character A UTF8 value to be matched.
 * @return Returns the pointer to the <b>OH_Drawing_Typeface</b> object matched,
 *         Return the typeface in the default fallback set if familyName is null,
 *         Return null if the typeface is not found for the given character.
 * @since 12
 * @version 1.0
 */
OH_Drawing_Typeface* OH_Drawing_FontMgrMatchFamilyStyleCharacter(const OH_Drawing_FontMgr*, const char familyName[],
                                                                 const OH_Drawing_TextFontStyle* fontStyle,
                                                                 const char* bcp47[], int bcp47Count, int32_t character);

/**
 * @brief Destroys an <b>OH_Drawing_FontStyleSet</b> object and reclaims the memory occupied by the object.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param OH_Drawing_FontStyleSet Indicates the pointer to an <b>OH_DRAWING_FontStyleSet</b> object.
 * @since 12
 * @version 1.0
 */
void OH_Drawing_FontStyleSetDestroy(OH_Drawing_FontStyleSet*);

/**
 * @brief Creates an <b>OH_Drawing_TextFontStyle</b> object, user should manage the pointer lifecycle and
 * release pointer by {@Link OH_Drawing_TextFontStyleDestroy}.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param Weight Weight of font.
 * @param Width Width of font.
 * @param OH_Drawing_FontStyleSlant Slant of font.
 * @return Returns the pointer to the <b>OH_Drawing_TextFontStyle</b> object created, user need recycle pointer by
 * {@link OH_Drawing_TextFontStyleDestroy}.
 * @since 12
 * @version 1.0
 */
OH_Drawing_TextFontStyle* OH_Drawing_TextFontStyleCreate(uint32_t weight, uint32_t width, OH_Drawing_FontStyleSlant);

/**
 * @brief Destroys an <b>OH_Drawing_TextFontStyle</b> object and reclaims the memory occupied by the object.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param OH_Drawing_TextFontStyle Indicates the pointer to an <b>OH_Drawing_TextFontStyle</b> object.
 * @since 12
 * @version 1.0
 */
void OH_Drawing_TextFontStyleDestroy(OH_Drawing_TextFontStyle*);
#ifdef __cplusplus
}
#endif
/** @} */
#endif
