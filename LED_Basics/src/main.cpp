// explicitly include the basic Arduino header - most arduino tools include it by default
#include <Arduino.h>

// you can use libraries by adding them to the platformio.ini lib_deps section
#include <RGBLed.h>

// the osoyoo shield we are using to break out the pins into connectors uses labels that correspond to the pins
// defined in the Arduino library:
// see Arduino/hardware/arduino/avr/variants/mega/pins_arduino.h for more names and pin mappings

// the 'analog' pins use the int identifiers A0-A15 (A0-A5 for the connectors) e.g:
// const int the-pin-for-my-cool-thingamabob = A4 // use for whatever is plugged into port A4

// the 'digital' pins use the ints 2-11 respectively e.g:
// const int the-other-nifty-device = 3 // use for whatever is plugged into port D3

// NB not all pins will function identically
// the naming of pins is NOT OBVIOUSLY related to their function:
// ALL accessible pins support digital input and output
// the 'analog' (A0-A5 and maybe digital 5) pins are for analog input; they DO NOT support analog output
// 'digital' pins 2-13 support PWM/pseudo-analog output via the analogWrite() function
// 'digital' pins 2 and 3 have dedicated hardware interrupts
// 'digital' pins 6 and 10-13 support pin change interrupts
// 'digital' pin 13 also controls an amber LED on the Arduino board

// Globals *************************************************************************
// use global constants to set pin numbers for where things are plugged in
// this isn't necessary, but it will make your code easier to maintain

const int ledPinG = 13;
const int ledPinY = A3;
const int ledPinR = 12; 
const int ledPinW = 11;

// Set up the RGB LED to use digital pins 22-24
RGBLed rgb = RGBLed(ANODE,22,23,24);


// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change:
const long interval = 7000;           // base interval at which to pulse (milliseconds)

// Setup  *************************************************************************
// setup runs once every startup: use it to setup hardware or libraries
void setup() {
  // setting the pinMode() is usually unnecessary with the arduino mega, but it helps keep things organized
  pinMode(ledPinY, OUTPUT);
  pinMode(ledPinG, OUTPUT);
  pinMode(ledPinR, OUTPUT);
  pinMode(ledPinW,OUTPUT);

  // init for RGB
  rgb.setup();
}

// Main Program *********************************************************************
// the loop executes repeatedly after setup finishes
// put your main code here that should be running all the time
// note that there is not guarantee of how long it will take for this loop to repeat:
// the more complex your program, the longer it will take for the loop to repeat
// use timers and interrupts if you need time or latency sensitive actions
void loop() {

  // get the current timer value so we can check how much time has elapsed
  unsigned long currentMillis = millis();
  
  // find out how many ms have elapsed since the last reset
  unsigned long elapsed = currentMillis - previousMillis;
  if (elapsed >= interval) {
    // reset things once we pass the timing interval
    previousMillis = currentMillis;
  }
  // set a level 0-255 based on how much time has passed
  int level = elapsed*255/interval;

  // set the yellow light to always on with digitalWrite()
  // you can also use 1 and 0 for HIGH and LOW respectively
  digitalWrite(ledPinY,HIGH);

  // set the white light to pulse in time with the interval using analogWrite()
  analogWrite(ledPinW,level);

  // set the green light to pulse in reverse of white
  analogWrite(ledPinG,255-level);

  // set the red light to pulse at 3x the rate of the white
  analogWrite(ledPinR,(level*3%255));

  // set the RGB led to color change based on interval harmonics
  rgb.on(Color(level,level*2%255,level*3%255));


  // try out some blinking for homework:
  // rgb.blink(Color(255,0,255),6000)
}
