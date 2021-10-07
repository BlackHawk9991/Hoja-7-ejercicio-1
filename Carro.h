#pragma once
#include "Terrestre.h"

int  velocidad[3] = { 2,3,4 };
int posicion[2] = { 2, 9 };

class Carro : public Terrestre {
public:
	Carro() : Terrestre(){
		x = 4;
		y = posicion[rand() % 2];
		dx = velocidad[rand() % 3];
		ancho = 11;
		alto = 3;
	}

	~Carro(){}

	//Algoritmo movimiento

	void borrar(){
		Console::SetCursorPosition(x, y);     cout << "           ";
		Console::SetCursorPosition(x, y + 1); cout << "           ";
		Console::SetCursorPosition(x, y + 2); cout << "           ";
	}

	void dibujar() {
		Console::ForegroundColor = ConsoleColor::White;
		Console::SetCursorPosition(x, y);     cout << "_______|~\\_";  
		Console::SetCursorPosition(x, y + 1); cout << "[______|_|-";
		Console::SetCursorPosition(x, y + 2); cout << "(_)   (_)  ";
	}
};