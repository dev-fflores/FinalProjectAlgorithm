#pragma once
#include <string>

using namespace std;

struct Vector2
{
	float x, y;
};

struct Color
{
	int r, g, b;
};

int getRand(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void printArray(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

// Función para generar códigos ANSI RGB
std::string setForegroundColor(Color color) {
	return "\033[38;2;" + std::to_string(color.r) + ";" + std::to_string(color.g) + ";" + std::to_string(color.b) + "m";
}

// Función para cambiar el fondo
std::string setBackgroundColor(Color color) {
	return "\033[48;2;" + std::to_string(color.r) + ";" + std::to_string(color.g) + ";" + std::to_string(color.b) + "m";
}

// Resetear colores
std::string resetColors() {
	return "\033[0m";
}