//DC Motor Control
//The DC motor will begin rotating left and right, and its speed will vary accordingly.
//Email:support@sunfounder.com
//Website:www.sunfounder.com
//2015.5.7
/***************************************/
const int motorIn1 = 9;  //attach to one of the pin of the motor
const int motorIn2 = 10;  //attach to another pin of the motor
/***************************************/
void setup()
{
  pinMode(motorIn1,OUTPUT);  //initialize the motorIn1 pin as output 
  pinMode(motorIn2,OUTPUT);  //initialize the motorIn2 pin as output 
}
/****************************************/
void loop()
{
  clockwise(200);  //rotate clockwise 
  delay(1000);  //wait for a second
  counterclockwise(200);  //rotate counterclockwise
  delay(1000);  //wait for a second
}
/****************************************/
//The function to drive motor rotate clockwise
void clockwise(int Speed)
{
  analogWrite(motorIn1,Speed);  //set the speed of motor
  analogWrite(motorIn2,0);  //stop the motorIn2 pin of motor
}
//The function to drive motor rotate counterclockwise
void counterclockwise(int Speed)
{
  analogWrite(motorIn1,0);  //stop the motorIn1 pin of motor
  analogWrite(motorIn2,Speed);  //set the speed of motor
}
/****************************************/
