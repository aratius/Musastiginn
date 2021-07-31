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
/* After M5Core is started or reset
the program in the setUp () function will be run, and this part will only be run once.
在 M5Core 启动或者复位后，即会开始执行setup()函数中的程序，该部分只会执行一次。 */
void setup(){
  M5.begin();
  M5.Axp.ScreenBreath(10); // 画面の明るさ7〜１2
  M5.Lcd.setRotation(3); // 画面を横向きにする
  M5.Lcd.fillScreen(WHITE);
  M5.Lcd.setCursor(5, 10);
  M5.Lcd.setTextColor(BLACK);
  M5.Lcd.setTextSize(2);
  M5.Lcd.printf("Hello World!");

}

/* After the program in setup() runs, it runs the program in loop()
The loop() function is an infinite loop in which the program runs repeatedly
在setup()函数中的程序执行完后，会接着执行loop()函数中的程序
loop()函数是一个死循环，其中的程序会不断的重复运行 */
void loop() {

}