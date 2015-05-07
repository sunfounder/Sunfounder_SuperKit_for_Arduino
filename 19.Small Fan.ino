//Small Fan
/****************************************************************
As explained above, the amount of times you press the button should change the rotation speed of the fan. 
Pressing it once will cause it to rotate slowly,
while pressing it three times will cause it to rotate quickly, and pressing it four times will cause it to stop.
****************************************************************/
//Email:support@sunfounder.com
//Website:www.sunfounder.com
//2015.5.7
// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin = 2;    // the number of the pushbutton pin
const int ledPin = 13;      // the number of the LED pin
const int motorIn1 = 9;
const int motorIn2 = 10;
int stat = 0; 
#define rank1 150
#define rank2 200
#define rank3 250
// Variables will change:
int ledState = HIGH;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers
/******************************************************************************/
void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  pinMode(motorIn1,OUTPUT);
  pinMode(motorIn2,OUTPUT);
  // set initial LED state
  digitalWrite(ledPin, ledState);
  Serial.begin(9600);
}

void loop() {
  // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);

  // check to see if you just pressed the button 
  // (i.e. the input went from LOW to HIGH),  and you've waited 
  // long enough since the last press to ignore any noise:  

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  } 
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        ledState = !ledState;
        stat = stat + 1;
        if(stat >= 4)
        {
          stat = 0;
        }
      }
    }
  }
  
  // set the LED:
  digitalWrite(ledPin, ledState);
    // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  switch(stat)
  {
    case 1:
      clockwise(rank1);
      break;
    case 2:
      clockwise(rank2);
      break;
    case 3:
      clockwise(rank3);
      break;
    default:
      clockwise(0);
  }
    lastButtonState = reading;
}
/***********************************************************/
void clockwise(int Speed)//
{
  analogWrite(motorIn1,0);
  analogWrite(motorIn2,Speed);
}
/***********************************************************/
