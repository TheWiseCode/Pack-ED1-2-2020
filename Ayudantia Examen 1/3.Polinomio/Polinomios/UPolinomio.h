// ---------------------------------------------------------------------------

#ifndef UPolinomioH
#define UPolinomioH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Funciones.h"
#include "UListaP.h"

using namespace std;

class yeapPolinomio {
private:
	ListaP* k;

	NodoL* buscar_exp(int exp);

public:
	yeapPolinomio();
	bool es_cero();
	void poner_termino(int coef, int exp);
	int coeficiente(int exp);
	int exponente(int nro_termino);
	int grado();
	int numero_terminos();
	string to_str();
	string mostrar_lista();
};
#endif
