// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UDicolaCola.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

DicolaCola::DicolaCola() {
	K = new ColaV2();
}

bool DicolaCola::vacia() {
	return K->vacia();
}

void DicolaCola::poner(int e) {
	K->poner(e);
}

void DicolaCola::sacar(int &e) {
	if (!vacia())
		K->sacar(e);
}

int DicolaCola::primero() {
	if (!vacia())
		return K->primero();
}

int DicolaCola::ultimo() {
	if (!vacia()) {
		ColaV2* aux = new ColaV2();
		int c = 0;
		int x;
		while (!K->vacia()) {
			K->sacar(x);
			aux->poner(x);
			c++;
		}
		while (!aux->vacia()) {
			aux->sacar(x);
			K->poner(x);
		}
		return x;
	}
}

void DicolaCola::poner_frente(int e) {
	ColaV2* aux = new ColaV2();
	while (!K->vacia()) {
		int x;
		K->sacar(x);
		aux->poner(x);
	}
	K->poner(e);
	while (!aux->vacia()) {
		int x;
		aux->sacar(x);
		K->poner(x);
	}
}

void DicolaCola::sacar_final(int &e) {
	if (!vacia()) {
		ColaV2* aux = new ColaV2();
		int c = 0;
		while (!K->vacia()) {
			int x;
			K->sacar(x);
			aux->poner(x);
			c++;
			e = x;
		}
		for (int i = 0; i < c - 1; i++) {
			int x;
			aux->sacar(x);
			K->poner(x);
		}
	}
}

string DicolaCola::to_str() {
	string s = "<<";
	int e;
	DicolaCola* aux = new DicolaCola();
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
