// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UDicolaL.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

DicolaL::DicolaL() {
	L = new ListaV();
}

bool DicolaL::vacia() {
	return L->vacia();
}

void DicolaL::poner(int e) {
	L->inserta(L->primero(), e);
}

void DicolaL::sacar(int &e) {
	if (!vacia()) {
		e = L->recupera(L->fin());
		L->suprime(L->fin());
	}
}

int DicolaL::primero() {
	if (!vacia())
		return L->recupera(L->fin());
}

int DicolaL::ultimo() {
	if (!vacia())
		return L->recupera(L->primero());
}

void DicolaL::poner_frente(int e) {
	L->inserta_ultimo(e);
}

void DicolaL::sacar_final(int &e) {
	if (!vacia()) {
		e = L->recupera(L->primero());
		L->suprime(L->primero());
	}
}

string DicolaL::to_str() {
	string s = "<<";
	int e;
	DicolaL* aux = new DicolaL();
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
