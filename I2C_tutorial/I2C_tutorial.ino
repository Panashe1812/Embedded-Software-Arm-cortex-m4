#include <Wire.h>

int temp_adrs= 72;
void setup() {
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  //Send a request
  //start talking
  Wire.beginTransmission(temp_adrs);
  // ask for register 0
  Wire.write(0);
  //complete transmission
  Wire.endTransmission();
  //request i byte
  Wire.requestFrom(temp_adrs,1);
  // wait for response
  while(Wire.available()==0);
  int c =Wire.read();
  

}
