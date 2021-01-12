#pragma once

#include <Arduino.h>

#define FASTLED_INTERNAL
#include <FastLED.h>

#include "effect.h"
#include "graphics.h"

class CirclesEffect : public Effect
{
private:
    const uint8_t fade = 64;
    boolean reversed;
    boolean randomColours;
    CRGB colour;

public:
    CirclesEffect(int ledCount,
                  boolean reversed = true,
                  boolean randomColours = false,
                  CRGB colour = CHSV(esp_random_range(), 255, 255)) : Effect(ledCount),
                                                                      reversed(reversed),
                                                                      randomColours(randomColours),
                                                                      colour(colour){};
    void draw();
};
