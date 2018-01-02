#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define NUM_PIXELS 250
#define NUM_COLORS 7
#define NUM_COLORS_TO_SHOW 4
#define PIN 6
#define BRIGHTNESS_MIN 0
#define BRIGHTNESS_MAX 60

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIXELS, PIN, NEO_GRB + NEO_KHZ800);

float brightness = (BRIGHTNESS_MAX - BRIGHTNESS_MIN) / 2;
float increment = 0.5;
int loopCount = 0;
int cycle = 0;
int numColorsToShow = 4;

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code

  strip.begin();
  strip.setBrightness(brightness);
  strip.show(); // Initialize all pixels to 'off'  

  Serial.begin(9600);
}

void loop() {
  for(int i = 0 ; i < NUM_PIXELS ; i++){
    strip.setPixelColor(i, getColorForIndex(((i % numColorsToShow) + cycle) % NUM_COLORS));
  }

  brightness += increment;
  if(brightness < BRIGHTNESS_MIN){
    brightness = BRIGHTNESS_MIN;
    increment *= -1; 
    cycle++; 
    numColorsToShow = random(1, NUM_COLORS_TO_SHOW + 1);
  } else if(brightness > BRIGHTNESS_MAX){
    brightness = BRIGHTNESS_MAX;
    increment *= -1;
    delay(60000);
  }
  strip.setBrightness(brightness);
  strip.show();
  delay(5);

  loopCount++;
}

uint32_t getColorForIndex(int index){
  int red;
  int green;
  int blue;

  switch(index%NUM_COLORS){
    case 0:
      // Cyan
      red = 0;
      green = 255;
      blue = 255;
      break;
    case 1:  
      // Yellow
      red = 255;
      green = 255;
      blue = 0;
      break;
    case 2:
      // Blue
      red = 0;
      green = 0;
      blue = 255;
      break;
    case 3:
      // Red
      red = 255;
      green = 50;
      blue = 50;
      break;
    case 4:
      // Green
      red = 0;
      green = 255;
      blue = 0;
      break;
    case 5:
      // Purple
      red = 255;
      green = 0;
      blue = 246;
      break;
    case 6:
      // White
      red = 255;
      green = 255;
      blue = 255;
      break;
  }

  return strip.Color(green, red, blue, 0);
}
