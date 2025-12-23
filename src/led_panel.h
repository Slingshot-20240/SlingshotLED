/// @file      led_panel.h
/// @brief     LED Panel Region Definitions and Fill Functions
/// @copyright Copyright (c) 2025 FTC Team 20240 Slingshot. MIT License.

#include <vector>

namespace led_panel
{
    struct Bounds
    {
        int start;
        int end;
    };

    struct RectangularRegion
    {
        Bounds x;
        Bounds y;
    };

    constexpr RectangularRegion QUADRANT_ONE{{4, 8}, {0, 4}};
    constexpr RectangularRegion QUADRANT_TWO{{0, 4}, {0, 4}};
    constexpr RectangularRegion QUADRANT_THREE{{0, 4}, {4, 8}};
    constexpr RectangularRegion QUADRANT_FOUR{{4, 8}, {4, 8}};
    constexpr RectangularRegion HALVE_ONE{{0, 8}, {0, 4}};
    constexpr RectangularRegion HALVE_TWO{{0, 8}, {4, 8}};
    constexpr RectangularRegion FULL_PANEL{{0, 8}, {0, 8}};

    /// @brief Fills a specific rectangular region with the given color.
    /// @param rect The rectangular region to fill.
    /// @param color The color to fill the rectangular region with.
    /// @param leds The LED array to modify.
    void fillRectangularRegion(RectangularRegion rect, CRGB color, CRGB *leds)
    {
        for (uint8_t y = rect.y.start; y < rect.y.end; y++)
        {
            for (uint8_t x = rect.x.start; x < rect.x.end; x++)
            {
                leds[y * 8 + x] = color;
            }
        }
    }
}