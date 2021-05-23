let datas;


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
  ellipse(mouseX, mouseY, mouseX / 2, mouseX / 2);
}
