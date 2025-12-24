/// @file      color.h
/// @brief     Predefined Colors
/// @copyright Copyright (c) 2025 FTC Team 20240 Slingshot. MIT License.

#pragma once

#include <FastLED.h>

/// @namespace color
/// @brief Provides predefined color constants for LED displays.
namespace color
{
  constexpr CRGB kOff = CHSV(0, 0, 0); ///< LED off (black).

  constexpr CRGB kArtifactPurple =
      CHSV(276 / 360.0 * 255, 95 / 100.0 * 255, 94 / 100.0 * 255); ///< DECODE artifact purple.
  constexpr CRGB kArtifactGreen =
      CHSV(129 / 360.0 * 255, 91 / 100.0 * 255, 78 / 100.0 * 255); ///< DECODE artifact green.

  constexpr CRGB kSlingshotPurple =
      CHSV(255 / 360.0 * 255, 67 / 100.0 * 255, 64 / 100.0 * 255); ///< Team Slingshot purple.

} // namespace color