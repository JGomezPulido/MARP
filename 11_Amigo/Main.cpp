
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

class MaximoCamino {
private:
    vector<bool> visitados;
    size_t maximo;

    int dfs(Grafo const& g, int v) {
        visitados[v] = true;
        size_t tam = 1;
        for (auto w : g.ady(v)) {
            if (!visitados[w]) {
                tam += dfs(g, w);
            }
        }
        return tam;
    }
public:
    MaximoCamino(Grafo const& g) : maximo(0), visitados(g.V(), false) {
        for (int i = 0; i < g.V(); i++) {
            if (!visitados[i]) {
                size_t tam = dfs(g, i);
                if (tam > maximo) maximo = tam;
            }
        }
    }

    size_t getMax() {
        return maximo;
    }
};

void resuelveCaso() {
    cout << MaximoCamino(Grafo(cin, 1)).getMax() << "\n";
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.
#define DOMJUDGE
int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
