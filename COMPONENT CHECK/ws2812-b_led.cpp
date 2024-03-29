#include <Adafruit_NeoPixel.h>

#define PIN            2
#define NUMPIXELS      2

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  // Turn on all LEDs in red color
  colorWipe(strip.Color(255, 0, 0), 50); // Red
  delay(1000);
  
  // Turn on all LEDs in green color
  colorWipe(strip.Color(0, 255, 0), 50); // Green
  delay(1000);
  
  // Turn on all LEDs in blue color
  colorWipe(strip.Color(0, 0, 255), 50); // Blue
  delay(1000);
}

void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
    strip.show();
    delay(wait);
  }
}
