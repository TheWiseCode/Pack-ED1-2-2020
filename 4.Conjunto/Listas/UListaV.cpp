// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UListaV.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

ListaV::ListaV() {
	this->longit = 0;
	elementos = new int[MAXV];
}

direccionI ListaV::fin() {
	if (!vacia())
		return longit - 1;
	else
		cout << "ERROR: LISTA VACIA\n";
}

direccionI ListaV::primero() {
	if (!vacia())
		return 0;
	else
		cout << "ERROR: LISTA VACIA\n";
}

direccionI ListaV::siguiente(direccionI d) {
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else {
		if (d == longit - 1)
			cout << "ERROR: DIRECCION ERRONEA\n";
		else
			return d + 1;
	}
}

direccionI ListaV::anterior(direccionI d) {
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else {
		if (d > 0 && d <= longit - 1)
			return d - 1;
		else
			cout << "ERROR: DIRECCION ERRONEA\n";
	}
}

bool ListaV::vacia() {
	return longit == 0;
}

int ListaV::recupera(direccionI d) {
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else {
		if (d >= 0 && d <= longit - 1)
			return elementos[d];
		else
			cout << "ERROR: DIRECCION ERRONEA\n";
	}
}

int ListaV::longitud() {
	return longit;
}

void ListaV::inserta(direccionI d, int e) {
	if (longit == MAXV) {
		cout << "ERROR: LISTA LLENA\n";
		return;
	}
	if (vacia()) {
		elementos[0] = e;
		longit++;
		return;
	}
	if (d >= 0 && d <= longit - 1) {
		for (int i = longit; i > d; i--)
			elementos[i] = elementos[i - 1];
		elementos[d] = e;
		longit++;
	}
	else
		cout << "ERROR: DIRECCION ERRONEA\n";
}

void ListaV::inserta_primero(int e) {
	if (longit == MAXV) {
		cout << "ERROR: LISTA LLENA\n";
		return;
	}
	for (int i = longit; i > 0; i--)
		elementos[i] = elementos[i - 1];
	elementos[0] = e;
	longit++;
}

void ListaV::inserta_ultimo(int e) {
	if (longit == MAXV)
		cout << "ERROR: LISTA LLENA\n";
	else {
		elementos[longit] = e;
		longit++;
	}
}

void ListaV::suprime(direccionI d) {
	if (longit == 0) {
		cout << "ERROR: LISTA VACIA\n";
		return;
	}
	if (d >= 0 && d <= longit - 1) {
		for (int i = d; i < longit - 1; i++)
			elementos[i] = elementos[i + 1];
		longit--;
	}
	else
		cout << "ERROR: DIRECCION ERRONEA\n";
}

void ListaV::modifica(direccionI d, int e) {
	if (longit == 0) {
		cout << "ERROR: LISTA VACIA\n";
		return;
	}
	if (d >= 0 && d <= longit - 1)
		elementos[d] = e;
	else
		cout << "ERROR: DIRECCION ERRONEA\n";
}

string ListaV::to_str() {
	string s = "[";
	for (int i = 0; i < longit; i++) {
		s += to_string(elementos[i]);
		if (i < longit - 1)
			s += ",";
	}
	return s + "]";
}

direccionI ListaV::localiza(int e) {
	for(int i = 0;i < longit;i++){
		if(elementos[i] == e)
			return i;
	}
	return -1;
}

void ListaV::elimina_dato(int e) {
	int i = 0;
	while(i < longit){
		if(elementos[i] == e)
			suprime(i);
		else
			i++;
	}
}

void ListaV::anula() {
	longit = 0;
}
