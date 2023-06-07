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

/**
 * Stack is implemented based on the array data structure. 
 * It follows the principle Last Out First In (LOFI) and supports data insertion and removal at one end.
 *
 * @namespace Stack
 * @syscap SystemCapability.Utils.Lang
 * @crossplatform
 * @since 8
 */
declare class Stack<T> {
  /**
   * A constructor used to create a Stack object.
   *
   * @throws { BusinessError } 10200012 - The Stack's constructor cannot be directly invoked.
   * @syscap SystemCapability.Utils.Lang
   * @crossplatform
   * @since 8
   */
  constructor();
  /**
   * Gets the element number of the Stack. This is a number one higher than the highest index in the Stack.
   *
   * @syscap SystemCapability.Utils.Lang
   * @crossplatform
   * @since 8
   */
  length: number;
  /**
   * Tests if this stack is empty
   *
   * @returns { boolean } the boolean type
   * @throws { BusinessError } 10200011 - The isEmpty method cannot be bound.
   * @syscap SystemCapability.Utils.Lang
   * @crossplatform
   * @since 8
   */
  isEmpty(): boolean;
  /**
   * Looks at the object at the top of this stack without removing it from the stack
   * Return undefined if this stack is empty
   *
   * @returns { T } the top value or undefined
   * @throws { BusinessError } 10200011 - The peek method cannot be bound.
   * @syscap SystemCapability.Utils.Lang
   * @crossplatform
   * @since 8
   */
  peek(): T;
  /**
   * Removes the object at the top of this stack and returns that object as the value of this function
   * an exception if the stack is empty
   *
   * @returns { T } Stack top value or undefined
   * @throws { BusinessError } 10200011 - The pop method cannot be bound.
   * @syscap SystemCapability.Utils.Lang
   * @crossplatform
   * @since 8
   */
  pop(): T;
  /**
   * Pushes an item onto the top of this stack
   *
   * @param { T } item - item item to be appended to this Stack
   * @returns { T } the T type
   * @throws { BusinessError } 10200011 - The push method cannot be bound.
   * @syscap SystemCapability.Utils.Lang
   * @crossplatform
   * @since 8
   */
  push(item: T): T;
  /**
   * Returns the 1-based position where an object is on this stack
   *
   * @param { T } element - element element Target to be deleted
   * @returns { number } the T type,If there is no such element, return -1
   * @throws { BusinessError } 10200011 - The locate method cannot be bound.
   * @syscap SystemCapability.Utils.Lang
   * @crossplatform
   * @since 8
   */
  locate(element: T): number;
  /**
   * Executes a provided function once for each value in the Stack object.
   *
   * @param { (value: T, index?: number, stack?: Stack<T>) => void } callbackFn - callbackFn
   * callbackFn (required) A function that accepts up to four arguments.The function
   * to be called for each element in the Stack
   * @param { Object } thisArg - thisArg thisArg (Optional) The value passed to the function generally uses the "this" value.
   * If this parameter is empty, "undefined" will be passed to the "this" value
   * @throws { BusinessError } 10200011 - The forEach method cannot be bound.
   * @throws { BusinessError } 401 - The type of parameters are invalid.
   * @syscap SystemCapability.Utils.Lang
   * @crossplatform
   * @since 8
   */
  forEach(callbackFn: (value: T, index?: number, stack?: Stack<T>) => void, thisArg?: Object): void;
  /**
   * returns an ES6 iterator.Each item of the iterator is a Javascript Object
   *
   * @returns { IterableIterator<T> }
   * @throws { BusinessError } 10200011 - The Symbol.iterator method cannot be bound.
   * @syscap SystemCapability.Utils.Lang
   * @crossplatform
   * @since 8
   */
  [Symbol.iterator](): IterableIterator<T>;
}

export default Stack;
