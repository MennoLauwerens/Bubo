#define LedPin 7
#define LedCount 2
#define LedSpeed 80

Adafruit_NeoPixel EyePixels = Adafruit_NeoPixel(LedCount, LedPin, NEO_GRB + NEO_KHZ800);

void init_eyes_led() {
  EyePixels.begin();
  for(int i=0; i<= LedCount-1; i++) EyePixels.setPixelColor(i , 0);
  EyePixels.show();
  //Queue(2000,EyeAction,20);
}

void do_eyes_led(){
  EyePixels.setPixelColor(0 , 255 , 0   , 0);
  EyePixels.setPixelColor(1 , 0   , 255 , 0);
  EyePixels.show();
}
