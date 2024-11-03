#include "pch.h"
#include <iostream>
#include <conio.h>
#include "GameObjects.h"

using namespace System;
using namespace std;

int main()
{
	srand(time(NULL));

	Player* player = new Player(100, { 0,0 }, 10, spr_player);

	// Mover al jugador con las teclas W, A, S, D en la consola usando Conole::SetCursorPosition
	while (true)
	{
		system("cls");
		for (int y = 0; y < 5; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				Console::SetCursorPosition(player->position.x + x, player->position.y + y);
				cout << player->sprite[y][x];
			}
		}

		char input = _getch();

		if (input == 'w')
		{
			player->position.y--;
		}
		else if (input == 's')
		{
			player->position.y++;
		}
		else if (input == 'a')
		{
			player->position.x--;
		}
		else if (input == 'd')
		{
			player->position.x++;
		}
	}



	system("pause > 0");

	return 0;
}