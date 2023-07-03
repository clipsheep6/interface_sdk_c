/*
 * Copyright (c) 2021-2023 Huawei Device Co., Ltd.
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
 * Defines the ColumnSplit component.
 * @since 7
 */
/**
 * Defines the ColumnSplit component.
 * @crossplatform
 * @since 10
 */
interface ColumnSplitInterface {
  /**
   * Layout the subassemblies vertically and insert a horizontal divider line between each subassemblies.
   * @since 7
   */
  /**
   * Layout the subassemblies vertically and insert a horizontal divider line between each subassemblies.
   * @crossplatform
   * @since 10
   */
  (): ColumnSplitAttribute;
}

/**
 * Defines the ColumnSplit component attribute functions.
 * @since 7
 */
/**
 * Defines the ColumnSplit component attribute functions.
 * @crossplatform
 * @since 10
 */
declare class ColumnSplitAttribute extends CommonMethod<ColumnSplitAttribute> {
  /**
   * Indicates whether the split line can be dragged. The default value is false.
   * @since 7
   */
  /**
   * Indicates whether the split line can be dragged. The default value is false.
   * @crossplatform
   * @since 10
   */
  resizeable(value: boolean): ColumnSplitAttribute;

  /**
   * Called when the ColumnSplit split line margin is set.
   * @crossplatform
   * @since 10
   */
  divider(
      value: {
        startMargin?: Length;
        endMargin?: Length;
      } | null,
  ): ColumnSplitAttribute;
}

/**
 * Defines ColumnSplit Component instance.
 * @since 7
 */
/**
 * Defines ColumnSplit Component instance.
 * @crossplatform
 * @since 10
 */
declare const ColumnSplitInstance: ColumnSplitAttribute;

/**
 * Defines ColumnSplit Component.
 * @since 7
 */
/**
 * Defines ColumnSplit Component.
 * @crossplatform
 * @since 10
 */
declare const ColumnSplit: ColumnSplitInterface;
