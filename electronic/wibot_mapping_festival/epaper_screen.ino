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
