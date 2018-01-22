//
// VideoPlayer.hpp for indie in /home/margue_m/rendu/tmp/VideoLoader
//
// Made by Mattéo Margueritte
// Login   <margue_m@epitech.net>
//
// Started on  Sat Jun 17 14:29:16 2017 Mattéo Margueritte
// Last update Sun Jun 18 15:33:52 2017 girard
//

#ifndef VIDEOPLAYER_HPP_
# define VIDEOPLAYER_HPP_

# include <string>
# include <stdexcept>
# include "irrlicht.h"

static const std::string			PATH_STUDIO_SOLID = "./media/video/frame/StudioSolid/studiosolid_";

static const size_t				FRAMES_STUDIO_SOLID = 145;

static const std::string			PATH_INTRO = "./media/video/frame/Intro/intro_";
static const size_t				FRAMES_INTRO = 399;

static const std::string			PATH_GAME_OVER = "./media/sound/game/Game_over.wav";
static const size_t				FRAMES_GAME_OVER = 103;

static const std::string			PATH_TRANSITION = "./media/video/frame/Transition/transition_";
static const size_t				FRAMES_TRANSITION = 212;


static const std::string			FORMAT = ".jpg";

class			VideoPlayer
{
  irr::IrrlichtDevice	*_device;
  irr::video::IVideoDriver *_driver;
  irr::gui::IGUIEnvironment *_env;
  unsigned int		_frameNumber;
  unsigned int		_maxFrames;
  std::string		_frameName;
  std::string		_format;
  std::string		_name;

public:
  VideoPlayer(std::string const &,
	      std::string const &,
	      const unsigned int);
  ~VideoPlayer(void);

  void			playVideo(void);
  void			loadVideo(std::string const &,
				  std::string const &,
				  const unsigned int);
};

#endif //VIDEOPLAYER_HPP_
