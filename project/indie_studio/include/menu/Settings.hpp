//
// Settings.hpp for settings in /home/ndejean/EPITECH/cpp_indie_studio/Menu
//
// Made by nicolas dejean
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Fri Jun  2 15:25:26 2017 nicolas dejean
// Last update Sun Jun 18 17:36:02 2017 girard
//

#ifndef SETTINGS_HPP_
#define SETTINGS_HPP_

#include <string>
#include <unordered_map>

#include "PlayerSettings.hpp"
#include "GlobalVar.hpp"

class				Settings
{
public:
  typedef void (PlayerSettings::*fkeys)(const std::string& key);

  Settings();
  ~Settings() = default;
  Settings(const Settings& cp);
  Settings			&operator=(const Settings& cp);

  std::unordered_map< CONTROL_TYPE, fkeys >     _replace;

  /* GETTERS && SETTERS*/

  /* OPTIONS */
  void				setFullscreen(bool fullscreen) {_fullscreen = fullscreen;}
  bool				getFullscreen(void) const { return (_fullscreen); }
  void				setUserName(const std::string& username) {_username = username;}
  const std::string		&getUserName(void) const { return (_username); }
  void				setLevel(uint16_t lvl) {_level = lvl;}
  uint16_t			getLevel(void) const { return (_level); }
  void				setNbLevel(uint16_t lvl) {_nb_level = lvl;}
  uint16_t			getNbLevel(void) const { return (_nb_level); }
  void				setNbPlayer(uint16_t nb_player) {_nb_player = nb_player;}
  uint16_t			getNbPlayer(void) const { return (_nb_player); }
  void				setJoystick(bool joystick) {_joystick = joystick;}
  int				getJoystick(void) const { return (_joystick); }
  const irr::core::dimension2d<irr::u32> &getDeskres(void) { return (_deskres); }


  /* CONTROLS */

  PlayerSettings		_playerOne;
  PlayerSettings		_playerTwo;
  PlayerSettings		_playerThree;
  PlayerSettings		_playerFour;

  const PlayerSettings		&getPlayerOne() const { return (_playerOne); }
  const PlayerSettings		&getPlayerTwo() const { return (_playerTwo); }
  const PlayerSettings		&getPlayerThree() const { return (_playerThree); }
  const PlayerSettings		&getPlayerFour() const { return (_playerFour); }

  void				setPlayerOne(const PlayerSettings &);
  void				setPlayerTwo(const PlayerSettings &);
  void				setPlayerThree(const PlayerSettings &);
  void				setPlayerFour(const PlayerSettings &);

  void				incNbLevel(void);
private:
  /* OPTIONS */
  irr::IrrlichtDevice *const	_nulldevice;
  irr::core::dimension2d<irr::u32>	_deskres;
  bool				_fullscreen;
  std::string			_username;
  uint16_t			_nb_level;
  uint16_t			_nb_player;
  bool				_joystick;
  uint16_t			_level;

};

#endif /* SETTINGS_HPP_ */
