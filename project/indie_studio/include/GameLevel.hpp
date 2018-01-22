//
// GameLevel.hpp for  in /home/tetard/eptechY2/CPP/indie
//
// Made by girard
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Fri Jun 16 12:22:14 2017 girard
// Last update Sun Jun 18 21:28:42 2017 Mattéo Margueritte
//

# ifndef GAMELEVEL_HPP_
# define GAMELEVEL_HPP_

# include <vector>
# include <list>
# include <memory>
# include "Sound.hpp"
# include "Camera.hpp"
# include "Settings.hpp"
# include "Menu.hpp"
# include "AGenerator.hpp"
# include "MyEventReceiver.hpp"
# include "ACharacter.hpp"
# include "Map.hpp"
# include "irrlicht.h"

static const std::string			INVISIBLE_POINT =
  "media/models/invisible_point.obj";

static const size_t				Y_BASE = 20;

class						GameLevel
{
private:
  Settings					_settings;

  std::vector<std::shared_ptr<ACharacter> >	_players;
  std::list<std::shared_ptr<ACharacter> >	_monsters;
  std::list<std::shared_ptr<ACharacter> >	_generators;

  std::shared_ptr<Map>				_map;

  irr::IrrlichtDevice				*_device;
  irr::video::IVideoDriver			*_driver;
  irr::scene::ISceneManager			*_smgr;
  irr::scene::IMetaTriangleSelector		*_monstersCollision;

  MyEventReceiver				_receiver;

public:
  GameLevel(const Settings &settings);
  virtual ~GameLevel(void);
  GameLevel(const GameLevel &cp) = delete;
  GameLevel						&operator=(const GameLevel &cp) = delete;

  ACharacter::PLAY_STATUS			launchLevel(void);

  const Settings				&getSettings(void) const { return (_settings); }
private:
  // init in GameLevel.cpp
  bool						instanciateGameLevel(void);
  bool						initIrrlicht(void);
  bool						initEnvironment(void);

  std::shared_ptr<ACharacter>			chooseCharacter(const PlayerSettings &ps,
								 const irr::core::vector3df &pos);
  void						initOnePlayer
  (const irr::core::vector3df &pos);
  void						initTwoPlayer
  (const irr::core::vector3df &pos);
  void						initThreePlayer
  (const irr::core::vector3df &pos);
  void						initFourPlayer
  (const irr::core::vector3df &pos);

  bool						initPlayers(void);

  bool						initCamera(void);

  // Players functions in PlayersGame.cpp
  irr::core::vector3df				getPlayersAveragePosition(void);


  ACharacter::PLAY_STATUS			playerTurn(const irr::f32 fdt);
  ACharacter::PLAY_STATUS			initLoop(void);
  void						checkDeadCharacters(void);
};

# endif /* GAMELEVEL_HPP_ */
