
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <climits>
using namespace std;

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "IndexPQ.h"
/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
class Caminos {
private:
    
    int INF = INT_MAX;
    int dest;
    int orig;
    int umbral;
    int cams;
    vector<int> dist;
    vector<bool> visit;
    IndexPQ<int> pq;

    void relajar(Arista<int> a, int v) {
        int w = a.otro(v);
        if (visit[w]) return;
        if (dist[w] > dist[v] + a.valor() || dist[v] + a.valor() <= umbral) {
            dist[w] = dist[v] + a.valor();
            pq.update(w, dist[w]); 
            if (w == dest && dist[v] + a.valor() == umbral) cams++;
            else if (w == dest && dist[v] + a.valor() < umbral) {
                umbral = dist[w];
                cams = 1;
            }
        }

    }
public:
    Caminos(GrafoValorado<int> const& g) : dest(g.V() - 1), orig(0), umbral(INF), cams(0), dist(g.V(), INF), visit(g.V(), false), pq(g.V()) {
        dist[orig] = 0;
        pq.push(orig, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (Arista<int> a : g.ady(v))
                relajar(a, v);
            visit[v] = true;
        }
    };

    int caminos() const { return cams; };
};

bool resuelveCaso() {

    // leer los datos de la entrada
    GrafoValorado<int> g(cin, 1);
    if (!std::cin)  // fin de la entrada
        return false;

    // resolver el caso posiblemente llamando a otras funciones
    Caminos sol(g);
    // escribir la solución
    cout << sol.caminos() << "\n";
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
