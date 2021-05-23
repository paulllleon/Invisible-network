// // Exemple 1 - Draw with ellipse -------------------------------------------------------------------
  function setup() {
    createCanvas(600, 600);
    
  }
  
  function draw() {

    background(255);
    if (mouseIsPressed) {
      fill(0);
    } else {
      fill(255);
    }
    ellipse(width/2, height/2, 80, 80);
    // ellipse(mouseX, mouseY, mouseX/2, mouseX/2);
  }



// // Exemple 2 - Shapes -----------------------------------------------------------------------------
// function setup() {
//     createCanvas(600, 600);
//   }
  
//   function draw() {

//     let colorX = 100 + mouseX/2;
//     let colorY = 0 + mouseY/2;

//     let white = color(255, 255, 255);
//     let black = color(48, 48, 48);
//     let blue = color(102, 0, 255);
//     let yellow = color(255, 255, 107);
//     let purple = color(121, mouseY, colorX);

//     background(black);

//     //rectangle
//     noStroke();
//     fill(blue);
//     rect(0, 0, width/2, height/2);

//     //arc
//     fill(purple);
//     arc(width/2, height, width, height, PI, TWO_PI);

//     //ellipse
//     fill(yellow);
//     ellipse(width/4*3, height/4, mouseX/2, mouseX/2);

//     //triangle
//     fill(white);
//     triangle(0, 0, 0, height/2, mouseX, mouseY);

//     stroke(white);
//     strokeWeight(5);
//     line(width/2, height/2, width, height);

//     stroke(white);
//     point(width/2, height/4*3);

//   }



// //Exemple 3 - Boucle For ---------------------------------------------------------------------------
// function setup() {
//     createCanvas(600, 600);
//   }
  
//   function draw() {
//     background(127);
//     noStroke();
//     for (let i = 0; i < height; i += 20) {
//       fill(129, 206, 15);
//       rect(0, i, width, 10);
//       fill(255);
//       rect(i, 0, 10, height);
//     }
//   }