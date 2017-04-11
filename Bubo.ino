
/* Bubo control
 * 
 * Coding starten on 01-01-2017
 * By M.Lauwerens
 */
#include <Adafruit_SleepyDog.h>
#include <DFPlayer_Mini_Mp3.h>
#include <Adafruit_NeoPixel.h>
#include <Servo.h>

//#define Debug

#define EyesLedAction 1
#define EyesRotAction 2
#define WingAction 3
#define NeckAction 4
#define LegsAction 5
#define Mpu6050Action 6
#define BeakAction 7
//#define WxatchdogAction 8

#define MaxQueueLength 100
unsigned long QueueTime[MaxQueueLength];
byte QueueModule[MaxQueueLength];
byte QueueAction[MaxQueueLength];
byte QueueData[MaxQueueLength];
int QueueLength = 0;
int QueueChanged = false;

void setup() {
  Serial.begin(115200);
  #ifdef Debug
    Serial.println("Bubo initialisation started.");
  #endif
  #ifdef EyesLedAction
    init_eyes_led();
  #endif
  #ifdef EyesRotAction
    init_eyes_rot();
  #endif
  #ifdef NeckAction
    init_neck();
  #endif
  #ifdef BeakAction
    init_beak();
  #endif
  #ifdef WingAction
    init_wings();
  #endif
  #ifdef LegsAction
    init_legs();
  #endif
  #ifdef Mpu6050Action
    init_mpu6050();
  #endif
  #ifdef WatchdogAction
    init_watchdog();
  #endif
  #ifdef Debug
    Serial.println("Initialisation Finished.");
  #endif
}

void loop() { 
   #ifdef Debug
     if (QueueChanged) {
      Serial.print("QueueLength: ");
      Serial.println(QueueLength);
      DumpQueue();
      QueueChanged=false;
    }
  #endif
  //delay(500);
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
        #ifdef EyesLedAction
          case EyesLedAction:
            do_eyes_led(QAction,QData);
            break;
        #endif
        #ifdef EyesRotAction
          case EyesRotAction:
            do_eyes_rot(QAction,QData);
            break;   
        #endif
        #ifdef WingAction
          case WingAction:
            do_wings(QAction,QData);
            break;
        #endif
        #ifdef NeckAction
          case NeckAction:
            do_neck(QAction,QData);
            break;
        #endif
        #ifdef LegsAction
          case LegsAction:  
            do_legs(QAction,QData);
            break;
        #endif
        #ifdef Mpu6050Action
        case Mpu6050Action:
            do_Mpu6050(QAction,QData);
            break;
        #endif
        #ifdef BeakAction
          case BeakAction:
            do_beak(QAction,QData);
            break;
        #endif
        #ifdef WatchdogAction
          case WatchdogAction:
            ResetWatchdog();
            break;
        #endif
      }
      break;
    }
  }
}

// Add event to comandqueue
void Queue(unsigned delayms, int module, int action,int data = 0) {
  QueueTime[QueueLength] = millis() + delayms;
  QueueModule[QueueLength] = module;
  QueueAction[QueueLength] = action;
  QueueData[QueueLength] = data;
  QueueLength++;
  QueueChanged=true;
}

void DumpQueue(){    
  Serial.println("DumpQueue:");
  for (int i=0;i < QueueLength;i++){
    Serial.print(i);
    Serial.print(" - ");
    Serial.print(QueueTime[i]);
    Serial.print(" - ");
    Serial.print(QueueModule[i]);
    Serial.print(" - ");
    Serial.print(QueueAction[i]);
    Serial.print(" - ");
    Serial.print(QueueData[i]);
    Serial.println(".");
  }
}
