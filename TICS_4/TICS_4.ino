
int estado=0;
const int intPin = 2;
long luz_int=1000;   // Variable del tiempo de disparo del Deslizador 1 (Dimmer)


void setup() {
  pinMode(5,OUTPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(intPin),interrupcion0,RISING);  // Interrupcion 0 (pin2) 
}                                          // LOW, CHANGE, RISING, FALLING
 
void loop() {
   if(Serial.available()>0){           // Si el puerto serie esta habilitado
        estado = Serial.read();       // Lee lo que llega por el puerto Serie
 }
  
 if(estado=='1') luz_int = 6300;   // Los 8 saltos del Deslizador 1 (Dimmer)
 if(estado=='2') luz_int = 6100;  
 if(estado=='3') luz_int = 5200;  
 if(estado=='4') luz_int = 4900;  
 if(estado=='5') luz_int = 4500; 
 if(estado=='6') luz_int = 4100; 
 if(estado=='7') luz_int = 3500;  
 if(estado=='8') luz_int = 3000; 

}
 
void interrupcion0()    // Funcion que se ejecuta durante cada interrupion
{


  digitalWrite(5,HIGH);
  delayMicroseconds(luz_int); 
  delayMicroseconds(100);
  digitalWrite(5,LOW);


 
}
