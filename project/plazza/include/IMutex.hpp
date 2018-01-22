#ifndef IMUTEX_HPP_
# define IMUTEX_HPP_

class IMutex
{
public:
  virtual ~IMutex() {}
  virtual void lock() const  = 0;
  virtual void unlock() const  = 0;
  virtual bool trylock() const = 0;
};

# endif /* !IMUTEX_HPP_ */
