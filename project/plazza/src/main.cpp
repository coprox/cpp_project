#include "User.hpp"

int		main(int ac, char **av)
{
  if (ac != 2 || std::atoi(av[1]) < 1)
    {
      std::cerr << "usage : ./plazza [threads_nb]" << std::endl;
      return (1);
    }
  User	core(std::atoi(av[1]));
  core.Wait_input();
}
