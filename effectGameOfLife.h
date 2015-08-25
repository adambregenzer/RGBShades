/*
 * Run Conway's Game of Life on the glasses
 * based on code by kredal
 * https://github.com/kredal/RGBShades/commit/2cf723b85363d0232035f220d2119ad5847e0e6c
 */


/* Globals
 */
uint8_t OldCells[80];  // Cells currently being drawn; updated from NewCells at the end of each effect loop
uint8_t NewCells[80];  // Cells for the next frame; based on neighbors of OldCells
uint8_t CellAge[80];   // How long since the cells were last switched on;  changes the cell color


/* Clear the screen and the cells matrices
 */
void Clear() {
    byte cell;

    for (cell = 0; cell < 80; cell++) {
        OldCells[cell] = 0;
        NewCells[cell] = 0;
    }
    FastLED.clear();
}


/* A higher value means lower probability of cells added
 */
void Randomize(byte Prob) {
    byte cell;

    for (cell = 0; cell < 80; cell++) {
        if (random(0, 10) > Prob) {
            OldCells[cell] = 1;
        }
    }
}


/* Puts a glider somewhere on the matrix
 */
void Glider(byte Xoff, byte Yoff) {
    OldCells[ 2 + Xoff + Yoff * 16] = 1;
    OldCells[16 + Xoff + Yoff * 16] = 1;
    OldCells[18 + Xoff + Yoff * 16] = 1;
    OldCells[33 + Xoff + Yoff * 16] = 1;
    OldCells[34 + Xoff + Yoff * 16] = 1;
}


/* Counts active neighbors
 */
uint8_t Neighbors(byte X, byte Y) {
    if (X == 0) {
        if (Y == 0) {
            // Top-Left Corner
            return OldCells[1] + OldCells[15] + OldCells[16] + OldCells[17] + OldCells[31] + OldCells[64] + OldCells[65] + OldCells[79];
        } else {
            // Left Column
            return OldCells[(Y-1)*16+15] + OldCells[(Y-1)*16] + OldCells[(Y-1)*16+1] + OldCells[Y*16+15] + OldCells[Y*16+1] + OldCells[((Y+1)%5)*16+15] + OldCells[((Y+1)%5)*16] + OldCells[((Y+1)%5)*16+1];
        }
    }
    if (Y == 0) {
        // Top Row
        return OldCells[63+X] + OldCells[64+X] + OldCells[64+((X+1)%16)] + OldCells[X-1] + OldCells[(X+1)%16] + OldCells[15+X] + OldCells[16+X] + OldCells[16+((X+1)%16)];
    } else {
        // Other Cells
        return OldCells[(Y-1)*16+X-1] + OldCells[(Y-1)*16+X] + OldCells[(Y-1)*16+((X+1)%16)] + OldCells[Y*16+X-1] + OldCells[Y*16+((X+1)%16)] + OldCells[((Y+1)%5)*16+X-1] + OldCells[((Y+1)%5)*16+X] + OldCells[((Y+1)%5)*16+((X+1)%16)];
    }
}


void gameOfLife() {
    static byte NewCount = 0;
    static byte OldCount = 0;
    static byte Empty = 0;
    static byte Stable = 0;
    static boolean Expand = false;

    int x, y;
    byte cell;

    // startup tasks
    if (effectInit == false) {
        effectInit = true;
        effectDelay = 150;

        Clear();
        Glider(0,0);
        Glider(8,1);
    }

    // Draw live cells and count them, determine neighbors and store live cells for next frame.
    NewCount = 0;
    for (x = 0; x < 16; x++) {
        for (y = 0; y < 5; y++) {
            // This is that Cell
            cell = y * 16 + x;

            // Dead cells
            if (OldCells[cell] == 0) {
                // Don't draw the cell if its dead
                leds[XY(x,y)] = CRGB::Black;

                // Its alive!
                if (Neighbors(x,y) == 3) {
                    NewCells[cell] = 1;
                    NewCount++;
                }

                // If the pattern is stable, increase cell growth
                if ((Expand == true) && (Neighbors(x,y) > 1)) {
                    NewCells[cell] = 1;
                }
            } else {
                // Draw live cells, color dependant on age
                leds[XY(x, y)] = CHSV((CellAge[cell]) * 20 + 28, 255, 255);

                if (Neighbors(x, y) != 2 && Neighbors(x, y) != 3) {
                    // Kill the cell
                    NewCells[cell] = 0;
                    CellAge[cell] = 0;
                } else {
                    // Stayin' alive
                    NewCells[cell] = 1;

                    // Increment the cell's age until its old
                    if (CellAge[cell] < 16) {
                        CellAge[cell]++;
                    }
                }
            }
        }
    }

    Expand = false;

    for (cell = 0; cell < 80; cell++) {
        // Update the old cells
        OldCells[cell] = NewCells[cell];

        // Count the live cells
        NewCount += OldCells[cell];
    }

    // There are no live cells
    if (NewCount == 0) {
        // This number determines the delay before randomizing
        if (++Empty > 3) {
            Empty = 0;
            Randomize(5); // 0-9 (A higher value means less cells added)
        }
    } else if (NewCount == OldCount) {
        // The live cell count hasn't changed, delay to confirm stable pattern
        if (Stable++ > 15) {
            Stable = 0;
            Expand = true;
        }
    } else {
        Stable = 0;
    }
    OldCount = NewCount;
}
