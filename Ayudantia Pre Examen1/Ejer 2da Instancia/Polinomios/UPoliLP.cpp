// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UPoliLP.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

PoliLP::PoliLP() {
	K = new ListaP();
}

direccionP PoliLP::buscar_exponente(int exp) {
	if (es_cero())
		return NULL;
	else {
		if (exp > grado() || exp < 0)
			return NULL;
		else {
			int ex = grado();
			NodoL* aux = K->siguiente(K->primero());
			while (aux != NULL) {
				if (ex == exp)
					return aux;
				ex--;
				aux = K->siguiente(aux);
			}
			return NULL;
		}
	}
}
// Ult Grado
// Penun --> Primero
/*
 NodoL* aux = K->anterior(K->fin());//El penultimo
 while(aux != NULL){
 ... Aqui la logica
 aux = K->anterior(aux);
 }

 */

// 1 Grado
// EXP: 2 --> fin() -> NULL
int PoliLP::expo(int i) {
	if (!es_cero()) {
		NodoL* aux = K->siguiente(K->primero());
		int c = 0;
		int ex = grado();
		while (aux != NULL) {
			int elem = K->recupera(aux);
			if (elem != 0) {
				c++;
				if (c == i)
					return ex;
			}
			ex--;
			aux = K->siguiente(aux);
		}
		return -1;
	}
	else {
		return -1;
	}
}

bool PoliLP::es_cero() {
	return K->vacia();
}

int PoliLP::grado() {
	if (!es_cero()) {
		NodoL* prim = K->primero();
		return K->recupera(prim);
	}
	else
		cout << "POLINOMIO NO TIENE TERMINOS\n";

}

int PoliLP::coeficiente(int exp) {
	NodoL* dir = buscar_exponente(exp);
	int coef = K->recupera(dir);
	if (dir != NULL && coef != 0)
		return coef;
	else
		cout << "POLINOMO NO TIENE ESTE TERMINO\n";
}

/*
 inserta_ultimo(coef);
 inserta_ultimo(exp);
 for(int i = 0;i < exp;i++)
 inserta_primero(0);
 */
void PoliLP::poner_termino(int coef, int exp) {
	if (coef != 0 && exp >= 0) {
		if (es_cero()) {
			K->inserta_ultimo(exp);
			K->inserta_ultimo(coef);
			for (int i = 0; i < exp; i++)
				K->inserta_ultimo(0);
		}
		else {
			NodoL* exisExp = buscar_exponente(exp);
			if (exisExp == NULL && exp > grado()) {
				NodoL* seg = K->siguiente(K->primero());
				K->inserta(seg, coef);
				int dif = exp - grado() - 1;
				for (int i = 0; i < dif; i++) {
					NodoL* ter = K->siguiente(K->siguiente(K->primero()));
					K->inserta(ter, 0);
					/*
					 NodoL* pen = K->anterior(K->fin());
					 K->inserta(pen, 0);
					 */
				}
				K->modifica(K->primero(), exp);
				// K->modifica(K->fin(), exp);
			}
			else {
				int co = K->recupera(exisExp);
				if (co == 0) {
					K->modifica(exisExp, coef);
				}
				else {
					int ncoef = co + coef;
					K->modifica(exisExp, ncoef);
					if (ncoef == 0 && exp == grado()) {
						NodoL* seg = K->siguiente(K->primero());
						// NodoL* pen = K->anterior(K->fin());
						// int elem = K->recupera(seg);
						while (seg != NULL && K->recupera(seg) == 0) {
							K->suprime(seg);
							// K->suprime(pen);
							seg = K->siguiente(K->primero());
							// pen = K->anterior(K->fin());
							// elem = K->recupera(seg);
						}
						if (K->longitud() == 1)
							K->suprime(K->primero());
						else {
							int num = K->longitud() - 1;
							K->modifica(K->primero(), num - 1);
							// K->modifica(K->fin(), num - 1);
						}
					}
				}
			}
		}
	}
}

int PoliLP::numero_terminos() {
	if (es_cero()) {
		return 0;
	}
	else {
		int c = 0;
		NodoL* aux = K->siguiente(K->primero());
		while (aux != NULL) {
			int coef = K->recupera(aux);
			if (coef != 0)
				c++;
			aux = K->siguiente(aux);
		}
		return c;
	}
}

int PoliLP::exponente(int nro) {
	int exp = expo(nro);
	if (exp != -1)
		return exp;
	else
		cout << "NO EXISTE ESE NUMERO DE TERMINO\n";
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

string PoliLP::mostrar_lista() {
	return K->to_str();
}
