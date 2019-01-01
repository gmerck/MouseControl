import processing.serial.*; //<>//
String val;
int posX;
int posY;
Serial myPort;
int baud = 115200;
String serPort = "/dev/ttyUSB0";

void setup() {
  myPort = new Serial(this, serPort, baud);
  myPort.bufferUntil('\n');
  size(600, 600); 
  noStroke();
  rectMode(CENTER);
}

void draw() {
  background(104); 
  fill(255, 104);
  ellipse(mouseX, mouseY, 10, 10);
  rectMode(CENTER);
  fill(255, 204);
  posX = (mouseX / (600/180));
  posY = (mouseY / (600/180));
  val = (("X") + (posX) + ("Y") + (posY));
  myPort.write(val); //<>//
  delay(50);
} //<>//
