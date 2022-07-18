#include <Servo.h>

void Distance();
void servoMotor();
void rotateLeft();
void rotateRight();


const int trigPin =4 ;
const int echoPin=7;

long duration;
int distance;

int brkA=8;
int brkB=9;
int dxnA=12;
int dxnB=13;

int spdA=3;
int spdB=11;

int pos = 0;       // variable to store the servo position

Servo myservo;  // create servo object to control a servo

void setup() 
{
  pinMode(trigPin,OUTPUT);// set the trig pin as an output
  pinMode(echoPin,INPUT);
  
  // initialise brake and direction pins for CHANNEL A

  pinMode(brkA, OUTPUT);         //channel A break
  pinMode(brkB, OUTPUT);         //channel B break
  
  pinMode(dxnA, OUTPUT);        // channel A direction
  pinMode(dxnB, OUTPUT);        // channel B direction

  myservo.attach(5);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);// start serial communication

}

void loop() {
  // put your main code here, to run repeatedly:
    
     if(distance<20)
     {
        brkA=HIGH;
        brkB=HIGH;
        
        servoMotor();
        Distance();
        rotateLeft();
        if(distance>15)
        {
        exit;}
        
        rotateRight();
        Distance();
        if(distance>15)
        {
        exit;
        }
        
     }
     else
     {delay(50);
     
      Motor();
      }
      
    Motor();

}
void Motor()
{
  // drive the motor forward 

  dxnA=HIGH;                //set the motor A to go forward
  brkA=LOW;                 //disengage the break for the motor
  analogWrite(spdA,255);    // motor A at full speed
  
  dxnB=HIGH;                //set the motor B to go forward
  brkB=LOW;  
  analogWrite(spdB,255);
}

void Distance()
{
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(2);

 // sets the trigPinon HIGH for 10 microseconds

 digitalWrite(trigPin,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin,LOW);

 // READ THE ECHO PIN AND RETURNS THE SOUND WAVE TRAVEL TIME IN MICROSECONDS
 duration=pulseIn(echoPin,HIGH);

// calculate distance
distance= duration*0.034/2;

// print on the serial monitor
Serial.print("Distance: ");
Serial.println(distance);
//delay();

}

void servoMotor()
{
      myservo.write(90); // rotate left 
           
      for (pos = 0; pos <= 180; pos += 5 ) 
      { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(500);                       // waits 15ms for the servo to reach the position
      }
      
      for (pos = 180; pos >= 0; pos -= 5)
      { // goes from 180 degrees to 0 degrees
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(500);                       // waits 15ms for the servo to reach the position
      }
}
void rotateLeft()
{ 
  dxnB=LOW;                //set the motor A to go forward
  brkB=LOW;                 //disengage the break for the motor
  analogWrite(spdB,255);    // motor A at full speed
  }
  void rotateRight()
  { dxnA=LOW;                //set the motor A to go forward
  brkA=LOW;                 //disengage the break for the motor
  analogWrite(spdA,255);    // motor A at full speed}

  }s
