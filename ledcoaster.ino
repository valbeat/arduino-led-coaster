#include <Adafruit_NeoPixel.h>

const int analogInPin = 0;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(10, 6, NEO_GRB + NEO_KHZ800);
int sensorValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(0, INPUT_PULLUP);
  strip.begin();
  strip.show();
}

void loop() {
  sensorValue = analogRead(analogInPin);                
  Serial.println(sensorValue);

  if (sensorValue < 500){
    colorWipe(strip.Color(0,0,128), 60);
    colorWipe(strip.Color(0,0,0), 60);
  } else {
    colorWipe(strip.Color(128,128,0), 0);
    colorWipe(strip.Color(0,0,0), 0);
  }
  delay(10);
}

void colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}
