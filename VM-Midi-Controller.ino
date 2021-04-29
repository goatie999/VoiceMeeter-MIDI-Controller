/*
 * Simple means to add a physical control surface to the VoiceMeeter
 * virtual mixser https://vb-audio.com/Voicemeeter/potato.htm using an
 * Ardunio Pro Micro (Leonardo) board and based on the Control Surface
 * (https://github.com/tttapa/Control-Surface) library from Pieter P (tttupa)
 * 
 * This sketch is build simply to control one fader using a potentiometer and
 * provide a visual feedback of the mute status of the bus assing to my main
 * microphone
 */

#include <Control_Surface.h>

USBMIDI_Interface midi;

CCPotentiometer pot = { 
  // A0, MIDI_CC::General_Purpose_Controller_1 
  A0, // Pin used for signal output of the potentionmeter
  {102, CHANNEL_1} // Controller Number, MIDI Channel Number 
};

CCValueLED mainMicMuteLED = {
  10, // Pin that the LED is connected too
  {103, CHANNEL_1} // Controller Number, MIDI Channel Number 
};

void setup() {
  Control_Surface.begin();
}

void loop() {
  Control_Surface.loop();  
}
