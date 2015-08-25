// This is all largely lifted from SmartMatrix library
// https://github.com/pixelmatix/SmartMatrix
// Many thanks to all the team there for their work

// Created from bdf2c Version 3, (c) 2009, 2010 by Lutz Sammer
//  License AGPLv3: GNU Affero General Public License version 3

// original public domain font source:
// http://www.opensource.apple.com/source/X11fonts/X11fonts-14/font-misc-misc/font-misc-misc-1.1.2/4x6.bdf

#include "fontCommon.h"

/// character bitmap for each encoding
static const byte __font3x5_bitmap__[] = {
//  32 $20 'space'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    ____,
    ____,
    ____,
    ____,
    ____,
//  33 $21 'exclam'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    _X__,
    _X__,
    _X__,
    ____,
    _X__,
//  34 $22 'quotedbl'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    X_X_,
    X_X_,
    ____,
    ____,
    ____,
//  35 $23 'numbersign'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    X_X_,
    XXXX,
    X_X_,
    XXXX,
    X_X_,
//  36 $24 'dollar'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    _XX_,
    X_X_,
    _X__,
    X_X_,
    XX__,
//  37 $25 'percent'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    X___,
    __X_,
    _X__,
    X___,
    __X_,
//  38 $26 'ampersand'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    _X__,
    X_X_,
    _X__,
    X_X_,
    _X_X,
//  39 $27 'quotesingle'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    _X__,
    _X__,
    ____,
    ____,
    ____,
//  40 $28 'parenleft'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    __X_,
    _X__,
    _X__,
    _X__,
    __X_,
//  41 $29 'parenright'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    X___,
    _X__,
    _X__,
    _X__,
    X___,
//  42 $2a 'asterisk'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    X_X_,
    _X__,
    XXX_,
    _X__,
    X_X_,
//  43 $2b 'plus'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    ____,
    _X__,
    XXX_,
    _X__,
    ____,
//  44 $2c 'comma'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    ____,
    ____,
    ____,
    _X__,
    X___,
//  45 $2d 'hyphen'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    ____,
    ____,
    XXX_,
    ____,
    ____,
//  46 $2e 'period'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    ____,
    ____,
    ____,
    _X__,
    ____,
//  47 $2f 'slash'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    __X_,
    __X_,
    _X__,
    X___,
    X___,
//  48 $30 'zero'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    _X__,
    X_X_,
    XXX_,
    X_X_,
    _X__,
//  49 $31 'one'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    _X__,
    XX__,
    _X__,
    _X__,
    XXX_,
//  50 $32 'two'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    _X__,
    X_X_,
    __X_,
    _X__,
    XXX_,
//  51 $33 'three'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    XXX_,
    __X_,
    _X__,
    __X_,
    XX__,
//  52 $34 'four'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    X_X_,
    X_X_,
    XXX_,
    __X_,
    __X_,
//  53 $35 'five'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    XXX_,
    X___,
    XX__,
    __X_,
    XX__,
//  54 $36 'six'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    _XX_,
    X___,
    XX__,
    X_X_,
    _X__,
//  55 $37 'seven'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    XXX_,
    __X_,
    _X__,
    X___,
    X___,
//  56 $38 'eight'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    _XX_,
    X_X_,
    _X__,
    X_X_,
    XX__,
//  57 $39 'nine'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    _X__,
    X_X_,
    _XX_,
    __X_,
    XX__,
//  58 $3a 'colon'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    ____,
    _X__,
    ____,
    ____,
    _X__,
//  59 $3b 'semicolon'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    ____,
    _X__,
    ____,
    _X__,
    X___,
//  60 $3c 'less'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    __X_,
    _X__,
    X___,
    _X__,
    __X_,
//  61 $3d 'equal'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    ____,
    XXX_,
    ____,
    XXX_,
    ____,
//  62 $3e 'greater'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    X___,
    _X__,
    __X_,
    _X__,
    X___,
//  63 $3f 'question'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    XX__,
    __X_,
    _X__,
    ____,
    _X__,
//  64 $40 'at'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    _XX_,
    X_X_,
    X_X_,
    X___,
    _XX_,
//  65 $41 'A'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    _X__,
    X_X_,
    XXX_,
    X_X_,
    X_X_,
//  66 $42 'B'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    XX__,
    X_X_,
    XX__,
    X_X_,
    XX__,
//  67 $43 'C'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    _X__,
    X_X_,
    X___,
    X_X_,
    _X__,
//  68 $44 'D'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    XX__,
    X_X_,
    X_X_,
    X_X_,
    XX__,
//  69 $45 'E'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    XXX_,
    X___,
    XX__,
    X___,
    XXX_,
//  70 $46 'F'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    XXX_,
    X___,
    XX__,
    X___,
    X___,
//  71 $47 'G'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    _XX_,
    X___,
    X_X_,
    X_X_,
    _XX_,
//  72 $48 'H'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    X_X_,
    X_X_,
    XXX_,
    X_X_,
    X_X_,
//  73 $49 'I'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    XXX_,
    _X__,
    _X__,
    _X__,
    XXX_,
//  74 $4a 'J'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    __X_,
    __X_,
    __X_,
    X_X_,
    _X__,
//  75 $4b 'K'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    X_X_,
    X_X_,
    XX__,
    X_X_,
    X_X_,
//  76 $4c 'L'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    X___,
    X___,
    X___,
    X___,
    XXX_,
//  77 $4d 'M'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    X_X_,
    XXX_,
    XXX_,
    X_X_,
    X_X_,
//  78 $4e 'N'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    __X_,
    X_X_,
    XXX_,
    X_X_,
    X___,
//  79 $4f 'O'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    _X__,
    X_X_,
    X_X_,
    X_X_,
    _X__,
//  80 $50 'P'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    XX__,
    X_X_,
    XX__,
    X___,
    X___,
//  81 $51 'Q'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    _X__,
    X_X_,
    X_X_,
    _X__,
    __X_,
//  82 $52 'R'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    XX__,
    X_X_,
    XX__,
    X_X_,
    X_X_,
//  83 $53 'S'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    _XX_,
    X___,
    _X__,
    __X_,
    XX__,
//  84 $54 'T'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    XXX_,
    _X__,
    _X__,
    _X__,
    _X__,
//  85 $55 'U'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    X_X_,
    X_X_,
    X_X_,
    X_X_,
    XXX_,
//  86 $56 'V'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    X_X_,
    X_X_,
    X_X_,
    XXX_,
    _X__,
//  87 $57 'W'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    X_X_,
    X_X_,
    XXX_,
    XXX_,
    X_X_,
//  88 $58 'X'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    X_X_,
    X_X_,
    _X__,
    X_X_,
    X_X_,
//  89 $59 'Y'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    X_X_,
    X_X_,
    _X__,
    _X__,
    _X__,
//  90 $5a 'Z'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    XXX_,
    __X_,
    _X__,
    X___,
    XXX_,
//  91 $5b 'bracketleft'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    _XX_,
    _X__,
    _X__,
    _X__,
    _XX_,
//  92 $5c 'backslash'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    X___,
    X___,
    _X__,
    __X_,
    __X_,
//  93 $5d 'bracketright'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    XX__,
    _X__,
    _X__,
    _X__,
    XX__,
//  95 $5f 'underscore'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    ____,
    ____,
    ____,
    ____,
    XXX_,
//  97 $61 'a'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    ____,
    _XX_,
    X_X_,
    X_X_,
    _XX_,
//  98 $62 'b'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    X___,
    XX__,
    X_X_,
    X_X_,
    XX__,
//  99 $63 'c'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    ____,
    _XX_,
    X___,
    X___,
    _XX_,
// 100 $64 'd'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    __X_,
    _XX_,
    X_X_,
    X_X_,
    _XX_,
// 101 $65 'e'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    ____,
    _X__,
    X_X_,
    XX__,
    _XX_,
// 102 $66 'f'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    __X_,
    _X__,
    XXX_,
    _X__,
    _X__,
// 103 $67 'g'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    _XX_,
    X_X_,
    _XX_,
    __X_,
    XX__,
// 104 $68 'h'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    X___,
    XX__,
    X_X_,
    X_X_,
    X_X_,
// 105 $69 'i'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    _X__,
    ____,
    XX__,
    _X__,
    XXX_,
// 106 $6a 'j'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    __X_,
    ____,
    __X_,
    __X_,
    XX__,
// 107 $6b 'k'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    X___,
    X_X_,
    XX__,
    X_X_,
    X_X_,
// 108 $6c 'l'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    XX__,
    _X__,
    _X__,
    _X__,
    XXX_,
// 109 $6d 'm'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    ____,
    X_X_,
    XXX_,
    X_X_,
    X_X_,
// 110 $6e 'n'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    ____,
    XX__,
    X_X_,
    X_X_,
    X_X_,
// 111 $6f 'o'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    ____,
    _X__,
    X_X_,
    X_X_,
    _X__,
// 112 $70 'p'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    XX__,
    X_X_,
    XX__,
    X___,
    X___,
// 113 $71 'q'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    _XX_,
    X_X_,
    X_X_,
    _XX_,
    __X_,
// 114 $72 'r'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    ____,
    X_X_,
    XX__,
    X___,
    X___,
// 115 $73 's'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    ____,
    _XX_,
    XX__,
    __X_,
    XX__,
// 116 $74 't'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    _X__,
    XXX_,
    _X__,
    _X__,
    __X_,
// 117 $75 'u'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    ____,
    X_X_,
    X_X_,
    X_X_,
    _XX_,
// 118 $76 'v'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    ____,
    X_X_,
    X_X_,
    X_X_,
    _X__,
// 119 $77 'w'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    ____,
    X_X_,
    X_X_,
    XXX_,
    X_X_,
// 120 $78 'x'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    ____,
    X_X_,
    _X__,
    _X__,
    X_X_,
// 121 $79 'y'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    X_X_,
    X_X_,
    _XX_,
    __X_,
    XX__,
// 122 $7a 'z'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    ____,
    XXX_,
    __X_,
    _X__,
    XXX_,
// 123 $7b 'braceleft'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    __X_,
    _X__,
    XX__,
    _X__,
    __X_,
// 124 $7c 'bar'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    _X__,
    _X__,
    _X__,
    _X__,
    _X__,
// 125 $7d 'braceright'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    X___,
    _X__,
    _XX_,
    _X__,
    X___,
// 161 $a1 'exclamdown'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    _X__,
    ____,
    _X__,
    _X__,
    _X__,
// 162 $a2 'heart'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    X_X_,
    XXX_,
    XXX_,
    _X__,
    ____,
// 166 $a6 'brokenbar'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    _X__,
    _X__,
    ____,
    _X__,
    _X__,
// 173 $ad 'hyphen'
//  width 4, bbx 0, bby -1, bbw 4, bbh 6
    ____,
    ____,
    XXX_,
    ____,
    ____,
};


/// character encoding for each index entry
static const unsigned short __font3x5_index__[] = {
    32,
    33,
    34,
    35,
    36,
    37,
    38,
    39,
    40,
    41,
    42,
    43,
    44,
    45,
    46,
    47,
    48,
    49,
    50,
    51,
    52,
    53,
    54,
    55,
    56,
    57,
    58,
    59,
    60,
    61,
    62,
    63,
    64,
    65,
    66,
    67,
    68,
    69,
    70,
    71,
    72,
    73,
    74,
    75,
    76,
    77,
    78,
    79,
    80,
    81,
    82,
    83,
    84,
    85,
    86,
    87,
    88,
    89,
    90,
    91,
    92,
    93,
    95,
    97,
    98,
    99,
    100,
    101,
    102,
    103,
    104,
    105,
    106,
    107,
    108,
    109,
    110,
    111,
    112,
    113,
    114,
    115,
    116,
    117,
    118,
    119,
    120,
    121,
    122,
    123,
    124,
    125,
    161,
    162,
    166,
    173
};

// bitmap font structure
const struct bitmap_font font3x5 = {
    .Width = 4, .Height = 5,
    .Chars = 96,
    .Widths = 0,
    .Index = __font3x5_index__,
    .Bitmap = __font3x5_bitmap__,
};
