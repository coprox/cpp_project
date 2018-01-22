//
// GameLevel.cpp for  in /home/tetard/eptechY2/CPP/indie
//
// Made by girard
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Fri Jun 16 13:15:31 2017 girard
// Last update Sun Jun 18 20:13:38 2017 girard
//

# include "ArachneGenerator.hpp"
# include "Mage.hpp"
# include "Hunter.hpp"
# include "Warrior.hpp"
# include "GameLevel.hpp"
# include "LifeBar.hpp"
# include "XpBar.hpp"

extern Sound sound;

GameLevel::GameLevel(const Settings &settings) :
  _device(NULL),
  _driver(NULL),
  _smgr(NULL)
{
  _settings = settings;
  sound.setSound(SOUND_DJ, true);
  sound.addSound(CLOSE_DOOR);
}

GameLevel::~GameLevel(void)
{
  if (_device) {
    _device->closeDevice();
    _device->run();
    _device->drop();
  }
}

bool				GameLevel::initIrrlicht(void)
{
  // Take settings from menu and load device from that
  irr::IrrlichtDevice		*nulldevice = irr::createDevice(irr::video::EDT_NULL);
  irr::core::dimension2d<irr::u32> deskres = nulldevice->getVideoModeList()->getDesktopResolution();
  nulldevice->drop();

  irr::SIrrlichtCreationParameters params;

  params.Fullscreen = _settings.getFullscreen();
  params.DriverType = irr::video::EDT_OPENGL;
  params.WindowSize = deskres;
  params.EventReceiver = &_receiver;

  _device = irr::createDeviceEx(params);
  if (!_device)
    return (false);
  _driver = _device->getVideoDriver();
  _smgr = _device->getSceneManager();
  if (_driver == NULL || _smgr == NULL)
    return (false);
  _monstersCollision = _smgr->createMetaTriangleSelector();
  if (_monstersCollision == NULL)
    return (false);
  return (true);
}

bool				GameLevel::initEnvironment(void)
{
  // Take the path from the settings
  if (MAP_LEVEL.find(_settings.getLevel()) == MAP_LEVEL.end()) {
    throw std::runtime_error("An error occured while loading level");
    return (false);
  }
  _map = std::make_shared<Map>(_device, MAP_LEVEL[_settings.getLevel()]);
  return (true);
}

std::shared_ptr<ACharacter> GameLevel::chooseCharacter(const PlayerSettings &ps,
						   const irr::core::vector3df &pos)
{
  std::shared_ptr<ACharacter>	charac;

  switch (ps.getCharacter())
  {
  case WARRIOR_ONE:
    charac = std::make_shared<Warrior>(_device, _map, ps, _players,
				    _monstersCollision, pos);
    break ;
  case HUNTER_ONE:
    charac = std::make_shared<Hunter>(_device, _map, ps, _players,
				      _monstersCollision, pos);
    break ;
  case SORCERER_ONE:
    charac = std::make_shared<Mage>(_device, _map, ps, _players,
				    _monstersCollision, pos);
    break ;
  default:
    throw std::runtime_error("Error while choosing character");
    break ;
  }
  return (charac);
}

bool				GameLevel::initPlayers(void)
{
  // take players from settings
  irr::core::vector3df		startPos(_map->getPlayerStartPos().first, Y_BASE,
					 _map->getPlayerStartPos().second);


  switch (_settings.getNbPlayer())
  {
  case 1:
    initOnePlayer(startPos);
    break;
  case 2:
    initTwoPlayer(startPos);
    break;
  case 3:
    initThreePlayer(startPos);
    break;
  case 4:
    initFourPlayer(startPos);
    break;
  default:
    throw std::runtime_error("Error while number of players");
    break;
  }

  size_t			numSpawn = 1;

  auto				mapObjects = _map->getObjects();
  while (mapObjects.find(std::string("spawner") + std::to_string(numSpawn)) != mapObjects.end())
  {
    std::string			key = std::string("spawner") + std::to_string(numSpawn);
    _generators.push_back(std::make_shared<ArachneGenerator>(mapObjects[key],
							     _device, _map, PS_DEFAULT, _players,
							     mapObjects[key]->getPosition()));
    numSpawn += 1;
  }
  return (true);
}

bool				GameLevel::instanciateGameLevel(void)
{
  if (!initIrrlicht() || !initEnvironment() || !initPlayers())
    throw std::runtime_error("Initialization level failed");
  return (true);
}

ACharacter::PLAY_STATUS		GameLevel::launchLevel(void)
{
  instanciateGameLevel();

  return (initLoop());
}

void				GameLevel::checkDeadCharacters(void)
{
  auto it_monster = _monsters.begin();
  auto it_generator = _generators.begin();

  while (it_monster != _monsters.end())
    {
      if ((*it_monster)->isDead() == true)
	{
	  (*it_monster)->getNode()->setVisible(false);
	  it_monster = _monsters.erase(it_monster);
	}
      else
	++it_monster;
    }
  while (it_generator != _generators.end())
    {
      if ((*it_generator)->isDead() == true)
	{
	  (*it_generator)->getNode()->setPosition(irr::core::vector3df(0, 500, 0));
	  it_generator = _generators.erase(it_generator);
	}
      else
	++it_generator;
    }
}

ACharacter::PLAY_STATUS		GameLevel::playerTurn(const irr::f32 fdt)
{
    ACharacter::PLAY_STATUS	actionStatus;
    auto			itPlayer = _players.begin();

    while (itPlayer != _players.end())
    {
      actionStatus = (*itPlayer)->play(_receiver, fdt, _monsters, _generators);
      if (actionStatus == ACharacter::PLAY_STATUS::FINISH)
	return (ACharacter::PLAY_STATUS::FINISH);
      if ((*itPlayer)->getPosition().Y < -10 || actionStatus == ACharacter::PLAY_STATUS::DEAD)
	itPlayer = _players.erase(itPlayer);
      else
	itPlayer++;
    }
    if (_players.size() == 0)
      return  (ACharacter::PLAY_STATUS::DEAD);
    return (ACharacter::PLAY_STATUS::ALIVE);
}

ACharacter::PLAY_STATUS		GameLevel::initLoop(void)
{
  Timer				time(_device);
  Camera			cam(_smgr, _players);

  while (_device->run())
  {
    if (_receiver.IsKeyDown(irr::KEY_ESCAPE))
      break ;

    ACharacter::PLAY_STATUS	actionStatus;
    irr::f32 fdt = time.frameDeltaTime();

    if ((actionStatus = playerTurn(fdt)) != ACharacter::PLAY_STATUS::ALIVE)
      return (actionStatus);
    cam.updateCamera(_players);
    if (_monsters.size() < NB_MONSTERS_MAX) {
      for (auto &it : _generators)
      {
	std::list<std::shared_ptr<ACharacter> > tmp =
	  dynamic_cast<AGenerator *>(it.get())->generate(_device, _players,
							 _monstersCollision);
	for (auto &tt : tmp)
	  _monsters.push_back(tt);
      }
    }
    for (auto &it : _monsters)
      it->play(_players);
    checkDeadCharacters();
    _driver->beginScene();
    _smgr->drawAll();
    _device->getGUIEnvironment()->drawAll();
    _driver->endScene();
  }
  return (ACharacter::PLAY_STATUS::MENU);
}
