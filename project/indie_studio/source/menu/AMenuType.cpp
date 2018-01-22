//
// AMenuType.cpp for  in /home/tetard/eptechY2/CPP/cpp_indie_studio
//
// Made by girard
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Wed May 31 15:25:39 2017 girard
// Last update Sat Jun 17 00:28:25 2017 nicolas dejean
//

#include <iostream>
#include "AMenuType.hpp"

AMenuType::AMenuType(irr::IrrlichtDevice* const device) :
  _smgr(device->getSceneManager()),
  _env(device->getGUIEnvironment())
{
  _font = _env->getFont(FONT_PATH);
}

wchar_t				*AMenuType::stringToWChar(const char *str)
{
  const size_t			cSize = strlen(str) + 1;
  wchar_t*			wc = new wchar_t[cSize];
  mbstowcs(wc, str, cSize);
  return wc;
}
