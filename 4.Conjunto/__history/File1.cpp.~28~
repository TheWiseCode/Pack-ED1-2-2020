#include <iostream>
#include "UConjL.h"
#include "UConjV.h"
#include "UConjP.h"
#include "UConjS.h"

using namespace std;

int main() {
	CSMemoria* m = new CSMemoria();
	m->new_espacio("dia,mes,año");
	ConjuntoS* c = new ConjuntoS(m);
	c->inserta(1);
	c->inserta(2);
	c->inserta(3);
	cout << c->to_str() << endl;
	c->inserta(3);
	c->inserta(4);
	cout << c->to_str() << endl;
	c->suprime(2);
	cout << c->to_str() << endl;
	m->mostrar();
	system("pause");
	return 0;
}
