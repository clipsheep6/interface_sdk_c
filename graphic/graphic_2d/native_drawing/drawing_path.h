/*
 * Copyright (c) 2021-2022 Huawei Device Co., Ltd.
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

#ifndef C_INCLUDE_DRAWING_PATH_H
#define C_INCLUDE_DRAWING_PATH_H

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
 * @file drawing_path.h
 *
 * @brief Declares functions related to the <b>path</b> object in the drawing module.
 *
 * @since 8
 * @version 1.0
 */

#include "drawing_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Direction for adding closed contours.
 *
 * @since 11
 * @version 1.0
 */
typedef enum {
    /** clockwise direction for adding closed contours */
    PATH_DIRECTION_CW,
    /** counter-clockwise direction for adding closed contours */
    PATH_DIRECTION_CCW,
} OH_Drawing_PathDirection;

/**
 * @brief FillType of path
 *
 * @since 11
 * @version 1.0
 */
typedef enum {
    /** Specifies that "inside" is computed by a non-zero sum of signed edge crossings */
    PATH_FILL_TYPE_WINDING,
    /** Specifies that "inside" is computed by an odd number of edge crossings */
    PATH_FILL_TYPE_EVEN_ODD,
    /** Same as Winding, but draws outside of the path, rather than inside */
    PATH_FILL_TYPE_INVERSE_WINDING,
    /** Same as EvenOdd, but draws outside of the path, rather than inside */
    PATH_FILL_TYPE_INVERSE_EVEN_ODD,
} OH_Drawing_PathFillType;

/**
 * @brief Creates an <b>OH_Drawing_Path</b> object.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @return Returns the pointer to the <b>OH_Drawing_Path</b> object created.
 * @since 8
 * @version 1.0
 */
OH_Drawing_Path* OH_Drawing_PathCreate(void);

/**
 * @brief Creates an <b>OH_Drawing_Path</b> copy object.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param OH_Drawing_Path Indicates the pointer to an <b>OH_Drawing_Rect</b> object.
 * @return Returns the pointer to the <b>OH_Drawing_Path</b> object created.
 * @since 12
 * @version 1.0
 */
OH_Drawing_Path* OH_Drawing_PathCopy(OH_Drawing_Path*);

/**
 * @brief Destroys an <b>OH_Drawing_Path</b> object and reclaims the memory occupied by the object.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param OH_Drawing_Path Indicates the pointer to an <b>OH_Drawing_Path</b> object.
 * @since 8
 * @version 1.0
 */
void OH_Drawing_PathDestroy(OH_Drawing_Path*);

/**
 * @brief Sets the start point of a path.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param OH_Drawing_Path Indicates the pointer to an <b>OH_Drawing_Path</b> object.
 * @param x Indicates the x coordinate of the start point.
 * @param y Indicates the y coordinate of the start point.
 * @since 8
 * @version 1.0
 */
void OH_Drawing_PathMoveTo(OH_Drawing_Path*, float x, float y);

/**
 * @brief Draws a line segment from the last point of a path to the target point.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param OH_Drawing_Path Indicates the pointer to an <b>OH_Drawing_Path</b> object.
 * @param x Indicates the x coordinate of the target point.
 * @param y Indicates the y coordinate of the target point.
 * @since 8
 * @version 1.0
 */
void OH_Drawing_PathLineTo(OH_Drawing_Path*, float x, float y);

/**
 * @brief Draws an arc to a path. 
 * 
 * This is done by using angle arc mode. In this mode, a rectangle that encloses an ellipse is specified first,
 * and then a start angle and a sweep angle are specified.
 * The arc is a portion of the ellipse defined by the start angle and the sweep angle. 
 * By default, a line segment from the last point of the path to the start point of the arc is also added.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param OH_Drawing_Path Indicates the pointer to an <b>OH_Drawing_Path</b> object.
 * @param x1 Indicates the x coordinate of the upper left corner of the rectangle.
 * @param y1 Indicates the y coordinate of the upper left corner of the rectangle.
 * @param x2 Indicates the x coordinate of the lower right corner of the rectangle.
 * @param y2 Indicates the y coordinate of the lower right corner of the rectangle.
 * @param startDeg Indicates the start angle, in degrees.
 * @param sweepDeg Indicates the angle to sweep, in degrees.
 * @since 8
 * @version 1.0
 */
void OH_Drawing_PathArcTo(OH_Drawing_Path*, float x1, float y1, float x2, float y2, float startDeg, float sweepDeg);

/**
 * @brief Draws a quadratic Bezier curve from the last point of a path to the target point.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param OH_Drawing_Path Indicates the pointer to an <b>OH_Drawing_Path</b> object.
 * @param ctrlX Indicates the x coordinate of the control point.
 * @param ctrlY Indicates the y coordinate of the control point.
 * @param endX Indicates the x coordinate of the target point.
 * @param endY Indicates the y coordinate of the target point.
 * @since 8
 * @version 1.0
 */
void OH_Drawing_PathQuadTo(OH_Drawing_Path*, float ctrlX, float ctrlY, float endX, float endY);

/**
 * @brief Draws a cubic Bezier curve from the last point of a path to the target point.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param OH_Drawing_Path Indicates the pointer to an <b>OH_Drawing_Path</b> object.
 * @param ctrlX1 Indicates the x coordinate of the first control point.
 * @param ctrlY1 Indicates the y coordinate of the first control point.
 * @param ctrlX2 Indicates the x coordinate of the second control point.
 * @param ctrlY2 Indicates the y coordinate of the second control point.
 * @param endX Indicates the x coordinate of the target point.
 * @param endY Indicates the y coordinate of the target point.
 * @since 8
 * @version 1.0
 */
void OH_Drawing_PathCubicTo(
    OH_Drawing_Path*, float ctrlX1, float ctrlY1, float ctrlX2, float ctrlY2, float endX, float endY);

/**
 * @brief Adds a new contour to the path, defined by the rect, and wound in the specified direction.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param OH_Drawing_Path Indicates the pointer to an <b>OH_Drawing_Path</b> object.
 * @param left Indicates the left coordinate of the upper left corner of the rectangle.
 * @param top Indicates the top coordinate of the upper top corner of the rectangle.
 * @param right Indicates the right coordinate of the lower right corner of the rectangle.
 * @param bottom Indicates the bottom coordinate of the lower bottom corner of the rectangle.
 * @param OH_Drawing_PathDirection Indicates the path direction.
 * @since 12
 * @version 1.0
 */
void OH_Drawing_PathAddRect(OH_Drawing_Path*, float left, float top, float right, float bottom, OH_Drawing_PathDirection);

/**
 * @brief Adds a new contour to the path, defined by the round rect, and wound in the specified direction.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param OH_Drawing_Path Indicates the pointer to an <b>OH_Drawing_Path</b> object.
 * @param OH_Drawing_RoundRect Indicates the pointer to an <b>OH_Drawing_RoundRect</b> object.
 * @param OH_Drawing_PathDirection Indicates the path direction.
 * @since 12
 * @version 1.0
 */
void OH_Drawing_PathAddRoundRect(OH_Drawing_Path*, const OH_Drawing_RoundRect* roundRect, OH_Drawing_PathDirection);

/**
 * @brief Appends arc to path, as the start of new contour.Arc added is part of ellipse bounded by oval,
 * from startAngle through sweepAngle. Both startAngle and sweepAngle are measured in degrees, where zero degrees 
 * is aligned with the positive x-axis, and positive sweeps extends arc clockwise.If sweepAngle <= -360, or
 * sweepAngle >= 360; and startAngle modulo 90 is nearly zero, append oval instead of arc. Otherwise, sweepAngle
 * values are treated modulo 360, and arc may or may not draw depending on numeric rounding.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param OH_Drawing_Path Indicates the pointer to an <b>OH_Drawing_Path</b> object.
 * @param OH_Drawing_Rect Indicates the pointer to an <b>OH_Drawing_Rect</b> object.
 * @param startAngle Indicates the starting angle of arc in degrees.
 * @param sweepAngle Indicates the sweep, in degrees. Positive is clockwise.
 * @since 12
 * @version 1.0
 */
void OH_Drawing_PathAddArc(OH_Drawing_Path*, const OH_Drawing_Rect*, float startAngle, float sweepAngle);

/**
 * @brief Appends src path to path, transformed by matrix. Transformed curves may have different verbs,
 * point, and conic weights.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param OH_Drawing_Path Indicates the pointer to an <b>OH_Drawing_Path</b> object.
 * @param src Indicates the pointer to an <b>OH_Drawing_Path</b> object.
 * @param OH_Drawing_Matrix Indicates the length of the <b>OH_Drawing_Matrix</b> object.
 * @since 12
 * @version 1.0
 */
void OH_Drawing_PathAddPath(OH_Drawing_Path*, const OH_Drawing_Path* src, const OH_Drawing_Matrix*);

/**
 * @brief Return the status that point (x, y) is contained by path.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param OH_Drawing_Path Indicates the pointer to an <b>OH_Drawing_Path</b> object.
 * @param x Indicates the x-axis value of containment test.
 * @param y Indicates the y-axis value of containment test.
 * @return Returns true if the point (x, y) is contained by path.
 * @since 12
 * @version 1.0
 */
bool OH_Drawing_PathContains(OH_Drawing_Path*, float x, float y);

/**
 * @brief Transforms verb array, point array, and weight by matrix. transform may change verbs
 * and increase their number. path is replaced by transformed data.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param OH_Drawing_Path Indicates the pointer to an <b>OH_Drawing_Path</b> object.
 * @param OH_Drawing_Matrix Indicates the pointer to an <b>OH_Drawing_Matrix</b> object.
 * @since 12
 * @version 1.0
 */
void OH_Drawing_PathTransform(OH_Drawing_Path*, const OH_Drawing_Matrix*);

/**
 * @brief Sets FillType, the rule used to fill path.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param OH_Drawing_Path Indicates the pointer to an <b>OH_Drawing_Path</b> object.
 * @param OH_Drawing_PathFillType Indicates the add path's fill type.
 * @since 12
 * @version 1.0
 */
void OH_Drawing_SetFillStyle(OH_Drawing_Path*, OH_Drawing_PathFillType);

/**
 * @brief Closes a path. A line segment from the start point to the last point of the path is added.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param OH_Drawing_Path Indicates the pointer to an <b>OH_Drawing_Path</b> object.
 * @since 8
 * @version 1.0
 */
void OH_Drawing_PathClose(OH_Drawing_Path*);

/**
 * @brief Resets path data.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param OH_Drawing_Path Indicates the pointer to an <b>OH_Drawing_Path</b> object.
 * @since 8
 * @version 1.0
 */
void OH_Drawing_PathReset(OH_Drawing_Path*);

#ifdef __cplusplus
}
#endif
/** @} */
#endif
