void listNetworks() {

  Serial.println("** Scan Networks **");
  int numSsid = WiFi.scanNetworks();
  if (numSsid == -1)
  {
    Serial.println("Couldn't get a wifi connection");
    while (true);
  }

  // print the list of networks seen:
  Serial.print("number of available networks:");
  Serial.println(numSsid);

  for (int thisNet = 0; thisNet < numSsid; thisNet++) {

    String wifiName = String(WiFi.SSID(thisNet));
    int rssi = WiFi.RSSI(thisNet);
    int wifiChannel = WiFi.channel(thisNet);
    byte bssid[6];
    String wifiBssid = printMacAddress(WiFi.BSSID(thisNet, bssid));
    
    Serial.print(thisNet); Serial.println(")");
    Serial.print("name : "); Serial.println(wifiName);
    Serial.print("rssi : "); Serial.println(rssi);
    Serial.print("bssid : "); Serial.println(wifiBssid); 
  }
}


String printMacAddress(byte mac[]) {
  String msg = "";
  for (int i = 5; i >= 0; i--) {
    if (mac[i] < 16) {
      msg += "0";
    }

    msg += String(mac[i], HEX);

    if (i > 0) {
      msg += ":";
    }
  }

  msg.toUpperCase();

  return msg;
}
