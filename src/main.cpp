#include <Arduino.h>

#define FASTLED_INTERNAL
#include <FastLED.h>

#include <OneButton.h>

// Not running WiFi or I2S - need to enable hardware RNG
extern "C"
{
#include "bootloader_random.h"
}

#include "effect.h"
#include "graphics.h"
#include "kr.h"
#include "circles.h"
#include "rainbow.h"
#include "cylon.h"
#include "marquee.h"
#include "twinkle.h"

uint8_t effectCount = 11;

#define LED_PIN 5
#define NUM_LEDS 32

#define BUTTON_PIN 17

CRGB leds[NUM_LEDS] = {0};

uint32_t maxPower = 100;
uint8_t brightness = 255;

OneButton btn = OneButton(BUTTON_PIN, true, true);

boolean running = true;
boolean enabled = true;

Effect *currentEffect;
uint8_t lastEffect = 0;

void runEffect(uint8_t effect)
{
  lastEffect = effect;

  if (currentEffect != nullptr)
    delete currentEffect;

  switch (effect)
  {
  case 0:
    currentEffect = new KnightRiderEffect(NUM_LEDS);
    break;
  case 1:
    currentEffect = new KnightRiderEffect(NUM_LEDS, true);
    break;
  case 2:
    currentEffect = new CirclesEffect(NUM_LEDS);
    break;
  case 3:
    currentEffect = new CirclesEffect(NUM_LEDS, false);
    break;
  case 4:
    currentEffect = new CirclesEffect(NUM_LEDS, true, true);
    break;
  case 5:
    currentEffect = new CirclesEffect(NUM_LEDS, false, true);
    break;
  case 6:
    currentEffect = new RainbowEffect(NUM_LEDS);
    break;
  case 7:
    currentEffect = new CylonEffect(NUM_LEDS);
    break;
  case 8:
    currentEffect = new CylonEffect(NUM_LEDS, true);
    break;
  case 9:
    currentEffect = new MarqueeEffect(NUM_LEDS);
    break;
  default:
    currentEffect = new TwinkleEffect(NUM_LEDS);
    break;
  }
}

void btnNext()
{
  uint8_t effect = esp_random_range(0, effectCount - 1);

  // Prevent rerunning current effect
  while (effect == lastEffect)
    effect = esp_random_range(0, effectCount - 1);

  runEffect(effect);
}

void btnPause()
{
  running = !running;
}

void btnOff()
{
  enabled = !enabled;
  running = enabled;
}

void setup()
{
  Serial.begin(115200);
  bootloader_random_enable();
  pinMode(LED_PIN, OUTPUT);

  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(brightness);
  FastLED.setMaxPowerInMilliWatts(maxPower);

  FastLED.clear();

  btn.attachClick(btnNext);
  btn.attachDoubleClick(btnOff);
  btn.attachLongPressStop(btnPause);

  runEffect(0);
}

void loop()
{
  EVERY_N_SECONDS(20)
  {
    if (running)
      runEffect((lastEffect + 1) % effectCount);
  }

  btn.tick();
  if (enabled)
  {

    if (currentEffect != nullptr)
      currentEffect->draw();

    FastLED.show();
  }
  else
  {
    FastLED.clear();
    FastLED.show();
  }
}
