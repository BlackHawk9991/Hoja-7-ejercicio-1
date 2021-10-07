#pragma once
#include "Persona.h"
#include "Bus.h"
#include "Carro.h"
#include "Bicicleta.h"
#include <vector>

class Juego {
private:
	Persona* persona;
	vector<Bus*> buses;
	vector<Carro*> carros;
	vector<Bicicleta*> bicicletas;
	bool victoria;
public:
	Juego() {
		victoria = true;
		persona = new Persona(30, 26);
		for (int i = 0; i < 1; i++) {
			aBus();
		}
		for (int i = 0; i < 1; i++) {
			aCarro();
		}
		for (int i = 0; i < 2; i++) {
			aBicicleta();
		}
	}
	
	~Juego() {}

	void aBus() {
		buses.push_back(new Bus);
	}

	void aCarro() {
		carros.push_back(new Carro);
	}

	void aBicicleta() {
		bicicletas.push_back(new Bicicleta);
	}

	//Algoritmo de movimiento para todas las clases
	void borrarTodo() {
		persona->borrar();
		for (int i = 0; i < buses.size(); i++) {
			buses[i]->borrar();
		}
		for (int i = 0; i < carros.size(); i++) {
			carros[i]->borrar();
		}
		for (int i = 0; i < bicicletas.size(); i++) {
			bicicletas[i]->borrar();
		}
	}

	void moverTodo() {
		for (int i = 0; i < carros.size(); i++) {
			carros[i]->movervehiculo();

		}
		for (int i = 0; i < buses.size(); i++) {
			buses[i]->movervehiculo();
		}
		for (int i = 0; i < bicicletas.size(); i++) {
			bicicletas[i]->movervehiculo();
		}
	}

	void dibujarTodo() {
		persona->dibujar();
		for (int i = 0; i < buses.size(); i++) {
			buses[i]->dibujar();
		}
		for (int i = 0; i < carros.size(); i++) {
			carros[i]->dibujar();
		}
		for (int i = 0; i < bicicletas.size(); i++) {
			bicicletas[i]->dibujar();
		}
	}
	
	Persona* getPersona() {
		return persona;
	}

	bool getVictoria() { return victoria; }
	void setVictoria(int v) { victoria = v; }

	void ambas_colisiones() {
		colision_bus();
		colision_carro();
	}

	void colision_carro() {
		for (int i = 0; i < carros.size(); i++) {
			if (carros[i]->getRectangle().IntersectsWith(persona->getRectangle())) {
				persona->borrarVida();
				victoria = false;
			}
		}
	}

	void colision_bus() {
		for (int i = 0; i < buses.size(); i++) {
			if (buses[i]->getRectangle().IntersectsWith(persona->getRectangle())) {
				persona->borrarVida();
				victoria = false;
			}
		}
	}
	
	void limites() {
		l_bus();
		l_carro();
		l_bicicleta();
	}
	
	void l_bicicleta() {
		for (int i = 0; i < bicicletas.size(); i++) {
			if (bicicletas[i]->getX() <= 3) {
				bicicletas.erase(bicicletas.begin() + i);
				aBicicleta();
			}
		}
	}

	void l_carro() {
		for (int i = 0; i < carros.size(); i++) {
			if (carros[i]->getX() >= 46) {
				carros.erase(carros.begin() + i);
				aCarro();
			}
		}
	}
	
	void l_bus() {
		for (int i = 0; i < buses.size(); i++) {
			if (buses[i]->getX() <= 3) {
				buses.erase(buses.begin() + i);
				aBus();
			}
		}
	}
};