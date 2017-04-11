#ifdef WatchdogAction
  void init_watchdog() {
    #ifdef Debug
      Serial.print("Init watchdog");
    #endif
    int countdownMS = Watchdog.enable(4000);
    Queue(3000,WatchdogAction,1);
    #ifdef Debug
      Serial.println(" - Done.");
    #endif;
  }
  
  void ResetWatchdog() {
    Watchdog.reset();
    Queue(3000,WatchdogAction,1);
  }
#endif
