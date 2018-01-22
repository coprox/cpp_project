//
// StartgameMenuType.cpp for start in /home/ndejean/EPITECH/cpp_indie_studio/Menu
//
// Made by nicolas dejean
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Sat Jun  3 08:50:06 2017 nicolas dejean
// Last update Sat Jun 17 14:02:17 2017 nicolas dejean
//

#include "StartGameMenuType.hpp"

StartGameMenuType::StartGameMenuType(irr::IrrlichtDevice* const device):
  AMenuType(device)
{}

void				StartGameMenuType::setButtons(std::unordered_map<TEXTURE_TYPE,
							      irr::video::ITexture *> textureList)
{
  _playButtons = {
    {SINGLE_PLAYER, _env->addButton(irr::core::rect<irr::s32>(MID(WIDTH) - MID(BUTTON_SIZE_X),
							  TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y,
							  (MID(WIDTH) - MID(BUTTON_SIZE_X)) + BUTTON_SIZE_X,
							  TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y + BUTTON_SIZE_Y),
				0, 200,
				L"SINGLE PLAYER", L"You don't need friends !") },
    {MULTIPLAYER,  _env->addButton(irr::core::rect<irr::s32>(MID(WIDTH) - MID(BUTTON_SIZE_X),
							TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 2) + BUTTON_SIZE_Y,
							MID(WIDTH) - MID(BUTTON_SIZE_X) + BUTTON_SIZE_X,
							TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 2) + BUTTON_SIZE_Y +
							BUTTON_SIZE_Y),
			      0, 201,
			      L"MULTIPLAYER", L"Play with other friends !")},
    { BACK_START,  _env->addButton(irr::core::rect<irr::s32>(MID(WIDTH) - MID(BUTTON_SIZE_X),
						       TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 3) + (BUTTON_SIZE_Y * 2),
						       MID(WIDTH) - MID(BUTTON_SIZE_X) + BUTTON_SIZE_X,
						       TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 3) + (BUTTON_SIZE_Y * 2)
						       + BUTTON_SIZE_Y),
			     0, 210,
			     L"BACK", L"Back to main menu.")}
  };
  _playButtons[SINGLE_PLAYER]->setImage(textureList[BUTTON]);
  _playButtons[MULTIPLAYER]->setImage(textureList[BUTTON]);
  _playButtons[BACK_START]->setImage(textureList[BUTTON]);
}

void				StartGameMenuType::setMenu(std::unordered_map<TEXTURE_TYPE,
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

void				StartGameMenuType::HowManyPlayer(std::unordered_map<TEXTURE_TYPE,
								 irr::video::ITexture *> textureList)
{
  _playButtons[TWO_PLAYER] = _env->addButton(irr::core::rect<irr::s32>(MID(WIDTH) + BUTTON_SIZE_X,
								       TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y,
								       MID(WIDTH) + (BUTTON_SIZE_X * 2),
								       TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y + BUTTON_SIZE_Y),
					     0, 202,
					     L"TWO PLAYERS", L"Play with one of your friends !");
  _playButtons[THREE_PLAYER] = _env->addButton(irr::core::rect<irr::s32>(MID(WIDTH) + BUTTON_SIZE_X,
									 TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 2) + BUTTON_SIZE_Y,
									 MID(WIDTH) + (BUTTON_SIZE_X * 2),
									 TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 2) + BUTTON_SIZE_Y +
									 BUTTON_SIZE_Y),
					       0, 203,
					       L"THREE PLAYERS", L"Three is better than two !");
  _playButtons[FOUR_PLAYER] = _env->addButton(irr::core::rect<irr::s32>(MID(WIDTH) + BUTTON_SIZE_X,
									TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 3) + (BUTTON_SIZE_Y * 2),
									MID(WIDTH) + (BUTTON_SIZE_X * 2),
									TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 3) + (BUTTON_SIZE_Y * 2)
									+ BUTTON_SIZE_Y),
					      0, 204,
					      L"FOUR PLAYERS", L"WOW ! how many friends do you have !");
  _playButtons[TWO_PLAYER]->setImage(textureList[BUTTON]);
  _playButtons[THREE_PLAYER]->setImage(textureList[BUTTON]);
  _playButtons[FOUR_PLAYER]->setImage(textureList[BUTTON]);

}
