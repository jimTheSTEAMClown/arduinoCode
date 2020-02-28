// defines pins numbers
const int stepPin = 5; 
const int dirPin = 2; 
const int enPin = 8;
const int stepSpeedDelay=1000;
// const int pauseDelay=32699;
const int pauseDelay=3000;
void setup() {
  
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);

  pinMode(enPin,OUTPUT);
  digitalWrite(enPin,LOW);
  
}
void loop() {
  digitalWrite(enPin,LOW);
  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 2000; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(stepSpeedDelay); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(stepSpeedDelay); 
  }
  digitalWrite(enPin,HIGH);
  delay(pauseDelay); // One second delay
  
  digitalWrite(enPin,LOW);
  digitalWrite(dirPin,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 1000; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(stepSpeedDelay);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(stepSpeedDelay);
  }
  digitalWrite(enPin,HIGH);
  delay(pauseDelay);
  
}
