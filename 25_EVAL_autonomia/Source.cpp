
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>

using namespace std;

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase
#include "GrafoValorado.h"
#include "ConjuntosDisjuntos.h"
/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
class Kruskal {
    int coste;
    int aristas;
public:
    Kruskal(GrafoValorado<int> const& g) {
        coste = 0;
        PriorityQueue<Arista<int>>cola(g.aristas()); //da error porque hay que usar el priority queue del profe no el de visual
        ConjuntosDisjuntos conjunto(g.V());
        aristas = 0;
        while (!cola.empty()) {
            Arista<int> e = cola.top(); cola.pop();
            int v = e.uno();
            int w = e.otro(v);

            if (conjunto.buscar(v) != conjunto.buscar(w)) {
                conjunto.unir(v, w);
                coste = e.valor();
                aristas++;
                if (aristas == g.V() - 1) return;
            }

        }
    }
    bool existsARM(GrafoValorado<int> const& g) {
        return aristas == g.V() - 1;;
    }
    int cost() {
        return coste;
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    GrafoValorado<int> g(cin, 1);
    if (!std::cin)  // fin de la entrada
        return false;

    // resolver el caso posiblemente llamando a otras funciones
    Kruskal sol(g);

    if (!sol.existsARM(g)) cout << "Imposible\n";
    else cout << sol.cost() << "\n";
    // escribir la solución

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
