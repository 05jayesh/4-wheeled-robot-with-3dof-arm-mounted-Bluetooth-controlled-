#include<AFMotor.h>
#include<Servo.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

Servo servo1;
Servo servo2;

void setup() {
  // put your setup code here, to run once:
servo1.attach(9);
servo2.attach(10);
servo1.write(90);
servo2.write(90);

Serial.begin(9600);

motor1.setSpeed(255);
motor2.setSpeed(255);
motor3.setSpeed(255);
motor4.setSpeed(255);

}

void loop() {
  // put your main code here, to run repeatedly:

char c;

    if (Serial.available())
    {  
        c = Serial.read();
        Serial.write(c);

     switch(c)
     { 
      case 'w':
        motor4.run(FORWARD);
        motor3.run(FORWARD);
       //9658* delay (100);
        break;

      case 'a':
        //motor3.run(FORWARD);
        motor4.run(BACKWARD);
       // delay (100);
        break;

      case 's':
        motor4.run(BACKWARD);
        motor3.run(BACKWARD);
        //delay (100);
        break;

      case 'd':
        //motor3.run(BACKWARD);
        motor4.run(FORWARD);
        //delay (100);
        break; 

       case 'x':
        motor3.run(RELEASE);
        motor4.run(RELEASE);
        servo1.write(130);
        servo2.write(50);
        break;

       case 'u':
        motor1.run(FORWARD);
        delay (50);
        motor1.run(RELEASE);
        break;

       case 'j':
        motor1.run(BACKWARD);
        delay (50);
        motor1.run(RELEASE);
        break;

       case 'h':
        motor2.run(FORWARD);
        delay (50);
        motor2.run(RELEASE);
        break;

       case 'k':
        motor2.run(BACKWARD);
        delay (50);
        motor2.run(RELEASE);
        break;

       case 'm':
        servo1.write(50);
        servo2.write(130);
        break;
        }
     }
 
}
