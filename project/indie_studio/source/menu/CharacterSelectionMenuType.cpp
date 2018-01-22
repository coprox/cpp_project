//
// CharacterSelectionMenuType.cpp for char in /home/ndejean/EPITECH/indie/source/menu
//
// Made by nicolas dejean
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Fri Jun 16 14:43:43 2017 nicolas dejean
// Last update Sat Jun 17 12:39:00 2017 nicolas dejean
//

#include "CharacterSelectionMenuType.hpp"

CharacterSelectionMenuType::CharacterSelectionMenuType(irr::IrrlichtDevice* const device):
  AMenuType(device),
  _character({
      { SINGLE_PLAYER, (&CharacterSelectionMenuType::singleplayerButtons) },
      { TWO_PLAYER, (&CharacterSelectionMenuType::multiplayerTwoButtons) },
      { THREE_PLAYER, (&CharacterSelectionMenuType::multiplayerThreeButtons) },
      { FOUR_PLAYER, (&CharacterSelectionMenuType::multiplayerFourButtons) }
    })
{}

void				CharacterSelectionMenuType::setMenu(std::unordered_map<TEXTURE_TYPE,
								    irr::video::ITexture *> textureList)
{
  _env->clear();
  setButtons(textureList);
}

void				CharacterSelectionMenuType::setButtons(std::unordered_map<TEXTURE_TYPE,
								       irr::video::ITexture *> textureList)
{
  auto				it = _character.find(static_cast<START_TYPE>(_settings.getNbPlayer()));
  charfnct			f;

  if (it != _character.end())
  {
    f = it->second;
    (this->*f)(textureList);
  }
  _characterButtons[APPLY_CHARACTER] =
    _env->addButton(irr::core::rect<irr::s32>(WIDTH - BUTTON_SIZE_X - MID(BUTTON_SIZE_X),
					      TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 2),
					      (WIDTH - BUTTON_SIZE_X - MID(BUTTON_SIZE_X))
					      + BUTTON_SIZE_X,
					      TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 2)
					      + BUTTON_SIZE_Y),
		    0, 710,
		    L"APPLY", L"Save your character");
  _characterButtons[BACK_CHARACTER] =
    _env->addButton(irr::core::rect<irr::s32>((WIDTH - BUTTON_SIZE_X - MID(BUTTON_SIZE_X)),
					      TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 3) +
					      BUTTON_SIZE_Y,
					      (WIDTH - BUTTON_SIZE_X - MID(BUTTON_SIZE_X))
					      + BUTTON_SIZE_X,
					      TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 3) +
					      (BUTTON_SIZE_Y * 2)),
		    0, 711,
		    L"BACK", L"Go back to mode selection");

  _characterButtons[APPLY_CHARACTER]->setImage(textureList[BUTTON]);
  _characterButtons[BACK_CHARACTER]->setImage(textureList[BUTTON]);
}

void				CharacterSelectionMenuType::singleplayerButtons(std::unordered_map<TEXTURE_TYPE,
									       irr::video::ITexture *> textureList)
{
  _env->addImage(textureList[SINGLEPLAYER_BACKGROUND], irr::core::position2d<irr::s32>(0, 0));
  _characterButtons = {
    { WARRIOR_ONE, _env->addButton(irr::core::rect<irr::s32>(MID(WIDTH) - MID(BUTTON_SIZE_X),
							  TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y,
							  (MID(WIDTH) - MID(BUTTON_SIZE_X)) + BUTTON_SIZE_X,
							  TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y + BUTTON_SIZE_Y),
				0, 712,
				L"WARRIOR", L"Be the strongest character !") },
    { HUNTER_ONE, _env->addButton(irr::core::rect<irr::s32>(MID(WIDTH) - MID(BUTTON_SIZE_X),
							    TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 2) + BUTTON_SIZE_Y,
							  (MID(WIDTH) - MID(BUTTON_SIZE_X)) + BUTTON_SIZE_X,
							    TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 2) + BUTTON_SIZE_Y * 2),
				0, 713,
				L"HUNTER", L"Be the smartest character !") },
    { SORCERER_ONE, _env->addButton(irr::core::rect<irr::s32>(MID(WIDTH) - MID(BUTTON_SIZE_X),
							      TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 3)
							      + (BUTTON_SIZE_Y * 2),
							      (MID(WIDTH) - MID(BUTTON_SIZE_X)) + BUTTON_SIZE_X,
							      TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 3) + BUTTON_SIZE_Y * 3),
				    0, 714,
				    L"SORCERER", L"Be the wisest character !") }
  };

  for (size_t i = 0; i < WARRIOR_TWO; i++) {
    if (i == WARRIOR_ONE)
      _characterButtons[static_cast< CHARACTER_TYPE >(i)]->setImage(textureList[BUTTON_CLICKED]);
    else
      _characterButtons[static_cast< CHARACTER_TYPE >(i)]->setImage(textureList[BUTTON]);
  }
}

void				CharacterSelectionMenuType::multiplayerTwoButtons(std::unordered_map<TEXTURE_TYPE,
									       irr::video::ITexture *> textureList)
{
  _env->addImage(textureList[MULTIPLAYER_TWO_BACKGROUND], irr::core::position2d<irr::s32>(0, 0));
  _characterButtons = {
    /* CHARACTER FOR PLAYER 1 */
    { WARRIOR_ONE, _env->addButton(irr::core::rect<irr::s32>(MID(MID(WIDTH)) - MID(BUTTON_SIZE_X),
							     TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y,
							     (MID(MID(WIDTH)) - MID(BUTTON_SIZE_X)) + BUTTON_SIZE_X,
							     TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y + BUTTON_SIZE_Y),
				   0, 712,
				   L"WARRIOR", L"Be the strongest character !") },
    { HUNTER_ONE, _env->addButton(irr::core::rect<irr::s32>(MID(MID(WIDTH)) - MID(BUTTON_SIZE_X),
							    TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 2) + BUTTON_SIZE_Y,
							    (MID(MID(WIDTH)) - MID(BUTTON_SIZE_X)) + BUTTON_SIZE_X,
							    TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 2) + BUTTON_SIZE_Y * 2),
				0, 713,
				  L"HUNTER", L"Be the smartest character !") },
    { SORCERER_ONE, _env->addButton(irr::core::rect<irr::s32>(MID(MID(WIDTH)) - MID(BUTTON_SIZE_X),
							      TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 3)
							      + (BUTTON_SIZE_Y * 2),
							      (MID(MID(WIDTH)) - MID(BUTTON_SIZE_X)) + BUTTON_SIZE_X,
							      TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 3) + BUTTON_SIZE_Y * 3),
				    0, 714,
				    L"SORCERER", L"Be the wisest character !") },
    /* CHARACTER FOR PLAYER 2 */
    { WARRIOR_TWO, _env->addButton(irr::core::rect<irr::s32>(MID(WIDTH) - MID(BUTTON_SIZE_X),
							  TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y,
							  (MID(WIDTH) - MID(BUTTON_SIZE_X)) + BUTTON_SIZE_X,
							  TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y + BUTTON_SIZE_Y),
				0, 715,
				L"WARRIOR", L"Be the strongest character !") },
    { HUNTER_TWO, _env->addButton(irr::core::rect<irr::s32>(MID(WIDTH) - MID(BUTTON_SIZE_X),
							  TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y * 2 + BUTTON_SIZE_Y,
							  (MID(WIDTH) - MID(BUTTON_SIZE_X)) + BUTTON_SIZE_X,
							  TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y * 2 + BUTTON_SIZE_Y * 2),
				0, 716,
				L"HUNTER", L"Be the smartest character !") },
    { SORCERER_TWO, _env->addButton(irr::core::rect<irr::s32>(MID(WIDTH) - MID(BUTTON_SIZE_X),
							  TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y * 3 + BUTTON_SIZE_Y * 2,
							  (MID(WIDTH) - MID(BUTTON_SIZE_X)) + BUTTON_SIZE_X,
							  TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y * 3 + BUTTON_SIZE_Y * 3),
				0, 717,
				L"SORCERER", L"Be the wisest character !") }
  };
  for (size_t i = 0; i < WARRIOR_THREE; i++)
  {
    if (i == WARRIOR_ONE || i == WARRIOR_TWO)
      _characterButtons[static_cast< CHARACTER_TYPE >(i)]->setImage(textureList[BUTTON_CLICKED]);
    else
      _characterButtons[static_cast< CHARACTER_TYPE >(i)]->setImage(textureList[BUTTON]);
  }
}

void				CharacterSelectionMenuType::multiplayerThreeButtons(std::unordered_map<TEXTURE_TYPE,
									       irr::video::ITexture *> textureList)
{
  _env->addImage(textureList[MULTIPLAYER_THREE_BACKGROUND], irr::core::position2d<irr::s32>(0, 0));
  _characterButtons = {
    /* CHARACTER FOR PLAYER 1 */
    { WARRIOR_ONE, _env->addButton(irr::core::rect<irr::s32>(MID(MID(BUTTON_SIZE_X)),
							     TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y,
							     (MID(MID(BUTTON_SIZE_X))) + BUTTON_SIZE_X,
							     TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y + BUTTON_SIZE_Y),
				   0, 712,
				   L"WARRIOR", L"Be the strongest character !") },
    { HUNTER_ONE, _env->addButton(irr::core::rect<irr::s32>(MID(MID(BUTTON_SIZE_X)),
							    TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 2) + BUTTON_SIZE_Y,
							    (MID(MID(BUTTON_SIZE_X))) + BUTTON_SIZE_X,
							    TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 2) + BUTTON_SIZE_Y * 2),
				0, 713,
				  L"HUNTER", L"Be the smartest character !") },
    { SORCERER_ONE, _env->addButton(irr::core::rect<irr::s32>(MID(MID(BUTTON_SIZE_X)),
							      TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 3)
							      + (BUTTON_SIZE_Y * 2),
							      (MID(MID(BUTTON_SIZE_X))) + BUTTON_SIZE_X,
							      TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 3) + BUTTON_SIZE_Y * 3),
				    0, 714,
				    L"SORCERER", L"Be the wisest character !") },
    /* CHARACTER FOR PLAYER 2 */
    { WARRIOR_TWO, _env->addButton(irr::core::rect<irr::s32>(MID(MID(WIDTH)),
							  TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y,
							     (MID(MID(WIDTH))) + BUTTON_SIZE_X,
							  TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y + BUTTON_SIZE_Y),
				0, 715,
				L"WARRIOR", L"Be the strongest character !") },
    { HUNTER_TWO, _env->addButton(irr::core::rect<irr::s32>(MID(MID(WIDTH)),
							  TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y * 2 + BUTTON_SIZE_Y,
							  (MID(MID(WIDTH))) + BUTTON_SIZE_X,
							  TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y * 2 + BUTTON_SIZE_Y * 2),
				0, 716,
				L"HUNTER", L"Be the smartest character !") },
    { SORCERER_TWO, _env->addButton(irr::core::rect<irr::s32>(MID(MID(WIDTH)),
							  TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y * 3 + BUTTON_SIZE_Y * 2,
							  (MID(MID(WIDTH))) + BUTTON_SIZE_X,
							  TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y * 3 + BUTTON_SIZE_Y * 3),
				0, 717,
				    L"SORCERER", L"Be the wisest character !") },
    /* CHARACTER FOR PLAYER 3 */
    { WARRIOR_THREE, _env->addButton(irr::core::rect<irr::s32>(MID(WIDTH) - MID(MID(BUTTON_SIZE_X)),
							       TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y,
							       (MID(WIDTH) - MID(MID(BUTTON_SIZE_X))) + BUTTON_SIZE_X,
							       TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y + BUTTON_SIZE_Y),
				0, 718,
				L"WARRIOR", L"Be the strongest character !") },
  { HUNTER_THREE, _env->addButton(irr::core::rect<irr::s32>(MID(WIDTH) - MID(MID(BUTTON_SIZE_X)),
							    TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 2) + BUTTON_SIZE_Y,
							    (MID(WIDTH) - MID(MID(BUTTON_SIZE_X))) + BUTTON_SIZE_X,
							    TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y * 2 + BUTTON_SIZE_Y * 2),
				0, 719,
				L"HUNTER", L"Be the smartest character !") },
    { SORCERER_THREE, _env->addButton(irr::core::rect<irr::s32>(MID(WIDTH) - MID(MID(BUTTON_SIZE_X)),
							  TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y * 3 + BUTTON_SIZE_Y * 2,
							  (MID(WIDTH) - MID(MID(BUTTON_SIZE_X))) + BUTTON_SIZE_X,
							  TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y * 3 + BUTTON_SIZE_Y * 3),
				0, 720,
				L"SORCERER", L"Be the wisest character !") }
  };
  for (size_t i = 0; i < WARRIOR_FOUR; i++)
  {
    if (i == WARRIOR_ONE || i == WARRIOR_TWO || i == WARRIOR_THREE)
      _characterButtons[static_cast< CHARACTER_TYPE >(i)]->setImage(textureList[BUTTON_CLICKED]);
    else
      _characterButtons[static_cast< CHARACTER_TYPE >(i)]->setImage(textureList[BUTTON]);
  }
}

void				CharacterSelectionMenuType::multiplayerFourButtons(std::unordered_map<TEXTURE_TYPE,
									       irr::video::ITexture *> textureList)
{
  _env->addImage(textureList[MULTIPLAYER_FOUR_BACKGROUND], irr::core::position2d<irr::s32>(0, 0));
  _characterButtons = {
    /* CHARACTER FOR PLAYER 1 */
    { WARRIOR_ONE, _env->addButton(irr::core::rect<irr::s32>(MID(MID(BUTTON_SIZE_X)),
							     TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y,
							     (MID(MID(BUTTON_SIZE_X))) + BUTTON_SIZE_X,
							     TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y + BUTTON_SIZE_Y),
				   0, 712,
				   L"WARRIOR", L"Be the strongest character !") },
    { HUNTER_ONE, _env->addButton(irr::core::rect<irr::s32>(MID(MID(BUTTON_SIZE_X)),
							    TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 2) + BUTTON_SIZE_Y,
							    (MID(MID(BUTTON_SIZE_X))) + BUTTON_SIZE_X,
							    TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 2) + BUTTON_SIZE_Y * 2),
				0, 713,
				  L"HUNTER", L"Be the smartest character !") },
    { SORCERER_ONE, _env->addButton(irr::core::rect<irr::s32>(MID(MID(BUTTON_SIZE_X)),
							      TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 3)
							      + (BUTTON_SIZE_Y * 2),
							      (MID(MID(BUTTON_SIZE_X))) + BUTTON_SIZE_X,
							      TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 3) + BUTTON_SIZE_Y * 3),
				    0, 714,
				    L"SORCERER", L"Be the wisest character !") },
    /* CHARACTER FOR PLAYER 2 */
    { WARRIOR_TWO, _env->addButton(irr::core::rect<irr::s32>(MID(MID(WIDTH)) - MID(MID(BUTTON_SIZE_X)),
							  TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y,
							     (MID(MID(WIDTH)) - MID(MID(BUTTON_SIZE_X))) + BUTTON_SIZE_X,
							  TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y + BUTTON_SIZE_Y),
				0, 715,
				L"WARRIOR", L"Be the strongest character !") },
    { HUNTER_TWO, _env->addButton(irr::core::rect<irr::s32>(MID(MID(WIDTH)) - MID(MID(BUTTON_SIZE_X)),
							  TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y * 2 + BUTTON_SIZE_Y,
							  (MID(MID(WIDTH)) - MID(MID(BUTTON_SIZE_X))) + BUTTON_SIZE_X,
							  TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y * 2 + BUTTON_SIZE_Y * 2),
				0, 716,
				L"HUNTER", L"Be the smartest character !") },
    { SORCERER_TWO, _env->addButton(irr::core::rect<irr::s32>(MID(MID(WIDTH)) - MID(MID(BUTTON_SIZE_X)),
							  TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y * 3 + BUTTON_SIZE_Y * 2,
							  (MID(MID(WIDTH)) - MID(MID(BUTTON_SIZE_X))) + BUTTON_SIZE_X,
							  TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y * 3 + BUTTON_SIZE_Y * 3),
				0, 717,
				    L"SORCERER", L"Be the wisest character !") },
    /* CHARACTER FOR PLAYER 3 */
    { WARRIOR_THREE, _env->addButton(irr::core::rect<irr::s32>(MID(WIDTH) - (MID(BUTTON_SIZE_X) + MID(MID(BUTTON_SIZE_X))),
							       TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y,
							       (MID(WIDTH) - (MID(BUTTON_SIZE_X) + MID(MID(BUTTON_SIZE_X)))) + BUTTON_SIZE_X,
							       TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y + BUTTON_SIZE_Y),
				0, 718,
				L"WARRIOR", L"Be the strongest character !") },
  { HUNTER_THREE, _env->addButton(irr::core::rect<irr::s32>(MID(WIDTH) - (MID(BUTTON_SIZE_X) + MID(MID(BUTTON_SIZE_X))),
							    TITLE_UP_Y + TITLE_Y + (BUTTON_DISTANCE_Y * 2) + BUTTON_SIZE_Y,
							    (MID(WIDTH) - (MID(BUTTON_SIZE_X) + MID(MID(BUTTON_SIZE_X)))) + BUTTON_SIZE_X,
							    TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y * 2 + BUTTON_SIZE_Y * 2),
				0, 719,
				L"HUNTER", L"Be the smartest character !") },
    { SORCERER_THREE, _env->addButton(irr::core::rect<irr::s32>(MID(WIDTH) - (MID(BUTTON_SIZE_X) + MID(MID(BUTTON_SIZE_X))),
							  TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y * 3 + BUTTON_SIZE_Y * 2,
							  (MID(WIDTH) - (MID(BUTTON_SIZE_X) + MID(MID(BUTTON_SIZE_X)))) + BUTTON_SIZE_X,
							  TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y * 3 + BUTTON_SIZE_Y * 3),
				0, 720,
				      L"SORCERER", L"Be the wisest character !") },
    /* CHARACTER FOR PLAYER 4 */
    { WARRIOR_FOUR, _env->addButton(irr::core::rect<irr::s32>(MID(WIDTH) + MID(BUTTON_SIZE_X) - MID(MID(MID(BUTTON_SIZE_X))),
							      TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y,
							      (MID(WIDTH) + MID(BUTTON_SIZE_X) - MID(MID(MID(BUTTON_SIZE_X)))) + BUTTON_SIZE_X,
							      TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y + BUTTON_SIZE_Y),
				0, 721,
				L"WARRIOR", L"Be the strongest character !") },
    { HUNTER_FOUR, _env->addButton(irr::core::rect<irr::s32>(MID(WIDTH) + MID(BUTTON_SIZE_X) - MID(MID(MID(BUTTON_SIZE_X))),
							  TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y * 2 + BUTTON_SIZE_Y,
							  (MID(WIDTH) + MID(BUTTON_SIZE_X) - MID(MID(MID(BUTTON_SIZE_X)))) + BUTTON_SIZE_X,
							  TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y * 2 + BUTTON_SIZE_Y * 2),
				0, 722,
				L"HUNTER", L"Be the smartest character !") },
    { SORCERER_FOUR, _env->addButton(irr::core::rect<irr::s32>(MID(WIDTH) + MID(BUTTON_SIZE_X) - MID(MID(MID(BUTTON_SIZE_X))),
							  TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y * 3 + BUTTON_SIZE_Y * 2,
							  (MID(WIDTH) + MID(BUTTON_SIZE_X) - MID(MID(MID(BUTTON_SIZE_X)))) + BUTTON_SIZE_X,
							  TITLE_UP_Y + TITLE_Y + BUTTON_DISTANCE_Y * 3 + BUTTON_SIZE_Y * 3),
				0, 723,
				L"SORCERER", L"Be the wisest character !") }
  };
  for (size_t i = 0; i < APPLY_CHARACTER; i++)
  {
    if (i == WARRIOR_ONE || i == WARRIOR_TWO || i == WARRIOR_THREE || i == WARRIOR_FOUR)
      _characterButtons[static_cast< CHARACTER_TYPE >(i)]->setImage(textureList[BUTTON_CLICKED]);
    else
      _characterButtons[static_cast< CHARACTER_TYPE >(i)]->setImage(textureList[BUTTON]);
  }
}
