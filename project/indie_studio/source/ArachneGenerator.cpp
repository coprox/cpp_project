//
// ArachneGenerator.cpp for  in /home/tetard/eptechY2/CPP/indie/source
//
// Made by girard
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Fri Jun 16 19:41:28 2017 girard
// Last update Sun Jun 18 19:15:37 2017 girard
//

# include <iostream>
# include "Arachne.hpp"
# include "ArachneGenerator.hpp"

ArachneGenerator::ArachneGenerator(irr::scene::ISceneNode * const node,
				   irr::IrrlichtDevice * const device,
				   const std::shared_ptr<Map> &map,
				   const PlayerSettings &playerSettings,
				   const std::vector<std::shared_ptr
				   <ACharacter> > &players,
				   irr::core::vector3df pos) :
  AGenerator(node, device, map, playerSettings, players, pos) {}

const std::list<std::shared_ptr<ACharacter> >		&ArachneGenerator::generate
(irr::IrrlichtDevice * const device,
 const std::vector<std::shared_ptr<ACharacter> > &players,
 irr::scene::IMetaTriangleSelector * const mSelector)
{

  irr::core::vector3df					pos = _node->getPosition();

  _monsters.clear();
  if (!_timer.isTimerOver())
    return (_monsters);
  _timer.setTimer(5000);

  _monsters.push_back(std::make_shared<Arachne>(device, _map, PS_DEFAULT,
						players, mSelector,
						irr::core::vector3df(pos.X + 20, pos.Y, pos.Z)));
   return (_monsters);
}
