
#include "pch.h"
#include <conio.h>
#include "GameObjects.h"
#include "FinalProjectAlgorithm.h"

int centerText(string text) {
    return (SCREEN_WIDTH / 2) - (text.length() / 2);
}
void printOptionsMainMenu(string titulo, string espacio, string jugar, string tematica, string instrucciones, string credito, string seleccionar, string salir) {

    Console::SetCursorPosition(centerText(titulo), 20);
    cout << titulo;

    Console::SetCursorPosition(centerText(espacio), 21);
    cout << espacio;

    Console::SetCursorPosition(centerText(jugar), 22);
    cout << jugar;

    Console::SetCursorPosition(centerText(espacio), 23);
    cout << espacio;

    Console::SetCursorPosition(centerText(tematica), 24);
    cout << tematica;

    Console::SetCursorPosition(centerText(espacio), 25);
    cout << espacio;

    Console::SetCursorPosition(centerText(instrucciones), 26);
    cout << instrucciones;

    Console::SetCursorPosition(centerText(espacio), 27);
    cout << espacio;

    Console::SetCursorPosition(centerText(credito), 28);
    cout << credito;

    Console::SetCursorPosition(centerText(espacio), 29);
    cout << espacio;

    Console::SetCursorPosition(centerText(salir), 30);
    cout << salir;

    Console::SetCursorPosition(centerText(espacio), 31);
    cout << espacio;

    Console::SetCursorPosition(centerText(seleccionar), 32);
    cout << seleccionar;


}

int showMainMenu() {
    int elegir;

    string titulo = "nombre del juego\n";
    string jugar = "1. Jugar\n";
    string tematica = "2. Tematica\n";
    string instrucciones = "3. Instrucciones\n";
    string credito = "4. Credito\n";
    string salir = "5. Salir\n";
    string seleccionar = "Seleccionar opcion: ";
    string espacio = "    ";

    do {
        system("cls");

        printOptionsMainMenu(titulo, espacio, jugar, tematica, instrucciones, credito, seleccionar, salir);
        Console::CursorVisible = true;
        cin >> elegir;

    } while (elegir < 1 || elegir > 5);
    return elegir;
}




void gamexddd() {
	// Mover al jugador con las teclas W, A, S, D en la consola usando Conole::SetCursorPosition
	Map* map = new Map(spr_map_01);

	Player* player = new Player(100, { 70,20 }, 10, spr_player);

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

}

void showGameMenu() {
    int choose = 0;

    while (1) {
        choose = showMainMenu();
        system("cls");

        switch (choose) {
        case 1:
            gamexddd();
            system("cls");
            break;
        case 2:
            cout << "El problema del trafico en el Peru es muy grave, por ello se creo este juego\n";
            cout << "el cual tiene como proposito ayudar o intentar que las personas\n";
            cout << "tomen conciencia acerca lo que pasa\n";
            cout << "tambien para que se pueda disminuir el trafico\n";
            cout << "y pueda ser un pais tranquilo y armonioso\n";
            system("pause > 0");
            Console::ReadKey();
            break;
        case 3:
            cout << "Eres un Policia que hace bien su trabajo\n";
            cout << "y de pronto vez que los carros empiezan a actuar mal y \n";
            cout << "se pasan las luz roja, hacen caos, desastres, entonces decides tomar orden\n\n";
            cout << "Puedes moverte arriba, abajo, izquierda, derecha\n";
            cout << "cada vez que te acercas a un coche apretando una tecla x detendras a un coche\n";
            cout << "solo podras detener al coche si este comete una infraccion de transito \n";
            cout << "si necesitas ayuda puedes llamar a tus mascotas para que el trabajo se haga mas facil\n";
            cout << "si se te pasan dos carros pierdes un corazon, si pierdes los 3 corazones pierdes la partida\n";
            cout << "al atrapar un carro ganas puntos\n";
            cout << "llegando a cierta cantidad de puntos pasas de nivel\n";
            cout << "DIVIERTETE\n";
            system("cls");
            break;
        case 4:
            cout << "Frank Flores\n\n";
            cout << "Cielo Atencio\n\n";
            cout << "Victor Hidago\n\n";

            system("cls");
            break;

        case 5:
            exit(0);
        }
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