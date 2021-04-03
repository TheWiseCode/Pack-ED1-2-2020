// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UPilaDi.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

PilaDi::PilaDi() {
	KCAR = new DicolaV3();
}

bool PilaDi::vacia() {
	return KCAR->vacia();
}

void PilaDi::meter(int e) {
	KCAR->poner_frente(e);
}

void PilaDi::sacar(int& e) {
	if (!vacia())
		KCAR->sacar(e);
}

int PilaDi::cima() {
	if (!vacia())
		return KCAR->primero();
}
