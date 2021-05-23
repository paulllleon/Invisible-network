let datas;

let rssi = 0;
let timeMet = 1;
let macadress = "A0:B1:C2:D3:E4:F5";
let name = "Anonymous Wifi";

function preload() {
  datas = loadJSON(
    "files/invisible-network-default-rtdb-paulllleon-export.json"
  );
}

function setup() {
  let cnv = createCanvas(600, 600);
  background(250);
}

function draw() {
  if (mouseIsPressed) {
    fill(0);
  } else {
    fill(255);
  }

  let radius = map(rssi, -120, 0, 0, 50);
  // ellipse(mouseX, mouseY, mouseX / 2, mouseX / 2);
  ellipse(mouseX, mouseY, radius, radius);

  if (ready) {
    updateVariable();
  }
}

function updateVariable() {
  rssi = currentWifi.rssi;
  name = currentWifi.name;
  macadress = currentWifi.macadress;
  metTime =  
}
