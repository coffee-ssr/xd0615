#include <Adafruit_NeoPixel.h> // 这告诉Arduino我们想要使用NeoPixel及其在此草图中带来的所有属性，如果没有这个草图，草图将无法运行。

#define PIN 2	 // 告诉草图我们要在微控制器上使用2引脚

#define NUMPIXELS      12 // 告诉字符串特定字符串上有12个像素

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800); // 它可以帮助微控制器进行通信与NeoPixel

int delayval = 100; // 定时延迟1s

int redColor = 0;
int greenColor = 0;
int blueColor = 0;

void setup() {
  // Initialize the NeoPixel library.
  pixels.begin();// 草图初始化库
}

void loop() {
  setColor();

  for (int i=0; i < NUMPIXELS; i++) {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(redColor, greenColor, blueColor));//修改像素的颜色 i为哪个像素  pixels.Color后为颜色的值 分别为红色绿色蓝色

    // This sends the updated pixel color to the hardware.
    pixels.show();//将当前设置发送到像素

    // Delay for a period of time (in milliseconds).
    delay(delayval);//延迟一段时间
  }
}

// setColor()
// picks random values to set for RGB
void setColor(){
  redColor = random(0, 255);
  greenColor = random(0,255);
  blueColor = random(0, 255);
}