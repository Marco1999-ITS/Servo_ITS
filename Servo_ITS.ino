


int ledpin = 4;       
int pushbutton = 7;
int val;
int lastval = 0;
int ledstate = LOW;    

void setup() {
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
  pinMode(pushbutton, INPUT);
}

void loop(){
  val = digitalRead(pushbutton);

  
  if (val == 1 && val != lastval){
    ledstate = !ledstate;
    digitalWrite(ledpin, ledstate); 
    
    
    delay(50); 
  }
  
  lastval = val; 
}

