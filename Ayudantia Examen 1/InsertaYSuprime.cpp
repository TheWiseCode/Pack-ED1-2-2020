void ListaP::inserta(NodoL d, int e) {
	NodoL* x = new NodoL;
	if (x != NULL) {
		x->ele = e;
		x->sig = NULL;
		if (vacia()) {
			puntero_a_lista = x;
			nro_de_elementos = 1;
		}
		else {
			nro_de_elementos++;
			if (d == primero()) {
				x->sig = d;
				puntero_a_lista = x;
			}
			else {
				NodoL ant = anterior(d);
				ant->sig = x;
				x->sig = d;
			}

		}
	}
	else
		cout << "ERROR: NO EXISTE ESPACIO DE MEMORIA\n";
}

void ListaP::suprime(NodoL* d) {
	if (Cantidad == 0) {
		cout << "ERROR: LISTA VACIA\n";
		return;
	}
	if (d == PunteroD) {
		NodoL* x = PunteroD;
		PunteroD = PunteroD->proximo;
		delete(x);
	}
	else {
		NodoL* ant = anterior(d);
		ant->proximo = d->proximo;
		delete(d);
	}
	Cantidad--;
}