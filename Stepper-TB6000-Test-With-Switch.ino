const int LED = 13;
const int stepDirPlus = 2;
const int stepPullPlus = 3;
const int dirSwitch = 7;
int dirSelect = 0;
void setup() {
    // put your setup code here, to run once:
  pinMode(stepDirPlus, OUTPUT);
  pinMode(stepPullPlus, OUTPUT);
  digitalWrite(stepDirPlus, HIGH); // LOW = CCW HIGH = CW 
}

void loop() {
  // put your main code here, to run repeatedly:
  dirSelect = digitalRead(dirSwitch);
  digitalWrite(stepDirPlus, dirSelect); // LOW = CCW HIGH = CW
  digitalWrite(stepPullPlus, LOW);
  digitalWrite(stepPullPlus, HIGH);
  digitalWrite(LED, HIGH);
  delayMicroseconds(5000);  // Controls the Speed
  digitalWrite(LED, LOW);
}
