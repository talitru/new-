#pragma once
#include "Bomb.h"
#include "Menu.h"
#include <conio.h>
#include <iostream>
#include <Windows.h>
enum { ESC = 27 };//escapes
enum { RAND = 7 };


class TheGame :public Figure
{
protected:
	Menu menu;
	Board GameBoard;
public:
	char LeftPlayerKeys[10] = { 'a','A','d','D','s','S','w','W','x','X' };
	char RightPlayerKeys[10] = { 'j','J','l','L','k','K','i','I','m','M' };
	TheGame() { GameBoard.initBoard(); };//ctor
	void resetBoard()
	{
		GameBoard.initBoard();
	}
	general* createFigure(int numOfPlayer, int* serialNum);
	virtual void RunGame();
	void clearKeyBoardBuffer()const;
	bool MoveFigure(Board& board, general& f, int serialNum, char direction);
	void getMenuInstructions()const
	{
		menu.ShowInstructions();
	}
	bool WinCheck(int NumPlayer)const;
	void HideCursor();

};
