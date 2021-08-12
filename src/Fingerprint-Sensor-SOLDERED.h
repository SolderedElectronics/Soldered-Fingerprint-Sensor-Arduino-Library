/**
 **************************************************
 *
 * @file        Generic-easyC-SOLDERED.h
 * @brief       Header file for sensor specific code.
 *
 *
 * @copyright GNU General Public License v3.0
 * @authors     Zvonimir Haramustek for soldered.com
 ***************************************************/

#ifndef __FINGERPRINT_SENSOR_SOLDERED__
#define __FINGERPRINT_SENSOR_SOLDERED__

#include "Arduino.h"
#include "libs/Adafruit-Fingerprint-Sensor-Library/Adafruit_Fingerprint.h"

class FingerprintSensor : public Adafruit_Fingerprint
{
  public:
#if defined(__AVR__) || defined(ESP8266) || defined(FREEDOM_E300_HIFIVE1)
    FingerprintSensor(SoftwareSerial *ss, uint32_t password = 0x0) : Adafruit_Fingerprint(ss, password)
    {
    }
#endif
    FingerprintSensor(HardwareSerial *hs, uint32_t password = 0x0) : Adafruit_Fingerprint(hs, password)
    {
    }
    FingerprintSensor(Stream *serial, uint32_t password = 0x0) : Adafruit_Fingerprint(serial, password)
    {
    }

  protected:
  private:
};

#endif
