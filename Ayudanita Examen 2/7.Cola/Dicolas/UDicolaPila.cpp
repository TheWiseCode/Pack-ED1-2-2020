// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UDicolaPila.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

DicolaPila::DicolaPila() {
	K = new PilaV();
}

bool DicolaPila::vacia() {
	return K->vacia();
}

void DicolaPila::poner(int e) {
	K->meter(e);
}

void DicolaPila::sacar(int &e) {
	if (!vacia()) {
		PilaV* aux = new PilaV();
		while (!K->vacia()) {
			int x;
			K->sacar(x);
			aux->meter(x);
		}
		aux->sacar(e);
		while (!aux->vacia()) {
			int x;
			aux->sacar(x);
			K->meter(x);
		}
	}
}

int DicolaPila::primero() {
	if (!vacia()) {
		PilaV* aux = new PilaV();
		while (!K->vacia()) {
			int x;
			K->sacar(x);
			aux->meter(x);
		}
		int e = aux->cima();
		while (!aux->vacia()) {
			int x;
			aux->sacar(x);
			K->meter(x);
		}
		return e;
	}
}

int DicolaPila::ultimo() {
	if (!vacia())
		return K->cima();
}

void DicolaPila::poner_frente(int e) {
	PilaV* aux = new PilaV();
	while (!K->vacia()) {
		int x;
		K->sacar(x);
		aux->meter(x);
	}
	K->meter(9);
	while (!aux->vacia()) {
		int x;
		aux->sacar(x);
		K->meter(x);
	}
}

void DicolaPila::sacar_final(int &e) {
	if (!vacia())
		K->sacar(e);
}

string DicolaPila::to_str() {
	string s = "<<";
	int e;
	DicolaPila* aux = new DicolaPila();
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
