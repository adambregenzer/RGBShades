/*
 * Show rolling eyes - "@ @"
 */


/* Constants
 */
#define ROLLINGEYESTIMER 2500
#define ROLLINGEYESEFFECTDELAY 15

void rollingEyes() {
    uint8_t atPixels1[] = {
        33, 39, 25, 17,  2, 10,  1,  9, 28, 20, 31, 37, 56, 50, 59, 63, 60,
        64, 61, 65, 62, 66, 51, 45, 36, 42, 23, 15,  5, 13
        //           1,  2,          5,              9, 10,         13,
        //      28,         25,     23,         20,         17,     15,
        //      31,     33,         36,         37,     39,         42,
        //      56,                 51,         50,                 45,
        //          59, 60, 61, 62,                 63, 64, 65, 66
    };

    uint8_t atPixels2[] = {
        33, 39, 34, 40, 25, 17,  3, 11,  2, 10,  1,  9, 28, 20, 31, 37, 56,
        50, 59, 63, 60, 64, 61, 65, 62, 66, 51, 45, 36, 42, 23, 15,  5, 13
        //           1,  2,  3,      5,              9, 10, 11,     13,
        //      28,         25,     23,         20,         17,     15,
        //      31,     33, 34,     36,         37,     39, 40,     42,
        //      56,                 51,         50,                 45,
        //          59, 60, 61, 62,                 63, 64, 65, 66
    };

    // static byte rollingEyesCounter;

    byte activeHue = cycleHue;
    byte pixelsLen;
    byte scaleHue;

    // startup tasks
    if (effectInit == false) {
        effectInit = true;
        effectDelay = ROLLINGEYESEFFECTDELAY;

        // rollingEyesCounter = 0;
        FastLED.clear();
    }

    // if (rollingEyesCounter < ROLLINGEYESTIMER / ROLLINGEYESEFFECTDELAY) {
    //   leds[34] = CRGB::Black;
    //   leds[40] = CRGB::Black;
    //   leds[3]  = CRGB::Black;
    //   leds[11] = CRGB::Black;
    //   pixelsLen = 30;
    //   scaleHue = 17;
    // } else {
    pixelsLen = 34;
    scaleHue = 15;
    // }

    for (byte x = 0; x < pixelsLen; x += 2) {
        // if (rollingEyesCounter < ROLLINGEYESTIMER / ROLLINGEYESEFFECTDELAY) {
        //   leds[atPixels1[x]] = CHSV(activeHue, 255, 255);
        //   leds[atPixels1[x + 1]] = CHSV(activeHue, 255, 255);
        // } else {
        leds[atPixels2[x]] = CHSV(activeHue, 255, 255);
        leds[atPixels2[x + 1]] = CHSV(activeHue, 255, 255);
        // }
        activeHue += scaleHue;
    }

    // rollingEyesCounter  += 1;
    // if (rollingEyesCounter == ROLLINGEYESTIMER * 2 / ROLLINGEYESEFFECTDELAY) {
    //   rollingEyesCounter = 0;
    // }

    cycleHue -= 2;
}
