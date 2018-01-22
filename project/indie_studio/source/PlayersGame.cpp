//
// PlayersGame.cpp for  in /home/tetard/eptechY2/CPP/indie
//
// Made by girard
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Fri Jun 16 15:59:58 2017 girard
// Last update Fri Jun 16 19:53:41 2017 girard
//

# include "GameLevel.hpp"

irr::core::vector3df			GameLevel::getPlayersAveragePosition(void)
{
  irr::core::vector3df			averagePos(0, 0, 0);

  if (_players.size() == 0)
    return (averagePos);
  for (auto &it : _players)
    averagePos += it->getPosition();
  return (averagePos /= _players.size());
}
