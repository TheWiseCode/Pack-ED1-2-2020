#include <iostream>
#include "UPilaL.h"
#include "UPilaV.h"
#include "UPilaP.h"
#include "UPilaS.h"
#include "UPilaDi.h"
#include "UMemoria.h"
#include <math.h>
#include <stdio.h>

using namespace std;

string infijaToPostfija(string cadena);
int evaluarPostfija(string cadena);
int evalua(float op1, char op, float op2);
int prioridadInfija(char c);
int prioridadPila(char c);
bool digito(char c);
bool operador(char c);

int main() {
	/*
	 PilaDi *p = new PilaDi();
	 p->meter(1);
	 p->meter(2);
	 p->meter(20);
	 p->meter(7);
	 p->meter(2);
	 p->meter(10);
	 p->meter(66);
	 p->meter(77);
	 p->meter(88);
	 cout << p->to_str() << endl;
	 cout << p->cima() << endl;
	 */
	string a = "(20+3)*5";
	string b = "2 3 5*+";
	string p = infijaToPostfija(a);
	cout << p << endl;
	float real = evaluarPostfija(p);
	cout << real << endl;
	system("pause");
	return 0;
}

int evalua(float op1, char op, float op2) {
	if (op == '^')
		return (int)pow(op1, op2);
	else if (op == '*')
		return op1 * op2;
	else if (op == '/')
		return op1 * 1.0 / op2;
	else if (op == '+')
		return op1 + op2;
	else if (op == '-')
		return op1 - op2;
	else
		return 0;
}

int evaluarPostfija(string cadena) {
	PilaP p;
	int n = cadena.length();
	for (int i = 0; i < n; i++) {
		char letra = cadena[i];
		if (digito(letra)) {
			string num = "";
			while (!operador(letra) && letra != ' ') {
				num += letra;
				i++;
				letra = cadena[i];
				if (i == n)
					break;
			}
			int n = atoi((char*)num.c_str());
			p.meter(n);
		}
		else if (letra != ' ') {
			int op1, op2;
			p.sacar(op2);
			p.sacar(op1);
			// char op = letra;
			int z = evalua(op1, letra, op2);
			p.meter(z);
		}
	}
	int res;
	p.sacar(res);
	return res;
}

string infijaToPostfija(string cadena) {
	PilaP p;
	string exp = "";
	int aux;
	int n = cadena.length();
	for (int i = 0; i < n; i++) {
		char letra = cadena[i];
		if (digito(letra)) {
			string num = "";
			while (!operador(letra) && letra != ')' && i < n) {
				num += letra;
				i++;
				letra = cadena[i];
			}
			exp += num + " ";
			i--;
		}
		else if (letra == '(')
			p.meter(letra);
		else {
			if (operador(letra)) {
				while (true) {
					aux = p.cima();
					if (p.vacia() || (prioridadInfija(letra) >
						prioridadPila(aux))) {
						p.meter(letra);
						break; // por aqui sale
					}
					else {
						p.sacar(aux);
						exp += aux;
					}
				}
			}
			else {
				if (letra == ')') {
					while (true) {
						p.sacar(aux);
						if (((char)aux) != '(')
							exp += (char)aux;
						else
							break;
					}
				}
			}
		}
	}
	while (!p.vacia()) {
		p.sacar(aux);
		exp += aux;
	}
	return exp;
}

int prioridadInfija(char c) {
	if (c == '^')
		return 4;
	else if (c == '*')
		return 2;
	else if (c == '/')
		return 2;
	else if (c == '+')
		return 1;
	else if (c == '-')
		return 1;
	else if (c == '(')
		return 5;
	else
		return 0;
}

int prioridadPila(char c) {
	if (c == '^')
		return 3;
	else if (c == '*')
		return 2;
	else if (c == '/')
		return 2;
	else if (c == '+')
		return 1;
	else if (c == '-')
		return 1;
	else if (c == '(')
		return 0;
	else
		return -1;
}

bool digito(char c) {
	return c == '0' || c == '1' || c == '2' || c == '3' || c == '4' ||
		c == '5' || c == '6' || c == '7' || c == '8' || c == '9';
}

bool operador(char c) {
	return c == '^' || c == '*' || c == '/' || c == '+' || c == '-';
}
