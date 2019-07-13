#include <EEPROM.h>
#include <String.h>

int data;
byte smallData;

void setup() {
  int i;
  Serial.begin(9600);
  Serial.println("Enter your command");
}

void loop() {
  String command;
  
  if(Serial.available()) {
    command = Serial.readString();
  }

  if(command[0] == 'r') {
    int pos;
    pos = command.substring(5, command.length()).toInt();
    Serial.print("\nData stored at address ");
    Serial.print(pos);
    Serial.print(" is: ");
    Serial.println(EEPROM.read(pos), DEC);
  }

  if(command[0] == 'w') {
    int loc, val, i, j;
    String com;
    char temp[10], temp1[10];
    
    com = command.substring(6, command.length());
    
    i = 0;
    while(com[i] != ' ') {
      temp[i] = com[i];
      i++;
    }

    loc = atoi(temp);
    
    j = i + 1;
    i = 0;
    while(com[j] != '\0') {
      temp1[i] = com[j];
      i++;
      j++;
    }
    
    val = atoi(temp1);
    
    data = val;
    smallData = data & 0xFF;
    EEPROM.write(loc, smallData);
    smallData = (data >> 8);
    EEPROM.write(loc + 1, smallData);
    Serial.println("Successfully written!");
  }
}
