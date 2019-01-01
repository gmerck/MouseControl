#include<Servo.h>

Servo serX;
Servo serY;

String serialData;  //capture data as String

void setup() {
  serX.attach(D6);  //on NodeMCU, use pin D6 for X axis servo
  serY.attach(D5);  //and D5 for Y axis servo
  Serial.begin(115200);
  Serial.setTimeout(10);  //tip thanks to Michael Reeves
  serX.write(0);  //Begin calibration test for X servo
  delay(500);
  serX.write(180);
  delay(500);
  serX.write(0);  //End calibration test for X servo
  serY.write(0); //Begin calibration test for Y servo
  delay(500);
  serY.write(180);
  delay(500);
  serY.write(0);  //End calibration test for Y servo
  
}

void loop() {
  if(Serial.available() > 0){  //If serial is working...
  serialData = Serial.readString();
  Serial.println(("serialread is : ") + (serialData));
  serX.write(parseDataX(serialData));  //set serX to the parsed value from down below here
  serY.write(parseDataY(serialData));  //set serY to the parsed value from under the one above
  }
}

int parseDataX(String data) {  //parse out some info.  it comes in as "XxxYyyy so first strip out all but the numbers by...
  data.remove(data.indexOf("Y"));  //Get everything before the "Y", so left with "Xxxx"
  data.remove(data.indexOf("X"), 1); //then take off the "X", so left wiht numbers

  return data.toInt();  //make that data in to an interger
}

int parseDataY(String data) {
  data.remove(0, data.indexOf("Y") + 1);  //parse out everything 1 char after the Y in the sequence
  
  return data.toInt();  //make that data in to an interger
}
