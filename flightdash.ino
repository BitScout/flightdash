
// Developed for the Teensy++ 2.0
// See https://www.pjrc.com/teensy/td_joystick.html on how to flash the firmaware

#define MODULE_THROTTLE
//#define MODULE_SURFACES

// Throttle mode
#define SW_THRTL   20
#define SW_PROP    21
#define SW_MIX     22

#define POT_THRTL_L 45
#define POT_THRTL_R 44
#define POT_PROP_L  43
#define POT_PROP_R  42
#define POT_MIX_L   41
#define POT_MIX_R   40

// Surfaces mode
#define SW_BLOCK_1 20

#define POT_SPDBRK 38
#define POT_FLAPS  39

//#define INT_1A 18
//#define INT_1B 19

void setup() {
  #ifdef MODULE_THROTTLE
    pinMode(POT_THRTL_L, INPUT_PULLUP);
    pinMode(POT_THRTL_R, INPUT_PULLUP);
    pinMode(POT_PROP_L, INPUT_PULLUP);
    pinMode(POT_PROP_R, INPUT_PULLUP);
    pinMode(POT_MIX_L, INPUT_PULLUP);
    pinMode(POT_MIX_R, INPUT_PULLUP);
    
    pinMode(SW_THRTL, INPUT_PULLUP);
    pinMode(SW_PROP, INPUT_PULLUP);
    pinMode(SW_MIX, INPUT_PULLUP);
    
    /*pinMode(INT_1A, INPUT_PULLUP);
    pinMode(INT_1B, INPUT_PULLUP);
  
    attachInterrupt(INT_1A, rtc_pps_handler_1A, RISING);*/
  #endif

  #ifdef MODULE_SURFACES
    pinMode(POT_SPDBRK, INPUT_PULLUP);
    pinMode(POT_FLAPS, INPUT_PULLUP);
    
    pinMode(SW_BLOCK_1, INPUT_PULLUP);
  #endif
}

void loop() {
  #ifdef MODULE_THROTTLE
    if (digitalRead(SW_THRTL)) {
      Joystick.sliderLeft(analogRead(POT_THRTL_L));
      Joystick.sliderRight(analogRead(POT_THRTL_R));
    }
    
    if (digitalRead(SW_PROP)) {
      Joystick.X(analogRead(POT_PROP_L));
      Joystick.Y(analogRead(POT_PROP_R));
    }
    
    if (digitalRead(SW_MIX)) {
      Joystick.Z(analogRead(POT_MIX_L));
      Joystick.Zrotate(analogRead(POT_MIX_R));
    }

    Joystick.button(1, digitalRead(SW_THRTL));
    Joystick.button(2, digitalRead(SW_PROP));
    Joystick.button(3, digitalRead(SW_MIX));
  #endif

  #ifdef MODULE_SURFACES
    if (digitalRead(SW_BLOCK_1)) {
      Joystick.X(analogRead(POT_SPDBRK));
      Joystick.Y(analogRead(POT_FLAPS));
    }
  #endif
  
  delay(20);
  
  //Joystick.button(1, 0);
  //Joystick.button(2, 0);
}

/*void rtc_pps_handler_1A() {
  cli();

  if (digitalRead(INT_1B)) {
    Joystick.button(1, 1);
  }
}*/
