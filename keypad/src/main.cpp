/* @file EventSerialKeypad.pde
 || @version 1.0
 || @author Alexander Brevig
 || @contact alexanderbrevig@gmail.com
 ||
 || @description
 || | Demonstrates using the KeypadEvent.
 || #
 */
#include <Arduino.h>
#include <Keypad.h>
#include <LiquidCrystal_PCF8574.h>
#include <Wire.h>

// function proto
void keypadEvent(KeypadEvent key);

// set up lcd with default address
LiquidCrystal_PCF8574 lcd(0x27);

const uint8_t ROWS = 4; //four rows
const uint8_t COLS = 4; //four columns
char keys[ROWS][COLS] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};

uint8_t rowPins[ROWS] = {33, 35, 37, 39}; //connect to the row pinouts of the keypad
uint8_t colPins[COLS] = {41, 43, 45, 47}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
uint8_t ledPin = 13; 

boolean blink = false;
boolean ledPin_state;

// set lcd origin
uint8_t col = 0;
uint8_t row = 0;

void setup(){
  Serial.begin(9600);                   // Allow output to serial connection
  pinMode(ledPin, OUTPUT);              // Sets the digital pin as output.
  digitalWrite(ledPin, HIGH);           // Turn the LED on.
  ledPin_state = digitalRead(ledPin);   // Store initial LED state. HIGH when LED is on.
  keypad.addEventListener(keypadEvent); // Add an event listener for this keypad
  
  // Check that the LCD is connected
  Serial.println("Check for LCD");

  // See http://playground.arduino.cc/Main/I2cScanner how to test for a I2C device.
  Wire.begin();
  Wire.beginTransmission(0x27);
  int error = Wire.endTransmission();

  if (error == 0) {
    Serial.println("LCD found.");
    lcd.begin(16, 2); // initialize the lcd
    lcd.setBacklight(150);
    lcd.home();
    lcd.clear();
    lcd.noCursor();
    lcd.setCursor(col,row);

  } else {
    Serial.println(": LCD not found.");

  }
}

void loop(){
    char key = keypad.getKey();

    if (key) {
        Serial.println(key);
        if (key == '*') {
          lcd.clear();
          lcd.setCursor(0,0);
          col = 0;
          row = 0;
        }
        else {
          lcd.print(key);
          col++;
          lcd.setCursor(col,0);
          if (col>15) {
            lcd.scrollDisplayLeft();
          }
        }
        
    }
    if (blink){
        digitalWrite(ledPin,!digitalRead(ledPin));    // Change the ledPin from Hi2Lo or Lo2Hi.
        delay(100);
    }
}

// Taking care of some special events.
void keypadEvent(KeypadEvent key){
    switch (keypad.getState()){
    case PRESSED:
        if (key == '#') {
            digitalWrite(ledPin,!digitalRead(ledPin));
            ledPin_state = digitalRead(ledPin);        // Remember LED state, lit or unlit.
        }
        break;

    case RELEASED:
        if (key == '*') {
            digitalWrite(ledPin,ledPin_state);    // Restore LED state from before it started blinking.
            blink = false;
        }
        break;

    case HOLD:
        if (key == '*') {
            blink = true;    // Blink the LED when holding the * key.
        }
        break;
    case IDLE:
      break;
    }
}