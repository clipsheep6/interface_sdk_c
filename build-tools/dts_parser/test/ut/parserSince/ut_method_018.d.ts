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
 * the ut for method in namespace
 */
export namespace test {
  /**
   * the ut for method in sourcefile, method has error codes
   * 
   * @throws { BusinessError } 401 - The parameter check failed.
   */
  function test1(param1: string): number;

  /**
   * the ut for method in sourcefile, method has error codes
   * 
   * @throws { BusinessError } 401 - The parameter check failed.
   * @throws { BusinessError } 402 - The parameter check failed.
   */
  function test2(param1: string): number;

  /**
   * the ut for method in sourcefile, method has error codes but forget to write
   * 
   * @throws { BusinessError } The parameter check failed.
   */
  function test1(param1: string): number;
}