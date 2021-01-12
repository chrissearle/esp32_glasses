#include <Arduino.h>

#define FASTLED_INTERNAL
#include <FastLED.h>

#include "twinkle.h"
#include "graphics.h"

static const CRGB colours[] = {
    CRGB::Red,
    CRGB::Blue,
    CRGB::Purple,
    CRGB::Green,
    CRGB::Orange};

void TwinkleEffect::draw()
{
    EVERY_N_MILLISECONDS(40)
    {
        passCount++;

        if (passCount >= length)
        {
            passCount = 0;

            clearPixels();
        }

        drawPixels(random(length), 1, colours[random(ARRAYSIZE(colours))]);
    }
}
