#include "stdafx.h"
#include "IA.h"


static unsigned int seed;

IA::IA(int Coin, int Board[MAX_BOARD][MAX_BOARD], int nb)
{
	seed = start_time;
	NB = nb;
	Thread = std::unique_ptr<std::thread>(new std::thread([this, Coin, Board]() {simulation(Coin, Board); }));
}

IA::~IA()
{
}

unsigned IA::rnd()
{
	seed = seed * 367413989 + 174680251;
	return (unsigned)(UInt32x32To64(MAX_BOARD, seed) >> 32);
}

void	IA::join()
{
	Thread->join();
}

bool	IA::horizontal(int x, int y, int player)
{	
	while (x >= 0 && board[x][y] == player)
	{
		--x;
	}
	++x;
	check = 0;
	while (x < MAX_BOARD && board[x][y] == player)
	{
		++x;
		++check;
	}
	if (check >= 5)
		return true;
	return false;

}

bool	IA::vertical(int x, int y, int player)
{
	while (y >= 0 && board[x][y] == player)
		--y;
	++y;
	check = 0;
	while (y < MAX_BOARD && board[x][y] == player)
	{
		++y;
		++check;
	}
	if (check >= 5)
		return true;
	return false;
}

bool	IA::diagoDownToUp(int x, int y, int player)
{
	while (y < MAX_BOARD && x >= 0 && board[x][y] == player)
	{
		++y;
		--x;
	}
	--y;
	++x;
	check = 0;
	while (y >= 0 && x < MAX_BOARD && board[x][y] == player)
	{
		++check;
		--y;
		++x;
	}
	if (check >= 5)
		return true;
	return false;
}

bool	IA::diagoUpToDown(int x, int y, int player)
{
	while (x >= 0 && y >= 0 && board[x][y] == player)
	{
		--y;
		--x;
	}
	++y;
	++x;
	check = 0;
	while (x < MAX_BOARD && y < MAX_BOARD && board[x][y] == player)
	{
		++check;
		++y;
		++x;
	}
	if (check >= 5)
		return true;
	return false;
}

bool	IA::check_win(int x, int y)
{
	if ((horizontal(x, y, board[x][y]) == true) ||
		(vertical(x, y, board[x][y]) == true) ||
		(diagoDownToUp(x, y, board[x][y]) == true) ||
		(diagoUpToDown(x, y, board[x][y]) == true))
		return (true);
	return false;
}

bool IA::right(int x, int y)
{
	if (x + 1 < MAX_BOARD)
	{
		if (0 == board[x + 1][y])
			return false;
		return true;
	}
	return false;
}

bool IA::left(int x, int y)
{
	if (x > 0)
	{
		if (0 == board[x - 1][y])
			return (false);
		return true;
	}
	return false;
}

bool IA::up(int x, int y)
{
	if (y > 0 )
	{
		if (0 == board[x][y - 1])
			return false;
		return true;
	}
	return false;
}

bool IA::down(int x, int y)
{
	if (y + 1 < MAX_BOARD)
	{
		if (0 == board[x][y + 1])
			return false;
		return true;
	}
	return false;
}

bool IA::rightUp(int x, int y)
{
	if (x + 1 < MAX_BOARD && y > 0)
	{
		if (0 == board[x + 1][y - 1])
			return false;
		return true;
	}
	return false;
}

bool IA::rightDown(int x, int y)
{
	if (y + 1 < MAX_BOARD && x + 1 < MAX_BOARD)
	{
		if (0 == board[x + 1][y + 1])
			return false;
		return true;
	}
	return false;
}

bool IA::leftUp(int x, int y)
{
	if (x > 0 && y > 0)
	{
		if (0 == board[x - 1][y - 1])
			return false;
		return true;
	}
	return false;
}

bool IA::leftDown(int x, int y)
{
	if (x > 0 && y + 1 < MAX_BOARD)
	{
		if (0 == board[x - 1][y + 1])
			return false;
		return true;
	}
	return false;
}

void IA::print_tab(int board[MAX_BOARD][MAX_BOARD])
{
	for (int y = 0; y < MAX_BOARD; y++) {
		for (int x = 0; x < MAX_BOARD; x++) {
			std::cout << board[x][y];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int IA::testFree(int x, int y)
{
	if ((down(x, y) == false) &&
		(up(x, y) == false) &&
		(left(x, y) == false) &&		
		(right(x, y) == false) &&		
		(leftUp(x, y) == false) &&
		(leftDown(x, y) == false) &&
		(rightUp(x, y) == false) &&
		(rightDown(x, y) == false))	
		return 0;
	return x >= 0 && y >= 0 && x < MAX_BOARD && y < MAX_BOARD && board[x][y] == 0;
}

void IA::init_simulation(int Coin, int Board[MAX_BOARD][MAX_BOARD])
{
	for (int y = 0; y < MAX_BOARD; y++) {
		for (int x = 0; x < MAX_BOARD; x++) {
			board[x][y] = Board[x][y];
		}
	}
	coin = Coin;
	playX = rnd();
	playY = rnd();
	while (!testFree(playX, playY))
	{
		playX = rnd();
		playY = rnd();
	}
	x = playX;
	y = playY;
	advX = -1;
	advY = -1;
	move = -1;
}

void IA::playerWin()
{
	if (me[0].move > move)
	{
		me.clear();
		test.move = move;
		test.rate = 1;
		test.x = playX;
		test.y = playY;
		me.push_back(test);
	}
	else
	{
		for (auto it = me.begin(); it != me.end(); ++it)
		{
			if ((*it).x == playX && (*it).y == playY)
			{
				find = true;
				(*it).rate = (*it).rate + 1;
			}
		}
		if (find == false)
		{
			test.move = move;
			test.rate = 1;
			test.x = playX;
			test.y = playY;
			me.push_back(test);
		}
	}
}

void IA::adverserWin()
{
	if (adv[0].move > move)
	{
		adv.clear();
		test.move = move;
		test.rate = 1;
		test.x = advX;
		test.y = advY;
		adv.push_back(test);
	}
	else
	{
		for (auto it = adv.begin(); it != adv.end(); ++it)
		{
			if ((*it).x == advX && (*it).y == advY)
			{
				find = true;
				++(*it).rate;
			}
		}
		if (find == false)
		{
			test.move = move;
			test.rate = 1;
			test.x = advX;
			test.y = advY;
			adv.push_back(test);
		}
	}
}

void IA::simulation(int Coin, int Board[MAX_BOARD][MAX_BOARD])
{
	int play = 1;

	adv.clear();
	me.clear();

	test.move = 400;
	test.rate = 1;
	test.x = 10;
	test.y = 10;

	adv.push_back(test);
	me.push_back(test);

	init_simulation(Coin, Board);
	index = 0;
	mytime.init_clock();
	while (mytime.check_clock(4))
	{
		find = false;
		board[x][y] = play;
		++move;
		if (play == 2 && advX == -1 && advY == -1)
		{
			advX = x;
			advY = y;
		}
		if (check_win(x, y) == true)
		{
			++index;
			if (play == 1 && me[0].move >= move)
				playerWin();
			else if (play == 2 && adv[0].move >= move)
				adverserWin();
			init_simulation(Coin, Board);
			play = 2;
		}
		++coin;
		if (coin == 400)
			init_simulation(Coin, Board);
		play = play == 1 ? 2 : 1;
		while (!testFree(x, y))
		{
			x = rnd();
			y = rnd();
		}
	}
}