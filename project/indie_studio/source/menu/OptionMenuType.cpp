//
// OptionMenuType.cpp for op in /home/tetard/eptechY2/CPP/cpp_indie_studio
//
// Made by girard
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Wed May 31 16:21:59 2017 girard
// Last update Sat Jun 17 19:12:05 2017 nicolas dejean
//

#include <iostream>
#include "OptionMenuType.hpp"

OptionMenuType::OptionMenuType(irr::IrrlichtDevice* const device) :
  AMenuType(device),
  _print({
      { "&", "UP KEY"},
      { "(", "DOWN KEY"},
      { "%", "LEFT KEY"},
      { "'", "RIGHT KEY"},
      { " ", "SPACE" }
    })
{}

const char				*OptionMenuType::printKeys(const std::string& key)
{
  auto				it = _print.find(key);
  if (it != _print.end())
    return it->second.c_str();
  return key.c_str();
}

void				OptionMenuType::setTabOptions(std::unordered_map<TEXTURE_TYPE,
							      irr::video::ITexture *> textureList)
{
  irr::gui::IGUITabControl	*optTab =
    _env->addTabControl(irr::core::rect<int>(MID(BUTTON_SIZE_X),
					     BUTTON_DISTANCE_Y,
					     (MID(BUTTON_SIZE_X)) + TAB_SIZE_X,
					     BUTTON_DISTANCE_Y +
					     TAB_SIZE_Y), 0, true, true);

  irr::gui::IGUITab		*controls = optTab->addTab(L"Controls Layout");
  irr::gui::IGUITab		*option = optTab->addTab(L"Options");
  irr::video::SColor		col(255, 0, 255, 0);

  /* OPTIONS */
  option->setTextColor(col);
  _env->addCheckBox(_settings.getFullscreen(), irr::core::rect<int>(20,85,180,110),
		      option, 100, L"Fullscreen");
  _env->addCheckBox(_settings.getJoystick(), irr::core::rect<int>(220,85,500,110),
		      option, 101, L"Enable joystick");

  /* CONTROLS */

  const wchar_t* playerOne = L"PLAYER 1";
  const wchar_t* playerTwo = L"PLAYER 2";
  const wchar_t* playerThree = L"PLAYER 3";
  const wchar_t* playerFour = L"PLAYER 4";

  _env->addStaticText(playerOne, irr::core::rect<int>(30, 30, 200, 60),
			true, true, controls);
  _env->addStaticText(playerTwo, irr::core::rect<int>(30 + 300, 30, 200 + 300, 60),
			true, true, controls);
  _env->addStaticText(playerThree, irr::core::rect<int>(30 + 600, 30, 200 + 600, 60),
			true, true, controls);
  _env->addStaticText(playerFour, irr::core::rect<int>(30 + 900, 30, 200 + 900, 60),
			true, true, controls);

  /* TEXT FOR KEYS */

  const wchar_t* up = L"UP";
  const wchar_t* down = L"DOWN";
  const wchar_t* right = L"RIGHT";
  const wchar_t* left = L"LEFT";
  const wchar_t* attack = L"ATTACK";

  _env->addStaticText(up, irr::core::rect<int>(30, 30 + 60, 80, BUTTON_SIZE_Y + 30),
			true, true, controls);
  _env->addStaticText(down, irr::core::rect<int>(30, 30 + 60 + BUTTON_SIZE_Y + 30, 80 + 40, (BUTTON_SIZE_Y + 30) * 2),
  			true, true, controls);
  _env->addStaticText(left, irr::core::rect<int>(30, 30 + 60 + ((BUTTON_SIZE_Y + 30) * 2), 80 + 40, (BUTTON_SIZE_Y + 30) * 3),
  			true, true, controls);
  _env->addStaticText(right, irr::core::rect<int>(30, 30 + 60 + ((BUTTON_SIZE_Y + 30) * 3), 80 + 40, (BUTTON_SIZE_Y + 30) * 4),
  			true, true, controls);
  _env->addStaticText(attack, irr::core::rect<int>(30, 30 + 60 + ((BUTTON_SIZE_Y + 30) * 4), 80 + 70, (BUTTON_SIZE_Y + 30) * 5),
  			true, true, controls);

  /* BUTTON FOR KEYS */
  _controlButtons = {
    /* PLAYER ONE */
    { PLAYER_1_UP, (_env->addButton(irr::core::rect<irr::s32>(30 + 140,
							      30 + 60,
							      80 + 240,
							      BUTTON_SIZE_Y  + 40),
				    controls, 112,
				    stringToWChar(printKeys(_settings._playerOne.getUpKey())),
				    L"Change the key by clicking on the button")) },
    { PLAYER_1_DOWN, (_env->addButton(irr::core::rect<irr::s32>(30 + 140,
								(30 + 100) + BUTTON_SIZE_Y,
								80 + 240,
								BUTTON_SIZE_Y * 2 + 80),
				      controls, 113,
				      stringToWChar(printKeys(_settings._playerOne.getDownKey())),
				      L"Change the key by clicking on the button")) },
    { PLAYER_1_LEFT, (_env->addButton(irr::core::rect<irr::s32>(30 + 140,
    								(30 + 120) + (BUTTON_SIZE_Y * 2),
    								80 + 240,
    								BUTTON_SIZE_Y * 3 + 100),
    				      controls, 114,
				      stringToWChar(printKeys(_settings._playerOne.getLeftKey())),
    				      L"Change the key by clicking on the button")) },
    { PLAYER_1_RIGHT, (_env->addButton(irr::core::rect<irr::s32>(30 + 140,
    								 (30 + 140) + (BUTTON_SIZE_Y * 3),
    								 80 + 240,
    								 BUTTON_SIZE_Y * 4 + 120),
    				       controls, 115,
				       stringToWChar(printKeys(_settings._playerOne.getRightKey())),
    				       L"Change the key by clicking on the button")) },
    { PLAYER_1_ATTACK, (_env->addButton(irr::core::rect<irr::s32>(30 + 140,
    								  (30 + 180) + (BUTTON_SIZE_Y * 4),
    								  80 + 240,
    								  BUTTON_SIZE_Y * 5 + 160),
    					controls, 116,
					stringToWChar(printKeys(_settings._playerOne.getAttackKey())),
    					L"Change the key by clicking on the button")) },
    /* PLAYER TWO */
    { PLAYER_2_UP, (_env->addButton(irr::core::rect<irr::s32>(30 + 140 + 300,
							      30 + 60,
							      80 + 240 + 300,
							      BUTTON_SIZE_Y + 40),
				    controls, 117,
				    stringToWChar(printKeys(_settings._playerTwo.getUpKey())),
				    L"Change the key by clicking on the button")) },
    { PLAYER_2_DOWN, (_env->addButton(irr::core::rect<irr::s32>(30 + 140 + 300,
								(30 + 100) + BUTTON_SIZE_Y,
								80 + 240 + 300,
								BUTTON_SIZE_Y * 2 + 80),
				      controls, 118,
				      stringToWChar(printKeys(_settings._playerTwo.getDownKey())),
				      L"Change the key by clicking on the button")) },
    { PLAYER_2_LEFT, (_env->addButton(irr::core::rect<irr::s32>(30 + 140 + 300,
    								(30 + 120) + (BUTTON_SIZE_Y * 2),
    								80 + 240 + 300,
    								BUTTON_SIZE_Y * 3 + 100),
    				      controls, 119,
				      stringToWChar(printKeys(_settings._playerTwo.getLeftKey())),
    				      L"Change the key by clicking on the button")) },
    { PLAYER_2_RIGHT, (_env->addButton(irr::core::rect<irr::s32>(30 + 140 + 300,
    								 (30 + 140) + (BUTTON_SIZE_Y * 3),
    								 80 + 240 + 300,
    								 BUTTON_SIZE_Y * 4 + 120),
    				       controls, 120,
				       stringToWChar(printKeys(_settings._playerTwo.getRightKey())),
    				       L"Change the key by clicking on the button")) },
    { PLAYER_2_ATTACK, (_env->addButton(irr::core::rect<irr::s32>(30 + 140 + 300,
    								  (30 + 180) + (BUTTON_SIZE_Y * 4),
    								  80 + 240 + 300,
    								  BUTTON_SIZE_Y * 5 + 160),
    					controls, 121,
					stringToWChar(printKeys(_settings._playerTwo.getAttackKey())),
    					L"Change the key by clicking on the button")) },
    /* PLAYER THREE */
    { PLAYER_3_UP, (_env->addButton(irr::core::rect<irr::s32>(30 + 140 + 600,
							      30 + 60,
							      80 + 240 + 600,
							      BUTTON_SIZE_Y + 40),
				    controls, 122,
				    stringToWChar(printKeys(_settings._playerThree.getUpKey())),
				    L"Change the key by clicking on the button")) },
    { PLAYER_3_DOWN, (_env->addButton(irr::core::rect<irr::s32>(30 + 140 + 600,
								(30 + 100) + BUTTON_SIZE_Y,
								80 + 240 + 600,
								BUTTON_SIZE_Y * 2 + 80),
				      controls, 123,
				      stringToWChar(printKeys(_settings._playerThree.getDownKey())),
				      L"Change the key by clicking on the button")) },
    { PLAYER_3_LEFT, (_env->addButton(irr::core::rect<irr::s32>(30 + 140 + 600,
    								(30 + 120) + (BUTTON_SIZE_Y * 2),
    								80 + 240 + 600,
    								BUTTON_SIZE_Y * 3 + 100),
    				      controls, 124,
				      stringToWChar(printKeys(_settings._playerThree.getLeftKey())),
    				      L"Change the key by clicking on the button")) },
    { PLAYER_3_RIGHT, (_env->addButton(irr::core::rect<irr::s32>(30 + 140 + 600,
    								 (30 + 140) + (BUTTON_SIZE_Y * 3),
    								 80 + 240 + 600,
    								 BUTTON_SIZE_Y * 4 + 120),
    				       controls, 125,
				       stringToWChar(printKeys(_settings._playerThree.getRightKey())),
    				       L"Change the key by clicking on the button")) },
    { PLAYER_3_ATTACK, (_env->addButton(irr::core::rect<irr::s32>(30 + 140 + 600,
    								  (30 + 180) + (BUTTON_SIZE_Y * 4),
    								  80 + 240 + 600,
    								  BUTTON_SIZE_Y * 5 + 160),
    					controls, 126,
					stringToWChar(printKeys(_settings._playerThree.getAttackKey())),
    					L"Change the key by clicking on the button")) },
    /* PLAYER FOUR */
    { PLAYER_4_UP, (_env->addButton(irr::core::rect<irr::s32>(30 + 140 + 900,
							      30 + 60,
							      80 + 240 + 900,
							      BUTTON_SIZE_Y + 40),
				    controls, 127,
				    stringToWChar(printKeys(_settings._playerFour.getUpKey())),
				    L"Change the key by clicking on the button")) },
    { PLAYER_4_DOWN, (_env->addButton(irr::core::rect<irr::s32>(30 + 140 + 900,
								(30 + 100) + BUTTON_SIZE_Y,
								80 + 240 + 900,
								BUTTON_SIZE_Y * 2 + 80),
				      controls, 128,
				      stringToWChar(printKeys(_settings._playerFour.getDownKey())),
				      L"Change the key by clicking on the button")) },
    { PLAYER_4_LEFT, (_env->addButton(irr::core::rect<irr::s32>(30 + 140 + 900,
    								(30 + 120) + (BUTTON_SIZE_Y * 2),
    								80 + 240 + 900,
    								BUTTON_SIZE_Y * 3 + 100),
    				      controls, 129,
				      stringToWChar(printKeys(_settings._playerFour.getLeftKey())),
    				      L"Change the key by clicking on the button")) },
    { PLAYER_4_RIGHT, (_env->addButton(irr::core::rect<irr::s32>(30 + 140 + 900,
    								 (30 + 140) + (BUTTON_SIZE_Y * 3),
    								 80 + 240 + 900,
    								 BUTTON_SIZE_Y * 4 + 120),
    				       controls, 130,
				       stringToWChar(printKeys(_settings._playerFour.getRightKey())),
    				       L"Change the key by clicking on the button")) },
    { PLAYER_4_ATTACK, (_env->addButton(irr::core::rect<irr::s32>(30 + 140 + 900,
    								  (30 + 180) + (BUTTON_SIZE_Y * 4),
    								  80 + 240 + 900,
    								  BUTTON_SIZE_Y * 5 + 160),
    					controls, 131,
					stringToWChar(printKeys(_settings._playerFour.getAttackKey())),
    					L"Change the key by clicking on the button")) }
  };
  for (size_t i = PLAYER_1_UP; i < UNDEFINED; i++)
    _controlButtons[static_cast< CONTROL_TYPE >(i)]->setImage(textureList[BUTTON]);
}

void				OptionMenuType::setButtons(std::unordered_map<TEXTURE_TYPE,
							   irr::video::ITexture *> textureList)
{
  _optionButtons = {
    {APPLY, (_env->addButton(irr::core::rect<irr::s32>(WIDTH - BUTTON_SIZE_X - MID(BUTTON_SIZE_X),
						       TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 2),
						       (WIDTH - BUTTON_SIZE_X - MID(BUTTON_SIZE_X))
						       + BUTTON_SIZE_X,
						       TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 2)
						       + BUTTON_SIZE_Y),
			     0, 110,
			     L"APPLY", L"Save your settings")) },
    {BACK_OPTION, (_env->addButton(irr::core::rect<irr::s32>((WIDTH - BUTTON_SIZE_X - MID(BUTTON_SIZE_X)),
							     TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 3) +
							     BUTTON_SIZE_Y,
							     (WIDTH - BUTTON_SIZE_X - MID(BUTTON_SIZE_X))
							     + BUTTON_SIZE_X,
							     TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 3) +
							     (BUTTON_SIZE_Y * 2)),
    			     0, 111,
    			     L"BACK", L"Go back to main Menu without saving your settings")) }
  };
  _optionButtons[APPLY]->setImage(textureList[BUTTON]);
  _optionButtons[BACK_OPTION]->setImage(textureList[BUTTON]);
}

void				OptionMenuType::setMenu(std::unordered_map<TEXTURE_TYPE,
							irr::video::ITexture *> textureList)
{
  _env->clear();
  /* LOGO + TEXTURE */
  _env->addImage(textureList[BACKGROUND], irr::core::position2d<irr::s32>(0, 0));

  /* Set Tabulation options */
  setTabOptions(textureList);

  /* Set Buttons */
  setButtons(textureList);

}
