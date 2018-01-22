//
// Process.hpp for y in /home/dekamor/rendu_sec/project/cpp_plazza/include
//
// Made by Dkamor
// Login   <corentin.bellamy@epitech.eu>
//
// Started on  Thu Apr 27 17:42:05 2017 Dkamor
// Last update Sun Apr 30 22:12:54 2017 Dkamor
//

#ifndef PROCESS_HPP_
# define PROCESS_HPP_

#include <vector>
#include <thread>
#include <map>
#include <iostream>
#include <memory>
#include "Thread.hpp"
#include "User.hpp"

# define PHONE "PHONE_NUMBER"
# define EMAIL "EMAIL_ADDRESS"
# define IP "IP_ADDRESS"

class Process
{
  std::vector<std::string>		_input;
  int					nb_threads;
  bool					_processus;
  int					id;
  std::vector<std::unique_ptr<std::thread>>		_threads;
  std::map<std::string, IUser::information>		contain;
public:
  Process(const std::vector<std::string>&, int, bool);
  ~Process();
  void			main_loop();
  void			create_process();
  bool			check_files();
  bool			check_input();
  bool			delete_main_input();
  int			create_tube(int);
  int			read_tube(int);
  IUser::information	find_commands(const std::string &);
  std::string		find_strings(const std::string &);
};
#endif /* !PROCESS_HPP_ */
