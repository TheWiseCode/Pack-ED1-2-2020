//---------------------------------------------------------------------------

#pragma hdrstop

#include "UColaV2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ColaV2::ColaV2() {
	ini = fin = 0;
	v = new int[MAXVC2];
}

bool ColaV2::vacia() {
	return ini == fin;
}

void ColaV2::poner(int e) {
	if (fin < MAXVC2) {
		v[fin] = e;
		fin++;
	}
}

void ColaV2::sacar(int &e) {
	if (!vacia()) {
		e = v[0];
        for(int i = 0;i < fin; i++)
            v[i] = v[i + 1];
        fin--;
	}
}

int ColaV2::primero() {
	if (!vacia())
		return v[0];
}

string ColaV2::to_str() {
	string s = "<<";
	int e;
	ColaV2* aux = new ColaV2();
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

