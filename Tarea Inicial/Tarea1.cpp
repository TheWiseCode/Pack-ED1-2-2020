#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
 1.Dada una cadena escrita en un archivo texto,
 calcular el promedio de todos los numeros en ese archivo.
 */

void pregu1();
float promedio(string cad);
float promedio1(string cad);
bool es_numero1(char c);
bool es_numero(string s);

/*
 2.Dada una cadena introducida por teclado,
 calcular las frecuencias de palabras
 */
void pregu2();
int pos_palabra(string* vc, int n, string pal);

int main() {
	/* string alf = "013456789";
	 int pos = alf.find_first_of("");//-1 o 2^32 - 1
	 cout << pos << endl; */
	pregu2();
	system("pause");
	return 0;
}

void pregu1() {
	ifstream file;
	string ruta = "C:\\Users\\pc\\Desktop\\Numeros.txt";
	file.open(ruta.c_str(), ios::in);
	if (file.fail()) {
		cout << "Error al abrir el archivo" << endl;
	}
	else {
		string line_file = "";
		while (!file.eof()) {
			string line;
			getline(file, line);
			line_file += line + " ";
		}
		// cout <<  line_file << endl;
		float prom = promedio1(line_file);
		cout << "Promedio: " << prom << endl;
	}
}

float promedio(string cad) {
	float suma = 0;
	int ne = 0;
	while (cad.length() > 0) {
		int pos = cad.find_first_of(" ");
		string palabra = cad.substr(0, pos);
		if (es_numero(palabra)) {
			suma += atoi(palabra.c_str());
			ne++;
		}
		cad.erase(0, pos + 1);
	}
	if (ne > 0)
		return suma * 1.0 / ne;
	else
		return 0;
}

bool es_numero1(char c) {
	return c == '0' || c == '1' || c == '2' || c == '3' || c == '4' ||
		c == '5' || c == '6' || c == '7' || c == '8' || c == '9';
}

float promedio1(string cad) {
	float suma = 0;
	int ne = 0;
	int n = cad.length();
	string num = "";
	string alf = "0123456789";
	for (int i = 0; i < n; i++) {
		char c = cad[i];
		if (es_numero1(c)) { // Es un numero el caracter
			num += c;
		}
		else {
			if (num.length() > 0) {
				suma += atoi(num.c_str());
				ne++;
			}
			num = "";
		}
	}
	if (ne > 0)
		return suma * 1.0 / ne;
	else
		return 0;
}

bool es_numero(string s) {
	int n = s.length();
	string alf = "-+0123456789";
	for (int i = 0; i < n; i++) {
		if (alf.find_first_of(s[i]) == -1)
			return false;
	}
	return true;
}
// -------------------------------------

// HOLA COMO ESTAN HOLA HOY COMO TODOS
/*
 String* vc = [HOLA, COMO, ESTAN, HOY, TODOS]
 int* vf    = [2, 2, 1, 1, 1]
 */

/*
 c = 3
 vc = ["HOLA", "COMO", "ESTAN", "", "", "", "", "", "", ""]
 vf = [1, 1, 1, 0, 0, 0, 0, 0, 0, 0 ]
 */

int pos_letra(string s) {
	string alf = "0123456789abcdefghijklmnñopqrstuvwxyz";
	for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		int p = alf.find_first_of(c);
		if (p >= 0)
			return i;
	}
	return -1;
}

int pos_espacio(string s, int p) {
	for (int i = p; i < s.length(); i++) {
		if (s[i] == ' ')
			return i;
	}
	return -1;
}

void pregu2() {
	string cad;
	cout << "Introduzca una cadena: \n";
	getline(cin, cad);
	string* vc = new string[10];
	int* vf = new int[10];
	int c = 0;
	while (cad.length() > 0) {
		int pl = pos_letra(cad);
		int pe = pos_espacio(cad, pl);
		if (pe == -1)
			pe = cad.length();
		string palabra = cad.substr(pl, pe - pl);
		cad.erase(0, pe + 1);
		int p = pos_palabra(vc, c, palabra);
		if (p == -1) {
			vc[c] = palabra;
			vf[c] = 1;
			c++;
		}
		else {
			vf[p]++;
		}
	}
	for (int i = 0; i < c; i++)
		cout << vc[i] << " : " << vf[i] << endl;
}

int pos_palabra(string* vc, int n, string palabra) {
	for (int i = 0; i < n; i++) {
		if (vc[i] == palabra)
			return i;
	}
	return -1;
}
