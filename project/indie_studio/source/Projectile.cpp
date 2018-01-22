//
// Projectile.cpp for indie in /home/margue_m/rendu/tmp/indie
//
// Made by Mattéo Margueritte
// Login   <margue_m@epitech.net>
//
// Started on  Tue Jun 13 11:18:47 2017 Mattéo Margueritte
// Last update Sun Jun 18 21:33:41 2017 Mattéo Margueritte
//

#include <iostream>
#include <exception>
#include "Projectile.hpp"

Projectile::Projectile(irr::scene::ITriangleSelector *mapColi,
		       irr::scene::IMetaTriangleSelector *envColi,
		       irr::scene::ISceneManager *smgr,
		       irr::core::vector3df start,
		       std::string const &model,
		       const std::list<std::shared_ptr<ACharacter> > &monsters,
		       const Direction dir,
		       const bool light,
		       const unsigned int damage,
		       const bool warrior):
  _dir(dir), _exist(true), _smgr(smgr),
  _mobCollision(_smgr->createMetaTriangleSelector()),
  _damage(damage)
{
  irr::core::vector3df		radius(4);
  irr::u32			speed = 3000;

  _node = _smgr->addMeshSceneNode(_smgr->getMesh(model.c_str()));
  if (!_node)
    throw std::runtime_error("Couldn't load projectile model");
  _node->setScale(_node->getScale() / 2.f);
  _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  if (warrior == true)
    {
      //_node->setMaterialType(irr::video::EMT_TRANSPARENT_ALPHA_CHANNEL);
      radius.X = 10;
      radius.Y = 10;
      radius.Z = 10;
      speed = 1;
    }
  _mobColi = _smgr->createCollisionResponseAnimator(getCollisionMonsters(monsters),
						    _node);
  _mobColi->setGravity(irr::core::vector3df(0));
  _mobColi->setEllipsoidRadius(radius);
  _envColi = _smgr->createCollisionResponseAnimator(envColi, _node);
  _envColi->setGravity(irr::core::vector3df(0));
  _envColi->setEllipsoidRadius(radius);
  _mapColi = _smgr->createCollisionResponseAnimator(mapColi, _node);
  _mapColi->setGravity(irr::core::vector3df(0));
  _mapColi->setEllipsoidRadius(radius);
  _lineAnim = _smgr->createFlyStraightAnimator(start,
					       getEndPos(start, warrior),
					       speed);
  _light = NULL;
  if (light == true)
    addLight();
  _node->addAnimator(_lineAnim);
  _node->addAnimator(_mobColi);
  _node->addAnimator(_envColi);
  _node->addAnimator(_mapColi);
}

Projectile::~Projectile(void)
{
  if (_mobCollision)
    _mobCollision->drop();
  _mapColi->drop();
  _envColi->drop();
  _lineAnim->drop();
  if (_light)
    _light->remove();
  if (_node && _exist == false)
    _node->remove();
}

void			Projectile::addLight(void)
{
  _light = _smgr->addLightSceneNode(_node);
}

irr::scene::IMetaTriangleSelector	*Projectile::getCollisionMonsters
(std::list<std::shared_ptr<ACharacter> > const &monsters)
{
  for (auto &it : monsters)
    _mobCollision->addTriangleSelector
      (_smgr->createTriangleSelectorFromBoundingBox(it->getNode()));
  return (_mobCollision);
}

irr::core::vector3df	Projectile::getEndPos(irr::core::vector3df start,
					      const bool warrior)
{
  irr::f32		dist = 1000;

  if (warrior == true)
    dist = 30;
  switch (_dir)
    {
    case FORWARD:
      start.Z += dist;
      break;
    case DIR_LEFT:
      start.X -= dist;
      _node->setRotation(ROTLEFT);
      break;
    case DIR_RIGHT:
      start.X += dist;
      _node->setRotation(ROTRIGHT);
      break;
    case BACKWARD:
      start.Z -= dist;
      _node->setRotation(ROTBACK);
      break;
    case FORWARD_LEFT:
      start.Z += dist;
      start.X -= dist;
      _node->setRotation(ROTFRONTLEFT);
      break;
    case FORWARD_RIGHT:
      start.Z += dist;
      start.X += dist;
      _node->setRotation(ROTFRONTRIGHT);
      break;
    case BACKWARD_LEFT:
      start.Z -= dist;
      start.X -= dist;
      _node->setRotation(ROTBACKLEFT);
      break;
    case BACKWARD_RIGHT:
      start.Z -= dist;
      start.X += dist;
      _node->setRotation(ROTBACKRIGHT);
      break;
    }
  return (start);
}

bool			Projectile::exist(void) const
{
  return (_exist);
}

void			Projectile::checkCollision
(std::list<std::shared_ptr<ACharacter> > const &monsters,
 std::list<std::shared_ptr<ACharacter> > const &generators)
{
  irr::scene::ISceneNode	*node;

  if (_mobColi->collisionOccurred() == true)
    {
      node = _mobColi->getCollisionNode();
      for (auto it : monsters)
	if (it->getNode() == node)
	  it->takeDammage(_damage);
      _exist = false;
    }
  if (_envColi->collisionOccurred() == true)
    {
      node = _envColi->getCollisionNode();
      for (auto it : generators)
	if (it->getNode() == node)
	  it->takeDammage(_damage);
      _exist = false;
    }
  if (_mapColi->collisionOccurred() == true
      || _lineAnim->hasFinished() == true)
    _exist = false;
}
