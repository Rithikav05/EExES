#include<Servo.h>
#include<stdlib.h>
#define M0 0
#define M1 1
#define M2 2
#define M3 3
#define mean 90
#define ldr A0
#define TRUE 1
#define FALSE 0


int exct;
int pos=0;

Servo myservo0;
Servo myservo1;  
Servo myservo2;
Servo myservo3;  

void setup()
{  
  Serial.begin(9600);
  pinMode(ldr,INPUT);
  myservo0.attach(M0);
  myservo1.attach(M1);
  myservo2.attach(M2);
  myservo3.attach(M3);

  pos=0;
}

void loop()
{
int ldrval=analogRead(ldr); 
if(ldrval<=30)
  {
    exct=TRUE;
    Serial.print("Pick-up. ");
    Serial.println(ldrval);
    Serial.println(exct);

  topickup();
  delay(1000);
  flex();
  delay(1000);
  torest(180);
  delay(1000);
  todrop();
  delay(1000);
  flex();
  delay(1000);
  torest(0);
  delay(1000);
}
else
  {
    exct=FALSE;
    Serial.print("Rest. ");
    Serial.println(ldrval);
    Serial.println(exct);
    
  }
  delay(1000);
}

void topickup()
{
  for(int i=90;i <=180; i++)
  {
    myservo0.write(i);
    delay(40);
  }
}

void torest(int start)
{
  if(start>mean)
  {
    for(int i=start; i>=mean ; i--)
    {
      myservo0.write(i);
      delay(40);
    }
  }
  else
  {
    for(int i=start; i<=mean ; i++)
    {
      myservo0.write(i);
      delay(40);
    }
  }
}

void todrop()
{
  for(int i=90; i>=0; i--)
  {
    myservo0.write(i);
    delay(40);
  }
}

void flex()
{
  for(int i=90,j=90;i<=130;i++,j--)
  {
    myservo1.write(j);
    myservo2.write(j);
    delay(30);
  }
  delay(1000);
  for(int k=160;k>=30;k--)
  {
    myservo3.write(k);
    delay(30);
  }
  delay(900);
  for(int k=30;k<=160;k++)
  {
    myservo3.write(k);
    delay(30);
  }
  delay(1000);
  for(int i=130,j=50;i>=90;i--,j++)
  {
    myservo1.write(j);
    myservo2.write(j);
    delay(30);
  }
  delay(1000);

}