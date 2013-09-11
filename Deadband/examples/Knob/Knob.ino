// This is a version of the Arduino "Knob" example which has been modified
// to use the Deadband library ( https://github.com/cellularmitosis/Deadband )
//
// If you've ever used a mill or a lathe which had some slop in the carriage, 
// or an old car which had slop in the steering, that's deadband.
//
// The Deadband library allows you to create "digital slop".
//
// The amount of deadband used below is somewhat conservative.  For a
// more gross demonstration, try running the stock "Knob" example, but
// unplug your potentiometer from A0, such that A0 is left floating.
// Your servo should start going crazy.  Now try the same, but use this
// example with 6 (or more) bits of deadband.  The servo should sit still.
//
// by Jason Pepas
// v0.1, Sept 10, 2013
// This sample code is released into the public domain.
//
// Original comment header follows:
// ----
//
// Controlling a servo position using a potentiometer (variable resistor) 
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

#include <Servo.h> 
#include "Deadband.h"

Servo myservo;  // create servo object to control a servo 

int potpin = A0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin 

// declare the deadband filter "object".
DeadbandFilter *filter = NULL;

void setup() 
{
  // create a filter which will give the potentiometer 4 bits (16 counts)
  // of deadband.  Deadband works just like "backlash" in gears.
  int widthOfDeadbandInBits = 4;
  filter = createDeadbandFilter(widthOfDeadbandInBits);

  myservo.attach(12);  // attaches the servo on pin 9 to the servo object 
} 

void loop() 
{
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 

  // apply the deadband filter to the values read from the ADC.
  // note that we will lose the top 16 counts of range after
  // filtering (ADC range will be 0 -> 1007, not 0 -> 1023).
  val = deadband(filter, val); 

  val = map(val, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
  myservo.write(val);                  // sets the servo position according to the scaled value 
  delay(10);                           // waits for the servo to get there 
}


