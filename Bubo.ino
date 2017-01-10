/* Bubo control
 * 
 * Coding starten on 01-01-2017
 * By M.Lauwerens
 */

#include <DFPlayer_Mini_Mp3.h>
#include <Adafruit_NeoPixel.h>
#include <Servo.h>

#define EyesLedAction 1
#define EyesRotAction 2
#define WingAction 3
#define NeckAction 4
#define LegsAction 5
#define Mpu6050Action 6

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
  init_neck();
  init_beak();
  //init_wings();
  //init_legs();
  init_mpu6050();
  delay(20000);
}

void loop() { 
   if (QueueChanged) {
    //Serial.print("QueueLength: ");
    //Serial.println(QueueLength);
    //DumpQueue();
    QueueChanged=false;
  }
  //do_eyes_led();
  //do_eyes_rot();
  //do_wings();
  //do_neck();
  //do_beak();
  //do_legs();
  //read_mpu6050();
  
  //rot_neck(read_neck());
  delay(500);
  //Serial.println(read_neck());
  for (int i=0;i < QueueLength;i++) {

    if (QueueTime[i] <= millis()) {
      int QModule = QueueModule[i];
      int QAction = QueueAction[i];
      int QData = QueueData[i];
      for (int j=i;j < QueueLength;j++) {
        QueueTime[j] = QueueTime[j+1];
        QueueModule[j] = QueueModule[j+1];
        QueueAction[j] = QueueAction[j+1];        
        QueueData[j] = QueueData[j+1];
      }
      QueueLength--;
      QueueChanged=true; 
      switch (QModule) {
        case 0:
          // do nothing for debugging
          break;
        case EyesLedAction:
          //do_eyes_led(QAction);
          break;
        case EyesRotAction:
          //do_eyes_rot(QAction);
          break;   
        case WingAction:
          //init_wings(QAction);
          break;
        case NeckAction:
          //do_neck(QAction);
          break;
        case LegsAction:  
          //do_legs(QAction,QData);
          break;
        case Mpu6050Action:
          //read_mpu6050(QAction,QData);
          break;
      }
      break;
    }
  }
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
