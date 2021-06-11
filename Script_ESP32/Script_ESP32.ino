#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>

const char *ssid = "SistemasProgramables";
const char *password = "MarcosWapo";

WiFiServer server(80);

void setup() {

  Serial.begin(115200);


  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  server.begin();
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

        if (currentLine.endsWith("GET /d1t1")) { //De esta manera solo imprime GET /, no imprime lo que sigue despues de ahí
          Serial.println("d1t1");
        }
        if (currentLine.endsWith("GET /d1t2")) { //Mismo caso
          Serial.println("d1t2");
        }
       if (currentLine.endsWith("GET /d1t3")) {
         Serial.println("d1t3");
       }
       if (currentLine.endsWith("GET /d1t4")) {
         Serial.println("d1t4");
       }
       if (currentLine.endsWith("GET /d2t1")) {
         Serial.println("d2t1");
       }
       if (currentLine.endsWith("GET /d2t2")) {
         Serial.println("d2t2");
       }
       if (currentLine.endsWith("GET /d2t3")) {
         Serial.println("d2t3");
       }
       if (currentLine.endsWith("GET /d2t4")) {
         Serial.println("d2t4");
       }
      if (currentLine.endsWith("GET /od1")) {
         Serial.println("od1");
       }
      if (currentLine.endsWith("GET /od2")) {
         Serial.println("od2");
       }
      }
    }
    // close the connection:
    client.stop();
  }
}
