/// @file      color.h
/// @brief     Predefined Colors
/// @copyright Copyright (c) 2025 FTC Team 20240 Slingshot. MIT License.

namespace color
{
    constexpr auto LEDS_OFF = CHSV(0, 0, 0);

    constexpr auto RED = CHSV(0, 255, 255);
    constexpr auto GREEN = CHSV(120 / 360.0 * 255, 255, 255);
    constexpr auto BLUE = CHSV(240 / 360.0 * 255, 255, 255);
    constexpr auto CYAN = CHSV(180 / 360.0 * 255, 255, 255);
    constexpr auto MAGENTA = CHSV(300 / 360.0 * 255, 255, 255);
    constexpr auto YELLOW = CHSV(60 / 360.0 * 255, 255, 255);
    constexpr auto WHITE = CHSV(0, 0, 255);

    constexpr auto ARTIFACT_PURPLE = CHSV(276 / 360.0 * 255, 95 / 100.0 * 255, 94 / 100.0 * 255);
    constexpr auto ARTIFACT_GREEN = CHSV(129 / 360.0 * 255, 91 / 100.0 * 255, 78 / 100.0 * 255);

    constexpr auto SLINGSHOT_PURPLE = CHSV(255 / 360.0 * 255, 67 / 100.0 * 255, 64 / 100.0 * 255);
}