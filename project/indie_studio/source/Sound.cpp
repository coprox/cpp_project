//
// Sound.cpp for  in /home/dekamor/rendu_sec/project/test/indie/source
//
// Made by Dkamor
// Login   <corentin.bellamy@epitech.eu>
//
// Started on  Fri Jun 16 19:29:53 2017 Dkamor
// Last update Sat Jun 17 15:36:30 2017 girard
//

#include "Sound.hpp"

Sound::Sound()
{
  _engine = irrklang::createIrrKlangDevice();
}

void	Sound::setSound(const std::string &path, bool loop)
{
  _engine->drop();
  _engine = irrklang::createIrrKlangDevice();
  _music = _engine->play3D(path.c_str(),
			   irrklang::vec3df(0, 0, 0), loop, false, true);
}

void	Sound::setVolume(irrklang::ik_f32 volume)
{
 _music->setVolume(volume);
}

void	Sound::addSound(const std::string &path)
{
  _engine->play3D(path.c_str(), irrklang::vec3df(0, 0, 0));
}

Sound::~Sound()
{
  if (_engine)
    _engine->drop();
}
