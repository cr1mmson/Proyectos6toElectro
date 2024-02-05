#include "AdafruitIO_WiFi.h"

#define IO_USERNAME  "USER"
#define IO_KEY       "KEY"

#define WIFI_SSID      "SSID"
#define WIFI_PASS      "Password"

AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);

AdafruitIO_Feed *gas = io.feed("ac");

int ap=16;

void setup() {
  Serial.begin(115200);
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
  envio_datos();
}

void envio_datos(){
float por=digitalRead(ap);
Serial.println(por);
gas->save(por);
}
