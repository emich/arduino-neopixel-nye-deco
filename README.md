# Neopixel Holiday String Lights Decoration

## Story
This was quickly written while realizing we were missing some decoration at home for a party we were hosting. I coded this an hour before all guests started arriving, so this isn't perfect code. 

This solution is super convenient as it just plugs into one of those million micro-USB chargers we all have at home.

## What this does
This code will make your neopixel lights cycle through a predefined set of colors. It will take color 0, 1, 2, etc., followed by its x following colors, where x is random. See it as a random window that starts at the current color. The animation will show the colors at a predefined max brightness, sleep for a certain amount of time (60s by default), fade to dark, change color, and repeat the cycle again. 

## Hardware used
Arduino

* [Arduino Nano](https://store.arduino.cc/usa/arduino-nano)

Light strip

* I used 3 of [these](https://www.amazon.com/ALITOVE-LED-Individually-Addressable-Waterproof/dp/B01AG923GI/ref=sr_1_3?ie=UTF8&qid=1514869985&sr=8-3&keywords=led+string+lights+addressable), or about a 150 lights, but anything [Neopixel](https://www.adafruit.com/category/168) will do.

## Stuff you can set easily
* NUM_PIXELS : The number of pixels you want to use. By default I setup 250, even if I only used about a 150.
* NUM_COLORS : The number of colors you want to predefine. For each of those, you need to define a color in getColorForIndex(int index)
* NUM_COLORS_TO_SHOW : The maximum number of colors you want to see at once on the strip (it will variate between 1 and this number). Should not exceed NUM_COLORS
* PIN : The Arduino board pin used for you Neopixel
* BRIGHTNESS_MIN : The minimum brightness. Best to keep it to 0 unless you want to see the color cycle happen live because that's what you're into.
* BRIGHTNESS_MAX : The maximum brightness (100 is the max, script is not enforcing that). The more lights you have, the lower I would keep this. Or find a way to beef up the power for your LED strip from another, more powerful, source.