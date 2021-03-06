#include <iostream>
#include <string>
#include "UPoliS.h"
#include "UPoliP.h"
#include "UPoliL.h"
#include "UPoliLP.h"
#include "UPoliV.h"

using namespace std;

void menuS();
void menuV();
void menuP();
void menuL();

bool sonOpuestos(PoliP* a, PoliP* b) {
	PoliP* suma = new PoliP();
	for (int i = 1; i <= a->numero_terminos(); i++) {
		int exp = a->exponente(i);
		int coef = a->coeficiente(exp);
		suma->poner_termino(coef, exp);
	}
	for (int i = 1; i <= b->numero_terminos(); i++) {
		int exp = b->exponente(i);
		int coef = b->coeficiente(exp);
		suma->poner_termino(coef, exp);
	}
	return suma->es_cero();
}

bool sonIguales(PoliP* a, PoliP* b) {
	PoliP* suma = new PoliP();
	suma->sumar(a, b, suma);
	return suma->es_cero();
	for (int i = 1; i <= a->numero_terminos(); i++) {
		int exp = a->exponente(i);
		int coef = a->coeficiente(exp);
		suma->poner_termino(coef, exp);
	}
	for (int i = 1; i <= b->numero_terminos(); i++) {
		int exp = b->exponente(i);
		int coef = b->coeficiente(exp);
		suma->poner_termino(-coef, exp);
	}
	return suma->es_cero();
}

float area(PoliP fx, float a, float b);
void punto_minimo(PoliP fx, float a, float b);

int main() {
	/* PoliP p, r;
	 p.poner_termino(2, 0);
	 r.poner_termino(1, 1);
	 cout << area(p, -2, 2) << endl; ;
	 cout << area(r, -1, 1) << endl; ; */
	PoliP p;
	p.poner_termino(-1, 2);
	p.poner_termino(1, 3);
	cout << p.to_str() << endl;
	// cout << p.evalua(0.65) << endl;
	punto_minimo(p, 0, 1);
	system("pause");
	return 0;
}

void punto_minimo(PoliP fx, float a, float b) {
	float minY = fx.evalua(a);
	float minX = a;
	float x = a;
	while (x <= b) {
		float evalua = fx.evalua(x);
		if (evalua < minY) {
			minY = evalua;
			minX = x;
		}
		cout << x << " , " << evalua << endl;
		x = x + 0.001;
	}
	cout << "Punto minimo: (" << minX << "," << minY << ")" << endl;
}

float area(PoliP fx, float a, float b) {
	float evaluaA = fx.evalua(a);
	float evaluaB = fx.evalua(b);
	return abs(evaluaB) + abs(evaluaA);
	/*
	 formula de la integral -> abs(evaluaB - evaluaA)
	 pero asi no saldria el segundo ejemplo
	 */
}

void menuS() {
	CSMemoria* mem;
	PoliS* p;
	int opcion;
	do {
		cout << "1.Crear Memoria\n";
		cout << "2.Pedir espacio\n";
		cout << "3.Liberar espacio\n";
		cout << "4.Crear Polinomio\n";
		cout << "5.Poner Termino\n";
		cout << "6.Mostrar Polinomio\n";
		cout << "7.Derivar\n";
		cout << "8.Mostrar Memoria\n";
		cout << "9.Salir\n";
		cout << "Opcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1: {
				mem = new CSMemoria();
			} break;
		case 2: {
				string id;
				cin.ignore();
				cout << "IDs: ";
				getline(cin, id);
				mem->new_espacio(id);
			} break;
		case 3: {
				int dir;
				cout << "Direccion a liberar: ";
				cin >> dir;
				mem->delete_espacio(dir);
			} break;
		case 4: {
				p = new PoliS(mem);
			} break;
		case 5: {
				int coef, exp;
				cout << "Coef: ";
				cin >> coef;
				cout << "Exp: ";
				cin >> exp;
				p->poner_termino(coef, exp);
			} break;
		case 6: {
				cout << p->to_str() << endl;
			} break;
		case 7: {
				p->derivar();
			} break;
		case 8: {
				mem->mostrar();
			} break;
		}
		system("pause");
		system("cls");
	}
	while (opcion != 9);
}

void menuV() {
	PoliV* p;
	int opcion;
	do {
		cout << "1.Crear Polinomio\n";
		cout << "2.Poner Termino\n";
		cout << "3.Mostrar Polinomio\n";
		cout << "4.Derivar\n";
		cout << "5.Salir\n";
		cout << "Opcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1: {
				p = new PoliV();
			} break;
		case 2: {
				int coef, exp;
				cout << "Coef: ";
				cin >> coef;
				cout << "Exp: ";
				cin >> exp;
				p->poner_termino(coef, exp);
			} break;
		case 3: {
				cout << p->to_str() << endl;
			} break;
		case 4: {
				p->derivar();
			} break;
		}
		system("pause");
		system("cls");
	}
	while (opcion != 5);
}

void menuP() {
	PoliP* p;
	int opcion;
	do {
		cout << "1.Crear Polinomio\n";
		cout << "2.Poner Termino\n";
		cout << "3.Mostrar Polinomio\n";
		cout << "4.Derivar\n";
		cout << "5.Salir\n";
		cout << "Opcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1: {
				p = new PoliP();
			} break;
		case 2: {
				int coef, exp;
				cout << "Coef: ";
				cin >> coef;
				cout << "Exp: ";
				cin >> exp;
				p->poner_termino(coef, exp);
			} break;
		case 3: {
				cout << p->to_str() << endl;
			} break;
		case 4: {
				p->derivar();
			} break;
		}
		system("pause");
		system("cls");
	}
	while (opcion != 5);
}

void menuL() {
	PoliL* p; // PoliLP* p;
	int opcion;
	do {
		cout << "1.Crear Polinomio\n";
		cout << "2.Poner Termino\n";
		cout << "3.Mostrar Polinomio\n";
		cout << "4.Derivar\n";
		cout << "5.Salir\n";
		cout << "Opcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1: {
				p = new PoliL(); // p = new PoliLP();
			} break;
		case 2: {
				int coef, exp;
				cout << "Coef: ";
				cin >> coef;
				cout << "Exp: ";
				cin >> exp;
				p->poner_termino(coef, exp);
			} break;
		case 3: {
				cout << p->to_str() << endl;
			} break;
		case 4: {
				p->derivar();
			} break;
		}
		system("pause");
		system("cls");
	}
	while (opcion != 5);
}
