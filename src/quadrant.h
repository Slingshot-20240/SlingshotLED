/// @file      quadrant.h
/// @brief     Quadrant Enumeration and Fill Functions
/// @copyright Copyright (c) 2025 FTC Team 20240 Slingshot. MIT License.

#include <vector>

enum quadrant
{
    ONE,
    TWO,
    THREE,
    FOUR
};

std::vector<quadrant> HALVE_ONE = {ONE, TWO};
std::vector<quadrant> HALVE_TWO = {THREE, FOUR};

/// Fills a specific quadrant with the given color.
/// @param quad The quadrant to fill.
/// @param color The color to fill the quadrant with.
/// @param leds The LED array to modify.
void fillQuadrant(quadrant quad, CRGB color, CRGB *leds)
{
    uint8_t startX = 0;
    uint8_t endX = 4;
    uint8_t startY = 0;
    uint8_t endY = 4;

    switch (quad)
    {
    case ONE:
        startX = 4;
        endX = 8;
        startY = 0;
        endY = 4;
        break;
    case TWO:
        startX = 0;
        endX = 4;
        startY = 0;
        endY = 4;
        break;
    case THREE:
        startX = 0;
        endX = 4;
        startY = 4;
        endY = 8;
        break;
    case FOUR:
        startX = 4;
        endX = 8;
        startY = 4;
        endY = 8;
        break;
    }

    for (uint8_t y = startY; y < endY; y++)
    {
        for (uint8_t x = startX; x < endX; x++)
        {
            leds[y * 8 + x] = color;
        }
    }
}

/// Fills multiple quadrants with the given color.
/// @param quads The vector of quadrants to fill.
/// @param color The color to fill the quadrants with.
/// @param leds The LED array to modify.
void fillQuadrants(std::vector<quadrant> &quads, CRGB color, CRGB *leds)
{
    for (uint8_t i = 0; i < quads.size(); i++)

    {
        fillQuadrant(quads[i], color, leds);
    }
}