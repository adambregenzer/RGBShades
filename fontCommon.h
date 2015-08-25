// This is all largely lifted from SmartMatrix library
// https://github.com/pixelmatix/SmartMatrix
// Many thanks to all the team there for their work

/*
 * MatrixFontCommon.h
 *
 *  Created on: Oct 21, 2013
 *      Author: louis
 */

#ifndef FONTCOMMON_H_
#define FONTCOMMON_H_

// bitmap font structure
typedef struct bitmap_font {
    unsigned char Width;           ///< max. character width
    unsigned char Height;          ///< character height
    unsigned short Chars;          ///< number of characters in font
    const unsigned char *Widths;   ///< width of each character
    const unsigned short *Index;   ///< encoding to character index
    const unsigned char *Bitmap;   ///< bitmap of all characters
} bitmap_font;

// @{ defines to have human readable font files
#define ____ 0x0
#define ___X 0x1
#define __X_ 0x2
#define __XX 0x3
#define _X__ 0x4
#define _X_X 0x5
#define _XX_ 0x6
#define _XXX 0x7
#define X___ 0x8
#define X__X 0x9
#define X_X_ 0xA
#define X_XX 0xB
#define XX__ 0xC
#define XX_X 0xD
#define XXX_ 0xE
#define XXXX 0xF
// @}

#endif /* FONTCOMMON_H_ */
