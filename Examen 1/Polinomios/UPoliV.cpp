// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UPoliV.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

PoliV::PoliV() {
	nt = 0;
	vc = new int[MAXP];
	ve = new int[MAXP];
}

bool PoliV::es_cero() {
	return nt == 0;
}

int PoliV::grado() {
	if (nt > 0) {
		int max = ve[0];
		for (int i = 1; i < nt; i++)
			if (ve[i] > max)
				max = ve[i];
		return max;
	}
	else
		cout << "ERROR: NO EXISTEN TERMINOS\n";
}

/*
 si exp>=0 y exp <= grado() entonces
 para cada i = 1 hasta nt
 inicio
 si ve[i] = exp entonces retornar vc[i]
 fin
 // error no existe termino con ese exponente
 */
int PoliV::coeficiente(int exp) {
	if (exp >= 0 && exp <= grado()) {
		for (int i = 0; i < nt; i++) {
			if (exp == ve[i])
				return vc[i];
		}
	}
	cout << "ERROR: NO EXISTE TERMINO CON ESE EXPONENTE\n";
}

void PoliV::asignar_coeficiente(int coef, int exp) {
	if (nt > 0) {
		// Logica de existe exponente
		int lug = -1;
		for (int i = 0; i < nt; i++) {
			if (exp == ve[i]) {
				lug = i;
				break;
			}
		}
		// -----
		if (lug != -1) {
			vc[lug] = coef;
			if (vc[lug] == 0) {
				for (int i = lug; i < nt; i++) {
					ve[i] = ve[i + 1];
					vc[i] = vc[i + 1];
				}
				nt--;
			}
		}
		else
			cout << "ERROR: NO EXISTE TERMINO CON ESE EXP\n";

	}
}

void PoliV::poner_termino(int coef, int exp) {
	if (coef != 0 && exp >= 0) {
		// Logica de existe exponente
		int lug = -1;
		for (int i = 0; i < nt; i++) {
			if (exp == ve[i]) {
				lug = i;
				break;
			}
		}
		// -----
		if (lug != -1) { // Modifica
			vc[lug] = vc[lug] + coef;
			if (vc[lug] == 0) {
				for (int i = lug; i < nt; i++) {
					ve[i] = ve[i + 1];
					vc[i] = vc[i + 1];
				}
				nt--;
			}
		}
		else { // Inserta
			vc[nt] = coef;
			ve[nt] = exp;
			nt++;
		}
	}
}

int PoliV::numero_terminos() {
	return nt;
}

int PoliV::exponente(int nro) {
	if (nro >= 1 && nro <= nt)
		return ve[nro - 1];
}

void PoliV::sumar(PoliV* p1, PoliV* p2, PoliV* &pr) {
	pr = new PoliV();
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

void PoliV::restar(PoliV* p1, PoliV* p2, PoliV* &pr) {
	pr = new PoliV();
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

void PoliV::multiplicar(PoliV* p1, PoliV* p2, PoliV* &pr) {
	pr = new PoliV();
}

void PoliV::derivar() {
	int n = numero_terminos();
	int* exn = new int[n];
	int* con = new int[n];
	int c = 0;
	while (!es_cero()) {
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

string PoliV::to_str() {
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

float PoliV::evaluar(float x) {
	float sum = 0;
	for (int i = 1; i <= numero_terminos(); i++) {
		int exp = exponente(i);
		int coef = coeficiente(exp);
		sum += coef * pow(x, exp);
	}
	return sum;
}
