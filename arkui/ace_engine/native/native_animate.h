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

#ifndef ARKUI_NATIVE_ANIMATE_H
#define ARKUI_NATIVE_ANIMATE_H

#include <cstdint>

#include "native_type.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
* @brief Defines the expected frame rate range of the animation.
*
* @since 12
*/
typedef struct {
    /** Expected minimum frame rate. */
    uint32_t min;
    /** Expected maximum frame rate. */
    uint32_t max;
    /** Expected optimal frame rate. */
    uint32_t expected;
} ArkUI_ExpectedFrameRateRange;

/**
* @brief Defines the callback type for when the animation playback is complete.
*
* @since 12
*/
typedef struct {
    /** Type of the <b>onFinish</b> callback. */
    ArkUI_FinishCallbackType type;
    /** Callback invoked when the animation playback is complete. */
    void (*callback)(void* userData);
    /** Custom type. */
    void* userData;
} ArkUI_AnimateCompleteCallback;

/**
* @brief Defines the animation configuration.
*
* @since 12
*/
typedef struct ArkUI_AnimateOption ArkUI_AnimateOption;

/**
* @brief Provides the definition of the interpolation object of the curve.
*
* @since 12
*/
struct ArkUI_Curve;

/**
* @brief Defines the interpolation object pointer definition of the curve.
*
* @since 12
*/
typedef struct ArkUI_Curve* ArkUI_CurveHandle;

/**
* @brief Defines the keyframe animation parameter object.
*
* @since 12
*/
typedef struct ArkUI_KeyframeAnimateOption ArkUI_KeyframeAnimateOption;

/**
* @brief Defines the animator animation parameter object.
*
* @since 12
*/
typedef struct ArkUI_AnimatorOption ArkUI_AnimatorOption;

/**
* @brief Defines the animator animation object pointer.
*
* @since 12
*/
typedef struct ArkUI_Animator* ArkUI_AnimatorHandle;

/**
* @brief Define the animator callback event object.

* @since 12
*/
struct ArkUI_AnimatorEvent;

/**
* @brief Define the animator callback object when receiving a frame.

* @since 12
*/
struct ArkUI_AnimatorOnFrameEvent;

/**
 * @brief Implements the native animation APIs provided by ArkUI.
 *
 * @version 1
 * @since 12
 */
typedef struct {
    /**
    * @brief Defines an explicit animation.
    *
    * @note Make sure the component attributes to be set in the event closure have been set before.
    *
    * @param context UIContext。
    * @param option Indicates the pointer to an animation configuration.
    * @param update Indicates the animation closure. The system automatically inserts a transition animation
    * for the state change caused by the closure.
    * @param complete Indicates the callback to be invoked when the animation playback is complete.
    * @return Returns the error code.
    *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
    *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
    */
    int32_t (*animateTo)(ArkUI_ContextHandle context, ArkUI_AnimateOption* option, ArkUI_ContextCallback* update,
        ArkUI_AnimateCompleteCallback* complete);

    /**
     * @brief Keyframe animation interface
     *
     * @param context UIContext instance.
     * @param option Keyframe animation parameters.
     * @return Error code.
     * {@link ARKUI_ERROR_CODE_NO_ERROR} Success.
     * {@link ARKUI_ERROR_CODE_PARAM_INVALID} Function parameter exception.
     */
    int32_t (*keyframeAnimateTo)(ArkUI_ContextHandle context,
                                 ArkUI_KeyframeAnimateOption *option);

    /**
     * @brief Create animator animation object
     *
     * @param context UIContext instance.
     * @param option animator animation parameters.
     * @return animator animation object pointer. Return NULL when function
     * parameter exception.
     */
    ArkUI_AnimatorHandle (*createAnimator)(ArkUI_ContextHandle context,
                                           ArkUI_AnimatorOption *option);

    /**
     * @brief Destroy animator animation object.
     *
     * @param animator animator animation object.
     */
    void (*disposeAnimator)(ArkUI_AnimatorHandle animator);
} ArkUI_NativeAnimateAPI_1;

/**
* @brief Creates an animation configuration.
*
* @return Returns the pointer to the created animation configuration.
* @since 12
*/
ArkUI_AnimateOption* OH_ArkUI_AnimateOption_Create();

/**
* @brief Destroys an animation configuration.
*
* @since 12
*/
void OH_ArkUI_AnimateOption_Dispose(ArkUI_AnimateOption* option);

/**
* @brief Obtains the animation duration, in milliseconds.
*
* @param option Indicates the pointer to an animation configuration.
* @return Returns the duration.
* @since 12
*/
uint32_t OH_ArkUI_AnimateOption_GetDuration(ArkUI_AnimateOption* option);

/**
* @brief Obtains the animation playback speed.
*
* @param option Indicates the pointer to an animation configuration.
* @return Returns the animation playback speed.
* @since 12
*/
float OH_ArkUI_AnimateOption_GetTempo(ArkUI_AnimateOption* option);

/**
* @brief Obtains the animation curve.
*
* @param option Indicates the pointer to an animation configuration.
* @return Returns the animated curve.
* @since 12
*/
ArkUI_AnimationCurve OH_ArkUI_AnimateOption_GetCurve(ArkUI_AnimateOption* option);

/**
* @brief Obtains the animation delay, in milliseconds.
*
* @param option Indicates the pointer to an animation configuration.
* @return Returns the animation delay.
* @since 12
*/
int32_t OH_ArkUI_AnimateOption_GetDelay(ArkUI_AnimateOption* option);

/**
* @brief Obtains the number of times that an animation is played.
*
* @param option Indicates the pointer to an animation configuration.
* @return Returns the number of times that the animation is played.
* @since 12
*/
int32_t OH_ArkUI_AnimateOption_GetIterations(ArkUI_AnimateOption* option);

/**
* @brief Obtains the animation playback mode.
*
* @param option Indicates the pointer to an animation configuration.
* @return Returns the animation playback mode.
* @since 12
*/
ArkUI_AnimationPlayMode OH_ArkUI_AnimateOption_GetPlayMode(ArkUI_AnimateOption* option);

/**
* @brief Obtains the expected frame rate range of an animation.
*
* @param option Indicates the pointer to an animation configuration.
* @return Returns the expected frame rate range.
* @since 12
*/
ArkUI_ExpectedFrameRateRange* OH_ArkUI_AnimateOption_GetExpectedFrameRateRange(ArkUI_AnimateOption* option);

/**
* @brief Sets the animation duration.
*
* @param option Indicates the pointer to an animation configuration.
* @param value Indicates the duration, in milliseconds.
* @since 12
*/
void OH_ArkUI_AnimateOption_SetDuration(ArkUI_AnimateOption* option, int32_t value);

/**
* @brief Sets the animation playback speed.
*
* @param option Indicates the pointer to an animation configuration.
* @param value Indicates the animation playback speed.
* @since 12
*/
void OH_ArkUI_AnimateOption_SetTempo(ArkUI_AnimateOption* option, float value);

/**
* @brief Sets the animation curve.
*
* @param option Indicates the pointer to an animation configuration.
* @param value Indicates the animated curve.
* @since 12
*/
void OH_ArkUI_AnimateOption_SetCurve(ArkUI_AnimateOption* option, ArkUI_AnimationCurve value);

/**
* @brief Sets the animation delay.
*
* @param option Indicates the pointer to an animation configuration.
* @param value Indicates the animation delay.
* @since 12
*/
void OH_ArkUI_AnimateOption_SetDelay(ArkUI_AnimateOption* option, int32_t value);

/**
* @brief Sets the number of times that an animation is played.
*
* @param option Indicates the pointer to an animation configuration.
* @param value Indicates the number of times that the animation is played.
* @since 12
*/
void OH_ArkUI_AnimateOption_SetIterations(ArkUI_AnimateOption* option, int32_t value);

/**
* @brief Sets the animation playback mode.
*
* @param option Indicates the pointer to an animation configuration.
* @param value Indicates the animation playback mode.
* @since 12
*/
void OH_ArkUI_AnimateOption_SetPlayMode(ArkUI_AnimateOption* option, ArkUI_AnimationPlayMode value);

/**
* @brief Sets the expected frame rate range of an animation.
*
* @param option Indicates the pointer to an animation configuration.
* @param value Indicates the expected frame rate range.
* @since 12
*/
void OH_ArkUI_AnimateOption_SetExpectedFrameRateRange(ArkUI_AnimateOption* option, ArkUI_ExpectedFrameRateRange* value);

/**
 * @brief Set the animation curve of the animation.
 *
 * @param option animator animation parameter.
 * @param value animation curve parameter.
 * @since 12
 */
void OH_ArkUI_AnimateOption_SetICurve(ArkUI_AnimateOption* option,
                                      ArkUI_CurveHandle value);

/**
 * @brief Get the animation curve of the animation.
 *
 * @param option animator animation parameter.
 * @return animation curve of the animation.
 * @since 12
 */
ArkUI_CurveHandle OH_ArkUI_AnimateOption_GetICurve(ArkUI_AnimateOption* option);

/**
 * @brief Get the keyframe animation parameter.
 *
 * @param size number of keyframe animation states.
 * @return keyframe animation parameter object. Returns NULL when size is less
 * than 0.
 * @since 12
 */
ArkUI_KeyframeAnimateOption* OH_ArkUI_KeyframeAnimateOption_Create(int32_t size);

/**
 * @brief Destroy keyframe animation parameters.
 *
 * @param option Keyframe animation parameter object.
 * @since 12
 */
void OH_ArkUI_KeyframeAnimateOption_Dispose(ArkUI_KeyframeAnimateOption* option);

/**
 * @brief Set the overall delay time of the keyframe animation in ms
 * (milliseconds). The default is no delay.
 *
 * @param option Keyframe animation parameters.
 * @param value Delay time, in ms (milliseconds).
 * @return Error code.
 * {@link ARKUI_ERROR_CODE_NO_ERROR} Success.
 * {@link ARKUI_ERROR_CODE_PARAM_INVALID} Function parameter exception.
 */
int32_t OH_ArkUI_KeyframeAnimateOption_SetDelay(ArkUI_KeyframeAnimateOption* option,
                                        int32_t value);

/**
 * @brief Set the number of animation playbacks for the keyframe animation. The
 * default is to play once. When set to -1, it means unlimited playback. When
 * set to 0, it means no animation effect.
 *
 * @param option Keyframe animation parameters.
 * @param value Number of animation playbacks.
 * @return Error code.
 * {@link ARKUI_ERROR_CODE_NO_ERROR} Success.
 * {@link ARKUI_ERROR_CODE_PARAM_INVALID} Function parameter exception.
 */
int32_t OH_ArkUI_KeyframeAnimateOption_SetIterations(
    ArkUI_KeyframeAnimateOption* option, int32_t value);

/**
 * @brief Set the callback for the completion of keyframe animation playback.
 * Called when all keyframe animations have been played.
 *
 * @param option Keyframe animation parameters.
 * @param userData User-defined object pointer.
 * @param onFinish Callback method.
 * @return Error code.
 * {@link ARKUI_ERROR_CODE_NO_ERROR} Success.
 * {@link ARKUI_ERROR_CODE_PARAM_INVALID} Function parameter exception.
 */
int32_t OH_ArkUI_KeyframeAnimateOption_RegisterOnFinishCallback(
    ArkUI_KeyframeAnimateOption* option, void* userData,
    void (*onFinish)(void* userData));

/**
 * @brief Set the duration of a keyframe animation in milliseconds.
 *
 * @param option Keyframe animation parameters.
 * @param value Duration. In milliseconds.
 * @param index Status index value.
 * @return error code.
 * {@link ARKUI_ERROR_CODE_NO_ERROR} Success.
 * {@link ARKUI_ERROR_CODE_PARAM_INVALID} Function parameter exception.
 */
int32_t OH_ArkUI_KeyframeAnimateOption_SetDuration(
    ArkUI_KeyframeAnimateOption* option, int32_t value, int32_t index);

/**
 * @brief Set the animation curve used by a keyframe in a keyframe animation.
 *
 * @note Since the duration of springMotion, responsiveSpringMotion, and
 * interpolatingSpring curves is not effective, these three curves are not
 * supported.
 * @param option Keyframe animation parameter.
 * @param value Animation curve used by this keyframe.
 * @param index State index value.
 * @return error code.
 * {@link ARKUI_ERROR_CODE_NO_ERROR} Success.
 * {@link ARKUI_ERROR_CODE_PARAM_INVALID} Function parameter exception.
 */
int32_t OH_ArkUI_KeyframeAnimateOption_SetCurve(ArkUI_KeyframeAnimateOption* option,
                                        ArkUI_CurveHandle value, int32_t index);

/**
 * @brief A closure function that sets the state at the keyframe moment, that
 * is, the state to be reached at the keyframe moment.
 *
 * @param option Keyframe animation parameter.
 * @param event Closure function.
 * @param userData User-defined object pointer.
 * @param index State index value.
 * @return Error code.
 * {@link ARKUI_ERROR_CODE_NO_ERROR} Success.
 * {@link ARKUI_ERROR_CODE_PARAM_INVALID} Function parameter exception.
 */
int32_t OH_ArkUI_KeyframeAnimateOption_RegisterOnEventCallback(
    ArkUI_KeyframeAnimateOption* option, void* userData,
    void (*event)(void* userData), int32_t index);

/**
 * @brief Get the overall delay time of the keyframe.
 *
 * @param option Keyframe animation parameters.
 * @return Overall delay time.
 * @since 12
 */
int32_t OH_ArkUI_KeyframeAnimateOption_GetDelay(ArkUI_KeyframeAnimateOption* option);

/**
 * @brief Get the number of keyframe animation playbacks.
 *
 * @param option Keyframe animation parameters.
 * @return Animation playback times.
 * @since 12
 */
int32_t OH_ArkUI_KeyframeAnimateOption_GetIterations(
    ArkUI_KeyframeAnimateOption* option);

/**
 * @brief Get the duration of a certain state of the keyframe animation.
 *
 * @param option Keyframe animation parameters.
 * @param index State index value.
 * @return Duration. The unit is milliseconds.
 * @since 12
 */
int32_t OH_ArkUI_KeyframeAnimateOption_GetDuration(ArkUI_KeyframeAnimateOption* option,
                                           int32_t index);

/**
 * @brief Get the animation curve of a certain state of the keyframe animation.
 *
 * @param option Keyframe animation parameters.
 * @param index State index value.
 * @return Animation curve.
 * @since 12
 */
ArkUI_CurveHandle OH_ArkUI_KeyframeAnimateOption_GetCurve(ArkUI_KeyframeAnimateOption* option,
                                        int32_t index);

/**
 * @brief Create animator animation object parameters.
 *
 * @note When keyframeSize is greater than 0, the animation interpolation start
 * point defaults to 0, and the animation interpolation end point mode value
 * is 1. Settings are not supported.
 * @param keyframeSize Number of keyframes.
 * @return animator animation object parameter pointer.
 * @since 12
 */
ArkUI_AnimatorOption* OH_ArkUI_AnimatorOption_Create(int32_t keyframeSize);

/**
 * @brief Destroy animator animation object parameters.
 *
 * @since 12
 */
void OH_ArkUI_ArkUI_AnimatorOption_Dispose(ArkUI_AnimatorOption* option);

/**
 * @brief Set the duration of the animator animation playback in milliseconds.
 *
 * @param option animator animation object parameters.
 * @param value playback duration in milliseconds.
 * @return error code.
 * {@link ARKUI_ERROR_CODE_NO_ERROR} success.
 * {@link ARKUI_ERROR_CODE_PARAM_INVALID} function parameter exception.
 */
int32_t OH_ArkUI_AnimatorOption_SetDuration(ArkUI_AnimatorOption* option,
                                            int32_t value);

/**
 * @brief Set the delay duration of the animator animation, in milliseconds.
 *
 * @param option animator animation object parameter.
 * @param value delay duration, in milliseconds.
 * @return error code.
 * {@link ARKUI_ERROR_CODE_NO_ERROR} success.
 * {@link ARKUI_ERROR_CODE_PARAM_INVALID} function parameter exception.
 */
int32_t OH_ArkUI_AnimatorOption_SetDelay(ArkUI_AnimatorOption* option,
                                         int32_t value);

/**
 * @brief Set the number of times the animator animation is played. Set to 0 to
 * not play, set to -1 to play infinitely.
 *
 * @note Setting to a negative number other than -1 is considered an invalid
 * value. Animations with invalid values ​​are played once by default.
 * @param option animator animation object parameter.
 * @param value animation playback times.
 * @return error code.
 * {@link ARKUI_ERROR_CODE_NO_ERROR} success.
 * {@link ARKUI_ERROR_CODE_PARAM_INVALID} function parameter exception.
 */
int32_t OH_ArkUI_AnimatorOption_SetIterations(ArkUI_AnimatorOption* option,
                                              int32_t value);

/**
 * @brief Set whether the animator animation is restored to the initial state
 * after execution.
 *
 * @param option animator animation object parameter.
 * @param value whether the animation is restored to the initial state after
 * execution.
 * @return error code.
 * {@link ARKUI_ERROR_CODE_NO_ERROR} success.
 * {@link ARKUI_ERROR_CODE_PARAM_INVALID} Function parameter exception.
 */
int32_t OH_ArkUI_AnimatorOption_SetFill(ArkUI_AnimatorOption* option,
                                        ArkUI_AnimationFillMode value);

/**
 * @brief Set the animator animation playback direction.
 *
 * @param option animator animation object parameters.
 * @param value animation playback direction.
 * @return error code.
 * {@link ARKUI_ERROR_CODE_NO_ERROR} Success.
 * {@link ARKUI_ERROR_CODE_PARAM_INVALID} Function parameter exception.
 */
int32_t OH_ArkUI_AnimatorOption_SetDirection(ArkUI_AnimatorOption* option,
                                             ArkUI_AnimationDirection value);

/**
 * @brief Set the animator animation interpolation curve.
 *
 * @note SpringCurve, springMotion, responsiveSpringMotion, interpolatingSpring
 * are not supported customCurve animation curve
 *
 * @param option animator animation object parameter.
 * @param value animation interpolation curve.
 * @return error code.
 * {@link ARKUI_ERROR_CODE_NO_ERROR} Success.
 * {@link ARKUI_ERROR_CODE_PARAM_INVALID} Function parameter exception.
 */
int32_t OH_ArkUI_AnimatorOption_SetCurve(ArkUI_AnimatorOption* option,
                                         ArkUI_CurveHandle value);

/**
 * @brief Set the animator animation interpolation start point.
 * @note This method does not work when the Animator animation is a keyframe
 * animation.
 *
 * @param option animator animation object parameter.
 * @param value animation interpolation start point.
 * @return error code.
 * {@link ARKUI_ERROR_CODE_NO_ERROR} success.
 * {@link ARKUI_ERROR_CODE_PARAM_INVALID} function parameter exception.
 */
int32_t OH_ArkUI_AnimatorOption_SetBegin(ArkUI_AnimatorOption* option,
                                         float value);

/**
 * @brief Set the animator animation interpolation end point.
 * @note This method does not work when the Animator animation is a keyframe
 * animation.
 *
 * @param option animator animation object parameter.
 * @param value animation interpolation end point.
 * @return error code.
 * {@link ARKUI_ERROR_CODE_NO_ERROR} success.
 * {@link ARKUI_ERROR_CODE_PARAM_INVALID} function parameter exception.
 */
int32_t OH_ArkUI_AnimatorOption_SetEnd(ArkUI_AnimatorOption* option,
                                       float value);

/**
 * @brief Set the expected frame rate range of the animator animation.
 *
 * @param option animator animation object parameter.
 * @param value expected frame rate range object.
 * @return error code.
 * {@link ARKUI_ERROR_CODE_NO_ERROR} success.
 * {@link ARKUI_ERROR_CODE_PARAM_INVALID} Function parameter exception.
 */
int32_t OH_ArkUI_AnimatorOption_SetExpectedFrameRateRange(
    ArkUI_AnimatorOption *option, ArkUI_ExpectedFrameRateRange* value);

/**
 * @brief Set animator animation keyframe parameters.
 *
 * @param option animator animation object parameters.
 * @param time keyframe time. Value range: [0, 1]
 * @param value keyframe value.
 * @param index keyframe index value.
 * @return error code.
 * {@link ARKUI_ERROR_CODE_NO_ERROR} Success.
 * {@link ARKUI_ERROR_CODE_PARAM_INVALID} Function parameter exception.
 */
int32_t OH_ArkUI_AnimatorOption_SetKeyframe(ArkUI_AnimatorOption* option,
                                            float time, float value,
                                            int32_t index);

/**
 * @brief Set the animator animation keyframe curve type.
 *
 * @note SpringCurve, springMotion, responsiveSpringMotion, interpolatingSpring
 * are not supported customCurve animation curve
 *
 * @param option animator animation object parameter.
 * @param value animation interpolation curve.
 * @param index keyframe index value.
 * @return error code.
 * {@link ARKUI_ERROR_CODE_NO_ERROR} success.
 * {@link ARKUI_ERROR_CODE_PARAM_INVALID} function parameter exception.
 */
int32_t OH_ArkUI_AnimatorOption_SetKeyframeCurve(ArkUI_AnimatorOption* option,
                                                 ArkUI_CurveHandle value,
                                                 int32_t index);
/**
 * @brief Get the duration of the animator animation playback.
 *
 * @param option animator animation parameter.
 * @return animation playback duration, in milliseconds.
 * @since 12
 */
int32_t OH_ArkUI_AnimatorOption_GetDuration(ArkUI_AnimatorOption* option);

/**
 * @brief Get the animator animation delay playback duration.
 *
 * @param option animator animation parameters.
 * @return animation delay playback duration, in milliseconds.
 * @since 12
 */
int32_t OH_ArkUI_AnimatorOption_GetDelay(ArkUI_AnimatorOption* option);

/**
 * @brief Get the animator animation playback count.
 *
 * @param option animator animation parameters.
 * @return animation playback count.
 * @since 12
 */
int32_t OH_ArkUI_AnimatorOption_GetIterations(ArkUI_AnimatorOption* option);

/**
 * @brief Get whether the animator animation is restored to the initial state
 * after execution.
 *
 * @param option animator animation parameters.
 * @return Whether it is restored to the initial state after execution.
 * @since 12
 */
ArkUI_AnimationFillMode OH_ArkUI_AnimatorOption_GetFill(ArkUI_AnimatorOption* option);

/**
 * @brief Get the animator animation playback direction.
 *
 * @param option animator animation parameters.
 * @return animation playback direction.
 * @since 12
 */
ArkUI_AnimationDirection OH_ArkUI_AnimatorOption_GetDirection(ArkUI_AnimatorOption* option);

/**
 * @brief Get the animator animation interpolation curve.
 *
 * @param option animator animation parameter.
 * @return animation interpolation curve.
 * @since 12
 */
ArkUI_CurveHandle OH_ArkUI_AnimatorOption_GetCurve(ArkUI_AnimatorOption* option);

/**
 * @brief Get the animator animation interpolation starting point.
 *
 * @param option animator animation parameter.
 * @return animation interpolation starting point.
 * @since 12
 */
float OH_ArkUI_AnimatorOption_GetBegin(ArkUI_AnimatorOption* option);

/**
 * @brief Get the end point of the animator animation interpolation.
 *
 * @param option animator animation parameter.
 * @return animation interpolation end point.
 * @since 12
 */
float OH_ArkUI_AnimatorOption_GetEnd(ArkUI_AnimatorOption* option);

/**
 * @brief Get the expected frame rate range of the animator animation.
 *
 * @param option animator animation parameter.
 * @return expected frame rate range object pointer.
 * @since 12
 */
ArkUI_ExpectedFrameRateRange* OH_ArkUI_AnimatorOption_GetExpectedFrameRateRange(
    ArkUI_AnimatorOption* option);

/**
 * @brief Get the animator animation key frame time.
 *
 * @param option animator animation object parameter.
 * @param index key frame index value.
 * @return key frame time.
 * @since 12
 */
float OH_ArkUI_AnimatorOption_GetKeyframeTime(ArkUI_AnimatorOption* option,
                                              int32_t index);

/**
 * @brief Get the animator animation key frame value.
 *
 * @param option animator animation object parameter.
 * @param index key frame index value.
 * @return key frame value.
 * @since 12
 */
float OH_ArkUI_AnimatorOption_GetKeyframeValue(ArkUI_AnimatorOption* option,
                                               int32_t index);

/**
 * @brief Get the animator animation keyframe animation interpolation curve.
 *
 * @param option animator animation object parameter.
 * @param index keyframe index value.
 * @return animation interpolation curve.
 * @since 12
 */
ArkUI_CurveHandle OH_ArkUI_AnimatorOption_GetKeyframeCurve(
    ArkUI_AnimatorOption* option, int32_t index);

/**
 * @brief Get the user-defined object in the animation event object.
 *
 * @param event Animation event object.
 * @return User-defined object.
 * @since 12
 */
void* OH_ArkUI_AnimatorEvent_GetUserData(ArkUI_AnimatorEvent* event);

/**
 * @brief Get the user-defined object in the animation event object.
 *
 * @param event Animation event object.
 * @return User-defined object.
 * @since 12
 */
void* OH_ArkUI_AnimatorOnFrameEvent_GetUserData(ArkUI_AnimatorOnFrameEvent* event);

/**
 * @brief Get the current progress in the animation event object.
 *
 * @param event Animation event object.
 * @return Animation progress.
 * @since 12
 */
float OH_ArkUI_AnimatorOnFrameEvent_GetValue(ArkUI_AnimatorOnFrameEvent* event);

/**
 * @brief Set the callback when the animator animation receives a frame.
 *
 * @param animator animator animation object.
 * @param userData user-defined parameters.
 * @param callback callback function.
 * @return error code.
 * {@link ARKUI_ERROR_CODE_NO_ERROR} success.
 * {@link ARKUI_ERROR_CODE_PARAM_INVALID} function parameter exception.
 */
int32_t OH_ArkUI_Animator_RegisterOnFrameCallback(
    ArkUI_AnimatorHandle animator, void* userData,
    void (*callback)(ArkUI_AnimatorOnFrameEvent* event));

/**
 * @brief Set the callback when the animator animation is completed.
 *
 * @param animator animator animation object.
 * @param userData user-defined parameters.
 * @param callback callback function.
 * @return error code.
 * {@link ARKUI_ERROR_CODE_NO_ERROR} success.
 * {@link ARKUI_ERROR_CODE_PARAM_INVALID} function parameter exception.
 */
int32_t OH_ArkUI_Animator_RegisterOnFinishCallback(
    ArkUI_AnimatorHandle animator, void* userData,
    void (*callback)(ArkUI_AnimatorEvent* event));

/**
 * @brief Set the callback when the animator animation is canceled.
 *
 * @param animator animator animation object.
 * @param userData user-defined parameters.
 * @param callback callback function.
 * @return error code.
 * {@link ARKUI_ERROR_CODE_NO_ERROR} Success.
 * {@link ARKUI_ERROR_CODE_PARAM_INVALID} Function parameter exception.
 */
int32_t OH_ArkUI_Animator_RegisterOnCancelCallback(
    ArkUI_AnimatorHandle animator, void* userData,
    void (*callback)(ArkUI_AnimatorEvent* event));

/**
 * @brief Set the callback when the animator animation repeats.
 *
 * @param animator animator animation object.
 * @param userData User-defined parameters.
 * @param callback callback function.
 * @return Error code.
 * {@link ARKUI_ERROR_CODE_NO_ERROR} Success.
 * {@link ARKUI_ERROR_CODE_PARAM_INVALID} Function parameter exception.
 */
int32_t OH_ArkUI_Animator_RegisterOnRepeatCallback(
    ArkUI_AnimatorHandle animator, void* userData,
    void (*callback)(ArkUI_AnimatorEvent* event));

/**
 * @brief Update animator animation.
 *
 * @param animator animator animation object.
 * @param option animator animation parameter.
 * @return error code.
 * {@link ARKUI_ERROR_CODE_NO_ERROR} Success.
 * {@link ARKUI_ERROR_CODE_PARAM_INVALID} Function parameter exception.
 */
int32_t OH_ArkUI_Animator_ResetAnimatorOption(ArkUI_AnimatorHandle animator,
                                              ArkUI_AnimatorOption* option);

/**
 * @brief Start animator animation.
 *
 * @param animator animator animation object.
 * @return error code.
 * {@link ARKUI_ERROR_CODE_NO_ERROR} success.
 * {@link ARKUI_ERROR_CODE_PARAM_INVALID} function parameter exception.
 */
int32_t OH_ArkUI_Animator_Play(ArkUI_AnimatorHandle animator);

/**
 * @brief end animator animation.
 *
 * @param animator animator animation object.
 * @return error code.
 * {@link ARKUI_ERROR_CODE_NO_ERROR} success.
 * {@link ARKUI_ERROR_CODE_PARAM_INVALID} function parameter exception.
 */
int32_t OH_ArkUI_Animator_Finish(ArkUI_AnimatorHandle animator);

/**
 * @brief Pause animator animation.
 *
 * @param animator animator animation object.
 * @return error code.
 * {@link ARKUI_ERROR_CODE_NO_ERROR} Success.
 * {@link ARKUI_ERROR_CODE_PARAM_INVALID} Function parameter exception.
 */
int32_t OH_ArkUI_Animator_Pause(ArkUI_AnimatorHandle animator);

/**
 * @brief Cancel animator animation.
 *
 * @param animator animator animation object.
 * @return error code.
 * {@link ARKUI_ERROR_CODE_NO_ERROR} Success.
 * {@link ARKUI_ERROR_CODE_PARAM_INVALID} Function parameter exception.
 */
int32_t OH_ArkUI_Animator_Cancel(ArkUI_AnimatorHandle animator);

/**
 * @brief Play animator animation in reverse order.
 *
 * @param animator animator animation object.
 * @return Error code.
 * {@link ARKUI_ERROR_CODE_NO_ERROR} Success.
 * {@link ARKUI_ERROR_CODE_PARAM_INVALID} Function parameter exception.
 */
int32_t OH_ArkUI_Animator_Reverse(ArkUI_AnimatorHandle animator);

/**
 * @brief Interpolation curve initialization function, which can create an
 * interpolation curve object based on the input parameters.
 *
 * @param curve Curve type.
 * @return Curve interpolation object pointer. Returns NULL if parameter is
 * abnormal.
 */
ArkUI_CurveHandle OH_ArkUI_Curve_InitCurve(ArkUI_AnimationCurve curve);

/**
 * @brief Constructs a step curve object.
 *
 * @param count The number of steps, which needs to be a positive integer, with
 * a range of values: [1, +∞).
 * @param end A step change occurs at the start or end of each interval.
 * true: a step change occurs at the end, false: a step change occurs at the
 * start.
 * @return Curve interpolation object pointer. Returns NULL if parameter is
 * abnormal.
 */
ArkUI_CurveHandle OH_ArkUI_Curve_StepsCurve(int32_t count, bool end);

/**
 * @brief Constructs a third-order Bezier curve object.
 *
 * @param x1 determines the horizontal coordinate of the first point of the
 * Bezier curve, the value range is: [0, 1]. When the set value is less than 0,
 * it is processed as 0; when the set value is greater than 1, it is processed
 * as 1.
 * @param y1 determines the vertical coordinate of the first point of the Bezier
 * curve.
 * @param x2 determines the horizontal coordinate of the second point of the
 * Bezier curve, the value range is: [0, 1]. When the set value is less than 0,
 * it is processed as 0; when the set value is greater than 1, it is processed
 * as 1.
 * @param y2 determines the vertical coordinate of the second point of the
 * Bezier curve.
 * @return The interpolation object pointer of the curve. If the parameter is
 * abnormal, NULL is returned.
 */
ArkUI_CurveHandle OH_ArkUI_Curve_CubicBezierCurve(float x1, float y1, float x2,
                                                  float y2);

/**
 * @brief Constructs a spring curve object. The shape of the curve is determined
 * by the spring parameters, and the animation duration is controlled by the
 * duration parameter in animation and animateTo.
 *
 * @param velocity Initial velocity. It is the parameter that affects the
 * elastic animation due to external factors. Its purpose is to ensure that the
 * object smoothly transitions from the previous motion state to the elastic
 * animation. The velocity is the normalized velocity, and its value is equal to
 * the actual velocity at the beginning of the animation divided by the change
 * value of the animation attribute.
 * @param mass Mass. The force-bearing object of the elastic system will have an
 * inertial effect on the elastic system. The larger the mass, the greater the
 * amplitude of the oscillation, and the slower the speed of returning to the
 * equilibrium position.
 * @param stiffness Stiffness. It is the degree to which an object deforms
 * against the applied force. In an elastic system, the greater the stiffness,
 * the stronger the ability to resist deformation, and the faster it returns to
 * the equilibrium position.
 * @param damping Damping. Used to describe the oscillation and attenuation of
 * the system after being disturbed. The greater the damping, the fewer
 * oscillations and smaller the amplitude of the elastic motion.
 * @return Curve interpolation object pointer. If the parameters are abnormal,
 * return NULL.
 */
ArkUI_CurveHandle OH_ArkUI_Curve_SpringCurve(float velocity, float mass,
                                             float stiffness, float damping);

/**
 * @brief Constructs an elastic animation curve object. If multiple elastic
 * animations are performed on the same attribute of the same object, each
 * animation will replace the previous animation and inherit the previous speed.
 * @note The animation time is determined by the curve parameters and is not
 * controlled by the duration parameters in animation and animateTo.
 *
 * @param response The natural vibration period of the spring determines the
 * speed of the spring reset.
 * @param dampingFraction The damping coefficient.
 * Values ​​greater than 0 and less than 1 are underdamped, and will exceed
 * the target value during the movement; Values ​​equal to 1 are critical
 * damping; Values ​​greater than 1 are overdamped, and will gradually
 * approach the target value during the movement.
 * @param overlapDuration The duration of the elastic animation connection. When
 * animation inheritance occurs, if the responses of the two elastic animations
 * are inconsistent, The response parameter will smoothly transition within the
 * overlapDuration time.
 * @return The interpolation object pointer of the curve. If the parameter is
 * abnormal, NULL is returned.
 */
ArkUI_CurveHandle OH_ArkUI_Curve_SpringMotion(float response,
                                              float dampingFraction,
                                              float overlapDuration);

/**
 * @brief Constructs an elastic hand-following animation curve object, which is
 * a special case of springMotion. Only the default parameters are different and
 * can be mixed with springMotion.
 * @note The animation time is determined by the curve parameters and is not
 * controlled by the duration parameters in animation and animateTo.
 *
 * @param response The natural vibration period of the spring determines the
 * speed of the spring reset.
 * @param dampingFraction damping coefficient.
 * Values ​​greater than 0 and less than 1 are underdamped, and will exceed
 * the target value during motion; Values ​​equal to 1 are critical damping;
 * Values ​​greater than 1 are overdamped, and will gradually approach the
 * target value during motion.
 * @param overlapDuration elastic animation connection duration. When animation
 * inheritance occurs, if the responses of the two elastic animations before and
 * after are inconsistent, response parameters will smoothly transition within
 * the overlapDuration time.
 * @return Curve interpolation object pointer. If the parameters are abnormal,
 * NULL is returned.
 */
ArkUI_CurveHandle OH_ArkUI_Curve_ResponsiveSpringMotion(float response,
                                                        float dampingFraction,
                                                        float overlapDuration);

/**
 * @brief Constructs an interpolator spring curve object, generates an animation
 * curve from 0 to 1, and the actual animation value is interpolated according
 * to the curve.
 * @note The animation time is determined by the curve parameters and is not
 * controlled by the duration parameters in animation and animateTo.
 *
 *
 * @param velocity Initial velocity. Parameters of the impact of external
 * factors on elastic motion. The purpose is to ensure that the object smoothly
 * transitions from the previous motion state to the elastic motion. This
 * velocity is the normalized velocity. Its value is equal to the actual
 * velocity at the beginning of the animation divided by the change value of the
 * animation property.
 * @param mass Mass. The object of the elastic system that is subjected to force
 * will have an inertial effect on the elastic system. The larger the mass, the
 * larger the amplitude of the oscillation and the slower the speed of returning
 * to the equilibrium position.
 * @param stiffness Stiffness. Indicates the degree to which the object deforms
 * against the applied force. The greater the stiffness, the stronger the
 * ability to resist deformation and the faster the speed of returning to the
 * equilibrium position.
 * @param damping Damping. Used to describe the oscillation and attenuation of
 * the system after being disturbed. The greater the damping, the fewer the
 * number of oscillations of the elastic motion and the smaller the oscillation
 * amplitude.
 * @return The interpolation object pointer of the curve. Returns NULL if the
 * parameter is abnormal.
 */
ArkUI_CurveHandle OH_ArkUI_Curve_InterpolatingSpring(float velocity, float mass,
                                                     float stiffness,
                                                     float damping);

/**
 * @brief Constructs a custom curve object.
 *
 * @param userData User-defined data.
 * @param interpolate User-defined interpolation callback function. fraction is
 * the interpolation input x value at the beginning of the animation. Value
 * range: [0,1] The return value is the y value of the curve. Value range:
 * [0,1]. When fraction is equal to 0, the return value is 0 corresponding to
 * the start of the animation. If the return value is not 0, the animation has a
 * jump effect at the start. When fraction is equal to 1, the return value is 1
 * corresponding to the end of the animation. If the return value is not 1, the
 * final value of the animation is not the value of the state variable, The
 * effect of being greater than or less than the state variable value and then
 * jumping to the state variable value appears.
 * @return The interpolation object pointer of the curve. If the parameter is
 * abnormal, NULL is returned.
 */
ArkUI_CurveHandle OH_ArkUI_Curve_CustomCurve(
    void* userData, float (*interpolate)(float fraction, void* userdata));

/**
 * @brief Destroy the custom curve object.
 *
 * @param curve Curve interpolation object pointer.
 */
void OH_ArkUI_Curve_disposeCurve(ArkUI_CurveHandle curveHandle);
#ifdef __cplusplus
};
#endif

#endif // ARKUI_NATIVE_ANIMATE_H