//
// Mage.hpp for  in /home/tetard/eptechY2/CPP/cpp_indie_studio/Game/include
//
// Made by girard
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Sat Jun  3 12:59:59 2017 girard
// Last update Sun Jun 18 17:41:36 2017 girard
//

# ifndef MAGE_HPP_
# define MAGE_HPP_

# include "ACharacter.hpp"

static const std::string	PATH_MAGE = "./media/models/poseidon.X";
static const std::string	PATH_MAGE_PROJ = "./media/models/Fireball.obj";

class				Mage : public ACharacter
{
private:

  ACharacter::PLAY_STATUS	checkEnvironment(
    std::list<std::shared_ptr<ACharacter> > const & gens,
    std::list<std::shared_ptr<ACharacter> > const & monsters);
public:
  Mage(irr::IrrlichtDevice * const device,
       const std::shared_ptr<Map> &map,
       const PlayerSettings &playerSettings,
       const std::vector<std::shared_ptr<ACharacter> > &players,
       irr::scene::IMetaTriangleSelector * const mSelector,
       irr::core::vector3df = {0, 0, 0});
  virtual ~Mage(void) = default;
  Mage(const Mage &cp) = delete;
  Mage				&operator=(const Mage &cp) = delete;

  void				shoot(const MyEventReceiver &receiver,
				     const irr::f32 frameDeltaTime,
				      const std::list<std::shared_ptr<ACharacter> > &monsters);

  virtual void			levelUp(void);
  virtual ACharacter::PLAY_STATUS	play(const MyEventReceiver &receiver,
					     const irr::f32 frameDeltaTime,
					     const std::list<std::shared_ptr
					     <ACharacter> > &monsters,
					     std::list<std::shared_ptr
					     <ACharacter> > const & generators);
  virtual bool			play(const std::vector<std::shared_ptr<ACharacter> >
				     & /* players */) { return (true); }
};

# endif /* MAGE_HPP_ */
