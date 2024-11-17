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
	Color color;
	int score;
	char sprite[5][4];
	int backup_map[SCREEN_HEIGHT][SCREEN_WIDTH];

	Player(Color color, Vector2 position, int score, const char sprite[5][4], const int backup_map[SCREEN_HEIGHT][SCREEN_WIDTH])
	{
		this->color = color;
		this->health = health;
		this->position = position;
		this->score = score;

		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				this->sprite[i][j] = sprite[i][j];
			}
		}

		for (size_t i = 0; i < SCREEN_HEIGHT; i++)
		{
			for (size_t j = 0; j < SCREEN_WIDTH; j++)
			{
				this->backup_map[i][j] = backup_map[i][j];
			}
		}
	}

	void move(char input_direction)
	{
		if (input_direction == 'w' || input_direction == 'W')
		{
			position.y--;
		}
		else if (input_direction == 's' || input_direction == 'S')
		{
			position.y++;
		}
		else if (input_direction == 'a' || input_direction == 'A')
		{
			position.x--;
		}
		else if (input_direction == 'd' || input_direction == 'D')
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
				int pos_x = position.x + x;
				int pos_y = position.y + y;

				Console::SetCursorPosition(pos_x, pos_y);
				//cout << backup_map[pos_y][pos_x];

				if (backup_map[pos_y][pos_x] == 0) Console::BackgroundColor = ConsoleColor::Cyan;
				if (backup_map[pos_y][pos_x] == 1) Console::BackgroundColor = ConsoleColor::Yellow;
				if (backup_map[pos_y][pos_x] == 2) Console::BackgroundColor = ConsoleColor::Gray;
				if (backup_map[pos_y][pos_x] == 3) Console::BackgroundColor = ConsoleColor::DarkRed;
				if (backup_map[pos_y][pos_x] == 4) Console::BackgroundColor = ConsoleColor::Green;
				if (backup_map[pos_y][pos_x] == 5) Console::BackgroundColor = ConsoleColor::DarkMagenta;
				if (backup_map[pos_y][pos_x] == 6) Console::BackgroundColor = ConsoleColor::DarkGray;

				//Console::ForegroundColor = ConsoleColor::Black;
				cout << setForegroundColor(color) << sprite[y][x];
			}
		}
	}

	void clear()
	{
		for (int y = 0; y < 5; y++)
		{
			for (int x = 0; x < 3; x++)
			{
				int pos_x = position.x + x;
				int pos_y = position.y + y;

				Console::SetCursorPosition(pos_x, pos_y);
				//cout << backup_map[pos_y][pos_x];

				if (backup_map[pos_y][pos_x] == 0) Console::BackgroundColor = ConsoleColor::Cyan;
				if (backup_map[pos_y][pos_x] == 1) Console::BackgroundColor = ConsoleColor::Yellow;
				if (backup_map[pos_y][pos_x] == 2) Console::BackgroundColor = ConsoleColor::Gray;
				if (backup_map[pos_y][pos_x] == 3) Console::BackgroundColor = ConsoleColor::DarkRed;
				if (backup_map[pos_y][pos_x] == 4) Console::BackgroundColor = ConsoleColor::Green;
				if (backup_map[pos_y][pos_x] == 5) Console::BackgroundColor = ConsoleColor::DarkMagenta;
				if (backup_map[pos_y][pos_x] == 6) Console::BackgroundColor = ConsoleColor::DarkGray;


				cout << " ";
			}
		}
	}

	void start() {
		Console::CursorVisible = false;
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
	Color color;

	Ally(const char sprite[3][3], Color color)
	{
		this->color = color;

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

	Ally(const char sprite[3][3], Vector2 position, Color color)
	{
		this->color = color;
		this->position = position;

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
				cout << setForegroundColor(color) << sprite[y][x];
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
	char sprite[3][9];
	Color color;
	float dx, dy;
	Vector2 direction;
	int backup_map[SCREEN_HEIGHT][SCREEN_WIDTH];
	float speed;

	Car(const char sprite[3][9], Color color, int backup_map[SCREEN_HEIGHT][SCREEN_WIDTH], Vector2 direction, float speed)
	{
		this->color = color;
		this->direction = direction;
		this->speed = speed;

		position.x = getRand(0, 160 - 10);
		position.y = getRand(0, 50 - 4);

		for (int y = 0; y < 3; y++)
		{
			for (int x = 0; x < 9; x++)
			{
				this->sprite[y][x] = sprite[y][x];
			}
		}

		for (size_t i = 0; i < SCREEN_HEIGHT; i++)
		{
			for (size_t j = 0; j < SCREEN_WIDTH; j++)
			{
				this->backup_map[i][j] = backup_map[i][j];
			}
		}
	}

	Car(const char sprite[3][9], Vector2 position, Color color, int backup_map[SCREEN_HEIGHT][SCREEN_WIDTH], Vector2 direction, float speed)
	{
		this->color = color;
		this->position = position;
		this->direction = direction;
		this->speed = speed;

		for (int y = 0; y < 3; y++)
		{
			for (int x = 0; x < 9; x++)
			{
				this->sprite[y][x] = sprite[y][x];
			}
		}

		for (size_t i = 0; i < SCREEN_HEIGHT; i++)
		{
			for (size_t j = 0; j < SCREEN_WIDTH; j++)
			{
				this->backup_map[i][j] = backup_map[i][j];
			}
		}
	}

	Car(const char sprite[4][5], Vector2 position, Color color, int backup_map[SCREEN_HEIGHT][SCREEN_WIDTH], Vector2 direction, float speed)
	{
		this->color = color;
		this->position = position;
		this->direction = direction;
		this->speed = speed;

		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 5; x++)
			{
				this->sprite[y][x] = sprite[y][x];
			}
		}

		for (size_t i = 0; i < SCREEN_HEIGHT; i++)
		{
			for (size_t j = 0; j < SCREEN_WIDTH; j++)
			{
				this->backup_map[i][j] = backup_map[i][j];
			}
		}
	}

	void draw()
	{
		for (int y = 0; y < 3; y++)
		{
			for (int x = 0; x < 9; x++)
			{
				int pos_x = position.x + x;
				int pos_y = position.y + y;

				Console::SetCursorPosition(pos_x, pos_y);
				//cout << backup_map[pos_y][pos_x];

				if (backup_map[pos_y][pos_x] == 0) std::cout << setBackgroundColor({0,255,255});
				if (backup_map[pos_y][pos_x] == 1) Console::BackgroundColor = ConsoleColor::Yellow;
				if (backup_map[pos_y][pos_x] == 2) Console::BackgroundColor = ConsoleColor::Gray;
				if (backup_map[pos_y][pos_x] == 3) Console::BackgroundColor = ConsoleColor::DarkRed;
				if (backup_map[pos_y][pos_x] == 4) Console::BackgroundColor = ConsoleColor::Green;
				if (backup_map[pos_y][pos_x] == 5) Console::BackgroundColor = ConsoleColor::DarkMagenta;
				if (backup_map[pos_y][pos_x] == 6) Console::BackgroundColor = ConsoleColor::DarkGray;

				//Console::ForegroundColor = color;
				cout << setForegroundColor(color) << sprite[y][x];
			}
		}
	}

	void clear()
	{

		for (int y = 0; y < 3; y++)
		{
			for (int x = 0; x < 9; x++)
			{
				int pos_x = position.x + x;
				int pos_y = position.y + y;

				Console::SetCursorPosition(pos_x, pos_y);
				//cout << backup_map[pos_y][pos_x];

				if (backup_map[pos_y][pos_x] == 0) std::cout << setBackgroundColor({ 0,255,255 });
				if (backup_map[pos_y][pos_x] == 1) Console::BackgroundColor = ConsoleColor::Yellow;
				if (backup_map[pos_y][pos_x] == 2) Console::BackgroundColor = ConsoleColor::Gray;
				if (backup_map[pos_y][pos_x] == 3) Console::BackgroundColor = ConsoleColor::DarkRed;
				if (backup_map[pos_y][pos_x] == 4) Console::BackgroundColor = ConsoleColor::Green;
				if (backup_map[pos_y][pos_x] == 5) Console::BackgroundColor = ConsoleColor::DarkMagenta;
				if (backup_map[pos_y][pos_x] == 6) Console::BackgroundColor = ConsoleColor::DarkGray;


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

		clear();


		if (direction.x == 1)
		{
			position.x += speed;
		}
		else if (direction.x == -1)
		{
			position.x -= speed;
		}
		else if (direction.y == 1)
		{
			position.y += speed;
		}
		else if (direction.y == -1)
		{
			position.y -= speed;
		}

		if (position.x < 1 || position.x > SCREEN_WIDTH - 10) {
			direction.x *= -1;
		}

		if (position.y < 1 || position.y > SCREEN_HEIGHT - 4) {
			direction.y *= -1;
		}



		draw();
	}
};

struct Map
{
	int map [SCREEN_HEIGHT][SCREEN_WIDTH];

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
				if (map[y][x] == 0) std::cout << setForegroundColor({0, 255, 255}) << "";
				if (map[y][x] == 1) Console::ForegroundColor = ConsoleColor::Yellow;
				if (map[y][x] == 2) Console::ForegroundColor = ConsoleColor::Gray;
				if (map[y][x] == 3) Console::ForegroundColor = ConsoleColor::DarkRed;
				if (map[y][x] == 4) Console::ForegroundColor = ConsoleColor::Green;
				if (map[y][x] == 5) Console::ForegroundColor = ConsoleColor::DarkMagenta;
				if (map[y][x] == 6) Console::ForegroundColor = ConsoleColor::DarkGray;


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
	Ally* allies[5];
	TrafficLight* traffic_lights;
	Car* cars[5];
	Map* map;

	bool is_running = true;

	Game(Player* player, Ally* allies[5], TrafficLight* traffic_lights, Car* cars[5], Map* map)
		: player(player), traffic_lights(traffic_lights), map(map)
	{
		for (int i = 0; i < 5; i++)
		{
			this->allies[i] = allies[i];
			this->cars[i] = cars[i];
		}
	}

	void start()
	{
		map->start();
		player->start();

		for (int i = 0; i < 5; i++)
		{
			allies[i]->start();
			cars[i]->start();

		}
	}

	void update()
	{
		player->update();

		for (int i = 0; i < 5; i++)
		{
			allies[i]->update();
			cars[i]->update();
		}
	}

	bool isRunning()
	{
		return is_running;
	}
};