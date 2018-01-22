#pragma once

#include <windows.h>
#include <vector>
#include <random>
#include <memory>
#include <thread>
#include <iostream>
#include "pisqpipe.h"
#include "Clock.h"
#include "IA.h"
#include "Clock.h"

#define MAX_BOARD 20

typedef struct	s_win
{
	int			x;
	int			y;
	int			rate;
	int			move;
}				t_win;

class IA
{
	std::unique_ptr<std::thread> Thread;
public:
	IA(int Coin, int Board[MAX_BOARD][MAX_BOARD], int nb);
	~IA();
	void simulation(int Coin, int Board[MAX_BOARD][MAX_BOARD]);
	int testFree(int x, int y);
	void print_tab(int board[MAX_BOARD][MAX_BOARD]);
	void init_simulation(int Coin, int Board[MAX_BOARD][MAX_BOARD]);
	void playerWin();
	void adverserWin();
	unsigned	 rnd();
	void join();
	bool vertical(int x, int y, int player);
	bool horizontal(int x, int y, int player);
	bool diagoDownToUp(int x, int y, int player);
	bool diagoUpToDown(int x, int y, int player);
	bool check_win(int x, int y);
	bool right(int x, int y);
	bool left(int x, int y);
	bool up(int x, int y);
	bool down(int x, int y);
	bool rightUp(int x, int y);
	bool rightDown(int x, int y);
	bool leftUp(int x, int y);
	bool leftDown(int x, int y);
	int playY = 0;
	int playX = 0;
	int check = 0;
	int move = 0;
	int coin = 0;
	int x = 10;
	int y = 10;
	int advX = -1;
	int advY = -1;
	int index = 0;
	unsigned seed;
	int NB;
	std::vector<t_win> adv;
	std::vector<t_win> me;
	t_win	test;
	bool	find = false;
	int board[MAX_BOARD][MAX_BOARD];
	Clock mytime;
};

