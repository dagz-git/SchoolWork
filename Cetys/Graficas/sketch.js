let walls = [];
let ray;
let particle;
function setup() {
  createCanvas(400, 400);
  for(let i = 0; i <8; i++){
     walls[i] = new Boundary(random(width),random(height),random(width),random(height));
    
  }
  
  walls.push(new Boundary(0, 0, width, 0));
  walls.push(new Boundary(width, 0, width, height));
  walls.push(new Boundary(width, height, 0, height));
  walls.push(new Boundary(0, height, 0, 0));
 
  particle = new Particle();

  
}

function draw() {
  background(0);
  for(let wall of walls){
     wall.show();
  }
 
  particle.update(mouseX, mouseY);
  particle.show();
  particle.look(walls);
  
  // ray.show()
  // ray.lookAt(mouseX, mouseY);
 
  
}