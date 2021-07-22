/**
 **************************************************
 *
 * @file        SHTC3.cpp
 * @brief       Library for SHTC3 sensor with easyC/i2c comunication
 *
 *
 *
 * @authors     @ soldered.com @Robert Peric
 ***************************************************/


#include "SHTC3-SOLDERED.h"


/**
 * @brief                   Sensor specific native constructor.
 *
 * @param int _pin          Example parameter.
 */
SHTC3::SHTC3(int _pin)
{
    pin = _pin;
    native = 1;
}

/**
 * @brief       Constructor for SHTC3 sensor
 */
SHTC3::SHTC3()
{
}

/**
 * @brief       readTemperature returns current enviroment temperature
 *
 * @return      float enviroment temperature
 */
float SHTC3::readTemperature()
{
    uint8_t data[6];
    wakeUp();
    sendCommand(TEMP_FIRST_NM_CS);
    readData(data, 6);
    powerDown();

    return ((float)(data[1] | (data[0] << 8))) / 1000;
}

/**
 * @brief       readHumidity returns current enviroment humidity
 *
 * @return      float enviroment humidity
 */
float SHTC3::readHumidity()
{
    uint8_t data[6];
    wakeUp();
    sendCommand(TEMP_FIRST_NM_CS);
    readData(data, 6);
    powerDown();

    return ((float)(data[4] | (data[3] << 8))) / 1000;
}

/**
 * @brief                   Overloaded function for virtual in base class to initialize sensor specific.
 */
void SHTC3::initializeNative()
{
    pinMode(pin, INPUT);
}

/**
 * @brief       wakeUp sends I2C command to start measurements
 */
void SHTC3::wakeUp()
{
    Wire.beginTransmission(SHTC3_ADDRESS);
    Wire.write(WAKEUP >> 8);
    Wire.write(WAKEUP);
    Wire.endTransmission();
    delayMicroseconds(240);
}

/**
 * @brief       sendMeasurementCommand is used after wakeUp to tell sensor to start measurement, consult datasheet for
 * different meassurement patterns
 *
 * @param       uint16_t measurement command from SHTC.c list of defines
 */
void SHTC3::sendCommand(uint16_t command)
{
    Wire.beginTransmission(SHTC3_ADDRESS);
    Wire.write(command >> 8);
    Wire.write(command);
    Wire.endTransmission();
}

/**
 * @brief       readData reads 6 bytes from sensor (temp and hum)
 *
 * @param       uint8_t data[] is used to store data from sensor
 */
void SHTC3::readData(uint8_t data[], int n)
{
    Wire.requestFrom(address, n);
    Wire.readBytes(data, n);
}

/**
 * @brief       powerDown puts sensor in sleep mode
 */
void SHTC3::powerDown()
{
    Wire.beginTransmission(SHTC3_ADDRESS);
    Wire.write(SLEEP >> 8);
    Wire.write(SLEEP);
    Wire.endTransmission();
}

/**
 * @brief       softwareReset resets sensor to its default state
 */
void SHTC3::softwareReset()
{
    wakeUp();
    sendCommand(RESET);
}

/**
 * @brief       readId requests device ID number
 *
 * @return      uint16_t device ID number
 */
uint16_t SHTC3::readId()
{
    uint8_t data[2];
    wakeUp();
    sendCommand(READOUT_ID);
    readData(data, 2);

    return ((uint16_t)(data[1] | data[0] << 8));
}