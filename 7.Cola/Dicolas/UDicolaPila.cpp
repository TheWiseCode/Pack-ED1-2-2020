// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UDicolaPila.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

DicolaPila::DicolaPila() {
	k = new PilaP();
}

bool DicolaPila::vacia() {
	return k->vacia();
}

void DicolaPila::poner(int e) {
}

void DicolaPila::sacar(int &e) {
	if(!vacia()){
		k->sacar(e);//saca de la cima de la pila
	}
}

int DicolaPila::primero() {
}

int DicolaPila::ultimo() {
}

void DicolaPila::poner_frente(int e) {
	k->meter(e);//Mete a la cima de la pila
}

void DicolaPila::sacar_final(int &e) {
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
