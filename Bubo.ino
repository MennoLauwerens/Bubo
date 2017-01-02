/* Bubo control
 * 
 * Coding starten on 01-01-2017
 * By M.Lauwerens
 */

#include <DFPlayer_Mini_Mp3.h>
#include <Adafruit_NeoPixel.h>
#include <Servo.h>

unsigned long QueueTime[MaxQueueLength];
int QueueModule[MaxQueueLength];
int QueueAction[MaxQueueLength];
int QueueData[MaxQueueLength];
int QueueLength = 0;
int QueueChanged = false;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
