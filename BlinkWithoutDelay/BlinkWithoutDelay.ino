#include <Arduino.h>

// constants won't change. Used here to set a pin number:
const int ledPinG = 4;// the number of the LED pin
const int ledPinY = 3;
const int ledPinR = 5; 
const int ledPinW = 6;

// Variables will change:
int ledState = LOW;             // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change:
const long interval = 7000;           // interval at which to blink (milliseconds)

void setup() {
  // set the digital pin as output:
  pinMode(ledPinY, OUTPUT);
  pinMode(ledPinG, OUTPUT);
  // pinMode(ledPinR, OUTPUT);
}

void loop() {
  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis = millis();

  unsigned long elapsed = currentMillis - previousMillis;
  if (elapsed >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    /*if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    */

    // set the LED with the ledState of the variable:
    // digitalWrite(ledPinR, ledState);

  }
  int level = elapsed*255/interval;
  analogWrite(ledPinG,level);
  analogWrite(ledPinR,(level+50)*3%255);
  analogWrite(ledPinY,(level+100)%255);
  analogWrite(ledPinW,(level+150)%255);

}
