// ---------------------------------------------------------------------------

#ifndef UPilaStrH
#define UPilaStrH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Funciones.h"

using namespace std;

class PilaStr {
private:
	string k;

public:
	PilaStr();
	bool vacia();
	void meter(int e);
	void sacar(int& e);
	int cima();
	string to_str();
};
#endif
