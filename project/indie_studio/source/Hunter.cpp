//
// Hunter.cpp for indie in /home/margue_m/rendu/cpp_indie_studio
//
// Made by Mattéo Margueritte
// Login   <margue_m@epitech.net>
//
// Started on  Sun Jun 18 19:57:12 2017 Mattéo Margueritte
// Last update Sun Jun 18 22:50:09 2017 bellamy corentin
//

#include "Hunter.hpp"

extern Sound sound;

Hunter::Hunter(irr::IrrlichtDevice * const device,
	       const std::shared_ptr<Map> &map,
	       const PlayerSettings &playerSettings,
	       const std::vector<std::shared_ptr<ACharacter> > &players,
	       irr::scene::IMetaTriangleSelector * const mSelector,
	       irr::core::vector3df pos) :
  ACharacter(PATH_HUNTER, device, map, playerSettings,
	     players, mSelector, true, pos)
{
  _attack = 10;
  _defense = 0;
  _speed = 120.f;
  _node->setScale(_node->getScale() / 3);

  _frameList =
    {
      {"F", {551, 570} },
      {"B", {491, 510} },
      {"L", {571, 590} },
      {"R", {591, 610} },
      {"FR", {531, 550} },
      {"FL", {511, 530} },
      {"BR", {471, 490} },
      {"BL", {451, 470} },
      {"DEATH", {26, 160} },
      {"ATTACK", {182, 197} }
    };
}

void				Hunter::levelUp(void)
{
  _level += 1;
  _xp = _xp - _xpToUp;
  _xpToUp *= 2;
  _attack += 3;
  _defense += 2;
  if (_xp >= _xpToUp)
    return (levelUp());
}

void			Hunter::shoot(const MyEventReceiver &receiver,
				      const irr::f32 /* frameDeltaTime */,
				      const std::list<std::shared_ptr
				      <ACharacter> > &monsters)
{
  if (_timer.isTimerOver() && receiver.IsKeyDown(_playerSettings.getEnumAttackKey()))
  {
    _timer.setTimer(200);
    sound.addSound(ARROW);
    static_cast<irr::scene::IAnimatedMeshSceneNode *>(_node)->setFrameLoop(_frameList["ATTACK"].first, _frameList["ATTACK"].second);
    _projs.push_back(std::make_unique<Projectile>(_map->getMapCollision(),
						  _map->getEnvCollision(),
						  _smgr,
						  _node->getPosition(),
						  PATH_HUNTER_PROJ,
						  monsters,
						  _dir,
						  false,
						  _attack));
  }
}

ACharacter::PLAY_STATUS			Hunter::checkEnvironment(std::list<std::shared_ptr
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

ACharacter::PLAY_STATUS		Hunter::play(const MyEventReceiver &receiver,
					   const irr::f32 frameDeltaTime,
					   const std::list<std::shared_ptr
					   <ACharacter> > &monsters,
					   std::list<std::shared_ptr
					   <ACharacter> > const &generators)
{
  move(receiver, frameDeltaTime);
  updateHud();
  shoot(receiver, frameDeltaTime, monsters);
  if (receiver.IsKeyDown(irr::KEY_KEY_L))
    sound.addSound(LAUGH);
  if (checkEnvironment(generators, monsters) == ACharacter::PLAY_STATUS::FINISH)
    return (ACharacter::PLAY_STATUS::FINISH);
  updateProjectiles(monsters, generators);
  if (isDead())
    return (ACharacter::PLAY_STATUS::DEAD);
  return (ACharacter::PLAY_STATUS::ALIVE);
}
