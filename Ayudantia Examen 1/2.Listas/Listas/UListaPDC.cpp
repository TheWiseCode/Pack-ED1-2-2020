// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UListaPDC.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

ListaPDC::ListaPDC() {
	ptr_elementos = NULL;
	longit = 0;
}

NodoLDC* ListaPDC::fin() {
	if (vacia()) {
		cout << "ERROR: LISTA VACIA\n";
		return NULL;
	}
	else {
		return ptr_elementos->ant;
	}
}

NodoLDC* ListaPDC::primero() {
	if (vacia()) {
		cout << "ERROR: LISTA VACIA\n";
		return NULL;
	}
	else {
		return ptr_elementos;
	}
}

NodoLDC* ListaPDC::siguiente(NodoLDC* d) {
	if (vacia()) {
		cout << "ERROR: LISTA VACIA\n";
		return NULL;
	}
	else if (d == fin()) {
		cout << "ERROR: DIRECCION ERRONEA\n";
		return NULL;
	}
	else {
		return d->sig;
	}
}

NodoLDC* ListaPDC::anterior(NodoLDC* d) {
	if (vacia()) {
		cout << "ERROR: LISTA VACIA\n";
		return NULL;
	}
	else if (d == primero()) {
		cout << "ERROR: DIRECCION ERRONEA\n";
		return NULL;
	}
	else {
		return d->sig;
	}
}

bool ListaPDC::vacia() {
	return longit == 0;
}

int ListaPDC::recupera(NodoLDC* d) {
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else
		return d->elemento;
}

int ListaPDC::longitud() {
	return longit;
}

void ListaPDC::inserta(NodoLDC* d, int e) {
	NodoLDC* nuevo = new NodoLDC;
	nuevo->elemento = e;
	nuevo->ant = nuevo->sig = NULL;
	if (vacia()) {
		/* nuevo->ant = nuevo;
		 nuevo->sig = nuevo; */
		nuevo->ant = nuevo->sig = nuevo;
		ptr_elementos = nuevo;
		longit = 1;
	}
	else {
		if (longit == 1) {
			nuevo->sig = ptr_elementos;
			nuevo->ant = ptr_elementos;
			ptr_elementos->ant = nuevo;
			ptr_elementos->sig = nuevo;
			ptr_elementos = nuevo;
		}
		else {
			if (d == ptr_elementos) {
				NodoLDC* prim = ptr_elementos;
				NodoLDC* ult = ptr_elementos->ant;
				prim->ant = nuevo;
				ult->sig = nuevo;
				nuevo->sig = prim;
				nuevo->ant = ult;
				ptr_elementos = nuevo;
			}
			else {
				NodoLDC* ante = d->ant;
				NodoLDC* sigt = d;
				ante->sig = nuevo;
				sigt->ant = nuevo;
				nuevo->ant = ante;
				nuevo->sig = sigt;
			}
		}
		longit++;
	}
}

void ListaPDC::inserta_primero(int e) {
	NodoLDC* nuevo = new NodoLDC;
	nuevo->elemento = e;
	nuevo->ant = nuevo->sig = NULL;
	if (vacia()) {
		nuevo->ant = nuevo->sig = nuevo;
		ptr_elementos = nuevo;
		longit = 1;
	}
	else {
		if (longit == 1) {
			nuevo->sig = ptr_elementos;
			nuevo->ant = ptr_elementos;
			ptr_elementos->ant = nuevo;
			ptr_elementos->sig = nuevo;
			ptr_elementos = nuevo;
		}
		else {
			NodoLDC* prim = ptr_elementos;
			NodoLDC* ult = ptr_elementos->ant;
			prim->ant = nuevo;
			ult->sig = nuevo;
			nuevo->sig = prim;
			nuevo->ant = ult;
			ptr_elementos = nuevo;
		}
		longit++;
	}
}

void ListaPDC::inserta_ultimo(int e) {
	NodoLDC* nuevo = new NodoLDC;
	nuevo->elemento = e;
	nuevo->ant = nuevo->sig = NULL;
	if (vacia()) {
		nuevo->ant = nuevo->sig = nuevo;
		ptr_elementos = nuevo;
		longit = 1;
	}
	else {
		if (longit == 1) {
			ptr_elementos->sig = nuevo;
			ptr_elementos->ant = nuevo;
			nuevo->sig = ptr_elementos;
			nuevo->ant = ptr_elementos;
		}
		else {
			NodoLDC* fini = fin();
			fini->sig = nuevo;
			nuevo->ant = fini;
			nuevo->sig = ptr_elementos;
			ptr_elementos->ant = nuevo;
		}
		longit++;
	}
}

void ListaPDC::suprime(NodoLDC* d) {
	if (longit > 0) {
		if (longit == 1) {
			ptr_elementos = NULL;
			longit = 0;
			delete(d);
		}
		else {
			if (d == primero()) {
				NodoLDC* nuevoPrimero = ptr_elementos->sig;
				NodoLDC* fini = fin();
				d->sig = d->ant = NULL;
				fini->sig = nuevoPrimero;
				nuevoPrimero->ant = fini;
				ptr_elementos = nuevoPrimero;
				delete(d);
			}
			else {
				NodoLDC* ante = d->ant;
				NodoLDC* sigt = d->sig;
				d->sig = d->ant = NULL;
				ante->sig = sigt;
				sigt->ant = ante;
				delete(d);
			}
			longit--;
		}
	}
}

void ListaPDC::modifica(NodoLDC* d, int e) {
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else
		d->elemento = e;
}

string ListaPDC::to_str() {
	string s = "[";
	NodoLDC* aux = ptr_elementos;
	for (int i = 0; i < longitud(); i++) {
		s += to_string(aux->elemento);
		if (aux != fin())
			s += ",";
		aux = aux->sig;
	}
	return s + "]";
}

NodoLDC* ListaPDC::localiza(int e) {
	NodoLDC* aux = ptr_elementos;
	for (int i = 0; i < longitud(); i++) {
		if (aux->elemento == e)
			return aux;
		aux = aux->sig;
	}
	return NULL;
}

void ListaPDC::elimina_dato(int e) {
	NodoLDC* aux = ptr_elementos;
	for (int i = 0; i < longitud(); i++) {
		if (aux->elemento == e) {
			NodoLDC* sup = aux;
			aux = aux->sig;
			suprime(sup);
		}
		else
			aux = aux->sig;
	}
}

void ListaPDC::anula() {
	while (!vacia())
		suprime(primero());
}
