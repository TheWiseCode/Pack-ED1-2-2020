//---------------------------------------------------------------------------

#ifndef UPilaVH
#define UPilaVH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Funciones.h"

using namespace std;

const int MAX_VP = 50;

class PilaV{
    private:
        int* elementos;
        int tope;
    public:
        PilaV();
        bool vacia();
        void meter(int e);
        void sacar(int& e);
        int cima();
        string to_str();
};

#endif
