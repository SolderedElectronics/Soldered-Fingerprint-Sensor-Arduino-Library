/***************************************************
  This is an example sketch for our optical Fingerprint sensor
  Designed specifically to work with the Adafruit Fingerprint sensor
  ----> http://www.adafruit.com/products/751
  These displays use TTL Serial to communicate, 2 pins are required to
  interface
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!
  Written by Limor Fried/Ladyada for Adafruit Industries.
  BSD license, all text above must be included in any redistribution

  Modified by soldered.com for our fingerprint sensor, available here: https://solde.red/108668
 ****************************************************/

#include "Fingerprint-Sensor-SOLDERED.h"


#if (defined(__AVR__) || defined(ESP8266)) && !defined(__AVR_ATmega2560__)
// For UNO and others without hardware serial, we must use software serial...
// pin #2 is IN from sensor (GREEN wire)
// pin #3 is OUT from arduino  (WHITE wire)
// Set up the serial port to use softwareserial..
SoftwareSerial mySerial(2, 3);

#else
// On Leonardo/M0/etc, others with hardware serial, use hardware serial!
// #0 is green wire, #1 is white
#define mySerial Serial1

#endif

// Using sensor without password
FingerprintSensor finger = FingerprintSensor(&mySerial);

// Using sensor with password
// FingerprintSensor finger = FingerprintSensor(&mySerial, 1337);

void setup()
{
    while (!Serial)
        ; // For Yun/Leo/Micro/Zero/...

    Serial.begin(9600);
    Serial.println("Adafruit fingerprint sensor, change password example");

    // set the data rate for the sensor serial port
    finger.begin(19200);

    if (finger.verifyPassword())
    {
        Serial.println("Found fingerprint sensor!");
    }
    else
    {
        Serial.println("Did not find fingerprint sensor :(");
        while (1)
            ;
    }

    Serial.print("Set password... ");
    uint8_t p = finger.setPassword(1337);
    if (p == FINGERPRINT_OK)
    {
        Serial.println("OK"); // Password is set
    }
    else
    {
        Serial.println("ERROR"); // Failed to set password
    }
}

void loop()
{
}
