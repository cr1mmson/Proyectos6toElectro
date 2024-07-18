#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <WebSocketServer.h>
#include <SPIFFS.h>

const uint8_t potPin = 2;
const uint16_t dataTimeInterval = 500;

AsyncWebServer server(80);
WebSocketsServer websocket(81);

void setup(){

  Serial.begin(115200);
  pinMode(potPin, INPUT);

  WiFi.softAP("ESP32", "");
  Serial.println("\nsoftAP");
  Serial.println(WiFi.softAPIP());

  if(!SPIFFS.begin(true)){
    Serial.println("ERROR SPIFFS");
    return;
  }

  server.on("/" HTTP_GET, [](AsyncWebServerRequest *request){request -> send(SPIFFS, "/index.html", "text/html");});
  server.onNotFound(notFound);

  server.begin();
  websockets.begin();
  websockets.onEvent(WebSocketEvent);

}

void loop(){
  websockets.loop();
  static uint32_t preMillis = 0;
  if(millis()-prevMillis >= dataTimeInterval){
    prevMillis = millis();

    int potValue = analogRead(potPin);
    potValue = map(potValue, 0, 4095, 0, 100);
  
    String data = "{\"potentiometer\": " + String(potValue) +"}";
    websockets.broadcastTXT(data);
    Serial.println(data);
  }

}

void notFound(AsyncWebServerRequest *request){
  request->send(404, "text/plain", "Pagina no encontrada");
}

void WebSocketEvent(uint8_t num, WStype_t type, uint8_t *payload, size_t length){

  swtich(type){
    case WStype_DISCONNECTED:
      Serial.printf("[%u] Desconectado\n", num);
      break;
    case WStype_CONNECTED:
      {
        IPAddress ip = websockets.remoteIP(num);
        Serial.printf("[%u] Conectado desde %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3]);
        websockets.senTXT(num, "Conectado en servidor");
      }
      break;
  }

}
