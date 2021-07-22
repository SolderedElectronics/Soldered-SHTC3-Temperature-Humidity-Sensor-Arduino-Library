/**
 **************************************************
 *
 * @file        SHTC3.cpp
 * @brief       Library for SHTC3 sensor with eastC/i2c comunication 
 *
 *
 *
 * @authors     @ soldered.com @Robert Peric
 ***************************************************/

#ifndef _SHTC3_H
#define _SHTC3_H

#include "Arduino.h"
#include "libs/Generic-easyC/easyC.h"

#define SHTC3_ADDRESS 0x70
#define WAKEUP        0x3517
#define SLEEP         0xB098
#define RESET         0x805D
#define READOUT_ID    0xEFC8

#define TEMP_FIRST_NM_CS 0x7CA2
#define HUM_FIRST_NM_CS  0x5C24
#define TEMP_FIRST_LM_CS 0x6458
#define HUM_FIRST_LM_CS  0x44DE

#define TEMP_FIRST_NM 0x7866
#define HUM_FIRST_NM  0x58E0
#define TEMP_FIRST_LM 0x609C
#define HUM_FIRST_LM  0x401A


class SHTC3 : public EasyC
{
  public:
    SHTC3();
    SHTC3(int _pin);
    float readTemperature();
    float readHumidity();
    void softwareReset();
    uint16_t readId();

  protected:
    void initializeNative();

  private:
    int pin;
    void wakeUp();
    void sendCommand(uint16_t command);
    void readData(uint8_t data[], int n);
    void powerDown();
};

#endif
