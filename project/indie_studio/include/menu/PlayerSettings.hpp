//
// PlayerSettings.hpp for player in /home/ndejean/EPITECH/indie/include/menu
//
// Made by nicolas dejean
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Thu Jun 15 19:35:27 2017 nicolas dejean
// Last update Sun Jun 18 02:45:59 2017 girard
//

#ifndef PLAYERSETTINGS_HPP_
#define PLAYERSETTINGS_HPP_

#include <string>
#include "GlobalVar.hpp"

class				PlayerSettings
{
private:
  std::string				_player;

  std::string				_up;
  std::string				_down;
  std::string				_left;
  std::string				_right;
  std::string				_attack;
  CHARACTER_TYPE			_character;

public:
  PlayerSettings(const std::string &player = "",
		 const std::string &up = "", const std::string &down = "",
		 const std::string &left = "", const std::string &right = "",
		 const std::string &attack = "");
  ~PlayerSettings() = default;
  PlayerSettings(const PlayerSettings& cp);
  PlayerSettings		&operator=(const PlayerSettings& cp) = delete;

  irr::EKEY_CODE				castKeyCode(const std::string &key) const;

  /* SETTER && GETTER */
  const std::string				&getPlayer() const { return (_player); }

  const std::string				&getUpKey() const { return (_up); }
  const std::string				&getDownKey() const { return (_down); }
  const std::string				&getRightKey() const { return (_right); }
  const std::string				&getLeftKey() const { return (_left); }
  const std::string				&getAttackKey() const { return (_attack); }
  irr::EKEY_CODE				getEnumUpKey() const { return (castKeyCode(_up)); }
  irr::EKEY_CODE				getEnumDownKey() const { return (castKeyCode(_down)); }
  irr::EKEY_CODE				getEnumRightKey() const { return (castKeyCode(_right)); }
  irr::EKEY_CODE				getEnumLeftKey() const { return (castKeyCode(_left)); }
  irr::EKEY_CODE				getEnumAttackKey() const { return (castKeyCode(_attack)); }
  CHARACTER_TYPE				getCharacter() const { return (_character); }

  void						setUpKey(const std::string &up) { _up = up; }
  void						setDownKey(const std::string &down) { _down = down; }
  void						setLeftKey(const std::string &left) { _left = left; }
  void						setRightKey(const std::string &right) { _right = right; }
  void						setAttackKey(const std::string  &attack) { _attack = attack; }
  void						setCharacter(CHARACTER_TYPE character) { _character = character;}

};

#endif /* !PLAYERSETTINGS_HPP_ */
