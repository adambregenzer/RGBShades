/*
 * Scanning pattern left/right, uses global hue cycle
 */


void rider() {
    static byte riderPos = 0;

    int brightness;
    CRGB riderColor;
    byte x, y;

    // startup tasks
    if (effectInit == false) {
        effectInit = true;
        effectDelay = 5;

        riderPos = 0;
    }

    // Draw one frame of the animation into the LED array
    for (x = 0; x < kMatrixWidth; x++) {
        brightness = abs(x * (256 / kMatrixWidth) - triwave8(riderPos) * 2 + 127) * 3;
        if (brightness > 255) {
            brightness = 255;
        }
        brightness = 255 - brightness;

        riderColor = CHSV(cycleHue, 255, brightness);

        for (y = 0; y < kMatrixHeight; y++) {
            leds[XY(x, y)] = riderColor;
        }
    }

    // byte wraps to 0 at 255, triwave8 is also 0-255 periodic
    riderPos++;
}
