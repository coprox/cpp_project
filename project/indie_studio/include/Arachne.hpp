//
// Arachne.hpp for  in /home/tetard/eptechY2/CPP/cpp_indie_studio/Game/include
//
// Made by girard
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Sat Jun  3 12:59:59 2017 girard
// Last update Sun Jun 18 18:21:59 2017 girard
//

# ifndef ARACHNE_HPP_
# define ARACHNE_HPP_

# include "ACharacter.hpp"

static const std::string	PATH_ARACHNE = "./media/models/arachne.X";

class				Arachne : public ACharacter
{
public:
  Arachne(irr::IrrlichtDevice * const device,
	  const std::shared_ptr<Map> &map,
	  const PlayerSettings &playerSettings,
	  const std::vector<std::shared_ptr<ACharacter> > &players,
	  irr::scene::IMetaTriangleSelector * const mSelector,
	  irr::core::vector3df = {0, 0, 0});
  virtual ~Arachne(void) = default;
  Arachne(const Arachne &cp) = delete;
  Arachne				&operator=(const Arachne &cp) = delete;

  virtual void			levelUp(void);
  virtual ACharacter::PLAY_STATUS	play(const MyEventReceiver & /* receiver */,
					     const irr::f32 /* frameDeltaTime */,
					     const std::list<std::shared_ptr
					     <ACharacter> > &/* monsters */,
					     std::list<std::shared_ptr
					     <ACharacter> > const &/* generators */) { return (ACharacter::PLAY_STATUS::ALIVE);}
  virtual bool			play(const std::vector<std::shared_ptr<ACharacter> > &players);
};

# endif /* MAGE_HPP_ */
