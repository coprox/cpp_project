//
// AGenerator.cpp for  in /home/tetard/eptechY2/CPP/indie
//
// Made by girard
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Fri Jun 16 19:31:12 2017 girard
// Last update Sun Jun 18 16:32:26 2017 girard
//

# include "AGenerator.hpp"

AGenerator::AGenerator(irr::scene::ISceneNode * const node,
		       irr::IrrlichtDevice * const device,
		       const std::shared_ptr<Map> &map,
		       const PlayerSettings &playerSettings,
		       const std::vector<std::shared_ptr<ACharacter> > &players,
		       irr::core::vector3df pos) :
  ACharacter(node, device, map, playerSettings, players, pos)
{
  _timer.setTimer(5000);
  _attack = 0;
  _defense = 0;
  _maxLife = 150;
  _life = 150;
}

bool			AGenerator::takeDammage(size_t attack)
{
  int dammages = static_cast<int>(static_cast<float>(attack) * ((100.0 - _defense) / 100.0));
  _life = _life - dammages <= 0 ? 0 : _life - dammages;

  return (_life <= 0 ? false : true);
}
