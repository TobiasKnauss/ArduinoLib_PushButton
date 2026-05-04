#include "PushButton.h"

//--------------------------------------------------------------------
PushButton::PushButton (uint8_t  i_DI,
                        bool     i_UseInternalPullup,
                        uint16_t i_DelayForOn_Milliseconds,
                        uint16_t i_DelayForOff_Milliseconds)
{
  m_DI                       = i_DI;
  m_DelayForOn_Milliseconds  = i_DelayForOn_Milliseconds;
  m_DelayForOff_Milliseconds = i_DelayForOff_Milliseconds;

  Reset ();

  pinMode (i_DI, INPUT);
  digitalWrite (i_DI, i_UseInternalPullup);
}

//--------------------------------------------------------------------
bool PushButton::Read ()
{
  bool state = digitalRead (m_DI);

  if (state != m_State)
  {
    if (state != m_DigitalRead_LastState)
      m_StartOfStateChange = millis ();

    uint16_t delay = state ? m_DelayForOn_Milliseconds : m_DelayForOff_Milliseconds;
    if (millis () - m_StartOfStateChange >= delay)
      m_State = state;
  }

  m_DigitalRead_LastState = state;

  return m_State;
}

//--------------------------------------------------------------------
void PushButton::Reset ()
{
  m_State                 = LOW;
  m_DigitalRead_LastState = LOW;
}
