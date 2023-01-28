#include <vector>
#include <Arduino.h>
#include "config.h"

// PINS
// ADC pin used to measure battery voltage
const uint8_t PIN_BAT_ADC  = A2;
// Pins for Waveshare e-paper Driver Board
const uint8_t PIN_EPD_BUSY = 13;
const uint8_t PIN_EPD_CS   =  2;
const uint8_t PIN_EPD_RST  = 21;
const uint8_t PIN_EPD_DC   = 22;
const uint8_t PIN_EPD_SCK  = 18;
const uint8_t PIN_EPD_MISO = 19; // 19 Master-In Slave-Out not used, as no data from display
const uint8_t PIN_EPD_MOSI = 23;
// I2C Pins used for BME280
const uint8_t PIN_BME_SDA = 17;
const uint8_t PIN_BME_SCL = 16;
const uint8_t BME_ADDRESS = 0x76; // if sensor does not work, try 0x77

// WIFI CREDENTIALS
const char *WIFI_SSID     = "ssid";
const char *WIFI_PASSWORD = "password";

// OPENWEATHERMAP API
// OpenWeatherMap API key, https://openweathermap.org/
const String OWM_APIKEY   = "abcdefghijklmnopqrstuvwxyz012345";
const String OWM_ENDPOINT = "api.openweathermap.org";
// OpenWeatherMap One Call 2.5 API is deprecated for all new free users 
// (accounts created after Summer 2022).
//
// Please note, that One Call API 3.0 is included in the "One Call by Call" 
// subscription only. This separate subscription includes 1,000 calls/day for 
// free and allows you to pay only for the number of API calls made to this 
// product.
//
// Here’s how to subscribe and avoid any credit card changes:
// - Go to https://home.openweathermap.org/subscriptions/billing_info/onecall_30/base?key=base&service=onecall_30
// - Follow the instructions to complete the subscription.
// - Go to https://home.openweathermap.org/subscriptions and set the "Calls per
//   day (no more than)" to 1,000. This ensures you will never overrun the free 
//   calls.
const String OWM_ONECALL_VERSION = "3.0";

// LOCATION
// Set your latitude and longitude.
// (used to get weather data as part of API requests to OpenWeatherMap)
const String LAT = "40.7128";
const String LON = "-74.0060";
// City name that will be shown in the top-right corner of the display.
const String CITY_STRING = "\x80\x81\x82\x83\x84\x85\x86\x87\x88\x89\x8A\x8B\x8C\x8D\x8E\x8F\x90\x91\x92\x93\x94\x95\x96\xFF";

// TIME
// For list of time zones see 
// https://github.com/nayarsystems/posix_tz_db/blob/master/zones.csv
const char *TIMEZONE = "EST5EDT,M3.2.0,M11.1.0";
// Time format used when displaying sunrise/set times. (Max 11 characters)
// For more information about formatting see
// https://man7.org/linux/man-pages/man3/strftime.3.html
// const char *TIME_FORMAT = "%l:%M%P"; // 12-hour ex: 1:23am  11:00pm
const char *TIME_FORMAT = "%H:%M";   // 24-hour ex: 01:23   23:00
// Time format used when displaying axis labels. (Max 11 characters)
// For more information about formatting see
// https://man7.org/linux/man-pages/man3/strftime.3.html
// const char *HOUR_FORMAT = "%l%P"; // 12-hour ex: 1am  11pm
const char *HOUR_FORMAT = "%H";      // 24-hour ex: 01   23
// Date format used when displaying date in top-right corner. For more 
// For more information about formatting see
// https://man7.org/linux/man-pages/man3/strftime.3.html
const char *DATE_FORMAT = "%A, %B %e"; // Saturday, January 1
// Date/Time format used when displaying the last refresh time along the bottom
// of the screen
// For more information about formatting see
// https://man7.org/linux/man-pages/man3/strftime.3.html
const char *REFRESH_TIME_FORMAT = "%x %H:%M";
// ntp_server1 is the primary time server, while ntp_server2 is a fallback.
// In most cases it's best to use pool.ntp.org to find an NTP server
// The system will try finding the closest available servers for you.
const char *NTP_SERVER_1 = "us.pool.ntp.org";
const char *NTP_SERVER_2 = "time.nist.gov";
// Sleep duration in minutes. (aka how often esp32 will wake for an update)
// Aligned to the nearest minute boundary, so if 30 will always update at 00 or 
// 30 past the hour.
const long SLEEP_DURATION = 30;                 
const int WAKE_TIME =  6; // Don't wakeup until after 06:00 to save battery
const int BED_TIME  = 23; // Sleep after (23+1) 00:00 to save battery

// HOURLY OUTLOOK GRAPH
// Number of hours to display on the outlook graph.
// Value must be between 7-47 (inclusively).
const int HOURLY_GRAPH_MAX = 24;

// BATTERY
// To protect the battery upon low battery voltage, the display will cease to 
// update until battery is charged again. The ESP32 will hibernate (consuming 
// < 11μA), waking briefly check the voltage at the corresponding interval (in 
// minutes).
const float LOW_BATTERY_VOLTAGE      = 3.20;  // volts
const float CRIT_LOW_BATTERY_VOLTAGE = 3.10;  // volts
const unsigned long LOW_BATTERY_SLEEP_INTERVAL      = 10; // (minutes)
const unsigned long CRIT_LOW_BATTERY_SLEEP_INTERVAL = 60; // (minutes)

// LANGUAGE
// see config.h

// UNITS
// see config.h

// AIR QUALITY INDEX
// see config.h

// WIND
// see config.h
