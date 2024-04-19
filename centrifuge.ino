#include <Servo.h>
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

int light_pin = 2;
int light_status = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(light_pin, INPUT);
   myservo.attach(9);
  light_status = 0;
}

// the loop function runs over and over again forever
void loop() {
  light_status = digitalRead(light_pin);
  digitalWrite(LED_BUILTIN, light_status);
  Serial.println(light_status);
  pos = 10;
  myservo.write(pos);
  delay(10000);
  pos = 90;
  myservo.write(pos);
  delay(10000);
  pos = 10;
  myservo.write(pos);
  delay(100000);

/*  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(500);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(100); 
*/                      // wait for a second
}
