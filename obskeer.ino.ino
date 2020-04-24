#include "DCMDriverL298.h"

#define DCMOTORDRIVERL298_1_PIN_INT1  22
#define DCMOTORDRIVERL298_1_PIN_ENB 4
#define DCMOTORDRIVERL298_1_PIN_INT2  24
#define DCMOTORDRIVERL298_1_PIN_ENA 3
#define DCMOTORDRIVERL298_1_PIN_INT3  28
#define DCMOTORDRIVERL298_1_PIN_INT4  26
#define DCMOTORDRIVERL298_2_PIN_INT1  30
#define DCMOTORDRIVERL298_2_PIN_ENB 6
#define DCMOTORDRIVERL298_2_PIN_INT2  32
#define DCMOTORDRIVERL298_2_PIN_ENA 5
#define DCMOTORDRIVERL298_2_PIN_INT3  34
#define DCMOTORDRIVERL298_2_PIN_INT4  36

DCMDriverL298 dcMotorDriverL298_1(DCMOTORDRIVERL298_1_PIN_ENA,DCMOTORDRIVERL298_1_PIN_INT1,DCMOTORDRIVERL298_1_PIN_INT2,DCMOTORDRIVERL298_1_PIN_ENB,DCMOTORDRIVERL298_1_PIN_INT3,DCMOTORDRIVERL298_1_PIN_INT4);
DCMDriverL298 dcMotorDriverL298_2(DCMOTORDRIVERL298_2_PIN_ENA,DCMOTORDRIVERL298_2_PIN_INT1,DCMOTORDRIVERL298_2_PIN_INT2,DCMOTORDRIVERL298_2_PIN_ENB,DCMOTORDRIVERL298_2_PIN_INT3,DCMOTORDRIVERL298_2_PIN_INT4);
const int trigpin = 50;
const int echopin = 52;

void setup()
{
  // put your setup code here, to run once:
pinMode(trigpin, OUTPUT);
pinMode(echopin, INPUT);


}
long duration, distance;

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigpin, LOW);
delayMicroseconds(2);
digitalWrite(trigpin, HIGH);
delayMicroseconds(10);
digitalWrite(trigpin, LOW);
duration = pulseIn(echopin, HIGH);
distance = duration/50.2;
if(distance<20)
{
    dcMotorDriverL298_2.stopMotors();
    //Stop both motors
    dcMotorDriverL298_1.stopMotors();
    delay(10);
  dcMotorDriverL298_1.setMotorA(0,0);
    dcMotorDriverL298_1.setMotorB(255,0);
     dcMotorDriverL298_2.setMotorA(0,0);
    dcMotorDriverL298_2.setMotorB(255,1);
  delay(1000);
}
else
{
   dcMotorDriverL298_1.setMotorA(255,1);
    dcMotorDriverL298_1.setMotorB(255,0);
     dcMotorDriverL298_2.setMotorA(255,0);
    dcMotorDriverL298_2.setMotorB(255,1);
}
delay(0);
}
