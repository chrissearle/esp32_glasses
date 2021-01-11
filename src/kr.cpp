#include <Arduino.h>

#define FASTLED_INTERNAL
#include <FastLED.h>

#include "kr.h"
#include "graphics.h"

void KnightRiderEffect::draw()
{
    EVERY_N_MILLISECONDS(20)
    {
        fadePixels(fade);

        int limit = length - width;

        if (mirrored)
            limit = (length / 2) - width;

        int position = beatsin16(32, 0, limit);

        for (int i = position; i < position + width; i++)
        {
            placePixel(i, CRGB::Red);

            if (mirrored)
                placePixel(length - i - 1, CRGB::Red);
        }
    }
}
