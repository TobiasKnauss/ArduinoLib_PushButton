#ifndef InputWithDelay_h
#define InputWithDelay_h

#include "Arduino.h"

//--------------------------------------------------------------------
// An input with debouncing delays.
//--------------------------------------------------------------------
class InputWithDelay
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
  InputWithDelay (uint8_t  i_DI,
                  bool     i_UseInternalPullup,
                  uint16_t i_DelayForOn_Milliseconds,
                  uint16_t i_DelayForOff_Milliseconds);

  //--------------------------------------------------------------------
  // Read the state of the input.
  // This method must be called cyclically.
  //--------------------------------------------------------------------
  bool Read ();

  //--------------------------------------------------------------------
  // Clear all cached states and timestamps of the input.
  //--------------------------------------------------------------------
  void Reset ();
};

#endif
