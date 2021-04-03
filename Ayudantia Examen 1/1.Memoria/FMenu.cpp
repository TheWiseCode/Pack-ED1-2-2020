#include <iostream>
#include <string>
#include "UMemoria.h"

using namespace std;

void menu();

int main() {
	menu();
	system("pause");
	return 0;
}

void menu() {
	CSMemoria* mem;
	int opcion;
	do {
		cout << "1.Crear" << endl;
		cout << "2.Pedir espacio" << endl;
		cout << "3.Liberar espacio" << endl;
		cout << "4.Poner dato" << endl;
		cout << "5.Mostrar Memoria" << endl;
		cout << "6.Salir" << endl;
		cout << "Opcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1: {
				mem = new CSMemoria();
				cout << "Memoria Creada\n";
			} break;
		case 2: {
				string ids;
				cout << "Ids: ";
				cin.ignore();
				getline(cin, ids);
				mem->new_espacio(ids);
			} break;
		case 3: {
				int dir_delete;
				cout << "Direccion a liberar: ";
				cin >> dir_delete;
				mem->delete_espacio(dir_delete);
			} break;
		case 4: {
				int dir, valor;
				string id;
				cout << "Direccion: " << endl;
				cin >> dir;
				cout << "Id: " << endl;
				cin.ignore();
				getline(cin, id);
				cout << "Valor: " << endl;
				cin >> valor;
				mem->poner_dato(dir, id, valor);
			} break;
		case 5: {
				mem->mostrar();
			} break;
		}
		system("pause");
		system("cls");
	}
	while (opcion != 6);
}
