#ifdef LegsAction
  #define LegPin 10
  
  #define LegMinPos 2
  #define LegNeutralPos 160
  #define LegMaxPos 70
  
  Servo ServoLegs;
  
  void init_legs(){
    #ifdef Debug
      Serial.print("Init legs");
    #endif
    ServoLegs.attach(LegPin);  
    ServoLegs.write(LegNeutralPos);
    delay(2000);
    ServoLegs.write(LegMaxPos);
    delay(2000);
    ServoLegs.write(LegNeutralPos);
    delay(1000);
    ServoLegs.detach();
    Queue(1000,LegsAction,2);
    #ifdef Debug
      Serial.println(" - Done.");
    #endif
  }
  
  void do_legs(int action, int actiondata){
    #ifdef Debug
      Serial.print("LegsAction: ");
      Serial.print(action);
      Serial.print(",");
      Serial.println(actiondata);
    #endif
    unsigned long myDelay1;
    unsigned long myDelay2;
    switch (action) {
      case 0: // detach
        ServoLegs.detach();
        break;
      case 1: // attach
        ServoLegs.attach(LegPin);
        break;
      case 2: // reschedule
        myDelay1 = 3000 + random(18000); //30000 + random(180000); // 30sec - 3.5 minuut
        myDelay2 = myDelay1 + 500 + random(30000);
        Serial.println( myDelay1);
        Serial.println( myDelay2);
        Queue(myDelay1,LegsAction,1); // Attach
        Queue(myDelay1+500,LegsAction,3,LegMaxPos + random(60)); // Bend over
        Queue(myDelay2,LegsAction,3,LegNeutralPos); // Move back
        Queue(myDelay2+1000,LegsAction,0); // detach
        Queue(myDelay2+1500,LegsAction,2); // reschedule
        break;
      case 3: // move
        ServoLegs.write(actiondata);
        break;
    }
  }
#endif
