//---------------------------------------------------------------------------

#pragma hdrstop

#include "UColaV3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ColaV3::ColaV3() {
	ini = fin = 0;
	v = new int[MAXVC3];
}

bool ColaV3::vacia() {
	return ini == fin;
}

int ColaV3::siguiente(int dir){
    if(dir == MAXVC3 - 1)
        return 0;
    else
        return dir + 1;
}

void ColaV3::poner(int e) {
	if (siguiente(fin) != ini) {
		v[fin] = e;
		fin = siguiente(fin);
	}
}

void ColaV3::sacar(int &e) {
	if (!vacia()) {
		e = v[ini];
		ini = siguiente(ini);
	}
}

int ColaV3::primero() {
	if (!vacia())
		return v[ini];
}

string ColaV3::to_str() {
	string s = "<<";
	int e;
	ColaV3* aux = new ColaV3();
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