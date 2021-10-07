#pragma once
#include <iostream>

using namespace std;
using namespace System;
using namespace System::Drawing;

class Terrestre {
protected: 
int x; 
int y; 
int dx; 
int dy; 
int ancho;
int alto;

public:
	//Constructor de los vehiculos
	Terrestre() {}

	//Constructor de la persona
	Terrestre(int x, int y) {
		this->x = x;
		this->y = y;
	}

	~Terrestre(){}

	void movervehiculo(){
		if (x <= 3 || x + ancho >= 57)dx = 0;
		x += dx;
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho, alto);
	}

	void setX(int v){x=v;}
	void setY(int v) { y = v; }
	int getX() { return x; }
	int getY() { return y; }
};