#include "stdafx.h"
#include "Clock.h"


Clock::Clock()
{
	this->current = std::unique_ptr<std::chrono::steady_clock::time_point>(new std::chrono::steady_clock::time_point);
}


Clock::~Clock()
{
}

void		Clock::init_clock()
{
	*current = std::chrono::steady_clock::now();
}

bool		Clock::check_clock(__int64 min)
{
	__int64		res;

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	res = std::chrono::duration_cast<std::chrono::seconds>(end - *current).count();
	return (res >= min) ? false : true;

}
