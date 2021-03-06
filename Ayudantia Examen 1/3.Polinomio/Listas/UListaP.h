// ---------------------------------------------------------------------------

#ifndef UListaPH
#define UListaPH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Funciones.h"

using namespace std;

struct NodoL {
	int elemento;
	NodoL* sig;
};

typedef NodoL* direccionP;

class ListaP {
private:
	direccionP ptr_elementos;
	int longit;

	void desenlazar(direccionP d);

public:
	ListaP();
	direccionP fin();
	direccionP primero();
	direccionP siguiente(direccionP d);
	direccionP anterior(direccionP d);
	bool vacia();
	int recupera(direccionP d);
	int longitud();
	void inserta(direccionP d, int e);
	void inserta_primero(int e);
	void inserta_ultimo(int e);
	void suprime(direccionP d);
	void modifica(direccionP d, int e);
	string to_str();
	direccionP localiza(int e);
	void elimina_dato(int e);
	void anula();
	void ordenamientoAsc();
	direccionP nodoMenor();
};

#endif
