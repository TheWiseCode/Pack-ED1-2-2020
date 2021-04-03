// ---------------------------------------------------------------------------

#ifndef UListaPDH
#define UListaPDH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Funciones.h"

using namespace std;

struct NodoLD {
	int elemento;
	NodoLD* ant;
	NodoLD* sig;
};

class ListaPD {
private:
	NodoLD* ptr_elementos;
	int longit;

public:
	ListaPD();
	NodoLD* fin();
	NodoLD* primero();
	NodoLD* siguiente(NodoLD* d);
	NodoLD* anterior(NodoLD* d);
	bool vacia();
	int recupera(NodoLD* d);
	int longitud();
	void inserta(NodoLD* d, int e);
	void inserta_primero(int e);
	void inserta_ultimo(int e);
	void suprime(NodoLD* d);
	void modifica(NodoLD* d, int e);
	string to_str();
	NodoLD* localiza(int e);
	void elimina_dato(int e);
	void anula();
};

#endif
