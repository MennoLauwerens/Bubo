#ifdef SoundAction

  void init_Sound () {
          Serial.begin (9600);
          while (!Serial);
          mp3_set_serial (Serial); 
          delay(1);
          mp3_set_volume (30);
          delay(1);
          mp3_play (1);
          Queue(1000,SoundAction,3);
  }

  void do_sound(int action, int actiondata){
    switch (action) {
      case 0: // Silent
        mp3_set_volume (0);
        break;
      case 1: // Full volume
        mp3_set_volume (30);
        break;
      case 2: // Play sound
        mp3_play (actiondata);
      case 3: // reschedule
        unsigned long myDelay = 3000 + random(18000);
        Queue(myDelay,SoundAction,2,random(10) + 1);
    }
  }




#endif
