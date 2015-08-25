/*
 * Hearts that start small on the bottom and get larger as they grow upward
 */


void hearts() {
    const uint8_t SmHeart[] = {46, 48, 53, 55, 60, 65};
    const uint8_t MedHeart[] = {31, 32, 34, 35, 38, 39,
        41, 42, 46, 47, 48, 55, 54, 53, 54, 55, 60, 65};
    const uint8_t LrgHeart[] = {15, 16, 18, 19, 24, 25,
        27, 28, 31, 32, 33, 34, 35, 38, 39, 40, 41, 42,
        46, 47, 48, 53, 54, 55, 60, 65};
    const uint8_t HugeHeart[] = {0, 1, 3, 4, 9, 10, 12,
        13, 14, 15, 16, 17, 18, 19, 20, 23, 24, 25, 26,
        27, 28, 29, 31, 32, 33, 34, 35, 38, 39, 40, 41,
        42, 46, 47, 48, 53, 54, 55, 60, 65};

    static int y;

    int x;

    // startup tasks
    if (effectInit == false) {
        effectInit = true;
        effectDelay = 250;

        y = 0;
        FastLED.clear();
    }

    if (y == 0) {
        for (x = 0; x < 6; x++)
            leds[SmHeart[x]] = CRGB::Salmon;
    } else if (y == 1) {
        for (x = 0; x < 18; x++)
            leds[MedHeart[x]] = CRGB::Tomato;
    } else if (y == 2) {
        for (x = 0; x < 26; x++)
            leds[LrgHeart[x]] = CRGB::Crimson;
    } else if (y == 3) {
        for (x = 0; x < 40; x++)
            leds[HugeHeart[x]] = CRGB::Red;
        effectDelay = 450;
    } else if (y == 4) {
        FastLED.clear();
    } else {
        y = -1;
    }

    y++;
}
