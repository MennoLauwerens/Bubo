#ifdef EyesLedAction
  #define LedPin 7
  #define LedSpeed 80
  #define LedMax 128
  
  Adafruit_NeoPixel EyePixels = Adafruit_NeoPixel(2, LedPin, NEO_GRB + NEO_KHZ800);
  
  void init_eyes_led() {
    #ifdef Debug
      Serial.print("Init Neopixels");
    #endif
    EyePixels.begin();
    for(int i=0; i<LedMax;i++){
      set_eyes(1,1,i,i,i);
      delay(5);
    }
    Queue(1000,EyesLedAction,3);
    #ifdef Debug
      Serial.println(" - Done.");
    #endif;
  }
  
  void do_eyes_led(int action, int actiondata){
    #ifdef Debug
      Serial.print("EyesLedAction: ");
      Serial.println(action);
    #endif
    int effect;
    unsigned long myDelay;
    switch (action) {
      case 0: // off
        set_eyes(1,1,0,0,0);
        break;
      case 1: // on
        //
        break;
      case 2: // reschedule
        myDelay = 3000 + random(18000);
        effect = 10 + random(2);
        Queue(myDelay,EyesLedAction,effect,0);
        break;
      case 3: // fade to red then goto reschedule
        set_eyes(1,1,actiondata,0,0);
        if (++actiondata < LedMax) {
          Queue(50,EyesLedAction,3,actiondata);
        } else {
          Queue(50,EyesLedAction,2);
        }
        break;
      case 10: // strobe blue
        if (actiondata == 0) {actiondata = random(200);}
        if (actiondata % 2){
          set_eyes(1,1,0,0,255);
        } else {
          set_eyes(1,1,0,0,0);
        }
        if (--actiondata < 1){
          set_eyes(1,1,0,0,0);
          Queue(50,EyesLedAction,3);
        } else {
          Queue(50,EyesLedAction,10,actiondata);
        }
        break;
      case 11: // blink right full red
        if (actiondata++ == 0) {
          set_eyes(1,0,0,0,0);
          Queue(500,EyesLedAction,11,actiondata);
        } else {
          set_eyes(1,0,LedMax,0,0);
          Queue(50,EyesLedAction,2);
        }
    }
  }

  void set_eyes(int Li,int Re,int R, int G, int B){
      if (Li == 1) {EyePixels.setPixelColor(0 , EyePixels.Color(R,G,B));}
      if (Re == 1) {EyePixels.setPixelColor(1 , EyePixels.Color(R,G,B));}
      EyePixels.show();
  }
#endif
