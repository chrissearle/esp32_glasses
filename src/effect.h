#pragma once

#include <Arduino.h>

#define FASTLED_INTERNAL
#include <FastLED.h>

class Effect
{
protected:
    CRGB *leds;
    unsigned int length;

public:
    Effect(int ledCount) : length(ledCount){};
    virtual ~Effect(){};
    virtual void draw() = 0;
};
