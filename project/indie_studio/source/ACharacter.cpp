//
// ACharacter.cpp for  in /home/tetard/eptechY2/CPP/cpp_indie_studio/Game
//
// Made by girard
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Sat Jun  3 11:17:50 2017 girard
// Last update Sun Jun 18 19:18:12 2017 girard
//

#include "ACharacter.hpp"

ACharacter::ACharacter(const std::string &path,
		       irr::IrrlichtDevice * const device,
		       const std::shared_ptr<Map> &map,
		       const PlayerSettings &playerSettings,
		       const std::vector<std::shared_ptr<ACharacter> > &/* players */,
		       irr::scene::IMetaTriangleSelector * const mSelector,
		       const bool player,
		       irr::core::vector3df pos) :
  _smgr(device->getSceneManager()),
  _node(_smgr->addAnimatedMeshSceneNode(_smgr->getMesh(path.c_str()))),
  _map(map),
  _life(100),
  _maxLife(100),
  _level(1),
  _xp(0),
  _xpToUp(10),
  _isBarsActivated(false),
  _attack(10),
  _speed(100.f),
  _defense(5),
  _nbKeys(0),
  _timer(device),
  _playerSettings(playerSettings)
{
  initCharacter(pos);
  handleInitCollisions(mSelector, player);
}

ACharacter::ACharacter(irr::scene::ISceneNode * const node,
		       irr::IrrlichtDevice * const device,
		       const std::shared_ptr<Map> &map,
		       const PlayerSettings &playerSettings,
		       const std::vector<std::shared_ptr<ACharacter> > &/* players */,
		       irr::core::vector3df pos) :
  _smgr(device->getSceneManager()),
  _node(node),
  _map(map),
  _life(100),
  _maxLife(100),
  _level(1),
  _xp(0),
  _xpToUp(10),
  _isBarsActivated(false),
  _attack(10),
  _speed(100.f),
  _defense(5),
  _nbKeys(0),
  _timer(device),
  _playerSettings(playerSettings)
{
  initCharacter(pos);
}

void					ACharacter::handleInitCollisions
(irr::scene::IMetaTriangleSelector * const mSelector,
 const bool player)
{
  irr::scene::ITriangleSelector*	selector =
    _smgr->createTriangleSelectorFromBoundingBox(_node);
  _node->setTriangleSelector(selector);
  {
    _envCollAnim = _smgr->createCollisionResponseAnimator(_map->getEnvCollision(),
							  _node);
    if (!_envCollAnim)
      throw std::runtime_error("EnvCollisionAnimator fail loading.");
    _envCollAnim->setGravity(irr::core::vector3df(0));
    _envCollAnim->setEllipsoidRadius(irr::core::vector3df(4));
    _node->addAnimator(_envCollAnim);

    if (player == false)
      {
	mSelector->addTriangleSelector(selector);
	irr::scene::ISceneNodeAnimatorCollisionResponse *monstersCollAnim =
	  _smgr->createCollisionResponseAnimator(mSelector, _node);
	monstersCollAnim->setEllipsoidRadius(irr::core::vector3df(12));
	monstersCollAnim->setGravity(irr::core::vector3df(0));
	_node->addAnimator(monstersCollAnim);
	monstersCollAnim->drop();
      }

    irr::scene::ISceneNodeAnimatorCollisionResponse *mapCollisionAnimator =
      _smgr->createCollisionResponseAnimator(_map->getMapCollision(),
					    _node);
    mapCollisionAnimator->setEllipsoidRadius(irr::core::vector3df(4));
    _node->addAnimator(mapCollisionAnimator);
    mapCollisionAnimator->drop();
  }
  selector->drop();
}

void					ACharacter::initCharacter(const irr::core::vector3df &pos)
{

  _envCollAnim = NULL;
  _dir = Direction::FORWARD;

  _smgr->addLightSceneNode(_node);
  _node->setPosition(pos);
}

void					ACharacter::changePosition(const MyEventReceiver &receiver,
								   const irr::f32 frameDeltaTime)
{
  irr::core::vector3df			nodePosition = _node->getPosition();

  if (receiver.IsKeyDown(_playerSettings.getEnumUpKey()))
    nodePosition.Z += _speed * frameDeltaTime;
  else if (receiver.IsKeyDown(_playerSettings.getEnumDownKey()))
    nodePosition.Z -= _speed * frameDeltaTime;
  if (receiver.IsKeyDown(_playerSettings.getEnumLeftKey()))
    nodePosition.X -= _speed * frameDeltaTime;
  else if (receiver.IsKeyDown(_playerSettings.getEnumRightKey()))
    nodePosition.X += _speed * frameDeltaTime;
  _node->setPosition(nodePosition);
}

void					ACharacter::setMovement(const std::string &key,
								const irr::core::vector3df &rotate)
{
    if (_node->getRotation() != rotate)
    {
      static_cast<irr::scene::IAnimatedMeshSceneNode *>(_node)->setFrameLoop(_frameList[key].first, _frameList[key].second);
      _node->setRotation(rotate);
    }
}

bool					ACharacter::isHorizontalDown(const MyEventReceiver &receiver) const
{
  return (receiver.IsKeyDown(_playerSettings.getEnumLeftKey()) ||
	  receiver.IsKeyDown(_playerSettings.getEnumRightKey()));
}

bool					ACharacter::isVerticalDown(const MyEventReceiver &receiver) const
{
  return (receiver.IsKeyDown(_playerSettings.getEnumUpKey()) ||
	  receiver.IsKeyDown(_playerSettings.getEnumDownKey()));
}

void					ACharacter::move(const MyEventReceiver &receiver,
							 const irr::f32 frameDeltaTime)
{
  changePosition(receiver, frameDeltaTime);

  if (receiver.IsKeyDown(_playerSettings.getEnumUpKey()) && !isHorizontalDown(receiver)) {
    setMovement(FRONT, ROTFRONT);
    _dir = Direction::FORWARD;
  }
  else if (receiver.IsKeyDown(_playerSettings.getEnumDownKey()) && !isHorizontalDown(receiver)) {
    setMovement(BACK, ROTBACK);
    _dir = Direction::BACKWARD;
  }
  else if (receiver.IsKeyDown(_playerSettings.getEnumLeftKey()) && !isVerticalDown(receiver)) {
    setMovement(LEFT, ROTLEFT);
    _dir = Direction::DIR_LEFT;
  }
  else if (receiver.IsKeyDown(_playerSettings.getEnumRightKey()) && !isVerticalDown(receiver)) {
    setMovement(RIGHT, ROTRIGHT);
    _dir = Direction::DIR_RIGHT;
  }
  else if (receiver.IsKeyDown(_playerSettings.getEnumDownKey()) &&
	   receiver.IsKeyDown(_playerSettings.getEnumLeftKey())) {
    setMovement(BACKLEFT, ROTBACKLEFT);
    _dir = Direction::BACKWARD_LEFT;
  }
  else if (receiver.IsKeyDown(_playerSettings.getEnumDownKey()) &&
	   receiver.IsKeyDown(_playerSettings.getEnumRightKey())) {
    setMovement(BACKRIGHT, ROTBACKRIGHT);
    _dir = Direction::BACKWARD_RIGHT;
  }
  else if (receiver.IsKeyDown(_playerSettings.getEnumUpKey()) &&
	   receiver.IsKeyDown(_playerSettings.getEnumLeftKey())) {
    setMovement(FRONTLEFT, ROTFRONTLEFT);
    _dir = Direction::FORWARD_LEFT;
  }
  else if (receiver.IsKeyDown(_playerSettings.getEnumUpKey()) &&
	   receiver.IsKeyDown(_playerSettings.getEnumRightKey())) {
    setMovement(FRONTRIGHT, ROTFRONTRIGHT);
    _dir = Direction::FORWARD_RIGHT;
  }
}

size_t					ACharacter::getDistance(const irr::core::vector3df &pos1,
								 const irr::core::vector3df &pos2) const
{
  return ((pos1.X > pos2.X ? pos1.X - pos2.X : pos2.X - pos1.X) +
	  (pos1.Z > pos2.Z ? pos1.Z - pos2.Z : pos2.Z - pos1.Z));
}

void					ACharacter::move(const std::vector<std::shared_ptr<ACharacter> > &players)
{
  if (players.size() == 0)
    return ;

  irr::scene::IAnimatedMeshSceneNode *tmpNode =
    static_cast<irr::scene::IAnimatedMeshSceneNode *>(_node);
  if (_frameList["F"].first != tmpNode->getStartFrame())
    tmpNode->setFrameLoop(_frameList["F"].first, _frameList["F"].second);

  irr::core::vector3df			direction = players[0]->getNode()->getPosition();
  irr::core::vector3df			origin = _node->getPosition();
  size_t				cur_distance = getDistance(origin, direction);
  int					player = 0;
  int					i = 0;

  for (auto &it : players)
    {
      if (getDistance(origin, it->getNode()->getPosition()) < cur_distance)
	{
	  direction = it->getNode()->getPosition();
	  cur_distance = getDistance(origin, direction);
	  player = i;
	}
      ++i;
    }
  irr::core::vector3df			position(4);
  irr::core::line3d<irr::f32>		line(_node->getPosition(), direction);
  irr::f32				ratio = (_speed * 0.01) / line.getLength();

  position.X = ((1 - ratio) * _node->getPosition().X + ratio * direction.X);
  position.Z = ((1 - ratio) * _node->getPosition().Z + ratio * direction.Z);
  if (line.getLength() < ATTACK_RANGE)
    {
      if (_timer.isTimerOver())
	{
	  _timer.setTimer(500);
	  static_cast<irr::scene::IAnimatedMeshSceneNode *>(_node)->
	    setFrameLoop(_frameList["ATTACK"].first, _frameList["ATTACK"].second);
	  players[player]->takeDammage(_attack);
	}
    }
  else
    _node->setPosition(position);
}

bool					ACharacter::takeDammage(size_t attack)
{
  int dammages = static_cast<int>(static_cast<float>(attack) * ((100.0 - _defense) / 100.0));

  _life = _life - dammages <= 0 ? 0 : _life - dammages;

  if (isDead()) {
    static_cast<irr::scene::IAnimatedMeshSceneNode *>(_node)->
      setFrameLoop(_frameList["DEATH"].first,
		   _frameList["DEATH"].second);
    static_cast<irr::scene::IAnimatedMeshSceneNode *>(_node)->setLoopMode(false);
  }
  return (_life <= 0 ? false : true);
}

void					ACharacter::setFullLife(void)
{
  _life = _maxLife;
}

bool					ACharacter::isDead(void) const
{
  return (_life <= 0 ? true : false);
}

void					ACharacter::setPosition(irr::core::vector3df pos)
{
  _node->setPosition(pos);
}

void					ACharacter::updateProjectiles
(std::list<std::shared_ptr<ACharacter> > const &monsters,
 std::list<std::shared_ptr<ACharacter> > const &generators)
{
  auto it = _projs.begin();

  while (it != _projs.end())
    {
      (*it)->checkCollision(monsters, generators);
      if ((*it)->exist() == false)
        it = _projs.erase(it);
      else
        ++it;
    }
}

void					ACharacter::updateHud(void)
{
  if (!_isBarsActivated) {
    _isBarsActivated = true;
    _lifeBar = std::make_unique<LifeBar>(
      _timer.getDevice(), _node, _playerSettings.getPlayer());
    _xpBar = std::make_unique<XpBar>(
      _timer.getDevice(), _node);
  }
  _xpBar->updateXp(static_cast<int>((static_cast<float>(_xp) * 100 / _xpToUp)));
  _lifeBar->updateLife(static_cast<int>((static_cast<float>(_life) * 100 / _maxLife)));
}
