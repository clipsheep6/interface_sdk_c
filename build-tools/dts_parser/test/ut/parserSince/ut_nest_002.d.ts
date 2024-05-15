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
 * the ut for parent node has since tag version, and some child nodes's version is less than parent version
 * 
 * @since 7
 */
export class Test {
  /**
   * @since 6
   */
  id: number;
  /**
   * @since 7
   */
  name: string;
  /**
   * @since 8
   */
  age: number;
}