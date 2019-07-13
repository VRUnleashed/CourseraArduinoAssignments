int sensorValue = 0;

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  sensorValue = analogRead(A0);
  
  if(sensorValue > 100){
    digitalWrite(13, LOW);
  } else if(sensorValue < 100){
    digitalWrite(13, HIGH);
  }
}
