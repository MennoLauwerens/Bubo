#ifdef EyesRotAction
  #define LeftEyeCW 3
  #define LeftEyeCCW 4
  #define RightEyeCW 11
  #define RightEyeCCW 12
  
  void init_eyes_rot() {
    #ifdef Debug
      Serial.print("Init eye motors");
    #endif
    pinMode(LeftEyeCCW, OUTPUT);
    pinMode(RightEyeCCW, OUTPUT);
    pinMode(LeftEyeCW, OUTPUT);
    pinMode(RightEyeCW, OUTPUT);
    delay(10);
    digitalWrite(LeftEyeCCW, LOW);
    digitalWrite(RightEyeCCW, HIGH);
    digitalWrite(LeftEyeCW, HIGH);
    digitalWrite(RightEyeCW, LOW);
    delay(1000);
    digitalWrite(LeftEyeCCW, HIGH);
    digitalWrite(RightEyeCCW, LOW);
    digitalWrite(LeftEyeCW, LOW);
    digitalWrite(RightEyeCW, HIGH);
    delay(1000);
    digitalWrite(LeftEyeCCW, LOW);
    digitalWrite(RightEyeCCW, LOW);
    digitalWrite(LeftEyeCW, LOW);
    digitalWrite(RightEyeCW, LOW);
    Queue(2333,EyesRotAction,10);
    #ifdef Debug
      Serial.println(" - Done.");
    #endif
  }
  
  
  
  void do_eyes_rot(int action, int actiondata){
      Serial.print("EyesRotAction: ");
      Serial.println(action);
      switch (action) {
      case 0: // stop
        digitalWrite(LeftEyeCCW, LOW);
        digitalWrite(RightEyeCCW, LOW);
        digitalWrite(LeftEyeCW, LOW);
        digitalWrite(RightEyeCW, LOW);
        break;
      case 1: // left CW
         digitalWrite(LeftEyeCCW, LOW);
         digitalWrite(LeftEyeCW, HIGH);
        break;
      case 2: // left CCW
         digitalWrite(LeftEyeCCW, HIGH);
         digitalWrite(LeftEyeCW, LOW);
        break;
      case 3: // right CW
         digitalWrite(RightEyeCCW, LOW);
         digitalWrite(RightEyeCW, HIGH);
        break;
      case 4: // right CCW
         digitalWrite(RightEyeCCW, HIGH);
         digitalWrite(RightEyeCW, LOW);
        break;
      case 10: // Schedule eyerotmove
        random_eye_move();
        break;
      }
  }
  
  void random_eye_move(){
     unsigned long eyemovedelay = 30000 + (random(10) * 10000);
     int eyemoveduration = 2000 + random(5000);
     int eyemovetype = random(9);
     switch (eyemovetype) { 
      case 0:
        Queue(eyemovedelay,EyesRotAction,1);
        break;
      case 1:
        Queue(eyemovedelay,EyesRotAction,2);
        break;
      case 2:
        Queue(eyemovedelay,EyesRotAction,3);
        break;
      case 3:
        Queue(eyemovedelay,EyesRotAction,4);
        break;
      case 4:
        Queue(eyemovedelay,EyesRotAction,5);
        break;
      case 5:
        Queue(eyemovedelay,EyesRotAction,1);
        Queue(eyemovedelay,EyesRotAction,3);
        break;
      case 6:
        Queue(eyemovedelay,EyesRotAction,1);
        Queue(eyemovedelay,EyesRotAction,4);
        break;
      case 7:
        Queue(eyemovedelay,EyesRotAction,2);
        Queue(eyemovedelay,EyesRotAction,3);
        break;
      case 8:
        Queue(eyemovedelay,EyesRotAction,2);
        Queue(eyemovedelay,EyesRotAction,4);
        break;
     }
     Queue(eyemovedelay+eyemoveduration,EyesRotAction,0);
     Queue(eyemovedelay+eyemoveduration,EyesRotAction,10);
  }
  

#endif
