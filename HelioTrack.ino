#include <Servo.h>
Servo myservo;
#define LDR_1 A0
#define LDR_2 A1
int pos = 90;
int Resistance = 20;
void setup(){
myservo.attach(4);
pinMode(LDR_1, INPUT);
pinMode(LDR_2, INPUT);
myservo.write(pos);
delay(1000);
}
void loop(){
int value_1 = analogRead(LDR_1);
int value_2 = analogRead(LDR_2);
if((abs(value_1 - value_2) <= Resistance) || (abs(value_2 - value_1) <= Resistance)) {
}else {
if(value_1 > value_2)
{
pos = pos+1;
}
if(value_1 < value_2)
{
pos = pos-1;
}
}
if(pos > 180) {pos = 180;}
if(pos < 0) {pos = 0;}
myservo.write(pos);
delay(50);
}
