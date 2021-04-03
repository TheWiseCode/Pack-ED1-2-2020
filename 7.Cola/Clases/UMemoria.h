// ---------------------------------------------------------------------------

#ifndef UMemoriaH
#define UMemoriaH
// ---------------------------------------------------------------------------

#include <iostream>
#include <string>
#include "Funciones.h"

using namespace std;

const int MAX = 20;
const int NULO = -1;

struct NodoMem {
	int dato;
	string id;
	int link;
};

class CSMemoria {
private:
	NodoMem* mem; // NodoMem mem[MAX];
	int libre;
	int numero_ids(string id);

public:
	CSMemoria();
	int new_espacio(string cadena);
	void delete_espacio(int dir);
	void poner_dato(int dir, string cadena_id, int valor);
	int obtener_dato(int dir, string cadena_id);
	int espacio_disponible();
	int espacio_ocupado();
	bool dir_libre(int dir);
	void mostrar();
};
#endif
