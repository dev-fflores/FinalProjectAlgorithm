#pragma once
#include "pch.h"
#include <iostream>
#include "Sprites.h"
#include "Utilities.h"

using namespace System;
using namespace std;


struct Player
{
	int health;
	Vector2 position;
	int score;
	char sprite[5][4];

	Player(int health, Vector2 position, int score, const char sprite[5][4])
		: health(health), position(position), score(score)
	{
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				this->sprite[i][j] = sprite[i][j];
			}
		}
	}

	void move(char input_direction)
	{
		if (input_direction == 'w')
		{
			position.y--;
		}
		else if (input_direction == 's')
		{
			position.y++;
		}
		else if (input_direction == 'a')
		{
			position.x--;
		}
		else if (input_direction == 'd')
		{
			position.x++;
		}
	}

	void draw()
	{
		for (int y = 0; y < 5; y++)
		{
			for (int x = 0; x < 3; x++)
			{
				Console::SetCursorPosition(position.x + x, position.y + y);
				cout << sprite[y][x];
			}
		}
	}

	void clear()
	{
		for (int y = 0; y < 5; y++)
		{
			for (int x = 0; x < 3; x++)
			{
				Console::SetCursorPosition(position.x + x, position.y + y);
				cout << " ";
			}
		}
	}

	void start() {
		draw();
	}

	void update()
	{
		if (_kbhit())
		{
			clear();
			char input = _getch();
			move(input);
			draw();
		}
	}
};

struct Ally
{
	int health;
	Vector2 position;
	char sprite[3][3];

	Ally(const char sprite[3][3])
	{
		position.x = getRand(0, SCREEN_WIDTH - 4);
		position.y = getRand(0, SCREEN_HEIGHT - 4);

		for (int y = 0; y < 3; y++)
		{
			for (int x = 0; x < 3; x++)
			{
				this->sprite[y][x] = sprite[y][x];
			}
		}
	}

	void draw()
	{
		for (int y = 0; y < 3; y++)
		{
			for (int x = 0; x < 3; x++)
			{
				Console::SetCursorPosition(position.x + x, position.y + y);
				cout << sprite[y][x];
			}
		}
	}

	void clear()
	{
		for (int y = 0; y < 3; y++)
		{
			for (int x = 0; x < 3; x++)
			{
				Console::SetCursorPosition(position.x + x, position.y + y);
				cout << " ";
			}
		}
	}

	void start()
	{
		draw();
	}

	void update()
	{
		//clear();
		draw();
	}
};

struct TrafficLight
{
	Vector2 position;
};

struct Car
{
	int health;
	Vector2 position;
	int direction;
	char sprite[3][9];

	Car(const char sprite[3][9])
	{
		position.x = getRand(0, 160 - 10);
		position.y = getRand(0, 50 - 4);

		for (int y = 0; y < 3; y++)
		{
			for (int x = 0; x < 9; x++)
			{
				this->sprite[y][x] = sprite[y][x];
			}
		}
	}

	Car(const char sprite[5][4], Vector2 position)
	{
		this->position = position;

		for (int y = 0; y < 3; y++)
		{
			for (int x = 0; x < 9; x++)
			{
				this->sprite[y][x] = sprite[y][x];
			}
		}
	}
	
	void draw()
	{
		for (int y = 0; y < 3; y++)
		{
			for (int x = 0; x < 9; x++)
			{
				Console::SetCursorPosition(position.x + x, position.y + y);
				cout << sprite[y][x];
			}
		}
	}

	void clear()
	{
		Console::SetCursorPosition(position.x, position.y);
		cout << " ";
	}

	void start()
	{
		draw();
	}

	void update()
	{
		//clear();
		draw();
	}
};

struct Map
{
	int map[SCREEN_HEIGHT][SCREEN_WIDTH];

	// Inicializar mapa con altura y anchura de la consola
	Map(const int input_map[SCREEN_HEIGHT][SCREEN_WIDTH])
	{
		for (int y = 0; y < SCREEN_HEIGHT; y++)
		{
			for (int x = 0; x < SCREEN_WIDTH; x++)
			{
				map[y][x] = input_map[y][x];
			}
		}
	}

	void draw()
	{
		for (int y = 0; y < SCREEN_HEIGHT; y++)
		{
			for (int x = 0; x < SCREEN_WIDTH; x++)
			{
				/*Console::SetCursorPosition(x, y);
				cout << map[y][x];*/
				if (map[y][x] == 0) Console::ForegroundColor = ConsoleColor::Cyan;
				if (map[y][x] == 1) Console::ForegroundColor = ConsoleColor::Yellow;
				if (map[y][x] == 2) Console::ForegroundColor = ConsoleColor::Gray;
				if (map[y][x] == 3) Console::ForegroundColor = ConsoleColor::DarkRed;


				cout << (char)219;
			}
		}
	}

	void clear()
	{
		for (int y = 0; y < SCREEN_HEIGHT; y++)
		{
			for (int x = 0; x < SCREEN_WIDTH; x++)
			{
				Console::SetCursorPosition(x, y);
				cout << " ";
			}
		}
	}

	void start()
	{
		draw();
	}

	void update()
	{
		//clear();
		draw();
	}
};

struct Game
{
	Player* player;
	Ally* allies;
	TrafficLight* traffic_lights;
	Car* cars;
	Map* map;

	Game(Player* player, Ally* allies, TrafficLight* traffic_lights, Car* cars, Map* map)
		: player(player), allies(allies), traffic_lights(traffic_lights), cars(cars), map(map)
	{
	}

	void update()
	{
		player->update();
	}
};
