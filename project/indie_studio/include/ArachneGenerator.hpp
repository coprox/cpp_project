//
// ArachneGenerator.hpp for  in /home/tetard/eptechY2/CPP/cpp_indie_studio/Game/include
//
// Made by girard
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Sat Jun  3 10:36:03 2017 girard
// Last update Sun Jun 18 18:09:28 2017 Mattéo Margueritte
//

# ifndef ARACHNEGENERATOR_HPP_
# define ARACHNEGENERATOR_HPP_

#include "AGenerator.hpp"

class					ArachneGenerator : public AGenerator
{
public:
  ArachneGenerator(irr::scene::ISceneNode * const node,
		   irr::IrrlichtDevice * const device,
		   const std::shared_ptr<Map> &map,
		   const PlayerSettings &playerSettings = PS_DEFAULT,
		   const std::vector<std::shared_ptr<ACharacter> > &players =
		   std::vector<std::shared_ptr<ACharacter> >(),
		   irr::core::vector3df pos = {0, 0, 0});
  virtual ~ArachneGenerator(void) = default;
  ArachneGenerator(const ArachneGenerator &cp) = delete;
  ArachneGenerator			&operator=(const ArachneGenerator &cp) = delete;

  virtual const std::list<std::shared_ptr<ACharacter> >	&generate(
    irr::IrrlichtDevice * const device,
    const std::vector<std::shared_ptr<ACharacter> > &players,
    irr::scene::IMetaTriangleSelector * const mSelector);

  virtual ACharacter::PLAY_STATUS	play(const MyEventReceiver & /* receiver */,
					     const irr::f32 /* frameDeltaTime */,
					     const std::list<std::shared_ptr
					     <ACharacter> > &/* monsters */,
					     std::list<std::shared_ptr
					     <ACharacter> > const &/* generators */) { return (ACharacter::PLAY_STATUS::ALIVE); }
  virtual bool			play(const std::vector<std::shared_ptr
				     <ACharacter> > &/* players */) { return (true); }
};

# endif /* ARACHNEGENERATOR_HPP_ */
