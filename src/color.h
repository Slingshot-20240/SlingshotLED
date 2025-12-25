/// @file      color.h
/// @brief     Predefined Colors
/// @copyright Copyright (c) 2025 FTC Team 20240 Slingshot. MIT License.

#pragma once

#include <FastLED.h>

/// @namespace color
/// @brief Provides predefined color constants for LED displays.
namespace color
{
  constexpr CRGB kOff = CRGB(0, 0, 0); ///< LED off (black).

  constexpr CRGB kArtifactPurple = CRGB(150, 12, 239); ///< DECODE artifact purple.
  constexpr CRGB kArtifactGreen = CRGB(19, 200, 47);   ///< DECODE artifact green.

  constexpr CRGB kSlingshotPurple = CRGB(99, 54, 162); ///< 20240 Slingshot purple.

} // namespace color