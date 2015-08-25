/*
 * Random pixels scroll sideways, uses current hue
 */


/* Constants
 */
#define rainDir 0


void sideRain() {
    byte randPixel;
    byte y;

    // startup tasks
    if (effectInit == false) {
        effectInit = true;
        effectDelay = 30;
    }

    scrollArray(rainDir);
    randPixel = random8(kMatrixHeight);
    for (y = 0; y < kMatrixHeight; y++) {
        leds[XY((kMatrixWidth - 1) * rainDir, y)] = CRGB::Black;
    }
    leds[XY((kMatrixWidth - 1) * rainDir, randPixel)] = CHSV(cycleHue, 255, 255);
}
