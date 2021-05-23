let datas;

let rssi = 0;
let timeMet = 1;
let macadress = "A0:B1:C2:D3:E4:F5";
let name = "Anonymous Wifi";
let lattitude = "4632.7500N";
let lgt = 6.588326;
let longitude = "634.3202E";
let ltt = 46.5366194;

function preload() {
  datas = loadJSON(
    "files/invisible-network-default-rtdb-paulllleon-export.json"
  );
}

function setup() {
  let cnv = createCanvas(600, 600);
  background(250);
  grid();
}

function draw() {
  if (mouseIsPressed) {
    fill(0);
  } else {
    fill(255);
  }

  if (ready) {
    updateVariable();
  }
}

function reDraw() {
  grid();
}

const order = "ABCDEFGHIJ";

const debug = false;
function grid() {
  background(255);
  stroke(0);
  strokeWeight(1);

  if (debug) {
    // desine les lignes de la grille
    for (let i = 1; i < order.length; i++) {
      const y = (height / order.length) * i;
      const x = (width / order.length) * i;
      line(0, y, width, y);
      line(x, 0, x, height);
    }
  }

  const cellWidth = width / order.length;
  const cellHeight = height / order.length;

  fill(0);
  //rect(width / 2, height / 2, cellWidth, cellHeight);
  noStroke();
  textSize(20);
  textAlign(CENTER);

  if (debug) {
    // dessine les index de la grille
    for (let i = 0; i < order.length; i++) {
      text(i + order[i], cellWidth / 2 + cellWidth * i, cellHeight / 2);

      if (i != 0) {
        text(
          i + order[i],
          cellWidth / 2,
          (cellHeight / 5) * 2 + cellHeight * i
        );
      }
    }
  }

  fill(0, 0, 0, 120);
  noStroke();
  //beginShape();

  //

  console.log(macadress);

  for (let i = 0; i < macadress.length; i += 3) {
    const char1 = macadress[i];
    const char2 = macadress[i + 1];

    // if(isNaN(char1)){
    //   x = order.indexOf(char1)
    // }else{
    //   x = char1;
    // }

    const x = isNaN(char1) ? order.indexOf(char1) : char1;
    const y = isNaN(char2) ? order.indexOf(char2) : char2;

    const posX = x * cellWidth + cellWidth / 2;
    const posY = y * cellHeight + cellHeight / 2;
    ellipse(posX, posY, width, width);
    // vertex(posX, posY);
  }
  // endShape();
  raster();
}

function raster() {
  //loadPixels();

  const gap = 15; // écart entre les points
  points = [];

  for (let i = 0; i < width; i += gap) {
    for (let j = 0; j < height; j += gap) {
      let c = get(i, j);
      const radius = map(red(c), 0, 255, 0, 50);
      points.push([i, j, radius, c]);
    }
  }

  background(255);
  for (let i = 0; i < points.length; i++) {
    const point = points[i];
    fill(0);
    ellipse(point[0], point[1], point[2], point[2]);
  }
}

// function is

function updateVariable() {
  rssi = currentWifi.rssi;
  name = currentWifi.name;
  macadress = currentWifi.macadress;
  metTime = currentWifi.metTime;
  lattitude = currentWifi.lattitude;
  ltt = currentWifi.ltt;
  longitude = currentWifi.longitude;
  lgt = currentWifi.lgt;
}
