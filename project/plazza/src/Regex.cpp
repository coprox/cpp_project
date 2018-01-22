//
// regex.cpp for regex in /home/paute_a/cpp_plazza/src
//
// Made by paute antoine
// Login   <paute_a@epitech.net>
//
// Started on  Fri Apr 28 15:12:32 2017 paute antoine
// Last update Sun Apr 30 22:41:40 2017 Dkamor
//

#include <vector>
#include <iostream>
#include <string>
#include "Regex.hh"
#include "IUser.hpp"

Regex::Regex(const std::string &filename, const IUser::information &info)
{
  std::ifstream fichier(filename);
  std::regex reg;
  std::map<IUser::information, std::regex> map;
  map[IUser::information::IP_ADDRESS] = M_IP;
  map[IUser::information::EMAIL_ADDRESS] = M_EMAIL;
  map[IUser::information::PHONE_NUMBER] = M_PHONE;
  if (fichier)
    {
      _file = true;
      getline(fichier, this->_buffer, '\0');
      this->_reg = map[info];
    }
}

void	Regex::Caesar()
{
  std::string test = get_buffer();
  for (int y = -255; y < 255; y++)
    {
      for (int i = 0; test[i] != '\0' ; i++)
  	test[i] = test[i] + 1;
      Search(test);
    }
}

bool	Regex::Search(std::string test)
{
  std::smatch m;

  if (std::regex_search(test, m, _reg) == true)
    {
      while (std::regex_search (test, m, _reg) == true)
	{
	  this->_vector.push_back(m[0]);
	  test = m.suffix().str();
	}
      return (true);
    }
  else
    return (false);
}

void	Regex::Print()
{
  if (!_vector.empty())
    {
      for (unsigned int i = 0; i < _vector.size(); i++)
	std::cout << _vector[i] << std::endl;
    }
}

void	Regex::Print_file()
{
  std::ofstream fichier("save.txt", std::ios::out | std::ios::app);

  if (fichier)
    {
      if (!_vector.empty())
	{
	  for (unsigned int i = 0; i < _vector.size(); i++)
	    fichier << _vector[i] << std::endl;
	}
    }
}

void	Regex::Xor()
{
  std::string test = get_buffer();
  int	first = 0;
  int	second = 0;
  int	exp = 1;
  int	i = 0;

  for (int y = 0; y < 65536; y++)
    {
      for (i = 0; i < 8; i++)
	{
	  if (y & 1 << i)
	    first = first + exp;
	  if (y & 1 << (i + 8))
	    second = second + exp;
	  exp = exp * 2;
	}
      i = 0;
      while (test[i])
	{
	  if (i % 2)
	    test[i] = test[i] ^ first;
	  else
	    test[i] = test[i] ^ second;
	}
      exp = 1;
      first = 0;
      second = 0;
    }
}

bool	Regex::get_file() const
{
  return(this->_file);
}

std::string	Regex::get_buffer() const
{
  return (this->_buffer);
}


Regex::~Regex()
{}
