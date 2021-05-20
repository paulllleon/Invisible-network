_(for no french, don't worry. This is a ongoing project, the english page will arrive soon, around end of june 2021)_

# Invisible-network

## Intro

Dans ce projet nous utilisions les composants suivants :

- Un microcontrôleur [Feather M0 + Wifi](https://learn.adafruit.com/adafruit-feather-m0-wifi-atwinc1500/)
- Un [module GPS](https://learn.adafruit.com/adafruit-ultimate-gps/arduino-wiring)
- Un écran E-paper [2.9" Grayscale eInk](https://learn.adafruit.com/adafruit-eink-display-breakouts/grayscale-29-overview)
- [Une batterie 3.7 1000mAh - connecteur JST 2.0](https://www.bastelgarage.ch/lipo-akku-1000mah-jst-1-25-lithium-ion-polymer-fur-lora-ttgo?search=lipo)

## Assemblage

---

## Setup

Commencer il vous faut installer l'application [Arduino](https://www.arduino.cc/en/software) qui vous permettra d'écrire du code et de l'envoyer à notre micro controleur. Si vous avez déjà Arduino IDE installé, notez que toute version à partir de la 1.8.0 fonctioneron pour ce projet.

Une fois installée, en l'ouvrant l'application arduino vous devriez voir une fenêtre qui ressemble à ça.

_(si vous êtes sous MacOS la fenêtre sera légerement différente, le menu se trouvera en dehors de la fenêtre dans la barre de navigation mac habituelle)_
![Arduino IDE](assets/images/arduino_ide.png)

Avant de pouvoir vraiment commencer il nous faut encore installer les _Boards Manager_ qui nous permettra de communiquer à le model spécifique de notre micro controleur.
Cela se fait en 2 étapes : (_[english doc here](https://learn.adafruit.com/adafruit-feather-m0-wifi-atwinc1500/setup)_)

### 1 - Ajouter les _Boards Mananger_ nécessaire pour utiliser le micro controller M0

Rendez vous dans les préférences de l'IDE Arduino.
--> `Fichier > Préférences`

Copier l'URL suivante `https://adafruit.github.io/arduino-board-index/package_adafruit_index.json` sous le paramettre _Url de gestionnaire des cartes supplémetnaries_

![gestionnaire de carte](assets/images/preference.png)

### 2 - Installer les _Boards_

Rendez vous dans les Gestionnaire de carte.
--> `Outils > Type de carte: > Gestionnaire de Carte`

Installez les paquets suivants :

- **Adafruit AVR Boards**
- **Adafruit SAMD Boards**

Pour cela taper, un à un, le nom de packets dans la barre de recherche et cliquer sur le boutton installez de l'élément correspondant.

![Board manager](assets/images/board_manager.png)

---

**ATTENTION**

**La paquet `Adafruit SAMD Boards` est parfois capricieux est peu nécessité plusieurs tentative avant de correctement s'installer.**

Vous pouvez vérifier que la paquet est bien installé si à côté de son apparêt le label `INSTALLED`

![INSTALLED](assets/images/installed.png)

Pour les utilisateur.trice.x.s de Windows 7 & 8, il vous faudra installer un driver supplémetaire

---

## Premier pats

Il est mainteant temps de tester que tout fonctionne !
Branchez un câble micro usb à votre micrôcontrôleur et l'autre extermité à votre ordinateur. Si la carte est correctement branchée elle devrait normalement allumer une led, le plus souvent une led rouge juste à côté du port USB.

_Si aucune led n'est allumé sur la carte, c'est que le câble USB n'est pas adéquat ou que le port USB de votre ordinateur a est defectueux. Changer USB, changez de port USB est reassayer._

1 - Sélectionner la carte du modèle **Feather M0**

`Outils > Type de carte: > Adafruit SAMD(32.bits... > Adafruit Feather M0`

(_si le sous-menu **Adafruit SAMD(32.bits...)** n'apparait pas, c'est que le paquet **Adafruit SAMD Boards** n'a été correction installé --> revenez au chapitre #Setup_)

![Carte Feather M0](assets/images/selection_M0.png)

2 - Sélectionner le bon port USB

`Outils > Port > ...(Adafruit Feather M0)`
Selon votre système d'exploitation le numéro de port affiché avant **Adafruit Feather M0**

- Windows : le plus souvent `COM` ex. COM7 (Adafruit Feather M0), COM14...
- MacOs : `/dev/cu` ou `/dev/tty.usbserail-xxxx` ex. /dev/tty.usbserail-1234 /dev/tty.usbserail-xxxx
- MacOs + usb Hub : `/dev/cu.usbmodem`

Si aucun des ports de la liste du menu `Outils > Port` ne contient _Adafruit Feather M0_ c'est soit que l'un des paquets **Adafruit AVR Boards** ou **Adafruit SAMD Boards** est mal installé, soit que le câble USB n'est pas adapté.

Sélectionner le port comprenant _Adafruit Feather M0_

![Port selection](assets/images/port_selection.png)

Il est maintenant temps de téléverser un premier code sur le Feather M0 !

Ouvrez le fichier .ino de l'exemple [Blink](https://github.com/paulllleon/Invisible-network/blob/main/electronic/basic/blink/blink.ino)

```
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
}
```

---

---

---

- [Arduino Documentation](https://www.arduino.cc/reference/en/)
- Installer les boards [M0 + Wifi](https://learn.adafruit.com/adafruit-feather-m0-wifi-atwinc1500/setup)

-[Update SSL](https://learn.adafruit.com/adafruit-feather-m0-wifi-atwinc1500/updating-ssl-certificates)
