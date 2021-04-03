// ---------------------------------------------------------------------------

#ifndef UColaP2H
#define UColaP2H
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Funciones.h"
#include "UColaP.h"

class ColaP2 {
private:
	NodoC* ini;
	NodoC* fin;

public:
	ColaP2();
	bool vacia();
	void poner(int e);
	void sacar(int &e);
	int primero();
	string to_str();
};
#endif
