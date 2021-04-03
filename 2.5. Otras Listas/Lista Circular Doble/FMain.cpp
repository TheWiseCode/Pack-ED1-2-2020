#include <iostream>
#include <string>
#include "ULista.h"

using namespace std;

int main() {
	try {
		Lista* list = new Lista();
		list->inserta(NULL, 10);
		list->inserta(list->fin(), 11);
		list->inserta(list->fin(), 55);
		list->inserta(list->primero(), 66);
		list->to_str();
		list->suprime(list->siguiente(list->fin()));
		list->to_str();
		list->mostrar();
	}
	catch (int e) {
		if (e == 100)
			cout << "Lista Vacia\n";
		else if (e == 200)
			cout << "Direccion Erronea\n";
	}
	system("pause");
	return 0;
}
