/*
 * Copyright (c) 2023 Huawei Device Co., Ltd.
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
 * @addtogroup 传感器
 * @{
 *
 * @brief 为您提供标准的开放api，定义常用传感器属性。
 *
 * @since 11
 */

/**
 * @file sensor_capi_base.h
 *
 * @brief 定义常用传感器属性。
 * @syscap SystemCapability.Sensors.Sensor
 *
 * @since 11
 */
#ifndef SENSOR_CAPI_BASE_H
#define SENSOR_CAPI_BASE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif
/** 传感器名称的最大长度 */
#ifndef NAME_MAX_LEN
#define NAME_MAX_LEN 128
#endif /* NAME_MAX_LEN */
/** 传感器数据大小 */
#ifndef SENSOR_USER_DATA_SIZE
#define SENSOR_USER_DATA_SIZE 104
#endif /* SENSOR_USER_DATA_SIZE */
/** 传感器版本的最大长度 */
#ifndef VERSION_MAX_LEN
#define VERSION_MAX_LEN 16
#endif /* SENSOR_USER_DATA_SIZE */

/**
 * @brief 传感器类型。
 *
 * @since 11
 */
typedef enum Sensor_SensorTypeId {
    ACCELEROMETER = 1,                    /**< 加速度传感器 */
    GYROSCOPE = 2,                        /**< 陀螺仪传感测器 */
    AMBIENT_LIGHT = 5,                    /**< 环境光传感器 */
    MAGNETIC_FIELD = 6,                   /**< 地磁传感器 */
    BAROMETER = 8,                        /**< 气压计传感器 */
    HALL = 10,                            /**< 霍尔传感器 */
    PROXIMITY = 12,                       /**< 接近光传感器 */
    HUMIDITY = 13,                        /**< 湿度传感器 */
    COLOR = 14,                           /**< 颜色传感器 */
    SAR = 15,                             /**< 吸收比率传感器 */
    ORIENTATION = 256,                    /**< 方向传感器 */
    GRAVITY = 257,                        /**< 重力传感器 */
    LINEAR_ACCELEROMETER = 258,           /**< 线性加速度传感器 */
    ROTATION_VECTOR = 259,                /**< 旋转矢量传感器 */
    AMBIENT_TEMPERATURE = 260,            /**< 温度传感器 */
    MAGNETIC_FIELD_UNCALIBRATED = 261,    /**< 未校准地磁传感器 */
    GYROSCOPE_UNCALIBRATED = 263,         /**< 未校准陀螺仪传感器 */
    SIGNIFICANT_MOTION = 264,             /**< 大幅动作检测传感器 */
    PEDOMETER_DETECTION = 265,            /**< 计步器检测传感器 */
    PEDOMETER = 266,                      /**< 计步器传感器 */
    HEART_RATE = 278,                     /**< 心率传感器 */
    WEAR_DETECTION = 280,                 /**< 佩戴检测传感器 */
    ACCELEROMETER_UNCALIBRATED = 281,     /**< 未校准加速度传感器 */
} Sensor_SensorTypeId;

/**
 * @brief 定义传感器操作错误码。
 *
 * @since 11
 */
typedef enum Sensor_Result {
    SENSOR_SUCCESS = 0,                   /**< 操作成功时返回该值 */
    SENSOR_PERMISSION_DENIED = 201,       /**< 当权限被拒绝时使用此错误代码 */
    SENSOR_PARAMETER_ERROR = 401,         /**< 当输入参数类型或范围不匹配时使用此错误代码 */
    SENSOR_SERVICE_EXCEPTION = 14500101,  /**< 当服务异常时使用此错误代码 */
} Sensor_Result;

/**
 * @brief 传感器属性信息。
 *
 * @since 11
 */
typedef struct Sensor_SensorInfo {
    char sensorName[NAME_MAX_LEN];   /**< 传感器名字 */
    char vendorName[NAME_MAX_LEN];   /**< 传感器供应商 */
    char firmwareVersion[VERSION_MAX_LEN];  /**< 传感器固件版本 */
    char hardwareVersion[VERSION_MAX_LEN];  /**< 传感器硬件版本 */
    int32_t sensorTypeId;  /**< 传感器类型 ID */
    int32_t index;      /**< 传感器编号，表示同类传感器的第几个器件，从0开始，默认是0, 0表示默认器件（主传感器）*/
    float maxRange;        /**< 传感器的最大测量范围 */
    float precision;       /**< 传感器精度 */
    float power;           /**< 传感器功率 */
    int64_t minSamplePeriod; /**< 允许的最小采样周期，以纳秒为单位 */
    int64_t maxSamplePeriod; /**< 允许的最大采样周期，以纳秒为单位 */
} Sensor_SensorInfo;

/**
 * @brief 列举传感器的数据报告模式。
 *
 * @since 11
 */
typedef enum Sensor_SensorMode {
    DEFAULT_MODE = 0,   /**< 默认数据报告模式 */
    REALTIME_MODE = 1,  /**< 实时上报数据模式，每次上报一组数据 */
    ON_CHANGE = 2,   /**< 实时上报数据模式，在状态发生变化时上报数据 */
    ONE_SHOT = 3,    /**< 实时上报数据模式，只上报一次数据 */
    FIFO_MODE = 4,   /**< 基于fifo的数据上报模式，根据<b>BatchCnt</b>设置上报数据 */
    MODE_MAX2,        /**< 最大传感器数据上报模式 */
} Sensor_SensorMode;

/**
 * @brief 上报的传感器数据信息。
 *
 * @since 11
 */
typedef struct Sensor_SensorEvent {
    int32_t sensorTypeId;  /**< 传感器类型 ID */
    int32_t version;       /**< 传感器算法版本 */
    int64_t timestamp;     /**< 报告传感器数据的时间 */
    int32_t option;       /**< 传感器数据选项，包括测量范围和精度 */
    int32_t mode;          /**< 传感器数据上报方式 (详细参考{@link Sensor_SensorMode}) */
    uint8_t *data = nullptr;         /**< 传感器数据 */
    uint32_t dataLen;      /**< 传感器数据长度 */
} Sensor_SensorEvent;

/**
 * @brief 传感器订阅Id。
 *
 * @since 11
 */
typedef struct Sensor_SubscribeId {
    Sensor_SensorTypeId sensorTypeId;   /**< 传感器类型ID */
    int32_t sensorIndex; /**< 当前类型的第几个传感器，默认值为0 */
    char networkId[NETWORK_ID_MAX_LEN]; /**< 分布式设备的networkId，默认值 "local" */
} Sensor_SubscribeId;

/**
 * @brief 传感器订阅属性。
 *
 * @since 11
 */
typedef struct Sensor_SubscribeAttribute {
    int64_t samplingInterval;     /**< 传感器采样周期 */
    int64_t reportInterval;       /**< 传感器上报频率 */
} Sensor_SubscribeAttribute;

/**
 * @brief 上报传感器数据的回调函数。
 *
 * @since 11
 */
typedef void (*Sensor_RecordSensorCallback)(Sensor_SensorEvent *event);

/**
 * @brief 为传感器订阅者预留的字段。
 *
 * @since 11
 */
typedef struct Sensor_UserData {
    char userData[SENSOR_USER_DATA_SIZE];  /**< 为传感器数据订阅者预留的字段 */
} Sensor_UserData;

/**
 * @brief 定义有关传感器数据订阅者的信息。
 *
 * @since 11
 */
typedef struct Sensor_SubscribeUser {
    char name[NAME_MAX_LEN];  /**< 传感器数据订阅者的名称 */
    Sensor_RecordSensorCallback callback;   /**< 用于报告传感器数据的回调 */
    Sensor_UserData *userData = nullptr;    /**< 传感器数据订阅者的保留字段 */
} Sensor_SubscribeUser;

/**
 * @brief 加速度传感器数据格式，
 * 表示施加在设备三个物理轴向（x、y 和 z）上的加速度（包含重力加速度），以 m/s2 为单位。
 *
 * @since 11
 */
typedef struct Sensor_AccelerometerData {
    float x;       /**< 施加在设备x轴的加速度（包含重力加速度），单位：m/s² */
    float y;       /**< 施加在设备y轴的加速度（包含重力加速度），单位：m/s² */
    float z;       /**< 施加在设备z轴的加速度（包含重力加速度），单位：m/s² */
} Sensor_AccelerometerData;

/**
 * @brief 线性加速度传感器数据格式。
 * 表示施加在设备三个物理轴向（x、y 和 z）上除去重力影响的线性加速度，以 m/s2 为单位。
 *
 * @since 11
 */
typedef struct Sensor_LinearAccelData {
    float x;       /**< 施加在设备x轴的线性加速度（不包含重力加速度），单位：m/s² */
    float y;       /**< 施加在设备y轴的线性加速度（不包含重力加速度），单位：m/s² */
    float z;       /**< 施加在设备z轴的线性加速度（不包含重力加速度），单位：m/s² */
} Sensor_LinearAccelData;

/**
 * @brief 陀螺仪传感器数据格式。
 * 表示设备在三个物理轴向（x、y 和 z）上的旋转角速度，以 rad/s 为单位。
 *
 * @since 11
 */
typedef struct Sensor_GyroscopeData {
    float x;       /**< 设备x轴的旋转角速度，单位：rad/s */
    float y;       /**< 设备y轴的旋转角速度，单位：rad/s */
    float z;       /**< 设备z轴的旋转角速度，单位：rad/s */
} Sensor_GyroscopeData;

/**
 * @brief 重力传感器数据格式。
 * 表示设备在三个物理轴向（x、y 和 z）上的重力，以 m/s2 为单位。
 *
 * @since 11
 */
typedef struct Sensor_GravityData {
    float x;       /**< 施加在设备x轴的重力，单位：m/s² */
    float y;       /**< 施加在设备y轴的重力，单位：m/s² */
    float z;       /**< 施加在设备z轴的重力，单位：m/s² */
} Sensor_GravityData;

/**
 * @brief 未校准加速度传感器。
 * 表示设备在三个物理轴(x、y 和 z)上的未校准加速度，以 m/s2 为单位。
 *
 * @since 11
 */
typedef struct Sensor_AccelUncalibratedData {
    float x;       /**< 施加在设备x轴未校准的加速度，单位：m/s² */
    float y;       /**< 施加在设备y轴未校准的加速度，单位：m/s² */
    float z;       /**< 施加在设备z轴未校准的加速度，单位：m/s² */
    float biasX;       /**< 施加在设备x轴未校准的加速度偏量，单位：m/s² */
    float biasY;       /**< 施加在设备上y轴未校准的加速度偏量，单位：m/s² */
    float biasZ;       /**< 施加在设备z轴未校准的加速度偏量，单位：m/s² */
} Sensor_AccelUncalibratedData;

/**
 * @brief 未校准陀螺仪传感器数据结构。
 * 表示设备在三个物理轴(x, y 和 z)上未校准旋转角速度，以 rad/s 为单位。
 *
 * @since 11
 */
typedef struct Sensor_GyroUncalibratedData {
    float x;       /**< 设备x轴未校准的旋转角速度，单位：rad/s */
    float y;       /**< 设备y轴未校准的旋转角速度，单位：rad/s */
    float z;       /**< 设备z轴未校准的旋转角速度，单位：rad/s */
    float biasX;       /**< 设备x轴未校准的旋转角速度偏量，单位：rad/s */
    float biasY;       /**< 设备y轴未校准的旋转角速度偏量，单位：rad/s */
    float biasZ;       /**< 设备z轴未校准的旋转角速度偏量，单位：rad/s */
} Sensor_GyroUncalibratedData;

/**
 * @brief 大幅动作检测传感器数据结构。
 * 表示设备在三个物理轴(x, y 和 z)是否存在大幅的运动，1 表示存在大幅的运动；0 表示没有大幅的运动。
 *
 * @since 11
 */
typedef struct Sensor_SignificantMotionData {
    float scalar;  /**< 表示剧烈运动程度。1 表示存在大幅度运动，0 表示没有大幅度运动 */
} Sensor_SignificantMotionData;

/**
 * @brief 计步器检测传感器数
 * 检测用户的计行走的状态；1 表示有行走的动作；0 则表示没有行走的动作。
 *
 * @since 11
 */
typedef struct Sensor_PedometerDetectData {
    float scalar;          /**< 计步器检测状态，1 表示有行走动作，0 表示没有动作 */
} Sensor_PedometerDetectData;

/**
 * @brief 计步器传感器数据结构。
 * 统计用户走过的步数。
 *
 * @since 11
 */
typedef struct Sensor_PedometerData {
    float steps;          /**< 用户的行走步数 */
} Sensor_PedometerData;

/**
 * @brief 温度传感器数据结构。
 * 测量环境温度，以摄氏度为单位。
 *
 * @since 11
 */
typedef struct Sensor_AmbientTemperatureData {
    float temperature;          /**< 环境温度，单位：摄氏度 */
} Sensor_AmbientTemperatureData;

/**
 * @brief 颜色传感器数据结构。
 * 测量光的强度，以勒克斯为单位；
 * 测量光的色温，以开尔文为单位。
 *
 * @since 11
 */
typedef struct Sensor_ColorData {
    float lightIntensity;          /**< 表示光的强度，单位：勒克斯 */
    float colorTemperature;        /**< 表示色温，单位：开尔文（k） */
} Sensor_ColorData;

/**
 * @brief 吸收比率传感器数据结构。
 * 测量吸收比率，以 W/kg 为单位。
 *
 * @since 11
 */
typedef struct Sensor_SarData {
    float absorptionRatio;        /**< 表示具体的吸收率，单位：W/kg */
} Sensor_SarData;

/**
 * @brief 湿度传感器数据结构。
 * 测量环境的相对湿度，以百分比(%)表示。
 *
 * @since 11
 */
typedef struct Sensor_HumidityData {
    float humidity;          /**< 湿度值。测量环境的相对湿度，以百分比 (%) 表示 */
} Sensor_HumidityData;

/**
 * @brief 地磁传感器数据结构。
 * 表示设备在三个物理轴(x, y 和 z)上的环境磁场强度，以 μT 为单位。
 *
 * @since 11
 */
typedef struct Sensor_MagneticFieldData {
    float x;       /**< 设备在x轴上的环境磁场强度，单位：μT */
    float y;       /**< 设备在y轴上的环境磁场强度，单位：μT */
    float z;       /**< 设备在z轴上的环境磁场强度，单位：μT */
} Sensor_MagneticFieldData;

/**
 * @brief 未校准地磁传感器数据结构。
 * 表示设备在三个物理轴(x, y 和 z)上的未校准环境磁场强度，以 μT 为单位。
 *
 * @since 11
 */
typedef struct Sensor_MagneticFieldUncalibratedData {
    float x;       /**< 设备在x轴上的未校准环境磁场强度，单位：μT */
    float y;       /**< 设备在y轴上的未校准环境磁场强度，单位：μT */
    float z;       /**< 设备在z轴上的未校准环境磁场强度，单位：μT */
    float biasX;       /**< 设备在x轴上的未校准环境磁场强度偏量，单位：μT */
    float biasY;       /**< 设备在y轴上的未校准环境磁场强度偏量，单位：μT */
    float biasZ;       /**< 设备在z轴上的未校准环境磁场强度偏量，单位：μT */
} Sensor_MagneticFieldUncalibratedData;

/**
 * @brief 气压计传感器数据结构。
 * 测量环境气压，以帕斯卡为单位。
 *
 * @since 11
 */
typedef struct Sensor_BarometerData {
    float pressure;       /**< 压力值，单位：帕斯卡 */
} Sensor_BarometerData;

/**
 * @brief 方向传感器数据结构。
 * 表示设备在三个物理轴(z, x 和 y)上旋转的角度值，以 rad 为单位。
 *
 * @since 11
 */
typedef struct Sensor_OrientationData {
    float alpha; /**< 设备在Z轴的旋转角度值，单位：rad */
    float beta;  /**< 设备在X轴的旋转角度值，单位：rad */
    float gamma; /**< 设备在Y轴的旋转角度值，单位：rad */
} Sensor_OrientationData;

/**
 * @brief 旋转矢量传感器数据结构。
 * 表示设备在三个物理轴(z, x 和 y)上旋转矢量，由加速度传感器和陀螺仪传感器合成。
 *
 * @since 11
 */
typedef struct Sensor_RotationVectorData {
    float x;       /**< 旋转矢量x轴分量 */
    float y;       /**< 旋转矢量y轴分量 */
    float z;       /**< 旋转矢量z轴分量 */
    float w;       /**< 标量 */
} Sensor_RotationVectorData;

/**
 * @brief 接近光传感器数据结构。
 * 表示设备显示的可见物体的接近度或距离，0 表示接近，大于 0 表示远离。
 *
 * @since 11
 */
typedef struct Sensor_ProximityData {
    float distance;       /**< 可见物体与设备显示器的接近程度。0 表示接近，大于 0 表示远离 */
} Sensor_ProximityData;

/**
 * @brief 环境光传感器数据结构。
 * 表示环境光的强度，以勒克斯为单位。
 *
 * @since 11
 */
typedef struct Sensor_AmbientLightData {
    float intensity;       /**< 表示光的强度，单位为：勒克斯 */
} Sensor_AmbientLightData;

/**
 * @brief 霍尔传感器数据结构。
 * 表示设备周围是否有磁力，0 表示没有磁力，大于 0 表示有磁力。
 *
 * @since 11
 */
typedef struct Sensor_HallData {
    float status;   /**< 显示霍尔状态。测量设备周围是否存在磁力吸引，0 表示没有，大于 0 表示有 */
} Sensor_HallData;

/**
 * @brief 心率传感器数据结构。
 * 表示用户的心率，以 bpm 为单位。
 *
 * @since 11
 */
typedef struct Sensor_HeartRateData {
    float heartRate;       /**< 用户的心率，单位：bpm */
} Sensor_HeartRateData;

/**
 * @brief 佩戴检测传感器数据结构。
 * 表示设备佩戴状态，1 表示已穿戴，0 表示未穿戴。
 *
 * @since 11
 */
typedef struct Sensor_WearDetectionData {
    float value;       /**< 佩戴状态，1 表示已穿戴，0 表示未穿戴 */
} Sensor_WearDetectionData;

#ifdef __cplusplus
}
#endif
#endif // SENSOR_CAPI_BASE_H