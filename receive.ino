#include<Servo.h>                                           //include servo library
Servo speedcontrolur;                                        //declare motors
Servo speedcontrolul;                                        //-
Servo speedcontroldr;                                        //-
Servo speedcontroldl;                                        //-
int speedul = 0;
int speedur = 0;
int speeddl = 0;
int speeddr = 0;
int ur;
int ul;
int dr;
int dl;
void setup() {
  speedcontrolur.attach(8);                                  //assign motors to pins
  speedcontrolul.attach(9);                                  //-
  speedcontroldr.attach(10);                                 //-
  speedcontroldl.attach(11);                                 //-
  speedcontrolur.writeMicroseconds(speedur);                   //intialize the speed of motor
  speedcontrolul.writeMicroseconds(speedur);
  speedcontroldr.writeMicroseconds(speeddr);
  speedcontroldl.writeMicroseconds(speeddl);

  Serial.begin(9600);
  Serial.println("receiver");
}

void loop() {
  if (Serial.available() > 0) {
    int command = Serial.read();
    Serial.print('k');
    if (command == 'u' && speedur < 1700) {
      speedur = speedur + 1;
      speedul = speedul + 1;
      speeddr = speeddr + 1;
      speeddl = speeddl + 1;
      ul = 0;
      ur = 0;
      dl = 0;
      dr = 0;
    }
    if (command == 'd' && speedur > 100) {
      speedur = speedur - 1;
      speedul = speedul - 1;
      speeddr = speeddr - 1;
      speeddl = speeddl - 1;
      ul = 0;
      ur = 0;
      dl = 0;
      dr = 0;
    }
    if (command == 'f' && speedur < 1600) {
      dr = 300;
      dl = 300;
    }
    if (command == 'b' && speedur < 1600) {
      ur = 300;
      ul = 300;
    }

    if (command == 'l' &&  speedur < 1600) {
      ur = 300;
      dr = 300;

    }
    if (command == 'r' && speedur < 1600) {
      ul = 300;
      dl = 300;
    }

  }
  int k = speedur + ur;
  Serial.println(k);
  Serial.print(ur);
  speedcontrolur.writeMicroseconds(speedur + ur);
  speedcontrolul.writeMicroseconds(speedul + ul);
  speedcontroldr.writeMicroseconds(speeddr + dl);
  speedcontroldl.writeMicroseconds(speeddl + dl);



}

