#include <M5StickCPlus.h>
#include <WiFi.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <WiFiMulti.h>

const char* ssid     = "STARRYWORKS inc.";
const char* password = "9876598765987";

// JSON (Arduino JSON) ----------
// jsonのサイズ
const int capacity = JSON_OBJECT_SIZE(1);
StaticJsonDocument<capacity> json_request;
// stringify
char buffer[255];

const char *host = "https://hooks.slack.com/services/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";

// slackにPOSTする
void SendMessage () {
	M5.Lcd.println("Send Message!");

	json_request["text"] = "ボタンが押されました。";
	serializeJson(json_request, buffer, sizeof(buffer));

	// HTTP通信 -----------------
	HTTPClient http;
	http.begin(host);
	http.addHeader("Content-type", "application/json");
	int status_code = http.POST((uint8_t*)buffer, strlen(buffer));
	Serial.printf("status_code=%d\r\n", status_code);

	if( status_code == 200 ){
    Stream* resp = http.getStreamPtr();

    DynamicJsonDocument json_response(255);
    deserializeJson(json_response, *resp);

    serializeJson(json_response, Serial);
    Serial.println("");
  }
  http.end();
}

void setup() {
	Serial.begin(115200);
	M5.begin();
	M5.Lcd.setTextSize(2);
	WiFi.begin(ssid, password);
	M5.Lcd.println("Connecting WiFi ...");
	while (WiFi.status() != WL_CONNECTED) {
		delay(100);
	}
	M5.Lcd.println("Connected !");
	M5.Lcd.println(WiFi.localIP());

}

void loop() {
	M5.update();
	if(M5.BtnA.wasPressed() || M5.BtnB.wasPressed()) {
		M5.Lcd.println("Button Pressed !");
		SendMessage();
  }
}

