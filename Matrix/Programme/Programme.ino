
 unsigned char j; 
//Cablage du module (gnd et +V) utilise 3 pins
int Max7219_pinCLK = 10;  
int Max7219_pinCS = 9;
int Max7219_pinDIN = 8;

unsigned char disp1[2][8]={
{0x3C,0x42,0x42,0x42,0x42,0x42,0x42,0x3C},//0
{B00011000,B00111100,B01111110,B11011011,B11111111,B00100100,B01011010,B10100101},//space invader
};
 
//Ecriture d'un caractere 8x8
void Write_Max7219_byte(unsigned char DATA) {   
  unsigned char i;
  digitalWrite(Max7219_pinCS,LOW);      
  for(i=8;i>=1;i--) {        
    digitalWrite(Max7219_pinCLK,LOW);
    digitalWrite(Max7219_pinDIN,DATA&0x80);// Extracting a bit data
    DATA = DATA<<1;
    digitalWrite(Max7219_pinCLK,HIGH);
  }                                 
}
 
//Ecriture elementaire d une seule rangee 
void Write_Max7219(unsigned char address,unsigned char dat) {
  digitalWrite(Max7219_pinCS,LOW);
  Write_Max7219_byte(address);           //address，code of LED
  Write_Max7219_byte(dat);               //data，figure on LED 
  digitalWrite(Max7219_pinCS,HIGH);
}

//Initialisation du module Max 7219 
void Init_MAX7219(void) {
  Write_Max7219(0x09, 0x00);       //decoding ：BCD
  Write_Max7219(0x0a, 0x03);       //brightness 
  Write_Max7219(0x0b, 0x07);       //scanlimit；8 LEDs
  Write_Max7219(0x0c, 0x01);       //power-down mode：0，normal mode：1
  Write_Max7219(0x0f, 0x00);       //test display：1；EOT，display：0
}
 
 
//Le programme d affichage
void setup() {
  //Pins a utiliser
  pinMode(Max7219_pinCLK,OUTPUT);
  pinMode(Max7219_pinCS,OUTPUT);
  pinMode(Max7219_pinDIN,OUTPUT);
  delay(50);  //Initialiser
  Init_MAX7219();
}


void loop() { 

  for(int i=1;i<9;i++) {  //Afficher un caractere à la fois

    Write_Max7219(i,disp1[1][i-1]);

  }       
}
