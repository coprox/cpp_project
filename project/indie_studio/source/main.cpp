//
// main.cpp for  in /home/tetard/eptechY2/CPP/indie/source
//
// Made by girard
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Fri Jun 16 16:48:21 2017 girard
// Last update Sun Jun 18 18:59:25 2017 girard
//

# include "Game.hpp"
# include "Sound.hpp"

Sound	sound;

int			main(void)
{
  try
    {
      Game			game;

      game.launchGame("");
    }
  catch (std::exception const &error)
    {
      std::cerr << "Error : " << error.what() << std::endl;
    }
  return (EXIT_SUCCESS);
}
