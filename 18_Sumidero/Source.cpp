
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Digrafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class Sumidero {
private:
    vector<int> visitados;
    vector<int> aristas;

    void dfs(Digrafo const& g, int a) {
        visitados[a] = true;
        for (int w : g.ady(a)) {
            aristas[w]++;
            if (!visitados[w]) {
                dfs(g, w);
            }
        }
    }
public:
    Sumidero(Digrafo const& g) : visitados(g.V(), false), aristas(g.V(), 0) {
        for (int i = 0; i < g.V(); i++) {
            if (!visitados[i]) {
                dfs(g, i);
            }
        }
    }
    int sumidero(Digrafo const& g) {
        for (int i = 0; i < g.V(); i++) {
            if (aristas[i] == g.V() - 1 && g.ady(i).size() == 0) {
                return i;
            }
        }
        return -1;
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    Digrafo grafo(cin, 0);
    if (!std::cin)  // fin de la entrada
        return false;

    Sumidero sol(grafo);
    // resolver el caso posiblemente llamando a otras funciones
    int a = sol.sumidero(grafo);
    // escribir la solución
    a == -1 ? cout << "NO\n" : cout << "SI " << a << "\n";
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

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
