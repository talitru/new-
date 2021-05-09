#include "HumanVsComputer.h"

void HumanVsComputer::RunGame()
{
	ChooseComputerLevel();
	TheGame::RunGame();
	general* f1, * f2;
	char key_char = 0;
	int y1 = Y1;
	int y2 = Y2;
	int serialNum1 = -1;
	int serialNum2 = -1;
	f1 = createFigure(LEFT_PLAYER, &serialNum1);

	f2 = createFigure(RIGHT_PLAYER, &serialNum2);



	while (key_char != EXIT && WinCheck(LEFT_PLAYER) == false && WinCheck(RIGHT_PLAYER) == false)
	{
		clearKeyBoardBuffer();

		f1->print(this->GameBoard);
		Sleep(100);


		f2->print(this->GameBoard);
		Sleep(100);


		++y1;
		++y2;

		if (_kbhit())
		{
			key_char = _getch();
			if (key_char == INSTRUCTIO_KEYS)
			{
				gotoxy(0, ROWS + 7);
				menu.ShowInstructions();
			}
			else if (key_char == ESC)
			{
				menu.ContinuePausedGame(key_char, this->GameBoard);
				menu.printMenu();
			}
			else
			{
				clearKeyBoardBuffer();
				for (int i = 0; i < 10; i++)
				{
					if (LeftPlayerKeys[i] == key_char)
					{
						if (MoveFigure(this->GameBoard, *f1, serialNum1, key_char) == false)
						{
							y1 = 1;
							GameBoard.DeleteRow(LEFT_PLAYER);
						}
						else
						{
							f1->print(this->GameBoard);
						}
						break;
					}
					if (RightPlayerKeys[i] == key_char)
					{
						if (MoveFigure(this->GameBoard, *f2, serialNum2, key_char) == false)
						{
							y2 = 1;
							GameBoard.DeleteRow(RIGHT_PLAYER);
						}
						else
						{
							f2->print(this->GameBoard);
						}
						break;
					}
				
						
				}
			}
		}
		clearKeyBoardBuffer();
		if (f1->update(this->GameBoard, serialNum1, DOWN) == false || y1 > ROWS)
		{
			y1 = 1;
			GameBoard.DeleteRow(LEFT_PLAYER);
			delete f1;
			f1 = createFigure(LEFT_PLAYER, &serialNum1);
		}

		if (f2->update(this->GameBoard, serialNum2, DOWN) == false || y2 > ROWS)
		{
			y2 = 1;
			GameBoard.DeleteRow(RIGHT_PLAYER);
			delete f2;
			f2 = createFigure(RIGHT_PLAYER, &serialNum2);
		}
	}
}


char HumanVsComputer::ChooseComputerLevel()
{
	char key_char = 0;
	gotoxy(30, 9);
	cout << "Hi! please enter the level of the computer:" << endl;
	gotoxy(30, 10);
	cout << "for the BEST level press (1)" << endl;
	gotoxy(30, 11);
	cout << "for the GOOD level press (2)" << endl;
	gotoxy(30, 12);
	cout << "for the NOVICE level press (3)" << endl;
	while (1)
	{
		if (_kbhit())
		{
			key_char = _getch();
			return key_char;
		}
	}
}
