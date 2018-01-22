//
// AGenerator.hpp for  in /home/tetard/eptechY2/CPP/cpp_indie_studio/Game/include
//
// Made by girard
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Sat Jun  3 10:36:03 2017 girard
// Last update Sun Jun 18 20:14:00 2017 girard
//

# ifndef AGENERATOR_HPP_
# define AGENERATOR_HPP_

# include <vector>
# include <string>
# include <memory>
# include <vector>
# include <list>
# include "Timer.hpp"
# include "ACharacter.hpp"
# include "MyEventReceiver.hpp"
# include "irrlicht.h"

static const size_t			NB_MONSTERS_MAX = 15;

class					AGenerator : public ACharacter
{
protected:
  std::list<std::shared_ptr<ACharacter> > _monsters;

public:
  AGenerator(irr::scene::ISceneNode * const node,
	     irr::IrrlichtDevice * const device,
	     const std::shared_ptr<Map> &map,
	     const PlayerSettings &playerSettings = PS_DEFAULT,
	     const std::vector<std::shared_ptr<ACharacter> > &players =
	     std::vector<std::shared_ptr<ACharacter> >(),
	     irr::core::vector3df pos = {0, 0, 0});
  virtual ~AGenerator(void) = default;
  AGenerator(const AGenerator &cp) = delete;
  AGenerator			&operator=(const AGenerator &cp) = delete;

  virtual void			move(const MyEventReceiver & /* receiver */,
				     const irr::f32 /* frameDeltaTime */) {}
  virtual void			move(const std::vector<std::shared_ptr<ACharacter> > & /* players */) {}

  virtual void			levelUp(void) {}

  virtual bool			takeDammage(size_t attack);

  virtual const std::list<std::shared_ptr<ACharacter> >	&generate(
    irr::IrrlichtDevice * const device,
    const std::vector<std::shared_ptr<ACharacter> > &players,
    irr::scene::IMetaTriangleSelector * const mSelector) = 0;

  virtual ACharacter::PLAY_STATUS	play(const MyEventReceiver & receiver,
					     const irr::f32 frameDeltaTime,
					     const std::list<std::shared_ptr
					     <ACharacter> > &monsters,
					     std::list<std::shared_ptr
					     <ACharacter> > const &generators) = 0;

  virtual bool			play(const std::vector<std::shared_ptr<ACharacter> > &players) = 0;
};

# endif /* AGENERATOR_HPP_ */
