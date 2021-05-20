// la fonction setup s'exécute une fois lorsque vous appuyez sur reset ou allumez la carte
void setup() {
  // initialiser la broche numero 13 comme une sortie.
  pinMode(13, OUTPUT);
}

// la fonction loop se lance  à la fin se fonction setup et se répète à l'infini
void loop() {
  digitalWrite(13, HIGH);   // allume la LED (HIGH)
  delay(1000);              // attend 1 seconde
  digitalWrite(13, LOW);    // éteind la LED en mettant la tension basse(LOW)
  delay(1000);              // attend 1 seconde
}
