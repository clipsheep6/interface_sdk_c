/*
 * Copyright (C) 2023 Huawei Device Co., Ltd.
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
 * @addtogroup OH_Camera
 * @{
 *
 * @brief Provide the definition of the C interface for the camera module.
 *
 * @syscap SystemCapability.Multimedia.Camera.Core
 *
 * @since 11
 * @version 1.0
 */

/**
 * @file camera.h
 *
 * @brief Declare the camera base concepts.
 *
 * @library libohcamera.so
 * @kit CameraKit
 * @syscap SystemCapability.Multimedia.Camera.Core
 * @since 11
 * @version 1.0
 */

#ifndef NATIVE_INCLUDE_CAMERA_CAMERA_H
#define NATIVE_INCLUDE_CAMERA_CAMERA_H

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief camera manager object.
 *
 * A pointer can be created using {@link OH_Camera_GetCameraManager} method.
 *
 * @since 11
 * @version 1.0
 */
typedef struct Camera_Manager Camera_Manager;

/**
 * @brief Enum for camera error code.
 *
 * @since 11
 * @version 1.0
 */
typedef enum Camera_ErrorCode {
    /**
     * Camera result is ok.
     */
    CAMERA_OK = 0,

    /**
     * Parameter missing or parameter type incorrect.
     */
    CAMERA_INVALID_ARGUMENT = 7400101,

    /**
     * Operation not allowed.
     */
    CAMERA_OPERATION_NOT_ALLOWED = 7400102,

    /**
     * Session not config.
     */
    CAMERA_SESSION_NOT_CONFIG = 7400103,

    /**
     * Session not running.
     */
    CAMERA_SESSION_NOT_RUNNING = 7400104,

    /**
     * Session config locked.
     */
    CAMERA_SESSION_CONFIG_LOCKED = 7400105,

    /**
     * Device setting locked.
     */
    CAMERA_DEVICE_SETTING_LOCKED = 7400106,

    /**
     * Can not use camera cause of conflict.
     */
    CAMERA_CONFLICT_CAMERA = 7400107,

    /**
     * Camera disabled cause of security reason.
     */
    CAMERA_DEVICE_DISABLED = 7400108,

    /**
     * Can not use camera cause of preempted.
     */
    CAMERA_DEVICE_PREEMPTED = 7400109,

    /**
     * Unresolved conflicts with current configurations.
     * @since 12
     */
    CAMERA_UNRESOLVED_CONFLICTS_WITH_CURRENT_CONFIGURATIONS = 7400110,

    /**
     * Camera service fatal error.
     */
    CAMERA_SERVICE_FATAL_ERROR = 7400201
} Camera_ErrorCode;

/**
 * @brief Enum for camera status.
 *
 * @since 11
 * @version 1.0
 */
typedef enum Camera_Status {
    /**
     * Appear status.
     */
    CAMERA_STATUS_APPEAR = 0,

    /**
     * Disappear status.
     */
    CAMERA_STATUS_DISAPPEAR = 1,

    /**
     * Available status.
     */
    CAMERA_STATUS_AVAILABLE = 2,

    /**
     * Unavailable status.
     */
    CAMERA_STATUS_UNAVAILABLE = 3
} Camera_Status;

/**
 * @brief Enum for scence mode.
 *
 * @since 12
 * @version 1.0
 */
typedef enum Camera_SceneMode {
    /**
     * Normal photo mode.
     */
    NORMAL_PHOTO = 1,

    /**
     * Normal video mode.
     */
    NORMAL_VIDEO = 2,

    /**
     * Secure photo mode.
     */
    SECURE_PHOTO = 12
} Camera_SceneMode;

/**
 * @brief Enum for camera position.
 *
 * @since 11
 * @version 1.0
 */
typedef enum Camera_Position {
    /**
     * Unspecified position.
     */
    CAMERA_POSITION_UNSPECIFIED = 0,

    /**
     * Back position.
     */
    CAMERA_POSITION_BACK = 1,

    /**
     * Front position.
     */
    CAMERA_POSITION_FRONT = 2
} Camera_Position;

/**
 * @brief Enum for camera type.
 *
 * @since 11
 * @version 1.0
 */
typedef enum Camera_Type {
    /**
     * Default camera type.
     */
    CAMERA_TYPE_DEFAULT = 0,

    /**
     * Wide camera.
     */
    CAMERA_TYPE_WIDE_ANGLE = 1,

    /**
     * Ultra wide camera.
     */
    CAMERA_TYPE_ULTRA_WIDE = 2,

    /**
     * Telephoto camera.
     */
    CAMERA_TYPE_TELEPHOTO = 3,

    /**
     * True depth camera.
     */
    CAMERA_TYPE_TRUE_DEPTH = 4
} Camera_Type;

/**
 * @brief Enum for camera connection type.
 *
 * @since 11
 * @version 1.0
 */
typedef enum Camera_Connection {
    /**
     * Built-in camera.
     */
    CAMERA_CONNECTION_BUILT_IN = 0,

    /**
     * Camera connected using USB.
     */
    CAMERA_CONNECTION_USB_PLUGIN = 1,

    /**
     * Remote camera.
     */
    CAMERA_CONNECTION_REMOTE = 2
} Camera_Connection;

/**
 * @brief Enum for camera format type.
 *
 * @since 11
 * @version 1.0
 */
typedef enum Camera_Format {
    /**
     * RGBA 8888 Format.
     */
    CAMERA_FORMAT_RGBA_8888 = 3,

    /**
     * YUV 420 Format.
     */
    CAMERA_FORMAT_YUV_420_SP = 1003,

    /**
     * JPEG Format.
     */
    CAMERA_FORMAT_JPEG = 2000,

    /**
     * YCBCR P010 Format.
     * @since 12
     */
    CAMERA_FORMAT_YCBCR_P010 = 2001,

    /**
     * YCRCB P010 Format.
     * @since 12
     */
    CAMERA_FORMAT_YCRCB_P010 = 2002
} Camera_Format;

/**
 * @brief Enum for flash mode.
 *
 * @since 11
 * @version 1.0
 */
typedef enum Camera_FlashMode {
    /**
     * Close mode.
     */
    FLASH_MODE_CLOSE = 0,

    /**
     * Open mode.
     */
    FLASH_MODE_OPEN = 1,

    /**
     * Auto mode.
     */
    FLASH_MODE_AUTO = 2,

    /**
     * Always open mode.
     */
    FLASH_MODE_ALWAYS_OPEN = 3
} Camera_FlashMode;

/**
 * @brief Enum for exposure mode.
 *
 * @since 11
 * @version 1.0
 */
typedef enum Camera_ExposureMode {
    /**
     * Lock exposure mode.
     */
    EXPOSURE_MODE_LOCKED = 0,

    /**
     * Auto exposure mode.
     */
    EXPOSURE_MODE_AUTO = 1,

    /**
     * Continuous automatic exposure.
     */
    EXPOSURE_MODE_CONTINUOUS_AUTO = 2
} Camera_ExposureMode;

/**
 * @brief Enum for focus mode.
 *
 * @since 11
 * @version 1.0
 */
typedef enum Camera_FocusMode {
    /**
     * Manual mode.
     */
    FOCUS_MODE_MANUAL = 0,

    /**
     * Continuous auto mode.
     */
    FOCUS_MODE_CONTINUOUS_AUTO = 1,

    /**
     * Auto mode.
     */
    FOCUS_MODE_AUTO = 2,

    /**
     * Locked mode.
     */
    FOCUS_MODE_LOCKED = 3
} Camera_FocusMode;

/**
 * @brief Enum for focus state.
 *
 * @since 11
 * @version 1.0
 */
typedef enum Camera_FocusState {
    /**
     * Scan state.
     */
    FOCUS_STATE_SCAN = 0,

    /**
     * Focused state.
     */
    FOCUS_STATE_FOCUSED = 1,

    /**
     * Unfocused state.
     */
    FOCUS_STATE_UNFOCUSED = 2
} Camera_FocusState;

/**
 * @brief Enum for video stabilization mode.
 *
 * @since 11
 * @version 1.0
 */
typedef enum Camera_VideoStabilizationMode {
    /**
     * Turn off video stablization.
     */
    STABILIZATION_MODE_OFF = 0,

    /**
     * LOW mode provides basic stabilization effect.
     */
    STABILIZATION_MODE_LOW = 1,

    /**
     * MIDDLE mode means algorithms can achieve better effects than LOW mode.
     */
    STABILIZATION_MODE_MIDDLE = 2,

    /**
     * HIGH mode means algorithms can achieve better effects than MIDDLE mode.
     */
    STABILIZATION_MODE_HIGH = 3,

    /**
     * Camera HDF can select mode automatically.
     */
    STABILIZATION_MODE_AUTO = 4
} Camera_VideoStabilizationMode;

/**
 * @brief Enum for the image rotation angles.
 *
 * @since 11
 * @version 1.0
 */
typedef enum Camera_ImageRotation {
    /**
     * The capture image rotates 0 degrees.
     */
    IAMGE_ROTATION_0 = 0,

    /**
     * The capture image rotates 90 degrees.
     */
    IAMGE_ROTATION_90 = 90,

    /**
     * The capture image rotates 180 degrees.
     */
    IAMGE_ROTATION_180 = 180,

    /**
     * The capture image rotates 270 degrees.
     */
    IAMGE_ROTATION_270 = 270
} Camera_ImageRotation;

/**
 * @brief Enum for the image quality levels.
 *
 * @since 11
 * @version 1.0
 */
typedef enum Camera_QualityLevel {
    /**
     * High image quality.
     */
    QUALITY_LEVEL_HIGH = 0,

    /**
     * Medium image quality.
     */
    QUALITY_LEVEL_MEDIUM = 1,

    /**
     * Low image quality.
     */
    QUALITY_LEVEL_LOW = 2
} Camera_QualityLevel;

/**
 * @brief Enum for metadata object type.
 *
 * @since 11
 * @version 1.0
 */
typedef enum Camera_MetadataObjectType {
    /**
     * Face detection.
     */
    FACE_DETECTION = 0
} Camera_MetadataObjectType;

/**
 * @brief Enum for torch mode.
 *
 * @since 12
 * @version 1.0
 */
typedef enum Camera_TorchMode {
    /**
     * The device torch is always off.
     */
    OFF = 0,

    /**
     * The device torch is always on.
     */
    ON = 1,

    /**
     * The device continuously monitors light levels and
     * uses the torch when necessary.
     */
    AUTO = 2
} Camera_TorchMode;

/**
 * @brief Enum for smooth zoom mode.
 *
 * @since 12
 * @version 1.0
 */
typedef enum Camera_SmoothZoomMode {
    /**
     * Normal zoom mode.
     */
    NORMAL = 0
} Camera_SmoothZoomMode;

/**
 * @brief Enum for preconfig type.
 *
 * @since 12
 * @version 1.0
 */
typedef enum Camera_PreconfigType {
    /**
     * The preconfig type is 720P.
     */
    PRECONFIG_720P = 0,

    /**
     * The preconfig type is 1080P.
     */
    PRECONFIG_1080P = 1,

    /**
     * The preconfig type is 4K.
     */
    PRECONFIG_4K = 2,

    /**
     * The preconfig type is high quality.
     */
    PRECONFIG_HIGH_QUALITY = 3
} Camera_PreconfigType;

/**
 * @brief Enum for preconfig ratio.
 *
 * @since 12
 * @version 1.0
 */
typedef enum Camera_PreconfigRatio {
    /**
     * The preconfig ratio is 1:1.
     */
    PRECONFIG_RATIO_1_1 = 0,

    /**
     * The preconfig ratio 4:3.
     */
    PRECONFIG_RATIO_4_3 = 1,

    /**
     * The preconfig ratio 16:9.
     */
    PRECONFIG_RATIO_16_9 = 2
} Camera_PreconfigRatio;

/**
 * @brief Enum for remote camera device type.
 *
 * @since 15
 * @version 1.0
 */
typedef enum Camera_HostDeviceType {
    /**
     * Indicates an unknown device camera.
     */
    HOST_DEVICE_TYPE_UNKNOWN_TYPE = 0,

    /**
     * Indicates a smartphone camera.
     */
    HOST_DEVICE_TYPE_PHONE = 0x0E,

    /**
     * Indicates tablet camera.
     */
    HOST_DEVICE_TYPE_TABLET = 0x11
} Camera_HostDeviceType;

/**
 * @brief Size parameter.
 *
 * @since 11
 * @version 1.0
 */
typedef struct Camera_Size {
    /**
     * Width.
     */
    uint32_t width;

    /**
     * Height.
     */
    uint32_t height;
} Camera_Size;

/**
 * @brief Profile for camera streams.
 *
 * @since 11
 * @version 1.0
 */
typedef struct Camera_Profile {
    /**
     * Camera format.
     */
    Camera_Format format;

    /**
     * Picture size.
     */
    Camera_Size size;
} Camera_Profile;

/**
 * @brief Frame rate range.
 *
 * @since 11
 * @version 1.0
 */
typedef struct Camera_FrameRateRange {
    /**
     * Min frame rate.
     */
    uint32_t min;

    /**
     * Max frame rate.
     */
    uint32_t max;
} Camera_FrameRateRange;

/**
 * @brief Video profile.
 *
 * @since 11
 * @version 1.0
 */
typedef struct Camera_VideoProfile {
    /**
     * Camera format.
     */
    Camera_Format format;

    /**
     * Picture size.
     */
    Camera_Size size;

    /**
     * Frame rate in unit fps (frames per second).
     */
    Camera_FrameRateRange range;
} Camera_VideoProfile;

/**
 * @brief Camera output capability.
 *
 * @since 11
 * @version 1.0
 */
typedef struct Camera_OutputCapability {
    /**
     * Preview profiles list.
     */
    Camera_Profile** previewProfiles;

    /**
     * Size of preview profiles list.
     */
    uint32_t previewProfilesSize;

    /**
     * Photo profiles list.
     */
    Camera_Profile** photoProfiles;

    /**
     * Size of photo profiles list.
     */
    uint32_t photoProfilesSize;

    /**
     * Video profiles list.
     */
    Camera_VideoProfile** videoProfiles;

    /**
     * Size of video profiles list.
     */
    uint32_t videoProfilesSize;

    /**
     * Metadata object types list.
     */
    Camera_MetadataObjectType** supportedMetadataObjectTypes;

    /**
     * Size of metadata object types list.
     */
    uint32_t metadataProfilesSize;
} Camera_OutputCapability;

/**
 * @brief Camera device object.
 *
 * @since 11
 * @version 1.0
 */
typedef struct Camera_Device {
    /**
     * Camera id attribute.
     */
    char* cameraId;

    /**
     * Camera position attribute.
     */
    Camera_Position cameraPosition;

    /**
     * Camera type attribute.
     */
    Camera_Type cameraType;

    /**
     * Camera connection type attribute.
     */
    Camera_Connection connectionType;
} Camera_Device;

/**
 * @brief Camera status info.
 *
 * @since 11
 * @version 1.0
 */
typedef struct Camera_StatusInfo {
    /**
     * Camera instance.
     */
    Camera_Device* camera;

    /**
     * Current camera status.
     */
    Camera_Status status;
} Camera_StatusInfo;

/**
 * @brief Point parameter.
 *
 * @since 11
 * @version 1.0
 */
typedef struct Camera_Point {
    /**
     * X co-ordinate.
     */
    double x;

    /**
     * Y co-ordinate.
     */
    double y;
} Camera_Point;

/**
 * @brief Photo capture location.
 *
 * @since 11
 * @version 1.0
 */
typedef struct Camera_Location {
    /**
     * Latitude.
     */
    double latitude;

    /**
     * Longitude.
     */
    double longitude;

    /**
     * Altitude.
     */
    double altitude;
} Camera_Location;

/**
 * @brief Photo capture options to set.
 *
 * @since 11
 * @version 1.0
 */
typedef struct Camera_PhotoCaptureSetting {
    /**
     * Photo image quality.
     */
    Camera_QualityLevel quality;

    /**
     * Photo rotation.
     */
    Camera_ImageRotation rotation;

    /**
     * Photo location.
     */
    Camera_Location* location;

    /**
     * Set the mirror photo function switch, default to false.
     */
    bool mirror;
} Camera_PhotoCaptureSetting;

/**
 * @brief Frame shutter callback info.
 *
 * @since 11
 * @version 1.0
 */
typedef struct Camera_FrameShutterInfo {
    /**
     * Capture id.
     */
    int32_t captureId;

    /**
     * Timestamp for frame.
     */
    uint64_t timestamp;
} Camera_FrameShutterInfo;

/**
 * @brief Capture end info.
 *
 * @since 11
 * @version 1.0
 */
typedef struct Camera_CaptureEndInfo {
    /**
     * Capture id.
     */
    int32_t captureId;

    /**
     * Frame count.
     */
    int64_t frameCount;
} Camera_CaptureEndInfo;

/**
 * @brief Rectangle definition.
 *
 * @since 11
 * @version 1.0
 */
typedef struct Camera_Rect {
    /**
     * X coordinator of top left point.
     */
    int32_t topLeftX;

    /**
     * Y coordinator of top left point.
     */
    int32_t topLeftY;

    /**
     * Width of this rectangle.
     */
    int32_t width;

    /**
     * Height of this rectangle.
     */
    int32_t height;
} Camera_Rect;

/**
 * @brief Metadata object basis.
 *
 * @since 11
 * @version 1.0
 */
typedef struct Camera_MetadataObject {
    /**
     * Metadata object type.
     */
    Camera_MetadataObjectType type;

    /**
     * Metadata object timestamp in milliseconds.
     */
    int64_t timestamp;

    /**
     * The axis-aligned bounding box of detected metadata object.
     */
    Camera_Rect* boundingBox;
} Camera_MetadataObject;

/**
 * @brief Torch Status Info.
 *
 * @since 12
 * @version 1.0
 */
typedef struct Camera_TorchStatusInfo {
    /**
     * is torch available.
     */
    bool isTorchAvailable;

    /**
     * is torch active.
     */
    bool isTorchActive;

    /**
     * the current torch brightness level.
     */
    float torchLevel;
} Camera_TorchStatusInfo;

/**
 * @brief SmoothZoomInfo object.
 *
 * @since 12
 * @version 1.0
 */
typedef struct Camera_SmoothZoomInfo {
    /**
     * The duration of smooth zoom.
     */
    int32_t duration;
} Camera_SmoothZoomInfo;

/**
 * @brief Capture start info.
 *
 * @since 12
 * @version 1.0
 */
typedef struct Camera_CaptureStartInfo {
    /**
     * Capture id.
     */
    int32_t captureId;

    /**
     * Time(in milliseconds) is the shutter time for the photo.
     */
    int64_t time;
} Camera_CaptureStartInfo;

/**
 * @brief Frame shutter end callback info.
 *
 * @since 12
 * @version 1.0
 */
typedef struct Camera_FrameShutterEndInfo {
    /**
     * Capture id.
     */
    int32_t captureId;
} Camera_FrameShutterEndInfo;

/**
* @brief Enum for fold status.
*
* @since 13
* @version 1.0
*/
typedef enum Camera_FoldStatus {
    /**
     * Non_foldable status.
     */
    NON_FOLDABLE = 0,

    /**
     * Expanded status.
     */
    EXPANDED = 1,

    /**
     * Folded status.
     */
    FOLDED = 2
} Camera_FoldStatus;

/**
 * @brief Fold status info.
 *
 * @since 13
 * @version 1.0
 */
typedef struct Camera_FoldStatusInfo {
    /**
     * Camera instance list.
     */
    Camera_Device** supportedCameras;

    /**
     * Size of camera list.
     */
    uint32_t cameraSize;

    /**
     * Current fold status.
     */
    Camera_FoldStatus foldStatus;
} Camera_FoldStatusInfo;

/**
 * @brief Auto device switch status info.
 *
 * @since 13
 * @version 1.0
 */
typedef struct Camera_AutoDeviceSwitchStatusInfo {
    /**
     * is device switched.
     */
    bool isDeviceSwitched;

    /**
     * is device capability changed.
     */
    bool isDeviceCapabilityChanged;
} Camera_AutoDeviceSwitchStatusInfo;

/**
 * @brief Creates a CameraManager instance.
 *
 * @param cameraManager the output {@link Camera_Manager} cameraManager will be created
 *        if the method call succeeds.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @since 11
 */
Camera_ErrorCode OH_Camera_GetCameraManager(Camera_Manager** cameraManager);

/**
 * @brief Delete the CameraManager instance.
 *
 * @param cameraManager the {@link Camera_Manager} cameraManager instance to be deleted.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @since 11
 */
Camera_ErrorCode OH_Camera_DeleteCameraManager(Camera_Manager* cameraManager);

/**
 * @brief Enum for quality prioritization.
 *
 * @since 14
 * @version 1.0
 */
typedef enum Camera_QualityPrioritization {
    /**
     * Hight quality priority.
     */
    HIGH_QUALITY = 0,

    /**
     * Power balance priority.
     */
    POWER_BALANCE = 1
} Camera_QualityPrioritization;

/**
 * @brief Enum for camera concurrent type.
 *
 * @since 18
 * @version 1.0
 */
typedef enum Camera_ConcurrentType {
    /**
     * Cameras concurrency with limited capability.
     */
    CAMERA_CONCURRENT_TYPE_LIMITED_CAPABILITY  = 0,

    /**
     * Cameras concurrenct with full capability.
     */
    CAMERA_CONCURRENT_TYPE_FULL_CAPABILITY = 1
} Camera_ConcurrentType;

/**
 * @brief Concurrency capability infos.
 *
 * @since 18
 * @version 1.0
 */
typedef struct Camera_ConcurrentInfo {
    /**
     * Camera instance.
     */
    Camera_Device camera;

    /**
     * Supported concurrent type.
     */
    Camera_ConcurrentType type;

    /**
     * Supported Modes.
     */
    Camera_SceneMode* sceneModes;

    /**
     * Supported outputCapabilities
     */
    Camera_OutputCapability* outputCapabilities;

    /**
     * Supported outputCapabilities size.
     */
    uint32_t modeAndCapabilitySize;
} Camera_ConcurrentInfo;

/**
 * @brief Enumerates the white balance modes.
 *
 * @since 20
 * @version 1.0
 */
typedef enum Camera_WhiteBalanceMode {
    /**
     * Automatic white balance mode.
     */
    CAMERA_WHITE_BALANCE_MODE_AUTO = 0,

    /**
     * Cloudy white balance mode.
     */
    CAMERA_WHITE_BALANCE_MODE_CLOUDY = 1,

    /**
     * Incandescent white balance mode.
     */
    CAMERA_WHITE_BALANCE_MODE_INCANDESCENT = 2,

    /**
     * Fluorescent white balance mode.
     */
    CAMERA_WHITE_BALANCE_MODE_FLUORESCENT = 3,

    /**
     * Daylight white balance mode.
     */
    CAMERA_WHITE_BALANCE_MODE_DAYLIGHT = 4,

    /**
     * Manual white balance mode.
     */
    CAMERA_WHITE_BALANCE_MODE_MANUAL = 5,

    /**
     * Lock white balance mode.
     */
    CAMERA_WHITE_BALANCE_MODE_LOCKED = 6
} Camera_WhiteBalanceMode;

/**
 * @brief Enumerates the system pressure levels of the current camera session. When the system pressure
 * increases, you are advised to reduce the load of the current camera session.
 *
 * @since 20
 * @version 1.0
 */
typedef enum Camera_SystemPressureLevel {
    /**
     * Normal level. This level indicates the system pressure is normal.
     */
    SYSTEM_PRESSURE_NORMAL = 0,

    /**
     * Mild level. This level indicates the system pressure is slightly elevated.
     */
    SYSTEM_PRESSURE_MILD = 1,

    /**
     * Severe level. This level indicates the system pressure is severely elevated.
     */
    SYSTEM_PRESSURE_SEVERE = 2,

    /**
     * Critical level. This level indicates the system pressure is critically elevated.
     */
    SYSTEM_PRESSURE_CRITICAL = 3,

    /**
     * Shutdown level. This level indicates the system pressure is fatal, so the camera session will be shut down soon.
     */
    SYSTEM_PRESSURE_SHUTDOWN = 4
} Camera_SystemPressureLevel;

/**
 * @brief Enumerates the control center effect types.
 *
 * @since 20
 * @version 1.0
 */
typedef enum Camera_ControlCenterEffectType {
    /**
     * Control center beauty effect type.
     */
    CONTROL_CENTER_EFFECT_TYPE_BEAUTY = 0,

    /**
     * Control center portrait effect type.
     */
    CONTROL_CENTER_EFFECT_TYPE_PORTRAIT = 1
} Camera_ControlCenterEffectType;

/**
 * @brief Control center status info.
 *
 * @since 20
 * @version 1.0
 */
typedef struct Camera_ControlCenterStatusInfo {
    /**
     * Control center effect type.
     */
    Camera_ControlCenterEffectType effectType;

    /**
     * If control center effect is active.
     */
    bool isActive;
} Camera_ControlCenterStatusInfo;

#ifdef __cplusplus
}
#endif

#endif // NATIVE_INCLUDE_CAMERA_CAMERA_H
/** @} */