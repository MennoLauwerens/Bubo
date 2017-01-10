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
  //Queue(500,EarAction,0);
  //Queue(3000,EarAction,2);
}

void do_neck(){
  ServoNeck.write(NeckNeutralPos+20);
  delay(2000); 
  ServoNeck.write(NeckNeutralPos-20);
  delay(2000);
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

