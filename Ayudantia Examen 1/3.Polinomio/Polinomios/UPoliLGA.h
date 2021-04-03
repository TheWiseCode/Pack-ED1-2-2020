// ---------------------------------------------------------------------------

#ifndef UPoliLGAH
#define UPoliLGAH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Funciones.h"
#include "UListaS.h"
#include "UListaV.h"
#include "UListaP.h"

using namespace std;

class PoliLGA {
private:
	ListaV* k;

	int buscar_exp(int exp);
	void actualizarGrado();

public:
	PoliLGA();
	bool es_cero();
	void poner_termino(int coef, int exp);
	int coeficiente(int exp);
	int exponente(int nro_termino);
	int grado();
	int numero_terminos();
	string to_str();
};
#endif
