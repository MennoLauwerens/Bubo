#define LeftEyeSpeed 3
#define LeftEyeDir 4
#define RightEyeSpeed 11
#define RightEyeDir 12

//Servo MotorSpeedLeft;
//Servo MotorSpeedRight;


void init_eyerot() {
  pinMode(LeftEyeDir, OUTPUT);
  pinMode(RightEyeDir, OUTPUT);
  pinMode(LeftEyeSpeed, OUTPUT);
  pinMode(RightEyeSpeed, OUTPUT);
  
  digitalWrite(LeftEyeDir, HIGH);
  digitalWrite(RightEyeDir, HIGH);
  digitalWrite(LeftEyeSpeed, HIGH);
  digitalWrite(RightEyeSpeed, HIGH);
  //MotorSpeedLeft.attach(LeftEyeSpeed);
  //MotorSpeedRight.attach(RightEyeSpeed);
}

void do_eyes(){
  digitalWrite(LeftEyeDir, HIGH);
  digitalWrite(RightEyeDir, LOW);
  digitalWrite(LeftEyeSpeed, LOW);
  digitalWrite(RightEyeSpeed, LOW);
  Serial.println("LowLow");
  delay(1000);
  digitalWrite(LeftEyeDir, LOW);
  digitalWrite(RightEyeDir, HIGH);
  digitalWrite(LeftEyeSpeed, LOW);
  digitalWrite(RightEyeSpeed, LOW);
  Serial.println("HighLow");
  delay(1000);
  digitalWrite(LeftEyeDir, LOW);
  digitalWrite(RightEyeDir, LOW);
  digitalWrite(LeftEyeSpeed, HIGH);
  digitalWrite(RightEyeSpeed, LOW);
  Serial.println("LowLow");
  delay(1000);
  digitalWrite(LeftEyeDir, LOW);
  digitalWrite(RightEyeDir, LOW);
  digitalWrite(LeftEyeSpeed, LOW);
  digitalWrite(RightEyeSpeed, HIGH);
  digitalWrite(RightEyeSpeed, HIGH);
  Serial.println("LowHigh");
  
}

