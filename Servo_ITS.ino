// NON servono più librerie Servo!

int ledpin = 4;       
int pushbutton = 7;
int motorPin = 9;  

int val;
int lastval = 0;
int ledstate = LOW;    

void setup() {
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
  pinMode(pushbutton, INPUT);
  
  pinMode(motorPin, OUTPUT);
  
  Serial.println("--- Sistema Motore DC Avviato ---");
}

void loop(){
  val = digitalRead(pushbutton);

  
  if (val == 1 && val != lastval){
    
    // Invertiamo lo stato
    ledstate = !ledstate;
    

    digitalWrite(ledpin, ledstate);  
    digitalWrite(motorPin, ledstate); 
    Serial.println("ON -> Motore ACCESO");
    
 
    
    delay(100); 
  }
  
  lastval = val; 
}
