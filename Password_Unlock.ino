#include <Keypad.h>
#include<Servo.h>

Servo myservo;
char pass[3]="123";
int pos=0,f=0,check=0,count=0;
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
{'1','2','A','3'},
{'4','5','B','6'},
{'7','8','C','9'},
{'*','0','D','#'}
};

byte rowPins[ROWS] = { 8, 7, 6, 9 };
byte colPins[COLS] = { 5, 4, 3, 2 };
Keypad keypad=Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);
int pin1=12;
int pin2=13;
 
void setup() {
  // put your setup code here, to run once:
  myservo.attach(11);
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
  Serial.begin(9600);
  Serial.println("press '*' or '#' instead of enter");
  Serial.println("Locked!!");
}
void setlocked(int);
void loop() {
  // put your main code here, to run repeatedly:
char key=keypad.waitForKey();
if(pass[pos]==key)
{
  pos++;
  count++;
}
else
count++;
if(key!='*' && key!='#')
Serial.println(key);
if(key=='*' || key=='#')
{
if(pos==3 && count==4)
{
  pos=0;
  check=0;
  count=0;
  setlocked(false);
}
else
{
  check++;
  pos=0;
  count=0;
  setlocked(true);
}
}
if(f==0)
{
if(check==3)
{
  check=0;
  f=1;
  Serial.println("Password system locked Try Again after 30 seconds");
  delay(30000);
  Serial.println("Now Enter");
}
}
delay(200);
}
void setlocked(int locked)
{
  if(locked)
  {
    digitalWrite(pin1,HIGH);
    digitalWrite(pin2,LOW);
    Serial.println("wrong password");
 }
  else
  {
    myservo.write(360);
    digitalWrite(pin2,HIGH);
    digitalWrite(pin1,LOW);
    Serial.println("Unlocked");
 }
}


