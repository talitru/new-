#pragma once

#include"TheGame.h"


class HumanVsComputer :public TheGame
{
public:
	virtual void RunGame();
	char ChooseComputerLevel();

};