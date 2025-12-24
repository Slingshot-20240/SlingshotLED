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

  constexpr CRGB kArtifactPurple = CRGB(163, 12, 226); ///< DECODE artifact purple.
  constexpr CRGB kArtifactGreen = CRGB(85, 198, 92);   ///< DECODE artifact green.

  constexpr CRGB kSlingshotPurple = CRGB(164, 53, 163); ///< 20240 Slingshot purple.

} // namespace color