//---------------------------------------------------------------------------

#ifndef UListaPDCH
#define UListaPDCH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Funciones.h"

using namespace std;

struct NodoLDC {
	int elemento;
	NodoLDC* ant;
	NodoLDC* sig;
};

class ListaPDC {
private:
	NodoLDC* ptr_elementos;
	int longit;

public:
	ListaPDC();
	NodoLDC* fin();
	NodoLDC* primero();
	NodoLDC* siguiente(NodoLDC* d);
	NodoLDC* anterior(NodoLDC* d);
	bool vacia();
	int recupera(NodoLDC* d);
	int longitud();
	void inserta(NodoLDC* d, int e);
	void inserta_primero(int e);
	void inserta_ultimo(int e);
	void suprime(NodoLDC* d);
	void modifica(NodoLDC* d, int e);
	string to_str();
	NodoLDC* localiza(int e);
	void elimina_dato(int e);
	void anula();
};

#endif
