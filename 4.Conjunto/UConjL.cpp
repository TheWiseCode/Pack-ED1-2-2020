// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UConjL.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

ConjuntoL::ConjuntoL() {
	elem = new ListaP();
}

bool ConjuntoL::vacio() {
	return elem->vacia();
}

bool ConjuntoL::pertenece(int e) {
	if (!elem->vacia()) {
		NodoL* p = elem->primero();
		while (p != NULL) {
			int ele = elem->recupera(p);
			if (e == ele)
				return true;
			p = elem->siguiente(p);
		}
		return false;
	}
	else {
		cout << "ERROR CONJUNTO SIN ELEMENTOS\n";
		return false;
	}
}

void ConjuntoL::inserta(int e) {
	if (!pertenece(e))
		elem->inserta(elem->primero(), e);
}

int ConjuntoL::cardinal() {
	return elem->longitud();
}

int ConjuntoL::ordinal(int e) {
	if (!elem->vacia()) {
		int c = 0;
		NodoL* p = elem->primero();
		while (p != NULL) {
			c++;
			int ele = elem->recupera(p);
			if (e == ele)
				return c;
			p = elem->siguiente(p);
		}
		return 0;
	}
	else {
		cout << "ERROR CONJUNTO SIN ELEMENTOS\n";
		return 0;
	}

}

void ConjuntoL::suprime(int e) {
	if (pertenece(e)) {
		NodoL* p = elem->primero();
		while (p != NULL) {
			int ele = elem->recupera(p);
			if (e == ele) {
				elem->suprime(p);
				return;
			}
			p = elem->siguiente(p);
		}
	}
	else
		cout << "ERROR EL CONJUNTO NO TIENE ESE ELEMENTO\n";
}

int ConjuntoL::muestrea() {
	if (!vacio()) {
		srand(time(NULL));
		int lug = (rand() % cardinal()) + 1;
		NodoL* dir = elem->primero();
		int cont = 0;
		for (int i = 1; i <= cardinal(); i++) {
			cont++;
			if (cont == lug) {
				return elem->recupera(dir);
			}
			dir = elem->siguiente(dir);
		}
	}
}

string ConjuntoL::to_str() {
	string s = "{";
	NodoL* p = elem->primero();
	while (p != NULL) {
		int ele = elem->recupera(p);
		s += to_string(ele);
		if (p != fin())
			s += ",";
		p = elem->siguiente(p);
	}
	return s + "}";
}
