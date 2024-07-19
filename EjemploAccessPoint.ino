#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "X";
const char* password = "098765";

IPAddress ip(192,168,4,22);
IPAddress gateway(192,168,4,2);
IPAddress subnet(255,255,255,0);

WebServer server(80);

void setup() {

  Serial.begin(115200);

  WiFi.softAP(ssid,password);
  WiFi.softAPConfig(ip, gateway, subnet);

  Serial.println("SSID: " + String(ssid));

  server.on("/", handleConnectionRoot);

  server.begin();
  Serial.print("SERVIDOR INICIADO");
  delay(150);
}

void loop() {
  server.handleClient();
}

String respuesta = "<!DOCTYPE html>\
<html>\
<body>\
<h1>EJEMPLO ESP32 AP </h1>\
</body>\
</html>";

void handleConnectionRoot(){

  server.send(200, "text/html", respuesta);
}
