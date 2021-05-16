void listNetworks() {

  for(int i = 0; i<100;i++){
    wifiAround[i] = "0";
  }
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
    Serial.print(thisNet);
    Serial.print(") ");
    Serial.println(WiFi.SSID(thisNet));

    String wifiName = String(WiFi.SSID(thisNet));
    int rssi = WiFi.RSSI(thisNet);
    int wifiChannel = WiFi.channel(thisNet);

    byte bssid[6];
    String wifiBssid = printMacAddress(WiFi.BSSID(thisNet, bssid));

    if(thisNet < 100){
    wifiAround[thisNet] = wifiBssid;
    }

    sendData(wifiBssid, wifiName, rssi, wifiChannel);
  }
  choseMessage(numSsid);
}

void registerNewFriend(String wifiName) {

  gotaNewFriend = true;
  newFriends ++;
  lastNewFriend = wifiName;
  if (newFriends <= 3) {
    if (newFriends == 1) {
      newFriendsList = wifiName;
    } else {
      newFriendsList += "_" + wifiName;
    }
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
