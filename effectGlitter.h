/*
 * Shimmering noise, uses global hue cycle
 */


void glitter() {
    int x, y;

    // startup tasks
    if (effectInit == false) {
        effectInit = true;
        effectDelay = 15;
    }

    // Draw one frame of the animation into the LED array
    for (x = 0; x < kMatrixWidth; x++) {
        for (y = 0; y <kMatrixHeight; y++) {
            leds[XY(x, y)] = CHSV(cycleHue, 255, random8(5) * 63);
        }
    }
}
