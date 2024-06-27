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
 * @addtogroup ArkUI_NativeModule
 * @{
 *
 * @brief Defines APIs for ArkUI to register drag callbacks on the native side.
 *
 * @since 12
 */

/**
 * @file native_drag_and_drop.h
 *
 * @brief Provides type definitions for <b>NativeDrag</b> APIs.
 *
 * @library libace_ndk.z.so
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @since 12
 */

#include <stdint.h>
#ifndef ARKUI_NATIVE_DRAG_AND_DROP_H
#define ARKUI_NATIVE_DRAG_AND_DROP_H

#include "ui_input_event.h"
#include "native_type.h"

//#include "udmf.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Enumerates drag results.
 *
 * @since 12
 */
typedef enum {
    /** Successful. */
    DRAG_SUCCESSFUL,

    /** Failed. */
    DRAG_FAILED,

    /** Canceled. */
    DRAG_CANCELED,
} DragResult;

/**
 * @brief Enumerates drag behivors.
 *
 * @since 12
 */
typedef enum {
    /** Copy. */
    PROPOSAL_COPY,

    /** Move. */
    PROPOSAL_MOVE,
} DropBehivor;

/**
 * @brief Enumerates preview drag status.
 *
 * @since 12
 */
typedef enum {
    /** Action detecting. */
    PRE_DRAG_STATUS_ACTION_DETECTING,

    /** Ready to trigger drag action. */
    PRE_DRAG_STATUS_READY_TO_TRIGGER_DRAG,

    /** Preview lift started. */
    PRE_DRAG_STATUS_PREVIEW_LIFT_STARTED,

    /** Preview lift finished. */
    PRE_DRAG_STATUS_PREVIEW_LIFT_FINISHED,

    /** Preview landing started. */
    PRE_DRAG_STATUS_PREVIEW_LANDING_STARTED,

    /** Preview landing finished. */
    PRE_DRAG_STATUS_PREVIEW_LANDING_FINISHED,

    /** Action canceled before drag. */
    PRE_DRAG_STATUS_CANCELED_BEFORE_DRAG,
} PreDragStatus;

/**
 * @brief Enumerates drag preview scale mode.
 *
 * @since 12
 */
typedef enum {
    /** Auto. */
    DRAG_PREVIEW_SCALE_AUTO,

    /** Disabled. */
    DRAG_PREVIEW_SCALE_DISABLED,
} DragPreviewScaleMode;

/**
 * @brief Enumerates drag status.
 *
 * @since 12
 */
typedef enum {
    /** Unknown. */
    UNKNOWN,

    /** Started. */
    DRAG_STATUS_STARTED,

    /** Ended. */
    DRAG_STATUS_ENDED,
} DragStatus;

typedef struct ArkUI_NodeEvent ArkUI_NodeEvent;

/**
 * @brief Defines the drag event.
 *
 * @since 12
 */
typedef struct ArkUI_DragEvent ArkUI_DragEvent;

/**
 * @brief Defines the drag preview option.
 *
 * @since 12
 */
typedef struct ArkUI_DragPreviewOption ArkUI_DragPreviewOption;

/**
 * @brief Defines the drag action.
 *
 * @since 12
 */
typedef struct ArkUI_DragAction ArkUI_DragAction;

/**
 * @brief Defines the drag and drop information.
 *
 * @since 12
 */
typedef struct ArkUI_DragAndDropInfo ArkUI_DragAndDropInfo;

/**
* @brief Obtains the pointer to the drag event from node event.
*
* @param event Indicates the pointer to the node event.
* @return Returns the pointer to the drag event.

* @since 12
*/
ArkUI_DragEvent* OH_ArkUI_DragEvent_GetDragEvent(ArkUI_NodeEvent *nodeEvent);

//从NodeEvent中获取 pre drag status
PreDragStatus OH_ArkUI_GetPreDragStatus(ArkUI_NodeEvent *nodeEvent);

//以下为拖入过程中涉及到的一些set操作,对DragEvent写操作
//useCustomDropAnimation--配置松手的时候,是否使能自定义动效 
int32_t OH_ArkUI_DragEvent_DisableDefaultDropAnimation(ArkUI_DragEvent* event, bool disable);

//dragBehavior--通知框架建议的数据接收方式
int32_t OH_ArkUI_DragEvent_SetSuggestedDropOperation(ArkUI_DragEvent* event, DropProposal proposal);

// setResult
int32_t OH_ArkUI_DragEvent_SetDragResult(ArkUI_DragEvent* event, DragResult result);

// setData
int32_t OH_ArkUI_DragEvent_SetData(ArkUI_DragEvent* event, UDMFData *data);

//以下为拖入过程中涉及到的一些get操作,DragEvent
// getData
UDMFData * OH_ArkUI_DragEvent_GetUnifiedData(ArkUI_DragEvent* event);
//外部依赖

// getSummary
UDMFDataSummary * OH_ArkUI_DragEvent_GetSummary(ArkUI_DragEvent* event);
//外部依赖

// getResult
DragResult OH_ArkUI_DragEvent_GetDragResult(ArkUI_DragEvent* event);

//getPreviewRect{x,y,width,height}
float OH_ArkUI_DragEvent_GetPreviewTouchPointX(ArkUI_DragEvent* event);//注意:返回值为VP单位,相对于window

float OH_ArkUI_DragEvent_GetPreviewTouchPointY(ArkUI_DragEvent* event);//注意;返回值为VP单位,相对于window

float OH_ArkUI_DragEvent_GetPreviewRectWidth(ArkUI_DragEvent* event);//注意;返回值为VP单位,相对于window

float OH_ArkUI_DragEvent_GetPreviewRectHeight(ArkUI_DragEvent*event);//注意;返回值为VP单位,相对于window

//getWindowX//getWindowY--获取跟手点相对于window的坐标
float OH_ArkUI_DragEvent_GetTouchPointXToWindow(ArkUI_DragEvent* event);//注意:返回值为VP单位,相对于window

float OH_ArkUI_DragEvent_GetTouchPointYToWindow(ArkUI_DragEvent* event);//注意;返回值为VP单位,相对于window

//getDisplayX//getDisplayY--获取跟手点相对于当前Display的坐标
float OH_ArkUI_DragEvent_GetTouchPointXToDisplay(ArkUI_DragEvent* event);//注意:返回值为VP单位,相对于Display

float OH_ArkUI_DragEvent_GetTouchPointYToDisplay(ArkUI_DragEvent* event);//注意;返回值为VP单位,相对于Display

/**
* @brief Obtains the velocity of the drag event along the x-axis.
*
* @param event Indicates the pointer to the drag event.
* @return Returns the velocity of the drag event along the x-axis, in vp/s.
* @since 12
*/
float OH_ArkUI_DragEvent_GetVelocityX(ArkUI_DragEvent* event);

/**
* @brief Obtains the velocity of the drag event along the y-axis.
*
* @param event Indicates the pointer to the drag event.
* @return Returns the velocity of the drag event along the y-axis, in vp/s.
* @since 12
*/
float OH_ArkUI_DragEvent_GetVelocityY(ArkUI_DragEvent* event);

/**
* @brief Obtains the velocity of the drag event along the main axis.
*
* @param event Indicates the pointer to the drag event.
* @return Returns the velocity of the drag event along the main axis, in vp/s.
*         The value is the square root of the sum of the squares of the velocity on the x-axis and y-axis.
* @since 12
*/
float OH_ArkUI_DragEvent_GetVelocity(ArkUI_DragEvent* event);

// getModifierKeyStates
// todo
//ModifierKeyName定义在 ui_input_event.h里
bool OH_ArkUI_DragEvent_GetModifierKeyStates(ArkUI_DragEvent* event, ModifierKeyName *keys, uint32_t count);

//UI实例上使能严格dragEvent上报--建议开启
void OH_ArkUI_Context_SetDragEventStrictReportingEnabled(bool enabled);

//allowDrop--节点创建的时候配置该节点允许接受落入的数据类型
int32_t OH_ArkUI_Node_SetAllowedDropDataTypes(ArkUI_NodeHandle node, UDMF_DataType *array, uint32_t size);
//draggable--设置该组件是否允许进行拖拽
int32_t OH_ArkUI_Node_SetDraggable(ArkUI_NodeHandle node, bool enabled);
//dragPreview--设置该组件长按浮起及被拖拽时的跟手图
int32_t OH_ArkUI_Node_SetDragPreview(ArkUI_NodeHandle node, PixelMap preview);
//dragPreviewoptions--构建一个ArkUI_DragPreviewoptions对象
ArkUI_DragPreviewOption *OH_ArkUI_CreateDragPreviewOption();

void OH_ArkUI_DragPreviewOption_Dispose(ArkUI_DragPreviewOption *option);
// dragPreviewOptions: DragPreviewMode (AUTO, DISABLE_SCAPE)--设置该组件长按浮起及被拖拽时的跟手图
int32_t OH_ArkUI_DragPreviewOption_SetscaleMode(ArkUI_DragPreviewOption *option, DragPreviewScaleMode scaleMode);
// dragPreviewOptions: DragPreviewMode (ENABLE_DEFAULT_SHAADOW)--使能默认的投影效果,默认使能
int32_t OH_ArkUI_DragPreviewOption_SetDefaultShadowEnabledd(ArkUI_DragPreviewOption *option, bool enabled);
// dragPreviewOptions: DragPreviewMode (ENABLE_DEFAULT_RADIUS)--使能默认的圆角效果,默认使能
int32_t OH_ArkUI_DragPreviewoption_SetDefaultRadiusEnableed(ArkUI_DragPreviewOption *option, bool enabled);
//dragPreviewOptions::numberBadge --设置是否显示角标,默认使能,开启后,系统会根据拖拽数量自动机型角标显示
int32_t OH_ArkUI_DragPreviewOption_SetNumberBadgeEnabled(ArkUI_DragPreviewOption *option, bool enableed);
//dragPreviewOptions::numberBadge--强制显示角标的数量,覆盖SetDragPreviewNumberBadgeEnabled设置的值
int32_t OH_ArkUI_DragPreviewOption_SetBadgeNumber(ArkUI_DragPreviewOption *option, uint32_t forcedNumber);

// dragPreviewoptions: DragInteractionOptions (defaultAnimationBeforeliifting)--使能拖拽交互上的默认点按缩小效果,默认使能
int32_t OH_ArkUI_DragPreviewOption_SetDefaultAnimationBeforeliftingEnabled(
    ArkUI_DragPreviewOption* option, bool enabled);
// dragPreviewOptions: DragInteractionOptions (isMultiSelectionEnabled)--使能list&grid组件上的默认的多选拖拽,默认不使能
int32_t OH_ArkUI_DragPreviewOption_SetMultiSelectionDragEnabled(ArkUI_DragPreviewOption *option, bool enabled);
//将构造的dragpreviewoption设置给组件
int32_t OH_ArkUI_Node_SetDragPreviewOption(ArkUI_NodeHandle node, ArkUI_DragPreviewOption *option);

ArkUI_DragAction *OH_ArkUI_CreateDragAction();
void OH_ArkUI_Dragaction_Dispose(ArkUI_DragAction *dragAction);
// 设置手指ID
int32_t OH_ArkUI_Dragaction_SetPointerid(ArkUI_DragAction *dragAction, uint32_t pointer);
int32_t OH_ArkUI_Dragaction_SetPixmaps(ArkUI_DragAction *draggAction, PixelMap *pixelMaps, uint32_t count);
//设置跟手点,相对于设置的第一个pixmap的左上角
int32_t OH_ArkUI_DragAction_SetTouchPointX(ArkUI_DragAction *dragAction, float x);
int32_t OH_ArkUI_DragAction_SetTouchPointY(ArkUI_DragAction *dragAction, float x);
//设置拖拽数据
int32_t OH_ArkUI_DragAction_SetData(ArkUI_DragAction *dragAction, UDMFData *data);
//将构造的dragpreviewoption设置给 drag action
int32_t OH_ArkUI_DragAction_SetDragPreviewOption(ArkUI_DragAction *dragAction, ArkUI_DragPreviewOption *option);
//注册拖拽状态监听回调,该回调可感知到拖拽已经发起或用户松手结束的状态,可通过该监听获取到落入方对数据的接收处理是否成功
int32_t OH_ArkUI_DragAction_RegisterStatusListener(
    ArkUI_DragAction* dragAction, void (*listener)(ArkUI_DragAndDropInfo* dragAndDropInfo), void* userDat);
void OH_ArkUI_DragAction_UnregisterStatusListener(ArkUI_DragAction *dragAction);
void* OH_ArkUI_DragAction_GetUserData(ArkUI_DragAndDropInfo* dragAndDropInfo);
//获取dragaction发起拖拽的状态,获取异常时返回UNKNOWN
DragStatus OH_ArkUI_DragAction_GetDragStatus(ArkUI_DragAndDropInfo* dragAndDropInfo);
//通过dragAndDropInfo获取到DragEvent,可通过DragEvent获取释放结果等
DragEvent *OH_ArkUI_DragAction_GetDragEvent(ArkUI_DragAndDropInfo* dragAndDropInfo);
//发起拖拽
int32_t OH_ArkUI_StartDrag(ArkUI_DragAction *dragAction);

#ifdef __cplusplus
};
#endif

#endif // ARKUI_NATIVE_DRAG_AND_DROP_H
/** @} */