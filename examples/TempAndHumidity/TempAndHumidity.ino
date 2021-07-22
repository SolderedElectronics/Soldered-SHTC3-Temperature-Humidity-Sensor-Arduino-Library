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
    Serial.begin(9600);
}

void loop()
{
    //For temperature use function readTemperature
    Serial.print("Temp: ");
    Serial.println(shtcSensor.readTemperature(), 2);

    //For geting humodity use function readHumidity
    Serial.print("Hum: ");
    Serial.println(shtcSensor.readHumidity(), 2);

    //If you are in need of knowing device ID use function readId 
    Serial.print("ID: ");
    Serial.println(shtcSensor.readId());

    delay(5000);
}
