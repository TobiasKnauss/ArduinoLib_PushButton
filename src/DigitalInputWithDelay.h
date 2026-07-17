#ifndef DigitalInputWithDelay_h
#define DigitalInputWithDelay_h

#include <Arduino.h>

#include <SignalWithDelay.h>

//--------------------------------------------------------------------
// A digital input with debouncing delays.
//--------------------------------------------------------------------
class DigitalInputWithDelay
{
//==================== Fields ====================

private:
  uint8_t m_DI;
  SignalWithDelay* m_pSignal;

//==================== Constructors ====================

public:
  DigitalInputWithDelay ( uint8_t  i_DI,
                          bool     i_UseInternalPullup,
                          bool     i_LowActive,
                          uint16_t i_DelayForOn_Milliseconds,
                          uint16_t i_DelayForOff_Milliseconds);

  ~DigitalInputWithDelay ();

//==================== Public Methods ====================

  //--------------------------------------------------------------------
  // Read the state of the digital input.
  // This method must be called cyclically.
  //--------------------------------------------------------------------
  bool Read ();

  //--------------------------------------------------------------------
  // Clear all cached states and timestamps of the digital input.
  //--------------------------------------------------------------------
  void Reset ();
};

#endif
