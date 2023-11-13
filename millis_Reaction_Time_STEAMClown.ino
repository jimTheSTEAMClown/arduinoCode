// millis() Test - Reaction Time #3 //

const int LED = 2;
const int button = 8;
int button_status = -1;
long rand_number;
long unsigned current_time = -1;
long unsigned LED_off_time = -1;
long unsigned reaction_time = -1;
int doing_stuff_count = -1;



void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  Serial.println("Test Your Reaction Time in 3 Seconds");
  Serial.println("Press the button To Start");
  Serial.println("Then Press Again when the LED goes ON");
  button_status = digitalRead(button);
  while(button_status == 1) 
  {
    button_status = digitalRead(button);
  }
  delay(3000);
}

void loop()
{
  digitalWrite(LED, HIGH);
  LED_off_time = millis();
  button_status = digitalRead(button);
  while(button_status == 1) 
  {
    button_status = digitalRead(button);
  }
  reaction_time = millis() - LED_off_time;
  digitalWrite(LED, LOW);
  delay(100); // This delay is because the next button Check is fast
  Serial.print("\nYour Reaction Time Is ");
  Serial.println(reaction_time);
  Serial.println("\nTest Your Reaction Time Again");
  Serial.println("Press the button To Start");
  Serial.println("Then Press Again when the LED goes ON");
  rand_number = random(500,3000);
  button_status = digitalRead(button);
  while(button_status == 1) 
  {
    button_status = digitalRead(button);
  }
  delay(rand_number);
}
