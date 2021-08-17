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

void setup()
{
    shtcSensor.begin();
    Serial.begin(115200);
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
