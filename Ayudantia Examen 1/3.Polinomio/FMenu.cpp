#include <iostream>
#include <string>
#include "UPoliS.h"
#include "UPoliP.h"
#include "UPoliL.h"
#include "UPoliLP.h"
#include "UPoliV.h"
#include "UPolinomio.h"
#include "UPoliLGA.h"

using namespace std;

void menuS();
void menuV();
void menuP();
void menuL();

// Area = 8 si f(x) = 2 o 2x^0
// Inge aqui sale
// Area = 0 si f(x) = x
// En la calculadora cientifica sale area = 0 y no area = 1
float area(PoliP fx, float a, float b) {
	float sumaEnA = 0, sumaEnB = 0;
	for (int i = 1; i <= fx.numero_terminos(); i++) {
		int exp = fx.exponente(i), coef = fx.coeficiente(exp);
		float nuevoExp = exp + 1, nuevoCoef = (coef * 1.0) / (exp + 1);
		sumaEnA += nuevoCoef * pow(a, nuevoExp);
		sumaEnB += nuevoCoef * pow(b, nuevoExp);
	}
	return abs(sumaEnB - sumaEnA);
}

/*
 Ingeniero la area de f(x) = x
 si a = -1 y b = 1
 me sale area = 0, tambien me sale eso resolviendo mediante integral,
 no me sale area = 1
 */
float area1(PoliP fx, float a, float b) {
	int n = fx.numero_terminos();
	float* exps = new float[n];
	float* coefs = new float[n];
	float sumA = 0, sumB = 0;
	for (int i = 1; i <= n; i++) {
		int exp = fx.exponente(i), coef = fx.coeficiente(exp);
		exps[i - 1] = exp + 1;
		coefs[i - 1] = (coef * 1.0) / (exp + 1);
	}
	for (int i = 0; i < n; i++) {
		sumA += coefs[i] * pow(a, exps[i]);
		sumB += coefs[i] * pow(b, exps[i]);
	}
	return abs(sumB - sumA);
}

float area(PoliP fx, float a, float b) {
	int n = fx.numero_terminos();
	float sumA = 0, sumB = 0;
	for (int i = 1; i <= n; i++) {
		int exp = fx.exponente(i), coef = fx.coeficiente(exp);
		int nExp = exp + 1, nCoef = (coef * 1.0) / (exp + 1);
		sumA += nCoef * pow(a, nExp);
	}
	for (int i = 1; i <= n; i++) {
		int exp = fx.exponente(i), coef = fx.coeficiente(exp);
		int nExp = exp + 1, nCoef = (coef * 1.0) / (exp + 1);
		sumB += nCoef * pow(a, nExp);
	}
	return abs(sumB - sumA);
}

int main() {
	PoliP p;
	p.poner_termino(1, 1);
	// p->poner_termino(5, 1);
	// p->poner_termino(4, 7);
	float ar = area2(p, -1, 1);
	cout << "Area: " << ar << endl;
	cout << p.to_str() << endl;
	system("pause");
	return 0;
}

/*
 void menuS() {
 CSMemoria* mem;
 PoliS* p;
 int opcion;
 do {
 cout << "1.Crear Memoria\n";
 cout << "2.Pedir espacio\n";
 cout << "3.Liberar espacio\n";
 cout << "4.Crear Polinomio\n";
 cout << "5.Poner Termino\n";
 cout << "6.Mostrar Polinomio\n";
 cout << "7.Derivar\n";
 cout << "8.Mostrar Memoria\n";
 cout << "9.Salir\n";
 cout << "Opcion: ";
 cin >> opcion;
 switch (opcion) {
 case 1: {
 mem = new CSMemoria();
 } break;
 case 2: {
 string id;
 cin.ignore();
 cout << "IDs: ";
 getline(cin, id);
 mem->new_espacio(id);
 } break;
 case 3: {
 int dir;
 cout << "Direccion a liberar: ";
 cin >> dir;
 mem->delete_espacio(dir);
 } break;
 case 4: {
 p = new PoliS(mem);
 } break;
 case 5: {
 int coef, exp;
 cout << "Coef: ";
 cin >> coef;
 cout << "Exp: ";
 cin >> exp;
 p->poner_termino(coef, exp);
 } break;
 case 6: {
 cout << p->to_str() << endl;
 } break;
 case 7: {
 p->derivar();
 } break;
 case 8: {
 mem->mostrar();
 } break;
 }
 system("pause");
 system("cls");
 }
 while (opcion != 9);
 }

 void menuV() {
 PoliV* p;
 int opcion;
 do {
 cout << "1.Crear Polinomio\n";
 cout << "2.Poner Termino\n";
 cout << "3.Mostrar Polinomio\n";
 cout << "4.Derivar\n";
 cout << "5.Salir\n";
 cout << "Opcion: ";
 cin >> opcion;
 switch (opcion) {
 case 1: {
 p = new PoliV();
 } break;
 case 2: {
 int coef, exp;
 cout << "Coef: ";
 cin >> coef;
 cout << "Exp: ";
 cin >> exp;
 p->poner_termino(coef, exp);
 } break;
 case 3: {
 cout << p->to_str() << endl;
 } break;
 case 4: {
 p->derivar();
 } break;
 }
 system("pause");
 system("cls");
 }
 while (opcion != 5);
 }

 void menuP() {
 PoliP* p;
 int opcion;
 do {
 cout << "1.Crear Polinomio\n";
 cout << "2.Poner Termino\n";
 cout << "3.Mostrar Polinomio\n";
 cout << "4.Derivar\n";
 cout << "5.Salir\n";
 cout << "Opcion: ";
 cin >> opcion;
 switch (opcion) {
 case 1: {
 p = new PoliP();
 } break;
 case 2: {
 int coef, exp;
 cout << "Coef: ";
 cin >> coef;
 cout << "Exp: ";
 cin >> exp;
 p->poner_termino(coef, exp);
 } break;
 case 3: {
 cout << p->to_str() << endl;
 } break;
 case 4: {
 p->derivar();
 } break;
 }
 system("pause");
 system("cls");
 }
 while (opcion != 5);
 }

 void menuL() {
 PoliL* p; // PoliLP* p;
 int opcion;
 do {
 cout << "1.Crear Polinomio\n";
 cout << "2.Poner Termino\n";
 cout << "3.Mostrar Polinomio\n";
 cout << "4.Derivar\n";
 cout << "5.Salir\n";
 cout << "Opcion: ";
 cin >> opcion;
 switch (opcion) {
 case 1: {
 p = new PoliL(); // p = new PoliLP();
 } break;
 case 2: {
 int coef, exp;
 cout << "Coef: ";
 cin >> coef;
 cout << "Exp: ";
 cin >> exp;
 p->poner_termino(coef, exp);
 } break;
 case 3: {
 cout << p->to_str() << endl;
 } break;
 case 4: {
 p->derivar();
 } break;
 }
 system("pause");
 system("cls");
 }
 while (opcion != 5);
 } */
