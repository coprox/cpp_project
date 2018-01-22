//
// Arachne.cpp for  in /home/tetard/eptechY2/CPP/cpp_indie_studio/Game
//
// Made by girard
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Sat Jun  3 15:09:16 2017 girard
// Last update Sun Jun 18 18:47:03 2017 girard
//

#include "Arachne.hpp"

Arachne::Arachne(irr::IrrlichtDevice * const device,
		 const std::shared_ptr<Map> &map,
		 const PlayerSettings &playerSettings,
		 const std::vector<std::shared_ptr<ACharacter> > &players,
		 irr::scene::IMetaTriangleSelector * const mSelector,
		 irr::core::vector3df pos) :
  ACharacter(PATH_ARACHNE, device, map, playerSettings,
	     players, mSelector, false, pos)
{
  _attack = 10;
  _defense = 0;
  _node->setScale(_node->getScale() / 4);

  _frameList =
    {
      {"F", {816, 845} },
      {"B", {726, 755} },
      {"L", {846, 875} },
      {"R", {876, 905} },
      {"FR", {786, 815} },
      {"FL", {756, 785} },
      {"BR", {696, 725} },
      {"BL", {666, 695} },
      {"DEATH", {0, 175} },
      {"ATTACK", {239, 252} }
    };

  static_cast<irr::scene::IAnimatedMeshSceneNode *>(_node)->setLoopMode(true);
}

void				Arachne::levelUp(void) {}

bool				Arachne::play(const std::vector<std::shared_ptr<ACharacter> > &players)
{
  move(players);

  return (true);
}
