#ifndef SCOPEDLOCK_HPP_
# define SCOPEDLOCK_HPP_

#include "Mutex.hpp"

class ScopedLock
{
  Mutex	*custom;
public:
  inline ScopedLock(Mutex *custom) :
    custom(custom)
  {
    this->custom->lock();
  }
  inline ~ScopedLock()
  {
    this->custom->unlock();
  }
};

# endif /* !SCOPEDLOCK_HPP_ */
