// ---------------------------------------------------------------------------

#ifndef UMatrizLH
#define UMatrizLH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Funciones.h"
#include "UListaP.h"

using namespace std;

class MatrizL {
private:
	ListaP* L;
	int repe, df, dc;
	// int nt;

	//int buscar(int f, int c);
	NodoL* buscar(int f, int c);
public : MatrizL();
	void dimensionar(int f, int c);
	int dimension_fila();
	int dimension_columna();
	void poner(int f, int c, int valor);
	int elemento(int f, int c);
	int numero_terminos();
	void definir_valor_repetido(int valor);
	string to_str();
};

#endif
