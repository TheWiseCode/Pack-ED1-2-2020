// ---------------------------------------------------------------------------

#ifndef UConjPH
#define UConjPH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Funciones.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

struct NodoCJ{
	int dato;
	NodoCJ* sig;
};

class ConjuntoP {
private:
	NodoCJ* ptr_conj;
	int cant;
public:
	ConjuntoP();
	bool vacio();
	bool pertenece(int e);
	void inserta(int e);
	int cardinal();
	int ordinal(int e);
	void suprime(int e);
	int muestrea();
	string to_str();
};
#endif
