#include <iostream>
#include "UMatrizV.h"
#include "UMatrizVC.h"
#include "UMatrizPtr.h"
#include "UMatrizPtrDb.h"
#include "UMatrizL.h"

using namespace std;

int main() {
	MatrizL* m = new MatrizL();
	/*
	 m->dimensionar(5, 5);
	 // m->definir_valor_repetido(1);
	 m->poner(1, 4, 1);
	 m->poner(1, 3, 80);
	 m->poner(1, 1, 1);
	 m->poner(2, 2, 64);
	 m->poner(2, 4, 1);
	 // m->poner(4, 4, 1);
	 m->poner(4, 2, 1);
	 // m->poner(4, 1, 1);
	 m->poner(3, 5, 1);
	 m->poner(3, 3, 1);
	 m->poner(5, 5, 1);
	 // m->definir_valor_repetido(1);
	 */
	m->dimensionar(3, 3);
	m->poner(1, 1, 4);
	m->poner(1, 2, 3);
	m->poner(2, 2, 2);
	m->poner(3, 1, -1);
	cout << m->to_str() << endl;
	m->definir_valor_repetido(-1);
	cout << m->to_str() << endl;
	system("pause");
	return 0;
}
