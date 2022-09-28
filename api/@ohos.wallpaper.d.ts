/*
 * Copyright (c) 2022 Huawei Device Co., Ltd.
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
import {AsyncCallback} from './basic';
import image from './@ohos.multimedia.image';

/**
 * System wallpaper
 * @syscap SystemCapability.MiscServices.Wallpaper
 * @import import wallpaper from '@ohos.wallpaper';
 * @since 7
 */
declare namespace wallpaper {
    enum WallpaperType {
        /**
         * Indicates the home screen wallpaper.
         */
        WALLPAPER_SYSTEM,
        /**
         * Indicates the lock screen wallpaper.
         */
        WALLPAPER_LOCKSCREEN
    }

    /**
     * Obtains the wallpaper colors for the wallpaper of the specified type.
     * 
     * @param wallpaperType Indicates the wallpaper type.
     * @return RgbaColor type of array callback function
     * @deprecated since 9
     */
    function getColors(wallpaperType: WallpaperType, callback: AsyncCallback<Array<RgbaColor>>): void;
    function getColors(wallpaperType: WallpaperType): Promise<Array<RgbaColor>>;

    /**
     * Obtains the wallpaper colors for the wallpaper of the specified type.
     * 
     * @param wallpaperType Indicates the wallpaper type.
     * @return RgbaColor type of array callback function
     * @throws {BusinessError} Parameter error.
     * @since 9
     */
    function getColorsSync(wallpaperType: WallpaperType): Array<RgbaColor>;

    /**
     * Obtains the ID of the wallpaper of the specified type.
     * 
     * @param wallpaperType Indicates the wallpaper type.
     * @return an integer greater than or equal to {@code 0} representing the wallpaper ID
     * if the specified type of wallpaper has been set; returns {@code -1} otherwise.
     * The return value is an integer ranging from -1 to 2^31 - 1.
     * @deprecated since 9
     */
    function getId(wallpaperType: WallpaperType, callback: AsyncCallback<number>): void;
    function getId(wallpaperType: WallpaperType): Promise<number>;

    /**
     * Obtains the ID of the wallpaper of the specified type.
     * 
     * @param wallpaperType Indicates the wallpaper type.
     * @return an integer greater than or equal to {@code 0} representing the wallpaper ID
     * if the specified type of wallpaper has been set; returns {@code -1} otherwise.
     * The return value is an integer ranging from -1 to 2^31 - 1.
     * @throws {BusinessError} Parameter error.
     * @since 9
     */
    function getIdSync(wallpaperType: WallpaperType): number;

    /**
     * Obtains a file of the wallpaper of the specified type.
     * 
     * @param wallpaperType Indicates the wallpaper type.
     * @permission ohos.permission.GET_WALLPAPER.
     * ohos.permission.READ_USER_STORAGE.
     * @return the file descriptor.
     * @since 8
     * @deprecated since 9
     */
    function getFile(wallpaperType: WallpaperType, callback: AsyncCallback<number>): void;
    function getFile(wallpaperType: WallpaperType): Promise<number>;

    /**
     * Obtains a file of the wallpaper of the specified type.
     * 
     * @param wallpaperType Indicates the wallpaper type.
     * @permission ohos.permission.GET_WALLPAPER.
     * @return the file descriptor.
     * @throws {BusinessError} Parameter error.
     * @since 9
     */
    function getFileSync(wallpaperType: WallpaperType): number;

    /**
     * Obtains the minimum height of the wallpaper.
     * 
     * @return the minimum height, in pixels; returns {@code 0} if no wallpaper has been set.
     * @deprecated since 9
     */
    function getMinHeight(callback: AsyncCallback<number>): void;
    function getMinHeight(): Promise<number>;

    /**
     * Obtains the minimum height of the wallpaper.
     * 
     * @return the minimum height, in pixels; returns {@code 0} if no wallpaper has been set.
     * @since 9
     */
    function getMinHeightSync(): number;

    /**
     * Obtains the minimum width of the wallpaper.
     * 
     * @return the minimum width, in pixels; returns {@code 0} if no wallpaper has been set.
     * @deprecated since 9
     */
    function getMinWidth(callback: AsyncCallback<number>): void;
    function getMinWidth(): Promise<number>;

    /**
     * Obtains the minimum width of the wallpaper.
     * 
     * @return the minimum width, in pixels; returns {@code 0} if no wallpaper has been set.
     * @since 9
     */
    function getMinWidthSync(): number;

    /**
     * Checks whether to allow the application to change the wallpaper for the current user.
     * 
     * @return true if the application is allowed to set a wallpaper for the current user;
     * @deprecated since 9
     */
    function isChangePermitted(callback: AsyncCallback<boolean>): void;
    function isChangePermitted(): Promise<boolean>;

    /**
     * Checks whether to allow the application to change the wallpaper for the current user.
     * 
     * @return true if the application is allowed to set a wallpaper for the current user;
     * @since 9
     */
    function isChangePermittedSync(): boolean;

    /**
     * Checks whether a user is allowed to set wallpapers.
     * 
     * @return true if a user is allowed to set wallpapers; returns false otherwise.
     * @deprecated since 9
     */
    function isOperationAllowed(callback: AsyncCallback<boolean>): void;
    function isOperationAllowed(): Promise<boolean>;

    /**
     * Checks whether a user is allowed to set wallpapers.
     * 
     * @return true if a user is allowed to set wallpapers; returns false otherwise.
     * @since 9
     */
    function isOperationAllowedSync(): boolean;

    /**
     * Removes a wallpaper of the specified type and restores the default one.
     * 
     * @param wallpaperType Indicates the wallpaper type.
     * @permission ohos.permission.SET_WALLPAPER
     * @deprecated since 9
     */
    function reset(wallpaperType: WallpaperType, callback: AsyncCallback<void>): void;
    function reset(wallpaperType: WallpaperType): Promise<void>;

    /**
     * Removes a wallpaper of the specified type and restores the default one.
     * 
     * @param wallpaperType Indicates the wallpaper type.
     * @throws {BusinessError} Parameter error.
     * @throws {BusinessError} Permission denied.
     * @permission ohos.permission.SET_WALLPAPER
     * @since 9
     */
    function resetWithException(wallpaperType: WallpaperType, callback: AsyncCallback<void>): void;
    function resetWithException(wallpaperType: WallpaperType): Promise<void>;

    /**
     * Sets a wallpaper of the specified type based on the uri path from a JPEG or PNG file or the pixel map of a PNG file.
     * 
     * @param source Indicates the uri path from a JPEG or PNG file or the pixel map of the PNG file.
     * @param wallpaperType Indicates the wallpaper type.
     * @permission ohos.permission.SET_WALLPAPER
     */
    function setWallpaper(source: string | image.PixelMap, wallpaperType: WallpaperType, callback: AsyncCallback<void>): void;
    function setWallpaper(source: string | image.PixelMap, wallpaperType: WallpaperType): Promise<void>;

    /**
     * Sets a wallpaper of the specified type based on the uri path from a JPEG or PNG file or the pixel map of a PNG file.
     * 
     * @param source Indicates the uri path from a JPEG or PNG file or the pixel map of the PNG file.
     * @param wallpaperType Indicates the wallpaper type.
     * @throws {BusinessError} Parameter error.
     * @throws {BusinessError} Permission denied.
     * @permission ohos.permission.SET_WALLPAPER
     * @since 9
     */
    function setWallpaperWithException(source: string | image.PixelMap, wallpaperType: WallpaperType, callback: AsyncCallback<void>): void;
    function setWallpaperWithException(source: string | image.PixelMap, wallpaperType: WallpaperType): Promise<void>;

    /**
     * Obtains the default pixel map of a wallpaper of the specified type.
     * 
     * @param wallpaperType Indicates the wallpaper type.
     * @return the default pixel map.
     * @permission ohos.permission.GET_WALLPAPER
     * @systemapi Hide this for inner system use.
     */
    function getPixelMap(wallpaperType: WallpaperType, callback: AsyncCallback<image.PixelMap>): void;
    function getPixelMap(wallpaperType: WallpaperType): Promise<image.PixelMap>;

    /**
     *
     * Obtains the default pixel map of a wallpaper of the specified type.
     * 
     * @param wallpaperType Indicates the wallpaper type.
     * @return the default pixel map.
     * @throws {BusinessError} Parameter error.
     * @throws {BusinessError} Permission denied.
     * @permission ohos.permission.GET_WALLPAPER
     * @systemapi Hide this for inner system use.
     * @since 9
     */
    function getPixelMapWithException(wallpaperType: WallpaperType, callback: AsyncCallback<image.PixelMap>): void;
    function getPixelMapWithException(wallpaperType: WallpaperType): Promise<image.PixelMap>;

    /**
     * Screen shot live wallpaper
     * 
     * @param scale scale the PixelMap
     * @param pixelFormat pixel format
     * @return the pixel map of wallpaper.
     * @permission ohos.permission.CAPTURE_SCREEN
     * @systemapi Hide this for inner system use.
     * @since 7
     */
    /**
     * Screen shot live wallpaper
     * 
     * @param scale scale the PixelMap
     * @param pixelFormat pixel format
     * @return the pixel map of wallpaper.
     * @throws {BusinessError} Parameter error.
     * @throws {BusinessError} Permission denied.
     * @permission ohos.permission.CAPTURE_SCREEN
     * @systemapi Hide this for inner system use.
     * @since 9
     */
    function screenshotLiveWallpaper(scale: number, pixelFormat: image.PixelMapFormat, callback: AsyncCallback<image.PixelMap>): void;
    function screenshotLiveWallpaper(scale: number, pixelFormat: image.PixelMapFormat): Promise<image.PixelMap>;

    /**
     * Registers a listener for wallpaper color changes to receive notifications about the changes.
     * 
     * @param type The incoming colorChange table open receiver pick a color change wallpaper wallpaper color changes
     * @param callback Provides dominant colors of the wallpaper.
     * @since 7
     */
    /**
     * Registers a listener for wallpaper color changes to receive notifications about the changes.
     * 
     * @param type The incoming colorChange table open receiver pick a color change wallpaper wallpaper color changes
     * @param callback Provides dominant colors of the wallpaper.
     * @throws {BusinessError} Parameter error.
     * @since 9
     */
    function on(type: 'colorChange', callback: (colors: Array<RgbaColor>, wallpaperType: WallpaperType) => void): void;

    /**
     * Unregisters a listener for wallpaper color changes.
     * 
     * @param type Incoming 'colorChange' table delete receiver to pick up a color change wallpaper wallpaper color changes
     * @param callback Provides dominant colors of the wallpaper.
     * @since 7
     */
    /**
     * Unregisters a listener for wallpaper color changes.
     * 
     * @param type Incoming 'colorChange' table delete receiver to pick up a color change wallpaper wallpaper color changes
     * @param callback Provides dominant colors of the wallpaper.
     * @throws {BusinessError} Parameter error.
     * @since 9
     */
    function off(type: 'colorChange', callback?: (colors: Array<RgbaColor>, wallpaperType: WallpaperType) => void): void;

    interface RgbaColor {
        /**
         * Said the red value, the range is 0 to 255.
         */
        red: number;
        /**
         * Said the green value, the range is 0 to 255.
         */
        green: number;
        /**
         * Said the blue value, the range is 0 to 255.
         */
        blue: number;
        /**
         * Said the alpha value, the range is 0 to 255.
         */
        alpha: number;
    }
}

export default wallpaper;
