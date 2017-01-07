#define LedPin 7
#define LedSpeed 80

Adafruit_NeoPixel EyePixels = Adafruit_NeoPixel(2, LedPin, NEO_GRB + NEO_KHZ800);

void init_eyes_led() {
  EyePixels.begin();
  for(int i=0; i<255;i++){
    EyePixels.setPixelColor(0 , EyePixels.Color(0,0,i));
    EyePixels.setPixelColor(1 , EyePixels.Color(0,0,i));
    EyePixels.show();
    delay(5);
  }
  //for(int i=0; i<= LedCount-1; i++) EyePixels.setPixelColor(i , 0);
  //EyePixels.show();
  //Queue(2000,EyeAction,20);
}

void do_eyes_led(){
  EyePixels.setPixelColor(0 , EyePixels.Color(255,255,255));
  EyePixels.setPixelColor(1 , EyePixels.Color(0,255,0));
  EyePixels.show();
  Serial.println("1");
  delay(1000);
  EyePixels.setPixelColor(0 , EyePixels.Color(255,0,0));
  EyePixels.setPixelColor(1 , EyePixels.Color(0,0,255));
  EyePixels.show();
  Serial.println("2");
  delay(1000);
}
