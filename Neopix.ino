#ifdef EyesLedAction
  #define LedPin 7
  #define LedSpeed 80
  
  Adafruit_NeoPixel EyePixels = Adafruit_NeoPixel(2, LedPin, NEO_GRB + NEO_KHZ800);
  
  void init_eyes_led() {
    #ifdef Debug
      Serial.print("Init Neopixels");
    #endif
    EyePixels.begin();
    for(int i=0; i<255;i++){
      set_eyes(0,0,i);
      delay(5);
    }
    Queue(1000,EyesLedAction,2);
    #ifdef Debug
      Serial.println(" - Done.");
    #endif;
  }
  
  void do_eyes_led(int action, int actiondata){
    #ifdef Debug
      Serial.print("EyesLedAction: ");
      Serial.println(action);
    #endif
    switch (action) {
      case 0: // off
        set_eyes(0,0,0);
        break;
      case 1: // on
        //
        break;
      case 2: // reschedule
        //int myDelay = 30000 + random(180000);
        //Queue(myDelay,EyesLedAction,1);
        //myDelay += random(5000);
        //Queue(myDelay,EyesLedAction,0);
        //Queue(myDelay + 1,EyesLedAction,2);
        Queue(1000,EyesLedAction,3,100);
        break;
       case 3: // strobe red
        if (actiondata % 2){
          set_eyes(255,0,0);
        } else {
          set_eyes(0,0,0);
        }
        if (--actiondata < 1){
          set_eyes(0,0,0);
          Queue(1000,EyesLedAction,2);
        } else {
          Queue(50,EyesLedAction,3,actiondata);
        }
        
    }
  }

  void set_eyes(int R, int G, int B){
      EyePixels.setPixelColor(0 , EyePixels.Color(R,G,B));
      EyePixels.setPixelColor(1 , EyePixels.Color(R,G,B));
      EyePixels.show();
  }
#endif
