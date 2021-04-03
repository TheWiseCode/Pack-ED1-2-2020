// ---------------------------------------------------------------------------

#ifndef UMatrizVH
#define UMatrizVH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Funciones.h"

using namespace std;

//int MAX_MV = 0;

class MatrizV {
private:
	int* vf;
	int* vc;
	int* vd;
	int df, dc;
	int repe;
	int nt;

	int posicion(int f, int c);

public:
	MatrizV();
	void dimensionar(int f, int c);
	int dimension_fila();
	int dimension_columna();
	void poner(int f, int c, int valor);
	int elemento(int f, int c);
	void definir_valor_repetido(int valor);
	string to_str();
};
#endif
