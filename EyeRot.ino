#define LeftEyeSpeed 3
#define LeftEyeDir 4
#define RightEyeSpeed 11
#define RightEyeDir 12

//Servo MotorSpeedLeft;
//Servo MotorSpeedRight;


void init_eyes_rot() {
  pinMode(LeftEyeDir, OUTPUT);
  pinMode(RightEyeDir, OUTPUT);
  pinMode(LeftEyeSpeed, OUTPUT);
  pinMode(RightEyeSpeed, OUTPUT);
  delay(10);
  digitalWrite(LeftEyeDir, LOW);
  digitalWrite(RightEyeDir, HIGH);
  digitalWrite(LeftEyeSpeed, HIGH);
  digitalWrite(RightEyeSpeed, LOW);
  delay(1000);
  digitalWrite(LeftEyeDir, HIGH);
  digitalWrite(RightEyeDir, LOW);
  digitalWrite(LeftEyeSpeed, LOW);
  digitalWrite(RightEyeSpeed, HIGH);
  delay(1000);
  digitalWrite(LeftEyeDir, LOW);
  digitalWrite(RightEyeDir, LOW);
  digitalWrite(LeftEyeSpeed, LOW);
  digitalWrite(RightEyeSpeed, LOW);
  
  //MotorSpeedLeft.attach(LeftEyeSpeed);
  //MotorSpeedRight.attach(RightEyeSpeed);
}

void do_eyes_rot(){
  digitalWrite(LeftEyeDir, HIGH);
  digitalWrite(RightEyeDir, LOW);
  digitalWrite(LeftEyeSpeed, LOW);
  digitalWrite(RightEyeSpeed, LOW);
  Serial.println("1");
  delay(1000);
  digitalWrite(LeftEyeDir, LOW);
  digitalWrite(RightEyeDir, HIGH);
  digitalWrite(LeftEyeSpeed, LOW);
  digitalWrite(RightEyeSpeed, LOW);
  Serial.println("2");
  delay(1000);
  digitalWrite(LeftEyeDir, LOW);
  digitalWrite(RightEyeDir, LOW);
  digitalWrite(LeftEyeSpeed, HIGH);
  digitalWrite(RightEyeSpeed, LOW);
  Serial.println("3");
  delay(1000);
  digitalWrite(LeftEyeDir, LOW);
  digitalWrite(RightEyeDir, LOW);
  digitalWrite(LeftEyeSpeed, LOW);
  digitalWrite(RightEyeSpeed, HIGH);
  Serial.println("4");
  
}

