//Controlling LED By PWM
//The led the LED lights up gradually,and then goes out gradually,repeatedly
//Email:support@sunfounder.com
//Website:www.sunfounder.com
//2015.5.7
/**************************************************************/
const int ledPin = 9;    // the pin that the LED is attached to

void setup ()
{
  pinMode(ledPin, OUTPUT);  // declare pin 9 to be an output:
}
 
void loop()
{
  for (int a=0; a<=255;a++)               //loop from 0 to 255
  {
    analogWrite(ledPin, a);               // set the brightness of pin 9:
    delay(8);                             //wait for 8 microseconds            
  }
    for (int a=255; a>=0;a--)             //loop from 255 down to 0
  {
    analogWrite(ledPin, a);               // set the brightness of pin 9:
    delay(8);                             //wait for 8 microseconds   
  }
  delay(800);                             //wait for 800 microseconds  
}
