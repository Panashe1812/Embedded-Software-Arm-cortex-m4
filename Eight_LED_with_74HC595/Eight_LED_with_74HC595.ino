//www.elegoo.com
//2016.06.13

int latchPin = 5;
int clockPin = 6;
int dataPin = 4;

byte leds = 0;

void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}

void loop() 
{
  leds = 0b11111111;
  updateShiftRegister();
  delay(200);

 // bitClear(leds,5);
  //bitClear(leds,6);
   //updateShiftRegister();
  //delay(500);
  
 for (int i = 0; i < 8; i++)
  {
    bitClear(leds, i);
    updateShiftRegister();
    delay(200);
  }
}

void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
}
