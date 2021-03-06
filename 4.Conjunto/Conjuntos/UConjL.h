//---------------------------------------------------------------------------

#ifndef UConjLH
#define UConjLH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "UListaP.h"

#include <stdlib.h>
#include <time.h>

using namespace std;

class ConjuntoL{
	private:
		ListaP* elem;
	public:
		ConjuntoL();
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
