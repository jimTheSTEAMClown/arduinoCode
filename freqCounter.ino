/*
 * Modified by STEAM Clown to not use the LCD and just Serial.print
 * https://create.arduino.cc/projecthub/jasirtp/arduino-frequency-counter-with-16x2-lcd-display-c99779
 * The MIT License (MIT)
 * 
 * Copyright (c) 2016 RuntimeProjects
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

//#include <LiquidCrystal.h>

//LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

long microSecs;
long freq;
int lastBit;
int nowVal;
long secs;
long maxHz;
long minHz;
long minmax;
void setup() {
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  //lcd.begin(16, 2);
  // Print a message to the LCD.
  //lcd.print("Loading...");
  pinMode(A1,INPUT);
  pinMode(A5,OUTPUT);
  microSecs = micros();
  freq = 0;
  lastBit = 0;
  nowVal =0;
  maxHz=0;
  minHz=0;
  minmax=0;
  secs = millis();
  //Serial.begin(9600);
}
int x=0;
void loop() {


  if ((microSecs+20)<micros()){
      nowVal=digitalRead(A1);
 
      if (lastBit!=nowVal) {
        lastBit=nowVal;
        freq=freq+1;
      }
      if (freq>maxHz){
        maxHz=freq;
      }
      if (freq<minHz){
        minHz=freq;
      }
      //lcd.clear();
      //lcd.print();
      microSecs = micros();
  }
  if (secs+1000<millis()){

    if (minmax+300000<millis())
    {
      minmax=millis();
      minHz=freq;
      maxHz=freq;
      
    }
      
//      lcd.clear();
//      lcd.print((freq/2));
//      lcd.print("hz");
//      lcd.setCursor(0,1);
//      lcd.print("+: ");
//      lcd.print(maxHz);
//      lcd.print(" -: ");
//      lcd.print(minHz);

      
      Serial.print((freq/2));
      Serial.println("hz");
      
      Serial.print("+: ");
      Serial.print(maxHz);
      Serial.print(" -: ");
      Serial.print(minHz);
      Serial.println(" ");
      freq=0;
      secs=millis();
      
  }

}
