#ifndef THREAD_HPP_
# define THREAD_HPP_

#include "ScopedLock.hpp"
#include "Regex.hh"
#include "IUser.hpp"

class Thread
{
  Mutex *_mutex;
  Regex	*_regex;
public:
  Thread(Mutex *);
  ~Thread();
  void		instruction(const std::string &file, const IUser::information &);
  void	        create_regex(const std::string &file, const IUser::information&);
};

#endif /* THREAD_HPP_ */
