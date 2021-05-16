void choseMessage(int amount) {
  String msg = "";
  if (gotaNewFriend) {
    if (newFriends > 1) {
      msg = msgNewFriends();
      if (newFriends > 3) {
        msg += "*and many more";
      }
    }
    else {
      msg = msgOneFriend();
    }
  } else {
    int number = randomInt(1);
   // int number = 1;
    if (number == 0) {
      msg = msgMetTime(int(random(0, amount)));
    }
    else if(number == 1){
      msg = msgWifiAround(amount);
      }

  }
  //msg += "*" + gPosition;
  displayText(msg);

  gotaNewFriend = false;
  newFriends = 0;
  lastNewFriend = "";
  newFriendsList = "";
}

String msgOneFriend() {
  String msg = "";
  int number = randomInt(1);
  if (number == 0) {
    msg = "I got a new friend*called*" + lastNewFriend;
  }
  else if (number == 1) {
    msg = "Just met*" + lastNewFriend + "*for the first time";
  }

  return msg;
}

String msgNewFriends() {
  String msg = "";
  int number = randomInt(0);
  if (number == 0) {
    msg = "I made new friends*" + newFriendsList;
  }
  else if (number == 1) {
  }
  return msg;
}

String msgMetTime(int index) {
  String bssid = wifiAround[index];
  String path = "/" + USER_NAME + "/wifi/" + bssid;
  Serial.print("random name: ");
  Serial.println(bssid);
  String wifiName = "";
  int metTime;
  //     if (Firebase.getInt(firebaseData, path + "/Int/Data" + (i + 1)))
  //    {


  if (Firebase.getString(firebaseData, path + "/name"))
  {
    wifiName = firebaseData.stringData();
    Serial.println(wifiName);
  }
  else
  {
    Serial.println("----------Can't get name--------");
    Serial.println("REASON: " + firebaseData.errorReason());
    Serial.println("--------------------------------");
    Serial.println();
  }

  if (Firebase.getInt(firebaseData, path + "/metTime"))
  {
    metTime = firebaseData.intData();
    Serial.println(metTime);
  }
  else
  {
    Serial.println("----------Can't get name--------");
    Serial.println("REASON: " + firebaseData.errorReason());
    Serial.println("--------------------------------");
    Serial.println();
  }

  String msg = "";

  int number = randomInt(2);

  if (number == 0) {
    msg = "It's the " + String(metTime) + " time I see*" +  wifiName + "*since we first met.";
  }
  else if (number == 1) {
    msg = "I have seen*" + wifiName + " " + String(metTime) + " times*since our first meeting.";
  }
  else if (number == 2) {
    msg = "Since our first*encounter*I've seen*" + wifiName + "*more than " + String(metTime) + " times.";
  }

  return msg;
}

String msgWifiAround(int qtt) {
  String msg = "";
  String amount = String(qtt);
 
  //        
  //        `I can see ${_around}*friends.`,
  //        `${*around} of my friends*are nearby`,
  //        `I have ${*around} friends*chilling around`,
  //        `I think there's*${*around} mates in the*neighborhood.`,
  //        `Around us,*there's ${*around} of my*friends.`,
  //

  int number = randomInt(1);

  if (number == 0) {
  msg =  "From here,*I can see " + amount +"*of my friends.";
  }
  else if (number == 1) {
  msg = "there's " + amount + " of*my friends here.";
  }
  else if (number == 2) {

  }

  return msg;
}



int randomInt(int maximum) {

  int number = int(random(0, maximum + 1));
  if (number == maximum + 1) {
    number = maximum;
  }
  return number;
}

void stringToArray(String _msg)
{
  String msg = _msg;
  int membersN = 10;
  String Ary[10];

  int pos = 0;
  for (int f = 0 ; f < msg.length(); f++) {
    if (msg.charAt(f) != '*')
    {
      Ary[pos] += msg.charAt(f);
    }
    else
    {
      pos ++;
    }
  }



  int offsetY = 20;

  for (int i = 0; i < membersN; i++)
  {

    display.setCursor(20, i * 20 + offsetY); //Interlignage

    // Serial.println(Ary[i]);
    display.print(Ary[i]);
  }

}
