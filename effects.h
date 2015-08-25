/*
 * List of functions that will be displayed
 */


#include "effectColorFill.h"
#include "effectConfetti.h"
#include "effectDisapprovingEyes.h"
// #include "effectGameOfLife.h"
#include "effectGlitter.h"
#include "effectHearts.h"
#include "effectPlasma.h"
#include "effectRider.h"
#include "effectRollingEyes.h"
#include "effectShadesOutline.h"
#include "effectSideRain.h"
#include "effectSlantBars.h"
#include "effectText.h"
#include "effectThreeDee.h"
#include "effectThreeSine.h"


#define numEffects (sizeof(effectList) / sizeof(effectList[0]))

// definition for list of effect function pointers
typedef void (*functionList)();

functionList effectList[] = {
    colorFill,
    confetti,
    disapprovingEyes,
    // gameOfLife,
    glitter,
    hearts,
    plasma,
    rider,
    rollingEyes,
    shadesOutline,
    sideRain,
    slantBars,
    textHue,
    textWhite,
    textInverted,
    textMultiColor,
    threeDee,
    threeSine,
};
