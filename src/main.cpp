/// @file      main.cpp
/// @brief     Slingshot Robot LED Panel Controller
/// @copyright Copyright (c) 2025 FTC Team 20240 Slingshot. MIT License.

#include <FastLED.h>

#include "color.h"
#include "led_panel.h"

// Hardware configuration
/// @brief GPIO mapping for Control Hub digital IO ports
/// @warning Do not change these pin definitions unless you know what you are doing!
namespace hardware
{
  constexpr uint8_t kDigitalPin0 = 21; ///< Control Hub digital port 0.
  constexpr uint8_t kDigitalPin1 = 20; ///< Control Hub digital port 1.
  constexpr uint8_t kLedDataPin = 16;  ///< LED board DIN pin.
} // namespace hardware

// LED configuration
/// @brief Voltage limit (V)
/// @warning Do not change this value unless you know what you are doing!
constexpr double kMaxVoltage = 4.5;

/// @brief Current limit (mA)
/// @note Adjust based on your power supply capabilities.
constexpr int kMaxCurrent = 500;

/// @brief LED panel brightness setting (0-255)
/// @note Max brightness may never be reached due to power limits.
constexpr uint8_t kBrightness = 64;

/// @brief Total number of LEDs on the panel
constexpr uint8_t kLedCount = led_panel::kPanelWidth * led_panel::kPanelHeight;

// Global state
CRGB gLeds[kLedCount]; ///< LED array buffer.

void setup()
{
  pinMode(hardware::kDigitalPin0, INPUT);
  pinMode(hardware::kDigitalPin1, INPUT);

  FastLED.addLeds<WS2812B, hardware::kLedDataPin, GRB>(gLeds, kLedCount)
      .setCorrection(TypicalSMD5050);
  FastLED.setMaxPowerInVoltsAndMilliamps(kMaxVoltage, kMaxCurrent);
  FastLED.clear(true);
  FastLED.setBrightness(kBrightness);
}

void loop()
{
  const bool pin0On = digitalRead(hardware::kDigitalPin0) == HIGH;
  const bool pin1On = digitalRead(hardware::kDigitalPin1) == HIGH;

  led_panel::fillWhen(pin0On, led_panel::kTopHalf, color::kSlingshotPurple, gLeds);
  led_panel::fillWhen(pin1On, led_panel::kBottomHalf, CRGB::Green, gLeds);
  FastLED.show();
}