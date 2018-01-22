//
// MainMenuType.hpp for mqin in /home/tetard/eptechY2/CPP/cpp_indie_studio
//
// Made by girard
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Wed May 31 14:15:03 2017 girard
// Last update Tue Jun 13 13:35:27 2017 girard

#ifndef MAINMENUTYPE_HPP_
#define MAINMENUTYPE_HPP_

#include "AMenuType.hpp"

class				MainMenuType : public AMenuType
{
public:
  virtual ~MainMenuType() {}
  MainMenuType(irr::IrrlichtDevice* const device);
  MainMenuType(const MainMenuType& cp) = delete;
  MainMenuType			&operator=(const MainMenuType& cp) = delete;

  virtual void			setMenu(std::unordered_map<TEXTURE_TYPE, irr::video::ITexture *> textureList);

  virtual void			setButtons(std::unordered_map<TEXTURE_TYPE,
					   irr::video::ITexture *>);
};

#endif /* !MAINMENUTYPE_HPP_ */
