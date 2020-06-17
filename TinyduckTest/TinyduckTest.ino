// Converted using digiQuack by CedArctic (https://github.com/CedArctic/digiQuack) 

#include "DigiKeyboard.h"

void setup() {
  delay(1000);
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(1000);
  DigiKeyboard.print("notepad");
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
  DigiKeyboard.print("Hello, World!");
}

void loop() {
  
}
