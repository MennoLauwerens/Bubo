/* Bubo control
 * 
 * Coding starten on 01-01-2017
 * By M.Lauwerens
 */

#include <DFPlayer_Mini_Mp3.h>
#include <Adafruit_NeoPixel.h>
#include <Servo.h>

#define MaxQueueLength 25
unsigned long QueueTime[MaxQueueLength];
int QueueModule[MaxQueueLength];
int QueueAction[MaxQueueLength];
int QueueData[MaxQueueLength];
int QueueLength = 0;
int QueueChanged = false;

void setup() {
  Serial.begin(115200);
  init_eyes();
  init_wings();
  //init_mpu6050();
  init_eyerot();
  init_legs();
}

void loop() {
  //read_mpu6050();
  do_eyes_rot();
  do_eyes_led();
  do_neck();
  do_wings();
  do_legs();
}

// Add event to comandqueue
void Queue(int delayms, int module, int action,int data = 0) {
  QueueTime[QueueLength] = millis() + delayms;
  QueueModule[QueueLength] = module;
  QueueAction[QueueLength] = action;
  QueueData[QueueLength] = data;
  QueueLength++;
  QueueChanged=true;
}
