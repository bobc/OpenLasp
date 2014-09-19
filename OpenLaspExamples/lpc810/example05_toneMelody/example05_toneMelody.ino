/*** LPC810 Arduino compatible library example ***/

/*
  Melody

 Plays a melody

 circuit:
 * piezo speaker on digital speaker pin


 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe

 modified and addeptet by ChrisMicro 2014 for LPC810

                      _________
                      |   U   |
        reset switch -|       |-
                     -|  LPC  |- GND
         speaker pin -|  810  |- +3.3V
            test led -|       |-
                      |_______|


This example code is in the public domain.

 http://arduino.cc/en/Tutorial/Tone

 */
#include "pitches.h"
#include "tone.h"

int SpeakerPin=3;
// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4,4,4,4,4 };

void setup() {

  int thisNote;

  // iterate over the notes of the melody:
  for (thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration= 1000/noteDurations[thisNote];
    tone(SpeakerPin, melody[thisNote]/2,noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 13/10;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(SpeakerPin);

  }
}

void loop() {
  // no need to repeat the melody.
}
