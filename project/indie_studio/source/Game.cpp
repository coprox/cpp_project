//
// Game.cpp for  in /home/tetard/eptechY2/CPP/indie/source
//
// Made by girard
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Fri Jun 16 16:30:32 2017 girard
// Last update Sun Jun 18 20:02:06 2017 nicolas dejean
//

# include <iostream>
# include "VideoPlayer.hpp"
# include "Game.hpp"

extern Sound sound;

Game::Game(void) : _isSettingsSaved(false) {}

ACharacter::PLAY_STATUS		Game::startGame(const std::string & /* profile */)
{
  std::unique_ptr<Menu>	menu;
  if (_isSettingsSaved)
    menu = std::make_unique<Menu>(_settings);
  else {
    menu = std::make_unique<Menu>();
    _isSettingsSaved = true;
  }
  if (!menu->runMenu())
    return (ACharacter::PLAY_STATUS::DEFAULT);

  _settings = menu->getSettings();
  GameLevel		level(menu->getSettings());

  ACharacter::PLAY_STATUS status;
  status = level.launchLevel();
  if (status == ACharacter::PLAY_STATUS::FINISH)
    _settings.incNbLevel();
  menu->setSettings(_settings);
  menu->overwriteSaveFile(_settings.getUserName());
  return (status);
}

void			Game::launchGame(const std::string &profile,
					 bool withIntro)
{

  if (withIntro) {

    VideoPlayer		vp(PATH_STUDIO_SOLID, FORMAT, FRAMES_STUDIO_SOLID);

    sound.setSound(SOUND_STUDIO_SOLID, false);
    vp.playVideo();
    vp.loadVideo(PATH_INTRO, FORMAT, FRAMES_INTRO);
    sound.setSound(SOUND_INTRO, false);
    vp.playVideo();
  }

  ACharacter::PLAY_STATUS status;
  status = startGame(profile);

  if (status == ACharacter::PLAY_STATUS::DEAD) {
    VideoPlayer		vp(PATH_GAME_OVER, FORMAT, FRAMES_GAME_OVER);
    sound.setSound(SOUND_GAME_OVER, false);
    vp.playVideo();
  }
  else if (status == ACharacter::PLAY_STATUS::FINISH ||
	   status == ACharacter::PLAY_STATUS::FINISH) {
    VideoPlayer		vp(PATH_TRANSITION, FORMAT, FRAMES_TRANSITION);
    sound.setSound(SOUND_TRANSITION, false);
    vp.playVideo();
  }
  else if (status == ACharacter::PLAY_STATUS::DEFAULT)
    return ;
  launchGame(profile, false);
}
