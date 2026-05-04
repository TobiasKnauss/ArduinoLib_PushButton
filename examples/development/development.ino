#include <Arduino.h>
#include <Streaming.h>

#include <PushButton.h>

#define ON HIGH
#define OFF LOW

PushButton m_PushButton (4, ON, 1000, 2000);

void setup ()
{
  Serial.begin (9600);
}

void loop ()
{
  Serial << millis () << "  :  " << digitalRead (4) << "  " << m_PushButton.Read () << endl;
  delay (200);
}
