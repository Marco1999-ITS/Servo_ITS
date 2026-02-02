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
  
  Serial.println("--- Sistema Soft-Start / Soft-Stop Avviato ---");
}

void loop(){
  val = digitalRead(pushbutton);

  
  if (val == 1 && val != lastval){
    
    
    ledstate = !ledstate;
    digitalWrite(ledpin, ledstate); 
   
    
    if (ledstate == HIGH) {
      
       Serial.println("ON -> Accelerazione in corso...");
       
       for (int i = 0; i <= 255; i++) {
         analogWrite(motorPin, i);
         delay(10); 
         Serial.println(i);
       }
       
       Serial.println("Massima potenza raggiunta (255)");
    } 
    else {
       
       Serial.println("OFF -> Decelerazione in corso...");
       
       for (int i = 255; i >= 0; i--) {
         analogWrite(motorPin, i);
         delay(10); 
         Serial.println(i);
       }
       
       Serial.println("Motore Fermo (0)");
    }
  
    
    delay(100); 
  }
  
  lastval = val; 
}
