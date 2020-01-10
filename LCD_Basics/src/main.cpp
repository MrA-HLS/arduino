#include <Arduino.h>
#include <Wire.h> // Library for I2C communication
#include <LiquidCrystal_I2C.h> // Library for LCD


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
// create class instance named lcd with address 0x27 and 16x2 size
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 02);

//see LED_Basics.ino for notes
const int ledPinW = 11;
unsigned long previousMillis = 0;   
const long interval = 7000; 

void setup() {
  // Initialize the LCD:
  lcd.init();
  lcd.backlight();
  lcd.setCursor(1,0);

  //set led pinMode
  pinMode(ledPinW,OUTPUT);
}
void loop() {
  unsigned long currentMillis = millis();
  unsigned long elapsed = currentMillis - previousMillis;
  if (elapsed >= interval) {
    previousMillis = currentMillis;
  }

  int level = elapsed*255/interval;

  // set the white light to pulse in time with the interval using analogWrite()
  analogWrite(ledPinW,level);

  lcd.clear();
  // lcd.autoscroll();
  lcd.setCursor(1,0);
  lcd.print("White level is:");
  lcd.setCursor(1,1);
  lcd.print(level);

  // wait around so we can see things?
  delay(50);
  
}
