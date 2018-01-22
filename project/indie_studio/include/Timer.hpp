//
// Timer.hpp for  in /home/tetard/eptechY2/CPP/indie
//
// Made by girard
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Mon Jun 12 16:51:19 2017 girard
// Last update Sun Jun 18 02:36:05 2017 girard
//

#ifndef TIMER_HPP_
# define TIMER_HPP_

#include "irrlicht.h"

class			Timer
{
private:
  irr::IrrlichtDevice	*_device;
  irr::u32		_thenFdt;
  irr::u32		_timeLeft;
  irr::u32		_thenTimer;

public:
  Timer(irr::IrrlichtDevice * const device, const irr::u32 &timer = 0);
  ~Timer(void) = default;
  Timer(const Timer &cp) = delete;
  Timer			&operator=(const Timer &cp) = delete;

  irr::f32	frameDeltaTime(void);

  void		setTimer(const irr::u32 &nbSec);
  bool		isTimerOver(void);

  irr::IrrlichtDevice	*getDevice(void) const { return (_device); }
};

#endif /* !TIMER_HPP_ */
