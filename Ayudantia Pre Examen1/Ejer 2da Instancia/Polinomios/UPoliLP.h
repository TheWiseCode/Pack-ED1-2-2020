// ---------------------------------------------------------------------------

#ifndef UPoliLPH
#define UPoliLPH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Funciones.h"
#include "UListaP.h"

using namespace std;

class PoliLP {
private:
	ListaP* K;

	direccionP buscar_exponente(int exp);
	int expo(int i);

public:
	PoliLP();
	bool es_cero();
	int grado();
	int coeficiente(int exp);
	void poner_termino(int coef, int exp);
	int numero_terminos();
	int exponente(int nro);
	string to_str();
	string mostrar_lista();

};
#endif
