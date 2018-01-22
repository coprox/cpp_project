//
// Camera.cpp for indie in /home/margue_m/rendu/tmp/indie
//
// Made by Mattéo Margueritte
// Login   <margue_m@epitech.net>
//
// Started on  Fri Jun 16 21:02:12 2017 Mattéo Margueritte
// Last update Sun Jun 18 18:30:37 2017 Mattéo Margueritte
//

#include "Camera.hpp"

Camera::Camera(irr::scene::ISceneManager * const smgr,
	       std::vector<std::shared_ptr<ACharacter> > const &players):
  _target(smgr->addMeshSceneNode(smgr->getMesh(INVISIBLE_POINT.c_str()))),
  _targetPosition(0)
{
  if (!_target)
    throw std::runtime_error("Couldn't create the camera target");
  updateTargetPosition(players);
  _target->setPosition(_targetPosition);
  _camera = smgr->addCameraSceneNode(_target,
				     irr::core::vector3df(0, 150, -50),
				     irr::core::vector3df(0, -30, 0));
  if (!_camera)
    throw std::runtime_error("Couldn't create the camera");
}

Camera::~Camera(void)
{
}

void				Camera::updateTargetPosition
(std::vector<std::shared_ptr<ACharacter> > const &players)
{
  _targetPosition.set(0, 0, 0);
  if (players.size() > 0)
    {
      for (auto &it : players)
	_targetPosition += it->getPosition();
      _targetPosition /= players.size();
    }
}

void				Camera::updateCamera
(std::vector<std::shared_ptr<ACharacter> > const &players)
{
  updateTargetPosition(players);
  _target->setPosition(_targetPosition);
  _camera->setTarget(_target->getPosition());
}
