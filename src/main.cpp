#include <Arduino.h>
#include <fastLED.h>
#define MA_BROCHE_ANGLE 32
CRGB monPixel;


void setup() {
  FastLED.addLeds<WS2812,27,GRB>( &monPixel,1);
  Serial.begin(115200);
}

void loop() {
  int maLectureAngle = analogRead(MA_BROCHE_ANGLE);
  Serial.print(maLectureAngle);
  Serial.println();
  delay(100);

  if (maLectureAngle > 2047){
    monPixel = CRGB(0,222,255);
    FastLED.show();
  } else{
    monPixel = CRGB(0,0,0);
    FastLED.show();
  }
}
