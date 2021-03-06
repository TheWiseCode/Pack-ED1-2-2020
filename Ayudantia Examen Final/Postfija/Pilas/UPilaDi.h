// ---------------------------------------------------------------------------

#ifndef UPilaDiH
#define UPilaDiH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "UDicolaV3.h"

using namespace std;

class PilaDi {
private:
	DicolaV3* k;

public:
	PilaDi();
	bool vacia();
	void meter(int e);
	void sacar(int& e);
	int cima();
	string to_str();
};

#endif
