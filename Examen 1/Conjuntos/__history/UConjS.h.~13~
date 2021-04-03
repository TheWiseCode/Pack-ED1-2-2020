// ---------------------------------------------------------------------------

#ifndef UConjSH
#define UConjSH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Funciones.h"
#include "UMemoria.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

const string datosCJ = "dato,sig";
const string datoCJ = "->dato";
const string sigCJ = "->sig";

class ConjuntoS {
private:
	CSMemoria* mem;
	int ptr_conj;
	int cant;

public:
	ConjuntoS();
	ConjuntoS(CSMemoria* m);
	bool vacio();
	bool pertenece(int e);
	void inserta(int e);
	int cardinal();
	int ordinal(int e);
	void suprime(int e);
	int muestrea();
	void unionC(ConjuntoS * a, ConjuntoS * b, ConjuntoS * &c);
	string to_str();
};
#endif
