
// include the library
#include <RadioLib.h>

// CC1101 has the following connections:
// CS pin:    10
// GDO0 pin:  2
// RST pin:   unused
// GDO2 pin:  3 (optional)
CC1101 radio = new Module(5, 12, RADIOLIB_NC, 13);

byte byteArr[] ={ 0xff, 0xff,0xaa, 0xaa, 0x00, 0x00, 0xCC, 0xCC};
 //{0x00, 0xff,0x00, 0xff, 0xaa, 0x00, 0x00, 0xff };

// or using RadioShield
// https://github.com/jgromes/RadioShield
//CC1101 radio = RadioShield.ModuleA;

void setup() {
  Serial.begin(115200);
  pinMode(0,INPUT);
  // initialize CC1101 with default settings
  Serial.print(F("[CC1101] Initializing ... "));
  int state = radio.begin();
  if (state == RADIOLIB_ERR_NONE) {
    Serial.println(F("success!"));
  } else {
    Serial.print(F("failed, code "));
    Serial.println(state);
    while (true);
  }
  radio.setFrequency(433);
  // radio.setFrequencyDeviation
}

void loop() {
if (!digitalRead(0)){
  delay(300);
  Serial.print(F("[CC1101] Transmitting packet ... "));

  // you can transmit C-string or Arduino string up to 63 characters long
  // int state = radio.transmit("Hello World!");

  // you can also transmit byte array up to 63 bytes long
  
  int state = radio.transmit(byteArr, 8);
  

  // byte=
  if (state == RADIOLIB_ERR_NONE) {
    // the packet was successfully transmitted
    Serial.println(F("success!"));

  } else if (state == RADIOLIB_ERR_PACKET_TOO_LONG) {
    // the supplied packet was longer than 64 bytes
    Serial.println(F("too long!"));

  } else {
    // some other error occurred
    Serial.print(F("failed, code "));
    Serial.println(state);

  }
}
  // wait for a second before transmitting again
 // delay(1000);
}