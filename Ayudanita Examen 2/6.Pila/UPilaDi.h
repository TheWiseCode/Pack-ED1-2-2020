// ---------------------------------------------------------------------------

#ifndef UPilaDiH
#define UPilaDiH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Funciones.h"
#include "UDicolaV3.h"

using namespace std;

class PilaDi {
private:
	DicolaV3* KCAR;

public:
	PilaDi();
	bool vacia();
	void meter(int e);
	void sacar(int& e);
	int cima();
};

#endif
