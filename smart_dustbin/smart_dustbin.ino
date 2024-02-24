
#include <Servo.h>   //servo library
Servo servo;     
int trigPin = 5;    
int echoPin = 6;   
int servoPin = 7;
int led= 10;
int led2=9;
long duration, dist, average;   
long aver[3];   //array for average


void setup() {       
    Serial.begin(9600);
    servo.attach(servoPin);  
    pinMode(led2,OUTPUT);
    pinMode(trigPin, OUTPUT);  
    pinMode(echoPin, INPUT);  
   pinMode(led,OUTPUT);
    servo.write(0);         //close cap on power on
    delay(100);
    servo.detach(); 
} 

void measure() {  

digitalWrite(trigPin, LOW);
delayMicroseconds(5);
digitalWrite(trigPin, HIGH);
delayMicroseconds(15);
digitalWrite(trigPin, LOW);
pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);
dist = (duration/2) / 29.1;    //obtain distance
}
void loop() { 
  for (int i=0;i<=2;i++) {   //average distance
    measure();               
   aver[i]=dist;            
    delay(10);              //delay between measurements
  }
 dist=(aver[0]+aver[1]+aver[2])/3;    

if ( dist<15)
{
//Change distance as per your need
 servo.attach(servoPin);
  delay(1);
 servo.write(0);  
 delay(3000);
  digitalWrite(led,HIGH);
 servo.write(120);    
 delay(50);
  digitalWrite(led,LOW); 
 servo.detach();      

}
else if(dist>15)
{
   digitalWrite(led2,HIGH);
}
  

Serial.print(dist);
}
