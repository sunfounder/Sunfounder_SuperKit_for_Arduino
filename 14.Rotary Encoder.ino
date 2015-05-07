//Rotary Encoder
/*************************************************************************
You will see the angular displacement of the rotary encoder printed on the serial monitor of the computer. 
When the rotary encoder turns clockwise, the angular displacement is increased;
when it turns counterclockwise, it’s decreased.
If you press the switch on the rotary encoder, related readings will return to zero.
*************************************************************************************/
//Email:support@sunfounder.com
//Website:www.sunfounder.com
//2015.5.7
const int clkPin= 2;
const int dtPin= 3;
const int swPin= 4 ;//the number of the button

int encoderVal = 0;

void setup()
{
  pinMode(clkPin, INPUT);//set clkPin as INPUT
  pinMode(dtPin, INPUT);
  pinMode(swPin, INPUT);
  digitalWrite(swPin, HIGH);
  Serial.begin(9600);
}

void loop()
{
  int change = getEncoderTurn();//
  encoderVal = encoderVal + change;
  if(digitalRead(swPin) == LOW)//if button pull down
  {
    encoderVal = 0;
  }
  Serial.println(encoderVal);
}

int getEncoderTurn(void)
{
  static int oldA = HIGH;
  static int oldB = HIGH;
  int result = 0;
  int newA = digitalRead(clkPin);//read the value of clkPin to newA
  int newB = digitalRead(dtPin);//read the value of dtPin to newB
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
