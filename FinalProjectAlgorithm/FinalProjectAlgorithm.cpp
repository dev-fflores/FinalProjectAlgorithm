#include "pch.h"
#include <iostream>
#include <conio.h>

using namespace System;
using namespace std;

int* generateMessage(int& size);
void printMessage(int* message, const int size);
bool isHungry(int* message, const int size);
bool isThirsty(int* message, const int size);
bool isInDanger(int* message, const int size);
int getRandomNumber(int min, int max);


int main() {
    srand(time(nullptr));

    int total_messages = 0, thirsty_counter = 0, hungry_counter = 0;
    char option;

    int* message;
    message = nullptr;
    
    int message_size = 0;

    do {
        cout << message_size;
        message = generateMessage(message_size);
        cout << message_size;

        printMessage(message,message_size);

        if (isHungry(message, message_size)) {
            cout << "Las personas tienen hambre!" << endl;
            hungry_counter++;
        }

        if (isThirsty(message, message_size)) {
            cout << "Las personas tienen sed!" << endl;
            thirsty_counter++;
        }

        if (isInDanger(message, message_size)) {
            cout << "Peligro!" << endl;
        }


        cout << "\nPresiona 'X' para salir o cualquier otra tecla para continuar: ";
        option = _getch();
        cout << endl << endl;

        total_messages++;
        delete[] message;

    } while (option != 'X' && option != 'x');

    cout << "\nReporte Final:" << endl;
    cout << "Total de mensajes procesados: " << total_messages << endl;
    cout << "Cantidad de veces que se solicito agua por calor: " << thirsty_counter << endl;
    cout << "Cantidad de veces que se solicito alimento por hambre: " << hungry_counter << endl;

    return 0;
}

int* generateMessage(int& size)
{
    int digits_to_fill[3] = { 0, 6, 7 };
    size = getRandomNumber(10, 20);
    int* message = new int[size];

    for (int i = 0; i < size; i++)
    {
        message[i] = digits_to_fill[getRandomNumber(0, 2)];
    }

    return message;
}

void printMessage(int* message, const int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "[" << message[i] << "]";
    }
    cout << endl;
}

bool isHungry(int* message, const int size)
{
    if (
        message[size - 1] == 7 &&
        message[size - 2] == 7 &&
        message[size - 3] == 7) {
        return true;
    }

    return false;
}

bool isThirsty(int* message, const int size)
{
    int code[3] = { 6,0,6 };
    int match_index = 0;

    for (int i = 0; i < size; i++)
    {
        if (message[i] == code[match_index]) {
            match_index++;
            if (match_index == 3) {
                return true;
            }
        }
        else if (message[i] == code[0]) {
            match_index = 1;
        }
        else {
            match_index = 0;
        }
    }

    return false;
}

bool isInDanger(int* message, const int size)
{
    for (int i = 0; i <= size - 3; i++)
    {
        if (message[i] == 6 && message[i + 1] == 6 && message[i + 2] == 6) {
            return true;
        }
    }

    return false;
}

int getRandomNumber(int min, int max)
{
    return min + rand() % (max - min + 1);
}
