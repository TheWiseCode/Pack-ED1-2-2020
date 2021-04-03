//---------------------------------------------------------------------------

#ifndef UColaV2H
#define UColaV2H
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Funciones.h"

using namespace std;

const int MAXVC2 = 20;

class ColaV2{
	private:
		int* v;
        int ini, fin;
	public:
		ColaV2();
		bool vacia();
		void poner(int e);
		void sacar(int &e);
		int primero();
		string to_str();
};
#endif
