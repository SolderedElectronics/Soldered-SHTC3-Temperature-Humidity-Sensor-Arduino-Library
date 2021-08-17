#include <Arduino.h>
#line 1 "/Users/nitkonitkic/Documents/Arduino/libraries/Soldered-SHTC3-Temperature-Humidity-Sensor-Arduino-Library/examples/TempAndHumidity/TempAndHumidity.ino"
/**
 **************************************************
 *
 * @file        TempAndHumidity.ino
 * @brief       Example file for using SHTC3 sensor with easyC/i2c
 *
 *
 *
 * @authors     @ soldered.com www.solde.red/333032
 ***************************************************/

#include "SHTC3-SOLDERED.h"

SHTC3 shtcSensor;

#line 16 "/Users/nitkonitkic/Documents/Arduino/libraries/Soldered-SHTC3-Temperature-Humidity-Sensor-Arduino-Library/examples/TempAndHumidity/TempAndHumidity.ino"
void setup();
#line 22 "/Users/nitkonitkic/Documents/Arduino/libraries/Soldered-SHTC3-Temperature-Humidity-Sensor-Arduino-Library/examples/TempAndHumidity/TempAndHumidity.ino"
void loop();
#line 16 "/Users/nitkonitkic/Documents/Arduino/libraries/Soldered-SHTC3-Temperature-Humidity-Sensor-Arduino-Library/examples/TempAndHumidity/TempAndHumidity.ino"
void setup()
{
    shtcSensor.begin();
    Serial.begin(9600);
}

void loop()
{
    shtcSensor.sample();

    // For temperature use function readTempC
    Serial.print("Temp: ");
    Serial.println(shtcSensor.readTempC(), 2);

    // For geting humodity use function readHumidity
    Serial.print("Hum: ");
    Serial.println(shtcSensor.readHumidity(), 2);

    delay(5000);
}

