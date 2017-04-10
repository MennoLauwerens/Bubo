#ifdef WingAction
  #define LeftWingPin 5
  #define RightWingPin 6
  
  #define LeftMinPos 0
  #define LeftMaxPos 90
  #define RightMinPos 0
  #define RightMaxPos 90
  #define WingMaxPos 0
  #define WingMinPos 90
  
  Servo ServoWingLeft;
  Servo ServoWingRight;
  
  void init_wings() {
    #ifdef Debug
      Serial.print("Init wings");
    #endif
    ServoWingLeft.attach(LeftWingPin);  
    ServoWingRight.attach(RightWingPin);
    wing(2,90);
    delay(750);
    wing(0,0);
    delay(750);
    wing(0,90);
    delay(750);
    wing(1,0);
    delay(750);
    wing(1,90);
    delay(1000);
    wing(2,0);
    delay(250);
    wing(2,90);
    delay(250);
    wing(2,0);
    delay(250);
    wing(2,80);
    Queue(500,WingAction,0);
    Queue(1000,WingAction,2);
    #ifdef Debug
      Serial.println(" - Done.");
    #endif
  }
  
  void do_wings(int action, int actiondata){
    #ifdef Debug
      Serial.print("WingAction: ");
      Serial.println(action);
    #endif

    int effect;
    unsigned long myDelay;
    switch (action) {
      case 0: // detach
        ServoWingLeft.detach();
        ServoWingRight.detach();
        break;
      case 1: // attach
        ServoWingLeft.attach(LeftWingPin);  
        ServoWingRight.attach(RightWingPin);
        break;
      case 2: // reschedule
        myDelay = 3000 + random(18000);
        effect = 10 + random(3);
        Queue(myDelay,WingAction,1);
        Queue(myDelay+50,WingAction,effect,3 + random(9));
        //myDelay += random(5000);
        //Queue(myDelay,EyesLedAction,0);
        //Queue(myDelay + 1,EyesLedAction,2);
        break;
      case 10: // flap left , count
      case 11: // flap right, count
      case 12: // flap both, count
        if (--actiondata > 0)
          if (actiondata % 2){
            wing(action-10,WingMinPos);
          } else {
            wing(action-10,WingMaxPos);
          }
          if (actiondata==0){
            Queue(500,WingAction,0);
            Queue(501,WingAction,2);
          } else {
            Queue(250,WingAction,action,actiondata);
          }
          break;
      //case 11: // flap right, count
      //case 12: // flap both, count
    }
  }
  
  //Pos 0-100 gr 0=folded
  void wing(int WingID,int Pos){
    if (WingID==0 || WingID==2){
      ServoWingLeft.write(180-Pos);
    } 
    if (WingID==1 || WingID==2){
      ServoWingRight.write(Pos);
    } 
  }
#endif
