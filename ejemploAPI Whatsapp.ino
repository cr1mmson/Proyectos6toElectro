#include <WiFi.h>
#include <HTTPClient.h>


const char* SSID = "";
const char* PASSWORD = "";

String phoneNumber = "";
String apiKey = "";



void setup() {
  Serial.begin(115200);
  WiFi.begin(SSID, PASSWORD);
  Serial.println("CONNECTING");

  while(WiFi.status() != WL_CONNECTED){
    delay(50);
    Serial.println(".");
  }

  Serial.println("");
  Serial.println("Connected to ");
  Serial.println(WiFi.localIP());
}

void loop() {
 envioMensaje("EJEMPLO%201%20TEXTO");
  delay(3000);
}


void envioMensaje(String message){

  String url = "https://api.callmebot.com/whatsapp.php?phone=" + phoneNumber + "&text=" + message + "&apikey=" + apiKey;

  HTTPClient http;

  http.begin(url);

  http.addHeader("Content-Type", "application/x-www-form-urlencoded");  

  int httpResponseCode = http.POST(url);

  if(httpResponseCode==200){
    Serial.println("SE ENVIO EL MENSAJE");
  }

  else{
    Serial.println("ERROR AL ENVIAR EL MENSAJE");
    Serial.println(httpResponseCode);
  }
  http.end();
}
