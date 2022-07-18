# define red 6
# define blue 5

void setup() {
  // put your setup code here, to run once:
pinMode(red,OUTPUT);
pinMode(blue,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int count=0;count<255;count++)
{   
    analogWrite(red,count);
    analogWrite(blue,255-count);
    delay(50);
    /*digitalWrite(blue,LOW);
    digitalWrite(red,HIGH);
    delay(1000);
    digitalWrite(blue,HIGH);
    digitalWrite(red,LOW);
    delay(2000);*/
    
}

}
