#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int led = 32; //Pin that the LED is attached to
int sensor = 23; //Pin that the sensor is attached to
int state = HIGH; // by default, no motion detected
int val = 0; // variable to sensor status (value)
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
lcd.init();
lcd.backlight();

lcd.setCursor(0, 0);
lcd.print("HELLO");
lcd.setCursor(0, 1);
lcd.print("I'm Shashidhar");
delay(2000);
lcd.clear();
pinMode(led, OUTPUT); // Initialize LED as an output
pinMode(sensor, INPUT); // Initialize sensor as an input
Serial.begin(115200); // initialize serial
}
void loop(){
delay(100);
val = digitalRead(sensor); // read sensor value
lcd.setCursor(0, 1);

if (val == HIGH) { // check if the sensor is HIGH
digitalWrite(led, HIGH); // turn LED ON
delay(100); // delay 100 milliseconds
if (state == LOW) {
lcd.print("Motion detected!");
state = HIGH; // update variable state to HIGH
}
}
else {
digitalWrite(led, LOW); // turn LED OFF
delay(100); // delay 200 milliseconds
if (state == HIGH){
lcd.print("Motion stopped!");
state = LOW; // update variable state to LOW
}
}
}
