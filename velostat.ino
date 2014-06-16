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
  Serial.print("sensor = " );                 
  Serial.println(sensorValue);

  if (sensorValue < 500){
    Serial.println("leds triggered");
    colorWipe(strip.Color(0,0,255), 60);
    colorWipe(strip.Color(0,0,0), 60);
  } else {
    colorWipe(strip.Color(255,255,0), 0);
    colorWipe(strip.Color(0,0,0), 0);
  }
}

void colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}
