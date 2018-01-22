#pragma once

#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <memory>

class Clock
{
private:
	std::unique_ptr<std::chrono::steady_clock::time_point> current;
public:
	Clock();
	~Clock();
	void init_clock();
	bool check_clock(__int64);
};

