int DO = 2; //Pin for Digital Output - DO
int DA = A0; // Pin for Analog Output - AO
int threshold = 532; //Set minimum threshold for LED lit
int sensorvalue = 0;
 
void setup() {
  Serial.begin(9600);
}
 
void loop() {
  sensorvalue = analogRead(DA);  //Read the analog value
  Serial.print("Analog: ");
  Serial.print(sensorvalue);  //Print the analog value
  Serial.print("  ");
  Serial.print("Digital: ");
  Serial.println(digitalRead(DO));  //Print the digital value
}
