

#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <ir_Daikin.h>
#include <M5StickCPlus.h>

const uint16_t kIrLed = 32;  // ESP8266 GPIO pin to use. Recommended: 4 (D2).
IRDaikin176 ac(kIrLed);  // Set the GPIO to be used to sending the message
bool isOn = false;

void setup() {
  ac.begin();
  Serial.begin(115200);
  isOn = ac.getPower();

  M5.begin();
  M5.Lcd.print("ac ctrller");
}

void loop() {
  M5.update();

	if(M5.BtnA.wasPressed()) {
    // M5.Lcd.clear(TFT_WHITE);
    M5.Lcd.println("Sending...");

    turn();

    // Now send the IR signal.
#if SEND_DAIKIN176
    ac.send();
#endif  // SEND_DAIKIN

  }

}

void turn() {
  if(isOn) {
    ac.off();
  } else {
    ac.on();
  }

  isOn = !isOn;

  ac.setFan(1);
  ac.setMode(kDaikinCool);
  ac.setTemp(25);
  ac.setSwingHorizontal(false);

  // Display what we are going to send.
  M5.Lcd.fillScreen(WHITE);
  M5.Lcd.println(isOn);
}