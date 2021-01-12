#include <Arduino.h>

#define FASTLED_INTERNAL
#include <FastLED.h>

#include "graphics.h"

CRGB colourFraction(CRGB colourIn, float fraction)
{
    fraction = min(1.0f, fraction);
    return CRGB(colourIn).fadeToBlackBy(255 * (1.0f - fraction));
}

void fadePixels(uint8_t amount)
{
    fadeToBlackBy(FastLED.leds(), FastLED.size(), amount);
}

void placePixel(int position, CRGB colour)
{
    FastLED.leds()[position] = colour;
}

void drawPixels(float position, float count, CRGB colour)
{
    float availFirstPixel = 1.0f - (position - (long)(position));
    float amtFirstPixel = min(availFirstPixel, count);
    float remaining = min(count, FastLED.size() - position);
    int pos = position;

    if (remaining > 0.0f)
    {
        FastLED.leds()[pos++] += colourFraction(colour, amtFirstPixel);
        remaining -= amtFirstPixel;
    }

    while (remaining > 1.0f)
    {
        FastLED.leds()[pos++] += colour;
        remaining--;
    }

    if (remaining > 0.0f)
    {
        FastLED.leds()[pos++] += colourFraction(colour, remaining);
    }
}

void clearPixels()
{
    FastLED.clear();
}

uint32_t esp_random_range(uint32_t out_min, uint32_t out_max)
{
    double rnd = (double)esp_random();
    double range = (double)(out_max - out_min);
    double divisor = (double)UINT32_MAX;

    return round((rnd * range) / divisor + out_min);
}
