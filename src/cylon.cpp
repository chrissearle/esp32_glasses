#include <Arduino.h>

#define FASTLED_INTERNAL
#include <FastLED.h>

#include "cylon.h"
#include "graphics.h"

void CylonEffect::draw()
{
    EVERY_N_MILLISECONDS(20)
    {
        fadePixels(fade);

        int limit = length - width;

        if (mirrored)
            limit = (length / 2) - width;

        int position = beatsin16(64, 0, limit);

        byte hue = beatsin8(96);
        CRGB colour = CHSV(hue, 255, 255);

        drawPixels(position, 3, colour);

        if (mirrored)
            drawPixels(length - width - position, 3, colour);
    }
}
