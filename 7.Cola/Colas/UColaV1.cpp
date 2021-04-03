// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UColaV1.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

ColaV1::ColaV1() {
	ini = fin = 0;
	v = new int[MAXVC1];
}

bool ColaV1::vacia() {
	return ini == fin;
}

void ColaV1::poner(int e) {
	if (fin < MAXVC1) {
		v[fin] = e;
		fin++;
	}
}

void ColaV1::sacar(int &e) {
	if (!vacia()) {
		e = v[ini];
		ini++;
	}
}

int ColaV1::primero() {
	if (!vacia())
		return v[ini];
}

string ColaV1::to_str() {
	string s = "<<";
	int e;
	ColaV1* aux = new ColaV1();
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
	/*
	 for(i = ini;i < fin; i++ )
	 s += to_string(v[i]) + ",";
	 */
	return s + "<<";
}
