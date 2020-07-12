
#include <Servo.h>

Servo feedbackMotor;  // create servo object to control a servo


int potpin = A3;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin
int LED = 8;

void setup() {
  feedbackMotor.attach(9);  // attaches the Servo Motor on pin 9 to the servo object
 

  pinMode(LED, OUTPUT);  // we will attach an Led to pin 8 and it will turn on if the servo angle is greter than 90 degrees 
}

void loop() {
  
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  feedbackMotor.write(val);                  // sets the servo position according to the scaled value read from the source motor 

  
  
  delay(15);  // waits for the servo to get there

  if(val > 15)  // if the source Motor is moving turn the LED on
  
   digitalWrite(LED, HIGH);
  
  else 
  
 digitalWrite(LED, LOW);

 delay(15); 
}
