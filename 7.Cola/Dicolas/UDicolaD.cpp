// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UDicolaD.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

Dicola::Dicola() {
	ini = fin = NULL;
}

bool Dicola::vacia() {
	return ini == NULL;
}

void Dicola::poner(int e) {
	NodoD* nuevo = new NodoD();
	nuevo->elemento = e;
	if (vacia()) {
		nuevo->ant = NULL;
		nuevo->sig = NULL;
		ini = nuevo;
		fin = nuevo;
	}
	else {
		NodoD* penultimo = fin;
		nuevo->sig = NULL;
		nuevo->ant = penultimo;
		penultimo->sig = nuevo;
		fin = nuevo;
	}
}

void Dicola::sacar(int &e) {
	if (!vacia()) {
		NodoD* x = ini;
		e = ini->elemento;
		if (ini == fin)
			ini = fin = NULL;
		else
			ini = ini->sig;
		delete(x);
	}
}

int Dicola::primero() {
	if (!vacia())
		return ini->elemento;
}

int Dicola::ultimo() {
	if (!vacia())
		return fin->elemento;
}

void Dicola::poner_frente(int e) {
	NodoD* nuevo = new NodoD();
	nuevo->elemento = e;
	if (vacia()) {
		// Aca se lo enlaza circularmente, ya que solo es un nodo
		nuevo->ant = nuevo;
		nuevo->sig = nuevo;
		ini = nuevo;
		fin = nuevo;
	}
	else {
		// Aqui se cambian los nodos del nuevo ini y de fin
		NodoD* nuevoSegundo = ini;
		nuevo->ant = fin;
		nuevo->sig = nuevoSegundo;
		nuevoSegundo->ant = nuevo;
		ini = nuevo;
		fin->sig = ini;
	}
}

void Dicola::sacar_final(int &e) {
	if (!vacia()) {
		NodoD* x = fin;
		e = fin->elemento;
		if (ini == fin)
			ini = fin = NULL;
		else {
			fin = fin->ant;
			fin->sig = NULL;
		}
		delete(x);
	}
}

void Dicola::mostrar() {
	NodoD*aux = ini;
	int c = 0;
	while (c < 3) {
		cout << aux->ant << " ," << aux << "|" << aux->elemento << ", " <<
			aux->sig << endl;
		aux = aux->sig;
		c++;
	}
	cout << endl;
}

string Dicola::to_str() {
	string s = "<<";
	int e;
	Dicola* aux = new Dicola();
	while (!vacia()) {
		sacar(e);
		aux->poner(e);
		s += to_string(e);
		if (!vacia())
			s += ",";
	}
	while (!aux->vacia()) {
		aux->sacar(e);
		poner(e);
	}
	return s + "<<";
}
