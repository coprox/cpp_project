//
// Game.hpp for  in /home/tetard/eptechY2/CPP/indie
//
// Made by girard
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Fri Jun 16 12:22:14 2017 girard
// Last update Sun Jun 18 20:25:04 2017 bellamy corentin
//

# ifndef GAME_HPP_
# define GAME_HPP_

# include "Sound.hpp"
# include "Menu.hpp"
# include "GameLevel.hpp"

class						Game
{
  Settings					_settings;
  bool						_isSettingsSaved;

public:
  Game(void);
  virtual ~Game(void) = default;
  Game(const Game &cp) = delete;
  Game						&operator=(const Game &cp) = delete;

  void						launchGame(const std::string &profil = "",
							   bool withIntro = true);
  ACharacter::PLAY_STATUS			startGame(const std::string &profile);
};

# endif /* GAME_HPP_ */
