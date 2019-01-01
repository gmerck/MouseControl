#include<Servo.h>

Servo serX;
Servo serY;

String serialData;

void setup() {
  serX.attach(D6);
  serY.attach(D5);
  Serial.begin(115200);
  Serial.setTimeout(10);
  serX.write(0);
  delay(500);
  serX.write(180);
  delay(500);
  serX.write(0);
  serY.write(0);
  delay(500);
  serY.write(180);
  delay(500);
  serY.write(0);
  
}

void loop() {
  if(Serial.available() > 0){
  serialData = Serial.readString();
  Serial.println(("serialread is : ") + (serialData));
  serX.write(parseDataX(serialData));
  serY.write(parseDataY(serialData));
  }
}

void serialEvent() {

}

int parseDataX(String data) {
  data.remove(data.indexOf("Y"));
  data.remove(data.indexOf("X"), 1);

  return data.toInt();
}

int parseDataY(String data) {
  data.remove(0, data.indexOf("Y") + 1);
  
  return data.toInt();
}
