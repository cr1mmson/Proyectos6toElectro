
//Añadir librería
#include "SPIFFS.h"

void listarArchivos() {

  File root = SPIFFS.open("/"); //Se declara "/" como ubicación root

  //file será el archivo que le sigue en jerarquía a root
  File file = root.openNextFile();

  while (file) {

    Serial.print("Archivo: ");
    Serial.println(file.name()); //Imprime nombre de archivo

    file = root.openNextFile(); //Pasa al siguiente archivo
  }

}

void setup() {

  Serial.begin(115200); //Inicia puerto serial

  //Iprimir mensaje de error al iniciar SPIFFS
  if (!SPIFFS.begin(true)) {
    Serial.println("Ocurrió un error al ejecutar SPIFFS.");
    return;
  }

  //Crea un archivo llamado "/ejemplo.txt"
  File file = SPIFFS.open("/ejemplo-2.txt", FILE_WRITE);

  if (!file) {
    Serial.println("Hubo un error creando el archivo.");
    return;
  }

  //Termina proceso
  file.close();

  //Muestra los archivos almacenados
  Serial.println("\n\n**Antes de eliminar**");
  listarArchivos();

  //Borra el archivo que se creó y el que estaba guardado
  SPIFFS.remove("/ejemplo.txt");
  SPIFFS.remove("/ejemplo-2.txt");

  //Vuelve a mostrar los archivos para verificar
  //que se hallan eliminado
  Serial.println("\n\n**Después de eliminar**");
  listarArchivos();
}

void loop() {}
