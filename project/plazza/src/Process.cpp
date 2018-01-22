//
// Process.cpp for y in /home/dekamor/rendu_sec/project/cpp_plazza/src
//
// Made by Dkamor
// Login   <corentin.bellamy@epitech.eu>
//
// Started on  Thu Apr 27 17:47:59 2017 Dkamor
// Last update Sun Apr 30 22:52:57 2017 Dkamor
//

#include <vector>
#include <thread>
#include <mutex>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "Process.hpp"


Process::Process(const std::vector<std::string> &_input, int nb_threads, bool _processus) :
  _input(_input),
  nb_threads(nb_threads),
  _processus(_processus)
{
  this->id = 0;
  this->contain[PHONE] = IUser::information::PHONE_NUMBER;
  this->contain[EMAIL] = IUser::information::EMAIL_ADDRESS;
  this->contain[IP] = IUser::information::IP_ADDRESS;
  if (this->check_input() == false)
    std::cerr << "wrong input, command not found" << std::endl;
  else
    this->create_process();
}


std::string		Process::find_strings(const std::string &file)
{
  std::string		tmp = "";
  int			cmp = 1;
  int			i = 0;
  if (file == "")
    return (tmp);
  for (auto it : this->_input)
    {
      if (it == PHONE || it == EMAIL ||
	  it  == IP)
	 ++cmp;
      else
	{
	  tmp = it;
	  break;
	}
    }
  if (tmp == "")
    i = 1;
  while (i != cmp)
    this->_input.erase(this->_input.begin() + i++);
  return (tmp);
}

bool			Process::check_input()
{
  int			i = 0;
  for (auto it : _input)
    ++i;
  if (i == 0)
    return (false);
  return (this->_input.back() != PHONE &&
	  this->_input.back() != EMAIL &&
	  this->_input.back() != IP) ? false : true;
}

bool			Process::check_files()
{
  for (auto it : this->_input)
      if (it != PHONE && it != EMAIL &&
	  it != IP)
	return (true);
  return (false);
}

IUser::information	Process::find_commands(const std::string &file)
{
  if (file  == "")
    return (IUser::information::PHONE_NUMBER);
  for (auto it : this->_input)
    {
      if (it == PHONE)
	return (IUser::information::PHONE_NUMBER);
      else if (it == EMAIL)
	return (IUser::information::EMAIL_ADDRESS);
      else if (it == IP)
	return (IUser::information::IP_ADDRESS);
    }
  std::cerr << "Wrong input, command not found" << std::endl;
  std::exit(1);
}


bool			Process::delete_main_input()
{
  std::string		file = "start";
  int			cmp = 0;

  while (cmp  != nb_threads)
    {
      file = this->find_strings(file);
      this->find_commands(file);
      ++cmp;
    }
  return (check_files());

}
void			Process::create_process()
{
  pid_t			pid;

  if ((pid = fork()) == -1)
    {
      std::cerr << "Fail on fork(), exit FAILURE" << std::endl;
      exit (1);
    }
  if (pid != 0)
    {
      ++id;
      create_tube(id);
      if (delete_main_input() == true)
	 this->create_process();
    }
  else
    {
      ++id;
      read_tube(id);
      this->main_loop();
      sleep(4);
      exit (0);
    }
}

int		Process::create_tube(int id)
{
  int	entreeTube;

  std::stringstream ss;
  ss << id;
  std::string str;
  str = ss.str();
  if (mkfifo(str.c_str(), 0644) != 0)
    {
      return (1);
    }
  if((entreeTube = open(str.c_str(), O_WRONLY)) == -1)
    {
      return (1);
    }
  write(entreeTube, str.c_str(), 10);
  return (0);
}

int	Process::read_tube(int id)
{
  char	testeru[33];
  int	sortieTube;

  std::stringstream ss;
  ss << id;
  std::string str;
  str = ss.str();
  if ((sortieTube = open(str.c_str(), O_RDONLY)) == -1)
    {
      return (1);
    }
  read(sortieTube, testeru, 7);
  remove(str.c_str());
  return (0);
}

void			Process::main_loop()
{
  int			cmp = 0;
  Mutex			mut;
  std::string		file = "start";
  IUser::information	info;

  Thread	thr(&mut);

  while (cmp != nb_threads)
    {
      file = this->find_strings(file);
      info = this->find_commands(file);
      this->_threads.push_back(std::unique_ptr<std::thread>(new std::thread([&thr, file, info](){thr.instruction(file, info);
	    })));
      ++cmp;
    }
  for (auto it = this->_threads.begin(); it != _threads.end(); ++it)
    {
      (*it)->join();
    }
}

Process::~Process()
{
}
