void readGps() {

  char c = GPS.read();
  if (GPSECHO)
    if (c) Serial.print(c);
  // if a sentence is received, we can check the checksum, parse it...
  if (GPS.newNMEAreceived()) {
    // a tricky thing here is if we print the NMEA sentence, or data
    // we end up not listening and catching other sentences!
    // so be very wary if using OUTPUT_ALLDATA and trying to print out data
    //    Serial.print(GPS.lastNMEA()); // this also sets the newNMEAreceived() flag to false
    if (!GPS.parse(GPS.lastNMEA())) // this also sets the newNMEAreceived() flag to false
      return; // we can fail to parse a sentence in which case we should just wait for another
  }

  // delai entre les scans 
  if (millis() - timer > 10000) {
    timer = millis(); // reset the timer
    
    int gHour = (int(GPS.hour) + 2) % 24;
    gTime = String(gHour, DEC) + ":" + String(GPS.minute, DEC) + ":" + String(GPS.seconds, DEC);
 
    gDay = String(GPS.day, DEC) + "/" + String(GPS.month, DEC) + "/" + String(GPS.year, DEC);
    
    gPosition = "no gps";
    if (GPS.fix) {
     gPosition = String(GPS.latitude, 4) + String(GPS.lat) + ", "  + String(GPS.longitude, 4) + String(GPS.lon);
    }

     Serial.println(gTime);
     Serial.println(gDay);
     Serial.println(gPosition);
//     Serial.println(GPS.minute);
//     Serial.println(GPS.seconds);
//     Serial.println(GPS.milliseconds);
     
    
    // ne pas lancer la recherche de wifi si le GPS n'est pas encore régler (0,0,0 valeur pas default)
    if (int(GPS.minute) != 0 || int(GPS.seconds) != 0 || int(GPS.milliseconds) != 0) {
      listNetworks();
    }else{
       displayText("gps module not ready");
      }
  }
}
