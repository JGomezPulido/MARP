
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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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
    // escribir la soluci�n
    a.esLibre(grafo) ? cout << "SI" : cout << "NO";
	cout << "\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
