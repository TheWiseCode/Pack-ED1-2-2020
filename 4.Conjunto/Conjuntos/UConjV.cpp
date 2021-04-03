// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UConjV.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

ConjuntoV::ConjuntoV() {
	cant = 0;
	v = new bool[MAXVC];
	for (int i = 0; i < MAXVC; i++)
		v[i] = false;
	srand(time(NULL));
}

bool ConjuntoV::vacio() {
	return cant == 0;
}

bool ConjuntoV::pertenece(int e) {
	return v[e - 1];
}

void ConjuntoV::inserta(int e) {
	if (!pertenece(e)) {
		v[e - 1] = true;
		cant++;
	}
}

int ConjuntoV::cardinal() {
	return cant;
}

int ConjuntoV::ordinal(int e) {
	if (!vacio()) {
		int resp = 0;
		for (int i = 1; i <= MAXVC; i++) {
			if (v[i - 1] == true) {
				resp++;
				if (e == i)
					return resp;
			}
		}
		return 0;
	}
	else {
		cout << "ERROR CONJUNTO SIN ELEMENTOS\n";
		return 0;
	}
}

void ConjuntoV::suprime(int e) {
	if (pertenece(e)) {
		v[e - 1] = false;
		cant--;
	}
	else
		cout << "ERROR EL CONJUNTO NO TIENE ESE ELEMENTO\n";
}

int ConjuntoV::muestrea() {
	if (!vacio()) {
		int lug = (rand() % cardinal()) + 1;
		int cont = 0;
		for (int i = 1; i <= MAXVC; i++) {
			if (v[i - 1] == true) {
				cont++;
				if (cont == lug)
					return i;
			}
		}
	}
}

string ConjuntoV::to_str() {
	string s = "{";
	int c = 0;
	for (int i = 1; i <= MAXVC; i++) {
		if (v[i - 1]) {
			c++;
			s += to_string(i);
			if (c < cant)
				s += ",";
		}
	}
	return s + "}";
}
