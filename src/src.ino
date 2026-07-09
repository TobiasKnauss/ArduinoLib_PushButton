#include "InputWithDelay.h"

InputWithDelay input = InputWithDelay (1, true, 20, 10);

void setup ()
{
  input.Read ();
  input.Reset ();
}

void loop ()
{
}
