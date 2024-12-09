#include <Arduino.h>
#include "DocykeMotor.h"

/**
-----------------
|               |
| 5  4  3  2  1 |
|               |
-----------------

5 - + 5v
4 - direction  --> 12
3 - speed      --> 25
2 - enable     --> 13
1 - - GND

**/

#define ENABLE_PIN 13
#define DIRECTION_PIN 12
#define VELOCITY_PIN 25

DocykeMotor motor(ENABLE_PIN, DIRECTION_PIN, VELOCITY_PIN); // Replace with your actual pin numbers

void setup()
{
  Serial.begin(115200);
  pinMode(ENABLE_PIN, OUTPUT);
  pinMode(DIRECTION_PIN, OUTPUT);
  pinMode(VELOCITY_PIN, OUTPUT);
  Serial.println("Starting motor");

  motor.enable();
  motor.setDirection(false); // Set to forward

  //set pin 14 to output pwm and do 60% and 0 with 5 sec delay
  pinMode(14, OUTPUT);
  
}

int speeds[] = {190,195,200,205,210,215,220,225,230,235,240,245,250,255};
int i = 0;
void loop()
{
  Serial.println("Forward");
  Serial.println(speeds[i]);
  analogWrite(14, speeds[i]);
  i++;
  if (i >= sizeof(speeds) / sizeof(speeds[0]))
  {
    i = 0;
  }
  delay(3000);

}
