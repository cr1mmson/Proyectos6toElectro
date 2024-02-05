#include "AdafruitIO_WiFi.h"
#include <Wire.h>
#include <SPI.h>
#include <analogWrite.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> 
#endif

#define PIN        4
#define NUMPIXELS 16
 

int por;

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define IO_USERNAME  "crimm"
#define IO_KEY       "aio_Fqya87IEbwK9NN9gkyzJ1n2Pz9an"

#define WIFI_SSID      "TIGO-E643"
#define WIFI_PASS      "F@m1l1@V1c3nt3"

const int ap = 34;

AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);


AdafruitIO_Feed *gas = io.feed("ac");



void setup() {

#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
   clock_prescale_set(clock_div_1);
#endif
 Serial.begin(115200);
pixels.begin();

Serial.print("Connecting to Adafruit IO");
        io.connect();
    while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.println(io.statusText());

}

void loop() {

 io.run();
 

air();

if(por>=600 && por<=750){
 pixels.clear();
 pixels.setPixelColor(0, pixels.Color(51,255,181));
 pixels.setPixelColor(1, pixels.Color(51,255,181));
 pixels.setPixelColor(2, pixels.Color(51,255,181));
 pixels.setPixelColor(3, pixels.Color(51,255,181));
 pixels.show();
 }

if(por>=800 && por<=950){
 pixels.clear();
 pixels.setPixelColor(0, pixels.Color(0,150,0));
 pixels.setPixelColor(1, pixels.Color(0,150,0));
 pixels.setPixelColor(2, pixels.Color(0,150,0));
 pixels.setPixelColor(3, pixels.Color(0,150,0));
 pixels.setPixelColor(4, pixels.Color(0,150,0));
 pixels.setPixelColor(5, pixels.Color(0,150,0));
 pixels.setPixelColor(6, pixels.Color(0,150,0));
 pixels.show();
}

if(por>=1000 && por<=1250){
 pixels.clear();
 pixels.setPixelColor(0, pixels.Color(255,40,2));
 pixels.setPixelColor(1, pixels.Color(255,40,2));
 pixels.setPixelColor(2, pixels.Color(255,40,2));
 pixels.setPixelColor(3, pixels.Color(255,40,2));
 pixels.setPixelColor(4, pixels.Color(255,40,2));
 pixels.setPixelColor(5, pixels.Color(255,40,2));
 pixels.setPixelColor(6, pixels.Color(255,40,2));
 pixels.setPixelColor(7, pixels.Color(255,40,2));
 pixels.setPixelColor(8, pixels.Color(255,40,2));
 pixels.setPixelColor(9, pixels.Color(255,40,2));
 pixels.setPixelColor(10, pixels.Color(255,40,2));
 pixels.setPixelColor(11, pixels.Color(255,40,2));
 pixels.setPixelColor(12, pixels.Color(255,40,2));
 pixels.show();
}


if(por>=1300 && por<=1550){
 pixels.clear();
 pixels.setPixelColor(0, pixels.Color(150,0,0));
 pixels.setPixelColor(1, pixels.Color(150,0,0));
 pixels.setPixelColor(2, pixels.Color(150,0,0));
 pixels.setPixelColor(3, pixels.Color(150,0,0));
 pixels.setPixelColor(4, pixels.Color(150,0,0));
 pixels.setPixelColor(5, pixels.Color(150,0,0));
 pixels.setPixelColor(6, pixels.Color(150,0,0));
 pixels.setPixelColor(7, pixels.Color(150,0,0));
 pixels.setPixelColor(8, pixels.Color(150,0,0));
 pixels.setPixelColor(9, pixels.Color(150,0,0));
 pixels.setPixelColor(10, pixels.Color(150,0,0));
 pixels.setPixelColor(11, pixels.Color(150,0,0));
 pixels.setPixelColor(12, pixels.Color(150,0,0));
 pixels.setPixelColor(13, pixels.Color(150,0,0));
 pixels.setPixelColor(14, pixels.Color(150,0,0));
 pixels.setPixelColor(15, pixels.Color(150,0,0));
 pixels.setPixelColor(16, pixels.Color(150,0,0));
 pixels.show();
}

 
}

void air(){
por=analogRead(ap);
Serial.println(por);
gas->save(por);
}
