#include "stdafx.h"
#include "pisqpipe.h"
#include <iostream>
#include <windows.h>
#include "Clock.h"
#include <vector>
#include <fstream>
#include "IA.h"

#define NB_THREAD 4

const char *infotext = "name=\"TesQuiDansLESPORT\", author=\"Epitech\", version=\"0.1.1.1\", country=\"FRANCE\"";

int coin = 0;
int board[MAX_BOARD][MAX_BOARD];

void brain_init()
{
	pipeOut("OK");
}

void brain_about()
{
	pipeOut("%s", infotext);
}

void brain_restart()
{
	int i = 0;	
	int x, y;
	coin = 0;
	for (x = 0; x < MAX_BOARD; x++) {
		for (y = 0; y < MAX_BOARD; y++) {
			board[x][y] = 0;
		}
	}
	pipeOut("OK");
}

int isFree(int x, int y)
{
	return x >= 0 && y >= 0 && x < MAX_BOARD && y < MAX_BOARD && board[x][y] == 0;
}

void brain_my(int x, int y)
{
	++coin;
	if (isFree(x, y)) {
		board[x][y] = 1;
	}
	else {
		pipeOut("ERROR my move [%d,%d]", x, y);
	}
}

void brain_opponents(int x, int y)
{
	++coin;
	if (isFree(x, y)) {
		board[x][y] = 2;
	}
	else {
		pipeOut("ERROR opponents's move [%d,%d]", x, y);
	}
}

void brain_block(int x, int y)
{
	if (isFree(x, y)) {
		board[x][y] = 3;
	}
	else {
		pipeOut("ERROR winning move [%d,%d]", x, y);
	}
}

int brain_takeback(int x, int y)
{
	if (x >= 0 && y >= 0 && x < MAX_BOARD && y < MAX_BOARD && board[x][y] != 0) {
		board[x][y] = 0;
		return 0;
	}
	return 2;
}

void brain_turn()
{
	int turnX = 10;
	int turnY = 10;
	if (coin == 0)
	{
		turnX = 10;
		turnY = 10;
	}
	else
	{
		int count = 0;
		std::vector<std::unique_ptr<IA>> contain;
		while (count != NB_THREAD)
		{
			contain.push_back(std::unique_ptr<IA>(new IA(coin, board, count)));
			++count;
		}
		for (auto it = contain.begin(); it != contain.end(); ++it)
			(*it)->join();
		std::vector<t_win> me;
		std::vector<t_win> adv;
		t_win tmp;
		tmp.move = 400;
		tmp.rate = 0;
		tmp.x = 0;
		tmp.y = 0;
		me.push_back(tmp);
		adv.push_back(tmp);
		bool find = false;

		for (auto ti = contain.begin(); ti != contain.end(); ++ti)
		{
			for (auto id = (*ti)->me.begin(); id != (*ti)->me.end(); ++id)
			{
				for (auto di = me.begin(); di != me.end(); ++di)
				{
					if ((*id).x == (*di).x && (*id).y == (*di).y)
					{
						(*di).rate += (*id).rate;
						find = true;
					}
				}
				if (find == false)
					me.push_back((*id));
				find = false;
			}
			for (auto id = (*ti)->adv.begin(); id != (*ti)->adv.end(); ++id)
			{
				for (auto di = adv.begin(); di != adv.end(); ++di)
				{
					if ((*id).x == (*di).x && (*id).y == (*di).y)
					{
						(*di).rate += (*id).rate;
						find = true;
					}
				}
				if (find == false)
					adv.push_back((*id));
				find = false;
			}
		
			int last = me[0].rate;
			int i = 0;
			int mpos = 0;
			for (auto it = me.begin(); it != me.end(); ++it)
			{
				if (last < (*it).rate)
				{
					mpos = i;
					last = (*it).rate;

				}
				++i;
			}
			i = 0;
			last = adv[0].rate;
			int apos = 0;
			for (auto it = adv.begin(); it != adv.end(); ++it)
			{
				if (last < (*it).rate)
				{
					apos = i;
					last = (*it).rate;
				}
				++i;
			}
			if (me[mpos].move <= adv[apos].move)
			{
				turnX = me[mpos].x;
				turnY = me[mpos].y;
			}
			else
			{
				turnX = adv[apos].x;
				turnY = adv[apos].y;
			}
		}
	}
	brain_my(turnX, turnY);
	pipeOut("%d,%d", turnX, turnY);
}

void brain_end()
{
}

#ifdef DEBUG_EVAL
#include <windows.h>

void brain_eval(int x, int y)
{
	HDC dc;
	HWND wnd;
	RECT rc;
	char c;
	wnd = GetForegroundWindow();
	dc = GetDC(wnd);
	GetClientRect(wnd, &rc);
	c = (char)(board[x][y] + '0');
	TextOut(dc, rc.right - 15, 3, &c, 1);
	ReleaseDC(wnd, dc);
}

#endif
