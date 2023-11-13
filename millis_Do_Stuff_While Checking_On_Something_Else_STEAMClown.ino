// millis() Test #2 //
int LED = 13;
long unsigned current_time = -1;
long unsigned past_time = -1;
long unsigned interval_time = 1000;
int doing_stuff_count = -1;


void setup()
{
  past_time = millis();
  doing_stuff_count = 0;
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop()
{
  current_time = millis();
  if (current_time - past_time >= interval_time) {
    /* Event code */ 
    Serial.print("Just Checked That Thing I need To Check Each Second. ");
    Serial.print("Current Time Is: ");
    Serial.println(current_time);
    /* Update the timing for the next time around */
    past_time = current_time;
    doing_stuff_count = 0;    
  }
  Serial.print("Doing Other Stuff ");
  doing_stuff_count++;
  Serial.print(doing_stuff_count);
  Serial.print(" between ");
  Serial.print(past_time);
  Serial.print(" and ");
  Serial.println(current_time);
}
