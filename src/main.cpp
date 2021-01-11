#include <Arduino.h>

#define FASTLED_INTERNAL
#include <FastLED.h>

#include "effect.h"
#include "kr.h"

#define LED_PIN 5
#define NUM_LEDS 32

CRGB leds[NUM_LEDS] = {0};

uint32_t maxPower = 800;
uint8_t brightness = 255;

void setup()
{
  pinMode(LED_PIN, OUTPUT);

  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(brightness);
  FastLED.setMaxPowerInMilliWatts(maxPower);

  FastLED.clear();
}

void loop()
{
  Effect *effect = new KnightRiderEffect(NUM_LEDS, true);

  effect->draw();

  FastLED.show();
}
