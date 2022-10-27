/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

/*@ <answer>
 *
 * Indicad el nombre completo y usuario del juez de quienes habéis hecho esta solución:
 * Estudiante 1: Paula Morillas Alonso MARP31
 * Estudiante 2: Jose Maria Gomez Pulido MARP20
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;
#include "DigrafoValorado.h"
#include "IndexPQ.h"
/*@ <answer>
 
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 El coste del algoritmo es el coste de Djikstra, que es O(V+log A)
 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo (después de la marca)
//@ <answer>
class Djikstra {
protected:
    const int INF = numeric_limits<int>::max();
    int final;
    vector<int> dist;
    IndexPQ<int> pq;
    int cont;
    
    void relajar(AristaDirigida<int> a)
    {
        int v = a.desde(); int w = a.hasta();
        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor();
            pq.update(w, dist[w]);
        }
    };
public:
    Djikstra(DigrafoValorado<int> const& g, int fin, int umbral) : final(fin), dist(g.V(), INF), pq(g.V()), cont(0) {
        dist[fin] = 0;
        pq.push(fin, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (AristaDirigida<int> a : g.ady(v)) {
                relajar(a);
            }
            if (v != final && dist[v] <= umbral) cont++;
        }
    }

    int cost() const {
        return cont;
    }
};


bool resuelveCaso() {
  
  // leemos la entrada
  int N, S, T, P;
  cin >> N >> S >> T >> P;
  
  if (!cin)
    return false;

  DigrafoValorado<int> g(N);
  int v, w, cost;
  // leer el resto del caso y resolverlo
  for (int i = 0; i < P; i++) {
      cin >> v >> w >> cost;
      g.ponArista({ v - 1, w - 1, cost });
  }
  Djikstra d(g.inverso(), S - 1, T);
  cout << d.cost() << "\n";
  
  
  return true;
}

//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

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
 // system("PAUSE");
#endif
  return 0;
}
