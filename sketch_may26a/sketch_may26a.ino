void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  char incomingByte;

  if(Serial.available() > 0) {
    
    incomingByte = Serial.read();

    if(incomingByte == '1') {
      digitalWrite(13, HIGH);
    } else if(incomingByte == '0') {
      digitalWrite(13, LOW);
    }
  }
}
