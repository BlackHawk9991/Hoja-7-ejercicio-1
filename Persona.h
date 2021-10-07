#pragma once
#include "Terrestre.h"

class Persona : public Terrestre {
private:
	int vida ;
public:
	Persona(int x , int y ) : Terrestre(x, y){
		vida = 1;
		dx = 2;
		dy = 2;
		ancho = 4;
		alto = 2;
	}
	
	~Persona() {}

	//Algoritmo de movimiento
	void borrar (){
		Console::SetCursorPosition(x, y);		cout << "    ";
		Console::SetCursorPosition(x, y + 1);	cout << "    ";
	}

	void mover(char indice){
		switch (indice){
     	case 'A':
	    	if (x  >= 3)x  -= dx; break;
		case 'D':
	     	if (x  + ancho <= 57)x  += dx; break;
		case 'W':
			if (y >= 2)y -= dy; break;
		case 'S':
		     if (y  + alto <= 27)y  += dy; break;
		}
	}
	void dibujar(){
		Console::ForegroundColor = ConsoleColor::Green;
		Console::SetCursorPosition(x, y);		cout << char(254) << char(254) << char(254) << char(254);
		Console::SetCursorPosition(x, y + 1);	cout << char(254) << char(254) << char(254) << char(254);
	}

	int getVida() { return vida; }
	void borrarVida(){vida = 0;}	
};