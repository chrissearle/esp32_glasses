#pragma once

#include <Arduino.h>

#define FASTLED_INTERNAL
#include <FastLED.h>

#include "effect.h"

class RainbowEffect : public Effect
{
private:
    int initialHue;
    int hueDensity;
    int deltaHue;

public:
    RainbowEffect(int ledCount,
                  int initialHue = 0,
                  int hueDensity = 4,
                  int deltaHue = 16) : Effect(ledCount),
                                       initialHue(initialHue),
                                       hueDensity(hueDensity),
                                       deltaHue(deltaHue){};
    void draw();
};
