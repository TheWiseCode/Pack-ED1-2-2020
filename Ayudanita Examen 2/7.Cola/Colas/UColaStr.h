// ---------------------------------------------------------------------------

#ifndef UColaStrH
#define UColaStrH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Funciones.h"

using namespace std;

class ColaStr {
private:
	string k;

public:
	ColaStr();
	bool vacia();
	void poner(int e);
	void sacar(int &e);
	int primero();
	string to_str();
};
#endif
