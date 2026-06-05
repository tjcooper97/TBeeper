#include <TBeeper.h>


TBeeper beeper(LED_BUILTIN);

void setup() { 
  // Demonstrating how to place pauses inbetween notes without having to manually calculate and write out delays
  beeper.beep(NOTE_G5, ONE_4TH, ONE_10TH);
  beeper.beep(NOTE_G5, ONE_4TH, ONE_10TH);
  beeper.beep(NOTE_G5, ONE_4TH, ONE_10TH);

  delay(2500); // Delaying so it's easier to tell when we enter the next demo

  // Demonstrating how there will be no pauses between notes, hoewver each one will play for the desired duration, totalling us to (about) 1 second of beep total (so you can listen to your beeper, and ensure it beeps for 1 second long at note NOTE_D5 with no pauses)
  beeper.beep(NOTE_D5, ONE_3RD);
  beeper.beep(NOTE_D5, ONE_3RD);
  beeper.beep(NOTE_D5, ONE_3RD);

  delay(1500); // Delaying so it's easier to tell when we enter the next demo

  // Demonstrating how now that mute is set to true, we not only not play the following notes, we don't delay for any amount of time as well (so you will not hear any beeps here with note NOTE_B5)
  beeper.mute = true;
  beeper.beep(NOTE_B5, ONE_3RD);
  beeper.beep(NOTE_B5, ONE_3RD);
  beeper.beep(NOTE_B5, ONE_3RD);
  beeper.mute = false;

  delay(1500); // Delaying so it's easier to tell when we start the startup chime
  
  beeper.chime(CHIME_STARTUP); 
}



void loop() { beeper.beep(NOTE_B5, ONE_4TH, ONE_FULL); } // start a beep with a duration of a quarter of a second, every second and a quarter (because we play out the whole duration, then delay for a whole second)