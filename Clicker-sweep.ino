/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep

 modified by Anton Gladyshev
*/ 

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
int pos = 0;    // variable to store the servo position 
long randnumbernp;
long randnumberdiff;
long delayvalue = 25000; 

void setup() 
{
  //Serial.begin(9600); 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  // if analog input pin 0 is unconnected, random analog
  // noise will cause the call to randomSeed() to generate
  // different seed numbers each time the sketch runs.
  // randomSeed() will then shuffle the random function.
  randomSeed(analogRead(0));
  myservo.write(140);
   delay(120000);
}

void loop() 
{ 
  randnumbernp   = random(0, 10); //0,1,2,3,4 left; 5,6,7,8,9 right
  randnumberdiff = random(0, 100);
  if (randnumbernp <= 4)
  {
    delayvalue = delayvalue - randnumbernp;
  }
  else
  {
    delayvalue = delayvalue + randnumbernp;
  }
  delay(delayvalue);
  if (delayvalue <= 22000)
  {
    delayvalue = 25000;
  }
  if (delayvalue >= 27000)
  {
    delayvalue = 25000;
  }
   for(pos = 140; pos>=95; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 95; pos <= 140; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }
} 

