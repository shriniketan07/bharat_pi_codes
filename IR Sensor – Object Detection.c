#define SENSOR_PIN 23 //Bharat Pi pin GPIO18 connected to OUT pin of IR obstacle
avoidance sensor
int lastState = HIGH; //the previous state from the input pin
int currentState; //the current reading from the input pin
void setup() {
 // initialize serial communication at 115200 bps
 Serial.begin(115200);
 // initialize the board pin as an input
 pinMode(SENSOR_PIN, INPUT);
}
void loop() {
 // read the state of the the input pin:
 currentState = digitalRead(SENSOR_PIN);
 if (lastState == HIGH && currentState == LOW)
 Serial.println("The obstacle is detected");
 else if (lastState == LOW && currentState == HIGH)
 Serial.println("The obstacle is cleared");
 delay(50);
 // save the the last state
 lastState = currentState;
}
