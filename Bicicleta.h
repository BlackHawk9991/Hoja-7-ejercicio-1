#pragma once
#include "Terrestre.h"

int l[3] = { 18, 21, 23};

class Bicicleta : public Terrestre {
public:
	Bicicleta() : Terrestre (){
		x = 50;
		y = l[rand() % 3];
		dx= -1;
		ancho = 6;
		alto = 2;
	}

	~Bicicleta() {}

	//Algoritmo de movimiento 
	void borrar(){
		Console::SetCursorPosition(x, y);     cout << "      ";
		Console::SetCursorPosition(x, y + 1); cout << "      ";
	}

	void dibujar (){
		Console::ForegroundColor= ConsoleColor::Red;
		Console::SetCursorPosition(x, y);     cout << " /_.. ";
		Console::SetCursorPosition(x, y + 1); cout << "(o)(o)";
	}
};
