/* 
 *  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * pin 3 to GND
*/
#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Servo.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {14, 15, 16, 17}; 
byte colPins[COLS] = {24, 26, 20, 21}; 
int pos = 0;

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Servo myservo;

int i;
const int ir=A0;
const int led1=52;
const int ldr=22;
const int led=7;
int value=0;

void setup(){
  Serial.begin(9600);
   Serial1.begin(9600);
  lcd.begin(16, 2);
  myservo.attach(9); 
  pinMode(led,OUTPUT);
  pinMode(ldr,INPUT);
pinMode(led1,OUTPUT);
digitalWrite(led1,LOW);

}
  
void loop(){
  lcd.clear();
  if(Serial.available()>0){
       analogWrite(led,Serial.read()); 
       }
       if(Serial1.available()>0){
        int z=Serial1.read();
        //Serial.println(z);
        switch(z){
          case 254: digitalWrite(led,HIGH);
          break;
          case 255: digitalWrite(led,LOW);
          break;
        }
        }
        
       value=digitalRead(ldr);
if(value==1)
{
  digitalWrite(led1,HIGH);
delay(100);
}
else{
   digitalWrite(led1,LOW);
delay(100); 
}
  if(digitalRead(ir)==1){
  lcd.print(" Passkey: ");
  delay(200);
  char customKey = customKeypad.getKey();
  if (customKey){
    Serial.println(customKey);
    lcd.setCursor(0, 1);
    lcd.print("*");
    String a="";
    a+=char(customKey);
    i=1;
  while(i<4){
    customKey = customKeypad.getKey();
  if (customKey){
    Serial.println(customKey);
    lcd.setCursor(i, 1);
    lcd.print("*");
    a+=char(customKey);
    i++;
  }
  }
  Serial.println(a);
  lcd.clear();
  lcd.setCursor(0, 1);
  
  if(a=="1234"){
  lcd.print("Welcome Asmita!");
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }}
  
  else if(a=="2345"){
  lcd.print("Welcome Shruti!");
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }}
  
  else{
  lcd.print("Invalid Access");}
  delay(1000);
  }
  }
  
}
