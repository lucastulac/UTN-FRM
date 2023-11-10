 class Timer {
  public:
  unsigned long hora;
  void funcionamientoTimer(class Timer, char);
 };

void setup() {
  
  Serial.begin(9600);
  
}

void loop() {

   Timer Cronometro; 
   char caracterLeido;
   //delay(1000);  
   if (Serial.available() > 0) {
   caracterLeido = Serial.read();
   }
   Cronometro.funcionamientoTimer(Cronometro,caracterLeido);
}
void Timer::funcionamientoTimer(class Timer Objeto, char caracterLeido){
  if(caracterLeido=='A'){
    Objeto.hora=millis();
    Serial.println(Objeto.hora); 
    }
  if(caracterLeido=='D'){
    Serial.println("El cronometro se paró"); 
    }
   if(caracterLeido=='R'){
    Objeto.hora=0;
    Serial.println("El cronometro se reseteó"); 
    } 
  }
