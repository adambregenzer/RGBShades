/*
 * Text effects
 */


void textHue() {
    drawScrollingString(CHSV(cycleHue, 255, 255), // Foreground
                        CRGB::Black,              // Background
                        "HUE");
}


void textWhite() {
    drawScrollingString(CRGB::White, // Foreground
                        CRGB::Black, // Background
                        "WHITE");
}


void textInverted() {
    drawScrollingString(CRGB::Black,              // Foreground
                        CHSV(cycleHue, 255, 255), // Background
                        "INVERTED");
}


void textMultiColor() {
    drawMultiColorScrollingString(CRGB::Black, // Background
                                  "MULTI");
}
