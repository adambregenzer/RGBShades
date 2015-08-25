// This is all largely lifted from SmartMatrix library
// https://github.com/pixelmatix/SmartMatrix
// Many thanks to all the team there for their work

/*
 * SmartMatrix Library - Methods for accessing bitmap fonts
 *
 * Copyright (c) 2014 Louis Beaudoin (Pixelmatix)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "font3x5.h"

byte xScrollOffset = 0;
int multiOffCounter = 0;
byte sineOffset = 0; // counter for current position of sine waves


// depends on letters in font->Index table being arranged in ascending order
// save location of last lookup to speed up repeated lookups of the same letter
// TODO: use successive approximation to locate the index faster
int getBitmapFontLocation(unsigned char letter, const bitmap_font *font) {
    static int location = 0;

    if (location < 0) {
        location = 0;
    }

    if (font->Index[location] == letter) {
        return location;
    }

    if (font->Index[location] < letter) {
        for (; location < font->Chars; location++) {
            if (font->Index[location] == letter) {
                return location;
            }
        }
    } else {
        for (; location >= 0; location--) {
            if (font->Index[location] == letter) {
                return location;
            }
        }
    }

    return -1;
}


bool getBitmapFontPixelAtXY(unsigned char letter, unsigned char x, unsigned char y, const bitmap_font *font) {
    int location;
    if (y >= font->Height) {
        return false;
    }

    location = getBitmapFontLocation(letter, font);

    if (location < 0) {
        return false;
    }

    if (font->Bitmap[(location * font->Height) + y] & (0x8 >> x)) {
        return true;
    } else {
        return false;
    }
}


uint8_t getBitmapFontRowAtXY(unsigned char letter, unsigned char y, const bitmap_font *font) {
    int location;

    if (y >= font->Height) {
        return 0x00;
    }

    location = getBitmapFontLocation(letter, font);

    if (location < 0) {
        return 0x00;
    }

    return font->Bitmap[(location * font->Height) + y];
}


void drawChar(int16_t x, int16_t y, const CRGB& charColor, char character, const bitmap_font *font) {
    int xcnt, ycnt;

    for (ycnt = 0; ycnt < font->Height; ycnt++) {
        for (xcnt = 0; xcnt < font->Width; xcnt++) {
            if (getBitmapFontPixelAtXY(character, xcnt, ycnt, font)) {
                leds[XY(x + xcnt, y + ycnt)] = charColor;
            }
        }
    }
}


void drawString(int16_t x, int16_t y, const CRGB& charColor, const char text[], const bitmap_font *font) {
    int xcnt, ycnt, i = 0, offset = 0;
    char character;

    for (i = 0; i < strlen(text); i++) {
        character = text[offset++];
        if (character == '\0') {
            return;
        }

        for (ycnt = 0; ycnt < font->Height; ycnt++) {
            for (xcnt = 0; xcnt < font->Width; xcnt++) {
                if (getBitmapFontPixelAtXY(character, xcnt, ycnt, font)) {
                    leds[XY(x + xcnt, y + ycnt)] = charColor;
                }
            }
        }
        x += font->Width;
    }
}


// draw string while clearing background
void drawString(int16_t x, int16_t y, const CRGB& charColor, const CRGB& backColor, const char text[], const bitmap_font *font) {
    int xcnt, ycnt, i = 0, offset = 0;
    char character;

    for (i = 0; i < strlen(text); i++) {
        character = text[offset++];
        if (character == '\0') {
            return;
        }

        for (ycnt = 0; ycnt < font->Height; ycnt++) {
            for (xcnt = 0; xcnt < font->Width; xcnt++) {
                if (getBitmapFontPixelAtXY(character, xcnt, ycnt, font)) {
                    leds[XY(x + xcnt, y + ycnt)] = charColor;
                } else {
                    leds[XY(x + xcnt, y + ycnt)] = backColor;
                }
            }
        }
        x += font->Width;
    }
}


/* Draws a string and scrolls it across the glasses */
void drawScrollingString(const CRGB& charColor, const CRGB& backColor, const char text[]) {
    if (effectInit == false) {
        effectInit = true;
        effectDelay = 100;
        xScrollOffset = 0;

        FastLED.clear();
    }

    fillAll(backColor);
    drawString(16 - xScrollOffset, 0, charColor, backColor, text, &font3x5);

    xScrollOffset++;
    if (xScrollOffset > (strlen(text) * font3x5.Width + 16)) {
        xScrollOffset = 0;
    }
}


void drawMultiColorScrollingString(const CRGB& backColor, const char text[]) {
    int xcnt, ycnt, i = 0, offset = 0;
    int16_t x = 16 - xScrollOffset, y = 0;
    char character;
    CRGB c;

    if (effectInit == false) {
        effectInit = true;
        effectDelay = 10;
        sineOffset = 0;
        xScrollOffset = 0;
        multiOffCounter = 0;
        x = 16;

        FastLED.clear();
    }

    for (i = 0; i < strlen(text); i++) {
        character = text[offset++];
        if (character == '\0')
            break;

        c = CHSV(i * 30 + sineOffset, 255, 128);
        for (ycnt = 0; ycnt < font3x5.Height; ycnt++) {
            for (xcnt = 0; xcnt < font3x5.Width; xcnt++) {
                if (getBitmapFontPixelAtXY(character, xcnt, ycnt, &font3x5)) {
                    leds[XY(x + xcnt,y + ycnt)] = c;
                } else {
                    leds[XY(x + xcnt,y + ycnt)] = backColor;
                }
            }
        }
        x += font3x5.Width;
    }

    if (multiOffCounter > 8) {
        xScrollOffset++;
        if (xScrollOffset > (strlen(text) * font3x5.Width + 16)) {
            xScrollOffset = 0;
        }
        multiOffCounter = 0;
    }

    if (multiOffCounter % 3 == 0) {
        sineOffset++;
    }

    multiOffCounter++;
}
