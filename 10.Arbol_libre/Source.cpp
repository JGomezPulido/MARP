
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

#include <deque>
#include <vector>
class ArbolLibre {
private:
	std::vector<bool> visit;
	std::vector<int> ant;
	int nVisit;
	bool ciclico;

	void dfs(Grafo const& G, int v) {
		visit[v] = true;
		++nVisit;
		for (int w : G.ady(v)) {
			if (ciclico) return;
			if (ant[v] == w) continue;

			if (!visit[w]) {
				ant[w] = v;
				dfs(G, w);
			}
			else{
				ciclico = true;		
			}
		}
	};

	bool esConexo(Grafo const& g) const{
		return nVisit == g.V();
	};

public:
	ArbolLibre(Grafo const& g, int s) : visit(g.V(), false), ant(g.V(), -1),  nVisit(0), ciclico(false) {
		dfs(g, 0);
	};

	bool esLibre(Grafo const& g) const {
		return !ciclico && esConexo(g);
	};
};

bool resuelveCaso() {
	Grafo grafo(cin);
    if (!std::cin)  // fin de la entrada
        return false;
    // resolver el caso posiblemente llamando a otras funciones
    ArbolLibre a(grafo, 0);
    // escribir la solución
    a.esLibre(grafo) ? cout << "SI" : cout << "NO";
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

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
