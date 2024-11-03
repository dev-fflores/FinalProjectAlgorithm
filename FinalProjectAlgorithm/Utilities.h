#pragma once

struct Vector2
{
	float x, y;
};

int getRand(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void printArray(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
