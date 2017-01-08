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
  wing(2,90);

  
  //Queue(500,EarAction,0);
  //Queue(3000,EarAction,2);
}

void do_wings(){
  wing(2 ,90);
  Serial.println("Max");
  delay(2000); 
  wing(2,0); 
  Serial.println("Min");
  delay(2000);
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

