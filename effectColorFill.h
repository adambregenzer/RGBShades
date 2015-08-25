/*
 * Fills saturated colors into the array from alternating directions
 */


void colorFill() {
    static byte currentColor = 0;
    static byte currentRow = 0;
    static byte currentDirection = 0;

    byte x, y;

    // startup tasks
    if (effectInit == false) {
        effectInit = true;
        effectDelay = 45;

        currentColor = 0;
        currentRow = 0;
        currentDirection = 0;
        currentPalette = RainbowColors_p;
    }

    // test a bitmask to fill up or down when currentDirection is 0 or 2 (0b00 or 0b10)
    if (!(currentDirection & 1)) {
        // slower since vertical has fewer pixels
        effectDelay = 45;

        if (currentDirection == 0) {
            y = currentRow;
        } else {
            y = kMatrixHeight - 1 - currentRow;
        }

        for (x = 0; x < kMatrixWidth; x++) {
            leds[XY(x,y)] = currentPalette[currentColor];
        }
    }

    // test a bitmask to fill left or right when currentDirection is 1 or 3 (0b01 or 0b11)
    if (currentDirection & 1) {
        // faster since horizontal has more pixels
        effectDelay = 20;

        if (currentDirection == 1) {
            x = currentRow;
        } else {
            x = kMatrixWidth - 1 - currentRow;
        }

        for (y = 0; y < kMatrixHeight; y++) {
            leds[XY(x,y)] = currentPalette[currentColor];
        }
    }

    currentRow++;

    // detect when a fill is complete, change color and direction
    if ((!(currentDirection & 1) && currentRow >= kMatrixHeight) || (currentRow >= kMatrixWidth)) {
        // wait a little bit longer after completing a fill
        effectDelay = 300;

        currentRow = 0;

        currentColor += random8(3, 6);
        if (currentColor > 15) {
            currentColor -= 16;
        }

        currentDirection++;
        if (currentDirection > 3) {
            currentDirection = 0;
        }
    }
}
