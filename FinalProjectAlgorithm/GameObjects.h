#pragma once
#include "Sprites.h"
#include "Utilities.h"


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

	void update()
	{
		clear();

		if (_kbhit())
		{
			char input = _getch();
			move(input);
		}

		draw();
	}
};

struct Ally
{
	int health;
	Vector2 position;
};

struct TrafficLight
{
	Vector2 position;
};

struct Car
{
	int health;
	Vector2 position;
};

struct Map
{
	int width, height;
	char** map;

	Map(int width, int height)
		: width(width), height(height)
	{
		map = new char* [height];
		for (int i = 0; i < height; ++i)
		{
			map[i] = new char[width];
		}
	}

	void draw()
	{
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				Console::SetCursorPosition(x, y);
				cout << map[y][x];
			}
		}
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
