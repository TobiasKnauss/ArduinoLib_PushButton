#include "DigitalInputWithDelay.h"

//--------------------------------------------------------------------
DigitalInputWithDelay::DigitalInputWithDelay (uint8_t  i_DI,
                                              bool     i_UseInternalPullup,
                                              uint16_t i_DelayForOn_Milliseconds,
                                              uint16_t i_DelayForOff_Milliseconds)
{
  m_DI = i_DI;
  m_pSignal = new SignalWithDelay (i_DelayForOn_Milliseconds, i_DelayForOff_Milliseconds);

  pinMode (i_DI, INPUT);
  digitalWrite (i_DI, i_UseInternalPullup);
}

//--------------------------------------------------------------------
DigitalInputWithDelay::~DigitalInputWithDelay ()
{
  delete m_pSignal;
}

//--------------------------------------------------------------------
bool DigitalInputWithDelay::Read ()
{
  bool state = digitalRead (m_DI);
  return m_pSignal->Process (state);
}

//--------------------------------------------------------------------
void DigitalInputWithDelay::Reset ()
{
  m_pSignal->Reset ();
}
