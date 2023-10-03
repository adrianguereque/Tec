#define PIR D0
#define LED D3

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(PIR, INPUT);

}

void loop() {
  int valor = digitlRead(PIR);
  Serial.printIn(valor);
  if(valor == HIGH){
    digitalWrite(LED, HIGH);
  }
  else{
    digitalWrite(LED, LOW);
  }
}
