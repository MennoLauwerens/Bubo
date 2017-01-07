#define BeakPin 8

void init_beak() {
  pinMode(BeakPin, OUTPUT);
  digitalWrite(BeakPin, HIGH);
  delay(1000);
  digitalWrite(BeakPin, LOW);
  //Queue(500,EarAction,0);
  //Queue(3000,EarAction,2);
}

void do_beak(){
  digitalWrite(BeakPin, HIGH);
  delay(1000);
  digitalWrite(BeakPin, LOW);
  delay(1000);
}
