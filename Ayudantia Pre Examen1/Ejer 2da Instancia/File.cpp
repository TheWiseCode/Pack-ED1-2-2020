#include <iostream>
#include "UPoliLP.h"

using namespace std;

int main() {
	PoliLP* p = new PoliLP();
	p->poner_termino(4, 3);
	cout << p->to_str() << endl;
	cout << p->mostrar_lista() << endl;
	p->poner_termino(2, 7);
	cout << p->to_str() << endl;
	cout << p->mostrar_lista() << endl;
	p->poner_termino(2, 3);
	cout << p->to_str() << endl;
	cout << p->mostrar_lista() << endl;
	p->poner_termino(-2, 7);
	cout << p->to_str() << endl;
	cout << p->mostrar_lista() << endl;
	p->poner_termino(-6, 3);
	cout << p->to_str() << endl;
	cout << p->mostrar_lista() << endl;
	system("pause");
	return 0;
}
