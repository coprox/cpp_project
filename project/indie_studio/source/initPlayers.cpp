//
// initPlayers.cpp for  in /home/tetard/eptechY2/CPP/indie
//
// Made by girard
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Sat Jun 17 22:08:39 2017 girard
// Last update Sun Jun 18 19:12:22 2017 girard
//

# include "GameLevel.hpp"

void			GameLevel::initOnePlayer
(const irr::core::vector3df &pos)
{
  _players.push_back(chooseCharacter(_settings.getPlayerOne(), pos));
}

void			GameLevel::initTwoPlayer
(const irr::core::vector3df &pos)
{
  initOnePlayer(pos);
  _players.push_back(chooseCharacter(_settings.getPlayerTwo(),
				     irr::core::vector3df(pos.X, pos.Y, pos.Z)));
}

void			GameLevel::initThreePlayer
(const irr::core::vector3df &pos)
{
  initTwoPlayer(pos);
  _players.push_back(chooseCharacter(_settings.getPlayerThree(),
				     irr::core::vector3df(pos.X, pos.Y, pos.Z)));
}

void			GameLevel::initFourPlayer
(const irr::core::vector3df &pos)
{
  initThreePlayer(pos);
  _players.push_back(chooseCharacter(_settings.getPlayerFour(),
				     irr::core::vector3df(pos.X, pos.Y, pos.Z)));

}
