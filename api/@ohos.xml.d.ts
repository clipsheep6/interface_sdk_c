/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
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
 * The xml module provides utilities for converting XML text to Javascript object, XML generation and parsing.
 *
 * @namespace xml
 * @syscap SystemCapability.Utils.Lang
 * @since 8
 */
/**
 * The xml module provides utilities for converting XML text to Javascript object, XML generation and parsing.
 *
 * @namespace xml
 * @syscap SystemCapability.Utils.Lang
 * @crossplatform
 * @since 10
 */
declare namespace xml {
  /**
   * The XmlSerializer interface is used to generate an xml file.
   *
   * @syscap SystemCapability.Utils.Lang
   * @since 8
   * @name XmlSerializer
   */
  /**
   * The XmlSerializer interface is used to generate an xml file.
   *
   * @syscap SystemCapability.Utils.Lang
   * @crossplatform
   * @since 10
   * @name XmlSerializer
   */
  class XmlSerializer {
    /**
     * A parameterized constructor used to create a new XmlSerializer instance.
     * As the input parameter of the constructor function, init supports three types.
     * The input parameter is an Arrarybuffer.
     * The input parameter is a DataView.
     * The input parameter is an encoding format of string type.
     *
     * @param { ArrayBuffer | DataView } buffer - A instance, the new XmlPullParser with.
     * @param { string } encoding - [encoding='utf8']  this is its encoding.
     * @throws { BusinessError } 401 - if the input parameters are invalid.
     * @syscap SystemCapability.Utils.Lang
     * @since 8
     */
    /**
     * A parameterized constructor used to create a new XmlSerializer instance.
     * As the input parameter of the constructor function, init supports three types.
     * The input parameter is an Arrarybuffer.
     * The input parameter is a DataView.
     * The input parameter is an encoding format of string type.
     *
     * @param { ArrayBuffer | DataView } buffer - A instance, the new XmlPullParser with.
     * @param { string } encoding - [encoding='utf8']  this is its encoding.
     * @throws { BusinessError } 401 - if the input parameters are invalid.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @since 10
     */
    constructor(buffer: ArrayBuffer | DataView, encoding?: string);

    /**
     * Write an attribute.
     *
     * @param { string } name - Key name of the attribute.
     * @param { string } value - Values of attribute.
     * @throws { BusinessError } 401 - if the input parameters are invalid.
     * @syscap SystemCapability.Utils.Lang
     * @since 8
     */
    /**
     * Write an attribute.
     *
     * @param { string } name - Key name of the attribute.
     * @param { string } value - Values of attribute.
     * @throws { BusinessError } 401 - if the input parameters are invalid.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @since 10
     */
    setAttributes(name: string, value: string): void;

    /**
     * Add an empty element.
     *
     * @param { string } name - Key name of the attribute.
     * @throws { BusinessError } 401 - The type of name must be string.
     * @syscap SystemCapability.Utils.Lang
     * @since 8
     */
    /**
     * Add an empty element.
     *
     * @param { string } name - Key name of the attribute.
     * @throws { BusinessError } 401 - The type of name must be string.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @since 10
     */
    addEmptyElement(name: string): void;

    /**
     * Writes xml declaration with encoding. For example: <?xml version="1.0" encoding="utf-8"?>.
     *
     * @syscap SystemCapability.Utils.Lang
     * @since 8
     */
    /**
     * Writes xml declaration with encoding. For example: <?xml version="1.0" encoding="utf-8"?>.
     *
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @since 10
     */
    setDeclaration(): void;

    /**
     * Writes a element start tag with the given name.
     *
     * @param { string } name - Name of the element.
     * @throws { BusinessError } 401 - The type of name must be string.
     * @syscap SystemCapability.Utils.Lang
     * @since 8
     */
    /**
     * Writes a element start tag with the given name.
     *
     * @param { string } name - Name of the element.
     * @throws { BusinessError } 401 - The type of name must be string.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @since 10
     */
    startElement(name: string): void;

    /**
     * Writes end tag of the element.
     *
     * @syscap SystemCapability.Utils.Lang
     * @since 8
     */
    /**
     * Writes end tag of the element.
     *
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @since 10
     */
    endElement(): void;

    /**
     * Writes the namespace of the current element tag.
     *
     * @param { string } prefix - Values name of the prefix.
     * @param { string } namespace - Values of namespace.
     * @throws { BusinessError } 401 - if the input parameters are invalid.
     * @syscap SystemCapability.Utils.Lang
     * @since 8
     */
    /**
     * Writes the namespace of the current element tag.
     *
     * @param { string } prefix - Values name of the prefix.
     * @param { string } namespace - Values of namespace.
     * @throws { BusinessError } 401 - if the input parameters are invalid.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @since 10
     */
    setNamespace(prefix: string, namespace: string): void;

    /**
     * Writes the comment.
     *
     * @param { string } text - Values of comment.
     * @throws { BusinessError } 401 - The type of text must be string.
     * @syscap SystemCapability.Utils.Lang
     * @since 8
     */
    /**
     * Writes the comment.
     *
     * @param { string } text - Values of comment.
     * @throws { BusinessError } 401 - The type of text must be string.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @since 10
     */
    setComment(text: string): void;

    /**
     * Writes the CDATA.
     *
     * @param { string } text -  Values of CDATA.
     * @throws { BusinessError } 401 - The type of text must be string.
     * @syscap SystemCapability.Utils.Lang
     * @since 8
     */
    /**
     * Writes the CDATA.
     *
     * @param { string } text - Values of CDATA.
     * @throws { BusinessError } 401 - The type of text must be string.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @since 10
     */
    setCDATA(text: string): void;

    /**
     * Writes the text.
     *
     * @param { string } text - Values of text.
     * @throws { BusinessError } 401 - The type of text must be string.
     * @syscap SystemCapability.Utils.Lang
     * @since 8
     */
    /**
     * Writes the text.
     *
     * @param { string } text - Values of text.
     * @throws { BusinessError } 401 - The type of text must be string.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @since 10
     */
    setText(text: string): void;

    /**
     * Writes the DOCTYPE.
     *
     * @param { string } text - Values of docType.
     * @throws { BusinessError } 401 - The type of text must be string.
     * @syscap SystemCapability.Utils.Lang
     * @since 8
     */
    /**
     * Writes the DOCTYPE.
     *
     * @param { string } text - Values of docType.
     * @throws { BusinessError } 401 - The type of text must be string.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @since 10
     */
    setDocType(text: string): void;
  }

  /**
   * The event types represented by XML elements.
   *
   * @enum { number }
   * @syscap SystemCapability.Utils.Lang
   * @since 8
   */
  /**
   * The event types represented by XML elements.
   *
   * @enum { number }
   * @syscap SystemCapability.Utils.Lang
   * @crossplatform
   * @since 10
   */
  enum EventType {
    /**
     * Start a document.
     *
     * @syscap SystemCapability.Utils.Lang
     * @since 8
     */
    /**
     * Start a document.
     *
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @since 10
     */
    START_DOCUMENT,
    /**
     * End a document.
     *
     * @syscap SystemCapability.Utils.Lang
     * @since 8
     */
    /**
     * End a document.
     *
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @since 10
     */
    END_DOCUMENT,
    /**
     * Start a tag.
     *
     * @syscap SystemCapability.Utils.Lang
     * @since 8
     */
    /**
     * Start a tag.
     *
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @since 10
     */
    START_TAG,
    /**
     * End a tag.
     *
     * @syscap SystemCapability.Utils.Lang
     * @since 8
     */
    /**
     * End a tag.
     *
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @since 10
     */
    END_TAG,
    /**
     * Character data.
     *
     * @syscap SystemCapability.Utils.Lang
     * @since 8
     */
    /**
     * Character data.
     *
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @since 10
     */
    TEXT,
    /**
     * A CDATA sections.
     *
     * @syscap SystemCapability.Utils.Lang
     * @since 8
     */
    /**
     * A CDATA sections.
     *
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @since 10
     */
    CDSECT,
    /**
     * An XML comment.
     *
     * @syscap SystemCapability.Utils.Lang
     * @since 8
     */
    /**
     * An XML comment.
     *
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @since 10
     */
    COMMENT,
    /**
     * An XML document type declaration.
     *
     * @syscap SystemCapability.Utils.Lang
     * @since 8
     */
    /**
     * An XML document type declaration.
     *
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @since 10
     */
    DOCDECL,
    /**
     * An XML processing instruction declaration.
     *
     * @syscap SystemCapability.Utils.Lang
     * @since 8
     */
    /**
     * An XML processing instruction declaration.
     *
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @since 10
     */
    INSTRUCTION,
    /**
     * An entity reference.
     *
     * @syscap SystemCapability.Utils.Lang
     * @since 8
     */
    /**
     * An entity reference.
     *
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @since 10
     */
    ENTITY_REFERENCE,
    /**
     * A whitespace.
     *
     * @syscap SystemCapability.Utils.Lang
     * @since 8
     */
    /**
     * A whitespace.
     *
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @since 10
     */
    WHITESPACE
  }

  /**
   * The current parse info.
   *
   * @typedef ParseInfo
   * @syscap SystemCapability.Utils.Lang
   * @since 8
   */
  /**
   * The current parse info.
   *
   * @typedef ParseInfo
   * @syscap SystemCapability.Utils.Lang
   * @crossplatform
   * @since 10
   */
  interface ParseInfo {
    /**
     * The current column number, starting from 1.
     *
     * @returns { number }
     * @syscap SystemCapability.Utils.Lang
     * @since 8
     */
    /**
     * The current column number, starting from 1.
     *
     * @returns { number }
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @since 10
     */
    getColumnNumber(): number;
    /**
     * The current depth of the element.
     *
     * @returns { number }
     * @syscap SystemCapability.Utils.Lang
     * @since 8
     */
    /**
     * The current depth of the element.
     *
     * @returns { number }
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @since 10
     */
    getDepth(): number;
    /**
     * The current line number, starting from 1.
     *
     * @returns { number }
     * @syscap SystemCapability.Utils.Lang
     * @since 8
     */
    /**
     * The current line number, starting from 1.
     *
     * @returns { number }
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @since 10
     */
    getLineNumber(): number;
    /**
     * The current element's name.
     *
     * @returns { string }
     * @syscap SystemCapability.Utils.Lang
     * @since 8
     */
    /**
     * The current element's name.
     *
     * @returns { string }
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @since 10
     */
    getName(): string;
    /**
     * The current element's namespace.
     *
     * @returns { string }
     * @syscap SystemCapability.Utils.Lang
     * @since 8
     */
    /**
     * The current element's namespace.
     *
     * @returns { string }
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @since 10
     */
    getNamespace(): string;
    /**
     * The current element's prefix.
     *
     * @returns { string }
     * @syscap SystemCapability.Utils.Lang
     * @since 8
     */
    /**
     * The current element's prefix.
     *
     * @returns { string }
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @since 10
     */
    getPrefix(): string;
    /**
     * The text content of the current event as String.
     *
     * @returns { string }
     * @syscap SystemCapability.Utils.Lang
     * @since 8
     */
    /**
     * The text content of the current event as String.
     *
     * @returns { string }
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @since 10
     */
    getText(): string;
    /**
     * Returns true if the current element is empty.
     *
     * @returns { boolean }
     * @syscap SystemCapability.Utils.Lang
     * @since 8
     */
    /**
     * Returns true if the current element is empty.
     *
     * @returns { boolean }
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @since 10
     */
    isEmptyElementTag(): boolean;
    /**
     * Checks whether the current TEXT event contains only whitespace characters.
     *
     * @returns { boolean }
     * @syscap SystemCapability.Utils.Lang
     * @since 8
     */
    /**
     * Checks whether the current TEXT event contains only whitespace characters.
     *
     * @returns { boolean }
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @since 10
     */
    isWhitespace(): boolean;
    /**
     * Returns the number of attributes of the current start tag.
     *
     * @returns { number }
     * @syscap SystemCapability.Utils.Lang
     * @since 8
     */
    /**
     * Returns the number of attributes of the current start tag.
     *
     * @returns { number }
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @since 10
     */
    getAttributeCount(): number;
  }

  /**
   * Parse options for XmlPullParser.
   *
   * @typedef ParseOptions
   * @syscap SystemCapability.Utils.Lang
   * @since 8
   */
  /**
   * Parse options for XmlPullParser.
   *
   * @typedef ParseOptions
   * @syscap SystemCapability.Utils.Lang
   * @crossplatform
   * @since 10
   */
  interface ParseOptions {
    /**
     * Whether to parsing Doctype of the elements.
     *
     * @syscap SystemCapability.Utils.Lang
     * @since 8
     */
    /**
     * Whether to parsing Doctype of the elements.
     *
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @since 10
     */
    supportDoctype?: boolean;

    /**
     * Whether to ignore parsing texts of the elements.
     *
     * @syscap SystemCapability.Utils.Lang
     * @since 8
     */
    /**
     * Whether to ignore parsing texts of the elements.
     *
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @since 10
     */
    ignoreNameSpace?: boolean;

    /**
     * Tag value callback function.
     *
     * @syscap SystemCapability.Utils.Lang
     * @since 8
     */
    /**
     * Tag value callback function.
     *
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @since 10
     */
    tagValueCallbackFunction?: (name: string, value: string) => boolean;

    /**
     * Attribute value callback function.
     *
     * @syscap SystemCapability.Utils.Lang
     * @since 8
     */
    /**
     * Attribute value callback function.
     *
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @since 10
     */
    attributeValueCallbackFunction?: (name: string, value: string) => boolean;

    /**
     * Token value callback function.
     *
     * @syscap SystemCapability.Utils.Lang
     * @since 8
     */
    /**
     * Token value callback function.
     *
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @since 10
     */
    tokenValueCallbackFunction?: (eventType: EventType, value: ParseInfo) => boolean;
  }

  /**
   * The XmlPullParser interface is used to parse the existing xml file.
   *
   * @syscap SystemCapability.Utils.Lang
   * @since 8
   * @name XmlPullParser
   */
  /**
   * The XmlPullParser interface is used to parse the existing xml file.
   *
   * @syscap SystemCapability.Utils.Lang
   * @crossplatform
   * @since 10
   * @name XmlPullParser
   */
  class XmlPullParser {
    /**
     * A constructor used to create a new XmlPullParser instance.
     *
     * @param { ArrayBuffer | DataView } buffer - A instance, the new XmlPullParser with.
     * @param { string } encoding - [encoding='utf8']  this is its encoding.
     * @throws { BusinessError } 401 - if the input parameters are invalid.
     * @syscap SystemCapability.Utils.Lang
     * @since 8
     */
    /**
     * A constructor used to create a new XmlPullParser instance.
     *
     * @param { ArrayBuffer | DataView } buffer - A instance, the new XmlPullParser with.
     * @param { string } encoding - [encoding='utf8']  this is its encoding.
     * @throws { BusinessError } 401 - if the input parameters are invalid.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @since 10
     */
    constructor(buffer: ArrayBuffer | DataView, encoding?: string);

    /**
     * Starts parsing the XML file.
     *
     * @param { ParseOptions } option - Parse options for XmlPullParser, the interface including
	 * two Boolean variables and three callback functions.
     * @throws { BusinessError } 401 - The type of option must be ParseOptions.
     * @syscap SystemCapability.Utils.Lang
     * @since 8
     */
    /**
     * Starts parsing the XML file.
     *
     * @param { ParseOptions } option - Parse options for XmlPullParser, the interface including
	 * two Boolean variables and three callback functions.
     * @throws { BusinessError } 401 - The type of option must be ParseOptions.
     * @syscap SystemCapability.Utils.Lang
     * @crossplatform
     * @since 10
     */
    parse(option: ParseOptions): void;
  }
}
export default xml;
