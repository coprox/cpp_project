//
// Warrior.hpp for indie in /home/margue_m/rendu/cpp_indie_studio
//
// Made by Mattéo Margueritte
// Login   <margue_m@epitech.net>
//
// Started on  Sun Jun 18 20:21:39 2017 Mattéo Margueritte
// Last update Sun Jun 18 21:26:36 2017 Mattéo Margueritte
//

# ifndef WARRIOR_HPP_
# define WARRIOR_HPP_

# include "ACharacter.hpp"

static const std::string	PATH_WARRIOR = "./media/models/odin.X";
static const std::string	PATH_WARRIOR_PROJ = "./media/models/exit_cube.obj";

class				Warrior : public ACharacter
{
private:

  ACharacter::PLAY_STATUS	checkEnvironment(
    std::list<std::shared_ptr<ACharacter> > const & gens,
    std::list<std::shared_ptr<ACharacter> > const & monsters);
public:
  Warrior(irr::IrrlichtDevice * const device,
       const std::shared_ptr<Map> &map,
       const PlayerSettings &playerSettings,
       const std::vector<std::shared_ptr<ACharacter> > &players,
       irr::scene::IMetaTriangleSelector * const mSelector,
       irr::core::vector3df = {0, 0, 0});
  virtual ~Warrior(void) = default;
  Warrior(const Warrior &cp) = delete;
  Warrior				&operator=(const Warrior &cp) = delete;

  void				shoot(const MyEventReceiver &receiver,
				      const irr::f32 frameDeltaTime,
				      const std::list<std::shared_ptr
				      <ACharacter> > &monsters);

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

# endif /* WARRIOR_HPP_ */
