//---------------------------------------------------------------------------

#ifndef UDicolaPilaH
#define UDicolaPilaH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Funciones.h"
#include "UPilaV.h"

class DicolaPila {
private:
	PilaV* K;

public:
	DicolaPila();
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
