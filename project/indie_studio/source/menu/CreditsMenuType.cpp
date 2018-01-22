//
// CreditsMenuType.cpp for credit in /home/ndejean/EPITECH/cpp_indie_studio/Menu
//
// Made by nicolas dejean
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Sat Jun  3 09:56:11 2017 nicolas dejean
// Last update Tue Jun 13 13:31:37 2017 girard
//

#include "CreditsMenuType.hpp"

void				CreditsMenuType::setButtons(std::unordered_map<TEXTURE_TYPE,
					 irr::video::ITexture *> textureList)
{
  irr::gui::IGUIButton		*back;
  back = _env->addButton(irr::core::rect<irr::s32>(800, 800,
					800 + BUTTON_SIZE_X,
					800 + BUTTON_SIZE_Y),
	      0, 300,
	      L"BACK", L"Back to Main Menu");
  back->setImage(textureList[BUTTON]);
}

void				CreditsMenuType::setMenu(std::unordered_map<TEXTURE_TYPE,
					irr::video::ITexture *> textureList)
{
  _env->clear();
  _env->addImage(textureList[CREDITS_GAME], irr::core::position2d<irr::s32>(0, 0));
  setButtons(textureList);
}
