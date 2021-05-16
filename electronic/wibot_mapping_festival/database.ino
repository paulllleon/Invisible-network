void sendData(String bssid, String wifiName, int rssi, int wifiChannel) {
  String path = "/" + USER_NAME + "/wifi/" + bssid;

  if (Firebase.setString(firebaseData, path + "/name", wifiName))
  {
  } else {
    Serial.print("Error in set wifiName, ");
    Serial.println(firebaseData.errorReason());
  }
  if (Firebase.setInt(firebaseData, path + "/rssi", rssi )) {}
  else {
    Serial.print("Error in set rssi, ");
    Serial.println(firebaseData.errorReason());
  }
  if (Firebase.setInt(firebaseData, path + "/channel", wifiChannel)) {}
  else {
    Serial.print("Error in set channel, ");
    Serial.println(firebaseData.errorReason());
  }

  // récupérer dans la database le nombre de fois qu'on a vu le wifi
  if (Firebase.getInt(firebaseData, path + "/metTime"))
  {
    int timeMet = firebaseData.intData();
    if (Firebase.setInt(firebaseData, path + "/metTime", timeMet + 1)) {}
    else {
      Serial.print("Error in set timeMet");
      Serial.println(firebaseData.errorReason());

    }
  }
  else { // si on arrive pas à récupérer le chiffre c'est qu'il n'existe pas
    // on l'initie en le mettant à 0
    if (Firebase.setInt(firebaseData, path + "/metTime", 0)) {}
    else {
      Serial.print("Error in initiate timeMet");
      Serial.println(firebaseData.errorReason());
    }
    Serial.println("----------Can't get metTime--------");
    Serial.println("REASON: " + firebaseData.errorReason());
    Serial.println("--------------------------------");
    Serial.println();

    registerNewFriend(wifiName);

  }
  String jsonStr = "";

  String allInOne = gTime + "-" + gDay + "-" + gPosition;
  //Serial.println(allInOne);
  // à chaque fois que l'on vois un wifi déjà croisé, on enregistre l'heure, la date, et la position de la rencontre
if (Firebase.pushString(firebaseData, "/snapshots/" + bssid, allInOne)) {}
  else {
    Serial.print("Error in set snapshot, ");
    Serial.println(firebaseData.errorReason());
  }
}


void logData() {
  if (Firebase.getInt(firebaseData, "paul/0A:D0:0C:EF:3F:0D/channel"))
  {
    Serial.println("----------Get result-----------");
    Serial.println("PATH: " + firebaseData.dataPath());
    Serial.println("TYPE: " + firebaseData.dataType());
    Serial.print("VALUE: ");
    if (firebaseData.dataType() == "int")
      Serial.println(firebaseData.intData());
    else if (firebaseData.dataType() == "float")
      Serial.println(firebaseData.floatData());
    else if (firebaseData.dataType() == "boolean")
      Serial.println(firebaseData.boolData() == 1 ? "true" : "false");
    else if (firebaseData.dataType() == "string")
      Serial.println(firebaseData.stringData());
    else if (firebaseData.dataType() == "json")
      Serial.println(firebaseData.jsonData());
    Serial.println("--------------------------------");
    Serial.println();
  }
  else
  {
    Serial.println("----------Can't get data--------");
    Serial.println("REASON: " + firebaseData.errorReason());
    Serial.println("--------------------------------");
    Serial.println();
  }
}
