#include "Mutex.hpp"


Mutex::Mutex()
{
  this->Mut = new std::mutex;
}

Mutex::~Mutex()
{
  delete this->Mut;
}

void	Mutex::lock() const
{
  this->Mut->lock();
}


void	Mutex::unlock() const
{
  this->Mut->unlock();
}

bool	Mutex::trylock() const
{
  return this->Mut->try_lock();
}
