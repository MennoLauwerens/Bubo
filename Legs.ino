#define LegPin 10

#define LegMinPos 2
#define LegNeutralPos 2
#define LegMaxPos 80

Servo ServoLegs;

void init_legs() {
  ServoLegs.attach(LegPin);  
  ServoLegs.write(LegNeutralPos);
  //delay(2000);
  //ServoLegs.write(LegMaxPos);
  //delay(2000);
  //ServoLegs.write(LegNeutralPos);
  //Queue(500,EarAction,0);
  //Queue(3000,EarAction,2);
}

void do_legs(){
  ServoLegs.write(LegNeutralPos+10);
}
