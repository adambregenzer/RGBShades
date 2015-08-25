/*
 * Emulate 3D anaglyph glasses
 */


void threeDee() {
    byte x, y;

    // startup tasks
    if (effectInit == false) {
        effectInit = true;
        effectDelay = 1000;

        for (x = 0; x < kMatrixWidth; x++) {
            for (y = 0; y < kMatrixHeight; y++) {
                if (x < 7) {
                    leds[XY(x, y)] = CRGB::Blue;
                } else if (x > 8) {
                    leds[XY(x, y)] = CRGB::Red;
                } else {
                    leds[XY(x, y)] = CRGB::Black;
                }
            }
        }

        leds[XY(6, 0)] = CRGB::Black;
        leds[XY(9, 0)] = CRGB::Black;
    }
}
