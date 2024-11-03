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
			for (int j = 0; j < 4; ++j)
			{
				this->sprite[i][j] = sprite[i][j];
			}
		}
	}
};

struct Enemy
{
	int health;
	Vector2 position;
};
