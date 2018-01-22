#include <stdlib.h>
#include <sstream>
#include "User.hpp"
#include "Process.hpp"


User::User(int _threads) : _threads(_threads)
{

}

User::~User()
{
}


void	User::Process_it()
{
  std::vector<std::string> files;
  std::string		   file;
  std::string		   tmp;
  std::stringstream	    stream(this->_input);
  std::string		    commands;

  while (getline(stream, commands, ';'))
    {
      std::stringstream    stream_space(commands);
      while (getline(stream_space, file, ' '))
	{
	  if (file[0] != '\0')
	    files.push_back(file);
	  tmp = file;
	}
      if (tmp != IP && tmp != EMAIL && tmp != PHONE)
	{
	  std::cerr << "wrong intput, can you please not troll ?" << std::endl;
	  return ;
	}

    }
  Process first_one(files, this->_threads, true);
}

void	User::Wait_input()
{
  while (1)
    if (getline(std::cin, this->_input))
      this->Process_it();
    else
      return ;
}
