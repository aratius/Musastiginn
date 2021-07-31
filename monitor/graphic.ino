/*
*******************************************************************************
* Copyright (c) 2021 by  M5Stack
*                 Equipped with M5Core sample source code
*                          配套  M5Core 示例源代码
* Visit the website for more information：https://docs.m5stack.com/en/core/gray
* 获取更多资料请访问：https://docs.m5stack.com/zh_CN/core/gray
*
* describe：Hello World
* date：2021/7/15
*******************************************************************************
*/

#include <M5StickCPlus.h>
// the setup routine runs once when M5StickC starts up
void setup() {

  // initialize the M5StickC object
  M5.begin();

  // Lcd display
  M5.Lcd.fillScreen(WHITE);
  delay(500);
  M5.Lcd.fillScreen(RED);
  delay(500);
  M5.Lcd.fillScreen(GREEN);
  delay(500);
  M5.Lcd.fillScreen(BLUE);
  delay(500);
  M5.Lcd.fillScreen(BLACK);
  delay(500);

  // text print
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 10);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(1);
  M5.Lcd.printf("Display Test!");

  // draw graphic
  delay(1000);
  M5.Lcd.drawRect(15, 55, 50, 50, BLUE);
  delay(1000);
  M5.Lcd.fillRect(15, 55, 50, 50, BLUE);
  delay(1000);
  M5.Lcd.drawCircle(40, 80, 30, RED);
  delay(1000);
  M5.Lcd.fillCircle(40, 80, 30, RED);
  delay(1000);
}

// the loop routine runs over and over again forever
void loop(){

  //rand draw
  M5.Lcd.fillTriangle(random(M5.Lcd.width()-1), random(M5.Lcd.height()-1), random(M5.Lcd.width()-1), random(M5.Lcd.height()-1), random(M5.Lcd.width()-1), random(M5.Lcd.height()-1), random(0xfffe));

  //M5.update();
}