//
// Settings.cpp for settings in /home/ndejean/EPITECH/indie/source/menu
//
// Made by nicolas dejean
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Thu Jun 15 08:58:05 2017 nicolas dejean
// Last update Sun Jun 18 17:37:01 2017 girard
//

#include "Settings.hpp"

Settings::Settings():
  // CONTROLS
  _playerOne("P1", "Z", "S", "Q", "D", "A"),
  _playerTwo("P2", "G", "B", "V", "N", " "),
  _playerThree("P3", "O", "L", "K", "M", "I"),
  _playerFour("P4", "&", "(", "%", "'", "3"),

  /* OPTIONS */
  _nulldevice(irr::createDevice(irr::video::EDT_NULL)),
  _deskres(_nulldevice->getVideoModeList()->getDesktopResolution()),
  _fullscreen(false),
  _username("Guest"),
  _nb_level(1),
  _nb_player(1),
  _joystick(false),
  _level(1)
{
  _nulldevice->drop();
    _replace = {
      { PLAYER_1_UP, (&PlayerSettings::setUpKey) },
      { PLAYER_1_DOWN, (&PlayerSettings::setDownKey) },
      { PLAYER_1_RIGHT, (&PlayerSettings::setRightKey) },
      { PLAYER_1_LEFT, (&PlayerSettings::setLeftKey) },
      { PLAYER_1_ATTACK, (&PlayerSettings::setAttackKey) },

      { PLAYER_2_UP, (&PlayerSettings::setUpKey) },
      { PLAYER_2_DOWN, (&PlayerSettings::setDownKey) },
      { PLAYER_2_RIGHT, (&PlayerSettings::setRightKey) },
      { PLAYER_2_LEFT, (&PlayerSettings::setLeftKey) },
      { PLAYER_2_ATTACK, (&PlayerSettings::setAttackKey) },

      { PLAYER_3_UP, (&PlayerSettings::setUpKey) },
      { PLAYER_3_DOWN, (&PlayerSettings::setDownKey) },
      { PLAYER_3_RIGHT, (&PlayerSettings::setRightKey) },
      { PLAYER_3_LEFT, (&PlayerSettings::setLeftKey) },
      { PLAYER_3_ATTACK, (&PlayerSettings::setAttackKey) },

      { PLAYER_4_UP, (&PlayerSettings::setUpKey) },
      { PLAYER_4_DOWN, (&PlayerSettings::setDownKey) },
      { PLAYER_4_RIGHT, (&PlayerSettings::setRightKey) },
      { PLAYER_4_LEFT, (&PlayerSettings::setLeftKey) },
      { PLAYER_4_ATTACK, (&PlayerSettings::setAttackKey) }
    };
}

Settings                      &Settings::operator=(const Settings& cp)
{
  if (this == &cp)
    return (*this);
  /* OPTIONS */
  setFullscreen(cp.getFullscreen());
  setUserName(cp.getUserName());
  setLevel(cp.getLevel());
  setNbLevel(cp.getNbLevel());
  setNbPlayer(cp.getNbPlayer());
  setJoystick(cp.getJoystick());

  /* CONTROLS */
  setPlayerOne(cp.getPlayerOne());
  setPlayerTwo(cp.getPlayerTwo());
  setPlayerThree(cp.getPlayerThree());
  setPlayerFour(cp.getPlayerFour());
  return (*this);
}

void					Settings::setPlayerOne(const PlayerSettings& cp)
{
  _playerOne.setUpKey(cp.getUpKey());
  _playerOne.setDownKey(cp.getDownKey());
  _playerOne.setLeftKey(cp.getLeftKey());
  _playerOne.setRightKey(cp.getRightKey());
  _playerOne.setAttackKey(cp.getAttackKey());
  _playerOne.setCharacter(cp.getCharacter());
}

void					Settings::setPlayerTwo(const PlayerSettings& cp)
{
  _playerTwo.setUpKey(cp.getUpKey());
  _playerTwo.setDownKey(cp.getDownKey());
  _playerTwo.setLeftKey(cp.getLeftKey());
  _playerTwo.setRightKey(cp.getRightKey());
  _playerTwo.setAttackKey(cp.getAttackKey());
  _playerTwo.setCharacter(cp.getCharacter());
}
void					Settings::setPlayerThree(const PlayerSettings& cp)
{
  _playerThree.setUpKey(cp.getUpKey());
  _playerThree.setDownKey(cp.getDownKey());
  _playerThree.setLeftKey(cp.getLeftKey());
  _playerThree.setRightKey(cp.getRightKey());
  _playerThree.setAttackKey(cp.getAttackKey());
  _playerThree.setCharacter(cp.getCharacter());
}
void					Settings::setPlayerFour(const PlayerSettings& cp)
{
  _playerFour.setUpKey(cp.getUpKey());
  _playerFour.setDownKey(cp.getDownKey());
  _playerFour.setLeftKey(cp.getLeftKey());
  _playerFour.setRightKey(cp.getRightKey());
  _playerFour.setAttackKey(cp.getAttackKey());
  _playerFour.setCharacter(cp.getCharacter());
}

void					Settings::incNbLevel(void)
{
  if (_nb_level < 9)
    _nb_level += 1;
}
