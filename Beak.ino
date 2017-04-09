#ifdef BeakAction
  #define BeakPin 8
  
  void init_beak() {
    #ifdef Debug
      Serial.print("Init beak");
    #endif
    pinMode(BeakPin, OUTPUT);
    digitalWrite(BeakPin, HIGH);
    delay(1000);
    digitalWrite(BeakPin, LOW);
    Queue(2001,BeakAction,2);
    #ifdef Debug
      Serial.println(" - Done.");
    #endif
  }

  void do_beak(int action, int actiondata){
    #ifdef Debug
      Serial.print("BeakAction: ");
      Serial.println(action);
    #endif
    switch (action) {
      case 0: // close
        digitalWrite(BeakPin, LOW);
        break;
      case 1: // open
        digitalWrite(BeakPin, HIGH);
        break;
      case 2: // reschedule
        unsigned long myDelay = 30000 + random(180000);
        Queue(myDelay,BeakAction,1);
        myDelay += random(5000);
        Queue(myDelay,BeakAction,0);
        Queue(myDelay + 1,BeakAction,2);
    }
  }
#endif
