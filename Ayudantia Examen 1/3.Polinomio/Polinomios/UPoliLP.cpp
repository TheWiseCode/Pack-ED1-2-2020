// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UPoliLP.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

PoliLP::PoliLP() {
	pol = new ListaP();
}

direccionP PoliLP::buscar_exponente(int exp) {
	if (!es_cero()) {
		direccionP dir = pol->siguiente(pol->primero());
		if (dir != NULL) {
			direccionP dir_exp = NULL;
			while (dir != NULL && dir_exp == NULL) {
				if (pol->recupera(dir) == exp)
					dir_exp = dir;
				if (dir == pol->fin())
					break;
				dir = pol->siguiente(pol->siguiente(dir));
			}
			return dir_exp;
		}
	}
	else {
		cout << "POLINOMIO NO TIENE TERMINOS\n";
		return NULL;
	}
}

direccionP PoliLP::buscar_termino_n(int i) {
	if (!es_cero()) {
		direccionP dir = pol->primero();
		int nt = 0;
		if (dir != NULL) {
			direccionP dir_ter = NULL;
			while (dir != NULL && dir_ter == NULL) {
				nt++;
				if (nt == i)
					dir_ter = dir;
				if (pol->siguiente(dir) == pol->fin())
					break;
				dir = pol->siguiente(pol->siguiente(dir));
			}
			return dir_ter;
		}
	}
	else {
		cout << "POLINOMIO NO TIENE TERMINOS\n";
		return NULL;
	}
}

bool PoliLP::es_cero() {
	return pol->vacia();
}

int PoliLP::grado() {
	if (!es_cero()) {
		direccionP dir = pol->siguiente(pol->primero());
		if (dir != NULL) {
			int max_grado = pol->recupera(dir);
			while (dir != NULL) {
				if (pol->recupera(dir) > max_grado)
					max_grado = pol->recupera(dir);
				if (dir == pol->fin())
					break;
				dir = pol->siguiente(pol->siguiente(dir));
			}
			return max_grado;
		}
	}
	else
		cout << "POLINOMIO NO TIENE TERMINOS\n";

}

int PoliLP::coeficiente(int exp) {
	direccionP dir = buscar_exponente(exp);
	if (dir != NULL)
		return pol->recupera(pol->anterior(dir));
	else
		cout << "POLINOMO NO TIENE ESTE TERMINO\n";
}

void PoliLP::asignar_coeficiente(int coef, int exp) {
	direccionP dir = buscar_exponente(exp);
	if (dir != NULL) {
		direccionP dir_coef = pol->anterior(dir);
		pol->modifica(dir_coef, coef);
		if (coef == 0) {
			pol->suprime(dir);
			pol->suprime(dir_coef);
		}
	}
	else
		cout << "POLINOMO NO TIENE ESTE TERMINO\n";
}

void PoliLP::poner_termino(int coef, int exp) {
	if (coef != 0 && exp >= 0) {
		direccionP dir_exp = buscar_exponente(exp);
		if (dir_exp != NULL) { // Modifica
			direccionP dir_coef = pol->anterior(dir_exp);
			int nuevo_coef = pol->recupera(dir_coef) + coef;
			pol->modifica(dir_coef, nuevo_coef);
			if (nuevo_coef == 0) {
				pol->suprime(dir_exp);
				pol->suprime(dir_coef);
			}
		}
		else { // Insercion
			pol->inserta_ultimo(exp);
			pol->inserta(pol->fin(), coef);
		}
	}
}

int PoliLP::numero_terminos() {
	return pol->longitud() / 2;
}

int PoliLP::exponente(int nro) {
	direccionP dir = buscar_termino_n(nro);
	if (dir != NULL)
		return pol->recupera(pol->siguiente(dir));
	else
		cout << "NO EXISTE ESE NUMERO DE TERMINO\n";
}

void PoliLP::sumar(PoliLP* p1, PoliLP* p2, PoliLP* &pr) {
	pr = new PoliLP();
	for (int i = 1; i <= p1->numero_terminos(); i++) {
		int ex = p1->exponente(i);
		int co = p1->coeficiente(ex);
		pr->poner_termino(ex, co);
	}
	for (int i = 1; i <= p2->numero_terminos(); i++) {
		int ex = p2->exponente(i);
		int co = p2->coeficiente(ex);
		pr->poner_termino(ex, co);
	}
}

void PoliLP::restar(PoliLP* p1, PoliLP* p2, PoliLP* &pr) {
	pr = new PoliLP();
	for (int i = 1; i <= p1->numero_terminos(); i++) {
		int ex = p1->exponente(i);
		int co = p1->coeficiente(ex);
		pr->poner_termino(ex, co);
	}
	for (int i = 1; i <= p2->numero_terminos(); i++) {
		int ex = p2->exponente(i);
		int co = p2->coeficiente(ex);
		pr->poner_termino(-ex, co);
	}
}

void PoliLP::multiplicar(PoliLP* p1, PoliLP* p2, PoliLP* &pr) {
	pr = new PoliLP();
}

void PoliLP::derivar() {
	int n = numero_terminos();
	int* exn = new int[n];
	int* con = new int[n];
	int c = 0;
	while(!es_cero()){
		int ex = exponente(1);
		int co = coeficiente(ex);
		poner_termino(-co, ex);
		exn[c] = ex;
		con[c] = co;
		c++;
	}
	for (int i = 0; i < n; i++) {
		int ex = exn[i];
		int co = con[i];
		poner_termino(co*ex, ex - 1);
	}
}

string PoliLP::to_str() {
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
