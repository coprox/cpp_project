#ifndef USER_HPP_
# define USER_HPP_

#include "IUser.hpp"

class User : public IUser
{
  int		_threads;
  std::string	_input;
public:
  User(int);
  virtual ~User();
  virtual void		Wait_input();
  virtual void		Process_it();
};

# endif /* !USER_HPP_ */
