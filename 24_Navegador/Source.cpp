
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

#include "DigrafoValorado.h"  // propios o los de las estructuras de datos de clase
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

class Conectado {
private:
    const int INF = INT_MAX;
    int orig;
    vector<int> dist;
    vector<int> cargas;
    IndexPQ<int> pq;

    void relajar(AristaDirigida<int> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor() + cargas[w]) {
            dist[w] = dist[v] + a.valor() + cargas[w];
            pq.update(w, dist[w]);
        }
    }
public:
    Conectado(DigrafoValorado<int> const& g, vector<int> const& carga) : orig(0), dist(g.V(), INF), cargas(carga), pq(g.V()) {
        dist[orig] = cargas[orig];
        pq.push(orig, cargas[orig]);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (AristaDirigida<int> a : g.ady(v)) {
                relajar(a);
            }
        }
    };
    bool hayCamino(int v) const { return dist[v] != INF; }
    int distancia(int v) const { return dist[v]; }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N;
    if (N == 0)
        return false;

    vector<int> carga(N);
    DigrafoValorado<int> g(N);
    for (int i = 0; i < N; i++) {
        cin >> carga[i];
    }
    int A;
    cin >> A;
    int v, w, coste;
    for (int i = 0; i < A; i++) {
        cin >> v >> w >> coste;
        g.ponArista({ v - 1, w - 1, coste });
    }
    // resolver el caso posiblemente llamando a otras funciones
    Conectado c(g, carga);

    if (!c.hayCamino(N - 1)) cout << "IMPOSIBLE\n";
    else cout << c.distancia(N - 1) << "\n";
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
