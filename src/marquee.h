#pragma once

#include <Arduino.h>

#define FASTLED_INTERNAL
#include <FastLED.h>

#include "effect.h"

class MarqueeEffect : public Effect
{
private:
    float scroll = 0.0f;
    byte hue = HUE_BLUE;

public:
    MarqueeEffect(int ledCount) : Effect(ledCount){};
    void draw();
};
