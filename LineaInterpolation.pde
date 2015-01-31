PVector p0,p1,p2,p3,x;
float t;
float a;


void setup(){
  size(400,400);
  t=0;
  a=0.01f;
  p0 = new PVector(50,50);
  p1 = new PVector(350,100);
  p2 = new PVector(250,350);
  p3 = new PVector(100,200);
}

void draw(){
  background(255);
  line(p0.x, p0.y, p1.x, p1.y);
  line(p1.x, p1.y, p2.x, p2.y);
  line(p2.x, p2.y, p3.x, p3.y);
  
  if(t < 1)       x = PVector.add(PVector.mult(p0, 1-t), PVector.mult(p1, t));
  else if(t < 2)  x = PVector.add(PVector.mult(p1, 2-t), PVector.mult(p2, t-1));
  else if(t < 3)  x = PVector.add(PVector.mult(p2, 3-t), PVector.mult(p3, t-2));
  else if(t < 4)  x = PVector.add(PVector.mult(p3, 4-t), PVector.mult(p2, t-3));
  else if(t < 5)  x = PVector.add(PVector.mult(p2, 5-t), PVector.mult(p1, t-4));
  else if(t < 6)  x = PVector.add(PVector.mult(p1, 6-t), PVector.mult(p0, t-5));
  else t=0;
  ellipse(x.x, x.y, 10, 10); 
  t += a;
}