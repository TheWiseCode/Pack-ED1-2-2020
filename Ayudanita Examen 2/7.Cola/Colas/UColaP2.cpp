// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UColaP2.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

ColaP2::ColaP2() {
	ini = fin = NULL;
}

bool ColaP2::vacia() {
	return ini == NULL;
}

void ColaP2::poner(int e) {
	NodoC* aux = new NodoC();
	if (aux != NULL) {
		aux->elemento = e;
		aux->sig = NULL;
		if (vacia())
			ini = fin = aux;
		else {
			fin->sig = aux;
			fin = aux;
		}
		aux->sig = ini;
	}
}

void ColaP2::sacar(int &e) {
	if (!vacia()) {
		NodoC* x = ini;
		e = ini->elemento;
		if (ini == fin)
			ini = fin = NULL;
		else {
			ini = ini->sig;
			fin->sig = ini;
		}
		delete(x);
	}
}

int ColaP2::primero() {
	if (!vacia())
		return ini->elemento;
}

string ColaP2::to_str() {
	string s = "<<";
	int e;
	ColaP2* aux = new ColaP2();
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
