// ---------------------------------------------------------------------------

#ifndef UPoliSH
#define UPoliSH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Funciones.h"
#include "UMemoria.h";

using namespace std;

const string datosP = "coef,exp,sig";
const string coefP = "->coef";
const string expP = "->exp";
const string sigP = "->sig";


class PoliS {
private:
	CSMemoria* mem;
	int ptr_poli;
	int nt;

	int buscar_exponente(int exp);
	int buscar_termino_n(int i);
	int anterior(int dir);

public:
	PoliS();
	PoliS(CSMemoria* m);
	bool es_cero();
	int grado();
	int coeficiente(int exp);
	void asignar_coeficiente(int coef, int exp);
	void poner_termino(int coef, int exp);
	int numero_terminos();
	int exponente(int nro);
	void sumar(PoliS* p1, PoliS* p2, PoliS* &pr);
	void restar(PoliS* p1, PoliS* p2, PoliS* &pr);
	void multiplicar(PoliS* p1, PoliS* p2, PoliS* &pr);
	void derivar();
	string to_str();
};
#endif
