#pragma once

#include <Arduino.h>

#define FASTLED_INTERNAL
#include <FastLED.h>

#include "effect.h"

class CylonEffect : public Effect
{
private:
    const int width = 3;
    const uint8_t fade = 64;
    boolean mirrored;

public:
    CylonEffect(int ledCount, boolean mirrored = false) : Effect(ledCount), mirrored(mirrored){};
    void draw();
};
