/*
 * Leds run around the periphery of the shades, changing color every go 'round
 */


void shadesOutline(){
    const uint8_t OutlineTable[] = {0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10,
        11, 12, 13, 14, 43, 44, 67, 66, 65, 64, 63, 50, 37, 21, 22, 36, 51, 62,
        61, 60, 59, 58, 57, 30, 29};

    static boolean erase = false;
    static uint8_t x = 0;
    static byte currentColor = 0;

    // startup tasks
    if (effectInit == false) {
        effectInit = true;
        effectDelay = 15;

        erase = false;
        x = 0;
        FastLED.clear();
        currentPalette = RainbowColors_p;
    }

    if (erase) {
        leds[OutlineTable[x]] = CRGB::Black;
    } else {
        leds[OutlineTable[x]] = currentPalette[currentColor];
    }

    x++;
    if (x == (sizeof(OutlineTable))) {
        erase = !erase;
        x = 0;
        currentColor += random8(3, 6);
        if (currentColor > 15) {
            currentColor -= 16;
        }
    }
}
