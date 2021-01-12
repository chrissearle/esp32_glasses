#pragma once

#include <Arduino.h>

#define FASTLED_INTERNAL
#include <FastLED.h>

#define ARRAYSIZE(x) (sizeof(x) / sizeof(x[0]))

extern CRGB colourFraction(CRGB colourIn, float fraction);

extern void placePixel(int position, CRGB colour);
extern void drawPixels(float position, float count, CRGB colour);
extern void fadePixels(uint8_t amount);
extern void clearPixels();
extern uint32_t esp_random_range(uint32_t out_min = 0, uint32_t out_max = 255);
