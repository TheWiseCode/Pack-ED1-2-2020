//---------------------------------------------------------------------------

#pragma hdrstop

#include "UPilaP.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

PilaP::PilaP(){
    tope = NULL;
}

bool PilaP::vacia(){
    return tope == NULL;
}

void PilaP::meter(int e){
    NodoP* aux = new NodoP;
    if(aux != NULL){
        aux->elemento = e;
        aux->sig = tope;
        tope = aux;
    }else
        cout << "ERROR NO HAY MEMORIA\n" << endl;
}

void PilaP::sacar(int& e){
    if(!vacia()){
        NodoP* x = tope;
        e = tope->elemento;
        tope = tope->sig;
        delete(x);
    }
}

int PilaP::cima(){
    if(!vacia()){
        return tope->elemento;
    }
}

string PilaP::to_str(){
    string r = "";
    PilaP* aux = new PilaP();
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
