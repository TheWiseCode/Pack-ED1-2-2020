// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UPolinomio.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

yeapPolinomio::yeapPolinomio() {
	k = new ListaP();
}

bool yeapPolinomio::es_cero() {
	return k->longitud() == 0;
}

NodoL* yeapPolinomio::buscar_exp(int exp) {
	NodoL* aux = k->siguiente(k->primero());
	int cont = grado();
	while (aux != NULL) {
		if (cont == exp) {
			int coef = k->recupera(aux);
			if (coef != 0)
				return aux;
			else
				return NULL;
		}
		cont--;
		aux = k->siguiente(aux);
	}
	return NULL;
}

void yeapPolinomio::poner_termino(int coef, int exp) {
	if (es_cero()) {
		k->inserta_ultimo(exp);
		k->inserta_ultimo(coef);
		for (int i = 0; i < exp; i++)
			k->inserta_ultimo(0);
	}
	else {
		NodoL* buscar = buscar_exp(exp);
		if (buscar == NULL) {
			if (exp > grado()) {
				int dif = exp - grado() - 1;
				NodoL* seg = k->siguiente(k->primero());
				k->inserta(seg, coef);
				for (int i = 0; i < dif; i++) {
					NodoL* ter = k->siguiente(k->siguiente(k->primero()));
					k->inserta(ter, 0);
				}
				k->modifica(k->primero(), exp);
			}
			else {
				int ex = grado();
				NodoL* aux = k->siguiente(k->primero());
				while (aux != NULL) {
					if (ex == exp)
						k->modifica(aux, coef);
					ex--;
					aux = k->siguiente(aux);
				}
			}
		}
		else {
			int ncoef = k->recupera(buscar) + coef;
			k->modifica(buscar, ncoef);
			if (ncoef == 0 && exp == grado()) {
				NodoL* seg = k->siguiente(k->primero());
				while (seg != NULL && k->recupera(seg) == 0) {
					k->suprime(seg);
					seg = k->siguiente(k->primero());
				}
				if (k->longitud() == 1)
					k->suprime(k->primero());
				else {
					int cont = 0;
					NodoL* aux = k->siguiente(k->primero());
					while (aux != NULL) {
						cont++;
						aux = k->siguiente(aux);
					}
					k->modifica(k->primero(), cont - 1);
				}
			}
		}
	}
}

int yeapPolinomio::coeficiente(int exp) {
	NodoL* encExp = buscar_exp(exp);
	if (encExp == NULL)
		cout << "NO EXISTE TERMINO CON ESE EXPONENTE\n";
	else
		return k->recupera(encExp);
}

int yeapPolinomio::exponente(int nro_termino) {
	if (k->longitud() > 1) {
		int c = 1;
		int exp = grado();
		NodoL* aux = k->siguiente(k->primero());
		while (aux != NULL) {
			int coef = k->recupera(aux);
			if (coef != 0) {
				if (c == nro_termino)
					return exp;
				c++;
			}
			exp--;
			aux = k->siguiente(aux);
		}
	}
}

int yeapPolinomio::grado() {
	if (es_cero())
		cout << "NO HAY TERMINOS EN EL POLINOMIO\n";
	else
		return k->recupera(k->primero());
}

int yeapPolinomio::numero_terminos() {
	if (k->longitud() == 0)
		return 0;
	else {
		int cont = 0;
		NodoL* aux = k->siguiente(k->primero());
		while (aux != NULL) {
			int coef = k->recupera(aux);
			if (coef != 0)
				cont++;
			aux = k->siguiente(aux);
		}
		return cont;
	}
}

string yeapPolinomio::to_str() {
	string s = "";
	for (int i = 1; i <= numero_terminos(); i++) {
		int ex = exponente(i);
		int co = coeficiente(ex);
		if (co > 0)
			s += "+";
		s += to_string(co) + "x^" + to_string(ex);
	}
	return s;
}

string yeapPolinomio::mostrar_lista() {
	return k->to_str();
}
