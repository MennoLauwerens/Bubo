#define NeckPin 9

#define NeckMinPos 0
#define NeckNeutralPos 90
#define NeckMaxPos 180

Servo ServoNeck;

int neckpos;
int rotbuffer;

void init_neck() {
  ServoNeck.attach(NeckPin);  
  ServoNeck.write(NeckNeutralPos);
  delay(1000);
  ServoNeck.write(NeckNeutralPos-40);
  delay(1000);
  ServoNeck.write(NeckNeutralPos+40);
  delay(1000);
  ServoNeck.write(NeckNeutralPos);
  neckpos=NeckNeutralPos;

  Queue(2000,NeckAction,10);
}

void do_neck(int action, int actiondata){
    Serial.print("NeckAction: ");
    Serial.println(action);
    switch (action) {
    case 0: // detach
      ServoNeck.detach();
      break;
    case 1: // attach
      ServoNeck.attach(NeckPin);
      break;
    case 2: // absolute move
       ServoNeck.write(actiondata);
       neckpos=actiondata;
       break;
    case 10: //Schedule new random move
      random_neck_move();
      break;
    }
}

void random_neck_move(){
  int moveangle = 20 - random(40);
  int newpos = neckpos + moveangle;
  if (newpos>180 || newpos<0){newpos = neckpos - moveangle;}
  int movespeed = 1; //20 * random(5);
  int movedir;
  int tmpdelay = movespeed;
  if(neckpos<newpos){movedir=1;}else{movedir=-1;}
  for(int i=neckpos;i!=newpos;i+=movedir){
    Queue(tmpdelay,NeckAction,2,i);
    tmpdelay += movespeed;
  }
  Queue(tmpdelay+2000,NeckAction,10,0);
  Serial.println("random  move scheduled!");
}

void rot_neck(int rot){
  rotbuffer+=rot;
  //Serial.print("rot_nek: rot=");
  //Serial.print(rot);
  //Serial.print("  rotbuffer=");
  //Serial.println(rotbuffer);
  if((rotbuffer)<15 || (rotbuffer)>15){
    neckpos+=rotbuffer;
    rotbuffer=0;
    if (neckpos>NeckMaxPos) {neckpos=NeckNeutralPos;}
    if (neckpos<NeckMinPos) {neckpos=NeckNeutralPos;}
    ServoNeck.write(neckpos);
  }
}

// Init left-right-center
// - Random reposition differens speeds
// - Gyro lock on/off
