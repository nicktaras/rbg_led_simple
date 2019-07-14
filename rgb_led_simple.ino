// Author Nicholas Taras
// RGB LED SIMPLE MOOD LIGHT 

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

// initial values.
#define PIN            5
float amt = 0;
float colorValueR = 0;
float colorValueG = 0;
float colorValueB = 0;
float colorValueR2 = 0;
float colorValueG2 = 0;
float colorValueB2 = 0;
int randNumber = 1;
int randNumberR = 0;
int randNumberG = 0;
int randNumberB = 0;
int randNumberR2 = 0;
int randNumberG2 = 0;
int randNumberB2 = 0;
float ease = 0.0001;
int holdColourDelay = 3000;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(8, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  pixels.begin();
}

// Animate from one whole colour to another.
void moodLightRandomPaint () {
    if (amt >= 1){
      randNumberR = random(255); 
      randNumberG = random(255); 
      randNumberB = random(255);
      randNumberR2 = random(255); 
      randNumberG2 = random(255); 
      randNumberB2 = random(255); 
      amt = 0;
      delay(holdColourDelay);
    } else {
      amt += 0.01 / 100;
      colorValueR += (randNumberR - colorValueR) * ease;
      colorValueG += (randNumberG - colorValueG) * ease;
      colorValueB += (randNumberB - colorValueB) * ease;
      colorValueR2 += (randNumberR2 - colorValueR2) * ease;
      colorValueG2 += (randNumberG2 - colorValueG2) * ease;
      colorValueB2 += (randNumberB2 - colorValueB2) * ease;
      pixels.setPixelColor(1, colorValueR, colorValueG, colorValueB);
      pixels.setPixelColor(6, colorValueR2, colorValueG2, colorValueB2);
      pixels.show();
    }
}

void loop() {
  moodLightRandomPaint();
}

