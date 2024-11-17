
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

	Player* player = new Player({ 0, 0, 0 }, {70,20}, 10, spr_player, map->map);

	Car* car_01 = new Car(spr_car_01_left, {80, 4}, {255, 0, 0}, map->map, {0, 1}, 1.0f);
	Car* car_02 = new Car(spr_car_02_left, {76, 4}, { 0, 255, 0 }, map->map, { 0, 1 }, 1.0f);
	Car* car_03 = new Car(spr_car_01_up, {70, 4}, { 0, 0, 255 }, map->map, { 0, 1 }, 0.15f);
	/*Car* car_02 = new Car(spr_car_02_left, ConsoleColor::Green, map->map);
	Car* car_03 = new Car(spr_car_03_left, ConsoleColor::Blue, map->map);
	Car* car_04 = new Car(spr_car_04_left, ConsoleColor::Yellow, map->map);
	Car* car_05 = new Car(spr_car_05_left, ConsoleColor::Magenta, map->map);*/
	
	Ally* ally_01 = new Ally(spr_ally_01, { 255, 0, 0 });
	Ally* ally_02 = new Ally(spr_ally_02, { 0, 0, 255 });
	Ally* ally_03 = new Ally(spr_ally_03, { 0, 255, 0 });
	Ally* ally_04 = new Ally(spr_ally_04, { 0, 255, 0 });
	Ally* ally_05 = new Ally(spr_ally_05, { 0, 0, 255 });

	TrafficLight* traffic_lights = new TrafficLight();

	//Car* cars[5] = { car_01, car_02, car_03, car_04, car_05 };
	Car* cars[5] = { car_01, car_02 , car_03 , car_02 , car_03 };
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