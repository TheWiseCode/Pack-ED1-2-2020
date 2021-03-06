#include <iostream>
#include "UColaL.h"
#include "UColaV1.h"
#include "UColaV2.h"
#include "UColaV3.h"
#include "UColaP.h"
#include "UColaS.h"

#include "UDicolaL.h"
#include "UDicolaD.h"
#include "UDicolaV2.h"
#include "UDicolaV3.h"
#include "UDicolaP.h"

#include "UColaPrioridad.h"

using namespace std;

void menu();

string mostrar(ColaV3 *c) {
	string s = "<<";
	int e;
	ColaV3* aux = new ColaV3();
	while (!c->vacia()) {
		c->sacar(e);
		aux->poner(e);
		s += to_string(e);
		if (!c->vacia())
			s += ",";
	}
	while (!aux->vacia()) {
		aux->sacar(e);
		c->poner(e);
	}
	return s + "<<";
}

void invertir(ColaV3 *c) {
	if (!c->vacia()) {
		int e;
		c->sacar(e);
		invertir(c);
		c->poner(e);
	}
}

int main() {
	Dicola* d = new Dicola();
	d->poner_frente(2);
	d->poner_frente(3);
	d->poner_frente(10);
	/* d->poner(20);
	 d->mostrar();
	 int y;
	 d->sacar(y);
	 d->sacar_final(y);
	 d->sacar(y);
	 d->sacar_final(y);
	 d->sacar_final(y);
	 d->mostrar();
	 d->poner_frente(2);
	 d->poner_frente(3);
	 d->poner(5);
	 d->poner_frente(10);
	 d->poner(20); */
	d->mostrar();
	system("pause");
	return 0;
	ColaPrioridad* cp = new ColaPrioridad();
	cp->asignar_frec_prioridad(2, 1);
	cp->asignar_frec_prioridad(3, 2);
	cp->asignar_frec_prioridad(1, 3);
	// Cola prioridad 1
	cp->poner(1, 1);
	cp->poner(2, 1);
	cp->poner(4, 1);
	cp->poner(6, 1);
	cp->poner(7, 1);
	// Cola prioridad 2
	cp->poner(1, 2);
	cp->poner(2, 2);
	cp->poner(3, 2);
	cp->poner(6, 2);
	// Cola prioridad 3
	// cp->poner(1, 3);
	// cp->poner(5, 3);
	// cp->poner(7, 3);
	// cp->poner(8, 3);
	//
	cout << cp->to_str() << endl;
	/* while (!cp->vacia()) {
	 int e;
	 cp->sacar(e);
	 cout << "-----\n";
	 cout << cp->to_str() << endl;
	 cout << "-----\n";
	 // cout << e << " , ";
	 } */
	int x;
	cp->sacar(x);
	cp->sacar(x);
	cp->sacar(x);
	cp->sacar(x);
	cp->sacar(x);
	cout << endl;
	cout << cp->to_str() << endl;
	cp->sacar(x);
	cout << cp->to_str() << endl;
	system("pause");
	return 0;
}

void menu() {
	ColaV3* c;
	cout << "1. Crear cola" << endl;
	cout << "2. Poner en la cola" << endl;
	cout << "3. Mostrar Cola" << endl;
	cout << "4. Invertir Cola" << endl;
	cout << "5. Salir" << endl;
	bool sale = false;
	while (!sale) {
		int opcion;
		cout << "Opcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1:
			c = new ColaV3();
			break;
		case 2: {
				int e;
				cout << "Elemento: ";
				cin >> e;
				c->poner(e);
			} break;
		case 3: {
				cout << mostrar(c) << endl;
			} break;
		case 4: {
				invertir(c);
			} break;
		case 5:
			sale = true;
			break;
		}
	}
}
