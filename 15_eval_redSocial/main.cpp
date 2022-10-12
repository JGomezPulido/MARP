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
#include <algorithm>
#include <limits>
#include "Grafo.h"

using namespace std;


/*@ <answer>
 
 El coste de la solucion es el coste del depth-first searc, esto es g(A+V), siendo A el numero de aristas
 y V el numero de vertices
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo (después de la marca)
//@ <answer>
class MaximoCamino {
private:
	vector<bool> visitados;
	vector<size_t> maximo;
	vector<int> conexas;

	int dfs(Grafo const& g, int v, int conex) {
		visitados[v] = true;
		conexas[v] = conex;
		size_t tam = 1;
		for (auto w : g.ady(v)) {
			if (!visitados[w]) {
				tam += dfs(g, w, conex);
			}
		}
		return tam;
	}
public:
	MaximoCamino(Grafo const& g, int grupos) : maximo(g.V(), 1), visitados(g.V(), false), conexas(g.V(), -1) {
		int conex = 0;
		for (int i = 0; i < g.V(); i++) {
			
			if (!visitados[i]) {
				size_t tam = dfs(g, i, conex);
				maximo[conex] = max(maximo[conex], tam);
				cout << maximo[conexas[i]] << " ";
				conex++;
			}
			else {
				cout << maximo[conexas[i]] << " ";
			}
			
		}
	}

	size_t getMax(int i) {
		return maximo[conexas[i]];
	}
};


bool resuelveCaso() {
	int N, G;
	cin >> N >> G;
	if (!cin) {
		return false;
	}
	Grafo g(N);
	int M;
	int a, b;
	for (int i = 0; i < G; i++) {
		cin >> M;
		if(M!=0)
		{
			cin >> a;
			
			for (int j = 0; j < M - 1; j++) {

				cin >> b;
				g.ponArista(a - 1, b - 1);
				a = b;
			}
		}
	}
	MaximoCamino m(g, G);
	cout << "\n";
	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
  // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
  std::ifstream in("casos.txt");
  auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
  
  // Resolvemos
  while (resuelveCaso());
  
  // para dejar todo como estaba al principio
#ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
  system("PAUSE");
#endif
  return 0;
}
