#include "TBeeper.h"


TBeeper beeper(LED_BUILTIN);

void setup() { beeper.chime(CHIME_STARTUP); }
void loop() {  }