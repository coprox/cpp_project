//
// MyEventReceiver.hpp for  in /home/tetard/eptechY2/CPP/indie
//
// Made by girard
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Mon Jun 12 16:17:40 2017 girard
// Last update Mon Jun 12 16:23:32 2017 girard
//

#ifndef MYEVENTRECEIVER_HPP_
# define MYEVENTRECEIVER_HPP_

#include "irrlicht.h"

class MyEventReceiver : public irr::IEventReceiver
{
private:
  // We use this array to store the current state of each key
  bool KeyIsDown[irr::KEY_KEY_CODES_COUNT];

public:
  MyEventReceiver();

  // This is the one method that we have to implement
  virtual bool OnEvent(const irr::SEvent& event);

  // This is used to check whether a key is being held down
  virtual bool IsKeyDown(irr::EKEY_CODE keyCode) const;

};

# endif /* !MYEVENTRECEIVER_HPP_ */
