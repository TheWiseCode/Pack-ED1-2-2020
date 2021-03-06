// ---------------------------------------------------------------------------

#pragma hdrstop

#include "ULista.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

Lista::Lista() {
	ptr_lista = NULL;
	longi = 0;
}

Nodo* Lista::fin() {
	if (!vacia())
		return ptr_lista->ant;
	else
		throw 100;
}

Nodo* Lista::primero() {
	return ptr_lista;
}

Nodo* Lista::siguiente(Nodo* P) {
	if (vacia())
		throw 100;
	else if (P->sig == primero())
		throw 200;
	else
		return P->sig;
}

Nodo* Lista::anterior(Nodo* P) {
	if (vacia())
		throw 100;
	else if (P->ant == fin())
		throw 200;
	else
		return P->ant;
}

bool Lista::vacia() {
	return longi == 0;
}

int Lista::recupera(Nodo* P) {
	if (!vacia())
		return P->elem;
	else
		throw 100;
}

int Lista::longitud() {
	return longi;
}

void Lista::inserta(Nodo* P, int e) {
	Nodo* nuevo = new Nodo;
	nuevo->ant = NULL;
	nuevo->elem = e;
	nuevo->sig = NULL;
	if (vacia()) {
		nuevo->ant = nuevo;
		nuevo->sig = nuevo;
		ptr_lista = nuevo;
		longi = 1;
	}
	else {
		if (P == primero() || longi == 1) {
			nuevo->sig = P;
			nuevo->ant = fin();
			ptr_lista = nuevo;
			P->ant = ptr_lista;
			fin()->sig = ptr_lista;
		}
		else {
			Nodo* ant = P->ant;
			ant->sig = nuevo;
			nuevo->ant = ant;
			nuevo->sig = P;
			P->ant = nuevo;
		}
		longi++;
	}
}

void Lista::suprime(Nodo* P) {
	if (!vacia()) {
		if (longi == 1)
			ptr_lista = NULL;
		else if (P == primero()) {
			Nodo* fi = fin();
			ptr_lista = ptr_lista->sig;
			ptr_lista->ant = fi;
			delete(P);
		}
		else if (P == fin()) {
			Nodo* pen = fin()->ant;
			pen->sig = ptr_lista;
			ptr_lista->ant = pen;
			delete(P);
		}
		else {
			Nodo* ant = P->ant;
			Nodo* sig = P->sig;
			ant->sig = sig;
			sig->ant = ant;
		}
		longi--;
	}
	else
		throw 100;
}

void Lista::modifica(Nodo* P, int e) {
	if (!vacia())
		P->elem = e;
	else
		throw 100;
}

string Lista::to_str() {
	Nodo* aux = ptr_lista;
	cout << "[";
	for (int i = 0; i < longi; i++) {
		cout << aux->elem;
		if (i < longi - 1)
			cout << ",";
		aux = aux->sig;
	}
	cout << "]" << endl;
	return "";
}

void Lista::mostrar() {
	Nodo* aux = ptr_lista;
	cout << "-------------------------------------\n";
	for (int i = 0; i < longi; i++) {
		cout << "ant: " << aux->ant << ",";
		cout << "dir: " << aux << ",";
		cout << "elem: " << aux->elem << ",";
		cout << "sig: " << aux->sig << endl;
		aux = aux->sig;
	}
	cout << "-------------------------------------\n";
}
