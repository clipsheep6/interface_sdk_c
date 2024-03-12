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

#ifndef ARKUI_NATIVE_DIALOG_H
#define ARKUI_NATIVE_DIALOG_H

#include "native_type.h"
#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    DIALOG_DISMISS_BACK_PRESS = 0,
    DIALOG_DISMISS_TOUCH_OUTSIDE,
} ArkUI_DismissReason;

typedef bool (*OnWillDismissEvent)(int32_t reason);
typedef struct {
    int32_t version;
    // 创建和销毁弹窗
    ArkUI_NativeDialogHandler (*create)();
    void (*dispose)(ArkUI_NativeDialogHandler handler);
    // 挂载和卸载自定义弹窗内容
    void (*attachContent)(ArkUI_NativeDialogHandler handler, ArkUI_NodeHandle content);
    void (*detachContent)(ArkUI_NativeDialogHandler handler, ArkUI_NodeHandle content);
    // 设置自定义弹窗属性
    void (*setContentAlignment)(ArkUI_NativeDialogHandler handler, int32_t alignment, float offsetX, float offsetY);
    void (*resetContentAlignment)(ArkUI_NativeDialogHandler handler);
    void (*setMode)(ArkUI_NativeDialogHandler handler, bool useModalMode, bool autoCancel);
    void (*setMask)(ArkUI_NativeDialogHandler handler, uint32_t maskColor, const ArkUI_VpRect* rect);
    void (*setBackgroundColor)(ArkUI_NativeDialogHandler handler, uint32_t backgroundColor);
    void (*setCornerRadius)(ArkUI_NativeDialogHandler handler, float topleft, float topRight,
        float bottomLeft, float bottomRight);
    void (*setGridCount)(ArkUI_NativeDialogHandler handler, int32_t gridCount);
    void (*setCustomStyle)(ArkUI_NativeDialogHandler handler, bool customStyle);
    // 注册关闭事件
    void (*registerOnWillDismiss)(ArkUI_NativeDialogHandler handler, OnWillDismissEvent eventHandler);
    // 显示和关闭弹窗
    void (*show)(ArkUI_NativeDialogHandler handler, bool showInSubWindow);
    void (*close)(ArkUI_NativeDialogHandler handler);
    void (*setCustomAnimation)(ArkUI_NativeDialogHandler handler, bool useCustomAnimation);
} ArkUI_NativeDialogAPI_1;

#ifdef __cplusplus
};
#endif

#endif // ARKUI_NATIVE_DIALOG_H