//
// Sound.cpp for y in /home/dekamor/rendu_sec/project/test/indie/include
//
// Made by Dkamor
// Login   <corentin.bellamy@epitech.eu>
//
// Started on  Fri Jun 16 19:41:38 2017 Dkamor
// Last update Sun Jun 18 22:49:08 2017 bellamy corentin
//

#ifndef SOUND_HPP_
# define SOUND_HPP_

#include "irrKlang.h"
#include <iostream>

static const std::string		SOUND_STUDIO_SOLID = "media/sound/game/StudioSolid2.wav";
static const std::string		SOUND_GAME_OVER = "media/sound/game/Game_over.wav";
static const std::string		SOUND_TRANSITION = "media/sound/game/Transition1.wav";
static const std::string		SOUND_INTRO = "media/sound/game/Intro.wav";


static const std::string		SOUND_DJ = "media/sound/game/ambiance_dj.ogg";
static const std::string		POTION = "media/sound/game/potion.wav";
static const std::string		CLOSE_DOOR = "media/sound/game/close_door.wav";
static const std::string		FIREBALL = "media/sound/game/fire.wav";
static const std::string		VICTORY = "media/sound/game/victory.wav";
static const std::string		DOOR = "media/sound/game/door.ogg";
static const std::string		ARROW = "media/sound/game/Arrow.ogg";
static const std::string		SCREAM = "media/sound/game/scream.ogg";
static const std::string		KEY = "media/sound/game/key.ogg";
static const std::string		SWORD = "media/sound/game/Sword.wav";
static const std::string		YELL = "media/sound/game/yell.wav";
static const std::string		LAUGH = "media/sound/game/laugh.wav";


class		Sound
{
  irrklang::ISoundEngine *_engine;
  irrklang::ISound	*_music;
public:
  Sound();
  ~Sound();
  void		setSound(const std::string &, bool);
  void		addSound(const std::string &);
  void		setVolume(irrklang::ik_f32);

  void		setPause(bool val = true) { _music->setIsPaused(val); }

  void		dropEngine(void) { _engine->drop(); }
};

# endif /* !SOUND_HPP_ */
