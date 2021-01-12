#pragma once

#include <Arduino.h>

#define FASTLED_INTERNAL
#include <FastLED.h>

#include "effect.h"

class TwinkleEffect : public Effect
{
private:
    unsigned int passCount = 0;

public:
    TwinkleEffect(int ledCount) : Effect(ledCount){};
    void draw();
};
