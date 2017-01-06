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
  init_eyes_led();
  init_eyes_rot();
  init_wings();
  init_neck();
  init_legs();
  //init_mpu6050();
}

void loop() { 
  do_eyes_led();
  do_eyes_rot();
  do_wings();
  do_neck();
  do_legs();
  //read_mpu6050();
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
