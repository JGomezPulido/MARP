/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

 /*@ <answer>
  *
  * Indicad el nombre completo y usuario del juez de quienes habéis hecho esta solución:
  * Estudiante 1: Jose Maria Gomez Pulido MARP20
  * Estudiante 2: Paula Morillas Alonso MARP31
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Digrafo.h"
using namespace std;



/*@ <answer>

 El coste del algoritmo es el coste de hacer una dfs en un digrafo, esto es O(A+V).

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>
vector<int> adt(int v, vector<int>const& inst, vector<char>const& prog) {
	vector<int> vec;
	switch (prog[v]) {
	case 'A':
		if (v + 1 < inst.size()) vec.push_back(v + 1);
		break;
	case 'J':
		vec.push_back(inst[v]);
		break;
	case 'C':
		if (v + 1 < inst.size()) vec.push_back(v + 1);
		vec.push_back(inst[v]);
		break;
	default:
		break;
	}
	return vec;
}

void dfs(vector<int> const& inst, vector<char>const& prog, vector<bool>& visit, vector<bool>& apil, int v, bool&ciclos) {
	apil[v] = true;
	visit[v] = true;
	for (int w : adt(v, inst, prog)) {
		if (!visit[w]) {
			if(w != prog.size()) dfs(inst, prog, visit, apil, w, ciclos);
		}
		else if(apil[w]) {
			ciclos = true;
		}
	}
	apil[v] = false;
}

bool resuelveCaso() {
	int L;
	cin >> L;
	if (!cin) return false;
	vector<int> instruc(L + 1,0);
	vector<char> prog(L + 1,'A');
	int jump;
	char ins;
	vector<bool> visit(L + 1, false);
	vector<bool> apilado(L + 1, false);
	bool ciclos = false;
	for (int i = 0; i < L; i++) {
		cin >> ins;
		prog[i] = ins;
		if (ins == 'J' || ins == 'C') {
			cin >> jump;
			instruc[i] = jump - 1;
		}
	}
	dfs(instruc, prog, visit, apilado, 0, ciclos);
	if (!visit[L]) {
		cout << "NUNCA\n";
	}
	else if (ciclos && visit[L]) {
		cout << "A VECES\n";
	}
	else {
		cout << "SIEMPRE\n";
	}
	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.
#define DOMJUDGE
int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	while (resuelveCaso()) {}

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
