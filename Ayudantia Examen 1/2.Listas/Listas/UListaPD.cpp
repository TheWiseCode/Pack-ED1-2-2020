// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UListaPD.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

ListaPD::ListaPD() {
	ptr_elementos = NULL;
	longit = 0;
}

NodoLD* ListaPD::fin() {
	if (vacia()) {
		cout << "ERROR: LISTA VACIA\n";
		return NULL;
	}
	else {
		NodoLD* x = ptr_elementos;
		NodoLD* ptr_fin;
		while (x != NULL) {
			ptr_fin = x;
			x = x->sig;
		}
		return ptr_fin;
	}
}

NodoLD* ListaPD::primero() {
	if (vacia()) {
		cout << "ERROR: LISTA VACIA\n";
		return NULL;
	}
	else
		return ptr_elementos;
}

NodoLD* ListaPD::siguiente(NodoLD* d) {
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else if (d == fin()) {
		cout << "DIRECCION ERRONEA\n";
		return NULL;
	}
	else
		return d->sig;
}

NodoLD* ListaPD::anterior(NodoLD* d) {
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else if (d == primero()) {
		cout << "DIRECCION ERRONEA\n";
		return NULL;
	}
	else
		return d->ant;
}

bool ListaPD::vacia() {
	return longit == 0;
}

int ListaPD::recupera(NodoLD* d) {
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else
		return d->elemento;
}

int ListaPD::longitud() {
	return longit;
}

void ListaPD::inserta(NodoLD* d, int e) {
	NodoLD* nuevo = new NodoLD;
	if (nuevo != NULL) {
		nuevo->elemento = e;
		nuevo->sig = nuevo->ant = NULL;
		if (vacia()) {
			ptr_elementos = nuevo;
			longit = 1;
		}
		else {
			if (d == primero()) {
				nuevo->sig = ptr_elementos;
				ptr_elementos->ant = nuevo;
				ptr_elementos = nuevo;
			}
			else {
				NodoLD* ante = d->ant;
				nuevo->sig = d;
				nuevo->ant = ante;
				d->ant = nuevo;
				ante->sig = nuevo;
			}
			longit++;
		}
	}
	else
		cout << "ERROR: NO EXISTE ESPACIO DE MEMORIA\n";
}

void ListaPD::inserta_primero(int e) {
	NodoLD* nuevo = new NodoLD;
	if (nuevo != NULL) {
		nuevo->elemento = e;
		nuevo->sig = nuevo->ant = NULL;
		if (vacia()) {
			ptr_elementos = nuevo;
			longit = 1;
		}
		else {
			nuevo->sig = ptr_elementos;
			ptr_elementos->ant = nuevo;
			ptr_elementos = nuevo;
			longit++;
		}
	}
	else
		cout << "ERROR: NO EXISTE ESPACIO DE MEMORIA\n";
}

void ListaPD::inserta_ultimo(int e) {
	NodoLD* nuevo = new NodoLD;
	if (nuevo != NULL) {
		nuevo->elemento = e;
		nuevo->sig = nuevo->ant = NULL;
		if (vacia()) {
			ptr_elementos = nuevo;
			longit = 1;
		}
		else {
			NodoLD* fi = fin();
			nuevo->ant = fi;
			fi->sig = nuevo;
			longit++;
		}
	}
	else
		cout << "ERROR: NO EXISTE ESPACIO DE MEMORIA\n";
}

void ListaPD::suprime(NodoLD* d) {
	if (longit == 0) {
		cout << "ERROR: LISTA VACIA\n";
		return;
	}
	if(d == primero()){
		ptr_elementos = ptr_elementos->sig;
		ptr_elementos->ant = NULL;
		delete(d);
	}else{
		NodoLD* ante = d->ant;
		ante->sig = d->sig;
		d->ant = NULL;
		delete(d);
	}
	longit--;
}

void ListaPD::modifica(NodoLD* d, int e) {
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else
		d->elemento = e;
}

string ListaPD::to_str() {
	string s = "[";
	NodoLD* aux = ptr_elementos;
	while (aux != NULL) {
		int el = aux->elemento;
		s += to_string(el);
		aux = aux->sig;
		if (aux != NULL)
			s += ",";
	}
	return s + "]";
}

NodoLD* ListaPD::localiza(int e) {
	NodoLD* aux = ptr_elementos;
	while (aux != NULL) {
		if (aux->elemento == e)
			return aux;
		aux = aux->sig;
	}
	return NULL;
}

void ListaPD::elimina_dato(int e) {
	NodoLD* aux = ptr_elementos;
	while (aux != NULL) {
		if (aux->elemento == e) {
			NodoLD* sup = aux;
			aux = aux->sig;
			suprime(sup);
		}
		else
			aux = aux->sig;
	}
}

void ListaPD::anula() {
	while (!vacia())
		suprime(primero());
}
