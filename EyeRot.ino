#define LeftEyeSpeed 3
#define LeftEyeDir 4
#define RightEyeSpeed 11
#define RightEyeDir 12

Servo MotorSpeedLeft;
Servo MotorSpeedRight;


void init_eyerot() {
  pinMode(LeftEyeDir, OUTPUT);
  pinMode(RightEyeDir, OUTPUT);
  digitalWrite(LeftEyeDir, LOW);
  digitalWrite(RightEyeDir, LOW);
  MotorSpeedLeft.attach(LeftEyeSpeed);
  MotorSpeedRight.attach(RightEyeSpeed);
}

