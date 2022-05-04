/**
 * BMX280 - BME280 & BMP280 Driver for Esspressif ESP-32.
 *
 * MIT License
 *
 * Copyright (C) 2020 Halit Utku Maden
 * Please contact at <utkumaden@hotmail.com>
 */

#ifndef _BMX280_DEFAULT_H_
#define _BMX280_DEFAULT_H_
#ifndef _BMX280_H_
#error Never include "bmx280_bits.h" by itself. Remove this reference and use "bmx280.h" instead.
#endif

typedef enum bmx280_tsmpl_t {
    BMX280_TEMPERATURE_OVERSAMPLING_NONE = 0x0,
    BMX280_TEMPERATURE_OVERSAMPLING_X1,
    BMX280_TEMPERATURE_OVERSAMPLING_X2,
    BMX280_TEMPERATURE_OVERSAMPLING_X4,
    BMX280_TEMPERATURE_OVERSAMPLING_X8,
    BMX280_TEMPERATURE_OVERSAMPLING_X16,
} bmx280_tsmpl_t;

typedef enum bmx280_psmpl_t {
    BMX280_PRESSURE_OVERSAMPLING_NONE = 0x0,
    BMX280_PRESSURE_OVERSAMPLING_X1,
    BMX280_PRESSURE_OVERSAMPLING_X2,
    BMX280_PRESSURE_OVERSAMPLING_X4,
    BMX280_PRESSURE_OVERSAMPLING_X8,
    BMX280_PRESSURE_OVERSAMPLING_X16,
} bmx280_psmpl_t;

#if !(CONFIG_BMX280_EXPECT_BMP280)
typedef enum bme280_hsmpl_t {
    BMX280_HUMIDITY_OVERSAMPLING_NONE = 0x0,
    BMX280_HUMIDITY_OVERSAMPLING_X1,
    BMX280_HUMIDITY_OVERSAMPLING_X2,
    BMX280_HUMIDITY_OVERSAMPLING_X4,
    BMX280_HUMIDITY_OVERSAMPLING_X8,
    BMX280_HUMIDITY_OVERSAMPLING_X16,
} bme280_hsmpl_t;
#endif

typedef enum bmx280_tstby_t {
    BMX280_STANDBY_0M5 = 0x0,
    BMX280_STANDBY_62M5,
    BMX280_STANDBY_125M,
    BMX280_STANDBY_250M,
    BMX280_STANDBY_500M,
    BMX280_STANDBY_1000M,
    BME280_STANDBY_10M,
    BME280_STANDBY_20M,
    BMP280_STANDBY_2000M = BME280_STANDBY_10M,
    BMP280_STANDBY_4000M = BME280_STANDBY_20M,
} bmx280_tstby_t;

typedef enum bmx280_iirf_t {
    BMX280_IIR_NONE = 0x0,
    BMX280_IIR_X1,
    BMX280_IIR_X2,
    BMX280_IIR_X4,
    BMX280_IIR_X8,
    BMX280_IIR_X16,
} bmx280_iirf_t;

typedef enum bmx280_mode_t {
    /** Sensor does no measurements. */
    BMX280_MODE_SLEEP = 0,
    /** Sensor is in a forced measurement cycle. Sleeps after finishing. */
    BMX280_MODE_FORCE = 1,
    /** Sensor does measurements. Never sleeps. */
    BMX280_MODE_CYCLE = 3,
} bmx280_mode_t;

typedef struct bmx280_config_t {
    bmx280_tsmpl_t t_sampling;
    bmx280_psmpl_t p_sampling;
    bmx280_tstby_t t_standby;
    bmx280_iirf_t iir_filter;
    #if !(CONFIG_BMX280_EXPECT_BMP280)
    bme280_hsmpl_t h_sampling;
    #endif
} bmx280_config_t;

#if (CONFIG_BMX280_DEFAULT_TEMPERATURE_OVERSAMPLING_NONE)
#define BMX280_DEFAULT_TEMPERATURE_OVERSAMPLING BMX280_TEMPERATURE_OVERSAMPLING_NONE
#elif (CONFIG_BMX280_DEFAULT_TEMPERATURE_OVERSAMPLING_X1)
#define BMX280_DEFAULT_TEMPERATURE_OVERSAMPLING BMX280_TEMPERATURE_OVERSAMPLING_X1
#elif (CONFIG_BMX280_DEFAULT_TEMPERATURE_OVERSAMPLING_X2)
#define BMX280_DEFAULT_TEMPERATURE_OVERSAMPLING BMX280_TEMPERATURE_OVERSAMPLING_X2
#elif (CONFIG_BMX280_DEFAULT_TEMPERATURE_OVERSAMPLING_X4)
#define BMX280_DEFAULT_TEMPERATURE_OVERSAMPLING BMX280_TEMPERATURE_OVERSAMPLING_X4
#elif (CONFIG_BMX280_DEFAULT_TEMPERATURE_OVERSAMPLING_X8)
#define BMX280_DEFAULT_TEMPERATURE_OVERSAMPLING BMX280_TEMPERATURE_OVERSAMPLING_X8
#else
#define BMX280_DEFAULT_TEMPERATURE_OVERSAMPLING BMX280_TEMPERATURE_OVERSAMPLING_X16
#endif

#if CONFIG_BMX280_DEFAULT_PRESSURE_OVERSAMPLING_NONE
#define BMX280_DEFAULT_PRESSURE_OVERSAMPLING BMX280_PRESSURE_OVERSAMPLING_NONE
#elif CONFIG_BMX280_DEFAULT_PRESSURE_OVERSAMPLING_X1
#define BMX280_DEFAULT_PRESSURE_OVERSAMPLING BMX280_PRESSURE_OVERSAMPLING_X1
#elif CONFIG_BMX280_DEFAULT_PRESSURE_OVERSAMPLING_X2
#define BMX280_DEFAULT_PRESSURE_OVERSAMPLING BMX280_PRESSURE_OVERSAMPLING_X2
#elif CONFIG_BMX280_DEFAULT_PRESSURE_OVERSAMPLING_X4
#define BMX280_DEFAULT_PRESSURE_OVERSAMPLING BMX280_PRESSURE_OVERSAMPLING_X4
#elif CONFIG_BMX280_DEFAULT_PRESSURE_OVERSAMPLING_X8
#define BMX280_DEFAULT_PRESSURE_OVERSAMPLING BMX280_PRESSURE_OVERSAMPLING_X8
#else
#define BMX280_DEFAULT_PRESSURE_OVERSAMPLING BMX280_PRESSURE_OVERSAMPLING_X16
#endif

#if (CONFIG_BMX280_DEFAULT_STANDBY_0M5)
#define BMX280_DEFAULT_STANDBY BMX280_STANDBY_0M5
#elif (CONFIG_BMX280_DEFAULT_STANDBY_62M5)
#define BMX280_DEFAULT_STANDBY BMX280_STANDBY_62M5
#elif (CONFIG_BMX280_DEFAULT_STANDBY_125M)
#define BMX280_DEFAULT_STANDBY BMX280_STANDBY_125M
#elif (CONFIG_BMX280_DEFAULT_STANDBY_250M)
#define BMX280_DEFAULT_STANDBY BMX280_STANDBY_250M
#elif (CONFIG_BMX280_DEFAULT_STANDBY_500M)
#define BMX280_DEFAULT_STANDBY BMX280_STANDBY_500M
#elif (CONFIG_BMX280_DEFAULT_STANDBY_1000M)
#define BMX280_DEFAULT_STANDBY BMX280_STANDBY_1000M
#elif (CONFIG_BMX280_DEFAULT_STANDBY_10M)
#define BMX280_DEFAULT_STANDBY BME280_STANDBY_10M
#else
#define BMX280_DEFAULT_STANDBY BMX280_STANDBY_20M
#endif

#if (CONFIG_BMX280_DEFAULT_IIR_NONE)
#define BMX280_DEFAULT_IIR BMX280_IIR_NONE
#elif (CONFIG_BMX280_DEFAULT_IIR_X2)
#define BMX280_DEFAULT_IIR BMX280_IIR_X2
#elif (CONFIG_BMX280_DEFAULT_IIR_X4)
#define BMX280_DEFAULT_IIR BMX280_IIR_X4
#elif (CONFIG_BMX280_DEFAULT_IIR_X8)
#define BMX280_DEFAULT_IIR BMX280_IIR_X8
#else
#define BMX280_DEFAULT_IIR BMX280_IIR_X16
#endif

#ifndef CONFIG_BMX280_EXPECT_BMP280
    #if (CONFIG_BMX280_DEFAULT_HUMIDITY_OVERSAMPLING_NONE)
        #define BMX280_DEFAULT_HUMIDITY_OVERSAMPLING BMX280_HUMIDITY_OVERSAMPLING_NONE
    #elif (CONFIG_BMX280_DEFAULT_HUMIDITY_OVERSAMPLING_X1)
        #define BMX280_DEFAULT_HUMIDITY_OVERSAMPLING BMX280_HUMIDITY_OVERSAMPLING_X1
    #elif (CONFIG_BMX280_DEFAULT_HUMIDITY_OVERSAMPLING_X2)
        #define BMX280_DEFAULT_HUMIDITY_OVERSAMPLING BMX280_HUMIDITY_OVERSAMPLING_X2
    #elif (CONFIG_BMX280_DEFAULT_HUMIDITY_OVERSAMPLING_X4)
        #define BMX280_DEFAULT_HUMIDITY_OVERSAMPLING BMX280_HUMIDITY_OVERSAMPLING_X4
    #elif (CONFIG_BMX280_DEFAULT_HUMIDITY_OVERSAMPLING_X8)
        #define BMX280_DEFAULT_HUMIDITY_OVERSAMPLING BMX280_HUMIDITY_OVERSAMPLING_X8
    #else
        #define BMX280_DEFAULT_HUMIDITY_OVERSAMPLING BMX280_HUMIDITY_OVERSAMPLING_X16
    #endif
#endif

#if !(CONFIG_BMX280_EXPECT_BMP280)
    #define BMX280_DEFAULT_CONFIG ((bmx280_config_t) { BMX280_DEFAULT_TEMPERATURE_OVERSAMPLING, BMX280_DEFAULT_PRESSURE_OVERSAMPLING, BMX280_DEFAULT_STANDBY, BMX280_DEFAULT_IIR, BMX280_DEFAULT_HUMIDITY_OVERSAMPLING })
#else
    #define BMX280_DEFAULT_CONFIG ((bmx280_config_t) { BMX280_DEFAULT_TEMPERATURE_OVERSAMPLING, BMX280_DEFAULT_PRESSURE_OVERSAMPLING, BMX280_DEFAULT_STANDBY, BMX280_DEFAULT_IIR})
#endif

#endif