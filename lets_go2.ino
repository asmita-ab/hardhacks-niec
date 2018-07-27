#include <Servo.h>

int pos = 0;
Servo myservo;
/*Connections:
 * Connect the pins described below:
Arduino Pin 2 to Pin 9.
Arduino Pin 3 to Pin 10.
Arduino Pin 4 to Pin 4.
Arduino Pin 5 to Pin 2.
Arduino Pin 6 to Pin 1.
Arduino Pin 8 to Pin 7.
Arduino Pin 9 to Pin 6.
GND to Pin 3 and Pin 8 each connected with 220 ohm resistors.
*/
int a = 2;  //For displaying segment "a"
int b = 3;  //For displaying segment "b"
int c = 4;  //For displaying segment "c"
int d = 5;  //For displaying segment "d"
int e = 6;  //For displaying segment "e"
int f = 8;  //For displaying segment "f"
int g = 9;  //For displaying segment "g"
int i;
const int ip1=11;
const int ip2=12;
int k=9;

void setup(){
  pinMode(a, OUTPUT);  //A
  pinMode(b, OUTPUT);  //B
  pinMode(c, OUTPUT);  //C
  pinMode(d, OUTPUT);  //D
  pinMode(e, OUTPUT);  //E
  pinMode(f, OUTPUT);  //F
  pinMode(g, OUTPUT);  //G
  Serial.begin(9600);
  myservo.attach(10);
  pinMode(ip1, INPUT);
  pinMode(ip2, INPUT);
}
  void displayDigit(int digit)

{
 //Conditions for displaying segment a
 if(digit!=1 && digit != 4)
 digitalWrite(a,HIGH);
 
 //Conditions for displaying segment b
 if(digit != 5 && digit != 6)
 digitalWrite(b,HIGH);
 
 //Conditions for displaying segment c
 if(digit !=2)
 digitalWrite(c,HIGH);
 
 //Conditions for displaying segment d
 if(digit != 1 && digit !=4 && digit !=7)
 digitalWrite(d,HIGH);
 
 //Conditions for displaying segment e 
 if(digit == 2 || digit ==6 || digit == 8 || digit==0)
 digitalWrite(e,HIGH);
 
 //Conditions for displaying segment f
 if(digit != 1 && digit !=2 && digit!=3 && digit !=7)
 digitalWrite(f,HIGH);
 if (digit!=0 && digit!=1 && digit !=7)
 digitalWrite(g,HIGH);
 
}
void turnOff()
{
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}

void loop(){
  turnOff();
  displayDigit(k);
  
  if(digitalRead(ip1)==1){
    if(k>0){
  for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  k--;
  turnOff();
  displayDigit(k);
  delay(2000);
  for (pos = 90; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
   myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  } 
   delay(1000);
  }}
  
  else if(digitalRead(ip2)==1){
    if(k<9){
  for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
   k++;
  turnOff();
  displayDigit(k);
  delay(2000);
  for (pos = 90; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  } 
   delay(1000);
  }}
}
