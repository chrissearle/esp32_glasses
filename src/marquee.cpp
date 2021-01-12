#include <Arduino.h>

#define FASTLED_INTERNAL
#include <FastLED.h>

#include "marquee.h"
#include "graphics.h"

void MarqueeEffect::draw()
{
    EVERY_N_MILLISECONDS(20)
    {
        fadePixels(64);

        scroll += 0.1f;

        if (scroll > 5.0)
            scroll -= 5.0;

        CRGB colour = CHSV(hue += 4, 255, 255);

        for (float i = scroll; i < length / 2 - 1; i += 5)
        {
            drawPixels(i, 3, colour);
            drawPixels(length - 1 - i, 3, colour);
        }
    }
}
