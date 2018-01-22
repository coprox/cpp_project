//
// PlayerSettings.cpp for player in /home/ndejean/EPITECH/indie/source/menu
//
// Made by nicolas dejean
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Thu Jun 15 19:33:14 2017 nicolas dejean
// Last update Sun Jun 18 02:39:30 2017 girard
//

#include "PlayerSettings.hpp"

PlayerSettings::PlayerSettings(const std::string &player,
			       const std::string& up, const std::string& down,
			       const std::string& left, const std::string& right,
			       const std::string& attack):
  _player(player),
  _up(up),
  _down(down),
  _left(left),
  _right(right),
  _attack(attack),
  _character(WARRIOR_ONE)
{}

PlayerSettings::PlayerSettings(const PlayerSettings &cp):
  _player(cp.getPlayer()),
  _up(cp.getUpKey()),
  _down(cp.getDownKey()),
  _left(cp.getLeftKey()),
  _right(cp.getRightKey()),
  _attack(cp.getAttackKey()),
  _character(cp.getCharacter())
{}

irr::EKEY_CODE				PlayerSettings::castKeyCode(const std::string &key) const
{
  if (key.size() == 0)
    return (irr::EKEY_CODE::KEY_KEY_CODES_COUNT);
  return (static_cast<irr::EKEY_CODE>(key.c_str()[0]));
}
