#include "TBeeper.h"

const TSoftwareVersion TBeeper_Version(TBEEPER_V_MAJOR, TBEEPER_V_MINOR, TBEEPER_V_PATCH);


TBeeper::TBeeper(uint8_t pin) { _pin = pin; }

bool TBeeper::silence() { noTone(_pin); return true; }

bool TBeeper::beep(uint16_t note, uint16_t noteduration)                         { if (mute) { return false; }; tone(_pin, note, noteduration); delay(noteduration);                 return true; }
bool TBeeper::beep(uint16_t note, uint16_t noteduration, uint16_t delayduration) { if (mute) { return false; }; tone(_pin, note, noteduration); delay(noteduration + delayduration); return true; }

bool TBeeper::chime(uint8_t chime) {
  noTone(_pin);
  if (mute) { return false; };
  if      (chime == CHIME_STARTUP)        { beep(NOTE_FS6, ONE_4TH);            beep(NOTE_B4,  ONE_6TH);            beep(NOTE_G5,  ONE_8TH);            beep(NOTE_B5,  ONE_8TH);            beep(NOTE_D6,  ONE_HALF); }
  else if (chime == CHIME_ITEMON)         { beep(NOTE_B5,  ONE_16TH, ONE_32ND); tone(_pin, NOTE_FS6, ONE_16TH); }
  else if (chime == CHIME_ITEMOFF)        { beep(NOTE_FS6, ONE_16TH, ONE_32ND); tone(_pin, NOTE_B5,  ONE_16TH); }
  else if (chime == CHIME_ERROR)          { tone(_pin, NOTE_A6,  ONE_F4TH); }
  else if (chime == CHIME_DENY)           { beep(NOTE_E4,  ONE_16TH, ONE_32ND); tone(_pin, NOTE_E4,  ONE_16TH); }
  else if (chime == CHIME_CONFIRM)        { beep(NOTE_FS6, ONE_16TH, ONE_32ND); tone(_pin, NOTE_FS6, ONE_16TH); }
  else if (chime == CHIME_SUCCESS)        { beep(NOTE_G5,  ONE_4TH,  ONE_16TH); beep(NOTE_B4,  ONE_8TH,  ONE_64TH); beep(NOTE_G5,  ONE_8TH,  ONE_32ND); tone(_pin, NOTE_D6,  ONE_3QTR); }
  else if (chime == CHIME_FAILURE)        { beep(NOTE_AS5, ONE_HALF, ONE_5TH);  beep(NOTE_A5,  ONE_HALF, ONE_5TH);  beep(NOTE_GS5, ONE_HALF, ONE_5TH);  tone(_pin, NOTE_G5,  ONE_3QTR); }

  else if (chime == CHIME_TIMES_UP)       { beep(NOTE_E5,  ONE_16TH, ONE_16TH); beep(NOTE_E5,  ONE_16TH, ONE_16TH); beep(NOTE_E5,  ONE_16TH, ONE_16TH); beep(NOTE_E5,  ONE_16TH, ONE_16TH); }
  else if (chime == CHIME_SIREN_UP)       { for (uint16_t n = NOTE_A5; n < NOTE_B6; n+=14) { beep(n, 3); }; }
  else if (chime == CHIME_SIREN_DOWN)     { for (uint16_t n = NOTE_B6; n > NOTE_A5; n-=14) { beep(n, 3); }; }
  else if (chime == CHIME_PEW)            { for (uint16_t n = NOTE_C6; n > NOTE_G5; n-=13) { beep(n, 3); }; }
  else if (chime == CHIME_PEW_BUM)        { for (uint16_t n = NOTE_C6; n > NOTE_G5; n-=13) { beep(n, 3); }; delay(ONE_32ND); tone(_pin, NOTE_E4,  ONE_10TH); }
  else if (chime == CHIME_BUEP_BEEP)      { for (uint16_t n = NOTE_G5; n < NOTE_B5; n+=13) { beep(n, 3); }; delay(ONE_32ND); tone(_pin, NOTE_FS6, ONE_10TH); }
  else if (chime == CHIME_FLOPPY)         { for (uint8_t  i = 0;       i < 4;       i++)   { beep(NOTE_C3, 30, 10); }; tone(_pin, NOTE_G2, 50); }

  else if (chime == CHIME_YACKITY_YACK)   { beep(NOTE_E5,  ONE_7TH,  ONE_10TH); beep(NOTE_E5,  ONE_10TH, ONE_16TH); beep(NOTE_E5,  ONE_7TH,  ONE_7TH);  beep(NOTE_E5,  ONE_5TH,  ONE_5TH);  beep(NOTE_E4,  ONE_5TH,  ONE_16TH); beep(NOTE_E4, ONE_5TH, ONE_16TH); tone(_pin, NOTE_E4, ONE_5TH); }
  else if (chime == CHIME_SMB_UNDERWORLD) { beep(NOTE_C3,  ONE_8TH,  ONE_32ND); beep(NOTE_C4,  ONE_8TH,  ONE_32ND); beep(NOTE_A2,  ONE_8TH,  ONE_32ND); beep(NOTE_A3,  ONE_8TH,  ONE_32ND); beep(NOTE_AS2, ONE_8TH,  ONE_32ND); tone(_pin, NOTE_AS3, ONE_8TH); }
  else if (chime == CHIME_THE_MOB)        { beep(NOTE_E3,  ONE_4TH,  ONE_6TH);  beep(NOTE_B2,  ONE_6TH,  ONE_16TH); beep(NOTE_CS3, ONE_6TH,  ONE_16TH); beep(NOTE_D3,  ONE_6TH,  ONE_16TH); beep(NOTE_CS3, ONE_6TH,  ONE_16TH); beep(NOTE_B2,  ONE_6TH,  ONE_4TH);  
                                            beep(NOTE_G2,  ONE_4TH,  ONE_6TH);  beep(NOTE_E2,  ONE_6TH,  ONE_16TH); beep(NOTE_E2,  ONE_6TH,  ONE_16TH); }
  else if (chime == CHIME_LOOK_OVER_HERE) { beep(NOTE_G5,  ONE_3RD);            beep(NOTE_G5,  ONE_3RD);            beep(NOTE_G5,  ONE_3RD);            tone(_pin, NOTE_D4,  ONE_HALF); }
  else if (chime == CHIME_RISING_TIDES)   { beep(NOTE_G5,  ONE_4TH);            beep(NOTE_B4,  ONE_4TH);            beep(NOTE_D5,  ONE_4TH);            beep(NOTE_F5,  ONE_4TH);            tone(_pin, NOTE_G5,  ONE_3RD);  }

  else if (chime == CHIME_1UP)            { beep(NOTE_E6,  ONE_4TH,  5);        beep(NOTE_G6,  ONE_4TH,  5);        beep(NOTE_E7,  ONE_4TH,  5);        beep(NOTE_C7,  ONE_4TH,  5);        beep(NOTE_D7,  ONE_4TH,  5);        tone(_pin, NOTE_G7,  ONE_4TH); }
  else if (chime == CHIME_BEEP)           { tone(NOTE_B5, 20); }
  else if (chime == CHIME_BOOP)           { tone(NOTE_F5, 20); }
  else if (chime == CHIME_BUMP)           { tone(NOTE_G4, 20); }

  else if (chime == CHIME_BEEP_BEEP)      { beep(NOTE_B5, 20, 45); tone(NOTE_B5, 20); }
  else if (chime == CHIME_BEEP_BOOP)      { beep(NOTE_B5, 20, 45); tone(NOTE_F5, 20); }
  else if (chime == CHIME_BOOP_BOOP)      { beep(NOTE_F5, 20, 45); tone(NOTE_F5, 20); }
  else if (chime == CHIME_BOOP_BEEP)      { beep(NOTE_F5, 20, 45); tone(NOTE_B5, 20); }
  else if (chime == CHIME_BOOP_BUMP)      { beep(NOTE_F5, 20, 45); tone(NOTE_G4, 20); }
  else if (chime == CHIME_BUMP_BUMP)      { beep(NOTE_G4, 20, 45); tone(NOTE_G4, 20); }
  else if (chime == CHIME_BUMP_BOOP)      { beep(NOTE_G4, 20, 45); tone(NOTE_F5, 20); }

  else if (chime == CHIME_BEEP_BEEP_BEEP) { beep(NOTE_B5, 20, 45); beep(NOTE_B5, 20, 45); tone(NOTE_B5, 20); }
  else if (chime == CHIME_BEEP_BEEP_BOOP) { beep(NOTE_B5, 20, 45); beep(NOTE_B5, 20, 45); tone(NOTE_F5, 20); }
  else if (chime == CHIME_BEEP_BOOP_BEEP) { beep(NOTE_B5, 20, 45); beep(NOTE_F5, 20, 45); tone(NOTE_B5, 20); }
  else if (chime == CHIME_BEEP_BOOP_BOOP) { beep(NOTE_B5, 20, 45); beep(NOTE_F5, 20, 45); tone(NOTE_F5, 20); }
  
  else if (chime == CHIME_BOOP_BOOP_BOOP) { beep(NOTE_F5, 20, 45); beep(NOTE_F5, 20, 45); tone(NOTE_F5, 20); }
  else if (chime == CHIME_BOOP_BOOP_BEEP) { beep(NOTE_F5, 20, 45); beep(NOTE_F5, 20, 45); tone(NOTE_B5, 20); }
  else if (chime == CHIME_BOOP_BOOP_BUMP) { beep(NOTE_F5, 20, 45); beep(NOTE_F5, 20, 45); tone(NOTE_G4, 20); }
  else if (chime == CHIME_BOOP_BEEP_BOOP) { beep(NOTE_F5, 20, 45); beep(NOTE_B5, 20, 45); tone(NOTE_F5, 20); }
  else if (chime == CHIME_BOOP_BEEP_BEEP) { beep(NOTE_F5, 20, 45); beep(NOTE_B5, 20, 45); tone(NOTE_B5, 20); }
  else if (chime == CHIME_BOOP_BUMP_BOOP) { beep(NOTE_F5, 20, 45); beep(NOTE_G4, 20, 45); tone(NOTE_F5, 20); }
  else if (chime == CHIME_BOOP_BUMP_BUMP) { beep(NOTE_F5, 20, 45); beep(NOTE_G4, 20, 45); tone(NOTE_G4, 20); }

  else if (chime == CHIME_BUMP_BUMP_BUMP) { beep(NOTE_G4, 20, 45); beep(NOTE_G4, 20, 45); tone(NOTE_G4, 20); }
  else if (chime == CHIME_BUMP_BUMP_BOOP) { beep(NOTE_G4, 20, 45); beep(NOTE_G4, 20, 45); tone(NOTE_F5, 20); }
  else if (chime == CHIME_BUMP_BOOP_BUMP) { beep(NOTE_G4, 20, 45); beep(NOTE_F5, 20, 45); tone(NOTE_G4, 20); }
  else if (chime == CHIME_BUMP_BOOP_BOOP) { beep(NOTE_G4, 20, 45); beep(NOTE_F5, 20, 45); tone(NOTE_F5, 20); }
  else                                    { return false; };
  return true;
}