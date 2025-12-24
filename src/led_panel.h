/// @file      led_panel.h
/// @brief     LED Panel Region Definitions and Fill Functions
/// @copyright Copyright (c) 2025 FTC Team 20240 Slingshot. MIT License.

#pragma once

#include <FastLED.h>
#include <cstdint>

/// @namespace led_panel
/// @brief Provides structures and functions for managing LED panel regions.
namespace led_panel
{
  /// @brief Represents a one-dimensional boundary range.
  struct Bounds
  {
    int start; ///< Starting index (inclusive).
    int end;   ///< Ending index (exclusive).
  };

  /// @brief Represents a two-dimensional rectangular region on the LED panel.
  struct RectangularRegion
  {
    Bounds x; ///< Horizontal bounds.
    Bounds y; ///< Vertical bounds.
  };

  // Panel dimension constants
  constexpr uint8_t kPanelWidth = 8;  ///< Width of the LED panel in pixels.
  constexpr uint8_t kPanelHeight = 8; ///< Height of the LED panel in pixels.

  // Predefined quadrant regions (8x8 panel divided into 4x4 quadrants)
  constexpr RectangularRegion kTopLeft{{0, 4}, {0, 4}};     ///< Top-left quadrant.
  constexpr RectangularRegion kTopRight{{4, 8}, {0, 4}};    ///< Top-right quadrant.
  constexpr RectangularRegion kBottomLeft{{0, 4}, {4, 8}};  ///< Bottom-left quadrant.
  constexpr RectangularRegion kBottomRight{{4, 8}, {4, 8}}; ///< Bottom-right quadrant.

  // Predefined half regions
  constexpr RectangularRegion kTopHalf{{0, 8}, {0, 4}};    ///< Top half of the panel.
  constexpr RectangularRegion kBottomHalf{{0, 8}, {4, 8}}; ///< Bottom half of the panel.
  constexpr RectangularRegion kLeftHalf{{0, 4}, {0, 8}};   ///< Left half of the panel.
  constexpr RectangularRegion kRightHalf{{4, 8}, {0, 8}};  ///< Right half of the panel.

  // Full panel region
  constexpr RectangularRegion kFullPanel{{0, 8}, {0, 8}}; ///< Entire LED panel.

  /// @brief Fills a rectangular region with the specified color.
  /// @param rect The rectangular region to fill.
  /// @param color The color to fill the region with.
  /// @param leds Pointer to the LED array to modify.
  inline void fill(const RectangularRegion &rect, const CRGB &color, CRGB *leds) noexcept
  {
    for (uint8_t y = rect.y.start; y < rect.y.end; ++y)
    {
      for (uint8_t x = rect.x.start; x < rect.x.end; ++x)
      {
        leds[y * kPanelWidth + x] = color;
      }
    }
  }

  /// @brief Conditionally fills a rectangular region based on a boolean condition.
  /// @param condition If true, fills with the specified color; otherwise LEDs will be turned off.
  /// @param rect The rectangular region to fill.
  /// @param color The color to fill the region with when condition is true.
  /// @param leds Pointer to the LED array to modify.
  inline void fillWhen(bool condition, const RectangularRegion &rect, const CRGB &color,
                       CRGB *leds) noexcept
  {
    const CRGB fillColor = condition ? color : CRGB::Black;
    fill(rect, fillColor, leds);
  }

} // namespace led_panel