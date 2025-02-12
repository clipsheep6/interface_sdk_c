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
 * @file drawing_point.h
 *
 * @brief Declares functions related to the <b>point</b> object in the drawing module.
 *
 * @kit ArkGraphics2D
 * @library libnative_drawing.so
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @since 11
 * @version 1.0
 */

#ifndef C_INCLUDE_DRAWING_POINT_H
#define C_INCLUDE_DRAWING_POINT_H

#include "drawing_error_code.h"
#include "drawing_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Creates an <b>OH_Drawing_Point</b> object.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param x Indicates the x-axis coordinates of the point.
 * @param y Indicates the y-axis coordinates of the point.
 * @return Returns the pointer to the <b>OH_Drawing_Point</b> object created.
 * @since 11
 * @version 1.0
 */
OH_Drawing_Point* OH_Drawing_PointCreate(float x, float y);

/**
 * @brief Gets the x-axis coordinate of the point.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param point Indicates the pointer to an <b>OH_Drawing_Point</b> object.
 * @param x Indicates the x-axis coordinate of the point.
 * @return Returns the error code.
 *         Returns {@link OH_DRAWING_SUCCESS} if the operation is successful.
 *         Returns {@link OH_DRAWING_ERROR_INVALID_PARAMETER} if point or x is nullptr.
 * @since 12
 * @version 1.0
 */
OH_Drawing_ErrorCode OH_Drawing_PointGetX(const OH_Drawing_Point* point, float* x);

/**
 * @brief Gets the y-axis coordinate of the point.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param point Indicates the pointer to an <b>OH_Drawing_Point</b> object.
 * @param y Indicates the y-axis coordinate of the point.
 * @return Returns the error code.
 *         Returns {@link OH_DRAWING_SUCCESS} if the operation is successful.
 *         Returns {@link OH_DRAWING_ERROR_INVALID_PARAMETER} if point or y is nullptr.
 * @since 12
 * @version 1.0
 */
OH_Drawing_ErrorCode OH_Drawing_PointGetY(const OH_Drawing_Point* point, float* y);

/**
 * @brief Sets the x-axis and y-axis coordinates of the point.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param point Indicates the pointer to an <b>OH_Drawing_Point</b> object.
 * @param x Indicates the x-axis coordinate of the point.
 * @param y Indicates the y-axis coordinate of the point.
 * @return Returns the error code.
 *         Returns {@link OH_DRAWING_SUCCESS} if the operation is successful.
 *         Returns {@link OH_DRAWING_ERROR_INVALID_PARAMETER} if point is nullptr.
 * @since 12
 * @version 1.0
 */
OH_Drawing_ErrorCode OH_Drawing_PointSet(OH_Drawing_Point* point, float x, float y);

/**
 * @brief Destroys an <b>OH_Drawing_Point</b> object and reclaims the memory occupied by the object.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param point Indicates the pointer to an <b>OH_Drawing_Point</b> object.
 * @since 11
 * @version 1.0
 */
void OH_Drawing_PointDestroy(OH_Drawing_Point* point);

#ifdef __cplusplus
}
#endif
/** @} */
#endif
