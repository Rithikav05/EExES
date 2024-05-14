#include<Servo.h>
#include<stdlib.h>

#define mean 90
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
  pinMode(A0,INPUT);
  myservo0.attach(4);
  myservo1.attach(5);
  myservo2.attach(6);
  myservo3.attach(7);

  pos=0;
}

void loop()
{
int ldrval=analogRead(ldr); 
if(ldrval<=25)
  {
    exct=TRUE;
    Serial.print("Pick-up. ");
    Serial.println(ldrval);
    //Serial.println(exct);

  topickup();
  delay(1000);
    
  flex1();
  pickGrip();
  flex2();
  delay(1000);
  
  torest(180);
  delay(1000);
  
  todrop();
  delay(1000);
  
  flex1();
  dropGrip();
  flex2();
  delay(1000);
  
  torest(0);
  delay(1000);
}
else
  {
    exct=FALSE;
    Serial.print("Rest. ");
    Serial.println(ldrval);
    //Serial.println(exct);
    
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

void flex1()
{
  for(int j=90;j>=60;j--)
  {
    myservo1.write(j);
    myservo2.write(j);
    delay(30);
  }
  delay(1000);
  for(int j=60;j>=50;j--)
  {
    myservo2.write(j);
    delay(30);
  }
  delay(500);
}

void flex2()
{
  for(int j=50;j<=60;j++)
  {
    myservo2.write(j);
    delay(30);
  }
  delay(600);
  for(int j=60;j<=90;j++)
  {
    myservo1.write(j);
    myservo2.write(j);
    delay(30);
  }
  delay(1000);
}


void pickGrip()
{
  for(int k=30;k<=165;k++)
  {
    myservo3.write(k);
    delay(30);
  }
  delay(1000);
}

void dropGrip()
{
  for(int k=165;k>=30;k--)
  {
    myservo3.write(k);
    delay(30);
  }
  delay(900);
}
