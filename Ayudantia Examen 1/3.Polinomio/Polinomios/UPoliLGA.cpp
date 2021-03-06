// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UPoliLGA.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

PoliLGA::PoliLGA() {
	k = new ListaV();
}

bool PoliLGA::es_cero() {
	return k->longitud() == 0;
}

int PoliLGA::buscar_exp(int exp) {
	int aux = k->siguiente((k->siguiente(k->primero())));
	while (true) {
		if (k->recupera(aux) == exp)
			return aux;
		if (aux == k->fin())
			break;
		aux = k->siguiente((k->siguiente(aux)));
	}
	return NULO;
}

void PoliLGA::poner_termino(int coef, int exp) {
	if (es_cero()) {
		k->inserta_ultimo(exp);
		k->inserta_ultimo(coef);
		k->inserta_ultimo(exp);
	}
	else {
		int encExp = buscar_exp(exp);
		if (encExp == NULO) { // Nueva insercion
			k->inserta_ultimo(coef);
			k->inserta_ultimo(exp);
			if (exp > grado())
				k->modifica(k->primero(), exp);
		}
		else {
			int ant = k->anterior(encExp);
			int nuevo_coef = coef + k->recupera(ant);
			k->modifica(ant, nuevo_coef);
			if (nuevo_coef == 0) {
				k->suprime(encExp);
				k->suprime(ant);
				if (k->longitud() == 1)
					k->suprime(k->primero());
				else if (exp == grado())
					actualizarGrado();
			}
		}
	}
}

void PoliLGA::actualizarGrado() {
	int aux = k->siguiente((k->siguiente(k->primero())));
	int may = k->recupera(aux);
	while (true) {
		int el = k->recupera(aux);
		if (el > may)
			may = el;
		if (aux == k->fin())
			break;
		aux = k->siguiente((k->siguiente(aux)));
	}
	k->modifica(k->primero(), may);
}

int PoliLGA::coeficiente(int exp) {
	int encExp = buscar_exp(exp);
	if (encExp == NULO)
		cout << "NO EXISTE TERMINO CON ESE EXPONENTE\n";
	else {
		int coef = k->anterior(encExp);
		return k->recupera(coef);
	}
}

int PoliLGA::exponente(int nro_termino) {
	int aux = k->siguiente((k->siguiente(k->primero())));
	int c = 1;
	while (true) {
		if (c == nro_termino)
			return k->recupera(aux);
		c++;
		if (aux == k->fin())
			break;
		aux = k->siguiente((k->siguiente(aux)));
	}
	return NULO;
}

int PoliLGA::grado() {
	if (es_cero()) {
		cout << "NO HAY TERMINOS EN EL POLINOMIO\n";
	}
	else {
		return k->recupera(k->primero());
	}
}

int PoliLGA::numero_terminos() {
	return (k->longitud() - 1) / 2;
}

string PoliLGA::to_str() {
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
