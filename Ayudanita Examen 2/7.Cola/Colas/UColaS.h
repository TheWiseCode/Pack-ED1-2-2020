// ---------------------------------------------------------------------------

#ifndef UColaSH
#define UColaSH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Funciones.h"
#include "UMemoria.h"

const string datosC = "elemento,sig";
const string elementoC = "->elemento";
const string sigC = "->sig";

class ColaS {
private:
	CSMemoria* mem;
	int ini, fin;

public:
	ColaS();
	ColaS(CSMemoria* m);
	bool vacia();
	void poner(int e);
	void sacar(int &e);
	int primero();
	string to_str();
};
#endif
