
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
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
class NumNodos {
private:
    vector<bool> visit;
    vector<int> ant;
    vector<int> dist;
    int num;
    int T;

    void bfs(Grafo const& g, int s) {
        std::queue<int> q;
        visit[s] = true;
        dist[s] = 0; 
        q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int w : g.ady(v)) {
                if (!visit[w]) {
                    ant[w] = v; dist[w] = dist[v] + 1; visit[w] = true;
                    if (dist[w] > T) ++num;
                    q.push(w);
                }
            }
        }
    }
public:
    NumNodos(Grafo const& g, int t, int s) : visit(g.V()), ant(g.V()), dist(g.V()), num(0), T(t) {
        bfs(g, s);
        for (bool b : visit) {
            if (!b) num++;
        }
    }

    int numero() {
        return num;
    }
};

bool resuelveCaso() {

    Grafo g(cin, 1);
    if (!std::cin)  // fin de la entrada
        return false;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int s, d;
        cin >> s >> d;
        cout << NumNodos(g, d, s-1).numero() << "\n";
    }
    cout << "---\n";
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la soluci�n

    return true;
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

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
