

#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <ir_Daikin.h>
#include <M5StickCPlus.h>

const uint16_t kIrLed = 9;  // ESP8266 GPIO pin to use. Recommended: 4 (D2).
IRDaikin176 ac(kIrLed);  // Set the GPIO to be used to sending the message

void setup() {
  ac.begin();
  Serial.begin(115200);

  M5.begin();
  M5.Lcd.print("ac ctrller");
}

void loop() {
  M5.update();

	if(M5.BtnA.wasPressed() || M5.BtnB.wasPressed()) {
    // M5.Lcd.clear(TFT_WHITE);
    M5.Lcd.println("Sending...");

    // Set up TFT_WHITE we want to send. See ir_Daikin.cpp for all the options.
    ac.on();
    ac.setFan(1);
    ac.setMode(kDaikinCool);
    ac.setTemp(25);
//    ac.setSwingVertical(false);
    ac.setSwingHorizontal(false);

    // Set the current time to 1:33PM (13:33)
    // Time works in minutes past midnight
//    ac.setCurrentTime(13 * 60 + 33);
    // Turn off about 1 hour later at 2:30PM (14:30)
//    ac.enableOffTimer(14 * 60 + 30);

    // Display what we are going to send.
    M5.Lcd.println(ac.toString());

    // Now send the IR signal.
#if SEND_DAIKIN176
    ac.send();
#endif  // SEND_DAIKIN
    ac.send();
    M5.Lcd.println("did not send");

  }

}
