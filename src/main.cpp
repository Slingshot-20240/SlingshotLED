/// @file      main.cpp
/// @brief     Slingshot Robot LED Panel Controller
/// @copyright Copyright (c) 2025 FTC Team 20240 Slingshot. MIT License.

#include <FastLED.h>
#include "quadrant.h"
#include "color.h"

// Brightness setting (0-255)
#define BRIGHTNESS 64

#define DIGITAL_0_PIN 27
#define DIGITAL_1_PIN 26

CRGB leds[64];

void setup()
{
  pinMode(DIGITAL_0_PIN, INPUT);
  pinMode(DIGITAL_1_PIN, INPUT);

  FastLED.addLeds<WS2812B, 16, GRB>(leds, 64).setCorrection(TypicalSMD5050);
  FastLED.setMaxPowerInVoltsAndMilliamps(4.5, 500);
  FastLED.clear(true);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop()
{
  /// TODO: Implement processing based on Digital IO output from Control Hub

  fillQuadrants(HALVE_ONE, COLOR_ARTIFACT_PURPLE, leds);
  fillQuadrants(HALVE_TWO, COLOR_ARTIFACT_GREEN, leds);

  FastLED.show();
}