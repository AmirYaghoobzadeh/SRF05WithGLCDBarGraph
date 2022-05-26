
#include <openGLCD.h>
#include <NewPing.h>
const int trig = 2;
const int echo = 3;
int maxDistance = 127;
int led = 12;
NewPing sonar(trig, echo, maxDistance);

void setup()
{
  GLCD.Init(NON_INVERTED);
  GLCD.SelectFont(Arial_14);
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop()
{
  int distance = sonar.ping_cm();
  GLCD.ClearScreen();
  if (distance <= 2 || distance >= 124)
  {
    digitalWrite(led, HIGH);
    Serial.print("Out Of Range...");
    GLCD.print("Out Of Range...");

  }
  else
  {
    digitalWrite(led, LOW);
    GLCD.print("Distance: ");
    GLCD.print(distance);
    GLCD.DrawHBarGraph(1, 15, 127, 10, 1, 0, 127, distance);
    Serial.print("Distance: ");
    Serial.println(distance);
  }
}
