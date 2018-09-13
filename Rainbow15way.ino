/*
 *Desktop 60led desktop strip
 *System displays a series of "running" lights
 *
 *Austin Esser
 *April 7th 2015
*/

#include <Adafruit_NeoPixel.h>
#define PIN 13
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

const int dimfactor = 4; // Sets the brightness level (larger integers result in a greater dim factor)
const int wheelconst = 15; //sets the number of rainbow segments in the led strip

void setup() {
  strip.begin();
  strip.show();
}

void loop() {
  rainbowCycle(30); // Sets the speed of the cycle (smaller is faster)
}

//interface with Adafruit_NeoPixel library to quickly cycle colors within the neopixel led strip
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;
  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
    if(WheelPos < 17) {
     return strip.Color((WheelPos * wheelconst)/dimfactor, (255 - WheelPos * wheelconst)/dimfactor, 0);
    } else if(WheelPos < 34) {
     WheelPos -= 17;
     return strip.Color((255 - WheelPos * wheelconst)/dimfactor, 0, (WheelPos * wheelconst)/dimfactor);
    } else if(WheelPos < 51){
     WheelPos -= 34;
     return strip.Color(0, (WheelPos * wheelconst)/dimfactor, (255 - WheelPos * wheelconst)/dimfactor);
    } else if(WheelPos < 68) {
     WheelPos -= 51;
     return strip.Color((WheelPos * wheelconst)/dimfactor, (255 - WheelPos * wheelconst)/dimfactor, 0);
    } else if(WheelPos < 85) {
     WheelPos -= 68;
     return strip.Color((255 - WheelPos * wheelconst)/dimfactor, 0, (WheelPos * wheelconst)/dimfactor);
    }else if(WheelPos < 102) {
      WheelPos -= 85;
     return strip.Color(0, (WheelPos * wheelconst)/dimfactor, (255 - WheelPos * wheelconst)/dimfactor);
    } else if(WheelPos < 119) {
     WheelPos -= 102;
     return strip.Color((WheelPos * wheelconst)/dimfactor, (255 - WheelPos * wheelconst)/dimfactor, 0);
     } else if(WheelPos < 136){
     WheelPos -= 119;
     return strip.Color((255 - WheelPos * wheelconst)/dimfactor, 0, (WheelPos * wheelconst)/dimfactor);
    } else if(WheelPos < 153){
     WheelPos -= 136;
     return strip.Color(0, (WheelPos * wheelconst)/dimfactor, (255 - WheelPos * wheelconst)/dimfactor);  
    } else if(WheelPos < 170) {
     WheelPos -= 153;
     return strip.Color((WheelPos * wheelconst)/dimfactor, (255 - WheelPos * wheelconst)/dimfactor, 0);
    } else if(WheelPos < 187){
     WheelPos -= 170;
     return strip.Color((255 - WheelPos * wheelconst)/dimfactor, 0, (WheelPos * wheelconst)/dimfactor);
    }else if(WheelPos < 204) {
     WheelPos -= 187;
     return strip.Color(0, (WheelPos * wheelconst)/dimfactor, (255 - WheelPos * wheelconst)/dimfactor);
    } else if(WheelPos < 221) {
     WheelPos -= 204;
     return strip.Color((WheelPos * wheelconst)/dimfactor, (255 - WheelPos * wheelconst)/dimfactor, 0);
    } else if(WheelPos < 238){
     WheelPos -= 221;
      return strip.Color((255 - WheelPos * wheelconst)/dimfactor, 0, (WheelPos * wheelconst)/dimfactor);
    } else {
     WheelPos -= 238;
     return strip.Color(0, (WheelPos * wheelconst)/dimfactor, (255 - WheelPos * wheelconst)/dimfactor);
    } 
}

