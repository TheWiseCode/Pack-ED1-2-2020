//---------------------------------------------------------------------------

#ifndef UColaV3H
#define UColaV3H
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Funciones.h"

using namespace std;

const int MAXVC3 = 9;

class ColaV3{
	private:
		int* v;
        int ini, fin;

        int siguiente(int dir);
	public:
		ColaV3();
		bool vacia();
		void poner(int e);
		void sacar(int &e);
		int primero();
		string to_str();
};
#endif
