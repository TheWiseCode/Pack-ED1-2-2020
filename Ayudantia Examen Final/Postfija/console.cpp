#include <iostream>
#include "UPilaDi.h"
#include <math.h>

using namespace std;

string infijaToPostfija(string cadena);
bool es_digito(char c);
bool es_operador(char c);
int evaluar(int op1, char oper, int op2);
int prioridad_infija(char c);
int prioridad_pila(char c);
int evaluarPostfija(string cadena);

bool es_letra(char c) {
	return (c >= 0x40 && c <= 0x5A) || (c >= 0x60 && c <= 0x7A);
}

string infijaToPostfijaLetra(string cadena) {
	PilaDi p;
	string postfija = "";
	for (int i = 0; i < cadena.length(); i++) {
		char c = cadena[i];
		if (es_letra(c)) {
			postfija += c;
		}
		else {
			if (es_operador(c)) {
				bool salir = false;
				while (!salir) {
					char aux = p.cima();
					if (p.vacia() || (prioridad_infija(c) >
						prioridad_pila(aux))) {
						p.meter(c);
						salir = true;
					}
					else {
						int x;
						p.sacar(x);
						aux = x;
						postfija += aux;
					}
				}
			}
			else {
				if (c == '(') {
					p.meter(c);
				}
				else if (c == ')') {
					char aux;
					do {
						int x;
						p.sacar(x);
						aux = x;
						if (aux != '(')
							postfija += aux;
					}
					while (aux != '(');
				}
			}
		}
	}
	char aux;
	while (!p.vacia()) {
		int x;
		p.sacar(x);
		aux = x;
		postfija += aux;
	}
	return postfija;
}

int main() {
	// string infija = "(20+3)*5";
	string infija = "(a+B)*c";
	// string postfija = infijaToPostfija(infija);
	string postfija = infijaToPostfijaLetra(infija);
	// int evaluado = evaluarPostfija(postfija);
	cout << postfija << endl;
	// cout << evaluado << endl;
	system("pause");
	return 0;
}

bool es_digito(char c) {
	return c >= 0x30 && c <= 0x39;
}

bool es_operador(char c) {
	return c == '^' || c == '*' || c == '/' || c == '+' || c == '-';
}

string infijaToPostfija(string cadena) {
	PilaDi p;
	string postfija = "";
	for (int i = 0; i < cadena.length(); i++) {
		char c = cadena[i];
		if (es_digito(c)) {
			string num = "";
			char aux = cadena[i];
			while (es_digito(aux)) {
				num += aux;
				i++;
				aux = cadena[i];
			}
			i--;
			postfija += num + " ";
		}
		else {
			if (es_operador(c)) {
				bool salir = false;
				while (!salir) {
					char aux = p.cima();
					if (p.vacia() || (prioridad_infija(c) >
						prioridad_pila(aux))) {
						p.meter(c);
						salir = true;
					}
					else {
						int x;
						p.sacar(x);
						aux = x;
						postfija += aux;
					}
				}
			}
			else {
				if (c == '(') {
					p.meter(c);
				}
				else if (c == ')') {
					char aux;
					do {
						int x;
						p.sacar(x);
						aux = x;
						if (aux != '(')
							postfija += aux;
					}
					while (aux != '(');
				}
			}
		}
	}
	char aux;
	while (!p.vacia()) {
		int x;
		p.sacar(x);
		aux = x;
		postfija += aux;
	}
	return postfija;
}

int evaluarPostfija(string cadena) {
	PilaDi p;
	int z = 0;
	for (int i = 0; i < cadena.length(); i++) {
		char c = cadena[i];
		if (es_digito(c)) {
			string num = "";
			char aux = cadena[i];
			while (es_digito(aux)) {
				num += aux;
				i++;
				aux = cadena[i];
			}
			i--;
			int n = atoi((char*)num.c_str());
			p.meter(n);
		}
		else if (c != ' ') {
			int op1, op2;
			p.sacar(op2);
			p.sacar(op1);
			char operacion = c;
			z = evaluar(op1, c, op2);
			p.meter(z);
		}
	}
	return z;
}

int evaluar(int op1, char oper, int op2) {
	if (oper == '^')
		return (int)pow(op1 * 1.0, op2 * 1.0);
	if (oper == '*')
		return op1 * op2;
	if (oper == '/')
		return op1 / op2;
	if (oper == '+')
		return op1 + op2;
	if (oper == '-')
		return op1 - op2;
}

int prioridad_infija(char c) {
	if (c == ' ^ ')
		return 4;
	if (c == ' * ')
		return 2;
	if (c == ' / ')
		return 2;
	if (c == ' + ')
		return 1;
	if (c == ' - ')
		return 1;
	if (c == '(')
		return 5;
}

int prioridad_pila(char c) {
	if (c == ' ^ ')
		return 3;
	if (c == ' * ')
		return 2;
	if (c == ' / ')
		return 2;
	if (c == ' + ')
		return 1;
	if (c == ' - ')
		return 1;
	if (c == '(')
		return 0;
}
