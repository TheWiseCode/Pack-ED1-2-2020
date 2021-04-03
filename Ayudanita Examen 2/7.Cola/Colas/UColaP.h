//---------------------------------------------------------------------------

#ifndef UColaPH
#define UColaPH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Funciones.h"

struct NodoC{
    int elemento;
    NodoC* sig;
};

class ColaP{
    private:
        NodoC* ini;
        NodoC* fin;
    public:
        ColaP();
        bool vacia();
		void poner(int e);
		void sacar(int &e);
		int primero();
		string to_str();
};
#endif
