#include <Adafruit_NeoPixel.h>

const int analogInPin = 0;
int sensorValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(0, INPUT_PULLUP);
  pinMode(13, OUTPUT);
}

void loop() {
  sensorValue = analogRead(analogInPin);
  Serial.print("sensor = " );                 
  Serial.println(sensorValue);      

  if (sensorValue < 500){
    Serial.println("leds triggered");
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }
  delay(100);      
}
