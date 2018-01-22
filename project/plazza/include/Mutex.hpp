#ifndef MUTEX_HPP_
# define MUTEX_HPP_

#include <mutex>
#include <iostream>

#include "IMutex.hpp"

class Mutex : public IMutex
{
  std::mutex *Mut;
public:
  Mutex();
  virtual ~Mutex();
  virtual void lock() const;
  virtual void unlock() const;
  virtual bool trylock() const;
};
#endif /* !MUTEX_HPP_ */
