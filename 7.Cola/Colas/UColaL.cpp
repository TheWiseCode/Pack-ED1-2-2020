// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UColaL.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

ColaL::ColaL() {
	L = new ListaV();
}

bool ColaL::vacia() {
	return L->vacia();
}

void ColaL::poner(int e) {
	L->inserta(L->primero(), e);
}

void ColaL::sacar(int &e) {
	if (!vacia()) {
		e = L->recupera(L->fin());
		L->suprime(L->fin());
	}
}

int ColaL::primero() {
	if (!vacia())
		return L->recupera(L->fin());
}

string ColaL::to_str() {
	string s = "<<";
	int e;
	ColaL* aux = new ColaL();
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
