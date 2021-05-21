_**(for people who don't speak French, don't worry. It is an ongoing project, the English page will arrive soon, towards the end of June 2021)**_

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
Cela se fait en 2 étapes : (_[EN documentation here](https://learn.adafruit.com/adafruit-feather-m0-wifi-atwinc1500/setup)_)

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

```C++
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
```

Ce code fait clignoter la LED rouge se trouvant juste à côté du porc USB.

Pour téléverser le code au Feather M0 il suffis de sélectionner le bon type de carte et le port :

- Outils > Type de carte: > Adafruit SAMD(32.bits... > Adafruit Feather M0
- Outils > Port > ...(Adafruit Feather M0)
- Appuyer sur le symbole → (flèche vert la droite) situé en haut à gauche de l'IDE Arduino

![Uplaod](assets/images/upload.png)

Si tout se passe bien

- compilation du croquis
- téléversement ...
- téleversement terminé

Si vous êtes passé par ces trois étapes, la LED rouge à côté du porc USB devrait clignoter.

Si ce n'est pas le cas essayer de mettre votre Feather M0 en _**bootloader**_ manuel. Pour cela, cliquez 2 fois (double clickez) sur le button _RESET_ de votre Feather M0. Le bouton _RESET_ est le petit button noir qui se trouve juste à côté du port USB du Feather M0.

![reset](assets/images/reset_btn.jpg)

_image origignal by [lady ada](https://learn.adafruit.com/users/adafruit) published under this [LICENSE](http://creativecommons.org/licenses/by-sa/3.0/)_

Si le double click functionne la LED située à côté du port USB du Feather M0 devrait pulsé

<!-- click the RST button twice (like a double-click)to get back into the bootloader.

The red LED will pulse and/or RGB LED will be green, so you know that its in bootloader mode.

Once it is in bootloader mode, you can select the newly created COM/Serial port and re-try uploading. -->

---

_**De manière général, si un code ne parvient pas être téléversé c'est qu'un de ces paramettre n'est pas correct.**_

- Type de Carte
- Port USB
- le Feather M0 n'est pas en mode _**bootloader**_

_**Vérifier ces trois paramettre et effectuer les actions suivantes**_

- Sélectionner le bon type de carte : `Outils > Type de carte: > Adafruit SAMD(32.bits... > Adafruit Feather M0`
- double clicker sur le button reset de du Feather M0 pour le mettre en mode _**bottloader**_
- Sélectionner le bon port USB : `Outils > Port > ...(Adafruit Feather M0)`
- Appuyer sur le symbole → (flèche vert la droite) situé en haut à gauche de l'IDE Arduino

---

---

---

---

## Installation de bibliothèques

Les bibliothèques sont des bouts codes réalisés par la communauté arduino ou des fabriquants de composants électronique. Les bibliotèque permette notamment de communiquer plus facilement avec des compsoants et utilisant des fonction simple qui nous "prémache" le travail.

Dans notre cas, nous aurons besoin de biblothèques pour :

- afficher du contenu sur l'écran e-paper
- récupérer l'heure et la position géographique
- scanner les réseaux wifi
- communiquer avec la database

## Tester les composants

Télécharger les biblothèques listé ci-dessous

- Pour l'utilisation do module GPS
  - Adafruit GPS Library
- Pour utiliser le module Wifi integré au Feather M0
  - WiFi101
- Pour communiquer avec la base de donnée Firebase
  - Firebase Arduino based on WiFi101
- Pour utiliser l'écran e-paper
  - Adafruit GFX Library
  - Adafruit ImageReader Library

**Ormi le téléchargement des bibliothèques**, l'étape de tester chacun des composants n'est pas obligatoire mais peu vous permettre de comprendre comment chaque composants fonctionne individuellement.

Si vous souhaiter finalisé le module _**Wibot**_ au plus vite e, passez au chapitre suivant : **#Connexion à la base de donnée**

Pour tester chacun des composants utiliser les exemples dans le dossier [electronic/test_component](https://github.com/paulllleon/Invisible-network/tree/main/electronic/test_component)

Pour téléverser les différents exemples à votre Feather M0, référez vous à la fin du chapitre **#Premier pats**.

La plupart des exemples utilise avec la fonction de debug `Serial.print()` qui permet d'afficher des informations dans le **Moniteur série**. Pour y accéder, une fois le téléversement terminé, cliqué sur le symbole de ⚲ loupe situé en haut à droite de l'IDE arduino.

![moniteur_serie_bouton](assets/images/moniteur_serie.png)

**Si l'un des exemple ne fonctionne pas, assurer vous d'avoir bien installé toutes les bibliothèques requises et reessayer de téléverser le code.**

---

## Connexion à la base de donnée

- Update firmware
- Update certificat SSL _([EN documentation here](https://learn.adafruit.com/adafruit-feather-m0-wifi-atwinc1500/updating-ssl-certificates))_

- Changer les paramettre corespondant à votre réseau
- Changer le `USER_NAME` pour un nom qui vous sier (**éviter les espace et les caractère spéciaux**)

```C++
  #define WIFI_SSID "Paul’s iPhone" // le nom de votre réseau wifi
  #define WIFI_PASSWORD "noproblemno" // le mot de passse de votre réseau
  ...
  ...
  ...
  String USER_NAME = "paul"; //le pseudo que vous avez chois sans espace ni caractère spécial
```

- Téléverser le code
- Ouvrez le Moniteur Série

Si vous ne parvenez pas à vous connecter à votre réseau wifi, vérifier que le `WIFI_SSID` soit correctement orthographier. Dans le cas de présence de caractère spéciaux je vous conseil d'utiliser l'exemple [wifi_scan-network](https://github.com/paulllleon/Invisible-network/tree/main/electronic/test_component/wifi_scan-network) pour scanner les wifi alentour et copier le nom de votre wifi affiché dans le Moniteur série.

Si

---

## Finalisation de wibot

Ouvrez le fichier [/electronic/wibot_mapping_festival](https://github.com/paulllleon/Invisible-network/tree/main/electronic/wibot_mapping_festival)

- Changer les paramettre corespondant à votre réseau
- Changer le `USER_NAME` pour un nom qui vous sier (**éviter les espace et les caractère spéciaux**)

```C++
  #define WIFI_SSID "Paul’s iPhone" // le nom de votre réseau wifi
  #define WIFI_PASSWORD "noproblemno" // le mot de passse de votre réseau
  ...
  ...
  ...
  String USER_NAME = "paul"; //le pseudo que vous avez chois sans espace ni caractère spécial
```

- [Arduino Documentation](https://www.arduino.cc/reference/en/)
- Installer les boards [M0 + Wifi](https://learn.adafruit.com/adafruit-feather-m0-wifi-atwinc1500/setup)
