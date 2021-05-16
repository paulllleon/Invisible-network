void displayText(String msg){
   display.begin(THINKINK_GRAYSCALE4);
    display.clearBuffer();
    display.setTextSize(2);
    display.setCursor(0, 0);
    display.setTextColor(COLOR1);
    display.setTextWrap(true);

    String test = "hello people _How are you ?";

     stringToArray(msg);

    display.display();
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
