/*
 * Copyright (c) 2022-2023 Huawei Device Co., Ltd.
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
 * @file
 * @kit Background Tasks Kit
 */

import workScheduler from './@ohos.resourceschedule.workScheduler';
import _WorkSchedulerExtensionContext from './application/WorkSchedulerExtensionContext';
export type WorkSchedulerExtensionContext = _WorkSchedulerExtensionContext;

/**
 * Class of the work scheduler extension ability.
 *
 * @syscap SystemCapability.ResourceSchedule.WorkScheduler
 * @StageModelOnly
 * @since 9
 */
export default class WorkSchedulerExtensionAbility {
  /**
   * Indicates work scheduler extension ability context.
   *
   * @syscap SystemCapability.ResourceSchedule.WorkScheduler
   * @StageModelOnly
   * @since 10
   */
  context: WorkSchedulerExtensionContext;

  /**
   * Called back when a work is started.
   *
   * @param {workScheduler.WorkInfo} work - The info of work.
   * @syscap SystemCapability.ResourceSchedule.WorkScheduler
   * @StageModelOnly
   * @since 9
   */
  onWorkStart(work: workScheduler.WorkInfo): void;

  /**
   * Called back when a work is stopped.
   *
   * @param {workScheduler.WorkInfo} work - The info of work.
   * @syscap SystemCapability.ResourceSchedule.WorkScheduler
   * @StageModelOnly
   * @since 9
   */
  onWorkStop(work: workScheduler.WorkInfo): void;
}
