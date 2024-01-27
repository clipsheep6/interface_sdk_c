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
 * @file
 * @kit ArkTS
 */

/**
 * ArkTS collections.
 *
 * @namespace collections
 * @syscap SystemCapability.Utils.Lang
 * @crossplatform
 * @atomicservice
 * @since 12
 */
declare namespace collections {
  /**
   * Array is a data structure that is implemented based on array. 
   * If multiple threads access a Array instance concurrently, 
   * and at least one of the threads modifies the array structurally,
   * it must be synchronized externally.
   * 
   * @syscap SystemCapability.Utils.Lang
   * @crossplatform
   * @atomicservice
   * @since 12
   */
  @Sendable
  class Array<T> {
    /**
     * A constructor used to create an ArkTS Array.
     *
     * @param { number } [arrayLength] - The length of the array
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 10200012 - The Array's constructor cannot be directly invoked.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    constructor(arrayLength?: number);
    /**
     * A constructor used to create an ArkTS Array.
     *
     * @param { T[] } items - An ArkTS array is initialized with the given elements
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 10200012 - The Array's constructor cannot be directly invoked.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    constructor(...items: T[]);
    /**
     * Creates an ArkTS Array from an array-like object.
     * 
     * @param { ArrayLike<T> } arrayLike - An array-like object to convert to an ArkTS Array.
     * @returns { Array<T> } A new Array instance
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 10200011 - The from method cannot be bound.
     * @static
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    static from<T>(arrayLike: ArrayLike<T>): Array<T>;
    /**
     * Creates an ArkTS Array from an iterable object.
     * 
     * @param { ArrayLike<T> } arrayLike - An array-like object to convert to an ArkTS Array.
     * @param { function } mapFn - A mapping function to call on every element of the array.
     * @returns { Array<U> } A new Array instance
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 10200011 - The from method cannot be bound.
     * @static
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    static from<T, U>(arrayLike: ArrayLike<T>, mapFn: (v: T, k: number) => U): Array<U>;
    /**
     * Gets or sets the length of the ArkTS array. This is a number one higher than the highest index in the ArkTS array.
     * 
     * @type { number }
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    length: number;
    /**
     * Removes the last element from an ArkTS array and returns it.
     * If the array is empty, undefined is returned and the array is not modified.
     * 
     * @returns { T | undefined } - The removed element from the array; undefined if the array is empty.
     * @throws { BusinessError } 10200011 - The pop method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    pop(): T | undefined;
    /**
     * Appends new elements to the end of an ArkTS Array, and returns the new length of the array.
     * 
     * @param { T[] } items - New elements to add to the ArkTS array.
     * @returns { number } - The new length property of the object upon which the method was called.
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 10200011 - The push method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    push(...items: T[]): number;
    /**
     * Combines two or more arrays.
     * This method returns a new array without modifying any existing arrays.
     * 
     * @param { (T | Array<T>)[] } items - Additional arrays and/or items to add to the end of the array.
     * @returns { Array<T> } - A new Array instance
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 10200011 - The concat method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    concat(...items: (T | Array<T>)[]): Array<T>;
    /**
     * Adds all the elements of an ArkTS Array into a string, separated by the specified separator string.
     * 
     * @param { string } [separator] - A string used to separate one element of the array from the next in the resulting string. If omitted, the array elements are separated with a comma.
     * @returns { string } A string with all array elements joined. If Array.length is 0, the empty string is returned.
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 10200011 - The join method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    join(separator?: string): string;
    /**
     * Removes the first element from an ArkTS Array and returns it.
     * If the array is empty, undefined is returned and the array is not modified.
     * 
     * @returns { T | undefined } The removed element from the array; undefined if the array is empty
     * @throws { BusinessError } 10200011 - The shift method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    shift(): T | undefined;
    /**
     * Inserts new elements at the start of an array, and returns the new length of the array.
     *
     * @param { T[] } items - Elements to insert at the start of the array.
     * @returns { number } The new length property of the object upon which the method was called.
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 10200011 - The unshift method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    unshift(...items: T[]): number;
    /**
     * Returns a copy of a section of an ArkTS Array.
     * For both start and end, a negative index can be used to indicate an offset from the end of the array.
     * For example, -2 refers to the second to last element of the array.
     *
     * @param { number } [start] - The beginning index of the specified portion of the array.
     * If start is undefined, then the slice begins at index 0.
     * @param { number } [end] - The end index of the specified portion of the array. This is exclusive of the element at the index 'end'.
     * If end is undefined, then the slice extends to the end of the array.
     * @returns { Array<T> } A new array containing the extracted elements.
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 10200011 - The slice method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    slice(start?: number, end?: number): Array<T>;
    /**
     * Sorts an array in place. This method mutates the array and returns a reference to the same array.
     *
     * @param { function } [compareFn] - Function used to determine the order of the elements. It is expected to return
     * a negative value if the first argument is less than the second argument, zero if they're equal, and a positive
     * value otherwise. If omitted, the elements are sorted in ascending, ASCII character order.
     * @returns { Array<T> } The reference to the original array, now sorted.
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 10200011 - The sort method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    sort(compareFn?: (a: T, b: T) => number): Array<T>;
    /**
     * Returns the index of the first occurrence of a value in an ArkTS Array, or -1 if it is not present.
     * 
     * @param { T } searchElement - The value to locate in the array.
     * @param { number } [fromIndex] - The array index at which to begin the search. If fromIndex is omitted, the search starts at index 0.
     * @returns { number } The first index of searchElement in the array; -1 if not found.
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 10200011 - The indexOf method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    indexOf(searchElement: T, fromIndex?: number): number;
    /**
     * Executes a provided function once for each value in the Array object.
     *
     * @param { function } callbackFn - A function that accepts up to three arguments.
     * The function to be called for each element.
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 10200011 - The forEach method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    forEach(callbackFn: (value: T, index: number, array: Array<T>) => void): void;
    /**
     * Calls a defined callback function on each element of an ArkTS Array, and returns an array that contains the results.
     * 
     * @param { function } callbackFn - A function that accepts up to three arguments. The map method calls the callbackFn function one time for each element in the array.
     * @returns { Array<U> } A new array with each element being the result of the callback function.
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 10200011 - The map method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    map<U>(callbackFn: (value: T, index: number, array:  Array<T>) => U): Array<U>;
    /**
     * Returns the elements of an ArkTS Array that meet the condition specified in a callback function.
     * 
     * @param { function } predicate - A function that accepts up to three arguments. The filter method calls the predicate function one time for each element in the array.
     * @returns { Array<S> } A shallow copy of the given containing just the elements that pass the test. If no elements pass the test, an empty array is returned.
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 10200011 - The filter method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    filter<S extends T>(predicate: (value: T, index: number, array: Array<T>) => boolean): Array<S>;
    /**
     * Returns the elements of an ArkTS Array that meet the condition specified in a callback function.
     * 
     * @param { function } predicate - A function that accepts up to three arguments. The filter method calls the predicate function one time for each element in the array.
     * @returns { Array<T> } A shallow copy of the given containing just the elements that pass the test. If no elements pass the test, an empty array is returned.
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 10200011 - The filter method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    filter(predicate: (value: T, index: number, array: Array<T>) => boolean): Array<T>;
    /**
     * Calls the specified callback function for all the elements in an ArkTS Array. The return value of the callback function is the accumulated result, and is provided as an argument in the next call to the callback function.
     * 
     * @param { function } callbackFn - A function that accepts up to four arguments. The reduce method calls the callbackFn function one time for each element in the array.
     * @returns { T } The value that results from running the "reducer" callback function to completion over the entire array.
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 10200011 - The reduce method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    reduce(callbackFn: (previousValue: T, currentValue: T, currentIndex: number, array: Array<T>) => T): T;
    /**
     * Calls the specified callback function for all the elements in an ArkTS Array. The return value of the callback function is the accumulated result, and is provided as an argument in the next call to the callback function.
     * 
     * @param { function } callbackFn - A function that accepts up to four arguments. The reduce method calls the callbackFn function one time for each element in the array.
     * @param { T } initialValue - If initialValue is specified, it is used as the initial value to start the accumulation. The first call to the callbackFn function provides this value as an argument instead of an array value.
     * @returns { T } The value that results from running the "reducer" callback function to completion over the entire array.
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 10200011 - The reduce method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    reduce(callbackFn: (previousValue: T, currentValue: T, currentIndex: number, array: Array<T>) => T, initialValue: T): T;
    /**
     * Calls the specified callback function for all the elements in an array. The return value of the callback function is the accumulated result, and is provided as an argument in the next call to the callback function.
     * 
     * @param { function } callbackFn - A function that accepts up to four arguments. The reduce method calls the callbackFn function one time for each element in the array.
     * @param { U } initialValue - If initialValue is specified, it is used as the initial value to start the accumulation. The first call to the callbackFn function provides this value as an argument instead of an array value.
     * @returns { U } The value that results from running the "reducer" callback function to completion over the entire array.
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 10200011 - The reduce method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
    */
    reduce<U>(callbackFn: (previousValue: U, currentValue: T, currentIndex: number, array: Array<T>) => U, initialValue: U): U;
    /**
     * Returns the item located at the specified index.
     *
     * @param { number } index - The zero-based index of the desired code unit. A negative index will count back from the last item.
     * @returns { T | undefined } The element in the array matching the given index. Always returns undefined if index < -array.length or index >= array.length without attempting to access the corresponding property.
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 10200011 - The at method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    at(index: number): T | undefined;
    /**
     * Returns an iterable of key, value pairs for every entry in the array
     * 
     * @returns { IterableIterator<[number, T]> } A new iterable iterator object.
     * @throws { BusinessError } 10200011 - The entries method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    entries(): IterableIterator<[number, T]>;
    /**
     * Returns an iterable of keys in the array
     * 
     * @returns { IterableIterator<number> } A new iterable iterator object.
     * @throws { BusinessError } 10200011 - The keys method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    keys(): IterableIterator<number>;
    /**
     * Returns an iterable of values in the array
     * 
     * @returns { IterableIterator<T> } A new iterable iterator object.
     * @throws { BusinessError } 10200011 - The values method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    values(): IterableIterator<T>;
    /**
     * Returns the value of the first element in the array where predicate is true, and undefined
     * otherwise.
     * 
     * @param { function } predicate - Find calls predicate once for each element of the array, in ascending
     * order, until it finds one where predicate returns true. If such an element is found, find
     * immediately returns that element value. Otherwise, find returns undefined.
     * @returns { S | undefined } The first element in the array that satisfies the provided testing function. Otherwise, undefined is returned.
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 10200011 - The find method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    find<S extends T>(predicate: (value: T, index: number, obj: Array<T>) => boolean): S | undefined;
    /**
     * Returns the value of the first element in the array where predicate is true, and undefined
     * otherwise.
     * 
     * @param { function } predicate - Find calls predicate once for each element of the array, in ascending
     * order, until it finds one where predicate returns true. If such an element is found, find
     * immediately returns that element value. Otherwise, find returns undefined.
     * @returns { T | undefined } The first element in the array that satisfies the provided testing function. Otherwise, undefined is returned.
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 10200011 - The find method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    find(predicate: (value: T, index: number, obj: Array<T>) => boolean): T | undefined;
    /**
     * Determines whether an array includes a certain element, returning true or false as appropriate.
     *
     * @param { T } searchElement - The element to search for.
     * @param { number } [fromIndex] - The position in this array at which to begin searching for searchElement.
     * @returns { boolean } A boolean value which is true if the value searchElement is found within the array (or the part of the array indicated by the index fromIndex, if specified).
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 10200011 - The includes method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    includes(searchElement: T, fromIndex?: number): boolean;
    /**
     * Returns the index of the first element in the array where predicate is true, and -1
     * otherwise.
     *
     * @param { function } predicate - Find calls predicate once for each element of the array, in ascending
     * order, until it finds one where predicate returns true. If such an element is found,
     * findIndex immediately returns that element index. Otherwise, findIndex returns -1.
     * @returns { number } The index of the first element in the array that passes the test. Otherwise, -1;
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 10200011 - The findIndex method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    findIndex(predicate: (value: T, index: number, obj: Array<T>) => boolean): number;
    /**
     * Returns the this object after filling the section identified by start and end with value
     * 
     * @param { T } value - Value to fill array section with
     * @param { number } [start] - Index to start filling the array at. If start is negative, it is treated as
     * length+start where length is the length of the array.
     * @param { number } [end] - Index to stop filling the array at. If end is negative, it is treated as
     * length+end.
     * @returns { Array<T> } The modified array, filled with value.
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 10200011 - The fill method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    fill(value: T, start?: number, end?: number): Array<T>;
  }
  
  /**
   * The Map holds key-value pairs.
   * If multiple threads access a Map instance concurrently, 
   * and at least one of the threads modifies the map structurally,
   * it must be synchronized externally.
   * 
   * @syscap SystemCapability.Utils.Lang
   * @crossplatform
   * @atomicservice
   * @since 12
   */
  @Sendable
  class Map<K, V> {
    /**
     * A constructor used to create a Map.
     *
     * @param { readonly (readonly [K, V])[] | null } [entries] - An Array or other iterable object whose elements are key-value pairs.
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 10200012 - The Map's constructor cannot be directly invoked.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    constructor(entries?: readonly (readonly [K, V])[] | null)
    /**
     * Returns an iterable of key, value pairs for every entry in the map.
     *
     * @returns { IterableIterator<[K, V]> } A new iterable iterator object.
     * @throws { BusinessError } 10200011 - The entries method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    entries(): IterableIterator<[K, V]>;
    /**
     * Returns an iterable of keys in the map.
     *
     * @returns { IterableIterator<K> } A new iterable iterator object.
     * @throws { BusinessError } 10200011 - The keys method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    keys(): IterableIterator<K>;
    /**
     * Returns an iterable of values in the map.
     *
     * @returns { IterableIterator<V> } A new iterable iterator object.
     * @throws { BusinessError } 10200011 - The values method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    values(): IterableIterator<V>;
    /**
     * Clears the map.
     *
     * @throws { BusinessError } 10200011 - The clear method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    clear(): void;
    /**
     * Returns true if an element in the Map existed and has been removed, or false if the element does not exist.
     *
     * @param { K } key - The key of the element to remove from the Map object.
     * @returns { boolean } True if an element in the Map Object existed and has been removed, or false if the element does not exist.
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 10200011 - The delete method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    delete(key: K): boolean;
    /**
     * Executes the provided callback once for each key of the map which actually exist.
     *
     * @param { function } callbackFn - A function that accepts up to three arguments.
     * The function to be called for each element.
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 10200011 - The forEach method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    forEach(callbackFn: (value: V, key: K, map: Map<K, V>) => void): void;
    /**
     * Returns a specified element from the Map object. If the value that is associated to the provided key is an object, then you will get a reference to that object and any change made to that object will effectively modify it inside the Map.
     *
     * @param { K } key - The key of the element to return from the Map object
     * @returns { V | undefined } The element associated with the specified key, or undefined if the key can''t be found in the Map object.
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 10200011 - The get method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    get(key: K): V | undefined;
    /**
     * Returns boolean indicating whether an element with the specified key exists or not.
     *
     * @param { K } key - The key of the element to test for presence in the Map object.
     * @returns { boolean } true if an element with the specified key exists in the Map Object; otherwise false.
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 10200011 - The has method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    has(key: K): boolean;
    /**
     * Adds a new element with a specified key and value to the Map. If an element with the same key already exists, the element will be updated.
     *
     * @param { K } key - The key of the element to add to the Map object.
     * @param { V } value - The value of the element to add to the object.
     * @returns { Map<K, V> } The Object.
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 10200011 - The set method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    set(key: K, value: V): Map<K, V>;
    /**
     * Returns the number of elements in the Map.
     *
     * @type { number }
     * @readonly
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    readonly size: number;
  }
  
  /**
   * Set lets you store unique values of any type.
   * If multiple threads access a Set instance concurrently, 
   * and at least one of the threads modifies the set structurally,
   * it must be synchronized externally.
   * 
   * @syscap SystemCapability.Utils.Lang
   * @crossplatform
   * @atomicservice
   * @since 12
   */
  @Sendable
  class Set<T> {
    /**
     * A constructor used to create a Set.
     *
     * @param { readonly T[] | null } [values] - If an iterable object is passed, all of its elements will be added to the new Set.
     * If you don't specify this parameter, or its value is null, the new Set is empty.
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 10200012 - The Set's constructor cannot be directly invoked.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    constructor(values?: readonly T[] | null);
    /**
     * Returns an iterable of [value, value] pairs for each element in this set.
     * 
     * @returns { IterableIterator<[T, T]> } A new iterable iterator object.
     * @throws { BusinessError } 10200011 - The entries method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    entries(): IterableIterator<[T, T]>;
    /**
     * Returns an iterable of the values in the set.
     *
     * @returns { IterableIterator<T> } A new iterable iterator object.
     * @throws { BusinessError } 10200011 - The keys method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    keys(): IterableIterator<T>;
    /**
     * Returns an iterable of values in the set.
     *
     * @returns { IterableIterator<T> } A new iterable iterator object.
     * @throws { BusinessError } 10200011 - The values method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    values(): IterableIterator<T>;
    /**
     * Appends a new element with a specified value to the end of the Set.
     *
     * @param { T } value - The value of the element to add to the Set object.
     * @returns { Set<T> } The Set object with added value.
     * @throws { BusinessError } 10200011 - The add method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    add(value: T): Set<T>;
    /**
     * Clears the Set.
     *
     * @throws { BusinessError } 10200011 - The clear method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    clear(): void;
    /**
     * Returns true if an element in the Set existed and has been removed, or false if the element does not exist.
     *
     * @param { T } value - The value to remove from Set.
     * @returns { boolean } Returns true if value was already in Set; otherwise false.
     * @throws { BusinessError } 10200011 - The delete method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    delete(value: T): boolean;
    /**
     * Executes a provided function once per each value in the Set object, in insertion order.
     *
     * @param { function } callbackFn - A function that accepts up to three arguments.
     * The function to be called for each element.
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 10200011 - The forEach method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    forEach(callbackFn: (value: T, value2: T, set: Set<T>) => void): void;
    /**
     * A boolean indicating whether an element with the specified value exists in the Set or not.
     *
     * @param { T } value -  The value to test for presence in the Object.
     * @returns { boolean } Returns true if an element with the specified value exists in the Set object; otherwise false.
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 10200011 - The has method cannot be bound.
     * @throws { BusinessError } 10200201 - Concurrent modification error.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    has(value: T): boolean;
    /**
     * Returns the number of elements in the Set.
     *
     * @type { number }
     * @readonly
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @atomicservice
     * @since 12
     */
    readonly size: number;
  }
}

export default collections;