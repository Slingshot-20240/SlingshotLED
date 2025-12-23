/// @file      main.cpp
/// @brief     Slingshot Robot LED Panel Controller
/// @copyright Copyright (c) 2025 FTC Team 20240 Slingshot. MIT License.

#include <FastLED.h>

#include "led_panel.h"
#include "color.h"

using led_panel::fillRectangularRegion;

/// @brief GPIO mapping for Control Hub digital IO port 0-1
/// @warning Do not change these pin definitions unless you know what you are doing!
constexpr int digitalPins[2] = {21, 20};

/// @brief Voltage limit (V)
/// @warning Do not change this value unless you know what you are doing!
constexpr double maxVoltage = 4.5;

/// @brief Current limit (mA)
/// @note Adjust based on your power supply capabilities.
constexpr int maxCurrent = 500;

/// @brief LED panel brightness setting (0-255)
/// @note Max brightness may never be reached due to power limits.
constexpr int brightness = 64;

/// @brief Colors for each half of the panel
/// @note To use custom predefined colors from color.h, reference color::COLOR_NAME
/// @note Alternatively, use built-in CRGB colors like CRGB::Red, CRGB::Blue, etc.
const CRGB halveColors[2] = {color::SLINGSHOT_PURPLE, CRGB::Green};

CRGB leds[64];

void setup()
{
  pinMode(digitalPins[0], INPUT);
  pinMode(digitalPins[1], INPUT);

  FastLED.addLeds<WS2812B, 16, GRB>(leds, 64).setCorrection(TypicalSMD5050);
  FastLED.setMaxPowerInVoltsAndMilliamps(maxVoltage, maxCurrent);
  FastLED.clear(true);
  FastLED.setBrightness(brightness);
}

void loop()
{
  if (digitalRead(digitalPins[0]) == HIGH)
  {
    fillRectangularRegion(led_panel::HALVE_ONE, halveColors[0], leds);
  }
  else
  {
    fillRectangularRegion(led_panel::HALVE_ONE, color::OFF, leds);
  }

  if (digitalRead(digitalPins[1]) == HIGH)
  {
    fillRectangularRegion(led_panel::HALVE_TWO, halveColors[1], leds);
  }
  else
  {
    fillRectangularRegion(led_panel::HALVE_TWO, color::OFF, leds);
  }

  FastLED.show();
}