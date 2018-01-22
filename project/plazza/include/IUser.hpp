//
// user.hpp for y in /home/dekamor/rendu_sec/project/cpp_plazza/include
//
// Made by Dkamor
// Login   <corentin.bellamy@epitech.eu>
//
// Started on  Tue Apr 25 17:50:31 2017 Dkamor
// Last update Sun Apr 30 17:36:23 2017 paute antoine
//

#ifndef IUSER_HPP_
# define IUSER_HPP_

#include <string>
#include <iostream>

class IUser
{
public:
  virtual ~IUser() {}
  virtual void Wait_input() = 0;
  virtual void Process_it() = 0;
  enum information
    {
      PHONE_NUMBER,
      EMAIL_ADDRESS,
      IP_ADDRESS,
    };
};

#endif /* !IUSER_HPP_ */
