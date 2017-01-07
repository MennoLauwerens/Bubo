#define NeckPin 9

#define NeckMinPos 0
#define NeckNeutralPos 90
#define NeckMaxPos 90

Servo ServoNeck;

void init_neck() {
  ServoNeck.attach(NeckPin);  
  ServoNeck.write(NeckNeutralPos);
  delay(1000);
  ServoNeck.write(NeckNeutralPos-40);
  delay(1000);
  ServoNeck.write(NeckNeutralPos+40);
  delay(1000);
  ServoNeck.write(NeckNeutralPos);
  //Queue(500,EarAction,0);
  //Queue(3000,EarAction,2);
}

void do_neck(){
  ServoNeck.write(NeckNeutralPos+20);
  delay(2000); 
  ServoNeck.write(NeckNeutralPos-20);
  delay(2000);
}
