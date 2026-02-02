
const int pinPulsante = 7;
const int pinLed = 4;

void setup() {
  Serial.begin(115200); // CORRETTO: "S" maiuscola
  pinMode(pinPulsante, INPUT);
  pinMode(pinLed, OUTPUT);
}

void loop() {
  int val = digitalRead(pinPulsante);
  int memo = 0;
  
  Serial.println(val); 

  if (val == 1) {
    digitalWrite(pinLed, HIGH); 
    
  } 
  else {
    digitalWrite(pinLed, LOW);  
  }
  
  delay(100);
}
