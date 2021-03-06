// ---------------------------------------------------------------------------

#ifndef UDicolaPH
#define UDicolaPH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Funciones.h"
#include "UColaP.h"

class DicolaP {
private:
	NodoC* ini;
	NodoC* fin;

public:
	DicolaP();
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
