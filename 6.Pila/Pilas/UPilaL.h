//---------------------------------------------------------------------------

#ifndef UPilaLH
#define UPilaLH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Funciones.h"
#include "UListaS.h"
#include "UListaP.h"

using namespace std;

class PilaL{
    private:
        ListaP* L;
    public:
        PilaL();
        bool vacia();
        void meter(int e);
        void sacar(int& e);
        int cima();
        string to_str();
};

#endif
