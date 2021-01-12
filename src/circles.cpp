#include <Arduino.h>

#define FASTLED_INTERNAL
#include <FastLED.h>

#include "circles.h"
#include "graphics.h"

void CirclesEffect::draw()
{
    EVERY_N_MILLISECONDS(20)
    {
        fadePixels(fade);

        int beat = beat8(64);

        int min = 0;
        int max = length / 2;

        if (reversed)
        {
            min = max;
            max = 0;
        }

        int position = map(beat, 0, 255, min, max);

        CRGB c = colour;

        if (randomColours)
        {
            c = CHSV(esp_random_range(), 255, 255);
        }

        drawPixels(position, 1, c);
        drawPixels(position + (length / 2), 1, c);
    }
}
