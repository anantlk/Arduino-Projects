int pin1=7;
int pin2=13;
int TimeBetwEmail=15;
long lastSend=-TimeBetwEmail*1000l;
void setup() {
  // put your setup code here, to run once:
  pinMode(pin1,INPUT);
  pinMode(pin2,OUTPUT);
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  long now=millis();
  int val=digitalRead(pin1);
  if(val==HIGH)
  {
  if(now>(lastSend+TimeBetwEmail*1000l))
  {
    lastSend=now;
    Serial.println("Movement");
  }
  else
  {
    Serial.println("Too soon");
  }
  digitalWrite(pin2,HIGH);
  delay(1000);
  }
  else
  {
    Serial.println("No Movement");
    digitalWrite(pin2,LOW);
    delay(1000);
  }
}
