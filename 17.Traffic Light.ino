//Traffic Light
//You will see the red LED light up first, then the red LED and yellow LED, followed by the green LED, and finally the yellow LED again.
//Email:support@sunfounder.com
//Website:www.sunfounder.com
//2015.5.7
const int redPin= 7; //red led attach to 
const int yellowPin =8 ; //yellow led attach to 
const int greenPin= 9; //green led attach to 
const int clkPin= 2;
const int dtPin= 3;
const int swPin= 6; //the number of the button

int encoderVal = 0;

int state = 0;
int shortPeriod = 1000;
int longPeriod = 1000;
int targetCount = shortPeriod;
int count = 0;

void setup()
{
    pinMode(clkPin, INPUT);
    pinMode(dtPin, INPUT);
    pinMode(swPin, INPUT);
    digitalWrite(swPin, HIGH);
    pinMode(redPin, OUTPUT);  //set the redPin as an output
    pinMode(yellowPin, OUTPUT);  //set the yellowPin as an output
    pinMode(greenPin, OUTPUT);  //set the greenPin as an output
    Serial.begin(9600);  // start serial port at 9600 bps:
}

void loop()
{ 
  count++;
  int change = getEncoderTurn();
  longPeriod = longPeriod + change * 1000;
  if (digitalRead(swPin) == LOW)
  {
      setLights(HIGH, HIGH, HIGH);
  }
  else
  {
    if (count == targetCount)
    {
      setState();
      count = 0;
    }
  }
  delay(1);
}

void setState(void)
{
    if (state == 0)
    {
      setLights(HIGH, LOW, LOW);
      targetCount = longPeriod;
      state = 1;
    }
    else if (state == 1)
    {
      setLights(HIGH, HIGH, LOW);
      targetCount = shortPeriod;
      state = 2;
    }
    else if (state == 2)
    {
      setLights(LOW, LOW, HIGH);
      targetCount = longPeriod;
      state = 3;
    }
    else if (state == 3)
    {
      setLights(LOW, HIGH, LOW);
      targetCount = shortPeriod;
      state = 0;
    }
}

int getEncoderTurn(void)
{
  static int oldA = HIGH;
  static int oldB = HIGH;
  int result = 0;
  int newA = digitalRead(clkPin);
  int newB = digitalRead(dtPin);
  if (newA != oldA || newB != oldB)
  {
    // something has changed
    if (oldA == HIGH && newA == LOW)
    {
      result = (oldB * 2 - 1);
    }
  }
  oldA = newA;
  oldB = newB;
  return result;
}

// the function to set the led with the specified state(on or off),HIGH is on, and LOW is off
void setLights(int redState, int yellowState, int greenState)
{
  digitalWrite(redPin, redState);
  digitalWrite(yellowPin, yellowState);
  digitalWrite(greenPin, greenState);
}
