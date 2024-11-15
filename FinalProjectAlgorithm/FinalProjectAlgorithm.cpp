
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

	Player* player = new Player(100, {70,20}, 10, spr_player, map->map);

	Car* car_01 = new Car(spr_car_01_left, ConsoleColor::Red);
	Car* car_02 = new Car(spr_car_01_left, ConsoleColor::Green);
	Car* car_03 = new Car(spr_car_01_left, ConsoleColor::Blue);
	Car* car_04 = new Car(spr_car_01_left, ConsoleColor::Yellow);
	Car* car_05 = new Car(spr_car_01_left, ConsoleColor::Magenta);


	Ally* ally_01 = new Ally(spr_ally_01, ConsoleColor::Red);
	Ally* ally_02 = new Ally(spr_ally_01, ConsoleColor::Green);
	Ally* ally_03 = new Ally(spr_ally_01, ConsoleColor::Blue);
	Ally* ally_04 = new Ally(spr_ally_01, ConsoleColor::Yellow);
	Ally* ally_05 = new Ally(spr_ally_01, ConsoleColor::Magenta);

	TrafficLight* traffic_lights = new TrafficLight();

	Car* cars[5] = { car_01, car_02, car_03, car_04, car_05 };
	Ally* allies[5] = { ally_01, ally_02, ally_03, ally_04, ally_05 };

	Game* game = new Game(player, allies, traffic_lights, cars, map);

	game->start();

	while (game->isRunning())
	{
		game->update();
	}

	



	system("pause > 0");

	return 0;
}