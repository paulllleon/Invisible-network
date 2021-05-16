
// GPS
#include <Adafruit_GPS.h>
#define GPSSerial Serial1
Adafruit_GPS GPS(&GPSSerial);
#define GPSECHO false

uint32_t timer = millis();

String gTime = "";
String gDay = "";
String gPosition = "";
//


//Wifi
String wifiName = "Paul’s iPhone";
#define WIFI_SSID "Paul’s iPhone"
#define WIFI_PASSWORD "noproblemno"

boolean gotaNewFriend = false;
int newFriends = 0;
String lastNewFriend = "";
String newFriendsList = "";

String wifiAround[] = {
  "0", "0", "0", "0", "0", "0", "0", "0", "0", "0",
  "0", "0", "0", "0", "0", "0", "0", "0", "0", "0",
  "0", "0", "0", "0", "0", "0", "0", "0", "0", "0",
  "0", "0", "0", "0", "0", "0", "0", "0", "0", "0",
  "0", "0", "0", "0", "0", "0", "0", "0", "0", "0",
  "0", "0", "0", "0", "0", "0", "0", "0", "0", "0",
  "0", "0", "0", "0", "0", "0", "0", "0", "0", "0",
  "0", "0", "0", "0", "0", "0", "0", "0", "0", "0",
  "0", "0", "0", "0", "0", "0", "0", "0", "0", "0",
  "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"
};
//


//Firebase
#include "Firebase_Arduino_WiFi101.h"
String USER_NAME = "paul";
#define FIREBASE_HOST "invisible-network-default-rtdb.europe-west1.firebasedatabase.app"
#define FIREBASE_AUTH "yfRnqbVBhJ4OpcjxCmfJp9N6rAR8C2mq3M2YjPzN"
FirebaseData firebaseData;
//

//Eink
#include "Adafruit_ThinkInk.h"
#include <SPI.h>

#define SD_CS       5
#define SRAM_CS     -1
#define EPD_CS      9
#define EPD_DC      10
#define EPD_RESET   -1
#define EPD_BUSY    -1

ThinkInk_290_Grayscale4_T5 display(EPD_DC, EPD_RESET, EPD_CS, SRAM_CS, EPD_BUSY);

#define COLOR1 EPD_BLACK
#define COLOR2 EPD_LIGHT
#define COLOR3 EPD_DARK
//



void setup()
{
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
  
    displayText("trying to connect wifi");
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);
  Serial.println();

  //Provide the autntication data
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH, WIFI_SSID, WIFI_PASSWORD);
  Firebase.reconnectWiFi(true);

  GPS.begin(9600);
  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCONLY);
  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ); // 1 Hz vitesse de rafraichissement
  GPS.sendCommand(PGCMD_ANTENNA);
  delay(1000);
  GPSSerial.println(PMTK_Q_RELEASE);
}

void loop()
{
  readGps();
}
