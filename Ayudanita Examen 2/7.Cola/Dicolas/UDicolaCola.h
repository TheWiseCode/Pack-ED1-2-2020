// ---------------------------------------------------------------------------

#ifndef UDicolaColaH
#define UDicolaColaH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Funciones.h"
#include "UColaV2.h"

class DicolaCola {
private:
	ColaV2* K;

public:
	DicolaCola();
	bool vacia();
	void poner(int e);
	void sacar(int &e);
	int primero();
	int ultimo();
	void poner_frente(int e);
	void sacar_final(int &e);
	string to_str();
};
#endif
