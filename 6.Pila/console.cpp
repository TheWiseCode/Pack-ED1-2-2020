#include <iostream>
#include "UPilaL.h"
#include "UPilaV.h"
#include "UPilaP.h"
#include "UPilaS.h"
#include "UMemoria.h"

using namespace std;

int main() {
	CSMemoria* mem = new CSMemoria();
	mem->new_espacio("perro,gato,gallina");
	PilaS *p = new PilaS(mem);
	p->meter(1);
	p->meter(2);
	p->meter(20);
	p->meter(7);
	p->meter(2);
	p->meter(10);
	p->meter(66);
	p->meter(77);
	p->meter(88);
	cout << p->to_str() << endl;
	cout << p->cima() << endl;
	mem->mostrar();
	system("pause");
	return 0;
}
