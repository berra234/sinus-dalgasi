bool yon=1;
uint8_t i,led=4;



void setup() {
  for(i=4;i<=13;i++)
  pinMode(i,OUTPUT);

}

void loop() {
  for(i=0;i<=9;i++){

    analogWrite(i+4,127.5*(1.0+sin(0.00628318*float(analogRead(2) *millis()+628318))));
  }

}
