//NE555 Timer
/*****************************************************************************
After burning the program, open the serial monitor,you can see that if you rotate the potentiometer,
the length of the pulse (in microsecond) displayed will change accordingly.
**************************************************************************/
//Email:support@sunfounder.com
//Website:www.sunfounder.com
//2015.5.7
int pin = 7;  //attach to the third pin of NE555
unsigned long duration;  //the variable to store the length of the pulse 
 
void setup()
{
  pinMode(pin, INPUT);  //set the pin as an input
  Serial.begin(9600);  // start serial port at 9600 bps:
}
 
void loop()
{
  duration = pulseIn(pin, HIGH);  //Reads a pulse on pin
  Serial.print(duration);  //print the length of the pulse on the serial monitor
  Serial.println();  //print an blank on serial monitor
  delay(500);  //wait for 500 microseconds
}
