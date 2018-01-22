//
// ACharacter.hpp for  in /home/tetard/eptechY2/CPP/cpp_indie_studio/Game/include
//
// Made by girard
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Sat Jun  3 10:36:03 2017 girard
// Last update Sun Jun 18 20:26:35 2017 nicolas dejean
//

# ifndef ACHARACTER_HPP_
# define ACHARACTER_HPP_

class			ACharacter;

#include <vector>
# include <string>
# include <unordered_map>
# include <memory>
# include <list>
# include "Map.hpp"
# include "PlayerSettings.hpp"
# include "Projectile.hpp"
# include "Timer.hpp"
# include "MyEventReceiver.hpp"
# include "irrlicht.h"
# include "XpBar.hpp"
# include "LifeBar.hpp"
# include "Sound.hpp"

static const PlayerSettings		PS_DEFAULT;

static const irr::core::vector3df	ROTFRONT = irr::core::vector3df(0, 180, 0);
static const irr::core::vector3df	ROTBACK = irr::core::vector3df(0, 0, 0);
static const irr::core::vector3df	ROTLEFT = irr::core::vector3df(0, 90, 0);
static const irr::core::vector3df	ROTRIGHT = irr::core::vector3df(0, 260, 0);
static const irr::core::vector3df	ROTFRONTLEFT = irr::core::vector3df(0, 135, 0);
static const irr::core::vector3df	ROTFRONTRIGHT = irr::core::vector3df(0, 225, 0);
static const irr::core::vector3df	ROTBACKLEFT = irr::core::vector3df(0, 45, 0);
static const irr::core::vector3df	ROTBACKRIGHT = irr::core::vector3df(0, 305, 0);

static const std::string		FRONT = "F";
static const std::string		BACK = "B";
static const std::string		LEFT = "L";
static const std::string		RIGHT = "R";
static const std::string		FRONTLEFT = "FL";
static const std::string		BACKLEFT = "BL";
static const std::string		FRONTRIGHT = "FR";
static const std::string		BACKRIGHT = "BR";

static const unsigned int		ATTACK_RANGE = 10;

class					ACharacter
{
public:
  enum					PLAY_STATUS
  {
    ALIVE,
    DEAD,
    FINISH,
    MENU,
    DEFAULT
  };

protected:
  irr::scene::ISceneManager		*_smgr;
  irr::scene::ISceneNode		*_node;

  std::shared_ptr<Map>			_map;

  irr::scene::ISceneNodeAnimatorCollisionResponse *_envCollAnim;

  int					_life;
  int					_maxLife;
  size_t				_level;
  size_t				_xp;
  size_t				_xpToUp;

  std::unique_ptr<XpBar>		_xpBar;
  std::unique_ptr<LifeBar>		_lifeBar;

  bool					_isBarsActivated;

  size_t				_attack;

  irr::f32				_speed;
  size_t				_defense;

  std::vector<std::unique_ptr<Projectile> > _projs;

  Direction				_dir;

  size_t				_nbKeys;

  Timer					_timer;

  std::unordered_map<std::string, std::pair<irr::s32, irr::s32> > _frameList;

  PlayerSettings			_playerSettings;

public:
  ACharacter(const std::string &path,
	     irr::IrrlichtDevice * const device,
	     const std::shared_ptr<Map> &map,
	     const PlayerSettings &playerSettings,
	     const std::vector<std::shared_ptr<ACharacter> > &players,
	     irr::scene::IMetaTriangleSelector * const mSelector,
	     const bool player,
	     irr::core::vector3df = {0, 0, 0});
  ACharacter(irr::scene::ISceneNode	* const node,
	     irr::IrrlichtDevice * const device,
	     const std::shared_ptr<Map> &map,
	     const PlayerSettings &playerSettings,
	     const std::vector<std::shared_ptr<ACharacter> > &players,
	     irr::core::vector3df = {0, 0, 0});
  virtual ~ACharacter(void) = default;
  ACharacter(const ACharacter &cp) = delete;
  ACharacter			&operator=(const ACharacter &cp) = delete;

  irr::scene::ISceneNode	*getNode(void) { return (_node); }

  int				getLife(void) const { return (_life); }
  int				getMaxLife(void) const { return (_maxLife); }
  size_t			getLevel(void) const { return (_level); }
  size_t			getXp(void) const { return (_xp); }
  size_t			getXpToUp(void) const { return (_xpToUp); }
  size_t			getAttack(void) const { return (_attack); }
  irr::f32			getSpeed(void) const { return (_speed); }
  size_t			getDefense(void) const { return (_defense); }

  const irr::core::vector3df	&getPosition(void) const { return (_node->getPosition()); }

  size_t			getNbKeys(void) const { return (_nbKeys); }

  void				setPosition(irr::core::vector3df position);

  size_t			getDistance(const irr::core::vector3df &pos1,
					    const irr::core::vector3df &pos2) const ;

  virtual bool			takeDammage(size_t attack);
  void				setFullLife(void);
  bool				isDead(void) const;

  virtual void			move(const MyEventReceiver &receiver,
				     const irr::f32 frameDeltaTime);
  virtual void			move(const std::vector<std::shared_ptr<ACharacter> > &players);

  virtual void			levelUp(void) = 0;

  virtual PLAY_STATUS		play(const MyEventReceiver &receiver,
				     const irr::f32 frameDeltaTime,
				     const std::list<std::shared_ptr
				     <ACharacter> > &monsters,
				     std::list<std::shared_ptr
				     <ACharacter> > const &generators) = 0;
  virtual bool			play(const std::vector<std::shared_ptr<ACharacter> > &players) = 0;

protected:
  void				updateHud(void);

  void				handleInitCollisions
  (irr::scene::IMetaTriangleSelector * const mSelector,
   const bool player);
  void				initCharacter(const irr::core::vector3df &pos);

  void				changePosition(const MyEventReceiver &receiver,
					       const irr::f32 frameDeltaTime);
  void				setMovement(const std::string &key,
					    const irr::core::vector3df &rotate);

  bool				isHorizontalDown(const MyEventReceiver &receiver) const;
  bool				isVerticalDown(const MyEventReceiver &receiver) const;

  void				updateProjectiles
  (std::list<std::shared_ptr<ACharacter> > const &,
   std::list<std::shared_ptr<ACharacter> > const &);
};

# endif /* ACHARACTER_HPP_ */
