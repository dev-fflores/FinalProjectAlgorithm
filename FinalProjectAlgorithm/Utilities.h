#pragma once
using namespace std;

struct Vector2
{
	int x, y;
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
