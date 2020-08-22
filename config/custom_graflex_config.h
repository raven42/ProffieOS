// This is a sample configuration file.
// This saber has:
//   o Proffieboard V1 hardware.
//   o Two buttons
//   o An XP-E2 RGB LED star on LED 4-5-6
//   o A neopixel blade on LED 1-2-3 and neopixel data 1.
// If you have a saber similar to this one, make a copy and use the copy.
// This is also the default configuration file. Pre-programmed boards will
// use this configuration file.

#ifdef CONFIG_TOP
#include "proffieboard_config.h"
#define NUM_BLADES 1
#define NUM_BUTTONS 2
#define VOLUME 1000
const unsigned int maxLedsPerStrip = 144;
#define CLASH_THRESHOLD_G 1.0
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define ENABLE_SERIAL
#endif

#ifdef CONFIG_PRESETS
Preset presets[] = {
   { "TeensySF", "tracks/venus.wav",    StyleNormalPtr<CYAN, WHITE, 300, 800>(), "cyan"},
   { "SmthJedi", "tracks/mars.wav",     StylePtr<InOutSparkTip<EASYBLADE(BLUE, WHITE), 300, 800> >(), "blue"},
   { "SmthGrey", "tracks/mercury.wav",  StyleFirePtr<RED, YELLOW>(), "fire"},
   { "SmthFuzz", "tracks/uranus.wav",   StyleNormalPtr<RED, WHITE, 300, 800>(), "red"},
   { "RgueCmdr", "tracks/venus.wav",    StyleFirePtr<BLUE, CYAN>(), "blue fire"},
   { "TthCrstl", "tracks/mars.wav",     StylePtr<InOutHelper<EASYBLADE(OnSpark<GREEN>, WHITE), 300, 800> >(), "green"},
   { "TeensySF", "tracks/mercury.wav",  StyleNormalPtr<WHITE, RED, 300, 800, RED>(), "white"},
   { "SmthJedi", "tracks/uranus.wav",   StyleNormalPtr<AudioFlicker<YELLOW, WHITE>, BLUE, 300, 800>(), "yellow"},
   { "SmthGrey", "tracks/venus.wav",    StylePtr<InOutSparkTip<EASYBLADE(MAGENTA, WHITE), 300, 800> >(), "magenta"},
   { "SmthFuzz", "tracks/mars.wav",     StyleNormalPtr<Gradient<RED, BLUE>, Gradient<CYAN, YELLOW>, 300, 800>(), "gradient"},
   { "RgueCmdr", "tracks/mercury.wav",  StyleRainbowPtr<300, 800>(), "rainbow"},
   { "TeensySF", "tracks/venus.wav",    &style_pov, "POV"},
   { "SmthJedi", "tracks/mars.wav",     &style_charging, "Battery\nLevel"}
};

// WS2811BladePtr<128, WS2811_ACTUALLY_800kHz | WS2811_GRB>(),   // 36" Neopixel blade (from:Elecrum Sabercraft - Scion)
// WS2811BladePtr<116, WS2811_ACTUALLY_800kHz | WS2811_GRB>(),   // 32" Neopixel blade (from:Aliexpress - Graflex)
BladeConfig blades[] = {
 { 0, WS2811BladePtr<128, WS2811_ACTUALLY_800kHz | WS2811_GRB>(), CONFIGARRAY(presets) },   
};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif
