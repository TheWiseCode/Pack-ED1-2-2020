//---------------------------------------------------------------------------

#ifndef UConjVH
#define UConjVH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Funciones.h"
#include <stdlib.h>
#include <time.h>

const int MAXVC = 100;

using namespace std;

class ConjuntoV{
	private:
		bool* v;
		int cant;
	public:
		ConjuntoV();
		bool vacio();
		bool pertenece(int e);
		void inserta(int e);
		int cardinal();
		int ordinal(int e);
		void suprime(int e);
		int muestrea();
		string to_str();
 };
#endif
