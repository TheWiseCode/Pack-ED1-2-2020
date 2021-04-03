// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UColaS.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

ColaS::ColaS() {
	mem = new CSMemoria();
	ini = fin = NULO;
}

ColaS::ColaS(CSMemoria* m) {
	mem = m;
	ini = fin = NULO;
}

bool ColaS::vacia() {
	return ini == NULO;
}

void ColaS::poner(int e) {
	int aux = mem->new_espacio(datosC);
	if (aux != NULO) {
		mem->poner_dato(aux, elementoC, e);
		mem->poner_dato(aux, sigC, NULO);
		if (vacia()) {
			ini = fin = aux;
		}
		else {
			mem->poner_dato(fin, sigC, aux);
			fin = aux;
		}
	}
}

void ColaS::sacar(int &e) {
	if (!vacia()) {
		e = mem->obtener_dato(ini, elementoC);
		int x = ini;
		if (ini == fin)
			ini = fin = NULO;
		else
			ini = mem->obtener_dato(ini, sigC);
		mem->delete_espacio(x);
	}
}

int ColaS::primero() {
	if (!vacia())
		return mem->obtener_dato(ini, elementoC);
}

string ColaS::to_str() {
	string s = "<<";
	int e;
	ColaS* aux = new ColaS();
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
