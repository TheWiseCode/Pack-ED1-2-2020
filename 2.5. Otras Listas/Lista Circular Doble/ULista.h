// ---------------------------------------------------------------------------

#ifndef UListaH
#define UListaH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

struct Nodo {
	Nodo* ant;
	int elem;
	Nodo* sig;
};

class Lista {
private:
	Nodo* ptr_lista;
	int longi;

public:
	Lista();
	Nodo* fin();
	Nodo* primero();
	Nodo* siguiente(Nodo* P);
	Nodo* anterior(Nodo* P);
	bool vacia();
	int recupera(Nodo* P);
	int longitud();
	void inserta(Nodo* P, int e);
	void suprime(Nodo* P);
	void modifica(Nodo* P, int e);
	string to_str();
	void mostrar();

};
#endif
