#include <Arduino.h>
#include "Config.h"
#include "Output.h"
#include <SD.h>
#include <SPI.h>
#include <TMRpcm.h>

TMRpcm audio;   // create an object for use in this sketch 

outputClass::outputClass(){
}

void outputClass::SETUP() {
  
  audio.speakerPin = SPEAKER_PIN_1; //5,6,11 or 46 on Mega, 9 on Uno, Nano, etc
  
  pinMode(SPEAKER_PIN_2,OUTPUT);  //Pin pairs: 9,10 Mega: 5-2,6-7,11-12,46-45
  
  if (!SD.begin(SD_CHIPSELECT_PIN)) {
    #ifdef DEBUG
      Serial.println("SD failed to initialize!");
    #endif
    return;
  }else{
    #ifdef DEBUG
      Serial.println("SD OK");
    #endif
    
  }
  
}

// Queue up next file to play. Alternates between two available outputs and handles fading in/out the files as needed.
void outputClass::queueFile(String fileName, bool stopPrevious = false) {
  // Determine if we have an unused output available.

  // Fade out the currently playing file if stopPrevious is set to true, else just overlay the new audio.
  
}

void outputClass::playAudio() {
  
    if(Serial.available()){                          //Send commands over serial to play
      
      switch(Serial.read()){
        case '1':
          audio.loop(0,1);
          audio.play("start.wav",1);
          #ifdef DEBUG
            Serial.println("Playing start.wav on pin 12"); 
          #endif
          break;    //Play tr1.wav on pin 11 (9 on Uno)
        case '2':
          audio.loop(0,0);
          audio.play("startup.wav",0);
          #ifdef DEBUG
            Serial.println("Playing startup.wav on pin 11"); 
          #endif
          break;    //Play tr1.wav on pin 11 (9 on Uno)
        case '3':
        audio.loop(1,1);
          audio.play("rpm1000.wav",1);
          #ifdef DEBUG
            Serial.println("Playing tr1.wav on pin 12"); 
          #endif
          break;    //Play tr1.wav on pin 12 (10 on Uno)
        case '4':
        audio.loop(1,0);
          audio.play("rpm1500.wav",0);
          #ifdef DEBUG
            Serial.println("Playing tr2.wav on pin 11"); 
          #endif
          break;    //Play tr2.wav on pin 11
        case '+':
          audio.volume(1);
          #ifdef DEBUG
            Serial.println("Increasing volume by 1"); 
          #endif
          break;            //Increase volume by 1
        case '-':
          audio.volume(0);
          #ifdef DEBUG
            Serial.println("Decreasing volume by 1"); 
          #endif
          break;            //Decrease volume by 1
        case 's':
          audio.stopPlayback(0);
          #ifdef DEBUG
            Serial.println("Stopping playback on pin 11"); 
          #endif
          break;      //Stop playback on pin 11
        case 'S':
          audio.stopPlayback(1);
          #ifdef DEBUG
            Serial.println("Stopping playback on pin 12"); 
          #endif
          break;      //Stop playback on pin 12
        case 'x':
          audio.stopPlayback();
          #ifdef DEBUG
            Serial.println("Stopping all playback"); 
          #endif
          break;       //Stop all playback
        
      }
    }
}

outputClass Audio = outputClass();
