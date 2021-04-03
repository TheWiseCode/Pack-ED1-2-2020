// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UDicolaP.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

DicolaP::DicolaP() {
	ini = fin = NULL;
}

bool DicolaP::vacia() {
	return ini == NULL;
}

void DicolaP::poner(int e) {
	NodoC* aux = new NodoC();
	if (aux != NULL) {
		aux->elemento = e;
		aux->sig = NULL;
		if (vacia()) {
			ini = fin = aux;
		}
		else {
			fin->sig = aux;
			fin = aux;
		}
	}
}

void DicolaP::sacar(int &e) {
	if (!vacia()) {
		e = ini->elemento;
		NodoC* x = ini;
		if (ini == fin)
			ini = fin = NULL;
		else
			ini = ini->sig;
		delete(x);
	}
}

int DicolaP::primero() {
	if (!vacia())
		return ini->elemento;
}

int DicolaP::ultimo() {
	if (!vacia())
		return fin->elemento;
}

void DicolaP::poner_frente(int e) {
	NodoC* aux = new NodoC();
	if (aux != NULL) {
		if (vacia())
			ini = fin = aux;
		else {
			aux->elemento = e;
			aux->sig = ini;
			ini = aux;
		}
	}
}

void DicolaP::sacar_final(int &e) {
	if (!vacia()) {
		e = fin->elemento;
		NodoC* x = fin;
		if (ini == fin)
			ini = fin = NULL;
		else {
			NodoC* ant = ini;
			while (ant->sig != fin)
				ant = ant->sig;
			ant->sig = NULL;
			fin = ant;
		}
		delete(x);
	}
}

string DicolaP::to_str() {
	string s = "<<";
	int e;
	DicolaP* aux = new DicolaP();
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
