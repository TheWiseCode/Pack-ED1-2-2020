//---------------------------------------------------------------------------

#pragma hdrstop

#include "UPilaV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

PilaV::PilaV(){
    elementos = new int[MAX_VP];
    tope = 0;
}

bool PilaV::vacia(){
    return tope == 0;
}

void PilaV::meter(int e){
    if(tope < MAX_VP){
        elementos[tope] = e;
        tope++;
    }
}

void PilaV::sacar(int& e){
    if(!vacia()){
        e = elementos[tope - 1];
        tope--;
    }
}

int PilaV::cima(){
    if(!vacia()){
        return elementos[tope - 1];
    }
}

string PilaV::to_str(){
    string r = "";
    PilaV* aux = new PilaV();
    while(!vacia()){
        int e;
        sacar(e);
        r += "| "+to_string(e)+" |\n";
        aux->meter(e);
    }
    while(!aux->vacia()){
        int e;
        aux->sacar(e);
        meter(e);
    }
    r += "+---+\n";
    return r;
}
