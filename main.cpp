#include <conio.h>
#include "Juego.h"

int main() {
	srand(time(NULL));
	Console::SetWindowSize(60, 30);
	char tecla;
	Juego* j = new Juego();
	while (true) {
		Console::CursorVisible = false;
		j->borrarTodo();
		j->ambas_colisiones();
		j->limites();
		if (j->getPersona()->getVida() == 0) { break; }
		if (_kbhit()) {
			tecla = _getch();
			tecla = toupper(tecla);
			j->getPersona()->mover(tecla);
		}
		j->moverTodo();
		j->dibujarTodo();
		_sleep(100);
	}

	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t     >>-FIN DEL JUEGO-<<";

	_getch();
	return 0;
}