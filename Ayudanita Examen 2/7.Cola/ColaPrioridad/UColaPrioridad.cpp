// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UColaPrioridad.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

ColaPrioridad::ColaPrioridad() {
	vc = new ColaP[MAX_CL];
	vf = new int[MAX_CL];
	for (int i = 0; i < MAX_CL; i++) {
		// vc[i] = new ColaL();
		vf[i] = 1;
	}
	cola_act = 0;
	cant = 0;
}

bool ColaPrioridad::vacia() {
	for (int i = 0; i < MAX_CL; i++) {
		if (!vc[i].vacia())
			return false;
	}
	return true;
}

int ColaPrioridad::primero() {
	if (!vacia()) {
		if (!vc[cola_act].vacia()) {
			if (cant < vf[cola_act])
				return vc[cola_act].primero();
		}
		else {
			while (vc[cola_act].vacia()) {
				cola_act = (cola_act + 1) % MAX_CL;
				cant = 0;
			}
			if (cant < vf[cola_act])
				return vc[cola_act].primero();

		}
	}
}

void ColaPrioridad::primero(int& valor) {
	if (!vacia()) {
		if (!vc[cola_act].vacia()) {
			if (cant < vf[cola_act])
				valor = vc[cola_act].primero();
		}
		else {
			int nuevaCola = cola_act;
			while (vc[nuevaCola].vacia()) {
				if (nuevaCola == MAX_CL - 1)
					nuevaCola = 0;
				else
					nuevaCola++;
			}
			cola_act = nuevaCola;
			cant = 0;
			if (cant < vf[cola_act])
				valor = vc[cola_act].primero();
		}
	}
}

int ColaPrioridad::primeroRec() {
	if (!vacia()) {
		if (!vc[cola_act].vacia()) {
			if (cant < vf[cola_act])
				return vc[cola_act].primero();
		}
		else {
			cola_act = (cola_act + 1) % MAX_CL;
			cant = 0;
			return primeroRec();
		}
	}
}

void ColaPrioridad::poner(int e, int prior) {
	if (prior > 0 && prior <= MAX_CL) {
		vc[prior - 1].poner(e);
	}
}

void ColaPrioridad::sacar(int &e) {
	if (!vacia()) {
		if (!vc[cola_act].vacia()) {
			if (cant < vf[cola_act]) {
				cant++;
				vc[cola_act].sacar(e);
				if (cant == vf[cola_act]) {
					cola_act = (cola_act + 1) % MAX_CL;
					cant = 0;
				}
			}
		}
		else {
			while (vc[cola_act].vacia()) {
				cola_act = (cola_act + 1) % MAX_CL;
				cant = 0;
			}
			if (cant < vf[cola_act]) {
				cant++;
				vc[cola_act].sacar(e);
				if (cant == vf[cola_act]) {
					cola_act = (cola_act + 1) % MAX_CL;
					cant = 0;
				}
			}
		}
	}
}

void ColaPrioridad::sacarRec(int &e) {
	if (!vacia()) {
		if (!vc[cola_act].vacia()) {
			if (cant < vf[cola_act]) {
				cant++;
				vc[cola_act].sacar(e);
				if (cant == vf[cola_act]) {
					cola_act = (cola_act + 1) % MAX_CL;
					cant = 0;
				}
			}
		}
		else {
			cola_act = (cola_act + 1) % MAX_CL;
			cant = 0;
			sacar(e);
		}
	}
}

void ColaPrioridad::asignar_frec_prioridad(int frec, int prior) {
	if (prior > 0 && prior <= MAX_CL) {
		vf[prior - 1] = frec;
	}
}

string ColaPrioridad::to_str() {
	string s = "";
	for (int i = 0; i < MAX_CL; i++)
		s += vc[i].to_str() + "\n";
	return s;

}
