//
// Mage.cpp for  in /home/tetard/eptechY2/CPP/cpp_indie_studio/Game
//
// Made by girard
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Sat Jun  3 15:09:16 2017 girard
// Last update Sun Jun 18 20:29:03 2017 nicolas dejean
//

#include "Mage.hpp"

extern Sound sound;

Mage::Mage(irr::IrrlichtDevice * const device,
	   const std::shared_ptr<Map> &map,
	   const PlayerSettings &playerSettings,
	   const std::vector<std::shared_ptr<ACharacter> > &players,
	   irr::scene::IMetaTriangleSelector * const mSelector,
	   irr::core::vector3df pos) :
  ACharacter(PATH_MAGE, device, map, playerSettings,
	     players, mSelector, true, pos)
{
  _attack = 35;
  _defense = 10;
  _speed = 90.f;
  _node->setScale(_node->getScale() / 3);

  _frameList =
    {
      {"F", {1348, 1391} },
      {"B", {1216, 1259} },
      {"L", {1392, 1435} },
      {"R", {1436, 1479} },
      {"FR", {1304, 1347} },
      {"FL", {1260, 1303} },
      {"BR", {1172, 1215} },
      {"BL", {1128, 1171} },
      {"DEATH", {0, 97} },
      {"ATTACK", {267, 280} }
    };
}

void				Mage::levelUp(void)
{
  _level += 1;
  _xp = _xp - _xpToUp;
  _xpToUp *= 2;
  _attack += 3;
  _defense += 2;
  if (_xp >= _xpToUp)
    return (levelUp());
}

void			Mage::shoot(const MyEventReceiver &receiver,
				    const irr::f32 /* frameDeltaTime */,
				    const std::list<std::shared_ptr<ACharacter> > &monsters)
{
  if (_timer.isTimerOver() && receiver.IsKeyDown(_playerSettings.getEnumAttackKey()))
  {
    _timer.setTimer(600);
    sound.addSound(FIREBALL);
    static_cast<irr::scene::IAnimatedMeshSceneNode *>(_node)->setFrameLoop(_frameList["ATTACK"].first, _frameList["ATTACK"].second);
    _projs.push_back(std::make_unique<Projectile>(_map->getMapCollision(),
						  _map->getEnvCollision(),
						  _smgr,
						  _node->getPosition(),
						  PATH_MAGE_PROJ,
						  monsters,
						  _dir,
						  false,
						  _attack));
  }
}

ACharacter::PLAY_STATUS			Mage::checkEnvironment(std::list<std::shared_ptr
							       <ACharacter> > const &generators,
							       const std::list<std::shared_ptr
							       <ACharacter> > &monsters)
{
  irr::scene::ISceneNode	*node;
  std::string			name;

  if (_envCollAnim->collisionOccurred() == true)
    {
      node = _envCollAnim->getCollisionNode();
      name = node->getName();
      if (!node)
	return (ACharacter::PLAY_STATUS::DEFAULT);
      if (name.find("key") != std::string::npos)
	{
	  ++_nbKeys;
	  sound.addSound(KEY);
	  node->setPosition(irr::core::vector3df(2000));
	}
      else if (name.find("door") != std::string::npos
	       && _nbKeys > 0)
	{
	  --_nbKeys;
	  sound.addSound(DOOR);
	  node->setPosition(irr::core::vector3df(2000));
	}
      else if (name.find("potion") != std::string::npos)
	{
	  sound.addSound(POTION);
	  node->setPosition(irr::core::vector3df(2000));
	  _life = _maxLife;
	}
      else if (name.find("exit") != std::string::npos && generators.size() == 0 &&
	       monsters.size() == 0)
	  return (ACharacter::PLAY_STATUS::FINISH);
    }
  return (ACharacter::PLAY_STATUS::DEFAULT);
}

ACharacter::PLAY_STATUS		Mage::play(const MyEventReceiver &receiver,
					   const irr::f32 frameDeltaTime,
					   const std::list<std::shared_ptr
					   <ACharacter> > &monsters,
					   std::list<std::shared_ptr
					   <ACharacter> > const &generators)
{
  move(receiver, frameDeltaTime);
  updateHud();
  shoot(receiver, frameDeltaTime, monsters);
  if (checkEnvironment(generators, monsters) == ACharacter::PLAY_STATUS::FINISH)
    return (ACharacter::PLAY_STATUS::FINISH);
  updateProjectiles(monsters, generators);
  if (isDead())
    return (ACharacter::PLAY_STATUS::DEAD);
  return (ACharacter::PLAY_STATUS::ALIVE);
}
