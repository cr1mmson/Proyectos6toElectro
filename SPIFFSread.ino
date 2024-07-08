//Añadir librería
#include "SPIFFS.h"

void setup() {
  //Iniciar puerto serial
  Serial.begin(115200);

  //Iprimir mensaje de error al iniciar SPIFFS
  if (!SPIFFS.begin(true)) {
    Serial.println("Ocurrió un error al ejecutar SPIFFS.");
    return;
  }

  //Abre el archivo que se subió desde la carpeta "data"
  File file = SPIFFS.open("/ejemplo.txt");

  //Mensaje de fallo al leer el contenido
  if (!file) {
    Serial.println("Error al abrir el archivo.");
    return;
  }

  //Imprimir contenido del archivo en el monitor serial
  Serial.println("Contenido:");
  while (file.available()) {
  Serial.write(file.read());
  }
  //Detiene el proceso
  file.close();
}

void loop() {

}
