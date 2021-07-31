#include <M5StickCPlus.h>
#include <WiFi.h>
const char* ssid     = "STARRYWORKS inc.";
const char* password = "9876598765987";
void setup() {
	Serial.begin(115200);
	M5.begin();
	M5.Lcd.setTextSize(2);
	WiFi.begin(ssid, password);
	M5.Lcd.println("Connecting WiFi...");
	while (WiFi.status() != WL_CONNECTED) {
		delay(100);
	}
	M5.Lcd.println("Connected!");
	M5.Lcd.println(WiFi.localIP());
}
void loop() {
	delay(1000);
}