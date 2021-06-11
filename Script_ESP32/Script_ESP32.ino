#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>

int d1t1 = 12;
int d1t2 = 13;
int d1t3 = 14;
int d1t4 = 15;

int d2t1 = 12;
int d2t2 = 12;
int d2t3 = 12;
int d2t4 = 12;
const char *ssid = "SistemasProgramables";
const char *password = "MarcosWapo";

WiFiServer server(80);


void setup() {


  Serial.begin(115200);
  Serial.println();
  Serial.println("Configurando punto de acceso...");

  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("IP: ");
  Serial.println(myIP);
  server.begin();
  Serial.println("Servidor arriba");
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    String currentLine = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        if (c == '\n') {


          if (currentLine.length() == 0) {
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }

        //Puerta
        /*
        Puerta izquierda = d1
        Puerta derecha = d2
        */
        //Rutinas:
        /*
         5 minutos = t1
        15 minutos = t2
        30 minutos = t3
        60 minutos = t4
        */
        //Ejemplos de peticiones: para cerrar la puerta izquierda durante 15 minutos el get será a: /d1t2
        if (currentLine.endsWith("GET /")) {
          Serial.println(currentLine);

        }
        if (currentLine.endsWith("POST")) {
          Serial.println(currentLine);

        }
//        if (currentLine.endsWith("GET /d1t3")) {
//          Serial.println("d1t3");
//
//        }
//        if (currentLine.endsWith("GET /d1t4")) {
//          Serial.println("d1t4");
//        }
//
//        if (currentLine.endsWith("GET /d2t1")) {
//          Serial.println("d2t1");
//        }
//        if (currentLine.endsWith("GET /d2t2")) {
//          Serial.println("d2t2");
//        }
//        if (currentLine.endsWith("GET /d2t3")) {
//          Serial.println("d2t3");
//        }
//        if (currentLine.endsWith("GET /d2t4")) {
//          Serial.println("d2t4");
//        }
      }
    }
    // close the connection:
    client.stop();
  }
}
