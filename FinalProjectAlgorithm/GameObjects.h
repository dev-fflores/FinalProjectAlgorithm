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

				if (backup_map[pos_y][pos_x] == 0) std::cout << setBackgroundColor({ 0, 255, 255 }); //cyan
				if (backup_map[pos_y][pos_x] == 1) std::cout << setBackgroundColor({ 255, 255, 0 }); //yellow
				if (backup_map[pos_y][pos_x] == 2) std::cout << setBackgroundColor({ 200, 200, 200 }); //gray
				if (backup_map[pos_y][pos_x] == 3) std::cout << setBackgroundColor({ 128, 0, 32 }); // dark red
				if (backup_map[pos_y][pos_x] == 4) std::cout << setBackgroundColor({ 34, 139, 34 }); // dark green
				if (backup_map[pos_y][pos_x] == 5) std::cout << setBackgroundColor({ 128, 0, 128 });// dark magenta
				if (backup_map[pos_y][pos_x] == 6) std::cout << setBackgroundColor({ 255, 255, 0 }); // dark gay

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

				if (backup_map[pos_y][pos_x] == 0) std::cout << setBackgroundColor({ 0, 255, 255 }); //cyan
				if (backup_map[pos_y][pos_x] == 1) std::cout << setBackgroundColor({ 255, 255, 0 }); //yellow
				if (backup_map[pos_y][pos_x] == 2) std::cout << setBackgroundColor({ 200, 200, 200 }); //gray
				if (backup_map[pos_y][pos_x] == 3) std::cout << setBackgroundColor({ 128, 0, 32 }); // dark red
				if (backup_map[pos_y][pos_x] == 4) std::cout << setBackgroundColor({ 34, 139, 34 }); // dark green
				if (backup_map[pos_y][pos_x] == 5) std::cout << setBackgroundColor({ 128, 0, 128 });// dark magenta
				if (backup_map[pos_y][pos_x] == 6) std::cout << setBackgroundColor({ 255, 255, 0 }); // dark gay


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
	char** sprite; // Arreglo dinámico para el sprite
	Color color;
	float dx, dy;
	Vector2 direction;
	int backup_map[SCREEN_HEIGHT][SCREEN_WIDTH];
	float speed;
	int sprite_width;  // Ancho del sprite
	int sprite_height; // Alto del sprite

	Car(const char** sprite, int sprite_width, int sprite_height, Color color, int backup_map[SCREEN_HEIGHT][SCREEN_WIDTH], Vector2 direction, float speed)
	{
		this->color = color;
		this->direction = direction;
		this->speed = speed;
		this->sprite_height = sprite_height;
		this->sprite_width = sprite_width;

		position.x = getRand(0, 160 - 10);
		position.y = getRand(0, 50 - 4);

		// Asignar memoria para el sprite dinámico
		this->sprite = new char* [sprite_height];
		for (int i = 0; i < sprite_height; i++) {
			this->sprite[i] = new char[sprite_width];
			for (int j = 0; j < sprite_width; j++) {
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

	Car(const char** sprite, int sprite_width, int sprite_height, Vector2 position, Color color, int backup_map[SCREEN_HEIGHT][SCREEN_WIDTH], Vector2 direction, float speed)
	{
		this->color = color;
		this->position = position;
		this->direction = direction;
		this->speed = speed;
		this->sprite_height = sprite_height;
		this->sprite_width = sprite_width;

		// Asignar memoria para el sprite dinámico
		this->sprite = new char* [sprite_height];
		for (int i = 0; i < sprite_height; i++) {
			this->sprite[i] = new char[sprite_width];
			for (int j = 0; j < sprite_width; j++) {
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

	void draw()
	{
		for (int y = 0; y < sprite_height; y++)
		{
			for (int x = 0; x < sprite_width; x++)
			{
				int pos_x = position.x + x;
				int pos_y = position.y + y;

				Console::SetCursorPosition(pos_x, pos_y);
				//cout << backup_map[pos_y][pos_x];

				if (backup_map[pos_y][pos_x] == 0) std::cout << setBackgroundColor({ 0, 255, 255 }); //cyan
				if (backup_map[pos_y][pos_x] == 1) std::cout << setBackgroundColor({ 255, 255, 0 }); //yellow
				if (backup_map[pos_y][pos_x] == 2) std::cout << setBackgroundColor({ 200, 200, 200 }); //gray
				if (backup_map[pos_y][pos_x] == 3) std::cout << setBackgroundColor({ 128, 0, 32 }); // dark red
				if (backup_map[pos_y][pos_x] == 4) std::cout << setBackgroundColor({ 34, 139, 34 }); // dark green
				if (backup_map[pos_y][pos_x] == 5) std::cout << setBackgroundColor({ 128, 0, 128 });// dark magenta
				if (backup_map[pos_y][pos_x] == 6) std::cout << setBackgroundColor({ 255, 255, 0 }); // dark gay

				//Console::ForegroundColor = color;
				cout << setForegroundColor(color) << sprite[y][x];
			}
		}
	}

	void clear()
	{

		for (int y = 0; y < sprite_height; y++)
		{
			for (int x = 0; x < sprite_width; x++)
			{
				int pos_x = position.x + x;
				int pos_y = position.y + y;

				Console::SetCursorPosition(pos_x, pos_y);
				//cout << backup_map[pos_y][pos_x];

				if (backup_map[pos_y][pos_x] == 0) std::cout << setBackgroundColor({ 0, 255, 255 }); //cyan
				if (backup_map[pos_y][pos_x] == 1) std::cout << setBackgroundColor({ 255, 255, 0 }); //yellow
				if (backup_map[pos_y][pos_x] == 2) std::cout << setBackgroundColor({ 200, 200, 200 }); //gray
				if (backup_map[pos_y][pos_x] == 3) std::cout << setBackgroundColor({ 128, 0, 32 }); // dark red
				if (backup_map[pos_y][pos_x] == 4) std::cout << setBackgroundColor({ 34, 139, 34 }); // dark green
				if (backup_map[pos_y][pos_x] == 5) std::cout << setBackgroundColor({ 128, 0, 128 });// dark magenta
				if (backup_map[pos_y][pos_x] == 6) std::cout << setBackgroundColor({ 255, 255, 0 }); // dark gay


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
				if (map[y][x] == 0) std::cout << setForegroundColor({0, 255, 255}); //cyan
				if (map[y][x] == 1) std::cout << setForegroundColor({ 255, 255, 0 }); //yellow
				if (map[y][x] == 2) std::cout << setForegroundColor({ 200, 200, 200 }); //gray
				if (map[y][x] == 3) std::cout << setForegroundColor({ 128, 0, 32 }); // dark red
				if (map[y][x] == 4) std::cout << setForegroundColor({ 34, 139, 34 }); // dark green
				if (map[y][x] == 5) std::cout << setForegroundColor({ 128, 0, 128 });// dark magenta
				if (map[y][x] == 6) std::cout << setForegroundColor({ 255, 255, 0 }); // dark gay


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

struct UI {
	Vector2 position;
	char** sprite;
	int ui_width;
	int ui_height;
	string title;
	string nickname;
	string message;
	int current_level;
	int score;

	int padding_left = 3;

	UI(const char** sprite, Vector2 position, int ui_width, int ui_height, string title, string nickname, string message, int current_level, int score)
	{
		this->position = position;
		this->ui_width = ui_width;
		this->ui_height = ui_height;
		this->title = title;
		this->nickname = nickname;
		this->message = message;
		this->current_level = current_level;
		this->score = score;

		this->sprite = new char* [ui_height];
		for (int i = 0; i < ui_height; i++) {
			this->sprite[i] = new char[ui_width];
			for (int j = 0; j < ui_width; j++) {
				this->sprite[i][j] = sprite[i][j];
			}
		}
	}

	void draw()
	{
		for (int y = 0; y < ui_height; y++)
		{
			for (int x = 0; x < ui_width; x++)
			{
				int pos_x = position.x + x;
				int pos_y = position.y + y;

				Console::SetCursorPosition(pos_x, pos_y);
				cout << sprite[y][x];
			}
		}
	}

	void clear()
	{
		for (int y = 0; y < ui_height; y++)
		{
			for (int x = 0; x < ui_width; x++)
			{
				int pos_x = position.x + x;
				int pos_y = position.y + y;

				Console::SetCursorPosition(pos_x, pos_y);
				cout << " ";
			}
		}
	}

	void start()
	{
		draw();

		Console::SetCursorPosition(position.x + padding_left, position.y + 1);
		cout << "Title: " << title;
		Console::SetCursorPosition(position.x + padding_left, position.y + 2);
		cout << "Nickname: " << nickname;
		Console::SetCursorPosition(position.x + padding_left, position.y + 3);
		cout << "Message: " << message;
		Console::SetCursorPosition(position.x + padding_left, position.y + 4);
		cout << "Level: " << current_level;
		Console::SetCursorPosition(position.x + padding_left, position.y + 5);
		cout << "Score: " << score;
	}

	void updateScore(int amount)
	{
		score += amount;
		Console::SetCursorPosition(position.x + padding_left, position.y + 5);
		cout << "Score: " << score;
	}


};



struct Game
{
	Player* player;
	Ally* allies[5];
	TrafficLight* traffic_lights;
	Car* cars[5];
	Map* map;
	UI* ui;

	bool is_running = true;
	bool first_collision = false;

	Game(Player* player, Ally* allies[5], TrafficLight* traffic_lights, Car* cars[5], Map* map, UI* ui)
		: player(player), traffic_lights(traffic_lights), map(map), ui(ui)
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
		ui->start();

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

			if (checkCollision(*player, *cars[i])) {
				// Sumar puntos al score del jugador
				player->score += 10;  // Por ejemplo, 10 puntos por colisión

				// Opción: Mover el carro a una nueva posición aleatoria
				/*cars[i]->position.x = getRand(0, 160 - cars[i]->sprite_width);
				cars[i]->position.y = getRand(0, 50 - cars[i]->sprite_height);*/

				// Mostrar el score actualizado en la consola (opcional)
				ui->updateScore(10);
			}
		}
	}

	bool isRunning()
	{
		return is_running;
	}

	bool checkCollision(const Player& player, const Car& car) {
		// Rango del jugador
		int player_left = player.position.x;
		int player_right = player.position.x + 3;  // Ancho del sprite del jugador
		int player_top = player.position.y;
		int player_bottom = player.position.y + 5;  // Alto del sprite del jugador

		// Rango del carro
		int car_left = car.position.x;
		int car_right = car.position.x + car.sprite_width;
		int car_top = car.position.y;
		int car_bottom = car.position.y + car.sprite_height;

		// Verificar si los rangos se solapan
		return !(player_right < car_left ||
			player_left > car_right ||
			player_bottom < car_top ||
			player_top > car_bottom);
	}
};