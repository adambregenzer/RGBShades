/*
 * RGB Plasma
 */


void plasma() {
    static byte offset = 0; // counter for radial color wave motion
    static int plasVector = 0; // counter for orbiting plasma center

    byte color;
    int x, y;

    // Calculate current center of plasma pattern (can be offscreen)
    int xOffset = cos8(plasVector / 256);
    int yOffset = sin8(plasVector / 256);

    // startup tasks
    if (effectInit == false) {
        effectInit = true;
        effectDelay = 10;
    }

    // Draw one frame of the animation into the LED array
    for (x = 0; x < kMatrixWidth; x++) {
        for (y = 0; y < kMatrixHeight; y++) {
            color = sin8(sqrt(sq(((float)x - 7.5) * 10 + xOffset - 127) + sq(((float)y - 2) * 10 + yOffset - 127)) + offset);
            leds[XY(x,y)] = CHSV(color, 255, 255);
        }
    }

    offset++; // wraps at 255 for sin8
    plasVector += 16; // using an int for slower orbit (wraps at 65536)
}
