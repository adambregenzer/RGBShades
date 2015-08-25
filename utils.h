/*
 * Assorted useful functions and variables
 */


/* Increment the global hue value for functions that use it
 */
void hueCycle(byte incr) {
    cycleHue += incr;
}


/* Set every LED in the array to a specified color
 */
void fillAll(CRGB fillColor) {
    for (byte i = 0; i < NUM_LEDS; i++) {
        leds[i] = fillColor;
    }
}


/* Fade every LED in the array by a specified amount
 */
void fadeAll(byte fadeIncr) {
    for (byte i = 0; i < NUM_LEDS; i++) {
        leds[i] = leds[i].fadeToBlackBy(fadeIncr);
    }
}


/* Shift all pixels by one, right or left (0 or 1)
 */
void scrollArray(byte scrollDir) {
    byte scrollX = 0;
    for (byte x = 1; x < kMatrixWidth; x++) {
        if (scrollDir == 0) {
            scrollX = kMatrixWidth - x;
        } else if (scrollDir == 1) {
            scrollX = x - 1;
        }

        for (byte y = 0; y < kMatrixHeight; y++) {
            leds[XY(scrollX,y)] = leds[XY(scrollX + scrollDir*2 - 1,y)];
        }
    }
}


/* Pick a random palette from a list
 */
void selectRandomPalette() {
    switch(random8(8)) {
    case 0:
        currentPalette = CloudColors_p;
        break;

    case 1:
        currentPalette = LavaColors_p;
        break;

    case 2:
        currentPalette = OceanColors_p;
        break;

    case 4:
        currentPalette = ForestColors_p;
        break;

    case 5:
        currentPalette = RainbowColors_p;
        break;

    case 6:
        currentPalette = PartyColors_p;
        break;

    case 7:
        currentPalette = HeatColors_p;
        break;
    }
}


/* Interrupt normal operation to indicate that auto cycle mode has changed
 */
void confirmBlink() {
    if (autoCycle) {
        // one blue blink, auto mode active
        fillAll(CRGB::DarkBlue);
        FastLED.show();
        FastLED.delay(200);
        FastLED.clear();
        FastLED.delay(200);
    } else {
        // two red blinks, manual mode active
        fillAll(CRGB::DarkRed);
        FastLED.show();
        FastLED.delay(200);
        FastLED.clear();
        FastLED.delay(200);
        fillAll(CRGB::DarkRed);
        FastLED.show();
        FastLED.delay(200);
        FastLED.clear();
        FastLED.delay(200);
    }
}
