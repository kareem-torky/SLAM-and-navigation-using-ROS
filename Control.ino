
#include <Encoder.h>
#include <math.h>
#include "Motor.h"

#define T 50

Motor m1(10, 9, 3, 2);
Motor m2(6, 7, 18, 19);

long oldt;
double targetSpeed = 0;

void setup() 
{
    Serial.begin(9600);
    oldt = millis();
}

void loop() 
{
    if(Serial.available())
    {
        String s = Serial.readStringUntil('\n');
        targetSpeed = s.toInt();
    }
    m1.setSpeed(targetSpeed);
    m2.setSpeed(targetSpeed);
    
    while(millis()-oldt < T){}
    oldt = millis();
    
    m1.PID();
    m2.PID();
    
    Serial.print(m1.speed);
    Serial.print("   ");
    Serial.println(m2.speed);
}