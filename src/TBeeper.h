#ifndef TBEEPER_H
#define TBEEPER_H
  #include <Arduino.h>
  #include <TSoftwareVersion.h>
    #define TBEEPER_V_MAJOR 1
    #define TBEEPER_V_MINOR 1
    #define TBEEPER_V_PATCH 0
    extern const TSoftwareVersion TBeeper_Version;


  // Musical notes
    #define NOTE_B0  31
    #define NOTE_C1  33
    #define NOTE_CS1 35
    #define NOTE_D1  37
    #define NOTE_DS1 39
    #define NOTE_E1  41
    #define NOTE_F1  44
    #define NOTE_FS1 46
    #define NOTE_G1  49
    #define NOTE_GS1 52
    #define NOTE_A1  55
    #define NOTE_AS1 58
    #define NOTE_B1  62
    #define NOTE_C2  65
    #define NOTE_CS2 69
    #define NOTE_D2  73
    #define NOTE_DS2 78
    #define NOTE_E2  82
    #define NOTE_F2  87
    #define NOTE_FS2 93
    #define NOTE_G2  98
    #define NOTE_GS2 104
    #define NOTE_A2  110
    #define NOTE_AS2 117
    #define NOTE_B2  123
    #define NOTE_C3  131
    #define NOTE_CS3 139
    #define NOTE_D3  147
    #define NOTE_DS3 156
    #define NOTE_E3  165
    #define NOTE_F3  175
    #define NOTE_FS3 185
    #define NOTE_G3  196
    #define NOTE_GS3 208
    #define NOTE_A3  220
    #define NOTE_AS3 233
    #define NOTE_B3  247
    #define NOTE_C4  262
    #define NOTE_CS4 277
    #define NOTE_D4  294
    #define NOTE_DS4 311
    #define NOTE_E4  330
    #define NOTE_F4  349
    #define NOTE_FS4 370
    #define NOTE_G4  392
    #define NOTE_GS4 415
    #define NOTE_A4  440
    #define NOTE_AS4 466
    #define NOTE_B4  494
    #define NOTE_C5  523
    #define NOTE_CS5 554
    #define NOTE_D5  587
    #define NOTE_DS5 622
    #define NOTE_E5  659
    #define NOTE_F5  698
    #define NOTE_FS5 740
    #define NOTE_G5  784
    #define NOTE_GS5 831
    #define NOTE_A5  880
    #define NOTE_AS5 932
    #define NOTE_B5  988
    #define NOTE_C6  1047
    #define NOTE_CS6 1109
    #define NOTE_D6  1175
    #define NOTE_DS6 1245
    #define NOTE_E6  1319
    #define NOTE_F6  1397
    #define NOTE_FS6 1480
    #define NOTE_G6  1568
    #define NOTE_GS6 1661
    #define NOTE_A6  1760
    #define NOTE_AS6 1865
    #define NOTE_B6  1976
    #define NOTE_C7  2093
    #define NOTE_CS7 2217
    #define NOTE_D7  2349
    #define NOTE_DS7 2489
    #define NOTE_E7  2637
    #define NOTE_F7  2794
    #define NOTE_FS7 2960
    #define NOTE_G7  3136
    #define NOTE_GS7 3322
    #define NOTE_A7  3520
    #define NOTE_AS7 3729
    #define NOTE_B7  3951
    #define NOTE_C8  4186
    #define NOTE_CS8 4435
    #define NOTE_D8  4699
    #define NOTE_DS8 4978

  // Note durations
    #define ONE_64TH  16
    #define ONE_32ND  31
    #define ONE_20th  50
    #define ONE_16TH  62
    #define ONE_10TH  100
    #define ONE_9TH   111
    #define ONE_8TH   125
    #define ONE_7TH   142
    #define ONE_6TH   167
    #define ONE_5TH   200
    #define ONE_4TH   250
    #define ONE_3RD   333
    #define ONE_HALF  500
    #define ONE_3QTR  750
    #define ONE_FULL  1000
    #define ONE_F64TH ONE_FULL + ONE_64TH
    #define ONE_F32ND ONE_FULL + ONE_32ND
    #define ONE_F20TH ONE_FULL + ONE_20TH
    #define ONE_F16TH ONE_FULL + ONE_16TH
    #define ONE_F10TH ONE_FULL + ONE_10TH
    #define ONE_F9TH  ONE_FULL + ONE_9TH
    #define ONE_F8TH  ONE_FULL + ONE_8TH
    #define ONE_F7TH  ONE_FULL + ONE_7TH
    #define ONE_F6TH  ONE_FULL + ONE_6TH
    #define ONE_F5TH  ONE_FULL + ONE_5TH
    #define ONE_F4TH  ONE_FULL + ONE_4TH
    #define ONE_F3RD  ONE_FULL + ONE_3RD
    #define ONE_FHALF ONE_FULL + ONE_HALF
    #define ONE_F3QTR ONE_FULL + ONE_3QTR


  // System chimes
    #define CHIME_STARTUP        1
    #define CHIME_ITEMON         2
    #define CHIME_ITEMOFF        3
    #define CHIME_ERROR          4
    #define CHIME_DENY           5
    #define CHIME_CONFIRM        6
    #define CHIME_SUCCESS        7
    #define CHIME_FAILURE        8

  // Alerts
    #define CHIME_TIMES_UP       50
    #define CHIME_SIREN_UP       51
    #define CHIME_SIREN_DOWN     52
    #define CHIME_PEW            53
    #define CHIME_PEW_BUM        54
    #define CHIME_BUEP_BEEP      55
    #define CHIME_FLOPPY         56

  // Little diddys
    #define CHIME_YACKITY_YACK   75
    #define CHIME_SMB_UNDERWORLD 76
    #define CHIME_THE_MOB        77
    #define CHIME_LOOK_OVER_HERE 78
    #define CHIME_RISING_TIDES   79
  
  // Beeps, boops, bumps
    #define CHIME_1UP            150
    #define CHIME_BEEP           151
    #define CHIME_BOOP           152
    #define CHIME_BUMP           153

    #define CHIME_BEEP_BEEP      160
    #define CHIME_BEEP_BOOP      161
    #define CHIME_BOOP_BOOP      162
    #define CHIME_BOOP_BEEP      163
    #define CHIME_BOOP_BUMP      164
    #define CHIME_BUMP_BUMP      165
    #define CHIME_BUMP_BOOP      166

    #define CHIME_BEEP_BEEP_BEEP 170
    #define CHIME_BEEP_BEEP_BOOP 171
    #define CHIME_BEEP_BOOP_BEEP 172
    #define CHIME_BEEP_BOOP_BOOP 173 

    #define CHIME_BOOP_BOOP_BOOP 180
    #define CHIME_BOOP_BOOP_BEEP 181
    #define CHIME_BOOP_BOOP_BUMP 182    
    #define CHIME_BOOP_BEEP_BOOP 183
    #define CHIME_BOOP_BEEP_BEEP 184
    #define CHIME_BOOP_BUMP_BOOP 185
    #define CHIME_BOOP_BUMP_BUMP 186
    
    #define CHIME_BUMP_BUMP_BUMP 190
    #define CHIME_BUMP_BUMP_BOOP 191
    #define CHIME_BUMP_BOOP_BUMP 192
    #define CHIME_BUMP_BOOP_BOOP 193




  class TBeeper {
    private:
      uint8_t _pin;

    public:
      TBeeper(uint8_t pin);

      bool mute;
      bool silence();

      bool beep(uint16_t note, uint16_t duration);
      bool beep(uint16_t note, uint16_t duration, uint16_t postduration);

      bool chime(uint8_t c);
  };
#endif