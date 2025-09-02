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
  int lumiere = (maLectureAngle*255) /4095;
    monPixel = CRGB(0,lumiere,0);
    FastLED.show();
}
