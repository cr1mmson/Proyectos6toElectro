
//Añadir librería
#include "SPIFFS.h"

//Función para listar archivos
void listarArchivos() {
  
  File root = SPIFFS.open("/"); //Se declara "/" como ubicación root

  //file será el archivo que le sigue en jerarquía a root
  File file = root.openNextFile(); 

  while (file) {
    Serial.print("Archivo: ");
    Serial.println(file.name()); //Imprime nombre de archivo 

    file = root.openNextFile();  //Pasa al siguiente archivo
  }
}

void setup() {

  Serial.begin(115200); //Inicia puerto serial

  //Iprimir mensaje de error al iniciar SPIFFS
  if (!SPIFFS.begin(true)) {
    Serial.println("Ocurrió un error al ejecutar SPIFFS.");
    return;
  }

  //Llama a la función para listar los archivos
  Serial.println("Listado de archivos:");
  listarArchivos();

}

void loop() {}
