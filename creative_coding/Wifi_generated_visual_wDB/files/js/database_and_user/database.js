let selection = "gps";
let wifiList = [];
let currentWifi;

let ready = false;

function readDB() {
  database.ref(`${USER}`).once("value", function (snapshot) {
    if (snapshot.val()) {
      //   snapshot.forEach(function (childSnapshot) {
      //     var key = childSnapshot.key;
      //   });

      let wifi = snapshot.val().wifi;
      //   console.log(Object.keys(wifi).length);
      let snap = snapshot.val().snapshots;

      //   console.log(wifi);

      for (let macAdress in snap) {
        // PAS PLUS DE 360 ???!!
        //console.log(macAdress);
        noGps = 0;
        withGps = 0;
        let datas = {};

        const wifiObj = wifi[macAdress];

        datas.macadress = macAdress;
        datas.wifiName = wifiObj.name;
        datas.channel = wifiObj.channel;
        datas.rssi = wifiObj.rssi;
        datas.met = wifiObj.metTime;

        //datas.adress = info.adress;

        const rawSnapshot = snap[macAdress];
        const keys = Object.keys(rawSnapshot);
        // console.log(keys);
        const cSnapshot = [];
        keys.forEach((key) => {
          cSnapshot.push(rawSnapshot[key]);
        });
        let good = false;
        cSnapshot.forEach((snap) => {
          const data = parsSnapshot(snap);
          //   console.log(data.position);
          if ((data.position.lattitude !== "" || selection == "all") && !good) {
            datas.lattitude = data.position.lattitude;
            datas.longitude = data.position.longitude;
            datas.ltt = gpstoGMapCord(data.position.lattitude);
            datas.lgt = gpstoGMapCord(data.position.longitude);
            datas.time = data.time;
            // console.log(datas);
            wifiList.push(new Wifi(macAdress, datas));
            good = true;
          }
        });
      }
    }

    const eastherEgg = {
      macadress: "SA:LU:T-:--:EC:AL",
      datas: {
        channel: 11,
        lattitude: "4632.7500N",
        lgt: 6.588326,
        longitude: "634.3202E",
        ltt: 46.5366194,
        macadress: "1C:B1:C2:D3:9C:4E",
        met: 152,
        rssi: -54,
        time: {
          day: "23",
          hour: "0",
          minute: "0",
          month: "5",
          second: "0",
          year: "21",
        },
        wifiName: "Happy_Birthday_Pauline",
      },
    };

    wifiList.push(new Wifi(eastherEgg.macadress, eastherEgg.datas));

    // trier la liste des wifis dans un orde alphabetic
    wifiList.sort((a, b) => {
      if (a.name < b.name) {
        return -1;
      }
      if (a.name > b.name) {
        return 1;
      }
      return 0;
    });

    currentWifi = wifiList[0];
    // console.log(wifiList);
    creatOptionList();
  });
}

function creatOptionList() {
  const select = document.getElementById("wifiList");

  for (let i = 0; i < wifiList.length; i++) {
    wifi = wifiList[i];
    const option = document.createElement("option");
    option.innerHTML = "<b>" + wifi.name + "</b> (" + wifi.macadress + ")";
    option.value = i;
    select.appendChild(option);
  }

  select.onchange = () => {
    currentWifi = wifiList[select.value];
    udpateCaption();
    logInfo();
    reDraw();
  };

  ready = true;
  currentWifi = wifiList[Math.floor(Math.random() * wifiList.length)];
  udpateCaption();
}

function udpateCaption() {
  const name = currentWifi.name == "" ? "Anonymous Network" : currentWifi.name;
  document.getElementById("wifiName").innerHTML = name;
  document.getElementById("macAdress").innerHTML = currentWifi.macadress;
  document.getElementById("timemet").innerHTML = currentWifi.metTime;
  document.getElementById("signal").innerHTML = currentWifi.rssi;
  document.getElementById(
    "location"
  ).innerHTML = `${currentWifi.lattitude}, ${currentWifi.longitude}`;
}

function logInfo() {
  const infoToLog = [
    "name",
    "macadress",
    "rssi",
    "metTime",
    "lattitude",
    "longitude",
  ];
  const bloc = document.getElementById("wifiDatas");
  bloc.innerHTML = "";
  infoToLog.forEach((key) => {
    const text = `${key} : ${currentWifi[key]}`;
    // console.log(text);
    const p = document.createElement("p");
    p.innerHTML = text;
    bloc.appendChild(p);
  });

  console.log("-----");
}

function parsSnapshot(snap) {
  // "23:30:10-21/5/21-4632.7500N, 634.3202E"
  // la donn??e d'entrer ressemble ?? la ligne ci dessus
  // des donn??es compact en un seul
  // on la process pour en extraire
  // 1. L'heure - 23:30:10
  // 2. la date - 21/5/21
  // 3. la lattitude - 4632.7500N
  // 4. la longitude - 634.3202E

  let position = {
    lattitude: "",
    longitude: "",
  };

  let currentParam = 0;

  const params = ["hour", "minute", "second", "day", "month", "year"];
  const special = ":/- ";

  let time = {};
  params.forEach((p) => {
    time[p] = "";
  });

  let countWithGps = false;

  for (let i = 0; i < snap.length; i++) {
    const char = snap[i];
    if (currentParam < params.length) {
      if (special.includes(char)) {
        currentParam++;
      } else {
        time[params[currentParam]] = time[params[currentParam]] + char;
      }
    } else {
      const rest = snap.slice(i, snap.length);
      //   console.log(rest);
      if (rest != "no gps") {
        const breakPoint = rest.search(",");
        position.lattitude = rest.slice(0, breakPoint);
        position.longitude = rest.slice(breakPoint + 2, rest.length);
        withGps++;
      } else {
        noGps++;
      }
      break;
    }
  }

  return { position: position, time: time };
}

function gpstoGMapCord(string) {
  const pointAt = string.indexOf(".");
  const startAt = string[0] == "0" ? 1 : 0;

  const big = Number(string.slice(startAt, pointAt - 2));
  const littleRaw = Number(string.slice(pointAt - 2, string.length - 1));
  const little = (littleRaw / 60) * 100;
  const letter = string.slice(-1);

  let number = big + little / 100;

  const minusLetter = "SW";
  if (minusLetter.includes(letter)) {
    number *= -1;
  }

  return number;
}

class Wifi {
  constructor(macadress, info) {
    this.macadress = macadress;
    this.name = info.wifiName;
    this.lattitude = info.lattitude;
    this.longitude = info.longitude;
    this.adress = info.adress;
    this.metTime = info.met + 1;
    const time = info.time;
    this.time = time;
    this.date = new Date(
      time.year,
      (time.month - 1) % 12,
      time.day,
      //   Math.floor(Math.random() * 30),
      time.hour,
      time.minute,
      time.second,
      0
    );
    this.channel = info.channel;
    this.rssi = info.rssi;
  }
}
