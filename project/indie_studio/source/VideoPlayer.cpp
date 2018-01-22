//
// VideoPlayer.cpp for indie in /home/margue_m/rendu/tmp/VideoLoader
//
// Made by Mattéo Margueritte
// Login   <margue_m@epitech.net>
//
// Started on  Sat Jun 17 14:29:20 2017 Mattéo Margueritte
// Last update Sun Jun 18 15:36:12 2017 girard
//

#include "VideoPlayer.hpp"

VideoPlayer::VideoPlayer(std::string const &name,
			 std::string const &format,
			 const unsigned int maxFrames) :
  _frameNumber(1), _maxFrames(maxFrames), _format(format),
  _name(name)
{
  irr::IrrlichtDevice *nulldevice = irr::createDevice(irr::video::EDT_NULL);
  irr::core::dimension2d<irr::u32> deskres = nulldevice->getVideoModeList()->getDesktopResolution();
  nulldevice->drop();
  _device = irr::createDevice(irr::video::EDT_OPENGL,deskres);

  if (!_device)
    throw std::runtime_error("Couldn't create device");
  _env = _device->getGUIEnvironment();
  if (!_env)
    throw std::runtime_error("Couldn't get env");
  _driver = _device->getVideoDriver();
  if (!_driver)
    throw std::runtime_error("Couldn't get VideoDriver");
}

VideoPlayer::~VideoPlayer(void)
{
  if (_device)
    _device->drop();
}

void				VideoPlayer::playVideo(void)
{
  while (_device->run())
    {
      _frameName.clear();
      _frameName += _name;
      _frameName += std::to_string(_frameNumber);
      _frameName += _format;
      _env->addImage(_driver->getTexture(_frameName.c_str()),
		     irr::core::position2d<irr::s32>(0, 0));
      _driver->beginScene();
      _env->drawAll();
      _driver->endScene();
      _env->clear();
      _driver->removeAllTextures();
      if (_frameNumber == _maxFrames)
	return ;
      ++_frameNumber;
    }
}

void				VideoPlayer::loadVideo(std::string const &name,
						       std::string const &format,
						       const unsigned int maxFrames)
{
  _name = name;
  _format = format;
  _maxFrames = maxFrames;
  _frameNumber = 1;
}
