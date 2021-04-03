// ---------------------------------------------------------------------------

#ifndef FuncionesH
#define FuncionesH
// ---------------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

string to_string(int valor) {
	if (valor == 0)
		return "0";
	bool es_negativo = valor < 0;
	string r = "";
	if (es_negativo)
		valor *= -1;
	while (valor != 0) {
		char c = valor % 10 + 0x30;
		r = c + r;
		valor = valor / 10;
	}
	return es_negativo ? "-" + r : r;
}

string repetir(char caracter, unsigned int cantidad) {
	return std::string(cantidad, caracter);
}

string rellenar(string s, char caracter, unsigned int cantidad) {
	if (cantidad <= s.length())
		return s;
	int relleno = cantidad - s.length();
	return repetir(caracter, relleno) + s;
}
#endif
