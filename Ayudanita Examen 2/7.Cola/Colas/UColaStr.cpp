// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UColaStr.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

ColaStr::ColaStr() {
	k = "";
}

bool ColaStr::vacia() {
	return k == "";
}

void ColaStr::poner(int e) {
	k = k + to_string(e) + ",";
}

void ColaStr::sacar(int &e) {
	if (!vacia()) {
		int pos = k.find_first_of(",");
		string sub = k.substr(0, pos);
		k.erase(0, pos + 1);
		e = atoi((char*)sub.c_str());
	}
}

int ColaStr::primero() {
	if (!vacia()) {
		int pos = k.find_first_of(",");
		string sub = k.substr(0, pos);
		return atoi((char*)sub.c_str());
	}
}

string ColaStr::to_str() {
	string s = "<<";
	int e;
	ColaStr* aux = new ColaStr();
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
