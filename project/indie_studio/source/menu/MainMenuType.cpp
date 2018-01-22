//
// MainMenuType.cpp for main in /home/tetard/eptechY2/CPP/cpp_indie_studio
//
// Made by girard
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Wed May 31 15:40:40 2017 girard
// Last update Tue Jun 13 13:32:00 2017 girard
//

#include <iostream>
#include "MainMenuType.hpp"

MainMenuType::MainMenuType(irr::IrrlichtDevice* const device) :
  AMenuType(device)
{}

void			MainMenuType::setButtons(std::unordered_map<TEXTURE_TYPE,
					      irr::video::ITexture *> textureList)
{
  _menuButtons = {
    {PLAY_GAME, _env->addButton(irr::core::rect<irr::s32>(MID(WIDTH) - MID(BUTTON_SIZE_X),
    							  TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y,
    							  (MID(WIDTH) - MID(BUTTON_SIZE_X)) + BUTTON_SIZE_X,
    							  TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y + BUTTON_SIZE_Y),
				0, 1,
				L"NEW GAME", L"Start a hole new game !") },
    {OPTION,  _env->addButton(irr::core::rect<irr::s32>(MID(WIDTH) - MID(BUTTON_SIZE_X),
							TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 2) + BUTTON_SIZE_Y,
							MID(WIDTH) - MID(BUTTON_SIZE_X) + BUTTON_SIZE_X,
							TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 2) + BUTTON_SIZE_Y +
							BUTTON_SIZE_Y),
			      0, 2,
    			     L"OPTIONS", L"Settings for a better gameplay !")},
    { CREDITS,  _env->addButton(irr::core::rect<irr::s32>(MID(WIDTH) - MID(BUTTON_SIZE_X),
							    TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 3) + (BUTTON_SIZE_Y * 2),
    							    MID(WIDTH) - MID(BUTTON_SIZE_X) + BUTTON_SIZE_X,
    							    TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 3) + (BUTTON_SIZE_Y * 2)
							    + BUTTON_SIZE_Y),
				  0, 3,
    				  L"CREDITS", L"The guys who coded this crazy awesome shit !")},
    { QUIT,  _env->addButton(irr::core::rect<irr::s32>(MID(WIDTH) - MID(BUTTON_SIZE_X),
						       TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 4) + (BUTTON_SIZE_Y * 3),
						       MID(WIDTH) - MID(BUTTON_SIZE_X) + BUTTON_SIZE_X,
						       TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 4) + (BUTTON_SIZE_Y * 3)
						       + BUTTON_SIZE_Y),
			     0, 4,
    				  L"EXIT GAME", L"Goodbye !")}
  };
  _menuButtons[PLAY_GAME]->setImage(textureList[BUTTON]);
  _menuButtons[OPTION]->setImage(textureList[BUTTON]);
  _menuButtons[CREDITS]->setImage(textureList[BUTTON]);
  _menuButtons[QUIT]->setImage(textureList[BUTTON]);
}

void			MainMenuType::setMenu(std::unordered_map<TEXTURE_TYPE,
					      irr::video::ITexture *> textureList)
{
  _env->clear();
  irr::gui::IGUISkin* skin = _env->getSkin();
  irr::gui::IGUIFont* font = _env->getFont(FONT_PATH);

  if (font)
    skin->setFont(font);

  skin->setSize(irr::gui::EGUI_DEFAULT_SIZE::EGDS_COUNT, 50);

  _env->addImage(textureList[BACKGROUND], irr::core::position2d<irr::s32>(0, 0));
  _env->addImage(textureList[LOGO], irr::core::position2d<irr::s32>(MID(WIDTH) - MID(TITLE_X), TITLE_UP_Y));
  setButtons(textureList);
}
