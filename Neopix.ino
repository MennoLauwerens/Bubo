#define LedPin 7
#define LedCount 2
#define LedSpeed 80

Adafruit_NeoPixel EyePixels = Adafruit_NeoPixel(LedCount, LedPin, NEO_GRB + NEO_KHZ800);

void init_eyes() {
  EyePixels.begin();
  for(int i=0; i<= LedCount-1; i++) EyePixels.setPixelColor(i , 0);
  EyePixels.show();
  //Queue(2000,EyeAction,20);
}

