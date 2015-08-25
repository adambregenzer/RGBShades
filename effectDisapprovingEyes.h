/*
 * Show disapproving eyes
 */


void disapprovingEyes() {
    const uint8_t disapprovingPixels[] = {
         0,  1,  2,  3,  4,  5,          8,  9, 10, 11, 12, 13,
        28,             24,             20,             16,
        31,     33,     35,             37,     39,     41,
        56,             52,             50,             46,
            59, 60, 61,                     63, 64, 65
    };

    CRGB pixelColor;
    byte x;

    // startup tasks
    if (effectInit == false) {
        effectInit = true;
        effectDelay = 50;

        FastLED.clear();
    }

    pixelColor = CHSV(cycleHue, 255, 255);

    for (x = 0; x < sizeof(disapprovingPixels); x++) {
        leds[disapprovingPixels[x]] = pixelColor;
    }
}
