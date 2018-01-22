//
// Hunter.hpp for indie in /home/margue_m/rendu/cpp_indie_studio
//
// Made by Mattéo Margueritte
// Login   <margue_m@epitech.net>
//
// Started on  Sun Jun 18 19:56:10 2017 Mattéo Margueritte
// Last update Sun Jun 18 20:02:57 2017 Mattéo Margueritte
//

# ifndef HUNTER_HPP_
# define HUNTER_HPP_

# include "ACharacter.hpp"

static const std::string	PATH_HUNTER = "./media/models/artemis.X";
static const std::string	PATH_HUNTER_PROJ = "./media/models/arrow.obj";

class				Hunter : public ACharacter
{
private:

  ACharacter::PLAY_STATUS	checkEnvironment(
    std::list<std::shared_ptr<ACharacter> > const & gens,
    std::list<std::shared_ptr<ACharacter> > const & monsters);
public:
  Hunter(irr::IrrlichtDevice * const device,
       const std::shared_ptr<Map> &map,
       const PlayerSettings &playerSettings,
       const std::vector<std::shared_ptr<ACharacter> > &players,
       irr::scene::IMetaTriangleSelector * const mSelector,
       irr::core::vector3df = {0, 0, 0});
  virtual ~Hunter(void) = default;
  Hunter(const Hunter &cp) = delete;
  Hunter				&operator=(const Hunter &cp) = delete;

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

# endif /* HUNTER_HPP_ */
