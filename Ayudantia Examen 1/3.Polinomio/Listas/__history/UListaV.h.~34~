// ---------------------------------------------------------------------------

#ifndef UListaVH
#define UListaVH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Funciones.h"

using namespace std;

const int MAXV = 100;

typedef int direccionI;

class ListaV {
private:
	int* elementos; // int elementos[MAXV];
	int longit;

public:
	ListaV();
	direccionI fin();
	direccionI primero();
	direccionI siguiente(direccionI d);
	direccionI anterior(direccionI d);
	bool vacia();
	int recupera(direccionI d);
	int longitud();
	void inserta(direccionI d, int e);
	void inserta_primero(int e);
	void inserta_ultimo(int e);
	void suprime(direccionI d);
	void modifica(direccionI d, int e);
	string to_str();
	direccionI localiza(int e);
	void elimina_dato(int e);
	void anula();
};

#endif
