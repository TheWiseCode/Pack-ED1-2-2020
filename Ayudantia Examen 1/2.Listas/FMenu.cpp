#include <iostream>
#include <string>
#include "UListaV.h"
#include "UListaP.h"
#include "UListaS.h"
#include "UListaPD.h"
#include "UListaPDC.h"

using namespace std;

void menuV();
void menuP();
void menuS();

bool es_palindroma(ListaV* list) {
	int n = list->longitud();
	if (n == 0)
		return false;
	if (n == 1)
		return true;
	if (n % 2 == 1) { // Impar
		int ini = list->primero();
		int fi = list->fin();
		while (ini != fi) {
			int datoIni = list->recupera(ini);
			int datoFin = list->recupera(fi);
			if (datoIni != datoFin)
				return false;
			ini = list->siguiente(ini);
			fi = list->anterior(fi);
		}
		return true;
	}
	else { // Par
		int ini = list->primero();
		int fi = list->fin();
		while (list->siguiente(fi) != ini) {
			int datoIni = list->recupera(ini);
			int datoFin = list->recupera(fi);
			if (datoIni != datoFin)
				return false;
			ini = list->siguiente(ini);
			fi = list->anterior(fi);
		}
	}
}

bool es_palindroma1(ListaV* list) {
	int n = list->longitud();
	if (n == 0)
		return false;
	if (n == 1)
		return true;
	int ini = list->primero();
	int fi = list->fin();
	while(true) {
		int datoIni = list->recupera(ini);
		int datoFin = list->recupera(fi);
		if (datoIni != datoFin)
			return false;
		ini = list->siguiente(ini);
		fi = list->anterior(fi);
		if(n%2 == 1 && ini == fi)
            break;
		else if(n%2 == 0 && list->siguiente(fi) == ini)
			break;
	}
	return true;
}

// 3	1	4	5	7	5	4	1	3
int main() {
	ListaV* li = new ListaV();
	li->inserta_ultimo(3);
	li->inserta_ultimo(1);
	li->inserta_ultimo(4);
	li->inserta_ultimo(5);
	li->inserta_ultimo(8);
	li->inserta_ultimo(5);
	li->inserta_ultimo(4);
	li->inserta_ultimo(1);
	li->inserta_ultimo(3);
	cout << li->to_str() << endl;
	bool palin = es_palindroma1(li);
	if (palin)
		cout << "True\n";
	else
		cout << "False\n";
	system("pause");
	return 0;
}

void menuV() {
	ListaV* list;
	int opcion;
	do {
		cout << "1.Crear Lista\n";
		cout << "2.Insertar inicio\n";
		cout << "3.Insertar final\n";
		cout << "4.Mostrar\n";
		cout << "5.Salir\n";
		cout << "Opcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1: {
				list = new ListaV();
			} break;
		case 2: {
				int e;
				cout << "Dato: ";
				cin >> e;
				list->inserta_primero(e);
			} break;
		case 3: {
				int e;
				cout << "Dato: ";
				cin >> e;
				list->inserta_ultimo(e);
			} break;
		case 4: {
				cout << list->to_str() << endl;
			} break;
		}
		system("pause");
		system("cls");
	}
	while (opcion != 5);
}

void menuP() {
	ListaP* list;
	int opcion;
	do {
		cout << "1.Crear Lista\n";
		cout << "2.Insertar inicio\n";
		cout << "3.Insertar final\n";
		cout << "4.Mostrar\n";
		cout << "5.Salir\n";
		cout << "Opcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1: {
				list = new ListaP();
			} break;
		case 2: {
				int e;
				cout << "Dato: ";
				cin >> e;
				list->inserta_primero(e);
			} break;
		case 3: {
				int e;
				cout << "Dato: ";
				cin >> e;
				list->inserta_ultimo(e);
			} break;
		case 4: {
				cout << list->to_str() << endl;
			} break;
		}
		system("pause");
		system("cls");
	}
	while (opcion != 5);
}

void menuS() {
	ListaS* list;
	CSMemoria* mem;
	int opcion;
	do {
		cout << "1.Crear Memoria\n";
		cout << "2.Pedir espacio\n";
		cout << "3.Liberar espacio\n";
		cout << "4.Crear Lista\n";
		cout << "5.Insertar inicio\n";
		cout << "6.Insertar final\n";
		cout << "7.Mostrar memoria\n";
		cout << "8.Mostrar lista\n";
		cout << "9.Salir\n";
		cout << "Opcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1: {
				mem = new CSMemoria();
			} break;
		case 2: {
				string ids;
				cin.ignore();
				cout << "IDS a guardar: ";
				getline(cin, ids);
				mem->new_espacio(ids);
			} break;
		case 3: {
				int dir;
				cout << "Direccion a liberar\n";
				cin >> dir;
				mem->delete_espacio(dir);
			} break;
		case 4: {
				list = new ListaS(mem);
			} break;
		case 5: {
				int e;
				cout << "Dato: ";
				cin >> e;
				list->inserta_primero(e);
			} break;
		case 6: {
				int e;
				cout << "Dato: ";
				cin >> e;
				list->inserta_ultimo(e);
			} break;
		case 7: {
				mem->mostrar();
			} break;
		case 8: {
				cout << list->to_str() << endl;
			} break;
		}
		system("pause");
		system("cls");
	}
	while (opcion != 9);
}
