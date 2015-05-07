//Serial Monitor
// open the serial monitor ,if you input red, you will see the red LED light up
//Email:support@sunfounder.com
//Website:www.sunfounder.com
//2015.5.7
const int greenPin= 2; //the green led pin attact to
const int yellowPin= 3; //the yellow led pin attact to
const int redPin= 4; //the red led pin attach to 
String comdata = "";
int lastLength = 0;

void setup()
{
  pinMode(greenPin,OUTPUT);  //initialize the greenPin as output
  pinMode(yellowPin, OUTPUT);  //initialize the yellowPin as output
  pinMode(redPin, OUTPUT);  //initialize the redPin as output
  Serial.begin(9600);  // start serial port at 9600 bps:
  Serial.print("Please input any color of LED:");  //print message on serial monitor
}

void loop()
{
  //read string from serial monitor
  if(Serial.available()>0)  // if we get a valid byte, read analog ins:
  {  
    comdata = "";
    while (Serial.available() > 0)  
    {        
      comdata += char(Serial.read());
      delay(2);
    }
    Serial.println(comdata);
  }
    if(comdata == "red")
    {
      digitalWrite(redPin, HIGH);//turn the red led on
      digitalWrite(greenPin, LOW);//turn the green led off
      digitalWrite(yellowPin, LOW);//turn the yellow led off
    }
    else if(comdata == "yellow")
    {
      digitalWrite(redPin, LOW);//turn the red led off
      digitalWrite(greenPin, LOW);//turn the green led off
      digitalWrite(yellowPin, HIGH);//turn the yellow led on
    }
    else if(comdata == "green")
    {
      digitalWrite(redPin, LOW);//turn the red led off
      digitalWrite(greenPin, HIGH);//turn the green led on
      digitalWrite(yellowPin, LOW);//turn the yellow led off
    }
    else
    {
      digitalWrite(redPin, LOW);//turn the red led off
      digitalWrite(greenPin, LOW);//turn the green led off
      digitalWrite(yellowPin, LOW);//turn the yellow led off
    }    
}
