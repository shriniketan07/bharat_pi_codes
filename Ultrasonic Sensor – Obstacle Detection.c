#include <NewPing.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define TRIG_PIN 33
#define ECHO_PIN 32
const int ledPin1 = 25;
const int ledPin2 = 26;
const int ledPin3 = 27;
#define MAX_DISTANCE 200 //Maximum distance to measure(cms)
// Create a NewPing object
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);
// Change 0x27 to your LCD I2C address if different
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
lcd.init();
lcd.backlight();
lcd.print("Ultrasonic Sensor");
lcd.print("By Bharath Pi");
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);
}
void loop() {
delay(100);
unsigned int distance = sonar.ping_cm();
// Display the distance on the LCD
lcd.setCursor(0, 1);
lcd.print("Distance: ");
lcd.print(distance);
lcd.print(" cm ");
if (distance<=10){
   digitalWrite(ledPin1, HIGH);
   digitalWrite(ledPin2, LOW);
   digitalWrite(ledPin3, LOW);}
   else if (distance>10 && distance <=20)
   {
    digitalWrite(ledPin1, LOW);
   digitalWrite(ledPin2, HIGH);
   digitalWrite(ledPin3, LOW);
  
   }
    else if (distance>20 && distance <=40)
   {
    digitalWrite(ledPin1, HIGH);
   digitalWrite(ledPin2, LOW);
   digitalWrite(ledPin3, HIGH);}
   else{
    digitalWrite(ledPin1, LOW);
   digitalWrite(ledPin2, LOW);
   digitalWrite(ledPin3, HIGH);
   }
  
    
}
