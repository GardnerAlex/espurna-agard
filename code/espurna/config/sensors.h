// =============================================================================
// SENSORS - General configuration
// =============================================================================

#pragma once

#ifndef SENSOR_DEBUG
#define SENSOR_DEBUG                        0               // Debug sensors
#endif

#ifndef SENSOR_READ_INTERVAL
#define SENSOR_READ_INTERVAL                6               // Read data from sensors every 6 seconds
#endif

#ifndef SENSOR_READ_MIN_INTERVAL
#define SENSOR_READ_MIN_INTERVAL            1               // Minimum read interval
#endif

#ifndef SENSOR_READ_MAX_INTERVAL
#define SENSOR_READ_MAX_INTERVAL            3600            // Maximum read interval
#endif

#ifndef SENSOR_INIT_INTERVAL
#define SENSOR_INIT_INTERVAL                10              // Try to re-init non-ready sensors every 10s
#endif

#ifndef SENSOR_REPORT_EVERY
#define SENSOR_REPORT_EVERY                 10              // Report every this many readings
#endif

#ifndef SENSOR_REPORT_MIN_EVERY
#define SENSOR_REPORT_MIN_EVERY             1               // Minimum every value
#endif

#ifndef SENSOR_REPORT_MAX_EVERY
#define SENSOR_REPORT_MAX_EVERY             60              // Maximum
#endif

#ifndef SENSOR_USE_INDEX
#define SENSOR_USE_INDEX                    0               // Use the index in topic (i.e. temperature/0)
#endif
                                                            // even if just one sensor (0 for backwards compatibility)

#ifndef SENSOR_POWER_CHECK_STATUS
#define SENSOR_POWER_CHECK_STATUS           1               // If set to 1 the reported power/current/energy will be 0 if the relay[0] is OFF
#endif

#ifndef SENSOR_REAL_TIME_VALUES
#define SENSOR_REAL_TIME_VALUES             0               // Show filtered/median values by default (0 => median, 1 => real time)
#endif

#ifndef SENSOR_SAVE_EVERY
#define SENSOR_SAVE_EVERY                   0               // Save accumulating values to EEPROM (atm only energy)
                                                            // A 0 means do not save and it's the default value
                                                            // A number different from 0 means it should store the value in EEPROM
                                                            // after these many reports
                                                            // Warning: this might wear out flash fast!
#endif

#define SENSOR_PUBLISH_ADDRESSES            0               // Publish sensor addresses
#define SENSOR_ADDRESS_TOPIC                "address"       // Topic to publish sensor addresses


// -----------------------------------------------------------------------------
// Magnitude offset correction
// -----------------------------------------------------------------------------

#ifndef SENSOR_TEMPERATURE_CORRECTION
#define SENSOR_TEMPERATURE_CORRECTION       0.0
#endif

#ifndef SENSOR_HUMIDITY_CORRECTION
#define SENSOR_HUMIDITY_CORRECTION          0.0
#endif

#ifndef SENSOR_PRESSURE_CORRECTION
#define SENSOR_PRESSURE_CORRECTION          0.0
#endif

#ifndef SENSOR_LUX_CORRECTION
#define SENSOR_LUX_CORRECTION               0.0
#endif

// =============================================================================
// Specific data for each sensor
// =============================================================================

//------------------------------------------------------------------------------
// AM2320 Humidity & Temperature sensor over I2C
// Enable support by passing AM2320_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef AM2320_SUPPORT
#define AM2320_SUPPORT                  0
#endif

#ifndef AM2320_ADDRESS
#define AM2320_ADDRESS                  0x00    // 0x00 means auto
#endif

//------------------------------------------------------------------------------
// Analog sensor
// Enable support by passing ANALOG_SUPPORT=1 build flag
//--------------------------------------------------------------------------------

#ifndef ANALOG_SUPPORT
#define ANALOG_SUPPORT                  0
#endif

#ifndef ANALOG_SAMPLES
#define ANALOG_SAMPLES                  10      // Number of samples
#endif

#ifndef ANALOG_DELAY
#define ANALOG_DELAY                    0       // Delay between samples in micros
#endif

//Use the following to perform scaling of raw analog values
//   scaledRead = ( factor * rawRead ) + offset
//
//Please take note that the offset is not affected by the scaling factor

#ifndef ANALOG_FACTOR
#define ANALOG_FACTOR                    1.0       // Multiply raw reading by this factor
#endif

#ifndef ANALOG_OFFSET
#define ANALOG_OFFSET                    0.0       // Add this offset to *scaled* value
#endif

// Round to this number of decimals
#ifndef ANALOG_DECIMALS
#define ANALOG_DECIMALS                  2
#endif


//------------------------------------------------------------------------------
// BH1750
// Enable support by passing BH1750_SUPPORT=1 build flag
// http://www.elechouse.com/elechouse/images/product/Digital%20light%20Sensor/bh1750fvi-e.pdf
//------------------------------------------------------------------------------

#ifndef BH1750_SUPPORT
#define BH1750_SUPPORT                  0
#endif

#ifndef BH1750_ADDRESS
#define BH1750_ADDRESS                  0x00    // 0x00 means auto
#endif

#ifndef BH1750_ACCURACY
#define BH1750_ACCURACY                 1.2     // RAW value conversion ratio
                                                // Allowed values are 0.96...1.44
#endif

#ifndef BH1750_SENSITIVITY
#define BH1750_SENSITIVITY              1.0     // Measurement sensitivity; value is derived from 'MTreg CURRENT'
                                                // `SENSITIVITY = MTreg CURRENT / MTreg DEFAULT` (up to 2 decimal places)
                                                // e.g. for MTreg allowed values of 31...254
                                                // * 31 -> 0.45 (min)
                                                // * 69 -> 1.0
                                                // * 138 -> 2.0
                                                // * 207 -> 3.0
                                                // * 254 -> 3.68 (max)
#endif

#ifndef BH1750_MODE
#define BH1750_MODE                     BH1750_CONTINUOUS_HIGH_RES_MODE
#endif

//------------------------------------------------------------------------------
// BMP085/BMP180
// Enable support by passing BMP180_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef BMP180_SUPPORT
#define BMP180_SUPPORT                  0
#endif

#ifndef BMP180_ADDRESS
#define BMP180_ADDRESS                  0x00    // 0x00 means auto
#endif

#define BMP180_MODE                     3       // 0 for ultra-low power, 1 for standard, 2 for high resolution and 3 for ultrahigh resolution

//------------------------------------------------------------------------------
// BME280/BMP280
// Enable support by passing BMX280_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef BMX280_SUPPORT
#define BMX280_SUPPORT                  0
#endif

#ifndef BMX280_NUMBER
#define BMX280_NUMBER                   1       // Number of sensors present. Either 1 or 2 allowed
#endif
#ifndef BMX280_ADDRESS
#define BMX280_ADDRESS                  0x00    // 0x00 means auto (0x76 or 0x77 allowed) for sensor #0
#endif                                          // If (BMX280_NUMBER == 2) and
                                                //   (BMX280_ADDRESS == 0x00) then sensor #1 is auto-discovered
                                                //   (BMX280_ADDRESS != 0x00) then sensor #1 is the unnamed address

#ifndef BMX280_MODE
#define BMX280_MODE                     1       // 0 for sleep mode, 1 or 2 for forced mode, 3 for normal mode
#endif
#ifndef BMX280_STANDBY
#define BMX280_STANDBY                  0       // 0 for 0.5ms, 1 for 62.5ms, 2 for 125ms
                                                // 3 for 250ms, 4 for 500ms, 5 for 1000ms
                                                // 6 for 10ms, 7 for 20ms
#endif
#ifndef BMX280_FILTER
#define BMX280_FILTER                   0       // 0 for OFF, 1 for 2 values, 2 for 4 values, 3 for 8 values and 4 for 16 values
#endif
#ifndef BMX280_TEMPERATURE
#define BMX280_TEMPERATURE              1       // Oversampling for temperature (set to 0 to disable magnitude)
                                                // 0b000 = 0 = Skip measurement
                                                // 0b001 = 1 = 1x 16bit/0.0050C resolution
                                                // 0b010 = 2 = 2x 17bit/0.0025C
                                                // 0b011 = 3 = 4x 18bit/0.0012C
                                                // 0b100 = 4 = 8x 19bit/0.0006C
                                                // 0b101 = 5 = 16x 20bit/0.0003C
#endif
#ifndef BMX280_HUMIDITY
#define BMX280_HUMIDITY                 1       // Oversampling for humidity (set to 0 to disable magnitude, only for BME280)
                                                // 0b000 = 0 = Skip measurement
                                                // 0b001 = 1 = 1x 0.07% resolution
                                                // 0b010 = 2 = 2x 0.05%
                                                // 0b011 = 3 = 4x 0.04%
                                                // 0b100 = 4 = 8x 0.03%
                                                // 0b101 = 5 = 16x 0.02%
#endif
#ifndef BMX280_PRESSURE
#define BMX280_PRESSURE                 1       // Oversampling for pressure (set to 0 to disable magnitude)
                                                // 0b000 = 0 = Skipped
                                                // 0b001 = 1 = 1x 16bit/2.62 Pa resolution
                                                // 0b010 = 2 = 2x 17bit/1.31 Pa
                                                // 0b011 = 3 = 4x 18bit/0.66 Pa
                                                // 0b100 = 4 = 8x 19bit/0.33 Pa
                                                // 0b101 = 5 = 16x 20bit/0.16 Pa
#endif

//------------------------------------------------------------------------------
// Dallas OneWire temperature sensors
// Enable support by passing DALLAS_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef DALLAS_SUPPORT
#define DALLAS_SUPPORT                  0
#endif

#ifndef DALLAS_PIN
#define DALLAS_PIN                      14
#endif

#define DALLAS_RESOLUTION               9           // Not used atm
#define DALLAS_READ_INTERVAL            2000        // Force sensor read & cache every 2 seconds

//------------------------------------------------------------------------------
// DHTXX temperature/humidity sensor
// Enable support by passing DHT_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef DHT_SUPPORT
#define DHT_SUPPORT                     0
#endif

#ifndef DHT_PIN
#define DHT_PIN                         14
#endif

#ifndef DHT_TYPE
#define DHT_TYPE                        DHT_CHIP_DHT22
#endif

//------------------------------------------------------------------------------
// CSE7766 based power sensor
// Enable support by passing CSE7766_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef CSE7766_SUPPORT
#define CSE7766_SUPPORT                 0
#endif

#ifndef CSE7766_PORT
#define CSE7766_PORT                    1      // By default, use the first port
                                               // (needs `UART[1-3]_BAUDRATE 4800`)
#endif

//------------------------------------------------------------------------------
// Digital sensor
// Enable support by passing DIGITAL_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef DIGITAL_SUPPORT
#define DIGITAL_SUPPORT                 0
#endif

#ifndef DIGITAL1_PIN
#define DIGITAL1_PIN                    5
#endif

#ifndef DIGITAL1_PIN_MODE
#define DIGITAL1_PIN_MODE                INPUT_PULLUP
#endif

#ifndef DIGITAL1_DEFAULT_STATE
#define DIGITAL1_DEFAULT_STATE           HIGH
#endif

#ifndef DIGITAL2_PIN
#define DIGITAL2_PIN                     GPIO_NONE
#endif

#ifndef DIGITAL2_PIN_MODE
#define DIGITAL2_PIN_MODE                INPUT_PULLUP
#endif

#ifndef DIGITAL2_DEFAULT_STATE
#define DIGITAL2_DEFAULT_STATE           HIGH
#endif

#ifndef DIGITAL3_PIN
#define DIGITAL3_PIN                     GPIO_NONE
#endif

#ifndef DIGITAL3_PIN_MODE
#define DIGITAL3_PIN_MODE                INPUT_PULLUP
#endif

#ifndef DIGITAL3_DEFAULT_STATE
#define DIGITAL3_DEFAULT_STATE           HIGH
#endif

#ifndef DIGITAL4_PIN
#define DIGITAL4_PIN                     GPIO_NONE
#endif

#ifndef DIGITAL4_PIN_MODE
#define DIGITAL4_PIN_MODE                INPUT_PULLUP
#endif

#ifndef DIGITAL4_DEFAULT_STATE
#define DIGITAL4_DEFAULT_STATE           HIGH
#endif

#ifndef DIGITAL5_PIN
#define DIGITAL5_PIN                     GPIO_NONE
#endif

#ifndef DIGITAL5_PIN_MODE
#define DIGITAL5_PIN_MODE                INPUT_PULLUP
#endif

#ifndef DIGITAL5_DEFAULT_STATE
#define DIGITAL5_DEFAULT_STATE           HIGH
#endif

#ifndef DIGITAL6_PIN
#define DIGITAL6_PIN                     GPIO_NONE
#endif

#ifndef DIGITAL6_PIN_MODE
#define DIGITAL6_PIN_MODE                INPUT_PULLUP
#endif

#ifndef DIGITAL6_DEFAULT_STATE
#define DIGITAL6_DEFAULT_STATE           HIGH
#endif

#ifndef DIGITAL7_PIN
#define DIGITAL7_PIN                     GPIO_NONE
#endif

#ifndef DIGITAL7_PIN_MODE
#define DIGITAL7_PIN_MODE                INPUT_PULLUP
#endif

#ifndef DIGITAL7_DEFAULT_STATE
#define DIGITAL7_DEFAULT_STATE           HIGH
#endif

#ifndef DIGITAL8_PIN
#define DIGITAL8_PIN                     GPIO_NONE
#endif

#ifndef DIGITAL8_PIN_MODE
#define DIGITAL8_PIN_MODE                INPUT_PULLUP
#endif

#ifndef DIGITAL8_DEFAULT_STATE
#define DIGITAL8_DEFAULT_STATE           HIGH
#endif

//------------------------------------------------------------------------------
// Dummy sensor, implementing some of the magnitudes
// Enable support by passing DUMMY_SENSOR_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef DUMMY_SENSOR_SUPPORT
#define DUMMY_SENSOR_SUPPORT            0
#endif

//------------------------------------------------------------------------------
// ECH1560 based power sensor
// Enable support by passing ECH1560_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef ECH1560_SUPPORT
#define ECH1560_SUPPORT                 0
#endif

#ifndef ECH1560_CLK_PIN
#define ECH1560_CLK_PIN                 4       // CLK pin for the ECH1560
#endif

#ifndef ECH1560_MISO_PIN
#define ECH1560_MISO_PIN                5       // MISO pin for the ECH1560
#endif

#ifndef ECH1560_INVERTED
#define ECH1560_INVERTED                0       // Signal is inverted
#endif

//------------------------------------------------------------------------------
// Energy Monitor general settings
//------------------------------------------------------------------------------

#ifndef EMON_MAX_SAMPLES
#define EMON_MAX_SAMPLES                1000        // Max number of samples to get
#endif

#ifndef EMON_MAX_TIME
#define EMON_MAX_TIME                   250         // Max time in ms to sample
#endif

#ifndef EMON_FILTER_SPEED
#define EMON_FILTER_SPEED               512         // Mobile average filter speed
#endif

#ifndef EMON_REFERENCE_VOLTAGE
#define EMON_REFERENCE_VOLTAGE          3.3         // Reference voltage of the ADC
#endif

#ifndef EMON_MAINS_VOLTAGE
#define EMON_MAINS_VOLTAGE              230         // Mains voltage
#endif

#ifndef EMON_CURRENT_RATIO
#define EMON_CURRENT_RATIO              30.0        // Current ratio in the clamp (30A/1V)
#endif

#ifndef EMON_REPORT_CURRENT
#define EMON_REPORT_CURRENT             0           // Report current
#endif

#ifndef EMON_REPORT_POWER
#define EMON_REPORT_POWER               1           // Report power
#endif

#ifndef EMON_REPORT_ENERGY
#define EMON_REPORT_ENERGY              1           // Report energy
#endif

//------------------------------------------------------------------------------
// Energy Monitor based on ADC121
// Enable support by passing EMON_ADC121_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef EMON_ADC121_SUPPORT
#define EMON_ADC121_SUPPORT             0       // Do not build support by default
#endif

#ifndef EMON_ADC121_I2C_ADDRESS
#define EMON_ADC121_I2C_ADDRESS         0x00    // 0x00 means auto
#endif

//------------------------------------------------------------------------------
// Energy Monitor based on ADS1X15
// Enable support by passing EMON_ADS1X15_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef EMON_ADS1X15_SUPPORT
#define EMON_ADS1X15_SUPPORT            0       // Do not build support by default
#endif

#ifndef EMON_ADS1X15_I2C_ADDRESS
#define EMON_ADS1X15_I2C_ADDRESS        0x00    // 0x00 means auto
#endif

#ifndef EMON_ADS1X15_TYPE
#define EMON_ADS1X15_TYPE               ADS1X15_CHIP_ADS1115
#endif

#ifndef EMON_ADS1X15_GAIN
#define EMON_ADS1X15_GAIN               ADS1X15_REG_CONFIG_PGA_4_096V
#endif

#ifndef EMON_ADS1X15_DATARATE
#define EMON_ADS1X15_DATARATE           ADS1X15_REG_CONFIG_DR_MASK
#endif

#ifndef EMON_ADS1X15_MASK
#define EMON_ADS1X15_MASK               0x0F    // A0=1 aka 0b1
                                                // A1=2 aka 0b10
                                                // A2=4 aka 0b100
                                                // A3=8 aka 0b1000
#endif

//------------------------------------------------------------------------------
// Energy Monitor based on interval analog GPIO
// Enable support by passing EMON_ANALOG_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef EMON_ANALOG_SUPPORT
#define EMON_ANALOG_SUPPORT             0       // Do not build support by default
#endif

#ifndef EMON_ANALOG_RESOLUTION
#define EMON_ANALOG_RESOLUTION          10      // ADC resolution (in bits)
#endif

//------------------------------------------------------------------------------
// Counter sensor
// Enable support by passing EVENTS_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef EVENTS_SUPPORT
#define EVENTS_SUPPORT                  0       // Do not build with counter support by default
#endif

#ifndef EVENTS1_PIN
#define EVENTS1_PIN                      5       // GPIO to monitor
#endif

#ifndef EVENTS1_PIN_MODE
#define EVENTS1_PIN_MODE                 INPUT   // INPUT, INPUT_PULLUP
#endif

#ifndef EVENTS1_INTERRUPT_MODE
#define EVENTS1_INTERRUPT_MODE           RISING  // RISING, FALLING, CHANGE
#endif

#ifndef EVENTS1_DEBOUNCE
#define EVENTS1_DEBOUNCE                 50      // Do not register events within less than 50 millis
#endif

#ifndef EVENTS2_PIN
#define EVENTS2_PIN                      GPIO_NONE       // GPIO to monitor
#endif

#ifndef EVENTS2_PIN_MODE
#define EVENTS2_PIN_MODE                 INPUT   // INPUT, INPUT_PULLUP
#endif

#ifndef EVENTS2_INTERRUPT_MODE
#define EVENTS2_INTERRUPT_MODE           RISING  // RISING, FALLING, CHANGE
#endif

#ifndef EVENTS2_DEBOUNCE
#define EVENTS2_DEBOUNCE                 50      // Do not register events within less than 50 millis
#endif

#ifndef EVENTS3_PIN
#define EVENTS3_PIN                      GPIO_NONE       // GPIO to monitor
#endif

#ifndef EVENTS3_PIN_MODE
#define EVENTS3_PIN_MODE                 INPUT   // INPUT, INPUT_PULLUP
#endif

#ifndef EVENTS3_INTERRUPT_MODE
#define EVENTS3_INTERRUPT_MODE           RISING  // RISING, FALLING, CHANGE
#endif

#ifndef EVENTS3_DEBOUNCE
#define EVENTS3_DEBOUNCE                 50      // Do not register events within less than 50 millis
#endif

#ifndef EVENTS4_PIN
#define EVENTS4_PIN                      GPIO_NONE       // GPIO to monitor
#endif

#ifndef EVENTS4_PIN_MODE
#define EVENTS4_PIN_MODE                 INPUT   // INPUT, INPUT_PULLUP
#endif

#ifndef EVENTS4_INTERRUPT_MODE
#define EVENTS4_INTERRUPT_MODE           RISING  // RISING, FALLING, CHANGE
#endif

#ifndef EVENTS4_DEBOUNCE
#define EVENTS4_DEBOUNCE                 50      // Do not register events within less than 50 millis
#endif

#ifndef EVENTS5_PIN
#define EVENTS5_PIN                      GPIO_NONE       // GPIO to monitor
#endif

#ifndef EVENTS5_PIN_MODE
#define EVENTS5_PIN_MODE                 INPUT   // INPUT, INPUT_PULLUP
#endif

#ifndef EVENTS5_INTERRUPT_MODE
#define EVENTS5_INTERRUPT_MODE           RISING  // RISING, FALLING, CHANGE
#endif

#ifndef EVENTS5_DEBOUNCE
#define EVENTS5_DEBOUNCE                 50      // Do not register events within less than 50 millis
#endif

#ifndef EVENTS6_PIN
#define EVENTS6_PIN                      GPIO_NONE       // GPIO to monitor
#endif

#ifndef EVENTS6_PIN_MODE
#define EVENTS6_PIN_MODE                 INPUT   // INPUT, INPUT_PULLUP
#endif

#ifndef EVENTS6_INTERRUPT_MODE
#define EVENTS6_INTERRUPT_MODE           RISING  // RISING, FALLING, CHANGE
#endif

#ifndef EVENTS6_DEBOUNCE
#define EVENTS6_DEBOUNCE                 50      // Do not register events within less than 50 millis
#endif

#ifndef EVENTS7_PIN
#define EVENTS7_PIN                      GPIO_NONE       // GPIO to monitor
#endif

#ifndef EVENTS7_PIN_MODE
#define EVENTS7_PIN_MODE                 INPUT   // INPUT, INPUT_PULLUP
#endif

#ifndef EVENTS7_INTERRUPT_MODE
#define EVENTS7_INTERRUPT_MODE           RISING  // RISING, FALLING, CHANGE
#endif

#ifndef EVENTS7_DEBOUNCE
#define EVENTS7_DEBOUNCE                 50      // Do not register events within less than 50 millis
#endif

#ifndef EVENTS8_PIN
#define EVENTS8_PIN                      GPIO_NONE       // GPIO to monitor
#endif

#ifndef EVENTS8_PIN_MODE
#define EVENTS8_PIN_MODE                 INPUT   // INPUT, INPUT_PULLUP
#endif

#ifndef EVENTS8_INTERRUPT_MODE
#define EVENTS8_INTERRUPT_MODE           RISING  // RISING, FALLING, CHANGE
#endif

#ifndef EVENTS8_DEBOUNCE
#define EVENTS8_DEBOUNCE                 50      // Do not register events within less than 50 millis
#endif

//------------------------------------------------------------------------------
// Geiger sensor
// Enable support by passing GEIGER_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef GEIGER_SUPPORT
#define GEIGER_SUPPORT                  0       // Do not build with geiger support by default
#endif

#ifndef GEIGER_PIN
#define GEIGER_PIN                      5       // D1
#endif

#ifndef GEIGER_PIN_MODE
#define GEIGER_PIN_MODE                 INPUT   // INPUT, INPUT_PULLUP
#endif

#ifndef GEIGER_INTERRUPT_MODE
#define GEIGER_INTERRUPT_MODE           RISING  // RISING, FALLING, CHANGE
#endif

#ifndef GEIGER_DEBOUNCE
#define GEIGER_DEBOUNCE                 25      // (milliseconds) Do not register events within less than 25 millis.
#endif
                                                // See https://github.com/Trickx/espurna/wiki/Geiger-counter

#ifndef GEIGER_CPM2SIEVERT
#define GEIGER_CPM2SIEVERT              240     // CPM to µSievert per hour conversion factor
#endif
                                                // Typically the literature uses the invers, but I find an integer type more convienient.

#ifndef GEIGER_REPORT_SIEVERTS
#define GEIGER_REPORT_SIEVERTS          1       // Enabler for local dose rate reports in µSv/h
#endif

#ifndef GEIGER_REPORT_CPM
#define GEIGER_REPORT_CPM               1       // Enabler for local dose rate reports in counts per minute
#endif

//------------------------------------------------------------------------------
// GUVAS12SD UV Sensor (analog)
// Enable support by passing GUVAS12SD_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef GUVAS12SD_SUPPORT
#define GUVAS12SD_SUPPORT               0
#endif

#ifndef GUVAS12SD_PIN
#define GUVAS12SD_PIN                   14
#endif

//------------------------------------------------------------------------------
// HLW8012 Energy monitor IC
// Enable support by passing HLW8012_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef HLW8012_SUPPORT
#define HLW8012_SUPPORT                 0
#endif

#ifndef HLW8012_SEL_PIN
#define HLW8012_SEL_PIN                 5
#endif

#ifndef HLW8012_CF1_PIN
#define HLW8012_CF1_PIN                 13
#endif

#ifndef HLW8012_CF_PIN
#define HLW8012_CF_PIN                  14
#endif

#ifndef HLW8012_SEL_CURRENT
#define HLW8012_SEL_CURRENT             HIGH    // SEL pin to HIGH to measure current
#endif

#ifndef HLW8012_CURRENT_R
#define HLW8012_CURRENT_R               0.001   // Current resistor
#endif

#ifndef HLW8012_VOLTAGE_R_UP
#define HLW8012_VOLTAGE_R_UP            ( 5 * 470000 )  // Upstream voltage resistor
#endif

#ifndef HLW8012_VOLTAGE_R_DOWN
#define HLW8012_VOLTAGE_R_DOWN          ( 1000 )        // Downstream voltage resistor
#endif

#ifndef HLW8012_CURRENT_RATIO
#define HLW8012_CURRENT_RATIO           HLW8012_DEFAULT_CURRENT_RATIO   // Value multiplier, internally used to scale RAW current
#endif

#ifndef HLW8012_VOLTAGE_RATIO
#define HLW8012_VOLTAGE_RATIO           HLW8012_DEFAULT_VOLTAGE_RATIO   // Value multiplier, internally used to scale RAW voltage
#endif

#ifndef HLW8012_POWER_RATIO
#define HLW8012_POWER_RATIO             HLW8012_DEFAULT_POWER_RATIO     // Value multiplier, internally used to scale RAW active power
#endif

#ifndef HLW8012_USE_INTERRUPTS
#define HLW8012_USE_INTERRUPTS          1       // Use interrupts to trap HLW8012 signals
#endif

#ifndef HLW8012_WAIT_FOR_WIFI
#define HLW8012_WAIT_FOR_WIFI           0       // Weather to enable interrupts only after
                                                // wifi connection has been stablished
#endif

#ifndef HLW8012_INTERRUPT_ON
#define HLW8012_INTERRUPT_ON            CHANGE  // When to trigger the interrupt
                                                // Use CHANGE for HLW8012
                                                // Use FALLING for BL0937 / HJL0
#endif

//------------------------------------------------------------------------------
// LDR sensor
// Enable support by passing LDR_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef LDR_SUPPORT
#define LDR_SUPPORT                     0
#endif

#ifndef LDR_SAMPLES
#define LDR_SAMPLES                     10      // Number of samples
#endif

#ifndef LDR_DELAY
#define LDR_DELAY                       0       // Delay between samples in micros
#endif

#ifndef LDR_TYPE
#define LDR_TYPE                        LDR_GL5528
#endif

#ifndef LDR_ON_GROUND
#define LDR_ON_GROUND                   true
#endif

#ifndef LDR_RESISTOR
#define LDR_RESISTOR                    10000   // Resistance
#endif

#ifndef LDR_MULTIPLICATION
#define LDR_MULTIPLICATION              32017200
#endif

#ifndef LDR_POWER
#define LDR_POWER                       1.5832
#endif

//------------------------------------------------------------------------------
// MHZ19 CO2 sensor
// Enable support by passing MHZ19_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef MHZ19_SUPPORT
#define MHZ19_SUPPORT                   0
#endif

#ifndef MHZ19_PORT
#define MHZ19_PORT                      1     // By default, use the first port
                                              // (needs `UART[1-3]_BAUDRATE 9600`)
#endif

#ifndef MHZ19_CALIBRATE_AUTO
#define MHZ19_CALIBRATE_AUTO            0
#endif

#ifndef MHZ19_DETECTION_RANGE
#define MHZ19_DETECTION_RANGE           2000
#endif

//------------------------------------------------------------------------------
// MICS-2710 (and MICS-4514) NO2 sensor
// Enable support by passing MICS2710_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef MICS2710_SUPPORT
#define MICS2710_SUPPORT                0
#endif

#ifndef MICS2710_NOX_PIN
#define MICS2710_NOX_PIN                0
#endif

#ifndef MICS2710_PRE_PIN
#define MICS2710_PRE_PIN                4
#endif

#define MICS2710_PREHEAT_TIME           10000   // 10s preheat for NOX read
#define MICS2710_RL                     820     // RL, load resistor
#define MICS2710_R0                     2200    // R0 calibration value for NO2 sensor,
                                                // Typical value as per datasheet

//------------------------------------------------------------------------------
// MICS-5525 (and MICS-4514) CO sensor
// Enable support by passing MICS5525_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef MICS5525_SUPPORT
#define MICS5525_SUPPORT                0
#endif

#ifndef MICS5525_RED_PIN
#define MICS5525_RED_PIN                0
#endif

#define MICS5525_RL                     820     // RL, load resistor
#define MICS5525_R0                     750000  // R0 calibration value for NO2 sensor,
                                                // Typical value as per datasheet

//------------------------------------------------------------------------------
// NTC sensor
// Enable support by passing NTC_SUPPORT=1 build flag
//--------------------------------------------------------------------------------

#ifndef NTC_SUPPORT
#define NTC_SUPPORT                     0
#endif

#ifndef NTC_SAMPLES
#define NTC_SAMPLES                     10      // Number of samples
#endif

#ifndef NTC_DELAY
#define NTC_DELAY                       0       // Delay between samples in micros
#endif

#ifndef NTC_INPUT_VOLTAGE
#define NTC_INPUT_VOLTAGE               3.3     // Actual voltage that is connected to the ADC
#endif

#ifndef NTC_R_DOWN
#define NTC_R_DOWN                      10000   // (Ohm) Resistor DOWN, NTC is connected to the voltage
                                                // [V]─NTC─┬─R_DOWN─[GND]
                                                //       [ADC]
#endif

#ifndef NTC_R_UP
#define NTC_R_UP                        0       // (Ohm) Resistor UP, NTC is connected to the ground
                                                // [V]─R_UP─┬─NTC─[GND]
                                                //        [ADC]
#endif

#ifndef NTC_T0
#define NTC_T0                          298.15  // 25 Celsius
#endif

#ifndef NTC_R0
#define NTC_R0                          10000   // Resistance at T0
#endif

#ifndef NTC_BETA
#define NTC_BETA                        3977    // Beta coeficient
#endif

//------------------------------------------------------------------------------
// PM1006 sensor
// Enable support by passing PM1006_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef PM1006_SUPPORT
#define PM1006_SUPPORT                    0
#endif

#ifndef PM1006_PORT
#define PM1006_PORT                       1    // By default, use the first port
                                               // (needs `UART[1-3]_BAUDRATE 9600`)
#endif

//------------------------------------------------------------------------------
// Particle Monitor based on Plantower PMS
// Enable support by passing PMSX003_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef PMSX003_SUPPORT
#define PMSX003_SUPPORT                 0
#endif

#ifndef PMS_PORT
#define PMS_PORT                        1     // By default, use the first port
                                              // (needs `UART[1-3]_BAUDRATE 9600`)
#endif

#ifndef PMS_TYPE
#define PMS_TYPE                        PMS_TYPE_X003
#endif

// You can enable smart sleep (read 6-times then sleep on 24-reading-cycles) to extend PMS sensor's life.
// Otherwise the default lifetime of PMS sensor is about 8000-hours/1-years.
// The PMS's fan will stop working on sleeping cycle, and will wake up on reading cycle.
#ifndef PMS_SMART_SLEEP
#define PMS_SMART_SLEEP                 0
#endif

//------------------------------------------------------------------------------
// Pulse Meter Energy monitor
// Enable support by passing PULSEMETER_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef PULSEMETER_SUPPORT
#define PULSEMETER_SUPPORT              0
#endif
#ifndef PULSEMETER_PIN
#define PULSEMETER_PIN                  5
#endif

#ifndef PULSEMETER_ENERGY_RATIO
#define PULSEMETER_ENERGY_RATIO         4000        // In pulses/kWh
#endif

#ifndef PULSEMETER_INTERRUPT_ON
#define PULSEMETER_INTERRUPT_ON         FALLING
#endif

#ifndef PULSEMETER_DEBOUNCE
#define PULSEMETER_DEBOUNCE             50         // Do not register pulses within less than 50 millis
#endif

//------------------------------------------------------------------------------
// PZEM004T based power monitor
// Enable support by passing PZEM004T_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef PZEM004T_SUPPORT
#define PZEM004T_SUPPORT                0
#endif

#ifndef PZEM004T_PORT
#define PZEM004T_PORT                   1       // By default, use the first port
                                                // (needs `UART[1-3]_BAUDRATE 9600`)
#endif

#ifndef PZEM004T_READ_INTERVAL
#define PZEM004T_READ_INTERVAL          1000    // (ms) Minimum interval between device readings. When there are more than one device, interval will be shared
                                                // between devices and each reading will happen after 'interval value' multiplied by the number of devices
#endif

#ifndef PZEM004T_DEVICES_MAX
#define PZEM004T_DEVICES_MAX            4       // Maximum number of active devices
#endif

#ifndef PZEM004T_ADDRESS_1
#define PZEM004T_ADDRESS_1            "192.168.1.1" // Device address, represented as an IPv4 string
                                                    // Only the first address is enabled by default. To have more devices, fill in other addresses here, in the custom.h or through settings (pzemAddr#)
#endif

#ifndef PZEM004T_ADDRESS_2
#define PZEM004T_ADDRESS_2            ""            // Only one device enabled by default
#endif

#ifndef PZEM004T_ADDRESS_3
#define PZEM004T_ADDRESS_3            ""            // Only one device enabled by default
#endif

#ifndef PZEM004T_ADDRESS_4
#define PZEM004T_ADDRESS_4            ""            // Only one device enabled by default
#endif

//------------------------------------------------------------------------------
// PZEM004T **V3.0** based power monitor
// Enable support by passing PZEM004TV30_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef PZEM004TV30_SUPPORT
#define PZEM004TV30_SUPPORT                0
#endif

#ifndef PZEM004TV30_ADDRESS
#define PZEM004TV30_ADDRESS                0xF8    // Default: factory value
#endif

#ifndef PZEM004TV30_PORT
#define PZEM004TV30_PORT                   1      // By default, use the first port
                                                  // (needs `UART[1-3]_BAUDRATE 9600`)
#endif

#ifndef PZEM004TV30_DEBUG
#define PZEM004TV30_DEBUG                  0
#endif

//------------------------------------------------------------------------------
// SDS011 particulates sensor
// Enable support by passing SDS011_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef SDS011_SUPPORT
#define SDS011_SUPPORT                   0
#endif

#ifndef SDS011_PORT
#define SDS011_PORT                      1   // By default, use the first port
                                             // (needs `UART[1-3]_BAUDRATE 9600`)
#endif

//------------------------------------------------------------------------------
// SenseAir CO2 sensor
// Enable support by passing SENSEAIR_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef SENSEAIR_SUPPORT
#define SENSEAIR_SUPPORT                0
#endif

#ifndef SENSEAIR_PORT
#define SENSEAIR_PORT                   1    // By default, use the first port
                                             // (needs `UART[1-3]_BAUDRATE 9600`)
#endif

//------------------------------------------------------------------------------
// SHT3X I2C (Wemos) temperature & humidity sensor
// Enable support by passing SHT3X_I2C_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef SHT3X_I2C_SUPPORT
#define SHT3X_I2C_SUPPORT               0
#endif

#ifndef SHT3X_I2C_ADDRESS
#define SHT3X_I2C_ADDRESS               0x00    // 0x00 means auto
#endif

//------------------------------------------------------------------------------
// SI7021 temperature & humidity sensor
// Enable support by passing SI7021_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef SI7021_SUPPORT
#define SI7021_SUPPORT                  0
#endif

#ifndef SI7021_ADDRESS
#define SI7021_ADDRESS                  0x00    // 0x00 means auto
#endif

//------------------------------------------------------------------------------
// SM300D2 sensor
// Enable support by passing SM300D2_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef SM300D2_SUPPORT
#define SM300D2_SUPPORT                   0
#endif

#ifndef SM300D2_PORT
#define SM300D2_PORT                      1     // By default, use the first port
                                                // (needs `UART[1-3]_BAUDRATE 9600`)
#endif

//------------------------------------------------------------------------------
// HDC1080 / 831R temperature & humidity sensor
// Enable support by passing HDC1080_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef HDC1080_SUPPORT
#define HDC1080_SUPPORT                  0
#endif

#ifndef HDC1080_ADDRESS
#define HDC1080_ADDRESS                  0x00    // 0x00 means auto
#endif

//------------------------------------------------------------------------------
// Sonar
// Enable support by passing SONAR_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef SONAR_SUPPORT
#define SONAR_SUPPORT                  0
#endif

#ifndef SONAR_TRIGGER
#define SONAR_TRIGGER                  12                            // GPIO for the trigger pin (output)
#endif

#ifndef SONAR_ECHO
#define SONAR_ECHO                     14                            // GPIO for the echo pin (input)
#endif

#ifndef SONAR_MAX_DISTANCE
#define SONAR_MAX_DISTANCE             MAX_SENSOR_DISTANCE           // Max sensor distance in cm
#endif

#ifndef SONAR_ITERATIONS
#define SONAR_ITERATIONS               5                             // Number of iterations to ping for
#endif                                                               // error correction.

//------------------------------------------------------------------------------
// T6613 CO2 sensor
// Enable support by passing T6613_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef T6613_SUPPORT
#define T6613_SUPPORT                   0
#endif

#ifndef T6613_PORT
#define T6613_PORT                      1    // By default, use the first port
                                             // (needs `UART[1-3]_BAUDRATE 9600`)
#endif

//------------------------------------------------------------------------------
// TMP3X analog temperature sensor
// Enable support by passing TMP3X_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef TMP3X_SUPPORT
#define TMP3X_SUPPORT                   0
#endif

#ifndef TMP3X_TYPE
#define TMP3X_TYPE                      TMP3X_TMP35
#endif

//------------------------------------------------------------------------------
// V9261F based power sensor
// Enable support by passing SI7021_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef V9261F_SUPPORT
#define V9261F_SUPPORT                  0
#endif

#ifndef V9261F_PORT
#define V9261F_PORT                     1       // By default, use the first port
                                                // (needs `UART[1-3]_BAUDRATE 4800` and `UART[1-3]_INVERT 1`)
#endif

#ifndef V9261F_SYNC_INTERVAL
#define V9261F_SYNC_INTERVAL            600     // Sync signal length (ms)
#endif

#ifndef V9261F_POWER_ACTIVE_FACTOR
#define V9261F_POWER_ACTIVE_FACTOR      153699.0
#endif

#ifndef V9261F_VOLTAGE_FACTOR
#define V9261F_VOLTAGE_FACTOR           4160651.0
#endif

#ifndef V9261F_CURRENT_FACTOR
#define V9261F_CURRENT_FACTOR           79371434.0
#endif

//------------------------------------------------------------------------------
// VEML6075 based power sensor
// Enable support by passing VEML6075_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef VEML6075_SUPPORT
#define VEML6075_SUPPORT                  0
#endif

#ifndef VEML6075_INTEGRATION_TIME
#define VEML6075_INTEGRATION_TIME         VEML6075::IT_100MS        // The time, in milliseconds, allocated for a single
#endif                                                              // measurement. A longer timing budget allows for more
                                                                    // accurate results at the cost of power.

#ifndef VEML6075_DYNAMIC_MODE
#define VEML6075_DYNAMIC_MODE             VEML6075::DYNAMIC_NORMAL  // The dynamic mode can either be normal or high. In high
#endif                                                              // dynamic mode, the resolution increases by about two
                                                                    // times.
//------------------------------------------------------------------------------
// VL53L1X
// Enable support by passing VL53L1X_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef VL53L1X_SUPPORT
#define VL53L1X_SUPPORT                              0
#endif

#ifndef VL53L1X_I2C_ADDRESS
#define VL53L1X_I2C_ADDRESS                          0x00          // 0x00 means auto
#endif

#ifndef VL53L1X_DISTANCE_MODE
#define VL53L1X_DISTANCE_MODE                        VL53L1X::Long // The distance mode of the sensor. Can be one of
#endif                                                             // `VL53L1X::Short`, `VL53L1X::Medium`, or `VL53L1X::Long.
                                                                   // Shorter distance modes are less affected by ambient light
                                                                   // but have lower maximum ranges, especially in the dark.


#ifndef VL53L1X_MEASUREMENT_TIMING_BUDGET
#define VL53L1X_MEASUREMENT_TIMING_BUDGET            140000        // The time, in microseconds, allocated for a single
                                                                   // measurement. A longer timing budget allows for more
                                                                   // accurate at the cost of power. The minimum budget is
                                                                   // 20 ms (20000 us) in short distance mode and 33 ms for
                                                                   // medium and long distance modes.
#endif

#ifndef VL53L1X_INTER_MEASUREMENT_PERIOD
#define VL53L1X_INTER_MEASUREMENT_PERIOD             50            // Period, in milliseconds, determining how
#endif                                                             // often the sensor takes a measurement.

//------------------------------------------------------------------------------
// MAX6675
// Enable support by passing MAX6675_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef MAX6675_SUPPORT
#define MAX6675_SUPPORT                              0
#endif

#ifndef MAX6675_CS_PIN
#define MAX6675_CS_PIN                               13
#endif

#ifndef MAX6675_SO_PIN
#define MAX6675_SO_PIN                               12
#endif

#ifndef MAX6675_SCK_PIN
#define MAX6675_SCK_PIN                              14
#endif

//------------------------------------------------------------------------------
// EZOPH pH meter
// Enable support by passing EZOPH_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef EZOPH_SUPPORT
#define EZOPH_SUPPORT                0
#endif

#ifndef EZOPH_PORT
#define EZOPH_PORT                   1       // By default, use the first port
                                             // (needs `UART[1-3]_BAUDRATE 9600`)
#endif

#ifndef EZOPH_SYNC_INTERVAL
#define EZOPH_SYNC_INTERVAL          1000    // Amount of time (in ms) sync new readings.
#endif

// -----------------------------------------------------------------------------
// ADE7953 Shelly Sensor
// Enable support by passing ADE7953_SUPPORT=1 build flag
// -----------------------------------------------------------------------------

#ifndef ADE7953_SUPPORT
#define ADE7953_SUPPORT                  0
#endif

#ifndef ADE7953_ADDRESS
#define ADE7953_ADDRESS                  0x38
#endif

#ifndef ADE7953_LINE_CYCLES
#define ADE7953_LINE_CYCLES              50.0f
#endif

#ifndef ADE7953_CURRENT_THRESHOLD
#define ADE7953_CURRENT_THRESHOLD        2000
#endif

// -----------------------------------------------------------------------------
// SI1145 UV Sensor over I2C
// Enable support by passing SI1145_SUPPORT=1 build flag
// -----------------------------------------------------------------------------

#ifndef SI1145_SUPPORT
#define SI1145_SUPPORT                   0
#endif

#ifndef SI1145_ADDRESS
#define SI1145_ADDRESS                   0x60
#endif

//------------------------------------------------------------------------------
// BME680
// Enable support by passing BME680_SUPPORT=1 build flag
//------------------------------------------------------------------------------

#ifndef BME680_SUPPORT
#define BME680_SUPPORT                              0
#endif

#ifndef BME680_I2C_ADDRESS
#define BME680_I2C_ADDRESS                          0x00                                   // 0x00 means auto
#endif

#ifndef BME680_BSEC_CONFIG
#define BME680_BSEC_CONFIG                          BME680_BSEC_CONFIG_GENERIC_33V_3S_4D   // BSEC config config value. By default, 3.3V as supply voltage,
#endif                                                                                     // 3 seconds as maximum time between bsec_sensor_control` calls
                                                                                           // and 4 days as the time considered for background calibration.

#ifndef BME680_STATE_SAVE_INTERVAL
#define BME680_STATE_SAVE_INTERVAL                  0                                      // How frequently (in milliseconds) should state be stored in
#endif                                                                                     // non-volatile memory. A common value would be every 6h or
                                                                                           // 360 * 60 * 1000 milliseconds. By default, this is disabled.

// -----------------------------------------------------------------------------
// INA219
// Enable support by passing INA219_SUPPORT=1 build flag
// -----------------------------------------------------------------------------

#ifndef INA219_SUPPORT
#define INA219_SUPPORT                              0
#endif

#ifndef INA219_ADDRESS
#define INA219_ADDRESS                              0x00 // 0x00 means auto
#endif

#ifndef INA219_OPERATING_MODE
#define INA219_OPERATING_MODE                       SHUNT_AND_BUS_CONTINUOUS
#endif

#ifndef INA219_SHUNT_MODE
#define INA219_SHUNT_MODE                           BIT_MODE_12
#endif

#ifndef INA219_SHUNT_RESISTANCE
#define INA219_SHUNT_RESISTANCE                     0.1 // Ohms
#endif

#ifndef INA219_BUS_MODE
#define INA219_BUS_MODE                             BIT_MODE_12
#endif

#ifndef INA219_BUS_RANGE
#define INA219_BUS_RANGE                            BRNG_32
#endif

#ifndef INA219_GAIN
#define INA219_GAIN                                 PG_320
#endif

#ifndef INA219_MAX_EXPECTED_CURRENT
#define INA219_MAX_EXPECTED_CURRENT                 2.0 // A
#endif

// -----------------------------------------------------------------------------
// ADC
// -----------------------------------------------------------------------------

// Default ADC mode is to monitor internal power supply
#ifndef ADC_MODE_VALUE
#define ADC_MODE_VALUE                  ADC_VCC
#endif

// -----------------------------------------------------------------------------
// I2C
// -----------------------------------------------------------------------------

#ifndef I2C_SUPPORT
#define I2C_SUPPORT                     0       // I2C enabled (1.98Kb)
#endif

#define I2C_USE_BRZO                    0       // Use brzo_i2c library or standard Wire

#ifndef I2C_SDA_PIN
#define I2C_SDA_PIN                     SDA     // SDA GPIO (Sonoff => 4, using Arduino Core variant definition as default)
#endif

#ifndef I2C_SCL_PIN
#define I2C_SCL_PIN                     SCL     // SCL GPIO (Sonoff => 14, using Arduino Core variant definition as default)
#endif

#ifndef I2C_CLOCK_STRETCH_TIME
#define I2C_CLOCK_STRETCH_TIME          200UL     // BRZO clock stretch time
#endif

#ifndef I2C_SCL_FREQUENCY
#define I2C_SCL_FREQUENCY               1000UL    // BRZO SCL frequency
#endif

#ifndef I2C_CLEAR_BUS
#define I2C_CLEAR_BUS                   0       // Clear I2C bus on boot
#endif

#ifndef I2C_PERFORM_SCAN
#define I2C_PERFORM_SCAN                1       // Perform a bus scan on boot
#endif

// =============================================================================
// Configuration helpers
// =============================================================================

// UART support for sensors using serial port
// (notice that baudrate and mode config is set *externally*)
#if (\
    CSE7766_SUPPORT || \
    MHZ19_SUPPORT || \
    PM1006_SUPPORT || \
    PMSX003_SUPPORT || \
    PZEM004T_SUPPORT || \
    SENSEAIR_SUPPORT || \
    SDS011_SUPPORT || \
    SM300D2_SUPPORT || \
    T6613_SUPPORT || \
    V9261F_SUPPORT || \
    EZOPH_SUPPORT || \
    PZEM004TV30_SUPPORT \
)
#undef UART_SUPPORT
#define UART_SUPPORT 1
#endif

// I2C support when sensor needs it
#if ( ADE7953_SUPPORT || \
    AM2320_SUPPORT || \
    BH1750_SUPPORT || \
    BME680_SUPPORT || \
    BMP180_SUPPORT || \
    BMX280_SUPPORT || \
    EMON_ADC121_SUPPORT || \
    EMON_ADS1X15_SUPPORT || \
    INA219_SUPPORT || \
    SHT3X_I2C_SUPPORT || \
    SI1145_SUPPORT || \
    SI7021_SUPPORT || \
    VEML6075_SUPPORT || \
    VL53L1X_SUPPORT || \
    HDC1080_SUPPORT \
)
#undef I2C_SUPPORT
#define I2C_SUPPORT                 1
#endif

// Can't have ADC reading something else
#if ( ANALOG_SUPPORT || \
    EMON_ANALOG_SUPPORT || \
    GUVAS12SD_SUPPORT || \
    LDR_SUPPORT || \
    MICS2710_SUPPORT || \
    MICS5525_SUPPORT || \
    NTC_SUPPORT || \
    TMP3X_SUPPORT \
)
#undef ADC_MODE_VALUE
#define ADC_MODE_VALUE ADC_TOUT
#endif

// Provide generic way to detect sensor presence
#ifndef SENSOR_SUPPORT
#define SENSOR_SUPPORT ( \
    ADE7953_SUPPORT || \
    AM2320_SUPPORT || \
    ANALOG_SUPPORT || \
    BH1750_SUPPORT || \
    BME680_SUPPORT || \
    BMP180_SUPPORT || \
    BMX280_SUPPORT || \
    CSE7766_SUPPORT || \
    DALLAS_SUPPORT || \
    DHT_SUPPORT || \
    DIGITAL_SUPPORT || \
    DUMMY_SENSOR_SUPPORT || \
    ECH1560_SUPPORT || \
    EMON_ADC121_SUPPORT || \
    EMON_ADS1X15_SUPPORT || \
    EMON_ANALOG_SUPPORT || \
    EVENTS_SUPPORT || \
    EZOPH_SUPPORT || \
    GEIGER_SUPPORT || \
    GUVAS12SD_SUPPORT || \
    HDC1080_SUPPORT || \
    HLW8012_SUPPORT || \
    INA219_SUPPORT || \
    LDR_SUPPORT || \
    MAX6675_SUPPORT || \
    MHZ19_SUPPORT || \
    MICS2710_SUPPORT || \
    MICS5525_SUPPORT || \
    NTC_SUPPORT || \
    PM1006_SUPPORT || \
    PMSX003_SUPPORT || \
    PULSEMETER_SUPPORT || \
    PZEM004TV30_SUPPORT || \
    PZEM004T_SUPPORT || \
    SDS011_SUPPORT || \
    SENSEAIR_SUPPORT || \
    SHT3X_I2C_SUPPORT || \
    SI1145_SUPPORT || \
    SI7021_SUPPORT || \
    SM300D2_SUPPORT || \
    SONAR_SUPPORT || \
    T6613_SUPPORT || \
    THERMOSTAT_SUPPORT || \
    TMP3X_SUPPORT || \
    V9261F_SUPPORT || \
    VEML6075_SUPPORT || \
    VL53L1X_SUPPORT \
)
#endif

