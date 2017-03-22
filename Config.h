//Include libraries
#include <pcmConfig.h>
//Define pins

//General settings
#define DEBUG // Uncomment to enable debug output

// Output settings
#define buffSize 128
#define ENABLE_MULTI
#define SD_CHIPSELECT_PIN 53  //example uses hardware SS pin 53 on Mega2560
#define SPEAKER_PIN_1 11
#define SPEAKER_PIN_2 12

// Input settings
#define THROTTLE_SIGNAL_IN_PIN 2 // pin connected to INTERRUPT 0
#define NEUTRAL_THROTTLE 1000 // usually 1500 for RC cars
#define FADE_DURATION 2 // When changing speeds, this is the time the two files overlap and fade in/out, in seconds

#define SHUTDOWN_FILE 0 // 000.mp3
#define START_FILE 1 // 001.mp3
#define RPM1_FILE 2 // 002.mp3
#define RPM2_FILE 3 // 003.mp3
#define RPM3_FILE 4 // 004.mp3
#define RPM4_FILE 5 // 005.mp3
#define RPM5_FILE 6 // 006.mp3
#define RPM6_FILE 7 // 007.mp3

#define AUTO_SPEEDS   // Instead of manually defining signal ranges for speeds, calculate them automatically on the fly. If this does not work as expected, comment it out and define speed ranges manually below.
#define NUMBER_OF_SPEEDS 5 // Define how many different speed files you are using.

// To use these make sure AUTO_SPEEDS is set to false.
#define SPEED_0 1000
#define SPEED_1 1150
#define SPEED_2 1300
#define SPEED_3 1450
#define SPEED_4 1600
#define SPEED_5 1750
#define SPEED_6 1900

#define SPEED_HYSTERESIS 75 // For example is SPEED_0 is 1000 and SPEED_HYSTERESIS is 75, then SPEED_0 audio will play whenever incoming signal is between 1000-75=925 and 1000+75=1075
