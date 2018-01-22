//
// Warrior.cpp for indie in /home/margue_m/rendu/cpp_indie_studio
//
// Made by Mattéo Margueritte
// Login   <margue_m@epitech.net>
//
// Started on  Sun Jun 18 20:22:35 2017 Mattéo Margueritte
// Last update Sun Jun 18 22:14:58 2017 bellamy corentin
//

#include "Warrior.hpp"

extern Sound sound;

Warrior::Warrior(irr::IrrlichtDevice * const device,
	       const std::shared_ptr<Map> &map,
	       const PlayerSettings &playerSettings,
	       const std::vector<std::shared_ptr<ACharacter> > &players,
	       irr::scene::IMetaTriangleSelector * const mSelector,
	       irr::core::vector3df pos) :
  ACharacter(PATH_WARRIOR, device, map, playerSettings,
	     players, mSelector, true, pos)
{
  _attack = 60;
  _defense = 80;
  _speed = 80.f;
  _node->setScale(_node->getScale() / 3);

  _frameList =
    {
      {"F", {1932, 1953} },
      {"B", {1954, 1975} },
      {"L", {2042, 2063} },
      {"R", {2020, 2041} },
      {"FR", {1844, 1865} },
      {"FL", {1756, 1777} },
      {"BR", {1778, 1799} },
      {"BL", {1866, 1887} },
      {"DEATH", {0, 64} },
      {"ATTACK", {313, 327} }
    };
}

void				Warrior::levelUp(void)
{
  _level += 1;
  _xp = _xp - _xpToUp;
  _xpToUp *= 2;
  _attack += 3;
  _defense += 2;
  if (_xp >= _xpToUp)
    return (levelUp());
}

void			Warrior::shoot(const MyEventReceiver &receiver,
				       const irr::f32 /* frameDeltaTime */,
				       const std::list<std::shared_ptr
				       <ACharacter> > &monsters)
{
  if (_timer.isTimerOver() && receiver.IsKeyDown(_playerSettings.getEnumAttackKey()))
    {
      _timer.setTimer(1000);
      sound.addSound(SWORD);
      static_cast<irr::scene::IAnimatedMeshSceneNode *>(_node)->setFrameLoop(_frameList["ATTACK"].first, _frameList["ATTACK"].second);
      _projs.push_back(std::make_unique<Projectile>(_map->getMapCollision(),
						    _map->getEnvCollision(),
						    _smgr,
						    _node->getPosition(),
						    PATH_WARRIOR_PROJ,
						    monsters,
						    _dir,
						    false,
						    _attack,
						    true));
  }
}

ACharacter::PLAY_STATUS			Warrior::checkEnvironment(std::list<std::shared_ptr
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

ACharacter::PLAY_STATUS		Warrior::play(const MyEventReceiver &receiver,
					   const irr::f32 frameDeltaTime,
					   const std::list<std::shared_ptr
					   <ACharacter> > &monsters,
					   std::list<std::shared_ptr
					   <ACharacter> > const &generators)
{
  move(receiver, frameDeltaTime);
  updateHud();
  shoot(receiver, frameDeltaTime, monsters);
  if (receiver.IsKeyDown(irr::KEY_KEY_Y))
    sound.addSound(YELL);
  if (checkEnvironment(generators, monsters) == ACharacter::PLAY_STATUS::FINISH)
    return (ACharacter::PLAY_STATUS::FINISH);
  updateProjectiles(monsters, generators);
  if (isDead())
    return (ACharacter::PLAY_STATUS::DEAD);
  return (ACharacter::PLAY_STATUS::ALIVE);
}
