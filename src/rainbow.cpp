#include <Arduino.h>

#define FASTLED_INTERNAL
#include <FastLED.h>

#include "rainbow.h"
#include "graphics.h"

void RainbowEffect::draw()
{
    EVERY_N_MILLISECONDS(10)
    {
        CHSV hsv(initialHue += hueDensity, 255, 255);

        for (int i = 0; i < length; ++i)
        {
            placePixel(i, hsv);
            hsv.hue += deltaHue;
        }
    }
}
