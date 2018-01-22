//
// ProfilMenuType.cpp for profil in /home/ndejean/EPITECH/cpp_indie_studio/Menu
//
// Made by nicolas dejean
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Fri Jun  9 11:31:54 2017 nicolas dejean
// Last update Sat Jun 17 00:31:28 2017 nicolas dejean
//

#include "ProfilMenuType.hpp"

ProfilMenuType::ProfilMenuType(irr::IrrlichtDevice* const device): AMenuType(device)
{}

void                            ProfilMenuType::setButtons(std::unordered_map<TEXTURE_TYPE,
							    irr::video::ITexture *> textureList)
{
  _profilButtons = {
    {APPLY_USER, (_env->addButton(irr::core::rect<irr::s32>(MID(WIDTH) - MID(BUTTON_SIZE_X),
						       TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 2)
							    + TEXT_SIZE_Y,
						       (MID(WIDTH) - MID(BUTTON_SIZE_X)) + BUTTON_SIZE_X,
						       TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 2) +
						       BUTTON_SIZE_Y + TEXT_SIZE_Y),
			     0, 410,
				  L"SIGN IN", L"Sign in with your username !")) },
    {EXIT_PROFIL, (_env->addButton(irr::core::rect<irr::s32>(MID(WIDTH) - MID(BUTTON_SIZE_X),
  							     TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 3) +
  							     TEXT_SIZE_Y + BUTTON_SIZE_Y,
  							     (MID(WIDTH) - MID(BUTTON_SIZE_X)) + BUTTON_SIZE_X,
  							     TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 3) +
  							     (BUTTON_SIZE_Y * 2) + TEXT_SIZE_Y),
  				   0, 411,
  				   L"EXIT GAME", L"Quit the best game ever !")) }
  };
  _profilButtons[APPLY_USER]->setImage(textureList[BUTTON]);
  _profilButtons[EXIT_PROFIL]->setImage(textureList[BUTTON]);
}

void				ProfilMenuType::setMenu(std::unordered_map<TEXTURE_TYPE,
							irr::video::ITexture *> textureList)
{
  _env->clear();
  _env->addImage(textureList[BACKGROUND], irr::core::position2d<irr::s32>(0, 0));
  _env->addImage(textureList[LOGO], irr::core::position2d<irr::s32>(MID(WIDTH) - MID(TITLE_X), TITLE_UP_Y));
  enterProfil();
  setButtons(textureList);
}

void				ProfilMenuType::enterProfil()
{
  _profilBox = _env->addEditBox(L"Enter your Profil",
				irr::core::rect<irr::s32>(MID(WIDTH) - MID(BUTTON_SIZE_X),
							  TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 2),
							  (MID(WIDTH) - MID(BUTTON_SIZE_X)) + BUTTON_SIZE_X,
							  TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 2) + USERBOX_SIZE_Y));
}
