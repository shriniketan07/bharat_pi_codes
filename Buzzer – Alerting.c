int buzzer =23 ; // set the buzzer control digital IO pin
void setup() {
 pinMode(buzzer, OUTPUT); // set pin 23 as output
}
void loop() {
 for (int i = 0; i < 80; i++) {
digitalWrite(buzzer, HIGH); // make a sound
delay(1); // send high signal to buzzer
digitalWrite(buzzer, LOW); // delay 1ms
34
delay(1); // send low signal to buzzer
}
 delay(50);
 for (int j = 0; j < 100; j++) {
digitalWrite(buzzer, HIGH); //make another sound
delay(2);
digitalWrite(buzzer, LOW); // delay 2ms
delay(2);
}
 delay(100);
}
