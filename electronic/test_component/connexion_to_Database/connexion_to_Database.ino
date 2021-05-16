#include "Firebase_Arduino_WiFi101.h"
#define WIFI_SSID "Paul’s iPhone"
#define WIFI_PASSWORD "noproblemno"

// le USER_NAME par votre nom/pseudo
String USER_NAME = "test";
#define FIREBASE_HOST "invisible-network-default-rtdb.europe-west1.firebasedatabase.app"
#define FIREBASE_AUTH "yfRnqbVBhJ4OpcjxCmfJp9N6rAR8C2mq3M2YjPzN"
FirebaseData firebaseData;


void setup() {
  WiFi.setPins(8, 7, 4, 2);
  Serial.begin(115200);
  while (!Serial) {
    delay(100);
    //  }
    delay(100);

    Serial.println();

    Serial.print("Connecting to Wi-Fi");
    int status = WL_IDLE_STATUS;
    while (status != WL_CONNECTED)
    {
      status = WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
      Serial.print(".");
      delay(100);
    }
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);
  Serial.println();

  //Provide the autntication data
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH, WIFI_SSID, WIFI_PASSWORD);
  Firebase.reconnectWiFi(true);

  String path = "/" + USER_NAME + "/test";

  if (Firebase.setString(firebaseData, path, "ceci est un test"))
  {
    Serial.println("le message test a été envoyé");
  } else {
    Serial.print("Error in set test message, ");
    Serial.println(firebaseData.errorReason());
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
