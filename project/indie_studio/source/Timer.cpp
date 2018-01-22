//
// Timer.cpp for  in /home/tetard/eptechY2/CPP/indie
//
// Made by girard
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Mon Jun 12 16:54:59 2017 girard
// Last update Wed Jun 14 14:30:22 2017 girard
//

#include "Timer.hpp"

Timer::Timer(irr::IrrlichtDevice * const device, const irr::u32 &timer) :
  _device(device),
  _thenFdt(device->getTimer()->getTime()),
  _timeLeft(timer),
  _thenTimer(device->getTimer()->getTime())
{}

irr::f32		Timer::frameDeltaTime(void)
{
  irr::u32		now = _device->getTimer()->getTime();
  const irr::f32	fdt = (irr::f32)(now - _thenFdt) / 1000.f;

  _thenFdt = now;
  return (fdt);
}

void			Timer::setTimer(const irr::u32 &nbSec)
{
  _timeLeft = nbSec;
}

bool			Timer::isTimerOver(void)
{
  irr::u32		now = _device->getTimer()->getTime();

  if (now - _thenTimer > _timeLeft)
  {
    _timeLeft = 0;
    _thenTimer = now;
    return (true);
  }
  else
  {
    _timeLeft = _timeLeft - (now - _thenTimer);
    _thenTimer = now;
    return (false);
  }
}
