#include <cstdlib>
#include <iostream>
#include <vector>
#include <thread>
#include <memory>
#include <chrono>
#include <unistd.h>
#include <mutex>
#include "Thread.hpp"


Thread::Thread(Mutex *mutex) : _mutex(mutex)
{
}

void			Thread::instruction(const std::string& file, const IUser::information &info)
{
  ScopedLock		lock(this->_mutex);
  this->_regex	 =	new Regex(file, info);
  if (this->_regex->get_file() == true)
    {
      if (_regex->Search(_regex->get_buffer()) == false)
	{
	  //this->_regex->Caesar();
	  //this->_regex->Xor();
	}
      this->_regex->Print();
      this->_regex->Print_file();
    }
}

Thread::~Thread()
{
  delete this->_regex;
}
