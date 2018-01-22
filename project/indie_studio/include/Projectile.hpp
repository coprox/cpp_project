//
// Projectile.hpp for indie in /home/margue_m/rendu/tmp/indie
//
// Made by Mattéo Margueritte
// Login   <margue_m@epitech.net>
//
// Started on  Tue Jun 13 11:18:44 2017 Mattéo Margueritte
// Last update Sun Jun 18 21:20:21 2017 Mattéo Margueritte
//

#ifndef PROJECTILE_HPP_
# define PROJECTILE_HPP_

enum				Direction
{
  FORWARD,
  DIR_LEFT,
  DIR_RIGHT,
  BACKWARD,
  FORWARD_LEFT,
  FORWARD_RIGHT,
  BACKWARD_LEFT,
  BACKWARD_RIGHT
};

class				Projectile;

# include <string>
# include <list>
# include <memory>
# include "ACharacter.hpp"
# include "irrlicht.h"

class				Projectile
{
public:

private:
  Direction			_dir;
  bool				_exist;
  irr::scene::ISceneManager	*_smgr;
  irr::scene::ISceneNode	*_node;
  irr::scene::ILightSceneNode	*_light;
  irr::scene::ISceneNodeAnimatorCollisionResponse	*_mapColi;
  irr::scene::ISceneNodeAnimatorCollisionResponse	*_envColi;
  irr::scene::ISceneNodeAnimatorCollisionResponse	*_mobColi;
  irr::scene::ISceneNodeAnimator	*_lineAnim;
  irr::scene::IMetaTriangleSelector	*_mobCollision;
  const unsigned int		_damage;

  irr::core::vector3df		getEndPos(irr::core::vector3df,
					  const bool);
  void				addLight(void);
  irr::scene::IMetaTriangleSelector	*getCollisionMonsters
  (std::list<std::shared_ptr<ACharacter> > const &);
public:
  Projectile(irr::scene::ITriangleSelector *mapColi,
	     irr::scene::IMetaTriangleSelector *envColi,
	     irr::scene::ISceneManager *smgr,
	     irr::core::vector3df start,
	     std::string const &texture,
	     const std::list<std::shared_ptr<ACharacter> > &monsters,
	     const Direction dir = FORWARD,
	     const bool light = true,
	     const unsigned int = 0,
	     const bool warrior = false);
  ~Projectile();

  void				checkCollision
  (std::list<std::shared_ptr<ACharacter> > const &,
   std::list<std::shared_ptr<ACharacter> > const &);
  bool				exist(void) const;
};

#endif //PROJECTILE_HPP_
