#pragma once
#include "Terrestre.h"

int p[2] = { 5, 13 };

class Bus : public Terrestre {
public:
	Bus() : Terrestre() {
		x = 36;
		y = p[rand() % 2];
		dx = -1;
		ancho = 20;
		alto = 4;
	}

	//Algoritmo de movimiento
	void borrar() {
        Console::SetCursorPosition(x, y);         cout << "                    ";
		Console::SetCursorPosition(x, y + 1);     cout << "                    ";
		Console::SetCursorPosition(x, y + 2);     cout << "                    ";
		Console::SetCursorPosition(x, y + 3);     cout << "                    ";
	}

	void dibujar() {
		Console::ForegroundColor = ConsoleColor::Green;
		Console::SetCursorPosition(x, y);     cout << "  ________________  ";
		Console::SetCursorPosition(x, y + 1); cout << " _/_|[][][][][][] | ";
		Console::SetCursorPosition(x, y + 2); cout << "(                 | ";
		Console::SetCursorPosition(x, y + 3); cout << " =--OO----------OO-=";
	}
};