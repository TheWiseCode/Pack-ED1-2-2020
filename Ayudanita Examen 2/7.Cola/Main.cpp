#include <iostream>
#include "UColaL.h"
#include "UColaV1.h"
#include "UColaV2.h"
#include "UColaV3.h"
#include "UColaP.h"
#include "UColaP2.h"
#include "UColaS.h"

#include "UDicolaL.h"
#include "UDicolaV2.h"
#include "UDicolaV3.h"
#include "UDicolaP.h"
#include "UDicolaPila.h"
#include "UDicolaCola.h"

#include "UPilaP.h"
#include "UPilaV.h"
#include "UPilaStr.h"
#include "UColaStr.h"

#include "UListaP.h"

#include "UColaPrioridad.h"

using namespace std;

// ---AYUDANTIA PRIMERA PARTE
void invertir(ColaP *c) {
	if (!c->vacia()) {
		int x;
		c->sacar(x);
		invertir(c);
		c->poner(x);
	}
}

void invertirIter(ColaP* c) {
	PilaP* aux = new PilaP();
	int x;
	while (!c->vacia()) {
		c->sacar(x);
		aux->meter(x);
	}
	while (!aux->vacia()) {
		aux->sacar(x);
		c->poner(x);
	}
}

void invertirIter(PilaP* p) {
	ColaP* aux = new ColaP();
	int x;
	while (!p->vacia()) {
		p->sacar(x);
		aux->poner(x);
	}
	while (!aux->vacia()) {
		aux->sacar(x);
		p->meter(x);
	}
}

int mayor(PilaV* p) {
	if (!p->vacia()) {
		PilaV* aux = new PilaV();
		int mayor = p->cima();
		int x;
		while (!p->vacia()) {
			p->sacar(x);
			aux->meter(x);
			if (x > mayor)
				mayor = x;
		}
		while (!aux->vacia()) {
			aux->sacar(x);
			p->meter(x);
		}
		return mayor;
	}
}

int segundo_mayor(PilaV &p) {
	if (!p.vacia()) {
		// Primero sacamos el mayor
		PilaV aux;
		int mayor = p.cima();
		int x;
		while (!p.vacia()) {
			p.sacar(x);
			aux.meter(x);
			if (x > mayor)
				mayor = x;
		}
		while (!aux.vacia()) {
			aux.sacar(x);
			p.meter(x);
		}
		//
		int segundo;
		// Indica si ya le asignamos valor a la var segundo
		bool b = false;
		while (!p.vacia()) {
			p.sacar(x);
			aux.meter(x);
			if (b == false) {
				if (x < mayor) {
					segundo = x;
					b = true;
				}
			}
			else if (x < mayor && x > segundo)
				segundo = x;
		}
		while (!aux.vacia()) {
			aux.sacar(x);
			p.meter(x);
		}
		// Aqui puede ser que no haya segundo mayor
		// Ejemplo 1: [ 1 ] Solo es un dato
		// Ejemplo 2: [1, 1] Hay dos datos, pero ambos son el mayor
		if (b == false)
			cout << "No hay segundo mayor\n";
		else
			return segundo;
	}
	else
		cout << "Pila vacia, no hay segundo mayor" << endl;
}
// --------------

// ---
int segundoMayor(PilaV &p) {
	if (!p.vacia()) {
		ListaP l;
		int may = p.cima();
		int x;
		while (!p.vacia()) {
			p.sacar(x);
			l.inserta_primero(x);
			if (x > may)
				may = x;
		}
		while (!l.vacia()) {
			x = l.recupera(l.primero());
			l.suprime(l.primero());
			p.meter(x);
		}
		int seg;
		bool b = false;
		while (!p.vacia()) {
			p.sacar(x);
			l.inserta_primero(x);
			if (!b) {
				if (x < may) {
					seg = x;
					b = true;
				}
			}
			else if (x < may && x > seg)
				seg = x;
		}
		while (!l.vacia()) {
			x = l.recupera(l.primero());
			l.suprime(l.primero());
			p.meter(x);
		}
		if (b == true)
			return seg;
	}
	cout << "No hay segundo mayor\n";
}
// ---

// ---------AYUDANTIA SEGUNDA PARTE
int longitud(PilaP* p) {
	PilaP* aux = new PilaP();
	int x, c = 0;
	while (!p->vacia()) {
		p->sacar(x);
		aux->meter(x);
		c++;
	}
	while (!aux->vacia()) {
		aux->sacar(x);
		p->meter(x);
	}
	return c;
}

int longitud(ColaP* c) {
	ColaP* aux = new ColaP();
	int x, k = 0;
	while (!c->vacia()) {
		c->sacar(x);
		aux->poner(x);
		k++;
	}
	while (!aux->vacia()) {
		aux->sacar(x);
		c->poner(x);
	}
	return k;
}

void eliminarDato(PilaP* p, int d) {
	PilaP* aux = new PilaP();
	int x;
	while (!p->vacia()) {
		p->sacar(x);
		if (x != d)
			aux->meter(x);
	}
	while (!aux->vacia()) {
		aux->sacar(x);
		p->meter(x);
	}
}

void reemplazaDato(PilaP* p, int a, int b) {
	PilaP* aux = new PilaP();
	int x;
	while (!p->vacia()) {
		p->sacar(x);
		if (x == a)
			aux->meter(b);
		else
			aux->meter(x);
	}
	while (!aux->vacia()) {
		aux->sacar(x);
		p->meter(x);
	}
}
// --------------

int main() {
	/*
	 ColaStr* p = new ColaStr();
	 p->poner(4);
	 p->poner(6);
	 p->poner(5);
	 p->poner(1);
	 p->poner(10);
	 p->poner(4);
	 p->poner(7);
	 cout << p->to_str() << endl;
	 */

	PilaV p;
	p.meter(4);
	p.meter(6);
	p.meter(5);
	p.meter(1);
	p.meter(10);
	p.meter(4);
	p.meter(7);
	int s = segundoMayor(p);
	cout << "Segundo mayor: " << s << endl;
	cout << p.to_str() << endl;
	/*
	 ColaP* c = new ColaP();
	 c->poner(2);
	 c->poner(6);
	 c->poner(1);
	 c->poner(4);
	 c->poner(7);
	 cout << c->to_str() << endl;
	 cout << "Longitud cola: " << longitud(c) << endl;
	 */
	system("pause");
	return 0;
}
