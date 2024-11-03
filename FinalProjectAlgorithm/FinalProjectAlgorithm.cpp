
#include "pch.h"
#include <conio.h>
#include "GameObjects.h"
#include "FinalProjectAlgorithm.h"


int main()
{
	srand(time(NULL));
	Console::SetWindowSize(160, 50);

	// Mover al jugador con las teclas W, A, S, D en la consola usando Conole::SetCursorPosition
	Map* map = new Map(spr_map_01);

	Player* player = new Player(100, {70,20}, 10, spr_player);

	Car* car = new Car(spr_car_01_left);
	Ally* ally = new Ally(spr_ally_01);

	map->start();
	player->start();
	car->start();
	ally->start();

	while (true)
	{
		player->update();
		//map->draw();
	}



	system("pause > 0");

	return 0;
}