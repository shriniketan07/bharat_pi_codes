
int ssPin = 32;
int ledPin = 33;
//int sensorvalue = 0;
boolean val=0;
int state = HIGH;
void setup(){
  
  Serial.begin(115200);
  pinMode(ledPin,OUTPUT);
  pinMode(ssPin,INPUT);
}
void loop(){
  
  val= digitalRead(ssPin);
  Serial.println(val);
  if(val == HIGH){
    digitalWrite(ledPin,HIGH);
    delay(100);

    if(state == LOW){
      Serial.println("Sound Detected");
      state = HIGH;
    }

  }
  else{
    digitalWrite(ledPin,LOW);
    delay(100);

     if(state == HIGH){
      Serial.println("Sound Stopped");
      state = LOW;
    }
  }
}
