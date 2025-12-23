/// @file      quadrant.h
/// @brief     Quadrant Enumeration and Fill Functions
/// @copyright Copyright (c) 2025 FTC Team 20240 Slingshot. MIT License.

#include <vector>

namespace quadrant
{
    struct Bounds
    {
        int start;
        int end;
    };

    struct Region
    {
        Bounds x;
        Bounds y;
    };

    constexpr Region ONE{{4, 8}, {0, 4}};
    constexpr Region TWO{{0, 4}, {0, 4}};
    constexpr Region THREE{{0, 4}, {4, 8}};
    constexpr Region FOUR{{4, 8}, {4, 8}};
}

std::vector<quadrant::Region> HALVE_ONE = {quadrant::ONE, quadrant::TWO};
std::vector<quadrant::Region> HALVE_TWO = {quadrant::THREE, quadrant::FOUR};

/// Fills a specific quadrant with the given color.
/// @param quad The quadrant to fill.
/// @param color The color to fill the quadrant with.
/// @param leds The LED array to modify.
void fillQuadrant(quadrant::Region quad, CRGB color, CRGB *leds)
{
    for (uint8_t y = quad.y.start; y < quad.y.end; y++)
    {
        for (uint8_t x = quad.x.start; x < quad.x.end; x++)
        {
            leds[y * 8 + x] = color;
        }
    }
}

/// Fills multiple quadrants with the given color.
/// @param quads The vector of quadrants to fill.
/// @param color The color to fill the quadrants with.
/// @param leds The LED array to modify.
void fillQuadrants(std::vector<quadrant::Region> &quads, CRGB color, CRGB *leds)
{
    for (uint8_t i = 0; i < quads.size(); i++)

    {
        fillQuadrant(quads[i], color, leds);
    }
}