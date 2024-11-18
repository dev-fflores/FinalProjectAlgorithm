
#include "pch.h"
#include <conio.h>
#include "GameObjects.h"
#include "FinalProjectAlgorithm.h"
#include "Menu.h"

void inicializar_juego() {
	// Mover al jugador con las teclas W, A, S, D en la consola usando Conole::SetCursorPosition
	Map* map = new Map(spr_map_01);

	UI* ui = new UI(ui_box, { 100, 36 }, 53, 10, "GAME", "Frank", "Hello", 1, 0);

	Player* player = new Player({ 0, 0, 0 }, { 70,20 }, 10, spr_player, map->map);

	Car* car_01 = new Car(spr_car_01_left, 9, 3, { 149, 18 }, { 255, 0, 0 }, map->map, { -1, 1 }, 0.15f);

	/*Car* car_02 = new Car(spr_car_02_left, 9, 3, {149, 21}, {255, 0, 0}, map->map, {-1, 1}, 0.15f);
	Car* car_03 = new Car(spr_car_03_left, 9, 3, {149, 24}, {255, 0, 0}, map->map, {-1, 1}, 0.15f);
	Car* car_04 = new Car(spr_car_04_left, 9, 3, {149, 27}, {255, 0, 0}, map->map, {-1, 1}, 0.15f);*/

	Car* car_02 = new Car(spr_car_01_right, 9, 3, { 2, 18 }, { 0, 255, 0 }, map->map, { 1, -1 }, 0.15f);
	/*Car* car_06 = new Car(spr_car_02_right, 9, 3, {2, 21}, { 0, 255, 0 }, map->map, { 1, -1 }, 0.15f);
	Car* car_07 = new Car(spr_car_03_right, 9, 3, {2, 24}, { 0, 255, 0 }, map->map, { 1, -1 }, 0.15f);
	Car* car_08 = new Car(spr_car_04_right, 9, 3, {2, 27}, { 0, 255, 0 }, map->map, { 1, -1 }, 0.15f);*/

	Car* car_03 = new Car(spr_car_01_up, 5, 4, { 81, 45 }, { 0, 0, 255 }, map->map, { 0, 1 }, 0.15f);
	/*Car* car_10 = new Car(spr_car_02_up, 5, 4, {75, 45}, { 0, 0, 255 }, map->map, { 0, 1 }, 0.15f);
	Car* car_11 = new Car(spr_car_03_up, 5, 4, {81, 45}, { 0, 0, 255 }, map->map, { 0, 1 }, 0.15f);
	Car* car_12 = new Car(spr_car_04_up, 5, 4, {81, 45}, { 0, 0, 255 }, map->map, { 0, 1 }, 0.15f);*/

	Car* car_04 = new Car(spr_car_02_down, 5, 4, { 81, 1 }, { 0, 0, 0 }, map->map, { 0, -1 }, 0.15f);
	Car* car_05 = new Car(spr_car_03_down, 5, 4, { 74, 1 }, { 0, 0, 0 }, map->map, { 0, -1 }, 0.15f);

	/*Car* car_02 = new Car(spr_car_02_left, ConsoleColor::Green, map->map);
	Car* car_03 = new Car(spr_car_03_left, ConsoleColor::Blue, map->map);
	Car* car_04 = new Car(spr_car_04_left, ConsoleColor::Yellow, map->map);
	Car* car_05 = new Car(spr_car_05_left, ConsoleColor::Magenta, map->map);*/

	Ally* ally_01 = new Ally(spr_ally_01, { 255, 0, 0 });
	Ally* ally_02 = new Ally(spr_ally_02, { 0, 0, 255 });
	Ally* ally_03 = new Ally(spr_ally_03, { 0, 255, 0 });
	Ally* ally_04 = new Ally(spr_ally_04, { 0, 255, 0 });
	Ally* ally_05 = new Ally(spr_ally_05, { 0, 0, 255 });

<<<<<<< HEAD
	TrafficLight* trafficlight01 = new TrafficLight(spr_traffic_light, { 80, 30 }, { 0, 0, 0 });
	TrafficLight* trafficlight02 = new TrafficLight(spr_traffic_light, { 20, 30 }, { 0, 0, 0 });
=======
	TrafficLight* trafficlight01 = new TrafficLight(spr_traffic_light, { 80, 30 }, { 0, 0, 0 } );
	TrafficLight* trafficlight02 = new TrafficLight(spr_traffic_light, { 20, 30 }, { 0, 0, 0 } );

	//TrafficLight* traffic_lights = new TrafficLight();

	
>>>>>>> develop

	//Car* cars[5] = { car_01, car_02, car_03, car_04, car_05 };
	Car* cars[5] = { car_01, car_02 , car_03 , car_04 , car_05, };
	Ally* allies[5] = { ally_01, ally_02, ally_03, ally_04, ally_05 };
	TrafficLight* traffic_lights[2] = { trafficlight01, trafficlight02 };

	Game* game = new Game(player, allies, traffic_lights, cars, map, ui);


	game->start();

	while (game->isRunning())
	{
		game->update();
	}

}




int main()
{
	srand(time(NULL));
	Console::SetWindowSize(160, 50);

	showGameMenu();




	system("pause > 0");

	return 0;
}