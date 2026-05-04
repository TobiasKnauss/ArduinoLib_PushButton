#ifndef PushButton_h
#define PushButton_h

#include "Arduino.h"

//--------------------------------------------------------------------
// A push button with debouncing delays.
//--------------------------------------------------------------------
class PushButton
{
//==================== Fields ====================

private:
  uint8_t  m_DI;
  uint16_t m_DelayForOn_Milliseconds;
  uint16_t m_DelayForOff_Milliseconds;

  bool          m_State;
  bool          m_DigitalRead_LastState;
  unsigned long m_StartOfStateChange;


//==================== Constructors ====================

public:
  PushButton (uint8_t  i_DI,
              bool     i_UseInternalPullup,
              uint16_t i_DelayForOn_Milliseconds,
              uint16_t i_DelayForOff_Milliseconds);

  //--------------------------------------------------------------------
  // Read the state of the push button.
  // This method must be called cyclically.
  //--------------------------------------------------------------------
  bool Read ();

  //--------------------------------------------------------------------
  // Clear all cached states and timestamps of the push button.
  //--------------------------------------------------------------------
  void Reset ();
};

#endif
