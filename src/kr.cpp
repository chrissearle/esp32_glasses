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

        int position = beatsin16(64, 0, limit);

        drawPixels(position, 3, CRGB::Red);

        if (mirrored)
            drawPixels(length - width - position, 3, CRGB::Red);
    }
}
