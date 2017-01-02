#define LeftWingPin 5
#define RightWingPin 6

#define LeftMinPos 0
#define LeftMaxPos 90
#define RightMinPos 0
#define RightMaxPos 90

Servo ServoWingLeft;
Servo ServoWingRight;

void init_wings() {
  ServoWingLeft.attach(LeftWingPin);  
  ServoWingRight.attach(RightWingPin);
  ServoWingLeft.write(LeftMinPos);
  ServoWingRight.write(RightMinPos);
  //Queue(500,EarAction,0);
  //Queue(3000,EarAction,2);
}
