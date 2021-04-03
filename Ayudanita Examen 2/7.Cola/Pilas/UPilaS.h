//---------------------------------------------------------------------------

#ifndef UPilaSH
#define UPilaSH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Funciones.h"
#include "UMemoria.h"

using namespace std;

const string datosP = "elemento,sig";
const string elementoP = "->elemento";
const string sigP = "->sig";

class PilaS{
    private:
        int tope;
        CSMemoria* mem;
    public:
        PilaS();
        PilaS(CSMemoria* m);
        bool vacia();
        void meter(int e);
        void sacar(int& e);
        int cima();
        string to_str();
};
#endif
