//
// Camera.hpp for indie in /home/margue_m/rendu/tmp/indie
//
// Made by Mattéo Margueritte
// Login   <margue_m@epitech.net>
//
// Started on  Fri Jun 16 21:02:10 2017 Mattéo Margueritte
// Last update Sun Jun 18 18:27:34 2017 Mattéo Margueritte
//

#ifndef CAMERA_HPP_
# define CAMERA_HPP_

# include <exception>
# include "irrlicht.h"
# include "ACharacter.hpp"
# include "GameLevel.hpp"

class			Camera
{
  irr::scene::ICameraSceneNode	*_camera;
  irr::scene::ISceneNode	*_target;
  irr::core::vector3df		_targetPosition;

  void				updateTargetPosition(std::vector<std::shared_ptr
						     <ACharacter> > const &);
public:
  Camera(irr::scene::ISceneManager * const,
	 std::vector<std::shared_ptr<ACharacter> > const &);
  ~Camera(void);

  void				updateCamera(std::vector<std::shared_ptr<ACharacter> >
				     const &);

  irr::scene::ICameraSceneNode	*getCamera(void) const { return (_camera); };
};

#endif //CAMERA_HPP_
