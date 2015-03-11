//Function: This procedure applies in the using ARDUINO MEGA 2560 drive ultrasonic module HC-SR-04.Measure distances with a serial show
//Time: August 16, 2012
int TrigPin = 11;
int EchoPin = 10;
void setup()
{
  Serial.begin(9600);
  pinMode(TrigPin,OUTPUT);
  pinMode(EchoPin,INPUT);
}
void loop()
{
  int distance,duration;
  
  digitalWrite(TrigPin,HIGH);//TrigPin prepare high of more than 10us
  delayMicroseconds(11);
  digitalWrite(TrigPin,LOW);

  duration = pulseIn(EchoPin, HIGH);//EchoPin received high start counting until the receiver to the low,return to the count valu
  duration = duration/29/2;//Calculating the distance  cm
                           // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  
  Serial.print(duration);//Serial display distance
  Serial.print("cm");
  Serial.println();
  delay(1000);
}
