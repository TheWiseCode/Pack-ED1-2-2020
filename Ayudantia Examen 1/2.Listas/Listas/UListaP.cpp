// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UListaP.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

ListaP::ListaP() {
	ptr_elementos = NULL;
	longit = 0;
}

direccionP ListaP::fin() {
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else {
		direccionP x = ptr_elementos;
		direccionP ptr_fin;
		while (x != NULL) {
			ptr_fin = x;
			x = x->sig;
		}
		return ptr_fin;
	}
}

direccionP ListaP::primero() {
	if (!vacia())
		return ptr_elementos;
	else
		cout << "ERROR: LISTA VACIA\n";
}

direccionP ListaP::siguiente(direccionP d) {
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else {
		if (d == fin())
			cout << "ERROR: DIRECCION ERRONEA\n";
		else
			return d->sig;
	}
}

direccionP ListaP::anterior(direccionP d) {
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else {
		if (d == primero())
			cout << "ERROR: DIRECCION ERRONEA\n";
		else {
			direccionP x = ptr_elementos;
			direccionP ant = NULL;
			while (x != NULL) {
				if (x == d)
					return ant;
				ant = x;
				x = x->sig;
			}
			return NULL;
		}
	}
}

bool ListaP::vacia() {
	return longit == 0;
}

int ListaP::recupera(direccionP d) {
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else
		return d->elemento;
}

int ListaP::longitud() {
	return longit;
}

void ListaP::inserta(direccionP d, int e) {
	NodoL* x = new NodoL;
	if (x != NULL) {
		x->elemento = e;
		x->sig = NULL;
		if (vacia()) {
			ptr_elementos = x;
			longit = 1;
		}
		else {
			longit++;
			if (d == primero()) {
				x->sig = d;
				ptr_elementos = x;
			}
			else {
				direccionP ant = anterior(d);
				ant->sig = x;
				x->sig = d;
			}

		}
	}
	else
		cout << "ERROR: NO EXISTE ESPACIO DE MEMORIA\n";
}

void ListaP::inserta_primero(int e) {
	NodoL* x = new NodoL;
	if (x != NULL) {
		x->elemento = e;
		x->sig = ptr_elementos;
		ptr_elementos = x;
		longit++;
	}
	else
		cout << "ERROR: NO EXISTE ESPACIO DE MEMORIA\n";
}

void ListaP::inserta_ultimo(int e) {
	NodoL* x = new NodoL;
	if (x != NULL) {
		x->elemento = e;
		x->sig = NULL;
		if (vacia())
			ptr_elementos = x;
		else
			fin()->sig = x;
		longit++;
	}
	else
		cout << "ERROR: NO EXISTE ESPACIO DE MEMORIA\n";
}

void ListaP::suprime(direccionP d) {
	if (longit == 0) {
		cout << "ERROR: LISTA VACIA\n";
		return;
	}
	if (d == ptr_elementos) {
		direccionP x = ptr_elementos;
		ptr_elementos = ptr_elementos->sig;
		delete(x);
	}
	else {
		direccionP ant = anterior(d);
		ant->sig = d->sig;
		delete(d);
	}
	longit--;
}

void ListaP::modifica(direccionP d, int e) {
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else
		d->elemento = e;
}

/*
 Recorrer con punteros
 direccion aux = ptr_elementos;
 while(aux != NULL){
 aux = aux->sig;
 }
 */
string ListaP::to_str() {
	string s = "[";
	direccionP aux = ptr_elementos;
	while (aux != NULL) {
		int el = aux->elemento;
		s += to_string(el);
		aux = aux->sig;
		if (aux != NULL)
			s += ",";
	}
	return s + "]";
}

direccionP ListaP::localiza(int e) {
	direccionP aux = ptr_elementos;
	while (aux != NULL) {
		if (aux->elemento == e)
			return aux;
		aux = aux->sig;
	}
	return NULL;
}

void ListaP::elimina_dato(int e) {
	direccionP aux = ptr_elementos;
	while (aux != NULL) {
		if (aux->elemento == e) {
			direccionP sup = aux;
			aux = aux->sig;
			suprime(sup);
		}
		else
			aux = aux->sig;
	}
}

void ListaP::anula() {
	while (!vacia())
		suprime(primero());
}

direccionP ListaP::nodoMenor() {
	if (vacia()) {
		return NULL;
	}
	else {
		NodoL* aux = ptr_elementos;
		NodoL* nodoMen = ptr_elementos;
		while (aux != NULL) {
			if (aux->elemento < nodoMen->elemento)
				nodoMen = aux;
			aux = aux->sig;
		}
		return nodoMen;
	}
}

void ListaP::ordenamientoAsc() {
	if (longitud() > 1) {
		NodoL* ptrAux = NULL;
		while (ptr_elementos != NULL) {
			NodoL* menor = nodoMenor();
			desenlazar(menor);
			menor->sig = NULL;
			if (ptrAux == NULL)
				ptrAux = menor;
			else {
				NodoL* fin = ptrAux;
				while (fin->sig != NULL)
					fin = fin->sig;
				fin->sig = menor;
			}
		}
		ptr_elementos = ptrAux;
	}
}

void ListaP::desenlazar(direccionP d) {
	if (longit == 0) {
		return;
	}
	if (d == ptr_elementos) {
		direccionP x = ptr_elementos;
		ptr_elementos = ptr_elementos->sig;
	}
	else {
		direccionP ant = anterior(d);
		ant->sig = d->sig;
	}
}

ListaP* ListaP::copia() {
	ListaP* copia = new ListaP();
	NodoL* aux = primero();
	while (true) {
		copia->inserta_ultimo(recupera(aux));
		if (aux == fin())
			break;
		aux = siguiente(aux);
	}
	return copia;
}

int ListaP::repeticion(int e) {
	int c = 0;
	NodoL* aux = primero();
	while (true) {
		if (recupera(aux) == e)
			c++;
		if (aux == fin())
			break;
		aux = siguiente(aux);
	}
	return c;
}

// [2, 3, 1, 3, 1, 4, 5, 7, 1, 2] --> [3, 4, 5, 7, 1, 2]
ListaP* ListaP::sin_repetidos() {
	/* ListaP* copia = new ListaP();
	 NodoL* aux = primero();
	 while (true) {
	 copia->inserta_ultimo(recupere(aux));
	 if (aux == fin())
	 break;
	 aux = siguiente(aux);
	 } */
	ListaP* copy = copia();
	// ------------------
	ListaP* ret = new ListaP();
	NodoL* aux = copy->primero();
	while (true) {
		bool elimino = false;
		int elem = copy->recupera(aux);
		int rep = copy->repeticion(elem);
		if (rep == 1) {
			ret->inserta_ultimo(elem);
		}
		else {
			NodoL* elim = aux;
			aux = copy->siguiente(aux);
			copy->suprime(elim);
			elimino = true;
		}
		if (aux == copy->fin())
			break;
		if (!elimino)
			aux = copy->siguiente(aux);
	}
	return ret;
}
