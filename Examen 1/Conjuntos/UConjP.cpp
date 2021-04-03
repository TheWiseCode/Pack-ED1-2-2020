// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UConjP.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

ConjuntoP::ConjuntoP() {
	cant = 0;
	ptr_conj = NULL;
	srand(time(NULL));
}

bool ConjuntoP::vacio() {
	return cant == 0; // ptr_conj == NULL;
}

bool ConjuntoP::pertenece(int e) {
	NodoCJ* pc = ptr_conj;
	while (pc != NULL) {
		if (pc->dato == e)
			return true;
		pc = pc->sig;
	}
	return false;
}

void ConjuntoP::inserta(int e) {
	if (!pertenece(e)) {
		NodoCJ* dir = new NodoCJ;
		if (dir != NULL) {
			dir->dato = e;
			dir->sig = ptr_conj;
			ptr_conj = dir;
			cant++;
		}
		else
			cout << "ERROR NO EXISTE ESPACIO MEMORIA\n";
	}
	else
		cout << "ERROR YA EXISTE EL ELEMENTO\n";
}

int ConjuntoP::cardinal() {
	return cant;
}

int ConjuntoP::ordinal(int e) {
	int cont = 0;
	NodoCJ* pc = ptr_conj;
	while (pc != NULL) {
		cont++;
		if (cont == e)
			return cont;
		pc = pc->sig;
	}
	return 0;
}

void ConjuntoP::suprime(int e) {
	if (pertenece(e)) {
		NodoCJ* dir;
		if (e == ptr_conj->dato) {
			dir = ptr_conj;
			ptr_conj = ptr_conj->sig;
		}
		else {
			NodoCJ* pc = ptr_conj;
			NodoCJ* ant;
			while (pc != NULL) {
				if (e == pc->dato) {
					dir = pc;
					break;
				}
				ant = pc;
				pc = pc->sig;
			}
			ant->sig = pc->sig;
			pc->sig = NULL;
		}
		cant--;
		delete(dir);
	}
}

int ConjuntoP::muestrea() {
	if (!vacio()) {
		int lug = (rand() % cardinal()) + 1;
		NodoCJ* dir = ptr_conj;
		int cont = 0;
		for (int i = 1; i <= cardinal(); i++) {
			cont++;
			if (cont == lug)
				return dir->dato;
			dir = dir->sig;
		}
	}
}

string ConjuntoP::to_str() {
	string s = "{";
	NodoCJ* p = ptr_conj;
	int c = 0;
	while (p != NULL) {
		c++;
		int ele = p->dato;
		s += to_string(ele);
		if (c < cant)
			s += ",";
		p = p->sig;
	}
	return s + "}";
}
