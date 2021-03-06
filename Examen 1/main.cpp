#include <iostream>
#include "UConjS.h"
#include "UPoliV.h"
#include "UListaP.h"

using namespace std;

void unionC(ConjuntoS * a, ConjuntoS * b, ConjuntoS * &c);
void diferenciaSim(ConjuntoS * a, ConjuntoS * b, ConjuntoS * &c);
void interseccion(ConjuntoS * a, ConjuntoS * b, ConjuntoS * c, ConjuntoS* &d);

void punto_minimo(PoliV &fx, float a, float b);

/*
 ConjuntoS* a;
 ConjuntoS* b;
 ConjuntoS* c;
 ConjuntoS* d;
 */

void menu();

int main() {
	/*
	 CSMemoria* mem = new CSMemoria();
	 a = new ConjuntoS(mem);
	 b = new ConjuntoS(mem);
	 c = new ConjuntoS(mem);
	 d = new ConjuntoS(mem);
	 a->inserta(7);
	 a->inserta(2);
	 a->inserta(5);
	 a->inserta(3);
	 a->inserta(6);
	 b->inserta(4);
	 b->inserta(3);
	 b->inserta(2);
	 b->inserta(7);
	 b->inserta(1);
	 c->inserta(3);
	 c->inserta(6);
	 c->inserta(4);
	 c->inserta(7);
	 interseccion(a, b, c, d);
	 cout << a->to_str() << endl;
	 cout << b->to_str() << endl;
	 cout << c->to_str() << endl;
	 cout << d->to_str() << endl; */
	/* PoliV p;
	 p.poner_termino(5, 3);
	 p.poner_termino(-6, 1);
	 punto_minimo(p, -1, 1);
	 cout << p.to_str() << endl; */
	menu();
	system("pause");
	return 0;
}

void menu() {
	ListaP* list;
	int opcion;
	do {
		cout << "1.Crear Lista" << endl;
		cout << "2.Insertar Final" << endl;
		cout << "3.Mostrar" << endl;
		cout << "4.Salir" << endl;
		cout << "Opcion: ";
		cin >> opcion;
		if (opcion == 1) {
			list = new ListaP();
		}
		else if (opcion == 2) {
			int elem;
			cout << "Elemento: ";
			cin >> elem;
			list->inserta_ultimo(elem);
		}
		else if (opcion == 3) {
			cout << list->to_str() << endl;
		}
		else if (opcion == 4) {
			cout << "saliendo" << endl;
		}
		system("pause");
		system("cls");
	}
	while (opcion != 4);
}

void punto_minimo(PoliV &fx, float a, float b) {
	float minY = fx.evaluar(a);
	float minX = a;
	float au = 0.0001;
	float x = a;
	while (x < b) {
		float y = fx.evaluar(x);
		if (y < minY) {
			minY = y;
			minX = x;
		}
		x += au;
	}
	cout << "Punto minimo: (" << minX << "," << minY << ")\n";
}

void unionC(ConjuntoS * a, ConjuntoS * b, ConjuntoS * &c) {
	ConjuntoS* aux = new ConjuntoS();
	while (!a->vacio()) {
		int elem = a->muestrea();
		c->inserta(elem);
		a->suprime(elem);
		aux->inserta(elem);
	}
	while (!aux->vacio()) {
		int elem = aux->muestrea();
		a->inserta(elem);
		aux->suprime(elem);
	}
	while (!b->vacio()) {
		int elem = b->muestrea();
		if (!c->pertenece(elem))
			c->inserta(elem);
		b->suprime(elem);
		aux->inserta(elem);
	}
	while (!aux->vacio()) {
		int elem = aux->muestrea();
		b->inserta(elem);
		aux->suprime(elem);
	}
}

// A - B // todo x Perteneca a A y no Pertenece a B
// B - A // todo x Perteneca a B y no Pertenece a A
void diferenciaSim(ConjuntoS * a, ConjuntoS * b, ConjuntoS * &c) {
	ConjuntoS* aux = new ConjuntoS();
	while (!a->vacio()) {
		int elem = a->muestrea();
		if (a->pertenece(elem) && !b->pertenece(elem))
			c->inserta(elem);
		a->suprime(elem);
		aux->inserta(elem);
	}
	while (!aux->vacio()) {
		int elem = aux->muestrea();
		a->inserta(elem);
		aux->suprime(elem);
	}
	while (!b->vacio()) {
		int elem = b->muestrea();
		if (b->pertenece(elem) && !a->pertenece(elem))
			c->inserta(elem);
		b->suprime(elem);
		aux->inserta(elem);
	}
	while (!aux->vacio()) {
		int elem = aux->muestrea();
		b->inserta(elem);
		aux->suprime(elem);
	}
}

void interseccion(ConjuntoS * a, ConjuntoS * b, ConjuntoS * c, ConjuntoS* &d) {
	ConjuntoS* aux = new ConjuntoS();
	while (!a->vacio()) {
		int elem = a->muestrea();
		if (a->pertenece(elem) && b->pertenece(elem) && c->pertenece(elem))
			d->inserta(elem);
		a->suprime(elem);
		aux->inserta(elem);
	}
	while (!aux->vacio()) {
		int elem = aux->muestrea();
		a->inserta(elem);
		aux->suprime(elem);
	}
}
